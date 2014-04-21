
/* $destdir\u15.c        Machine generated C code */

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


/* Code for constsml */

static Lisp_Object CC_constsml(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for constsml");
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
    v0003 = stack[0];
    if (!(is_number(v0003))) goto v0005;
    v0003 = elt(env, 1); /* "<cn" */
    fn = elt(env, 13); /* printout */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0003 = stack[0];
    v0003 = Lfloatp(nil, v0003);
    env = stack[-1];
    if (v0003 == nil) goto v0007;
    v0003 = elt(env, 2); /* " type=""real""> " */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    goto v0008;

v0008:
    v0003 = stack[0];
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0003 = elt(env, 5); /* " </cn>" */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    goto v0005;

v0005:
    v0003 = stack[0];
    if (!(symbolp(v0003))) goto v0009;
    v0003 = stack[0];
    v0004 = Lintern(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0003 = qvalue(elt(env, 6)); /* constants!* */
    v0003 = Lmember(nil, v0004, v0003);
    if (v0003 == nil) goto v0010;
    v0003 = elt(env, 7); /* "<cn type=""constant""> " */
    fn = elt(env, 13); /* printout */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0003 = stack[0];
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0003 = elt(env, 5); /* " </cn>" */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    goto v0009;

v0009:
    v0003 = nil;
    { popv(2); return onevalue(v0003); }

v0010:
    v0003 = elt(env, 8); /* "<ci" */
    fn = elt(env, 13); /* printout */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0003 = stack[0];
    fn = elt(env, 14); /* listp */
    v0003 = (*qfn1(fn))(qenv(fn), v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    if (v0003 == nil) goto v0011;
    v0003 = elt(env, 9); /* " type=""list""> " */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    goto v0012;

v0012:
    v0003 = stack[0];
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    v0003 = elt(env, 11); /* " </ci>" */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    goto v0009;

v0011:
    v0003 = stack[0];
    v0003 = Lsimple_vectorp(nil, v0003);
    env = stack[-1];
    if (v0003 == nil) goto v0013;
    v0003 = elt(env, 10); /* " type=""vector""> " */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    goto v0012;

v0013:
    v0003 = elt(env, 4); /* "> " */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    goto v0012;

v0007:
    v0003 = stack[0];
    v0003 = integerp(v0003);
    if (v0003 == nil) goto v0014;
    v0003 = elt(env, 3); /* " type=""integer""> " */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    goto v0008;

v0014:
    v0003 = elt(env, 4); /* "> " */
    v0003 = Lprinc(nil, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-1];
    goto v0008;
/* error exit handlers */
v0006:
    popv(2);
    return nil;
}



/* Code for xord_deglex */

static Lisp_Object CC_xord_deglex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0011, v0024, v0025, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xord_deglex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
    stack[-1] = v0000;
/* end of prologue */
    v0011 = stack[-1];
    v0024 = qcar(v0011);
    v0011 = (Lisp_Object)17; /* 1 */
    if (v0024 == v0011) goto v0005;
    v0011 = stack[0];
    v0024 = qcar(v0011);
    v0011 = (Lisp_Object)17; /* 1 */
    if (v0024 == v0011) goto v0027;
    v0011 = stack[-1];
    fn = elt(env, 3); /* xdegreemon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0011 = stack[0];
    fn = elt(env, 3); /* xdegreemon */
    v0011 = (*qfn1(fn))(qenv(fn), v0011);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0026 = stack[-2];
    v0025 = v0011;
    v0024 = v0026;
    v0011 = v0025;
    if (equal(v0024, v0011)) goto v0001;
    v0011 = v0026;
    v0024 = v0025;
        popv(4);
        return Lgreaterp(nil, v0011, v0024);

v0001:
    v0024 = stack[-1];
    v0011 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v0024, v0011);
    }

v0027:
    v0011 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v0011); }

v0005:
    v0011 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0011); }
/* error exit handlers */
v0028:
    popv(4);
    return nil;
}



/* Code for assert_uninstall1 */

static Lisp_Object CC_assert_uninstall1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0018, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_uninstall1");
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
    v0018 = stack[0];
    v0037 = elt(env, 1); /* assert_installed */
    v0037 = get(v0018, v0037);
    env = stack[-1];
    if (v0037 == nil) goto v0027;
    v0019 = stack[0];
    v0018 = stack[0];
    v0037 = elt(env, 3); /* assert_noassertfn */
    v0037 = get(v0018, v0037);
    env = stack[-1];
    fn = elt(env, 5); /* copyd */
    v0037 = (*qfn2(fn))(qenv(fn), v0019, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-1];
    v0018 = stack[0];
    v0037 = elt(env, 1); /* assert_installed */
    v0019 = qvalue(elt(env, 4)); /* nil */
        popv(2);
        return Lputprop(nil, 3, v0018, v0037, v0019);

v0027:
    v0018 = elt(env, 2); /* "assert not installed for" */
    v0037 = stack[0];
    v0037 = list2(v0018, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 6); /* lprim */
        return (*qfn1(fn))(qenv(fn), v0037);
    }
/* error exit handlers */
v0038:
    popv(2);
    return nil;
}



/* Code for getmatelem */

static Lisp_Object CC_getmatelem(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0068, v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getmatelem");
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

v0070:
    v0067 = stack[-2];
    v0068 = Llength(nil, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    v0067 = (Lisp_Object)49; /* 3 */
    if (v0068 == v0067) goto v0072;
    v0068 = stack[-2];
    v0067 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 9); /* typerr */
    v0067 = (*qfn2(fn))(qenv(fn), v0068, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    goto v0072;

v0072:
    v0067 = stack[-2];
    v0067 = qcar(v0067);
    if (!symbolp(v0067)) v0067 = nil;
    else { v0067 = qfastgets(v0067);
           if (v0067 != nil) { v0067 = elt(v0067, 4); /* avalue */
#ifdef RECORD_GET
             if (v0067 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0067 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0067 == SPID_NOPROP) v0067 = nil; }}
#endif
    stack[-3] = v0067;
    v0067 = stack[-3];
    if (v0067 == nil) goto v0073;
    v0067 = stack[-3];
    v0068 = qcar(v0067);
    v0067 = elt(env, 3); /* matrix */
    v0067 = (v0068 == v0067 ? lisp_true : nil);
    v0067 = (v0067 == nil ? lisp_true : nil);
    goto v0009;

v0009:
    if (v0067 == nil) goto v0016;
    v0067 = stack[-2];
    v0068 = qcar(v0067);
    v0067 = elt(env, 4); /* "matrix" */
    fn = elt(env, 9); /* typerr */
    v0067 = (*qfn2(fn))(qenv(fn), v0068, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    goto v0074;

v0074:
    v0067 = stack[-2];
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    fn = elt(env, 10); /* reval_without_mod */
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    stack[0] = v0067;
    v0067 = stack[0];
    v0067 = integerp(v0067);
    if (v0067 == nil) goto v0075;
    v0068 = stack[0];
    v0067 = (Lisp_Object)1; /* 0 */
    v0067 = (Lisp_Object)lesseq2(v0068, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    v0067 = v0067 ? lisp_true : nil;
    env = stack[-4];
    goto v0076;

v0076:
    if (v0067 == nil) goto v0077;
    v0068 = stack[0];
    v0067 = elt(env, 8); /* "positive integer" */
    fn = elt(env, 9); /* typerr */
    v0067 = (*qfn2(fn))(qenv(fn), v0068, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    goto v0077;

v0077:
    v0067 = stack[-3];
    v0068 = qcdr(v0067);
    v0067 = stack[0];
    fn = elt(env, 11); /* nth */
    v0067 = (*qfn2(fn))(qenv(fn), v0068, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    stack[-3] = v0067;
    v0067 = stack[-2];
    v0067 = qcdr(v0067);
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    fn = elt(env, 10); /* reval_without_mod */
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    stack[0] = v0067;
    v0067 = stack[0];
    v0067 = integerp(v0067);
    if (v0067 == nil) goto v0078;
    v0068 = stack[0];
    v0067 = (Lisp_Object)1; /* 0 */
    v0067 = (Lisp_Object)lesseq2(v0068, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    v0067 = v0067 ? lisp_true : nil;
    env = stack[-4];
    goto v0079;

v0079:
    if (v0067 == nil) goto v0080;
    v0068 = stack[0];
    v0067 = elt(env, 8); /* "positive integer" */
    fn = elt(env, 9); /* typerr */
    v0067 = (*qfn2(fn))(qenv(fn), v0068, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    goto v0080;

v0080:
    v0068 = stack[-3];
    v0067 = stack[0];
    {
        popv(5);
        fn = elt(env, 11); /* nth */
        return (*qfn2(fn))(qenv(fn), v0068, v0067);
    }

v0078:
    v0067 = qvalue(elt(env, 2)); /* t */
    goto v0079;

v0075:
    v0067 = qvalue(elt(env, 2)); /* t */
    goto v0076;

v0016:
    v0067 = stack[-3];
    v0067 = qcdr(v0067);
    v0068 = qcar(v0067);
    stack[-3] = v0068;
    v0067 = elt(env, 5); /* mat */
    if (!consp(v0068)) goto v0081;
    v0068 = qcar(v0068);
    if (v0068 == v0067) goto v0074;
    else goto v0081;

v0081:
    v0067 = stack[-3];
    if (symbolp(v0067)) goto v0082;
    stack[-1] = elt(env, 3); /* matrix */
    stack[0] = (Lisp_Object)17; /* 1 */
    v0069 = elt(env, 6); /* "Matrix" */
    v0067 = stack[-2];
    v0068 = qcar(v0067);
    v0067 = elt(env, 7); /* "not set" */
    v0067 = list3(v0069, v0068, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    fn = elt(env, 12); /* rerror */
    v0067 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    goto v0074;

v0082:
    v0068 = stack[-3];
    v0067 = stack[-2];
    v0067 = qcdr(v0067);
    v0067 = cons(v0068, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-4];
    stack[-2] = v0067;
    goto v0070;

v0073:
    v0067 = qvalue(elt(env, 2)); /* t */
    goto v0009;
/* error exit handlers */
v0071:
    popv(5);
    return nil;
}



/* Code for class */

static Lisp_Object CC_class(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for class");
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
    v0087 = stack[0];
    fn = elt(env, 3); /* ord */
    v0088 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-1];
    v0087 = (Lisp_Object)1; /* 0 */
    if (v0088 == v0087) goto v0089;
    v0088 = qvalue(elt(env, 1)); /* ordering */
    v0087 = elt(env, 2); /* lex */
    if (v0088 == v0087) goto v0035;
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    goto v0090;

v0090:
    v0087 = Lreverse(nil, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    env = stack[-1];
    fn = elt(env, 4); /* leftzeros */
    v0087 = (*qfn1(fn))(qenv(fn), v0087);
    nil = C_nil;
    if (exception_pending()) goto v0034;
    v0087 = (Lisp_Object)((int32_t)(v0087) + 0x10);
    { popv(2); return onevalue(v0087); }

v0035:
    v0087 = stack[0];
    goto v0090;

v0089:
    v0087 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0087); }
/* error exit handlers */
v0034:
    popv(2);
    return nil;
}



/* Code for gperm3 */

static Lisp_Object CC_gperm3(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0074, v0031, v0032;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gperm3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0031 = v0015;
    v0074 = v0000;
/* end of prologue */

v0092:
    v0032 = v0074;
    if (v0032 == nil) { popv(2); return onevalue(v0031); }
    v0032 = v0074;
    v0032 = qcdr(v0032);
    stack[0] = v0032;
    v0032 = v0031;
    v0031 = qcar(v0074);
    v0074 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* gperm2 */
    v0074 = (*qfnn(fn))(qenv(fn), 3, v0032, v0031, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-1];
    v0031 = v0074;
    v0074 = stack[0];
    goto v0092;
/* error exit handlers */
v0009:
    popv(2);
    return nil;
}



/* Code for gcref_mkedges!-tgf */

static Lisp_Object CC_gcref_mkedgesKtgf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gcref_mkedges-tgf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0014 = v0015;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = v0014;
    goto v0092;

v0092:
    v0014 = stack[-2];
    if (v0014 == nil) goto v0070;
    v0014 = stack[-2];
    v0014 = qcar(v0014);
    stack[0] = v0014;
    v0014 = stack[-1];
    v0014 = Lprinc(nil, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-3];
    v0014 = elt(env, 2); /* " " */
    v0014 = Lprinc(nil, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-3];
    v0014 = stack[0];
    fn = elt(env, 3); /* prin2t */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-3];
    v0014 = stack[-2];
    v0014 = qcdr(v0014);
    stack[-2] = v0014;
    goto v0092;

v0070:
    v0014 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0014); }
/* error exit handlers */
v0084:
    popv(4);
    return nil;
}



/* Code for wureducedpolysp */

static Lisp_Object CC_wureducedpolysp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wureducedpolysp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
    stack[-1] = v0000;
/* end of prologue */

v0094:
    v0087 = stack[0];
    if (v0087 == nil) goto v0005;
    v0088 = stack[-1];
    v0087 = stack[0];
    v0087 = qcar(v0087);
    fn = elt(env, 3); /* wureducedp */
    v0087 = (*qfn2(fn))(qenv(fn), v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-2];
    if (v0087 == nil) goto v0023;
    v0088 = stack[-1];
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    stack[-1] = v0088;
    stack[0] = v0087;
    goto v0094;

v0023:
    v0087 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0087); }

v0005:
    v0087 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0087); }
/* error exit handlers */
v0095:
    popv(3);
    return nil;
}



/* Code for ibalp_var!-satlist */

static Lisp_Object CC_ibalp_varKsatlist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-satlist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0015;
    v0110 = v0000;
/* end of prologue */
    stack[-5] = v0110;
    goto v0092;

v0092:
    v0110 = stack[-5];
    if (v0110 == nil) goto v0070;
    v0110 = stack[-5];
    v0110 = qcar(v0110);
    stack[-3] = v0110;
    v0110 = stack[-3];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    if (!(v0110 == nil)) goto v0112;
    v0110 = stack[-3];
    v0110 = qcar(v0110);
    stack[-2] = v0110;
    goto v0074;

v0074:
    v0110 = stack[-2];
    if (v0110 == nil) goto v0084;
    v0110 = stack[-2];
    v0110 = qcar(v0110);
    stack[-1] = v0110;
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    stack[0] = qcdr(v0110);
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    v0110 = sub1(v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0110 = (*qfn2(fn))(qenv(fn), stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    stack[0] = qcdr(v0110);
    v0110 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0110 = (*qfn2(fn))(qenv(fn), stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    v0110 = stack[-2];
    v0110 = qcdr(v0110);
    stack[-2] = v0110;
    goto v0074;

v0084:
    v0110 = stack[-3];
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    stack[-2] = v0110;
    goto v0004;

v0004:
    v0110 = stack[-2];
    if (v0110 == nil) goto v0003;
    v0110 = stack[-2];
    v0110 = qcar(v0110);
    stack[-1] = v0110;
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    stack[0] = qcdr(v0110);
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    v0110 = sub1(v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0110 = (*qfn2(fn))(qenv(fn), stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    stack[0] = qcdr(v0110);
    v0110 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0110 = (*qfn2(fn))(qenv(fn), stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    v0110 = stack[-2];
    v0110 = qcdr(v0110);
    stack[-2] = v0110;
    goto v0004;

v0003:
    v0110 = stack[-3];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    stack[-1] = v0110;
    goto v0051;

v0051:
    v0110 = stack[-1];
    if (v0110 == nil) goto v0114;
    v0110 = stack[-1];
    v0110 = qcar(v0110);
    v0111 = v0110;
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    v0111 = qcdr(v0111);
    stack[0] = qcdr(v0111);
    v0111 = stack[-3];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    fn = elt(env, 4); /* delq */
    v0110 = (*qfn2(fn))(qenv(fn), v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0110 = (*qfn2(fn))(qenv(fn), stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    v0110 = stack[-1];
    v0110 = qcdr(v0110);
    stack[-1] = v0110;
    goto v0051;

v0114:
    v0110 = stack[-3];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0111 = qcdr(v0110);
    v0110 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v0110 = (*qfn2(fn))(qenv(fn), v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    goto v0112;

v0112:
    v0110 = stack[-3];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    stack[0] = qcdr(v0110);
    v0111 = stack[-4];
    v0110 = stack[-3];
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcdr(v0110);
    v0110 = qcar(v0110);
    v0110 = cons(v0111, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0110 = (*qfn2(fn))(qenv(fn), stack[0], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0113;
    env = stack[-6];
    v0110 = stack[-5];
    v0110 = qcdr(v0110);
    stack[-5] = v0110;
    goto v0092;

v0070:
    v0110 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0110); }
/* error exit handlers */
v0113:
    popv(7);
    return nil;
}



/* Code for getcomb */

static Lisp_Object CC_getcomb(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0109, v0115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getcomb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0109 = v0015;
    stack[0] = v0000;
/* end of prologue */
    v0115 = v0109;
    v0109 = qvalue(elt(env, 1)); /* i */
    fn = elt(env, 4); /* nextcomb */
    v0109 = (*qfn2(fn))(qenv(fn), v0115, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    qvalue(elt(env, 2)) = v0109; /* comb */
    v0109 = qvalue(elt(env, 2)); /* comb */
    v0109 = qcar(v0109);
    v0115 = qvalue(elt(env, 2)); /* comb */
    v0115 = qcdr(v0115);
    qvalue(elt(env, 2)) = v0115; /* comb */
    v0115 = v0109;
    if (v0115 == nil) goto v0033;
    stack[-1] = v0109;
    v0115 = stack[0];
    fn = elt(env, 5); /* setdiff */
    v0109 = (*qfn2(fn))(qenv(fn), v0115, v0109);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    {
        Lisp_Object v0116 = stack[-1];
        popv(3);
        return cons(v0116, v0109);
    }

v0033:
    v0109 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v0109); }
/* error exit handlers */
v0021:
    popv(3);
    return nil;
}



/* Code for setdmode1 */

static Lisp_Object CC_setdmode1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132, v0133, v0134, v0135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setdmode1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v0133 = v0015;
    stack[-5] = v0000;
/* end of prologue */
    v0134 = stack[-5];
    v0132 = elt(env, 1); /* tag */
    v0132 = get(v0134, v0132);
    env = stack[-7];
    stack[-6] = v0132;
    v0132 = qvalue(elt(env, 2)); /* dmode!* */
    stack[-4] = v0132;
    v0132 = v0133;
    if (v0132 == nil) goto v0083;
    v0133 = stack[-5];
    v0132 = elt(env, 5); /* (rounded complex!-rounded) */
    v0132 = Lmemq(nil, v0133, v0132);
    if (v0132 == nil) goto v0062;
    fn = elt(env, 12); /* !!mfefix */
    v0132 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    goto v0062;

v0062:
    v0133 = stack[-6];
    v0132 = stack[-4];
    if (v0133 == v0132) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v0133 = stack[-6];
    v0132 = elt(env, 6); /* realtype */
    v0132 = get(v0133, v0132);
    env = stack[-7];
    stack[-3] = v0132;
    if (!(v0132 == nil)) goto v0082;
    v0132 = stack[-6];
    stack[-3] = v0132;
    goto v0082;

v0082:
    v0132 = qvalue(elt(env, 7)); /* domainlist!* */
    stack[-2] = v0132;
    goto v0137;

v0137:
    v0132 = stack[-2];
    if (v0132 == nil) goto v0138;
    v0132 = stack[-2];
    v0132 = qcar(v0132);
    stack[-1] = v0132;
    v0133 = stack[-1];
    v0132 = elt(env, 8); /* !:gi!: */
    if (v0133 == v0132) goto v0139;
    v0133 = stack[-1];
    v0132 = stack[-3];
    v0132 = (v0133 == v0132 ? lisp_true : nil);
    v0132 = (v0132 == nil ? lisp_true : nil);
    goto v0059;

v0059:
    if (v0132 == nil) goto v0140;
    v0132 = elt(env, 9); /* !* */
    stack[0] = Lexplode(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    v0132 = stack[-1];
    if (!symbolp(v0132)) v0132 = nil;
    else { v0132 = qfastgets(v0132);
           if (v0132 != nil) { v0132 = elt(v0132, 8); /* dname */
#ifdef RECORD_GET
             if (v0132 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0132 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0132 == SPID_NOPROP) v0132 = nil; }}
#endif
    v0132 = Lexplode(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    v0132 = Lappend(nil, stack[0], v0132);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    v0132 = Lcompress(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    v0133 = Lintern(nil, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    v0132 = qvalue(elt(env, 3)); /* nil */
    v0132 = Lset(nil, v0133, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    goto v0140;

v0140:
    v0132 = stack[-2];
    v0132 = qcdr(v0132);
    stack[-2] = v0132;
    goto v0137;

v0139:
    v0132 = qvalue(elt(env, 3)); /* nil */
    goto v0059;

v0138:
    fn = elt(env, 13); /* rmsubs */
    v0132 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    v0132 = stack[-4];
    if (!symbolp(v0132)) v0132 = nil;
    else { v0132 = qfastgets(v0132);
           if (v0132 != nil) { v0132 = elt(v0132, 8); /* dname */
#ifdef RECORD_GET
             if (v0132 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0132 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0132 == SPID_NOPROP) v0132 = nil; }}
#endif
    stack[-4] = v0132;
    v0132 = stack[-4];
    if (v0132 == nil) goto v0141;
    v0135 = elt(env, 10); /* "Domain mode" */
    v0134 = stack[-4];
    v0133 = elt(env, 11); /* "changed to" */
    v0132 = stack[-5];
    v0132 = list4(v0135, v0134, v0133, v0132);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    fn = elt(env, 14); /* lprim */
    v0132 = (*qfn1(fn))(qenv(fn), v0132);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    goto v0141;

v0141:
    v0132 = stack[-6];
    qvalue(elt(env, 2)) = v0132; /* dmode!* */
    qvalue(elt(env, 4)) = v0132; /* gdmode!* */
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v0083:
    v0132 = stack[-4];
    if (v0132 == nil) goto v0022;
    v0133 = stack[-5];
    v0132 = stack[-4];
    if (!symbolp(v0132)) v0132 = nil;
    else { v0132 = qfastgets(v0132);
           if (v0132 != nil) { v0132 = elt(v0132, 8); /* dname */
#ifdef RECORD_GET
             if (v0132 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0132 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0132 == SPID_NOPROP) v0132 = nil; }}
#endif
    stack[-4] = v0132;
    if (v0133 == v0132) goto v0085;
    v0133 = stack[-5];
    v0132 = stack[-4];
    {
        popv(8);
        fn = elt(env, 15); /* offmoderr */
        return (*qfn2(fn))(qenv(fn), v0133, v0132);
    }

v0085:
    fn = elt(env, 13); /* rmsubs */
    v0132 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-7];
    v0132 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v0132; /* dmode!* */
    qvalue(elt(env, 4)) = v0132; /* gdmode!* */
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v0022:
    v0132 = qvalue(elt(env, 3)); /* nil */
    { popv(8); return onevalue(v0132); }
/* error exit handlers */
v0136:
    popv(8);
    return nil;
}



/* Code for bcplus!? */

static Lisp_Object CC_bcplusW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0036;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcplus?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0035 = v0000;
/* end of prologue */
    v0035 = qcar(v0035);
    v0036 = v0035;
    v0035 = v0036;
    if (is_number(v0035)) goto v0027;
    v0035 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0035);

v0027:
    v0035 = (Lisp_Object)1; /* 0 */
        return Lgreaterp(nil, v0036, v0035);
}



/* Code for vevmaptozero1 */

static Lisp_Object CC_vevmaptozero1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevmaptozero1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0022 = v0015;
    stack[0] = v0000;
/* end of prologue */

v0005:
    v0014 = stack[0];
    if (v0014 == nil) { popv(2); return onevalue(v0022); }
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    v0014 = (Lisp_Object)1; /* 0 */
    v0022 = cons(v0014, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    goto v0005;
/* error exit handlers */
v0091:
    popv(2);
    return nil;
}



/* Code for noncommuting */

static Lisp_Object CC_noncommuting(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0108, v0082, v0144;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncommuting");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0108 = v0015;
    v0082 = v0000;
/* end of prologue */
    v0144 = nil;
    v0107 = v0082;
    if (!consp(v0107)) goto v0145;
    v0107 = v0082;
    v0107 = qcar(v0107);
    goto v0146;

v0146:
    v0082 = v0107;
    v0107 = v0108;
    if (!consp(v0107)) goto v0083;
    v0107 = v0108;
    v0107 = qcar(v0107);
    goto v0147;

v0147:
    v0108 = v0107;
    v0107 = v0082;
    if (!consp(v0107)) goto v0009;
    v0107 = v0082;
    v0107 = qcar(v0107);
    if (!symbolp(v0107)) v0107 = nil;
    else { v0107 = qfastgets(v0107);
           if (v0107 != nil) { v0107 = elt(v0107, 0); /* noncom */
#ifdef RECORD_GET
             if (v0107 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0107 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0107 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0107 == SPID_NOPROP) v0107 = nil; else v0107 = lisp_true; }}
#endif
    goto v0017;

v0017:
    if (v0107 == nil) return onevalue(v0144);
    v0107 = v0108;
    if (!consp(v0107)) goto v0001;
    v0107 = v0108;
    v0107 = qcar(v0107);
    if (!symbolp(v0107)) v0107 = nil;
    else { v0107 = qfastgets(v0107);
           if (v0107 != nil) { v0107 = elt(v0107, 0); /* noncom */
#ifdef RECORD_GET
             if (v0107 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0107 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0107 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0107 == SPID_NOPROP) v0107 = nil; else v0107 = lisp_true; }}
#endif
    goto v0116;

v0116:
    if (v0107 == nil) return onevalue(v0144);
    v0107 = elt(env, 2); /* noncommutes */
    v0107 = get(v0082, v0107);
    v0107 = Lmember(nil, v0108, v0107);
    v0144 = v0107;
    return onevalue(v0144);

v0001:
    v0107 = v0108;
    if (!symbolp(v0107)) v0107 = nil;
    else { v0107 = qfastgets(v0107);
           if (v0107 != nil) { v0107 = elt(v0107, 0); /* noncom */
#ifdef RECORD_GET
             if (v0107 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0107 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0107 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0107 == SPID_NOPROP) v0107 = nil; else v0107 = lisp_true; }}
#endif
    goto v0116;

v0009:
    v0107 = v0082;
    if (!symbolp(v0107)) v0107 = nil;
    else { v0107 = qfastgets(v0107);
           if (v0107 != nil) { v0107 = elt(v0107, 0); /* noncom */
#ifdef RECORD_GET
             if (v0107 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0107 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0107 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0107 == SPID_NOPROP) v0107 = nil; else v0107 = lisp_true; }}
#endif
    goto v0017;

v0083:
    v0107 = v0108;
    goto v0147;

v0145:
    v0107 = v0082;
    goto v0146;
}



/* Code for prop!-simp */

static Lisp_Object CC_propKsimp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0035, v0036, v0093, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prop-simp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0090 = v0015;
    v0035 = v0000;
/* end of prologue */
    v0022 = v0035;
    v0093 = v0090;
    v0036 = qvalue(elt(env, 1)); /* nil */
    v0035 = (Lisp_Object)1; /* 0 */
    v0090 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 2); /* prop!-simp1 */
        return (*qfnn(fn))(qenv(fn), 5, v0022, v0093, v0036, v0035, v0090);
    }
}



/* Code for xread1 */

static Lisp_Object CC_xread1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0340, v0341, v0342;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xread1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0000;
/* end of prologue */
    stack[-8] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v0340 = qvalue(elt(env, 1)); /* commentlist!* */
    if (v0340 == nil) goto v0008;
    v0340 = qvalue(elt(env, 1)); /* commentlist!* */
    stack[-1] = v0340;
    v0340 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v0340; /* commentlist!* */
    goto v0008;

v0008:
    v0340 = qvalue(elt(env, 3)); /* cursym!* */
    stack[-3] = v0340;
    goto v0023;

v0023:
    v0340 = stack[-3];
    if (!(symbolp(v0340))) goto v0007;
    v0341 = stack[-3];
    v0340 = elt(env, 4); /* !*lpar!* */
    if (v0341 == v0340) goto v0065;
    v0341 = stack[-3];
    v0340 = elt(env, 5); /* !*rpar!* */
    if (v0341 == v0340) goto v0083;
    v0340 = stack[-3];
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 23); /* infix */
#ifdef RECORD_GET
             if (v0340 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0340 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; }}
#endif
    stack[-4] = v0340;
    if (!(v0340 == nil)) goto v0090;
    v0340 = stack[-3];
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 55); /* delim */
#ifdef RECORD_GET
             if (v0340 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0340 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0340 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; else v0340 = lisp_true; }}
#endif
    if (v0340 == nil) goto v0028;
    v0341 = qvalue(elt(env, 3)); /* cursym!* */
    v0340 = elt(env, 40); /* !*semicol!* */
    if (v0341 == v0340) goto v0343;
    fn = elt(env, 48); /* eolcheck */
    v0340 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0343;

v0343:
    v0341 = stack[-3];
    v0340 = elt(env, 41); /* !*colon!* */
    if (v0341 == v0340) goto v0345;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0346;

v0346:
    if (!(v0340 == nil)) goto v0347;
    v0341 = stack[-3];
    v0340 = elt(env, 44); /* nodel */
    v0340 = Lflagp(nil, v0341, v0340);
    env = stack[-9];
    if (v0340 == nil) goto v0348;
    v0340 = stack[-7];
    if (v0340 == nil) goto v0349;
    v0341 = stack[-7];
    v0340 = elt(env, 22); /* group */
    if (v0341 == v0340) goto v0350;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0351;

v0351:
    if (!(v0340 == nil)) goto v0347;
    v0340 = stack[-7];
    if (!(symbolp(v0340))) goto v0032;
    v0341 = stack[-7];
    v0340 = elt(env, 17); /* paren */
    if (v0341 == v0340) goto v0352;
    v0341 = stack[-7];
    v0340 = elt(env, 16); /* struct */
    v0340 = Lflagp(nil, v0341, v0340);
    env = stack[-9];
    goto v0353;

v0353:
    if (v0340 == nil) goto v0032;
    v0341 = elt(env, 46); /* "Too few right parentheses" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0032;

v0032:
    v0340 = stack[-4];
    if (v0340 == nil) goto v0354;
    v0341 = elt(env, 20); /* "Improper delimiter" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0355;

v0355:
    v0340 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0340;
    goto v0022;

v0022:
    v0340 = stack[-6];
    if (!(v0340 == nil)) goto v0356;
    v0341 = elt(env, 20); /* "Improper delimiter" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0356;

v0356:
    v0340 = stack[-6];
    v0341 = qcar(v0340);
    v0340 = stack[-3];
    fn = elt(env, 50); /* mkvar */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[0] = v0340;
    goto v0014;

v0014:
    v0340 = stack[-6];
    v0340 = qcdr(v0340);
    stack[-6] = v0340;
    v0340 = stack[-6];
    if (v0340 == nil) goto v0357;
    v0340 = stack[-6];
    v0340 = qcar(v0340);
    if (!consp(v0340)) goto v0358;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0359;

v0359:
    if (v0340 == nil) goto v0360;
    v0341 = elt(env, 27); /* "Missing operator" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0360;

v0360:
    v0340 = stack[-6];
    v0341 = qcar(v0340);
    v0340 = stack[0];
    v0340 = list2(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[0] = v0340;
    goto v0014;

v0358:
    v0340 = stack[-6];
    v0340 = qcar(v0340);
    v0340 = Lsymbolp(nil, v0340);
    env = stack[-9];
    v0340 = (v0340 == nil ? lisp_true : nil);
    goto v0359;

v0357:
    v0341 = stack[0];
    v0340 = stack[-8];
    v0340 = cons(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-8] = v0340;
    goto v0091;

v0091:
    v0340 = stack[-5];
    if (v0340 == nil) goto v0361;
    v0341 = stack[-4];
    v0340 = stack[-5];
    v0340 = qcar(v0340);
    v0340 = qcar(v0340);
    v0340 = (Lisp_Object)lessp2(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    v0340 = v0340 ? lisp_true : nil;
    env = stack[-9];
    if (!(v0340 == nil)) goto v0362;
    v0341 = stack[-4];
    v0340 = stack[-5];
    v0340 = qcar(v0340);
    v0340 = qcar(v0340);
    if (equal(v0341, v0340)) goto v0363;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0364;

v0364:
    if (!(v0340 == nil)) goto v0362;

v0365:
    v0342 = stack[-4];
    v0341 = stack[-3];
    v0340 = stack[-5];
    v0340 = acons(v0342, v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-5] = v0340;
    v0341 = stack[-3];
    v0340 = elt(env, 18); /* !*comma!* */
    if (!(v0341 == v0340)) goto v0093;
    v0340 = stack[-5];
    v0340 = qcdr(v0340);
    if (!(v0340 == nil)) goto v0027;
    v0340 = stack[-7];
    if (v0340 == nil) goto v0366;
    v0341 = stack[-7];
    v0340 = elt(env, 29); /* (lambda paren) */
    v0340 = Lmemq(nil, v0341, v0340);
    if (!(v0340 == nil)) goto v0367;
    v0341 = stack[-7];
    v0340 = elt(env, 16); /* struct */
    v0340 = Lflagp(nil, v0341, v0340);
    env = stack[-9];
    goto v0367;

v0367:
    if (!(v0340 == nil)) goto v0027;

v0017:
    v0340 = stack[-8];
    v0340 = qcdr(v0340);
    if (v0340 == nil) goto v0368;
    v0340 = elt(env, 47); /* "Please send hearn@rand.org your program!!" 
*/
    v0340 = Lprint(nil, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    v0341 = elt(env, 20); /* "Improper delimiter" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    v0340 = nil;
    { popv(10); return onevalue(v0340); }

v0368:
    v0340 = stack[-8];
    v0341 = qcar(v0340);
    v0340 = stack[-1];
    {
        popv(10);
        fn = elt(env, 51); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v0341, v0340);
    }

v0027:
    fn = elt(env, 52); /* scan */
    v0340 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-3] = v0340;
    goto v0023;

v0366:
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0367;

v0093:
    v0340 = stack[-2];
    stack[-3] = v0340;
    goto v0023;

v0362:
    v0340 = stack[-8];
    v0340 = qcdr(v0340);
    v0341 = qcar(v0340);
    v0340 = elt(env, 30); /* not */
    if (!consp(v0341)) goto v0369;
    v0341 = qcar(v0341);
    if (!(v0341 == v0340)) goto v0369;
    v0340 = stack[-5];
    v0340 = qcar(v0340);
    v0341 = qcar(v0340);
    v0340 = elt(env, 31); /* member */
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 23); /* infix */
#ifdef RECORD_GET
             if (v0340 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0340 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; }}
#endif
    v0340 = (Lisp_Object)geq2(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    v0340 = v0340 ? lisp_true : nil;
    env = stack[-9];
    goto v0370;

v0370:
    if (v0340 == nil) goto v0371;
    v0341 = elt(env, 32); /* "NOT" */
    v0340 = elt(env, 33); /* "infix operator" */
    fn = elt(env, 53); /* typerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0371;

v0371:
    v0340 = stack[-8];
    v0340 = qcdr(v0340);
    v0341 = qcar(v0340);
    v0340 = elt(env, 26); /* !*!*un!*!* */
    if (v0341 == v0340) goto v0372;
    v0340 = stack[-5];
    v0340 = qcar(v0340);
    stack[0] = qcdr(v0340);
    v0340 = stack[-8];
    v0341 = qcar(v0340);
    v0340 = stack[-5];
    v0340 = qcar(v0340);
    v0340 = qcdr(v0340);
    if (!consp(v0341)) goto v0373;
    v0341 = qcar(v0341);
    if (!(v0341 == v0340)) goto v0373;
    v0340 = stack[-5];
    v0340 = qcar(v0340);
    v0340 = qcdr(v0340);
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 35); /* nary */
#ifdef RECORD_GET
             if (v0340 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v0340 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v0340 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; else v0340 = lisp_true; }}
#endif
    goto v0374;

v0374:
    if (v0340 == nil) goto v0375;
    v0340 = stack[-8];
    v0340 = qcdr(v0340);
    v0341 = qcar(v0340);
    v0340 = stack[-8];
    v0340 = qcar(v0340);
    v0340 = qcdr(v0340);
    v0340 = cons(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0376;

v0376:
    v0340 = cons(stack[0], v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[0] = v0340;
    goto v0377;

v0377:
    v0340 = stack[-5];
    v0340 = qcdr(v0340);
    stack[-5] = v0340;
    v0341 = stack[0];
    v0340 = stack[-8];
    v0340 = qcdr(v0340);
    v0340 = qcdr(v0340);
    v0340 = cons(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-8] = v0340;
    goto v0091;

v0375:
    v0340 = stack[-8];
    v0340 = qcdr(v0340);
    v0341 = qcar(v0340);
    v0340 = stack[-8];
    v0340 = qcar(v0340);
    v0340 = list2(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0376;

v0373:
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0374;

v0372:
    v0340 = stack[-8];
    v0341 = qcar(v0340);
    v0340 = elt(env, 26); /* !*!*un!*!* */
    if (v0341 == v0340) goto v0365;
    v0340 = stack[-5];
    v0340 = qcar(v0340);
    v0341 = qcdr(v0340);
    v0340 = stack[-8];
    v0340 = qcar(v0340);
    v0340 = list2(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[0] = v0340;
    goto v0377;

v0369:
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0370;

v0363:
    v0341 = stack[-3];
    v0340 = stack[-5];
    v0340 = qcar(v0340);
    v0340 = qcdr(v0340);
    if (v0341 == v0340) goto v0378;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0379;

v0379:
    if (v0340 == nil) goto v0380;
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0364;

v0380:
    v0340 = stack[-5];
    v0340 = qcar(v0340);
    v0340 = qcdr(v0340);
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 49); /* alt */
#ifdef RECORD_GET
             if (v0340 != SPID_NOPROP)
                record_get(elt(fastget_names, 49), 1);
             else record_get(elt(fastget_names, 49), 0),
                v0340 = nil; }
           else record_get(elt(fastget_names, 49), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; }}
#endif
    goto v0364;

v0378:
    v0340 = stack[-3];
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 35); /* nary */
#ifdef RECORD_GET
             if (v0340 == SPID_NOPROP)
                record_get(elt(fastget_names, 35), 0),
                v0340 = nil;
             else record_get(elt(fastget_names, 35), 1),
                v0340 = lisp_true; }
           else record_get(elt(fastget_names, 35), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; else v0340 = lisp_true; }}
#endif
    if (v0340 == nil) goto v0381;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0379;

v0381:
    v0341 = stack[-3];
    v0340 = elt(env, 28); /* right */
    v0340 = Lflagp(nil, v0341, v0340);
    env = stack[-9];
    v0340 = (v0340 == nil ? lisp_true : nil);
    goto v0379;

v0361:
    v0341 = stack[-4];
    v0340 = (Lisp_Object)1; /* 0 */
    if (v0341 == v0340) goto v0017;
    else goto v0365;

v0354:
    v0340 = stack[-8];
    if (v0340 == nil) goto v0382;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0383;

v0383:
    if (v0340 == nil) goto v0355;
    v0341 = qvalue(elt(env, 2)); /* nil */
    v0340 = stack[-1];
    {
        popv(10);
        fn = elt(env, 51); /* xcomment */
        return (*qfn2(fn))(qenv(fn), v0341, v0340);
    }

v0382:
    v0340 = stack[-6];
    if (v0340 == nil) goto v0384;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0383;

v0384:
    v0340 = stack[-5];
    v0340 = (v0340 == nil ? lisp_true : nil);
    goto v0383;

v0352:
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0353;

v0347:
    v0341 = elt(env, 20); /* "Improper delimiter" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0032;

v0350:
    v0341 = stack[-3];
    v0340 = elt(env, 45); /* (!*rsqbkt!* !*rcbkt!* !*rsqb!*) */
    v0340 = Lmemq(nil, v0341, v0340);
    v0340 = (v0340 == nil ? lisp_true : nil);
    goto v0351;

v0349:
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0351;

v0348:
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0351;

v0345:
    v0341 = stack[-7];
    v0340 = elt(env, 42); /* for */
    if (v0341 == v0340) goto v0385;
    v0340 = qvalue(elt(env, 43)); /* !*blockp */
    if (v0340 == nil) goto v0386;
    v0340 = stack[-6];
    if (v0340 == nil) goto v0387;
    v0340 = stack[-6];
    v0340 = qcar(v0340);
    if (!consp(v0340)) goto v0388;
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0346;

v0388:
    v0340 = stack[-6];
    v0340 = qcdr(v0340);
    goto v0346;

v0387:
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0346;

v0386:
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0346;

v0385:
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0346;

v0028:
    v0340 = stack[-3];
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 36); /* stat */
#ifdef RECORD_GET
             if (v0340 != SPID_NOPROP)
                record_get(elt(fastget_names, 36), 1);
             else record_get(elt(fastget_names, 36), 0),
                v0340 = nil; }
           else record_get(elt(fastget_names, 36), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; }}
#endif
    stack[-4] = v0340;
    if (v0340 == nil) goto v0013;
    v0341 = stack[-4];
    v0340 = elt(env, 34); /* endstat */
    if (v0341 == v0340) goto v0389;
    fn = elt(env, 48); /* eolcheck */
    v0340 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0389;

v0389:
    v0341 = stack[-3];
    v0340 = elt(env, 35); /* go */
    v0340 = Lflagp(nil, v0341, v0340);
    env = stack[-9];
    if (v0340 == nil) goto v0390;
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0391;

v0391:
    if (v0340 == nil) goto v0007;
    v0341 = stack[-3];
    v0340 = elt(env, 38); /* procedure */
    if (v0341 == v0340) goto v0392;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0393;

v0393:
    if (v0340 == nil) goto v0394;
    v0340 = stack[-6];
    if (v0340 == nil) goto v0395;
    v0340 = stack[-6];
    v0340 = qcdr(v0340);
    if (!(v0340 == nil)) goto v0396;
    v0340 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (!(v0340 == nil)) goto v0396;
    v0340 = stack[-6];
    v0340 = qcar(v0340);
    fn = elt(env, 54); /* procstat1 */
    v0340 = (*qfn1(fn))(qenv(fn), v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    v0340 = ncons(v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-6] = v0340;
    goto v0397;

v0397:
    v0340 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0340;
    goto v0008;

v0396:
    v0341 = elt(env, 39); /* "proc form" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0397;

v0395:
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 54); /* procstat1 */
    v0340 = (*qfn1(fn))(qenv(fn), v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    v0340 = ncons(v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-6] = v0340;
    goto v0397;

v0394:
    v0341 = stack[-4];
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 55); /* lispapply */
    v0341 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    v0340 = stack[-6];
    v0340 = cons(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-6] = v0340;
    goto v0397;

v0392:
    v0340 = qvalue(elt(env, 6)); /* !*reduce4 */
    goto v0393;

v0007:
    v0340 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0340;
    goto v0398;

v0398:
    v0341 = stack[-3];
    v0340 = stack[-6];
    v0340 = cons(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-6] = v0340;
    v0340 = stack[-3];
    fn = elt(env, 56); /* toknump */
    v0340 = (*qfn1(fn))(qenv(fn), v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    if (v0340 == nil) goto v0100;
    v0341 = stack[-2];
    v0340 = qvalue(elt(env, 9)); /* !$eol!$ */
    if (v0341 == v0340) goto v0399;
    v0340 = qvalue(elt(env, 10)); /* nxtsym!* */
    fn = elt(env, 57); /* chknewnam */
    v0340 = (*qfn1(fn))(qenv(fn), v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-2] = v0340;
    if (symbolp(v0340)) goto v0122;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0139;

v0139:
    if (v0340 == nil) goto v0100;
    v0340 = elt(env, 13); /* times */
    qvalue(elt(env, 3)) = v0340; /* cursym!* */
    goto v0008;

v0100:
    v0341 = stack[-7];
    v0340 = elt(env, 14); /* proc */
    if (v0341 == v0340) goto v0400;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0401;

v0401:
    if (v0340 == nil) goto v0027;
    v0341 = elt(env, 15); /* "Syntax error in procedure header" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0027;

v0400:
    v0340 = stack[-6];
    v0341 = Llength(nil, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    v0340 = (Lisp_Object)33; /* 2 */
    v0340 = (Lisp_Object)greaterp2(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    v0340 = v0340 ? lisp_true : nil;
    env = stack[-9];
    goto v0401;

v0122:
    v0340 = stack[-2];
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 55); /* delim */
#ifdef RECORD_GET
             if (v0340 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0340 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0340 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; else v0340 = lisp_true; }}
#endif
    if (v0340 == nil) goto v0402;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0139;

v0402:
    v0340 = stack[-2];
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 11); /* switch!* */
#ifdef RECORD_GET
             if (v0340 != SPID_NOPROP)
                record_get(elt(fastget_names, 11), 1);
             else record_get(elt(fastget_names, 11), 0),
                v0340 = nil; }
           else record_get(elt(fastget_names, 11), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; }}
#endif
    if (v0340 == nil) goto v0403;
    v0341 = stack[-2];
    v0340 = elt(env, 11); /* !( */
    if (v0341 == v0340) goto v0403;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0139;

v0403:
    v0340 = stack[-2];
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 23); /* infix */
#ifdef RECORD_GET
             if (v0340 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0340 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; }}
#endif
    if (v0340 == nil) goto v0404;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0139;

v0404:
    v0340 = qvalue(elt(env, 12)); /* !*eoldelimp */
    if (v0340 == nil) goto v0046;
    v0341 = stack[-2];
    v0340 = qvalue(elt(env, 9)); /* !$eol!$ */
    v0340 = (v0341 == v0340 ? lisp_true : nil);
    goto v0118;

v0118:
    v0340 = (v0340 == nil ? lisp_true : nil);
    goto v0139;

v0046:
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0118;

v0399:
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0139;

v0390:
    v0341 = stack[-7];
    v0340 = elt(env, 14); /* proc */
    if (v0341 == v0340) goto v0405;
    v0341 = stack[-4];
    v0340 = elt(env, 36); /* endstatfn */
    v0340 = Lflagp(nil, v0341, v0340);
    env = stack[-9];
    if (v0340 == nil) goto v0406;
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0391;

v0406:
    v0340 = qvalue(elt(env, 10)); /* nxtsym!* */
    fn = elt(env, 58); /* delcp */
    v0340 = (*qfn1(fn))(qenv(fn), v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    if (v0340 == nil) goto v0407;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0391;

v0407:
    v0341 = qvalue(elt(env, 10)); /* nxtsym!* */
    v0340 = elt(env, 37); /* !, */
    v0340 = (v0341 == v0340 ? lisp_true : nil);
    v0340 = (v0340 == nil ? lisp_true : nil);
    goto v0391;

v0405:
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0391;

v0013:
    v0340 = qvalue(elt(env, 6)); /* !*reduce4 */
    if (v0340 == nil) goto v0061;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0408;

v0408:
    if (v0340 == nil) goto v0007;
    v0341 = elt(env, 8); /* decstat */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 55); /* lispapply */
    v0341 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    v0340 = stack[-6];
    v0340 = cons(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-6] = v0340;
    goto v0008;

v0061:
    v0341 = stack[-3];
    v0340 = elt(env, 7); /* type */
    v0340 = Lflagp(nil, v0341, v0340);
    env = stack[-9];
    goto v0408;

v0090:
    fn = elt(env, 48); /* eolcheck */
    v0340 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    v0341 = stack[-3];
    v0340 = elt(env, 18); /* !*comma!* */
    if (v0341 == v0340) goto v0409;
    fn = elt(env, 52); /* scan */
    v0340 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-2] = v0340;
    if (!consp(v0340)) goto v0410;
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0411;

v0411:
    if (!(v0340 == nil)) goto v0035;
    v0341 = stack[-2];
    v0340 = elt(env, 5); /* !*rpar!* */
    if (v0341 == v0340) goto v0412;
    v0341 = stack[-2];
    v0340 = elt(env, 18); /* !*comma!* */
    if (v0341 == v0340) goto v0413;
    v0340 = stack[-2];
    if (!symbolp(v0340)) v0340 = nil;
    else { v0340 = qfastgets(v0340);
           if (v0340 != nil) { v0340 = elt(v0340, 55); /* delim */
#ifdef RECORD_GET
             if (v0340 == SPID_NOPROP)
                record_get(elt(fastget_names, 55), 0),
                v0340 = nil;
             else record_get(elt(fastget_names, 55), 1),
                v0340 = lisp_true; }
           else record_get(elt(fastget_names, 55), 0); }
#else
             if (v0340 == SPID_NOPROP) v0340 = nil; else v0340 = lisp_true; }}
#endif
    goto v0414;

v0414:
    if (v0340 == nil) goto v0415;
    v0340 = stack[-4];
    if (v0340 == nil) goto v0416;
    v0340 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0340;
    goto v0416;

v0416:
    v0341 = stack[-3];
    v0340 = stack[-6];
    v0340 = cons(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-6] = v0340;
    goto v0093;

v0415:
    v0341 = stack[-2];
    v0340 = elt(env, 4); /* !*lpar!* */
    if (v0341 == v0340) goto v0417;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0418;

v0418:
    if (!(v0340 == nil)) goto v0023;

v0035:
    v0340 = stack[-6];
    if (!(v0340 == nil)) goto v0022;
    v0341 = stack[-3];
    v0340 = elt(env, 24); /* unary */
    v0340 = get(v0341, v0340);
    env = stack[-9];
    stack[-3] = v0340;
    if (!(v0340 == nil)) goto v0419;
    v0341 = elt(env, 25); /* "Redundant operator" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0419;

v0419:
    v0341 = elt(env, 26); /* !*!*un!*!* */
    v0340 = stack[-8];
    v0340 = cons(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-8] = v0340;
    goto v0365;

v0417:
    fn = elt(env, 48); /* eolcheck */
    v0340 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    if (v0340 == nil) goto v0420;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0418;

v0420:
    v0340 = elt(env, 17); /* paren */
    fn = elt(env, 59); /* xread */
    v0340 = (*qfn1(fn))(qenv(fn), v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-2] = v0340;
    if (!consp(v0340)) goto v0421;
    v0340 = stack[-2];
    v0341 = qcar(v0340);
    v0340 = elt(env, 18); /* !*comma!* */
    if (v0341 == v0340) goto v0422;
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0418;

v0422:
    v0341 = stack[-3];
    v0340 = stack[-2];
    v0340 = qcdr(v0340);
    v0340 = cons(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-3] = v0340;
    goto v0418;

v0421:
    v0340 = qvalue(elt(env, 2)); /* nil */
    goto v0418;

v0413:
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0414;

v0412:
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0414;

v0410:
    v0340 = stack[-2];
    fn = elt(env, 56); /* toknump */
    v0340 = (*qfn1(fn))(qenv(fn), v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0411;

v0409:
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0411;

v0083:
    v0340 = stack[-7];
    if (v0340 == nil) goto v0423;
    v0341 = stack[-7];
    v0340 = elt(env, 22); /* group */
    if (v0341 == v0340) goto v0424;
    v0341 = stack[-7];
    v0340 = elt(env, 14); /* proc */
    v0340 = (v0341 == v0340 ? lisp_true : nil);
    goto v0425;

v0425:
    if (v0340 == nil) goto v0032;
    v0341 = elt(env, 23); /* "Too many right parentheses" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0090;

v0424:
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0425;

v0423:
    v0340 = qvalue(elt(env, 21)); /* t */
    goto v0425;

v0065:
    fn = elt(env, 48); /* eolcheck */
    v0340 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    v0340 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v0340;
    fn = elt(env, 52); /* scan */
    v0341 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    v0340 = elt(env, 5); /* !*rpar!* */
    if (v0341 == v0340) goto v0147;
    v0341 = stack[-6];
    v0340 = elt(env, 16); /* struct */
    v0340 = Lflagpcar(nil, v0341, v0340);
    env = stack[-9];
    if (v0340 == nil) goto v0426;
    v0340 = stack[-6];
    v0340 = qcar(v0340);
    v0340 = CC_xread1(env, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-3] = v0340;
    goto v0427;

v0427:
    v0341 = stack[-7];
    v0340 = elt(env, 16); /* struct */
    v0340 = Lflagp(nil, v0341, v0340);
    env = stack[-9];
    if (v0340 == nil) goto v0428;
    v0340 = stack[-3];
    fn = elt(env, 60); /* remcomma */
    v0340 = (*qfn1(fn))(qenv(fn), v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-3] = v0340;
    goto v0398;

v0428:
    v0341 = stack[-3];
    v0340 = elt(env, 18); /* !*comma!* */
    if (!consp(v0341)) goto v0398;
    v0341 = qcar(v0341);
    if (!(v0341 == v0340)) goto v0398;
    v0340 = stack[-6];
    if (v0340 == nil) goto v0429;
    v0340 = stack[-6];
    v0342 = qcar(v0340);
    v0340 = stack[-3];
    v0341 = qcdr(v0340);
    v0340 = stack[-6];
    v0340 = qcdr(v0340);
    v0340 = acons(v0342, v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-6] = v0340;
    goto v0027;

v0429:
    v0341 = stack[-7];
    v0340 = elt(env, 19); /* lambda */
    if (v0341 == v0340) goto v0398;
    v0341 = elt(env, 20); /* "Improper delimiter" */
    v0340 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 49); /* symerr */
    v0340 = (*qfn2(fn))(qenv(fn), v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    goto v0027;

v0426:
    v0340 = elt(env, 17); /* paren */
    v0340 = CC_xread1(env, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-3] = v0340;
    goto v0427;

v0147:
    v0340 = stack[-6];
    if (v0340 == nil) goto v0027;
    v0340 = stack[-6];
    v0340 = qcar(v0340);
    v0341 = ncons(v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    v0340 = stack[-6];
    v0340 = qcdr(v0340);
    v0340 = cons(v0341, v0340);
    nil = C_nil;
    if (exception_pending()) goto v0344;
    env = stack[-9];
    stack[-6] = v0340;
    goto v0027;
/* error exit handlers */
v0344:
    popv(10);
    return nil;
}



/* Code for setel */

static Lisp_Object CC_setel(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0064, v0081, v0431, v0012;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0015;
    stack[-2] = v0000;
/* end of prologue */
    v0064 = stack[-2];
    v0081 = qcar(v0064);
    v0064 = elt(env, 1); /* dimension */
    v0064 = get(v0081, v0064);
    env = stack[-4];
    stack[-3] = v0064;
    v0064 = stack[-3];
    stack[0] = Llength(nil, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0064 = stack[-2];
    v0064 = qcdr(v0064);
    v0064 = Llength(nil, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    if (equal(stack[0], v0064)) goto v0109;
    v0431 = elt(env, 2); /* rlisp */
    v0081 = (Lisp_Object)353; /* 22 */
    v0064 = elt(env, 3); /* "Incorrect array reference" */
    {
        popv(5);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0431, v0081, v0064);
    }

v0109:
    v0064 = stack[-2];
    v0064 = qcar(v0064);
    if (!symbolp(v0064)) v0064 = nil;
    else { v0064 = qfastgets(v0064);
           if (v0064 != nil) { v0064 = elt(v0064, 4); /* avalue */
#ifdef RECORD_GET
             if (v0064 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0064 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0064 == SPID_NOPROP) v0064 = nil; }}
#endif
    v0064 = qcdr(v0064);
    v0012 = qcar(v0064);
    v0064 = stack[-2];
    v0431 = qcdr(v0064);
    v0081 = stack[-1];
    v0064 = stack[-3];
    {
        popv(5);
        fn = elt(env, 5); /* setel1 */
        return (*qfnn(fn))(qenv(fn), 4, v0012, v0431, v0081, v0064);
    }
/* error exit handlers */
v0026:
    popv(5);
    return nil;
}



/* Code for !:expt */

static Lisp_Object CC_Texpt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0326, v0327, v0446;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :expt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0015;
    stack[-4] = v0000;
/* end of prologue */
    v0326 = stack[-4];
    if (v0326 == nil) goto v0008;
    v0327 = stack[-3];
    v0326 = (Lisp_Object)1; /* 0 */
    if (v0327 == v0326) goto v0017;
    v0327 = stack[-3];
    v0326 = (Lisp_Object)17; /* 1 */
    if (v0327 == v0326) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v0327 = stack[-4];
    v0326 = (Lisp_Object)17; /* 1 */
    if (v0327 == v0326) goto v0019;
    v0327 = stack[-3];
    v0326 = (Lisp_Object)1; /* 0 */
    v0326 = (Lisp_Object)lessp2(v0327, v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    v0326 = v0326 ? lisp_true : nil;
    env = stack[-6];
    if (v0326 == nil) goto v0011;
    v0326 = stack[-4];
    fn = elt(env, 5); /* fieldp */
    v0326 = (*qfn1(fn))(qenv(fn), v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    if (v0326 == nil) goto v0106;
    v0326 = stack[-4];
    stack[0] = v0326;
    goto v0107;

v0107:
    v0326 = stack[-3];
    v0326 = negate(v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0326 = CC_Texpt(env, stack[0], v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 6); /* !:recip */
        return (*qfn1(fn))(qenv(fn), v0326);
    }

v0106:
    v0326 = stack[-4];
    fn = elt(env, 7); /* mkratnum */
    v0326 = (*qfn1(fn))(qenv(fn), v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[0] = v0326;
    goto v0107;

v0011:
    v0326 = stack[-4];
    if (!consp(v0326)) goto v0057;
    v0326 = stack[-4];
    v0327 = qcar(v0326);
    v0326 = elt(env, 4); /* expt */
    v0326 = get(v0327, v0326);
    env = stack[-6];
    stack[-2] = v0326;
    if (v0326 == nil) goto v0335;
    v0446 = stack[-2];
    v0327 = stack[-4];
    v0326 = stack[-3];
        popv(7);
        return Lapply2(nil, 3, v0446, v0327, v0326);

v0335:
    v0326 = stack[-4];
    v0326 = qcar(v0326);
    if (!symbolp(v0326)) v0327 = nil;
    else { v0327 = qfastgets(v0326);
           if (v0327 != nil) { v0327 = elt(v0327, 34); /* i2d */
#ifdef RECORD_GET
             if (v0327 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0327 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0327 == SPID_NOPROP) v0327 = nil; }}
#endif
    v0326 = (Lisp_Object)17; /* 1 */
    v0326 = Lapply1(nil, v0327, v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[-5] = v0326;
    v0326 = stack[-4];
    v0326 = qcar(v0326);
    if (!symbolp(v0326)) v0326 = nil;
    else { v0326 = qfastgets(v0326);
           if (v0326 != nil) { v0326 = elt(v0326, 54); /* times */
#ifdef RECORD_GET
             if (v0326 != SPID_NOPROP)
                record_get(elt(fastget_names, 54), 1);
             else record_get(elt(fastget_names, 54), 0),
                v0326 = nil; }
           else record_get(elt(fastget_names, 54), 0); }
#else
             if (v0326 == SPID_NOPROP) v0326 = nil; }}
#endif
    stack[-2] = v0326;
    goto v0447;

v0447:
    v0326 = stack[-3];
    stack[-1] = v0326;
    stack[0] = (Lisp_Object)33; /* 2 */
    v0327 = stack[-3];
    v0326 = (Lisp_Object)33; /* 2 */
    v0326 = quot2(v0327, v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[-3] = v0326;
    v0326 = times2(stack[0], v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0327 = difference2(stack[-1], v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0326 = (Lisp_Object)1; /* 0 */
    if (v0327 == v0326) goto v0069;
    v0446 = stack[-2];
    v0327 = stack[-4];
    v0326 = stack[-5];
    v0326 = Lapply2(nil, 3, v0446, v0327, v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[-5] = v0326;
    goto v0069;

v0069:
    v0327 = stack[-3];
    v0326 = (Lisp_Object)1; /* 0 */
    if (v0327 == v0326) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v0446 = stack[-2];
    v0327 = stack[-4];
    v0326 = stack[-4];
    v0326 = Lapply2(nil, 3, v0446, v0327, v0326);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[-4] = v0326;
    goto v0447;

v0057:
    v0327 = stack[-4];
    v0326 = stack[-3];
        popv(7);
        return Lexpt(nil, v0327, v0326);

v0019:
    v0326 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v0326); }

v0017:
    v0326 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v0326); }

v0008:
    v0327 = stack[-3];
    v0326 = (Lisp_Object)1; /* 0 */
    if (v0327 == v0326) goto v0090;
    v0326 = qvalue(elt(env, 3)); /* nil */
    { popv(7); return onevalue(v0326); }

v0090:
    v0446 = elt(env, 1); /* poly */
    v0327 = (Lisp_Object)177; /* 11 */
    v0326 = elt(env, 2); /* "0/0 formed" */
    {
        popv(7);
        fn = elt(env, 8); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0446, v0327, v0326);
    }
/* error exit handlers */
v0097:
    popv(7);
    return nil;
}



/* Code for in_list1 */

static Lisp_Object CC_in_list1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0007, v0066, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for in_list1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0007 = v0015;
    v0066 = v0000;
/* end of prologue */
    v0027 = v0066;
    v0066 = v0007;
    v0007 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* in_list1a */
        return (*qfnn(fn))(qenv(fn), 3, v0027, v0066, v0007);
    }
}



/* Code for ofsf_entry2at1 */

static Lisp_Object MS_CDECL CC_ofsf_entry2at1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0095, v0109;
    Lisp_Object fn;
    Lisp_Object v0042, v0015, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    v0042 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_entry2at1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0042,v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0015,v0042);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0042;
    stack[-1] = v0015;
    v0034 = v0000;
/* end of prologue */
    v0095 = stack[-1];
    v0109 = qcar(v0095);
    v0095 = v0034;
    v0034 = elt(env, 1); /* and */
    v0034 = (v0095 == v0034 ? lisp_true : nil);
    fn = elt(env, 3); /* ofsf_clnegrel */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0109, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-3];
    v0095 = stack[0];
    v0034 = stack[-1];
    v0034 = qcdr(v0034);
    fn = elt(env, 4); /* addsq */
    v0034 = (*qfn2(fn))(qenv(fn), v0095, v0034);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-3];
    v0034 = qcar(v0034);
    v0095 = qvalue(elt(env, 2)); /* nil */
    {
        Lisp_Object v0116 = stack[-2];
        popv(4);
        return list3(v0116, v0034, v0095);
    }
/* error exit handlers */
v0021:
    popv(4);
    return nil;
}



/* Code for qremd */

static Lisp_Object CC_qremd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0105, v0335;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qremd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0015;
    stack[-2] = v0000;
/* end of prologue */
    v0105 = stack[-2];
    if (v0105 == nil) goto v0145;
    v0335 = stack[-1];
    v0105 = (Lisp_Object)17; /* 1 */
    if (v0335 == v0105) goto v0027;
    v0105 = qvalue(elt(env, 1)); /* dmode!* */
    if (!symbolp(v0105)) v0105 = nil;
    else { v0105 = qfastgets(v0105);
           if (v0105 != nil) { v0105 = elt(v0105, 3); /* field */
#ifdef RECORD_GET
             if (v0105 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0105 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0105 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0105 == SPID_NOPROP) v0105 = nil; else v0105 = lisp_true; }}
#endif
    if (v0105 == nil) goto v0085;
    v0105 = stack[-1];
    fn = elt(env, 3); /* !:recip */
    v0335 = (*qfn1(fn))(qenv(fn), v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    v0105 = stack[-2];
    fn = elt(env, 4); /* multd */
    v0105 = (*qfn2(fn))(qenv(fn), v0335, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    popv(5);
    return ncons(v0105);

v0085:
    v0105 = stack[-2];
    if (!consp(v0105)) goto v0021;
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0105 = (consp(v0105) ? nil : lisp_true);
    goto v0020;

v0020:
    if (v0105 == nil) goto v0455;
    v0335 = stack[-2];
    v0105 = stack[-1];
    {
        popv(5);
        fn = elt(env, 5); /* !:divide */
        return (*qfn2(fn))(qenv(fn), v0335, v0105);
    }

v0455:
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0335 = qcdr(v0105);
    v0105 = stack[-1];
    fn = elt(env, 6); /* qremf */
    v0105 = (*qfn2(fn))(qenv(fn), v0335, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    stack[-3] = v0105;
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0335 = qcar(v0105);
    v0105 = (Lisp_Object)17; /* 1 */
    v0105 = cons(v0335, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    v0335 = ncons(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    v0105 = stack[-3];
    v0105 = qcar(v0105);
    fn = elt(env, 7); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0335, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    v0105 = stack[-2];
    v0105 = qcar(v0105);
    v0335 = qcar(v0105);
    v0105 = (Lisp_Object)17; /* 1 */
    v0105 = cons(v0335, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    v0335 = ncons(v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    v0105 = stack[-3];
    v0105 = qcdr(v0105);
    fn = elt(env, 7); /* multf */
    v0105 = (*qfn2(fn))(qenv(fn), v0335, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    stack[0] = cons(stack[0], v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    v0105 = stack[-2];
    v0335 = qcdr(v0105);
    v0105 = stack[-1];
    v0105 = CC_qremd(env, v0335, v0105);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[-4];
    {
        Lisp_Object v0051 = stack[0];
        popv(5);
        fn = elt(env, 8); /* praddf */
        return (*qfn2(fn))(qenv(fn), v0051, v0105);
    }

v0021:
    v0105 = qvalue(elt(env, 2)); /* t */
    goto v0020;

v0027:
    v0105 = stack[-2];
    popv(5);
    return ncons(v0105);

v0145:
    v0335 = stack[-2];
    v0105 = stack[-2];
    popv(5);
    return cons(v0335, v0105);
/* error exit handlers */
v0050:
    popv(5);
    return nil;
}



/* Code for variablesir */

static Lisp_Object MS_CDECL CC_variablesir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0454, v0020;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "variablesir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for variablesir");
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
    v0020 = qvalue(elt(env, 1)); /* char */
    v0454 = elt(env, 2); /* (!/ o m b v a r) */
    if (equal(v0020, v0454)) goto v0092;
    fn = elt(env, 4); /* omvir */
    v0454 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-1];
    stack[0] = v0454;
    fn = elt(env, 5); /* lex */
    v0454 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-1];
    v0454 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0020 = stack[0];
    if (v0020 == nil) goto v0014;
    v0020 = stack[0];
    popv(2);
    return cons(v0020, v0454);

v0014:
    v0020 = stack[0];
        popv(2);
        return Lappend(nil, v0020, v0454);

v0092:
    v0454 = nil;
    { popv(2); return onevalue(v0454); }
/* error exit handlers */
v0116:
    popv(2);
    return nil;
}



/* Code for initwght */

static Lisp_Object CC_initwght(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0462, v0441;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for initwght");
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
    stack[-3] = v0000;
/* end of prologue */
    v0462 = (Lisp_Object)1; /* 0 */
    stack[-5] = v0462;
    stack[0] = v0462;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0441 = qvalue(elt(env, 2)); /* maxvar */
    v0462 = stack[-3];
    v0462 = plus2(v0441, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-6];
    v0441 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0462/(16/CELL)));
    v0462 = (Lisp_Object)65; /* 4 */
    v0462 = *(Lisp_Object *)((char *)v0441 + (CELL-TAG_VECTOR) + ((int32_t)v0462/(16/CELL)));
    stack[-4] = v0462;
    goto v0070;

v0070:
    v0462 = stack[-4];
    if (v0462 == nil) goto v0128;
    v0462 = stack[-4];
    v0462 = qcar(v0462);
    stack[-2] = v0462;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0441 = qvalue(elt(env, 2)); /* maxvar */
    v0462 = stack[-2];
    v0462 = qcar(v0462);
    v0462 = plus2(v0441, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-6];
    v0441 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0462/(16/CELL)));
    v0462 = (Lisp_Object)1; /* 0 */
    v0462 = *(Lisp_Object *)((char *)v0441 + (CELL-TAG_VECTOR) + ((int32_t)v0462/(16/CELL)));
    if (v0462 == nil) goto v0454;
    v0462 = stack[-2];
    v0462 = qcdr(v0462);
    v0462 = qcar(v0462);
    fn = elt(env, 4); /* dm!-abs */
    v0462 = (*qfn1(fn))(qenv(fn), v0462);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-6];
    fn = elt(env, 5); /* !:onep */
    v0462 = (*qfn1(fn))(qenv(fn), v0462);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-6];
    if (!(v0462 == nil)) goto v0062;
    v0462 = stack[-5];
    v0462 = add1(v0462);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-6];
    stack[-5] = v0462;
    goto v0062;

v0062:
    v0462 = stack[0];
    v0462 = add1(v0462);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-6];
    stack[0] = v0462;
    goto v0454;

v0454:
    v0462 = stack[-4];
    v0462 = qcdr(v0462);
    stack[-4] = v0462;
    goto v0070;

v0128:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v0441 = qvalue(elt(env, 2)); /* maxvar */
    v0462 = stack[-3];
    v0462 = plus2(v0441, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-6];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0462/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[0];
    stack[-1] = stack[-5];
    v0441 = (Lisp_Object)49; /* 3 */
    v0462 = stack[-5];
    v0462 = times2(v0441, v0462);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-6];
    v0462 = plus2(stack[0], v0462);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    env = stack[-6];
    v0462 = acons(stack[-2], stack[-1], v0462);
    nil = C_nil;
    if (exception_pending()) goto v0104;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v0462;
    v0462 = nil;
    { popv(7); return onevalue(v0462); }
/* error exit handlers */
v0104:
    popv(7);
    return nil;
}



/* Code for getrtype1 */

static Lisp_Object CC_getrtype1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0041;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrtype1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0041 = v0000;
/* end of prologue */
    v0041 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0041);
}



/* Code for vevlcm */

static Lisp_Object CC_vevlcm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0131, v0107;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vevlcm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
    stack[-1] = v0000;
/* end of prologue */
    v0107 = nil;
    goto v0146;

v0146:
    v0013 = stack[-1];
    if (v0013 == nil) goto v0072;
    v0013 = stack[0];
    if (v0013 == nil) goto v0072;
    v0013 = stack[-1];
    v0131 = qcar(v0013);
    v0013 = stack[0];
    v0013 = qcar(v0013);
    if (((int32_t)(v0131)) > ((int32_t)(v0013))) goto v0448;
    v0013 = stack[0];
    v0013 = qcar(v0013);
    goto v0035;

v0035:
    v0131 = v0107;
    v0013 = cons(v0013, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    env = stack[-2];
    v0107 = v0013;
    v0013 = stack[-1];
    v0013 = qcdr(v0013);
    stack[-1] = v0013;
    v0013 = stack[0];
    v0013 = qcdr(v0013);
    stack[0] = v0013;
    goto v0146;

v0448:
    v0013 = stack[-1];
    v0013 = qcar(v0013);
    goto v0035;

v0072:
    v0013 = v0107;
    v0013 = Lnreverse(nil, v0013);
    env = stack[-2];
    v0107 = v0013;
    v0013 = stack[-1];
    if (v0013 == nil) goto v0019;
    v0131 = v0107;
    v0013 = stack[-1];
    v0013 = Lnconc(nil, v0131, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    v0107 = v0013;
    { popv(3); return onevalue(v0107); }

v0019:
    v0013 = stack[0];
    if (v0013 == nil) { popv(3); return onevalue(v0107); }
    v0131 = v0107;
    v0013 = stack[0];
    v0013 = Lnconc(nil, v0131, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0144;
    v0107 = v0013;
    { popv(3); return onevalue(v0107); }
/* error exit handlers */
v0144:
    popv(3);
    return nil;
}



/* Code for bcneg */

static Lisp_Object CC_bcneg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0073;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcneg");
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
    v0009 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0009 == nil) goto v0074;
    v0073 = stack[0];
    v0009 = (Lisp_Object)1; /* 0 */
    v0009 = Leqn(nil, v0073, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-1];
    if (!(v0009 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v0073 = qvalue(elt(env, 2)); /* current!-modulus */
    v0009 = stack[0];
    v0009 = (Lisp_Object)(int32_t)((int32_t)v0073 - (int32_t)v0009 + TAG_FIXNUM);
    { popv(2); return onevalue(v0009); }

v0074:
    v0009 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* negsq */
        return (*qfn1(fn))(qenv(fn), v0009);
    }
/* error exit handlers */
v0088:
    popv(2);
    return nil;
}



/* Code for evaluate1 */

static Lisp_Object CC_evaluate1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0054, v0105, v0335;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0054 = v0015;
    v0105 = v0000;
/* end of prologue */
    v0053 = v0105;
    if (is_number(v0053)) goto v0005;
    v0053 = v0105;
    if (v0053 == nil) goto v0005;
    v0053 = v0105;
    v0053 = Lconsp(nil, v0053);
    env = stack[0];
    if (v0053 == nil) goto v0014;
    v0053 = v0105;
    v0053 = qcar(v0053);
    if (!symbolp(v0053)) v0053 = nil;
    else { v0053 = qfastgets(v0053);
           if (v0053 != nil) { v0053 = elt(v0053, 8); /* dname */
#ifdef RECORD_GET
             if (v0053 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v0053 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v0053 == SPID_NOPROP) v0053 = nil; }}
#endif
    if (!(v0053 == nil)) { popv(1); return onevalue(v0105); }

v0014:
    v0335 = v0105;
    v0053 = v0054;
    v0053 = Lassoc(nil, v0335, v0053);
    v0335 = v0053;
    v0053 = v0335;
    if (v0053 == nil) goto v0088;
    v0053 = v0335;
    v0053 = qcdr(v0053);
    { popv(1); return onevalue(v0053); }

v0088:
    v0053 = v0105;
    if (!consp(v0053)) goto v0029;
    v0053 = v0105;
    v0053 = qcar(v0053);
    v0105 = qcdr(v0105);
    {
        popv(1);
        fn = elt(env, 11); /* evaluate2 */
        return (*qfnn(fn))(qenv(fn), 3, v0053, v0105, v0054);
    }

v0029:
    v0054 = v0105;
    v0053 = elt(env, 1); /* i */
    if (v0054 == v0053) goto v0081;
    v0054 = v0105;
    v0053 = elt(env, 6); /* e */
    if (v0054 == v0053) goto v0003;
    v0054 = v0105;
    v0053 = elt(env, 8); /* pi */
    v0053 = (v0054 == v0053 ? lisp_true : nil);
    goto v0449;

v0449:
    if (v0053 == nil) goto v0337;
    v0053 = v0105;
    fn = elt(env, 12); /* simp */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[0];
    v0053 = qcar(v0053);
    {
        popv(1);
        fn = elt(env, 13); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v0053);
    }

v0337:
    v0053 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 9)) = v0053; /* !*evaluateerror */
    v0054 = v0105;
    v0053 = elt(env, 10); /* "number" */
    {
        popv(1);
        fn = elt(env, 14); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0054, v0053);
    }

v0003:
    v0053 = qvalue(elt(env, 7)); /* t */
    goto v0449;

v0081:
    v0054 = qvalue(elt(env, 2)); /* dmode!* */
    v0053 = elt(env, 3); /* ivalue */
    v0053 = get(v0054, v0053);
    env = stack[0];
    v0105 = v0053;
    if (v0053 == nil) goto v0131;
    v0054 = v0105;
    v0053 = elt(env, 4); /* (nil) */
    fn = elt(env, 15); /* apply */
    v0053 = (*qfn2(fn))(qenv(fn), v0054, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    v0053 = qcar(v0053);
    { popv(1); return onevalue(v0053); }

v0131:
    v0053 = elt(env, 5); /* "i used as indeterminate value" */
    {
        popv(1);
        fn = elt(env, 16); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0053);
    }

v0005:
    v0053 = v0105;
    {
        popv(1);
        fn = elt(env, 13); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v0053);
    }
/* error exit handlers */
v0121:
    popv(1);
    return nil;
}



/* Code for gpexp1p */

static Lisp_Object CC_gpexp1p(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gpexp1p");
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

v0094:
    v0093 = stack[0];
    if (v0093 == nil) goto v0089;
    v0093 = stack[0];
    v0093 = qcar(v0093);
    fn = elt(env, 3); /* gpexpp */
    v0093 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-1];
    if (v0093 == nil) goto v0008;
    v0093 = stack[0];
    v0093 = qcdr(v0093);
    stack[0] = v0093;
    goto v0094;

v0008:
    v0093 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0093); }

v0089:
    v0093 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0093); }
/* error exit handlers */
v0014:
    popv(2);
    return nil;
}



/* Code for repasc */

static Lisp_Object MS_CDECL CC_repasc(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003, v0004, v0061;
    Lisp_Object fn;
    Lisp_Object v0042, v0015, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "repasc");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    v0042 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repasc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0042,v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0015,v0042);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0042;
    stack[-1] = v0015;
    stack[-2] = v0000;
/* end of prologue */
    v0061 = nil;
    goto v0072;

v0072:
    v0003 = stack[0];
    if (v0003 == nil) goto v0007;
    v0004 = stack[-2];
    v0003 = stack[0];
    v0003 = qcar(v0003);
    v0003 = qcar(v0003);
    if (equal(v0004, v0003)) goto v0019;
    v0003 = stack[0];
    v0003 = qcar(v0003);
    v0004 = v0061;
    v0003 = cons(v0003, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-4];
    v0061 = v0003;
    v0003 = stack[0];
    v0003 = qcdr(v0003);
    stack[0] = v0003;
    goto v0072;

v0019:
    stack[-3] = v0061;
    v0061 = stack[-2];
    v0004 = stack[-1];
    v0003 = stack[0];
    v0003 = qcdr(v0003);
    v0003 = acons(v0061, v0004, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-4];
    {
        Lisp_Object v0338 = stack[-3];
        popv(5);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0338, v0003);
    }

v0007:
    stack[-3] = v0061;
    stack[-1] = elt(env, 1); /* alg */
    stack[0] = (Lisp_Object)113; /* 7 */
    v0061 = elt(env, 2); /* "key" */
    v0004 = stack[-2];
    v0003 = elt(env, 3); /* "not found" */
    v0003 = list3(v0061, v0004, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-4];
    fn = elt(env, 5); /* rerror */
    v0003 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v0003);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-4];
    {
        Lisp_Object v0138 = stack[-3];
        popv(5);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0138, v0003);
    }
/* error exit handlers */
v0128:
    popv(5);
    return nil;
}



/* Code for mvar_member */

static Lisp_Object CC_mvar_member(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0073, v0087, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mvar_member");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0087 = v0015;
    v0088 = v0000;
/* end of prologue */
    v0073 = v0088;
    v0009 = v0087;
    if (equal(v0073, v0009)) goto v0005;
    v0009 = v0087;
    if (!consp(v0009)) goto v0031;
    v0009 = v0088;
    v0073 = v0087;
    v0073 = qcdr(v0073);
    {
        fn = elt(env, 3); /* arglist_member */
        return (*qfn2(fn))(qenv(fn), v0009, v0073);
    }

v0031:
    v0009 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0009);

v0005:
    v0009 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0009);
}



/* Code for general!-expt!-mod!-p */

static Lisp_Object CC_generalKexptKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0108, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-expt-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0082 = v0015;
    stack[0] = v0000;
/* end of prologue */
    v0108 = v0082;
    v0107 = (Lisp_Object)1; /* 0 */
    if (v0108 == v0107) goto v0005;
    v0108 = v0082;
    v0107 = (Lisp_Object)17; /* 1 */
    if (v0108 == v0107) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0108 = v0082;
    v0107 = (Lisp_Object)33; /* 2 */
    v0107 = Ldivide(nil, v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    stack[-1] = v0107;
    v0108 = stack[0];
    v0107 = stack[-1];
    v0107 = qcar(v0107);
    v0107 = CC_generalKexptKmodKp(env, v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    v0082 = v0107;
    v0107 = v0082;
    v0108 = v0082;
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v0107 = (*qfn2(fn))(qenv(fn), v0107, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[-2];
    v0082 = v0107;
    v0107 = stack[-1];
    v0108 = qcdr(v0107);
    v0107 = (Lisp_Object)1; /* 0 */
    if (v0108 == v0107) { popv(3); return onevalue(v0082); }
    v0108 = v0082;
    v0107 = stack[0];
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v0107 = (*qfn2(fn))(qenv(fn), v0108, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    v0082 = v0107;
    { popv(3); return onevalue(v0082); }

v0005:
    v0107 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v0107); }
/* error exit handlers */
v0106:
    popv(3);
    return nil;
}



/* Code for negate!-term */

static Lisp_Object CC_negateKterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0007;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for negate-term");
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
    v0007 = v0000;
/* end of prologue */
    v0023 = v0007;
    stack[0] = qcar(v0023);
    v0023 = v0007;
    v0023 = qcdr(v0023);
    fn = elt(env, 1); /* minus!-mod!-p */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    {
        Lisp_Object v0065 = stack[0];
        popv(1);
        return cons(v0065, v0023);
    }
/* error exit handlers */
v0027:
    popv(1);
    return nil;
}



/* Code for split_ext */

static Lisp_Object CC_split_ext(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0398, v0451, v0458;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for split_ext");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0451 = v0015;
    v0458 = v0000;
/* end of prologue */
    v0398 = v0458;
    v0398 = qcdr(v0398);
    stack[-7] = v0398;
    v0398 = v0458;
    v0398 = qcar(v0398);
    fn = elt(env, 3); /* split_form */
    v0398 = (*qfn2(fn))(qenv(fn), v0398, v0451);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[0] = v0398;
    v0398 = elt(env, 1); /* ext */
    stack[-6] = ncons(v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0398 = stack[0];
    v0451 = qcar(v0398);
    v0398 = stack[-7];
    v0398 = cons(v0451, v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    stack[-5] = (*qfn1(fn))(qenv(fn), v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0398 = stack[0];
    v0398 = qcdr(v0398);
    stack[-4] = v0398;
    v0398 = stack[-4];
    if (v0398 == nil) goto v0029;
    v0398 = stack[-4];
    v0398 = qcar(v0398);
    v0451 = v0398;
    v0398 = v0451;
    stack[0] = qcar(v0398);
    v0398 = v0451;
    v0451 = qcdr(v0398);
    v0398 = stack[-7];
    v0398 = cons(v0451, v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    v0398 = (*qfn1(fn))(qenv(fn), v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0398 = cons(stack[0], v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0398 = ncons(v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    stack[-2] = v0398;
    stack[-3] = v0398;
    goto v0454;

v0454:
    v0398 = stack[-4];
    v0398 = qcdr(v0398);
    stack[-4] = v0398;
    v0398 = stack[-4];
    if (v0398 == nil) goto v0108;
    stack[-1] = stack[-2];
    v0398 = stack[-4];
    v0398 = qcar(v0398);
    v0451 = v0398;
    v0398 = v0451;
    stack[0] = qcar(v0398);
    v0398 = v0451;
    v0451 = qcdr(v0398);
    v0398 = stack[-7];
    v0398 = cons(v0451, v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    fn = elt(env, 4); /* cancel */
    v0398 = (*qfn1(fn))(qenv(fn), v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0398 = cons(stack[0], v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0398 = ncons(v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0398 = Lrplacd(nil, stack[-1], v0398);
    nil = C_nil;
    if (exception_pending()) goto v0443;
    env = stack[-8];
    v0398 = stack[-2];
    v0398 = qcdr(v0398);
    stack[-2] = v0398;
    goto v0454;

v0108:
    v0398 = stack[-3];
    goto v0022;

v0022:
    {
        Lisp_Object v0125 = stack[-6];
        Lisp_Object v0126 = stack[-5];
        popv(9);
        return acons(v0125, v0126, v0398);
    }

v0029:
    v0398 = qvalue(elt(env, 2)); /* nil */
    goto v0022;
/* error exit handlers */
v0443:
    popv(9);
    return nil;
}



/* Code for mkprod */

static Lisp_Object CC_mkprod(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0476, v0477;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkprod");
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
    stack[-4] = v0000;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = nil; /* !*exp */
    stack[-1] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v0476 = stack[-4];
    if (v0476 == nil) goto v0027;
    v0476 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v0476 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    goto v0066;

v0066:
    if (v0476 == nil) goto v0086;
    v0476 = stack[-4];
    goto v0145;

v0145:
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    { popv(7); return onevalue(v0476); }

v0086:
    v0476 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v0476; /* !*sub2 */
    v0477 = stack[-4];
    v0476 = (Lisp_Object)17; /* 1 */
    v0476 = cons(v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    fn = elt(env, 11); /* subs2 */
    v0476 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[0] = v0476;
    v0476 = stack[0];
    v0477 = qcdr(v0476);
    v0476 = (Lisp_Object)17; /* 1 */
    if (v0477 == v0476) goto v0030;
    v0476 = stack[-4];
    goto v0145;

v0030:
    v0476 = stack[0];
    v0477 = qcar(v0476);
    v0476 = stack[-4];
    if (equal(v0477, v0476)) goto v0087;
    v0476 = stack[0];
    v0476 = qcar(v0476);
    stack[-4] = v0476;
    v0476 = stack[-4];
    if (v0476 == nil) goto v0025;
    v0476 = stack[-4];
    fn = elt(env, 10); /* kernlp */
    v0476 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    goto v0024;

v0024:
    if (v0476 == nil) goto v0087;
    v0476 = stack[-4];
    goto v0145;

v0087:
    v0476 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 1)) = v0476; /* !*exp */
    v0476 = stack[-4];
    fn = elt(env, 12); /* ckrn */
    v0476 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[-5] = v0476;
    v0477 = stack[-4];
    v0476 = stack[-5];
    fn = elt(env, 13); /* quotf */
    v0476 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[-4] = v0476;
    v0476 = stack[-4];
    fn = elt(env, 14); /* expnd */
    v0476 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[0] = v0476;
    v0476 = stack[0];
    if (v0476 == nil) goto v0137;
    v0476 = stack[0];
    fn = elt(env, 10); /* kernlp */
    v0476 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    goto v0138;

v0138:
    if (v0476 == nil) goto v0130;
    v0477 = stack[-5];
    v0476 = stack[0];
    fn = elt(env, 15); /* multf */
    v0476 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    goto v0145;

v0130:
    v0476 = qvalue(elt(env, 4)); /* !*mcd */
    if (v0476 == nil) goto v0126;
    v0476 = qvalue(elt(env, 5)); /* !*sqfree */
    if (!(v0476 == nil)) goto v0478;
    v0476 = qvalue(elt(env, 6)); /* !*factor */
    if (!(v0476 == nil)) goto v0478;
    v0476 = qvalue(elt(env, 7)); /* !*gcd */
    if (!(v0476 == nil)) goto v0478;

v0126:
    v0476 = stack[0];
    fn = elt(env, 12); /* ckrn */
    v0476 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[-3] = v0476;
    v0477 = stack[0];
    v0476 = stack[-3];
    fn = elt(env, 13); /* quotf */
    v0476 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[0] = v0476;
    v0477 = stack[0];
    v0476 = (Lisp_Object)17; /* 1 */
    v0476 = cons(v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    v0476 = list2(stack[-3], v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[-3] = v0476;
    goto v0437;

v0437:
    v0476 = stack[-3];
    v0476 = qcdr(v0476);
    v0476 = qcar(v0476);
    v0477 = qcdr(v0476);
    v0476 = (Lisp_Object)17; /* 1 */
    v0476 = (Lisp_Object)greaterp2(v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    v0476 = v0476 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0476 == nil)) goto v0479;
    v0476 = stack[-3];
    v0476 = qcdr(v0476);
    v0476 = qcdr(v0476);
    if (!(v0476 == nil)) goto v0479;
    v0476 = qvalue(elt(env, 9)); /* !*group */
    if (v0476 == nil) goto v0327;
    v0476 = qvalue(elt(env, 8)); /* nil */
    goto v0101;

v0101:
    if (v0476 == nil) goto v0480;
    v0476 = stack[-3];
    v0476 = qcdr(v0476);
    v0476 = qcar(v0476);
    v0477 = qcar(v0476);
    v0476 = stack[-3];
    v0476 = qcdr(v0476);
    v0476 = qcar(v0476);
    v0476 = qcdr(v0476);
    fn = elt(env, 16); /* mksp!* */
    v0477 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    v0476 = stack[-3];
    v0476 = qcar(v0476);
    fn = elt(env, 15); /* multf */
    v0476 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[0] = v0476;
    goto v0426;

v0426:
    v0477 = stack[-5];
    v0476 = stack[0];
    fn = elt(env, 15); /* multf */
    v0476 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    goto v0145;

v0480:
    v0477 = stack[-4];
    v0476 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* mksp!* */
    v0476 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[0] = v0476;
    goto v0426;

v0327:
    v0476 = stack[-4];
    fn = elt(env, 17); /* tmsf */
    stack[0] = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    v0476 = stack[-3];
    v0476 = qcdr(v0476);
    v0476 = qcar(v0476);
    v0476 = qcar(v0476);
    fn = elt(env, 17); /* tmsf */
    v0476 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    v0476 = (Lisp_Object)greaterp2(stack[0], v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    v0476 = v0476 ? lisp_true : nil;
    env = stack[-6];
    goto v0101;

v0479:
    v0476 = stack[-3];
    v0476 = qcar(v0476);
    stack[0] = v0476;
    v0476 = stack[-3];
    v0476 = qcdr(v0476);
    stack[-3] = v0476;
    goto v0047;

v0047:
    v0476 = stack[-3];
    if (v0476 == nil) goto v0426;
    v0476 = stack[-3];
    v0476 = qcar(v0476);
    v0477 = v0476;
    v0477 = qcar(v0477);
    v0476 = qcdr(v0476);
    fn = elt(env, 16); /* mksp!* */
    v0477 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    v0476 = stack[0];
    fn = elt(env, 15); /* multf */
    v0476 = (*qfn2(fn))(qenv(fn), v0477, v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[0] = v0476;
    v0476 = stack[-3];
    v0476 = qcdr(v0476);
    stack[-3] = v0476;
    goto v0047;

v0478:
    v0476 = stack[0];
    fn = elt(env, 18); /* fctrf */
    v0476 = (*qfn1(fn))(qenv(fn), v0476);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-6];
    stack[-3] = v0476;
    goto v0437;

v0137:
    v0476 = qvalue(elt(env, 3)); /* t */
    goto v0138;

v0025:
    v0476 = qvalue(elt(env, 3)); /* t */
    goto v0024;

v0027:
    v0476 = qvalue(elt(env, 3)); /* t */
    goto v0066;
/* error exit handlers */
v0318:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-1]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-2]; /* !*exp */
    popv(7);
    return nil;
}



/* Code for rl_negateat */

static Lisp_Object CC_rl_negateat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_negateat");
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
    v0086 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_negateat!* */
    v0086 = ncons(v0086);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-1];
    {
        Lisp_Object v0007 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0007, v0086);
    }
/* error exit handlers */
v0023:
    popv(2);
    return nil;
}



/* Code for variableom */

static Lisp_Object CC_variableom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0038, v0339;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for variableom");
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
    v0038 = stack[0];
    v0339 = Lintern(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0038 = qvalue(elt(env, 1)); /* constantsom!* */
    v0038 = Lassoc(nil, v0339, v0038);
    stack[-1] = v0038;
    v0038 = stack[-1];
    if (v0038 == nil) goto v0034;
    v0038 = elt(env, 2); /* "<OMS " */
    fn = elt(env, 9); /* printout */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0038 = elt(env, 3); /* "cd=""" */
    v0038 = Lprinc(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0038 = stack[-1];
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0038 = Lprinc(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0038 = elt(env, 4); /* """ " */
    v0038 = Lprinc(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0038 = elt(env, 5); /* "name=""" */
    v0038 = Lprinc(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0038 = stack[-1];
    v0038 = qcdr(v0038);
    v0038 = qcdr(v0038);
    v0038 = qcar(v0038);
    v0038 = Lprinc(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0038 = elt(env, 6); /* """/>" */
    v0038 = Lprinc(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    goto v0066;

v0066:
    v0038 = nil;
    { popv(3); return onevalue(v0038); }

v0034:
    v0038 = stack[0];
    if (v0038 == nil) goto v0066;
    v0038 = elt(env, 8); /* "<OMV " */
    fn = elt(env, 9); /* printout */
    v0038 = (*qfn1(fn))(qenv(fn), v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0038 = elt(env, 5); /* "name=""" */
    v0038 = Lprinc(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0038 = stack[0];
    v0038 = Lprinc(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0038 = elt(env, 6); /* """/>" */
    v0038 = Lprinc(nil, v0038);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    goto v0066;
/* error exit handlers */
v0064:
    popv(3);
    return nil;
}



/* Code for matsm!*1 */

static Lisp_Object CC_matsmH1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0329, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for matsm*1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0329 = v0000;
/* end of prologue */
    stack[-8] = elt(env, 1); /* mat */
    stack[-7] = v0329;
    v0329 = stack[-7];
    if (v0329 == nil) goto v0090;
    v0329 = stack[-7];
    v0329 = qcar(v0329);
    stack[-3] = v0329;
    v0329 = stack[-3];
    if (v0329 == nil) goto v0088;
    v0329 = stack[-3];
    v0329 = qcar(v0329);
    fn = elt(env, 4); /* subs2!* */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0329 = ncons(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    stack[-1] = v0329;
    stack[-2] = v0329;
    goto v0017;

v0017:
    v0329 = stack[-3];
    v0329 = qcdr(v0329);
    stack[-3] = v0329;
    v0329 = stack[-3];
    if (v0329 == nil) goto v0018;
    stack[0] = stack[-1];
    v0329 = stack[-3];
    v0329 = qcar(v0329);
    fn = elt(env, 4); /* subs2!* */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0329 = ncons(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0329 = Lrplacd(nil, stack[0], v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0329 = stack[-1];
    v0329 = qcdr(v0329);
    stack[-1] = v0329;
    goto v0017;

v0018:
    v0329 = stack[-2];
    goto v0032;

v0032:
    v0329 = ncons(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    stack[-5] = v0329;
    stack[-6] = v0329;
    goto v0027;

v0027:
    v0329 = stack[-7];
    v0329 = qcdr(v0329);
    stack[-7] = v0329;
    v0329 = stack[-7];
    if (v0329 == nil) goto v0131;
    stack[-4] = stack[-5];
    v0329 = stack[-7];
    v0329 = qcar(v0329);
    stack[-3] = v0329;
    v0329 = stack[-3];
    if (v0329 == nil) goto v0464;
    v0329 = stack[-3];
    v0329 = qcar(v0329);
    fn = elt(env, 4); /* subs2!* */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0329 = ncons(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    stack[-1] = v0329;
    stack[-2] = v0329;
    goto v0461;

v0461:
    v0329 = stack[-3];
    v0329 = qcdr(v0329);
    stack[-3] = v0329;
    v0329 = stack[-3];
    if (v0329 == nil) goto v0458;
    stack[0] = stack[-1];
    v0329 = stack[-3];
    v0329 = qcar(v0329);
    fn = elt(env, 4); /* subs2!* */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v0329 = (*qfn1(fn))(qenv(fn), v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0329 = ncons(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0329 = Lrplacd(nil, stack[0], v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0329 = stack[-1];
    v0329 = qcdr(v0329);
    stack[-1] = v0329;
    goto v0461;

v0458:
    v0329 = stack[-2];
    goto v0452;

v0452:
    v0329 = ncons(v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0329 = Lrplacd(nil, stack[-4], v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0329 = stack[-5];
    v0329 = qcdr(v0329);
    stack[-5] = v0329;
    goto v0027;

v0464:
    v0329 = qvalue(elt(env, 2)); /* nil */
    goto v0452;

v0131:
    v0329 = stack[-6];
    goto v0146;

v0146:
    v0329 = cons(stack[-8], v0329);
    nil = C_nil;
    if (exception_pending()) goto v0402;
    env = stack[-9];
    v0104 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v0104; /* !*sub2 */
    { popv(10); return onevalue(v0329); }

v0088:
    v0329 = qvalue(elt(env, 2)); /* nil */
    goto v0032;

v0090:
    v0329 = qvalue(elt(env, 2)); /* nil */
    goto v0146;
/* error exit handlers */
v0402:
    popv(10);
    return nil;
}



/* Code for bind */

static Lisp_Object CC_bind(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0093;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bind");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0093 = v0015;
    v0036 = v0000;
/* end of prologue */
    stack[-1] = v0036;
    stack[0] = elt(env, 1); /* binding */
    if (!symbolp(v0036)) v0036 = nil;
    else { v0036 = qfastgets(v0036);
           if (v0036 != nil) { v0036 = elt(v0036, 13); /* binding */
#ifdef RECORD_GET
             if (v0036 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v0036 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v0036 == SPID_NOPROP) v0036 = nil; }}
#endif
    v0036 = cons(v0093, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0448;
    {
        Lisp_Object v0091 = stack[-1];
        Lisp_Object v0085 = stack[0];
        popv(2);
        return Lputprop(nil, 3, v0091, v0085, v0036);
    }
/* error exit handlers */
v0448:
    popv(2);
    return nil;
}



/* Code for modminusp!: */

static Lisp_Object CC_modminuspT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0448, v0091;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modminusp:");
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
    v0448 = v0000;
/* end of prologue */
    v0091 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v0091 == nil) goto v0093;
    v0091 = (Lisp_Object)33; /* 2 */
    v0448 = qcdr(v0448);
    v0448 = times2(v0091, v0448);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[0];
    v0091 = qvalue(elt(env, 2)); /* current!-modulus */
        popv(1);
        return Lgreaterp(nil, v0448, v0091);

v0093:
    v0448 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v0448); }
/* error exit handlers */
v0085:
    popv(1);
    return nil;
}



/* Code for groebnormalform */

static Lisp_Object MS_CDECL CC_groebnormalform(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0147, v0083, v0090, v0035;
    Lisp_Object fn;
    Lisp_Object v0042, v0015, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groebnormalform");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0015 = va_arg(aa, Lisp_Object);
    v0042 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groebnormalform");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0147 = v0042;
    v0083 = v0015;
    v0090 = v0000;
/* end of prologue */
    v0035 = v0090;
    v0090 = v0083;
    v0083 = v0147;
    v0147 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* groebnormalform0 */
        return (*qfnn(fn))(qenv(fn), 4, v0035, v0090, v0083, v0147);
    }
}



/* Code for list!+list */

static Lisp_Object CC_listLlist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0015)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list+list");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0015,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0015);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0015;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0092;

v0092:
    v0088 = stack[-1];
    if (v0088 == nil) goto v0145;
    v0088 = stack[-1];
    v0033 = qcar(v0088);
    v0088 = stack[0];
    v0088 = qcar(v0088);
    fn = elt(env, 1); /* !:plus */
    v0033 = (*qfn2(fn))(qenv(fn), v0033, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    v0088 = stack[-2];
    v0088 = cons(v0033, v0088);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-3];
    stack[-2] = v0088;
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    stack[-1] = v0088;
    v0088 = stack[0];
    v0088 = qcdr(v0088);
    stack[0] = v0088;
    goto v0092;

v0145:
    v0088 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0088);
    }
/* error exit handlers */
v0115:
    popv(4);
    return nil;
}



/* Code for zero!-roads */

static Lisp_Object CC_zeroKroads(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0073;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for zero-roads");
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

v0094:
    v0009 = stack[0];
    if (v0009 == nil) goto v0089;
    v0009 = stack[0];
    v0009 = qcar(v0009);
    fn = elt(env, 2); /* z!-roads */
    v0009 = (*qfn1(fn))(qenv(fn), v0009);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[-2];
    v0073 = v0009;
    v0009 = v0073;
    if (v0009 == nil) goto v0084;
    stack[-1] = v0073;
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    v0009 = CC_zeroKroads(env, v0009);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    {
        Lisp_Object v0034 = stack[-1];
        popv(3);
        return cons(v0034, v0009);
    }

v0084:
    v0009 = stack[0];
    v0009 = qcdr(v0009);
    stack[0] = v0009;
    goto v0094;

v0089:
    v0009 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0009); }
/* error exit handlers */
v0033:
    popv(3);
    return nil;
}



setup_type const u15_setup[] =
{
    {"constsml",                CC_constsml,    too_many_1,    wrong_no_1},
    {"xord_deglex",             too_few_2,      CC_xord_deglex,wrong_no_2},
    {"assert_uninstall1",       CC_assert_uninstall1,too_many_1,wrong_no_1},
    {"getmatelem",              CC_getmatelem,  too_many_1,    wrong_no_1},
    {"class",                   CC_class,       too_many_1,    wrong_no_1},
    {"gperm3",                  too_few_2,      CC_gperm3,     wrong_no_2},
    {"gcref_mkedges-tgf",       too_few_2,      CC_gcref_mkedgesKtgf,wrong_no_2},
    {"wureducedpolysp",         too_few_2,      CC_wureducedpolysp,wrong_no_2},
    {"ibalp_var-satlist",       too_few_2,      CC_ibalp_varKsatlist,wrong_no_2},
    {"getcomb",                 too_few_2,      CC_getcomb,    wrong_no_2},
    {"setdmode1",               too_few_2,      CC_setdmode1,  wrong_no_2},
    {"bcplus?",                 CC_bcplusW,     too_many_1,    wrong_no_1},
    {"vevmaptozero1",           too_few_2,      CC_vevmaptozero1,wrong_no_2},
    {"noncommuting",            too_few_2,      CC_noncommuting,wrong_no_2},
    {"prop-simp",               too_few_2,      CC_propKsimp,  wrong_no_2},
    {"xread1",                  CC_xread1,      too_many_1,    wrong_no_1},
    {"setel",                   too_few_2,      CC_setel,      wrong_no_2},
    {":expt",                   too_few_2,      CC_Texpt,      wrong_no_2},
    {"in_list1",                too_few_2,      CC_in_list1,   wrong_no_2},
    {"ofsf_entry2at1",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at1},
    {"qremd",                   too_few_2,      CC_qremd,      wrong_no_2},
    {"variablesir",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_variablesir},
    {"initwght",                CC_initwght,    too_many_1,    wrong_no_1},
    {"getrtype1",               CC_getrtype1,   too_many_1,    wrong_no_1},
    {"vevlcm",                  too_few_2,      CC_vevlcm,     wrong_no_2},
    {"bcneg",                   CC_bcneg,       too_many_1,    wrong_no_1},
    {"evaluate1",               too_few_2,      CC_evaluate1,  wrong_no_2},
    {"gpexp1p",                 CC_gpexp1p,     too_many_1,    wrong_no_1},
    {"repasc",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_repasc},
    {"mvar_member",             too_few_2,      CC_mvar_member,wrong_no_2},
    {"general-expt-mod-p",      too_few_2,      CC_generalKexptKmodKp,wrong_no_2},
    {"negate-term",             CC_negateKterm, too_many_1,    wrong_no_1},
    {"split_ext",               too_few_2,      CC_split_ext,  wrong_no_2},
    {"mkprod",                  CC_mkprod,      too_many_1,    wrong_no_1},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
    {"variableom",              CC_variableom,  too_many_1,    wrong_no_1},
    {"matsm*1",                 CC_matsmH1,     too_many_1,    wrong_no_1},
    {"bind",                    too_few_2,      CC_bind,       wrong_no_2},
    {"modminusp:",              CC_modminuspT,  too_many_1,    wrong_no_1},
    {"groebnormalform",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebnormalform},
    {"list+list",               too_few_2,      CC_listLlist,  wrong_no_2},
    {"zero-roads",              CC_zeroKroads,  too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u15", (two_args *)"7419 6420632 6578787", 0}
};

/* end of generated code */
