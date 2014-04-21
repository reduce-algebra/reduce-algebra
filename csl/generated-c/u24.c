
/* $destdir\u24.c        Machine generated C code */

/* Signature: 00000000 21-Apr-2014 */

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
   if (check_stack(__FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
#endif
extern int32_t software_ticks, countdown;
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
extern Lisp_Object used_space, avail_space, eof_symbol;
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
extern int force_reclaim_method, reclaim_trap_count;
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
extern char *CSLtmpnam(char *suffix, int32_t suffixlen);
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
                              size_t n, char *dirn, FILE *old_file);
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
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
             kara_sem2a, kara_sem2b, kara_sem2c;
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


/* Code for in_list1a */

static Lisp_Object MS_CDECL CC_in_list1a(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052, v0053, v0054;
    Lisp_Object fn;
    Lisp_Object v0011, v0014, v0003;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "in_list1a");
    va_start(aa, nargs);
    v0003 = va_arg(aa, Lisp_Object);
    v0014 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for in_list1a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0011,v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0003,v0014,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0011;
    stack[-4] = v0014;
    stack[0] = v0003;
/* end of prologue */
    v0052 = qvalue(elt(env, 1)); /* !*echo */
    stack[-5] = v0052;
    v0052 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v0052 == nil) goto v0055;
    v0052 = stack[0];
    fn = elt(env, 20); /* type */
    v0053 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0052 = elt(env, 3); /* string */
    if (v0053 == v0052) goto v0057;
    v0053 = stack[0];
    v0052 = elt(env, 3); /* string */
    fn = elt(env, 21); /* typerr */
    v0052 = (*qfn2(fn))(qenv(fn), v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    goto v0055;

v0055:
    v0052 = stack[0];
    fn = elt(env, 22); /* mkfil!* */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    stack[0] = v0052;
    v0052 = stack[0];
    v0052 = Lexplodec(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    stack[-2] = v0052;
    v0053 = stack[-2];
    v0052 = elt(env, 4); /* !$ */
    if (!consp(v0053)) goto v0058;
    v0053 = qcar(v0053);
    if (!(v0053 == v0052)) goto v0058;
    v0052 = stack[-2];
    v0053 = qcdr(v0052);
    v0052 = elt(env, 5); /* !/ */
    if (!consp(v0053)) goto v0059;
    v0053 = qcar(v0053);
    if (!(v0053 == v0052)) goto v0059;
    v0052 = qvalue(elt(env, 6)); /* t */
    goto v0060;

v0060:
    if (v0052 == nil) goto v0061;
    v0052 = qvalue(elt(env, 9)); /* ifl!* */
    if (v0052 == nil) goto v0062;
    v0052 = qvalue(elt(env, 9)); /* ifl!* */
    v0052 = qcar(v0052);
    v0052 = Lexplodec(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0052 = Lreverse(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0054 = v0052;
    goto v0063;

v0063:
    v0052 = v0054;
    if (v0052 == nil) goto v0064;
    v0053 = v0054;
    v0052 = elt(env, 5); /* !/ */
    if (!consp(v0053)) goto v0065;
    v0053 = qcar(v0053);
    if (!(v0053 == v0052)) goto v0065;
    v0052 = qvalue(elt(env, 6)); /* t */
    goto v0066;

v0066:
    if (!(v0052 == nil)) goto v0064;
    v0052 = v0054;
    v0052 = qcdr(v0052);
    v0054 = v0052;
    goto v0063;

v0064:
    v0052 = v0054;
    if (!(v0052 == nil)) goto v0067;
    v0052 = elt(env, 13); /* (!/ !.) */
    v0054 = v0052;
    goto v0067;

v0067:
    stack[-1] = elt(env, 10); /* !" */
    v0052 = v0054;
    stack[0] = Lreverse(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0052 = stack[-2];
    v0052 = qcdr(v0052);
    v0053 = qcdr(v0052);
    v0052 = elt(env, 12); /* (!") */
    v0052 = Lappend(nil, v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0052 = Lappend(nil, stack[0], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0052 = cons(stack[-1], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    stack[-2] = v0052;
    v0052 = stack[-2];
    v0052 = Lcompress(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    stack[0] = v0052;
    goto v0061;

v0061:
    v0053 = stack[0];
    v0052 = elt(env, 14); /* input */
    fn = elt(env, 23); /* open */
    v0052 = (*qfn2(fn))(qenv(fn), v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    stack[-2] = v0052;
    v0052 = stack[-2];
    v0052 = Lrds(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    stack[-1] = v0052;
    v0053 = stack[0];
    v0052 = qvalue(elt(env, 15)); /* linelist!* */
    v0052 = Lassoc(nil, v0053, v0052);
    if (!(v0052 == nil)) goto v0068;

v0068:
    v0052 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 16)) = v0052; /* curline!* */
    v0054 = stack[0];
    v0053 = stack[-2];
    v0052 = (Lisp_Object)17; /* 1 */
    v0052 = list3(v0054, v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    qvalue(elt(env, 9)) = v0052; /* ifl!* */
    v0053 = qvalue(elt(env, 9)); /* ifl!* */
    v0052 = qvalue(elt(env, 17)); /* ipl!* */
    v0052 = cons(v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    qvalue(elt(env, 17)) = v0052; /* ipl!* */
    v0052 = stack[-4];
    qvalue(elt(env, 1)) = v0052; /* !*echo */
    v0052 = stack[-3];
    fn = elt(env, 24); /* begin1a */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0052 = stack[-1];
    v0052 = Lrds(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0052 = stack[-2];
    v0052 = Lclose(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0052 = stack[-5];
    qvalue(elt(env, 1)) = v0052; /* !*echo */
    v0052 = qvalue(elt(env, 17)); /* ipl!* */
    if (v0052 == nil) goto v0069;
    v0052 = qvalue(elt(env, 8)); /* nil */
    goto v0070;

v0070:
    if (v0052 == nil) goto v0071;
    v0052 = qvalue(elt(env, 8)); /* nil */
    { popv(7); return onevalue(v0052); }

v0071:
    v0052 = qvalue(elt(env, 17)); /* ipl!* */
    if (v0052 == nil) goto v0072;
    v0053 = stack[0];
    v0052 = qvalue(elt(env, 17)); /* ipl!* */
    v0052 = qcar(v0052);
    v0052 = qcar(v0052);
    v0052 = (v0053 == v0052 ? lisp_true : nil);
    v0052 = (v0052 == nil ? lisp_true : nil);
    goto v0073;

v0073:
    if (v0052 == nil) goto v0074;
    v0054 = elt(env, 19); /* "FILE STACK CONFUSION" */
    v0053 = stack[0];
    v0052 = qvalue(elt(env, 17)); /* ipl!* */
    v0052 = list3(v0054, v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    fn = elt(env, 25); /* rederr */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    goto v0075;

v0075:
    v0052 = nil;
    { popv(7); return onevalue(v0052); }

v0074:
    v0052 = qvalue(elt(env, 17)); /* ipl!* */
    v0052 = qcdr(v0052);
    qvalue(elt(env, 17)) = v0052; /* ipl!* */
    goto v0075;

v0072:
    v0052 = qvalue(elt(env, 6)); /* t */
    goto v0073;

v0069:
    v0052 = qvalue(elt(env, 18)); /* contl!* */
    goto v0070;

v0065:
    v0053 = v0054;
    v0052 = elt(env, 7); /* !\ */
    v0052 = Leqcar(nil, v0053, v0052);
    env = stack[-6];
    goto v0066;

v0062:
    stack[-1] = elt(env, 10); /* !" */
    stack[0] = elt(env, 11); /* !. */
    v0052 = stack[-2];
    v0053 = qcdr(v0052);
    v0052 = elt(env, 12); /* (!") */
    v0052 = Lappend(nil, v0053, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0052 = list2star(stack[-1], stack[0], v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    v0052 = Lcompress(nil, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    stack[0] = v0052;
    goto v0061;

v0059:
    v0052 = stack[-2];
    v0053 = qcdr(v0052);
    v0052 = elt(env, 7); /* !\ */
    v0052 = Leqcar(nil, v0053, v0052);
    env = stack[-6];
    goto v0060;

v0058:
    v0052 = qvalue(elt(env, 8)); /* nil */
    goto v0060;

v0057:
    v0052 = stack[0];
    fn = elt(env, 26); /* value */
    v0052 = (*qfn1(fn))(qenv(fn), v0052);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-6];
    stack[0] = v0052;
    goto v0055;
/* error exit handlers */
v0056:
    popv(7);
    return nil;
}



/* Code for outrefend */

static Lisp_Object CC_outrefend(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0126, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for outrefend");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0003;
/* end of prologue */
    v0125 = qvalue(elt(env, 1)); /* calls!* */
    v0126 = v0125;
    v0125 = v0126;
    if (v0125 == nil) goto v0012;
    stack[-1] = stack[-2];
    stack[0] = elt(env, 2); /* calls */
    v0125 = qvalue(elt(env, 3)); /* toplv!* */
    if (v0125 == nil) goto v0128;
    v0127 = v0126;
    v0126 = stack[-2];
    v0125 = elt(env, 2); /* calls */
    v0125 = get(v0126, v0125);
    env = stack[-4];
    fn = elt(env, 21); /* union */
    v0125 = (*qfn2(fn))(qenv(fn), v0127, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    goto v0130;

v0130:
    v0125 = Lputprop(nil, 3, stack[-1], stack[0], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    goto v0012;

v0012:
    v0125 = qvalue(elt(env, 1)); /* calls!* */
    stack[-1] = v0125;
    goto v0131;

v0131:
    v0125 = stack[-1];
    if (v0125 == nil) goto v0132;
    v0125 = stack[-1];
    v0125 = qcar(v0125);
    stack[0] = v0125;
    v0125 = stack[0];
    v0126 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    v0125 = elt(env, 5); /* cinthis */
    v0125 = Lremflag(nil, v0126, v0125);
    env = stack[-4];
    v0126 = stack[0];
    v0125 = stack[-2];
    if (v0126 == v0125) goto v0133;
    v0126 = stack[0];
    v0125 = elt(env, 6); /* seen */
    v0125 = Lflagp(nil, v0126, v0125);
    env = stack[-4];
    if (!(v0125 == nil)) goto v0134;
    v0125 = stack[0];
    v0126 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    v0125 = elt(env, 6); /* seen */
    v0125 = Lflag(nil, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    v0126 = stack[0];
    v0125 = qvalue(elt(env, 7)); /* seen!* */
    v0125 = cons(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    qvalue(elt(env, 7)) = v0125; /* seen!* */
    goto v0134;

v0134:
    v0127 = stack[0];
    v0126 = elt(env, 8); /* calledby */
    v0125 = stack[-2];
    fn = elt(env, 22); /* traput */
    v0125 = (*qfnn(fn))(qenv(fn), 3, v0127, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    goto v0133;

v0133:
    v0125 = stack[-1];
    v0125 = qcdr(v0125);
    stack[-1] = v0125;
    goto v0131;

v0132:
    v0125 = qvalue(elt(env, 9)); /* globs!* */
    v0126 = v0125;
    v0125 = v0126;
    if (v0125 == nil) goto v0064;
    stack[-1] = stack[-2];
    stack[0] = elt(env, 10); /* globs */
    v0125 = qvalue(elt(env, 3)); /* toplv!* */
    if (v0125 == nil) goto v0135;
    v0127 = v0126;
    v0126 = stack[-2];
    v0125 = elt(env, 10); /* globs */
    v0125 = get(v0126, v0125);
    env = stack[-4];
    fn = elt(env, 21); /* union */
    v0125 = (*qfn2(fn))(qenv(fn), v0127, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    goto v0066;

v0066:
    v0125 = Lputprop(nil, 3, stack[-1], stack[0], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    goto v0064;

v0064:
    v0125 = qvalue(elt(env, 9)); /* globs!* */
    stack[-3] = v0125;
    goto v0136;

v0136:
    v0125 = stack[-3];
    if (v0125 == nil) goto v0137;
    v0125 = stack[-3];
    v0125 = qcar(v0125);
    stack[-1] = v0125;
    stack[0] = stack[-1];
    v0126 = stack[-1];
    v0125 = elt(env, 11); /* dclglb */
    v0125 = Lflagp(nil, v0126, v0125);
    env = stack[-4];
    if (v0125 == nil) goto v0138;
    v0125 = elt(env, 12); /* usedby */
    v0126 = v0125;
    goto v0025;

v0025:
    v0125 = stack[-2];
    fn = elt(env, 22); /* traput */
    v0125 = (*qfnn(fn))(qenv(fn), 3, stack[0], v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    v0125 = stack[-1];
    v0126 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    v0125 = elt(env, 16); /* glb2rf */
    v0125 = Lremflag(nil, v0126, v0125);
    env = stack[-4];
    v0126 = stack[-1];
    v0125 = elt(env, 17); /* glb2bd */
    v0125 = Lflagp(nil, v0126, v0125);
    env = stack[-4];
    if (v0125 == nil) goto v0139;
    v0125 = stack[-1];
    v0126 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    v0125 = elt(env, 17); /* glb2bd */
    v0125 = Lremflag(nil, v0126, v0125);
    env = stack[-4];
    v0127 = stack[-1];
    v0126 = elt(env, 18); /* boundby */
    v0125 = stack[-2];
    fn = elt(env, 22); /* traput */
    v0125 = (*qfnn(fn))(qenv(fn), 3, v0127, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    goto v0139;

v0139:
    v0126 = stack[-1];
    v0125 = elt(env, 19); /* glb2st */
    v0125 = Lflagp(nil, v0126, v0125);
    env = stack[-4];
    if (v0125 == nil) goto v0005;
    v0125 = stack[-1];
    v0126 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    v0125 = elt(env, 19); /* glb2st */
    v0125 = Lremflag(nil, v0126, v0125);
    env = stack[-4];
    v0127 = stack[-1];
    v0126 = elt(env, 20); /* setby */
    v0125 = stack[-2];
    fn = elt(env, 22); /* traput */
    v0125 = (*qfnn(fn))(qenv(fn), 3, v0127, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    goto v0005;

v0005:
    v0125 = stack[-3];
    v0125 = qcdr(v0125);
    stack[-3] = v0125;
    goto v0136;

v0138:
    v0126 = stack[-1];
    v0125 = elt(env, 13); /* gseen */
    v0125 = Lflagp(nil, v0126, v0125);
    env = stack[-4];
    if (!(v0125 == nil)) goto v0140;
    v0126 = stack[-1];
    v0125 = qvalue(elt(env, 14)); /* gseen!* */
    v0125 = cons(v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    qvalue(elt(env, 14)) = v0125; /* gseen!* */
    v0125 = stack[-1];
    v0126 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    v0125 = elt(env, 13); /* gseen */
    v0125 = Lflag(nil, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-4];
    goto v0140;

v0140:
    v0125 = elt(env, 15); /* usedunby */
    v0126 = v0125;
    goto v0025;

v0137:
    v0125 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v0125); }

v0135:
    v0125 = v0126;
    goto v0066;

v0128:
    v0125 = v0126;
    goto v0130;
/* error exit handlers */
v0129:
    popv(5);
    return nil;
}



/* Code for monomdivide */

static Lisp_Object CC_monomdivide(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0063, v0156;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomdivide");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0014;
    stack[-4] = v0003;
/* end of prologue */
    stack[-2] = nil;
    v0064 = (Lisp_Object)17; /* 1 */
    v0064 = Lmkvect(nil, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-6];
    stack[-5] = v0064;
    stack[-1] = stack[-5];
    stack[0] = (Lisp_Object)1; /* 0 */
    v0063 = stack[-4];
    v0064 = (Lisp_Object)1; /* 0 */
    v0156 = *(Lisp_Object *)((char *)v0063 + (CELL-TAG_VECTOR) + ((int32_t)v0064/(16/CELL)));
    v0063 = stack[-3];
    v0064 = (Lisp_Object)1; /* 0 */
    v0064 = *(Lisp_Object *)((char *)v0063 + (CELL-TAG_VECTOR) + ((int32_t)v0064/(16/CELL)));
    v0064 = difference2(v0156, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-6];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0064;
    v0063 = stack[-4];
    v0064 = (Lisp_Object)17; /* 1 */
    v0064 = *(Lisp_Object *)((char *)v0063 + (CELL-TAG_VECTOR) + ((int32_t)v0064/(16/CELL)));
    stack[0] = v0064;
    v0063 = stack[-3];
    v0064 = (Lisp_Object)17; /* 1 */
    v0064 = *(Lisp_Object *)((char *)v0063 + (CELL-TAG_VECTOR) + ((int32_t)v0064/(16/CELL)));
    stack[-1] = v0064;
    goto v0046;

v0046:
    v0064 = stack[0];
    v0064 = qcar(v0064);
    if (v0064 == nil) goto v0157;
    v0064 = stack[0];
    v0063 = qcar(v0064);
    v0064 = stack[-1];
    v0064 = qcar(v0064);
    if (equal(v0063, v0064)) goto v0158;
    v0064 = stack[0];
    v0063 = qcar(v0064);
    v0064 = stack[-2];
    v0064 = cons(v0063, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-6];
    stack[-2] = v0064;
    v0064 = stack[0];
    v0064 = qcdr(v0064);
    stack[0] = v0064;
    goto v0046;

v0158:
    v0064 = stack[0];
    v0064 = qcdr(v0064);
    stack[0] = v0064;
    v0064 = stack[-1];
    v0064 = qcdr(v0064);
    stack[-1] = v0064;
    goto v0046;

v0157:
    v0063 = qvalue(elt(env, 1)); /* nil */
    v0064 = stack[-2];
    v0064 = cons(v0063, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-6];
    stack[-2] = v0064;
    stack[-1] = stack[-5];
    stack[0] = (Lisp_Object)17; /* 1 */
    v0064 = stack[-2];
    v0064 = Lreverse(nil, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0064;
    { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
/* error exit handlers */
v0030:
    popv(7);
    return nil;
}



/* Code for sfto_updecf */

static Lisp_Object CC_sfto_updecf(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0151;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_updecf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0151 = v0003;
/* end of prologue */
    v0119 = qvalue(elt(env, 1)); /* !*sfto_yun */
    if (v0119 == nil) goto v0012;
    v0119 = v0151;
    {
        popv(1);
        fn = elt(env, 4); /* sfto_yun!-updecf */
        return (*qfn1(fn))(qenv(fn), v0119);
    }

v0012:
    v0119 = qvalue(elt(env, 2)); /* !*sfto_musser */
    if (v0119 == nil) goto v0159;
    v0119 = v0151;
    {
        popv(1);
        fn = elt(env, 5); /* sfto_musser!-updecf */
        return (*qfn1(fn))(qenv(fn), v0119);
    }

v0159:
    v0119 = elt(env, 3); /* "sfto_updecf: select a decomposition method" 
*/
    v0119 = ncons(v0119);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0119);
    }
/* error exit handlers */
v0160:
    popv(1);
    return nil;
}



/* Code for vunion */

static Lisp_Object CC_vunion(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0035;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vunion");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0014;
    stack[-2] = v0003;
/* end of prologue */
    v0037 = stack[-2];
    if (v0037 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0037 = stack[-2];
    v0037 = qcar(v0037);
    v0035 = qcar(v0037);
    v0037 = stack[-1];
    v0037 = Lassoc(nil, v0035, v0037);
    stack[-3] = v0037;
    if (v0037 == nil) goto v0168;
    v0037 = stack[-2];
    v0037 = qcar(v0037);
    v0035 = qcdr(v0037);
    v0037 = stack[-3];
    v0037 = qcdr(v0037);
    v0037 = (Lisp_Object)greaterp2(v0035, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    v0037 = v0037 ? lisp_true : nil;
    env = stack[-4];
    if (v0037 == nil) goto v0170;
    v0037 = stack[-2];
    stack[0] = qcar(v0037);
    v0037 = stack[-2];
    stack[-2] = qcdr(v0037);
    v0035 = stack[-3];
    v0037 = stack[-1];
    v0037 = Ldelete(nil, v0035, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0037 = CC_vunion(env, stack[-2], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    {
        Lisp_Object v0171 = stack[0];
        popv(5);
        return cons(v0171, v0037);
    }

v0170:
    stack[0] = stack[-3];
    v0037 = stack[-2];
    stack[-2] = qcdr(v0037);
    v0035 = stack[-3];
    v0037 = stack[-1];
    v0037 = Ldelete(nil, v0035, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    env = stack[-4];
    v0037 = CC_vunion(env, stack[-2], v0037);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    {
        Lisp_Object v0172 = stack[0];
        popv(5);
        return cons(v0172, v0037);
    }

v0168:
    v0037 = stack[-2];
    stack[0] = qcar(v0037);
    v0037 = stack[-2];
    v0035 = qcdr(v0037);
    v0037 = stack[-1];
    v0037 = CC_vunion(env, v0035, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0169;
    {
        Lisp_Object v0038 = stack[0];
        popv(5);
        return cons(v0038, v0037);
    }
/* error exit handlers */
v0169:
    popv(5);
    return nil;
}



/* Code for tayexp!-minus */

static Lisp_Object CC_tayexpKminus(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-minus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0159 = v0003;
/* end of prologue */
    v0055 = v0159;
    if (!consp(v0055)) goto v0010;
    v0055 = v0159;
    {
        fn = elt(env, 1); /* rnminus!: */
        return (*qfn1(fn))(qenv(fn), v0055);
    }

v0010:
    v0055 = v0159;
    return negate(v0055);
}



/* Code for encodeir */

static Lisp_Object CC_encodeir(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0060, v0165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for encodeir");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* char */
    v0060 = elt(env, 2); /* !  */
    v0040 = qvalue(elt(env, 3)); /* atts */
    v0040 = cons(v0060, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    v0040 = Lappend(nil, stack[-1], v0040);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    v0060 = elt(env, 4); /* !$ */
    fn = elt(env, 7); /* delall */
    v0040 = (*qfn2(fn))(qenv(fn), v0060, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    stack[-1] = elt(env, 5); /* semantic */
    v0165 = stack[0];
    v0060 = v0040;
    v0040 = qvalue(elt(env, 6)); /* nil */
    v0040 = list2star(v0165, v0060, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0177;
    env = stack[-2];
    v0060 = qvalue(elt(env, 6)); /* nil */
    {
        Lisp_Object v0110 = stack[-1];
        popv(3);
        return list2star(v0110, v0040, v0060);
    }
/* error exit handlers */
v0177:
    popv(3);
    return nil;
}



/* Code for testchar1 */

static Lisp_Object CC_testchar1(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0150, v0040;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for testchar1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
/* end of prologue */
    v0150 = stack[0];
    v0150 = integerp(v0150);
    if (!(v0150 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0150 = stack[0];
    v0150 = Lexplodec(nil, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-1];
    v0150 = qcdr(v0150);
    if (v0150 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0040 = stack[0];
    v0150 = qvalue(elt(env, 1)); /* nochar!* */
    v0150 = Lmember(nil, v0040, v0150);
    if (!(v0150 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0040 = stack[0];
    v0150 = qvalue(elt(env, 2)); /* nochar1!* */
    v0150 = Lmember(nil, v0040, v0150);
    if (!(v0150 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0040 = stack[0];
    v0150 = qvalue(elt(env, 2)); /* nochar1!* */
    v0150 = cons(v0040, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0165;
    env = stack[-1];
    qvalue(elt(env, 2)) = v0150; /* nochar1!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0165:
    popv(2);
    return nil;
}



/* Code for insertparens */

static Lisp_Object CC_insertparens(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for insertparens");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0118 = v0003;
/* end of prologue */
    stack[-1] = elt(env, 1); /* !( */
    stack[0] = v0118;
    v0118 = elt(env, 2); /* !) */
    v0118 = ncons(v0118);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-2];
    v0118 = Lappend(nil, stack[0], v0118);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    {
        Lisp_Object v0167 = stack[-1];
        popv(3);
        return cons(v0167, v0118);
    }
/* error exit handlers */
v0160:
    popv(3);
    return nil;
}



/* Code for log_inlines */

static Lisp_Object MS_CDECL CC_log_inlines(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0155, v0152;
    Lisp_Object fn;
    Lisp_Object v0011, v0014, v0003;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "log_inlines");
    va_start(aa, nargs);
    v0003 = va_arg(aa, Lisp_Object);
    v0014 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for log_inlines");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0011,v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0003,v0014,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0155 = v0011;
    stack[0] = v0014;
    stack[-1] = v0003;
/* end of prologue */
    v0152 = stack[-1];
    v0155 = stack[0];
    fn = elt(env, 2); /* log_assignment */
    v0155 = (*qfn2(fn))(qenv(fn), v0152, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    if (v0155 == nil) goto v0183;
    v0155 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0155); }

v0183:
    v0152 = stack[-1];
    v0155 = stack[0];
    fn = elt(env, 3); /* log_freevars */
    v0155 = (*qfn2(fn))(qenv(fn), v0152, v0155);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    if (v0155 == nil) goto v0151;
    v0155 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0155); }

v0151:
    v0155 = nil;
    { popv(3); return onevalue(v0155); }
/* error exit handlers */
v0049:
    popv(3);
    return nil;
}



/* Code for splitlist!: */

static Lisp_Object CC_splitlistT(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0154, v0153, v0117;
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
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0003;
/* end of prologue */
    v0117 = nil;
    goto v0013;

v0013:
    v0154 = stack[-1];
    if (v0154 == nil) goto v0180;
    v0154 = stack[-1];
    v0153 = qcar(v0154);
    v0154 = stack[0];
    if (!consp(v0153)) goto v0049;
    v0153 = qcar(v0153);
    if (!(v0153 == v0154)) goto v0049;
    v0154 = stack[-1];
    v0154 = qcar(v0154);
    v0153 = v0117;
    v0154 = cons(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-2];
    v0117 = v0154;
    v0154 = stack[-1];
    v0154 = qcdr(v0154);
    stack[-1] = v0154;
    goto v0013;

v0049:
    v0154 = stack[-1];
    v0154 = qcdr(v0154);
    stack[-1] = v0154;
    goto v0013;

v0180:
    v0154 = v0117;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0154);
    }
/* error exit handlers */
v0131:
    popv(3);
    return nil;
}



/* Code for rl_bestgaussp */

static Lisp_Object CC_rl_bestgaussp(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_bestgaussp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0175 = v0003;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_bestgaussp!* */
    v0175 = ncons(v0175);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    {
        Lisp_Object v0159 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0159, v0175);
    }
/* error exit handlers */
v0055:
    popv(2);
    return nil;
}



/* Code for get!*elements */

static Lisp_Object CC_getHelements(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0159;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get*elements");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0055 = v0003;
/* end of prologue */
    v0159 = elt(env, 1); /* elems */
    return get(v0055, v0159);
}



/* Code for ofsf_xor */

static Lisp_Object CC_ofsf_xor(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0183, v0168, v0051;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_xor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0168 = v0014;
    v0051 = v0003;
/* end of prologue */
    v0183 = v0051;
    if (!(v0183 == nil)) goto v0176;
    v0183 = v0168;
    if (!(v0183 == nil)) goto v0176;
    v0183 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0183);

v0176:
    v0183 = v0051;
    if (v0183 == nil) goto v0181;
    v0183 = v0168;
    goto v0130;

v0130:
    v0183 = (v0183 == nil ? lisp_true : nil);
    return onevalue(v0183);

v0181:
    v0183 = qvalue(elt(env, 1)); /* nil */
    goto v0130;
}



/* Code for termorder */

static Lisp_Object CC_termorder(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0162, v0158, v0185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termorder");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0003;
/* end of prologue */
    v0162 = stack[-1];
    if (v0162 == nil) goto v0029;
    v0162 = stack[-1];
    v0162 = (Lisp_Object)zerop(v0162);
    v0162 = v0162 ? lisp_true : nil;
    env = stack[-3];
    if (v0162 == nil) goto v0159;
    v0162 = stack[0];
    v0162 = (Lisp_Object)zerop(v0162);
    v0162 = v0162 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0162 == nil)) goto v0029;

v0159:
    v0162 = stack[-1];
    v0162 = (Lisp_Object)zerop(v0162);
    v0162 = v0162 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0162 == nil)) goto v0029;
    v0162 = stack[0];
    v0162 = (Lisp_Object)zerop(v0162);
    v0162 = v0162 ? lisp_true : nil;
    env = stack[-3];
    if (!(v0162 == nil)) goto v0029;

v0029:
    v0162 = stack[-1];
    fn = elt(env, 1); /* listsum */
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    stack[-2] = v0162;
    v0162 = stack[0];
    fn = elt(env, 1); /* listsum */
    v0162 = (*qfn1(fn))(qenv(fn), v0162);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    env = stack[-3];
    v0185 = v0162;
    v0158 = stack[-2];
    v0162 = v0185;
    if (equal(v0158, v0162)) goto v0150;
    v0162 = stack[-2];
    v0158 = v0185;
    v0162 = (Lisp_Object)lessp2(v0162, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0114;
    v0162 = v0162 ? lisp_true : nil;
    if (v0162 == nil) goto v0133;
    v0162 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v0162); }

v0133:
    v0162 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0162); }

v0150:
    v0158 = stack[-1];
    v0162 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* termorder1 */
        return (*qfn2(fn))(qenv(fn), v0158, v0162);
    }
/* error exit handlers */
v0114:
    popv(4);
    return nil;
}



/* Code for delhisto */

static Lisp_Object CC_delhisto(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0196, v0068, v0138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delhisto");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0003;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0068 = qvalue(elt(env, 2)); /* maxvar */
    v0196 = stack[-2];
    v0196 = plus2(v0068, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0068 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0196 = (Lisp_Object)1; /* 0 */
    v0196 = *(Lisp_Object *)((char *)v0068 + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    if (v0196 == nil) goto v0012;
    v0068 = stack[-2];
    v0196 = (Lisp_Object)1; /* 0 */
    v0196 = (Lisp_Object)geq2(v0068, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0196 = v0196 ? lisp_true : nil;
    env = stack[-4];
    if (v0196 == nil) goto v0012;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0068 = qvalue(elt(env, 2)); /* maxvar */
    v0196 = stack[-2];
    v0196 = plus2(v0068, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0068 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0196 = (Lisp_Object)113; /* 7 */
    v0196 = *(Lisp_Object *)((char *)v0068 + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0196 = qcar(v0196);
    stack[-3] = v0196;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0068 = qvalue(elt(env, 2)); /* maxvar */
    v0196 = stack[-2];
    v0196 = plus2(v0068, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0068 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0196 = (Lisp_Object)113; /* 7 */
    v0196 = *(Lisp_Object *)((char *)v0068 + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0196 = qcdr(v0196);
    stack[-1] = v0196;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0068 = qvalue(elt(env, 2)); /* maxvar */
    v0196 = stack[-2];
    v0196 = plus2(v0068, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0068 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0196 = (Lisp_Object)17; /* 1 */
    v0196 = *(Lisp_Object *)((char *)v0068 + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0068 = qcdr(v0196);
    v0196 = (Lisp_Object)3201; /* 200 */
    fn = elt(env, 4); /* min */
    v0196 = (*qfn2(fn))(qenv(fn), v0068, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0068 = stack[-3];
    if (v0068 == nil) goto v0135;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0068 = qvalue(elt(env, 2)); /* maxvar */
    v0196 = stack[-3];
    v0196 = plus2(v0068, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0068 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0196 = (Lisp_Object)113; /* 7 */
    v0068 = *(Lisp_Object *)((char *)v0068 + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0196 = stack[-1];
    v0196 = Lrplacd(nil, v0068, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    goto v0197;

v0197:
    v0196 = stack[-1];
    if (v0196 == nil) goto v0198;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0068 = qvalue(elt(env, 2)); /* maxvar */
    v0196 = stack[-1];
    v0196 = plus2(v0068, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-4];
    v0068 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0196 = (Lisp_Object)113; /* 7 */
    v0068 = *(Lisp_Object *)((char *)v0068 + (CELL-TAG_VECTOR) + ((int32_t)v0196/(16/CELL)));
    v0196 = stack[-3];
    v0196 = Lrplaca(nil, v0068, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    goto v0198;

v0198:
    v0196 = nil;
    { popv(5); return onevalue(v0196); }

v0135:
    v0138 = qvalue(elt(env, 3)); /* codhisto */
    v0068 = v0196;
    v0196 = stack[-1];
    *(Lisp_Object *)((char *)v0138 + (CELL-TAG_VECTOR) + ((int32_t)v0068/(16/CELL))) = v0196;
    goto v0197;

v0012:
    v0196 = nil;
    { popv(5); return onevalue(v0196); }
/* error exit handlers */
v0096:
    popv(5);
    return nil;
}



/* Code for dipev2f */

static Lisp_Object CC_dipev2f(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipev2f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0003;
/* end of prologue */

v0012:
    v0115 = stack[-1];
    if (v0115 == nil) goto v0029;
    v0115 = stack[-1];
    v0184 = qcar(v0115);
    v0115 = (Lisp_Object)1; /* 0 */
    if (v0184 == v0115) goto v0176;
    v0115 = stack[0];
    v0184 = qcar(v0115);
    v0115 = stack[-1];
    v0115 = qcar(v0115);
    fn = elt(env, 1); /* to */
    v0184 = (*qfn2(fn))(qenv(fn), v0184, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    v0115 = (Lisp_Object)17; /* 1 */
    v0115 = cons(v0184, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    stack[-2] = ncons(v0115);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    v0115 = stack[-1];
    v0184 = qcdr(v0115);
    v0115 = stack[0];
    v0115 = qcdr(v0115);
    v0115 = CC_dipev2f(env, v0184, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    {
        Lisp_Object v0201 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* multf */
        return (*qfn2(fn))(qenv(fn), v0201, v0115);
    }

v0176:
    v0115 = stack[-1];
    v0115 = qcdr(v0115);
    stack[-1] = v0115;
    v0115 = stack[0];
    v0115 = qcdr(v0115);
    stack[0] = v0115;
    goto v0012;

v0029:
    v0115 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0115); }
/* error exit handlers */
v0200:
    popv(4);
    return nil;
}



/* Code for vdpsave */

static Lisp_Object CC_vdpsave(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object v0121;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdpsave");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0121 = v0003;
/* end of prologue */
    return onevalue(v0121);
}



/* Code for treesizep */

static Lisp_Object CC_treesizep(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for treesizep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0118 = v0014;
    v0119 = v0003;
/* end of prologue */
    fn = elt(env, 1); /* treesizep1 */
    v0119 = (*qfn2(fn))(qenv(fn), v0119, v0118);
    errexit();
    v0118 = (Lisp_Object)1; /* 0 */
    v0118 = (v0119 == v0118 ? lisp_true : nil);
    return onevalue(v0118);
}



/* Code for getphystypecar */

static Lisp_Object CC_getphystypecar(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystypecar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0159 = v0003;
/* end of prologue */
    v0055 = v0159;
    if (!consp(v0055)) goto v0202;
    v0055 = v0159;
    v0055 = qcar(v0055);
    {
        fn = elt(env, 2); /* getphystype */
        return (*qfn1(fn))(qenv(fn), v0055);
    }

v0202:
    v0055 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0055);
}



/* Code for nfactorial */

static Lisp_Object CC_nfactorial(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0047;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nfactorial");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
/* end of prologue */
    v0047 = stack[-1];
    v0203 = (Lisp_Object)321; /* 20 */
    v0203 = (Lisp_Object)greaterp2(v0047, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    v0203 = v0203 ? lisp_true : nil;
    env = stack[-3];
    if (v0203 == nil) goto v0167;
    v0047 = (Lisp_Object)17; /* 1 */
    v0203 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* fac!-part */
        return (*qfn2(fn))(qenv(fn), v0047, v0203);
    }

v0167:
    v0203 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0203;
    v0203 = (Lisp_Object)17; /* 1 */
    stack[0] = v0203;
    goto v0128;

v0128:
    v0047 = stack[-1];
    v0203 = stack[0];
    v0203 = difference2(v0047, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    v0203 = Lminusp(nil, v0203);
    env = stack[-3];
    if (!(v0203 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v0047 = stack[-2];
    v0203 = stack[0];
    v0203 = times2(v0047, v0203);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    stack[-2] = v0203;
    v0203 = stack[0];
    v0203 = add1(v0203);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-3];
    stack[0] = v0203;
    goto v0128;
/* error exit handlers */
v0184:
    popv(4);
    return nil;
}



/* Code for no!-side!-effect!-listp */

static Lisp_Object CC_noKsideKeffectKlistp(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for no-side-effect-listp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
/* end of prologue */

v0204:
    v0179 = stack[0];
    if (v0179 == nil) goto v0010;
    v0179 = stack[0];
    v0179 = qcar(v0179);
    fn = elt(env, 3); /* no!-side!-effectp */
    v0179 = (*qfn1(fn))(qenv(fn), v0179);
    nil = C_nil;
    if (exception_pending()) goto v0168;
    env = stack[-1];
    if (v0179 == nil) goto v0176;
    v0179 = stack[0];
    v0179 = qcdr(v0179);
    stack[0] = v0179;
    goto v0204;

v0176:
    v0179 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0179); }

v0010:
    v0179 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0179); }
/* error exit handlers */
v0168:
    popv(2);
    return nil;
}



/* Code for outrdefun */

static Lisp_Object MS_CDECL CC_outrdefun(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0208, v0025;
    Lisp_Object fn;
    Lisp_Object v0011, v0014, v0003;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "outrdefun");
    va_start(aa, nargs);
    v0003 = va_arg(aa, Lisp_Object);
    v0014 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for outrdefun");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0011,v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0003,v0014,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0014;
    stack[-2] = v0003;
/* end of prologue */
    v0025 = stack[-2];
    v0208 = stack[-1];
    fn = elt(env, 16); /* qtypnm */
    v0208 = (*qfn2(fn))(qenv(fn), v0025, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    stack[-2] = v0208;
    v0025 = stack[-2];
    v0208 = elt(env, 1); /* defd */
    v0208 = Lflagp(nil, v0025, v0208);
    env = stack[-4];
    if (v0208 == nil) goto v0057;
    v0025 = stack[-2];
    v0208 = stack[-1];
    fn = elt(env, 17); /* recref */
    v0208 = (*qfn2(fn))(qenv(fn), v0025, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    goto v0177;

v0177:
    v0025 = stack[-1];
    v0208 = elt(env, 2); /* function */
    v0208 = Lflagp(nil, v0025, v0208);
    env = stack[-4];
    if (v0208 == nil) goto v0042;
    v0025 = stack[-2];
    v0208 = elt(env, 3); /* dclglb */
    v0208 = Lflagp(nil, v0025, v0208);
    env = stack[-4];
    if (v0208 == nil) goto v0163;
    v0208 = qvalue(elt(env, 4)); /* t */
    goto v0060;

v0060:
    if (v0208 == nil) goto v0173;
    v0208 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 18); /* qerline */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    v0208 = elt(env, 7); /* "**** Variable " */
    v0208 = Lprinc(nil, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    v0208 = stack[-2];
    fn = elt(env, 19); /* princng */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    v0208 = elt(env, 8); /* " defined as function" */
    v0208 = Lprinc(nil, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    v0208 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* newline */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    goto v0173;

v0173:
    v0208 = stack[0];
    if (v0208 == nil) goto v0210;
    v0025 = stack[-1];
    v0208 = elt(env, 9); /* naryarg */
    v0208 = Lflagp(nil, v0025, v0208);
    env = stack[-4];
    if (!(v0208 == nil)) goto v0210;
    v0025 = stack[-2];
    v0208 = stack[0];
    fn = elt(env, 21); /* defineargs */
    v0208 = (*qfn2(fn))(qenv(fn), v0025, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    goto v0211;

v0211:
    stack[-3] = stack[-2];
    stack[0] = elt(env, 11); /* gall */
    v0025 = qvalue(elt(env, 12)); /* curlin!* */
    v0208 = stack[-1];
    v0208 = cons(v0025, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    v0208 = Lputprop(nil, 3, stack[-3], stack[0], v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    v0208 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 13)) = v0208; /* globs!* */
    v0208 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 14)) = v0208; /* calls!* */
    v0208 = stack[-2];
    qvalue(elt(env, 15)) = v0208; /* curfun!* */
    { popv(5); return onevalue(v0208); }

v0210:
    v0025 = stack[-1];
    v0208 = elt(env, 9); /* naryarg */
    v0208 = Lflagp(nil, v0025, v0208);
    env = stack[-4];
    if (v0208 == nil) goto v0212;
    v0025 = stack[-2];
    v0208 = elt(env, 10); /* naryargs */
    v0208 = Lflagp(nil, v0025, v0208);
    env = stack[-4];
    v0208 = (v0208 == nil ? lisp_true : nil);
    goto v0156;

v0156:
    if (v0208 == nil) goto v0211;
    v0208 = stack[-2];
    v0025 = ncons(v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    v0208 = elt(env, 10); /* naryargs */
    v0208 = Lflag(nil, v0025, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    goto v0211;

v0212:
    v0208 = qvalue(elt(env, 6)); /* nil */
    goto v0156;

v0163:
    v0025 = stack[-2];
    v0208 = qvalue(elt(env, 5)); /* locls!* */
    v0208 = Lassoc(nil, v0025, v0208);
    goto v0060;

v0042:
    v0208 = qvalue(elt(env, 6)); /* nil */
    goto v0060;

v0057:
    v0208 = stack[-2];
    v0025 = ncons(v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    v0208 = elt(env, 1); /* defd */
    v0208 = Lflag(nil, v0025, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-4];
    goto v0177;
/* error exit handlers */
v0209:
    popv(5);
    return nil;
}



/* Code for cnrd */

static Lisp_Object MS_CDECL CC_cnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0138, v0228, v0229;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cnrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cnrd");
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
/* end of prologue */
    v0228 = qvalue(elt(env, 2)); /* atts */
    v0138 = elt(env, 3); /* type */
    fn = elt(env, 16); /* find */
    v0138 = (*qfn2(fn))(qenv(fn), v0228, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    v0138 = Lintern(nil, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    stack[-1] = v0138;
    v0228 = qvalue(elt(env, 2)); /* atts */
    v0138 = elt(env, 4); /* base */
    fn = elt(env, 16); /* find */
    v0138 = (*qfn2(fn))(qenv(fn), v0228, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    stack[0] = v0138;
    fn = elt(env, 17); /* lex */
    v0138 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    v0138 = qvalue(elt(env, 5)); /* char */
    stack[-4] = v0138;
    fn = elt(env, 17); /* lex */
    v0138 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    v0228 = stack[-1];
    v0138 = elt(env, 6); /* constant */
    if (v0228 == v0138) goto v0123;
    v0138 = stack[-1];
    if (v0138 == nil) goto v0132;
    v0228 = stack[-1];
    v0138 = elt(env, 7); /* (real integer) */
    v0138 = Lmember(nil, v0228, v0138);
    if (v0138 == nil) goto v0134;
    v0138 = stack[0];
    if (v0138 == nil) goto v0184;
    stack[-3] = elt(env, 8); /* based_integer */
    stack[-2] = qvalue(elt(env, 1)); /* nil */
    stack[-1] = stack[0];
    stack[0] = elt(env, 9); /* string */
    v0138 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v0228 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    v0138 = qvalue(elt(env, 1)); /* nil */
    v0228 = list2star(stack[0], v0228, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    v0138 = qvalue(elt(env, 1)); /* nil */
    v0138 = list2star(stack[-1], v0228, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    {
        Lisp_Object v0230 = stack[-3];
        Lisp_Object v0231 = stack[-2];
        popv(6);
        return list2star(v0230, v0231, v0138);
    }

v0184:
    v0138 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v0138);
    }

v0134:
    v0138 = stack[-1];
    v0228 = Lintern(nil, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    v0138 = elt(env, 10); /* (rational complex!-cartesian complex!-polar) 
*/
    v0138 = Lmember(nil, v0228, v0138);
    if (v0138 == nil) goto v0037;
    fn = elt(env, 19); /* seprd */
    v0138 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    stack[-2] = v0138;
    v0228 = stack[-1];
    v0138 = elt(env, 11); /* rational */
    if (v0228 == v0138) goto v0143;
    v0228 = stack[-1];
    v0138 = elt(env, 12); /* complex!-cartesian */
    if (v0228 == v0138) goto v0232;
    v0228 = stack[-1];
    v0138 = elt(env, 14); /* complex!-polar */
    if (!(v0228 == v0138)) goto v0037;
    fn = elt(env, 17); /* lex */
    v0138 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    stack[-1] = elt(env, 15); /* complex_polar */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v0138 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v0229 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    v0228 = stack[-2];
    v0138 = qvalue(elt(env, 1)); /* nil */
    v0138 = list2star(v0229, v0228, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    {
        Lisp_Object v0233 = stack[-1];
        Lisp_Object v0234 = stack[0];
        popv(6);
        return list2star(v0233, v0234, v0138);
    }

v0037:
    v0138 = nil;
    { popv(6); return onevalue(v0138); }

v0232:
    fn = elt(env, 17); /* lex */
    v0138 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    stack[-1] = elt(env, 13); /* complex_cartesian */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v0138 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v0229 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    v0228 = stack[-2];
    v0138 = qvalue(elt(env, 1)); /* nil */
    v0138 = list2star(v0229, v0228, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    {
        Lisp_Object v0094 = stack[-1];
        Lisp_Object v0095 = stack[0];
        popv(6);
        return list2star(v0094, v0095, v0138);
    }

v0143:
    fn = elt(env, 17); /* lex */
    v0138 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    v0138 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v0228 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-5];
    v0138 = stack[-2];
    {
        popv(6);
        fn = elt(env, 11); /* rational */
        return (*qfn2(fn))(qenv(fn), v0228, v0138);
    }

v0132:
    v0138 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v0138);
    }

v0123:
    v0138 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v0138);
    }
/* error exit handlers */
v0019:
    popv(6);
    return nil;
}



/* Code for ordexp */

static Lisp_Object CC_ordexp(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0060, v0165, v0199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordexp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0060 = v0014;
    v0165 = v0003;
/* end of prologue */

v0012:
    v0040 = v0165;
    if (v0040 == nil) goto v0029;
    v0040 = v0165;
    v0199 = qcar(v0040);
    v0040 = v0060;
    v0040 = qcar(v0040);
    if (v0199 == v0040) goto v0176;
    v0040 = v0165;
    v0040 = qcar(v0040);
    if (v0040 == nil) goto v0174;
    v0040 = v0060;
    v0040 = qcar(v0040);
    if (v0040 == nil) goto v0155;
    v0040 = v0165;
    v0040 = qcar(v0040);
    v0060 = qcar(v0060);
    {
        fn = elt(env, 3); /* ordop */
        return (*qfn2(fn))(qenv(fn), v0040, v0060);
    }

v0155:
    v0040 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0040);

v0174:
    v0040 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0040);

v0176:
    v0040 = v0165;
    v0040 = qcdr(v0040);
    v0165 = v0040;
    v0040 = v0060;
    v0040 = qcdr(v0040);
    v0060 = v0040;
    goto v0012;

v0029:
    v0040 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0040);
}



/* Code for gbfdot */

static Lisp_Object CC_gbfdot(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0122;
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
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0003;
/* end of prologue */
    v0182 = stack[-1];
    v0122 = qcar(v0182);
    v0182 = stack[0];
    v0182 = qcar(v0182);
    fn = elt(env, 1); /* csl_timbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0122, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    v0182 = stack[-1];
    v0122 = qcdr(v0182);
    v0182 = stack[0];
    v0182 = qcdr(v0182);
    fn = elt(env, 1); /* csl_timbf */
    v0182 = (*qfn2(fn))(qenv(fn), v0122, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0178;
    env = stack[-3];
    {
        Lisp_Object v0048 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* plubf */
        return (*qfn2(fn))(qenv(fn), v0048, v0182);
    }
/* error exit handlers */
v0178:
    popv(4);
    return nil;
}



/* Code for evaluate!-horner */

static Lisp_Object CC_evaluateKhorner(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0150, v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate-horner");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
/* end of prologue */
    v0150 = stack[-1];
    v0149 = qvalue(elt(env, 1)); /* horner!-cache!* */
    v0149 = Lassoc(nil, v0150, v0149);
    stack[-2] = v0149;
    v0149 = stack[-2];
    if (v0149 == nil) goto v0118;
    v0149 = stack[-2];
    v0149 = qcdr(v0149);
    { popv(4); return onevalue(v0149); }

v0118:
    v0149 = stack[-1];
    fn = elt(env, 2); /* simp!* */
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    stack[-2] = v0149;
    v0149 = stack[-2];
    v0149 = qcar(v0149);
    fn = elt(env, 3); /* hornerf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    v0149 = stack[-2];
    v0149 = qcdr(v0149);
    fn = elt(env, 3); /* hornerf */
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    v0149 = cons(stack[0], v0149);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    fn = elt(env, 4); /* prepsq */
    v0149 = (*qfn1(fn))(qenv(fn), v0149);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    stack[-2] = v0149;
    v0040 = stack[-1];
    v0150 = stack[-2];
    v0149 = qvalue(elt(env, 1)); /* horner!-cache!* */
    v0149 = acons(v0040, v0150, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0166;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0149; /* horner!-cache!* */
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v0166:
    popv(4);
    return nil;
}



/* Code for getphystypeor */

static Lisp_Object CC_getphystypeor(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystypeor");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
/* end of prologue */

v0204:
    v0119 = stack[0];
    if (!consp(v0119)) goto v0181;
    v0119 = stack[0];
    v0119 = qcar(v0119);
    fn = elt(env, 2); /* getphystype */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-1];
    if (!(v0119 == nil)) { popv(2); return onevalue(v0119); }
    v0119 = stack[0];
    v0119 = qcdr(v0119);
    stack[0] = v0119;
    goto v0204;

v0181:
    v0119 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0119); }
/* error exit handlers */
v0160:
    popv(2);
    return nil;
}



/* Code for gcdout */

static Lisp_Object CC_gcdout(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0112, v0224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcdout");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
/* end of prologue */
    v0058 = qvalue(elt(env, 1)); /* !*modular */
    if (!(v0058 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0058 = stack[0];
    if (v0058 == nil) goto v0029;
    v0058 = stack[0];
    fn = elt(env, 3); /* ljet */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    fn = elt(env, 4); /* ord */
    v0112 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    v0058 = (Lisp_Object)1; /* 0 */
    if (v0112 == v0058) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0058 = stack[0];
    stack[-1] = v0058;
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcdr(v0058);
    v0224 = v0058;
    goto v0049;

v0049:
    v0058 = stack[-1];
    if (v0058 == nil) goto v0201;
    v0112 = v0224;
    v0058 = (Lisp_Object)17; /* 1 */
    if (v0112 == v0058) goto v0201;
    v0112 = v0224;
    v0058 = stack[-1];
    v0058 = qcar(v0058);
    v0058 = qcdr(v0058);
    fn = elt(env, 5); /* gcdf!* */
    v0058 = (*qfn2(fn))(qenv(fn), v0112, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-2];
    v0224 = v0058;
    v0058 = stack[-1];
    v0058 = qcdr(v0058);
    stack[-1] = v0058;
    goto v0049;

v0201:
    v0112 = v0224;
    v0058 = (Lisp_Object)17; /* 1 */
    if (v0112 == v0058) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0058 = stack[0];
    v0112 = v0224;
    {
        popv(3);
        fn = elt(env, 6); /* pcdiv */
        return (*qfn2(fn))(qenv(fn), v0058, v0112);
    }

v0029:
    v0058 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0058); }
/* error exit handlers */
v0236:
    popv(3);
    return nil;
}



/* Code for ad_numsort */

static Lisp_Object CC_ad_numsort(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0202, v0175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ad_numsort");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0202 = v0003;
/* end of prologue */
    v0175 = v0202;
    v0202 = elt(env, 1); /* lambda_n4e0tk_4 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v0175, v0202);
    }
}



/* Code for lambda_n4e0tk_4 */

static Lisp_Object CC_lambda_n4e0tk_4(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0175, v0176;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_n4e0tk_4");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0175 = v0014;
    v0176 = v0003;
/* end of prologue */
        return Lleq(nil, v0176, v0175);
}



/* Code for safe!-modrecip */

static Lisp_Object CC_safeKmodrecip(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0166, v0177, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for safe-modrecip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0177 = v0003;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* !*msg */
    qvalue(elt(env, 1)) = nil; /* !*msg */
    stack[0] = qvalue(elt(env, 2)); /* !*protfg */
    qvalue(elt(env, 2)) = nil; /* !*protfg */
    v0166 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v0166; /* !*msg */
    v0166 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v0166; /* !*protfg */
    v0110 = v0177;
    v0166 = elt(env, 5); /* !:mod!: */
    if (!consp(v0110)) goto v0155;
    v0110 = qcar(v0110);
    if (!(v0110 == v0166)) goto v0155;
    v0166 = v0177;
    v0166 = qcdr(v0166);
    v0177 = v0166;
    goto v0155;

v0155:
    v0166 = elt(env, 6); /* general!-modular!-reciprocal */
    v0110 = list2(v0166, v0177);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    v0177 = qvalue(elt(env, 3)); /* nil */
    v0166 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* errorset */
    v0166 = (*qfnn(fn))(qenv(fn), 3, v0110, v0177, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    stack[-2] = v0166;
    v0166 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 7)) = v0166; /* erfg!* */
    v0166 = stack[-2];
    fn = elt(env, 9); /* errorp */
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    if (v0166 == nil) goto v0040;
    v0166 = qvalue(elt(env, 3)); /* nil */
    goto v0013;

v0013:
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    { popv(4); return onevalue(v0166); }

v0040:
    v0166 = stack[-2];
    v0166 = qcar(v0166);
    goto v0013;
/* error exit handlers */
v0047:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    popv(4);
    return nil;
}



/* Code for horner!-rule!-for!-one!-var */

static Lisp_Object MS_CDECL CC_hornerKruleKforKoneKvar(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0240, v0212, v0217, v0218, v0065, v0105;
    Lisp_Object fn;
    Lisp_Object v0010, v0121, v0011, v0014, v0003;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-for-one-var");
    va_start(aa, nargs);
    v0003 = va_arg(aa, Lisp_Object);
    v0014 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0121 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for horner-rule-for-one-var");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0010,v0121,v0011,v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0003,v0014,v0011,v0121,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v0240 = v0010;
    v0212 = v0121;
    v0217 = v0011;
    v0218 = v0014;
    v0065 = v0003;
/* end of prologue */

v0204:
    v0033 = v0065;
    if (!consp(v0033)) goto v0181;
    v0033 = v0065;
    v0033 = qcar(v0033);
    v0033 = (consp(v0033) ? nil : lisp_true);
    goto v0130;

v0130:
    if (v0033 == nil) goto v0050;
    v0033 = qvalue(elt(env, 1)); /* t */
    goto v0175;

v0175:
    if (v0033 == nil) goto v0045;
    v0033 = v0217;
    v0033 = (Lisp_Object)zerop(v0033);
    v0033 = v0033 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0033 == nil)) { popv(7); return onevalue(v0065); }
    stack[-1] = v0065;
    stack[0] = v0212;
    v0033 = v0217;
    v0033 = Lexpt(nil, v0033, v0240);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-6];
    fn = elt(env, 2); /* !*n2f */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-6];
    fn = elt(env, 3); /* multf */
    v0033 = (*qfn2(fn))(qenv(fn), stack[0], v0033);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-6];
    {
        Lisp_Object v0135 = stack[-1];
        popv(7);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v0135, v0033);
    }

v0045:
    v0033 = v0065;
    v0033 = qcar(v0033);
    v0033 = qcar(v0033);
    v0033 = qcdr(v0033);
    stack[-5] = v0033;
    v0033 = v0065;
    stack[-4] = qcdr(v0033);
    stack[-3] = v0218;
    stack[-2] = v0217;
    v0033 = v0217;
    v0033 = (Lisp_Object)zerop(v0033);
    v0033 = v0033 ? lisp_true : nil;
    env = stack[-6];
    if (v0033 == nil) goto v0169;
    v0033 = v0065;
    v0033 = qcar(v0033);
    v0033 = qcdr(v0033);
    v0240 = v0033;
    goto v0241;

v0241:
    v0033 = stack[-5];
    v0065 = stack[-4];
    v0218 = stack[-3];
    v0217 = stack[-2];
    v0212 = v0240;
    v0240 = v0033;
    goto v0204;

v0169:
    v0033 = v0065;
    v0033 = qcar(v0033);
    stack[-1] = qcdr(v0033);
    stack[0] = v0212;
    v0212 = v0217;
    v0033 = stack[-5];
    v0033 = (Lisp_Object)(int32_t)((int32_t)v0240 - (int32_t)v0033 + TAG_FIXNUM);
    v0033 = Lexpt(nil, v0212, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-6];
    fn = elt(env, 2); /* !*n2f */
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-6];
    fn = elt(env, 3); /* multf */
    v0033 = (*qfn2(fn))(qenv(fn), stack[0], v0033);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-6];
    fn = elt(env, 4); /* addf */
    v0033 = (*qfn2(fn))(qenv(fn), stack[-1], v0033);
    nil = C_nil;
    if (exception_pending()) goto v0107;
    env = stack[-6];
    v0240 = v0033;
    goto v0241;

v0050:
    v0033 = v0065;
    v0033 = qcar(v0033);
    v0033 = qcar(v0033);
    v0105 = qcar(v0033);
    v0033 = v0218;
    v0033 = (equal(v0105, v0033) ? lisp_true : nil);
    v0033 = (v0033 == nil ? lisp_true : nil);
    goto v0175;

v0181:
    v0033 = qvalue(elt(env, 1)); /* t */
    goto v0130;
/* error exit handlers */
v0107:
    popv(7);
    return nil;
}



/* Code for add2locs */

static Lisp_Object CC_add2locs(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0212, v0217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for add2locs");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0217 = v0003;
/* end of prologue */
    v0212 = qvalue(elt(env, 1)); /* !*globals */
    if (v0212 == nil) goto v0013;
    v0212 = v0217;
    stack[-2] = v0212;
    goto v0055;

v0055:
    v0212 = stack[-2];
    if (v0212 == nil) goto v0013;
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    stack[-1] = v0212;
    v0217 = stack[-1];
    v0212 = qvalue(elt(env, 3)); /* locls!* */
    v0212 = Lassoc(nil, v0217, v0212);
    stack[-3] = v0212;
    v0212 = stack[-3];
    if (v0212 == nil) goto v0164;
    v0217 = stack[-1];
    v0212 = elt(env, 4); /* dclglb */
    v0212 = Lflagp(nil, v0217, v0212);
    env = stack[-4];
    if (v0212 == nil) goto v0164;
    v0212 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 13); /* qerline */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = elt(env, 5); /* "*** Variable " */
    v0212 = Lprinc(nil, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = stack[-1];
    v0212 = Lprin(nil, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = elt(env, 6); /* " nested declaration in " */
    v0212 = Lprinc(nil, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = qvalue(elt(env, 7)); /* curfun!* */
    fn = elt(env, 14); /* princng */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* newline */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[0] = stack[-3];
    v0217 = qvalue(elt(env, 2)); /* nil */
    v0212 = stack[-3];
    v0212 = cons(v0217, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = Lrplacd(nil, stack[0], v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    goto v0227;

v0227:
    v0217 = stack[-1];
    v0212 = elt(env, 4); /* dclglb */
    v0212 = Lflagp(nil, v0217, v0212);
    env = stack[-4];
    if (v0212 == nil) goto v0145;
    v0212 = qvalue(elt(env, 8)); /* t */
    goto v0245;

v0245:
    if (v0212 == nil) goto v0063;
    v0212 = stack[-1];
    fn = elt(env, 16); /* globind */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    goto v0063;

v0063:
    v0217 = stack[-1];
    v0212 = elt(env, 10); /* seen */
    v0212 = Lflagp(nil, v0217, v0212);
    env = stack[-4];
    if (v0212 == nil) goto v0143;
    v0212 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 13); /* qerline */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = elt(env, 11); /* "*** Function " */
    v0212 = Lprinc(nil, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = stack[-1];
    fn = elt(env, 14); /* princng */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = elt(env, 12); /* " used as variable in " */
    v0212 = Lprinc(nil, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = qvalue(elt(env, 7)); /* curfun!* */
    fn = elt(env, 14); /* princng */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 15); /* newline */
    v0212 = (*qfn1(fn))(qenv(fn), v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    goto v0143;

v0143:
    v0212 = stack[-2];
    v0212 = qcdr(v0212);
    stack[-2] = v0212;
    goto v0055;

v0145:
    v0217 = stack[-1];
    v0212 = elt(env, 9); /* glb2rf */
    v0212 = Lflagp(nil, v0217, v0212);
    env = stack[-4];
    goto v0245;

v0164:
    stack[0] = stack[-1];
    v0212 = qvalue(elt(env, 2)); /* nil */
    v0217 = ncons(v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0212 = qvalue(elt(env, 3)); /* locls!* */
    v0212 = acons(stack[0], v0217, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    qvalue(elt(env, 3)) = v0212; /* locls!* */
    goto v0227;

v0013:
    v0212 = nil;
    { popv(5); return onevalue(v0212); }
/* error exit handlers */
v0192:
    popv(5);
    return nil;
}



/* Code for rl_qefsolset */

static Lisp_Object MS_CDECL CC_rl_qefsolset(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0178, v0048, v0049, v0057, v0124;
    Lisp_Object fn;
    Lisp_Object v0010, v0121, v0011, v0014, v0003;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rl_qefsolset");
    va_start(aa, nargs);
    v0003 = va_arg(aa, Lisp_Object);
    v0014 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0121 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_qefsolset");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0010,v0121,v0011,v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0003,v0014,v0011,v0121,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0178 = v0010;
    v0048 = v0121;
    v0049 = v0011;
    v0057 = v0014;
    v0124 = v0003;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* rl_qefsolset!* */
    stack[-2] = v0124;
    stack[-1] = v0057;
    stack[0] = v0049;
    v0178 = list2(v0048, v0178);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-4];
    v0178 = list3star(stack[-2], stack[-1], stack[0], v0178);
    nil = C_nil;
    if (exception_pending()) goto v0235;
    env = stack[-4];
    {
        Lisp_Object v0132 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0132, v0178);
    }
/* error exit handlers */
v0235:
    popv(5);
    return nil;
}



/* Code for super_der_simp */

static Lisp_Object CC_super_der_simp(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0294, v0295, v0296;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for super_der_simp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0003;
/* end of prologue */
    v0294 = stack[-9];
    v0295 = Llength(nil, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = (Lisp_Object)33; /* 2 */
    if (v0295 == v0294) goto v0010;
    v0294 = stack[-9];
    {
        popv(12);
        fn = elt(env, 7); /* simpiden */
        return (*qfn1(fn))(qenv(fn), v0294);
    }

v0010:
    v0294 = stack[-9];
    v0294 = qcar(v0294);
    fn = elt(env, 8); /* reval */
    v0294 = (*qfn1(fn))(qenv(fn), v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-10] = v0294;
    v0295 = stack[-10];
    v0294 = elt(env, 1); /* variables */
    v0294 = get(v0295, v0294);
    env = stack[-11];
    stack[-8] = v0294;
    v0294 = stack[-9];
    v0294 = qcdr(v0294);
    v0294 = qcar(v0294);
    fn = elt(env, 9); /* simp!* */
    v0294 = (*qfn1(fn))(qenv(fn), v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-9] = v0294;
    v0294 = stack[-9];
    v0295 = qcar(v0294);
    v0294 = elt(env, 2); /* (ext) */
    fn = elt(env, 10); /* split_form */
    v0294 = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-7] = v0294;
    v0294 = elt(env, 3); /* ext */
    v0296 = ncons(v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = stack[-7];
    v0295 = qcar(v0294);
    v0294 = stack[-7];
    v0294 = qcdr(v0294);
    v0294 = acons(v0296, v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-7] = v0294;
    v0294 = stack[-9];
    v0295 = qcdr(v0294);
    v0294 = elt(env, 2); /* (ext) */
    fn = elt(env, 10); /* split_form */
    v0294 = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-6] = v0294;
    v0294 = elt(env, 3); /* ext */
    v0296 = ncons(v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = stack[-6];
    v0295 = qcar(v0294);
    v0294 = stack[-6];
    v0294 = qcdr(v0294);
    v0294 = acons(v0296, v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-6] = v0294;
    v0294 = (Lisp_Object)17; /* 1 */
    stack[-5] = v0294;
    v0295 = stack[-10];
    v0294 = elt(env, 4); /* even_dimension */
    v0295 = get(v0295, v0294);
    env = stack[-11];
    v0294 = stack[-5];
    v0294 = difference2(v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = Lminusp(nil, v0294);
    env = stack[-11];
    if (v0294 == nil) goto v0108;
    v0294 = qvalue(elt(env, 5)); /* nil */
    goto v0112;

v0112:
    stack[-5] = v0294;
    v0294 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0294;
    v0295 = stack[-10];
    v0294 = elt(env, 6); /* odd_dimension */
    v0295 = get(v0295, v0294);
    env = stack[-11];
    v0294 = stack[-4];
    v0294 = difference2(v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = Lminusp(nil, v0294);
    env = stack[-11];
    if (v0294 == nil) goto v0069;
    v0294 = qvalue(elt(env, 5)); /* nil */
    goto v0298;

v0298:
    stack[-1] = v0294;
    v0295 = stack[-5];
    v0294 = stack[-7];
    fn = elt(env, 11); /* even_action */
    stack[0] = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0295 = stack[-1];
    v0294 = stack[-7];
    fn = elt(env, 12); /* odd_action */
    v0294 = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    fn = elt(env, 13); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = stack[-9];
    v0295 = qcdr(v0294);
    v0294 = (Lisp_Object)17; /* 1 */
    v0294 = cons(v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    fn = elt(env, 14); /* quotsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0295 = stack[-5];
    v0294 = stack[-6];
    fn = elt(env, 11); /* even_action */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = stack[-9];
    v0295 = qcar(v0294);
    v0294 = (Lisp_Object)17; /* 1 */
    v0294 = cons(v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    fn = elt(env, 15); /* super_product_sq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = stack[-9];
    v0295 = qcdr(v0294);
    v0294 = stack[-9];
    v0294 = qcdr(v0294);
    fn = elt(env, 16); /* multf */
    v0295 = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = (Lisp_Object)17; /* 1 */
    v0294 = cons(v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    fn = elt(env, 14); /* quotsq */
    v0294 = (*qfn2(fn))(qenv(fn), stack[-1], v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    fn = elt(env, 17); /* negsq */
    v0294 = (*qfn1(fn))(qenv(fn), v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    {
        Lisp_Object v0299 = stack[0];
        popv(12);
        fn = elt(env, 13); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0299, v0294);
    }

v0069:
    v0296 = stack[-10];
    v0295 = (Lisp_Object)17; /* 1 */
    v0294 = stack[-4];
    v0294 = list3(v0296, v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v0294 = (*qfn1(fn))(qenv(fn), v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[0] = stack[-4];
    v0295 = v0294;
    v0294 = elt(env, 2); /* (ext) */
    fn = elt(env, 18); /* split_ext */
    v0294 = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = cons(stack[0], v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = ncons(v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-2] = v0294;
    stack[-3] = v0294;
    goto v0300;

v0300:
    v0294 = stack[-4];
    v0294 = add1(v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-4] = v0294;
    v0295 = stack[-10];
    v0294 = elt(env, 6); /* odd_dimension */
    v0295 = get(v0295, v0294);
    env = stack[-11];
    v0294 = stack[-4];
    v0294 = difference2(v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = Lminusp(nil, v0294);
    env = stack[-11];
    if (v0294 == nil) goto v0301;
    v0294 = stack[-3];
    goto v0298;

v0301:
    stack[-1] = stack[-2];
    v0296 = stack[-10];
    v0295 = (Lisp_Object)17; /* 1 */
    v0294 = stack[-4];
    v0294 = list3(v0296, v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v0294 = (*qfn1(fn))(qenv(fn), v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[0] = stack[-4];
    v0295 = v0294;
    v0294 = elt(env, 2); /* (ext) */
    fn = elt(env, 18); /* split_ext */
    v0294 = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = cons(stack[0], v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = ncons(v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = Lrplacd(nil, stack[-1], v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = stack[-2];
    v0294 = qcdr(v0294);
    stack[-2] = v0294;
    goto v0300;

v0108:
    v0296 = stack[-10];
    v0295 = (Lisp_Object)1; /* 0 */
    v0294 = stack[-5];
    v0294 = list3(v0296, v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v0294 = (*qfn1(fn))(qenv(fn), v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-1] = v0294;
    v0295 = stack[-8];
    v0294 = stack[-5];
    fn = elt(env, 19); /* nth */
    stack[0] = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0295 = stack[-1];
    v0294 = elt(env, 2); /* (ext) */
    fn = elt(env, 18); /* split_ext */
    v0294 = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = cons(stack[0], v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = ncons(v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-3] = v0294;
    stack[-4] = v0294;
    goto v0224;

v0224:
    v0294 = stack[-5];
    v0294 = add1(v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-5] = v0294;
    v0295 = stack[-10];
    v0294 = elt(env, 4); /* even_dimension */
    v0295 = get(v0295, v0294);
    env = stack[-11];
    v0294 = stack[-5];
    v0294 = difference2(v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = Lminusp(nil, v0294);
    env = stack[-11];
    if (v0294 == nil) goto v0079;
    v0294 = stack[-4];
    goto v0112;

v0079:
    stack[-2] = stack[-3];
    v0296 = stack[-10];
    v0295 = (Lisp_Object)1; /* 0 */
    v0294 = stack[-5];
    v0294 = list3(v0296, v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    fn = elt(env, 9); /* simp!* */
    v0294 = (*qfn1(fn))(qenv(fn), v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    stack[-1] = v0294;
    v0295 = stack[-8];
    v0294 = stack[-5];
    fn = elt(env, 19); /* nth */
    stack[0] = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0295 = stack[-1];
    v0294 = elt(env, 2); /* (ext) */
    fn = elt(env, 18); /* split_ext */
    v0294 = (*qfn2(fn))(qenv(fn), v0295, v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = cons(stack[0], v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = ncons(v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = Lrplacd(nil, stack[-2], v0294);
    nil = C_nil;
    if (exception_pending()) goto v0297;
    env = stack[-11];
    v0294 = stack[-3];
    v0294 = qcdr(v0294);
    stack[-3] = v0294;
    goto v0224;
/* error exit handlers */
v0297:
    popv(12);
    return nil;
}



/* Code for get!-free!-form */

static Lisp_Object CC_getKfreeKform(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164, v0059, v0222;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get-free-form");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0003;
/* end of prologue */
    stack[-2] = nil;
    v0059 = stack[-1];
    v0164 = qvalue(elt(env, 1)); /* frasc!* */
    v0164 = Latsoc(nil, v0059, v0164);
    stack[0] = v0164;
    if (v0164 == nil) goto v0168;
    v0164 = stack[0];
    v0164 = qcdr(v0164);
    { popv(4); return onevalue(v0164); }

v0168:
    v0059 = stack[-1];
    v0164 = elt(env, 2); /* !~ */
    if (!consp(v0059)) goto v0057;
    v0059 = qcar(v0059);
    if (!(v0059 == v0164)) goto v0057;
    v0164 = stack[-1];
    v0164 = qcdr(v0164);
    v0164 = qcar(v0164);
    stack[-1] = v0164;
    v0164 = elt(env, 3); /* (!! !~ !! !~) */
    stack[0] = v0164;
    v0164 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v0164;
    goto v0131;

v0131:
    v0164 = stack[-1];
    v0164 = Lexplode(nil, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-3];
    v0164 = Lappend(nil, stack[0], v0164);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-3];
    v0164 = Lcompress(nil, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-3];
    v0164 = Lintern(nil, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-3];
    stack[0] = v0164;
    v0222 = stack[-1];
    v0059 = stack[0];
    v0164 = qvalue(elt(env, 1)); /* frasc!* */
    v0164 = acons(v0222, v0059, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0164; /* frasc!* */
    v0164 = stack[-2];
    if (v0164 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0164 = stack[0];
    v0059 = ncons(v0164);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-3];
    v0164 = elt(env, 6); /* optional */
    v0164 = Lflag(nil, v0059, v0164);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v0057:
    v0164 = elt(env, 5); /* (!! !~) */
    stack[0] = v0164;
    goto v0131;
/* error exit handlers */
v0195:
    popv(4);
    return nil;
}



/* Code for mk!+unit!+mat */

static Lisp_Object CC_mkLunitLmat(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+unit+mat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0013 = v0003;
/* end of prologue */
    {
        fn = elt(env, 1); /* gen!+can!+bas */
        return (*qfn1(fn))(qenv(fn), v0013);
    }
}



/* Code for mksp!* */

static Lisp_Object CC_mkspH(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0244, v0133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksp*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0003;
/* end of prologue */
    stack[-2] = nil;
    v0244 = stack[-1];
    if (v0244 == nil) goto v0176;
    v0244 = stack[-1];
    fn = elt(env, 2); /* kernlp */
    v0244 = (*qfn1(fn))(qenv(fn), v0244);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    goto v0175;

v0175:
    if (v0244 == nil) goto v0180;
    v0133 = stack[-1];
    v0244 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* exptf */
        return (*qfn2(fn))(qenv(fn), v0133, v0244);
    }

v0180:
    v0244 = stack[-1];
    fn = elt(env, 4); /* minusf */
    v0244 = (*qfn1(fn))(qenv(fn), v0244);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    if (v0244 == nil) goto v0235;
    v0244 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v0244;
    v0244 = stack[-1];
    fn = elt(env, 5); /* negf */
    v0244 = (*qfn1(fn))(qenv(fn), v0244);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    stack[-1] = v0244;
    goto v0235;

v0235:
    v0133 = stack[-1];
    v0244 = stack[0];
    fn = elt(env, 6); /* mksp */
    v0133 = (*qfn2(fn))(qenv(fn), v0133, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    v0244 = (Lisp_Object)17; /* 1 */
    v0244 = cons(v0133, v0244);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    v0244 = ncons(v0244);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-3];
    stack[-1] = v0244;
    v0244 = stack[-2];
    if (v0244 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0244 = stack[0];
    v0244 = Levenp(nil, v0244);
    env = stack[-3];
    if (!(v0244 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0244 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* negf */
        return (*qfn1(fn))(qenv(fn), v0244);
    }

v0176:
    v0244 = qvalue(elt(env, 1)); /* t */
    goto v0175;
/* error exit handlers */
v0158:
    popv(4);
    return nil;
}



/* Code for rl_susipost */

static Lisp_Object CC_rl_susipost(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0118, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_susipost");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0118 = v0014;
    v0119 = v0003;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susipost!* */
    v0118 = list2(v0119, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-1];
    {
        Lisp_Object v0167 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0167, v0118);
    }
/* error exit handlers */
v0160:
    popv(2);
    return nil;
}



/* Code for opfneval */

static Lisp_Object CC_opfneval(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0303;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for opfneval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0003;
/* end of prologue */
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    if (!symbolp(v0091)) v0091 = nil;
    else { v0091 = qfastgets(v0091);
           if (v0091 != nil) { v0091 = elt(v0091, 39); /* remember */
#ifdef RECORD_GET
             if (v0091 == SPID_NOPROP)
                record_get(elt(fastget_names, 39), 0),
                v0091 = nil;
             else record_get(elt(fastget_names, 39), 1),
                v0091 = lisp_true; }
           else record_get(elt(fastget_names, 39), 0); }
#else
             if (v0091 == SPID_NOPROP) v0091 = nil; else v0091 = lisp_true; }}
#endif
    if (v0091 == nil) goto v0100;
    v0091 = stack[-2];
    v0303 = qcar(v0091);
    v0091 = elt(env, 1); /* noval */
    v0091 = Lflagp(nil, v0303, v0091);
    env = stack[-5];
    if (v0091 == nil) goto v0048;
    v0091 = stack[-2];
    v0091 = qcdr(v0091);
    goto v0160;

v0160:
    stack[-4] = v0091;
    v0091 = stack[-4];
    if (v0091 == nil) goto v0117;
    v0091 = stack[-4];
    v0091 = qcar(v0091);
    v0303 = v0091;
    v0091 = v0303;
    v0091 = integerp(v0091);
    if (v0091 == nil) goto v0293;
    v0091 = v0303;
    goto v0165;

v0165:
    v0091 = ncons(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[-1] = v0091;
    stack[-3] = v0091;
    goto v0119;

v0119:
    v0091 = stack[-4];
    v0091 = qcdr(v0091);
    stack[-4] = v0091;
    v0091 = stack[-4];
    if (v0091 == nil) goto v0244;
    stack[0] = stack[-1];
    v0091 = stack[-4];
    v0091 = qcar(v0091);
    v0303 = v0091;
    v0091 = v0303;
    v0091 = integerp(v0091);
    if (v0091 == nil) goto v0112;
    v0091 = v0303;
    goto v0170;

v0170:
    v0091 = ncons(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0091 = Lrplacd(nil, stack[0], v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    stack[-1] = v0091;
    goto v0119;

v0112:
    v0091 = v0303;
    v0091 = Lmkquote(nil, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    goto v0170;

v0244:
    v0091 = stack[-3];
    goto v0118;

v0118:
    stack[-4] = v0091;
    v0091 = stack[-2];
    v0303 = qcar(v0091);
    v0091 = stack[-4];
    v0303 = cons(v0303, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    if (!symbolp(v0091)) v0091 = nil;
    else { v0091 = qfastgets(v0091);
           if (v0091 != nil) { v0091 = elt(v0091, 50); /* kvalue */
#ifdef RECORD_GET
             if (v0091 != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                v0091 = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (v0091 == SPID_NOPROP) v0091 = nil; }}
#endif
    v0091 = Lassoc(nil, v0303, v0091);
    v0303 = v0091;
    if (v0091 == nil) goto v0197;
    v0091 = v0303;
    v0091 = qcdr(v0091);
    v0091 = qcar(v0091);
    { popv(6); return onevalue(v0091); }

v0197:
    v0091 = stack[-2];
    v0303 = qcar(v0091);
    v0091 = stack[-4];
    v0091 = cons(v0303, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    fn = elt(env, 3); /* lispeval */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[-3] = v0091;
    v0091 = stack[-2];
    stack[-1] = qcar(v0091);
    v0091 = stack[-2];
    v0091 = qcar(v0091);
    if (!symbolp(v0091)) stack[0] = nil;
    else { stack[0] = qfastgets(v0091);
           if (stack[0] != nil) { stack[0] = elt(stack[0], 50); /* kvalue 
*/
#ifdef RECORD_GET
             if (stack[0] != SPID_NOPROP)
                record_get(elt(fastget_names, 50), 1);
             else record_get(elt(fastget_names, 50), 0),
                stack[0] = nil; }
           else record_get(elt(fastget_names, 50), 0); }
#else
             if (stack[0] == SPID_NOPROP) stack[0] = nil; }}
#endif
    v0091 = stack[-2];
    v0303 = qcar(v0091);
    v0091 = stack[-4];
    v0303 = cons(v0303, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0091 = stack[-3];
    fn = elt(env, 4); /* put!-kvalue */
    v0091 = (*qfnn(fn))(qenv(fn), 4, stack[-1], stack[0], v0303, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v0293:
    v0091 = v0303;
    v0091 = Lmkquote(nil, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    goto v0165;

v0117:
    v0091 = qvalue(elt(env, 2)); /* nil */
    goto v0118;

v0048:
    v0091 = stack[-2];
    v0091 = qcdr(v0091);
    fn = elt(env, 5); /* revlis */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    goto v0160;

v0100:
    v0091 = stack[-2];
    stack[-4] = qcar(v0091);
    v0091 = stack[-2];
    v0303 = qcar(v0091);
    v0091 = elt(env, 1); /* noval */
    v0091 = Lflagp(nil, v0303, v0091);
    env = stack[-5];
    if (v0091 == nil) goto v0027;
    v0091 = stack[-2];
    v0091 = qcdr(v0091);
    goto v0205;

v0205:
    stack[-3] = v0091;
    v0091 = stack[-3];
    if (v0091 == nil) goto v0188;
    v0091 = stack[-3];
    v0091 = qcar(v0091);
    v0091 = Lmkquote(nil, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0091 = ncons(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    stack[-1] = v0091;
    stack[-2] = v0091;
    goto v0304;

v0304:
    v0091 = stack[-3];
    v0091 = qcdr(v0091);
    stack[-3] = v0091;
    v0091 = stack[-3];
    if (v0091 == nil) goto v0097;
    stack[0] = stack[-1];
    v0091 = stack[-3];
    v0091 = qcar(v0091);
    v0091 = Lmkquote(nil, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0091 = ncons(v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0091 = Lrplacd(nil, stack[0], v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    v0091 = stack[-1];
    v0091 = qcdr(v0091);
    stack[-1] = v0091;
    goto v0304;

v0097:
    v0091 = stack[-2];
    goto v0136;

v0136:
    v0091 = cons(stack[-4], v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 3); /* lispeval */
        return (*qfn1(fn))(qenv(fn), v0091);
    }

v0188:
    v0091 = qvalue(elt(env, 2)); /* nil */
    goto v0136;

v0027:
    v0091 = stack[-2];
    v0091 = qcdr(v0091);
    fn = elt(env, 5); /* revlis */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-5];
    goto v0205;
/* error exit handlers */
v0088:
    popv(6);
    return nil;
}



/* Code for exptplus */

static Lisp_Object CC_exptplus(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0060, v0165, v0199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exptplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0165 = v0014;
    v0199 = v0003;
/* end of prologue */
    v0060 = v0199;
    if (!consp(v0060)) goto v0012;
    v0060 = v0165;
    if (!consp(v0060)) goto v0124;
    v0060 = elt(env, 1); /* "Bad exponent sum" */
    {
        fn = elt(env, 2); /* interr */
        return (*qfn1(fn))(qenv(fn), v0060);
    }

v0124:
    v0060 = v0199;
    v0060 = qcar(v0060);
    v0060 = plus2(v0060, v0165);
    errexit();
    return ncons(v0060);

v0012:
    v0060 = v0165;
    if (!consp(v0060)) goto v0159;
    v0060 = v0199;
    v0165 = qcar(v0165);
    v0060 = plus2(v0060, v0165);
    errexit();
    return ncons(v0060);

v0159:
    v0060 = v0199;
    return plus2(v0060, v0165);
}



/* Code for ps!:expansion!-point */

static Lisp_Object CC_psTexpansionKpoint(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0235, v0132, v0131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:expansion-point");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0131 = v0003;
/* end of prologue */
    v0235 = v0131;
    if (!consp(v0235)) goto v0029;
    v0235 = v0131;
    v0132 = qcar(v0235);
    v0235 = elt(env, 2); /* !:ps!: */
    if (v0132 == v0235) goto v0182;
    v0235 = v0131;
    v0235 = qcar(v0235);
    if (!symbolp(v0235)) v0235 = nil;
    else { v0235 = qfastgets(v0235);
           if (v0235 != nil) { v0235 = elt(v0235, 8); /* dname */
#ifdef RECORD_GET
             if (v0235 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0235 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0235 == SPID_NOPROP) v0235 = nil; }}
#endif
    goto v0028;

v0028:
    if (v0235 == nil) goto v0049;
    v0235 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0235);

v0049:
    v0132 = v0131;
    v0235 = (Lisp_Object)49; /* 3 */
    {
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v0132, v0235);
    }

v0182:
    v0235 = qvalue(elt(env, 3)); /* nil */
    goto v0028;

v0029:
    v0235 = qvalue(elt(env, 1)); /* t */
    goto v0028;
}



/* Code for testredzz */

static Lisp_Object CC_testredzz(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for testredzz");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0117 = v0003;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v0235 = qvalue(elt(env, 2)); /* maxvar */
    v0117 = plus2(v0235, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0235 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0117/(16/CELL)));
    v0117 = (Lisp_Object)65; /* 4 */
    v0117 = *(Lisp_Object *)((char *)v0235 + (CELL-TAG_VECTOR) + ((int32_t)v0117/(16/CELL)));
    stack[0] = v0117;
    goto v0012;

v0012:
    v0117 = stack[0];
    if (v0117 == nil) goto v0122;
    v0117 = stack[0];
    v0117 = qcar(v0117);
    v0117 = qcar(v0117);
    fn = elt(env, 4); /* testredh */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0117 = stack[0];
    v0117 = qcdr(v0117);
    stack[0] = v0117;
    goto v0012;

v0122:
    v0117 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0117); }
/* error exit handlers */
v0131:
    popv(2);
    return nil;
}



/* Code for meq */

static Lisp_Object CC_meq(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0155, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for meq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0003;
/* end of prologue */
    v0123 = stack[-1];
    fn = elt(env, 2); /* binding */
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-2];
    v0155 = v0123;
    v0123 = v0155;
    if (v0123 == nil) goto v0051;
    v0123 = v0155;
    v0152 = elt(env, 1); /* unbound */
    if (v0123 == v0152) goto v0051;
    v0123 = v0155;
    v0155 = v0123;
    goto v0029;

v0029:
    v0123 = stack[0];
    v0123 = (equal(v0155, v0123) ? lisp_true : nil);
    { popv(3); return onevalue(v0123); }

v0051:
    v0123 = stack[-1];
    v0155 = v0123;
    goto v0029;
/* error exit handlers */
v0049:
    popv(3);
    return nil;
}



/* Code for getphystypetimes */

static Lisp_Object CC_getphystypetimes(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117, v0235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getphystypetimes");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* nil */
    v0117 = stack[0];
    fn = elt(env, 3); /* collectphystype */
    v0117 = (*qfn1(fn))(qenv(fn), v0117);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-2];
    fn = elt(env, 4); /* deleteall */
    v0117 = (*qfn2(fn))(qenv(fn), stack[-1], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-2];
    v0235 = v0117;
    if (v0117 == nil) goto v0028;
    v0117 = v0235;
    v0117 = qcdr(v0117);
    if (v0117 == nil) goto v0119;
    stack[-1] = elt(env, 0); /* getphystypetimes */
    v0235 = elt(env, 2); /* "PHYSOP type mismatch in" */
    v0117 = stack[0];
    v0117 = list2(v0235, v0117);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    env = stack[-2];
    fn = elt(env, 5); /* rederr2 */
    v0117 = (*qfn2(fn))(qenv(fn), stack[-1], v0117);
    nil = C_nil;
    if (exception_pending()) goto v0173;
    v0117 = nil;
    { popv(3); return onevalue(v0117); }

v0119:
    v0117 = v0235;
    v0117 = qcar(v0117);
    { popv(3); return onevalue(v0117); }

v0028:
    v0117 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0117); }
/* error exit handlers */
v0173:
    popv(3);
    return nil;
}



/* Code for edges_parents */

static Lisp_Object CC_edges_parents(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for edges_parents");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
/* end of prologue */
    v0183 = stack[0];
    if (v0183 == nil) goto v0010;
    v0183 = stack[0];
    v0183 = qcar(v0183);
    fn = elt(env, 2); /* edge_new_parents */
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    env = stack[-2];
    stack[-1] = v0183;
    v0183 = stack[0];
    v0183 = qcdr(v0183);
    v0183 = CC_edges_parents(env, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0174;
    {
        Lisp_Object v0050 = stack[-1];
        popv(3);
        return Lappend(nil, v0050, v0183);
    }

v0010:
    v0183 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0183); }
/* error exit handlers */
v0174:
    popv(3);
    return nil;
}



/* Code for fs!:prin1 */

static Lisp_Object CC_fsTprin1(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0304, v0079;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:prin1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
/* end of prologue */
    v0304 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v0304;
    v0079 = stack[0];
    v0304 = (Lisp_Object)1; /* 0 */
    v0079 = *(Lisp_Object *)((char *)v0079 + (CELL-TAG_VECTOR) + ((int32_t)v0304/(16/CELL)));
    v0304 = elt(env, 2); /* (1 . 1) */
    if (equal(v0079, v0304)) goto v0180;
    v0304 = elt(env, 3); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    v0079 = stack[0];
    v0304 = (Lisp_Object)1; /* 0 */
    v0304 = *(Lisp_Object *)((char *)v0079 + (CELL-TAG_VECTOR) + ((int32_t)v0304/(16/CELL)));
    fn = elt(env, 13); /* sqprint */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    v0304 = elt(env, 4); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    goto v0180;

v0180:
    v0304 = stack[0];
    fn = elt(env, 14); /* fs!:null!-angle */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    if (v0304 == nil) goto v0173;
    v0079 = stack[0];
    v0304 = (Lisp_Object)1; /* 0 */
    v0079 = *(Lisp_Object *)((char *)v0079 + (CELL-TAG_VECTOR) + ((int32_t)v0304/(16/CELL)));
    v0304 = elt(env, 2); /* (1 . 1) */
    if (!(equal(v0079, v0304))) goto v0154;
    v0304 = elt(env, 11); /* "1" */
    fn = elt(env, 12); /* prin2!* */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    goto v0154;

v0154:
    v0304 = nil;
    { popv(5); return onevalue(v0304); }

v0173:
    v0079 = stack[0];
    v0304 = (Lisp_Object)17; /* 1 */
    v0304 = *(Lisp_Object *)((char *)v0079 + (CELL-TAG_VECTOR) + ((int32_t)v0304/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    v0304 = elt(env, 5); /* "[" */
    fn = elt(env, 12); /* prin2!* */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    v0079 = stack[0];
    v0304 = (Lisp_Object)33; /* 2 */
    v0304 = *(Lisp_Object *)((char *)v0079 + (CELL-TAG_VECTOR) + ((int32_t)v0304/(16/CELL)));
    stack[-2] = v0304;
    v0304 = (Lisp_Object)1; /* 0 */
    stack[0] = v0304;
    goto v0114;

v0114:
    v0079 = (Lisp_Object)113; /* 7 */
    v0304 = stack[0];
    v0304 = difference2(v0079, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    v0304 = Lminusp(nil, v0304);
    env = stack[-4];
    if (v0304 == nil) goto v0243;
    v0304 = elt(env, 10); /* "]" */
    fn = elt(env, 12); /* prin2!* */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    goto v0154;

v0243:
    v0079 = stack[-2];
    v0304 = stack[0];
    v0079 = *(Lisp_Object *)((char *)v0079 + (CELL-TAG_VECTOR) + ((int32_t)v0304/(16/CELL)));
    stack[-1] = v0079;
    v0304 = (Lisp_Object)1; /* 0 */
    if (v0079 == v0304) goto v0042;
    v0079 = stack[-1];
    v0304 = (Lisp_Object)1; /* 0 */
    v0304 = (Lisp_Object)lessp2(v0079, v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    v0304 = v0304 ? lisp_true : nil;
    env = stack[-4];
    if (v0304 == nil) goto v0157;
    v0304 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v0304;
    v0304 = elt(env, 7); /* "-" */
    fn = elt(env, 12); /* prin2!* */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    v0304 = stack[-1];
    v0304 = negate(v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    stack[-1] = v0304;
    goto v0157;

v0157:
    v0304 = stack[-3];
    if (!(v0304 == nil)) goto v0306;
    v0304 = elt(env, 8); /* "+" */
    fn = elt(env, 12); /* prin2!* */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    goto v0306;

v0306:
    v0079 = stack[-1];
    v0304 = (Lisp_Object)17; /* 1 */
    if (v0079 == v0304) goto v0221;
    v0304 = stack[-1];
    fn = elt(env, 12); /* prin2!* */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    goto v0221;

v0221:
    v0304 = qvalue(elt(env, 6)); /* nil */
    stack[-3] = v0304;
    v0079 = qvalue(elt(env, 9)); /* fourier!-name!* */
    v0304 = stack[0];
    v0304 = *(Lisp_Object *)((char *)v0079 + (CELL-TAG_VECTOR) + ((int32_t)v0304/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v0304 = (*qfn1(fn))(qenv(fn), v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    goto v0042;

v0042:
    v0304 = stack[0];
    v0304 = add1(v0304);
    nil = C_nil;
    if (exception_pending()) goto v0208;
    env = stack[-4];
    stack[0] = v0304;
    goto v0114;
/* error exit handlers */
v0208:
    popv(5);
    return nil;
}



/* Code for dfprintfn */

static Lisp_Object CC_dfprintfn(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0148, v0293;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dfprintfn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0110 = v0003;
/* end of prologue */
    v0148 = qvalue(elt(env, 1)); /* !*nat */
    if (v0148 == nil) goto v0029;
    v0148 = qvalue(elt(env, 3)); /* !*fort */
    if (!(v0148 == nil)) goto v0028;
    v0148 = qvalue(elt(env, 4)); /* !*dfprint */
    v0148 = (v0148 == nil ? lisp_true : nil);
    goto v0028;

v0028:
    if (v0148 == nil) goto v0048;
    v0110 = elt(env, 5); /* failed */
    { popv(1); return onevalue(v0110); }

v0048:
    v0148 = elt(env, 6); /* !!df!! */
    v0110 = qcdr(v0110);
    v0293 = cons(v0148, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[0];
    v0148 = (Lisp_Object)1; /* 0 */
    v0110 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 8); /* layout!-formula */
    v0110 = (*qfnn(fn))(qenv(fn), 3, v0293, v0148, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[0];
    v0148 = v0110;
    v0110 = v0148;
    if (v0110 == nil) goto v0149;
    v0110 = v0148;
    fn = elt(env, 9); /* putpline */
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    v0110 = nil;
    { popv(1); return onevalue(v0110); }

v0149:
    v0110 = elt(env, 5); /* failed */
    { popv(1); return onevalue(v0110); }

v0029:
    v0148 = qvalue(elt(env, 2)); /* t */
    goto v0028;
/* error exit handlers */
v0203:
    popv(1);
    return nil;
}



/* Code for reverse!-num1 */

static Lisp_Object CC_reverseKnum1(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0309, v0092;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reverse-num1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0014;
    stack[0] = v0003;
/* end of prologue */
    v0092 = stack[0];
    v0309 = (Lisp_Object)1; /* 0 */
    if (v0092 == v0309) goto v0012;
    v0092 = stack[-2];
    v0309 = (Lisp_Object)17; /* 1 */
    if (v0092 == v0309) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0092 = stack[-2];
    v0309 = (Lisp_Object)33; /* 2 */
    if (v0092 == v0309) goto v0178;
    v0092 = stack[-2];
    v0309 = (Lisp_Object)49; /* 3 */
    if (v0092 == v0309) goto v0203;
    v0092 = stack[-2];
    v0309 = (Lisp_Object)65; /* 4 */
    if (v0092 == v0309) goto v0207;
    stack[-1] = (Lisp_Object)33; /* 2 */
    v0092 = stack[-2];
    v0309 = (Lisp_Object)33; /* 2 */
    v0309 = quot2(v0092, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0309 = Lexpt(nil, stack[-1], v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-3] = v0309;
    v0092 = stack[0];
    v0309 = stack[-3];
    v0309 = Ldivide(nil, v0092, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-1] = v0309;
    v0309 = stack[-2];
    v0309 = Levenp(nil, v0309);
    env = stack[-4];
    if (!(v0309 == nil)) goto v0065;
    v0092 = stack[-3];
    v0309 = (Lisp_Object)33; /* 2 */
    v0309 = times2(v0092, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-3] = v0309;
    goto v0065;

v0065:
    v0309 = stack[-1];
    stack[0] = qcdr(v0309);
    v0092 = stack[-2];
    v0309 = (Lisp_Object)33; /* 2 */
    v0309 = quot2(v0092, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0092 = CC_reverseKnum1(env, stack[0], v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0309 = stack[-3];
    stack[0] = times2(v0092, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0309 = stack[-1];
    stack[-1] = qcar(v0309);
    v0309 = stack[-2];
    v0092 = add1(v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0309 = (Lisp_Object)33; /* 2 */
    v0309 = quot2(v0092, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0309 = CC_reverseKnum1(env, stack[-1], v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    {
        Lisp_Object v0027 = stack[0];
        popv(5);
        return plus2(v0027, v0309);
    }

v0207:
    v0092 = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v0309 = stack[0];
    v0309 = *(Lisp_Object *)((char *)v0092 + (CELL-TAG_VECTOR) + ((int32_t)v0309/(16/CELL)));
    { popv(5); return onevalue(v0309); }

v0203:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v0092 = (Lisp_Object)33; /* 2 */
    v0309 = stack[0];
    v0309 = times2(v0092, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    v0309 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0309/(16/CELL)));
    { popv(5); return onevalue(v0309); }

v0178:
    stack[-1] = qvalue(elt(env, 1)); /* reverse!-num!-table!* */
    v0092 = (Lisp_Object)65; /* 4 */
    v0309 = stack[0];
    v0309 = times2(v0092, v0309);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    v0309 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0309/(16/CELL)));
    { popv(5); return onevalue(v0309); }

v0012:
    v0309 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0309); }
/* error exit handlers */
v0026:
    popv(5);
    return nil;
}



/* Code for qtypnm */

static Lisp_Object CC_qtypnm(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0209, v0302;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qtypnm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0014;
    stack[-4] = v0003;
/* end of prologue */
    v0209 = stack[-3];
    v0090 = elt(env, 1); /* function */
    v0090 = Lflagp(nil, v0209, v0090);
    env = stack[-6];
    if (v0090 == nil) goto v0203;
    v0209 = stack[-4];
    v0090 = elt(env, 2); /* seen */
    v0090 = Lflagp(nil, v0209, v0090);
    env = stack[-6];
    if (!(v0090 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v0090 = stack[-4];
    v0209 = ncons(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0090 = elt(env, 2); /* seen */
    v0090 = Lflag(nil, v0209, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0209 = stack[-4];
    v0090 = qvalue(elt(env, 3)); /* seen!* */
    v0090 = cons(v0209, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    qvalue(elt(env, 3)) = v0090; /* seen!* */
    { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

v0203:
    v0209 = stack[-3];
    v0090 = elt(env, 4); /* tseen */
    v0090 = get(v0209, v0090);
    env = stack[-6];
    stack[-2] = v0090;
    if (v0090 == nil) goto v0166;
    v0209 = stack[-4];
    v0090 = stack[-2];
    v0090 = qcdr(v0090);
    v0090 = Latsoc(nil, v0209, v0090);
    stack[-5] = v0090;
    if (v0090 == nil) goto v0166;
    v0090 = stack[-5];
    v0090 = qcdr(v0090);
    { popv(7); return onevalue(v0090); }

v0166:
    v0090 = stack[-2];
    if (!(v0090 == nil)) goto v0059;
    stack[-1] = elt(env, 5); /* !( */
    v0090 = stack[-3];
    stack[0] = Lexplode(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0090 = elt(env, 6); /* !) */
    v0090 = ncons(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0090 = Lnconc(nil, stack[0], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0090 = cons(stack[-1], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0090 = ncons(v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    stack[-2] = v0090;
    v0302 = stack[-3];
    v0209 = elt(env, 4); /* tseen */
    v0090 = stack[-2];
    v0090 = Lputprop(nil, 3, v0302, v0209, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0209 = stack[-3];
    v0090 = qvalue(elt(env, 7)); /* tseen!* */
    v0090 = cons(v0209, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    qvalue(elt(env, 7)) = v0090; /* tseen!* */
    goto v0059;

v0059:
    v0090 = stack[-4];
    v0090 = Lexplode(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    stack[-1] = v0090;
    v0090 = Lcompress(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    stack[-5] = v0090;
    stack[0] = stack[-2];
    v0302 = stack[-4];
    v0209 = stack[-5];
    v0090 = stack[-2];
    v0090 = qcdr(v0090);
    v0090 = acons(v0302, v0209, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0090 = Lrplacd(nil, stack[0], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0090 = stack[-2];
    v0209 = qcar(v0090);
    v0090 = stack[-1];
    v0090 = Lappend(nil, v0209, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    stack[-2] = v0090;
    stack[-1] = stack[-5];
    stack[0] = elt(env, 8); /* rccnam */
    v0090 = stack[-2];
    v0209 = Llength(nil, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0090 = stack[-2];
    v0090 = cons(v0209, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0090 = Lputprop(nil, 3, stack[-1], stack[0], v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-6];
    v0302 = stack[-3];
    v0209 = elt(env, 9); /* funs */
    v0090 = stack[-5];
    fn = elt(env, 10); /* traput */
    v0090 = (*qfnn(fn))(qenv(fn), 3, v0302, v0209, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
/* error exit handlers */
v0061:
    popv(7);
    return nil;
}



/* Code for settinsert */

static Lisp_Object CC_settinsert(Lisp_Object env,
                         Lisp_Object v0003)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0159, v0130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for settinsert");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0003);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0003;
/* end of prologue */
    v0159 = stack[0];
    fn = elt(env, 2); /* janettreeinsert */
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-1];
    v0130 = stack[0];
    v0159 = qvalue(elt(env, 1)); /* fluidbibasissett */
    v0159 = cons(v0130, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-1];
    qvalue(elt(env, 1)) = v0159; /* fluidbibasissett */
    v0159 = nil;
    { popv(2); return onevalue(v0159); }
/* error exit handlers */
v0120:
    popv(2);
    return nil;
}



/* Code for smemberlp */

static Lisp_Object CC_smemberlp(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0235, v0132;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smemberlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0014;
    stack[-1] = v0003;
/* end of prologue */

v0204:
    v0235 = stack[0];
    if (v0235 == nil) goto v0012;
    v0235 = stack[0];
    if (!consp(v0235)) goto v0176;
    v0132 = stack[-1];
    v0235 = stack[0];
    v0235 = qcar(v0235);
    v0235 = CC_smemberlp(env, v0132, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-2];
    if (!(v0235 == nil)) { popv(3); return onevalue(v0235); }
    v0132 = stack[-1];
    v0235 = stack[0];
    v0235 = qcdr(v0235);
    stack[-1] = v0132;
    stack[0] = v0235;
    goto v0204;

v0176:
    v0132 = stack[0];
    v0235 = stack[-1];
    v0235 = Lmember(nil, v0132, v0235);
    { popv(3); return onevalue(v0235); }

v0012:
    v0235 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0235); }
/* error exit handlers */
v0149:
    popv(3);
    return nil;
}



/* Code for mri_pasf2mri */

static Lisp_Object CC_mri_pasf2mri(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_pasf2mri");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0130 = v0014;
    v0181 = v0003;
/* end of prologue */
    stack[-1] = v0181;
    stack[0] = elt(env, 1); /* mri_pasf2mriat */
    v0130 = ncons(v0130);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-2];
    {
        Lisp_Object v0151 = stack[-1];
        Lisp_Object v0160 = stack[0];
        popv(3);
        fn = elt(env, 2); /* cl_apply2ats1 */
        return (*qfnn(fn))(qenv(fn), 3, v0151, v0160, v0130);
    }
/* error exit handlers */
v0119:
    popv(3);
    return nil;
}



/* Code for distribute!.multiplicity */

static Lisp_Object CC_distributeQmultiplicity(Lisp_Object env,
                         Lisp_Object v0003, Lisp_Object v0014)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0293, v0203;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for distribute.multiplicity");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0014,v0003);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0003,v0014);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0014;
    v0293 = v0003;
/* end of prologue */
    stack[-4] = v0293;
    v0293 = stack[-4];
    if (v0293 == nil) goto v0176;
    v0293 = stack[-4];
    v0293 = qcar(v0293);
    v0203 = v0293;
    v0293 = stack[-3];
    v0293 = cons(v0203, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0293 = ncons(v0293);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-1] = v0293;
    stack[-2] = v0293;
    goto v0029;

v0029:
    v0293 = stack[-4];
    v0293 = qcdr(v0293);
    stack[-4] = v0293;
    v0293 = stack[-4];
    if (v0293 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0293 = stack[-4];
    v0293 = qcar(v0293);
    v0203 = v0293;
    v0293 = stack[-3];
    v0293 = cons(v0203, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0293 = ncons(v0293);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0293 = Lrplacd(nil, stack[0], v0293);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0293 = stack[-1];
    v0293 = qcdr(v0293);
    stack[-1] = v0293;
    goto v0029;

v0176:
    v0293 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0293); }
/* error exit handlers */
v0116:
    popv(6);
    return nil;
}



setup_type const u24_setup[] =
{
    {"in_list1a",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_in_list1a},
    {"outrefend",               CC_outrefend,   too_many_1,    wrong_no_1},
    {"monomdivide",             too_few_2,      CC_monomdivide,wrong_no_2},
    {"sfto_updecf",             CC_sfto_updecf, too_many_1,    wrong_no_1},
    {"vunion",                  too_few_2,      CC_vunion,     wrong_no_2},
    {"tayexp-minus",            CC_tayexpKminus,too_many_1,    wrong_no_1},
    {"encodeir",                CC_encodeir,    too_many_1,    wrong_no_1},
    {"testchar1",               CC_testchar1,   too_many_1,    wrong_no_1},
    {"insertparens",            CC_insertparens,too_many_1,    wrong_no_1},
    {"log_inlines",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_log_inlines},
    {"splitlist:",              too_few_2,      CC_splitlistT, wrong_no_2},
    {"rl_bestgaussp",           CC_rl_bestgaussp,too_many_1,   wrong_no_1},
    {"get*elements",            CC_getHelements,too_many_1,    wrong_no_1},
    {"ofsf_xor",                too_few_2,      CC_ofsf_xor,   wrong_no_2},
    {"termorder",               too_few_2,      CC_termorder,  wrong_no_2},
    {"delhisto",                CC_delhisto,    too_many_1,    wrong_no_1},
    {"dipev2f",                 too_few_2,      CC_dipev2f,    wrong_no_2},
    {"vdpsave",                 CC_vdpsave,     too_many_1,    wrong_no_1},
    {"treesizep",               too_few_2,      CC_treesizep,  wrong_no_2},
    {"getphystypecar",          CC_getphystypecar,too_many_1,  wrong_no_1},
    {"nfactorial",              CC_nfactorial,  too_many_1,    wrong_no_1},
    {"no-side-effect-listp",    CC_noKsideKeffectKlistp,too_many_1,wrong_no_1},
    {"outrdefun",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_outrdefun},
    {"cnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cnrd},
    {"ordexp",                  too_few_2,      CC_ordexp,     wrong_no_2},
    {"gbfdot",                  too_few_2,      CC_gbfdot,     wrong_no_2},
    {"evaluate-horner",         CC_evaluateKhorner,too_many_1, wrong_no_1},
    {"getphystypeor",           CC_getphystypeor,too_many_1,   wrong_no_1},
    {"gcdout",                  CC_gcdout,      too_many_1,    wrong_no_1},
    {"ad_numsort",              CC_ad_numsort,  too_many_1,    wrong_no_1},
    {"lambda_n4e0tk_4",         too_few_2,      CC_lambda_n4e0tk_4,wrong_no_2},
    {"safe-modrecip",           CC_safeKmodrecip,too_many_1,   wrong_no_1},
    {"horner-rule-for-one-var", wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"add2locs",                CC_add2locs,    too_many_1,    wrong_no_1},
    {"rl_qefsolset",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_qefsolset},
    {"super_der_simp",          CC_super_der_simp,too_many_1,  wrong_no_1},
    {"get-free-form",           CC_getKfreeKform,too_many_1,   wrong_no_1},
    {"mk+unit+mat",             CC_mkLunitLmat, too_many_1,    wrong_no_1},
    {"mksp*",                   too_few_2,      CC_mkspH,      wrong_no_2},
    {"rl_susipost",             too_few_2,      CC_rl_susipost,wrong_no_2},
    {"opfneval",                CC_opfneval,    too_many_1,    wrong_no_1},
    {"exptplus",                too_few_2,      CC_exptplus,   wrong_no_2},
    {"ps:expansion-point",      CC_psTexpansionKpoint,too_many_1,wrong_no_1},
    {"testredzz",               CC_testredzz,   too_many_1,    wrong_no_1},
    {"meq",                     too_few_2,      CC_meq,        wrong_no_2},
    {"getphystypetimes",        CC_getphystypetimes,too_many_1,wrong_no_1},
    {"edges_parents",           CC_edges_parents,too_many_1,   wrong_no_1},
    {"fs:prin1",                CC_fsTprin1,    too_many_1,    wrong_no_1},
    {"dfprintfn",               CC_dfprintfn,   too_many_1,    wrong_no_1},
    {"reverse-num1",            too_few_2,      CC_reverseKnum1,wrong_no_2},
    {"qtypnm",                  too_few_2,      CC_qtypnm,     wrong_no_2},
    {"settinsert",              CC_settinsert,  too_many_1,    wrong_no_1},
    {"smemberlp",               too_few_2,      CC_smemberlp,  wrong_no_2},
    {"mri_pasf2mri",            too_few_2,      CC_mri_pasf2mri,wrong_no_2},
    {"distribute.multiplicity", too_few_2,      CC_distributeQmultiplicity,wrong_no_2},
    {NULL, (one_args *)"u24", (two_args *)"17806 5369626 4829854", 0}
};

/* end of generated code */
