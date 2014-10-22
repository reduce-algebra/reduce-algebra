
/* $destdir\u51.c        Machine generated C code */

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


/* Code for sfto_dgcd */

static Lisp_Object CC_sfto_dgcd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_dgcd");
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
    v0007 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* sfto_dcontentf */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-2];
    stack[-1] = v0007;
    v0008 = stack[-1];
    v0007 = (Lisp_Object)17; /* 1 */
    v0007 = Leqn(nil, v0008, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-2];
    if (!(v0007 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0007 = stack[0];
    fn = elt(env, 1); /* sfto_dcontentf */
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-2];
    {
        Lisp_Object v0010 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* sfto_gcdf */
        return (*qfn2(fn))(qenv(fn), v0010, v0007);
    }
/* error exit handlers */
v0009:
    popv(3);
    return nil;
}



/* Code for mod!-domainvalchk */

static Lisp_Object CC_modKdomainvalchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0020, v0021;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mod-domainvalchk");
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
    v0021 = v0001;
    v0019 = v0000;
/* end of prologue */
    v0020 = v0019;
    v0019 = elt(env, 1); /* expt */
    if (v0020 == v0019) goto v0005;
    v0019 = qvalue(elt(env, 2)); /* nil */
    goto v0022;

v0022:
    v0021 = v0019;
    v0020 = v0021;
    v0019 = elt(env, 3); /* failed */
    if (v0020 == v0019) goto v0023;
    v0020 = v0021;
    v0019 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v0020, v0019);

v0023:
    v0019 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0019); }

v0005:
    v0019 = v0021;
    v0019 = qcar(v0019);
    v0020 = v0021;
    v0020 = qcdr(v0020);
    v0020 = qcar(v0020);
    fn = elt(env, 4); /* mod!-expt!-fract */
    v0019 = (*qfn2(fn))(qenv(fn), v0019, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[0];
    goto v0022;
/* error exit handlers */
v0024:
    popv(1);
    return nil;
}



/* Code for test!-ideal */

static Lisp_Object CC_testKideal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0035, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for test-ideal");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0036 = v0000;
/* end of prologue */
    v0035 = qvalue(elt(env, 1)); /* id!-vars!* */
    v0034 = elt(env, 2); /* list */
    if (!consp(v0035)) goto v0017;
    v0035 = qcar(v0035);
    if (!(v0035 == v0034)) goto v0017;
    v0035 = v0036;
    v0034 = elt(env, 2); /* list */
    if (!consp(v0035)) goto v0037;
    v0035 = qcar(v0035);
    if (!(v0035 == v0034)) goto v0037;
    v0034 = elt(env, 4); /* i */
    v0035 = v0036;
    v0035 = qcdr(v0035);
    return cons(v0034, v0035);

v0037:
    v0035 = v0036;
    v0034 = elt(env, 4); /* i */
    if (!consp(v0035)) goto v0011;
    v0035 = qcar(v0035);
    if (v0035 == v0034) return onevalue(v0036);
    else goto v0011;

v0011:
    v0035 = v0036;
    v0034 = elt(env, 5); /* "polynomial ideal" */
    {
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0035, v0034);
    }

v0017:
    v0035 = qvalue(elt(env, 1)); /* id!-vars!* */
    v0034 = elt(env, 3); /* "ideal setting; set variables first" */
    {
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0035, v0034);
    }
}



/* Code for pst_d1 */

static Lisp_Object MS_CDECL CC_pst_d1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065;
    Lisp_Object fn;
    Lisp_Object v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pst_d1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_d1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v0055;
    stack[-11] = v0001;
    v0065 = v0000;
/* end of prologue */
    stack[0] = stack[-10];
    v0065 = sub1(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0065/(16/CELL)));
    stack[-12] = v0065;
    v0065 = stack[-12];
    if (v0065 == nil) goto v0031;
    v0065 = stack[-12];
    v0065 = qcar(v0065);
    stack[-6] = v0065;
    stack[0] = stack[-10];
    v0065 = stack[-11];
    v0065 = sub1(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0065/(16/CELL)));
    stack[-5] = v0065;
    v0065 = stack[-5];
    if (v0065 == nil) goto v0067;
    v0065 = stack[-5];
    v0065 = qcar(v0065);
    stack[-1] = v0065;
    v0065 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v0065 = (*qfn2(fn))(qenv(fn), stack[0], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = qcar(v0065);
    fn = elt(env, 4); /* ordn */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    stack[-3] = v0065;
    stack[-4] = v0065;
    goto v0010;

v0010:
    v0065 = stack[-5];
    v0065 = qcdr(v0065);
    stack[-5] = v0065;
    v0065 = stack[-5];
    if (v0065 == nil) goto v0068;
    stack[-2] = stack[-3];
    v0065 = stack[-5];
    v0065 = qcar(v0065);
    stack[-1] = v0065;
    v0065 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v0065 = (*qfn2(fn))(qenv(fn), stack[0], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = qcar(v0065);
    fn = elt(env, 4); /* ordn */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = Lrplacd(nil, stack[-2], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = stack[-3];
    v0065 = qcdr(v0065);
    stack[-3] = v0065;
    goto v0010;

v0068:
    v0065 = stack[-4];
    goto v0009;

v0009:
    fn = elt(env, 4); /* ordn */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    stack[-8] = v0065;
    stack[-9] = v0065;
    goto v0069;

v0069:
    v0065 = stack[-12];
    v0065 = qcdr(v0065);
    stack[-12] = v0065;
    v0065 = stack[-12];
    if (v0065 == nil) { Lisp_Object res = stack[-9]; popv(14); return onevalue(res); }
    stack[-7] = stack[-8];
    v0065 = stack[-12];
    v0065 = qcar(v0065);
    stack[-6] = v0065;
    stack[0] = stack[-10];
    v0065 = stack[-11];
    v0065 = sub1(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0065/(16/CELL)));
    stack[-5] = v0065;
    v0065 = stack[-5];
    if (v0065 == nil) goto v0070;
    v0065 = stack[-5];
    v0065 = qcar(v0065);
    stack[-1] = v0065;
    v0065 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v0065 = (*qfn2(fn))(qenv(fn), stack[0], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = qcar(v0065);
    fn = elt(env, 4); /* ordn */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    stack[-3] = v0065;
    stack[-4] = v0065;
    goto v0071;

v0071:
    v0065 = stack[-5];
    v0065 = qcdr(v0065);
    stack[-5] = v0065;
    v0065 = stack[-5];
    if (v0065 == nil) goto v0072;
    stack[-2] = stack[-3];
    v0065 = stack[-5];
    v0065 = qcar(v0065);
    stack[-1] = v0065;
    v0065 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v0065 = (*qfn2(fn))(qenv(fn), stack[0], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = qcar(v0065);
    fn = elt(env, 4); /* ordn */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = Lrplacd(nil, stack[-2], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = stack[-3];
    v0065 = qcdr(v0065);
    stack[-3] = v0065;
    goto v0071;

v0072:
    v0065 = stack[-4];
    goto v0073;

v0073:
    fn = elt(env, 4); /* ordn */
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = ncons(v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = Lrplacd(nil, stack[-7], v0065);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-13];
    v0065 = stack[-8];
    v0065 = qcdr(v0065);
    stack[-8] = v0065;
    goto v0069;

v0070:
    v0065 = qvalue(elt(env, 1)); /* nil */
    goto v0073;

v0067:
    v0065 = qvalue(elt(env, 1)); /* nil */
    goto v0009;

v0031:
    v0065 = qvalue(elt(env, 1)); /* nil */
    { popv(14); return onevalue(v0065); }
/* error exit handlers */
v0066:
    popv(14);
    return nil;
}



/* Code for spreadvar */

static Lisp_Object MS_CDECL CC_spreadvar(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0080, v0081;
    Lisp_Object v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spreadvar");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spreadvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0080 = v0055;
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0022:
    v0079 = stack[-1];
    if (!consp(v0079)) goto v0082;
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0079 = (consp(v0079) ? nil : lisp_true);
    goto v0032;

v0032:
    if (!(v0079 == nil)) { popv(4); return onevalue(v0080); }
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0081 = qcar(v0079);
    v0079 = stack[0];
    if (equal(v0081, v0079)) goto v0037;
    v0079 = qvalue(elt(env, 2)); /* nil */
    goto v0008;

v0008:
    if (v0079 == nil) goto v0002;
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0079 = qcdr(v0079);
    v0079 = cons(v0079, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-3];
    v0080 = v0079;
    goto v0002;

v0002:
    v0079 = stack[-1];
    v0079 = qcdr(v0079);
    stack[-2] = v0079;
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0081 = qcdr(v0079);
    v0079 = stack[0];
    v0079 = CC_spreadvar(env, 3, v0081, v0079, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-3];
    v0080 = v0079;
    v0079 = stack[-2];
    stack[-1] = v0079;
    goto v0022;

v0037:
    v0079 = stack[-1];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0081 = qcdr(v0079);
    v0079 = v0080;
    v0079 = Lmember(nil, v0081, v0079);
    v0079 = (v0079 == nil ? lisp_true : nil);
    goto v0008;

v0082:
    v0079 = qvalue(elt(env, 1)); /* t */
    goto v0032;
/* error exit handlers */
v0083:
    popv(4);
    return nil;
}



/* Code for gcd!-mod!-p */

static Lisp_Object CC_gcdKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0089, v0090, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcd-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0090 = v0001;
    v0091 = v0000;
/* end of prologue */
    v0088 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0088; /* reduction!-count */
    v0088 = v0091;
    if (v0088 == nil) goto v0015;
    v0088 = v0090;
    if (v0088 == nil) goto v0092;
    v0088 = v0091;
    if (!consp(v0088)) goto v0030;
    v0088 = v0091;
    v0088 = qcar(v0088);
    v0088 = (consp(v0088) ? nil : lisp_true);
    goto v0006;

v0006:
    if (v0088 == nil) goto v0093;
    v0088 = (Lisp_Object)17; /* 1 */
    return onevalue(v0088);

v0093:
    v0088 = v0090;
    if (!consp(v0088)) goto v0009;
    v0088 = v0090;
    v0088 = qcar(v0088);
    v0088 = (consp(v0088) ? nil : lisp_true);
    goto v0023;

v0023:
    if (v0088 == nil) goto v0094;
    v0088 = (Lisp_Object)17; /* 1 */
    return onevalue(v0088);

v0094:
    v0088 = v0091;
    v0088 = qcar(v0088);
    v0088 = qcar(v0088);
    v0089 = qcdr(v0088);
    v0088 = v0090;
    v0088 = qcar(v0088);
    v0088 = qcar(v0088);
    v0088 = qcdr(v0088);
    if (((int32_t)(v0089)) > ((int32_t)(v0088))) goto v0095;
    v0088 = v0090;
    v0089 = v0091;
    {
        fn = elt(env, 3); /* ordered!-gcd!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0088, v0089);
    }

v0095:
    v0088 = v0091;
    v0089 = v0090;
    {
        fn = elt(env, 3); /* ordered!-gcd!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0088, v0089);
    }

v0009:
    v0088 = qvalue(elt(env, 2)); /* t */
    goto v0023;

v0030:
    v0088 = qvalue(elt(env, 2)); /* t */
    goto v0006;

v0092:
    v0088 = v0091;
    {
        fn = elt(env, 4); /* monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v0088);
    }

v0015:
    v0088 = v0090;
    {
        fn = elt(env, 4); /* monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v0088);
    }
}



/* Code for initmonomials */

static Lisp_Object MS_CDECL CC_initmonomials(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "initmonomials");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for initmonomials");
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
    v0013 = qvalue(elt(env, 1)); /* fluidbibasisvariables */
    v0013 = Llength(nil, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0013; /* fluidbibasisnumberofvariables */
    v0013 = qvalue(elt(env, 2)); /* fluidbibasisnumberofvariables */
    v0013 = Lmkvect(nil, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0013; /* fluidbibasissinglevariablemonomialss 
*/
    v0013 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0013;
    goto v0005;

v0005:
    v0064 = qvalue(elt(env, 2)); /* fluidbibasisnumberofvariables */
    v0013 = stack[-2];
    v0013 = difference2(v0064, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0013 = Lminusp(nil, v0013);
    env = stack[-3];
    if (v0013 == nil) goto v0097;
    v0013 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v0013; /* fluidbibasistripleid */
    v0013 = nil;
    { popv(4); return onevalue(v0013); }

v0097:
    stack[-1] = qvalue(elt(env, 3)); /* fluidbibasissinglevariablemonomialss 
*/
    stack[0] = stack[-2];
    v0013 = stack[-2];
    fn = elt(env, 6); /* createsinglevariablemonom */
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0013;
    v0013 = stack[-2];
    v0013 = add1(v0013);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    stack[-2] = v0013;
    goto v0005;
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for rl_translat */

static Lisp_Object MS_CDECL CC_rl_translat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0010, v0099, v0100, v0029;
    Lisp_Object fn;
    Lisp_Object v0056, v0004, v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rl_translat");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    v0056 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_translat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0056,v0004,v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0001,v0055,v0004,v0056);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0009 = v0056;
    v0010 = v0004;
    v0099 = v0055;
    v0100 = v0001;
    v0029 = v0000;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* rl_translat!* */
    stack[-2] = v0029;
    stack[-1] = v0100;
    stack[0] = v0099;
    v0009 = list2(v0010, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    v0009 = list3star(stack[-2], stack[-1], stack[0], v0009);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    {
        Lisp_Object v0037 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0037, v0009);
    }
/* error exit handlers */
v0078:
    popv(5);
    return nil;
}



/* Code for get!*real!*irreducible!*rep */

static Lisp_Object CC_getHrealHirreducibleHrep(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0008;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get*real*irreducible*rep");
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
    v0007 = stack[-1];
    stack[-2] = ncons(v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    v0008 = elt(env, 1); /* realrep */
    v0007 = stack[0];
    fn = elt(env, 2); /* mkid */
    v0007 = (*qfn2(fn))(qenv(fn), v0008, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    v0007 = get(stack[-1], v0007);
    env = stack[-3];
    v0007 = qcdr(v0007);
    v0007 = Lappend(nil, stack[-2], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 3); /* mk_resimp_rep */
        return (*qfn1(fn))(qenv(fn), v0007);
    }
/* error exit handlers */
v0010:
    popv(4);
    return nil;
}



/* Code for makevar */

static Lisp_Object CC_makevar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makevar");
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
    v0082 = v0000;
/* end of prologue */
    stack[-1] = Lexplode(nil, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    v0082 = stack[0];
    v0082 = Lexplode(nil, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-2];
    v0082 = Lnconc(nil, stack[-1], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0093;
        popv(3);
        return Lcompress(nil, v0082);
/* error exit handlers */
v0093:
    popv(3);
    return nil;
}



/* Code for ps!:constmult!-erule */

static Lisp_Object CC_psTconstmultKerule(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0016, v0098;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:constmult-erule");
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
    v0016 = v0001;
    v0098 = v0000;
/* end of prologue */
    v0096 = v0098;
    v0096 = qcdr(v0096);
    stack[0] = qcar(v0096);
    v0096 = v0098;
    v0096 = qcdr(v0096);
    v0096 = qcdr(v0096);
    v0096 = qcar(v0096);
    fn = elt(env, 1); /* ps!:evaluate */
    v0096 = (*qfn2(fn))(qenv(fn), v0096, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-1];
    {
        Lisp_Object v0003 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0003, v0096);
    }
/* error exit handlers */
v0002:
    popv(2);
    return nil;
}



/* Code for frlp */

static Lisp_Object CC_frlp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0007, v0008;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for frlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0007 = v0000;
/* end of prologue */

v0104:
    v0101 = v0007;
    if (v0101 == nil) goto v0056;
    v0101 = v0007;
    v0008 = qcar(v0101);
    v0101 = qvalue(elt(env, 2)); /* frlis!* */
    v0101 = Lmemq(nil, v0008, v0101);
    if (v0101 == nil) goto v0033;
    v0101 = v0007;
    v0101 = qcdr(v0101);
    v0007 = v0101;
    goto v0104;

v0033:
    v0101 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0101);

v0056:
    v0101 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0101);
}



/* Code for cr!:onep */

static Lisp_Object CC_crTonep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cr:onep");
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
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    v0084 = qcdr(v0084);
    if (!consp(v0084)) goto v0107;
    v0085 = elt(env, 1); /* !:rd!: */
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    v0084 = qcdr(v0084);
    v0084 = cons(v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    goto v0022;

v0022:
    v0085 = v0084;
    v0084 = v0085;
    if (!consp(v0084)) goto v0008;
    v0084 = v0085;
    v0084 = qcdr(v0084);
    v0085 = qcar(v0084);
    v0084 = (Lisp_Object)1; /* 0 */
    v0084 = (v0085 == v0084 ? lisp_true : nil);
    goto v0007;

v0007:
    if (v0084 == nil) goto v0056;
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    if (!consp(v0084)) goto v0021;
    v0085 = elt(env, 1); /* !:rd!: */
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    v0084 = cons(v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    goto v0020;

v0020:
    fn = elt(env, 3); /* mkround */
    v0084 = (*qfn1(fn))(qenv(fn), v0084);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 4); /* rd!:onep */
        return (*qfn1(fn))(qenv(fn), v0084);
    }

v0021:
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    goto v0020;

v0056:
    v0084 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0084); }

v0008:
    v0084 = v0085;
    v0084 = (Lisp_Object)zerop(v0084);
    v0084 = v0084 ? lisp_true : nil;
    env = stack[-1];
    goto v0007;

v0107:
    v0084 = stack[0];
    v0084 = qcdr(v0084);
    v0084 = qcdr(v0084);
    goto v0022;
/* error exit handlers */
v0089:
    popv(2);
    return nil;
}



/* Code for groebreduceonestepint */

static Lisp_Object MS_CDECL CC_groebreduceonestepint(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0120, v0121;
    Lisp_Object fn;
    Lisp_Object v0056, v0004, v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "groebreduceonestepint");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    v0056 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebreduceonestepint");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0056,v0004,v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0000,v0001,v0055,v0004,v0056);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0056;
    stack[-4] = v0004;
    stack[-3] = v0055;
    stack[-6] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0119 = stack[-1];
    fn = elt(env, 8); /* vdpred */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    stack[0] = v0119;
    v0120 = v0119;
    v0119 = v0120;
    if (v0119 == nil) goto v0096;
    v0119 = v0120;
    v0119 = qcdr(v0119);
    v0119 = qcdr(v0119);
    v0119 = qcdr(v0119);
    v0119 = qcar(v0119);
    v0119 = (v0119 == nil ? lisp_true : nil);
    goto v0103;

v0103:
    if (v0119 == nil) goto v0014;
    v0119 = stack[-2];
    fn = elt(env, 8); /* vdpred */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    stack[-2] = v0119;
    v0119 = stack[-6];
    qvalue(elt(env, 2)) = v0119; /* secondvalue!* */
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v0014:
    v0120 = stack[-4];
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    v0119 = qcar(v0119);
    fn = elt(env, 9); /* vevdif */
    v0119 = (*qfn2(fn))(qenv(fn), v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    stack[-7] = v0119;
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    v0119 = qcdr(v0119);
    v0119 = qcar(v0119);
    stack[-5] = v0119;
    v0119 = qvalue(elt(env, 3)); /* !*groebdivide */
    if (v0119 == nil) goto v0021;
    v0120 = stack[-3];
    v0119 = stack[-5];
    fn = elt(env, 10); /* vbcgcd */
    v0119 = (*qfn2(fn))(qenv(fn), v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    goto v0020;

v0020:
    stack[-4] = v0119;
    v0120 = stack[-5];
    v0119 = stack[-4];
    fn = elt(env, 11); /* vbcquot */
    v0119 = (*qfn2(fn))(qenv(fn), v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    stack[-5] = v0119;
    v0120 = stack[-3];
    v0119 = stack[-4];
    fn = elt(env, 11); /* vbcquot */
    v0119 = (*qfn2(fn))(qenv(fn), v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    stack[-4] = v0119;
    v0119 = stack[-6];
    if (v0119 == nil) goto v0080;
    v0119 = stack[-6];
    if (v0119 == nil) goto v0061;
    v0119 = stack[-6];
    v0119 = qcdr(v0119);
    v0119 = qcdr(v0119);
    v0119 = qcdr(v0119);
    v0119 = qcar(v0119);
    v0119 = (v0119 == nil ? lisp_true : nil);
    goto v0123;

v0123:
    if (!(v0119 == nil)) goto v0080;
    v0120 = stack[-6];
    v0119 = stack[-5];
    fn = elt(env, 12); /* vdpvbcprod */
    v0119 = (*qfn2(fn))(qenv(fn), v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    stack[-6] = v0119;
    goto v0080;

v0080:
    v0119 = qvalue(elt(env, 4)); /* !*groebprot */
    if (v0119 == nil) goto v0124;
    stack[-3] = stack[-5];
    v0119 = stack[-4];
    fn = elt(env, 13); /* vbcneg */
    v0121 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    v0120 = stack[-7];
    v0119 = stack[-1];
    fn = elt(env, 14); /* groebreductionprotocol */
    v0119 = (*qfnn(fn))(qenv(fn), 4, stack[-3], v0121, v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    goto v0124;

v0124:
    v0119 = stack[-2];
    fn = elt(env, 8); /* vdpred */
    stack[-3] = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    stack[-2] = stack[-5];
    v0120 = qvalue(elt(env, 5)); /* vdpvars!* */
    v0119 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 15); /* vevmaptozero1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    v0119 = stack[-4];
    fn = elt(env, 13); /* vbcneg */
    v0120 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    v0119 = stack[-7];
    fn = elt(env, 16); /* vdpilcomb1 */
    v0119 = (*qfnn(fn))(qenv(fn), 6, stack[-3], stack[-2], stack[-1], stack[0], v0120, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    stack[-2] = v0119;
    v0119 = stack[-6];
    qvalue(elt(env, 2)) = v0119; /* secondvalue!* */
    v0119 = stack[-5];
    qvalue(elt(env, 7)) = v0119; /* thirdvalue!* */
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v0061:
    v0119 = qvalue(elt(env, 1)); /* t */
    goto v0123;

v0021:
    v0119 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 17); /* vbcfi */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[-8];
    goto v0020;

v0096:
    v0119 = qvalue(elt(env, 1)); /* t */
    goto v0103;
/* error exit handlers */
v0122:
    popv(9);
    return nil;
}



/* Code for remove_critical_pairs */

static Lisp_Object CC_remove_critical_pairs(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0005;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove_critical_pairs");
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
    stack[0] = v0001;
    v0093 = v0000;
/* end of prologue */
    v0005 = v0093;
    if (v0005 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v0005 = stack[0];
    fn = elt(env, 1); /* remove_items */
    v0093 = (*qfn2(fn))(qenv(fn), v0005, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v0030:
    popv(1);
    return nil;
}



/* Code for noncom1 */

static Lisp_Object CC_noncom1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0032;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncom1");
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
    v0032 = v0000;
/* end of prologue */
    v0033 = qvalue(elt(env, 1)); /* t */
    qvalue(elt(env, 2)) = v0033; /* !*ncmp */
    v0033 = v0032;
    v0033 = ncons(v0033);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[0];
    v0032 = elt(env, 3); /* noncom */
        popv(1);
        return Lflag(nil, v0033, v0032);
/* error exit handlers */
v0082:
    popv(1);
    return nil;
}



/* Code for coeff1_calc */

static Lisp_Object MS_CDECL CC_coeff1_calc(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0106, v0094, v0067;
    Lisp_Object fn;
    Lisp_Object v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeff1_calc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coeff1_calc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0055;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0022;

v0022:
    v0106 = stack[0];
    if (v0106 == nil) goto v0082;
    v0067 = stack[-2];
    v0094 = stack[-1];
    v0106 = stack[0];
    v0106 = qcar(v0106);
    fn = elt(env, 1); /* calc_coeffmap_ */
    v0094 = (*qfnn(fn))(qenv(fn), 3, v0067, v0094, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-4];
    v0106 = stack[-3];
    v0106 = cons(v0094, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-4];
    stack[-3] = v0106;
    v0106 = stack[0];
    v0106 = qcdr(v0106);
    stack[0] = v0106;
    goto v0022;

v0082:
    stack[0] = stack[-3];
    v0106 = (Lisp_Object)1; /* 0 */
    v0106 = ncons(v0106);
    nil = C_nil;
    if (exception_pending()) goto v0011;
    env = stack[-4];
    {
        Lisp_Object v0019 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0019, v0106);
    }
/* error exit handlers */
v0011:
    popv(5);
    return nil;
}



/* Code for rappend */

static Lisp_Object CC_rappend(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0089;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rappend");
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
    stack[0] = v0000;
/* end of prologue */
    v0089 = elt(env, 1); /* append */
    v0088 = stack[0];
    v0088 = cons(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-3];
    fn = elt(env, 4); /* argnochk */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-3];
    v0088 = stack[0];
    v0088 = qcar(v0088);
    fn = elt(env, 5); /* reval */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-3];
    stack[-2] = v0088;
    fn = elt(env, 6); /* getrtype */
    v0089 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-3];
    v0088 = elt(env, 2); /* list */
    if (v0089 == v0088) goto v0125;
    v0089 = stack[-2];
    v0088 = elt(env, 3); /* "list" */
    fn = elt(env, 7); /* typerr */
    v0088 = (*qfn2(fn))(qenv(fn), v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    goto v0018;

v0018:
    v0088 = nil;
    { popv(4); return onevalue(v0088); }

v0125:
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    fn = elt(env, 5); /* reval */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-3];
    stack[-1] = v0088;
    fn = elt(env, 6); /* getrtype */
    v0089 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    env = stack[-3];
    v0088 = elt(env, 2); /* list */
    if (v0089 == v0088) goto v0127;
    v0089 = stack[-1];
    v0088 = elt(env, 3); /* "list" */
    fn = elt(env, 7); /* typerr */
    v0088 = (*qfn2(fn))(qenv(fn), v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    goto v0018;

v0127:
    stack[0] = elt(env, 2); /* list */
    v0088 = stack[-2];
    v0089 = qcdr(v0088);
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    v0088 = Lappend(nil, v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0059;
    {
        Lisp_Object v0074 = stack[0];
        popv(4);
        return cons(v0074, v0088);
    }
/* error exit handlers */
v0059:
    popv(4);
    return nil;
}



/* Code for dummy_nam */

static Lisp_Object CC_dummy_nam(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dummy_nam");
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
    v0033 = v0000;
/* end of prologue */
    fn = elt(env, 4); /* ordn */
    v0032 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[0];
    v0033 = elt(env, 1); /* symbolic */
    fn = elt(env, 5); /* list2vect!* */
    v0033 = (*qfn2(fn))(qenv(fn), v0032, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[0];
    qvalue(elt(env, 2)) = v0033; /* g_dvnames */
    v0033 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v0033); }
/* error exit handlers */
v0082:
    popv(1);
    return nil;
}



/* Code for vp2df */

static Lisp_Object MS_CDECL CC_vp2df(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0084, v0085;
    Lisp_Object fn;
    Lisp_Object v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vp2df");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vp2df");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0055;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0084 = stack[-2];
    v0105 = elt(env, 1); /* sqrt */
    if (!consp(v0084)) goto v0003;
    v0084 = qcar(v0084);
    if (!(v0084 == v0105)) goto v0003;
    v0084 = stack[-1];
    v0105 = (Lisp_Object)17; /* 1 */
    v0105 = (Lisp_Object)greaterp2(v0084, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    v0105 = v0105 ? lisp_true : nil;
    env = stack[-3];
    goto v0069;

v0069:
    if (v0105 == nil) goto v0034;
    v0085 = stack[-2];
    v0084 = stack[-1];
    v0105 = stack[0];
    fn = elt(env, 3); /* vp1 */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v0085, v0084, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-3];
    v0105 = stack[0];
    fn = elt(env, 4); /* vp2 */
    v0105 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-3];
    {
        Lisp_Object v0058 = stack[-1];
        popv(4);
        fn = elt(env, 5); /* mulpower */
        return (*qfn2(fn))(qenv(fn), v0058, v0105);
    }

v0034:
    v0085 = stack[-2];
    v0084 = stack[-1];
    v0105 = stack[0];
    fn = elt(env, 3); /* vp1 */
    v0085 = (*qfnn(fn))(qenv(fn), 3, v0085, v0084, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-3];
    v0084 = (Lisp_Object)17; /* 1 */
    v0105 = (Lisp_Object)17; /* 1 */
    v0105 = list2star(v0085, v0084, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    popv(4);
    return ncons(v0105);

v0003:
    v0105 = qvalue(elt(env, 2)); /* nil */
    goto v0069;
/* error exit handlers */
v0091:
    popv(4);
    return nil;
}



/* Code for qqe_length!-graph!-neighbors */

static Lisp_Object CC_qqe_lengthKgraphKneighbors(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0092;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-neighbors");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0102 = v0000;
/* end of prologue */
    v0092 = elt(env, 1); /* neighbors */
    return get(v0102, v0092);
}



/* Code for aex_sgn */

static Lisp_Object CC_aex_sgn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_sgn");
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
    stack[0] = v0000;
/* end of prologue */
    v0141 = stack[0];
    fn = elt(env, 6); /* aex_simpleratp */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    if (v0141 == nil) goto v0018;
    v0141 = stack[0];
    fn = elt(env, 7); /* aex_ex */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 8); /* rat_sgn */
        return (*qfn1(fn))(qenv(fn), v0141);
    }

v0018:
    v0141 = qvalue(elt(env, 2)); /* !*rlanuexsgnopt */
    if (v0141 == nil) goto v0098;
    v0141 = stack[0];
    fn = elt(env, 9); /* aex_containment */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    stack[-2] = v0141;
    fn = elt(env, 10); /* rat_0 */
    stack[-1] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    v0141 = stack[-2];
    fn = elt(env, 11); /* iv_lb */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    fn = elt(env, 12); /* rat_less */
    v0141 = (*qfn2(fn))(qenv(fn), stack[-1], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    if (v0141 == nil) goto v0027;
    v0141 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v0141); }

v0027:
    v0141 = stack[-2];
    fn = elt(env, 13); /* iv_rb */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    fn = elt(env, 10); /* rat_0 */
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    fn = elt(env, 12); /* rat_less */
    v0141 = (*qfn2(fn))(qenv(fn), stack[-1], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    if (v0141 == nil) goto v0098;
    v0141 = (Lisp_Object)-15; /* -1 */
    { popv(6); return onevalue(v0141); }

v0098:
    v0141 = stack[0];
    fn = elt(env, 14); /* aex_mvar */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    stack[-4] = v0141;
    v0141 = stack[0];
    fn = elt(env, 15); /* aex_ctx */
    v0122 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    v0141 = stack[-4];
    fn = elt(env, 16); /* ctx_get */
    v0141 = (*qfn2(fn))(qenv(fn), v0122, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    stack[-3] = v0141;
    v0122 = stack[0];
    v0141 = stack[-4];
    fn = elt(env, 17); /* aex_unbind */
    v0141 = (*qfn2(fn))(qenv(fn), v0122, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    fn = elt(env, 18); /* aex_reduce */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    fn = elt(env, 19); /* aex_mklcnt */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    stack[-1] = v0141;
    v0141 = stack[-1];
    fn = elt(env, 6); /* aex_simpleratp */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    if (v0141 == nil) goto v0058;
    v0141 = stack[-1];
    fn = elt(env, 7); /* aex_ex */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 8); /* rat_sgn */
        return (*qfn1(fn))(qenv(fn), v0141);
    }

v0058:
    v0141 = qvalue(elt(env, 3)); /* !*rlverbose */
    if (v0141 == nil) goto v0143;
    v0141 = qvalue(elt(env, 4)); /* !*rlanuexverbose */
    if (v0141 == nil) goto v0143;
    v0122 = stack[-1];
    v0141 = stack[-4];
    fn = elt(env, 20); /* aex_deg */
    v0122 = (*qfn2(fn))(qenv(fn), v0122, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    v0141 = (Lisp_Object)1; /* 0 */
    v0141 = (Lisp_Object)lesseq2(v0122, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    v0141 = v0141 ? lisp_true : nil;
    env = stack[-5];
    if (v0141 == nil) goto v0143;
    v0141 = elt(env, 5); /* "[aex_sgn:num!]" */
    v0141 = Lprinc(nil, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    goto v0143;

v0143:
    v0141 = stack[-3];
    fn = elt(env, 21); /* anu_dp */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    stack[0] = v0141;
    v0122 = v0141;
    v0141 = stack[-4];
    fn = elt(env, 22); /* aex_diff */
    v0122 = (*qfn2(fn))(qenv(fn), v0122, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    v0141 = stack[-1];
    fn = elt(env, 23); /* aex_mult */
    v0122 = (*qfn2(fn))(qenv(fn), v0122, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    v0141 = stack[-4];
    fn = elt(env, 24); /* aex_sturmchain */
    v0141 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0122, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    stack[-2] = v0141;
    stack[-1] = stack[-2];
    stack[0] = stack[-4];
    v0141 = stack[-3];
    fn = elt(env, 25); /* anu_iv */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    fn = elt(env, 11); /* iv_lb */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    fn = elt(env, 26); /* aex_stchsgnch1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    stack[-1] = stack[-2];
    stack[-2] = stack[-4];
    v0141 = stack[-3];
    fn = elt(env, 25); /* anu_iv */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    fn = elt(env, 13); /* iv_rb */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    env = stack[-5];
    fn = elt(env, 26); /* aex_stchsgnch1 */
    v0141 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-2], v0141);
    nil = C_nil;
    if (exception_pending()) goto v0142;
    {
        Lisp_Object v0044 = stack[0];
        popv(6);
        return difference2(v0044, v0141);
    }
/* error exit handlers */
v0142:
    popv(6);
    return nil;
}



/* Code for dipdivmon */

static Lisp_Object MS_CDECL CC_dipdivmon(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0020;
    Lisp_Object fn;
    Lisp_Object v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipdivmon");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipdivmon");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0055;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0022;

v0022:
    v0019 = stack[-2];
    if (v0019 == nil) goto v0102;
    v0019 = stack[-2];
    v0020 = qcar(v0019);
    v0019 = stack[0];
    fn = elt(env, 1); /* evdif */
    v0020 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0019 = stack[-3];
    v0019 = cons(v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    stack[-3] = v0019;
    v0019 = stack[-2];
    v0019 = qcdr(v0019);
    v0020 = qcar(v0019);
    v0019 = stack[-1];
    fn = elt(env, 2); /* bcquot */
    v0020 = (*qfn2(fn))(qenv(fn), v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    v0019 = stack[-3];
    v0019 = cons(v0020, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-4];
    stack[-3] = v0019;
    v0019 = stack[-2];
    v0019 = qcdr(v0019);
    v0019 = qcdr(v0019);
    stack[-2] = v0019;
    goto v0022;

v0102:
    v0019 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0019);
    }
/* error exit handlers */
v0144:
    popv(5);
    return nil;
}



/* Code for vdpenumerate */

static Lisp_Object CC_vdpenumerate(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0012, v0011;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpenumerate");
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
    v0027 = stack[0];
    if (v0027 == nil) goto v0107;
    v0027 = stack[0];
    v0027 = qcdr(v0027);
    v0027 = qcdr(v0027);
    v0027 = qcdr(v0027);
    v0027 = qcar(v0027);
    v0027 = (v0027 == nil ? lisp_true : nil);
    goto v0022;

v0022:
    if (!(v0027 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0027 = stack[0];
    fn = elt(env, 4); /* vdpsave */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    stack[0] = v0027;
    v0012 = stack[0];
    v0027 = elt(env, 2); /* number */
    fn = elt(env, 5); /* vdpgetprop */
    v0027 = (*qfn2(fn))(qenv(fn), v0012, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    if (!(v0027 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0011 = stack[0];
    v0012 = elt(env, 2); /* number */
    v0027 = qvalue(elt(env, 3)); /* pcount!* */
    v0027 = (Lisp_Object)((int32_t)(v0027) + 0x10);
    qvalue(elt(env, 3)) = v0027; /* pcount!* */
    fn = elt(env, 6); /* vdpputprop */
    v0027 = (*qfnn(fn))(qenv(fn), 3, v0011, v0012, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    stack[0] = v0027;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0107:
    v0027 = qvalue(elt(env, 1)); /* t */
    goto v0022;
/* error exit handlers */
v0020:
    popv(2);
    return nil;
}



/* Code for rembras */

static Lisp_Object CC_rembras(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rembras");
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
    v0023 = qvalue(elt(env, 1)); /* !*nat */
    if (v0023 == nil) goto v0098;
    v0023 = stack[0];
    if (!consp(v0023)) goto v0092;
    v0023 = stack[0];
    v0023 = qcar(v0023);
    if (!symbolp(v0023)) v0023 = nil;
    else { v0023 = qfastgets(v0023);
           if (v0023 != nil) { v0023 = elt(v0023, 23); /* infix */
#ifdef RECORD_GET
             if (v0023 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0023 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0023 == SPID_NOPROP) v0023 = nil; }}
#endif
    v0023 = (v0023 == nil ? lisp_true : nil);
    goto v0102;

v0102:
    if (v0023 == nil) goto v0098;
    v0023 = elt(env, 3); /* " " */
    fn = elt(env, 6); /* prin2!* */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0023 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); /* maprin */
        return (*qfn1(fn))(qenv(fn), v0023);
    }

v0098:
    v0023 = elt(env, 4); /* "(" */
    fn = elt(env, 6); /* prin2!* */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0023 = stack[0];
    fn = elt(env, 7); /* maprin */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0023 = elt(env, 5); /* ")" */
    {
        popv(2);
        fn = elt(env, 6); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v0023);
    }

v0092:
    v0023 = qvalue(elt(env, 2)); /* t */
    goto v0102;
/* error exit handlers */
v0010:
    popv(2);
    return nil;
}



/* Code for minprec */

static Lisp_Object MS_CDECL CC_minprec(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "minprec");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minprec");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0102 = qvalue(elt(env, 1)); /* !*bftag */
    if (v0102 == nil) goto v0022;
    v0102 = qvalue(elt(env, 2)); /* !:prec!: */
    return onevalue(v0102);

v0022:
    v0102 = qvalue(elt(env, 3)); /* !!nfpd */
    return onevalue(v0102);
}



/* Code for expt!-separate */

static Lisp_Object CC_exptKseparate(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0076, v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expt-separate");
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
    v0076 = stack[-1];
    v0126 = elt(env, 1); /* expt */
    if (!consp(v0076)) goto v0069;
    v0076 = qcar(v0076);
    if (!(v0076 == v0126)) goto v0069;
    v0126 = stack[-1];
    v0126 = qcdr(v0126);
    v0076 = qcar(v0126);
    v0126 = stack[0];
    fn = elt(env, 5); /* depends */
    v0126 = (*qfn2(fn))(qenv(fn), v0076, v0126);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-2];
    if (!(v0126 == nil)) goto v0107;
    v0126 = stack[-1];
    v0126 = qcdr(v0126);
    v0126 = qcdr(v0126);
    v0076 = qcar(v0126);
    v0126 = elt(env, 3); /* plus */
    v0126 = Leqcar(nil, v0076, v0126);
    env = stack[-2];
    v0126 = (v0126 == nil ? lisp_true : nil);
    goto v0107;

v0107:
    if (v0126 == nil) goto v0012;
    v0126 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v0126); }

v0012:
    v0126 = stack[-1];
    v0126 = qcdr(v0126);
    v0126 = qcdr(v0126);
    v0126 = qcar(v0126);
    v0077 = qcdr(v0126);
    v0126 = stack[-1];
    v0126 = qcdr(v0126);
    v0076 = qcar(v0126);
    v0126 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* expt!-separate1 */
        return (*qfnn(fn))(qenv(fn), 3, v0077, v0076, v0126);
    }

v0069:
    v0126 = qvalue(elt(env, 2)); /* t */
    goto v0107;
/* error exit handlers */
v0128:
    popv(3);
    return nil;
}



/* Code for coeff_ordn1 */

static Lisp_Object CC_coeff_ordn1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0026, v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coeff_ordn1");
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

v0104:
    v0025 = stack[-1];
    if (v0025 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0025 = stack[-1];
    v0144 = qcar(v0025);
    v0025 = stack[-1];
    v0026 = qcdr(v0025);
    v0025 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* p_subsatlaslist */
    v0025 = (*qfnn(fn))(qenv(fn), 3, v0144, v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    v0026 = v0025;
    v0025 = v0026;
    if (v0025 == nil) goto v0013;
    v0025 = stack[0];
    stack[-1] = v0026;
    stack[0] = v0025;
    goto v0104;

v0013:
    v0025 = stack[-1];
    stack[-2] = qcdr(v0025);
    v0025 = stack[-1];
    v0026 = qcar(v0025);
    v0025 = stack[0];
    v0025 = cons(v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v0025;
    goto v0104;
/* error exit handlers */
v0035:
    popv(4);
    return nil;
}



/* Code for !*ex2sf */

static Lisp_Object CC_Hex2sf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *ex2sf");
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
    goto v0057;

v0057:
    v0026 = stack[-1];
    if (v0026 == nil) goto v0107;
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    if (v0026 == nil) goto v0030;
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0026 = qcar(v0026);
    v0144 = qcar(v0026);
    v0026 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* to */
    stack[0] = (*qfn2(fn))(qenv(fn), v0144, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0026 = qcdr(v0026);
    fn = elt(env, 2); /* subs2chk */
    v0144 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    v0026 = stack[-2];
    v0026 = acons(stack[0], v0144, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    stack[-2] = v0026;
    v0026 = stack[-1];
    v0026 = qcdr(v0026);
    stack[-1] = v0026;
    goto v0057;

v0030:
    stack[0] = stack[-2];
    v0026 = stack[-1];
    v0026 = qcar(v0026);
    v0026 = qcdr(v0026);
    fn = elt(env, 2); /* subs2chk */
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0035;
    env = stack[-3];
    {
        Lisp_Object v0036 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0036, v0026);
    }

v0107:
    v0026 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0026);
    }
/* error exit handlers */
v0035:
    popv(4);
    return nil;
}



/* Code for fs!:onep */

static Lisp_Object CC_fsTonep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:onep");
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
    v0026 = stack[0];
    v0025 = (Lisp_Object)49; /* 3 */
    v0025 = *(Lisp_Object *)((char *)v0026 + (CELL-TAG_VECTOR) + ((int32_t)v0025/(16/CELL)));
    if (v0025 == nil) goto v0006;
    v0025 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0025); }

v0006:
    v0026 = stack[0];
    v0025 = (Lisp_Object)1; /* 0 */
    v0025 = *(Lisp_Object *)((char *)v0026 + (CELL-TAG_VECTOR) + ((int32_t)v0025/(16/CELL)));
    v0025 = Lonep(nil, v0025);
    env = stack[-1];
    if (v0025 == nil) goto v0018;
    v0025 = stack[0];
    fn = elt(env, 3); /* fs!:null!-angle */
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-1];
    if (v0025 == nil) goto v0063;
    v0026 = stack[0];
    v0025 = (Lisp_Object)17; /* 1 */
    v0025 = *(Lisp_Object *)((char *)v0026 + (CELL-TAG_VECTOR) + ((int32_t)v0025/(16/CELL)));
    v0026 = elt(env, 2); /* cos */
    v0025 = (v0025 == v0026 ? lisp_true : nil);
    { popv(2); return onevalue(v0025); }

v0063:
    v0025 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0025); }

v0018:
    v0025 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0025); }
/* error exit handlers */
v0095:
    popv(2);
    return nil;
}



/* Code for distri_pol */

static Lisp_Object CC_distri_pol(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for distri_pol");
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
    v0049 = stack[-1];
    if (v0049 == nil) goto v0056;
    v0049 = stack[-1];
    if (!consp(v0049)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0049 = stack[-1];
    v0049 = qcdr(v0049);
    if (v0049 == nil) goto v0101;
    v0049 = stack[-1];
    v0049 = qcar(v0049);
    v0049 = ncons(v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    stack[0] = CC_distri_pol(env, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    v0049 = stack[-1];
    v0049 = qcdr(v0049);
    v0049 = CC_distri_pol(env, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    {
        Lisp_Object v0152 = stack[0];
        popv(4);
        fn = elt(env, 2); /* addfd */
        return (*qfn2(fn))(qenv(fn), v0152, v0049);
    }

v0101:
    v0049 = (Lisp_Object)17; /* 1 */
    stack[0] = v0049;
    v0049 = stack[-1];
    stack[-2] = v0049;
    goto v0125;

v0125:
    v0049 = stack[-2];
    if (!consp(v0049)) goto v0011;
    v0049 = stack[-2];
    v0049 = qcdr(v0049);
    v0049 = (v0049 == nil ? lisp_true : nil);
    goto v0106;

v0106:
    if (v0049 == nil) goto v0029;
    v0049 = stack[-2];
    v0049 = qcar(v0049);
    v0048 = qcar(v0049);
    v0049 = (Lisp_Object)17; /* 1 */
    v0049 = cons(v0048, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    v0049 = ncons(v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v0049 = (*qfn2(fn))(qenv(fn), stack[0], v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    stack[0] = v0049;
    v0049 = stack[-2];
    v0049 = qcar(v0049);
    v0049 = qcdr(v0049);
    stack[-2] = v0049;
    goto v0125;

v0029:
    v0049 = stack[-2];
    if (!consp(v0049)) goto v0074;
    stack[-1] = stack[0];
    v0049 = stack[-2];
    v0049 = qcar(v0049);
    v0049 = ncons(v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    v0049 = CC_distri_pol(env, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v0049 = (*qfn2(fn))(qenv(fn), stack[-1], v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    stack[-1] = CC_distri_pol(env, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    v0049 = stack[-2];
    v0049 = qcdr(v0049);
    v0049 = CC_distri_pol(env, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    fn = elt(env, 3); /* multf */
    v0049 = (*qfn2(fn))(qenv(fn), stack[0], v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    v0049 = CC_distri_pol(env, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0151;
    env = stack[-3];
    {
        Lisp_Object v0135 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* addfd */
        return (*qfn2(fn))(qenv(fn), v0135, v0049);
    }

v0074:
    v0048 = stack[0];
    v0049 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* multf */
        return (*qfn2(fn))(qenv(fn), v0048, v0049);
    }

v0011:
    v0049 = qvalue(elt(env, 1)); /* nil */
    goto v0106;

v0056:
    v0049 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0049); }
/* error exit handlers */
v0151:
    popv(4);
    return nil;
}



/* Code for x!*!*p!-w */

static Lisp_Object MS_CDECL CC_xHHpKw(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0003;
    Lisp_Object fn;
    Lisp_Object v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "x**p-w");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for x**p-w");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0055;
    v0002 = v0001;
    v0003 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* to */
    v0003 = (*qfn2(fn))(qenv(fn), v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-1];
    v0002 = (Lisp_Object)17; /* 1 */
    v0002 = cons(v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-1];
    v0003 = ncons(v0002);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[-1];
    v0002 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* general!-difference!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0003, v0002);
    }
/* error exit handlers */
v0007:
    popv(2);
    return nil;
}



/* Code for qroundup */

static Lisp_Object CC_qroundup(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0037;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qroundup");
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
    v0037 = stack[-1];
    v0078 = (Lisp_Object)1; /* 0 */
    v0078 = (Lisp_Object)lessp2(v0037, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    v0078 = v0078 ? lisp_true : nil;
    env = stack[-2];
    if (v0078 == nil) goto v0099;
    v0078 = stack[-1];
    v0037 = negate(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    v0078 = stack[0];
    v0078 = quot2(v0037, v0078);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    popv(3);
    return negate(v0078);

v0099:
    v0078 = stack[0];
    v0078 = sub1(v0078);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-2];
    v0037 = plus2(stack[-1], v0078);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    v0078 = stack[0];
    popv(3);
    return quot2(v0037, v0078);
/* error exit handlers */
v0067:
    popv(3);
    return nil;
}



/* Code for ofsf_translat2 */

static Lisp_Object MS_CDECL CC_ofsf_translat2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0026, v0144, v0095, v0127;
    Lisp_Object fn;
    Lisp_Object v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_translat2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_translat2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0025 = v0055;
    v0026 = v0001;
    v0095 = v0000;
/* end of prologue */
    v0144 = v0026;
    v0144 = qcar(v0144);
    if (v0144 == nil) goto v0032;
    v0127 = v0095;
    v0144 = v0026;
    v0095 = qcar(v0144);
    v0144 = v0026;
    v0144 = qcdr(v0144);
    v0144 = qcar(v0144);
    v0026 = qcdr(v0026);
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    {
        fn = elt(env, 2); /* ofsf_translatqua */
        return (*qfnn(fn))(qenv(fn), 5, v0127, v0095, v0144, v0026, v0025);
    }

v0032:
    v0144 = v0026;
    v0144 = qcdr(v0144);
    v0144 = qcar(v0144);
    v0026 = qcdr(v0026);
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    v0127 = v0025;
    v0025 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 3); /* ofsf_translatlin */
        return (*qfnn(fn))(qenv(fn), 5, v0095, v0144, v0026, v0127, v0025);
    }
}



/* Code for put!-avalue */

static Lisp_Object MS_CDECL CC_putKavalue(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0157, v0117, v0038;
    Lisp_Object fn;
    Lisp_Object v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "put-avalue");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for put-avalue");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0055;
    stack[-2] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0117 = stack[-2];
    v0157 = elt(env, 1); /* scalar */
    if (v0117 == v0157) goto v0016;
    v0117 = stack[0];
    v0157 = stack[-1];
    fn = elt(env, 7); /* smember */
    v0157 = (*qfn2(fn))(qenv(fn), v0117, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    if (v0157 == nil) goto v0061;
    v0157 = stack[0];
    {
        popv(5);
        fn = elt(env, 8); /* recursiveerror */
        return (*qfn1(fn))(qenv(fn), v0157);
    }

v0061:
    stack[-3] = stack[0];
    stack[0] = elt(env, 6); /* avalue */
    v0117 = stack[-2];
    v0157 = stack[-1];
    v0157 = list2(v0117, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    {
        Lisp_Object v0047 = stack[-3];
        Lisp_Object v0049 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v0047, v0049, v0157);
    }

v0016:
    v0117 = stack[-1];
    v0157 = elt(env, 2); /* !*sq */
    if (!consp(v0117)) goto v0013;
    v0117 = qcar(v0117);
    if (!(v0117 == v0157)) goto v0013;
    v0117 = stack[0];
    v0157 = stack[-1];
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    fn = elt(env, 9); /* sq_member */
    v0157 = (*qfn2(fn))(qenv(fn), v0117, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-4];
    goto v0030;

v0030:
    if (v0157 == nil) goto v0005;
    v0157 = stack[0];
    {
        popv(5);
        fn = elt(env, 8); /* recursiveerror */
        return (*qfn1(fn))(qenv(fn), v0157);
    }

v0005:
    v0157 = qvalue(elt(env, 4)); /* !*reduce4 */
    if (v0157 == nil) goto v0035;
    v0038 = stack[0];
    v0117 = stack[-1];
    v0157 = elt(env, 5); /* generic */
    {
        popv(5);
        fn = elt(env, 10); /* putobject */
        return (*qfnn(fn))(qenv(fn), 3, v0038, v0117, v0157);
    }

v0035:
    stack[-3] = stack[0];
    stack[0] = elt(env, 6); /* avalue */
    v0117 = stack[-2];
    v0157 = stack[-1];
    v0157 = list2(v0117, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    {
        Lisp_Object v0048 = stack[-3];
        Lisp_Object v0040 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v0048, v0040, v0157);
    }

v0013:
    v0157 = qvalue(elt(env, 3)); /* nil */
    goto v0030;
/* error exit handlers */
v0158:
    popv(5);
    return nil;
}



/* Code for makecoeffpairs1 */

static Lisp_Object MS_CDECL CC_makecoeffpairs1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0179, v0180, v0181;
    Lisp_Object fn;
    Lisp_Object v0004, v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "makecoeffpairs1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for makecoeffpairs1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0055,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v0004;
    stack[-11] = v0055;
    stack[-12] = v0001;
    stack[-13] = v0000;
/* end of prologue */
    v0178 = stack[-12];
    if (v0178 == nil) goto v0022;
    v0178 = stack[-13];
    v0181 = qcdr(v0178);
    v0178 = stack[-12];
    v0180 = qcdr(v0178);
    v0178 = stack[-11];
    v0179 = qcdr(v0178);
    v0178 = stack[-10];
    v0178 = qcdr(v0178);
    v0178 = CC_makecoeffpairs1(env, 4, v0181, v0180, v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    stack[-14] = v0178;
    goto v0005;

v0005:
    v0178 = stack[-14];
    if (v0178 == nil) goto v0014;
    v0178 = stack[-14];
    v0178 = qcar(v0178);
    stack[-6] = v0178;
    v0178 = stack[-13];
    stack[-2] = qcar(v0178);
    v0178 = stack[-12];
    stack[-1] = qcar(v0178);
    v0178 = stack[-11];
    stack[0] = qcar(v0178);
    v0178 = stack[-10];
    v0178 = qcar(v0178);
    fn = elt(env, 3); /* tayexp!-minus */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    fn = elt(env, 4); /* makecoeffpairshom */
    v0178 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    stack[-5] = v0178;
    v0178 = stack[-5];
    if (v0178 == nil) goto v0105;
    v0178 = stack[-5];
    v0178 = qcar(v0178);
    v0179 = v0178;
    v0178 = v0179;
    stack[-1] = qcar(v0178);
    v0178 = stack[-6];
    stack[0] = qcar(v0178);
    v0178 = v0179;
    v0179 = qcdr(v0178);
    v0178 = stack[-6];
    v0178 = qcdr(v0178);
    v0178 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = acons(stack[-1], stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    stack[-3] = v0178;
    stack[-4] = v0178;
    goto v0011;

v0011:
    v0178 = stack[-5];
    v0178 = qcdr(v0178);
    stack[-5] = v0178;
    v0178 = stack[-5];
    if (v0178 == nil) goto v0183;
    stack[-2] = stack[-3];
    v0178 = stack[-5];
    v0178 = qcar(v0178);
    v0179 = v0178;
    v0178 = v0179;
    stack[-1] = qcar(v0178);
    v0178 = stack[-6];
    stack[0] = qcar(v0178);
    v0178 = v0179;
    v0179 = qcdr(v0178);
    v0178 = stack[-6];
    v0178 = qcdr(v0178);
    v0178 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = acons(stack[-1], stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = Lrplacd(nil, stack[-2], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    stack[-3] = v0178;
    goto v0011;

v0183:
    v0178 = stack[-4];
    goto v0012;

v0012:
    stack[-9] = v0178;
    v0178 = stack[-9];
    fn = elt(env, 5); /* lastpair */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    stack[-8] = v0178;
    v0178 = stack[-14];
    v0178 = qcdr(v0178);
    stack[-14] = v0178;
    v0178 = stack[-8];
    if (!consp(v0178)) goto v0005;
    else goto v0006;

v0006:
    v0178 = stack[-14];
    if (v0178 == nil) { Lisp_Object res = stack[-9]; popv(16); return onevalue(res); }
    stack[-7] = stack[-8];
    v0178 = stack[-14];
    v0178 = qcar(v0178);
    stack[-6] = v0178;
    v0178 = stack[-13];
    stack[-2] = qcar(v0178);
    v0178 = stack[-12];
    stack[-1] = qcar(v0178);
    v0178 = stack[-11];
    stack[0] = qcar(v0178);
    v0178 = stack[-10];
    v0178 = qcar(v0178);
    fn = elt(env, 3); /* tayexp!-minus */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    fn = elt(env, 4); /* makecoeffpairshom */
    v0178 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    stack[-5] = v0178;
    v0178 = stack[-5];
    if (v0178 == nil) goto v0184;
    v0178 = stack[-5];
    v0178 = qcar(v0178);
    v0179 = v0178;
    v0178 = v0179;
    stack[-1] = qcar(v0178);
    v0178 = stack[-6];
    stack[0] = qcar(v0178);
    v0178 = v0179;
    v0179 = qcdr(v0178);
    v0178 = stack[-6];
    v0178 = qcdr(v0178);
    v0178 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = acons(stack[-1], stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    stack[-3] = v0178;
    stack[-4] = v0178;
    goto v0141;

v0141:
    v0178 = stack[-5];
    v0178 = qcdr(v0178);
    stack[-5] = v0178;
    v0178 = stack[-5];
    if (v0178 == nil) goto v0185;
    stack[-2] = stack[-3];
    v0178 = stack[-5];
    v0178 = qcar(v0178);
    v0179 = v0178;
    v0178 = v0179;
    stack[-1] = qcar(v0178);
    v0178 = stack[-6];
    stack[0] = qcar(v0178);
    v0178 = v0179;
    v0179 = qcdr(v0178);
    v0178 = stack[-6];
    v0178 = qcdr(v0178);
    v0178 = cons(v0179, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = acons(stack[-1], stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = ncons(v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = Lrplacd(nil, stack[-2], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = stack[-3];
    v0178 = qcdr(v0178);
    stack[-3] = v0178;
    goto v0141;

v0185:
    v0178 = stack[-4];
    goto v0186;

v0186:
    v0178 = Lrplacd(nil, stack[-7], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    v0178 = stack[-8];
    fn = elt(env, 5); /* lastpair */
    v0178 = (*qfn1(fn))(qenv(fn), v0178);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-15];
    stack[-8] = v0178;
    v0178 = stack[-14];
    v0178 = qcdr(v0178);
    stack[-14] = v0178;
    goto v0006;

v0184:
    v0178 = qvalue(elt(env, 2)); /* nil */
    goto v0186;

v0105:
    v0178 = qvalue(elt(env, 2)); /* nil */
    goto v0012;

v0014:
    v0178 = qvalue(elt(env, 2)); /* nil */
    { popv(16); return onevalue(v0178); }

v0022:
    v0178 = elt(env, 1); /* ((nil)) */
    { popv(16); return onevalue(v0178); }
/* error exit handlers */
v0182:
    popv(16);
    return nil;
}



/* Code for qqe_length!-graph!-marked */

static Lisp_Object CC_qqe_lengthKgraphKmarked(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0092;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_length-graph-marked");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0102 = v0000;
/* end of prologue */
    v0092 = elt(env, 1); /* blockmark */
    return get(v0102, v0092);
}



/* Code for pasf_smeqtable */

static Lisp_Object CC_pasf_smeqtable(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0016, v0098;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smeqtable");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0096 = v0001;
    v0016 = v0000;
/* end of prologue */
    v0098 = elt(env, 1); /* ((equal (equal 1) (neq false) (geq 1) (leq 1) (greaterp false) (lessp false) (cong 1) (ncong false)) (neq (equal false) (neq 1) (geq 3 . greaterp) (leq 3 . lessp) (greaterp
 2) (lessp 2) (cong nil) (ncong 2)) (geq (equal 2) (neq 3 . greaterp) (geq 1) (leq 3 . equal) (greaterp 2) (lessp false) (cong nil) (ncong 5 . greaterp)) (leq (equal 2) (neq 3 . lessp) (geq 3 . equal)
 (leq 1) (greaterp false) (lessp 2) (cong nil) (ncong 5 . lessp)) (greaterp (equal false) (neq 1) (geq 1) (leq false) (greaterp 1) (lessp false) (cong nil) (ncong nil)) (lessp (equal false) (neq 1) (g
eq false) (leq 1) (greaterp false) (lessp 1) (cong nil) (ncong nil)) (cong (equal 2) (neq nil) (geq nil) (leq nil) (greaterp nil) (lessp nil) (cong 1) (ncong false)) (ncong (equal false) (neq 1) (geq 
4 . greaterp) (leq 4 . lessp) (greaterp nil) (lessp nil) (cong false) (ncong 1))) 
*/
    v0016 = Latsoc(nil, v0016, v0098);
    v0096 = Latsoc(nil, v0096, v0016);
    v0096 = qcdr(v0096);
    return onevalue(v0096);
}



/* Code for mkarg */

static Lisp_Object CC_mkarg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0150, v0143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkarg");
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
    v0150 = stack[-1];
    if (v0150 == nil) goto v0069;
    v0150 = stack[-1];
    v0150 = Lconstantp(nil, v0150);
    env = stack[-3];
    goto v0107;

v0107:
    if (!(v0150 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0150 = stack[-1];
    if (!consp(v0150)) goto v0098;
    v0150 = stack[-1];
    v0143 = qcar(v0150);
    v0150 = elt(env, 2); /* (quote !:dn!: !:int!:) */
    v0150 = Lmemq(nil, v0143, v0150);
    if (v0150 == nil) goto v0012;
    v0150 = stack[-1];
        popv(4);
        return Lmkquote(nil, v0150);

v0012:
    stack[-2] = nil;
    goto v0024;

v0024:
    v0150 = stack[-1];
    if (v0150 == nil) goto v0035;
    v0150 = stack[-1];
    v0143 = qcar(v0150);
    v0150 = stack[0];
    v0143 = CC_mkarg(env, v0143, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    v0150 = stack[-2];
    v0150 = cons(v0143, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-3];
    stack[-2] = v0150;
    v0150 = stack[-1];
    v0150 = qcdr(v0150);
    stack[-1] = v0150;
    goto v0024;

v0035:
    stack[0] = elt(env, 3); /* list */
    v0150 = stack[-2];
    fn = elt(env, 4); /* reversip!* */
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    {
        Lisp_Object v0061 = stack[0];
        popv(4);
        return cons(v0061, v0150);
    }

v0098:
    v0143 = stack[-1];
    v0150 = stack[0];
    v0150 = Latsoc(nil, v0143, v0150);
    if (!(v0150 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0150 = stack[-1];
        popv(4);
        return Lmkquote(nil, v0150);

v0069:
    v0150 = qvalue(elt(env, 1)); /* t */
    goto v0107;
/* error exit handlers */
v0123:
    popv(4);
    return nil;
}



/* Code for ldf!-pow!-var */

static Lisp_Object CC_ldfKpowKvar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0080, v0081, v0150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldf-pow-var");
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
    v0080 = v0000;
/* end of prologue */
    v0081 = nil;
    stack[-2] = nil;
    stack[-1] = v0080;
    goto v0069;

v0069:
    v0080 = stack[-1];
    if (v0080 == nil) goto v0107;
    v0080 = stack[-1];
    v0080 = qcar(v0080);
    stack[0] = v0081;
    v0080 = qcdr(v0080);
    fn = elt(env, 5); /* kernels */
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0080 = Lappend(nil, stack[0], v0080);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    v0081 = v0080;
    v0080 = stack[-1];
    v0080 = qcdr(v0080);
    stack[-1] = v0080;
    goto v0069;

v0107:
    v0080 = v0081;
    fn = elt(env, 6); /* makeset */
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    fn = elt(env, 7); /* prlist */
    v0080 = (*qfn1(fn))(qenv(fn), v0080);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    stack[0] = v0080;
    goto v0010;

v0010:
    v0080 = stack[0];
    if (v0080 == nil) goto v0009;
    v0080 = stack[0];
    v0080 = qcar(v0080);
    v0150 = v0080;
    v0081 = v0150;
    v0080 = elt(env, 2); /* x */
    if (!consp(v0081)) goto v0076;
    v0081 = qcar(v0081);
    if (!(v0081 == v0080)) goto v0076;
    v0080 = qvalue(elt(env, 3)); /* t */
    goto v0019;

v0019:
    if (v0080 == nil) goto v0028;
    v0081 = v0150;
    v0080 = stack[-2];
    v0080 = cons(v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-3];
    stack[-2] = v0080;
    goto v0028;

v0028:
    v0080 = stack[0];
    v0080 = qcdr(v0080);
    stack[0] = v0080;
    goto v0010;

v0076:
    v0081 = v0150;
    v0080 = elt(env, 4); /* u */
    v0080 = Leqcar(nil, v0081, v0080);
    env = stack[-3];
    goto v0019;

v0009:
    v0080 = stack[-2];
    {
        popv(4);
        fn = elt(env, 6); /* makeset */
        return (*qfn1(fn))(qenv(fn), v0080);
    }
/* error exit handlers */
v0060:
    popv(4);
    return nil;
}



/* Code for vdpvbcprod */

static Lisp_Object CC_vdpvbcprod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpvbcprod");
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
    v0009 = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0010 = stack[0];
    v0010 = qcdr(v0010);
    v0010 = qcdr(v0010);
    v0010 = qcdr(v0010);
    v0010 = qcar(v0010);
    fn = elt(env, 2); /* dipbcprod */
    v0009 = (*qfn2(fn))(qenv(fn), v0010, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    fn = elt(env, 3); /* dip2vdp */
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0010 = v0009;
    v0009 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v0009 == nil) { popv(3); return onevalue(v0010); }
    stack[-1] = v0010;
    v0009 = stack[0];
    fn = elt(env, 4); /* gsugar */
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    {
        Lisp_Object v0125 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* gsetsugar */
        return (*qfn2(fn))(qenv(fn), v0125, v0009);
    }
/* error exit handlers */
v0029:
    popv(3);
    return nil;
}



/* Code for r2oreaction */

static Lisp_Object MS_CDECL CC_r2oreaction(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0131, v0193;
    Lisp_Object fn;
    Lisp_Object v0004, v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "r2oreaction");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for r2oreaction");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0055,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0004;
    v0108 = v0055;
    stack[-5] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    stack[-6] = v0108;
    v0108 = stack[-1];
    stack[-2] = v0108;
    goto v0032;

v0032:
    v0108 = stack[-2];
    if (v0108 == nil) goto v0033;
    v0108 = stack[-2];
    v0108 = qcar(v0108);
    stack[0] = elt(env, 2); /* times */
    stack[-3] = stack[-6];
    v0193 = elt(env, 3); /* expt */
    v0131 = v0108;
    v0131 = qcdr(v0131);
    v0108 = qcar(v0108);
    v0108 = list3(v0193, v0131, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    v0108 = list3(stack[0], stack[-3], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    fn = elt(env, 6); /* aeval */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    stack[-6] = v0108;
    v0108 = stack[-2];
    v0108 = qcdr(v0108);
    stack[-2] = v0108;
    goto v0032;

v0033:
    v0108 = stack[-1];
    stack[-3] = v0108;
    goto v0019;

v0019:
    v0108 = stack[-3];
    if (v0108 == nil) goto v0011;
    v0108 = stack[-3];
    v0108 = qcar(v0108);
    v0131 = v0108;
    v0193 = qcdr(v0131);
    v0131 = stack[-4];
    v0131 = Lassoc(nil, v0193, v0131);
    stack[-2] = v0131;
    stack[-1] = elt(env, 4); /* difference */
    stack[0] = qcdr(v0131);
    v0193 = elt(env, 2); /* times */
    v0131 = stack[-6];
    v0108 = qcar(v0108);
    v0108 = list3(v0193, v0131, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    v0108 = list3(stack[-1], stack[0], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    fn = elt(env, 7); /* reval */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    v0108 = Lrplacd(nil, stack[-2], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    v0108 = stack[-3];
    v0108 = qcdr(v0108);
    stack[-3] = v0108;
    goto v0019;

v0011:
    v0108 = stack[-5];
    stack[-3] = v0108;
    goto v0194;

v0194:
    v0108 = stack[-3];
    if (v0108 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v0108 = stack[-3];
    v0108 = qcar(v0108);
    v0131 = v0108;
    v0193 = qcdr(v0131);
    v0131 = stack[-4];
    v0131 = Lassoc(nil, v0193, v0131);
    stack[-2] = v0131;
    stack[-1] = elt(env, 5); /* plus */
    stack[0] = qcdr(v0131);
    v0193 = elt(env, 2); /* times */
    v0131 = stack[-6];
    v0108 = qcar(v0108);
    v0108 = list3(v0193, v0131, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    v0108 = list3(stack[-1], stack[0], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    fn = elt(env, 7); /* reval */
    v0108 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    v0108 = Lrplacd(nil, stack[-2], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0132;
    env = stack[-7];
    v0108 = stack[-3];
    v0108 = qcdr(v0108);
    stack[-3] = v0108;
    goto v0194;
/* error exit handlers */
v0132:
    popv(8);
    return nil;
}



/* Code for basisvectorp */

static Lisp_Object CC_basisvectorp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for basisvectorp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0006 = v0000;
/* end of prologue */
    v0005 = v0006;
    if (!consp(v0005)) goto v0017;
    v0005 = v0006;
    v0006 = qvalue(elt(env, 1)); /* basisvectorl!* */
    v0005 = Lmemq(nil, v0005, v0006);
    return onevalue(v0005);

v0017:
    v0005 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0005);
}



/* Code for mk!-strand!-vertex */

static Lisp_Object CC_mkKstrandKvertex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086, v0087, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk-strand-vertex");
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
    v0086 = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0126 = stack[-2];
    v0087 = v0086;
    v0086 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* incident */
    v0086 = (*qfnn(fn))(qenv(fn), 3, v0126, v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-4];
    v0087 = v0086;
    v0086 = v0087;
    v0086 = qcar(v0086);
    stack[-3] = v0086;
    stack[-1] = stack[-2];
    v0086 = v0087;
    stack[0] = qcdr(v0086);
    v0086 = stack[-3];
    v0086 = qcar(v0086);
    v0086 = qcdr(v0086);
    v0086 = add1(v0086);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-4];
    fn = elt(env, 1); /* incident */
    v0086 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0086);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-4];
    v0087 = v0086;
    v0086 = v0087;
    if (v0086 == nil) goto v0078;
    v0086 = v0087;
    v0086 = qcar(v0086);
    goto v0021;

v0021:
    v0126 = stack[-2];
    v0087 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* mk!-strand!-vertex2 */
        return (*qfnn(fn))(qenv(fn), 3, v0126, v0087, v0086);
    }

v0078:
    v0087 = stack[-2];
    v0086 = (Lisp_Object)1; /* 0 */
    v0086 = cons(v0087, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-4];
    v0086 = ncons(v0086);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-4];
    goto v0021;
/* error exit handlers */
v0128:
    popv(5);
    return nil;
}



/* Code for horner!-rule!-in!-order!-mod!-p */

static Lisp_Object MS_CDECL CC_hornerKruleKinKorderKmodKp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0197, v0191, v0190, v0112, v0113;
    Lisp_Object fn;
    Lisp_Object v0004, v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "horner-rule-in-order-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    v0004 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for horner-rule-in-order-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0004,v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0055,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0055;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */

v0104:
    v0197 = stack[-1];
    if (!consp(v0197)) goto v0092;
    v0197 = stack[-1];
    v0197 = qcar(v0197);
    v0197 = (consp(v0197) ? nil : lisp_true);
    goto v0102;

v0102:
    if (v0197 == nil) goto v0067;
    v0197 = stack[-1];
    fn = elt(env, 2); /* !*d2n */
    v0112 = (*qfn1(fn))(qenv(fn), v0197);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-5];
    v0190 = stack[-3];
    v0197 = stack[0];
    v0197 = qcar(v0197);
    v0191 = qcdr(v0197);
    v0197 = stack[-2];
    v0197 = Lmodular_expt(nil, v0191, v0197);
    env = stack[-5];
    v0197 = Lmodular_times(nil, v0190, v0197);
    {   int32_t w = int_of_fixnum(v0112) + int_of_fixnum(v0197);
        if (w >= current_modulus) w -= current_modulus;
        v0197 = fixnum_of_int(w);
    }
    { popv(6); return onevalue(v0197); }

v0067:
    v0197 = stack[-1];
    v0197 = qcar(v0197);
    v0197 = qcar(v0197);
    v0191 = qcar(v0197);
    v0197 = stack[0];
    v0197 = qcar(v0197);
    v0197 = qcar(v0197);
    if (equal(v0191, v0197)) goto v0176;
    v0191 = stack[-1];
    v0197 = stack[0];
    v0197 = qcdr(v0197);
    fn = elt(env, 3); /* evaluate!-in!-order!-mod!-p */
    v0112 = (*qfn2(fn))(qenv(fn), v0191, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-5];
    v0190 = stack[-3];
    v0197 = stack[0];
    v0197 = qcar(v0197);
    v0191 = qcdr(v0197);
    v0197 = stack[-2];
    v0197 = Lmodular_expt(nil, v0191, v0197);
    env = stack[-5];
    v0197 = Lmodular_times(nil, v0190, v0197);
    {   int32_t w = int_of_fixnum(v0112) + int_of_fixnum(v0197);
        if (w >= current_modulus) w -= current_modulus;
        v0197 = fixnum_of_int(w);
    }
    { popv(6); return onevalue(v0197); }

v0176:
    v0197 = stack[-1];
    v0197 = qcar(v0197);
    v0197 = qcar(v0197);
    v0197 = qcdr(v0197);
    stack[-4] = v0197;
    v0197 = stack[-1];
    v0197 = qcar(v0197);
    v0191 = qcdr(v0197);
    v0197 = stack[0];
    v0197 = qcdr(v0197);
    fn = elt(env, 3); /* evaluate!-in!-order!-mod!-p */
    v0113 = (*qfn2(fn))(qenv(fn), v0191, v0197);
    nil = C_nil;
    if (exception_pending()) goto v0193;
    env = stack[-5];
    v0112 = stack[-3];
    v0197 = stack[0];
    v0197 = qcar(v0197);
    v0190 = qcdr(v0197);
    v0191 = stack[-2];
    v0197 = stack[-4];
    v0197 = (Lisp_Object)(int32_t)((int32_t)v0191 - (int32_t)v0197 + TAG_FIXNUM);
    v0197 = Lmodular_expt(nil, v0190, v0197);
    env = stack[-5];
    v0197 = Lmodular_times(nil, v0112, v0197);
    env = stack[-5];
    {   int32_t w = int_of_fixnum(v0113) + int_of_fixnum(v0197);
        if (w >= current_modulus) w -= current_modulus;
        v0112 = fixnum_of_int(w);
    }
    v0190 = stack[-4];
    v0197 = stack[-1];
    v0191 = qcdr(v0197);
    v0197 = stack[0];
    stack[-3] = v0112;
    stack[-2] = v0190;
    stack[-1] = v0191;
    stack[0] = v0197;
    goto v0104;

v0092:
    v0197 = qvalue(elt(env, 1)); /* t */
    goto v0102;
/* error exit handlers */
v0193:
    popv(6);
    return nil;
}



/* Code for delengthsf */

static Lisp_Object CC_delengthsf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delengthsf");
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
    v0105 = stack[-1];
    v0105 = Lconsp(nil, v0105);
    env = stack[-3];
    if (v0105 == nil) goto v0107;
    v0105 = stack[-1];
    v0105 = qcar(v0105);
    v0105 = Lconsp(nil, v0105);
    env = stack[-3];
    if (v0105 == nil) goto v0093;
    v0105 = stack[-1];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    v0105 = Lconsp(nil, v0105);
    env = stack[-3];
    v0105 = (v0105 == nil ? lisp_true : nil);
    goto v0022;

v0022:
    if (v0105 == nil) goto v0011;
    v0105 = stack[-1];
    if (!consp(v0105)) goto v0099;
    v0105 = stack[-1];
    v0105 = qcar(v0105);
    v0105 = (consp(v0105) ? nil : lisp_true);
    goto v0010;

v0010:
    if (v0105 == nil) goto v0094;
    v0105 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v0105); }

v0094:
    v0105 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0105); }

v0099:
    v0105 = qvalue(elt(env, 1)); /* t */
    goto v0010;

v0011:
    v0105 = stack[-1];
    v0105 = qcar(v0105);
    v0105 = qcar(v0105);
    stack[-2] = qcdr(v0105);
    v0105 = stack[-1];
    v0105 = qcar(v0105);
    v0105 = qcdr(v0105);
    stack[0] = CC_delengthsf(env, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    v0105 = stack[-1];
    v0105 = qcdr(v0105);
    v0105 = CC_delengthsf(env, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-3];
    v0105 = plus2(stack[0], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    {
        Lisp_Object v0090 = stack[-2];
        popv(4);
        return plus2(v0090, v0105);
    }

v0093:
    v0105 = qvalue(elt(env, 1)); /* t */
    goto v0022;

v0107:
    v0105 = qvalue(elt(env, 1)); /* t */
    goto v0022;
/* error exit handlers */
v0089:
    popv(4);
    return nil;
}



/* Code for exceeds!-order!-variant */

static Lisp_Object CC_exceedsKorderKvariant(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0144, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exceeds-order-variant");
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

v0104:
    v0144 = stack[-1];
    if (v0144 == nil) goto v0057;
    v0144 = stack[0];
    v0144 = qcar(v0144);
    stack[-2] = v0144;
    v0144 = (Lisp_Object)1; /* 0 */
    v0095 = v0144;
    goto v0016;

v0016:
    v0144 = stack[-2];
    if (v0144 == nil) goto v0007;
    v0144 = stack[-2];
    v0144 = qcar(v0144);
    fn = elt(env, 2); /* tayexp!-plus2 */
    v0144 = (*qfn2(fn))(qenv(fn), v0144, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    v0095 = v0144;
    v0144 = stack[-2];
    v0144 = qcdr(v0144);
    stack[-2] = v0144;
    goto v0016;

v0007:
    v0144 = v0095;
    v0095 = v0144;
    v0144 = stack[-1];
    v0144 = qcar(v0144);
    fn = elt(env, 3); /* tayexp!-greaterp */
    v0144 = (*qfn2(fn))(qenv(fn), v0095, v0144);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-3];
    if (!(v0144 == nil)) { popv(4); return onevalue(v0144); }
    v0144 = stack[-1];
    v0095 = qcdr(v0144);
    v0144 = stack[0];
    v0144 = qcdr(v0144);
    stack[-1] = v0095;
    stack[0] = v0144;
    goto v0104;

v0057:
    v0144 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0144); }
/* error exit handlers */
v0036:
    popv(4);
    return nil;
}



/* Code for get_mat */

static Lisp_Object CC_get_mat(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0089;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get_mat");
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
    v0089 = stack[-2];
    v0088 = elt(env, 1); /* id */
    if (v0089 == v0088) goto v0069;
    v0088 = qvalue(elt(env, 2)); /* nil */
    stack[-3] = v0088;
    goto v0009;

v0009:
    v0088 = stack[-1];
    v0089 = Llength(nil, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    v0088 = (Lisp_Object)1; /* 0 */
    v0088 = (Lisp_Object)greaterp2(v0089, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    v0088 = v0088 ? lisp_true : nil;
    env = stack[-4];
    if (v0088 == nil) goto v0097;
    v0088 = stack[-3];
    if (!(v0088 == nil)) goto v0097;
    v0089 = stack[-2];
    v0088 = stack[-1];
    v0088 = qcar(v0088);
    v0088 = qcar(v0088);
    if (!(equal(v0089, v0088))) goto v0094;
    v0088 = stack[-1];
    v0088 = qcar(v0088);
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    stack[0] = v0088;
    v0088 = qvalue(elt(env, 3)); /* t */
    stack[-3] = v0088;
    goto v0094;

v0094:
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    stack[-1] = v0088;
    goto v0009;

v0097:
    v0088 = stack[-3];
    if (!(v0088 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0088 = elt(env, 4); /* "error in get_mat" */
    fn = elt(env, 5); /* rederr */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    v0088 = nil;
    { popv(5); return onevalue(v0088); }

v0069:
    v0088 = stack[-1];
    v0088 = qcar(v0088);
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    fn = elt(env, 6); /* get!+row!+nr */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 7); /* mk!+unit!+mat */
        return (*qfn1(fn))(qenv(fn), v0088);
    }
/* error exit handlers */
v0074:
    popv(5);
    return nil;
}



/* Code for qqe_simplqequal */

static Lisp_Object CC_qqe_simplqequal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0241, v0242, v0243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_simplqequal");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0241 = v0001;
    stack[0] = v0000;
/* end of prologue */

v0104:
    v0241 = stack[0];
    fn = elt(env, 7); /* qqe_arg2r */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[-7] = v0241;
    v0241 = stack[0];
    fn = elt(env, 8); /* qqe_arg2l */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[-8] = v0241;
    v0242 = stack[-7];
    v0241 = stack[-8];
    if (equal(v0242, v0241)) goto v0031;
    v0241 = stack[-8];
    fn = elt(env, 9); /* qqe_qprefix!-var */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[-6] = v0241;
    v0241 = stack[-7];
    fn = elt(env, 9); /* qqe_qprefix!-var */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[-5] = v0241;
    v0242 = stack[-6];
    v0241 = stack[-5];
    if (v0242 == v0241) goto v0013;
    v0242 = stack[-6];
    v0241 = elt(env, 3); /* qepsilon */
    if (v0242 == v0241) goto v0021;
    v0242 = stack[-5];
    v0241 = elt(env, 3); /* qepsilon */
    v0241 = (v0242 == v0241 ? lisp_true : nil);
    goto v0014;

v0014:
    if (v0241 == nil) goto v0099;
    v0241 = stack[-7];
    fn = elt(env, 10); /* qqe_number!-of!-adds!-in!-qterm */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[-3] = v0241;
    v0241 = stack[-8];
    fn = elt(env, 10); /* qqe_number!-of!-adds!-in!-qterm */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[-4] = v0241;
    v0241 = stack[-7];
    fn = elt(env, 11); /* qqe_number!-of!-tails!-in!-qterm */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[-1] = v0241;
    v0241 = stack[-8];
    fn = elt(env, 11); /* qqe_number!-of!-tails!-in!-qterm */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[-2] = v0241;
    v0242 = stack[-6];
    v0241 = stack[-5];
    if (v0242 == v0241) goto v0155;
    v0241 = qvalue(elt(env, 4)); /* nil */
    goto v0081;

v0081:
    if (v0241 == nil) goto v0190;
    v0241 = elt(env, 5); /* false */
    { popv(10); return onevalue(v0241); }

v0190:
    v0242 = stack[-7];
    v0241 = elt(env, 3); /* qepsilon */
    if (v0242 == v0241) goto v0193;
    v0241 = qvalue(elt(env, 4)); /* nil */
    goto v0051;

v0051:
    if (v0241 == nil) goto v0245;
    v0241 = elt(env, 5); /* false */
    { popv(10); return onevalue(v0241); }

v0245:
    v0242 = stack[-8];
    v0241 = elt(env, 3); /* qepsilon */
    if (v0242 == v0241) goto v0246;
    v0241 = qvalue(elt(env, 4)); /* nil */
    goto v0247;

v0247:
    if (v0241 == nil) goto v0248;
    v0241 = elt(env, 5); /* false */
    { popv(10); return onevalue(v0241); }

v0248:
    v0242 = stack[-7];
    v0241 = elt(env, 3); /* qepsilon */
    if (v0242 == v0241) goto v0167;
    v0241 = qvalue(elt(env, 4)); /* nil */
    goto v0249;

v0249:
    if (v0241 == nil) goto v0250;
    v0242 = stack[-6];
    v0241 = elt(env, 3); /* qepsilon */
    if (v0242 == v0241) goto v0251;
    v0241 = stack[-8];
    fn = elt(env, 12); /* qqe_simplterm */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    v0242 = elt(env, 6); /* qequal */
    v0243 = v0241;
    v0241 = stack[-7];
    {
        popv(10);
        fn = elt(env, 13); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0242, v0243, v0241);
    }

v0251:
    v0241 = elt(env, 1); /* true */
    { popv(10); return onevalue(v0241); }

v0250:
    v0242 = stack[-8];
    v0241 = elt(env, 3); /* qepsilon */
    if (v0242 == v0241) goto v0252;
    v0241 = qvalue(elt(env, 4)); /* nil */
    goto v0253;

v0253:
    if (v0241 == nil) goto v0099;
    v0242 = stack[-5];
    v0241 = elt(env, 3); /* qepsilon */
    if (v0242 == v0241) goto v0254;
    v0241 = stack[-7];
    fn = elt(env, 12); /* qqe_simplterm */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[0] = v0241;
    v0243 = elt(env, 6); /* qequal */
    v0242 = stack[-8];
    v0241 = stack[0];
    {
        popv(10);
        fn = elt(env, 13); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0243, v0242, v0241);
    }

v0254:
    v0241 = elt(env, 1); /* true */
    { popv(10); return onevalue(v0241); }

v0099:
    v0241 = stack[-7];
    fn = elt(env, 12); /* qqe_simplterm */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[0] = v0241;
    v0241 = stack[-8];
    fn = elt(env, 12); /* qqe_simplterm */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    v0243 = stack[-7];
    v0242 = stack[0];
    if (equal(v0243, v0242)) goto v0255;
    v0242 = qvalue(elt(env, 4)); /* nil */
    goto v0256;

v0256:
    if (v0242 == nil) goto v0257;
    v0243 = elt(env, 6); /* qequal */
    v0242 = v0241;
    v0241 = stack[0];
    {
        popv(10);
        fn = elt(env, 13); /* qqe_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0243, v0242, v0241);
    }

v0257:
    v0243 = elt(env, 6); /* qequal */
    v0242 = v0241;
    v0241 = stack[0];
    fn = elt(env, 13); /* qqe_mk2 */
    v0241 = (*qfnn(fn))(qenv(fn), 3, v0243, v0242, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    stack[0] = v0241;
    goto v0104;

v0255:
    v0243 = stack[-8];
    v0242 = v0241;
    v0242 = (equal(v0243, v0242) ? lisp_true : nil);
    goto v0256;

v0252:
    v0242 = stack[-3];
    v0241 = (Lisp_Object)1; /* 0 */
    if (v0242 == v0241) goto v0258;
    v0241 = qvalue(elt(env, 4)); /* nil */
    goto v0253;

v0258:
    v0242 = stack[-4];
    v0241 = (Lisp_Object)1; /* 0 */
    v0241 = (v0242 == v0241 ? lisp_true : nil);
    goto v0253;

v0167:
    v0242 = stack[-3];
    v0241 = (Lisp_Object)1; /* 0 */
    if (v0242 == v0241) goto v0259;
    v0241 = qvalue(elt(env, 4)); /* nil */
    goto v0249;

v0259:
    v0242 = stack[-4];
    v0241 = (Lisp_Object)1; /* 0 */
    v0241 = (v0242 == v0241 ? lisp_true : nil);
    goto v0249;

v0246:
    v0242 = stack[-3];
    v0241 = stack[-1];
    v0241 = (Lisp_Object)greaterp2(v0242, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    v0241 = v0241 ? lisp_true : nil;
    env = stack[-9];
    goto v0247;

v0193:
    v0242 = stack[-4];
    v0241 = stack[-2];
    v0241 = (Lisp_Object)greaterp2(v0242, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    v0241 = v0241 ? lisp_true : nil;
    env = stack[-9];
    goto v0051;

v0155:
    v0242 = stack[-3];
    v0241 = stack[-1];
    v0241 = (Lisp_Object)geq2(v0242, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    v0241 = v0241 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0241 == nil)) goto v0134;
    v0242 = stack[-4];
    v0241 = stack[-2];
    v0241 = (Lisp_Object)geq2(v0242, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    v0241 = v0241 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0241 == nil)) goto v0134;
    v0241 = qvalue(elt(env, 4)); /* nil */
    goto v0081;

v0134:
    v0242 = stack[-3];
    v0241 = stack[-1];
    stack[0] = difference2(v0242, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    v0242 = stack[-4];
    v0241 = stack[-2];
    v0241 = difference2(v0242, v0241);
    nil = C_nil;
    if (exception_pending()) goto v0244;
    env = stack[-9];
    v0241 = (equal(stack[0], v0241) ? lisp_true : nil);
    v0241 = (v0241 == nil ? lisp_true : nil);
    goto v0081;

v0021:
    v0241 = qvalue(elt(env, 2)); /* t */
    goto v0014;

v0013:
    v0241 = qvalue(elt(env, 2)); /* t */
    goto v0014;

v0031:
    v0241 = elt(env, 1); /* true */
    { popv(10); return onevalue(v0241); }
/* error exit handlers */
v0244:
    popv(10);
    return nil;
}



/* Code for cl_atl */

static Lisp_Object CC_cl_atl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atl");
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
    v0092 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* cl_atl1 */
    v0033 = (*qfn1(fn))(qenv(fn), v0092);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[0];
    v0092 = elt(env, 1); /* rl_ordatp */
    {
        popv(1);
        fn = elt(env, 3); /* sort */
        return (*qfn2(fn))(qenv(fn), v0033, v0092);
    }
/* error exit handlers */
v0032:
    popv(1);
    return nil;
}



/* Code for dip_comp1 */

static Lisp_Object CC_dip_comp1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dip_comp1");
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
    v0032 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* dip_evlmon */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    v0032 = stack[0];
    fn = elt(env, 1); /* dip_evlmon */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-2];
    {
        Lisp_Object v0093 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* ev_comp */
        return (*qfn2(fn))(qenv(fn), v0093, v0032);
    }
/* error exit handlers */
v0018:
    popv(3);
    return nil;
}



/* Code for i2ps */

static Lisp_Object CC_i2ps(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0004;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for i2ps");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0000;
/* end of prologue */
    return onevalue(v0004);
}



/* Code for appends */

static Lisp_Object MS_CDECL CC_appends(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0006, v0030, v0031;
    Lisp_Object v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "appends");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for appends");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0006 = v0055;
    v0030 = v0001;
    v0031 = v0000;
/* end of prologue */
    stack[0] = v0031;
    v0006 = Lappend(nil, v0030, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    {
        Lisp_Object v0016 = stack[0];
        popv(1);
        return Lappend(nil, v0016, v0006);
    }
/* error exit handlers */
v0096:
    popv(1);
    return nil;
}



/* Code for formoptimize1 */

static Lisp_Object MS_CDECL CC_formoptimize1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0254, v0274, v0275;
    Lisp_Object fn;
    Lisp_Object v0055, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formoptimize1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0055 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formoptimize1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0055,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0055);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0055;
    stack[-7] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0104:
    v0254 = stack[-1];
    fn = elt(env, 12); /* constp */
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    if (v0254 == nil) goto v0022;
    v0254 = stack[-1];
        popv(10);
        return Lmkquote(nil, v0254);

v0022:
    v0254 = stack[-1];
    if (!consp(v0254)) goto v0033;
    v0254 = stack[-1];
    v0274 = qcar(v0254);
    v0254 = elt(env, 1); /* (!:rd!: !:cr!: !:crn!: !:dn!:) */
    v0254 = Lmember(nil, v0274, v0254);
    if (v0254 == nil) goto v0037;
    v0254 = stack[-1];
    v0254 = qcdr(v0254);
    fn = elt(env, 13); /* chopchop */
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    stack[-1] = v0254;
    v0254 = stack[-1];
    v0274 = qcar(v0254);
    v0254 = stack[-1];
    v0254 = qcdr(v0254);
    fn = elt(env, 14); /* decimal2internal */
    v0254 = (*qfn2(fn))(qenv(fn), v0274, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
        popv(10);
        return Lmkquote(nil, v0254);

v0037:
    v0254 = stack[-1];
    v0274 = qcar(v0254);
    v0254 = elt(env, 2); /* !:int!: */
    if (v0274 == v0254) goto v0064;
    v0274 = stack[-1];
    v0254 = elt(env, 3); /* eval */
    if (!consp(v0274)) goto v0061;
    v0274 = qcar(v0274);
    if (!(v0274 == v0254)) goto v0061;
    stack[-2] = elt(env, 4); /* sq2pre */
    stack[0] = elt(env, 5); /* aeval */
    v0254 = stack[-1];
    v0254 = qcdr(v0254);
    v0275 = qcar(v0254);
    v0274 = stack[-7];
    v0254 = stack[-6];
    fn = elt(env, 15); /* form1 */
    v0254 = (*qfnn(fn))(qenv(fn), 3, v0275, v0274, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    v0254 = list2(stack[0], v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    {
        Lisp_Object v0277 = stack[-2];
        popv(10);
        return list2(v0277, v0254);
    }

v0061:
    v0254 = stack[-1];
    v0274 = qcar(v0254);
    v0254 = elt(env, 6); /* (lsetq rsetq lrsetq) */
    v0254 = Lmemq(nil, v0274, v0254);
    if (v0254 == nil) goto v0251;
    v0254 = stack[-1];
    v0254 = qcar(v0254);
    stack[-8] = v0254;
    v0254 = stack[-1];
    v0254 = qcdr(v0254);
    v0254 = qcar(v0254);
    stack[0] = v0254;
    v0254 = stack[-1];
    v0254 = qcdr(v0254);
    v0254 = qcdr(v0254);
    v0254 = qcar(v0254);
    stack[-5] = v0254;
    v0274 = stack[-8];
    v0254 = elt(env, 7); /* (lsetq lrsetq) */
    v0254 = Lmemq(nil, v0274, v0254);
    if (v0254 == nil) goto v0278;
    v0254 = stack[0];
    fn = elt(env, 16); /* listp */
    v0254 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    if (v0254 == nil) goto v0278;
    v0254 = stack[0];
    stack[-4] = qcar(v0254);
    v0254 = stack[0];
    v0254 = qcdr(v0254);
    stack[-3] = v0254;
    v0254 = stack[-3];
    if (v0254 == nil) goto v0050;
    v0254 = stack[-3];
    v0254 = qcar(v0254);
    v0274 = elt(env, 3); /* eval */
    v0254 = list2(v0274, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    v0254 = ncons(v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    stack[-1] = v0254;
    stack[-2] = v0254;
    goto v0187;

v0187:
    v0254 = stack[-3];
    v0254 = qcdr(v0254);
    stack[-3] = v0254;
    v0254 = stack[-3];
    if (v0254 == nil) goto v0042;
    stack[0] = stack[-1];
    v0254 = stack[-3];
    v0254 = qcar(v0254);
    v0274 = elt(env, 3); /* eval */
    v0254 = list2(v0274, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    v0254 = ncons(v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    v0254 = Lrplacd(nil, stack[0], v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    v0254 = stack[-1];
    v0254 = qcdr(v0254);
    stack[-1] = v0254;
    goto v0187;

v0042:
    v0254 = stack[-2];
    goto v0279;

v0279:
    v0254 = cons(stack[-4], v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    stack[0] = v0254;
    goto v0278;

v0278:
    v0274 = stack[-8];
    v0254 = elt(env, 9); /* (rsetq lrsetq) */
    v0254 = Lmemq(nil, v0274, v0254);
    if (v0254 == nil) goto v0170;
    v0274 = elt(env, 3); /* eval */
    v0254 = stack[-5];
    v0254 = list2(v0274, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    stack[-5] = v0254;
    goto v0170;

v0170:
    v0275 = elt(env, 10); /* setq */
    v0274 = stack[0];
    v0254 = stack[-5];
    v0275 = list3(v0275, v0274, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    v0274 = stack[-7];
    v0254 = stack[-6];
    stack[-1] = v0275;
    stack[-7] = v0274;
    stack[-6] = v0254;
    goto v0104;

v0050:
    v0254 = qvalue(elt(env, 8)); /* nil */
    goto v0279;

v0251:
    stack[-4] = elt(env, 11); /* list */
    v0254 = stack[-1];
    stack[-3] = v0254;
    v0254 = stack[-3];
    if (v0254 == nil) goto v0280;
    v0254 = stack[-3];
    v0254 = qcar(v0254);
    v0275 = v0254;
    v0274 = stack[-7];
    v0254 = stack[-6];
    v0254 = CC_formoptimize1(env, 3, v0275, v0274, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    v0254 = ncons(v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    stack[-1] = v0254;
    stack[-2] = v0254;
    goto v0281;

v0281:
    v0254 = stack[-3];
    v0254 = qcdr(v0254);
    stack[-3] = v0254;
    v0254 = stack[-3];
    if (v0254 == nil) goto v0181;
    stack[0] = stack[-1];
    v0254 = stack[-3];
    v0254 = qcar(v0254);
    v0275 = v0254;
    v0274 = stack[-7];
    v0254 = stack[-6];
    v0254 = CC_formoptimize1(env, 3, v0275, v0274, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    v0254 = ncons(v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    v0254 = Lrplacd(nil, stack[0], v0254);
    nil = C_nil;
    if (exception_pending()) goto v0276;
    env = stack[-9];
    v0254 = stack[-1];
    v0254 = qcdr(v0254);
    stack[-1] = v0254;
    goto v0281;

v0181:
    v0254 = stack[-2];
    goto v0160;

v0160:
    {
        Lisp_Object v0282 = stack[-4];
        popv(10);
        return cons(v0282, v0254);
    }

v0280:
    v0254 = qvalue(elt(env, 8)); /* nil */
    goto v0160;

v0064:
    v0254 = stack[-1];
    v0254 = qcdr(v0254);
    v0254 = qcar(v0254);
        popv(10);
        return Lmkquote(nil, v0254);

v0033:
    v0254 = stack[-1];
        popv(10);
        return Lmkquote(nil, v0254);
/* error exit handlers */
v0276:
    popv(10);
    return nil;
}



/* Code for simpintersection */

static Lisp_Object CC_simpintersection(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0091, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpintersection");
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
    v0090 = v0000;
/* end of prologue */
    v0091 = elt(env, 1); /* intersection */
    fn = elt(env, 3); /* applysetop */
    v0090 = (*qfn2(fn))(qenv(fn), v0091, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0058 = v0090;
    v0090 = v0058;
    v0091 = qcar(v0090);
    v0090 = elt(env, 1); /* intersection */
    if (v0091 == v0090) goto v0094;
    v0090 = v0058;
    v0091 = v0090;
    goto v0002;

v0002:
    v0090 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* mksp */
    v0091 = (*qfn2(fn))(qenv(fn), v0091, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0090 = (Lisp_Object)17; /* 1 */
    v0090 = cons(v0091, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0091 = ncons(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    v0090 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v0091, v0090);

v0094:
    v0091 = qvalue(elt(env, 2)); /* empty_set */
    v0090 = v0058;
    v0090 = qcdr(v0090);
    v0058 = v0090;
    v0090 = Lmember(nil, v0091, v0090);
    if (v0090 == nil) goto v0106;
    v0090 = qvalue(elt(env, 2)); /* empty_set */
    goto v0078;

v0078:
    v0091 = v0090;
    goto v0002;

v0106:
    v0090 = v0058;
    v0090 = qcdr(v0090);
    if (v0090 == nil) goto v0077;
    stack[0] = elt(env, 1); /* intersection */
    v0090 = v0058;
    fn = elt(env, 5); /* ordn */
    v0090 = (*qfn1(fn))(qenv(fn), v0090);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    v0090 = cons(stack[0], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0074;
    env = stack[-1];
    goto v0078;

v0077:
    v0090 = v0058;
    v0090 = qcar(v0090);
    goto v0078;
/* error exit handlers */
v0074:
    popv(2);
    return nil;
}



setup_type const u51_setup[] =
{
    {"sfto_dgcd",               too_few_2,      CC_sfto_dgcd,  wrong_no_2},
    {"mod-domainvalchk",        too_few_2,      CC_modKdomainvalchk,wrong_no_2},
    {"test-ideal",              CC_testKideal,  too_many_1,    wrong_no_1},
    {"pst_d1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_pst_d1},
    {"spreadvar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_spreadvar},
    {"gcd-mod-p",               too_few_2,      CC_gcdKmodKp,  wrong_no_2},
    {"initmonomials",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_initmonomials},
    {"rl_translat",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_translat},
    {"get*real*irreducible*rep",too_few_2,      CC_getHrealHirreducibleHrep,wrong_no_2},
    {"makevar",                 too_few_2,      CC_makevar,    wrong_no_2},
    {"ps:constmult-erule",      too_few_2,      CC_psTconstmultKerule,wrong_no_2},
    {"frlp",                    CC_frlp,        too_many_1,    wrong_no_1},
    {"cr:onep",                 CC_crTonep,     too_many_1,    wrong_no_1},
    {"groebreduceonestepint",   wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebreduceonestepint},
    {"remove_critical_pairs",   too_few_2,      CC_remove_critical_pairs,wrong_no_2},
    {"noncom1",                 CC_noncom1,     too_many_1,    wrong_no_1},
    {"coeff1_calc",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeff1_calc},
    {"rappend",                 CC_rappend,     too_many_1,    wrong_no_1},
    {"dummy_nam",               CC_dummy_nam,   too_many_1,    wrong_no_1},
    {"vp2df",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_vp2df},
    {"qqe_length-graph-neighbors",CC_qqe_lengthKgraphKneighbors,too_many_1,wrong_no_1},
    {"aex_sgn",                 CC_aex_sgn,     too_many_1,    wrong_no_1},
    {"dipdivmon",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipdivmon},
    {"vdpenumerate",            CC_vdpenumerate,too_many_1,    wrong_no_1},
    {"rembras",                 CC_rembras,     too_many_1,    wrong_no_1},
    {"minprec",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_minprec},
    {"expt-separate",           too_few_2,      CC_exptKseparate,wrong_no_2},
    {"coeff_ordn1",             too_few_2,      CC_coeff_ordn1,wrong_no_2},
    {"*ex2sf",                  CC_Hex2sf,      too_many_1,    wrong_no_1},
    {"fs:onep",                 CC_fsTonep,     too_many_1,    wrong_no_1},
    {"distri_pol",              CC_distri_pol,  too_many_1,    wrong_no_1},
    {"x**p-w",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_xHHpKw},
    {"qroundup",                too_few_2,      CC_qroundup,   wrong_no_2},
    {"ofsf_translat2",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_translat2},
    {"put-avalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKavalue},
    {"makecoeffpairs1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_makecoeffpairs1},
    {"qqe_length-graph-marked", CC_qqe_lengthKgraphKmarked,too_many_1,wrong_no_1},
    {"pasf_smeqtable",          too_few_2,      CC_pasf_smeqtable,wrong_no_2},
    {"mkarg",                   too_few_2,      CC_mkarg,      wrong_no_2},
    {"ldf-pow-var",             CC_ldfKpowKvar, too_many_1,    wrong_no_1},
    {"vdpvbcprod",              too_few_2,      CC_vdpvbcprod, wrong_no_2},
    {"r2oreaction",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_r2oreaction},
    {"basisvectorp",            CC_basisvectorp,too_many_1,    wrong_no_1},
    {"mk-strand-vertex",        too_few_2,      CC_mkKstrandKvertex,wrong_no_2},
    {"horner-rule-in-order-mod-p",wrong_no_na,  wrong_no_nb,   (n_args *)CC_hornerKruleKinKorderKmodKp},
    {"delengthsf",              CC_delengthsf,  too_many_1,    wrong_no_1},
    {"exceeds-order-variant",   too_few_2,      CC_exceedsKorderKvariant,wrong_no_2},
    {"get_mat",                 too_few_2,      CC_get_mat,    wrong_no_2},
    {"qqe_simplqequal",         too_few_2,      CC_qqe_simplqequal,wrong_no_2},
    {"cl_atl",                  CC_cl_atl,      too_many_1,    wrong_no_1},
    {"dip_comp1",               too_few_2,      CC_dip_comp1,  wrong_no_2},
    {"i2ps",                    CC_i2ps,        too_many_1,    wrong_no_1},
    {"appends",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_appends},
    {"formoptimize1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_formoptimize1},
    {"simpintersection",        CC_simpintersection,too_many_1,wrong_no_1},
    {NULL, (one_args *)"u51", (two_args *)"11036 231733 8654735", 0}
};

/* end of generated code */
