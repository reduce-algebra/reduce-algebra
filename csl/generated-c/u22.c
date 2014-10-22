
/* $destdir\u22.c        Machine generated C code */

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


/* Code for quotof */

static Lisp_Object CC_quotof(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0065, v0066;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotof");
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
    v0064 = stack[-3];
    if (v0064 == nil) goto v0067;
    v0065 = stack[-3];
    v0064 = stack[-2];
    if (equal(v0065, v0064)) goto v0068;
    v0065 = stack[-2];
    v0064 = (Lisp_Object)17; /* 1 */
    if (v0065 == v0064) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0064 = stack[-2];
    if (!consp(v0064)) goto v0069;
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0064 = (consp(v0064) ? nil : lisp_true);
    goto v0070;

v0070:
    if (v0064 == nil) goto v0071;
    v0065 = stack[-3];
    v0064 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* quotofd */
        return (*qfn2(fn))(qenv(fn), v0065, v0064);
    }

v0071:
    v0064 = stack[-3];
    if (!consp(v0064)) goto v0072;
    v0064 = stack[-3];
    v0064 = qcar(v0064);
    v0064 = (consp(v0064) ? nil : lisp_true);
    goto v0073;

v0073:
    if (v0064 == nil) goto v0074;
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0064 = qcar(v0064);
    v0064 = qcdr(v0064);
    v0065 = stack[-2];
    v0065 = qcar(v0065);
    v0065 = qcar(v0065);
    stack[0] = qcar(v0065);
    v0065 = v0064;
    if (is_number(v0065)) goto v0075;
    v0065 = elt(env, 3); /* minus */
    v0064 = list2(v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    goto v0077;

v0077:
    fn = elt(env, 6); /* mksp */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    stack[-1] = stack[-3];
    v0065 = stack[-2];
    v0064 = elt(env, 4); /* lcx */
    fn = elt(env, 7); /* carx */
    v0064 = (*qfn2(fn))(qenv(fn), v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0064 = qcdr(v0064);
    v0064 = CC_quotof(env, stack[-1], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0064 = cons(stack[0], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    popv(6);
    return ncons(v0064);

v0075:
    v0064 = negate(v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    goto v0077;

v0074:
    v0064 = stack[-3];
    v0064 = qcar(v0064);
    v0065 = qcar(v0064);
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    v0064 = qcar(v0064);
    stack[0] = v0065;
    stack[-4] = v0064;
    v0064 = stack[0];
    v0065 = qcar(v0064);
    v0064 = stack[-4];
    v0064 = qcar(v0064);
    if (v0065 == v0064) goto v0078;
    v0064 = stack[0];
    v0065 = qcar(v0064);
    v0064 = stack[-4];
    v0064 = qcar(v0064);
    fn = elt(env, 8); /* ordop */
    v0064 = (*qfn2(fn))(qenv(fn), v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    if (v0064 == nil) goto v0079;
    stack[-1] = stack[0];
    v0064 = stack[-3];
    v0064 = qcar(v0064);
    v0065 = qcdr(v0064);
    v0064 = stack[-2];
    stack[0] = CC_quotof(env, v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0064 = stack[-3];
    v0065 = qcdr(v0064);
    v0064 = stack[-2];
    v0064 = CC_quotof(env, v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    {
        Lisp_Object v0080 = stack[-1];
        Lisp_Object v0081 = stack[0];
        popv(6);
        return acons(v0080, v0081, v0064);
    }

v0079:
    v0064 = stack[-4];
    stack[0] = qcar(v0064);
    v0064 = stack[-4];
    v0064 = qcdr(v0064);
    v0064 = negate(v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    fn = elt(env, 6); /* mksp */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    stack[-1] = stack[-3];
    v0065 = stack[-2];
    v0064 = elt(env, 4); /* lcx */
    fn = elt(env, 7); /* carx */
    v0064 = (*qfn2(fn))(qenv(fn), v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0064 = qcdr(v0064);
    v0064 = CC_quotof(env, stack[-1], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0064 = cons(stack[0], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    popv(6);
    return ncons(v0064);

v0078:
    v0064 = stack[0];
    v0065 = qcdr(v0064);
    v0064 = stack[-4];
    v0064 = qcdr(v0064);
    stack[-1] = difference2(v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0064 = stack[-3];
    v0064 = qcar(v0064);
    stack[0] = qcdr(v0064);
    v0065 = stack[-2];
    v0064 = elt(env, 4); /* lcx */
    fn = elt(env, 7); /* carx */
    v0064 = (*qfn2(fn))(qenv(fn), v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0064 = qcdr(v0064);
    stack[0] = CC_quotof(env, stack[0], v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0064 = stack[-3];
    v0065 = qcdr(v0064);
    v0064 = stack[-2];
    v0064 = CC_quotof(env, v0065, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    env = stack[-5];
    v0066 = stack[-1];
    stack[-1] = stack[0];
    stack[0] = v0064;
    v0065 = v0066;
    v0064 = (Lisp_Object)1; /* 0 */
    if (v0065 == v0064) goto v0082;
    v0064 = stack[-4];
    v0064 = qcar(v0064);
    v0065 = v0066;
    fn = elt(env, 9); /* to */
    v0066 = (*qfn2(fn))(qenv(fn), v0064, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0076;
    v0065 = stack[-1];
    v0064 = stack[0];
    popv(6);
    return acons(v0066, v0065, v0064);

v0082:
    v0065 = stack[-1];
    v0064 = stack[0];
    {
        popv(6);
        fn = elt(env, 10); /* raddf */
        return (*qfn2(fn))(qenv(fn), v0065, v0064);
    }

v0072:
    v0064 = qvalue(elt(env, 2)); /* t */
    goto v0073;

v0069:
    v0064 = qvalue(elt(env, 2)); /* t */
    goto v0070;

v0068:
    v0064 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v0064); }

v0067:
    v0064 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0064); }
/* error exit handlers */
v0076:
    popv(6);
    return nil;
}



/* Code for xremainder!-mod!-p */

static Lisp_Object MS_CDECL CC_xremainderKmodKp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0040, v0038;
    Lisp_Object fn;
    Lisp_Object v0100, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xremainder-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0100 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xremainder-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0100,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0100;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0105:
    v0039 = stack[-2];
    if (!consp(v0039)) goto v0106;
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0039 = (consp(v0039) ? nil : lisp_true);
    goto v0107;

v0107:
    if (v0039 == nil) goto v0071;
    v0039 = qvalue(elt(env, 1)); /* t */
    goto v0068;

v0068:
    if (!(v0039 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0039 = qcdr(v0039);
    fn = elt(env, 2); /* minus!-mod!-p */
    v0040 = (*qfn1(fn))(qenv(fn), v0039);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = qcdr(v0039);
    fn = elt(env, 3); /* quotient!-mod!-p */
    v0039 = (*qfn2(fn))(qenv(fn), v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    stack[-3] = v0039;
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0040 = qcdr(v0039);
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = qcdr(v0039);
    v0039 = (Lisp_Object)(int32_t)((int32_t)v0040 - (int32_t)v0039 + TAG_FIXNUM);
    v0038 = v0039;
    v0040 = v0038;
    v0039 = (Lisp_Object)1; /* 0 */
    if (v0040 == v0039) goto v0109;
    v0039 = stack[-2];
    stack[-2] = qcdr(v0039);
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0040 = v0038;
    fn = elt(env, 4); /* mksp */
    v0040 = (*qfn2(fn))(qenv(fn), v0039, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    v0039 = stack[-3];
    v0040 = cons(v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    v0039 = stack[-1];
    v0039 = qcdr(v0039);
    fn = elt(env, 5); /* times!-term!-mod!-p */
    v0039 = (*qfn2(fn))(qenv(fn), v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    fn = elt(env, 6); /* plus!-mod!-p */
    v0039 = (*qfn2(fn))(qenv(fn), stack[-2], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    stack[-2] = v0039;
    goto v0110;

v0110:
    v0038 = stack[-2];
    v0040 = stack[-1];
    v0039 = stack[0];
    stack[-2] = v0038;
    stack[-1] = v0040;
    stack[0] = v0039;
    goto v0105;

v0109:
    v0039 = stack[-2];
    stack[-2] = qcdr(v0039);
    v0039 = stack[-1];
    v0040 = qcdr(v0039);
    v0039 = stack[-3];
    fn = elt(env, 7); /* multiply!-by!-constant!-mod!-p */
    v0039 = (*qfn2(fn))(qenv(fn), v0040, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    fn = elt(env, 6); /* plus!-mod!-p */
    v0039 = (*qfn2(fn))(qenv(fn), stack[-2], v0039);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-4];
    stack[-2] = v0039;
    goto v0110;

v0071:
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0040 = qcar(v0039);
    v0039 = stack[0];
    if (equal(v0040, v0039)) goto v0111;
    v0039 = qvalue(elt(env, 1)); /* t */
    goto v0068;

v0111:
    v0039 = stack[-2];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0040 = qcdr(v0039);
    v0039 = stack[-1];
    v0039 = qcar(v0039);
    v0039 = qcar(v0039);
    v0039 = qcdr(v0039);
    v0039 = ((intptr_t)v0040 < (intptr_t)v0039) ? lisp_true : nil;
    goto v0068;

v0106:
    v0039 = qvalue(elt(env, 1)); /* t */
    goto v0107;
/* error exit handlers */
v0108:
    popv(5);
    return nil;
}



/* Code for yylex */

static Lisp_Object MS_CDECL CC_yylex(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0193, v0194, v0195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "yylex");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for yylex");
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
    stack[-2] = nil;
    fn = elt(env, 29); /* lex_basic_token */
    v0193 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[0] = v0193;
    goto v0095;

v0095:
    v0193 = stack[-2];
    if (!(v0193 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v0060:
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 3); /* comment */
    if (v0194 == v0193) goto v0069;
    v0193 = qvalue(elt(env, 1)); /* nil */
    goto v0197;

v0197:
    if (!(v0193 == nil)) goto v0198;
    v0194 = stack[0];
    v0193 = elt(env, 4); /* !:symbol_or_keyword */
    if (v0194 == v0193) goto v0199;
    v0194 = stack[0];
    v0193 = elt(env, 19); /* !:symbol */
    if (v0194 == v0193) goto v0009;
    v0193 = stack[0];
    if (is_number(v0193)) goto v0200;
    v0193 = qvalue(elt(env, 7)); /* t */
    stack[-2] = v0193;
    v0194 = stack[0];
    v0193 = elt(env, 15); /* lex_code */
    v0193 = get(v0194, v0193);
    env = stack[-3];
    stack[0] = v0193;
    goto v0095;

v0200:
    v0195 = qvalue(elt(env, 5)); /* lex_char */
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 28); /* lex_dipthong */
    v0193 = get(v0194, v0193);
    env = stack[-3];
    v0193 = Latsoc(nil, v0195, v0193);
    stack[-2] = v0193;
    if (v0193 == nil) goto v0201;
    v0193 = stack[-2];
    v0193 = qcdr(v0193);
    stack[0] = v0193;
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    qvalue(elt(env, 2)) = v0193; /* yylval */
    v0193 = stack[0];
    v0194 = qcar(v0193);
    v0193 = elt(env, 15); /* lex_code */
    v0193 = get(v0194, v0193);
    env = stack[-3];
    stack[0] = v0193;
    v0193 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0193; /* lex_char */
    v0194 = qvalue(elt(env, 5)); /* lex_char */
    v0193 = qvalue(elt(env, 9)); /* !$eol!$ */
    if (!(equal(v0194, v0193))) goto v0202;
    v0193 = qvalue(elt(env, 10)); /* which_line */
    v0193 = add1(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 10)) = v0193; /* which_line */
    goto v0202;

v0202:
    v0194 = qvalue(elt(env, 5)); /* lex_char */
    v0193 = qvalue(elt(env, 11)); /* !$eof!$ */
    if (equal(v0194, v0193)) goto v0200;
    v0193 = qvalue(elt(env, 12)); /* last64p */
    v0193 = add1(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 12)) = v0193; /* last64p */
    v0194 = qvalue(elt(env, 12)); /* last64p */
    v0193 = (Lisp_Object)1025; /* 64 */
    if (!(v0194 == v0193)) goto v0203;
    v0193 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v0193; /* last64p */
    goto v0203;

v0203:
    v0195 = qvalue(elt(env, 13)); /* last64 */
    v0194 = qvalue(elt(env, 12)); /* last64p */
    v0193 = qvalue(elt(env, 5)); /* lex_char */
    *(Lisp_Object *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL))) = v0193;
    goto v0200;

v0201:
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 14); /* !#define */
    v0193 = get(v0194, v0193);
    env = stack[-3];
    stack[-2] = v0193;
    if (v0193 == nil) goto v0204;
    v0193 = stack[-2];
    v0193 = qcdr(v0193);
    qvalue(elt(env, 2)) = v0193; /* yylval */
    v0193 = stack[-2];
    v0193 = qcar(v0193);
    stack[0] = v0193;
    v0193 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0193;
    goto v0095;

v0204:
    v0193 = qvalue(elt(env, 7)); /* t */
    stack[-2] = v0193;
    goto v0095;

v0009:
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 20); /* !#if */
    if (v0194 == v0193) goto v0205;
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 21); /* !#else */
    if (v0194 == v0193) goto v0206;
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 22); /* !#elif */
    v0193 = (v0194 == v0193 ? lisp_true : nil);
    goto v0207;

v0207:
    if (v0193 == nil) goto v0208;
    v0194 = qvalue(elt(env, 23)); /* if_depth */
    v0193 = (Lisp_Object)1; /* 0 */
    if (v0194 == v0193) goto v0209;
    v0193 = qvalue(elt(env, 23)); /* if_depth */
    v0193 = sub1(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 23)) = v0193; /* if_depth */
    goto v0210;

v0210:
    v0193 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v0193; /* yylval */
    v0194 = stack[0];
    v0193 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 30); /* lex_skipping */
    v0193 = (*qfn2(fn))(qenv(fn), v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[0] = v0193;
    goto v0095;

v0209:
    v0193 = elt(env, 24); /* "Unexpected #else of #elif" */
    fn = elt(env, 31); /* yyerror */
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    goto v0210;

v0208:
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 25); /* !#endif */
    if (v0194 == v0193) goto v0211;
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 27); /* !#eval */
    if (v0194 == v0193) goto v0212;
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 14); /* !#define */
    if (v0194 == v0193) goto v0213;
    v0194 = elt(env, 19); /* !:symbol */
    v0193 = elt(env, 15); /* lex_code */
    v0193 = get(v0194, v0193);
    env = stack[-3];
    stack[0] = v0193;
    v0193 = qvalue(elt(env, 7)); /* t */
    stack[-2] = v0193;
    goto v0095;

v0213:
    fn = elt(env, 32); /* read_s_expression */
    v0193 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    v0193 = qvalue(elt(env, 2)); /* yylval */
    stack[0] = v0193;
    fn = elt(env, 32); /* read_s_expression */
    v0193 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[-2] = v0193;
    v0193 = stack[0];
    if (!(symbolp(v0193))) goto v0214;
    stack[-1] = stack[0];
    stack[0] = elt(env, 14); /* !#define */
    v0194 = stack[-2];
    v0193 = qvalue(elt(env, 2)); /* yylval */
    v0193 = cons(v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    v0193 = Lputprop(nil, 3, stack[-1], stack[0], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    goto v0214;

v0214:
    fn = elt(env, 29); /* lex_basic_token */
    v0193 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[0] = v0193;
    v0193 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0193;
    goto v0095;

v0212:
    fn = elt(env, 32); /* read_s_expression */
    v0193 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    v0195 = qvalue(elt(env, 2)); /* yylval */
    v0194 = qvalue(elt(env, 1)); /* nil */
    v0193 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 33); /* errorset */
    v0193 = (*qfnn(fn))(qenv(fn), 3, v0195, v0194, v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    fn = elt(env, 29); /* lex_basic_token */
    v0193 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[0] = v0193;
    goto v0095;

v0211:
    v0194 = qvalue(elt(env, 23)); /* if_depth */
    v0193 = (Lisp_Object)1; /* 0 */
    if (v0194 == v0193) goto v0215;
    v0193 = qvalue(elt(env, 23)); /* if_depth */
    v0193 = sub1(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 23)) = v0193; /* if_depth */
    goto v0216;

v0216:
    fn = elt(env, 29); /* lex_basic_token */
    v0193 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[0] = v0193;
    goto v0095;

v0215:
    v0193 = elt(env, 26); /* "Unexpected #endif" */
    fn = elt(env, 31); /* yyerror */
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    goto v0216;

v0206:
    v0193 = qvalue(elt(env, 7)); /* t */
    goto v0207;

v0205:
    fn = elt(env, 32); /* read_s_expression */
    v0193 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    v0193 = qvalue(elt(env, 2)); /* yylval */
    fn = elt(env, 34); /* lex_conditional */
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[0] = v0193;
    goto v0095;

v0199:
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 14); /* !#define */
    v0193 = get(v0194, v0193);
    env = stack[-3];
    stack[0] = v0193;
    if (v0193 == nil) goto v0022;
    v0193 = stack[0];
    v0193 = qcdr(v0193);
    qvalue(elt(env, 2)) = v0193; /* yylval */
    v0193 = stack[0];
    v0193 = qcar(v0193);
    stack[0] = v0193;
    goto v0095;

v0022:
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 15); /* lex_code */
    v0193 = get(v0194, v0193);
    env = stack[-3];
    stack[-2] = v0193;
    if (v0193 == nil) goto v0217;
    v0193 = stack[-2];
    stack[0] = v0193;
    goto v0218;

v0218:
    v0193 = qvalue(elt(env, 7)); /* t */
    stack[-2] = v0193;
    goto v0095;

v0217:
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 16); /* rlis */
    v0193 = Lflagp(nil, v0194, v0193);
    env = stack[-3];
    if (v0193 == nil) goto v0219;
    v0194 = elt(env, 17); /* rlistat */
    v0193 = elt(env, 15); /* lex_code */
    v0193 = get(v0194, v0193);
    env = stack[-3];
    stack[0] = v0193;
    goto v0218;

v0219:
    v0194 = qvalue(elt(env, 2)); /* yylval */
    v0193 = elt(env, 18); /* endstat */
    v0193 = Lflagp(nil, v0194, v0193);
    env = stack[-3];
    if (v0193 == nil) goto v0220;
    v0194 = elt(env, 18); /* endstat */
    v0193 = elt(env, 15); /* lex_code */
    v0193 = get(v0194, v0193);
    env = stack[-3];
    stack[0] = v0193;
    goto v0218;

v0220:
    v0194 = elt(env, 19); /* !:symbol */
    v0193 = elt(env, 15); /* lex_code */
    v0193 = get(v0194, v0193);
    env = stack[-3];
    stack[0] = v0193;
    goto v0218;

v0198:
    v0194 = qvalue(elt(env, 5)); /* lex_char */
    v0193 = elt(env, 6); /* !; */
    if (v0194 == v0193) goto v0072;
    v0194 = qvalue(elt(env, 5)); /* lex_char */
    v0193 = elt(env, 8); /* !$ */
    v0193 = (v0194 == v0193 ? lisp_true : nil);
    goto v0073;

v0073:
    if (v0193 == nil) goto v0058;
    v0193 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0193; /* lex_char */
    v0194 = qvalue(elt(env, 5)); /* lex_char */
    v0193 = qvalue(elt(env, 9)); /* !$eol!$ */
    if (!(equal(v0194, v0193))) goto v0221;
    v0193 = qvalue(elt(env, 10)); /* which_line */
    v0193 = add1(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 10)) = v0193; /* which_line */
    goto v0221;

v0221:
    v0194 = qvalue(elt(env, 5)); /* lex_char */
    v0193 = qvalue(elt(env, 11)); /* !$eof!$ */
    if (equal(v0194, v0193)) goto v0043;
    v0193 = qvalue(elt(env, 12)); /* last64p */
    v0193 = add1(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 12)) = v0193; /* last64p */
    v0194 = qvalue(elt(env, 12)); /* last64p */
    v0193 = (Lisp_Object)1025; /* 64 */
    if (!(v0194 == v0193)) goto v0102;
    v0193 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v0193; /* last64p */
    goto v0102;

v0102:
    v0195 = qvalue(elt(env, 13)); /* last64 */
    v0194 = qvalue(elt(env, 12)); /* last64p */
    v0193 = qvalue(elt(env, 5)); /* lex_char */
    *(Lisp_Object *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL))) = v0193;
    goto v0043;

v0043:
    fn = elt(env, 29); /* lex_basic_token */
    v0193 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    stack[0] = v0193;
    goto v0060;

v0058:
    v0193 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 5)) = v0193; /* lex_char */
    v0194 = qvalue(elt(env, 5)); /* lex_char */
    v0193 = qvalue(elt(env, 9)); /* !$eol!$ */
    if (!(equal(v0194, v0193))) goto v0222;
    v0193 = qvalue(elt(env, 10)); /* which_line */
    v0193 = add1(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 10)) = v0193; /* which_line */
    goto v0222;

v0222:
    v0194 = qvalue(elt(env, 5)); /* lex_char */
    v0193 = qvalue(elt(env, 11)); /* !$eof!$ */
    if (equal(v0194, v0193)) goto v0198;
    v0193 = qvalue(elt(env, 12)); /* last64p */
    v0193 = add1(v0193);
    nil = C_nil;
    if (exception_pending()) goto v0196;
    env = stack[-3];
    qvalue(elt(env, 12)) = v0193; /* last64p */
    v0194 = qvalue(elt(env, 12)); /* last64p */
    v0193 = (Lisp_Object)1025; /* 64 */
    if (!(v0194 == v0193)) goto v0223;
    v0193 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v0193; /* last64p */
    goto v0223;

v0223:
    v0195 = qvalue(elt(env, 13)); /* last64 */
    v0194 = qvalue(elt(env, 12)); /* last64p */
    v0193 = qvalue(elt(env, 5)); /* lex_char */
    *(Lisp_Object *)((char *)v0195 + (CELL-TAG_VECTOR) + ((int32_t)v0194/(16/CELL))) = v0193;
    goto v0198;

v0072:
    v0193 = qvalue(elt(env, 7)); /* t */
    goto v0073;

v0069:
    v0194 = stack[0];
    v0193 = elt(env, 4); /* !:symbol_or_keyword */
    v0193 = (v0194 == v0193 ? lisp_true : nil);
    goto v0197;
/* error exit handlers */
v0196:
    popv(4);
    return nil;
}



/* Code for mksq */

static Lisp_Object CC_mksq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0252, v0253;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksq");
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
    stack[-2] = nil;
    stack[-1] = nil;
    v0252 = qvalue(elt(env, 1)); /* subfg!* */
    if (v0252 == nil) goto v0068;
    v0253 = stack[-4];
    v0252 = qvalue(elt(env, 2)); /* wtl!* */
    v0252 = Lassoc(nil, v0253, v0252);
    stack[-2] = v0252;
    if (v0252 == nil) goto v0254;
    stack[0] = elt(env, 3); /* k!* */
    v0253 = stack[-3];
    v0252 = stack[-2];
    v0252 = qcdr(v0252);
    v0252 = times2(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    v0252 = CC_mksq(env, stack[0], v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    stack[-2] = v0252;
    v0252 = qcar(v0252);
    if (v0252 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    else goto v0254;

v0254:
    v0252 = stack[-4];
    if (!consp(v0252)) goto v0057;
    v0252 = qvalue(elt(env, 4)); /* !*nosubs */
    if (v0252 == nil) goto v0255;
    v0252 = qvalue(elt(env, 5)); /* nil */
    goto v0256;

v0256:
    if (!(v0252 == nil)) goto v0257;
    stack[0] = elt(env, 6); /* used!* */
    v0252 = stack[-4];
    fn = elt(env, 14); /* fkern */
    v0252 = (*qfn1(fn))(qenv(fn), v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    stack[-5] = v0252;
    v0252 = qcdr(v0252);
    v0252 = qcdr(v0252);
    v0252 = Lmemq(nil, stack[0], v0252);
    if (!(v0252 == nil)) goto v0095;
    v0253 = stack[-5];
    v0252 = elt(env, 6); /* used!* */
    fn = elt(env, 15); /* aconc */
    v0252 = (*qfn2(fn))(qenv(fn), v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    goto v0095;

v0095:
    v0252 = qvalue(elt(env, 4)); /* !*nosubs */
    if (!(v0252 == nil)) goto v0068;
    v0253 = stack[-3];
    v0252 = (Lisp_Object)17; /* 1 */
    if (v0253 == v0252) goto v0068;
    v0253 = stack[-4];
    v0252 = qvalue(elt(env, 7)); /* asymplis!* */
    v0252 = Lassoc(nil, v0253, v0252);
    stack[-1] = v0252;
    if (v0252 == nil) goto v0181;
    v0252 = stack[-1];
    v0253 = qcdr(v0252);
    v0252 = stack[-3];
    v0252 = (Lisp_Object)lesseq2(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    v0252 = v0252 ? lisp_true : nil;
    env = stack[-6];
    if (v0252 == nil) goto v0181;
    v0253 = qvalue(elt(env, 5)); /* nil */
    v0252 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v0253, v0252);

v0181:
    v0253 = stack[-4];
    v0252 = qvalue(elt(env, 8)); /* powlis!* */
    v0252 = Lassoc(nil, v0253, v0252);
    stack[-1] = v0252;
    if (!(v0252 == nil)) goto v0258;
    v0252 = stack[-4];
    if (!consp(v0252)) goto v0103;
    v0252 = stack[-4];
    v0253 = qcar(v0252);
    v0252 = elt(env, 9); /* (expt sqrt) */
    v0252 = Lmemq(nil, v0253, v0252);
    if (v0252 == nil) goto v0259;
    v0252 = stack[-4];
    v0252 = qcdr(v0252);
    v0253 = qcar(v0252);
    v0252 = qvalue(elt(env, 8)); /* powlis!* */
    v0252 = Lassoc(nil, v0253, v0252);
    stack[-1] = v0252;
    goto v0260;

v0260:
    if (!(v0252 == nil)) goto v0258;

v0068:
    v0252 = stack[-5];
    if (!(v0252 == nil)) goto v0218;
    v0252 = stack[-4];
    fn = elt(env, 14); /* fkern */
    v0252 = (*qfn1(fn))(qenv(fn), v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    stack[-5] = v0252;
    goto v0218;

v0218:
    v0253 = stack[-5];
    v0252 = stack[-3];
    fn = elt(env, 16); /* getpower */
    v0253 = (*qfn2(fn))(qenv(fn), v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    v0252 = (Lisp_Object)17; /* 1 */
    v0252 = cons(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    v0253 = ncons(v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    v0252 = (Lisp_Object)17; /* 1 */
    v0252 = cons(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    stack[-5] = v0252;
    v0252 = stack[-2];
    if (v0252 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v0253 = stack[-2];
    v0252 = stack[-5];
    {
        popv(7);
        fn = elt(env, 17); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0253, v0252);
    }

v0258:
    v0253 = stack[-3];
    v0252 = stack[-1];
    v0252 = qcdr(v0252);
    v0252 = qcar(v0252);
    v0253 = times2(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    v0252 = (Lisp_Object)1; /* 0 */
    v0252 = (Lisp_Object)lessp2(v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    v0252 = v0252 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0252 == nil)) goto v0068;
    v0252 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 11)) = v0252; /* !*sub2 */
    goto v0068;

v0259:
    v0252 = qvalue(elt(env, 5)); /* nil */
    goto v0260;

v0103:
    v0252 = qvalue(elt(env, 5)); /* nil */
    goto v0260;

v0257:
    v0252 = stack[-1];
    v0252 = qcdr(v0252);
    stack[-1] = v0252;
    v0252 = qvalue(elt(env, 13)); /* !*resubs */
    if (!(v0252 == nil)) goto v0210;
    v0252 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 4)) = v0252; /* !*nosubs */
    goto v0210;

v0210:
    v0252 = stack[-1];
    fn = elt(env, 18); /* simpcar */
    v0252 = (*qfn1(fn))(qenv(fn), v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    stack[-5] = v0252;
    v0252 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 4)) = v0252; /* !*nosubs */
    v0253 = stack[-5];
    v0252 = stack[-3];
    {
        popv(7);
        fn = elt(env, 19); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v0253, v0252);
    }

v0255:
    v0252 = stack[-4];
    v0252 = qcar(v0252);
    if (!consp(v0252)) goto v0261;
    v0252 = qvalue(elt(env, 5)); /* nil */
    goto v0256;

v0261:
    v0252 = stack[-4];
    v0253 = qcar(v0252);
    v0252 = elt(env, 12); /* mksqsubfn */
    v0252 = get(v0253, v0252);
    env = stack[-6];
    stack[-1] = v0252;
    if (v0252 == nil) goto v0017;
    v0253 = stack[-1];
    v0252 = stack[-4];
    v0252 = Lapply1(nil, v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    stack[-1] = v0252;
    goto v0016;

v0016:
    if (!(v0252 == nil)) goto v0256;
    v0253 = stack[-4];
    v0252 = stack[-4];
    v0252 = qcar(v0252);
    if (!symbolp(v0252)) v0252 = nil;
    else { v0252 = qfastgets(v0252);
           if (v0252 != nil) { v0252 = elt(v0252, 50); /* kvalue */
#ifdef RECORD_GET
             if (v0252 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v0252 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v0252 == SPID_NOPROP) v0252 = nil; }}
#endif
    v0252 = Lassoc(nil, v0253, v0252);
    stack[-1] = v0252;
    goto v0256;

v0017:
    v0252 = qvalue(elt(env, 5)); /* nil */
    goto v0016;

v0057:
    v0252 = qvalue(elt(env, 4)); /* !*nosubs */
    if (v0252 == nil) goto v0072;
    v0252 = qvalue(elt(env, 5)); /* nil */
    goto v0073;

v0073:
    if (!(v0252 == nil)) goto v0257;
    v0252 = stack[-4];
    if (!(symbolp(v0252))) goto v0095;
    v0252 = stack[-4];
    v0253 = ncons(v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    v0252 = elt(env, 6); /* used!* */
    v0252 = Lflag(nil, v0253, v0252);
    nil = C_nil;
    if (exception_pending()) goto v0150;
    env = stack[-6];
    goto v0095;

v0072:
    v0252 = stack[-4];
    if (!symbolp(v0252)) v0252 = nil;
    else { v0252 = qfastgets(v0252);
           if (v0252 != nil) { v0252 = elt(v0252, 4); /* avalue */
#ifdef RECORD_GET
             if (v0252 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0252 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0252 == SPID_NOPROP) v0252 = nil; }}
#endif
    stack[-1] = v0252;
    goto v0073;
/* error exit handlers */
v0150:
    popv(7);
    return nil;
}



/* Code for ofsf_optsubstat */

static Lisp_Object MS_CDECL CC_ofsf_optsubstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0268, v0088;
    Lisp_Object fn;
    Lisp_Object v0100, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_optsubstat");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0100 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_optsubstat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0100,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0268 = v0100;
    stack[-2] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    v0088 = qcar(v0088);
    fn = elt(env, 2); /* ofsf_optsplitterm */
    v0268 = (*qfn2(fn))(qenv(fn), v0088, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-4];
    stack[-3] = v0268;
    if (v0268 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0268 = stack[0];
    stack[-1] = qcar(v0268);
    v0268 = stack[-3];
    v0088 = qcar(v0268);
    v0268 = stack[-2];
    v0268 = qcar(v0268);
    fn = elt(env, 3); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0088, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-4];
    v0268 = stack[-3];
    v0088 = qcdr(v0268);
    v0268 = stack[-2];
    v0268 = qcdr(v0268);
    fn = elt(env, 3); /* multf */
    v0268 = (*qfn2(fn))(qenv(fn), v0088, v0268);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-4];
    fn = elt(env, 4); /* addf */
    v0268 = (*qfn2(fn))(qenv(fn), stack[0], v0268);
    nil = C_nil;
    if (exception_pending()) goto v0269;
    env = stack[-4];
    v0088 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0270 = stack[-1];
        popv(5);
        return list3(v0270, v0268, v0088);
    }
/* error exit handlers */
v0269:
    popv(5);
    return nil;
}



/* Code for binomial!-coefft!-mod!-p */

static Lisp_Object CC_binomialKcoefftKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0280, v0281, v0182, v0183, v0181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for binomial-coefft-mod-p");
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
    v0281 = stack[-2];
    v0280 = stack[-1];
    v0280 = (Lisp_Object)lessp2(v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    v0280 = v0280 ? lisp_true : nil;
    env = stack[-4];
    if (v0280 == nil) goto v0254;
    v0280 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0280); }

v0254:
    v0281 = stack[-2];
    v0280 = stack[-1];
    if (equal(v0281, v0280)) goto v0062;
    v0281 = stack[-1];
    v0280 = (Lisp_Object)17; /* 1 */
    if (v0281 == v0280) goto v0060;
    v0280 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0280;
    stack[0] = stack[-1];
    v0281 = stack[-2];
    v0280 = stack[-1];
    v0280 = difference2(v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    fn = elt(env, 2); /* min */
    v0280 = (*qfn2(fn))(qenv(fn), stack[0], v0280);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    stack[0] = v0280;
    v0280 = stack[-2];
    v0280 = Lmodular_number(nil, v0280);
    env = stack[-4];
    stack[-2] = v0280;
    v0280 = stack[-1];
    v0280 = Lmodular_number(nil, v0280);
    env = stack[-4];
    v0280 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0280;
    goto v0094;

v0094:
    v0281 = stack[0];
    v0280 = stack[-1];
    v0280 = difference2(v0281, v0280);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    v0280 = Lminusp(nil, v0280);
    env = stack[-4];
    if (v0280 == nil) goto v0189;
    v0280 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0280);
    }

v0189:
    v0280 = stack[-1];
    v0280 = Lmodular_number(nil, v0280);
    env = stack[-4];
    v0181 = v0280;
    v0183 = stack[-3];
    v0182 = stack[-2];
    v0281 = v0181;
    v0280 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v0281) - int_of_fixnum(v0280);
        if (w < 0) w += current_modulus;
        v0280 = fixnum_of_int(w);
    }
    {   int32_t w = int_of_fixnum(v0182) - int_of_fixnum(v0280);
        if (w < 0) w += current_modulus;
        v0280 = fixnum_of_int(w);
    }
    v0280 = Lmodular_times(nil, v0183, v0280);
    env = stack[-4];
    v0281 = v0181;
    v0280 = Lmodular_quotient(nil, v0280, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    stack[-3] = v0280;
    v0280 = stack[-1];
    v0280 = add1(v0280);
    nil = C_nil;
    if (exception_pending()) goto v0083;
    env = stack[-4];
    stack[-1] = v0280;
    goto v0094;

v0060:
    v0280 = stack[-2];
    v0280 = Lmodular_number(nil, v0280);
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0280);
    }

v0062:
    v0280 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0280); }
/* error exit handlers */
v0083:
    popv(5);
    return nil;
}



/* Code for bvarml */

static Lisp_Object CC_bvarml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0278, v0247;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bvarml");
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
    v0278 = elt(env, 1); /* "<bvar>" */
    fn = elt(env, 5); /* printout */
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-1];
    v0278 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 6); /* indent!* */
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-1];
    v0278 = stack[0];
    v0278 = qcar(v0278);
    fn = elt(env, 7); /* expression */
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-1];
    v0278 = stack[0];
    v0278 = qcdr(v0278);
    v0247 = qcar(v0278);
    v0278 = (Lisp_Object)17; /* 1 */
    if (v0247 == v0278) goto v0101;
    v0278 = stack[0];
    v0278 = qcdr(v0278);
    v0278 = qcar(v0278);
    v0278 = ncons(v0278);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-1];
    fn = elt(env, 8); /* degreeml */
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-1];
    goto v0101;

v0101:
    v0278 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 6); /* indent!* */
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    env = stack[-1];
    v0278 = elt(env, 4); /* "</bvar>" */
    fn = elt(env, 5); /* printout */
    v0278 = (*qfn1(fn))(qenv(fn), v0278);
    nil = C_nil;
    if (exception_pending()) goto v0282;
    v0278 = nil;
    { popv(2); return onevalue(v0278); }
/* error exit handlers */
v0282:
    popv(2);
    return nil;
}



/* Code for rationalizesq */

static Lisp_Object CC_rationalizesq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0223, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rationalizesq");
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
    stack[-4] = qvalue(elt(env, 1)); /* !*structure */
    qvalue(elt(env, 1)) = nil; /* !*structure */
    stack[-2] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v0049 = qvalue(elt(env, 3)); /* dmode!* */
    v0223 = elt(env, 4); /* rationalizefn */
    v0223 = get(v0049, v0223);
    env = stack[-5];
    stack[0] = v0223;
    if (v0223 == nil) goto v0288;
    v0049 = stack[0];
    v0223 = stack[-3];
    v0223 = Lapply1(nil, v0049, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    stack[-3] = v0223;
    goto v0288;

v0288:
    v0049 = elt(env, 5); /* (i 2 (nil . t) -1 nil) */
    v0223 = qvalue(elt(env, 6)); /* powlis!* */
    v0223 = cons(v0049, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    qvalue(elt(env, 6)) = v0223; /* powlis!* */
    v0223 = stack[-3];
    fn = elt(env, 11); /* subs2q */
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    stack[-1] = v0223;
    v0223 = qvalue(elt(env, 6)); /* powlis!* */
    v0223 = qcdr(v0223);
    qvalue(elt(env, 6)) = v0223; /* powlis!* */
    v0223 = stack[-1];
    v0223 = qcdr(v0223);
    if (!consp(v0223)) goto v0289;
    v0223 = stack[-1];
    v0223 = qcdr(v0223);
    v0223 = qcar(v0223);
    v0223 = (consp(v0223) ? nil : lisp_true);
    goto v0264;

v0264:
    if (v0223 == nil) goto v0088;
    v0223 = stack[-1];
    goto v0290;

v0290:
    qvalue(elt(env, 2)) = stack[-2]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-4]; /* !*structure */
    { popv(6); return onevalue(v0223); }

v0088:
    v0223 = stack[-1];
    v0223 = qcdr(v0223);
    fn = elt(env, 12); /* rationalizef */
    v0049 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    stack[0] = v0049;
    v0223 = (Lisp_Object)17; /* 1 */
    if (v0049 == v0223) goto v0184;
    v0223 = stack[-1];
    v0049 = qcar(v0223);
    v0223 = stack[0];
    fn = elt(env, 13); /* multf */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0049, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    v0223 = stack[-1];
    v0049 = qcdr(v0223);
    v0223 = stack[0];
    fn = elt(env, 13); /* multf */
    v0223 = (*qfn2(fn))(qenv(fn), v0049, v0223);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    v0223 = cons(stack[-3], v0223);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    stack[-1] = v0223;
    v0223 = qvalue(elt(env, 8)); /* !*algint */
    if (v0223 == nil) goto v0187;
    v0223 = qvalue(elt(env, 10)); /* nil */
    goto v0186;

v0186:
    if (v0223 == nil) goto v0291;
    v0223 = stack[-1];
    fn = elt(env, 14); /* gcdchk */
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    stack[-1] = v0223;
    goto v0291;

v0291:
    v0223 = stack[-1];
    fn = elt(env, 11); /* subs2q */
    v0223 = (*qfn1(fn))(qenv(fn), v0223);
    nil = C_nil;
    if (exception_pending()) goto v0182;
    env = stack[-5];
    goto v0290;

v0187:
    v0223 = qvalue(elt(env, 9)); /* !*rationalize */
    v0223 = (v0223 == nil ? lisp_true : nil);
    goto v0186;

v0184:
    v0223 = stack[-3];
    goto v0290;

v0289:
    v0223 = qvalue(elt(env, 7)); /* t */
    goto v0264;
/* error exit handlers */
v0182:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-2]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-4]; /* !*structure */
    popv(6);
    return nil;
}



/* Code for vdpequal */

static Lisp_Object CC_vdpequal(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0189, v0190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpequal");
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
    v0189 = stack[-1];
    v0093 = stack[0];
    if (v0189 == v0093) goto v0067;
    v0189 = stack[-1];
    v0093 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0189, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0189 = stack[0];
    v0093 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    v0093 = (*qfn2(fn))(qenv(fn), v0189, v0093);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0190 = stack[-2];
    v0189 = v0093;
    v0093 = v0190;
    if (v0093 == nil) goto v0271;
    v0093 = v0190;
    v0093 = (equal(v0093, v0189) ? lisp_true : nil);
    goto v0099;

v0099:
    if (!(v0093 == nil)) { popv(4); return onevalue(v0093); }
    v0093 = stack[-1];
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0189 = qcar(v0093);
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcdr(v0093);
    v0093 = qcar(v0093);
    {
        popv(4);
        fn = elt(env, 5); /* dipequal */
        return (*qfn2(fn))(qenv(fn), v0189, v0093);
    }

v0271:
    v0093 = qvalue(elt(env, 3)); /* nil */
    goto v0099;

v0067:
    v0093 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v0093); }
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for xdegreecheck */

static Lisp_Object CC_xdegreecheck(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0266, v0267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xdegreecheck");
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
    v0267 = v0000;
/* end of prologue */
    v0266 = qvalue(elt(env, 1)); /* xtruncate!* */
    if (v0266 == nil) goto v0233;
    v0266 = v0267;
    fn = elt(env, 3); /* xdegree */
    v0266 = (*qfn1(fn))(qenv(fn), v0266);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[0];
    v0267 = qvalue(elt(env, 1)); /* xtruncate!* */
        popv(1);
        return Lgreaterp(nil, v0266, v0267);

v0233:
    v0266 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0266); }
/* error exit handlers */
v0294:
    popv(1);
    return nil;
}



/* Code for prinlatom */

static Lisp_Object CC_prinlatom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0293, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prinlatom");
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
    v0093 = stack[-1];
    v0293 = elt(env, 1); /* font */
    v0293 = get(v0093, v0293);
    env = stack[-3];
    stack[-2] = v0293;
    if (v0293 == nil) goto v0060;
    v0293 = stack[-2];
    fn = elt(env, 5); /* prin2la */
    v0293 = (*qfn1(fn))(qenv(fn), v0293);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-3];
    goto v0060;

v0060:
    v0093 = stack[-1];
    v0293 = elt(env, 2); /* accent */
    v0293 = get(v0093, v0293);
    env = stack[-3];
    stack[0] = v0293;
    if (v0293 == nil) goto v0271;
    v0293 = stack[0];
    fn = elt(env, 5); /* prin2la */
    v0293 = (*qfn1(fn))(qenv(fn), v0293);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-3];
    goto v0271;

v0271:
    v0093 = stack[-1];
    v0293 = elt(env, 3); /* name */
    v0293 = get(v0093, v0293);
    env = stack[-3];
    v0093 = v0293;
    if (v0293 == nil) goto v0058;
    v0293 = v0093;
    fn = elt(env, 5); /* prin2la */
    v0293 = (*qfn1(fn))(qenv(fn), v0293);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-3];
    goto v0248;

v0248:
    v0293 = stack[0];
    if (v0293 == nil) goto v0097;
    v0293 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v0293 = (*qfn1(fn))(qenv(fn), v0293);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-3];
    goto v0097;

v0097:
    v0293 = stack[-2];
    if (v0293 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0293 = elt(env, 4); /* "}" */
    fn = elt(env, 5); /* prin2la */
    v0293 = (*qfn1(fn))(qenv(fn), v0293);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0058:
    v0293 = stack[-1];
    fn = elt(env, 6); /* testchar1 */
    v0293 = (*qfn1(fn))(qenv(fn), v0293);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-3];
    fn = elt(env, 5); /* prin2la */
    v0293 = (*qfn1(fn))(qenv(fn), v0293);
    nil = C_nil;
    if (exception_pending()) goto v0295;
    env = stack[-3];
    goto v0248;
/* error exit handlers */
v0295:
    popv(4);
    return nil;
}



/* Code for rd!:times */

static Lisp_Object CC_rdTtimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0301, v0302;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:times");
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
    v0082 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v0082;
    v0082 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v0082 == nil) goto v0257;
    v0082 = qvalue(elt(env, 1)); /* nil */
    goto v0303;

v0303:
    if (v0082 == nil) goto v0088;
    v0301 = elt(env, 3); /* !:rd!: */
    v0082 = stack[0];
    popv(5);
    return cons(v0301, v0082);

v0088:
    v0301 = stack[-2];
    v0082 = stack[-1];
    fn = elt(env, 6); /* convprc2 */
    v0082 = (*qfn2(fn))(qenv(fn), v0301, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    stack[-3] = v0082;
    v0082 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v0082;
    v0082 = stack[-3];
    if (!consp(v0082)) goto v0285;
    v0301 = stack[-3];
    v0082 = stack[-2];
    fn = elt(env, 7); /* csl_timbf */
    v0082 = (*qfn2(fn))(qenv(fn), v0301, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    goto v0093;

v0093:
    {
        popv(5);
        fn = elt(env, 8); /* mkround */
        return (*qfn1(fn))(qenv(fn), v0082);
    }

v0285:
    stack[-1] = elt(env, 5); /* times2 */
    v0082 = stack[-3];
    stack[0] = Lmkquote(nil, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    v0082 = stack[-2];
    v0082 = Lmkquote(nil, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    v0301 = list3(stack[-1], stack[0], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    v0082 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 9); /* errorset!* */
    v0082 = (*qfn2(fn))(qenv(fn), v0301, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    stack[0] = v0082;
    v0082 = stack[0];
    fn = elt(env, 10); /* errorp */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    if (v0082 == nil) goto v0305;
    fn = elt(env, 11); /* rndbfon */
    v0082 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    v0082 = stack[-3];
    v0082 = Lfloatp(nil, v0082);
    env = stack[-4];
    if (v0082 == nil) goto v0306;
    v0082 = stack[-3];
    fn = elt(env, 12); /* fl2bf */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    stack[0] = v0082;
    goto v0223;

v0223:
    v0082 = stack[-2];
    v0082 = Lfloatp(nil, v0082);
    env = stack[-4];
    if (v0082 == nil) goto v0177;
    v0082 = stack[-2];
    fn = elt(env, 12); /* fl2bf */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    goto v0049;

v0049:
    fn = elt(env, 7); /* csl_timbf */
    v0082 = (*qfn2(fn))(qenv(fn), stack[0], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    goto v0093;

v0177:
    v0082 = stack[-2];
    if (!consp(v0082)) goto v0040;
    v0082 = stack[-2];
    goto v0104;

v0104:
    fn = elt(env, 13); /* normbf */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    goto v0049;

v0040:
    v0082 = stack[-2];
    v0082 = integerp(v0082);
    if (v0082 == nil) goto v0174;
    v0302 = elt(env, 3); /* !:rd!: */
    v0301 = stack[-2];
    v0082 = (Lisp_Object)1; /* 0 */
    v0082 = list2star(v0302, v0301, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    goto v0104;

v0174:
    v0082 = stack[-2];
    fn = elt(env, 14); /* read!:num */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    goto v0104;

v0306:
    v0082 = stack[-3];
    if (!consp(v0082)) goto v0307;
    v0082 = stack[-3];
    goto v0084;

v0084:
    fn = elt(env, 13); /* normbf */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    stack[0] = v0082;
    goto v0223;

v0307:
    v0082 = stack[-3];
    v0082 = integerp(v0082);
    if (v0082 == nil) goto v0179;
    v0302 = elt(env, 3); /* !:rd!: */
    v0301 = stack[-3];
    v0082 = (Lisp_Object)1; /* 0 */
    v0082 = list2star(v0302, v0301, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    goto v0084;

v0179:
    v0082 = stack[-3];
    fn = elt(env, 14); /* read!:num */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    goto v0084;

v0305:
    v0082 = stack[0];
    v0082 = qcar(v0082);
    goto v0093;

v0257:
    v0082 = stack[-2];
    v0082 = qcdr(v0082);
    if (!consp(v0082)) goto v0062;
    v0082 = qvalue(elt(env, 1)); /* nil */
    goto v0303;

v0062:
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    if (!consp(v0082)) goto v0061;
    v0082 = qvalue(elt(env, 1)); /* nil */
    goto v0303;

v0061:
    v0082 = stack[-2];
    v0301 = qcdr(v0082);
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    fn = elt(env, 15); /* safe!-fp!-times */
    v0082 = (*qfn2(fn))(qenv(fn), v0301, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0304;
    env = stack[-4];
    stack[0] = v0082;
    goto v0303;
/* error exit handlers */
v0304:
    popv(5);
    return nil;
}



/* Code for red_tailred */

static Lisp_Object CC_red_tailred(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0069, v0278;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_tailred");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0070 = v0001;
    v0278 = v0000;
/* end of prologue */
    v0069 = qvalue(elt(env, 1)); /* !*noetherian */
    if (v0069 == nil) goto v0279;
    v0069 = v0070;
    v0070 = elt(env, 2); /* red_topred */
    {
        fn = elt(env, 4); /* red_tailreddriver */
        return (*qfnn(fn))(qenv(fn), 3, v0278, v0069, v0070);
    }

v0279:
    v0069 = v0070;
    v0070 = elt(env, 3); /* red_topredbe */
    {
        fn = elt(env, 4); /* red_tailreddriver */
        return (*qfnn(fn))(qenv(fn), 3, v0278, v0069, v0070);
    }
}



/* Code for decprec2internal */

static Lisp_Object CC_decprec2internal(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0254, v0266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for decprec2internal");
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
    v0254 = v0000;
/* end of prologue */
    v0266 = v0254;
    v0254 = qvalue(elt(env, 1)); /* log2of10 */
    v0254 = times2(v0266, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    env = stack[0];
    fn = elt(env, 2); /* ceiling */
    v0266 = (*qfn1(fn))(qenv(fn), v0254);
    nil = C_nil;
    if (exception_pending()) goto v0267;
    v0254 = (Lisp_Object)49; /* 3 */
    popv(1);
    return plus2(v0266, v0254);
/* error exit handlers */
v0267:
    popv(1);
    return nil;
}



/* Code for cl_atml1 */

static Lisp_Object CC_cl_atml1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0303, v0257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atml1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0303 = v0000;
/* end of prologue */
    v0257 = v0303;
    v0303 = elt(env, 1); /* cl_atmlc */
    {
        fn = elt(env, 2); /* cl_f2ml */
        return (*qfn2(fn))(qenv(fn), v0257, v0303);
    }
}



/* Code for ofsf_sippsubst */

static Lisp_Object CC_ofsf_sippsubst(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0266, v0267, v0294;
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
    v0267 = v0001;
    v0294 = v0000;
/* end of prologue */
    v0266 = v0267;
    if (v0266 == nil) return onevalue(v0294);
    v0266 = v0294;
    {
        fn = elt(env, 1); /* ofsf_sippsubst1 */
        return (*qfn2(fn))(qenv(fn), v0266, v0267);
    }
}



/* Code for cgp_ci */

static Lisp_Object CC_cgp_ci(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0303, v0257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_ci");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0303 = v0000;
/* end of prologue */
    v0257 = v0303;
    v0303 = (Lisp_Object)97; /* 6 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v0257, v0303);
    }
}



/* Code for downwght1 */

static Lisp_Object CC_downwght1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0169, v0321;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for downwght1");
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
    v0169 = v0001;
    stack[-4] = v0000;
/* end of prologue */
    fn = elt(env, 3); /* dm!-abs */
    v0169 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    fn = elt(env, 4); /* !:onep */
    v0169 = (*qfn1(fn))(qenv(fn), v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    if (v0169 == nil) goto v0063;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0321 = qvalue(elt(env, 2)); /* maxvar */
    v0169 = stack[-4];
    v0169 = plus2(v0321, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    stack[-5] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0321 = qvalue(elt(env, 2)); /* maxvar */
    v0169 = stack[-4];
    v0169 = plus2(v0321, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    v0321 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = (Lisp_Object)17; /* 1 */
    v0169 = *(Lisp_Object *)((char *)v0321 + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    stack[-2] = sub1(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0321 = qvalue(elt(env, 2)); /* maxvar */
    v0169 = stack[-4];
    v0169 = plus2(v0321, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    v0321 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = (Lisp_Object)17; /* 1 */
    v0169 = *(Lisp_Object *)((char *)v0321 + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = qcar(v0169);
    stack[-1] = qcdr(v0169);
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0321 = qvalue(elt(env, 2)); /* maxvar */
    v0169 = stack[-4];
    v0169 = plus2(v0321, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    v0321 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = (Lisp_Object)17; /* 1 */
    v0169 = *(Lisp_Object *)((char *)v0321 + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = qcdr(v0169);
    v0169 = sub1(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    v0169 = acons(stack[-2], stack[-1], v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    *(Lisp_Object *)((char *)stack[-5] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v0169;
    { popv(7); return onevalue(v0169); }

v0063:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0321 = qvalue(elt(env, 2)); /* maxvar */
    v0169 = stack[-4];
    v0169 = plus2(v0321, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    stack[-5] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0321 = qvalue(elt(env, 2)); /* maxvar */
    v0169 = stack[-4];
    v0169 = plus2(v0321, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    v0321 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = (Lisp_Object)17; /* 1 */
    v0169 = *(Lisp_Object *)((char *)v0321 + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = qcar(v0169);
    v0169 = qcar(v0169);
    stack[-2] = sub1(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0321 = qvalue(elt(env, 2)); /* maxvar */
    v0169 = stack[-4];
    v0169 = plus2(v0321, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    v0321 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = (Lisp_Object)17; /* 1 */
    v0169 = *(Lisp_Object *)((char *)v0321 + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = qcar(v0169);
    v0169 = qcdr(v0169);
    stack[-1] = sub1(v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0321 = qvalue(elt(env, 2)); /* maxvar */
    v0169 = stack[-4];
    v0169 = plus2(v0321, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    v0321 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0169 = (Lisp_Object)17; /* 1 */
    v0169 = *(Lisp_Object *)((char *)v0321 + (CELL-TAG_VECTOR) + ((int32_t)v0169/(16/CELL)));
    v0321 = qcdr(v0169);
    v0169 = (Lisp_Object)65; /* 4 */
    v0169 = difference2(v0321, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-6];
    v0169 = acons(stack[-2], stack[-1], v0169);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    *(Lisp_Object *)((char *)stack[-5] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v0169;
    { popv(7); return onevalue(v0169); }
/* error exit handlers */
v0167:
    popv(7);
    return nil;
}



/* Code for dip!-nc!-ev!-prod1 */

static Lisp_Object MS_CDECL CC_dipKncKevKprod1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0248, v0282, v0098, v0099;
    Lisp_Object fn;
    Lisp_Object v0100, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dip-nc-ev-prod1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0100 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dip-nc-ev-prod1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0100,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0282 = v0100;
    v0098 = v0001;
    v0099 = v0000;
/* end of prologue */
    v0248 = v0099;
    if (v0248 == nil) { popv(3); return onevalue(v0282); }
    v0248 = v0099;
    stack[-1] = qcar(v0248);
    stack[0] = v0098;
    v0248 = v0099;
    v0248 = qcdr(v0248);
    v0098 = (Lisp_Object)((int32_t)(v0098) + 0x10);
    v0248 = CC_dipKncKevKprod1(env, 3, v0248, v0098, v0282);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-2];
    {
        Lisp_Object v0111 = stack[-1];
        Lisp_Object v0250 = stack[0];
        popv(3);
        fn = elt(env, 1); /* dip!-nc!-ev!-prod2 */
        return (*qfnn(fn))(qenv(fn), 3, v0111, v0250, v0248);
    }
/* error exit handlers */
v0249:
    popv(3);
    return nil;
}



/* Code for bas_newnumber */

static Lisp_Object CC_bas_newnumber(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0107;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bas_newnumber");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0101 = v0001;
    v0107 = v0000;
/* end of prologue */
    v0101 = qcdr(v0101);
    return cons(v0107, v0101);
}



/* Code for simp!-prop!-order */

static Lisp_Object CC_simpKpropKorder(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0250, v0264, v0289, v0265;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp-prop-order");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0264 = v0001;
    v0289 = v0000;
/* end of prologue */

v0067:
    v0250 = v0289;
    if (v0250 == nil) goto v0095;
    v0250 = v0289;
    v0250 = qcar(v0250);
    v0265 = qcar(v0250);
    v0250 = v0264;
    v0250 = qcar(v0250);
    v0250 = qcar(v0250);
    if (equal(v0265, v0250)) goto v0101;
    v0250 = v0289;
    v0250 = qcar(v0250);
    v0264 = qcar(v0250);
    v0250 = elt(env, 2); /* prop!* */
    if (v0264 == v0250) goto v0288;
    v0250 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0250);

v0288:
    v0250 = qvalue(elt(env, 3)); /* t */
    return onevalue(v0250);

v0101:
    v0250 = v0289;
    v0250 = qcdr(v0250);
    v0289 = v0250;
    v0250 = v0264;
    v0250 = qcdr(v0250);
    v0264 = v0250;
    goto v0067;

v0095:
    v0250 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0250);
}



/* Code for resimpf */

static Lisp_Object CC_resimpf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0106;
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
    v0106 = v0000;
/* end of prologue */
    v0107 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v0107; /* varstack!* */
    v0107 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* subf1 */
    v0107 = (*qfn2(fn))(qenv(fn), v0106, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-1];
    v0107 = qcar(v0107);
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    { popv(2); return onevalue(v0107); }
/* error exit handlers */
v0062:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* varstack!* */
    popv(2);
    return nil;
}



/* Code for gf2cr!: */

static Lisp_Object CC_gf2crT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063;
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
    v0063 = stack[-1];
    v0063 = qcar(v0063);
    fn = elt(env, 2); /* striptag */
    stack[0] = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-3];
    v0063 = stack[-1];
    v0063 = qcdr(v0063);
    fn = elt(env, 2); /* striptag */
    v0063 = (*qfn1(fn))(qenv(fn), v0063);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    {
        Lisp_Object v0192 = stack[-2];
        Lisp_Object v0197 = stack[0];
        popv(4);
        return list2star(v0192, v0197, v0063);
    }
/* error exit handlers */
v0294:
    popv(4);
    return nil;
}



/* Code for s!:prinl2 */

static Lisp_Object CC_sTprinl2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0338, v0339;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for s:prinl2");
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
    v0338 = qvalue(elt(env, 1)); /* !*print!-level!* */
    v0338 = integerp(v0338);
    if (v0338 == nil) goto v0294;
    v0339 = stack[-2];
    v0338 = qvalue(elt(env, 1)); /* !*print!-level!* */
    v0338 = (Lisp_Object)greaterp2(v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0338 = v0338 ? lisp_true : nil;
    env = stack[-5];
    if (v0338 == nil) goto v0294;
    v0338 = elt(env, 2); /* "#" */
        popv(6);
        return Lprinc(nil, v0338);

v0294:
    v0338 = stack[-3];
    if (!consp(v0338)) goto v0288;
    v0338 = qvalue(elt(env, 3)); /* nil */
    goto v0340;

v0340:
    if (v0338 == nil) goto v0341;
    v0339 = qvalue(elt(env, 4)); /* !*prinl!-fn!* */
    v0338 = stack[-3];
        popv(6);
        return Lapply1(nil, v0339, v0338);

v0341:
    v0339 = stack[-3];
    v0338 = qvalue(elt(env, 5)); /* !*prinl!-visited!-nodes!* */
    fn = elt(env, 19); /* gethash */
    v0338 = (*qfn2(fn))(qenv(fn), v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[-1] = v0338;
    v0338 = stack[-1];
    v0338 = (Lisp_Object)zerop(v0338);
    v0338 = v0338 ? lisp_true : nil;
    env = stack[-5];
    if (!(v0338 == nil)) goto v0189;
    v0339 = stack[-1];
    v0338 = (Lisp_Object)1; /* 0 */
    v0338 = (Lisp_Object)lessp2(v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0338 = v0338 ? lisp_true : nil;
    env = stack[-5];
    if (v0338 == nil) goto v0187;
    v0338 = elt(env, 2); /* "#" */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = stack[-1];
    v0338 = negate(v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = elt(env, 2); /* "#" */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v0338); }

v0187:
    stack[-4] = stack[-3];
    stack[0] = qvalue(elt(env, 5)); /* !*prinl!-visited!-nodes!* */
    v0338 = stack[-1];
    v0338 = negate(v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    fn = elt(env, 20); /* puthash */
    v0338 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[0], v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = elt(env, 2); /* "#" */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = stack[-1];
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = elt(env, 6); /* "=" */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    goto v0189;

v0189:
    v0338 = stack[-3];
    fn = elt(env, 21); /* simple!-vector!-p */
    v0338 = (*qfn1(fn))(qenv(fn), v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    if (v0338 == nil) goto v0218;
    v0338 = elt(env, 7); /* "%(" */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = qvalue(elt(env, 8)); /* !*print!-array!* */
    if (v0338 == nil) goto v0030;
    v0338 = stack[-3];
    v0338 = Lupbv(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[-4] = v0338;
    v0338 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0338 = integerp(v0338);
    if (v0338 == nil) goto v0241;
    v0339 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0338 = stack[-4];
    v0338 = (Lisp_Object)lessp2(v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0338 = v0338 ? lisp_true : nil;
    env = stack[-5];
    if (v0338 == nil) goto v0241;
    v0338 = qvalue(elt(env, 9)); /* !*print!-length!* */
    stack[-4] = v0338;
    goto v0241;

v0241:
    v0338 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0338;
    goto v0037;

v0037:
    v0339 = stack[-4];
    v0338 = stack[-1];
    v0338 = difference2(v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = Lminusp(nil, v0338);
    env = stack[-5];
    if (!(v0338 == nil)) goto v0306;
    v0339 = stack[-3];
    v0338 = stack[-1];
    stack[0] = *(Lisp_Object *)((char *)v0339 + (CELL-TAG_VECTOR) + ((int32_t)v0338/(16/CELL)));
    v0338 = stack[-2];
    v0338 = add1(v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = CC_sTprinl2(env, stack[0], v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[0] = stack[-1];
    v0338 = stack[-3];
    v0338 = Lupbv(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    if (equal(stack[0], v0338)) goto v0297;
    v0338 = elt(env, 10); /* " " */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    goto v0297;

v0297:
    v0338 = stack[-1];
    v0338 = add1(v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[-1] = v0338;
    goto v0037;

v0306:
    v0338 = elt(env, 12); /* ")" */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v0338); }

v0030:
    v0338 = elt(env, 11); /* "..." */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    goto v0306;

v0218:
    v0338 = stack[-3];
    if (!consp(v0338)) goto v0234;
    v0338 = elt(env, 13); /* "(" */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0338;
    goto v0342;

v0342:
    v0338 = stack[-3];
    stack[0] = qcar(v0338);
    v0338 = stack[-2];
    v0338 = add1(v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = CC_sTprinl2(env, stack[0], v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = stack[-3];
    v0338 = qcdr(v0338);
    stack[-3] = v0338;
    v0338 = stack[-3];
    if (!consp(v0338)) goto v0343;
    v0338 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0338 = integerp(v0338);
    if (v0338 == nil) goto v0344;
    v0338 = stack[-4];
    v0339 = add1(v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[-4] = v0339;
    v0338 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0338 = (Lisp_Object)greaterp2(v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0338 = v0338 ? lisp_true : nil;
    env = stack[-5];
    if (v0338 == nil) goto v0344;
    v0338 = elt(env, 16); /* " ...)" */
        popv(6);
        return Lprinc(nil, v0338);

v0344:
    v0339 = stack[-3];
    v0338 = qvalue(elt(env, 5)); /* !*prinl!-visited!-nodes!* */
    fn = elt(env, 19); /* gethash */
    v0338 = (*qfn2(fn))(qenv(fn), v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[-1] = v0338;
    v0339 = stack[-1];
    v0338 = (Lisp_Object)1; /* 0 */
    if (v0339 == v0338) goto v0137;
    v0339 = stack[-1];
    v0338 = (Lisp_Object)1; /* 0 */
    v0338 = (Lisp_Object)lessp2(v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0338 = v0338 ? lisp_true : nil;
    env = stack[-5];
    if (v0338 == nil) goto v0345;
    v0338 = elt(env, 17); /* " . #" */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = stack[-1];
    v0338 = negate(v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = elt(env, 18); /* "#)" */
        popv(6);
        return Lprinc(nil, v0338);

v0345:
    v0338 = elt(env, 15); /* " . " */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[0] = stack[-3];
    v0338 = stack[-2];
    v0338 = add1(v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = CC_sTprinl2(env, stack[0], v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = elt(env, 12); /* ")" */
        popv(6);
        return Lprinc(nil, v0338);

v0137:
    v0338 = elt(env, 10); /* " " */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    goto v0342;

v0343:
    v0338 = stack[-3];
    fn = elt(env, 21); /* simple!-vector!-p */
    v0338 = (*qfn1(fn))(qenv(fn), v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    if (v0338 == nil) goto v0253;
    v0338 = elt(env, 14); /* " . %(" */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = qvalue(elt(env, 8)); /* !*print!-array!* */
    if (v0338 == nil) goto v0346;
    v0338 = stack[-3];
    v0338 = Lupbv(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[-4] = v0338;
    v0338 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0338 = integerp(v0338);
    if (v0338 == nil) goto v0220;
    v0339 = qvalue(elt(env, 9)); /* !*print!-length!* */
    v0338 = stack[-4];
    v0338 = (Lisp_Object)lessp2(v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    v0338 = v0338 ? lisp_true : nil;
    env = stack[-5];
    if (v0338 == nil) goto v0220;
    v0338 = qvalue(elt(env, 9)); /* !*print!-length!* */
    stack[-4] = v0338;
    goto v0220;

v0220:
    v0338 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0338;
    goto v0157;

v0157:
    v0339 = stack[-4];
    v0338 = stack[-1];
    v0338 = difference2(v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = Lminusp(nil, v0338);
    env = stack[-5];
    if (!(v0338 == nil)) goto v0016;
    v0339 = stack[-3];
    v0338 = stack[-1];
    stack[0] = *(Lisp_Object *)((char *)v0339 + (CELL-TAG_VECTOR) + ((int32_t)v0338/(16/CELL)));
    v0338 = stack[-2];
    v0338 = add1(v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = CC_sTprinl2(env, stack[0], v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[0] = stack[-1];
    v0338 = stack[-3];
    v0338 = Lupbv(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    if (equal(stack[0], v0338)) goto v0154;
    v0338 = elt(env, 10); /* " " */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    goto v0154;

v0154:
    v0338 = stack[-1];
    v0338 = add1(v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    stack[-1] = v0338;
    goto v0157;

v0016:
    v0338 = elt(env, 12); /* ")" */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    goto v0011;

v0011:
    v0338 = elt(env, 12); /* ")" */
        popv(6);
        return Lprinc(nil, v0338);

v0346:
    v0338 = elt(env, 11); /* "..." */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    goto v0016;

v0253:
    v0338 = stack[-3];
    if (v0338 == nil) goto v0011;
    v0338 = elt(env, 15); /* " . " */
    v0338 = Lprinc(nil, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0339 = qvalue(elt(env, 4)); /* !*prinl!-fn!* */
    v0338 = stack[-3];
    v0338 = Lapply1(nil, v0339, v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    goto v0011;

v0234:
    v0339 = qvalue(elt(env, 4)); /* !*prinl!-fn!* */
    v0338 = stack[-3];
        popv(6);
        return Lapply1(nil, v0339, v0338);

v0288:
    v0338 = stack[-3];
    fn = elt(env, 21); /* simple!-vector!-p */
    v0338 = (*qfn1(fn))(qenv(fn), v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    if (v0338 == nil) goto v0278;
    v0338 = qvalue(elt(env, 3)); /* nil */
    goto v0340;

v0278:
    v0338 = stack[-3];
    fn = elt(env, 22); /* gensymp */
    v0338 = (*qfn1(fn))(qenv(fn), v0338);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-5];
    v0338 = (v0338 == nil ? lisp_true : nil);
    goto v0340;
/* error exit handlers */
v0131:
    popv(6);
    return nil;
}



/* Code for formrlis */

static Lisp_Object MS_CDECL CC_formrlis(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0259, v0043;
    Lisp_Object fn;
    Lisp_Object v0100, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formrlis");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0100 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formrlis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0100,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0044 = v0100;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0044 = stack[-2];
    v0259 = qcar(v0044);
    v0044 = elt(env, 1); /* flagop */
    v0044 = Lflagp(nil, v0259, v0044);
    env = stack[-4];
    if (v0044 == nil) goto v0254;
    v0044 = stack[-2];
    v0044 = qcdr(v0044);
    fn = elt(env, 8); /* idlistp */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-4];
    if (v0044 == nil) goto v0349;
    stack[-3] = elt(env, 7); /* flag */
    stack[0] = elt(env, 2); /* list */
    v0044 = stack[-2];
    v0043 = qcdr(v0044);
    v0259 = stack[-1];
    v0044 = elt(env, 4); /* algebraic */
    fn = elt(env, 9); /* formlis */
    v0044 = (*qfnn(fn))(qenv(fn), 3, v0043, v0259, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-4];
    stack[0] = cons(stack[0], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-4];
    v0044 = stack[-2];
    v0044 = qcar(v0044);
    v0044 = Lmkquote(nil, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    {
        Lisp_Object v0298 = stack[-3];
        Lisp_Object v0244 = stack[0];
        popv(5);
        return list3(v0298, v0244, v0044);
    }

v0349:
    v0259 = elt(env, 5); /* !*comma!* */
    v0044 = stack[-2];
    v0044 = qcdr(v0044);
    v0259 = cons(v0259, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-4];
    v0044 = elt(env, 6); /* "identifier list" */
    {
        popv(5);
        fn = elt(env, 10); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0259, v0044);
    }

v0254:
    v0044 = stack[-2];
    stack[-3] = qcar(v0044);
    stack[0] = elt(env, 2); /* list */
    v0044 = stack[-2];
    v0259 = qcar(v0044);
    v0044 = elt(env, 3); /* share */
    if (v0259 == v0044) goto v0278;
    v0044 = stack[-2];
    v0043 = qcdr(v0044);
    v0259 = stack[-1];
    v0044 = elt(env, 4); /* algebraic */
    fn = elt(env, 9); /* formlis */
    v0044 = (*qfnn(fn))(qenv(fn), 3, v0043, v0259, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-4];
    goto v0288;

v0288:
    v0044 = cons(stack[0], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    {
        Lisp_Object v0041 = stack[-3];
        popv(5);
        return list2(v0041, v0044);
    }

v0278:
    stack[-1] = nil;
    v0044 = stack[-2];
    v0044 = qcdr(v0044);
    stack[-2] = v0044;
    goto v0057;

v0057:
    v0044 = stack[-2];
    if (v0044 == nil) goto v0073;
    v0044 = stack[-2];
    v0044 = qcar(v0044);
    v0259 = Lmkquote(nil, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-4];
    v0044 = stack[-1];
    v0044 = cons(v0259, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-4];
    stack[-1] = v0044;
    v0044 = stack[-2];
    v0044 = qcdr(v0044);
    stack[-2] = v0044;
    goto v0057;

v0073:
    v0044 = stack[-1];
    fn = elt(env, 11); /* reversip!* */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0310;
    env = stack[-4];
    goto v0288;
/* error exit handlers */
v0310:
    popv(5);
    return nil;
}



/* Code for qqe_arg!-check!-q */

static Lisp_Object CC_qqe_argKcheckKq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_arg-check-q");
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
    v0056 = stack[0];
    fn = elt(env, 3); /* qqe_id!-nyt!-branchq */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-1];
    if (v0056 == nil) goto v0283;
    v0056 = stack[0];
    if (!consp(v0056)) goto v0308;
    v0056 = qvalue(elt(env, 1)); /* nil */
    goto v0106;

v0106:
    if (v0056 == nil) goto v0101;
    v0056 = stack[0];
    fn = elt(env, 4); /* qqe_btidp */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-1];
    if (v0056 == nil) goto v0061;
    v0056 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0056); }

v0061:
    v0056 = stack[0];
    fn = elt(env, 5); /* qqe_nytidp */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-1];
    if (v0056 == nil) goto v0277;
    v0056 = stack[0];
    fn = elt(env, 6); /* qqe_qtid */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-1];
    v0056 = stack[0];
    fn = elt(env, 7); /* qqe_add2rollbackids */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-1];
    v0056 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0056); }

v0277:
    v0056 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0056); }

v0101:
    v0056 = stack[0];
    if (is_number(v0056)) goto v0067;
    v0056 = stack[0];
    fn = elt(env, 8); /* qqe_arg!-check */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-1];
    v0056 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v0056); }

v0067:
    v0056 = nil;
    { popv(2); return onevalue(v0056); }

v0308:
    v0056 = stack[0];
    v0056 = (is_number(v0056) ? lisp_true : nil);
    v0056 = (v0056 == nil ? lisp_true : nil);
    goto v0106;

v0283:
    v0056 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0056); }
/* error exit handlers */
v0072:
    popv(2);
    return nil;
}



/* Code for bc_prod */

static Lisp_Object CC_bc_prod(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0280, v0281, v0182, v0183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bc_prod");
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
    v0183 = v0001;
    v0182 = v0000;
/* end of prologue */
    v0280 = v0182;
    v0281 = qcdr(v0280);
    v0280 = (Lisp_Object)17; /* 1 */
    if (v0281 == v0280) goto v0068;
    v0280 = qvalue(elt(env, 1)); /* nil */
    goto v0095;

v0095:
    if (v0280 == nil) goto v0185;
    v0280 = v0182;
    v0281 = qcar(v0280);
    v0280 = (Lisp_Object)17; /* 1 */
    if (v0281 == v0280) { popv(1); return onevalue(v0183); }
    v0280 = v0183;
    v0281 = qcar(v0280);
    v0280 = (Lisp_Object)17; /* 1 */
    if (v0281 == v0280) { popv(1); return onevalue(v0182); }
    v0280 = v0182;
    v0280 = qcar(v0280);
    v0281 = v0183;
    v0281 = qcar(v0281);
    v0281 = times2(v0280, v0281);
    nil = C_nil;
    if (exception_pending()) goto v0181;
    env = stack[0];
    v0182 = v0281;
    v0280 = (Lisp_Object)1; /* 0 */
    if (v0281 == v0280) goto v0272;
    v0281 = v0182;
    v0280 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v0281, v0280);

v0272:
    v0281 = qvalue(elt(env, 1)); /* nil */
    v0280 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v0281, v0280);

v0185:
    v0280 = v0182;
    v0281 = v0183;
    {
        popv(1);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0280, v0281);
    }

v0068:
    v0280 = v0182;
    v0280 = qcar(v0280);
    if (is_number(v0280)) goto v0070;
    v0280 = qvalue(elt(env, 1)); /* nil */
    goto v0095;

v0070:
    v0280 = v0183;
    v0281 = qcdr(v0280);
    v0280 = (Lisp_Object)17; /* 1 */
    if (v0281 == v0280) goto v0071;
    v0280 = qvalue(elt(env, 1)); /* nil */
    goto v0095;

v0071:
    v0280 = v0183;
    v0280 = qcar(v0280);
    v0280 = (is_number(v0280) ? lisp_true : nil);
    goto v0095;
/* error exit handlers */
v0181:
    popv(1);
    return nil;
}



/* Code for resume */

static Lisp_Object CC_resume(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0271, v0277, v0249, v0111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resume");
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
    v0271 = v0001;
    v0277 = v0000;
/* end of prologue */
    v0249 = v0271;
    if (v0249 == nil) goto v0071;
    v0249 = v0271;
    v0249 = qcar(v0249);
    v0111 = qcar(v0249);
    v0249 = v0271;
    v0249 = qcar(v0249);
    v0249 = qcdr(v0249);
    v0249 = qcar(v0249);
    v0271 = qcdr(v0271);
    {
        popv(1);
        fn = elt(env, 3); /* amatch */
        return (*qfnn(fn))(qenv(fn), 4, v0111, v0249, v0277, v0271);
    }

v0071:
    v0271 = v0277;
    fn = elt(env, 4); /* chk */
    v0277 = (*qfn1(fn))(qenv(fn), v0271);
    nil = C_nil;
    if (exception_pending()) goto v0250;
    env = stack[0];
    v0271 = qvalue(elt(env, 1)); /* t */
    if (v0277 == v0271) goto v0340;
    v0271 = nil;
    { popv(1); return onevalue(v0271); }

v0340:
    v0271 = qvalue(elt(env, 2)); /* substitution */
    {
        popv(1);
        fn = elt(env, 5); /* bsubs */
        return (*qfn1(fn))(qenv(fn), v0271);
    }
/* error exit handlers */
v0250:
    popv(1);
    return nil;
}



/* Code for groebsavelterm */

static Lisp_Object CC_groebsavelterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0340, v0288;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebsavelterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0288 = v0000;
/* end of prologue */
    v0340 = qvalue(elt(env, 1)); /* !*groelterms */
    if (v0340 == nil) goto v0067;
    v0340 = v0288;
    if (v0340 == nil) goto v0257;
    v0340 = v0288;
    v0340 = qcdr(v0340);
    v0340 = qcdr(v0340);
    v0340 = qcdr(v0340);
    v0340 = qcar(v0340);
    v0340 = (v0340 == nil ? lisp_true : nil);
    goto v0303;

v0303:
    if (!(v0340 == nil)) goto v0067;
    v0340 = v0288;
    v0340 = qcdr(v0340);
    v0340 = qcdr(v0340);
    v0340 = qcar(v0340);
    {
        fn = elt(env, 3); /* groebsaveltermbc */
        return (*qfn1(fn))(qenv(fn), v0340);
    }

v0067:
    v0340 = nil;
    return onevalue(v0340);

v0257:
    v0340 = qvalue(elt(env, 2)); /* t */
    goto v0303;
}



/* Code for gbfdot */

static Lisp_Object CC_gbfdot(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0288, v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gbfdot");
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
    v0288 = stack[-1];
    v0071 = qcar(v0288);
    v0288 = stack[0];
    v0288 = qcar(v0288);
    fn = elt(env, 1); /* csl_timbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0071, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-3];
    v0288 = stack[-1];
    v0071 = qcdr(v0288);
    v0288 = stack[0];
    v0288 = qcdr(v0288);
    fn = elt(env, 1); /* csl_timbf */
    v0288 = (*qfn2(fn))(qenv(fn), v0071, v0288);
    nil = C_nil;
    if (exception_pending()) goto v0278;
    env = stack[-3];
    {
        Lisp_Object v0247 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* plubf */
        return (*qfn2(fn))(qenv(fn), v0247, v0288);
    }
/* error exit handlers */
v0278:
    popv(4);
    return nil;
}



/* Code for physopordchk */

static Lisp_Object CC_physopordchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0263, v0262, v0268;
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
    v0263 = v0000;
/* end of prologue */
    fn = elt(env, 4); /* !*collectphysops */
    v0263 = (*qfn1(fn))(qenv(fn), v0263);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v0263 = (*qfn1(fn))(qenv(fn), v0263);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    stack[-1] = v0263;
    v0263 = stack[0];
    fn = elt(env, 4); /* !*collectphysops */
    v0263 = (*qfn1(fn))(qenv(fn), v0263);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    fn = elt(env, 5); /* deletemult!* */
    v0263 = (*qfn1(fn))(qenv(fn), v0263);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-2];
    v0268 = v0263;
    v0263 = stack[-1];
    if (v0263 == nil) goto v0254;
    v0263 = v0268;
    if (v0263 == nil) goto v0192;
    v0262 = elt(env, 3); /* unit */
    v0263 = stack[-1];
    v0263 = Lmember(nil, v0262, v0263);
    if (!(v0263 == nil)) goto v0060;
    v0262 = elt(env, 3); /* unit */
    v0263 = v0268;
    v0263 = Lmember(nil, v0262, v0263);
    if (!(v0263 == nil)) goto v0060;
    v0263 = stack[-1];
    v0262 = v0268;
    {
        popv(3);
        fn = elt(env, 6); /* physopordchk!* */
        return (*qfn2(fn))(qenv(fn), v0263, v0262);
    }

v0060:
    v0263 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0263); }

v0192:
    v0263 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0263); }

v0254:
    v0263 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0263); }
/* error exit handlers */
v0191:
    popv(3);
    return nil;
}



/* Code for def_edge */

static Lisp_Object CC_def_edge(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0069, v0278, v0247;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for def_edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0247 = v0001;
    v0070 = v0000;
/* end of prologue */
    v0070 = qcdr(v0070);
    v0070 = qcar(v0070);
    v0278 = v0070;
    v0070 = v0278;
    v0069 = qcar(v0070);
    v0070 = v0247;
    v0070 = Lassoc(nil, v0069, v0070);
    if (v0070 == nil) goto v0068;
    v0070 = v0278;
    v0070 = qcdr(v0070);
    v0069 = v0247;
    v0070 = Lassoc(nil, v0070, v0069);
    return onevalue(v0070);

v0068:
    v0070 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0070);
}



/* Code for comblog */

static Lisp_Object CC_comblog(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0306, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for comblog");
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
    goto v0067;

v0067:
    v0306 = stack[0];
    if (!consp(v0306)) goto v0101;
    v0306 = stack[0];
    v0018 = qcar(v0306);
    v0306 = qvalue(elt(env, 2)); /* domainlist!* */
    v0306 = Lmemq(nil, v0018, v0306);
    goto v0257;

v0257:
    if (v0306 == nil) goto v0277;
    v0018 = stack[-1];
    v0306 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0018, v0306);
    }

v0277:
    v0306 = stack[0];
    v0018 = qcar(v0306);
    v0306 = elt(env, 3); /* plus */
    if (v0018 == v0306) goto v0099;
    v0306 = stack[0];
    v0018 = qcar(v0306);
    v0306 = elt(env, 4); /* times */
    if (v0018 == v0306) goto v0072;
    v0306 = qvalue(elt(env, 6)); /* nil */
    goto v0098;

v0098:
    if (v0306 == nil) goto v0223;
    v0306 = stack[0];
    fn = elt(env, 8); /* simp!* */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    fn = elt(env, 9); /* clogsq */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    fn = elt(env, 10); /* prepsq!* */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    {
        Lisp_Object v0350 = stack[-1];
        popv(3);
        fn = elt(env, 7); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0350, v0306);
    }

v0223:
    v0306 = stack[0];
    v0306 = qcar(v0306);
    v0018 = CC_comblog(env, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0306 = stack[-1];
    v0306 = cons(v0018, v0306);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    stack[-1] = v0306;
    v0306 = stack[0];
    v0306 = qcdr(v0306);
    stack[0] = v0306;
    goto v0067;

v0072:
    v0306 = stack[0];
    fn = elt(env, 8); /* simp!* */
    v0306 = (*qfn1(fn))(qenv(fn), v0306);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-2];
    v0306 = qcar(v0306);
    v0018 = v0306;
    v0306 = v0018;
    if (!consp(v0306)) goto v0295;
    v0306 = v0018;
    v0306 = qcar(v0306);
    v0306 = (consp(v0306) ? nil : lisp_true);
    goto v0246;

v0246:
    if (v0306 == nil) goto v0051;
    v0306 = qvalue(elt(env, 6)); /* nil */
    goto v0098;

v0051:
    v0306 = v0018;
    v0306 = qcar(v0306);
    v0306 = qcar(v0306);
    v0018 = qcar(v0306);
    v0306 = elt(env, 5); /* log */
    v0306 = Leqcar(nil, v0018, v0306);
    env = stack[-2];
    goto v0098;

v0295:
    v0306 = qvalue(elt(env, 1)); /* t */
    goto v0246;

v0099:
    v0306 = qvalue(elt(env, 1)); /* t */
    goto v0098;

v0101:
    v0306 = qvalue(elt(env, 1)); /* t */
    goto v0257;
/* error exit handlers */
v0084:
    popv(3);
    return nil;
}



/* Code for endstat */

static Lisp_Object MS_CDECL CC_endstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068;
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
    v0068 = qvalue(elt(env, 1)); /* cursym!* */
    stack[0] = v0068;
    v0068 = elt(env, 2); /* end */
    fn = elt(env, 3); /* comm1 */
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0257;
    v0068 = stack[0];
    popv(1);
    return ncons(v0068);
/* error exit handlers */
v0257:
    popv(1);
    return nil;
}



/* Code for prepd1 */

static Lisp_Object CC_prepd1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0061, v0340;
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
    v0340 = v0000;
/* end of prologue */
    v0060 = v0340;
    if (!consp(v0060)) return onevalue(v0340);
    v0060 = v0340;
    v0061 = qcar(v0060);
    v0060 = elt(env, 1); /* prepfn */
    v0060 = get(v0061, v0060);
    v0061 = v0340;
        return Lapply1(nil, v0060, v0061);
}



/* Code for red_totalred */

static Lisp_Object CC_red_totalred(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0254, v0266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for red_totalred");
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
    v0254 = v0001;
    v0266 = v0000;
/* end of prologue */
    stack[0] = v0266;
    fn = elt(env, 1); /* red_topred */
    v0254 = (*qfn2(fn))(qenv(fn), v0266, v0254);
    nil = C_nil;
    if (exception_pending()) goto v0294;
    env = stack[-1];
    {
        Lisp_Object v0192 = stack[0];
        popv(2);
        fn = elt(env, 2); /* red_tailred */
        return (*qfn2(fn))(qenv(fn), v0192, v0254);
    }
/* error exit handlers */
v0294:
    popv(2);
    return nil;
}



/* Code for tensorp */

static Lisp_Object CC_tensorp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0266, v0267;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tensorp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0267 = v0000;
/* end of prologue */
    v0266 = v0267;
    if (!consp(v0266)) goto v0062;
    v0266 = v0267;
    v0266 = qcar(v0266);
    v0267 = elt(env, 1); /* tensor */
        return Lflagp(nil, v0266, v0267);

v0062:
    v0266 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0266);
}



/* Code for ilog2 */

static Lisp_Object CC_ilog2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ilog2");
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
    v0083 = stack[-2];
    v0010 = (Lisp_Object)1; /* 0 */
    v0010 = (Lisp_Object)lesseq2(v0083, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    v0010 = v0010 ? lisp_true : nil;
    env = stack[-4];
    if (v0010 == nil) goto v0095;
    v0083 = stack[-2];
    v0010 = elt(env, 0); /* ilog2 */
    fn = elt(env, 2); /* terrlst */
    v0010 = (*qfn2(fn))(qenv(fn), v0083, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    goto v0095;

v0095:
    v0010 = (Lisp_Object)33; /* 2 */
    stack[0] = v0010;
    v0010 = stack[0];
    v0010 = ncons(v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-1] = v0010;
    goto v0098;

v0098:
    v0083 = stack[-2];
    v0010 = stack[0];
    v0010 = (Lisp_Object)greaterp2(v0083, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    v0010 = v0010 ? lisp_true : nil;
    env = stack[-4];
    if (v0010 == nil) goto v0059;
    v0083 = stack[0];
    v0010 = stack[-1];
    v0010 = cons(v0083, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-1] = v0010;
    v0083 = stack[0];
    v0010 = stack[0];
    v0010 = times2(v0083, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[0] = v0010;
    goto v0098;

v0059:
    v0010 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0010;
    goto v0093;

v0093:
    v0010 = stack[-1];
    v0083 = qcar(v0010);
    stack[0] = v0083;
    v0010 = (Lisp_Object)33; /* 2 */
    if (v0083 == v0010) goto v0048;
    v0010 = stack[-1];
    v0010 = qcdr(v0010);
    stack[-1] = v0010;
    v0083 = stack[-2];
    v0010 = stack[0];
    v0010 = (Lisp_Object)geq2(v0083, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    v0010 = v0010 ? lisp_true : nil;
    env = stack[-4];
    if (v0010 == nil) goto v0351;
    v0083 = stack[-2];
    v0010 = stack[0];
    v0010 = quot2(v0083, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-2] = v0010;
    v0010 = stack[-3];
    v0010 = add1(v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-3] = v0010;
    goto v0351;

v0351:
    v0083 = stack[-3];
    v0010 = (Lisp_Object)33; /* 2 */
    v0010 = times2(v0083, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    env = stack[-4];
    stack[-3] = v0010;
    goto v0093;

v0048:
    v0083 = stack[-2];
    v0010 = (Lisp_Object)33; /* 2 */
    v0010 = (Lisp_Object)geq2(v0083, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    v0010 = v0010 ? lisp_true : nil;
    env = stack[-4];
    if (v0010 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0010 = stack[-3];
    v0010 = add1(v0010);
    nil = C_nil;
    if (exception_pending()) goto v0260;
    stack[-3] = v0010;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v0260:
    popv(5);
    return nil;
}



/* Code for nonlnrsys */

static Lisp_Object CC_nonlnrsys(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nonlnrsys");
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

v0105:
    v0070 = stack[-1];
    if (v0070 == nil) goto v0067;
    v0070 = stack[-1];
    v0069 = qcar(v0070);
    v0070 = stack[0];
    fn = elt(env, 2); /* nonlnr */
    v0070 = (*qfn2(fn))(qenv(fn), v0069, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0248;
    env = stack[-2];
    if (!(v0070 == nil)) { popv(3); return onevalue(v0070); }
    v0070 = stack[-1];
    v0069 = qcdr(v0070);
    v0070 = stack[0];
    stack[-1] = v0069;
    stack[0] = v0070;
    goto v0105;

v0067:
    v0070 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0070); }
/* error exit handlers */
v0248:
    popv(3);
    return nil;
}



/* Code for dmconv0 */

static Lisp_Object CC_dmconv0(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0294, v0192, v0197;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dmconv0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0197 = v0000;
/* end of prologue */
    v0294 = v0197;
    if (v0294 == nil) goto v0233;
    v0192 = v0197;
    v0294 = elt(env, 2); /* !:gi!: */
    if (v0192 == v0294) goto v0095;
    v0294 = v0197;
    goto v0226;

v0226:
    qvalue(elt(env, 4)) = v0294; /* dmd!* */
    return onevalue(v0294);

v0095:
    v0294 = elt(env, 3); /* !:crn!: */
    goto v0226;

v0233:
    v0294 = elt(env, 1); /* !:rn!: */
    goto v0226;
}



/* Code for refprint */

static Lisp_Object CC_refprint(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0284, v0186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for refprint");
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
    v0284 = qvalue(elt(env, 1)); /* cloc!* */
    if (v0284 == nil) goto v0107;
    v0284 = qvalue(elt(env, 1)); /* cloc!* */
    v0284 = qcar(v0284);
    goto v0290;

v0290:
    stack[-4] = v0284;
    v0186 = stack[-4];
    v0284 = qvalue(elt(env, 3)); /* pfiles!* */
    v0284 = Lassoc(nil, v0186, v0284);
    qvalue(elt(env, 4)) = v0284; /* curfun!* */
    if (v0284 == nil) goto v0247;
    v0284 = qvalue(elt(env, 4)); /* curfun!* */
    v0284 = qcar(v0284);
    stack[-4] = v0284;
    v0284 = qvalue(elt(env, 4)); /* curfun!* */
    v0284 = qcdr(v0284);
    qvalue(elt(env, 4)) = v0284; /* curfun!* */
    goto v0063;

v0063:
    v0284 = qvalue(elt(env, 1)); /* cloc!* */
    if (v0284 == nil) goto v0092;
    v0284 = qvalue(elt(env, 1)); /* cloc!* */
    v0284 = qcdr(v0284);
    if (v0284 == nil) goto v0092;
    v0186 = stack[-4];
    v0284 = qvalue(elt(env, 1)); /* cloc!* */
    v0284 = qcdr(v0284);
    v0284 = cons(v0186, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-5];
    goto v0190;

v0190:
    qvalue(elt(env, 8)) = v0284; /* curlin!* */
    v0284 = qvalue(elt(env, 7)); /* nil */
    qvalue(elt(env, 9)) = v0284; /* locls!* */
    qvalue(elt(env, 10)) = v0284; /* globs!* */
    qvalue(elt(env, 11)) = v0284; /* calls!* */
    v0284 = stack[-3];
    fn = elt(env, 12); /* anform */
    v0284 = (*qfn1(fn))(qenv(fn), v0284);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-5];
    v0284 = qvalue(elt(env, 4)); /* curfun!* */
    fn = elt(env, 13); /* outrefend */
    v0284 = (*qfn1(fn))(qenv(fn), v0284);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    v0284 = nil;
    { popv(6); return onevalue(v0284); }

v0092:
    v0284 = qvalue(elt(env, 7)); /* nil */
    goto v0190;

v0247:
    stack[0] = stack[-4];
    v0284 = elt(env, 5); /* g */
    v0186 = Lgensym1(nil, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-5];
    qvalue(elt(env, 4)) = v0186; /* curfun!* */
    v0284 = qvalue(elt(env, 3)); /* pfiles!* */
    v0284 = acons(stack[0], v0186, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-5];
    qvalue(elt(env, 3)) = v0284; /* pfiles!* */
    v0284 = stack[-4];
    v0284 = Lexplode(nil, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-5];
    v0284 = qcdr(v0284);
    v0284 = Lnreverse(nil, v0284);
    env = stack[-5];
    v0284 = qcdr(v0284);
    v0284 = Lnreverse(nil, v0284);
    env = stack[-5];
    stack[-2] = v0284;
    stack[-1] = qvalue(elt(env, 4)); /* curfun!* */
    stack[0] = elt(env, 6); /* rccnam */
    v0284 = stack[-2];
    v0186 = Llength(nil, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-5];
    v0284 = stack[-2];
    v0284 = cons(v0186, v0284);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-5];
    v0284 = Lputprop(nil, 3, stack[-1], stack[0], v0284);
    nil = C_nil;
    if (exception_pending()) goto v0274;
    env = stack[-5];
    goto v0063;

v0107:
    v0284 = elt(env, 2); /* "*TTYINPUT*" */
    goto v0290;
/* error exit handlers */
v0274:
    popv(6);
    return nil;
}



/* Code for mkpartitions1 */

static Lisp_Object MS_CDECL CC_mkpartitions1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0084, v0350, v0307;
    Lisp_Object v0067, v0233, v0226, v0100, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "mkpartitions1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0100 = va_arg(aa, Lisp_Object);
    v0226 = va_arg(aa, Lisp_Object);
    v0233 = va_arg(aa, Lisp_Object);
    v0067 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkpartitions1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0067,v0233,v0226,v0100,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0100,v0226,v0233,v0067);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0067;
    stack[-4] = v0233;
    stack[-5] = v0226;
    stack[-6] = v0100;
    stack[-7] = v0001;
    stack[-8] = v0000;
/* end of prologue */

v0254:
    v0084 = stack[-7];
    v0083 = (Lisp_Object)17; /* 1 */
    if (v0084 == v0083) goto v0071;
    v0084 = stack[-6];
    v0083 = stack[-5];
    v0083 = (Lisp_Object)greaterp2(v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    v0083 = v0083 ? lisp_true : nil;
    env = stack[-10];
    if (!(v0083 == nil)) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v0084 = stack[-8];
    v0083 = stack[-6];
    v0083 = difference2(v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-10];
    stack[-9] = v0083;
    v0083 = stack[-7];
    v0083 = sub1(v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-10];
    stack[-2] = v0083;
    v0084 = stack[-8];
    v0083 = stack[-6];
    stack[0] = difference2(v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-10];
    v0083 = stack[-7];
    v0083 = sub1(v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-10];
    v0083 = quot2(stack[0], v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-10];
    stack[-1] = v0083;
    v0084 = stack[-6];
    v0083 = stack[-4];
    v0083 = cons(v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-10];
    stack[0] = v0083;
    v0083 = stack[-6];
    v0307 = add1(v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-10];
    v0350 = stack[-5];
    v0084 = stack[-4];
    v0083 = stack[-3];
    v0083 = CC_mkpartitions1(env, 6, stack[-8], stack[-7], v0307, v0350, v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-10];
    stack[-3] = v0083;
    v0083 = stack[0];
    stack[-4] = v0083;
    v0083 = stack[-1];
    stack[-5] = v0083;
    v0083 = stack[-2];
    stack[-7] = v0083;
    v0083 = stack[-9];
    stack[-8] = v0083;
    goto v0254;

v0071:
    v0084 = stack[-8];
    v0083 = stack[-6];
    v0083 = (Lisp_Object)geq2(v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    v0083 = v0083 ? lisp_true : nil;
    env = stack[-10];
    if (v0083 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    v0084 = stack[-8];
    v0083 = stack[-4];
    v0083 = cons(v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-10];
    v0084 = Lreverse(nil, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    v0083 = stack[-3];
    popv(11);
    return cons(v0084, v0083);
/* error exit handlers */
v0078:
    popv(11);
    return nil;
}



/* Code for cl_flip */

static Lisp_Object CC_cl_flip(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0348, v0349, v0284;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_flip");
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
    v0284 = v0000;
/* end of prologue */
    v0349 = v0284;
    v0348 = elt(env, 1); /* and */
    if (v0349 == v0348) goto v0233;
    v0349 = v0284;
    v0348 = elt(env, 2); /* or */
    if (v0349 == v0348) goto v0106;
    v0349 = v0284;
    v0348 = elt(env, 3); /* all */
    if (v0349 == v0348) goto v0279;
    v0349 = v0284;
    v0348 = elt(env, 4); /* ex */
    if (v0349 == v0348) goto v0278;
    v0349 = v0284;
    v0348 = elt(env, 5); /* ball */
    if (v0349 == v0348) goto v0250;
    v0349 = v0284;
    v0348 = elt(env, 6); /* bex */
    if (v0349 == v0348) goto v0072;
    v0349 = v0284;
    v0348 = elt(env, 7); /* true */
    if (v0349 == v0348) goto v0292;
    v0349 = v0284;
    v0348 = elt(env, 8); /* false */
    if (v0349 == v0348) goto v0295;
    v0348 = elt(env, 9); /* "cl_flip(): don't know" */
    v0349 = v0284;
    v0348 = list2(v0348, v0349);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 10); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0348);
    }

v0295:
    v0348 = elt(env, 7); /* true */
    { popv(1); return onevalue(v0348); }

v0292:
    v0348 = elt(env, 8); /* false */
    { popv(1); return onevalue(v0348); }

v0072:
    v0348 = elt(env, 5); /* ball */
    { popv(1); return onevalue(v0348); }

v0250:
    v0348 = elt(env, 6); /* bex */
    { popv(1); return onevalue(v0348); }

v0278:
    v0348 = elt(env, 3); /* all */
    { popv(1); return onevalue(v0348); }

v0279:
    v0348 = elt(env, 4); /* ex */
    { popv(1); return onevalue(v0348); }

v0106:
    v0348 = elt(env, 1); /* and */
    { popv(1); return onevalue(v0348); }

v0233:
    v0348 = elt(env, 2); /* or */
    { popv(1); return onevalue(v0348); }
/* error exit handlers */
v0186:
    popv(1);
    return nil;
}



/* Code for simpexpt11 */

static Lisp_Object MS_CDECL CC_simpexpt11(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0353, v0306, v0018;
    Lisp_Object fn;
    Lisp_Object v0100, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt11");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0100 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpexpt11");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0100,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0100;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    v0353 = qvalue(elt(env, 1)); /* !*precise_complex */
    if (v0353 == nil) goto v0303;
    v0018 = stack[-3];
    v0306 = stack[-2];
    v0353 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* simpexpt2 */
        return (*qfnn(fn))(qenv(fn), 3, v0018, v0306, v0353);
    }

v0303:
    v0353 = stack[-2];
    v0353 = qcdr(v0353);
    if (!consp(v0353)) goto v0059;
    v0353 = stack[-2];
    v0353 = qcdr(v0353);
    v0353 = qcar(v0353);
    v0353 = (consp(v0353) ? nil : lisp_true);
    goto v0071;

v0071:
    if (v0353 == nil) goto v0352;
    v0353 = qvalue(elt(env, 2)); /* t */
    goto v0060;

v0060:
    if (v0353 == nil) goto v0188;
    v0018 = stack[-3];
    v0306 = stack[-2];
    v0353 = stack[-1];
    {
        popv(6);
        fn = elt(env, 4); /* simpexpt2 */
        return (*qfnn(fn))(qenv(fn), 3, v0018, v0306, v0353);
    }

v0188:
    stack[0] = stack[-3];
    v0353 = stack[-4];
    v0306 = qcar(v0353);
    v0353 = (Lisp_Object)17; /* 1 */
    v0306 = cons(v0306, v0353);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-5];
    v0353 = stack[-1];
    fn = elt(env, 5); /* simpexpt1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, stack[0], v0306, v0353);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-5];
    v0353 = stack[-4];
    v0306 = qcdr(v0353);
    v0353 = stack[-2];
    v0353 = qcdr(v0353);
    v0306 = cons(v0306, v0353);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-5];
    v0353 = stack[-1];
    fn = elt(env, 5); /* simpexpt1 */
    v0353 = (*qfnn(fn))(qenv(fn), 3, stack[-3], v0306, v0353);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-5];
    {
        Lisp_Object v0260 = stack[0];
        popv(6);
        fn = elt(env, 6); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0260, v0353);
    }

v0352:
    v0353 = stack[-2];
    v0306 = qcar(v0353);
    v0353 = stack[-2];
    v0353 = qcdr(v0353);
    fn = elt(env, 7); /* qremf */
    v0353 = (*qfn2(fn))(qenv(fn), v0306, v0353);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-5];
    stack[-4] = v0353;
    v0353 = qcar(v0353);
    if (v0353 == nil) goto v0265;
    v0353 = stack[-4];
    v0353 = qcdr(v0353);
    goto v0289;

v0289:
    v0353 = (v0353 == nil ? lisp_true : nil);
    goto v0060;

v0265:
    v0353 = qvalue(elt(env, 3)); /* nil */
    goto v0289;

v0059:
    v0353 = qvalue(elt(env, 2)); /* t */
    goto v0071;
/* error exit handlers */
v0241:
    popv(6);
    return nil;
}



/* Code for expnd */

static Lisp_Object CC_expnd(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0282, v0098, v0099;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expnd");
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
    v0282 = qvalue(elt(env, 1)); /* !*really_off_exp */
    if (!(v0282 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v0282 = stack[0];
    fn = elt(env, 3); /* expnd1 */
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-2];
    stack[0] = v0282;
    v0282 = qvalue(elt(env, 2)); /* !*sub2 */
    if (v0282 == nil) goto v0278;
    v0282 = stack[0];
    fn = elt(env, 4); /* subs2f */
    v0282 = (*qfn1(fn))(qenv(fn), v0282);
    nil = C_nil;
    if (exception_pending()) goto v0249;
    env = stack[-2];
    v0099 = v0282;
    v0098 = qcdr(v0282);
    v0282 = (Lisp_Object)17; /* 1 */
    if (!(v0098 == v0282)) goto v0278;
    v0282 = v0099;
    v0282 = qcar(v0282);
    goto v0107;

v0107:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    { popv(3); return onevalue(v0282); }

v0278:
    v0282 = stack[0];
    goto v0107;
/* error exit handlers */
v0249:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    popv(3);
    return nil;
}



/* Code for cl_susiinter */

static Lisp_Object MS_CDECL CC_cl_susiinter(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0109, v0274, v0351, v0337;
    Lisp_Object fn;
    Lisp_Object v0100, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_susiinter");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0100 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susiinter");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0100,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0100);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0100;
    stack[-4] = v0001;
    v0109 = v0000;
/* end of prologue */
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = v0109;
    goto v0101;

v0101:
    v0109 = stack[0];
    if (v0109 == nil) goto v0299;
    v0109 = stack[0];
    v0109 = qcar(v0109);
    v0351 = v0109;
    v0109 = v0351;
    v0274 = qcar(v0109);
    v0109 = elt(env, 2); /* delete */
    if (v0274 == v0109) goto v0288;
    v0109 = v0351;
    v0274 = qcar(v0109);
    v0109 = elt(env, 4); /* ignore */
    v0109 = (v0274 == v0109 ? lisp_true : nil);
    goto v0340;

v0340:
    if (v0109 == nil) goto v0093;
    v0109 = v0351;
    v0109 = qcdr(v0109);
    if (v0109 == nil) goto v0089;
    v0109 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v0109;
    goto v0279;

v0279:
    v0109 = stack[0];
    v0109 = qcdr(v0109);
    stack[0] = v0109;
    goto v0101;

v0089:
    v0274 = stack[-3];
    v0109 = stack[-4];
    fn = elt(env, 6); /* delqip */
    v0109 = (*qfn2(fn))(qenv(fn), v0274, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-6];
    stack[-4] = v0109;
    goto v0279;

v0093:
    v0109 = v0351;
    v0274 = qcar(v0109);
    v0109 = elt(env, 5); /* add */
    if (!(v0274 == v0109)) goto v0279;
    v0109 = v0351;
    v0274 = qcdr(v0109);
    v0109 = stack[-5];
    v0109 = cons(v0274, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-6];
    stack[-5] = v0109;
    goto v0279;

v0288:
    v0109 = qvalue(elt(env, 3)); /* t */
    goto v0340;

v0299:
    v0337 = stack[-4];
    v0351 = stack[-5];
    v0274 = stack[-2];
    v0109 = stack[-1];
    popv(7);
    return list4(v0337, v0351, v0274, v0109);
/* error exit handlers */
v0273:
    popv(7);
    return nil;
}



/* Code for binaryrd */

static Lisp_Object MS_CDECL CC_binaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0266, v0267, v0294;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "binaryrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for binaryrd");
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
    fn = elt(env, 2); /* mathml */
    v0266 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-2];
    stack[-1] = v0266;
    fn = elt(env, 2); /* mathml */
    v0266 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-2];
    stack[0] = v0266;
    fn = elt(env, 3); /* lex */
    v0266 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0279;
    env = stack[-2];
    v0267 = stack[-1];
    v0266 = stack[0];
    v0294 = qvalue(elt(env, 1)); /* nil */
    popv(3);
    return list2star(v0267, v0266, v0294);
/* error exit handlers */
v0279:
    popv(3);
    return nil;
}



/* Code for atomlis */

static Lisp_Object CC_atomlis(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0192, v0197;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for atomlis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0192 = v0000;
/* end of prologue */

v0105:
    v0197 = v0192;
    if (v0197 == nil) goto v0233;
    v0197 = v0192;
    v0197 = qcar(v0197);
    if (!consp(v0197)) goto v0101;
    v0192 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0192);

v0101:
    v0192 = qcdr(v0192);
    goto v0105;

v0233:
    v0192 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0192);
}



setup_type const u22_setup[] =
{
    {"quotof",                  too_few_2,      CC_quotof,     wrong_no_2},
    {"xremainder-mod-p",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_xremainderKmodKp},
    {"yylex",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_yylex},
    {"mksq",                    too_few_2,      CC_mksq,       wrong_no_2},
    {"ofsf_optsubstat",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_optsubstat},
    {"binomial-coefft-mod-p",   too_few_2,      CC_binomialKcoefftKmodKp,wrong_no_2},
    {"bvarml",                  CC_bvarml,      too_many_1,    wrong_no_1},
    {"rationalizesq",           CC_rationalizesq,too_many_1,   wrong_no_1},
    {"vdpequal",                too_few_2,      CC_vdpequal,   wrong_no_2},
    {"xdegreecheck",            CC_xdegreecheck,too_many_1,    wrong_no_1},
    {"prinlatom",               CC_prinlatom,   too_many_1,    wrong_no_1},
    {"rd:times",                too_few_2,      CC_rdTtimes,   wrong_no_2},
    {"red_tailred",             too_few_2,      CC_red_tailred,wrong_no_2},
    {"decprec2internal",        CC_decprec2internal,too_many_1,wrong_no_1},
    {"cl_atml1",                CC_cl_atml1,    too_many_1,    wrong_no_1},
    {"ofsf_sippsubst",          too_few_2,      CC_ofsf_sippsubst,wrong_no_2},
    {"cgp_ci",                  CC_cgp_ci,      too_many_1,    wrong_no_1},
    {"downwght1",               too_few_2,      CC_downwght1,  wrong_no_2},
    {"dip-nc-ev-prod1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipKncKevKprod1},
    {"bas_newnumber",           too_few_2,      CC_bas_newnumber,wrong_no_2},
    {"simp-prop-order",         too_few_2,      CC_simpKpropKorder,wrong_no_2},
    {"resimpf",                 CC_resimpf,     too_many_1,    wrong_no_1},
    {"gf2cr:",                  CC_gf2crT,      too_many_1,    wrong_no_1},
    {"s:prinl2",                too_few_2,      CC_sTprinl2,   wrong_no_2},
    {"formrlis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formrlis},
    {"qqe_arg-check-q",         CC_qqe_argKcheckKq,too_many_1, wrong_no_1},
    {"bc_prod",                 too_few_2,      CC_bc_prod,    wrong_no_2},
    {"resume",                  too_few_2,      CC_resume,     wrong_no_2},
    {"groebsavelterm",          CC_groebsavelterm,too_many_1,  wrong_no_1},
    {"gbfdot",                  too_few_2,      CC_gbfdot,     wrong_no_2},
    {"physopordchk",            too_few_2,      CC_physopordchk,wrong_no_2},
    {"def_edge",                too_few_2,      CC_def_edge,   wrong_no_2},
    {"comblog",                 CC_comblog,     too_many_1,    wrong_no_1},
    {"endstat",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_endstat},
    {"prepd1",                  CC_prepd1,      too_many_1,    wrong_no_1},
    {"red_totalred",            too_few_2,      CC_red_totalred,wrong_no_2},
    {"tensorp",                 CC_tensorp,     too_many_1,    wrong_no_1},
    {"ilog2",                   CC_ilog2,       too_many_1,    wrong_no_1},
    {"nonlnrsys",               too_few_2,      CC_nonlnrsys,  wrong_no_2},
    {"dmconv0",                 CC_dmconv0,     too_many_1,    wrong_no_1},
    {"refprint",                CC_refprint,    too_many_1,    wrong_no_1},
    {"mkpartitions1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkpartitions1},
    {"cl_flip",                 CC_cl_flip,     too_many_1,    wrong_no_1},
    {"simpexpt11",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt11},
    {"expnd",                   CC_expnd,       too_many_1,    wrong_no_1},
    {"cl_susiinter",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_susiinter},
    {"binaryrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_binaryrd},
    {"atomlis",                 CC_atomlis,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u22", (two_args *)"18099 7636518 626161", 0}
};

/* end of generated code */
