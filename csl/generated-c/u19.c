
/* $destdir\u19.c        Machine generated C code */

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


/* Code for evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_evaluateKmodKp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0026, v0027, v0028, v0029;
    Lisp_Object fn;
    Lisp_Object v0010, v0011, v0005;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate-mod-p");
    va_start(aa, nargs);
    v0005 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0005,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0010;
    stack[-1] = v0011;
    stack[-2] = v0005;
/* end of prologue */

v0030:
    v0025 = stack[-2];
    if (!consp(v0025)) goto v0031;
    v0025 = stack[-2];
    v0025 = qcar(v0025);
    v0025 = (consp(v0025) ? nil : lisp_true);
    goto v0032;

v0032:
    if (!(v0025 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0026 = stack[0];
    v0025 = (Lisp_Object)1; /* 0 */
    if (v0026 == v0025) goto v0033;
    v0025 = stack[-1];
    if (v0025 == nil) goto v0034;
    v0025 = stack[-2];
    v0025 = qcar(v0025);
    v0025 = qcar(v0025);
    v0026 = qcar(v0025);
    v0025 = stack[-1];
    if (equal(v0026, v0025)) goto v0035;
    v0025 = stack[-2];
    v0025 = qcar(v0025);
    v0027 = qcdr(v0025);
    v0026 = stack[-1];
    v0025 = stack[0];
    stack[-3] = CC_evaluateKmodKp(env, 3, v0027, v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    env = stack[-4];
    v0025 = stack[-2];
    v0027 = qcdr(v0025);
    v0026 = stack[-1];
    v0025 = stack[0];
    v0025 = CC_evaluateKmodKp(env, 3, v0027, v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0036;
    v0026 = stack[-3];
    v0027 = v0026;
    if (v0027 == nil) { popv(5); return onevalue(v0025); }
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0027 = qcar(v0027);
    popv(5);
    return acons(v0027, v0026, v0025);

v0035:
    v0025 = stack[-2];
    v0025 = qcar(v0025);
    v0029 = qcdr(v0025);
    v0025 = stack[-2];
    v0025 = qcar(v0025);
    v0025 = qcar(v0025);
    v0028 = qcdr(v0025);
    v0025 = stack[-2];
    v0027 = qcdr(v0025);
    v0026 = stack[0];
    v0025 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v0029, v0028, v0027, v0026, v0025);
    }

v0034:
    v0025 = elt(env, 3); /* "Variable=NIL in EVALUATE-MOD-P" */
    {
        popv(5);
        fn = elt(env, 5); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0025);
    }

v0033:
    v0025 = qvalue(elt(env, 2)); /* nil */
    stack[0] = v0025;
    goto v0030;

v0031:
    v0025 = qvalue(elt(env, 1)); /* t */
    goto v0032;
/* error exit handlers */
v0036:
    popv(5);
    return nil;
}



/* Code for crprcd2 */

static Lisp_Object CC_crprcd2(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for crprcd2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0005;
/* end of prologue */
    v0037 = stack[-1];
    fn = elt(env, 2); /* crprcd */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    stack[-1] = v0037;
    v0037 = stack[0];
    fn = elt(env, 2); /* crprcd */
    v0037 = (*qfn1(fn))(qenv(fn), v0037);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    qvalue(elt(env, 1)) = v0037; /* yy!! */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v0024:
    popv(3);
    return nil;
}



/* Code for lalr_display_symbols */

static Lisp_Object MS_CDECL CC_lalr_display_symbols(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lalr_display_symbols");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_display_symbols");
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
    push(nil);
/* end of prologue */
    v0048 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = (Lisp_Object)zerop(v0048);
    v0048 = v0048 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0048 == nil)) goto v0051;
    v0048 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    goto v0051;

v0051:
    v0048 = elt(env, 1); /* "Terminal symbols are:" */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = qvalue(elt(env, 2)); /* terminals */
    stack[-1] = v0048;
    goto v0052;

v0052:
    v0048 = stack[-1];
    if (v0048 == nil) goto v0053;
    v0048 = stack[-1];
    v0048 = qcar(v0048);
    stack[0] = v0048;
    v0048 = elt(env, 4); /* " " */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[0];
    v0048 = qcar(v0048);
    v0048 = Lprin(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = elt(env, 5); /* ":" */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[0];
    v0048 = qcdr(v0048);
    v0048 = Lprin(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[-1];
    v0048 = qcdr(v0048);
    stack[-1] = v0048;
    goto v0052;

v0053:
    v0048 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = elt(env, 6); /* "Non-terminal symbols are:" */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = qvalue(elt(env, 7)); /* non_terminals */
    stack[-5] = v0048;
    goto v0054;

v0054:
    v0048 = stack[-5];
    if (v0048 == nil) goto v0055;
    v0048 = stack[-5];
    v0048 = qcar(v0048);
    stack[0] = v0048;
    v0048 = elt(env, 8); /* "[" */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0049 = stack[0];
    v0048 = elt(env, 9); /* non_terminal_code */
    v0048 = get(v0049, v0048);
    env = stack[-6];
    v0048 = Lprin(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = elt(env, 10); /* "]" */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[0];
    fn = elt(env, 16); /* lalr_prin_symbol */
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = elt(env, 5); /* ":" */
    stack[-4] = v0048;
    v0049 = stack[0];
    v0048 = elt(env, 11); /* produces */
    v0048 = get(v0049, v0048);
    env = stack[-6];
    stack[-3] = v0048;
    goto v0056;

v0056:
    v0048 = stack[-3];
    if (v0048 == nil) goto v0057;
    v0048 = stack[-3];
    v0048 = qcar(v0048);
    stack[-2] = v0048;
    v0048 = (Lisp_Object)321; /* 20 */
    v0048 = Lttab(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[-4];
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = elt(env, 12); /* "|" */
    stack[-4] = v0048;
    v0048 = stack[-2];
    v0048 = qcar(v0048);
    stack[-1] = v0048;
    goto v0058;

v0058:
    v0048 = stack[-1];
    if (v0048 == nil) goto v0059;
    v0048 = stack[-1];
    v0048 = qcar(v0048);
    stack[0] = v0048;
    v0048 = elt(env, 4); /* " " */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[0];
    fn = elt(env, 16); /* lalr_prin_symbol */
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[-1];
    v0048 = qcdr(v0048);
    stack[-1] = v0048;
    goto v0058;

v0059:
    v0049 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = (Lisp_Object)769; /* 48 */
    v0048 = (Lisp_Object)greaterp2(v0049, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    v0048 = v0048 ? lisp_true : nil;
    env = stack[-6];
    if (v0048 == nil) goto v0026;
    v0048 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    goto v0026;

v0026:
    v0048 = (Lisp_Object)769; /* 48 */
    v0048 = Lttab(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = elt(env, 13); /* "{" */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[-2];
    v0048 = qcdr(v0048);
    stack[-1] = v0048;
    goto v0060;

v0060:
    v0048 = stack[-1];
    if (v0048 == nil) goto v0061;
    v0048 = stack[-1];
    v0048 = qcar(v0048);
    stack[0] = v0048;
    v0048 = elt(env, 4); /* " " */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[0];
    v0048 = Lprin(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[-1];
    v0048 = qcdr(v0048);
    stack[-1] = v0048;
    goto v0060;

v0061:
    v0048 = elt(env, 14); /* " }" */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[-3];
    v0048 = qcdr(v0048);
    stack[-3] = v0048;
    goto v0056;

v0057:
    v0048 = (Lisp_Object)321; /* 20 */
    v0048 = Lttab(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = elt(env, 15); /* ";" */
    v0048 = Lprinc(nil, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-6];
    v0048 = stack[-5];
    v0048 = qcdr(v0048);
    stack[-5] = v0048;
    goto v0054;

v0055:
    v0048 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    v0048 = nil;
    { popv(7); return onevalue(v0048); }
/* error exit handlers */
v0050:
    popv(7);
    return nil;
}



/* Code for ofsf_ignshift */

static Lisp_Object MS_CDECL CC_ofsf_ignshift(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0068, v0069;
    Lisp_Object fn;
    Lisp_Object v0010, v0011, v0005;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_ignshift");
    va_start(aa, nargs);
    v0005 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_ignshift");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0005,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0010;
    stack[-1] = v0011;
    stack[-2] = v0005;
/* end of prologue */
    v0067 = stack[-2];
    v0067 = qcdr(v0067);
    v0068 = qcar(v0067);
    v0067 = stack[-1];
    fn = elt(env, 7); /* sfto_reorder */
    v0067 = (*qfn2(fn))(qenv(fn), v0068, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-3];
    v0069 = v0067;
    v0067 = v0069;
    if (!consp(v0067)) goto v0071;
    v0067 = v0069;
    v0067 = qcar(v0067);
    v0067 = (consp(v0067) ? nil : lisp_true);
    goto v0072;

v0072:
    if (v0067 == nil) goto v0033;
    v0067 = qvalue(elt(env, 2)); /* nil */
    goto v0073;

v0073:
    if (v0067 == nil) goto v0074;
    v0067 = qvalue(elt(env, 3)); /* !*rlpos */
    if (!(v0067 == nil)) goto v0075;
    v0067 = stack[0];
    if (!(v0067 == nil)) goto v0075;
    v0067 = stack[-2];
    v0068 = qcar(v0067);
    v0067 = elt(env, 4); /* (equal neq) */
    v0067 = Lmemq(nil, v0068, v0067);
    if (!(v0067 == nil)) goto v0075;
    v0067 = v0069;
    v0067 = qcar(v0067);
    v0067 = qcar(v0067);
    v0067 = qcdr(v0067);
    v0067 = Levenp(nil, v0067);
    env = stack[-3];
    if (!(v0067 == nil)) goto v0075;
    v0067 = elt(env, 6); /* odd */
    { popv(4); return onevalue(v0067); }

v0075:
    v0067 = elt(env, 5); /* ignore */
    { popv(4); return onevalue(v0067); }

v0074:
    v0067 = nil;
    { popv(4); return onevalue(v0067); }

v0033:
    v0067 = v0069;
    v0067 = qcdr(v0067);
    if (v0067 == nil) goto v0076;
    v0067 = qvalue(elt(env, 2)); /* nil */
    goto v0073;

v0076:
    v0067 = v0069;
    v0067 = qcar(v0067);
    v0067 = qcar(v0067);
    v0068 = qcar(v0067);
    v0067 = stack[-1];
    v0067 = (v0068 == v0067 ? lisp_true : nil);
    goto v0073;

v0071:
    v0067 = qvalue(elt(env, 1)); /* t */
    goto v0072;
/* error exit handlers */
v0070:
    popv(4);
    return nil;
}



/* Code for sq2sspl */

static Lisp_Object CC_sq2sspl(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0075, v0083;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sq2sspl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0005;
/* end of prologue */
    stack[-2] = nil;
    goto v0084;

v0084:
    v0075 = stack[-1];
    if (!consp(v0075)) goto v0052;
    v0075 = stack[-1];
    v0075 = qcar(v0075);
    v0075 = (consp(v0075) ? nil : lisp_true);
    goto v0053;

v0053:
    if (v0075 == nil) goto v0085;
    v0075 = stack[-1];
    v0083 = v0075;
    goto v0086;

v0086:
    v0075 = stack[-2];
    if (v0075 == nil) { popv(4); return onevalue(v0083); }
    v0075 = stack[-2];
    v0075 = qcar(v0075);
    v0075 = Lappend(nil, v0075, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-3];
    v0083 = v0075;
    v0075 = stack[-2];
    v0075 = qcdr(v0075);
    stack[-2] = v0075;
    goto v0086;

v0085:
    v0075 = stack[-1];
    v0083 = qcar(v0075);
    v0075 = stack[0];
    fn = elt(env, 2); /* sq2sstm */
    v0083 = (*qfn2(fn))(qenv(fn), v0083, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-3];
    v0075 = stack[-2];
    v0075 = cons(v0083, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[-3];
    stack[-2] = v0075;
    v0075 = stack[-1];
    v0075 = qcdr(v0075);
    stack[-1] = v0075;
    goto v0084;

v0052:
    v0075 = qvalue(elt(env, 1)); /* t */
    goto v0053;
/* error exit handlers */
v0087:
    popv(4);
    return nil;
}



/* Code for cl_qb */

static Lisp_Object CC_cl_qb(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0046, v0017, v0018, v0019;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_qb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
/* end of prologue */
    v0019 = nil;
    v0016 = (Lisp_Object)1; /* 0 */
    v0018 = v0016;
    goto v0090;

v0090:
    v0016 = stack[0];
    if (!consp(v0016)) goto v0091;
    v0016 = stack[0];
    v0016 = qcar(v0016);
    goto v0052;

v0052:
    stack[-1] = v0016;
    v0017 = v0016;
    v0046 = v0017;
    v0016 = elt(env, 1); /* ex */
    if (v0046 == v0016) goto v0092;
    v0046 = v0017;
    v0016 = elt(env, 3); /* all */
    v0016 = (v0046 == v0016 ? lisp_true : nil);
    goto v0071;

v0071:
    if (v0016 == nil) { popv(3); return onevalue(v0018); }
    v0046 = stack[-1];
    v0016 = v0019;
    if (equal(v0046, v0016)) goto v0065;
    v0016 = v0018;
    v0016 = add1(v0016);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-2];
    v0018 = v0016;
    v0016 = stack[-1];
    v0019 = v0016;
    goto v0065;

v0065:
    v0016 = stack[0];
    v0016 = qcdr(v0016);
    v0016 = qcdr(v0016);
    v0016 = qcar(v0016);
    stack[0] = v0016;
    goto v0090;

v0092:
    v0016 = qvalue(elt(env, 2)); /* t */
    goto v0071;

v0091:
    v0016 = stack[0];
    goto v0052;
/* error exit handlers */
v0009:
    popv(3);
    return nil;
}



/* Code for aex_simpleratp */

static Lisp_Object CC_aex_simpleratp(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_simpleratp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0022 = v0005;
/* end of prologue */
    fn = elt(env, 2); /* aex_ex */
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-1];
    stack[0] = v0022;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    if (is_number(v0022)) goto v0074;
    v0022 = qvalue(elt(env, 1)); /* nil */
    goto v0086;

v0086:
    if (!(v0022 == nil)) { popv(2); return onevalue(v0022); }
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0022 = (v0022 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0022); }

v0074:
    v0022 = stack[0];
    v0023 = qcar(v0022);
    v0022 = (Lisp_Object)1; /* 0 */
    v0022 = Leqn(nil, v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    v0022 = (v0022 == nil ? lisp_true : nil);
    goto v0086;
/* error exit handlers */
v0034:
    popv(2);
    return nil;
}



/* Code for mapins */

static Lisp_Object CC_mapins(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0095, v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mapins");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0005;
/* end of prologue */
    stack[-2] = nil;
    goto v0030;

v0030:
    v0079 = stack[0];
    if (v0079 == nil) goto v0086;
    v0095 = stack[-1];
    v0079 = stack[0];
    v0079 = qcar(v0079);
    v0079 = qcar(v0079);
    v0076 = cons(v0095, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    v0079 = stack[0];
    v0079 = qcar(v0079);
    v0095 = qcdr(v0079);
    v0079 = stack[-2];
    v0079 = acons(v0076, v0095, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-3];
    stack[-2] = v0079;
    v0079 = stack[0];
    v0079 = qcdr(v0079);
    stack[0] = v0079;
    goto v0030;

v0086:
    v0079 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0079);
    }
/* error exit handlers */
v0054:
    popv(4);
    return nil;
}



/* Code for exptpri */

static Lisp_Object CC_exptpri(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0152, v0153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptpri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v0151 = v0011;
    stack[-5] = v0005;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*list */
    qvalue(elt(env, 1)) = nil; /* !*list */
    stack[0] = nil;
    v0152 = qvalue(elt(env, 2)); /* !*nat */
    if (v0152 == nil) goto v0091;
    v0152 = qvalue(elt(env, 4)); /* !*fort */
    goto v0052;

v0052:
    if (v0152 == nil) goto v0072;
    v0151 = elt(env, 5); /* failed */
    goto v0090;

v0090:
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    { popv(8); return onevalue(v0151); }

v0072:
    v0152 = elt(env, 6); /* expt */
    if (!symbolp(v0152)) v0152 = nil;
    else { v0152 = qfastgets(v0152);
           if (v0152 != nil) { v0152 = elt(v0152, 23); /* infix */
#ifdef RECORD_GET
             if (v0152 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0152 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0152 == SPID_NOPROP) v0152 = nil; }}
#endif
    stack[-2] = v0152;
    v0151 = (Lisp_Object)greaterp2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    v0151 = v0151 ? lisp_true : nil;
    env = stack[-7];
    v0151 = (v0151 == nil ? lisp_true : nil);
    stack[-4] = v0151;
    v0151 = stack[-5];
    v0151 = qcdr(v0151);
    v0151 = qcar(v0151);
    stack[-1] = v0151;
    v0151 = stack[-5];
    v0151 = qcdr(v0151);
    v0151 = qcdr(v0151);
    v0151 = qcar(v0151);
    stack[-3] = v0151;
    v0151 = qvalue(elt(env, 7)); /* !*eraise */
    if (v0151 == nil) goto v0007;
    v0151 = stack[-1];
    if (!consp(v0151)) goto v0056;
    v0151 = stack[-1];
    v0151 = qcar(v0151);
    if (!symbolp(v0151)) v0151 = nil;
    else { v0151 = qfastgets(v0151);
           if (v0151 != nil) { v0151 = elt(v0151, 57); /* prifn */
#ifdef RECORD_GET
             if (v0151 != SPID_NOPROP)
                record_get(elt(fastget_names, 57), 1);
             else record_get(elt(fastget_names, 57), 0),
                v0151 = nil; }
           else record_get(elt(fastget_names, 57), 0); }
#else
             if (v0151 == SPID_NOPROP) v0151 = nil; }}
#endif
    stack[0] = v0151;
    if (v0151 == nil) goto v0045;
    v0152 = stack[0];
    v0151 = elt(env, 6); /* expt */
    v0152 = get(v0152, v0151);
    env = stack[-7];
    v0151 = elt(env, 9); /* inbrackets */
    v0151 = (v0152 == v0151 ? lisp_true : nil);
    goto v0065;

v0065:
    if (v0151 == nil) goto v0007;
    v0153 = stack[-1];
    v0152 = (Lisp_Object)1; /* 0 */
    v0151 = elt(env, 9); /* inbrackets */
    fn = elt(env, 19); /* layout!-formula */
    v0151 = (*qfnn(fn))(qenv(fn), 3, v0153, v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    stack[-1] = v0151;
    goto v0047;

v0047:
    v0151 = stack[-1];
    if (v0151 == nil) goto v0155;
    stack[-5] = qvalue(elt(env, 11)); /* !*ratpri */
    qvalue(elt(env, 11)) = nil; /* !*ratpri */
    v0152 = stack[-3];
    v0151 = elt(env, 12); /* quotient */
    if (!consp(v0152)) goto v0048;
    v0152 = qcar(v0152);
    if (!(v0152 == v0151)) goto v0048;
    v0151 = stack[-3];
    v0151 = qcdr(v0151);
    v0152 = qcar(v0151);
    v0151 = elt(env, 13); /* minus */
    v0151 = Leqcar(nil, v0152, v0151);
    env = stack[-7];
    goto v0156;

v0156:
    if (v0151 == nil) goto v0157;
    stack[0] = elt(env, 13); /* minus */
    v0151 = stack[-3];
    v0153 = qcar(v0151);
    v0151 = stack[-3];
    v0151 = qcdr(v0151);
    v0151 = qcar(v0151);
    v0151 = qcdr(v0151);
    v0152 = qcar(v0151);
    v0151 = stack[-3];
    v0151 = qcdr(v0151);
    v0151 = qcdr(v0151);
    v0151 = qcar(v0151);
    v0151 = list3(v0153, v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    v0151 = list2(stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    stack[-3] = v0151;
    goto v0159;

v0159:
    v0153 = stack[-3];
    v0151 = qvalue(elt(env, 7)); /* !*eraise */
    if (v0151 == nil) goto v0160;
    v0151 = (Lisp_Object)1; /* 0 */
    v0152 = v0151;
    goto v0161;

v0161:
    v0151 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 19); /* layout!-formula */
    v0151 = (*qfnn(fn))(qenv(fn), 3, v0153, v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    stack[-3] = v0151;
    qvalue(elt(env, 11)) = stack[-5]; /* !*ratpri */
    v0151 = stack[-3];
    if (v0151 == nil) goto v0162;
    v0151 = stack[-1];
    v0151 = qcar(v0151);
    v0152 = qcdr(v0151);
    v0151 = stack[-3];
    v0151 = qcar(v0151);
    v0151 = qcdr(v0151);
    v0151 = plus2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    stack[-5] = v0151;
    v0151 = stack[-4];
    if (v0151 == nil) goto v0163;
    v0152 = stack[-5];
    v0151 = (Lisp_Object)33; /* 2 */
    v0151 = plus2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    stack[-5] = v0151;
    goto v0163;

v0163:
    stack[0] = stack[-5];
    v0151 = qvalue(elt(env, 8)); /* nil */
    v0152 = Llinelength(nil, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = qvalue(elt(env, 14)); /* spare!* */
    v0152 = difference2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = qvalue(elt(env, 15)); /* orig!* */
    v0151 = difference2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = (Lisp_Object)greaterp2(stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    v0151 = v0151 ? lisp_true : nil;
    env = stack[-7];
    if (v0151 == nil) goto v0164;
    v0151 = elt(env, 5); /* failed */
    goto v0090;

v0164:
    stack[0] = stack[-5];
    v0151 = qvalue(elt(env, 8)); /* nil */
    v0152 = Llinelength(nil, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = qvalue(elt(env, 14)); /* spare!* */
    v0152 = difference2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = qvalue(elt(env, 16)); /* posn!* */
    v0151 = difference2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = (Lisp_Object)greaterp2(stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    v0151 = v0151 ? lisp_true : nil;
    env = stack[-7];
    if (v0151 == nil) goto v0165;
    v0151 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 20); /* terpri!* */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    goto v0165;

v0165:
    v0151 = stack[-4];
    if (v0151 == nil) goto v0166;
    v0151 = elt(env, 17); /* "(" */
    fn = elt(env, 21); /* prin2!* */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    goto v0166;

v0166:
    v0151 = stack[-1];
    fn = elt(env, 22); /* putpline */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = qvalue(elt(env, 7)); /* !*eraise */
    if (v0151 == nil) goto v0167;
    v0152 = (Lisp_Object)17; /* 1 */
    v0151 = stack[-3];
    v0151 = qcdr(v0151);
    v0151 = qcar(v0151);
    v0151 = difference2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    stack[-5] = v0151;
    goto v0168;

v0168:
    v0153 = (Lisp_Object)1; /* 0 */
    v0152 = stack[-5];
    v0151 = stack[-3];
    v0151 = qcar(v0151);
    v0151 = qcar(v0151);
    fn = elt(env, 23); /* update!-pline */
    stack[-2] = (*qfnn(fn))(qenv(fn), 3, v0153, v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = stack[-3];
    v0151 = qcar(v0151);
    stack[-1] = qcdr(v0151);
    v0151 = stack[-3];
    v0151 = qcdr(v0151);
    v0152 = qcar(v0151);
    v0151 = stack[-5];
    stack[0] = plus2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = stack[-3];
    v0151 = qcdr(v0151);
    v0152 = qcdr(v0151);
    v0151 = stack[-5];
    v0151 = plus2(v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = cons(stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = acons(stack[-2], stack[-1], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    fn = elt(env, 22); /* putpline */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = stack[-4];
    if (v0151 == nil) goto v0169;
    v0151 = elt(env, 18); /* ")" */
    fn = elt(env, 21); /* prin2!* */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    goto v0169;

v0169:
    v0151 = nil;
    goto v0090;

v0167:
    v0151 = elt(env, 6); /* expt */
    fn = elt(env, 24); /* oprin */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = (Lisp_Object)1; /* 0 */
    stack[-5] = v0151;
    goto v0168;

v0162:
    v0151 = elt(env, 5); /* failed */
    goto v0090;

v0160:
    v0151 = stack[-2];
    v0152 = v0151;
    goto v0161;

v0157:
    v0151 = stack[-3];
    fn = elt(env, 25); /* negnumberchk */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    stack[-3] = v0151;
    goto v0159;

v0048:
    v0151 = qvalue(elt(env, 8)); /* nil */
    goto v0156;

v0155:
    v0151 = elt(env, 5); /* failed */
    goto v0090;

v0007:
    v0152 = stack[0];
    v0151 = elt(env, 10); /* indexprin */
    if (v0152 == v0151) goto v0170;
    v0151 = qvalue(elt(env, 8)); /* nil */
    goto v0039;

v0039:
    if (v0151 == nil) goto v0171;
    v0151 = qvalue(elt(env, 8)); /* nil */
    goto v0090;

v0171:
    v0153 = stack[-1];
    v0152 = stack[-2];
    v0151 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 19); /* layout!-formula */
    v0151 = (*qfnn(fn))(qenv(fn), 3, v0153, v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    stack[-1] = v0151;
    goto v0047;

v0170:
    v0152 = stack[-1];
    v0151 = stack[-3];
    fn = elt(env, 26); /* indexpower */
    v0152 = (*qfn2(fn))(qenv(fn), v0152, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[-7];
    v0151 = elt(env, 5); /* failed */
    v0151 = (v0152 == v0151 ? lisp_true : nil);
    v0151 = (v0151 == nil ? lisp_true : nil);
    goto v0039;

v0045:
    v0151 = qvalue(elt(env, 8)); /* nil */
    goto v0065;

v0056:
    v0151 = qvalue(elt(env, 8)); /* nil */
    goto v0065;

v0091:
    v0152 = qvalue(elt(env, 3)); /* t */
    goto v0052;
/* error exit handlers */
v0158:
    env = stack[-7];
    qvalue(elt(env, 11)) = stack[-5]; /* !*ratpri */
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
v0154:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* !*list */
    popv(8);
    return nil;
}



/* Code for om2mml */

static Lisp_Object MS_CDECL CC_om2mml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "om2mml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for om2mml");
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
    fn = elt(env, 3); /* om2ir */
    v0091 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    stack[0] = v0091;
    v0091 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0091 = elt(env, 2); /* "Intermediate representation:" */
    v0091 = Lprinc(nil, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0091 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0091 = stack[0];
    v0091 = Lprinc(nil, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0091 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    env = stack[-1];
    v0091 = stack[0];
    fn = elt(env, 5); /* ir2mml */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0172;
    v0091 = nil;
    { popv(2); return onevalue(v0091); }
/* error exit handlers */
v0172:
    popv(2);
    return nil;
}



/* Code for newenv */

static Lisp_Object CC_newenv(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for newenv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0090 = v0005;
/* end of prologue */
    v0024 = v0090;
    v0090 = elt(env, 1); /* unbound */
    {
        fn = elt(env, 2); /* bind */
        return (*qfn2(fn))(qenv(fn), v0024, v0090);
    }
}



/* Code for evdif */

static Lisp_Object CC_evdif(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0173, v0174;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evdif");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0005;
/* end of prologue */
    v0174 = nil;
    goto v0037;

v0037:
    v0035 = stack[0];
    if (v0035 == nil) goto v0047;
    v0035 = stack[-1];
    if (!(v0035 == nil)) goto v0071;
    v0035 = elt(env, 2); /* (0) */
    stack[-1] = v0035;
    goto v0071;

v0071:
    v0035 = stack[-1];
    v0173 = qcar(v0035);
    v0035 = stack[0];
    v0035 = qcar(v0035);
    v0035 = (Lisp_Object)(int32_t)((int32_t)v0173 - (int32_t)v0035 + TAG_FIXNUM);
    v0173 = v0174;
    v0035 = cons(v0035, v0173);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    v0174 = v0035;
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    v0035 = stack[0];
    v0035 = qcdr(v0035);
    stack[0] = v0035;
    goto v0037;

v0047:
    v0035 = v0174;
    v0173 = Lnreverse(nil, v0035);
    v0035 = stack[-1];
        popv(3);
        return Lnconc(nil, v0173, v0035);
/* error exit handlers */
v0045:
    popv(3);
    return nil;
}



/* Code for !:dmpluslst */

static Lisp_Object CC_Tdmpluslst(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :dmpluslst");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0092 = v0005;
/* end of prologue */
    v0071 = v0092;
    if (v0071 == nil) goto v0051;
    v0071 = v0092;
    v0071 = qcdr(v0071);
    if (v0071 == nil) goto v0037;
    v0071 = v0092;
    stack[0] = qcar(v0071);
    v0071 = v0092;
    v0071 = qcdr(v0071);
    v0071 = CC_Tdmpluslst(env, v0071);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    {
        Lisp_Object v0023 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:plus */
        return (*qfn2(fn))(qenv(fn), v0023, v0071);
    }

v0037:
    v0071 = v0092;
    v0071 = qcar(v0071);
    { popv(2); return onevalue(v0071); }

v0051:
    v0071 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0071); }
/* error exit handlers */
v0022:
    popv(2);
    return nil;
}



/* Code for physop!-ordop */

static Lisp_Object CC_physopKordop(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0187, v0188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physop-ordop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0005;
/* end of prologue */

v0189:
    v0187 = stack[-1];
    fn = elt(env, 5); /* !*physopp */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    if (v0187 == nil) goto v0032;
    v0187 = stack[0];
    fn = elt(env, 5); /* !*physopp */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    if (v0187 == nil) goto v0032;
    v0187 = stack[-1];
    if (symbolp(v0187)) goto v0020;
    v0187 = stack[-1];
    v0188 = qcar(v0187);
    v0187 = elt(env, 3); /* physopname */
    v0187 = get(v0188, v0187);
    env = stack[-4];
    stack[-3] = v0187;
    v0188 = stack[-3];
    v0187 = stack[-1];
    v0187 = qcdr(v0187);
    v0187 = cons(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    stack[-3] = v0187;
    v0187 = stack[-1];
    v0187 = qcar(v0187);
    stack[-1] = v0187;
    goto v0191;

v0191:
    v0188 = stack[-1];
    v0187 = qvalue(elt(env, 4)); /* specoplist!* */
    v0187 = Lmember(nil, v0188, v0187);
    if (v0187 == nil) goto v0056;
    v0187 = qvalue(elt(env, 2)); /* t */
    { popv(5); return onevalue(v0187); }

v0056:
    v0187 = stack[0];
    if (symbolp(v0187)) goto v0008;
    v0187 = stack[0];
    v0188 = qcar(v0187);
    v0187 = elt(env, 3); /* physopname */
    v0187 = get(v0188, v0187);
    env = stack[-4];
    stack[-2] = v0187;
    v0188 = stack[-2];
    v0187 = stack[0];
    v0187 = qcdr(v0187);
    v0187 = cons(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    stack[-2] = v0187;
    v0187 = stack[0];
    v0187 = qcar(v0187);
    stack[0] = v0187;
    goto v0192;

v0192:
    v0188 = stack[0];
    v0187 = qvalue(elt(env, 4)); /* specoplist!* */
    v0187 = Lmember(nil, v0188, v0187);
    if (v0187 == nil) goto v0059;
    v0187 = qvalue(elt(env, 2)); /* t */
    { popv(5); return onevalue(v0187); }

v0059:
    v0187 = stack[-3];
    fn = elt(env, 6); /* opnum!* */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    stack[-1] = v0187;
    v0187 = stack[-2];
    fn = elt(env, 6); /* opnum!* */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    stack[0] = v0187;
    v0188 = stack[-1];
    v0187 = stack[0];
    v0187 = (Lisp_Object)lessp2(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    v0187 = v0187 ? lisp_true : nil;
    env = stack[-4];
    if (v0187 == nil) goto v0193;
    v0187 = qvalue(elt(env, 2)); /* t */
    { popv(5); return onevalue(v0187); }

v0193:
    v0188 = stack[-1];
    v0187 = stack[0];
    v0187 = (Lisp_Object)greaterp2(v0188, v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    v0187 = v0187 ? lisp_true : nil;
    env = stack[-4];
    if (v0187 == nil) goto v0194;
    v0187 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0187); }

v0194:
    v0187 = stack[-3];
    if (symbolp(v0187)) goto v0195;
    v0187 = stack[-2];
    if (symbolp(v0187)) goto v0137;
    v0187 = stack[-3];
    v0188 = qcdr(v0187);
    v0187 = stack[-2];
    v0187 = qcdr(v0187);
    stack[-1] = v0188;
    stack[0] = v0187;
    goto v0189;

v0137:
    v0187 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0187); }

v0195:
    v0187 = qvalue(elt(env, 2)); /* t */
    { popv(5); return onevalue(v0187); }

v0008:
    v0188 = stack[0];
    v0187 = elt(env, 3); /* physopname */
    v0187 = get(v0188, v0187);
    env = stack[-4];
    stack[-2] = v0187;
    goto v0192;

v0020:
    v0188 = stack[-1];
    v0187 = elt(env, 3); /* physopname */
    v0187 = get(v0188, v0187);
    env = stack[-4];
    stack[-3] = v0187;
    goto v0191;

v0032:
    v0187 = stack[-1];
    fn = elt(env, 5); /* !*physopp */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    if (v0187 == nil) goto v0033;
    v0187 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0187); }

v0033:
    v0187 = stack[0];
    fn = elt(env, 5); /* !*physopp */
    v0187 = (*qfn1(fn))(qenv(fn), v0187);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-4];
    if (v0187 == nil) goto v0089;
    v0187 = qvalue(elt(env, 2)); /* t */
    { popv(5); return onevalue(v0187); }

v0089:
    v0188 = stack[-1];
    v0187 = stack[0];
    {
        popv(5);
        fn = elt(env, 7); /* ordop2 */
        return (*qfn2(fn))(qenv(fn), v0188, v0187);
    }
/* error exit handlers */
v0190:
    popv(5);
    return nil;
}



/* Code for mktails1 */

static Lisp_Object MS_CDECL CC_mktails1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0142, v0202, v0038;
    Lisp_Object fn;
    Lisp_Object v0010, v0011, v0005;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails1");
    va_start(aa, nargs);
    v0005 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mktails1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0005,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0010;
    v0142 = v0011;
    stack[-1] = v0005;
/* end of prologue */
    v0202 = stack[-1];
    fn = elt(env, 3); /* getroad */
    v0142 = (*qfn2(fn))(qenv(fn), v0202, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    v0202 = v0142;
    v0038 = (Lisp_Object)1; /* 0 */
    v0142 = v0202;
    if (v0038 == v0142) goto v0204;
    v0038 = (Lisp_Object)1; /* 0 */
    v0142 = stack[-1];
    v0142 = qcdr(v0142);
    if (v0038 == v0142) goto v0088;
    v0038 = stack[-1];
    v0142 = stack[0];
    v0142 = Lassoc(nil, v0038, v0142);
    v0038 = v0142;
    v0142 = v0038;
    if (v0142 == nil) goto v0056;
    v0142 = v0038;
    v0142 = qcdr(v0142);
    v0142 = qcdr(v0142);
    if (v0142 == nil) goto v0069;
    v0142 = v0038;
    v0142 = qcdr(v0142);
    v0202 = Lreverse(nil, v0142);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    v0142 = stack[0];
    popv(4);
    return cons(v0202, v0142);

v0069:
    v0142 = v0038;
    v0202 = qcdr(v0142);
    v0142 = stack[0];
    popv(4);
    return cons(v0202, v0142);

v0056:
    v0142 = stack[-1];
    fn = elt(env, 4); /* mkinds */
    v0142 = (*qfn2(fn))(qenv(fn), v0142, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    v0038 = v0142;
    stack[-2] = v0038;
    v0142 = stack[-1];
    v0202 = v0038;
    v0202 = cons(v0142, v0202);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    v0142 = stack[0];
    {
        Lisp_Object v0127 = stack[-2];
        popv(4);
        return list2star(v0127, v0202, v0142);
    }

v0088:
    v0142 = stack[-1];
    v0202 = qcar(v0142);
    v0142 = elt(env, 2); /* replace_by_vector */
    v0142 = get(v0202, v0142);
    env = stack[-3];
    if (!(v0142 == nil)) goto v0045;
    v0142 = stack[-1];
    v0142 = qcar(v0142);
    goto v0045;

v0045:
    v0202 = ncons(v0142);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    v0142 = stack[0];
    popv(4);
    return cons(v0202, v0142);

v0204:
    v0202 = qvalue(elt(env, 1)); /* nil */
    v0142 = stack[0];
    popv(4);
    return cons(v0202, v0142);
/* error exit handlers */
v0203:
    popv(4);
    return nil;
}



/* Code for putd */

static Lisp_Object MS_CDECL CC_putd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0216, v0217, v0218;
    Lisp_Object fn;
    Lisp_Object v0010, v0011, v0005;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "putd");
    va_start(aa, nargs);
    v0005 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for putd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0005,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0010;
    stack[-1] = v0011;
    stack[-2] = v0005;
/* end of prologue */
    v0217 = stack[0];
    v0216 = elt(env, 1); /* funarg */
    if (!consp(v0217)) goto v0099;
    v0217 = qcar(v0217);
    if (!(v0217 == v0216)) goto v0099;
    v0217 = elt(env, 2); /* lambda */
    v0216 = stack[0];
    v0216 = qcdr(v0216);
    v0216 = qcdr(v0216);
    v0216 = cons(v0217, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    stack[0] = v0216;
    goto v0099;

v0099:
    v0216 = stack[-2];
    if (!symbolp(v0216)) v0216 = nil;
    else { v0216 = qfastgets(v0216);
           if (v0216 != nil) { v0216 = elt(v0216, 1); /* lose */
#ifdef RECORD_GET
             if (v0216 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v0216 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v0216 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v0216 == SPID_NOPROP) v0216 = nil; else v0216 = lisp_true; }}
#endif
    if (v0216 == nil) goto v0079;
    v0216 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    v0216 = elt(env, 3); /* "+++ " */
    v0216 = Lprinc(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    v0216 = stack[-2];
    v0216 = Lprin(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    v0216 = elt(env, 4); /* " not defined (LOSE flag)" */
    v0216 = Lprintc(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    v0216 = qvalue(elt(env, 5)); /* nil */
    { popv(4); return onevalue(v0216); }

v0079:
    v0216 = qvalue(elt(env, 6)); /* !*redefmsg */
    if (v0216 == nil) goto v0083;
    v0216 = stack[-2];
    fn = elt(env, 15); /* getd */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    if (v0216 == nil) goto v0083;
    v0216 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    v0216 = elt(env, 3); /* "+++ " */
    v0216 = Lprinc(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    v0216 = stack[-2];
    v0216 = Lprin(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    v0216 = elt(env, 7); /* " redefined" */
    v0216 = Lprintc(nil, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    goto v0083;

v0083:
    v0217 = stack[-1];
    v0216 = elt(env, 8); /* expr */
    if (v0217 == v0216) goto v0017;
    v0217 = stack[-1];
    v0216 = elt(env, 9); /* subr */
    if (v0217 == v0216) goto v0013;
    v0217 = stack[-1];
    v0216 = elt(env, 10); /* macro */
    if (v0217 == v0216) goto v0219;
    v0216 = qvalue(elt(env, 5)); /* nil */
    goto v0008;

v0008:
    if (v0216 == nil) goto v0141;
    v0218 = elt(env, 11); /* dm */
    v0217 = stack[-2];
    v0216 = stack[0];
    v0216 = qcdr(v0216);
    v0216 = list2star(v0218, v0217, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0141:
    v0217 = stack[-1];
    v0216 = elt(env, 12); /* fexpr */
    if (v0217 == v0216) goto v0127;
    v0216 = qvalue(elt(env, 5)); /* nil */
    goto v0041;

v0041:
    if (v0216 == nil) goto v0220;
    v0218 = elt(env, 13); /* df */
    v0217 = stack[-2];
    v0216 = stack[0];
    v0216 = qcdr(v0216);
    v0216 = list2star(v0218, v0217, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    env = stack[-3];
    fn = elt(env, 16); /* eval */
    v0216 = (*qfn1(fn))(qenv(fn), v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0220:
    v0217 = elt(env, 14); /* "Bad type ~S in putd" */
    v0216 = stack[-1];
    fn = elt(env, 17); /* error */
    v0216 = (*qfn2(fn))(qenv(fn), v0217, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0127:
    v0217 = stack[0];
    v0216 = elt(env, 2); /* lambda */
    v0216 = Leqcar(nil, v0217, v0216);
    env = stack[-3];
    goto v0041;

v0219:
    v0217 = stack[0];
    v0216 = elt(env, 2); /* lambda */
    v0216 = Leqcar(nil, v0217, v0216);
    env = stack[-3];
    goto v0008;

v0013:
    v0217 = stack[-2];
    v0216 = stack[0];
    v0216 = Lsymbol_set_definition(nil, v0217, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v0017:
    v0217 = stack[-2];
    v0216 = stack[0];
    v0216 = Lsymbol_set_definition(nil, v0217, v0216);
    nil = C_nil;
    if (exception_pending()) goto v0186;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v0186:
    popv(4);
    return nil;
}



/* Code for lalr_make_gotos */

static Lisp_Object MS_CDECL CC_lalr_make_gotos(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0233, v0234, v0126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lalr_make_gotos");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_make_gotos");
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
    push2(nil, nil);
/* end of prologue */
    stack[-5] = nil;
    stack[-4] = nil;
    v0233 = (Lisp_Object)1; /* 0 */
    stack[-6] = v0233;
    v0233 = qvalue(elt(env, 1)); /* goto_cache */
    fn = elt(env, 13); /* hashcontents */
    v0233 = (*qfn1(fn))(qenv(fn), v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    stack[-3] = v0233;
    goto v0024;

v0024:
    v0233 = stack[-3];
    if (v0233 == nil) goto v0090;
    v0233 = stack[-3];
    v0233 = qcar(v0233);
    stack[-2] = v0233;
    v0233 = stack[-2];
    v0233 = qcar(v0233);
    if (is_number(v0233)) goto v0093;
    v0233 = qvalue(elt(env, 3)); /* !*lalr_verbose */
    if (v0233 == nil) goto v0183;
    v0233 = stack[-2];
    v0233 = qcdr(v0233);
    stack[-1] = v0233;
    goto v0094;

v0094:
    v0233 = stack[-1];
    if (v0233 == nil) goto v0183;
    v0233 = stack[-1];
    v0233 = qcar(v0233);
    stack[0] = v0233;
    v0233 = stack[0];
    v0233 = qcar(v0233);
    v0233 = Lprin(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = (Lisp_Object)161; /* 10 */
    v0233 = Lttab(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = stack[-2];
    v0233 = qcar(v0233);
    fn = elt(env, 14); /* lalr_prin_symbol */
    v0233 = (*qfn1(fn))(qenv(fn), v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = elt(env, 4); /* " GOTO state " */
    v0233 = Lprinc(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = stack[0];
    v0233 = qcdr(v0233);
    v0233 = Lprin(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = stack[-1];
    v0233 = qcdr(v0233);
    stack[-1] = v0233;
    goto v0094;

v0183:
    v0233 = stack[-2];
    v0234 = qcar(v0233);
    v0233 = elt(env, 5); /* non_terminal_code */
    v0126 = get(v0234, v0233);
    env = stack[-7];
    v0234 = stack[-6];
    v0233 = stack[-5];
    v0233 = acons(v0126, v0234, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    stack[-5] = v0233;
    v0233 = stack[-2];
    v0233 = qcdr(v0233);
    if (v0233 == nil) goto v0093;
    v0233 = stack[-2];
    v0233 = qcdr(v0233);
    fn = elt(env, 15); /* lalr_most_common_dest */
    v0233 = (*qfn1(fn))(qenv(fn), v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    stack[0] = v0233;
    v0233 = stack[-2];
    v0233 = qcdr(v0233);
    stack[-1] = v0233;
    goto v0039;

v0039:
    v0233 = stack[-1];
    if (v0233 == nil) goto v0040;
    v0233 = stack[-1];
    v0233 = qcar(v0233);
    v0126 = v0233;
    v0233 = v0126;
    v0234 = qcdr(v0233);
    v0233 = stack[0];
    if (equal(v0234, v0233)) goto v0236;
    v0234 = v0126;
    v0233 = stack[-4];
    v0233 = cons(v0234, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    stack[-4] = v0233;
    v0233 = stack[-6];
    v0233 = add1(v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    stack[-6] = v0233;
    goto v0236;

v0236:
    v0233 = stack[-1];
    v0233 = qcdr(v0233);
    stack[-1] = v0233;
    goto v0039;

v0040:
    v0126 = (Lisp_Object)-15; /* -1 */
    v0234 = stack[0];
    v0233 = stack[-4];
    v0233 = acons(v0126, v0234, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    stack[-4] = v0233;
    v0233 = stack[-6];
    v0233 = add1(v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    stack[-6] = v0233;
    goto v0093;

v0093:
    v0233 = stack[-3];
    v0233 = qcdr(v0233);
    stack[-3] = v0233;
    goto v0024;

v0090:
    v0233 = qvalue(elt(env, 6)); /* non_terminals */
    v0233 = Llength(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    fn = elt(env, 16); /* mkvect16 */
    v0233 = (*qfn1(fn))(qenv(fn), v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    qvalue(elt(env, 7)) = v0233; /* goto_index */
    v0233 = stack[-6];
    fn = elt(env, 16); /* mkvect16 */
    v0233 = (*qfn1(fn))(qenv(fn), v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    qvalue(elt(env, 8)) = v0233; /* goto_old_state */
    v0233 = stack[-6];
    fn = elt(env, 16); /* mkvect16 */
    v0233 = (*qfn1(fn))(qenv(fn), v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    qvalue(elt(env, 9)) = v0233; /* goto_new_state */
    v0233 = stack[-5];
    stack[0] = v0233;
    goto v0237;

v0237:
    v0233 = stack[0];
    if (v0233 == nil) goto v0238;
    v0233 = stack[0];
    v0233 = qcar(v0233);
    v0126 = qvalue(elt(env, 7)); /* goto_index */
    v0234 = v0233;
    v0234 = qcar(v0234);
    v0233 = qcdr(v0233);
    fn = elt(env, 17); /* putv16 */
    v0233 = (*qfnn(fn))(qenv(fn), 3, v0126, v0234, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = stack[0];
    v0233 = qcdr(v0233);
    stack[0] = v0233;
    goto v0237;

v0238:
    v0234 = stack[-6];
    v0233 = (Lisp_Object)1; /* 0 */
    v0233 = (Lisp_Object)greaterp2(v0234, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    v0233 = v0233 ? lisp_true : nil;
    env = stack[-7];
    if (v0233 == nil) goto v0132;
    v0233 = stack[-6];
    v0233 = sub1(v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    stack[-6] = v0233;
    v0126 = qvalue(elt(env, 8)); /* goto_old_state */
    v0234 = stack[-6];
    v0233 = stack[-4];
    v0233 = qcar(v0233);
    v0233 = qcar(v0233);
    fn = elt(env, 17); /* putv16 */
    v0233 = (*qfnn(fn))(qenv(fn), 3, v0126, v0234, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0126 = qvalue(elt(env, 9)); /* goto_new_state */
    v0234 = stack[-6];
    v0233 = stack[-4];
    v0233 = qcar(v0233);
    v0233 = qcdr(v0233);
    fn = elt(env, 17); /* putv16 */
    v0233 = (*qfnn(fn))(qenv(fn), 3, v0126, v0234, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = stack[-4];
    v0233 = qcdr(v0233);
    stack[-4] = v0233;
    goto v0238;

v0132:
    v0233 = elt(env, 10); /* "goto_index: " */
    v0233 = Lprinc(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = qvalue(elt(env, 7)); /* goto_index */
    v0233 = Lprint(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = elt(env, 11); /* "goto_old_state: " */
    v0233 = Lprinc(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = qvalue(elt(env, 8)); /* goto_old_state */
    v0233 = Lprint(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = elt(env, 12); /* "goto_new_state: " */
    v0233 = Lprinc(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-7];
    v0233 = qvalue(elt(env, 9)); /* goto_new_state */
    v0233 = Lprint(nil, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    v0233 = nil;
    { popv(8); return onevalue(v0233); }
/* error exit handlers */
v0235:
    popv(8);
    return nil;
}



/* Code for rlis */

static Lisp_Object MS_CDECL CC_rlis(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rlis");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rlis");
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
    v0035 = qvalue(elt(env, 1)); /* cursym!* */
    stack[0] = v0035;
    fn = elt(env, 6); /* scan */
    v0035 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    if (!symbolp(v0035)) v0035 = nil;
    else { v0035 = qfastgets(v0035);
           if (v0035 != nil) { v0035 = elt(v0035, 55); /* delim */
#ifdef RECORD_GET
             if (v0035 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0035 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0035 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0035 == SPID_NOPROP) v0035 = nil; else v0035 = lisp_true; }}
#endif
    if (v0035 == nil) goto v0037;
    v0035 = stack[0];
    v0173 = qvalue(elt(env, 2)); /* nil */
    popv(3);
    return list2(v0035, v0173);

v0037:
    v0035 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v0035 == nil) goto v0239;
    stack[-1] = stack[0];
    stack[0] = elt(env, 4); /* list */
    v0035 = elt(env, 5); /* lambda */
    fn = elt(env, 7); /* xread1 */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    fn = elt(env, 8); /* remcomma */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    v0035 = cons(stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    {
        Lisp_Object v0045 = stack[-1];
        popv(3);
        return list2(v0045, v0035);
    }

v0239:
    v0035 = elt(env, 5); /* lambda */
    fn = elt(env, 7); /* xread1 */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-2];
    fn = elt(env, 8); /* remcomma */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    {
        Lisp_Object v0043 = stack[0];
        popv(3);
        return cons(v0043, v0035);
    }
/* error exit handlers */
v0199:
    popv(3);
    return nil;
}



/* Code for tmsf */

static Lisp_Object CC_tmsf(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0236, v0197, v0144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tmsf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0005;
/* end of prologue */
    v0236 = (Lisp_Object)1; /* 0 */
    v0144 = v0236;
    goto v0086;

v0086:
    v0236 = stack[-1];
    if (!consp(v0236)) goto v0052;
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = (consp(v0236) ? nil : lisp_true);
    goto v0053;

v0053:
    if (v0236 == nil) goto v0071;
    v0236 = stack[-1];
    if (v0236 == nil) { popv(4); return onevalue(v0144); }
    v0236 = v0144;
    popv(4);
    return add1(v0236);

v0071:
    stack[-2] = v0144;
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = qcar(v0236);
    v0236 = qcar(v0236);
    stack[0] = v0236;
    fn = elt(env, 3); /* sfp */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    if (v0236 == nil) goto v0065;
    v0236 = stack[0];
    v0236 = CC_tmsf(env, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    stack[0] = v0236;
    goto v0064;

v0064:
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = qcdr(v0236);
    fn = elt(env, 4); /* tmsf!* */
    v0236 = (*qfn1(fn))(qenv(fn), v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    v0236 = plus2(stack[0], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    v0236 = plus2(stack[-2], v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    v0144 = v0236;
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = qcar(v0236);
    v0197 = qcdr(v0236);
    v0236 = (Lisp_Object)17; /* 1 */
    if (v0197 == v0236) goto v0077;
    v0236 = stack[-1];
    v0236 = qcar(v0236);
    v0236 = qcar(v0236);
    v0197 = qcdr(v0236);
    v0236 = (Lisp_Object)33; /* 2 */
    if (v0197 == v0236) goto v0230;
    v0197 = v0144;
    v0236 = (Lisp_Object)33; /* 2 */
    v0236 = plus2(v0197, v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    v0144 = v0236;
    goto v0077;

v0077:
    v0236 = stack[-1];
    v0236 = qcdr(v0236);
    stack[-1] = v0236;
    goto v0086;

v0230:
    v0236 = v0144;
    v0236 = add1(v0236);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    v0144 = v0236;
    goto v0077;

v0065:
    v0236 = (Lisp_Object)17; /* 1 */
    stack[0] = v0236;
    goto v0064;

v0052:
    v0236 = qvalue(elt(env, 1)); /* t */
    goto v0053;
/* error exit handlers */
v0240:
    popv(4);
    return nil;
}



/* Code for pasf_vf */

static Lisp_Object CC_pasf_vf(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0026, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_vf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0026 = v0005;
/* end of prologue */
    v0027 = v0026;
    v0025 = elt(env, 1); /* true */
    if (v0027 == v0025) goto v0082;
    v0027 = v0026;
    v0025 = elt(env, 3); /* false */
    v0025 = (v0027 == v0025 ? lisp_true : nil);
    goto v0031;

v0031:
    if (v0025 == nil) goto v0090;
    v0025 = qvalue(elt(env, 4)); /* nil */
    goto v0086;

v0086:
    if (v0025 == nil) { popv(1); return onevalue(v0026); }
    v0025 = v0026;
    v0025 = Lconsp(nil, v0025);
    env = stack[0];
    if (v0025 == nil) goto v0219;
    v0025 = v0026;
    v0025 = qcar(v0025);
    v0025 = Lconsp(nil, v0025);
    env = stack[0];
    if (v0025 == nil) goto v0219;
    v0025 = v0026;
    v0025 = qcar(v0025);
    v0027 = qcar(v0025);
    v0025 = elt(env, 5); /* (cong ncong) */
    v0025 = Lmemq(nil, v0027, v0025);
    if (v0025 == nil) goto v0219;
    v0025 = v0026;
    v0025 = qcar(v0025);
    v0025 = qcdr(v0025);
    if (!consp(v0025)) goto v0056;
    v0025 = v0026;
    v0025 = qcar(v0025);
    v0025 = qcdr(v0025);
    v0025 = qcar(v0025);
    v0025 = (consp(v0025) ? nil : lisp_true);
    goto v0057;

v0057:
    if (!(v0025 == nil)) goto v0219;
    v0025 = v0026;
    v0025 = qcdr(v0025);
    v0025 = qcar(v0025);
    if (!(v0025 == nil)) { popv(1); return onevalue(v0026); }
    v0025 = elt(env, 3); /* false */
    { popv(1); return onevalue(v0025); }

v0219:
    v0025 = v0026;
    v0025 = qcar(v0025);
    v0026 = qcdr(v0026);
    v0026 = qcar(v0026);
    fn = elt(env, 6); /* pasf_evalatp */
    v0025 = (*qfn2(fn))(qenv(fn), v0025, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[0];
    if (v0025 == nil) goto v0145;
    v0025 = elt(env, 1); /* true */
    { popv(1); return onevalue(v0025); }

v0145:
    v0025 = elt(env, 3); /* false */
    { popv(1); return onevalue(v0025); }

v0056:
    v0025 = qvalue(elt(env, 2)); /* t */
    goto v0057;

v0090:
    v0025 = v0026;
    v0025 = qcdr(v0025);
    v0025 = qcar(v0025);
    if (!consp(v0025)) goto v0064;
    v0025 = v0026;
    v0025 = qcdr(v0025);
    v0025 = qcar(v0025);
    v0025 = qcar(v0025);
    v0025 = (consp(v0025) ? nil : lisp_true);
    goto v0086;

v0064:
    v0025 = qvalue(elt(env, 2)); /* t */
    goto v0086;

v0082:
    v0025 = qvalue(elt(env, 2)); /* t */
    goto v0031;
/* error exit handlers */
v0028:
    popv(1);
    return nil;
}



/* Code for ibalp_negateat */

static Lisp_Object CC_ibalp_negateat(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_negateat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0005;
/* end of prologue */
    v0091 = stack[-1];
    fn = elt(env, 1); /* ibalp_op */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-3];
    v0091 = stack[-1];
    fn = elt(env, 2); /* ibalp_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-3];
    v0091 = stack[-1];
    fn = elt(env, 3); /* ibalp_arg2r */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-3];
    fn = elt(env, 4); /* ibalp_negatet */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-3];
    {
        Lisp_Object v0073 = stack[-2];
        Lisp_Object v0033 = stack[0];
        popv(4);
        fn = elt(env, 5); /* ibalp_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v0073, v0033, v0091);
    }
/* error exit handlers */
v0063:
    popv(4);
    return nil;
}



/* Code for !*!*a2s */

static Lisp_Object CC_HHa2s(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013;
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
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0012 = v0011;
    stack[-3] = v0005;
/* end of prologue */
    v0012 = stack[-3];
    if (v0012 == nil) goto v0099;
    v0013 = stack[-3];
    v0012 = elt(env, 2); /* nochange */
    v0012 = Lflagpcar(nil, v0013, v0012);
    env = stack[-5];
    if (v0012 == nil) goto v0201;
    v0012 = stack[-3];
    v0013 = qcar(v0012);
    v0012 = elt(env, 3); /* getel */
    if (!(v0013 == v0012)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v0201:
    v0013 = elt(env, 4); /* random */
    v0012 = stack[-3];
    fn = elt(env, 11); /* smember */
    v0012 = (*qfn2(fn))(qenv(fn), v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-5];
    if (v0012 == nil) goto v0056;
    stack[-4] = elt(env, 5); /* lambda */
    stack[-2] = elt(env, 6); /* (!*uncached) */
    stack[-1] = elt(env, 7); /* progn */
    stack[0] = elt(env, 8); /* (declare (special !*uncached)) */
    v0013 = qvalue(elt(env, 9)); /* !*!*a2sfn */
    v0012 = stack[-3];
    v0012 = list2(v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-5];
    v0012 = list3(stack[-1], stack[0], v0012);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-5];
    v0012 = list3(stack[-4], stack[-2], v0012);
    nil = C_nil;
    if (exception_pending()) goto v0213;
    env = stack[-5];
    v0013 = qvalue(elt(env, 10)); /* t */
    popv(6);
    return list2(v0012, v0013);

v0056:
    v0013 = qvalue(elt(env, 9)); /* !*!*a2sfn */
    v0012 = stack[-3];
    popv(6);
    return list2(v0013, v0012);

v0099:
    v0012 = elt(env, 1); /* "tell Hearn!!" */
    {
        popv(6);
        fn = elt(env, 12); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0012);
    }
/* error exit handlers */
v0213:
    popv(6);
    return nil;
}



/* Code for merge!-ind!-vars */

static Lisp_Object CC_mergeKindKvars(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0242;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for merge-ind-vars");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0005;
/* end of prologue */
    v0088 = qvalue(elt(env, 1)); /* !*nocommutedf */
    if (!(v0088 == nil)) goto v0080;
    v0088 = qvalue(elt(env, 2)); /* !*commutedf */
    if (v0088 == nil) goto v0053;
    v0088 = qvalue(elt(env, 3)); /* nil */
    goto v0024;

v0024:
    if (!(v0088 == nil)) goto v0080;
    v0242 = stack[0];
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    v0088 = qcdr(v0088);
    {
        popv(4);
        fn = elt(env, 4); /* derad */
        return (*qfn2(fn))(qenv(fn), v0242, v0088);
    }

v0080:
    v0242 = stack[0];
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    v0088 = qcdr(v0088);
    {
        popv(4);
        fn = elt(env, 5); /* derad!* */
        return (*qfn2(fn))(qenv(fn), v0242, v0088);
    }

v0053:
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    stack[-2] = qcar(v0088);
    v0242 = stack[0];
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    v0088 = qcdr(v0088);
    v0088 = cons(v0242, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-3];
    v0088 = Lmemq(nil, stack[-2], v0088);
    goto v0024;
/* error exit handlers */
v0015:
    popv(4);
    return nil;
}



/* Code for spquotematrix */

static Lisp_Object CC_spquotematrix(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object v0078;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spquotematrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0078 = v0005;
/* end of prologue */
    v0078 = elt(env, 1); /* sparse */
    return onevalue(v0078);
}



/* Code for vevdif */

static Lisp_Object CC_vevdif(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0026, v0027, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevdif");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0011;
    stack[-4] = v0005;
/* end of prologue */
    stack[-5] = nil;
    v0027 = nil;
    v0026 = stack[-4];
    stack[-1] = v0026;
    v0026 = stack[-3];
    stack[0] = v0026;
    goto v0082;

v0082:
    v0026 = stack[-1];
    if (v0026 == nil) goto v0031;
    v0026 = stack[0];
    if (v0026 == nil) goto v0031;
    v0026 = v0027;
    if (!(v0026 == nil)) goto v0031;
    v0026 = stack[-1];
    v0027 = qcar(v0026);
    v0026 = stack[0];
    v0026 = qcar(v0026);
    v0026 = (Lisp_Object)(int32_t)((int32_t)v0027 - (int32_t)v0026 + TAG_FIXNUM);
    stack[-2] = v0026;
    v0027 = stack[-2];
    v0026 = stack[-5];
    v0026 = cons(v0027, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    stack[-5] = v0026;
    v0027 = stack[-2];
    v0026 = (Lisp_Object)1; /* 0 */
    v0026 = ((intptr_t)v0027 < (intptr_t)v0026) ? lisp_true : nil;
    v0027 = v0026;
    v0026 = stack[-1];
    v0026 = qcdr(v0026);
    stack[-1] = v0026;
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    stack[0] = v0026;
    goto v0082;

v0031:
    v0026 = v0027;
    if (!(v0026 == nil)) goto v0088;
    v0026 = stack[0];
    if (v0026 == nil) goto v0243;
    v0026 = stack[0];
    if (v0026 == nil) goto v0046;
    v0026 = stack[0];
    v0027 = qcar(v0026);
    v0026 = (Lisp_Object)1; /* 0 */
    if (v0027 == v0026) goto v0062;
    v0026 = qvalue(elt(env, 1)); /* nil */
    goto v0016;

v0016:
    if (!(v0026 == nil)) goto v0243;

v0088:
    v0026 = stack[-4];
    v0026 = Lprint(nil, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    v0026 = stack[-3];
    v0026 = Lprint(nil, v0026);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    v0026 = elt(env, 3); /* backtrace */
    fn = elt(env, 6); /* getd */
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    if (v0026 == nil) goto v0058;
    fn = elt(env, 3); /* backtrace */
    v0026 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    goto v0058;

v0058:
    v0028 = elt(env, 4); /* dipoly */
    v0027 = (Lisp_Object)81; /* 5 */
    v0026 = elt(env, 5); /* "Vevdif, difference would be < 0" */
    {
        popv(7);
        fn = elt(env, 7); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0028, v0027, v0026);
    }

v0243:
    v0026 = stack[-5];
    v0027 = Lnreverse(nil, v0026);
    v0026 = stack[-1];
        popv(7);
        return Lnconc(nil, v0027, v0026);

v0062:
    v0026 = stack[0];
    v0026 = qcdr(v0026);
    fn = elt(env, 8); /* vevzero!?1 */
    v0026 = (*qfn1(fn))(qenv(fn), v0026);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-6];
    goto v0016;

v0046:
    v0026 = qvalue(elt(env, 2)); /* t */
    goto v0016;
/* error exit handlers */
v0040:
    popv(7);
    return nil;
}



/* Code for inttovec1 */

static Lisp_Object CC_inttovec1(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0199, v0045;
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
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0005;
/* end of prologue */
    v0045 = stack[-1];
    v0199 = (Lisp_Object)17; /* 1 */
    if (v0045 == v0199) goto v0099;
    v0199 = stack[-1];
    v0045 = sub1(v0199);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    v0199 = stack[0];
    v0199 = qcdr(v0199);
    fn = elt(env, 1); /* inttovec!-solve */
    v0199 = (*qfn2(fn))(qenv(fn), v0045, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    stack[-2] = v0199;
    v0199 = stack[0];
    v0045 = qcar(v0199);
    v0199 = stack[-2];
    v0199 = qcar(v0199);
    stack[0] = difference2(v0045, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    v0199 = stack[-1];
    v0045 = sub1(v0199);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    env = stack[-3];
    v0199 = stack[-2];
    v0199 = CC_inttovec1(env, v0045, v0199);
    nil = C_nil;
    if (exception_pending()) goto v0242;
    {
        Lisp_Object v0075 = stack[0];
        popv(4);
        return cons(v0075, v0199);
    }

v0099:
    v0199 = stack[0];
    v0199 = qcar(v0199);
    popv(4);
    return ncons(v0199);
/* error exit handlers */
v0242:
    popv(4);
    return nil;
}



/* Code for removeindices */

static Lisp_Object CC_removeindices(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for removeindices");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0011;
    stack[-3] = v0005;
/* end of prologue */
    v0060 = elt(env, 0); /* removeindices */
    if (!symbolp(v0060)) v0060 = nil;
    else { v0060 = qfastgets(v0060);
           if (v0060 != nil) { v0060 = elt(v0060, 53); /* tracing */
#ifdef RECORD_GET
             if (v0060 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v0060 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v0060 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v0060 == SPID_NOPROP) v0060 = nil; else v0060 = lisp_true; }}
#endif
    if (v0060 == nil) goto v0084;
    stack[-4] = elt(env, 0); /* removeindices */
    stack[-1] = elt(env, 1); /* "u= " */
    stack[0] = stack[-3];
    v0203 = elt(env, 2); /* " x= " */
    v0060 = stack[-2];
    v0060 = list2(v0203, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    v0060 = list3star(stack[-4], stack[-1], stack[0], v0060);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    fn = elt(env, 6); /* trwrite */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    goto v0084;

v0084:
    v0060 = stack[-2];
    if (v0060 == nil) goto v0079;
    v0060 = stack[-3];
    v0060 = Lsymbolp(nil, v0060);
    env = stack[-5];
    if (!(v0060 == nil)) goto v0081;
    v0060 = stack[-3];
    fn = elt(env, 7); /* !*physopp */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    v0060 = (v0060 == nil ? lisp_true : nil);
    goto v0081;

v0081:
    if (!(v0060 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0060 = stack[-2];
    if (!(symbolp(v0060))) goto v0088;
    v0060 = stack[-2];
    fn = elt(env, 8); /* isanindex */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    if (!(v0060 == nil)) goto v0088;

v0230:
    v0203 = elt(env, 0); /* removeindices */
    v0060 = elt(env, 4); /* "invalid arguments to removeindices" */
    fn = elt(env, 9); /* rederr2 */
    v0060 = (*qfn2(fn))(qenv(fn), v0203, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    goto v0045;

v0045:
    v0060 = stack[-3];
    v0060 = qcar(v0060);
    stack[0] = v0060;
    v0060 = stack[-3];
    v0060 = qcdr(v0060);
    stack[-3] = v0060;
    v0060 = stack[-3];
    if (v0060 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v0060 = stack[-2];
    if (symbolp(v0060)) goto v0244;
    v0060 = stack[-2];
    stack[-1] = v0060;
    goto v0212;

v0212:
    v0060 = stack[-1];
    if (v0060 == nil) goto v0014;
    v0060 = stack[-1];
    v0060 = qcar(v0060);
    v0203 = v0060;
    v0060 = stack[-3];
    v0060 = Ldelete(nil, v0203, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    stack[-3] = v0060;
    v0060 = stack[-1];
    v0060 = qcdr(v0060);
    stack[-1] = v0060;
    goto v0212;

v0014:
    v0060 = stack[-3];
    if (v0060 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v0203 = stack[0];
    v0060 = stack[-3];
    popv(6);
    return cons(v0203, v0060);

v0244:
    v0203 = stack[-2];
    v0060 = stack[-3];
    v0060 = Ldelete(nil, v0203, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    stack[-3] = v0060;
    goto v0014;

v0088:
    v0060 = stack[-2];
    fn = elt(env, 10); /* idlistp */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    if (v0060 == nil) goto v0045;
    v0060 = stack[-2];
    fn = elt(env, 11); /* areallindices */
    v0060 = (*qfn1(fn))(qenv(fn), v0060);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-5];
    if (v0060 == nil) goto v0230;
    else goto v0045;

v0079:
    v0060 = qvalue(elt(env, 3)); /* t */
    goto v0081;
/* error exit handlers */
v0209:
    popv(6);
    return nil;
}



/* Code for assert_install */

static Lisp_Object CC_assert_install(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_install");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0241 = v0005;
/* end of prologue */
    stack[0] = v0241;
    goto v0099;

v0099:
    v0241 = stack[0];
    if (v0241 == nil) goto v0086;
    v0241 = stack[0];
    v0241 = qcar(v0241);
    fn = elt(env, 2); /* assert_install1 */
    v0241 = (*qfn1(fn))(qenv(fn), v0241);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-1];
    v0241 = stack[0];
    v0241 = qcdr(v0241);
    stack[0] = v0241;
    goto v0099;

v0086:
    v0241 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0241); }
/* error exit handlers */
v0073:
    popv(2);
    return nil;
}



/* Code for idcons_ordp */

static Lisp_Object CC_idcons_ordp(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0053, v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for idcons_ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0082 = v0011;
    v0053 = v0005;
/* end of prologue */
    v0052 = v0053;
    v0053 = v0082;
    v0082 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v0052, v0053, v0082);
    }
}



/* Code for arplus!: */

static Lisp_Object CC_arplusT(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0072, v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for arplus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0072 = v0011;
    v0071 = v0005;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = nil; /* !*exp */
    v0066 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v0066; /* !*exp */
    stack[0] = elt(env, 4); /* !:ar!: */
    v0066 = v0071;
    v0066 = qcdr(v0066);
    v0072 = qcdr(v0072);
    fn = elt(env, 5); /* addf */
    v0066 = (*qfn2(fn))(qenv(fn), v0066, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    v0066 = cons(stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v0066); }
/* error exit handlers */
v0023:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for formsetq */

static Lisp_Object MS_CDECL CC_formsetq(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0012, v0013, v0182, v0067;
    Lisp_Object fn;
    Lisp_Object v0010, v0011, v0005;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formsetq");
    va_start(aa, nargs);
    v0005 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formsetq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0013 = v0010;
    v0182 = v0011;
    v0067 = v0005;
/* end of prologue */
    v0012 = v0013;
    v0014 = elt(env, 1); /* symbolic */
    if (v0012 == v0014) goto v0204;
    v0014 = v0067;
    v0012 = v0182;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v0014, v0012, v0013);
    }

v0204:
    v0014 = v0067;
    v0014 = qcdr(v0014);
    v0012 = qcar(v0014);
    v0014 = elt(env, 2); /* list */
    if (!consp(v0012)) goto v0173;
    v0012 = qcar(v0012);
    if (!(v0012 == v0014)) goto v0173;
    v0014 = v0067;
    v0012 = v0182;
    {
        fn = elt(env, 5); /* formsetq1 */
        return (*qfnn(fn))(qenv(fn), 3, v0014, v0012, v0013);
    }

v0173:
    v0014 = v0067;
    v0014 = qcdr(v0014);
    v0012 = qcar(v0014);
    v0014 = elt(env, 3); /* cons */
    if (!consp(v0012)) goto v0009;
    v0012 = qcar(v0012);
    if (!(v0012 == v0014)) goto v0009;
    v0014 = v0067;
    v0012 = v0182;
    {
        fn = elt(env, 6); /* formsetq2 */
        return (*qfnn(fn))(qenv(fn), 3, v0014, v0012, v0013);
    }

v0009:
    v0014 = v0067;
    v0012 = v0182;
    {
        fn = elt(env, 4); /* formsetq0 */
        return (*qfnn(fn))(qenv(fn), 3, v0014, v0012, v0013);
    }
}



/* Code for gcref_select */

static Lisp_Object CC_gcref_select(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0219, v0236, v0197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcref_select");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0219 = v0005;
/* end of prologue */
    stack[-3] = v0219;
    goto v0084;

v0084:
    v0219 = stack[-3];
    if (v0219 == nil) goto v0032;
    v0219 = stack[-3];
    v0219 = qcar(v0219);
    v0197 = v0219;
    v0236 = v0197;
    v0219 = elt(env, 2); /* defd */
    v0219 = Lflagp(nil, v0236, v0219);
    env = stack[-4];
    if (v0219 == nil) goto v0239;
    v0236 = v0197;
    v0219 = qvalue(elt(env, 3)); /* gcref_nolist!* */
    v0219 = Lmemq(nil, v0236, v0219);
    v0219 = (v0219 == nil ? lisp_true : nil);
    goto v0093;

v0093:
    if (v0219 == nil) goto v0073;
    v0219 = v0197;
    v0219 = ncons(v0219);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0241;

v0241:
    stack[-2] = v0219;
    v0219 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    stack[-1] = v0219;
    v0219 = stack[-3];
    v0219 = qcdr(v0219);
    stack[-3] = v0219;
    v0219 = stack[-1];
    if (!consp(v0219)) goto v0084;
    else goto v0037;

v0037:
    v0219 = stack[-3];
    if (v0219 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0219 = stack[-3];
    v0219 = qcar(v0219);
    v0197 = v0219;
    v0236 = v0197;
    v0219 = elt(env, 2); /* defd */
    v0219 = Lflagp(nil, v0236, v0219);
    env = stack[-4];
    if (v0219 == nil) goto v0007;
    v0236 = v0197;
    v0219 = qvalue(elt(env, 3)); /* gcref_nolist!* */
    v0219 = Lmemq(nil, v0236, v0219);
    v0219 = (v0219 == nil ? lisp_true : nil);
    goto v0056;

v0056:
    if (v0219 == nil) goto v0062;
    v0219 = v0197;
    v0219 = ncons(v0219);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    goto v0016;

v0016:
    v0219 = Lrplacd(nil, stack[0], v0219);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    v0219 = stack[-1];
    fn = elt(env, 4); /* lastpair */
    v0219 = (*qfn1(fn))(qenv(fn), v0219);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-4];
    stack[-1] = v0219;
    v0219 = stack[-3];
    v0219 = qcdr(v0219);
    stack[-3] = v0219;
    goto v0037;

v0062:
    v0219 = nil;
    goto v0016;

v0007:
    v0219 = qvalue(elt(env, 1)); /* nil */
    goto v0056;

v0073:
    v0219 = nil;
    goto v0241;

v0239:
    v0219 = qvalue(elt(env, 1)); /* nil */
    goto v0093;

v0032:
    v0219 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0219); }
/* error exit handlers */
v0240:
    popv(5);
    return nil;
}



/* Code for ofsf_smupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smupdknowl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0181, v0148, v0058;
    Lisp_Object fn;
    Lisp_Object v0078, v0010, v0011, v0005;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smupdknowl");
    va_start(aa, nargs);
    v0005 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    v0078 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0078,v0010,v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0005,v0011,v0010,v0078);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v0078;
    stack[-2] = v0010;
    stack[-3] = v0011;
    stack[-4] = v0005;
/* end of prologue */

v0032:
    v0181 = stack[-3];
    if (v0181 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    v0148 = stack[-4];
    v0181 = elt(env, 2); /* and */
    if (v0148 == v0181) goto v0063;
    v0181 = stack[-3];
    v0181 = qcar(v0181);
    fn = elt(env, 4); /* ofsf_negateat */
    v0181 = (*qfn1(fn))(qenv(fn), v0181);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    goto v0241;

v0241:
    v0148 = v0181;
    v0181 = stack[-3];
    v0181 = qcdr(v0181);
    stack[-3] = v0181;
    v0181 = stack[-1];
    fn = elt(env, 5); /* ofsf_at2ir */
    v0181 = (*qfn2(fn))(qenv(fn), v0148, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0058 = v0181;
    v0181 = v0058;
    v0148 = qcar(v0181);
    v0181 = stack[-2];
    v0181 = Lassoc(nil, v0148, v0181);
    stack[-5] = v0181;
    if (v0181 == nil) goto v0070;
    stack[0] = stack[-5];
    v0181 = v0058;
    v0181 = qcdr(v0181);
    v0148 = qcar(v0181);
    v0181 = stack[-5];
    v0181 = qcdr(v0181);
    fn = elt(env, 6); /* ofsf_sminsert */
    v0181 = (*qfn2(fn))(qenv(fn), v0148, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    fn = elt(env, 7); /* setcdr */
    v0181 = (*qfn2(fn))(qenv(fn), stack[0], v0181);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    v0181 = stack[-5];
    v0148 = qcdr(v0181);
    v0181 = elt(env, 3); /* false */
    if (!(v0148 == v0181)) goto v0032;
    v0181 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0181;
    v0181 = elt(env, 3); /* false */
    stack[-2] = v0181;
    goto v0032;

v0070:
    v0148 = v0058;
    v0181 = stack[-2];
    v0181 = cons(v0148, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0170;
    env = stack[-6];
    stack[-2] = v0181;
    goto v0032;

v0063:
    v0181 = stack[-3];
    v0181 = qcar(v0181);
    goto v0241;
/* error exit handlers */
v0170:
    popv(7);
    return nil;
}



/* Code for qqe_arg!-check */

static Lisp_Object CC_qqe_argKcheck(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_arg-check");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
/* end of prologue */
    v0182 = stack[0];
    v0182 = qcar(v0182);
    stack[-1] = v0182;
    v0182 = stack[-1];
    fn = elt(env, 4); /* qqe_rqopp */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (v0182 == nil) goto v0037;
    v0182 = stack[0];
    fn = elt(env, 5); /* qqe_arg!-check!-lq!-rq */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    goto v0030;

v0030:
    v0182 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0182); }

v0037:
    v0182 = stack[-1];
    fn = elt(env, 6); /* qqe_rbopp */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (v0182 == nil) goto v0082;
    v0182 = stack[0];
    fn = elt(env, 7); /* qqe_arg!-check!-lb!-rb */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    goto v0030;

v0082:
    v0182 = stack[-1];
    fn = elt(env, 8); /* qqe_qopheadp */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (!(v0182 == nil)) goto v0172;
    v0182 = stack[-1];
    fn = elt(env, 9); /* qqe_qoptailp */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (!(v0182 == nil)) goto v0172;
    v0182 = stack[-1];
    fn = elt(env, 10); /* qqe_qopaddp */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (v0182 == nil) goto v0173;
    v0182 = stack[0];
    fn = elt(env, 11); /* qqe_arg!-check!-lb!-rq */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    goto v0030;

v0173:
    v0182 = stack[0];
    v0182 = qcdr(v0182);
    stack[-1] = v0182;
    goto v0043;

v0043:
    v0182 = stack[-1];
    if (v0182 == nil) goto v0030;
    v0182 = stack[-1];
    v0182 = qcar(v0182);
    fn = elt(env, 12); /* qqe_arg!-check!-b */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (!(v0182 == nil)) goto v0017;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v0182 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    v0067 = stack[0];
    v0182 = elt(env, 3); /* "some arguments are not of basic type" */
    fn = elt(env, 14); /* typerr */
    v0182 = (*qfn2(fn))(qenv(fn), v0067, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    goto v0017;

v0017:
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    stack[-1] = v0182;
    goto v0043;

v0172:
    v0182 = stack[0];
    v0182 = qcdr(v0182);
    v0182 = qcar(v0182);
    fn = elt(env, 15); /* qqe_arg!-check!-q */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (!(v0182 == nil)) goto v0030;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v0182 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    v0067 = stack[0];
    v0182 = elt(env, 1); /* "some arguments are not of queue type" */
    fn = elt(env, 14); /* typerr */
    v0182 = (*qfn2(fn))(qenv(fn), v0067, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    goto v0030;
/* error exit handlers */
v0149:
    popv(3);
    return nil;
}



/* Code for kernord!-split */

static Lisp_Object CC_kernordKsplit(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0240, v0243, v0146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernord-split");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0011;
    stack[-3] = v0005;
/* end of prologue */
    stack[-4] = nil;
    stack[-1] = nil;
    v0240 = stack[-3];
    fn = elt(env, 2); /* powers */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-5];
    stack[-3] = v0240;
    v0240 = stack[-2];
    fn = elt(env, 2); /* powers */
    v0240 = (*qfn1(fn))(qenv(fn), v0240);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-5];
    stack[-2] = v0240;
    v0240 = stack[-3];
    stack[0] = v0240;
    goto v0082;

v0082:
    v0240 = stack[0];
    if (v0240 == nil) goto v0031;
    v0240 = stack[0];
    v0240 = qcar(v0240);
    v0146 = v0240;
    v0240 = v0146;
    v0243 = qcar(v0240);
    v0240 = stack[-2];
    v0240 = Lassoc(nil, v0243, v0240);
    if (v0240 == nil) goto v0021;
    v0243 = v0146;
    v0240 = stack[-1];
    v0240 = cons(v0243, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-5];
    stack[-1] = v0240;
    goto v0072;

v0072:
    v0240 = stack[0];
    v0240 = qcdr(v0240);
    stack[0] = v0240;
    goto v0082;

v0021:
    v0243 = v0146;
    v0240 = stack[-4];
    v0240 = cons(v0243, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-5];
    stack[-4] = v0240;
    goto v0072;

v0031:
    v0240 = stack[-2];
    stack[0] = v0240;
    goto v0075;

v0075:
    v0240 = stack[0];
    if (v0240 == nil) goto v0212;
    v0240 = stack[0];
    v0240 = qcar(v0240);
    v0146 = v0240;
    v0240 = v0146;
    v0243 = qcar(v0240);
    v0240 = stack[-3];
    v0240 = Lassoc(nil, v0243, v0240);
    if (v0240 == nil) goto v0039;
    v0243 = v0146;
    v0240 = stack[-1];
    v0240 = cons(v0243, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-5];
    stack[-1] = v0240;
    goto v0230;

v0230:
    v0240 = stack[0];
    v0240 = qcdr(v0240);
    stack[0] = v0240;
    goto v0075;

v0039:
    v0243 = v0146;
    v0240 = stack[-4];
    v0240 = cons(v0243, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-5];
    stack[-4] = v0240;
    goto v0230;

v0212:
    v0240 = stack[-4];
    v0243 = Lnreverse(nil, v0240);
    env = stack[-5];
    v0240 = stack[-1];
    v0240 = Lnreverse(nil, v0240);
    popv(6);
    return cons(v0243, v0240);
/* error exit handlers */
v0025:
    popv(6);
    return nil;
}



/* Code for ibalp_negatet */

static Lisp_Object CC_ibalp_negatet(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0201, v0089, v0064;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_negatet");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0064 = v0005;
/* end of prologue */
    v0089 = v0064;
    v0201 = (Lisp_Object)1; /* 0 */
    if (v0089 == v0201) goto v0051;
    v0089 = v0064;
    v0201 = (Lisp_Object)17; /* 1 */
    if (v0089 == v0201) goto v0082;
    v0201 = elt(env, 1); /* bnot */
    v0089 = v0064;
    return list2(v0201, v0089);

v0082:
    v0201 = (Lisp_Object)1; /* 0 */
    return onevalue(v0201);

v0051:
    v0201 = (Lisp_Object)17; /* 1 */
    return onevalue(v0201);
}



/* Code for aex_fvarl */

static Lisp_Object CC_aex_fvarl(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_fvarl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
/* end of prologue */
    v0031 = stack[0];
    fn = elt(env, 1); /* aex_varl */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    v0031 = stack[0];
    fn = elt(env, 2); /* aex_ctx */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    fn = elt(env, 3); /* ctx_idl */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-2];
    {
        Lisp_Object v0091 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* lto_setminus */
        return (*qfn2(fn))(qenv(fn), v0091, v0031);
    }
/* error exit handlers */
v0052:
    popv(3);
    return nil;
}



/* Code for freeoff */

static Lisp_Object CC_freeoff(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeoff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0005;
/* end of prologue */

v0099:
    v0058 = stack[-1];
    if (!consp(v0058)) goto v0032;
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = (consp(v0058) ? nil : lisp_true);
    goto v0024;

v0024:
    if (v0058 == nil) goto v0086;
    v0058 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0058); }

v0086:
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    fn = elt(env, 3); /* sfp */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    if (v0058 == nil) goto v0230;
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0212 = qcar(v0058);
    v0058 = stack[0];
    v0058 = CC_freeoff(env, v0212, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    if (v0058 == nil) goto v0245;
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0212 = qcdr(v0058);
    v0058 = stack[0];
    v0058 = CC_freeoff(env, v0212, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    if (v0058 == nil) goto v0242;
    v0058 = stack[-1];
    v0058 = qcdr(v0058);
    stack[-1] = v0058;
    goto v0099;

v0242:
    v0058 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0058); }

v0245:
    v0058 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0058); }

v0230:
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcar(v0058);
    v0212 = qcar(v0058);
    v0058 = stack[0];
    fn = elt(env, 4); /* ndepends */
    v0058 = (*qfn2(fn))(qenv(fn), v0212, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    if (v0058 == nil) goto v0182;
    v0058 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0058); }

v0182:
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0212 = qcdr(v0058);
    v0058 = stack[0];
    v0058 = CC_freeoff(env, v0212, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    if (v0058 == nil) goto v0007;
    v0058 = stack[-1];
    v0058 = qcdr(v0058);
    stack[-1] = v0058;
    goto v0099;

v0007:
    v0058 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0058); }

v0032:
    v0058 = qvalue(elt(env, 1)); /* t */
    goto v0024;
/* error exit handlers */
v0236:
    popv(3);
    return nil;
}



/* Code for indexvarordp */

static Lisp_Object CC_indexvarordp(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147, v0145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indexvarordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0005;
/* end of prologue */
    v0147 = stack[-1];
    v0145 = qcar(v0147);
    v0147 = stack[0];
    v0147 = qcar(v0147);
    if (v0145 == v0147) goto v0072;
    v0147 = qvalue(elt(env, 1)); /* t */
    goto v0037;

v0037:
    if (v0147 == nil) goto v0065;
    v0145 = stack[-1];
    v0147 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0145, v0147);
    }

v0065:
    v0147 = stack[-1];
    v0147 = qcdr(v0147);
    fn = elt(env, 6); /* flatindxl */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    v0147 = stack[0];
    v0147 = qcdr(v0147);
    fn = elt(env, 6); /* flatindxl */
    v0145 = (*qfn1(fn))(qenv(fn), v0147);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    v0147 = stack[-2];
    stack[-2] = v0145;
    v0145 = v0147;
    v0147 = qvalue(elt(env, 3)); /* indxl!* */
    fn = elt(env, 7); /* boundindp */
    v0147 = (*qfn2(fn))(qenv(fn), v0145, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    if (v0147 == nil) goto v0004;
    v0145 = stack[-2];
    v0147 = qvalue(elt(env, 3)); /* indxl!* */
    fn = elt(env, 7); /* boundindp */
    v0147 = (*qfn2(fn))(qenv(fn), v0145, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    if (v0147 == nil) goto v0244;
    v0147 = stack[-1];
    v0145 = qcdr(v0147);
    v0147 = stack[0];
    v0147 = qcdr(v0147);
    {
        popv(4);
        fn = elt(env, 8); /* indordlp */
        return (*qfn2(fn))(qenv(fn), v0145, v0147);
    }

v0244:
    v0147 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v0147); }

v0004:
    v0145 = stack[-2];
    v0147 = qvalue(elt(env, 3)); /* indxl!* */
    fn = elt(env, 7); /* boundindp */
    v0147 = (*qfn2(fn))(qenv(fn), v0145, v0147);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-3];
    if (v0147 == nil) goto v0144;
    v0147 = qvalue(elt(env, 4)); /* nil */
    { popv(4); return onevalue(v0147); }

v0144:
    v0145 = stack[-1];
    v0147 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0145, v0147);
    }

v0072:
    v0145 = stack[-1];
    v0147 = qvalue(elt(env, 2)); /* kord!* */
    v0147 = Lmemq(nil, v0145, v0147);
    if (!(v0147 == nil)) goto v0037;
    v0145 = stack[0];
    v0147 = qvalue(elt(env, 2)); /* kord!* */
    v0147 = Lmemq(nil, v0145, v0147);
    goto v0037;
/* error exit handlers */
v0025:
    popv(4);
    return nil;
}



/* Code for gfdot */

static Lisp_Object CC_gfdot(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0071, v0092, v0204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfdot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0092 = v0011;
    v0204 = v0005;
/* end of prologue */
    v0071 = v0204;
    v0071 = qcar(v0071);
    if (!consp(v0071)) goto v0090;
    v0071 = v0204;
    {
        fn = elt(env, 1); /* gbfdot */
        return (*qfn2(fn))(qenv(fn), v0071, v0092);
    }

v0090:
    v0071 = v0204;
    {
        fn = elt(env, 2); /* gffdot */
        return (*qfn2(fn))(qenv(fn), v0071, v0092);
    }
}



/* Code for inttovec */

static Lisp_Object CC_inttovec(Lisp_Object env,
                         Lisp_Object v0005, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inttovec");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0005,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0172 = v0011;
    v0074 = v0005;
/* end of prologue */
    stack[0] = v0172;
    fn = elt(env, 1); /* inttovec!-solve */
    v0074 = (*qfn2(fn))(qenv(fn), v0172, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0063;
    env = stack[-1];
    {
        Lisp_Object v0073 = stack[0];
        popv(2);
        fn = elt(env, 2); /* inttovec1 */
        return (*qfn2(fn))(qenv(fn), v0073, v0074);
    }
/* error exit handlers */
v0063:
    popv(2);
    return nil;
}



/* Code for physopsm!* */

static Lisp_Object CC_physopsmH(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0118, v0260, v0261;
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
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0005;
/* end of prologue */
    stack[0] = nil;
    v0117 = stack[-3];
    if (v0117 == nil) goto v0053;
    v0117 = stack[-3];
    v0117 = (is_number(v0117) ? lisp_true : nil);
    goto v0082;

v0082:
    if (v0117 == nil) goto v0032;
    v0117 = stack[-3];
    stack[0] = v0117;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0032:
    v0117 = stack[-3];
    fn = elt(env, 13); /* physopp */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    if (v0117 == nil) goto v0066;
    v0117 = stack[-3];
    if (!symbolp(v0117)) v0117 = nil;
    else { v0117 = qfastgets(v0117);
           if (v0117 != nil) { v0117 = elt(v0117, 46); /* rvalue */
#ifdef RECORD_GET
             if (v0117 != SPID_NOPROP)
                record_get(elt(fastget_names, 46), 1);
             else record_get(elt(fastget_names, 46), 0),
                v0117 = nil; }
           else record_get(elt(fastget_names, 46), 0); }
#else
             if (v0117 == SPID_NOPROP) v0117 = nil; }}
#endif
    stack[-1] = v0117;
    if (v0117 == nil) goto v0023;
    v0117 = stack[-1];
    fn = elt(env, 14); /* physopaeval */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    goto v0204;

v0204:
    stack[0] = v0117;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0023:
    v0117 = stack[-3];
    if (symbolp(v0117)) goto v0064;
    v0117 = stack[-3];
    v0118 = qcar(v0117);
    v0117 = elt(env, 2); /* psimpfn */
    v0117 = get(v0118, v0117);
    env = stack[-5];
    stack[-1] = v0117;
    if (v0117 == nil) goto v0095;
    v0118 = stack[-1];
    v0117 = stack[-3];
    v0117 = Lapply1(nil, v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    goto v0204;

v0095:
    v0117 = stack[-3];
    v0117 = qcar(v0117);
    if (!symbolp(v0117)) v0117 = nil;
    else { v0117 = qfastgets(v0117);
           if (v0117 != nil) { v0117 = elt(v0117, 9); /* opmtch */
#ifdef RECORD_GET
             if (v0117 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0117 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0117 == SPID_NOPROP) v0117 = nil; }}
#endif
    if (v0117 == nil) goto v0046;
    v0117 = stack[-3];
    fn = elt(env, 15); /* opmtch!* */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    stack[-1] = v0117;
    if (v0117 == nil) goto v0046;
    v0117 = stack[-1];
    goto v0204;

v0046:
    v0117 = stack[-3];
    goto v0204;

v0064:
    v0117 = stack[-3];
    goto v0204;

v0066:
    v0117 = stack[-3];
    if (!consp(v0117)) goto v0019;
    v0117 = stack[-3];
    v0117 = qcar(v0117);
    stack[-4] = v0117;
    v0117 = stack[-3];
    v0117 = qcdr(v0117);
    stack[-2] = v0117;
    v0118 = stack[-4];
    v0117 = elt(env, 3); /* physopfunction */
    v0117 = get(v0118, v0117);
    env = stack[-5];
    stack[-1] = v0117;
    if (v0117 == nil) goto v0159;
    v0118 = stack[-4];
    v0117 = elt(env, 4); /* physoparith */
    v0117 = Lflagp(nil, v0118, v0117);
    env = stack[-5];
    if (v0117 == nil) goto v0143;
    v0117 = stack[-2];
    fn = elt(env, 16); /* hasonephysop */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    if (v0117 == nil) goto v0028;
    stack[0] = stack[-1];
    v0117 = stack[-2];
    v0117 = ncons(v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    fn = elt(env, 17); /* apply */
    v0117 = (*qfn2(fn))(qenv(fn), stack[0], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    stack[0] = v0117;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0028:
    v0118 = stack[-4];
    v0117 = stack[-2];
    v0117 = cons(v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    fn = elt(env, 18); /* reval3 */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    stack[0] = v0117;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0143:
    v0118 = stack[-4];
    v0117 = elt(env, 5); /* physopfn */
    v0117 = Lflagp(nil, v0118, v0117);
    env = stack[-5];
    if (v0117 == nil) goto v0132;
    v0117 = stack[-2];
    fn = elt(env, 19); /* areallphysops */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    if (v0117 == nil) goto v0263;
    stack[0] = stack[-1];
    v0117 = stack[-2];
    v0117 = ncons(v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    fn = elt(env, 17); /* apply */
    v0117 = (*qfn2(fn))(qenv(fn), stack[0], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    stack[0] = v0117;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0263:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v0261 = elt(env, 6); /* "invalid call of " */
    v0260 = stack[-4];
    v0118 = elt(env, 7); /* " with args: " */
    v0117 = stack[-2];
    v0117 = list4(v0261, v0260, v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    fn = elt(env, 20); /* rederr2 */
    v0117 = (*qfn2(fn))(qenv(fn), stack[-1], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0132:
    stack[-1] = elt(env, 0); /* physopsm!* */
    v0260 = stack[-4];
    v0118 = elt(env, 8); /* " has been flagged Physopfunction" */
    v0117 = elt(env, 9); /* " but is not defined" */
    v0117 = list3(v0260, v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    fn = elt(env, 20); /* rederr2 */
    v0117 = (*qfn2(fn))(qenv(fn), stack[-1], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0159:
    v0118 = stack[-4];
    v0117 = elt(env, 10); /* physopmapping */
    v0117 = Lflagp(nil, v0118, v0117);
    env = stack[-5];
    if (v0117 == nil) goto v0264;
    v0117 = stack[-2];
    fn = elt(env, 21); /* !*physopp!* */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    goto v0265;

v0265:
    if (v0117 == nil) goto v0266;
    v0118 = stack[-4];
    v0117 = stack[-2];
    v0118 = cons(v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    v0117 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 22); /* to */
    v0118 = (*qfn2(fn))(qenv(fn), v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    v0117 = (Lisp_Object)17; /* 1 */
    v0117 = cons(v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    v0118 = ncons(v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    v0117 = (Lisp_Object)17; /* 1 */
    v0117 = cons(v0118, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-5];
    fn = elt(env, 23); /* mk!*sq */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    stack[0] = v0117;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0266:
    v0118 = stack[-4];
    v0117 = elt(env, 12); /* prog */
    if (v0118 == v0117) goto v0235;
    v0117 = stack[-3];
    fn = elt(env, 24); /* aeval */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    stack[0] = v0117;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0235:
    v0117 = stack[-2];
    fn = elt(env, 25); /* physopprog */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    stack[0] = v0117;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0264:
    v0117 = qvalue(elt(env, 11)); /* nil */
    goto v0265;

v0019:
    v0117 = stack[-3];
    fn = elt(env, 24); /* aeval */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    stack[0] = v0117;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v0053:
    v0117 = qvalue(elt(env, 1)); /* t */
    goto v0082;
/* error exit handlers */
v0262:
    popv(6);
    return nil;
}



/* Code for factorial */

static Lisp_Object CC_factorial(Lisp_Object env,
                         Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for factorial");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0005;
/* end of prologue */
    v0055 = stack[-1];
    v0055 = integerp(v0055);
    if (v0055 == nil) goto v0037;
    v0054 = stack[-1];
    v0055 = (Lisp_Object)1; /* 0 */
    v0055 = (Lisp_Object)lessp2(v0054, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    v0055 = v0055 ? lisp_true : nil;
    env = stack[-3];
    goto v0084;

v0084:
    if (v0055 == nil) goto v0095;
    stack[-2] = elt(env, 2); /* arith */
    stack[0] = (Lisp_Object)65; /* 4 */
    v0054 = stack[-1];
    v0055 = elt(env, 3); /* "invalid factorial argument" */
    v0055 = list2(v0054, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-3];
    {
        Lisp_Object v0035 = stack[-2];
        Lisp_Object v0173 = stack[0];
        popv(4);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0035, v0173, v0055);
    }

v0095:
    v0055 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* nfactorial */
        return (*qfn1(fn))(qenv(fn), v0055);
    }

v0037:
    v0055 = qvalue(elt(env, 1)); /* t */
    goto v0084;
/* error exit handlers */
v0065:
    popv(4);
    return nil;
}



/* Code for assert_format */

static Lisp_Object MS_CDECL CC_assert_format(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0177, v0178;
    Lisp_Object v0010, v0011, v0005;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "assert_format");
    va_start(aa, nargs);
    v0005 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_format");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0005,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0156 = v0010;
    stack[-8] = v0011;
    stack[-9] = v0005;
/* end of prologue */
    v0156 = Lexplode(nil, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    stack[-10] = v0156;
    stack[-7] = elt(env, 1); /* !! */
    stack[-6] = elt(env, 2); /* !) */
    stack[-5] = elt(env, 1); /* !! */
    stack[-4] = elt(env, 3); /* !  */
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 4); /* !- */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 5); /* !> */
    v0178 = elt(env, 1); /* !! */
    v0177 = elt(env, 3); /* !  */
    v0156 = stack[-10];
    v0156 = list2star(v0178, v0177, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    v0156 = list2star(stack[-1], stack[0], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    v0156 = list2star(stack[-3], stack[-2], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    v0156 = list2star(stack[-5], stack[-4], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    v0156 = list2star(stack[-7], stack[-6], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    stack[-10] = v0156;
    v0156 = stack[-8];
    v0156 = Lreverse(nil, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    stack[-4] = v0156;
    goto v0245;

v0245:
    v0156 = stack[-4];
    if (v0156 == nil) goto v0083;
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 7); /* !, */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 3); /* !  */
    v0177 = Lexplode(nil, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    v0156 = stack[-10];
    v0156 = Lnconc(nil, v0177, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    v0156 = list2star(stack[-1], stack[0], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    v0156 = list2star(stack[-3], stack[-2], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    stack[-10] = v0156;
    v0156 = stack[-4];
    v0156 = qcdr(v0156);
    stack[-4] = v0156;
    goto v0245;

v0083:
    v0156 = stack[-10];
    v0156 = qcdr(v0156);
    v0156 = qcdr(v0156);
    v0156 = qcdr(v0156);
    v0156 = qcdr(v0156);
    stack[-10] = v0156;
    stack[-3] = elt(env, 1); /* !! */
    stack[-2] = elt(env, 8); /* !: */
    stack[-1] = elt(env, 1); /* !! */
    stack[0] = elt(env, 3); /* !  */
    v0178 = elt(env, 1); /* !! */
    v0177 = elt(env, 9); /* !( */
    v0156 = stack[-10];
    v0156 = list2star(v0178, v0177, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    v0156 = list2star(stack[-1], stack[0], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    v0156 = list2star(stack[-3], stack[-2], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    stack[-10] = v0156;
    v0156 = stack[-9];
    v0177 = Lexplode(nil, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    env = stack[-11];
    v0156 = stack[-10];
    v0156 = Lnconc(nil, v0177, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0207;
    stack[-10] = v0156;
    v0156 = stack[-10];
        popv(12);
        return Lcompress(nil, v0156);
/* error exit handlers */
v0207:
    popv(12);
    return nil;
}



/* Code for groeb!=weight */

static Lisp_Object MS_CDECL CC_groebMweight(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073;
    Lisp_Object fn;
    Lisp_Object v0010, v0011, v0005;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groeb=weight");
    va_start(aa, nargs);
    v0005 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=weight");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0010,v0011,v0005);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0005,v0011,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0010;
    stack[-1] = v0011;
    v0073 = v0005;
/* end of prologue */
    fn = elt(env, 1); /* mo_ecart */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    v0073 = stack[-1];
    fn = elt(env, 2); /* bas_dpecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    v0073 = stack[0];
    fn = elt(env, 2); /* bas_dpecart */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-3];
    v0073 = Lmin2(nil, stack[-1], v0073);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    {
        Lisp_Object v0071 = stack[-2];
        popv(4);
        return plus2(v0071, v0073);
    }
/* error exit handlers */
v0072:
    popv(4);
    return nil;
}



setup_type const u19_setup[] =
{
    {"evaluate-mod-p",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluateKmodKp},
    {"crprcd2",                 too_few_2,      CC_crprcd2,    wrong_no_2},
    {"lalr_display_symbols",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_lalr_display_symbols},
    {"ofsf_ignshift",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_ignshift},
    {"sq2sspl",                 too_few_2,      CC_sq2sspl,    wrong_no_2},
    {"cl_qb",                   CC_cl_qb,       too_many_1,    wrong_no_1},
    {"aex_simpleratp",          CC_aex_simpleratp,too_many_1,  wrong_no_1},
    {"mapins",                  too_few_2,      CC_mapins,     wrong_no_2},
    {"exptpri",                 too_few_2,      CC_exptpri,    wrong_no_2},
    {"om2mml",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2mml},
    {"newenv",                  CC_newenv,      too_many_1,    wrong_no_1},
    {"evdif",                   too_few_2,      CC_evdif,      wrong_no_2},
    {":dmpluslst",              CC_Tdmpluslst,  too_many_1,    wrong_no_1},
    {"physop-ordop",            too_few_2,      CC_physopKordop,wrong_no_2},
    {"mktails1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails1},
    {"putd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_putd},
    {"lalr_make_gotos",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_lalr_make_gotos},
    {"rlis",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_rlis},
    {"tmsf",                    CC_tmsf,        too_many_1,    wrong_no_1},
    {"pasf_vf",                 CC_pasf_vf,     too_many_1,    wrong_no_1},
    {"ibalp_negateat",          CC_ibalp_negateat,too_many_1,  wrong_no_1},
    {"**a2s",                   too_few_2,      CC_HHa2s,      wrong_no_2},
    {"merge-ind-vars",          too_few_2,      CC_mergeKindKvars,wrong_no_2},
    {"spquotematrix",           CC_spquotematrix,too_many_1,   wrong_no_1},
    {"vevdif",                  too_few_2,      CC_vevdif,     wrong_no_2},
    {"inttovec1",               too_few_2,      CC_inttovec1,  wrong_no_2},
    {"removeindices",           too_few_2,      CC_removeindices,wrong_no_2},
    {"assert_install",          CC_assert_install,too_many_1,  wrong_no_1},
    {"idcons_ordp",             too_few_2,      CC_idcons_ordp,wrong_no_2},
    {"arplus:",                 too_few_2,      CC_arplusT,    wrong_no_2},
    {"formsetq",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formsetq},
    {"gcref_select",            CC_gcref_select,too_many_1,    wrong_no_1},
    {"ofsf_smupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smupdknowl},
    {"qqe_arg-check",           CC_qqe_argKcheck,too_many_1,   wrong_no_1},
    {"kernord-split",           too_few_2,      CC_kernordKsplit,wrong_no_2},
    {"ibalp_negatet",           CC_ibalp_negatet,too_many_1,   wrong_no_1},
    {"aex_fvarl",               CC_aex_fvarl,   too_many_1,    wrong_no_1},
    {"freeoff",                 too_few_2,      CC_freeoff,    wrong_no_2},
    {"indexvarordp",            too_few_2,      CC_indexvarordp,wrong_no_2},
    {"gfdot",                   too_few_2,      CC_gfdot,      wrong_no_2},
    {"inttovec",                too_few_2,      CC_inttovec,   wrong_no_2},
    {"physopsm*",               CC_physopsmH,   too_many_1,    wrong_no_1},
    {"factorial",               CC_factorial,   too_many_1,    wrong_no_1},
    {"assert_format",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_format},
    {"groeb=weight",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebMweight},
    {NULL, (one_args *)"u19", (two_args *)"181 9445421 9218612", 0}
};

/* end of generated code */
