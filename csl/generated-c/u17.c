
/* $destdir\u17.c        Machine generated C code */

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


/* Code for pappend */

static Lisp_Object CC_pappend(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappend");
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
    stack[0] = v0001;
    stack[-4] = v0000;
/* end of prologue */
    v0017 = stack[-4];
    fn = elt(env, 2); /* unpkp */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    stack[-4] = v0017;
    v0017 = stack[-4];
    v0017 = Llength(nil, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    stack[-5] = v0017;
    v0017 = stack[0];
    fn = elt(env, 2); /* unpkp */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    stack[0] = v0017;
    v0017 = stack[0];
    stack[-3] = v0017;
    v0017 = stack[-3];
    if (v0017 == nil) goto v0020;
    v0017 = stack[-3];
    v0017 = qcar(v0017);
    v0018 = v0017;
    v0017 = stack[-5];
    v0017 = plus2(v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    v0017 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    stack[-1] = v0017;
    stack[-2] = v0017;
    goto v0021;

v0021:
    v0017 = stack[-3];
    v0017 = qcdr(v0017);
    stack[-3] = v0017;
    v0017 = stack[-3];
    if (v0017 == nil) goto v0022;
    stack[0] = stack[-1];
    v0017 = stack[-3];
    v0017 = qcar(v0017);
    v0018 = v0017;
    v0017 = stack[-5];
    v0017 = plus2(v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    v0017 = ncons(v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    v0017 = Lrplacd(nil, stack[0], v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    v0017 = stack[-1];
    v0017 = qcdr(v0017);
    stack[-1] = v0017;
    goto v0021;

v0022:
    v0017 = stack[-2];
    goto v0023;

v0023:
    stack[0] = v0017;
    v0018 = stack[-4];
    v0017 = stack[0];
    v0017 = Lappend(nil, v0018, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0019;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 3); /* pkp */
        return (*qfn1(fn))(qenv(fn), v0017);
    }

v0020:
    v0017 = qvalue(elt(env, 1)); /* nil */
    goto v0023;
/* error exit handlers */
v0019:
    popv(7);
    return nil;
}



/* Code for ratn */

static Lisp_Object CC_ratn(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006, v0030;
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
    v0030 = v0000;
/* end of prologue */
    v0005 = v0030;
    if (v0005 == nil) goto v0031;
    v0005 = v0030;
    if (!consp(v0005)) goto v0032;
    v0005 = v0030;
    v0006 = qcar(v0005);
    v0005 = elt(env, 1); /* !:rn!: */
    if (v0006 == v0005) goto v0033;
    v0030 = elt(env, 2); /* arnum */
    v0006 = (Lisp_Object)97; /* 6 */
    v0005 = elt(env, 3); /* "Illegal domain in :ar:" */
    {
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0030, v0006, v0005);
    }

v0033:
    v0005 = v0030;
    v0005 = qcdr(v0005);
    return onevalue(v0005);

v0032:
    v0006 = v0030;
    v0005 = (Lisp_Object)17; /* 1 */
    return cons(v0006, v0005);

v0031:
    v0006 = (Lisp_Object)1; /* 0 */
    v0005 = (Lisp_Object)17; /* 1 */
    return cons(v0006, v0005);
}



/* Code for ra_budan!-0!-1 */

static Lisp_Object CC_ra_budanK0K1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ra_budan-0-1");
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
    v0042 = v0000;
/* end of prologue */
    v0041 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0041;
    v0041 = (Lisp_Object)1; /* 0 */
    stack[0] = v0041;
    v0041 = v0042;
    fn = elt(env, 3); /* ra_budan!-transform */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    stack[-3] = v0041;
    goto v0023;

v0023:
    v0041 = stack[-3];
    if (v0041 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0041 = stack[-3];
    if (!consp(v0041)) goto v0044;
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = (consp(v0041) ? nil : lisp_true);
    goto v0016;

v0016:
    if (v0041 == nil) goto v0045;
    v0041 = stack[-3];
    v0042 = v0041;
    v0041 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0041;
    goto v0029;

v0029:
    v0041 = v0042;
    fn = elt(env, 4); /* minusf */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    if (v0041 == nil) goto v0046;
    v0041 = (Lisp_Object)-15; /* -1 */
    goto v0024;

v0024:
    stack[-2] = v0041;
    v0042 = stack[-2];
    v0041 = stack[-1];
    v0042 = times2(v0042, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    v0041 = (Lisp_Object)1; /* 0 */
    v0041 = (Lisp_Object)lessp2(v0042, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    v0041 = v0041 ? lisp_true : nil;
    env = stack[-4];
    if (v0041 == nil) goto v0047;
    v0041 = stack[0];
    v0041 = add1(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-4];
    stack[0] = v0041;
    goto v0047;

v0047:
    v0041 = stack[-2];
    stack[-1] = v0041;
    goto v0023;

v0046:
    v0041 = (Lisp_Object)17; /* 1 */
    goto v0024;

v0045:
    v0041 = stack[-3];
    v0041 = qcar(v0041);
    v0041 = qcdr(v0041);
    v0042 = v0041;
    v0041 = stack[-3];
    v0041 = qcdr(v0041);
    stack[-3] = v0041;
    goto v0029;

v0044:
    v0041 = qvalue(elt(env, 2)); /* t */
    goto v0016;
/* error exit handlers */
v0043:
    popv(5);
    return nil;
}



/* Code for resetparser */

static Lisp_Object MS_CDECL CC_resetparser(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "resetparser");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resetparser");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0031 = qvalue(elt(env, 1)); /* !*slin */
    if (v0031 == nil) goto v0009;
    v0031 = nil;
    return onevalue(v0031);

v0009:
    v0031 = qvalue(elt(env, 2)); /* t */
    {
        fn = elt(env, 3); /* comm1 */
        return (*qfn1(fn))(qenv(fn), v0031);
    }
}



/* Code for cl_fvarl1 */

static Lisp_Object CC_cl_fvarl1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_fvarl1");
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
    v0036 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* cl_varl1 */
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    errexit();
    v0036 = qcar(v0036);
    return onevalue(v0036);
}



/* Code for powers3 */

static Lisp_Object CC_powers3(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0051;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers3");
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
    v0050 = v0000;
/* end of prologue */

v0034:
    v0051 = v0050;
    if (!consp(v0051)) goto v0013;
    v0051 = v0050;
    v0051 = qcar(v0051);
    v0051 = (consp(v0051) ? nil : lisp_true);
    goto v0011;

v0011:
    if (!(v0051 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0051 = v0050;
    v0051 = qcar(v0051);
    v0051 = qcdr(v0051);
    stack[-2] = v0051;
    v0051 = v0050;
    v0051 = qcar(v0051);
    v0051 = qcar(v0051);
    stack[0] = qcar(v0051);
    v0051 = v0050;
    v0051 = qcar(v0051);
    v0051 = qcar(v0051);
    v0051 = qcdr(v0051);
    v0050 = qcar(v0050);
    v0050 = qcar(v0050);
    v0050 = qcdr(v0050);
    v0051 = cons(v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-3];
    v0050 = stack[-1];
    v0050 = acons(stack[0], v0051, v0050);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-3];
    stack[-1] = v0050;
    v0050 = stack[-2];
    goto v0034;

v0013:
    v0051 = qvalue(elt(env, 1)); /* t */
    goto v0011;
/* error exit handlers */
v0052:
    popv(4);
    return nil;
}



/* Code for expnd1 */

static Lisp_Object CC_expnd1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0062, v0063;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expnd1");
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
    goto v0034;

v0034:
    v0062 = stack[-1];
    if (!consp(v0062)) goto v0004;
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = (consp(v0062) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0062 == nil) goto v0028;
    v0062 = stack[-1];
    v0063 = v0062;
    goto v0031;

v0031:
    v0062 = stack[-2];
    if (v0062 == nil) { popv(4); return onevalue(v0063); }
    v0062 = stack[-2];
    v0062 = qcar(v0062);
    fn = elt(env, 2); /* addf */
    v0062 = (*qfn2(fn))(qenv(fn), v0062, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    v0063 = v0062;
    v0062 = stack[-2];
    v0062 = qcdr(v0062);
    stack[-2] = v0062;
    goto v0031;

v0028:
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    fn = elt(env, 3); /* sfp */
    v0062 = (*qfn1(fn))(qenv(fn), v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    if (v0062 == nil) goto v0015;
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    v0063 = qcdr(v0062);
    v0062 = (Lisp_Object)1; /* 0 */
    v0062 = (Lisp_Object)lessp2(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    v0062 = v0062 ? lisp_true : nil;
    env = stack[-3];
    goto v0014;

v0014:
    if (v0062 == nil) goto v0043;
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0063 = qcar(v0062);
    v0062 = (Lisp_Object)17; /* 1 */
    v0062 = cons(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    stack[0] = ncons(v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = qcdr(v0062);
    v0062 = CC_expnd1(env, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    fn = elt(env, 4); /* multf */
    v0062 = (*qfn2(fn))(qenv(fn), stack[0], v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    v0063 = v0062;
    goto v0040;

v0040:
    v0062 = stack[-2];
    v0062 = cons(v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    stack[-2] = v0062;
    v0062 = stack[-1];
    v0062 = qcdr(v0062);
    stack[-1] = v0062;
    goto v0034;

v0043:
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    v0063 = CC_expnd1(env, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = qcar(v0062);
    v0062 = qcdr(v0062);
    fn = elt(env, 5); /* exptf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0063, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    v0062 = stack[-1];
    v0062 = qcar(v0062);
    v0062 = qcdr(v0062);
    v0062 = CC_expnd1(env, v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    fn = elt(env, 4); /* multf */
    v0062 = (*qfn2(fn))(qenv(fn), stack[0], v0062);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-3];
    v0063 = v0062;
    goto v0040;

v0015:
    v0062 = qvalue(elt(env, 1)); /* t */
    goto v0014;

v0004:
    v0062 = qvalue(elt(env, 1)); /* t */
    goto v0012;
/* error exit handlers */
v0064:
    popv(4);
    return nil;
}



/* Code for tobvarir */

static Lisp_Object CC_tobvarir(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0066;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tobvarir");
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
    v0055 = stack[-1];
    if (v0055 == nil) goto v0036;
    stack[-2] = elt(env, 1); /* bvar */
    v0055 = stack[-1];
    v0066 = qcar(v0055);
    v0055 = (Lisp_Object)17; /* 1 */
    stack[0] = list2(v0066, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-3];
    v0055 = stack[-1];
    v0055 = qcdr(v0055);
    v0055 = CC_tobvarir(env, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    {
        Lisp_Object v0015 = stack[-2];
        Lisp_Object v0067 = stack[0];
        popv(4);
        return acons(v0015, v0067, v0055);
    }

v0036:
    v0055 = nil;
    { popv(4); return onevalue(v0055); }
/* error exit handlers */
v0014:
    popv(4);
    return nil;
}



/* Code for simprecip */

static Lisp_Object CC_simprecip(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014, v0015;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simprecip");
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
    v0015 = v0000;
/* end of prologue */
    v0014 = qvalue(elt(env, 1)); /* !*mcd */
    if (v0014 == nil) goto v0021;
    v0014 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v0014 = (*qfn2(fn))(qenv(fn), v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[0];
    fn = elt(env, 4); /* simp */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* invsq */
        return (*qfn1(fn))(qenv(fn), v0014);
    }

v0021:
    v0014 = elt(env, 2); /* recip */
    fn = elt(env, 3); /* carx */
    v0015 = (*qfn2(fn))(qenv(fn), v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[0];
    v0014 = (Lisp_Object)-15; /* -1 */
    v0014 = list2(v0015, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0067;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 6); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v0014);
    }
/* error exit handlers */
v0067:
    popv(1);
    return nil;
}



/* Code for rdcos!* */

static Lisp_Object CC_rdcosH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0065;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rdcos*");
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
    v0021 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* convprec */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[0];
    v0065 = v0021;
    v0021 = v0065;
    if (!consp(v0021)) goto v0031;
    v0021 = v0065;
    fn = elt(env, 2); /* cos!* */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[0];
    goto v0071;

v0071:
    {
        popv(1);
        fn = elt(env, 3); /* mkround */
        return (*qfn1(fn))(qenv(fn), v0021);
    }

v0031:
    v0021 = v0065;
    fn = elt(env, 4); /* cos */
    v0021 = (*qfn1(fn))(qenv(fn), v0021);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[0];
    goto v0071;
/* error exit handlers */
v0032:
    popv(1);
    return nil;
}



/* Code for one!-entry!-listp */

static Lisp_Object CC_oneKentryKlistp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0067;
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

v0073:
    v0015 = stack[-1];
    if (v0015 == nil) goto v0036;
    v0015 = stack[-1];
    v0067 = qcar(v0015);
    v0015 = stack[0];
    fn = elt(env, 3); /* one!-entryp */
    v0015 = (*qfn2(fn))(qenv(fn), v0067, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    if (v0015 == nil) goto v0013;
    v0015 = stack[-1];
    v0067 = qcdr(v0015);
    v0015 = stack[0];
    stack[-1] = v0067;
    stack[0] = v0015;
    goto v0073;

v0013:
    v0015 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0015); }

v0036:
    v0015 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0015); }
/* error exit handlers */
v0045:
    popv(3);
    return nil;
}



/* Code for mv2sf1 */

static Lisp_Object MS_CDECL CC_mv2sf1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077, v0078, v0052;
    Lisp_Object fn;
    Lisp_Object v0039, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mv2sf1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv2sf1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0039,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0039;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */

v0034:
    v0077 = stack[-2];
    if (v0077 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0077 = stack[-2];
    v0078 = qcar(v0077);
    v0077 = (Lisp_Object)1; /* 0 */
    if (v0078 == v0077) goto v0013;
    v0077 = stack[0];
    v0078 = qcar(v0077);
    v0077 = stack[-2];
    v0077 = qcar(v0077);
    fn = elt(env, 1); /* to */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-4];
    v0077 = stack[-2];
    v0052 = qcdr(v0077);
    v0078 = stack[-1];
    v0077 = stack[0];
    v0077 = qcdr(v0077);
    v0077 = CC_mv2sf1(env, 3, v0052, v0078, v0077);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    env = stack[-4];
    v0077 = cons(stack[-3], v0077);
    nil = C_nil;
    if (exception_pending()) goto v0079;
    popv(5);
    return ncons(v0077);

v0013:
    v0077 = stack[-2];
    v0077 = qcdr(v0077);
    stack[-2] = v0077;
    v0077 = stack[0];
    v0077 = qcdr(v0077);
    stack[0] = v0077;
    goto v0034;
/* error exit handlers */
v0079:
    popv(5);
    return nil;
}



/* Code for rnminusp!: */

static Lisp_Object CC_rnminuspT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0055;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnminusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0044 = v0000;
/* end of prologue */
    v0044 = qcdr(v0044);
    v0055 = qcar(v0044);
    v0044 = v0055;
    if (!consp(v0055)) goto v0080;
    v0055 = v0044;
    v0055 = qcar(v0055);
    if (!symbolp(v0055)) v0055 = nil;
    else { v0055 = qfastgets(v0055);
           if (v0055 != nil) { v0055 = elt(v0055, 30); /* minusp */
#ifdef RECORD_GET
             if (v0055 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0055 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0055 == SPID_NOPROP) v0055 = nil; }}
#endif
        return Lapply1(nil, v0055, v0044);

v0080:
    v0055 = v0044;
    v0044 = (Lisp_Object)1; /* 0 */
        return Llessp(nil, v0055, v0044);
}



/* Code for polynommultiplybyvariable */

static Lisp_Object CC_polynommultiplybyvariable(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynommultiplybyvariable");
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
    stack[-3] = nil;
    v0087 = stack[-2];
    stack[0] = v0087;
    goto v0080;

v0080:
    v0087 = stack[0];
    v0087 = qcar(v0087);
    if (v0087 == nil) goto v0003;
    v0087 = stack[0];
    v0088 = qcar(v0087);
    v0087 = stack[-1];
    fn = elt(env, 2); /* monomgetvariabledegree */
    v0088 = (*qfn2(fn))(qenv(fn), v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0087 = (Lisp_Object)1; /* 0 */
    v0087 = Leqn(nil, v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    if (v0087 == nil) goto v0035;
    v0087 = stack[0];
    v0088 = qcar(v0087);
    v0087 = stack[-3];
    v0087 = cons(v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    stack[-3] = v0087;
    v0088 = stack[0];
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    v0087 = qcar(v0087);
    v0088 = Lrplaca(nil, v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    v0087 = qcdr(v0087);
    v0087 = Lrplacd(nil, v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    goto v0080;

v0035:
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    stack[0] = v0087;
    goto v0080;

v0003:
    v0088 = qvalue(elt(env, 1)); /* nil */
    v0087 = stack[-3];
    v0087 = cons(v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    stack[-3] = v0087;
    v0087 = stack[-3];
    v0087 = Lreverse(nil, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    stack[-3] = v0087;
    v0087 = stack[-3];
    stack[0] = v0087;
    goto v0057;

v0057:
    v0087 = stack[0];
    v0087 = qcar(v0087);
    if (v0087 == nil) goto v0090;
    v0087 = stack[0];
    v0088 = qcar(v0087);
    v0087 = stack[-1];
    fn = elt(env, 3); /* monommultiplybyvariable */
    v0087 = (*qfn2(fn))(qenv(fn), v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    stack[0] = v0087;
    goto v0057;

v0090:
    v0088 = stack[-2];
    v0087 = stack[-3];
    fn = elt(env, 4); /* polynomadd */
    v0087 = (*qfn2(fn))(qenv(fn), v0088, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0087 = nil;
    { popv(5); return onevalue(v0087); }
/* error exit handlers */
v0089:
    popv(5);
    return nil;
}



/* Code for mchkopt1 */

static Lisp_Object MS_CDECL CC_mchkopt1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0109, v0110;
    Lisp_Object fn;
    Lisp_Object v0039, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mchkopt1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchkopt1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0039,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0039;
    v0108 = v0001;
    v0110 = v0000;
/* end of prologue */
    v0108 = qcdr(v0108);
    v0109 = v0108;
    if (v0108 == nil) goto v0049;
    v0108 = v0109;
    v0108 = qcar(v0108);
    stack[-3] = v0108;
    v0108 = v0109;
    v0108 = qcdr(v0108);
    v0109 = v0108;
    if (v0108 == nil) goto v0070;
    v0108 = v0109;
    v0108 = qcar(v0108);
    stack[-5] = v0108;
    v0108 = v0109;
    v0108 = qcdr(v0108);
    if (v0108 == nil) goto v0016;
    v0108 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0108); }

v0016:
    v0108 = stack[-3];
    if (!symbolp(v0108)) v0108 = nil;
    else { v0108 = qfastgets(v0108);
           if (v0108 != nil) { v0108 = elt(v0108, 6); /* optional */
#ifdef RECORD_GET
             if (v0108 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v0108 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v0108 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v0108 == SPID_NOPROP) v0108 = nil; else v0108 = lisp_true; }}
#endif
    if (v0108 == nil) goto v0067;
    v0109 = v0110;
    v0108 = stack[-5];
    fn = elt(env, 2); /* mchk */
    v0108 = (*qfn2(fn))(qenv(fn), v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-5] = v0108;
    v0108 = stack[-5];
    if (v0108 == nil) goto v0050;
    v0108 = stack[-5];
    v0108 = qcar(v0108);
    v0110 = stack[-3];
    v0109 = stack[-4];
    v0109 = qcar(v0109);
    v0108 = acons(v0110, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0108 = ncons(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-1] = v0108;
    stack[-2] = v0108;
    goto v0076;

v0076:
    v0108 = stack[-5];
    v0108 = qcdr(v0108);
    stack[-5] = v0108;
    v0108 = stack[-5];
    if (v0108 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0108 = stack[-5];
    v0108 = qcar(v0108);
    v0110 = stack[-3];
    v0109 = stack[-4];
    v0109 = qcar(v0109);
    v0108 = acons(v0110, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0108 = ncons(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0108 = Lrplacd(nil, stack[0], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    stack[-1] = v0108;
    goto v0076;

v0050:
    v0108 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0108); }

v0067:
    v0108 = stack[-5];
    if (!symbolp(v0108)) v0108 = nil;
    else { v0108 = qfastgets(v0108);
           if (v0108 != nil) { v0108 = elt(v0108, 6); /* optional */
#ifdef RECORD_GET
             if (v0108 == SPID_NOPROP)
                record_get(elt(fastget_names, 6), 0),
                v0108 = nil;
             else record_get(elt(fastget_names, 6), 1),
                v0108 = lisp_true; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v0108 == SPID_NOPROP) v0108 = nil; else v0108 = lisp_true; }}
#endif
    if (v0108 == nil) goto v0112;
    v0109 = v0110;
    v0108 = stack[-3];
    fn = elt(env, 2); /* mchk */
    v0108 = (*qfn2(fn))(qenv(fn), v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-3] = v0108;
    v0108 = stack[-3];
    if (v0108 == nil) goto v0113;
    v0108 = stack[-3];
    v0108 = qcar(v0108);
    v0110 = stack[-5];
    v0109 = stack[-4];
    v0109 = qcdr(v0109);
    v0109 = qcar(v0109);
    v0108 = acons(v0110, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0108 = ncons(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    stack[-1] = v0108;
    stack[-2] = v0108;
    goto v0114;

v0114:
    v0108 = stack[-3];
    v0108 = qcdr(v0108);
    stack[-3] = v0108;
    v0108 = stack[-3];
    if (v0108 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v0108 = stack[-3];
    v0108 = qcar(v0108);
    v0110 = stack[-5];
    v0109 = stack[-4];
    v0109 = qcdr(v0109);
    v0109 = qcar(v0109);
    v0108 = acons(v0110, v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0108 = ncons(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0108 = Lrplacd(nil, stack[0], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0111;
    env = stack[-6];
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    stack[-1] = v0108;
    goto v0114;

v0113:
    v0108 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0108); }

v0112:
    v0108 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0108); }

v0070:
    v0108 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0108); }

v0049:
    v0108 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0108); }
/* error exit handlers */
v0111:
    popv(7);
    return nil;
}



/* Code for remove!-free!-vars!* */

static Lisp_Object CC_removeKfreeKvarsH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0071;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for remove-free-vars*");
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
    v0071 = v0000;
/* end of prologue */
    v0034 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*!*noremove!*!* */
    qvalue(elt(env, 2)) = v0034; /* !*!*noremove!*!* */
    v0034 = v0071;
    fn = elt(env, 3); /* remove!-free!-vars */
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*!*noremove!*!* */
    { popv(2); return onevalue(v0034); }
/* error exit handlers */
v0115:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*!*noremove!*!* */
    popv(2);
    return nil;
}



/* Code for sf2ss */

static Lisp_Object CC_sf2ss(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sf2ss");
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
    v0030 = stack[-1];
    if (!consp(v0030)) goto v0011;
    v0030 = stack[-1];
    v0030 = qcar(v0030);
    v0030 = (consp(v0030) ? nil : lisp_true);
    goto v0049;

v0049:
    if (!(v0030 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0030 = stack[-1];
    fn = elt(env, 2); /* searchpl */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    stack[-2] = v0030;
    v0030 = stack[-2];
    fn = elt(env, 3); /* qsort */
    stack[0] = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    v0030 = stack[-2];
    v0030 = Llength(nil, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    v0030 = cons(stack[0], v0030);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    stack[0] = v0030;
    v0046 = stack[-1];
    fn = elt(env, 4); /* sq2sspl */
    v0046 = (*qfn2(fn))(qenv(fn), v0046, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    v0030 = (Lisp_Object)17; /* 1 */
    v0030 = list2star(stack[0], v0046, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 5); /* lx2xx */
        return (*qfn1(fn))(qenv(fn), v0030);
    }

v0011:
    v0030 = qvalue(elt(env, 1)); /* t */
    goto v0049;
/* error exit handlers */
v0047:
    popv(4);
    return nil;
}



/* Code for ibalp_var!-unsatlist */

static Lisp_Object CC_ibalp_varKunsatlist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0008, v0119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-unsatlist");
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
    stack[-2] = v0001;
    v0008 = v0000;
/* end of prologue */
    stack[-3] = v0008;
    goto v0034;

v0034:
    v0008 = stack[-3];
    if (v0008 == nil) goto v0080;
    v0008 = stack[-3];
    v0008 = qcar(v0008);
    stack[-1] = v0008;
    v0119 = stack[-2];
    v0008 = (Lisp_Object)17; /* 1 */
    v0008 = Leqn(nil, v0119, v0008);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-4];
    if (v0008 == nil) goto v0024;
    v0008 = stack[-1];
    v0008 = qcdr(v0008);
    v0008 = qcdr(v0008);
    stack[0] = qcdr(v0008);
    v0008 = stack[-1];
    v0008 = qcdr(v0008);
    v0008 = qcdr(v0008);
    v0008 = qcdr(v0008);
    v0008 = qcar(v0008);
    v0008 = sub1(v0008);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-4];
    fn = elt(env, 2); /* setcar */
    v0008 = (*qfn2(fn))(qenv(fn), stack[0], v0008);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-4];
    goto v0065;

v0065:
    v0008 = stack[-3];
    v0008 = qcdr(v0008);
    stack[-3] = v0008;
    goto v0034;

v0024:
    v0008 = stack[-1];
    v0008 = qcdr(v0008);
    stack[0] = qcdr(v0008);
    v0008 = stack[-1];
    v0008 = qcdr(v0008);
    v0008 = qcdr(v0008);
    v0008 = qcar(v0008);
    v0008 = sub1(v0008);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-4];
    fn = elt(env, 2); /* setcar */
    v0008 = (*qfn2(fn))(qenv(fn), stack[0], v0008);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-4];
    goto v0065;

v0080:
    v0008 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0008); }
/* error exit handlers */
v0120:
    popv(5);
    return nil;
}



/* Code for sfto_dprpartksf */

static Lisp_Object CC_sfto_dprpartksf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049;
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
    v0049 = v0000;
/* end of prologue */
    stack[0] = v0049;
    fn = elt(env, 1); /* sfto_dcontentf */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-1];
    {
        Lisp_Object v0012 = stack[0];
        popv(2);
        fn = elt(env, 2); /* quotf */
        return (*qfn2(fn))(qenv(fn), v0012, v0049);
    }
/* error exit handlers */
v0013:
    popv(2);
    return nil;
}



/* Code for ev_tdeg */

static Lisp_Object CC_ev_tdeg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0040, v0016, v0044;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_tdeg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0016 = v0000;
/* end of prologue */
    v0040 = (Lisp_Object)1; /* 0 */
    goto v0031;

v0031:
    v0044 = v0016;
    if (v0044 == nil) return onevalue(v0040);
    v0044 = v0016;
    v0044 = qcar(v0044);
    v0040 = (Lisp_Object)(int32_t)((int32_t)v0044 + (int32_t)v0040 - TAG_FIXNUM);
    v0016 = qcdr(v0016);
    goto v0031;
}



/* Code for dipilcomb1 */

static Lisp_Object MS_CDECL CC_dipilcomb1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172, v0173, v0174;
    Lisp_Object fn;
    Lisp_Object v0036, v0037, v0009, v0039, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "dipilcomb1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    v0009 = va_arg(aa, Lisp_Object);
    v0037 = va_arg(aa, Lisp_Object);
    v0036 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dipilcomb1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v0036,v0037,v0009,v0039,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0000,v0001,v0039,v0009,v0037,v0036);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v0036;
    stack[-11] = v0037;
    stack[-12] = v0009;
    stack[-13] = v0039;
    stack[-14] = v0001;
    stack[-15] = v0000;
/* end of prologue */
    v0172 = qvalue(elt(env, 1)); /* !*gcd */
    stack[-1] = v0172;
    stack[-16] = nil;
    stack[-9] = nil;
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v0173 = stack[-14];
    v0172 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    if (v0172 == nil) goto v0055;
    v0173 = stack[-11];
    v0172 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    if (v0172 == nil) goto v0055;
    v0172 = stack[-1];
    goto v0016;

v0016:
    qvalue(elt(env, 1)) = v0172; /* !*gcd */
    v0172 = stack[-13];
    fn = elt(env, 5); /* evzero!? */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    v0172 = (v0172 == nil ? lisp_true : nil);
    stack[-7] = v0172;
    v0172 = stack[-10];
    fn = elt(env, 5); /* evzero!? */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    v0172 = (v0172 == nil ? lisp_true : nil);
    stack[-6] = v0172;
    v0172 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v0172;
    stack[-5] = v0172;
    v0172 = qvalue(elt(env, 3)); /* nil */
    stack[-8] = v0172;
    stack[-2] = v0172;
    stack[-3] = v0172;
    goto v0033;

v0033:
    v0172 = stack[-5];
    if (v0172 == nil) goto v0077;
    v0172 = stack[-15];
    if (v0172 == nil) goto v0086;
    v0172 = stack[-15];
    v0172 = qcar(v0172);
    stack[-16] = v0172;
    v0172 = stack[-7];
    if (v0172 == nil) goto v0176;
    v0173 = stack[-16];
    v0172 = stack[-13];
    fn = elt(env, 6); /* evsum */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    stack[-16] = v0172;
    goto v0176;

v0176:
    v0172 = qvalue(elt(env, 3)); /* nil */
    stack[-5] = v0172;
    goto v0077;

v0077:
    v0172 = stack[-4];
    if (v0172 == nil) goto v0177;
    v0172 = stack[-12];
    if (v0172 == nil) goto v0178;
    v0172 = stack[-12];
    v0172 = qcar(v0172);
    stack[-9] = v0172;
    v0172 = stack[-6];
    if (v0172 == nil) goto v0179;
    v0173 = stack[-9];
    v0172 = stack[-10];
    fn = elt(env, 6); /* evsum */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    stack[-9] = v0172;
    goto v0179;

v0179:
    v0172 = qvalue(elt(env, 3)); /* nil */
    stack[-4] = v0172;
    goto v0177;

v0177:
    v0173 = stack[-16];
    v0172 = stack[-9];
    fn = elt(env, 7); /* evcomp */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    v0174 = v0172;
    v0173 = v0174;
    v0172 = (Lisp_Object)17; /* 1 */
    if (v0173 == v0172) goto v0180;
    v0173 = v0174;
    v0172 = (Lisp_Object)-15; /* -1 */
    if (v0173 == v0172) goto v0181;
    v0172 = qvalue(elt(env, 1)); /* !*gcd */
    if (v0172 == nil) goto v0182;
    v0172 = stack[-15];
    v0172 = qcdr(v0172);
    v0173 = qcar(v0172);
    v0172 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    if (v0172 == nil) goto v0183;
    v0172 = stack[-12];
    v0172 = qcdr(v0172);
    v0173 = qcar(v0172);
    v0172 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    v0172 = (v0172 == nil ? lisp_true : nil);
    goto v0184;

v0184:
    if (v0172 == nil) goto v0182;
    v0172 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v0172; /* !*gcd */
    goto v0182;

v0182:
    v0172 = stack[-15];
    v0172 = qcdr(v0172);
    v0173 = qcar(v0172);
    v0172 = stack[-14];
    fn = elt(env, 8); /* bcprod */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    v0172 = stack[-12];
    v0172 = qcdr(v0172);
    v0173 = qcar(v0172);
    v0172 = stack[-11];
    fn = elt(env, 8); /* bcprod */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    fn = elt(env, 9); /* bcsum */
    v0172 = (*qfn2(fn))(qenv(fn), stack[-1], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    stack[-1] = v0172;
    v0172 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    if (!(v0172 == nil)) goto v0185;
    v0174 = stack[-16];
    v0173 = stack[-1];
    v0172 = qvalue(elt(env, 3)); /* nil */
    v0172 = list2star(v0174, v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    v0172 = Lnconc(nil, stack[-2], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    stack[-3] = v0172;
    v0172 = stack[-3];
    v0172 = qcdr(v0172);
    v0172 = qcdr(v0172);
    stack[-2] = v0172;
    goto v0185;

v0185:
    v0172 = stack[-15];
    v0172 = qcdr(v0172);
    v0172 = qcdr(v0172);
    stack[-15] = v0172;
    v0172 = stack[-12];
    v0172 = qcdr(v0172);
    v0172 = qcdr(v0172);
    stack[-12] = v0172;
    v0172 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v0172;
    stack[-5] = v0172;
    goto v0095;

v0095:
    v0172 = stack[-8];
    if (!(v0172 == nil)) goto v0033;
    v0172 = stack[-3];
    stack[-2] = v0172;
    stack[-8] = v0172;
    goto v0033;

v0183:
    v0172 = qvalue(elt(env, 2)); /* t */
    goto v0184;

v0181:
    v0172 = qvalue(elt(env, 1)); /* !*gcd */
    if (v0172 == nil) goto v0186;
    v0172 = stack[-12];
    v0172 = qcdr(v0172);
    v0173 = qcar(v0172);
    v0172 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    if (!(v0172 == nil)) goto v0186;
    v0172 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v0172; /* !*gcd */
    goto v0186;

v0186:
    v0172 = stack[-12];
    v0172 = qcdr(v0172);
    v0173 = qcar(v0172);
    v0172 = stack[-11];
    fn = elt(env, 8); /* bcprod */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    stack[-1] = v0172;
    v0172 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    if (!(v0172 == nil)) goto v0187;
    v0174 = stack[-9];
    v0173 = stack[-1];
    v0172 = qvalue(elt(env, 3)); /* nil */
    v0172 = list2star(v0174, v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    v0172 = Lnconc(nil, stack[-2], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    stack[-3] = v0172;
    v0172 = stack[-3];
    v0172 = qcdr(v0172);
    v0172 = qcdr(v0172);
    stack[-2] = v0172;
    goto v0187;

v0187:
    v0172 = stack[-12];
    v0172 = qcdr(v0172);
    v0172 = qcdr(v0172);
    stack[-12] = v0172;
    v0172 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v0172;
    goto v0095;

v0180:
    v0172 = qvalue(elt(env, 1)); /* !*gcd */
    if (v0172 == nil) goto v0188;
    v0172 = stack[-15];
    v0172 = qcdr(v0172);
    v0173 = qcar(v0172);
    v0172 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    if (!(v0172 == nil)) goto v0188;
    v0172 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v0172; /* !*gcd */
    goto v0188;

v0188:
    v0172 = stack[-15];
    v0172 = qcdr(v0172);
    v0173 = qcar(v0172);
    v0172 = stack[-14];
    fn = elt(env, 8); /* bcprod */
    v0172 = (*qfn2(fn))(qenv(fn), v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    stack[-1] = v0172;
    v0172 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    if (!(v0172 == nil)) goto v0189;
    v0174 = stack[-16];
    v0173 = stack[-1];
    v0172 = qvalue(elt(env, 3)); /* nil */
    v0172 = list2star(v0174, v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    v0172 = Lnconc(nil, stack[-2], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    stack[-3] = v0172;
    v0172 = stack[-3];
    v0172 = qcdr(v0172);
    v0172 = qcdr(v0172);
    stack[-2] = v0172;
    goto v0189;

v0189:
    v0172 = stack[-15];
    v0172 = qcdr(v0172);
    v0172 = qcdr(v0172);
    stack[-15] = v0172;
    v0172 = qvalue(elt(env, 2)); /* t */
    stack[-5] = v0172;
    goto v0095;

v0178:
    stack[-1] = stack[-8];
    stack[-2] = stack[-15];
    v0174 = stack[-13];
    v0173 = stack[-14];
    v0172 = qvalue(elt(env, 3)); /* nil */
    v0172 = list2star(v0174, v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    fn = elt(env, 11); /* dipprod */
    v0172 = (*qfn2(fn))(qenv(fn), stack[-2], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    v0172 = Lnconc(nil, stack[-1], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    goto v0028;

v0028:
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(18); return onevalue(v0172); }

v0086:
    v0172 = stack[-12];
    if (v0172 == nil) goto v0190;
    stack[-1] = stack[-8];
    stack[-2] = stack[-12];
    v0174 = stack[-10];
    v0173 = stack[-11];
    v0172 = qvalue(elt(env, 3)); /* nil */
    v0172 = list2star(v0174, v0173, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    fn = elt(env, 11); /* dipprod */
    v0172 = (*qfn2(fn))(qenv(fn), stack[-2], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    v0172 = Lnconc(nil, stack[-1], v0172);
    nil = C_nil;
    if (exception_pending()) goto v0175;
    env = stack[-17];
    goto v0028;

v0190:
    v0172 = stack[-8];
    goto v0028;

v0055:
    v0172 = nil;
    goto v0016;
/* error exit handlers */
v0175:
    env = stack[-17];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(18);
    return nil;
}



/* Code for bcfd */

static Lisp_Object CC_bcfd(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0074, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bcfd");
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
    v0038 = v0000;
/* end of prologue */
    v0076 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v0076 == nil) goto v0031;
    v0076 = v0038;
    v0076 = integerp(v0076);
    if (v0076 == nil) goto v0072;
    v0076 = v0038;
    {
        popv(1);
        fn = elt(env, 4); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0076);
    }

v0072:
    v0076 = v0038;
    v0074 = qcar(v0076);
    v0076 = elt(env, 2); /* !:mod!: */
    if (v0074 == v0076) goto v0045;
    v0076 = elt(env, 3); /* "Invalid modular coefficient" */
    v0074 = v0038;
    v0076 = list2(v0076, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 5); /* rederr */
        return (*qfn1(fn))(qenv(fn), v0076);
    }

v0045:
    v0076 = v0038;
    v0076 = qcdr(v0076);
    {
        popv(1);
        fn = elt(env, 4); /* bcfi */
        return (*qfn1(fn))(qenv(fn), v0076);
    }

v0031:
    v0074 = v0038;
    v0076 = (Lisp_Object)17; /* 1 */
    {
        popv(1);
        fn = elt(env, 6); /* mkbc */
        return (*qfn2(fn))(qenv(fn), v0074, v0076);
    }
/* error exit handlers */
v0024:
    popv(1);
    return nil;
}



/* Code for freeoffl */

static Lisp_Object CC_freeoffl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0015, v0067;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeoffl");
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

v0073:
    v0015 = stack[0];
    if (v0015 == nil) goto v0036;
    v0067 = stack[-1];
    v0015 = stack[0];
    v0015 = qcar(v0015);
    fn = elt(env, 3); /* freeoff */
    v0015 = (*qfn2(fn))(qenv(fn), v0067, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-2];
    if (v0015 == nil) goto v0013;
    v0067 = stack[-1];
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    stack[-1] = v0067;
    stack[0] = v0015;
    goto v0073;

v0013:
    v0015 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0015); }

v0036:
    v0015 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0015); }
/* error exit handlers */
v0045:
    popv(3);
    return nil;
}



/* Code for cut!:mt */

static Lisp_Object CC_cutTmt(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0196, v0197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cut:mt");
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
    v0197 = stack[-2];
    v0196 = elt(env, 1); /* !:rd!: */
    if (!consp(v0197)) goto v0040;
    v0197 = qcar(v0197);
    if (!(v0197 == v0196)) goto v0040;
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    v0196 = (consp(v0196) ? nil : lisp_true);
    v0196 = (v0196 == nil ? lisp_true : nil);
    goto v0011;

v0011:
    if (v0196 == nil) goto v0038;
    v0196 = stack[-1];
    v0196 = integerp(v0196);
    if (v0196 == nil) goto v0117;
    v0197 = stack[-1];
    v0196 = (Lisp_Object)1; /* 0 */
    v0196 = (Lisp_Object)greaterp2(v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0196 = v0196 ? lisp_true : nil;
    env = stack[-4];
    goto v0031;

v0031:
    if (v0196 == nil) goto v0104;
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    v0196 = qcar(v0196);
    v0196 = Labsval(nil, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    fn = elt(env, 3); /* msd */
    v0197 = (*qfn1(fn))(qenv(fn), v0196);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    v0196 = stack[-1];
    v0197 = difference2(v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    stack[-1] = v0197;
    v0196 = (Lisp_Object)1; /* 0 */
    v0196 = (Lisp_Object)lesseq2(v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    v0196 = v0196 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0196 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    stack[0] = qcar(v0196);
    v0196 = stack[-1];
    v0196 = negate(v0196);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v0196);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    v0196 = stack[-2];
    v0196 = qcdr(v0196);
    v0197 = qcdr(v0196);
    v0196 = stack[-1];
    v0196 = plus2(v0197, v0196);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    {
        Lisp_Object v0199 = stack[-3];
        Lisp_Object v0114 = stack[0];
        popv(5);
        return list2star(v0199, v0114, v0196);
    }

v0104:
    v0196 = elt(env, 0); /* cut!:mt */
    {
        popv(5);
        fn = elt(env, 4); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v0196);
    }

v0117:
    v0196 = qvalue(elt(env, 2)); /* nil */
    goto v0031;

v0038:
    v0196 = qvalue(elt(env, 2)); /* nil */
    goto v0031;

v0040:
    v0196 = qvalue(elt(env, 2)); /* nil */
    goto v0011;
/* error exit handlers */
v0198:
    popv(5);
    return nil;
}



/* Code for cstimes */

static Lisp_Object CC_cstimes(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0078, v0052, v0007, v0008;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cstimes");
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
    v0052 = v0001;
    v0007 = v0000;
/* end of prologue */

v0034:
    v0078 = v0007;
    if (v0078 == nil) goto v0115;
    v0078 = v0007;
    v0008 = qcar(v0078);
    v0078 = (Lisp_Object)17; /* 1 */
    if (v0008 == v0078) goto v0027;
    v0078 = v0007;
    v0078 = qcdr(v0078);
    stack[0] = v0078;
    v0078 = v0007;
    v0078 = qcar(v0078);
    v0078 = cons(v0078, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    v0052 = v0078;
    v0078 = stack[0];
    v0007 = v0078;
    goto v0034;

v0027:
    v0078 = v0007;
    v0078 = qcdr(v0078);
    v0007 = v0078;
    goto v0034;

v0115:
    v0078 = v0052;
    if (v0078 == nil) goto v0012;
    v0078 = v0052;
    v0078 = qcdr(v0078);
    if (v0078 == nil) goto v0065;
    v0078 = elt(env, 1); /* times */
    popv(2);
    return cons(v0078, v0052);

v0065:
    v0078 = v0052;
    v0078 = qcar(v0078);
    { popv(2); return onevalue(v0078); }

v0012:
    v0078 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v0078); }
/* error exit handlers */
v0086:
    popv(2);
    return nil;
}



/* Code for assert_uninstall_all */

static Lisp_Object MS_CDECL CC_assert_uninstall_all(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_uninstall_all");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for assert_uninstall_all");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0009 = qvalue(elt(env, 1)); /* assert_functionl!* */
    {
        fn = elt(env, 2); /* assert_uninstall */
        return (*qfn1(fn))(qenv(fn), v0009);
    }
}



/* Code for general!-reduce!-degree!-mod!-p */

static Lisp_Object CC_generalKreduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0171, v0170, v0060;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-reduce-degree-mod-p");
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
    v0171 = stack[-1];
    v0171 = qcar(v0171);
    v0171 = qcdr(v0171);
    fn = elt(env, 1); /* general!-modular!-minus */
    v0170 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-3];
    v0171 = stack[0];
    v0171 = qcar(v0171);
    v0171 = qcdr(v0171);
    fn = elt(env, 2); /* general!-modular!-quotient */
    v0171 = (*qfn2(fn))(qenv(fn), v0170, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-3];
    stack[-2] = v0171;
    v0171 = stack[-1];
    v0171 = qcar(v0171);
    v0171 = qcar(v0171);
    v0170 = qcdr(v0171);
    v0171 = stack[0];
    v0171 = qcar(v0171);
    v0171 = qcar(v0171);
    v0171 = qcdr(v0171);
    v0171 = (Lisp_Object)(int32_t)((int32_t)v0170 - (int32_t)v0171 + TAG_FIXNUM);
    v0060 = v0171;
    v0170 = v0060;
    v0171 = (Lisp_Object)1; /* 0 */
    if (v0170 == v0171) goto v0074;
    v0171 = stack[-1];
    stack[-1] = qcdr(v0171);
    v0171 = stack[0];
    v0171 = qcar(v0171);
    v0171 = qcar(v0171);
    v0171 = qcar(v0171);
    v0170 = v0060;
    fn = elt(env, 3); /* mksp */
    v0170 = (*qfn2(fn))(qenv(fn), v0171, v0170);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-3];
    v0171 = stack[-2];
    v0170 = cons(v0170, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-3];
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    fn = elt(env, 4); /* general!-times!-term!-mod!-p */
    v0171 = (*qfn2(fn))(qenv(fn), v0170, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-3];
    {
        Lisp_Object v0056 = stack[-1];
        popv(4);
        fn = elt(env, 5); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0056, v0171);
    }

v0074:
    v0171 = stack[-1];
    stack[-1] = qcdr(v0171);
    v0171 = stack[0];
    v0170 = qcdr(v0171);
    v0171 = stack[-2];
    fn = elt(env, 6); /* general!-multiply!-by!-constant!-mod!-p */
    v0171 = (*qfn2(fn))(qenv(fn), v0170, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0176;
    env = stack[-3];
    {
        Lisp_Object v0104 = stack[-1];
        popv(4);
        fn = elt(env, 5); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0104, v0171);
    }
/* error exit handlers */
v0176:
    popv(4);
    return nil;
}



/* Code for mksetq */

static Lisp_Object CC_mksetq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0077, v0078, v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksetq");
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
    v0077 = v0001;
    v0078 = v0000;
/* end of prologue */
    v0047 = v0078;
    if (!consp(v0047)) goto v0115;
    v0047 = v0078;
    v0052 = qcar(v0047);
    v0047 = elt(env, 2); /* setfn */
    v0047 = get(v0052, v0047);
    env = stack[0];
    v0052 = v0047;
    if (v0047 == nil) goto v0005;
    v0047 = v0052;
        popv(1);
        return Lapply2(nil, 3, v0047, v0078, v0077);

v0005:
    v0077 = v0078;
    v0047 = elt(env, 3); /* "assignment argument" */
    fn = elt(env, 4); /* typerr */
    v0047 = (*qfn2(fn))(qenv(fn), v0077, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    v0047 = nil;
    { popv(1); return onevalue(v0047); }

v0115:
    v0047 = elt(env, 1); /* setq */
    popv(1);
    return list3(v0047, v0078, v0077);
/* error exit handlers */
v0007:
    popv(1);
    return nil;
}



/* Code for defineargs */

static Lisp_Object CC_defineargs(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0120, v0190, v0195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for defineargs");
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
    v0168 = stack[-1];
    if (!symbolp(v0168)) v0168 = nil;
    else { v0168 = qfastgets(v0168);
           if (v0168 != nil) { v0168 = elt(v0168, 42); /* number!-of!-args 
*/
#ifdef RECORD_GET
             if (v0168 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v0168 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v0168 == SPID_NOPROP) v0168 = nil; }}
#endif
    v0120 = v0168;
    v0168 = v0120;
    if (v0168 == nil) goto v0004;
    v0190 = stack[0];
    v0168 = v0120;
    if (equal(v0190, v0168)) goto v0029;
    v0190 = stack[-1];
    v0168 = elt(env, 2); /* calledby */
    v0190 = get(v0190, v0168);
    env = stack[-2];
    v0168 = v0190;
    if (v0190 == nil) goto v0052;
    v0195 = stack[-1];
    v0190 = stack[0];
    fn = elt(env, 3); /* instdof */
    v0168 = (*qfnn(fn))(qenv(fn), 4, v0195, v0190, v0120, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-2];
    goto v0052;

v0052:
    v0120 = stack[-1];
    v0168 = stack[0];
    fn = elt(env, 4); /* hasarg */
    v0168 = (*qfn2(fn))(qenv(fn), v0120, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    v0168 = nil;
    { popv(3); return onevalue(v0168); }

v0029:
    v0168 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0168); }

v0004:
    v0120 = stack[-1];
    v0168 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* hasarg */
        return (*qfn2(fn))(qenv(fn), v0120, v0168);
    }
/* error exit handlers */
v0003:
    popv(3);
    return nil;
}



/* Code for polynomheadreduceby */

static Lisp_Object CC_polynomheadreduceby(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for polynomheadreduceby");
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
    stack[-3] = nil;
    goto v0115;

v0115:
    v0035 = stack[-2];
    v0035 = qcar(v0035);
    if (v0035 == nil) goto v0031;
    v0035 = stack[-3];
    if (!(v0035 == nil)) goto v0031;
    v0035 = stack[-2];
    v0168 = qcar(v0035);
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    fn = elt(env, 4); /* monomisdivisibleby */
    v0035 = (*qfn2(fn))(qenv(fn), v0168, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    if (v0035 == nil) goto v0078;
    v0035 = stack[-2];
    v0168 = qcar(v0035);
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    fn = elt(env, 5); /* monomdivide */
    v0035 = (*qfn2(fn))(qenv(fn), v0168, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    stack[0] = stack[-2];
    v0168 = stack[-1];
    fn = elt(env, 6); /* polynommultiplybymonom */
    v0035 = (*qfn2(fn))(qenv(fn), v0168, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    fn = elt(env, 7); /* polynomadd */
    v0035 = (*qfn2(fn))(qenv(fn), stack[0], v0035);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    goto v0115;

v0078:
    v0035 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v0035;
    goto v0115;

v0031:
    v0035 = qvalue(elt(env, 3)); /* fluidbibasisreductionsmade */
    v0035 = (Lisp_Object)((int32_t)(v0035) + 0x10);
    qvalue(elt(env, 3)) = v0035; /* fluidbibasisreductionsmade */
    v0035 = nil;
    { popv(5); return onevalue(v0035); }
/* error exit handlers */
v0002:
    popv(5);
    return nil;
}



/* Code for revalx */

static Lisp_Object CC_revalx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revalx");
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
    v0028 = v0000;
/* end of prologue */
    v0029 = v0028;
    if (!consp(v0029)) goto v0023;
    v0029 = v0028;
    v0029 = qcar(v0029);
    v0029 = (consp(v0029) ? nil : lisp_true);
    v0029 = (v0029 == nil ? lisp_true : nil);
    goto v0031;

v0031:
    if (v0029 == nil) goto v0020;
    v0029 = v0028;
    fn = elt(env, 2); /* prepf */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0033;
    env = stack[0];
    goto v0037;

v0037:
    {
        popv(1);
        fn = elt(env, 3); /* reval */
        return (*qfn1(fn))(qenv(fn), v0029);
    }

v0020:
    v0029 = v0028;
    goto v0037;

v0023:
    v0029 = qvalue(elt(env, 1)); /* nil */
    goto v0031;
/* error exit handlers */
v0033:
    popv(1);
    return nil;
}



/* Code for squared!+matrix!+p */

static Lisp_Object CC_squaredLmatrixLp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for squared+matrix+p");
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
    v0069 = stack[0];
    fn = elt(env, 2); /* matrix!+p */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    if (v0069 == nil) goto v0036;
    v0069 = stack[0];
    fn = elt(env, 3); /* get!+row!+nr */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0069 = stack[0];
    fn = elt(env, 4); /* get!+col!+nr */
    v0069 = (*qfn1(fn))(qenv(fn), v0069);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    if (!(equal(stack[-1], v0069))) goto v0036;
    v0069 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0069); }

v0036:
    v0069 = nil;
    { popv(3); return onevalue(v0069); }
/* error exit handlers */
v0028:
    popv(3);
    return nil;
}



/* Code for sq2sstm */

static Lisp_Object CC_sq2sstm(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0205, v0196, v0197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sq2sstm");
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
    stack[-2] = v0001;
    v0197 = v0000;
/* end of prologue */
    v0205 = v0197;
    v0205 = qcar(v0205);
    v0196 = qcar(v0205);
    v0205 = stack[-2];
    v0205 = qcar(v0205);
    v0205 = qcar(v0205);
    if (equal(v0196, v0205)) goto v0080;
    v0205 = v0197;
    stack[-1] = ncons(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    v0205 = stack[-2];
    v0205 = qcar(v0205);
    stack[0] = qcdr(v0205);
    v0205 = stack[-2];
    v0205 = qcdr(v0205);
    v0205 = sub1(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    v0205 = cons(stack[0], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    fn = elt(env, 2); /* sq2sscfpl */
    v0205 = (*qfn2(fn))(qenv(fn), stack[-1], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    v0196 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0196;
    goto v0083;

v0083:
    v0196 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* mapins */
        return (*qfn2(fn))(qenv(fn), v0196, v0205);
    }

v0080:
    v0205 = v0197;
    v0205 = qcdr(v0205);
    stack[0] = v0205;
    v0205 = v0197;
    v0205 = qcar(v0205);
    v0205 = qcdr(v0205);
    stack[-3] = v0205;
    v0205 = stack[0];
    if (!consp(v0205)) goto v0027;
    v0205 = stack[0];
    v0205 = qcar(v0205);
    v0205 = (consp(v0205) ? nil : lisp_true);
    goto v0068;

v0068:
    if (v0205 == nil) goto v0078;
    stack[-1] = stack[-3];
    v0205 = stack[-2];
    v0205 = qcdr(v0205);
    fn = elt(env, 4); /* mkzl */
    v0196 = (*qfn1(fn))(qenv(fn), v0205);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    v0205 = stack[0];
    v0205 = acons(stack[-1], v0196, v0205);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    popv(5);
    return ncons(v0205);

v0078:
    stack[-1] = stack[0];
    v0205 = stack[-2];
    v0205 = qcar(v0205);
    stack[0] = qcdr(v0205);
    v0205 = stack[-2];
    v0205 = qcdr(v0205);
    v0205 = sub1(v0205);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    v0205 = cons(stack[0], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    fn = elt(env, 2); /* sq2sscfpl */
    v0205 = (*qfn2(fn))(qenv(fn), stack[-1], v0205);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[-4];
    goto v0083;

v0027:
    v0205 = qvalue(elt(env, 1)); /* t */
    goto v0068;
/* error exit handlers */
v0198:
    popv(5);
    return nil;
}



/* Code for token!-number */

static Lisp_Object CC_tokenKnumber(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0238, v0239, v0240;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for token-number");
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
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v0238 = (Lisp_Object)1; /* 0 */
    stack[-3] = v0238;
    v0238 = (Lisp_Object)33; /* 2 */
    qvalue(elt(env, 1)) = v0238; /* ttype!* */
    goto v0115;

v0115:
    v0238 = stack[-1];
    if (!(v0238 == nil)) goto v0027;
    v0239 = stack[-4];
    v0238 = elt(env, 2); /* !) */
    if (!(v0239 == v0238)) goto v0027;

v0070:
    v0238 = stack[-5];
    if (v0238 == nil) goto v0080;
    v0238 = stack[-3];
    v0238 = sub1(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[-3] = v0238;
    goto v0080;

v0080:
    fn = elt(env, 23); /* readch1 */
    v0238 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[-4] = v0238;
    v0239 = stack[-4];
    v0238 = qvalue(elt(env, 3)); /* !$eof!$ */
    if (v0239 == v0238) goto v0010;
    v0238 = stack[-4];
    fn = elt(env, 24); /* id2string */
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    fn = elt(env, 25); /* string!-length */
    v0239 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    v0238 = (Lisp_Object)17; /* 1 */
    v0238 = (v0239 == v0238 ? lisp_true : nil);
    v0238 = (v0238 == nil ? lisp_true : nil);
    goto v0046;

v0046:
    if (!(v0238 == nil)) goto v0004;
    v0239 = stack[-4];
    v0238 = elt(env, 5); /* !. */
    if (v0239 == v0238) goto v0200;
    v0238 = stack[-4];
    v0238 = Ldigitp(nil, v0238);
    env = stack[-6];
    if (!(v0238 == nil)) goto v0115;
    v0239 = stack[-1];
    v0238 = elt(env, 8); /* (!0) */
    if (equal(v0239, v0238)) goto v0063;
    v0238 = qvalue(elt(env, 11)); /* nil */
    goto v0082;

v0082:
    if (v0238 == nil) goto v0166;
    v0238 = (Lisp_Object)1; /* 0 */
    stack[-1] = v0238;
    goto v0145;

v0145:
    fn = elt(env, 23); /* readch1 */
    v0239 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[-4] = v0239;
    v0238 = elt(env, 17); /* hexdigit */
    v0238 = get(v0239, v0238);
    env = stack[-6];
    stack[0] = v0238;
    if (v0238 == nil) goto v0023;
    v0239 = (Lisp_Object)257; /* 16 */
    v0238 = stack[-1];
    v0239 = times2(v0239, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    v0238 = stack[0];
    v0238 = plus2(v0239, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[-1] = v0238;
    goto v0145;

v0023:
    v0238 = stack[-5];
    if (v0238 == nil) goto v0242;
    v0240 = elt(env, 18); /* !:dn!: */
    v0239 = stack[-1];
    v0238 = stack[-3];
    v0238 = list2star(v0240, v0239, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    goto v0243;

v0243:
    qvalue(elt(env, 21)) = v0238; /* nxtsym!* */
    v0238 = stack[-4];
    qvalue(elt(env, 22)) = v0238; /* crchar!* */
    v0238 = qvalue(elt(env, 21)); /* nxtsym!* */
    { popv(7); return onevalue(v0238); }

v0242:
    v0238 = qvalue(elt(env, 19)); /* !*adjprec */
    if (v0238 == nil) goto v0127;
    v0240 = elt(env, 20); /* !:int!: */
    v0239 = stack[-1];
    v0238 = qvalue(elt(env, 11)); /* nil */
    v0238 = list2star(v0240, v0239, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    goto v0243;

v0127:
    v0238 = stack[-1];
    goto v0243;

v0166:
    v0239 = stack[-4];
    v0238 = elt(env, 12); /* !\ */
    if (v0239 == v0238) goto v0097;
    v0239 = stack[-4];
    v0238 = elt(env, 13); /* e */
    if (v0239 == v0238) goto v0244;
    v0239 = stack[-4];
    v0238 = elt(env, 14); /* !E */
    v0238 = (v0239 == v0238 ? lisp_true : nil);
    goto v0245;

v0245:
    if (!(v0238 == nil)) goto v0026;

v0004:
    v0238 = stack[-1];
    fn = elt(env, 26); /* reversip!* */
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    v0238 = Lcompress(nil, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[-1] = v0238;
    goto v0023;

v0026:
    v0238 = qvalue(elt(env, 4)); /* t */
    stack[-5] = v0238;
    fn = elt(env, 23); /* readch1 */
    v0239 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[-4] = v0239;
    v0238 = elt(env, 15); /* !- */
    if (v0239 == v0238) goto v0157;
    v0239 = stack[-4];
    v0238 = elt(env, 16); /* !+ */
    if (v0239 == v0238) goto v0049;
    v0239 = stack[-4];
    v0238 = qvalue(elt(env, 3)); /* !$eof!$ */
    if (v0239 == v0238) goto v0246;
    v0238 = stack[-4];
    fn = elt(env, 24); /* id2string */
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    fn = elt(env, 25); /* string!-length */
    v0239 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    v0238 = (Lisp_Object)17; /* 1 */
    v0238 = (v0239 == v0238 ? lisp_true : nil);
    v0238 = (v0238 == nil ? lisp_true : nil);
    goto v0247;

v0247:
    if (!(v0238 == nil)) goto v0004;
    v0238 = stack[-4];
    v0238 = Ldigitp(nil, v0238);
    env = stack[-6];
    if (v0238 == nil) goto v0004;
    v0238 = stack[-4];
    v0238 = ncons(v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[0] = v0238;
    goto v0049;

v0049:
    fn = elt(env, 23); /* readch1 */
    v0238 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[-4] = v0238;
    v0238 = stack[-4];
    fn = elt(env, 24); /* id2string */
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    fn = elt(env, 25); /* string!-length */
    v0239 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    v0238 = (Lisp_Object)17; /* 1 */
    if (!(v0239 == v0238)) goto v0012;
    v0238 = stack[-4];
    v0238 = Ldigitp(nil, v0238);
    env = stack[-6];
    if (v0238 == nil) goto v0012;
    v0239 = stack[-4];
    v0238 = stack[0];
    v0238 = cons(v0239, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[0] = v0238;
    goto v0049;

v0012:
    v0238 = stack[0];
    if (!(v0238 == nil)) goto v0248;
    v0240 = elt(env, 6); /* rlisp */
    v0239 = (Lisp_Object)65; /* 4 */
    v0238 = elt(env, 7); /* "Syntax error: improper number" */
    fn = elt(env, 27); /* rerror */
    v0238 = (*qfnn(fn))(qenv(fn), 3, v0240, v0239, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    goto v0248;

v0248:
    v0238 = stack[0];
    fn = elt(env, 26); /* reversip!* */
    v0238 = (*qfn1(fn))(qenv(fn), v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    v0238 = Lcompress(nil, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[0] = v0238;
    v0238 = stack[-2];
    if (v0238 == nil) goto v0249;
    v0239 = stack[-3];
    v0238 = stack[0];
    v0238 = difference2(v0239, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[-3] = v0238;
    goto v0004;

v0249:
    v0239 = stack[-3];
    v0238 = stack[0];
    v0238 = plus2(v0239, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[-3] = v0238;
    goto v0004;

v0246:
    v0238 = qvalue(elt(env, 4)); /* t */
    goto v0247;

v0157:
    v0238 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v0238;
    goto v0049;

v0244:
    v0238 = qvalue(elt(env, 4)); /* t */
    goto v0245;

v0097:
    fn = elt(env, 23); /* readch1 */
    v0238 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    goto v0080;

v0063:
    v0239 = stack[-4];
    v0238 = elt(env, 9); /* x */
    if (v0239 == v0238) goto v0101;
    v0239 = stack[-4];
    v0238 = elt(env, 10); /* !X */
    v0238 = (v0239 == v0238 ? lisp_true : nil);
    goto v0082;

v0101:
    v0238 = qvalue(elt(env, 4)); /* t */
    goto v0082;

v0200:
    v0238 = stack[-5];
    if (v0238 == nil) goto v0105;
    v0240 = elt(env, 6); /* rlisp */
    v0239 = (Lisp_Object)49; /* 3 */
    v0238 = elt(env, 7); /* "Syntax error: improper number" */
    fn = elt(env, 27); /* rerror */
    v0238 = (*qfnn(fn))(qenv(fn), 3, v0240, v0239, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    goto v0026;

v0105:
    v0238 = qvalue(elt(env, 4)); /* t */
    stack[-5] = v0238;
    goto v0080;

v0010:
    v0238 = qvalue(elt(env, 4)); /* t */
    goto v0046;

v0027:
    v0239 = stack[-4];
    v0238 = stack[-1];
    v0238 = cons(v0239, v0238);
    nil = C_nil;
    if (exception_pending()) goto v0241;
    env = stack[-6];
    stack[-1] = v0238;
    goto v0070;
/* error exit handlers */
v0241:
    popv(7);
    return nil;
}



/* Code for dvfsf_mk2 */

static Lisp_Object MS_CDECL CC_dvfsf_mk2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004, v0023, v0021;
    Lisp_Object v0039, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dvfsf_mk2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dvfsf_mk2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0004 = v0039;
    v0023 = v0001;
    v0021 = v0000;
/* end of prologue */
    return list3(v0021, v0023, v0004);
}



/* Code for quotofd */

static Lisp_Object CC_quotofd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotofd");
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
    stack[-3] = nil;
    goto v0034;

v0034:
    v0168 = stack[-2];
    if (v0168 == nil) goto v0115;
    v0168 = stack[-2];
    if (!consp(v0168)) goto v0065;
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0168 = (consp(v0168) ? nil : lisp_true);
    goto v0021;

v0021:
    if (v0168 == nil) goto v0076;
    stack[0] = stack[-3];
    v0120 = stack[-2];
    v0168 = stack[-1];
    fn = elt(env, 2); /* quotodd */
    v0168 = (*qfn2(fn))(qenv(fn), v0120, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-4];
    {
        Lisp_Object v0017 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0017, v0168);
    }

v0076:
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    stack[0] = qcar(v0168);
    v0168 = stack[-2];
    v0168 = qcar(v0168);
    v0120 = qcdr(v0168);
    v0168 = stack[-1];
    v0120 = CC_quotofd(env, v0120, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-4];
    v0168 = stack[-3];
    v0168 = acons(stack[0], v0120, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0003;
    env = stack[-4];
    stack[-3] = v0168;
    v0168 = stack[-2];
    v0168 = qcdr(v0168);
    stack[-2] = v0168;
    goto v0034;

v0065:
    v0168 = qvalue(elt(env, 1)); /* t */
    goto v0021;

v0115:
    v0168 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0168);
    }
/* error exit handlers */
v0003:
    popv(5);
    return nil;
}



/* Code for mml2om */

static Lisp_Object MS_CDECL CC_mml2om(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0004;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mml2om");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mml2om");
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
    fn = elt(env, 3); /* mml2ir */
    v0004 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-1];
    stack[0] = v0004;
    v0004 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-1];
    v0004 = elt(env, 2); /* "Intermediate representation: " */
    v0004 = Lprinc(nil, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-1];
    v0004 = qvalue(elt(env, 1)); /* t */
    fn = elt(env, 4); /* terpri!* */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-1];
    v0004 = stack[0];
    v0004 = Lprint(nil, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-1];
    v0004 = stack[0];
    fn = elt(env, 5); /* ir2om */
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    v0004 = nil;
    { popv(2); return onevalue(v0004); }
/* error exit handlers */
v0021:
    popv(2);
    return nil;
}



/* Code for chk */

static Lisp_Object CC_chk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042, v0019;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for chk");
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

v0073:
    v0041 = stack[0];
    if (v0041 == nil) goto v0037;
    v0042 = stack[0];
    v0041 = qvalue(elt(env, 1)); /* t */
    if (v0042 == v0041) goto v0011;
    v0041 = stack[0];
    v0041 = qcar(v0041);
    fn = elt(env, 3); /* bsubs */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    stack[-1] = v0041;
    v0041 = stack[-1];
    fn = elt(env, 4); /* freexp */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    if (v0041 == nil) goto v0035;
    v0041 = stack[0];
    v0041 = qcdr(v0041);
    v0041 = CC_chk(env, v0041);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0042 = v0041;
    v0041 = v0042;
    if (v0041 == nil) goto v0045;
    v0041 = v0042;
    v0019 = qvalue(elt(env, 1)); /* t */
    if (v0041 == v0019) goto v0116;
    v0041 = stack[-1];
    popv(3);
    return cons(v0041, v0042);

v0116:
    v0041 = stack[-1];
    popv(3);
    return ncons(v0041);

v0045:
    v0041 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0041); }

v0035:
    v0041 = stack[-1];
    fn = elt(env, 5); /* reval */
    v0042 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[-2];
    v0041 = qvalue(elt(env, 1)); /* t */
    if (v0042 == v0041) goto v0086;
    v0041 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0041); }

v0086:
    v0041 = stack[0];
    v0041 = qcdr(v0041);
    stack[0] = v0041;
    goto v0073;

v0011:
    v0041 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0041); }

v0037:
    v0041 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0041); }
/* error exit handlers */
v0057:
    popv(3);
    return nil;
}



/* Code for scal!*list */

static Lisp_Object CC_scalHlist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for scal*list");
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
    goto v0034;

v0034:
    v0027 = stack[0];
    if (v0027 == nil) goto v0115;
    v0014 = stack[-1];
    v0027 = stack[0];
    v0027 = qcar(v0027);
    fn = elt(env, 1); /* !:times */
    v0014 = (*qfn2(fn))(qenv(fn), v0014, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    v0027 = stack[-2];
    v0027 = cons(v0014, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    stack[-2] = v0027;
    v0027 = stack[0];
    v0027 = qcdr(v0027);
    stack[0] = v0027;
    goto v0034;

v0115:
    v0027 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0027);
    }
/* error exit handlers */
v0048:
    popv(4);
    return nil;
}



/* Code for trwrite */

static Lisp_Object CC_trwrite(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022;
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
    v0022 = stack[0];
    v0022 = qcar(v0022);
    if (!symbolp(v0022)) v0022 = nil;
    else { v0022 = qfastgets(v0022);
           if (v0022 != nil) { v0022 = elt(v0022, 53); /* tracing */
#ifdef RECORD_GET
             if (v0022 == SPID_NOPROP)
                record_get(elt(fastget_names, 53), 0),
                v0022 = nil;
             else record_get(elt(fastget_names, 53), 1),
                v0022 = lisp_true; }
           else record_get(elt(fastget_names, 53), 0); }
#else
             if (v0022 == SPID_NOPROP) v0022 = nil; else v0022 = lisp_true; }}
#endif
    if (v0022 == nil) goto v0071;
    v0022 = elt(env, 2); /* "**in procedure: " */
    v0022 = Lprinc(nil, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0022 = Lprinc(nil, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    v0022 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    stack[0] = v0022;
    goto v0072;

v0072:
    v0022 = stack[0];
    if (v0022 == nil) goto v0069;
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0022 = Lprinc(nil, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    env = stack[-1];
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    stack[0] = v0022;
    goto v0072;

v0069:
    v0022 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0075;
    v0022 = nil;
    { popv(2); return onevalue(v0022); }

v0071:
    v0022 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0022); }
/* error exit handlers */
v0075:
    popv(2);
    return nil;
}



/* Code for sf2mv1 */

static Lisp_Object MS_CDECL CC_sf2mv1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0082, v0087, v0088;
    Lisp_Object fn;
    Lisp_Object v0039, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sf2mv1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sf2mv1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0039,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0039;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */

v0034:
    v0082 = stack[-3];
    if (v0082 == nil) goto v0115;
    v0082 = stack[-3];
    if (!consp(v0082)) goto v0021;
    v0082 = stack[-3];
    v0082 = qcar(v0082);
    v0082 = (consp(v0082) ? nil : lisp_true);
    goto v0023;

v0023:
    if (v0082 == nil) goto v0074;
    stack[0] = stack[-2];
    v0082 = stack[-1];
    v0082 = Llength(nil, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-5];
    fn = elt(env, 3); /* nzeros */
    v0082 = (*qfn1(fn))(qenv(fn), v0082);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-5];
    v0087 = Lappend(nil, stack[0], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-5];
    v0082 = stack[-3];
    v0082 = cons(v0087, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    popv(6);
    return ncons(v0082);

v0074:
    v0082 = stack[-3];
    v0082 = qcar(v0082);
    v0082 = qcar(v0082);
    v0087 = qcar(v0082);
    v0082 = stack[-1];
    v0082 = qcar(v0082);
    if (equal(v0087, v0082)) goto v0119;
    stack[0] = stack[-2];
    v0082 = (Lisp_Object)1; /* 0 */
    v0082 = ncons(v0082);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-5];
    v0082 = Lappend(nil, stack[0], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-5];
    stack[-2] = v0082;
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    stack[-1] = v0082;
    goto v0034;

v0119:
    v0082 = stack[-3];
    v0082 = qcar(v0082);
    stack[-4] = qcdr(v0082);
    stack[0] = stack[-2];
    v0082 = stack[-3];
    v0082 = qcar(v0082);
    v0082 = qcar(v0082);
    v0082 = qcdr(v0082);
    v0082 = ncons(v0082);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-5];
    v0087 = Lappend(nil, stack[0], v0082);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-5];
    v0082 = stack[-1];
    v0082 = qcdr(v0082);
    stack[0] = CC_sf2mv1(env, 3, stack[-4], v0087, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    env = stack[-5];
    v0082 = stack[-3];
    v0088 = qcdr(v0082);
    v0087 = stack[-2];
    v0082 = stack[-1];
    v0082 = CC_sf2mv1(env, 3, v0088, v0087, v0082);
    nil = C_nil;
    if (exception_pending()) goto v0237;
    {
        Lisp_Object v0053 = stack[0];
        popv(6);
        return Lappend(nil, v0053, v0082);
    }

v0021:
    v0082 = qvalue(elt(env, 2)); /* t */
    goto v0023;

v0115:
    v0082 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0082); }
/* error exit handlers */
v0237:
    popv(6);
    return nil;
}



/* Code for dv_skel2factor1 */

static Lisp_Object CC_dv_skel2factor1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0057, v0043;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_skel2factor1");
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
    v0057 = stack[-1];
    if (v0057 == nil) goto v0115;
    v0057 = stack[-1];
    fn = elt(env, 3); /* listp */
    v0057 = (*qfn1(fn))(qenv(fn), v0057);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-3];
    if (v0057 == nil) goto v0074;
    v0057 = stack[-1];
    v0043 = qcar(v0057);
    v0057 = stack[0];
    v0057 = CC_dv_skel2factor1(env, v0043, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-3];
    stack[-2] = v0057;
    v0057 = stack[-1];
    v0043 = qcdr(v0057);
    v0057 = stack[0];
    v0057 = CC_dv_skel2factor1(env, v0043, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-3];
    v0057 = cons(stack[-2], v0057);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    { popv(4); return onevalue(v0057); }

v0074:
    v0043 = stack[-1];
    v0057 = elt(env, 2); /* !~dv */
    if (!(v0043 == v0057)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0057 = stack[0];
    v0057 = qcar(v0057);
    stack[-1] = v0057;
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    if (v0057 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0043 = stack[0];
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    v0057 = qcar(v0057);
    v0057 = Lrplaca(nil, v0043, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-3];
    v0043 = stack[0];
    v0057 = stack[0];
    v0057 = qcdr(v0057);
    v0057 = qcdr(v0057);
    v0057 = Lrplacd(nil, v0043, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0115:
    v0057 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0057); }
/* error exit handlers */
v0103:
    popv(4);
    return nil;
}



/* Code for derivative!-mod!-p!-1 */

static Lisp_Object CC_derivativeKmodKpK1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for derivative-mod-p-1");
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
    v0059 = stack[-2];
    if (!consp(v0059)) goto v0115;
    v0059 = stack[-2];
    v0059 = qcar(v0059);
    v0059 = (consp(v0059) ? nil : lisp_true);
    goto v0031;

v0031:
    if (v0059 == nil) goto v0020;
    v0059 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0059); }

v0020:
    v0059 = stack[-2];
    v0059 = qcar(v0059);
    v0059 = qcar(v0059);
    v0194 = qcar(v0059);
    v0059 = stack[-1];
    if (equal(v0194, v0059)) goto v0027;
    v0059 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v0059); }

v0027:
    v0059 = stack[-2];
    v0059 = qcar(v0059);
    v0059 = qcar(v0059);
    v0194 = qcdr(v0059);
    v0059 = (Lisp_Object)17; /* 1 */
    if (v0194 == v0059) goto v0117;
    v0194 = stack[-1];
    v0059 = stack[-2];
    v0059 = qcar(v0059);
    v0059 = qcar(v0059);
    v0059 = qcdr(v0059);
    v0059 = (Lisp_Object)((int32_t)(v0059) - 0x10);
    fn = elt(env, 3); /* mksp */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0194, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-4];
    v0059 = stack[-2];
    v0059 = qcar(v0059);
    v0194 = qcdr(v0059);
    v0059 = stack[-2];
    v0059 = qcar(v0059);
    v0059 = qcar(v0059);
    v0059 = qcdr(v0059);
    v0059 = Lmodular_number(nil, v0059);
    env = stack[-4];
    fn = elt(env, 4); /* multiply!-by!-constant!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v0194, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-4];
    v0059 = stack[-2];
    v0194 = qcdr(v0059);
    v0059 = stack[-1];
    v0059 = CC_derivativeKmodKpK1(env, v0194, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-4];
    {
        Lisp_Object v0170 = stack[-3];
        Lisp_Object v0060 = stack[0];
        popv(5);
        fn = elt(env, 5); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0170, v0060, v0059);
    }

v0117:
    v0059 = stack[-2];
    v0059 = qcar(v0059);
    v0059 = qcdr(v0059);
    { popv(5); return onevalue(v0059); }

v0115:
    v0059 = qvalue(elt(env, 1)); /* t */
    goto v0031;
/* error exit handlers */
v0171:
    popv(5);
    return nil;
}



/* Code for lalr_print_action_map */

static Lisp_Object MS_CDECL CC_lalr_print_action_map(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lalr_print_action_map");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_print_action_map");
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
    v0045 = elt(env, 1); /* "Action map:" */
    v0045 = Lprinc(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0045 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0045 = qvalue(elt(env, 2)); /* action_map */
    stack[-2] = v0045;
    goto v0115;

v0115:
    v0045 = stack[-2];
    if (v0045 == nil) goto v0031;
    v0045 = stack[-2];
    v0045 = qcar(v0045);
    stack[-1] = v0045;
    v0045 = stack[-1];
    v0045 = qcdr(v0045);
    v0045 = Lprin(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0045 = elt(env, 4); /* ":" */
    v0045 = Lprinc(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    stack[0] = (Lisp_Object)193; /* 12 */
    v0045 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0045 = difference2(stack[0], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0045 = Lxtab(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0045 = stack[-1];
    v0045 = qcar(v0045);
    v0045 = Lprin(nil, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0045 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-3];
    v0045 = stack[-2];
    v0045 = qcdr(v0045);
    stack[-2] = v0045;
    goto v0115;

v0031:
    v0045 = nil;
    { popv(4); return onevalue(v0045); }
/* error exit handlers */
v0116:
    popv(4);
    return nil;
}



/* Code for cl_simpl */

static Lisp_Object MS_CDECL CC_cl_simpl(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0042, v0019, v0192;
    Lisp_Object fn;
    Lisp_Object v0039, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_simpl");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0039 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_simpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0039,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0039);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0039;
    v0042 = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0041 = qvalue(elt(env, 1)); /* !*rlsism */
    if (v0041 == nil) goto v0013;
    v0041 = v0042;
    fn = elt(env, 6); /* cl_sitheo */
    v0041 = (*qfn1(fn))(qenv(fn), v0041);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-5];
    v0042 = v0041;
    v0019 = v0042;
    v0041 = elt(env, 3); /* inctheo */
    if (v0019 == v0041) goto v0055;
    stack[-4] = elt(env, 4); /* and */
    stack[-1] = v0042;
    stack[0] = qvalue(elt(env, 2)); /* nil */
    v0041 = stack[-2];
    v0041 = add1(v0041);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-5];
    fn = elt(env, 7); /* rl_smupdknowl */
    v0041 = (*qfnn(fn))(qenv(fn), 4, stack[-4], stack[-1], stack[0], v0041);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-5];
    v0042 = v0041;
    v0019 = v0042;
    v0041 = elt(env, 5); /* false */
    if (v0019 == v0041) goto v0051;
    v0192 = stack[-3];
    v0019 = v0042;
    v0042 = stack[-2];
    v0041 = qvalue(elt(env, 2)); /* nil */
    {
        popv(6);
        fn = elt(env, 8); /* cl_simpl1 */
        return (*qfnn(fn))(qenv(fn), 4, v0192, v0019, v0042, v0041);
    }

v0051:
    v0041 = elt(env, 3); /* inctheo */
    { popv(6); return onevalue(v0041); }

v0055:
    v0041 = elt(env, 3); /* inctheo */
    { popv(6); return onevalue(v0041); }

v0013:
    v0192 = stack[-3];
    v0019 = qvalue(elt(env, 2)); /* nil */
    v0042 = stack[-2];
    v0041 = qvalue(elt(env, 2)); /* nil */
    {
        popv(6);
        fn = elt(env, 8); /* cl_simpl1 */
        return (*qfnn(fn))(qenv(fn), 4, v0192, v0019, v0042, v0041);
    }
/* error exit handlers */
v0102:
    popv(6);
    return nil;
}



/* Code for ibalp_recalcv */

static Lisp_Object CC_ibalp_recalcv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0204, v0169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_recalcv");
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
    v0204 = v0000;
/* end of prologue */
    stack[-2] = v0204;
    goto v0036;

v0036:
    v0204 = stack[-2];
    if (v0204 == nil) goto v0115;
    v0204 = stack[-2];
    v0204 = qcar(v0204);
    stack[-1] = v0204;
    v0204 = stack[-1];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    stack[0] = qcdr(v0204);
    v0204 = stack[-1];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0169 = qcar(v0204);
    v0204 = elt(env, 2); /* 0.05 */
    v0204 = difference2(v0169, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v0204 = (*qfn2(fn))(qenv(fn), stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-3];
    v0204 = stack[-1];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    stack[0] = qcdr(v0204);
    v0204 = stack[-1];
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0204 = qcdr(v0204);
    v0169 = qcar(v0204);
    v0204 = elt(env, 2); /* 0.05 */
    v0204 = difference2(v0169, v0204);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v0204 = (*qfn2(fn))(qenv(fn), stack[0], v0204);
    nil = C_nil;
    if (exception_pending()) goto v0194;
    env = stack[-3];
    v0204 = stack[-2];
    v0204 = qcdr(v0204);
    stack[-2] = v0204;
    goto v0036;

v0115:
    v0204 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0204); }
/* error exit handlers */
v0194:
    popv(4);
    return nil;
}



/* Code for vdp_zero!? */

static Lisp_Object CC_vdp_zeroW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vdp_zero?");
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
    v0036 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* vdp_poly */
    v0036 = (*qfn1(fn))(qenv(fn), v0036);
    errexit();
    v0036 = (v0036 == nil ? lisp_true : nil);
    return onevalue(v0036);
}



/* Code for omsir */

static Lisp_Object MS_CDECL CC_omsir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omsir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for omsir");
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
    stack[-1] = nil;
    v0095 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v0095;
    v0180 = qvalue(elt(env, 2)); /* atts */
    v0095 = elt(env, 3); /* name */
    fn = elt(env, 12); /* find */
    v0095 = (*qfn2(fn))(qenv(fn), v0180, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0095 = Lintern(nil, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    stack[-5] = v0095;
    v0180 = qvalue(elt(env, 2)); /* atts */
    v0095 = elt(env, 4); /* cd */
    fn = elt(env, 12); /* find */
    v0095 = (*qfn2(fn))(qenv(fn), v0180, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0095 = Lintern(nil, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    stack[-3] = v0095;
    v0095 = stack[-5];
    v0180 = Lexplode(nil, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0095 = elt(env, 5); /* (v e c t o r) */
    if (equal(v0180, v0095)) goto v0068;
    v0095 = stack[-5];
    v0180 = Lintern(nil, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0095 = qvalue(elt(env, 7)); /* mmleq!* */
    v0095 = Lmember(nil, v0180, v0095);
    stack[-4] = v0095;
    goto v0117;

v0117:
    v0095 = stack[-4];
    if (!(v0095 == nil)) goto v0050;
    v0180 = stack[-5];
    v0095 = qvalue(elt(env, 8)); /* special_cases!* */
    v0095 = Lassoc(nil, v0180, v0095);
    stack[-4] = v0095;
    if (v0095 == nil) goto v0060;
    v0095 = stack[-4];
    v0095 = Lreverse(nil, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0095 = qcar(v0095);
    stack[-2] = v0095;
    v0095 = stack[-2];
    if (v0095 == nil) goto v0019;
    v0095 = stack[-2];
    v0095 = ncons(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    stack[-2] = v0095;
    goto v0019;

v0019:
    v0095 = stack[-4];
    v0095 = Lreverse(nil, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0095 = qcdr(v0095);
    stack[0] = qcar(v0095);
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    v0095 = Lreverse(nil, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0095 = qcdr(v0095);
    v0095 = qcdr(v0095);
    v0095 = Lreverse(nil, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    v0095 = cons(stack[0], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0157;
    env = stack[-6];
    stack[-4] = v0095;
    goto v0050;

v0050:
    v0095 = stack[-4];
    if (v0095 == nil) goto v0053;
    v0095 = stack[-4];
    v0180 = qcar(v0095);
    v0095 = qvalue(elt(env, 10)); /* valid_om!* */
    v0095 = Lassoc(nil, v0180, v0095);
    stack[-1] = v0095;
    goto v0053;

v0053:
    v0095 = stack[-1];
    if (v0095 == nil) goto v0100;
    v0095 = stack[-1];
    v0095 = qcdr(v0095);
    v0095 = qcar(v0095);
    stack[-1] = v0095;
    goto v0100;

v0100:
    v0095 = stack[-4];
    if (v0095 == nil) goto v0098;
    v0180 = stack[-3];
    v0095 = stack[-1];
    v0095 = (v0095 == nil ? lisp_true : nil);
    v0095 = (equal(v0180, v0095) ? lisp_true : nil);
    goto v0097;

v0097:
    if (v0095 == nil) goto v0177;
    v0095 = stack[-5];
    {
        popv(7);
        fn = elt(env, 13); /* encodeir */
        return (*qfn1(fn))(qenv(fn), v0095);
    }

v0177:
    v0095 = stack[-4];
    v0180 = qcar(v0095);
    v0095 = stack[-2];
    popv(7);
    return list2(v0180, v0095);

v0098:
    v0095 = qvalue(elt(env, 11)); /* t */
    goto v0097;

v0060:
    v0180 = stack[-5];
    v0095 = qvalue(elt(env, 9)); /* special_cases2!* */
    v0180 = Lassoc(nil, v0180, v0095);
    v0095 = v0180;
    if (v0180 == nil) goto v0050;
    v0180 = v0095;
    v0180 = qcdr(v0180);
    v0180 = qcar(v0180);
    v0095 = qcdr(v0095);
    v0095 = qcdr(v0095);
    {
        popv(7);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v0180, v0095);
    }

v0068:
    v0095 = elt(env, 6); /* (vectorml linalg1) */
    stack[-4] = v0095;
    goto v0117;
/* error exit handlers */
v0157:
    popv(7);
    return nil;
}



/* Code for !*wedgepf2pf */

static Lisp_Object CC_Hwedgepf2pf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0027, v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *wedgepf2pf");
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
    goto v0036;

v0036:
    v0068 = stack[0];
    if (v0068 == nil) goto v0031;
    v0068 = stack[0];
    v0068 = qcar(v0068);
    v0068 = qcar(v0068);
    fn = elt(env, 1); /* mkuwedge */
    v0014 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    v0068 = stack[0];
    v0068 = qcar(v0068);
    v0027 = qcdr(v0068);
    v0068 = stack[-1];
    v0068 = acons(v0014, v0027, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-2];
    stack[-1] = v0068;
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    stack[0] = v0068;
    goto v0036;

v0031:
    v0068 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0068);
    }
/* error exit handlers */
v0118:
    popv(3);
    return nil;
}



/* Code for rd!:plus */

static Lisp_Object CC_rdTplus(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0260, v0261, v0188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:plus");
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
    stack[-2] = v0001;
    stack[0] = v0000;
/* end of prologue */
    v0260 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v0260;
    v0260 = qvalue(elt(env, 2)); /* !*!*roundbf */
    if (v0260 == nil) goto v0049;
    v0260 = qvalue(elt(env, 1)); /* nil */
    goto v0080;

v0080:
    if (v0260 == nil) goto v0078;
    v0261 = elt(env, 3); /* !:rd!: */
    v0260 = stack[-1];
    popv(5);
    return cons(v0261, v0260);

v0078:
    v0261 = stack[0];
    v0260 = stack[-2];
    fn = elt(env, 6); /* convprc2 */
    v0260 = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    stack[-3] = v0260;
    v0260 = qvalue(elt(env, 4)); /* yy!! */
    stack[-2] = v0260;
    v0260 = stack[-3];
    if (!consp(v0260)) goto v0102;
    v0261 = stack[-3];
    v0260 = stack[-2];
    fn = elt(env, 7); /* plubf */
    v0260 = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    goto v0120;

v0120:
    stack[0] = v0260;
    v0188 = stack[0];
    v0261 = stack[-3];
    v0260 = stack[-2];
    fn = elt(env, 8); /* rdzchk */
    v0260 = (*qfnn(fn))(qenv(fn), 3, v0188, v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 9); /* mkround */
        return (*qfn1(fn))(qenv(fn), v0260);
    }

v0102:
    stack[-1] = elt(env, 5); /* plus2 */
    v0260 = stack[-3];
    stack[0] = Lmkquote(nil, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    v0260 = stack[-2];
    v0260 = Lmkquote(nil, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    v0261 = list3(stack[-1], stack[0], v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    v0260 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 10); /* errorset!* */
    v0260 = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    stack[-1] = v0260;
    v0260 = stack[-1];
    fn = elt(env, 11); /* errorp */
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    if (v0260 == nil) goto v0109;
    fn = elt(env, 12); /* rndbfon */
    v0260 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    v0260 = stack[-3];
    v0260 = Lfloatp(nil, v0260);
    env = stack[-4];
    if (v0260 == nil) goto v0263;
    v0260 = stack[-3];
    fn = elt(env, 13); /* fl2bf */
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    stack[0] = v0260;
    goto v0199;

v0199:
    stack[-3] = stack[0];
    v0260 = stack[-2];
    v0260 = Lfloatp(nil, v0260);
    env = stack[-4];
    if (v0260 == nil) goto v0230;
    v0260 = stack[-2];
    fn = elt(env, 13); /* fl2bf */
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    goto v0264;

v0264:
    stack[-2] = v0260;
    fn = elt(env, 7); /* plubf */
    v0260 = (*qfn2(fn))(qenv(fn), stack[0], v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    goto v0120;

v0230:
    v0260 = stack[-2];
    if (!consp(v0260)) goto v0161;
    v0260 = stack[-2];
    goto v0091;

v0091:
    fn = elt(env, 14); /* normbf */
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    goto v0264;

v0161:
    v0260 = stack[-2];
    v0260 = integerp(v0260);
    if (v0260 == nil) goto v0112;
    v0188 = elt(env, 3); /* !:rd!: */
    v0261 = stack[-2];
    v0260 = (Lisp_Object)1; /* 0 */
    v0260 = list2star(v0188, v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    goto v0091;

v0112:
    v0260 = stack[-2];
    fn = elt(env, 15); /* read!:num */
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    goto v0091;

v0263:
    v0260 = stack[-3];
    if (!consp(v0260)) goto v0265;
    v0260 = stack[-3];
    goto v0178;

v0178:
    fn = elt(env, 14); /* normbf */
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    stack[0] = v0260;
    goto v0199;

v0265:
    v0260 = stack[-3];
    v0260 = integerp(v0260);
    if (v0260 == nil) goto v0097;
    v0188 = elt(env, 3); /* !:rd!: */
    v0261 = stack[-3];
    v0260 = (Lisp_Object)1; /* 0 */
    v0260 = list2star(v0188, v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    goto v0178;

v0097:
    v0260 = stack[-3];
    fn = elt(env, 15); /* read!:num */
    v0260 = (*qfn1(fn))(qenv(fn), v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    goto v0178;

v0109:
    v0260 = stack[-1];
    v0260 = qcar(v0260);
    goto v0120;

v0049:
    v0260 = stack[0];
    v0260 = qcdr(v0260);
    if (!consp(v0260)) goto v0023;
    v0260 = qvalue(elt(env, 1)); /* nil */
    goto v0080;

v0023:
    v0260 = stack[-2];
    v0260 = qcdr(v0260);
    if (!consp(v0260)) goto v0040;
    v0260 = qvalue(elt(env, 1)); /* nil */
    goto v0080;

v0040:
    v0260 = stack[0];
    v0261 = qcdr(v0260);
    v0260 = stack[-2];
    v0260 = qcdr(v0260);
    fn = elt(env, 16); /* safe!-fp!-plus */
    v0260 = (*qfn2(fn))(qenv(fn), v0261, v0260);
    nil = C_nil;
    if (exception_pending()) goto v0262;
    env = stack[-4];
    stack[-1] = v0260;
    goto v0080;
/* error exit handlers */
v0262:
    popv(5);
    return nil;
}



/* Code for map__edges */

static Lisp_Object CC_map__edges(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0075, v0116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for map__edges");
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
    goto v0034;

v0034:
    v0075 = stack[0];
    if (v0075 == nil) goto v0071;
    v0075 = stack[0];
    v0116 = qcar(v0075);
    v0075 = stack[-1];
    v0075 = cons(v0116, v0075);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    stack[-1] = v0075;
    v0075 = stack[0];
    v0075 = qcdr(v0075);
    stack[0] = v0075;
    goto v0034;

v0071:
    v0075 = qvalue(elt(env, 1)); /* nil */
    v0116 = v0075;
    goto v0031;

v0031:
    v0075 = stack[-1];
    if (v0075 == nil) { popv(3); return onevalue(v0116); }
    v0075 = stack[-1];
    v0075 = qcar(v0075);
    fn = elt(env, 2); /* union_edges */
    v0075 = (*qfn2(fn))(qenv(fn), v0075, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0116 = v0075;
    v0075 = stack[-1];
    v0075 = qcdr(v0075);
    stack[-1] = v0075;
    goto v0031;
/* error exit handlers */
v0038:
    popv(3);
    return nil;
}



/* Code for setk */

static Lisp_Object CC_setk(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0193, v0201, v0171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setk");
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
    v0201 = v0000;
/* end of prologue */
    v0193 = v0201;
    if (!consp(v0193)) goto v0103;
    v0193 = v0201;
    v0171 = qcar(v0193);
    v0193 = elt(env, 1); /* evalargfn */
    v0193 = get(v0171, v0193);
    env = stack[-2];
    v0171 = v0193;
    v0193 = v0171;
    if (v0193 == nil) goto v0025;
    v0193 = v0201;
    stack[-1] = qcar(v0193);
    v0193 = v0171;
    v0201 = qcdr(v0201);
    v0193 = Lapply1(nil, v0193, v0201);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0201 = cons(stack[-1], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0193 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v0201, v0193);
    }

v0025:
    v0193 = v0201;
    v0193 = qcar(v0193);
    if (!symbolp(v0193)) v0171 = nil;
    else { v0171 = qfastgets(v0193);
           if (v0171 != nil) { v0171 = elt(v0171, 2); /* rtype */
#ifdef RECORD_GET
             if (v0171 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0171 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0171 == SPID_NOPROP) v0171 = nil; }}
#endif
    v0193 = elt(env, 2); /* matrix */
    if (v0171 == v0193) goto v0052;
    v0193 = v0201;
    stack[-1] = qcar(v0193);
    v0193 = v0201;
    v0193 = qcdr(v0193);
    fn = elt(env, 4); /* revlis */
    v0193 = (*qfn1(fn))(qenv(fn), v0193);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0201 = cons(stack[-1], v0193);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    v0193 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v0201, v0193);
    }

v0052:
    v0193 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v0201, v0193);
    }

v0103:
    v0193 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* setk0 */
        return (*qfn2(fn))(qenv(fn), v0201, v0193);
    }
/* error exit handlers */
v0058:
    popv(3);
    return nil;
}



/* Code for lalr_print_firsts */

static Lisp_Object CC_lalr_print_firsts(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0119, v0086;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_print_firsts");
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
    v0119 = elt(env, 1); /* "FIRST sets for each non-terminal:" */
    v0119 = Lprinc(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0119 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0119 = stack[0];
    stack[-2] = v0119;
    goto v0080;

v0080:
    v0119 = stack[-2];
    if (v0119 == nil) goto v0115;
    v0119 = stack[-2];
    v0119 = qcar(v0119);
    stack[-1] = v0119;
    v0119 = stack[-1];
    fn = elt(env, 6); /* lalr_prin_symbol */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0119 = elt(env, 3); /* ": " */
    v0119 = Lprinc(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    stack[0] = (Lisp_Object)241; /* 15 */
    v0119 = Lposn(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0119 = difference2(stack[0], v0119);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0119 = Lxtab(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0086 = stack[-1];
    v0119 = elt(env, 4); /* lalr_first */
    v0119 = get(v0086, v0119);
    env = stack[-3];
    stack[-1] = v0119;
    goto v0067;

v0067:
    v0119 = stack[-1];
    if (v0119 == nil) goto v0015;
    v0119 = stack[-1];
    v0119 = qcar(v0119);
    stack[0] = v0119;
    v0119 = elt(env, 5); /* " " */
    v0119 = Lprinc(nil, v0119);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0119 = stack[0];
    fn = elt(env, 6); /* lalr_prin_symbol */
    v0119 = (*qfn1(fn))(qenv(fn), v0119);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0119 = stack[-1];
    v0119 = qcdr(v0119);
    stack[-1] = v0119;
    goto v0067;

v0015:
    v0119 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0120;
    env = stack[-3];
    v0119 = stack[-2];
    v0119 = qcdr(v0119);
    stack[-2] = v0119;
    goto v0080;

v0115:
    v0119 = nil;
    { popv(4); return onevalue(v0119); }
/* error exit handlers */
v0120:
    popv(4);
    return nil;
}



/* Code for sfto_ucontentf1 */

static Lisp_Object CC_sfto_ucontentf1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0002, v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_ucontentf1");
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
    goto v0071;

v0071:
    v0002 = stack[-1];
    if (!consp(v0002)) goto v0070;
    v0002 = stack[-1];
    v0002 = qcar(v0002);
    v0002 = (consp(v0002) ? nil : lisp_true);
    goto v0032;

v0032:
    if (v0002 == nil) goto v0068;
    v0002 = qvalue(elt(env, 1)); /* t */
    goto v0004;

v0004:
    if (v0002 == nil) goto v0116;
    v0002 = stack[-1];
    v0003 = v0002;
    goto v0115;

v0115:
    v0002 = stack[-2];
    if (v0002 == nil) { popv(4); return onevalue(v0003); }
    v0002 = stack[-2];
    v0002 = qcar(v0002);
    fn = elt(env, 2); /* sfto_gcdf!* */
    v0002 = (*qfn2(fn))(qenv(fn), v0002, v0003);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    v0003 = v0002;
    v0002 = stack[-2];
    v0002 = qcdr(v0002);
    stack[-2] = v0002;
    goto v0115;

v0116:
    v0002 = stack[-1];
    v0002 = qcar(v0002);
    v0003 = qcdr(v0002);
    v0002 = stack[-2];
    v0002 = cons(v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    stack[-2] = v0002;
    v0002 = stack[-1];
    v0002 = qcdr(v0002);
    stack[-1] = v0002;
    goto v0071;

v0068:
    v0002 = stack[-1];
    v0002 = qcar(v0002);
    v0002 = qcar(v0002);
    v0003 = qcar(v0002);
    v0002 = stack[0];
    v0002 = Lneq(nil, v0003, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-3];
    goto v0004;

v0070:
    v0002 = qvalue(elt(env, 1)); /* t */
    goto v0032;
/* error exit handlers */
v0200:
    popv(4);
    return nil;
}



/* Code for qqe_eta!-in!-term */

static Lisp_Object CC_qqe_etaKinKterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0250;
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
    v0018 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v0018;
    v0018 = stack[0];
    if (!consp(v0018)) goto v0115;
    v0018 = stack[0];
    fn = elt(env, 3); /* qqe_op */
    v0250 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    v0018 = elt(env, 2); /* (lhead rhead) */
    v0018 = Lmemq(nil, v0250, v0018);
    if (v0018 == nil) goto v0033;
    v0018 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_eta!-in!-term1 */
        return (*qfn1(fn))(qenv(fn), v0018);
    }

v0033:
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    stack[0] = v0018;
    goto v0117;

v0117:
    v0018 = stack[0];
    if (v0018 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0018 = stack[-1];
    if (!(v0018 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0018 = stack[0];
    v0018 = qcar(v0018);
    if (!consp(v0018)) goto v0075;
    v0018 = stack[0];
    v0018 = qcar(v0018);
    fn = elt(env, 3); /* qqe_op */
    v0250 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    v0018 = elt(env, 2); /* (lhead rhead) */
    v0018 = Lmemq(nil, v0250, v0018);
    if (v0018 == nil) goto v0086;
    v0018 = stack[0];
    v0018 = qcar(v0018);
    fn = elt(env, 4); /* qqe_eta!-in!-term1 */
    v0018 = (*qfn1(fn))(qenv(fn), v0018);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    stack[-1] = v0018;
    goto v0075;

v0075:
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    stack[0] = v0018;
    goto v0117;

v0086:
    v0018 = stack[0];
    v0018 = qcar(v0018);
    v0018 = CC_qqe_etaKinKterm(env, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-2];
    stack[-1] = v0018;
    goto v0075;

v0115:
    v0018 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0018); }
/* error exit handlers */
v0085:
    popv(3);
    return nil;
}



setup_type const u17_setup[] =
{
    {"pappend",                 too_few_2,      CC_pappend,    wrong_no_2},
    {"ratn",                    CC_ratn,        too_many_1,    wrong_no_1},
    {"ra_budan-0-1",            CC_ra_budanK0K1,too_many_1,    wrong_no_1},
    {"resetparser",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_resetparser},
    {"cl_fvarl1",               CC_cl_fvarl1,   too_many_1,    wrong_no_1},
    {"powers3",                 too_few_2,      CC_powers3,    wrong_no_2},
    {"expnd1",                  CC_expnd1,      too_many_1,    wrong_no_1},
    {"tobvarir",                CC_tobvarir,    too_many_1,    wrong_no_1},
    {"simprecip",               CC_simprecip,   too_many_1,    wrong_no_1},
    {"rdcos*",                  CC_rdcosH,      too_many_1,    wrong_no_1},
    {"one-entry-listp",         too_few_2,      CC_oneKentryKlistp,wrong_no_2},
    {"mv2sf1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mv2sf1},
    {"rnminusp:",               CC_rnminuspT,   too_many_1,    wrong_no_1},
    {"polynommultiplybyvariable",too_few_2,     CC_polynommultiplybyvariable,wrong_no_2},
    {"mchkopt1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchkopt1},
    {"remove-free-vars*",       CC_removeKfreeKvarsH,too_many_1,wrong_no_1},
    {"sf2ss",                   CC_sf2ss,       too_many_1,    wrong_no_1},
    {"ibalp_var-unsatlist",     too_few_2,      CC_ibalp_varKunsatlist,wrong_no_2},
    {"sfto_dprpartksf",         CC_sfto_dprpartksf,too_many_1, wrong_no_1},
    {"ev_tdeg",                 CC_ev_tdeg,     too_many_1,    wrong_no_1},
    {"dipilcomb1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipilcomb1},
    {"bcfd",                    CC_bcfd,        too_many_1,    wrong_no_1},
    {"freeoffl",                too_few_2,      CC_freeoffl,   wrong_no_2},
    {"cut:mt",                  too_few_2,      CC_cutTmt,     wrong_no_2},
    {"cstimes",                 too_few_2,      CC_cstimes,    wrong_no_2},
    {"assert_uninstall_all",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_uninstall_all},
    {"general-reduce-degree-mod-p",too_few_2,   CC_generalKreduceKdegreeKmodKp,wrong_no_2},
    {"mksetq",                  too_few_2,      CC_mksetq,     wrong_no_2},
    {"defineargs",              too_few_2,      CC_defineargs, wrong_no_2},
    {"polynomheadreduceby",     too_few_2,      CC_polynomheadreduceby,wrong_no_2},
    {"revalx",                  CC_revalx,      too_many_1,    wrong_no_1},
    {"squared+matrix+p",        CC_squaredLmatrixLp,too_many_1,wrong_no_1},
    {"sq2sstm",                 too_few_2,      CC_sq2sstm,    wrong_no_2},
    {"token-number",            CC_tokenKnumber,too_many_1,    wrong_no_1},
    {"dvfsf_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_dvfsf_mk2},
    {"quotofd",                 too_few_2,      CC_quotofd,    wrong_no_2},
    {"mml2om",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mml2om},
    {"chk",                     CC_chk,         too_many_1,    wrong_no_1},
    {"scal*list",               too_few_2,      CC_scalHlist,  wrong_no_2},
    {"trwrite",                 CC_trwrite,     too_many_1,    wrong_no_1},
    {"sf2mv1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_sf2mv1},
    {"dv_skel2factor1",         too_few_2,      CC_dv_skel2factor1,wrong_no_2},
    {"derivative-mod-p-1",      too_few_2,      CC_derivativeKmodKpK1,wrong_no_2},
    {"lalr_print_action_map",   wrong_no_na,    wrong_no_nb,   (n_args *)CC_lalr_print_action_map},
    {"cl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_simpl},
    {"ibalp_recalcv",           CC_ibalp_recalcv,too_many_1,   wrong_no_1},
    {"vdp_zero?",               CC_vdp_zeroW,   too_many_1,    wrong_no_1},
    {"omsir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omsir},
    {"*wedgepf2pf",             CC_Hwedgepf2pf, too_many_1,    wrong_no_1},
    {"rd:plus",                 too_few_2,      CC_rdTplus,    wrong_no_2},
    {"map__edges",              CC_map__edges,  too_many_1,    wrong_no_1},
    {"setk",                    too_few_2,      CC_setk,       wrong_no_2},
    {"lalr_print_firsts",       CC_lalr_print_firsts,too_many_1,wrong_no_1},
    {"sfto_ucontentf1",         too_few_2,      CC_sfto_ucontentf1,wrong_no_2},
    {"qqe_eta-in-term",         CC_qqe_etaKinKterm,too_many_1, wrong_no_1},
    {NULL, (one_args *)"u17", (two_args *)"2438 9586626 5554363", 0}
};

/* end of generated code */
