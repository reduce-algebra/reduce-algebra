
/* $destdir\u31.c        Machine generated C code */

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


/* Code for difference!: */

static Lisp_Object CC_differenceT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036, v0037, v0038, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for difference:");
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
    v0038 = v0001;
    v0039 = v0000;
/* end of prologue */
    v0036 = v0039;
    v0036 = qcdr(v0036);
    v0037 = qcar(v0036);
    stack[-1] = v0037;
    v0036 = (Lisp_Object)1; /* 0 */
    if (v0037 == v0036) goto v0040;
    v0036 = v0038;
    v0036 = qcdr(v0036);
    v0037 = qcar(v0036);
    stack[0] = v0037;
    v0036 = (Lisp_Object)1; /* 0 */
    if (v0037 == v0036) { popv(6); return onevalue(v0039); }
    v0036 = v0039;
    v0036 = qcdr(v0036);
    v0036 = qcdr(v0036);
    stack[-4] = v0036;
    v0037 = v0038;
    v0037 = qcdr(v0037);
    v0037 = qcdr(v0037);
    stack[-2] = v0037;
    v0037 = difference2(v0036, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-5];
    stack[-3] = v0037;
    v0036 = (Lisp_Object)1; /* 0 */
    if (v0037 == v0036) goto v0042;
    v0037 = stack[-3];
    v0036 = (Lisp_Object)1; /* 0 */
    v0036 = (Lisp_Object)greaterp2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    v0036 = v0036 ? lisp_true : nil;
    env = stack[-5];
    if (v0036 == nil) goto v0043;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v0037 = stack[-1];
    v0036 = stack[-3];
    v0037 = Lash1(nil, v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-5];
    v0036 = stack[0];
    v0037 = difference2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    v0036 = stack[-2];
    {
        Lisp_Object v0044 = stack[-4];
        popv(6);
        return list2star(v0044, v0037, v0036);
    }

v0043:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v0036 = stack[-3];
    v0036 = negate(v0036);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-5];
    v0036 = Lash1(nil, stack[0], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-5];
    v0037 = difference2(stack[-1], v0036);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    v0036 = stack[-4];
    {
        Lisp_Object v0045 = stack[-2];
        popv(6);
        return list2star(v0045, v0037, v0036);
    }

v0042:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v0037 = stack[-1];
    v0036 = stack[0];
    v0037 = difference2(v0037, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    v0036 = stack[-4];
    {
        Lisp_Object v0046 = stack[-2];
        popv(6);
        return list2star(v0046, v0037, v0036);
    }

v0040:
    v0036 = v0038;
    {
        popv(6);
        fn = elt(env, 2); /* minus!: */
        return (*qfn1(fn))(qenv(fn), v0036);
    }
/* error exit handlers */
v0041:
    popv(6);
    return nil;
}



/* Code for ev!-denom2 */

static Lisp_Object CC_evKdenom2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev-denom2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0040 = v0001;
    v0049 = v0000;
/* end of prologue */
    v0049 = qcar(v0049);
    {
        fn = elt(env, 1); /* ev!-edgeloop */
        return (*qfn2(fn))(qenv(fn), v0049, v0040);
    }
}



/* Code for assert_procstat!-argl */

static Lisp_Object MS_CDECL CC_assert_procstatKargl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0073, v0074, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_procstat-argl");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_procstat-argl");
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
    stack[0] = nil;
    goto v0076;

v0076:
    v0074 = qvalue(elt(env, 1)); /* cursym!* */
    v0073 = elt(env, 2); /* !*rpar!* */
    if (v0074 == v0073) goto v0077;
    fn = elt(env, 14); /* eolcheck */
    v0073 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0073 = qvalue(elt(env, 1)); /* cursym!* */
    if (symbolp(v0073)) goto v0079;
    v0074 = elt(env, 4); /* "Expecting identifier but found" */
    v0073 = qvalue(elt(env, 1)); /* cursym!* */
    v0073 = list2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    fn = elt(env, 15); /* assert_rederr */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    goto v0079;

v0079:
    v0073 = qvalue(elt(env, 1)); /* cursym!* */
    stack[-2] = v0073;
    fn = elt(env, 16); /* scan */
    v0073 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0074 = qvalue(elt(env, 1)); /* cursym!* */
    v0073 = elt(env, 5); /* !*colon!* */
    if (v0074 == v0073) goto v0080;
    v0073 = nil;
    goto v0081;

v0081:
    v0075 = stack[-2];
    v0074 = v0073;
    v0073 = stack[0];
    v0073 = acons(v0075, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    stack[0] = v0073;
    v0074 = qvalue(elt(env, 1)); /* cursym!* */
    v0073 = elt(env, 7); /* (!*comma!* !*rpar!*) */
    v0073 = Lmemq(nil, v0074, v0073);
    if (!(v0073 == nil)) goto v0082;
    v0074 = elt(env, 8); /* "Expecting ',' or ')' but found" */
    v0073 = qvalue(elt(env, 1)); /* cursym!* */
    v0073 = list2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    fn = elt(env, 15); /* assert_rederr */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    goto v0082;

v0082:
    v0074 = qvalue(elt(env, 1)); /* cursym!* */
    v0073 = elt(env, 9); /* !*comma!* */
    if (!(v0074 == v0073)) goto v0076;
    fn = elt(env, 16); /* scan */
    v0073 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    goto v0076;

v0080:
    fn = elt(env, 16); /* scan */
    v0073 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0073 = qvalue(elt(env, 1)); /* cursym!* */
    fn = elt(env, 17); /* assert_typesyntaxp */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    if (!(v0073 == nil)) goto v0030;
    v0074 = elt(env, 6); /* "Expecting type but found" */
    v0073 = qvalue(elt(env, 1)); /* cursym!* */
    v0073 = list2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    fn = elt(env, 15); /* assert_rederr */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    goto v0030;

v0030:
    v0073 = qvalue(elt(env, 1)); /* cursym!* */
    stack[-1] = v0073;
    fn = elt(env, 16); /* scan */
    v0073 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0073 = stack[-1];
    goto v0081;

v0077:
    v0074 = qvalue(elt(env, 10)); /* nxtsym!* */
    v0073 = elt(env, 5); /* !*colon!* */
    if (v0074 == v0073) goto v0003;
    v0074 = qvalue(elt(env, 10)); /* nxtsym!* */
    v0073 = elt(env, 12); /* !: */
    v0073 = (v0074 == v0073 ? lisp_true : nil);
    goto v0083;

v0083:
    if (v0073 == nil) goto v0084;
    fn = elt(env, 16); /* scan */
    v0073 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    fn = elt(env, 16); /* scan */
    v0073 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    v0073 = qvalue(elt(env, 1)); /* cursym!* */
    fn = elt(env, 17); /* assert_typesyntaxp */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    if (!(v0073 == nil)) goto v0085;
    v0074 = elt(env, 6); /* "Expecting type but found" */
    v0073 = qvalue(elt(env, 1)); /* cursym!* */
    v0073 = list2(v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    fn = elt(env, 15); /* assert_rederr */
    v0073 = (*qfn1(fn))(qenv(fn), v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-3];
    goto v0085;

v0085:
    v0073 = qvalue(elt(env, 1)); /* cursym!* */
    goto v0086;

v0086:
    v0075 = elt(env, 13); /* returnvalue */
    v0074 = v0073;
    v0073 = stack[0];
    v0073 = acons(v0075, v0074, v0073);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    stack[0] = v0073;
    v0073 = stack[0];
        popv(4);
        return Lnreverse(nil, v0073);

v0084:
    v0073 = nil;
    goto v0086;

v0003:
    v0073 = qvalue(elt(env, 11)); /* t */
    goto v0083;
/* error exit handlers */
v0078:
    popv(4);
    return nil;
}



/* Code for harmonicp */

static Lisp_Object CC_harmonicp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0048;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for harmonicp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0047 = v0000;
/* end of prologue */
    v0048 = elt(env, 1); /* fourier!-angle */
    return get(v0047, v0048);
}



/* Code for outer!-simpsqrt */

static Lisp_Object CC_outerKsimpsqrt(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for outer-simpsqrt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0076 = v0000;
/* end of prologue */
    v0049 = qvalue(elt(env, 1)); /* !*inside!-int!* */
    if (v0049 == nil) goto v0087;
    v0049 = v0076;
    {
        fn = elt(env, 2); /* proper!-simpsqrt */
        return (*qfn1(fn))(qenv(fn), v0049);
    }

v0087:
    v0049 = v0076;
    {
        fn = elt(env, 3); /* simpsqrt */
        return (*qfn1(fn))(qenv(fn), v0049);
    }
}



/* Code for listeval0 */

static Lisp_Object CC_listeval0(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0095, v0096;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listeval0");
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
    v0023 = qvalue(elt(env, 1)); /* simpcount!* */
    v0095 = add1(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-1];
    qvalue(elt(env, 1)) = v0095; /* simpcount!* */
    v0023 = qvalue(elt(env, 2)); /* simplimit!* */
    v0023 = (Lisp_Object)greaterp2(v0095, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    v0023 = v0023 ? lisp_true : nil;
    env = stack[-1];
    if (v0023 == nil) goto v0016;
    v0023 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v0023; /* simpcount!* */
    v0096 = elt(env, 3); /* rlisp */
    v0095 = (Lisp_Object)321; /* 20 */
    v0023 = elt(env, 4); /* "Simplification recursion too deep" */
    fn = elt(env, 5); /* rerror */
    v0023 = (*qfnn(fn))(qenv(fn), 3, v0096, v0095, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-1];
    goto v0016;

v0016:
    v0023 = stack[0];
    if (!(symbolp(v0023))) goto v0097;
    v0023 = stack[0];
    if (!symbolp(v0023)) v0023 = nil;
    else { v0023 = qfastgets(v0023);
           if (v0023 != nil) { v0023 = elt(v0023, 17); /* share */
#ifdef RECORD_GET
             if (v0023 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v0023 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v0023 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v0023 == SPID_NOPROP) v0023 = nil; else v0023 = lisp_true; }}
#endif
    if (v0023 == nil) goto v0098;
    v0023 = stack[0];
    fn = elt(env, 6); /* eval */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-1];
    v0023 = CC_listeval0(env, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-1];
    stack[0] = v0023;
    goto v0097;

v0097:
    v0023 = qvalue(elt(env, 1)); /* simpcount!* */
    v0023 = sub1(v0023);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-1];
    qvalue(elt(env, 1)) = v0023; /* simpcount!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0098:
    v0023 = stack[0];
    if (!symbolp(v0023)) v0023 = nil;
    else { v0023 = qfastgets(v0023);
           if (v0023 != nil) { v0023 = elt(v0023, 4); /* avalue */
#ifdef RECORD_GET
             if (v0023 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0023 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0023 == SPID_NOPROP) v0023 = nil; }}
#endif
    v0096 = v0023;
    if (v0023 == nil) goto v0097;
    v0023 = v0096;
    v0023 = qcdr(v0023);
    v0095 = qcar(v0023);
    v0023 = stack[0];
    if (equal(v0095, v0023)) goto v0097;
    v0023 = v0096;
    v0023 = qcdr(v0023);
    v0023 = qcar(v0023);
    v0023 = CC_listeval0(env, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-1];
    stack[0] = v0023;
    goto v0097;
/* error exit handlers */
v0081:
    popv(2);
    return nil;
}



/* Code for bvarom */

static Lisp_Object CC_bvarom(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bvarom");
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
    v0100 = stack[0];
    v0100 = qcar(v0100);
    v0100 = Lconsp(nil, v0100);
    env = stack[-1];
    if (v0100 == nil) goto v0005;
    v0100 = stack[0];
    v0100 = qcar(v0100);
    v0101 = qcar(v0100);
    v0100 = elt(env, 1); /* bvar */
    if (!(v0101 == v0100)) goto v0005;
    v0100 = stack[0];
    v0100 = qcar(v0100);
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    fn = elt(env, 2); /* objectom */
    v0100 = (*qfn1(fn))(qenv(fn), v0100);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-1];
    v0100 = stack[0];
    v0100 = qcdr(v0100);
    v0100 = CC_bvarom(env, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    goto v0005;

v0005:
    v0100 = nil;
    { popv(2); return onevalue(v0100); }
/* error exit handlers */
v0032:
    popv(2);
    return nil;
}



/* Code for multerm */

static Lisp_Object CC_multerm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multerm");
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
    v0101 = stack[-1];
    v0033 = qcdr(v0101);
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    fn = elt(env, 1); /* !*multsq */
    v0101 = (*qfn2(fn))(qenv(fn), v0033, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    stack[-2] = v0101;
    v0101 = stack[-1];
    v0033 = qcar(v0101);
    v0101 = stack[0];
    v0101 = qcar(v0101);
    fn = elt(env, 2); /* mulpower */
    v0101 = (*qfn2(fn))(qenv(fn), v0033, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-3];
    {
        Lisp_Object v0066 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multdfconst */
        return (*qfn2(fn))(qenv(fn), v0066, v0101);
    }
/* error exit handlers */
v0098:
    popv(4);
    return nil;
}



/* Code for redcodmat */

static Lisp_Object MS_CDECL CC_redcodmat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0079, v0104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "redcodmat");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for redcodmat");
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
    v0079 = qvalue(elt(env, 1)); /* rowmin */
    stack[0] = v0079;
    goto v0040;

v0040:
    v0104 = qvalue(elt(env, 2)); /* rowmax */
    v0079 = stack[0];
    v0079 = difference2(v0104, v0079);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    v0079 = Lminusp(nil, v0079);
    env = stack[-1];
    if (v0079 == nil) goto v0010;
    v0079 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0079); }

v0010:
    v0079 = stack[0];
    fn = elt(env, 4); /* testred */
    v0079 = (*qfn1(fn))(qenv(fn), v0079);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    v0079 = stack[0];
    v0079 = add1(v0079);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-1];
    stack[0] = v0079;
    goto v0040;
/* error exit handlers */
v0092:
    popv(2);
    return nil;
}



/* Code for unify */

static Lisp_Object MS_CDECL CC_unify(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0131, v0132, v0133, v0134;
    Lisp_Object fn;
    Lisp_Object v0010, v0016, v0005, v0011, v0012;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "unify");
    va_start(aa, nargs);
    v0012 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    v0016 = va_arg(aa, Lisp_Object);
    v0010 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unify");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0010,v0016,v0005,v0011,v0012);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0012,v0011,v0005,v0016,v0010);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-13] = v0010;
    stack[-14] = v0016;
    v0131 = v0005;
    v0132 = v0011;
    v0130 = v0012;
/* end of prologue */
    stack[-15] = qvalue(elt(env, 1)); /* op */
    qvalue(elt(env, 1)) = nil; /* op */
    stack[-12] = qvalue(elt(env, 2)); /* r */
    qvalue(elt(env, 2)) = nil; /* r */
    stack[-11] = qvalue(elt(env, 3)); /* p */
    qvalue(elt(env, 3)) = nil; /* p */
    qvalue(elt(env, 1)) = v0130; /* op */
    v0130 = v0132;
    qvalue(elt(env, 2)) = v0130; /* r */
    v0130 = v0131;
    qvalue(elt(env, 3)) = v0130; /* p */
    v0130 = qvalue(elt(env, 2)); /* r */
    if (v0130 == nil) goto v0099;
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0035;

v0035:
    if (v0130 == nil) goto v0071;
    v0131 = stack[-14];
    v0130 = stack[-13];
    fn = elt(env, 14); /* resume */
    v0130 = (*qfn2(fn))(qenv(fn), v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-16];
    goto v0049;

v0049:
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    { popv(17); return onevalue(v0130); }

v0071:
    v0130 = qvalue(elt(env, 2)); /* r */
    if (v0130 == nil) goto v0066;
    v0130 = qvalue(elt(env, 3)); /* p */
    if (v0130 == nil) goto v0136;
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0137;

v0137:
    if (v0130 == nil) goto v0095;
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0049;

v0095:
    stack[0] = nil;
    stack[-9] = nil;
    stack[-8] = qvalue(elt(env, 6)); /* symm */
    qvalue(elt(env, 6)) = nil; /* symm */
    stack[-7] = qvalue(elt(env, 7)); /* comb */
    qvalue(elt(env, 7)) = nil; /* comb */
    stack[-6] = qvalue(elt(env, 8)); /* identity */
    qvalue(elt(env, 8)) = nil; /* identity */
    stack[-5] = qvalue(elt(env, 9)); /* mcontract */
    qvalue(elt(env, 9)) = nil; /* mcontract */
    stack[-4] = qvalue(elt(env, 10)); /* acontract */
    qvalue(elt(env, 10)) = nil; /* acontract */
    stack[-3] = qvalue(elt(env, 11)); /* expand */
    qvalue(elt(env, 11)) = nil; /* expand */
    stack[-2] = qvalue(elt(env, 12)); /* i */
    qvalue(elt(env, 12)) = nil; /* i */
    stack[-1] = qvalue(elt(env, 13)); /* upb */
    qvalue(elt(env, 13)) = nil; /* upb */
    v0130 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 12)) = v0130; /* i */
    v0130 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 13)) = v0130; /* upb */
    v0130 = qvalue(elt(env, 2)); /* r */
    v0130 = qcar(v0130);
    fn = elt(env, 15); /* pm!:free */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    if (v0130 == nil) goto v0139;
    v0130 = qvalue(elt(env, 2)); /* r */
    v0130 = qcar(v0130);
    fn = elt(env, 16); /* genp */
    v0131 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    v0130 = stack[-14];
    v0130 = cons(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    stack[-14] = v0130;
    goto v0139;

v0139:
    v0130 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 17); /* initarg */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    goto v0082;

v0082:
    v0130 = stack[0];
    if (v0130 == nil) goto v0140;
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0059;

v0059:
    if (v0130 == nil) goto v0141;
    v0130 = qvalue(elt(env, 2)); /* r */
    v0130 = qcar(v0130);
    if (!consp(v0130)) goto v0142;
    v0134 = qvalue(elt(env, 1)); /* op */
    v0133 = qvalue(elt(env, 2)); /* r */
    v0132 = stack[-9];
    v0131 = stack[-14];
    v0130 = stack[-13];
    fn = elt(env, 18); /* suspend */
    v0130 = (*qfnn(fn))(qenv(fn), 5, v0134, v0133, v0132, v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    stack[0] = v0130;
    goto v0082;

v0142:
    v0130 = qvalue(elt(env, 2)); /* r */
    v0130 = qcar(v0130);
    fn = elt(env, 15); /* pm!:free */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    if (v0130 == nil) goto v0143;
    v0130 = qvalue(elt(env, 2)); /* r */
    v0131 = qcar(v0130);
    v0130 = stack[-9];
    v0130 = qcar(v0130);
    fn = elt(env, 19); /* bind */
    v0130 = (*qfn2(fn))(qenv(fn), v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    v0130 = stack[-14];
    fn = elt(env, 20); /* chk */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    stack[-10] = v0130;
    if (v0130 == nil) goto v0144;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v0130 = qvalue(elt(env, 2)); /* r */
    v0130 = qcdr(v0130);
    fn = elt(env, 21); /* mval */
    v0133 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    v0130 = stack[-9];
    v0132 = qcdr(v0130);
    v0131 = stack[-10];
    v0130 = stack[-13];
    v0130 = CC_unify(env, 5, stack[0], v0133, v0132, v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    stack[0] = v0130;
    goto v0144;

v0144:
    v0130 = qvalue(elt(env, 2)); /* r */
    v0130 = qcar(v0130);
    fn = elt(env, 22); /* unbind */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    goto v0082;

v0143:
    v0130 = qvalue(elt(env, 2)); /* r */
    v0131 = qcar(v0130);
    v0130 = stack[-9];
    v0130 = qcar(v0130);
    fn = elt(env, 23); /* meq */
    v0130 = (*qfn2(fn))(qenv(fn), v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    if (v0130 == nil) goto v0082;
    stack[0] = qvalue(elt(env, 1)); /* op */
    v0130 = qvalue(elt(env, 2)); /* r */
    v0130 = qcdr(v0130);
    fn = elt(env, 21); /* mval */
    v0133 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    v0130 = stack[-9];
    v0132 = qcdr(v0130);
    v0131 = stack[-14];
    v0130 = stack[-13];
    v0130 = CC_unify(env, 5, stack[0], v0133, v0132, v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    stack[0] = v0130;
    goto v0082;

v0141:
    v0130 = stack[0];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    goto v0049;

v0140:
    v0130 = qvalue(elt(env, 3)); /* p */
    fn = elt(env, 24); /* nextarg */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0138;
    env = stack[-16];
    stack[-9] = v0130;
    goto v0059;

v0136:
    v0130 = qvalue(elt(env, 1)); /* op */
    fn = elt(env, 25); /* ident */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-16];
    if (!(v0130 == nil)) goto v0031;
    v0130 = qvalue(elt(env, 2)); /* r */
    v0130 = qcar(v0130);
    fn = elt(env, 26); /* mgenp */
    v0130 = (*qfn1(fn))(qenv(fn), v0130);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-16];
    goto v0031;

v0031:
    v0130 = (v0130 == nil ? lisp_true : nil);
    goto v0137;

v0066:
    v0130 = elt(env, 5); /* "UNIFY:pattern over-run for function " */
    v0130 = Lprinc(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-16];
    v0130 = qvalue(elt(env, 1)); /* op */
    v0130 = Lprint(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0135;
    env = stack[-16];
    v0130 = qvalue(elt(env, 4)); /* nil */
    goto v0049;

v0099:
    v0130 = qvalue(elt(env, 3)); /* p */
    v0130 = (v0130 == nil ? lisp_true : nil);
    goto v0035;
/* error exit handlers */
v0138:
    env = stack[-16];
    qvalue(elt(env, 13)) = stack[-1]; /* upb */
    qvalue(elt(env, 12)) = stack[-2]; /* i */
    qvalue(elt(env, 11)) = stack[-3]; /* expand */
    qvalue(elt(env, 10)) = stack[-4]; /* acontract */
    qvalue(elt(env, 9)) = stack[-5]; /* mcontract */
    qvalue(elt(env, 8)) = stack[-6]; /* identity */
    qvalue(elt(env, 7)) = stack[-7]; /* comb */
    qvalue(elt(env, 6)) = stack[-8]; /* symm */
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
v0135:
    env = stack[-16];
    qvalue(elt(env, 3)) = stack[-11]; /* p */
    qvalue(elt(env, 2)) = stack[-12]; /* r */
    qvalue(elt(env, 1)) = stack[-15]; /* op */
    popv(17);
    return nil;
}



/* Code for mkbc */

static Lisp_Object CC_mkbc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkbc");
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

v0005:
    v0020 = stack[-1];
    v0020 = (is_number(v0020) ? lisp_true : nil);
    if (!(v0020 == nil)) goto v0010;
    v0020 = stack[-1];
    fn = elt(env, 3); /* f2dip11 */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    goto v0010;

v0010:
    v0020 = stack[0];
    v0020 = (is_number(v0020) ? lisp_true : nil);
    if (!(v0020 == nil)) goto v0076;
    v0020 = stack[0];
    fn = elt(env, 3); /* f2dip11 */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    goto v0076;

v0076:
    v0020 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0020 == nil) goto v0129;
    v0020 = stack[0];
    v0020 = Lmodular_reciprocal(nil, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    v0020 = times2(stack[-1], v0020);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0020);
    }

v0129:
    v0018 = stack[0];
    v0020 = (Lisp_Object)17; /* 1 */
    if (v0018 == v0020) goto v0068;
    v0020 = stack[0];
    fn = elt(env, 5); /* minusf */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    if (v0020 == nil) goto v0065;
    v0020 = stack[-1];
    fn = elt(env, 6); /* negf */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    stack[-1] = v0020;
    v0020 = stack[0];
    fn = elt(env, 6); /* negf */
    v0020 = (*qfn1(fn))(qenv(fn), v0020);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    stack[0] = v0020;
    goto v0005;

v0065:
    v0018 = stack[-1];
    v0020 = stack[0];
    fn = elt(env, 7); /* gcdf */
    v0020 = (*qfn2(fn))(qenv(fn), v0018, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    stack[-2] = v0020;
    v0018 = stack[-1];
    v0020 = stack[-2];
    fn = elt(env, 8); /* quotfx */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0018, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    env = stack[-3];
    v0018 = stack[0];
    v0020 = stack[-2];
    fn = elt(env, 8); /* quotfx */
    v0020 = (*qfn2(fn))(qenv(fn), v0018, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0140;
    {
        Lisp_Object v0043 = stack[-1];
        popv(4);
        return cons(v0043, v0020);
    }

v0068:
    v0018 = stack[-1];
    v0020 = (Lisp_Object)17; /* 1 */
    if (v0018 == v0020) goto v0151;
    v0018 = stack[-1];
    v0020 = stack[0];
    popv(4);
    return cons(v0018, v0020);

v0151:
    v0020 = elt(env, 2); /* (1 . 1) */
    { popv(4); return onevalue(v0020); }
/* error exit handlers */
v0140:
    popv(4);
    return nil;
}



/* Code for gfplus */

static Lisp_Object CC_gfplus(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0092, v0090, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfplus");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0090 = v0001;
    v0091 = v0000;
/* end of prologue */
    v0092 = v0091;
    v0092 = qcar(v0092);
    if (!consp(v0092)) goto v0047;
    v0092 = v0091;
    {
        fn = elt(env, 1); /* gbfplus */
        return (*qfn2(fn))(qenv(fn), v0092, v0090);
    }

v0047:
    v0092 = v0091;
    {
        fn = elt(env, 2); /* gffplus */
        return (*qfn2(fn))(qenv(fn), v0092, v0090);
    }
}



/* Code for collectphysops_reversed */

static Lisp_Object CC_collectphysops_reversed(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for collectphysops_reversed");
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
    v0096 = stack[-1];
    if (!consp(v0096)) goto v0010;
    v0096 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    if (v0096 == nil) goto v0069;
    stack[-2] = stack[-1];
    v0096 = stack[-1];
    fn = elt(env, 3); /* collectindices */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    fn = elt(env, 4); /* removeindices */
    v0108 = (*qfn2(fn))(qenv(fn), stack[-2], v0096);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    v0096 = stack[0];
    popv(4);
    return cons(v0108, v0096);

v0069:
    v0096 = stack[-1];
    if (!consp(v0096)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0096 = stack[-1];
    v0108 = qcar(v0096);
    v0096 = stack[0];
    v0096 = CC_collectphysops_reversed(env, v0108, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    stack[0] = v0096;
    v0096 = stack[-1];
    v0096 = qcdr(v0096);
    stack[-1] = v0096;
    goto v0069;

v0010:
    v0096 = stack[-1];
    fn = elt(env, 2); /* physopp */
    v0096 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    if (v0096 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0108 = stack[-1];
    v0096 = stack[0];
    popv(4);
    return cons(v0108, v0096);
/* error exit handlers */
v0027:
    popv(4);
    return nil;
}



/* Code for mk!-numr */

static Lisp_Object MS_CDECL CC_mkKnumr(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0042, v0155;
    Lisp_Object fn;
    Lisp_Object v0053, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk-numr");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0053 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk-numr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0053;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0040;

v0040:
    v0042 = stack[-1];
    v0089 = stack[0];
    if (equal(v0042, v0089)) goto v0047;
    v0042 = stack[-1];
    v0089 = (Lisp_Object)1; /* 0 */
    if (v0042 == v0089) goto v0097;
    v0155 = elt(env, 1); /* difference */
    v0042 = stack[-2];
    v0089 = stack[-1];
    v0089 = list3(v0155, v0042, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-4];
    v0042 = v0089;
    goto v0152;

v0152:
    v0089 = stack[-3];
    v0089 = cons(v0042, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-4];
    stack[-3] = v0089;
    v0089 = stack[-1];
    v0089 = add1(v0089);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[-4];
    stack[-1] = v0089;
    goto v0040;

v0097:
    v0089 = stack[-2];
    v0042 = v0089;
    goto v0152;

v0047:
    v0089 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0089);
    }
/* error exit handlers */
v0067:
    popv(5);
    return nil;
}



/* Code for ofsf_evalatp */

static Lisp_Object CC_ofsf_evalatp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0157, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_evalatp");
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
    v0127 = v0000;
/* end of prologue */
    v0157 = v0127;
    v0156 = elt(env, 1); /* equal */
    if (v0157 == v0156) goto v0005;
    v0157 = v0127;
    v0156 = elt(env, 2); /* neq */
    if (v0157 == v0156) goto v0153;
    v0157 = v0127;
    v0156 = elt(env, 3); /* leq */
    if (v0157 == v0156) goto v0090;
    v0157 = v0127;
    v0156 = elt(env, 4); /* geq */
    if (v0157 == v0156) goto v0029;
    v0157 = v0127;
    v0156 = elt(env, 5); /* lessp */
    if (v0157 == v0156) goto v0028;
    v0157 = v0127;
    v0156 = elt(env, 6); /* greaterp */
    if (v0157 == v0156) goto v0095;
    v0156 = elt(env, 7); /* "ofsf_evalatp: unknown operator " */
    v0157 = v0127;
    v0156 = list2(v0156, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 8); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0156);
    }

v0095:
    v0156 = stack[0];
    fn = elt(env, 9); /* minusf */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    if (!(v0156 == nil)) goto v0065;
    v0156 = stack[0];
    v0156 = (v0156 == nil ? lisp_true : nil);
    goto v0065;

v0065:
    v0156 = (v0156 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0156); }

v0028:
    v0156 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); /* minusf */
        return (*qfn1(fn))(qenv(fn), v0156);
    }

v0029:
    v0156 = stack[0];
    fn = elt(env, 9); /* minusf */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    v0156 = (v0156 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0156); }

v0090:
    v0156 = stack[0];
    fn = elt(env, 9); /* minusf */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    if (!(v0156 == nil)) { popv(2); return onevalue(v0156); }
    v0156 = stack[0];
    v0156 = (v0156 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0156); }

v0153:
    v0156 = stack[0];
    v0156 = (v0156 == nil ? lisp_true : nil);
    v0156 = (v0156 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0156); }

v0005:
    v0156 = stack[0];
    v0156 = (v0156 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v0156); }
/* error exit handlers */
v0060:
    popv(2);
    return nil;
}



/* Code for rtypepart */

static Lisp_Object CC_rtypepart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rtypepart");
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
    v0040 = v0000;
/* end of prologue */
    fn = elt(env, 3); /* getrtypecar */
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[0];
    if (v0040 == nil) goto v0087;
    v0040 = elt(env, 1); /* yetunknowntype */
    { popv(1); return onevalue(v0040); }

v0087:
    v0040 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0040); }
/* error exit handlers */
v0049:
    popv(1);
    return nil;
}



/* Code for evalnumberp */

static Lisp_Object CC_evalnumberp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0158, v0159, v0160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalnumberp");
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
    v0158 = v0000;
/* end of prologue */
    fn = elt(env, 5); /* aeval */
    v0158 = (*qfn1(fn))(qenv(fn), v0158);
    nil = C_nil;
    if (exception_pending()) goto v0154;
    env = stack[0];
    v0160 = v0158;
    v0158 = v0160;
    if (!consp(v0158)) goto v0010;
    v0158 = v0160;
    v0159 = qcar(v0158);
    v0158 = elt(env, 1); /* !*sq */
    if (v0159 == v0158) goto v0092;
    v0158 = qvalue(elt(env, 2)); /* t */
    goto v0093;

v0093:
    if (v0158 == nil) goto v0070;
    v0158 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v0158); }

v0070:
    v0158 = v0160;
    v0158 = qcdr(v0158);
    v0158 = qcar(v0158);
    v0158 = qcar(v0158);
    v0159 = v0158;
    v0158 = v0159;
    if (!consp(v0158)) goto v0161;
    v0158 = v0159;
    v0158 = qcar(v0158);
    v0159 = elt(env, 4); /* numbertag */
        popv(1);
        return Lflagp(nil, v0158, v0159);

v0161:
    v0158 = qvalue(elt(env, 2)); /* t */
    { popv(1); return onevalue(v0158); }

v0092:
    v0158 = v0160;
    v0158 = qcdr(v0158);
    v0158 = qcar(v0158);
    v0158 = qcdr(v0158);
    v0158 = (consp(v0158) ? nil : lisp_true);
    v0158 = (v0158 == nil ? lisp_true : nil);
    goto v0093;

v0010:
    v0158 = v0160;
    v0158 = (is_number(v0158) ? lisp_true : nil);
    { popv(1); return onevalue(v0158); }
/* error exit handlers */
v0154:
    popv(1);
    return nil;
}



/* Code for qqe_ofsf_varlat */

static Lisp_Object CC_qqe_ofsf_varlat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_ofsf_varlat");
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
    v0091 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* qqe_ofsf_prepat */
    v0091 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    stack[-1] = v0091;
    v0091 = stack[-1];
    fn = elt(env, 3); /* qqe_arg2l */
    v0102 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0091 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* qqe_ofsf_varlterm */
    stack[0] = (*qfn2(fn))(qenv(fn), v0102, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0091 = stack[-1];
    fn = elt(env, 5); /* qqe_arg2r */
    v0102 = (*qfn1(fn))(qenv(fn), v0091);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0091 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 4); /* qqe_ofsf_varlterm */
    v0091 = (*qfn2(fn))(qenv(fn), v0102, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    {
        Lisp_Object v0033 = stack[0];
        popv(3);
        fn = elt(env, 6); /* union */
        return (*qfn2(fn))(qenv(fn), v0033, v0091);
    }
/* error exit handlers */
v0101:
    popv(3);
    return nil;
}



/* Code for pasf_smordtable1 */

static Lisp_Object CC_pasf_smordtable1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0079, v0104;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smordtable1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0099 = v0001;
    v0079 = v0000;
/* end of prologue */
    v0104 = elt(env, 1); /* ((lessp (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (leq (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp fals
e) (cong nil) (ncong nil)) (equal (lessp 1) (leq 1) (equal false) (neq 1) (geq false) (greaterp false) (cong nil) (ncong nil)) (neq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong
 nil) (ncong nil)) (geq (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncong nil)) (greaterp (lessp nil) (leq nil) (equal 2) (neq nil) (geq 2) (greaterp 2) (cong nil) (ncon
g nil))) */
    v0079 = Latsoc(nil, v0079, v0104);
    v0099 = Latsoc(nil, v0099, v0079);
    v0099 = qcdr(v0099);
    return onevalue(v0099);
}



/* Code for ciml */

static Lisp_Object MS_CDECL CC_ciml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ciml");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ciml");
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
    v0162 = qvalue(elt(env, 2)); /* atts */
    v0066 = elt(env, 3); /* (t y p e) */
    fn = elt(env, 5); /* search_att */
    v0066 = (*qfn2(fn))(qenv(fn), v0162, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-1];
    fn = elt(env, 6); /* lex */
    v0066 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-1];
    v0066 = qvalue(elt(env, 4)); /* char */
    stack[0] = v0066;
    fn = elt(env, 6); /* lex */
    v0066 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-1];
    v0066 = stack[0];
    v0066 = Lcompress(nil, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    env = stack[-1];
    stack[0] = v0066;
    v0066 = stack[0];
    if (!(is_number(v0066))) goto v0079;
    v0162 = stack[0];
    v0066 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 7); /* errorml */
    v0066 = (*qfn2(fn))(qenv(fn), v0162, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0149;
    goto v0079;

v0079:
    v0066 = stack[0];
        popv(2);
        return Lintern(nil, v0066);
/* error exit handlers */
v0149:
    popv(2);
    return nil;
}



/* Code for contposp */

static Lisp_Object CC_contposp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0099;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0035 = v0000;
/* end of prologue */

v0163:
    v0099 = v0035;
    if (v0099 == nil) goto v0011;
    v0099 = v0035;
    v0099 = qcar(v0099);
    if (!consp(v0099)) goto v0040;
    v0035 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0035);

v0040:
    v0035 = qcdr(v0035);
    goto v0163;

v0011:
    v0035 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0035);
}



/* Code for fl2bf */

static Lisp_Object CC_fl2bf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0151, v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fl2bf");
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
    v0151 = v0000;
/* end of prologue */
    fn = elt(env, 3); /* frexp */
    v0151 = (*qfn1(fn))(qenv(fn), v0151);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-3];
    stack[-2] = v0151;
    v0151 = stack[-2];
    v0151 = qcdr(v0151);
    v0164 = stack[-2];
    v0164 = qcar(v0164);
    stack[-2] = v0164;
    stack[0] = v0151;
    v0164 = (Lisp_Object)33; /* 2 */
    v0151 = qvalue(elt(env, 1)); /* !!nbfpd */
    v0151 = Lexpt(nil, v0164, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-3];
    v0151 = times2(stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-3];
    v0151 = Ltruncate(nil, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-3];
    stack[-1] = elt(env, 2); /* !:rd!: */
    stack[0] = v0151;
    v0164 = stack[-2];
    v0151 = qvalue(elt(env, 1)); /* !!nbfpd */
    v0151 = difference2(v0164, v0151);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-3];
    v0151 = list2star(stack[-1], stack[0], v0151);
    nil = C_nil;
    if (exception_pending()) goto v0136;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* normbf */
        return (*qfn1(fn))(qenv(fn), v0151);
    }
/* error exit handlers */
v0136:
    popv(4);
    return nil;
}



/* Code for mkfortterpri */

static Lisp_Object MS_CDECL CC_mkfortterpri(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012;
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
    v0012 = elt(env, 1); /* fortterpri */
    return ncons(v0012);
}



/* Code for log_freevars */

static Lisp_Object CC_log_freevars(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0181, v0182, v0183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for log_freevars");
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
    v0182 = v0000;
/* end of prologue */
    v0181 = stack[0];
    if (!consp(v0181)) goto v0005;
    v0183 = stack[0];
    v0181 = elt(env, 7); /* quote */
    if (!consp(v0183)) goto v0043;
    v0183 = qcar(v0183);
    if (!(v0183 == v0181)) goto v0043;
    v0181 = qvalue(elt(env, 1)); /* t */
    goto v0062;

v0062:
    if (v0181 == nil) goto v0126;
    v0181 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0181); }

v0126:
    v0183 = stack[0];
    v0181 = elt(env, 10); /* prog */
    if (!consp(v0183)) goto v0074;
    v0183 = qcar(v0183);
    if (!(v0183 == v0181)) goto v0074;
    v0181 = stack[0];
    v0181 = qcdr(v0181);
    v0181 = qcar(v0181);
    v0183 = Lappend(nil, v0181, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    v0181 = stack[0];
    v0182 = qcdr(v0181);
    v0181 = qvalue(elt(env, 1)); /* t */
    {
        popv(2);
        fn = elt(env, 13); /* log_freevars_list */
        return (*qfnn(fn))(qenv(fn), 3, v0183, v0182, v0181);
    }

v0074:
    v0183 = stack[0];
    v0181 = elt(env, 11); /* lambda */
    if (!consp(v0183)) goto v0185;
    v0183 = qcar(v0183);
    if (!(v0183 == v0181)) goto v0185;
    v0181 = stack[0];
    v0181 = qcdr(v0181);
    v0181 = qcar(v0181);
    v0183 = Lappend(nil, v0181, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    v0181 = stack[0];
    v0182 = qcdr(v0181);
    v0181 = qvalue(elt(env, 3)); /* nil */
    {
        popv(2);
        fn = elt(env, 13); /* log_freevars_list */
        return (*qfnn(fn))(qenv(fn), 3, v0183, v0182, v0181);
    }

v0185:
    v0183 = stack[0];
    v0181 = elt(env, 12); /* cond */
    if (!consp(v0183)) goto v0186;
    v0183 = qcar(v0183);
    if (!(v0183 == v0181)) goto v0186;
    v0181 = stack[0];
    v0181 = qcdr(v0181);
    {
        popv(2);
        fn = elt(env, 14); /* log_freevars_list_list */
        return (*qfn2(fn))(qenv(fn), v0182, v0181);
    }

v0186:
    v0181 = stack[0];
    v0181 = qcar(v0181);
    if (!consp(v0181)) goto v0130;
    v0183 = v0182;
    v0182 = stack[0];
    v0181 = qvalue(elt(env, 3)); /* nil */
    {
        popv(2);
        fn = elt(env, 13); /* log_freevars_list */
        return (*qfnn(fn))(qenv(fn), 3, v0183, v0182, v0181);
    }

v0130:
    v0183 = v0182;
    v0181 = stack[0];
    v0182 = qcdr(v0181);
    v0181 = qvalue(elt(env, 3)); /* nil */
    {
        popv(2);
        fn = elt(env, 13); /* log_freevars_list */
        return (*qfnn(fn))(qenv(fn), 3, v0183, v0182, v0181);
    }

v0043:
    v0183 = stack[0];
    v0181 = elt(env, 8); /* function */
    if (!consp(v0183)) goto v0187;
    v0183 = qcar(v0183);
    if (!(v0183 == v0181)) goto v0187;
    v0181 = stack[0];
    v0181 = qcdr(v0181);
    v0181 = qcar(v0181);
    v0181 = (consp(v0181) ? nil : lisp_true);
    goto v0015;

v0015:
    if (v0181 == nil) goto v0188;
    v0181 = qvalue(elt(env, 1)); /* t */
    goto v0062;

v0188:
    v0183 = stack[0];
    v0181 = elt(env, 9); /* go */
    v0181 = Leqcar(nil, v0183, v0181);
    env = stack[-1];
    goto v0062;

v0187:
    v0181 = qvalue(elt(env, 3)); /* nil */
    goto v0015;

v0005:
    v0181 = stack[0];
    if (symbolp(v0181)) goto v0099;
    v0181 = qvalue(elt(env, 1)); /* t */
    goto v0049;

v0049:
    if (v0181 == nil) goto v0108;
    v0181 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v0181); }

v0108:
    v0181 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    v0181 = (Lisp_Object)zerop(v0181);
    v0181 = v0181 ? lisp_true : nil;
    env = stack[-1];
    if (!(v0181 == nil)) goto v0026;
    v0181 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    goto v0026;

v0026:
    v0181 = elt(env, 4); /* "+++ Use of free variable in smacro/inline body: " 
*/
    v0181 = Lprinc(nil, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    v0181 = stack[0];
    v0181 = Lprint(nil, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    v0181 = elt(env, 5); /* "+++ Macro was: " */
    v0181 = Lprinc(nil, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    v0181 = qvalue(elt(env, 6)); /* inlineinfo */
    v0181 = Lprint(nil, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    v0181 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0181); }

v0099:
    v0181 = stack[0];
    v0181 = Lmember(nil, v0181, v0182);
    if (!(v0181 == nil)) goto v0049;
    v0181 = stack[0];
    v0181 = Lsymbol_globalp(nil, v0181);
    env = stack[-1];
    if (!(v0181 == nil)) goto v0049;
    v0181 = stack[0];
    v0181 = Lsymbol_specialp(nil, v0181);
    nil = C_nil;
    if (exception_pending()) goto v0184;
    env = stack[-1];
    if (!(v0181 == nil)) goto v0049;
    v0182 = stack[0];
    v0181 = elt(env, 2); /* constant!? */
    v0181 = get(v0182, v0181);
    env = stack[-1];
    if (!(v0181 == nil)) goto v0049;
    v0181 = stack[0];
    if (v0181 == nil) goto v0128;
    v0182 = stack[0];
    v0181 = qvalue(elt(env, 1)); /* t */
    v0181 = (equal(v0182, v0181) ? lisp_true : nil);
    goto v0049;

v0128:
    v0181 = qvalue(elt(env, 1)); /* t */
    goto v0049;
/* error exit handlers */
v0184:
    popv(2);
    return nil;
}



/* Code for clean_numid */

static Lisp_Object CC_clean_numid(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for clean_numid");
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
    goto v0005;

v0005:
    v0101 = stack[0];
    if (v0101 == nil) goto v0088;
    v0101 = stack[0];
    v0101 = qcar(v0101);
    fn = elt(env, 1); /* !*id2num */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-2];
    if (v0101 == nil) goto v0099;
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    stack[0] = v0101;
    goto v0005;

v0099:
    v0101 = stack[0];
    v0033 = qcar(v0101);
    v0101 = stack[-1];
    v0101 = cons(v0033, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-2];
    stack[-1] = v0101;
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    stack[0] = v0101;
    goto v0005;

v0088:
    v0101 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0101);
    }
/* error exit handlers */
v0129:
    popv(3);
    return nil;
}



/* Code for assoc2 */

static Lisp_Object CC_assoc2(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0091, v0102, v0097, v0100;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assoc2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0097 = v0001;
    v0100 = v0000;
/* end of prologue */

v0005:
    v0091 = v0097;
    if (v0091 == nil) goto v0088;
    v0102 = v0100;
    v0091 = v0097;
    v0091 = qcar(v0091);
    v0091 = qcdr(v0091);
    if (equal(v0102, v0091)) goto v0040;
    v0091 = v0097;
    v0091 = qcdr(v0091);
    v0097 = v0091;
    goto v0005;

v0040:
    v0091 = v0097;
    v0091 = qcar(v0091);
    return onevalue(v0091);

v0088:
    v0091 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0091);
}



/* Code for reduce!-mod!-eigf */

static Lisp_Object CC_reduceKmodKeigf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-mod-eigf");
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
    stack[-1] = v0001;
    v0032 = v0000;
/* end of prologue */
    v0070 = qvalue(elt(env, 1)); /* !*sub2 */
    stack[-2] = qvalue(elt(env, 1)); /* !*sub2 */
    qvalue(elt(env, 1)) = v0070; /* !*sub2 */
    v0070 = v0032;
    v0070 = qcar(v0070);
    stack[0] = qcar(v0070);
    v0070 = v0032;
    v0070 = qcdr(v0070);
    v0032 = qcar(v0032);
    v0032 = qcdr(v0032);
    v0032 = cons(v0070, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-3];
    fn = elt(env, 2); /* cancel */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-3];
    fn = elt(env, 3); /* negsq */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-3];
    v0070 = cons(stack[0], v0032);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-3];
    v0032 = stack[-1];
    fn = elt(env, 4); /* reduce!-eival!-powers */
    v0032 = (*qfn2(fn))(qenv(fn), v0070, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-3];
    fn = elt(env, 5); /* subs2 */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* !*sub2 */
    { popv(4); return onevalue(v0032); }
/* error exit handlers */
v0162:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* !*sub2 */
    popv(4);
    return nil;
}



/* Code for mk!+squared!+norm */

static Lisp_Object CC_mkLsquaredLnorm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+squared+norm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0040 = v0000;
/* end of prologue */
    v0049 = v0040;
    {
        fn = elt(env, 1); /* mk!+inner!+product */
        return (*qfn2(fn))(qenv(fn), v0049, v0040);
    }
}



/* Code for cl_susicpknowl */

static Lisp_Object CC_cl_susicpknowl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0158, v0159;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_susicpknowl");
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
    v0158 = v0000;
/* end of prologue */
    stack[-3] = v0158;
    v0158 = stack[-3];
    if (v0158 == nil) goto v0048;
    v0158 = stack[-3];
    v0158 = qcar(v0158);
    v0159 = v0158;
    v0159 = qcar(v0159);
    v0158 = qcdr(v0158);
    v0158 = cons(v0159, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0158 = ncons(v0158);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    stack[-1] = v0158;
    stack[-2] = v0158;
    goto v0010;

v0010:
    v0158 = stack[-3];
    v0158 = qcdr(v0158);
    stack[-3] = v0158;
    v0158 = stack[-3];
    if (v0158 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0158 = stack[-3];
    v0158 = qcar(v0158);
    v0159 = v0158;
    v0159 = qcar(v0159);
    v0158 = qcdr(v0158);
    v0158 = cons(v0159, v0158);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0158 = ncons(v0158);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0158 = Lrplacd(nil, stack[0], v0158);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-4];
    v0158 = stack[-1];
    v0158 = qcdr(v0158);
    stack[-1] = v0158;
    goto v0010;

v0048:
    v0158 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0158); }
/* error exit handlers */
v0023:
    popv(5);
    return nil;
}



/* Code for make!-modular!-symmetric */

static Lisp_Object CC_makeKmodularKsymmetric(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0024, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for make-modular-symmetric");
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
    v0024 = stack[-1];
    if (v0024 == nil) goto v0011;
    v0024 = stack[-1];
    if (!consp(v0024)) goto v0040;
    v0024 = stack[-1];
    v0024 = qcar(v0024);
    v0024 = (consp(v0024) ? nil : lisp_true);
    goto v0048;

v0048:
    if (v0024 == nil) goto v0068;
    v0023 = stack[-1];
    v0024 = qvalue(elt(env, 3)); /* modulus!/2 */
    v0024 = (Lisp_Object)greaterp2(v0023, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    v0024 = v0024 ? lisp_true : nil;
    env = stack[-3];
    if (v0024 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0023 = stack[-1];
    v0024 = qvalue(elt(env, 4)); /* current!-modulus */
    v0024 = difference2(v0023, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 5); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0024);
    }

v0068:
    v0024 = stack[-1];
    v0024 = qcar(v0024);
    stack[-2] = qcar(v0024);
    v0024 = stack[-1];
    v0024 = qcar(v0024);
    v0024 = qcdr(v0024);
    stack[0] = CC_makeKmodularKsymmetric(env, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-3];
    v0024 = stack[-1];
    v0024 = qcdr(v0024);
    v0024 = CC_makeKmodularKsymmetric(env, v0024);
    nil = C_nil;
    if (exception_pending()) goto v0081;
    env = stack[-3];
    {
        Lisp_Object v0114 = stack[-2];
        Lisp_Object v0026 = stack[0];
        popv(4);
        fn = elt(env, 6); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0114, v0026, v0024);
    }

v0040:
    v0024 = qvalue(elt(env, 2)); /* t */
    goto v0048;

v0011:
    v0024 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0024); }
/* error exit handlers */
v0081:
    popv(4);
    return nil;
}



/* Code for setfuncsnaryrd */

static Lisp_Object MS_CDECL CC_setfuncsnaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setfuncsnaryrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setfuncsnaryrd");
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
    fn = elt(env, 4); /* mathml */
    v0148 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-1];
    stack[0] = v0148;
    v0148 = stack[0];
    v0148 = Lconsp(nil, v0148);
    env = stack[-1];
    if (v0148 == nil) goto v0016;
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    if (v0148 == nil) goto v0016;
    v0148 = stack[0];
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0148 = qcar(v0148);
    v0148 = qcdr(v0148);
    v0148 = qcar(v0148);
    v0128 = Lintern(nil, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-1];
    v0148 = elt(env, 1); /* multiset */
    if (!(v0128 == v0148)) goto v0016;
    v0148 = elt(env, 1); /* multiset */
    qvalue(elt(env, 2)) = v0148; /* mmlatts */
    goto v0016;

v0016:
    v0148 = stack[0];
    if (v0148 == nil) goto v0066;
    v0148 = CC_setfuncsnaryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    {
        Lisp_Object v0089 = stack[0];
        popv(2);
        return cons(v0089, v0148);
    }

v0066:
    v0148 = nil;
    { popv(2); return onevalue(v0148); }
/* error exit handlers */
v0028:
    popv(2);
    return nil;
}



/* Code for delyzz */

static Lisp_Object CC_delyzz(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0150, v0029;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delyzz");
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
    v0029 = nil;
    goto v0048;

v0048:
    v0150 = stack[-1];
    v0149 = stack[0];
    v0149 = qcar(v0149);
    v0149 = qcar(v0149);
    if (equal(v0150, v0149)) goto v0034;
    v0149 = stack[0];
    v0149 = qcar(v0149);
    v0150 = v0029;
    v0149 = cons(v0149, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0164;
    env = stack[-2];
    v0029 = v0149;
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    stack[0] = v0149;
    goto v0048;

v0034:
    v0150 = v0029;
    v0149 = stack[0];
    v0149 = qcdr(v0149);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0150, v0149);
    }
/* error exit handlers */
v0164:
    popv(3);
    return nil;
}



/* Code for suchp */

static Lisp_Object CC_suchp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0072, v0071;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for suchp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0071 = v0000;
/* end of prologue */
    v0072 = v0071;
    if (!consp(v0072)) goto v0153;
    v0072 = v0071;
    v0072 = qcar(v0072);
    v0071 = elt(env, 1); /* such!-that */
    v0072 = (v0072 == v0071 ? lisp_true : nil);
    return onevalue(v0072);

v0153:
    v0072 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0072);
}



/* Code for sc_subtrsq */

static Lisp_Object CC_sc_subtrsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_subtrsq");
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
    v0040 = v0001;
    v0049 = v0000;
/* end of prologue */
    stack[0] = v0049;
    fn = elt(env, 1); /* negsq */
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    {
        Lisp_Object v0153 = stack[0];
        popv(2);
        fn = elt(env, 2); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0153, v0040);
    }
/* error exit handlers */
v0093:
    popv(2);
    return nil;
}



/* Code for lessppair */

static Lisp_Object CC_lessppair(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0098, v0066, v0162, v0080;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lessppair");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0066 = v0001;
    v0162 = v0000;
/* end of prologue */
    v0098 = v0162;
    v0080 = qcar(v0098);
    v0098 = v0066;
    v0098 = qcar(v0098);
    if (equal(v0080, v0098)) goto v0094;
    v0098 = v0162;
    v0098 = qcar(v0098);
    v0066 = qcar(v0066);
        return Llessp(nil, v0098, v0066);

v0094:
    v0098 = v0162;
    v0098 = qcdr(v0098);
    v0066 = qcdr(v0066);
        return Llessp(nil, v0098, v0066);
}



/* Code for ratdif */

static Lisp_Object CC_ratdif(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratdif");
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
    v0093 = v0001;
    v0153 = v0000;
/* end of prologue */
    stack[0] = v0153;
    fn = elt(env, 2); /* ratminus */
    v0153 = (*qfn1(fn))(qenv(fn), v0093);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-1];
    v0093 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0072 = stack[0];
        popv(2);
        fn = elt(env, 3); /* ratplusm */
        return (*qfnn(fn))(qenv(fn), 3, v0072, v0153, v0093);
    }
/* error exit handlers */
v0103:
    popv(2);
    return nil;
}



/* Code for cl_atl1 */

static Lisp_Object CC_cl_atl1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_atl1");
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
    v0161 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* cl_atml1 */
    v0161 = (*qfn1(fn))(qenv(fn), v0161);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-3] = v0161;
    v0161 = stack[-3];
    if (v0161 == nil) goto v0040;
    v0161 = stack[-3];
    v0161 = qcar(v0161);
    v0161 = qcar(v0161);
    v0161 = ncons(v0161);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    stack[-1] = v0161;
    stack[-2] = v0161;
    goto v0010;

v0010:
    v0161 = stack[-3];
    v0161 = qcdr(v0161);
    stack[-3] = v0161;
    v0161 = stack[-3];
    if (v0161 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0161 = stack[-3];
    v0161 = qcar(v0161);
    v0161 = qcar(v0161);
    v0161 = ncons(v0161);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    v0161 = Lrplacd(nil, stack[0], v0161);
    nil = C_nil;
    if (exception_pending()) goto v0137;
    env = stack[-4];
    v0161 = stack[-1];
    v0161 = qcdr(v0161);
    stack[-1] = v0161;
    goto v0010;

v0040:
    v0161 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0161); }
/* error exit handlers */
v0137:
    popv(5);
    return nil;
}



/* Code for cl_smsimpl!-junct */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0056, v0177, v0198, v0086, v0122, v0199, v0123;
    Lisp_Object fn;
    Lisp_Object v0012, v0053, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "cl_smsimpl-junct");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0053 = va_arg(aa, Lisp_Object);
    v0012 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_smsimpl-junct");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0012,v0053,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0053,v0012);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0012;
    stack[-6] = v0053;
    stack[0] = v0001;
    stack[-7] = v0000;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    v0056 = qvalue(elt(env, 1)); /* !*rlsism */
    if (v0056 == nil) goto v0103;
    v0056 = stack[-6];
    fn = elt(env, 5); /* rl_smcpknowl */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-9];
    stack[-2] = v0056;
    v0198 = elt(env, 3); /* false */
    v0177 = stack[-7];
    v0056 = elt(env, 4); /* and */
    v0056 = (v0177 == v0056 ? lisp_true : nil);
    fn = elt(env, 6); /* cl_cflip */
    v0056 = (*qfn2(fn))(qenv(fn), v0198, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-9];
    stack[-8] = v0056;
    v0056 = stack[0];
    stack[-1] = v0056;
    goto v0136;

v0136:
    v0056 = stack[-1];
    if (v0056 == nil) goto v0019;
    v0056 = stack[-1];
    v0056 = qcar(v0056);
    stack[0] = v0056;
    v0056 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-9];
    if (v0056 == nil) goto v0106;
    v0177 = stack[0];
    v0056 = stack[-7];
    fn = elt(env, 8); /* cl_simplat */
    v0056 = (*qfn2(fn))(qenv(fn), v0177, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-9];
    goto v0154;

v0154:
    stack[0] = v0056;
    v0056 = stack[0];
    fn = elt(env, 7); /* cl_atfp */
    v0056 = (*qfn1(fn))(qenv(fn), v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-9];
    if (v0056 == nil) goto v0157;
    v0177 = stack[0];
    v0056 = stack[-4];
    v0056 = cons(v0177, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-9];
    stack[-4] = v0056;
    goto v0107;

v0107:
    v0056 = stack[-1];
    v0056 = qcdr(v0056);
    stack[-1] = v0056;
    goto v0136;

v0157:
    v0177 = stack[0];
    v0056 = stack[-3];
    v0056 = cons(v0177, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-9];
    stack[-3] = v0056;
    goto v0107;

v0106:
    v0056 = stack[0];
    goto v0154;

v0019:
    v0086 = stack[-7];
    v0198 = stack[-4];
    v0177 = stack[-2];
    v0056 = stack[-5];
    fn = elt(env, 9); /* rl_smupdknowl */
    v0056 = (*qfnn(fn))(qenv(fn), 4, v0086, v0198, v0177, v0056);
    nil = C_nil;
    if (exception_pending()) goto v0073;
    env = stack[-9];
    stack[-2] = v0056;
    v0177 = stack[-2];
    v0056 = elt(env, 3); /* false */
    if (v0177 == v0056) goto v0002;
    v0123 = stack[-7];
    v0199 = stack[-4];
    v0056 = stack[-3];
    v0122 = Lnreverse(nil, v0056);
    env = stack[-9];
    v0086 = stack[-6];
    v0198 = stack[-2];
    v0177 = stack[-5];
    v0056 = stack[-8];
    {
        popv(10);
        fn = elt(env, 10); /* cl_smsimpl!-junct1 */
        return (*qfnn(fn))(qenv(fn), 7, v0123, v0199, v0122, v0086, v0198, v0177, v0056);
    }

v0002:
    v0056 = stack[-8];
    popv(10);
    return ncons(v0056);

v0103:
    v0086 = stack[0];
    v0198 = stack[-5];
    v0177 = stack[-7];
    v0056 = qvalue(elt(env, 2)); /* nil */
    {
        popv(10);
        fn = elt(env, 11); /* cl_gand!-col */
        return (*qfnn(fn))(qenv(fn), 4, v0086, v0198, v0177, v0056);
    }
/* error exit handlers */
v0073:
    popv(10);
    return nil;
}



/* Code for depend!-f */

static Lisp_Object CC_dependKf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for depend-f");
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

v0163:
    v0089 = stack[-1];
    if (!consp(v0089)) goto v0087;
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    v0089 = (consp(v0089) ? nil : lisp_true);
    goto v0088;

v0088:
    if (v0089 == nil) goto v0104;
    v0089 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0089); }

v0104:
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    v0089 = qcar(v0089);
    v0042 = qcar(v0089);
    v0089 = stack[0];
    fn = elt(env, 3); /* depend!-p */
    v0089 = (*qfn2(fn))(qenv(fn), v0042, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    if (!(v0089 == nil)) { popv(3); return onevalue(v0089); }
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    v0042 = qcdr(v0089);
    v0089 = stack[0];
    v0089 = CC_dependKf(env, v0042, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-2];
    if (!(v0089 == nil)) { popv(3); return onevalue(v0089); }
    v0089 = stack[-1];
    v0042 = qcdr(v0089);
    v0089 = stack[0];
    stack[-1] = v0042;
    stack[0] = v0089;
    goto v0163;

v0087:
    v0089 = qvalue(elt(env, 1)); /* t */
    goto v0088;
/* error exit handlers */
v0159:
    popv(3);
    return nil;
}



/* Code for critical_element */

static Lisp_Object CC_critical_element(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0049;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for critical_element");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0040 = v0000;
/* end of prologue */
    v0049 = v0040;
    v0049 = qcdr(v0049);
    v0049 = qcar(v0049);
        return Lapply1(nil, v0049, v0040);
}



/* Code for mktails */

static Lisp_Object MS_CDECL CC_mktails(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0096, v0108;
    Lisp_Object fn;
    Lisp_Object v0053, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktails");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0053 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mktails");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0096 = v0053;
    stack[-2] = v0001;
    v0108 = v0000;
/* end of prologue */
    stack[0] = nil;
    v0095 = v0108;
    if (v0095 == nil) goto v0153;
    v0095 = v0108;
    stack[-3] = v0095;
    v0095 = v0096;
    stack[-1] = v0095;
    goto v0092;

v0092:
    v0095 = stack[-3];
    if (v0095 == nil) goto v0158;
    v0095 = stack[-3];
    v0108 = qcar(v0095);
    v0096 = stack[-2];
    v0095 = stack[-1];
    fn = elt(env, 2); /* mktails1 */
    v0095 = (*qfnn(fn))(qenv(fn), 3, v0108, v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    v0096 = v0095;
    v0095 = v0096;
    v0095 = qcdr(v0095);
    stack[-1] = v0095;
    v0095 = v0096;
    v0096 = qcar(v0095);
    v0095 = stack[0];
    v0095 = Lappend(nil, v0096, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-4];
    stack[0] = v0095;
    v0095 = stack[-3];
    v0095 = qcdr(v0095);
    stack[-3] = v0095;
    goto v0092;

v0158:
    v0096 = stack[0];
    v0095 = stack[-1];
    popv(5);
    return cons(v0096, v0095);

v0153:
    v0095 = qvalue(elt(env, 1)); /* nil */
    popv(5);
    return cons(v0095, v0096);
/* error exit handlers */
v0025:
    popv(5);
    return nil;
}



/* Code for remchkf1 */

static Lisp_Object CC_remchkf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069, v0137, v0136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remchkf1");
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
    v0069 = stack[-1];
    fn = elt(env, 4); /* termsf */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    stack[-2] = v0069;
    v0136 = stack[-1];
    v0137 = stack[0];
    v0069 = stack[-2];
    fn = elt(env, 5); /* xremf */
    v0069 = (*qfnn(fn))(qenv(fn), 3, v0136, v0137, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    stack[0] = v0069;
    v0069 = stack[0];
    if (v0069 == nil) goto v0152;
    v0069 = stack[0];
    v0069 = qcar(v0069);
    stack[0] = v0069;
    fn = elt(env, 4); /* termsf */
    v0137 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    v0069 = stack[-2];
    v0069 = (Lisp_Object)geq2(v0137, v0069);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    v0069 = v0069 ? lisp_true : nil;
    env = stack[-3];
    goto v0104;

v0104:
    if (!(v0069 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0069 = qvalue(elt(env, 2)); /* !*trcompact */
    if (v0069 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0069 = elt(env, 3); /* "*** Remainder smaller" */
    fn = elt(env, 6); /* prin2t */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v0152:
    v0069 = qvalue(elt(env, 1)); /* t */
    goto v0104;
/* error exit handlers */
v0031:
    popv(4);
    return nil;
}



/* Code for simp!-prop2 */

static Lisp_Object CC_simpKprop2(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0046, v0204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp-prop2");
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
    v0045 = qvalue(elt(env, 1)); /* propvars!* */
    stack[-1] = v0045;
    goto v0076;

v0076:
    v0045 = stack[-1];
    if (v0045 == nil) goto v0049;
    v0045 = stack[-1];
    v0045 = qcar(v0045);
    stack[0] = v0045;
    v0045 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v0045;
    goto v0090;

v0090:
    v0045 = stack[-5];
    if (v0045 == nil) goto v0092;
    v0045 = stack[-5];
    v0045 = qcar(v0045);
    stack[-3] = v0045;
    v0045 = stack[-5];
    v0045 = qcdr(v0045);
    stack[-5] = v0045;
    v0046 = elt(env, 3); /* prop!* */
    v0045 = stack[0];
    v0045 = list2(v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-7];
    stack[-4] = v0045;
    v0046 = elt(env, 4); /* not_prop!* */
    v0045 = stack[0];
    v0045 = list2(v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-7];
    v0204 = v0045;
    v0046 = stack[-4];
    v0045 = stack[-3];
    v0045 = Lmember(nil, v0046, v0045);
    if (!(v0045 == nil)) goto v0027;
    v0045 = v0204;
    v0046 = stack[-4];
    v0204 = v0046;
    stack[-4] = v0045;
    goto v0027;

v0027:
    v0046 = stack[-4];
    v0045 = stack[-3];
    v0045 = Lsubst(nil, 3, v0204, v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-7];
    stack[-6] = v0045;
    v0046 = stack[-3];
    v0045 = stack[-2];
    v0045 = cons(v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-7];
    stack[-2] = v0045;
    v0046 = stack[-6];
    v0045 = stack[-5];
    v0045 = Lmember(nil, v0046, v0045);
    stack[-6] = v0045;
    if (v0045 == nil) goto v0090;
    v0045 = stack[-6];
    if (v0045 == nil) goto v0205;
    v0045 = stack[-6];
    v0046 = qcar(v0045);
    v0045 = stack[-5];
    v0045 = Ldelete(nil, v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-7];
    stack[-5] = v0045;
    v0045 = stack[-6];
    v0046 = qcar(v0045);
    v0045 = stack[-2];
    v0045 = cons(v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-7];
    stack[-2] = v0045;
    goto v0205;

v0205:
    v0046 = stack[-4];
    v0045 = stack[-3];
    v0045 = Ldelete(nil, v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-7];
    stack[-3] = v0045;
    v0045 = stack[-3];
    v0046 = ncons(v0045);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-7];
    v0045 = stack[-2];
    fn = elt(env, 5); /* union */
    v0045 = (*qfn2(fn))(qenv(fn), v0046, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-7];
    stack[-2] = v0045;
    goto v0090;

v0092:
    v0045 = stack[-2];
    stack[-5] = v0045;
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    stack[-1] = v0045;
    goto v0076;

v0049:
    v0045 = stack[-5];
    {
        popv(8);
        fn = elt(env, 6); /* simp!-prop!-condense */
        return (*qfn1(fn))(qenv(fn), v0045);
    }
/* error exit handlers */
v0086:
    popv(8);
    return nil;
}



/* Code for fd2q */

static Lisp_Object CC_fd2q(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0206, v0147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fd2q");
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

v0011:
    v0206 = stack[0];
    if (!consp(v0206)) goto v0048;
    v0206 = stack[0];
    v0147 = qcar(v0206);
    v0206 = elt(env, 1); /* !:ar!: */
    if (v0147 == v0206) goto v0103;
    v0206 = stack[0];
    v0147 = qcar(v0206);
    v0206 = elt(env, 2); /* !:rn!: */
    if (v0147 == v0206) goto v0102;
    v0206 = stack[0];
    v0206 = qcar(v0206);
    v0147 = qcar(v0206);
    v0206 = (Lisp_Object)17; /* 1 */
    v0206 = cons(v0147, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    v0147 = ncons(v0206);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    v0206 = (Lisp_Object)17; /* 1 */
    stack[-1] = cons(v0147, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    v0206 = stack[0];
    v0206 = qcar(v0206);
    v0206 = qcdr(v0206);
    v0206 = CC_fd2q(env, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    fn = elt(env, 3); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0206);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    v0206 = stack[0];
    v0206 = qcdr(v0206);
    v0206 = CC_fd2q(env, v0206);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-2];
    {
        Lisp_Object v0207 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addsq */
        return (*qfn2(fn))(qenv(fn), v0207, v0206);
    }

v0102:
    v0206 = stack[0];
    v0206 = qcdr(v0206);
    { popv(3); return onevalue(v0206); }

v0103:
    v0206 = stack[0];
    v0206 = qcdr(v0206);
    stack[0] = v0206;
    goto v0011;

v0048:
    v0147 = stack[0];
    v0206 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0147, v0206);
/* error exit handlers */
v0139:
    popv(3);
    return nil;
}



/* Code for general!-ordered!-gcd!-mod!-p */

static Lisp_Object CC_generalKorderedKgcdKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0107, v0206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-ordered-gcd-mod-p");
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
    v0107 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0107;
    goto v0087;

v0087:
    v0206 = stack[-1];
    v0107 = stack[0];
    fn = elt(env, 3); /* general!-reduce!-degree!-mod!-p */
    v0107 = (*qfn2(fn))(qenv(fn), v0206, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    stack[-1] = v0107;
    v0107 = stack[-1];
    if (v0107 == nil) goto v0103;
    v0107 = stack[-2];
    v0107 = add1(v0107);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    stack[-2] = v0107;
    v0107 = stack[-1];
    if (!consp(v0107)) goto v0097;
    v0107 = stack[-1];
    v0107 = qcar(v0107);
    v0107 = (consp(v0107) ? nil : lisp_true);
    goto v0102;

v0102:
    if (v0107 == nil) goto v0030;
    v0206 = qvalue(elt(env, 2)); /* reduction!-count */
    v0107 = stack[-2];
    v0107 = plus2(v0206, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0107; /* reduction!-count */
    v0107 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v0107); }

v0030:
    v0107 = stack[-1];
    v0107 = qcar(v0107);
    v0107 = qcar(v0107);
    v0206 = qcdr(v0107);
    v0107 = stack[0];
    v0107 = qcar(v0107);
    v0107 = qcar(v0107);
    v0107 = qcdr(v0107);
    v0107 = (Lisp_Object)lessp2(v0206, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    v0107 = v0107 ? lisp_true : nil;
    env = stack[-3];
    if (v0107 == nil) goto v0087;
    v0206 = qvalue(elt(env, 2)); /* reduction!-count */
    v0107 = stack[-2];
    v0107 = plus2(v0206, v0107);
    nil = C_nil;
    if (exception_pending()) goto v0139;
    env = stack[-3];
    qvalue(elt(env, 2)) = v0107; /* reduction!-count */
    v0107 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0107;
    v0107 = stack[-1];
    v0206 = v0107;
    v0107 = stack[0];
    stack[-1] = v0107;
    v0107 = v0206;
    stack[0] = v0107;
    goto v0087;

v0097:
    v0107 = qvalue(elt(env, 1)); /* t */
    goto v0102;

v0103:
    v0107 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* general!-monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v0107);
    }
/* error exit handlers */
v0139:
    popv(4);
    return nil;
}



/* Code for rl_atnum */

static Lisp_Object CC_rl_atnum(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_atnum");
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
    v0048 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_atnum!* */
    v0048 = ncons(v0048);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    {
        Lisp_Object v0076 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0076, v0048);
    }
/* error exit handlers */
v0049:
    popv(2);
    return nil;
}



/* Code for mk!+conjugate!+sq */

static Lisp_Object CC_mkLconjugateLsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+conjugate+sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* conjsq */
        return (*qfn1(fn))(qenv(fn), v0016);
    }
}



/* Code for repr_n */

static Lisp_Object CC_repr_n(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0129, v0098;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for repr_n");
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
    v0070 = v0098;
    v0070 = qcdr(v0070);
    v0070 = qcdr(v0070);
    v0070 = qcar(v0070);
    if (v0070 == nil) goto v0011;
    v0070 = v0098;
    v0070 = qcdr(v0070);
    v0070 = qcdr(v0070);
    v0070 = qcdr(v0070);
    v0070 = qcdr(v0070);
    v0129 = qcar(v0070);
    v0070 = (Lisp_Object)1; /* 0 */
    if (v0129 == v0070) goto v0049;
    v0070 = v0098;
    v0070 = qcdr(v0070);
    v0070 = qcdr(v0070);
    v0070 = qcar(v0070);
    v0070 = qcar(v0070);
    v0070 = qcar(v0070);
    { popv(1); return onevalue(v0070); }

v0049:
    v0070 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0070); }

v0011:
    v0070 = elt(env, 1); /* "repr_n : invalid REPR structure" */
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0070);
    }
/* error exit handlers */
v0066:
    popv(1);
    return nil;
}



/* Code for setrd */

static Lisp_Object MS_CDECL CC_setrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setrd");
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
    v0104 = elt(env, 1); /* (t y p e != s e t !$) */
    qvalue(elt(env, 2)) = v0104; /* atts */
    stack[0] = elt(env, 3); /* list */
    fn = elt(env, 4); /* stats_getargs */
    v0104 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    v0104 = cons(stack[0], v0104);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    v0152 = v0104;
    v0104 = v0152;
    stack[0] = qcar(v0104);
    v0104 = v0152;
    v0104 = qcdr(v0104);
    fn = elt(env, 5); /* norepeat */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    {
        Lisp_Object v0091 = stack[0];
        popv(2);
        return cons(v0091, v0104);
    }
/* error exit handlers */
v0090:
    popv(2);
    return nil;
}



/* Code for prlist */

static Lisp_Object CC_prlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0033;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prlist");
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
    v0033 = nil;
    goto v0005;

v0005:
    v0101 = stack[0];
    if (v0101 == nil) goto v0088;
    v0101 = stack[0];
    v0101 = qcar(v0101);
    v0101 = Lconsp(nil, v0101);
    env = stack[-1];
    if (v0101 == nil) goto v0091;
    v0101 = stack[0];
    v0101 = qcar(v0101);
    v0101 = cons(v0101, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-1];
    v0033 = v0101;
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    stack[0] = v0101;
    goto v0005;

v0091:
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    stack[0] = v0101;
    goto v0005;

v0088:
    v0101 = v0033;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0101);
    }
/* error exit handlers */
v0070:
    popv(2);
    return nil;
}



/* Code for amatch */

static Lisp_Object MS_CDECL CC_amatch(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0208, v0008, v0009, v0180;
    Lisp_Object fn;
    Lisp_Object v0005, v0011, v0012, v0053;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "amatch");
    va_start(aa, nargs);
    v0053 = va_arg(aa, Lisp_Object);
    v0012 = va_arg(aa, Lisp_Object);
    v0011 = va_arg(aa, Lisp_Object);
    v0005 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for amatch");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0005,v0011,v0012,v0053);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0053,v0012,v0011,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v0005;
    stack[-4] = v0011;
    v0008 = v0012;
    v0208 = v0053;
/* end of prologue */
    stack[-5] = qvalue(elt(env, 1)); /* r */
    qvalue(elt(env, 1)) = nil; /* r */
    stack[-2] = qvalue(elt(env, 2)); /* p */
    qvalue(elt(env, 2)) = nil; /* p */
    qvalue(elt(env, 1)) = v0208; /* r */
    v0208 = v0008;
    qvalue(elt(env, 2)) = v0208; /* p */
    goto v0153;

v0153:
    v0208 = qvalue(elt(env, 1)); /* r */
    if (!consp(v0208)) goto v0099;
    v0208 = qvalue(elt(env, 2)); /* p */
    if (!consp(v0208)) goto v0151;
    v0208 = qvalue(elt(env, 1)); /* r */
    v0008 = qcar(v0208);
    v0208 = qvalue(elt(env, 2)); /* p */
    v0208 = qcar(v0208);
    v0208 = Lneq(nil, v0008, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    goto v0161;

v0161:
    if (v0208 == nil) goto v0154;
    v0208 = qvalue(elt(env, 1)); /* r */
    fn = elt(env, 7); /* suchp */
    v0208 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    if (v0208 == nil) goto v0022;
    v0208 = qvalue(elt(env, 1)); /* r */
    v0208 = qcdr(v0208);
    v0208 = qcar(v0208);
    stack[0] = v0208;
    v0208 = qvalue(elt(env, 1)); /* r */
    v0208 = qcdr(v0208);
    v0208 = qcdr(v0208);
    v0008 = qcar(v0208);
    v0208 = stack[-4];
    v0208 = cons(v0008, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    stack[-4] = v0208;
    v0208 = stack[0];
    qvalue(elt(env, 1)) = v0208; /* r */
    goto v0153;

v0022:
    v0208 = qvalue(elt(env, 5)); /* !*semantic */
    if (v0208 == nil) goto v0200;
    v0009 = elt(env, 6); /* equal */
    v0008 = qvalue(elt(env, 1)); /* r */
    v0208 = qvalue(elt(env, 2)); /* p */
    v0008 = list3(v0009, v0008, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    v0208 = stack[-4];
    v0008 = cons(v0008, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    v0208 = stack[-3];
    fn = elt(env, 8); /* resume */
    v0208 = (*qfn2(fn))(qenv(fn), v0008, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    goto v0047;

v0047:
    qvalue(elt(env, 2)) = stack[-2]; /* p */
    qvalue(elt(env, 1)) = stack[-5]; /* r */
    { popv(7); return onevalue(v0208); }

v0200:
    v0208 = qvalue(elt(env, 3)); /* nil */
    goto v0047;

v0154:
    v0208 = qvalue(elt(env, 1)); /* r */
    stack[0] = qcar(v0208);
    v0208 = qvalue(elt(env, 1)); /* r */
    v0208 = qcdr(v0208);
    fn = elt(env, 9); /* mval */
    v0180 = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    v0208 = qvalue(elt(env, 2)); /* p */
    v0009 = qcdr(v0208);
    v0008 = stack[-4];
    v0208 = stack[-3];
    fn = elt(env, 10); /* unify */
    v0208 = (*qfnn(fn))(qenv(fn), 5, stack[0], v0180, v0009, v0008, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    goto v0047;

v0151:
    v0208 = qvalue(elt(env, 4)); /* t */
    goto v0161;

v0099:
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    v0208 = qvalue(elt(env, 1)); /* r */
    v0208 = ncons(v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    fn = elt(env, 9); /* mval */
    stack[0] = (*qfn1(fn))(qenv(fn), v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    v0208 = qvalue(elt(env, 2)); /* p */
    v0009 = ncons(v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    v0008 = stack[-4];
    v0208 = stack[-3];
    fn = elt(env, 10); /* unify */
    v0208 = (*qfnn(fn))(qenv(fn), 5, stack[-1], stack[0], v0009, v0008, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-6];
    goto v0047;
/* error exit handlers */
v0085:
    env = stack[-6];
    qvalue(elt(env, 2)) = stack[-2]; /* p */
    qvalue(elt(env, 1)) = stack[-5]; /* r */
    popv(7);
    return nil;
}



/* Code for evaluate */

static Lisp_Object MS_CDECL CC_evaluate(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0042, v0155;
    Lisp_Object fn;
    Lisp_Object v0053, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0053 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluate");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v0042 = v0053;
    v0155 = v0001;
    stack[-5] = v0000;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* !*evaluateerror */
    qvalue(elt(env, 1)) = nil; /* !*evaluateerror */
    v0089 = qvalue(elt(env, 2)); /* !*protfg */
    v0089 = (v0089 == nil ? lisp_true : nil);
    stack[-3] = v0089;
    v0089 = v0155;
    fn = elt(env, 8); /* pair */
    v0089 = (*qfn2(fn))(qenv(fn), v0089, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-7];
    stack[-6] = v0089;
    v0042 = qvalue(elt(env, 3)); /* nil */
    v0089 = qvalue(elt(env, 4)); /* t */
    stack[-2] = qvalue(elt(env, 5)); /* !*msg */
    qvalue(elt(env, 5)) = v0042; /* !*msg */
    stack[-1] = qvalue(elt(env, 2)); /* !*protfg */
    qvalue(elt(env, 2)) = v0089; /* !*protfg */
    stack[0] = elt(env, 6); /* evaluate0 */
    v0089 = stack[-5];
    stack[-5] = Lmkquote(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    v0089 = stack[-6];
    v0089 = Lmkquote(nil, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    v0155 = list3(stack[0], stack[-5], v0089);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    v0042 = stack[-3];
    v0089 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 9); /* errorset */
    v0089 = (*qfnn(fn))(qenv(fn), 3, v0155, v0042, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-7];
    stack[0] = v0089;
    qvalue(elt(env, 2)) = stack[-1]; /* !*protfg */
    qvalue(elt(env, 5)) = stack[-2]; /* !*msg */
    v0089 = stack[0];
    fn = elt(env, 10); /* errorp */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-7];
    if (v0089 == nil) goto v0068;
    v0089 = elt(env, 7); /* "error during function evaluation (e.g. singularity)" 
*/
    fn = elt(env, 11); /* rederr */
    v0089 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-7];
    goto v0068;

v0068:
    v0089 = stack[0];
    v0089 = qcar(v0089);
    qvalue(elt(env, 1)) = stack[-4]; /* !*evaluateerror */
    { popv(8); return onevalue(v0089); }
/* error exit handlers */
v0096:
    env = stack[-7];
    qvalue(elt(env, 2)) = stack[-1]; /* !*protfg */
    qvalue(elt(env, 5)) = stack[-2]; /* !*msg */
    qvalue(elt(env, 1)) = stack[-4]; /* !*evaluateerror */
    popv(8);
    return nil;
v0095:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-4]; /* !*evaluateerror */
    popv(8);
    return nil;
}



/* Code for contr!-strand */

static Lisp_Object CC_contrKstrand(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for contr-strand");
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
    v0104 = v0000;
/* end of prologue */

v0005:
    v0152 = stack[0];
    if (v0152 == nil) { popv(2); return onevalue(v0104); }
    v0152 = v0104;
    v0104 = stack[0];
    v0104 = qcar(v0104);
    fn = elt(env, 1); /* contr1!-strand */
    v0104 = (*qfn2(fn))(qenv(fn), v0152, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-1];
    v0152 = stack[0];
    v0152 = qcdr(v0152);
    stack[0] = v0152;
    goto v0005;
/* error exit handlers */
v0090:
    popv(2);
    return nil;
}



/* Code for nzero */

static Lisp_Object CC_nzero(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nzero");
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
    goto v0047;

v0047:
    v0100 = stack[0];
    v0097 = (Lisp_Object)1; /* 0 */
    if (v0100 == v0097) goto v0088;
    v0100 = (Lisp_Object)1; /* 0 */
    v0097 = stack[-1];
    v0097 = cons(v0100, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    stack[-1] = v0097;
    v0097 = stack[0];
    v0097 = sub1(v0097);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    stack[0] = v0097;
    goto v0047;

v0088:
    v0097 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0097);
    }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for remchkf */

static Lisp_Object MS_CDECL CC_remchkf(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0108, v0081;
    Lisp_Object fn;
    Lisp_Object v0053, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "remchkf");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0053 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remchkf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0053;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0108 = stack[-2];
    v0096 = stack[-1];
    fn = elt(env, 2); /* remchkf1 */
    v0096 = (*qfn2(fn))(qenv(fn), v0108, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-4];
    stack[-3] = v0096;
    v0096 = stack[-3];
    if (!consp(v0096)) goto v0099;
    v0096 = stack[-3];
    v0096 = qcar(v0096);
    v0096 = (consp(v0096) ? nil : lisp_true);
    goto v0035;

v0035:
    if (v0096 == nil) goto v0070;
    v0096 = qvalue(elt(env, 1)); /* t */
    goto v0103;

v0103:
    if (!(v0096 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v0096 = stack[-3];
    stack[-2] = qcar(v0096);
    v0096 = stack[-3];
    v0081 = qcdr(v0096);
    v0108 = stack[-1];
    v0096 = stack[0];
    v0096 = CC_remchkf(env, 3, v0081, v0108, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    {
        Lisp_Object v0106 = stack[-2];
        popv(5);
        return cons(v0106, v0096);
    }

v0070:
    v0096 = stack[-2];
    fn = elt(env, 3); /* kernels */
    v0108 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-4];
    v0096 = stack[0];
    fn = elt(env, 4); /* intersection */
    v0096 = (*qfn2(fn))(qenv(fn), v0108, v0096);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-4];
    v0096 = (v0096 == nil ? lisp_true : nil);
    goto v0103;

v0099:
    v0096 = qvalue(elt(env, 1)); /* t */
    goto v0035;
/* error exit handlers */
v0105:
    popv(5);
    return nil;
}



/* Code for simp!-prop!-condense */

static Lisp_Object CC_simpKpropKcondense(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simp-prop-condense");
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
    stack[-2] = nil;
    v0105 = stack[-3];
    v0025 = elt(env, 1); /* lambda_n4e0tl_6 */
    fn = elt(env, 3); /* sort */
    v0025 = (*qfn2(fn))(qenv(fn), v0105, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    stack[-3] = v0025;
    goto v0153;

v0153:
    v0025 = stack[-3];
    if (v0025 == nil) goto v0093;
    v0025 = stack[-3];
    v0025 = qcar(v0025);
    stack[-4] = v0025;
    v0025 = stack[-3];
    v0025 = qcdr(v0025);
    stack[-3] = v0025;
    v0105 = stack[-4];
    v0025 = stack[-2];
    v0025 = cons(v0105, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    stack[-2] = v0025;
    v0025 = stack[-3];
    stack[-1] = v0025;
    goto v0098;

v0098:
    v0025 = stack[-1];
    if (v0025 == nil) goto v0153;
    v0025 = stack[-1];
    v0025 = qcar(v0025);
    stack[0] = v0025;
    v0105 = stack[-4];
    v0025 = stack[0];
    fn = elt(env, 4); /* subsetp */
    v0025 = (*qfn2(fn))(qenv(fn), v0105, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    if (v0025 == nil) goto v0137;
    v0105 = stack[0];
    v0025 = stack[-3];
    v0025 = Ldelete(nil, v0105, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-5];
    stack[-3] = v0025;
    goto v0137;

v0137:
    v0025 = stack[-1];
    v0025 = qcdr(v0025);
    stack[-1] = v0025;
    goto v0098;

v0093:
    v0025 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* ordn */
        return (*qfn1(fn))(qenv(fn), v0025);
    }
/* error exit handlers */
v0206:
    popv(6);
    return nil;
}



/* Code for lambda_n4e0tl_6 */

static Lisp_Object CC_lambda_n4e0tl_6(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lambda_n4e0tl_6");
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
    v0049 = v0000;
/* end of prologue */
    stack[-1] = Llength(nil, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[-2];
    v0049 = stack[0];
    v0049 = Llength(nil, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    {
        Lisp_Object v0094 = stack[-1];
        popv(3);
        return Llessp(nil, v0094, v0049);
    }
/* error exit handlers */
v0153:
    popv(3);
    return nil;
}



/* Code for skp_ordp */

static Lisp_Object CC_skp_ordp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0153, v0094, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for skp_ordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0153 = v0001;
    v0094 = v0000;
/* end of prologue */
    v0103 = qcar(v0094);
    v0094 = qcar(v0153);
    v0153 = elt(env, 1); /* atom_compare */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v0103, v0094, v0153);
    }
}



/* Code for sfto_int2sf */

static Lisp_Object CC_sfto_int2sf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0093, v0153;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_int2sf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0093 = v0000;
/* end of prologue */
    v0153 = v0093;
    v0076 = (Lisp_Object)1; /* 0 */
    if (!(v0153 == v0076)) return onevalue(v0093);
    v0076 = nil;
    return onevalue(v0076);
}



/* Code for ofsf_ir2atl */

static Lisp_Object MS_CDECL CC_ofsf_ir2atl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0140, v0043;
    Lisp_Object fn;
    Lisp_Object v0053, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_ir2atl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0053 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_ir2atl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v0053;
    stack[0] = v0001;
    stack[-5] = v0000;
/* end of prologue */
    v0059 = stack[0];
    v0140 = qcar(v0059);
    v0059 = (Lisp_Object)17; /* 1 */
    v0059 = cons(v0140, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-7];
    stack[-6] = v0059;
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[-3] = v0059;
    goto v0072;

v0072:
    v0059 = stack[-3];
    if (v0059 == nil) goto v0104;
    v0059 = stack[-3];
    v0059 = qcar(v0059);
    v0140 = v0059;
    v0059 = v0140;
    v0043 = qcar(v0059);
    v0059 = stack[-4];
    if (equal(v0043, v0059)) goto v0151;
    v0059 = nil;
    goto v0101;

v0101:
    stack[-2] = v0059;
    v0059 = stack[-2];
    fn = elt(env, 2); /* lastpair */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-7];
    stack[-1] = v0059;
    v0059 = stack[-3];
    v0059 = qcdr(v0059);
    stack[-3] = v0059;
    v0059 = stack[-1];
    if (!consp(v0059)) goto v0072;
    else goto v0071;

v0071:
    v0059 = stack[-3];
    if (v0059 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    stack[0] = stack[-1];
    v0059 = stack[-3];
    v0059 = qcar(v0059);
    v0140 = v0059;
    v0059 = v0140;
    v0043 = qcar(v0059);
    v0059 = stack[-4];
    if (equal(v0043, v0059)) goto v0157;
    v0059 = nil;
    goto v0106;

v0106:
    v0059 = Lrplacd(nil, stack[0], v0059);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-7];
    v0059 = stack[-1];
    fn = elt(env, 2); /* lastpair */
    v0059 = (*qfn1(fn))(qenv(fn), v0059);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-7];
    stack[-1] = v0059;
    v0059 = stack[-3];
    v0059 = qcdr(v0059);
    stack[-3] = v0059;
    goto v0071;

v0157:
    v0043 = stack[-5];
    v0059 = v0140;
    v0140 = qcdr(v0059);
    v0059 = stack[-6];
    fn = elt(env, 3); /* ofsf_entry2at */
    v0059 = (*qfnn(fn))(qenv(fn), 3, v0043, v0140, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-7];
    v0059 = ncons(v0059);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-7];
    goto v0106;

v0151:
    v0043 = stack[-5];
    v0059 = v0140;
    v0140 = qcdr(v0059);
    v0059 = stack[-6];
    fn = elt(env, 3); /* ofsf_entry2at */
    v0059 = (*qfnn(fn))(qenv(fn), 3, v0043, v0140, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-7];
    v0059 = ncons(v0059);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-7];
    goto v0101;

v0104:
    v0059 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v0059); }
/* error exit handlers */
v0002:
    popv(8);
    return nil;
}



/* Code for mk!+outer!+list */

static Lisp_Object CC_mkLouterLlist(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0076;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+outer+list");
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
    v0049 = elt(env, 1); /* list */
    v0076 = ncons(v0049);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    v0049 = stack[0];
        popv(1);
        return Lappend(nil, v0076, v0049);
/* error exit handlers */
v0153:
    popv(1);
    return nil;
}



/* Code for freeof!-dfl */

static Lisp_Object CC_freeofKdfl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0070, v0129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeof-dfl");
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

v0163:
    v0070 = stack[-1];
    if (!consp(v0070)) goto v0005;
    v0070 = stack[-1];
    v0129 = qcar(v0070);
    v0070 = stack[0];
    fn = elt(env, 3); /* freeof!-df */
    v0070 = (*qfn2(fn))(qenv(fn), v0129, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0162;
    env = stack[-2];
    if (v0070 == nil) goto v0049;
    v0070 = stack[-1];
    v0129 = qcdr(v0070);
    v0070 = stack[0];
    stack[-1] = v0129;
    stack[0] = v0070;
    goto v0163;

v0049:
    v0070 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0070); }

v0005:
    v0070 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0070); }
/* error exit handlers */
v0162:
    popv(3);
    return nil;
}



/* Code for pasf_fact */

static Lisp_Object CC_pasf_fact(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0213, v0214, v0215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_fact");
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
    stack[-1] = v0000;
/* end of prologue */
    v0214 = stack[-1];
    v0213 = elt(env, 1); /* true */
    if (v0214 == v0213) goto v0049;
    v0214 = stack[-1];
    v0213 = elt(env, 3); /* false */
    v0213 = (v0214 == v0213 ? lisp_true : nil);
    goto v0040;

v0040:
    if (!(v0213 == nil)) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    v0213 = stack[-1];
    v0213 = qcar(v0213);
    stack[-5] = v0213;
    v0213 = stack[-1];
    v0213 = qcdr(v0213);
    v0213 = qcar(v0213);
    fn = elt(env, 10); /* fctrf */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    stack[0] = v0213;
    v0213 = stack[0];
    v0214 = Llength(nil, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    v0213 = (Lisp_Object)49; /* 3 */
    v0213 = (Lisp_Object)lessp2(v0214, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    v0213 = v0213 ? lisp_true : nil;
    env = stack[-6];
    if (!(v0213 == nil)) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    v0214 = stack[-5];
    v0213 = elt(env, 4); /* (equal neq) */
    v0213 = Lmemq(nil, v0214, v0213);
    if (v0213 == nil) goto v0191;
    v0214 = stack[-5];
    v0213 = elt(env, 5); /* equal */
    if (v0214 == v0213) goto v0025;
    v0213 = elt(env, 7); /* and */
    stack[-4] = v0213;
    goto v0108;

v0108:
    v0213 = stack[0];
    v0213 = qcdr(v0213);
    stack[-3] = v0213;
    v0213 = stack[-3];
    if (v0213 == nil) goto v0127;
    v0213 = stack[-3];
    v0213 = qcar(v0213);
    v0215 = stack[-5];
    v0214 = qcar(v0213);
    v0213 = qvalue(elt(env, 8)); /* nil */
    v0213 = list3(v0215, v0214, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    stack[-1] = v0213;
    stack[-2] = v0213;
    goto v0197;

v0197:
    v0213 = stack[-3];
    v0213 = qcdr(v0213);
    stack[-3] = v0213;
    v0213 = stack[-3];
    if (v0213 == nil) goto v0002;
    stack[0] = stack[-1];
    v0213 = stack[-3];
    v0213 = qcar(v0213);
    v0215 = stack[-5];
    v0214 = qcar(v0213);
    v0213 = qvalue(elt(env, 8)); /* nil */
    v0213 = list3(v0215, v0214, v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    v0213 = Lrplacd(nil, stack[0], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    v0213 = stack[-1];
    v0213 = qcdr(v0213);
    stack[-1] = v0213;
    goto v0197;

v0002:
    v0213 = stack[-2];
    goto v0081;

v0081:
    {
        Lisp_Object v0217 = stack[-4];
        popv(7);
        return cons(v0217, v0213);
    }

v0127:
    v0213 = qvalue(elt(env, 8)); /* nil */
    goto v0081;

v0025:
    v0213 = elt(env, 6); /* or */
    stack[-4] = v0213;
    goto v0108;

v0191:
    v0214 = stack[-5];
    v0213 = elt(env, 9); /* (leq lessp geq greaterp) */
    v0213 = Lmemq(nil, v0214, v0213);
    if (v0213 == nil) { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }
    v0213 = stack[0];
    stack[-1] = qcdr(v0213);
    v0213 = stack[0];
    v0213 = qcar(v0213);
    fn = elt(env, 11); /* minusf */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    if (v0213 == nil) goto v0176;
    v0213 = stack[-5];
    fn = elt(env, 12); /* pasf_anegrel */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-6];
    goto v0052;

v0052:
    {
        Lisp_Object v0218 = stack[-1];
        popv(7);
        fn = elt(env, 13); /* pasf_fact1 */
        return (*qfn2(fn))(qenv(fn), v0218, v0213);
    }

v0176:
    v0213 = stack[-5];
    goto v0052;

v0049:
    v0213 = qvalue(elt(env, 2)); /* t */
    goto v0040;
/* error exit handlers */
v0216:
    popv(7);
    return nil;
}



/* Code for ctx_new */

static Lisp_Object MS_CDECL CC_ctx_new(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0047;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ctx_new");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ctx_new");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0087 = elt(env, 1); /* ctx */
    v0047 = qvalue(elt(env, 2)); /* nil */
    return list2(v0087, v0047);
}



/* Code for minusrd */

static Lisp_Object MS_CDECL CC_minusrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0152, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "minusrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minusrd");
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
    v0152 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    stack[0] = v0152;
    fn = elt(env, 1); /* mathml */
    v0152 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0092 = v0152;
    if (v0092 == nil) goto v0087;
    v0092 = stack[0];
    fn = elt(env, 2); /* alg_difference */
    v0152 = (*qfn2(fn))(qenv(fn), v0092, v0152);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    stack[0] = v0152;
    fn = elt(env, 3); /* lex */
    v0152 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v0087:
    v0152 = stack[0];
    fn = elt(env, 4); /* alg_minus */
    v0152 = (*qfn1(fn))(qenv(fn), v0152);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    stack[0] = v0152;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v0091:
    popv(2);
    return nil;
}



/* Code for ps!:prepfn!: */

static Lisp_Object CC_psTprepfnT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0012;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:prepfn:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0012 = v0000;
/* end of prologue */
    return onevalue(v0012);
}



/* Code for calc_den_tar */

static Lisp_Object CC_calc_den_tar(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0090, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for calc_den_tar");
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
    v0090 = v0001;
    v0091 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* denlist */
    v0090 = (*qfn2(fn))(qenv(fn), v0091, v0090);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[0];
    v0091 = v0090;
    v0090 = v0091;
    if (v0090 == nil) goto v0076;
    v0090 = v0091;
    v0090 = qcdr(v0090);
    if (v0090 == nil) goto v0103;
    v0090 = v0091;
    {
        popv(1);
        fn = elt(env, 2); /* constimes */
        return (*qfn1(fn))(qenv(fn), v0090);
    }

v0103:
    v0090 = v0091;
    v0090 = qcar(v0090);
    { popv(1); return onevalue(v0090); }

v0076:
    v0090 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v0090); }
/* error exit handlers */
v0102:
    popv(1);
    return nil;
}



/* Code for sf2mv */

static Lisp_Object CC_sf2mv(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0093, v0153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sf2mv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0076 = v0001;
    v0093 = v0000;
/* end of prologue */
    v0153 = v0093;
    v0093 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* sf2mv1 */
        return (*qfnn(fn))(qenv(fn), 3, v0153, v0093, v0076);
    }
}



/* Code for getavalue */

static Lisp_Object CC_getavalue(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0153, v0094;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getavalue");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0153 = v0000;
/* end of prologue */
    if (!symbolp(v0153)) v0153 = nil;
    else { v0153 = qfastgets(v0153);
           if (v0153 != nil) { v0153 = elt(v0153, 4); /* avalue */
#ifdef RECORD_GET
             if (v0153 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v0153 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v0153 == SPID_NOPROP) v0153 = nil; }}
#endif
    v0094 = v0153;
    v0153 = v0094;
    if (v0153 == nil) goto v0049;
    v0153 = v0094;
    v0153 = qcdr(v0153);
    v0153 = qcar(v0153);
    return onevalue(v0153);

v0049:
    v0153 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0153);
}



/* Code for domainvalchk */

static Lisp_Object CC_domainvalchk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0081, v0114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for domainvalchk");
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
    v0081 = qvalue(elt(env, 1)); /* dmode!* */
    v0108 = elt(env, 0); /* domainvalchk */
    v0108 = get(v0081, v0108);
    env = stack[-3];
    stack[-2] = v0108;
    if (v0108 == nil) goto v0088;
    v0114 = stack[-2];
    v0081 = stack[-1];
    v0108 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v0114, v0081, v0108);

v0088:
    v0108 = stack[0];
    v0108 = Lreverse(nil, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-3];
    stack[0] = v0108;
    goto v0016;

v0016:
    v0108 = stack[0];
    if (v0108 == nil) goto v0098;
    v0108 = stack[0];
    v0108 = qcar(v0108);
    v0081 = qcdr(v0108);
    v0108 = (Lisp_Object)17; /* 1 */
    if (v0081 == v0108) goto v0042;
    v0108 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0108); }

v0042:
    v0108 = stack[0];
    v0108 = qcar(v0108);
    fn = elt(env, 3); /* mk!*sq */
    v0081 = (*qfn1(fn))(qenv(fn), v0108);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-3];
    v0108 = stack[-2];
    v0108 = cons(v0081, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-3];
    stack[-2] = v0108;
    v0108 = stack[0];
    v0108 = qcdr(v0108);
    stack[0] = v0108;
    goto v0016;

v0098:
    v0081 = stack[-1];
    v0108 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* valuechk */
        return (*qfn2(fn))(qenv(fn), v0081, v0108);
    }
/* error exit handlers */
v0105:
    popv(4);
    return nil;
}



/* Code for omattrir */

static Lisp_Object MS_CDECL CC_omattrir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0114, v0026;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omattrir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omattrir");
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
    fn = elt(env, 6); /* lex */
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    fn = elt(env, 7); /* omatpir */
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    stack[-1] = v0081;
    fn = elt(env, 6); /* lex */
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    fn = elt(env, 8); /* omobj */
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    stack[0] = v0081;
    fn = elt(env, 6); /* lex */
    v0081 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    v0081 = elt(env, 1); /* (!/ o m a t t r) */
    fn = elt(env, 9); /* checktag */
    v0081 = (*qfn1(fn))(qenv(fn), v0081);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    v0081 = stack[-1];
    v0081 = Lconsp(nil, v0081);
    env = stack[-2];
    if (v0081 == nil) goto v0049;
    v0081 = stack[-1];
    v0081 = qcar(v0081);
    v0081 = qcdr(v0081);
    v0114 = qcar(v0081);
    v0081 = elt(env, 2); /* csymbol */
    if (!(v0114 == v0081)) goto v0049;
    v0114 = stack[0];
    v0081 = qvalue(elt(env, 3)); /* nil */
    v0026 = qvalue(elt(env, 3)); /* nil */
    popv(3);
    return list2star(v0114, v0081, v0026);

v0049:
    v0081 = stack[0];
    if (is_number(v0081)) goto v0069;
    v0026 = elt(env, 5); /* ci */
    v0114 = stack[-1];
    v0081 = stack[0];
    popv(3);
    return list3(v0026, v0114, v0081);

v0069:
    v0026 = elt(env, 4); /* cn */
    v0114 = stack[-1];
    v0081 = stack[0];
    popv(3);
    return list3(v0026, v0114, v0081);
/* error exit handlers */
v0105:
    popv(3);
    return nil;
}



/* Code for cr!:prep */

static Lisp_Object CC_crTprep(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cr:prep");
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
    v0100 = elt(env, 1); /* !:rd!: */
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    v0097 = qcar(v0097);
    v0097 = cons(v0100, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    v0100 = elt(env, 1); /* !:rd!: */
    v0097 = stack[0];
    v0097 = qcdr(v0097);
    v0097 = qcdr(v0097);
    v0097 = cons(v0100, v0097);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    v0097 = (*qfn1(fn))(qenv(fn), v0097);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    v0097 = cons(stack[-1], v0097);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* crprep1 */
        return (*qfn1(fn))(qenv(fn), v0097);
    }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for nonlnr */

static Lisp_Object CC_nonlnr(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0054, v0194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nonlnr");
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

v0163:
    v0054 = stack[-1];
    if (!consp(v0054)) goto v0087;
    v0054 = stack[-1];
    v0054 = qcar(v0054);
    v0054 = (consp(v0054) ? nil : lisp_true);
    goto v0088;

v0088:
    if (v0054 == nil) goto v0034;
    v0054 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0054); }

v0034:
    v0054 = stack[-1];
    v0054 = qcar(v0054);
    v0054 = qcar(v0054);
    v0194 = qcar(v0054);
    v0054 = stack[0];
    v0054 = Lmember(nil, v0194, v0054);
    if (v0054 == nil) goto v0064;
    v0054 = stack[-1];
    v0054 = qcar(v0054);
    v0054 = qcar(v0054);
    v0194 = qcdr(v0054);
    v0054 = (Lisp_Object)17; /* 1 */
    v0054 = (Lisp_Object)greaterp2(v0194, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    v0054 = v0054 ? lisp_true : nil;
    env = stack[-2];
    if (!(v0054 == nil)) { popv(3); return onevalue(v0054); }
    v0054 = stack[-1];
    v0054 = qcar(v0054);
    v0194 = qcdr(v0054);
    v0054 = stack[0];
    fn = elt(env, 3); /* freeofl */
    v0054 = (*qfn2(fn))(qenv(fn), v0194, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    if (v0054 == nil) goto v0068;
    v0054 = stack[-1];
    v0194 = qcdr(v0054);
    v0054 = stack[0];
    stack[-1] = v0194;
    stack[0] = v0054;
    goto v0163;

v0068:
    v0054 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0054); }

v0064:
    v0054 = stack[-1];
    v0054 = qcar(v0054);
    v0054 = qcar(v0054);
    v0194 = qcar(v0054);
    v0054 = stack[0];
    fn = elt(env, 3); /* freeofl */
    v0054 = (*qfn2(fn))(qenv(fn), v0194, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    if (v0054 == nil) goto v0106;
    v0054 = stack[-1];
    v0054 = qcar(v0054);
    v0194 = qcdr(v0054);
    v0054 = stack[0];
    v0054 = CC_nonlnr(env, v0194, v0054);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    if (!(v0054 == nil)) { popv(3); return onevalue(v0054); }
    v0054 = stack[-1];
    v0194 = qcdr(v0054);
    v0054 = stack[0];
    stack[-1] = v0194;
    stack[0] = v0054;
    goto v0163;

v0106:
    v0054 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0054); }

v0087:
    v0054 = qvalue(elt(env, 1)); /* t */
    goto v0088;
/* error exit handlers */
v0057:
    popv(3);
    return nil;
}



/* Code for giintgcd */

static Lisp_Object CC_giintgcd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0064, v0107, v0206;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for giintgcd");
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
    v0064 = v0001;
    v0107 = v0000;
/* end of prologue */

v0048:
    v0206 = v0064;
    v0063 = (Lisp_Object)17; /* 1 */
    if (v0206 == v0063) goto v0087;
    v0063 = v0107;
    if (v0063 == nil) { popv(2); return onevalue(v0064); }
    v0063 = v0107;
    if (!consp(v0063)) goto v0092;
    v0206 = v0107;
    v0063 = elt(env, 1); /* !:gi!: */
    if (!consp(v0206)) goto v0154;
    v0206 = qcar(v0206);
    if (!(v0206 == v0063)) goto v0154;
    v0063 = v0107;
    v0063 = qcdr(v0063);
    stack[0] = qcar(v0063);
    v0063 = v0107;
    v0063 = qcdr(v0063);
    v0063 = qcdr(v0063);
    v0063 = Lgcd(nil, v0063, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    {
        Lisp_Object v0022 = stack[0];
        popv(2);
        return Lgcd(nil, v0022, v0063);
    }

v0154:
    v0063 = v0107;
    v0063 = qcar(v0063);
    v0063 = qcdr(v0063);
    stack[0] = v0063;
    v0063 = v0107;
    v0063 = qcdr(v0063);
    v0063 = CC_giintgcd(env, v0063, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-1];
    v0064 = v0063;
    v0063 = stack[0];
    v0107 = v0063;
    goto v0048;

v0092:
    v0063 = v0107;
        popv(2);
        return Lgcd(nil, v0063, v0064);

v0087:
    v0063 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0063); }
/* error exit handlers */
v0021:
    popv(2);
    return nil;
}



setup_type const u31_setup[] =
{
    {"difference:",             too_few_2,      CC_differenceT,wrong_no_2},
    {"ev-denom2",               too_few_2,      CC_evKdenom2,  wrong_no_2},
    {"assert_procstat-argl",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_procstatKargl},
    {"harmonicp",               CC_harmonicp,   too_many_1,    wrong_no_1},
    {"outer-simpsqrt",          CC_outerKsimpsqrt,too_many_1,  wrong_no_1},
    {"listeval0",               CC_listeval0,   too_many_1,    wrong_no_1},
    {"bvarom",                  CC_bvarom,      too_many_1,    wrong_no_1},
    {"multerm",                 too_few_2,      CC_multerm,    wrong_no_2},
    {"redcodmat",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_redcodmat},
    {"unify",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_unify},
    {"mkbc",                    too_few_2,      CC_mkbc,       wrong_no_2},
    {"gfplus",                  too_few_2,      CC_gfplus,     wrong_no_2},
    {"collectphysops_reversed", too_few_2,      CC_collectphysops_reversed,wrong_no_2},
    {"mk-numr",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkKnumr},
    {"ofsf_evalatp",            too_few_2,      CC_ofsf_evalatp,wrong_no_2},
    {"rtypepart",               CC_rtypepart,   too_many_1,    wrong_no_1},
    {"evalnumberp",             CC_evalnumberp, too_many_1,    wrong_no_1},
    {"qqe_ofsf_varlat",         CC_qqe_ofsf_varlat,too_many_1, wrong_no_1},
    {"pasf_smordtable1",        too_few_2,      CC_pasf_smordtable1,wrong_no_2},
    {"ciml",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_ciml},
    {"contposp",                CC_contposp,    too_many_1,    wrong_no_1},
    {"fl2bf",                   CC_fl2bf,       too_many_1,    wrong_no_1},
    {"mkfortterpri",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkfortterpri},
    {"log_freevars",            too_few_2,      CC_log_freevars,wrong_no_2},
    {"clean_numid",             CC_clean_numid, too_many_1,    wrong_no_1},
    {"assoc2",                  too_few_2,      CC_assoc2,     wrong_no_2},
    {"reduce-mod-eigf",         too_few_2,      CC_reduceKmodKeigf,wrong_no_2},
    {"mk+squared+norm",         CC_mkLsquaredLnorm,too_many_1, wrong_no_1},
    {"cl_susicpknowl",          CC_cl_susicpknowl,too_many_1,  wrong_no_1},
    {"make-modular-symmetric",  CC_makeKmodularKsymmetric,too_many_1,wrong_no_1},
    {"setfuncsnaryrd",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_setfuncsnaryrd},
    {"delyzz",                  too_few_2,      CC_delyzz,     wrong_no_2},
    {"suchp",                   CC_suchp,       too_many_1,    wrong_no_1},
    {"sc_subtrsq",              too_few_2,      CC_sc_subtrsq, wrong_no_2},
    {"lessppair",               too_few_2,      CC_lessppair,  wrong_no_2},
    {"ratdif",                  too_few_2,      CC_ratdif,     wrong_no_2},
    {"cl_atl1",                 CC_cl_atl1,     too_many_1,    wrong_no_1},
    {"cl_smsimpl-junct",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct},
    {"depend-f",                too_few_2,      CC_dependKf,   wrong_no_2},
    {"critical_element",        CC_critical_element,too_many_1,wrong_no_1},
    {"mktails",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktails},
    {"remchkf1",                too_few_2,      CC_remchkf1,   wrong_no_2},
    {"simp-prop2",              CC_simpKprop2,  too_many_1,    wrong_no_1},
    {"fd2q",                    CC_fd2q,        too_many_1,    wrong_no_1},
    {"general-ordered-gcd-mod-p",too_few_2,     CC_generalKorderedKgcdKmodKp,wrong_no_2},
    {"rl_atnum",                CC_rl_atnum,    too_many_1,    wrong_no_1},
    {"mk+conjugate+sq",         CC_mkLconjugateLsq,too_many_1, wrong_no_1},
    {"repr_n",                  CC_repr_n,      too_many_1,    wrong_no_1},
    {"setrd",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_setrd},
    {"prlist",                  CC_prlist,      too_many_1,    wrong_no_1},
    {"amatch",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_amatch},
    {"evaluate",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluate},
    {"contr-strand",            too_few_2,      CC_contrKstrand,wrong_no_2},
    {"nzero",                   CC_nzero,       too_many_1,    wrong_no_1},
    {"remchkf",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_remchkf},
    {"simp-prop-condense",      CC_simpKpropKcondense,too_many_1,wrong_no_1},
    {"lambda_n4e0tl_6",         too_few_2,      CC_lambda_n4e0tl_6,wrong_no_2},
    {"skp_ordp",                too_few_2,      CC_skp_ordp,   wrong_no_2},
    {"sfto_int2sf",             CC_sfto_int2sf, too_many_1,    wrong_no_1},
    {"ofsf_ir2atl",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_ir2atl},
    {"mk+outer+list",           CC_mkLouterLlist,too_many_1,   wrong_no_1},
    {"freeof-dfl",              too_few_2,      CC_freeofKdfl, wrong_no_2},
    {"pasf_fact",               CC_pasf_fact,   too_many_1,    wrong_no_1},
    {"ctx_new",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_ctx_new},
    {"minusrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_minusrd},
    {"ps:prepfn:",              CC_psTprepfnT,  too_many_1,    wrong_no_1},
    {"calc_den_tar",            too_few_2,      CC_calc_den_tar,wrong_no_2},
    {"sf2mv",                   too_few_2,      CC_sf2mv,      wrong_no_2},
    {"getavalue",               CC_getavalue,   too_many_1,    wrong_no_1},
    {"domainvalchk",            too_few_2,      CC_domainvalchk,wrong_no_2},
    {"omattrir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_omattrir},
    {"cr:prep",                 CC_crTprep,     too_many_1,    wrong_no_1},
    {"nonlnr",                  too_few_2,      CC_nonlnr,     wrong_no_2},
    {"giintgcd",                too_few_2,      CC_giintgcd,   wrong_no_2},
    {NULL, (one_args *)"u31", (two_args *)"21561 8263772 4476267", 0}
};

/* end of generated code */
