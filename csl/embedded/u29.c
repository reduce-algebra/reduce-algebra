
/* $destdir/generated-c\u29.c Machine generated C code */

/* Signature: 00000000 20-Aug-2010 */

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
#if !defined UNDER_CE && ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
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
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? 153600 : 2048)
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
#define PAGE_MASK               ((((uint32_t)1) << (32-PAGE_BITS)) - 1)
#define OFFSET_MASK             ((((uint32_t)1) << PAGE_BITS) - 1)
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
#define font_of_char(n)  (((int32_t)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32_t)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0xffff)
#else
#define code_of_char(n)  ((char)(((int32_t)(n) >>  8) & 0xff))
#endif
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 24) |                  \
    (((uint32_t)(bits)) << 16) | (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
 
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
#define UNWIND_ERROR      0x100       
#define UNWIND_UNWIND     0x200       
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
extern Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
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
#define HEADLINE_FLAG 0x08
#define MESSAGES_FLAG 0x10
#define ALWAYS_NOISY  0x20
#define verbos_flag (miscflags & GC_MSG_BITS)
 
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
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
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
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow");
#else
#define if_check_stack
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
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol;
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
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int fasl_output_file, output_directory;
extern FILE *binary_read_file;
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
extern CSLbool always_noisy;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
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
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
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
                         Lisp_Object env, Lisp_Object fname);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name);
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
#define validate_string(a) 0
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
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
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
                            Lisp_Object env, int compilerp);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object resource_exceeded();
extern int time_base,  space_base,  io_base,  errors_base;
extern int time_now,   space_now,   io_now,   errors_now;
extern int time_limit, space_limit, io_limit, errors_limit;
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
#define _pi       3.14159265358979323846
#define _half_pi  1.57079632679489661923
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
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
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
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
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
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
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
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
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
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
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


/* Code for matrixrd */

static Lisp_Object MS_CDECL CC_matrixrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrd");
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
    v15 = (Lisp_Object)1; /* 0 */
    stack[-1] = v15;
    v15 = nil;
    stack[0] = v15;
    goto v17;

v17:
    v16 = stack[-1];
    v15 = (Lisp_Object)1; /* 0 */
    if (v16 == v15) goto v18;
    v16 = elt(env, 6); /* mat */
    v15 = stack[0];
    v15 = cons(v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 7); /* aeval */
        return (*qfn1(fn))(qenv(fn), v15);
    }

v18:
    fn = elt(env, 8); /* lex */
    v15 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v16 = qvalue(elt(env, 2)); /* char */
    v15 = elt(env, 3); /* (m a t r i x r o w) */
    if (equal(v16, v15)) goto v20;
    v15 = (Lisp_Object)17; /* 1 */
    stack[-1] = v15;
    goto v17;

v20:
    fn = elt(env, 9); /* matrixrowrd */
    v15 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v16 = v15;
    v15 = stack[0];
    if (v15 == nil) goto v21;
    v15 = v16;
    v15 = ncons(v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v15 = Lappend(nil, stack[0], v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    stack[0] = v15;
    goto v22;

v22:
    v16 = qvalue(elt(env, 2)); /* char */
    v15 = elt(env, 4); /* (!/ m a t r i x r o w) */
    if (equal(v16, v15)) goto v17;
    v16 = elt(env, 5); /* "</matrixrow>" */
    v15 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 10); /* errorml */
    v15 = (*qfn2(fn))(qenv(fn), v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    goto v17;

v21:
    v15 = v16;
    v15 = ncons(v15);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    stack[0] = v15;
    goto v22;
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for prlist */

static Lisp_Object CC_prlist(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prlist");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v23;
/* end of prologue */
    v10 = nil;
    goto v27;

v27:
    v26 = stack[0];
    if (v26 == nil) goto v28;
    v26 = stack[0];
    v26 = qcar(v26);
    v26 = Lconsp(nil, v26);
    env = stack[-1];
    if (v26 == nil) goto v29;
    v26 = stack[0];
    v26 = qcar(v26);
    v26 = cons(v26, v10);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    v10 = v26;
    v26 = stack[0];
    v26 = qcdr(v26);
    stack[0] = v26;
    goto v27;

v29:
    v26 = stack[0];
    v26 = qcdr(v26);
    stack[0] = v26;
    goto v27;

v28:
    v26 = v10;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v26);
    }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for suchp */

static Lisp_Object CC_suchp(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for suchp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v23;
/* end of prologue */
    v32 = v33;
    if (!consp(v32)) goto v34;
    v32 = v33;
    v32 = qcar(v32);
    v33 = elt(env, 2); /* such!-that */
    v32 = (v32 == v33 ? lisp_true : nil);
    return onevalue(v32);

v34:
    v32 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v32);
}



/* Code for diplmon2sq */

static Lisp_Object CC_diplmon2sq(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diplmon2sq");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v24 = v2;
    v25 = v23;
/* end of prologue */
    stack[0] = v25;
    v25 = v24;
    v24 = qvalue(elt(env, 1)); /* dipvars!* */
    fn = elt(env, 2); /* dipev2f */
    v25 = (*qfn2(fn))(qenv(fn), v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    v24 = (Lisp_Object)17; /* 1 */
    v24 = cons(v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    {
        Lisp_Object v29 = stack[0];
        popv(2);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v29, v24);
    }
/* error exit handlers */
v39:
    popv(2);
    return nil;
}



/* Code for gpexpp */

static Lisp_Object CC_gpexpp(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpexpp");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v23;
/* end of prologue */

v27:
    v59 = stack[0];
    if (!consp(v59)) goto v28;
    v59 = stack[0];
    v60 = qcar(v59);
    v59 = elt(env, 2); /* (!:rd!: !:cr!: !:crn!: !:gi!:) */
    v59 = Lmemq(nil, v60, v59);
    if (v59 == nil) goto v61;
    v59 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v59); }

v61:
    v59 = stack[0];
    v60 = qcar(v59);
    v59 = elt(env, 4); /* plus */
    if (v60 == v59) goto v62;
    v59 = stack[0];
    v60 = qcar(v59);
    v59 = elt(env, 5); /* (minus recip) */
    v59 = Lmemq(nil, v60, v59);
    if (v59 == nil) goto v63;
    v59 = stack[0];
    v60 = Llength(nil, v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v59 = (Lisp_Object)33; /* 2 */
    if (v60 == v59) goto v65;
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }

v65:
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcar(v59);
    stack[0] = v59;
    goto v27;

v63:
    v59 = stack[0];
    v60 = qcar(v59);
    v59 = elt(env, 6); /* (difference quotient expt) */
    v59 = Lmemq(nil, v60, v59);
    if (v59 == nil) goto v66;
    v59 = stack[0];
    v60 = Llength(nil, v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v59 = (Lisp_Object)49; /* 3 */
    if (v60 == v59) goto v67;
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }

v67:
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcar(v59);
    v59 = CC_gpexpp(env, v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    if (v59 == nil) goto v68;
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcdr(v59);
    v59 = qcar(v59);
    stack[0] = v59;
    goto v27;

v68:
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }

v66:
    v59 = stack[0];
    v60 = qcar(v59);
    v59 = elt(env, 7); /* times */
    if (v60 == v59) goto v69;
    v59 = stack[0];
    v60 = qcar(v59);
    v59 = elt(env, 8); /* !:rd!: */
    if (v60 == v59) goto v70;
    v59 = stack[0];
    v60 = qcar(v59);
    v59 = elt(env, 9); /* (!:cr!: !:crn!: !:gi!:) */
    v59 = Lmemq(nil, v60, v59);
    if (v59 == nil) goto v71;
    v59 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v59); }

v71:
    v59 = stack[0];
    v59 = qcar(v59);
    fn = elt(env, 10); /* unresidp */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    if (v59 == nil) goto v72;
    v59 = stack[0];
    v59 = qcdr(v59);
    {
        popv(2);
        fn = elt(env, 11); /* gparg1p */
        return (*qfn1(fn))(qenv(fn), v59);
    }

v72:
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }

v70:
    v59 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v59); }

v69:
    v59 = stack[0];
    v60 = Llength(nil, v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v59 = (Lisp_Object)49; /* 3 */
    v59 = (Lisp_Object)geq2(v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v59 = v59 ? lisp_true : nil;
    env = stack[-1];
    if (v59 == nil) goto v73;
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcar(v59);
    v59 = CC_gpexpp(env, v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    if (v59 == nil) goto v74;
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcdr(v59);
    v59 = qcar(v59);
    v59 = CC_gpexpp(env, v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    if (v59 == nil) goto v75;
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcdr(v59);
    v59 = qcdr(v59);
    {
        popv(2);
        fn = elt(env, 12); /* gpexp1p */
        return (*qfn1(fn))(qenv(fn), v59);
    }

v75:
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }

v74:
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }

v73:
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }

v62:
    v59 = stack[0];
    v60 = Llength(nil, v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v59 = (Lisp_Object)33; /* 2 */
    v59 = (Lisp_Object)geq2(v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    v59 = v59 ? lisp_true : nil;
    env = stack[-1];
    if (v59 == nil) goto v76;
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcar(v59);
    v59 = CC_gpexpp(env, v59);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    if (v59 == nil) goto v4;
    v59 = stack[0];
    v59 = qcdr(v59);
    v59 = qcdr(v59);
    {
        popv(2);
        fn = elt(env, 12); /* gpexp1p */
        return (*qfn1(fn))(qenv(fn), v59);
    }

v4:
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }

v76:
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }

v28:
    v59 = stack[0];
    v59 = Lsymbolp(nil, v59);
    env = stack[-1];
    v60 = v59;
    if (!(v59 == nil)) { popv(2); return onevalue(v60); }
    v59 = stack[0];
    v59 = (is_number(v59) ? lisp_true : nil);
    v60 = v59;
    if (!(v59 == nil)) { popv(2); return onevalue(v60); }
    v59 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v59); }
/* error exit handlers */
v64:
    popv(2);
    return nil;
}



/* Code for calc_coeffmap_ */

static Lisp_Object MS_CDECL CC_calc_coeffmap_(Lisp_Object env, int nargs,
                         Lisp_Object v23, Lisp_Object v2,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v58, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "calc_coeffmap_");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_coeffmap_");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v23,v2,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-2] = v2;
    v82 = v23;
/* end of prologue */
    v58 = v82;
    v82 = stack[-1];
    fn = elt(env, 2); /* calc_map_ */
    v82 = (*qfn2(fn))(qenv(fn), v58, v82);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-4];
    v57 = v82;
    v58 = v57;
    v82 = (Lisp_Object)1; /* 0 */
    if (v58 == v82) goto v84;
    stack[-3] = elt(env, 1); /* times */
    stack[0] = v57;
    v58 = stack[-2];
    v82 = stack[-1];
    fn = elt(env, 3); /* calc_coeff */
    v82 = (*qfn2(fn))(qenv(fn), v58, v82);
    nil = C_nil;
    if (exception_pending()) goto v83;
    {
        Lisp_Object v62 = stack[-3];
        Lisp_Object v85 = stack[0];
        popv(5);
        return list2star(v62, v85, v82);
    }

v84:
    v82 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v82); }
/* error exit handlers */
v83:
    popv(5);
    return nil;
}



/* Code for quotodd */

static Lisp_Object CC_quotodd(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotodd");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v88 = v2;
    v89 = v23;
/* end of prologue */
    v87 = v89;
    if (!(!consp(v87))) goto v38;
    v87 = v88;
    if (!(!consp(v87))) goto v38;
    v87 = v89;
    fn = elt(env, 1); /* mkrn */
    v87 = (*qfn2(fn))(qenv(fn), v87, v88);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v87);
    }

v38:
    v87 = v89;
    {
        popv(1);
        fn = elt(env, 3); /* lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v87, v88);
    }
/* error exit handlers */
v26:
    popv(1);
    return nil;
}



/* Code for lieninstruc */

static Lisp_Object CC_lieninstruc(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v123, v124, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lieninstruc");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v23;
/* end of prologue */
    v70 = (Lisp_Object)17; /* 1 */
    stack[-5] = v70;
    goto v84;

v84:
    stack[0] = elt(env, 1); /* difference */
    v124 = elt(env, 1); /* difference */
    v123 = stack[-4];
    v70 = (Lisp_Object)17; /* 1 */
    v70 = list3(v124, v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v123 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v70 = stack[-5];
    v70 = list3(stack[0], v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    if (v70 == nil) goto v36;
    v70 = nil;
    { popv(7); return onevalue(v70); }

v36:
    v70 = stack[-5];
    v70 = add1(v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    stack[-3] = v70;
    goto v9;

v9:
    stack[0] = elt(env, 1); /* difference */
    v70 = stack[-4];
    fn = elt(env, 7); /* aeval!* */
    v123 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v70 = stack[-3];
    v70 = list3(stack[0], v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    if (v70 == nil) goto v79;
    v70 = stack[-5];
    v124 = elt(env, 6); /* plus */
    v123 = v70;
    v70 = (Lisp_Object)17; /* 1 */
    v70 = list3(v124, v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    stack[-5] = v70;
    goto v84;

v79:
    v70 = (Lisp_Object)17; /* 1 */
    stack[-2] = v70;
    goto v3;

v3:
    stack[0] = elt(env, 1); /* difference */
    v70 = stack[-4];
    fn = elt(env, 7); /* aeval!* */
    v123 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v70 = stack[-2];
    v70 = list3(stack[0], v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 8); /* aminusp!: */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    if (v70 == nil) goto v127;
    v70 = stack[-3];
    v124 = elt(env, 6); /* plus */
    v123 = v70;
    v70 = (Lisp_Object)17; /* 1 */
    v70 = list3(v124, v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    stack[-3] = v70;
    goto v9;

v127:
    v125 = elt(env, 3); /* lie_cc */
    v124 = stack[-5];
    v123 = stack[-3];
    v70 = stack[-2];
    stack[0] = list4(v125, v124, v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v125 = elt(env, 4); /* lienstrucin */
    v124 = stack[-5];
    v123 = stack[-3];
    v70 = stack[-2];
    v70 = list4(v125, v124, v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 9); /* setk */
    v70 = (*qfn2(fn))(qenv(fn), stack[0], v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v125 = elt(env, 3); /* lie_cc */
    v124 = stack[-3];
    v123 = stack[-5];
    v70 = stack[-2];
    stack[-1] = list4(v125, v124, v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    stack[0] = elt(env, 5); /* minus */
    v125 = elt(env, 4); /* lienstrucin */
    v124 = stack[-5];
    v123 = stack[-3];
    v70 = stack[-2];
    v70 = list4(v125, v124, v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v70 = list2(stack[0], v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 9); /* setk */
    v70 = (*qfn2(fn))(qenv(fn), stack[-1], v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    v70 = stack[-2];
    v124 = elt(env, 6); /* plus */
    v123 = v70;
    v70 = (Lisp_Object)17; /* 1 */
    v70 = list3(v124, v123, v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    fn = elt(env, 7); /* aeval!* */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-6];
    stack[-2] = v70;
    goto v3;
/* error exit handlers */
v126:
    popv(7);
    return nil;
}



/* Code for groeb!=testc1 */

static Lisp_Object CC_groebMtestc1(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=testc1");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v23;
/* end of prologue */
    v78 = stack[0];
    v130 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* nth */
    v130 = (*qfn2(fn))(qenv(fn), v78, v130);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    fn = elt(env, 2); /* bas_dpoly */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    stack[-1] = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v78 = stack[0];
    v130 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 1); /* nth */
    v130 = (*qfn2(fn))(qenv(fn), v78, v130);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    fn = elt(env, 2); /* bas_dpoly */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    fn = elt(env, 4); /* mo_sum */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v130);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v78 = stack[0];
    v130 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* nth */
    v130 = (*qfn2(fn))(qenv(fn), v78, v130);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    {
        Lisp_Object v57 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* mo_equal!? */
        return (*qfn2(fn))(qenv(fn), v57, v130);
    }
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for diff!-k!-times!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKkKtimesKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v23, Lisp_Object v2,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v145, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-k-times-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff-k-times-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v23,v2,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-2] = v2;
    stack[-3] = v23;
/* end of prologue */
    v144 = stack[-3];
    if (!consp(v144)) goto v146;
    v144 = stack[-3];
    v144 = qcar(v144);
    if (!consp(v144)) goto v146;
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v145 = qcar(v144);
    v144 = stack[-1];
    if (equal(v145, v144)) goto v88;
    v144 = stack[-3];
    v144 = qcar(v144);
    stack[-4] = qcar(v144);
    v144 = stack[-3];
    v144 = qcar(v144);
    v47 = qcdr(v144);
    v145 = stack[-2];
    v144 = stack[-1];
    stack[0] = CC_diffKkKtimesKmodKp(env, 3, v47, v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v144 = stack[-3];
    v47 = qcdr(v144);
    v145 = stack[-2];
    v144 = stack[-1];
    v144 = CC_diffKkKtimesKmodKp(env, 3, v47, v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    {
        Lisp_Object v69 = stack[-4];
        Lisp_Object v148 = stack[0];
        popv(6);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v69, v148, v144);
    }

v88:
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v145 = qcdr(v144);
    v144 = stack[-2];
    v144 = (Lisp_Object)lessp2(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v144 = v144 ? lisp_true : nil;
    env = stack[-5];
    if (v144 == nil) goto v79;
    v144 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v144); }

v79:
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v145 = qcdr(v144);
    v144 = stack[-2];
    if (equal(v145, v144)) goto v130;
    stack[0] = stack[-1];
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v145 = qcdr(v144);
    v144 = stack[-2];
    v144 = difference2(v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    fn = elt(env, 3); /* mksp */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcar(v144);
    v145 = qcdr(v144);
    v144 = stack[-2];
    fn = elt(env, 4); /* binomial!-coefft!-mod!-p */
    v145 = (*qfn2(fn))(qenv(fn), v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcdr(v144);
    fn = elt(env, 5); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    v144 = stack[-3];
    v47 = qcdr(v144);
    v145 = stack[-2];
    v144 = stack[-1];
    v144 = CC_diffKkKtimesKmodKp(env, 3, v47, v145, v144);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-5];
    {
        Lisp_Object v149 = stack[-4];
        Lisp_Object v150 = stack[0];
        popv(6);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v149, v150, v144);
    }

v130:
    v144 = stack[-3];
    v144 = qcar(v144);
    v144 = qcdr(v144);
    { popv(6); return onevalue(v144); }

v146:
    v144 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v144); }
/* error exit handlers */
v147:
    popv(6);
    return nil;
}



/* Code for prepsq!*0 */

static Lisp_Object CC_prepsqH0(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v141, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*0");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v23;
/* end of prologue */
    v4 = stack[-2];
    v4 = qcar(v4);
    if (v4 == nil) goto v28;
    v4 = stack[-2];
    v141 = qcar(v4);
    v4 = stack[-2];
    v4 = qcdr(v4);
    fn = elt(env, 2); /* gcdf */
    v141 = (*qfn2(fn))(qenv(fn), v141, v4);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    stack[-3] = v141;
    v4 = (Lisp_Object)17; /* 1 */
    if (v141 == v4) goto v103;
    v4 = stack[-2];
    v141 = qcar(v4);
    v4 = stack[-3];
    fn = elt(env, 3); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v141, v4);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    v4 = stack[-2];
    v141 = qcdr(v4);
    v4 = stack[-3];
    fn = elt(env, 3); /* quotf */
    v141 = (*qfn2(fn))(qenv(fn), v141, v4);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-4];
    v4 = stack[-1];
    {
        Lisp_Object v155 = stack[0];
        popv(5);
        fn = elt(env, 4); /* prepsq!*1 */
        return (*qfnn(fn))(qenv(fn), 3, v155, v141, v4);
    }

v103:
    v4 = stack[-2];
    v154 = qcar(v4);
    v4 = stack[-2];
    v141 = qcdr(v4);
    v4 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* prepsq!*1 */
        return (*qfnn(fn))(qenv(fn), 3, v154, v141, v4);
    }

v28:
    v4 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v4); }
/* error exit handlers */
v118:
    popv(5);
    return nil;
}



/* Code for simpexpt2 */

static Lisp_Object MS_CDECL CC_simpexpt2(Lisp_Object env, int nargs,
                         Lisp_Object v23, Lisp_Object v2,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v225, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt2");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v23,v2,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v7;
    stack[-2] = v2;
    stack[-3] = v23;
/* end of prologue */

v18:
    v225 = stack[-3];
    v224 = (Lisp_Object)17; /* 1 */
    if (v225 == v224) goto v13;
    v224 = stack[-2];
    v224 = qcar(v224);
    stack[-4] = v224;
    v224 = stack[-3];
    v224 = Lconsp(nil, v224);
    env = stack[-5];
    if (v224 == nil) goto v88;
    v224 = stack[-3];
    v225 = qcar(v224);
    v224 = elt(env, 1); /* expt */
    if (!(v225 == v224)) goto v139;
    v224 = qvalue(elt(env, 2)); /* !*precise_complex */
    if (!(v224 == nil)) goto v139;
    v224 = stack[-3];
    v224 = qcdr(v224);
    v224 = qcdr(v224);
    v224 = qcar(v224);
    fn = elt(env, 15); /* simp */
    v225 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-4] = v225;
    v224 = stack[-2];
    fn = elt(env, 16); /* multsq */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-2] = v224;
    v224 = qvalue(elt(env, 3)); /* !*precise */
    if (v224 == nil) goto v15;
    v224 = stack[-4];
    v224 = qcar(v224);
    if (!(is_number(v224))) goto v15;
    v224 = stack[-4];
    v224 = qcar(v224);
    v224 = Levenp(nil, v224);
    env = stack[-5];
    if (v224 == nil) goto v15;
    v225 = elt(env, 4); /* abs */
    v224 = stack[-3];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    v224 = list2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-3] = v224;
    goto v65;

v65:
    v226 = stack[-3];
    v225 = stack[-2];
    v224 = stack[-1];
    {
        popv(6);
        fn = elt(env, 17); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v226, v225, v224);
    }

v15:
    v224 = stack[-3];
    v224 = qcdr(v224);
    v224 = qcar(v224);
    stack[-3] = v224;
    goto v65;

v139:
    v224 = stack[-3];
    v225 = qcar(v224);
    v224 = elt(env, 5); /* sqrt */
    if (!(v225 == v224)) goto v228;
    v224 = qvalue(elt(env, 6)); /* !*keepsqrts */
    if (!(v224 == nil)) goto v228;
    v224 = stack[-3];
    v224 = qcdr(v224);
    stack[0] = qcar(v224);
    v225 = (Lisp_Object)17; /* 1 */
    v224 = (Lisp_Object)33; /* 2 */
    v225 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v224 = stack[-2];
    fn = elt(env, 16); /* multsq */
    v225 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v224 = stack[-1];
    stack[-3] = stack[0];
    stack[-2] = v225;
    stack[-1] = v224;
    goto v18;

v228:
    v224 = stack[-3];
    v225 = qcar(v224);
    v224 = elt(env, 7); /* times */
    if (!(v225 == v224)) goto v91;
    v224 = qvalue(elt(env, 3)); /* !*precise */
    if (!(v224 == nil)) goto v91;
    v225 = (Lisp_Object)17; /* 1 */
    v224 = (Lisp_Object)17; /* 1 */
    v224 = cons(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-4] = v224;
    v224 = stack[-3];
    v224 = qcdr(v224);
    stack[0] = v224;
    goto v149;

v149:
    v224 = stack[0];
    if (v224 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v224 = stack[0];
    v224 = qcar(v224);
    v226 = v224;
    v225 = stack[-2];
    v224 = stack[-1];
    fn = elt(env, 17); /* simpexpt1 */
    v225 = (*qfnn(fn))(qenv(fn), 3, v226, v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v224 = stack[-4];
    fn = elt(env, 16); /* multsq */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-4] = v224;
    v224 = stack[0];
    v224 = qcdr(v224);
    stack[0] = v224;
    goto v149;

v91:
    v224 = stack[-3];
    v225 = qcar(v224);
    v224 = elt(env, 7); /* times */
    if (!(v225 == v224)) goto v229;
    v224 = stack[-3];
    v224 = qcdr(v224);
    fn = elt(env, 18); /* split!-sign */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[0] = v224;
    if (v224 == nil) goto v229;
    v224 = stack[0];
    v224 = qcar(v224);
    if (v224 == nil) goto v229;
    v224 = stack[0];
    v224 = qcdr(v224);
    v225 = qcar(v224);
    v224 = stack[0];
    v224 = qcdr(v224);
    v224 = qcdr(v224);
    v224 = Lappend(nil, v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 19); /* retimes */
    v226 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v225 = stack[-2];
    v224 = stack[-1];
    fn = elt(env, 17); /* simpexpt1 */
    v224 = (*qfnn(fn))(qenv(fn), 3, v226, v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-4] = v224;
    v224 = stack[0];
    v224 = qcar(v224);
    stack[0] = v224;
    goto v230;

v230:
    v224 = stack[0];
    if (v224 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v224 = stack[0];
    v224 = qcar(v224);
    v226 = v224;
    v225 = stack[-2];
    v224 = stack[-1];
    fn = elt(env, 17); /* simpexpt1 */
    v225 = (*qfnn(fn))(qenv(fn), 3, v226, v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v224 = stack[-4];
    fn = elt(env, 16); /* multsq */
    v224 = (*qfn2(fn))(qenv(fn), v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-4] = v224;
    v224 = stack[0];
    v224 = qcdr(v224);
    stack[0] = v224;
    goto v230;

v229:
    v224 = stack[-3];
    v225 = qcar(v224);
    v224 = elt(env, 9); /* quotient */
    if (!(v225 == v224)) goto v231;
    v224 = qvalue(elt(env, 3)); /* !*precise */
    if (v224 == nil) goto v232;
    v224 = stack[-3];
    v224 = qcdr(v224);
    v224 = qcdr(v224);
    v224 = qcar(v224);
    fn = elt(env, 20); /* posnump */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    if (v224 == nil) goto v231;
    v224 = stack[-2];
    fn = elt(env, 21); /* prepsq */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 20); /* posnump */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    if (!(v224 == nil)) goto v232;

v231:
    v224 = stack[-3];
    v225 = qcar(v224);
    v224 = elt(env, 12); /* minus */
    if (!(v225 == v224)) goto v88;
    v224 = qvalue(elt(env, 3)); /* !*precise */
    if (!(v224 == nil)) goto v88;
    v224 = stack[-3];
    v224 = qcdr(v224);
    v225 = qcar(v224);
    v224 = (Lisp_Object)17; /* 1 */
    if (v225 == v224) goto v88;
    v224 = stack[-2];
    fn = elt(env, 21); /* prepsq */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-1] = v224;
    v225 = (Lisp_Object)-15; /* -1 */
    v224 = stack[-1];
    v224 = list2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 22); /* simpexpt */
    stack[0] = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v224 = stack[-3];
    v224 = qcdr(v224);
    v225 = qcar(v224);
    v224 = stack[-1];
    v224 = list2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 22); /* simpexpt */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    {
        Lisp_Object v233 = stack[0];
        popv(6);
        fn = elt(env, 16); /* multsq */
        return (*qfn2(fn))(qenv(fn), v233, v224);
    }

v88:
    v224 = stack[-1];
    if (v224 == nil) goto v234;
    v224 = stack[-3];
    if (!(is_number(v224))) goto v235;
    v224 = stack[-3];
    v224 = (Lisp_Object)zerop(v224);
    v224 = v224 ? lisp_true : nil;
    env = stack[-5];
    if (v224 == nil) goto v235;
    v225 = qvalue(elt(env, 8)); /* nil */
    v224 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v225, v224);

v235:
    v224 = stack[-4];
    if (is_number(v224)) goto v236;
    v224 = stack[-4];
    fn = elt(env, 23); /* prepf */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-4] = v224;
    goto v236;

v236:
    v224 = stack[-2];
    v224 = qcdr(v224);
    fn = elt(env, 23); /* prepf */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-2] = v224;
    v225 = stack[-4];
    v224 = qvalue(elt(env, 14)); /* frlis!* */
    v224 = Lmemq(nil, v225, v224);
    if (v224 == nil) goto v237;
    v225 = stack[-2];
    v224 = (Lisp_Object)17; /* 1 */
    if (!(v225 == v224)) goto v237;
    v226 = stack[-3];
    v225 = stack[-4];
    v224 = (Lisp_Object)17; /* 1 */
    v224 = acons(v226, v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v225 = ncons(v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    v224 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v225, v224);

v237:
    v224 = qvalue(elt(env, 10)); /* !*mcd */
    if (!(v224 == nil)) goto v238;
    v224 = stack[-4];
    if (!(is_number(v224))) goto v238;
    v225 = stack[-2];
    v224 = (Lisp_Object)17; /* 1 */
    if (!(v225 == v224)) goto v238;
    v224 = stack[-3];
    if (!consp(v224)) goto v238;
    v224 = stack[-3];
    fn = elt(env, 24); /* simp!* */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v225 = qcdr(v224);
    v224 = (Lisp_Object)17; /* 1 */
    if (!(v225 == v224)) goto v238;
    v225 = stack[-3];
    v224 = stack[-4];
    {
        popv(6);
        fn = elt(env, 25); /* mksq */
        return (*qfn2(fn))(qenv(fn), v225, v224);
    }

v238:
    v226 = stack[-3];
    v225 = stack[-4];
    v224 = stack[-2];
    {
        popv(6);
        fn = elt(env, 26); /* simpx1 */
        return (*qfnn(fn))(qenv(fn), 3, v226, v225, v224);
    }

v234:
    v224 = qvalue(elt(env, 13)); /* dmode!* */
    if (v224 == nil) goto v239;
    v224 = stack[-3];
    if (!(symbolp(v224))) goto v239;
    v225 = stack[-3];
    v224 = qvalue(elt(env, 13)); /* dmode!* */
    v224 = get(v225, v224);
    env = stack[-5];
    if (!(v224 == nil)) goto v240;

v239:
    v224 = stack[-3];
    fn = elt(env, 24); /* simp!* */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 21); /* prepsq */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-3] = v224;
    goto v240;

v240:
    v226 = stack[-3];
    v225 = stack[-2];
    v224 = qvalue(elt(env, 11)); /* t */
    {
        popv(6);
        fn = elt(env, 17); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v226, v225, v224);
    }

v232:
    v224 = stack[-1];
    if (!(v224 == nil)) goto v241;
    v224 = qvalue(elt(env, 10)); /* !*mcd */
    if (v224 == nil) goto v241;
    v224 = stack[-3];
    fn = elt(env, 24); /* simp!* */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 21); /* prepsq */
    v226 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v225 = stack[-2];
    v224 = qvalue(elt(env, 11)); /* t */
    {
        popv(6);
        fn = elt(env, 17); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v226, v225, v224);
    }

v241:
    v224 = stack[-2];
    fn = elt(env, 21); /* prepsq */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-2] = v224;
    v224 = stack[-3];
    v224 = qcdr(v224);
    v225 = qcar(v224);
    v224 = stack[-2];
    v224 = list2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 22); /* simpexpt */
    stack[0] = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v224 = stack[-3];
    v224 = qcdr(v224);
    v224 = qcdr(v224);
    v225 = qcar(v224);
    v224 = stack[-2];
    v224 = list2(v225, v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 22); /* simpexpt */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    {
        Lisp_Object v242 = stack[0];
        popv(6);
        fn = elt(env, 27); /* quotsq */
        return (*qfn2(fn))(qenv(fn), v242, v224);
    }

v13:
    v225 = (Lisp_Object)17; /* 1 */
    v224 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v225, v224);
/* error exit handlers */
v227:
    popv(6);
    return nil;
}



/* Code for replace!-next */

static Lisp_Object CC_replaceKnext(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v83, v62, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace-next");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v23;
/* end of prologue */
    stack[-2] = nil;
    goto v146;

v146:
    v21 = stack[-1];
    if (v21 == nil) goto v35;
    v21 = stack[-1];
    v21 = qcar(v21);
    v85 = qcar(v21);
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v62 = qcar(v21);
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v21 = qcdr(v21);
    v83 = qcar(v21);
    v21 = stack[0];
    v21 = qcar(v21);
    v83 = list4(v85, v62, v83, v21);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v21 = stack[-2];
    v21 = cons(v83, v21);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v21;
    v21 = stack[-1];
    v21 = qcdr(v21);
    stack[-1] = v21;
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[0] = v21;
    goto v146;

v35:
    v21 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v21);
    }
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for mk!+outer!+list */

static Lisp_Object CC_mkLouterLlist(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v129;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+outer+list");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v23;
/* end of prologue */
    v18 = elt(env, 1); /* list */
    v129 = ncons(v18);
    nil = C_nil;
    if (exception_pending()) goto v17;
    v18 = stack[0];
        popv(1);
        return Lappend(nil, v129, v18);
/* error exit handlers */
v17:
    popv(1);
    return nil;
}



/* Code for matrixelems */

static Lisp_Object CC_matrixelems(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixelems");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v23;
/* end of prologue */
    v29 = nil;
    goto v27;

v27:
    v39 = stack[0];
    if (v39 == nil) goto v37;
    v39 = stack[0];
    v39 = qcar(v39);
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    v39 = cons(v39, v29);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-1];
    v29 = v39;
    v39 = stack[0];
    v39 = qcdr(v39);
    stack[0] = v39;
    goto v27;

v37:
    v39 = v29;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v39);
    }
/* error exit handlers */
v88:
    popv(2);
    return nil;
}



/* Code for f4 */

static Lisp_Object CC_f4(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f4");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v23;
/* end of prologue */
    v209 = stack[0];
    v60 = elt(env, 1); /* pi */
    if (v209 == v60) goto v146;
    v209 = stack[0];
    v60 = elt(env, 3); /* euler_gamma */
    if (v209 == v60) goto v31;
    v209 = stack[0];
    v60 = elt(env, 5); /* true */
    if (v209 == v60) goto v39;
    v209 = stack[0];
    v60 = elt(env, 7); /* false */
    if (v209 == v60) goto v143;
    v209 = stack[0];
    v60 = elt(env, 9); /* !Na!N */
    if (v209 == v60) goto v248;
    v209 = stack[0];
    v60 = elt(env, 11); /* infinity */
    if (v209 == v60) goto v103;
    v209 = stack[0];
    v60 = elt(env, 17); /* e */
    if (v209 == v60) goto v249;
    v209 = stack[0];
    v60 = elt(env, 19); /* i */
    if (v209 == v60) goto v51;
    v60 = stack[0];
    if (!(is_number(v60))) goto v250;
    v60 = elt(env, 21); /* "<cn" */
    fn = elt(env, 34); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    v60 = stack[0];
    v60 = Lfloatp(nil, v60);
    env = stack[-1];
    if (v60 == nil) goto v132;
    v60 = qvalue(elt(env, 12)); /* !*web */
    if (v60 == nil) goto v46;
    v60 = elt(env, 23); /* " type=&quot;real&quot;>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v66;

v66:
    v60 = stack[0];
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    v60 = elt(env, 16); /* "</cn>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v250;

v250:
    v60 = stack[0];
    if (!(symbolp(v60))) goto v27;
    v60 = elt(env, 27); /* "<ci" */
    fn = elt(env, 34); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    v60 = stack[0];
    fn = elt(env, 35); /* listp */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    if (v60 == nil) goto v73;
    v60 = qvalue(elt(env, 12)); /* !*web */
    if (v60 == nil) goto v124;
    v60 = elt(env, 29); /* " type=&quot;list&quot;>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v252;

v252:
    v60 = stack[0];
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    v60 = elt(env, 32); /* "</ci>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v27;

v27:
    v60 = nil;
    { popv(2); return onevalue(v60); }

v124:
    v60 = elt(env, 28); /* " type=""list"">" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v252;

v73:
    v60 = stack[0];
    v60 = Lsimple_vectorp(nil, v60);
    env = stack[-1];
    if (v60 == nil) goto v253;
    v60 = qvalue(elt(env, 12)); /* !*web */
    if (v60 == nil) goto v254;
    v60 = elt(env, 31); /* " type=&quot;vector&quot;>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v252;

v254:
    v60 = elt(env, 30); /* " type=""vector"">" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v252;

v253:
    v60 = elt(env, 26); /* ">" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v252;

v46:
    v60 = elt(env, 22); /* " type=""real"">" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v66;

v132:
    v60 = stack[0];
    v60 = integerp(v60);
    if (v60 == nil) goto v255;
    v60 = qvalue(elt(env, 12)); /* !*web */
    if (v60 == nil) goto v97;
    v60 = elt(env, 25); /* " type=&quot;integer&quot;>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v66;

v97:
    v60 = elt(env, 24); /* " type=""integer"">" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v66;

v255:
    v60 = elt(env, 26); /* ">" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v66;

v51:
    v60 = qvalue(elt(env, 12)); /* !*web */
    if (v60 == nil) goto v48;
    v60 = elt(env, 14); /* "<cn type=&quot;constant&quot;>" */
    fn = elt(env, 34); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v256;

v256:
    v60 = elt(env, 20); /* "&ImaginaryI;" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    v60 = elt(env, 16); /* "</cn>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v27;

v48:
    v60 = elt(env, 13); /* "<cn type=""constant"">" */
    fn = elt(env, 34); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v256;

v249:
    v60 = qvalue(elt(env, 12)); /* !*web */
    if (v60 == nil) goto v117;
    v60 = elt(env, 14); /* "<cn type=&quot;constant&quot;>" */
    fn = elt(env, 34); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v52;

v52:
    v60 = elt(env, 18); /* "&ExponentialE;" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    v60 = elt(env, 16); /* "</cn>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v27;

v117:
    v60 = elt(env, 13); /* "<cn type=""constant"">" */
    fn = elt(env, 34); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v52;

v103:
    v60 = qvalue(elt(env, 12)); /* !*web */
    if (v60 == nil) goto v3;
    v60 = elt(env, 14); /* "<cn type=&quot;constant&quot;>" */
    fn = elt(env, 34); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v152;

v152:
    v60 = elt(env, 15); /* "&infin;" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    v60 = elt(env, 16); /* "</cn>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v27;

v3:
    v60 = elt(env, 13); /* "<cn type=""constant"">" */
    fn = elt(env, 34); /* printout */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-1];
    goto v152;

v248:
    v60 = elt(env, 10); /* "<notanumber/>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v27;

v143:
    v60 = elt(env, 8); /* "<false/>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v27;

v39:
    v60 = elt(env, 6); /* "<true/>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v27;

v31:
    v60 = elt(env, 4); /* "<eulergamma/>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v27;

v146:
    v60 = elt(env, 2); /* "<pi/>" */
    v60 = Lprinc(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v251;
    goto v27;
/* error exit handlers */
v251:
    popv(2);
    return nil;
}



/* Code for insertocc */

static Lisp_Object CC_insertocc(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v62, v85;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insertocc");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v85 = v2;
    stack[-1] = v23;
/* end of prologue */
    v62 = v85;
    v83 = stack[-1];
    v83 = Lassoc(nil, v62, v83);
    stack[-2] = v83;
    if (v83 == nil) goto v78;
    stack[0] = v85;
    v83 = stack[-2];
    v83 = qcdr(v83);
    v83 = add1(v83);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v85 = cons(stack[0], v83);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v62 = stack[-2];
    v83 = stack[-1];
    v83 = Lsubst(nil, 3, v85, v62, v83);
    nil = C_nil;
    if (exception_pending()) goto v55;
    stack[-1] = v83;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v78:
    v62 = (Lisp_Object)17; /* 1 */
    v83 = stack[-1];
    v83 = acons(v85, v62, v83);
    nil = C_nil;
    if (exception_pending()) goto v55;
    stack[-1] = v83;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for exdf0 */

static Lisp_Object CC_exdf0(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exdf0");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v23;
/* end of prologue */
    v77 = stack[0];
    v77 = qcar(v77);
    fn = elt(env, 1); /* exdff0 */
    stack[-1] = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    v77 = stack[0];
    v77 = qcdr(v77);
    fn = elt(env, 2); /* negf */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    fn = elt(env, 1); /* exdff0 */
    v243 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    v77 = stack[0];
    fn = elt(env, 3); /* multpfsq */
    v77 = (*qfn2(fn))(qenv(fn), v243, v77);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    fn = elt(env, 4); /* addpf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v77);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    v243 = (Lisp_Object)17; /* 1 */
    v77 = stack[0];
    v77 = qcdr(v77);
    v77 = cons(v243, v77);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    {
        Lisp_Object v130 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v130, v77);
    }
/* error exit handlers */
v128:
    popv(3);
    return nil;
}



/* Code for gfplus */

static Lisp_Object CC_gfplus(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v39, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfplus");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v39 = v2;
    v29 = v23;
/* end of prologue */
    v20 = v29;
    v20 = qcar(v20);
    if (!consp(v20)) goto v36;
    v20 = v29;
    {
        fn = elt(env, 1); /* gbfplus */
        return (*qfn2(fn))(qenv(fn), v20, v39);
    }

v36:
    v20 = v29;
    {
        fn = elt(env, 2); /* gffplus */
        return (*qfn2(fn))(qenv(fn), v20, v39);
    }
}



/* Code for gpargp */

static Lisp_Object CC_gpargp(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpargp");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v23;
/* end of prologue */
    v80 = stack[0];
    v80 = Lstringp(nil, v80);
    env = stack[-1];
    if (!(v80 == nil)) { popv(2); return onevalue(v80); }
    v80 = stack[0];
    fn = elt(env, 1); /* gpexpp */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-1];
    if (!(v80 == nil)) { popv(2); return onevalue(v80); }
    v80 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* gplogexpp */
        return (*qfn1(fn))(qenv(fn), v80);
    }
/* error exit handlers */
v129:
    popv(2);
    return nil;
}



/* Code for s_world_names */

static Lisp_Object CC_s_world_names(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for s_world_names");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v82 = v23;
/* end of prologue */
    v82 = qcar(v82);
    stack[-3] = v82;
    v82 = stack[-3];
    if (v82 == nil) goto v80;
    v82 = stack[-3];
    v82 = qcar(v82);
    v82 = qcar(v82);
    v82 = ncons(v82);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-4];
    stack[-1] = v82;
    stack[-2] = v82;
    goto v257;

v257:
    v82 = stack[-3];
    v82 = qcdr(v82);
    stack[-3] = v82;
    v82 = stack[-3];
    if (v82 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v82 = stack[-3];
    v82 = qcar(v82);
    v82 = qcar(v82);
    v82 = ncons(v82);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-4];
    v82 = Lrplacd(nil, stack[0], v82);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-4];
    v82 = stack[-1];
    v82 = qcdr(v82);
    stack[-1] = v82;
    goto v257;

v80:
    v82 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v82); }
/* error exit handlers */
v248:
    popv(5);
    return nil;
}



/* Code for tayexp!-max2 */

static Lisp_Object CC_tayexpKmax2(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-max2");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v23;
/* end of prologue */
    v33 = stack[-1];
    v32 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v38;
    if (v32 == nil) { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v38:
    popv(2);
    return nil;
}



/* Code for my!+nullsq!+p */

static Lisp_Object CC_myLnullsqLp(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for my+nullsq+p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v23;
/* end of prologue */
    v81 = qcar(v81);
    if (v81 == nil) goto v146;
    v81 = nil;
    return onevalue(v81);

v146:
    v81 = qvalue(elt(env, 1)); /* t */
    return onevalue(v81);
}



/* Code for ctx_new */

static Lisp_Object MS_CDECL CC_ctx_new(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ctx_new");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_new");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v14 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* ctx_fromial */
        return (*qfn1(fn))(qenv(fn), v14);
    }
}



/* Code for lowupperlimitrd */

static Lisp_Object MS_CDECL CC_lowupperlimitrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "lowupperlimitrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lowupperlimitrd");
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
    fn = elt(env, 5); /* mathml */
    v128 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[0] = v128;
    fn = elt(env, 6); /* lex */
    v128 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    v130 = qvalue(elt(env, 1)); /* char */
    v128 = elt(env, 2); /* (!/ l o w l i m i t) */
    if (equal(v130, v128)) goto v35;
    v130 = elt(env, 3); /* "</lowlimit>" */
    v128 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 7); /* errorml */
    v128 = (*qfn2(fn))(qenv(fn), v130, v128);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    goto v87;

v87:
    stack[-1] = elt(env, 4); /* lowupperlimit */
    v128 = stack[-2];
    v128 = ncons(v128);
    nil = C_nil;
    if (exception_pending()) goto v58;
    {
        Lisp_Object v57 = stack[-1];
        Lisp_Object v8 = stack[0];
        popv(4);
        return list2star(v57, v8, v128);
    }

v35:
    fn = elt(env, 8); /* upperlimitrd */
    v128 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[-2] = v128;
    goto v87;
/* error exit handlers */
v58:
    popv(4);
    return nil;
}



/* Code for ldf!-dep!-var */

static Lisp_Object CC_ldfKdepKvar(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-dep-var");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v62 = v23;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = v62;
    goto v28;

v28:
    v62 = stack[-1];
    if (v62 == nil) goto v257;
    v62 = stack[-1];
    v62 = qcar(v62);
    stack[0] = v62;
    v62 = stack[0];
    fn = elt(env, 3); /* ldt!-tvar */
    v85 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v62 = qvalue(elt(env, 2)); /* depl!* */
    v62 = Lassoc(nil, v85, v62);
    if (v62 == nil) goto v33;
    v62 = stack[0];
    fn = elt(env, 3); /* ldt!-tvar */
    v85 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    v62 = qvalue(elt(env, 2)); /* depl!* */
    v62 = Lassoc(nil, v85, v62);
    v85 = qcdr(v62);
    v62 = stack[-2];
    v62 = Lappend(nil, v85, v62);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-3];
    stack[-2] = v62;
    goto v33;

v33:
    v62 = stack[-1];
    v62 = qcdr(v62);
    stack[-1] = v62;
    goto v28;

v257:
    v62 = stack[-2];
    {
        popv(4);
        fn = elt(env, 4); /* makeset */
        return (*qfn1(fn))(qenv(fn), v62);
    }
/* error exit handlers */
v55:
    popv(4);
    return nil;
}



/* Code for findoptrow */

static Lisp_Object MS_CDECL CC_findoptrow(Lisp_Object env, int nargs,
                         Lisp_Object v23, Lisp_Object v2,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94, v270, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "findoptrow");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findoptrow");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v23,v2,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v7;
    stack[0] = v2;
    stack[-6] = v23;
/* end of prologue */
    stack[-7] = nil;
    stack[-2] = stack[0];
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v94 = qvalue(elt(env, 2)); /* maxvar */
    v93 = stack[-6];
    v93 = plus2(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-8];
    v94 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    v93 = (Lisp_Object)65; /* 4 */
    v93 = *(Lisp_Object *)((char *)v94 + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    fn = elt(env, 8); /* pnthxzz */
    v93 = (*qfn2(fn))(qenv(fn), stack[-2], v93);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-8];
    v93 = qcar(v93);
    v93 = qcdr(v93);
    v93 = qcar(v93);
    stack[-3] = v93;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v94 = qvalue(elt(env, 2)); /* maxvar */
    v93 = stack[0];
    v93 = plus2(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-8];
    v94 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    v93 = (Lisp_Object)65; /* 4 */
    v93 = *(Lisp_Object *)((char *)v94 + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    stack[-2] = v93;
    goto v58;

v58:
    v93 = stack[-2];
    if (v93 == nil) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    v93 = stack[-2];
    v93 = qcar(v93);
    stack[-1] = v93;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v94 = qvalue(elt(env, 2)); /* maxvar */
    v93 = stack[-1];
    v93 = qcar(v93);
    stack[-4] = v93;
    v93 = plus2(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-8];
    v94 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    v93 = (Lisp_Object)1; /* 0 */
    v93 = *(Lisp_Object *)((char *)v94 + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    if (v93 == nil) goto v120;
    v92 = stack[-4];
    v270 = stack[-6];
    v93 = stack[-1];
    v93 = qcdr(v93);
    v94 = qcar(v93);
    v93 = stack[-3];
    fn = elt(env, 9); /* testpr */
    v93 = (*qfnn(fn))(qenv(fn), 4, v92, v270, v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-8];
    stack[0] = v93;
    v93 = qcdr(v93);
    if (v93 == nil) goto v256;
    v93 = stack[0];
    v94 = Llength(nil, v93);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-8];
    stack[-1] = v94;
    v93 = stack[-5];
    v93 = (Lisp_Object)greaterp2(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v271;
    v93 = v93 ? lisp_true : nil;
    env = stack[-8];
    if (v93 == nil) goto v132;
    v93 = stack[-1];
    stack[-5] = v93;
    qvalue(elt(env, 5)) = v93; /* newnjsi */
    v93 = stack[-4];
    stack[-7] = v93;
    v93 = stack[0];
    qvalue(elt(env, 6)) = v93; /* newjsi */
    goto v132;

v132:
    v94 = stack[-4];
    v93 = qvalue(elt(env, 7)); /* roccup2 */
    v93 = cons(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-8];
    qvalue(elt(env, 7)) = v93; /* roccup2 */
    goto v150;

v150:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v94 = qvalue(elt(env, 2)); /* maxvar */
    v93 = stack[-4];
    v93 = plus2(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-8];
    v270 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    v94 = (Lisp_Object)1; /* 0 */
    v93 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v270 + (CELL-TAG_VECTOR) + ((int32_t)v94/(16/CELL))) = v93;
    goto v120;

v120:
    v93 = stack[-2];
    v93 = qcdr(v93);
    stack[-2] = v93;
    goto v58;

v256:
    v94 = stack[-4];
    v93 = qvalue(elt(env, 4)); /* roccup1 */
    v93 = cons(v94, v93);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-8];
    qvalue(elt(env, 4)) = v93; /* roccup1 */
    goto v150;
/* error exit handlers */
v271:
    popv(9);
    return nil;
}



/* Code for o!-nextarg */

static Lisp_Object CC_oKnextarg(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for o-nextarg");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v23;
/* end of prologue */
    v132 = qvalue(elt(env, 1)); /* !*udebug */
    if (v132 == nil) goto v31;
    v132 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 12); /* uprint */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    goto v31;

v31:
    v133 = qvalue(elt(env, 3)); /* i */
    v132 = (Lisp_Object)17; /* 1 */
    if (!(v133 == v132)) goto v77;
    v133 = qvalue(elt(env, 3)); /* i */
    v132 = qvalue(elt(env, 4)); /* upb */
    v132 = (Lisp_Object)lesseq2(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    v132 = v132 ? lisp_true : nil;
    env = stack[-3];
    if (v132 == nil) goto v77;
    v132 = stack[-1];
    goto v18;

v18:
    stack[0] = v132;
    v132 = qvalue(elt(env, 3)); /* i */
    v132 = add1(v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    qvalue(elt(env, 3)) = v132; /* i */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v77:
    v133 = qvalue(elt(env, 3)); /* i */
    v132 = (Lisp_Object)1; /* 0 */
    if (!(v133 == v132)) goto v11;
    v133 = qvalue(elt(env, 3)); /* i */
    v132 = qvalue(elt(env, 4)); /* upb */
    v132 = (Lisp_Object)lesseq2(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    v132 = v132 ? lisp_true : nil;
    env = stack[-3];
    if (v132 == nil) goto v11;
    v133 = elt(env, 5); /* (null!-fn) */
    v132 = stack[-1];
    v132 = cons(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    goto v18;

v11:
    v132 = qvalue(elt(env, 6)); /* acontract */
    if (v132 == nil) goto v222;
    v133 = qvalue(elt(env, 3)); /* i */
    v132 = qvalue(elt(env, 4)); /* upb */
    v132 = (Lisp_Object)lesseq2(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    v132 = v132 ? lisp_true : nil;
    env = stack[-3];
    if (v132 == nil) goto v222;
    stack[-2] = qvalue(elt(env, 7)); /* op */
    v133 = stack[-1];
    v132 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 13); /* first0 */
    stack[0] = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v133 = stack[-1];
    v132 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 14); /* last0 */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v132 = acons(stack[-2], stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    fn = elt(env, 15); /* mval */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    goto v18;

v222:
    v132 = qvalue(elt(env, 8)); /* mcontract */
    if (v132 == nil) goto v53;
    v133 = qvalue(elt(env, 3)); /* i */
    v132 = qvalue(elt(env, 4)); /* upb */
    v132 = (Lisp_Object)lesseq2(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    v132 = v132 ? lisp_true : nil;
    env = stack[-3];
    if (v132 == nil) goto v53;
    stack[-2] = elt(env, 9); /* null!-fn */
    v133 = stack[-1];
    v132 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 13); /* first0 */
    stack[0] = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v133 = stack[-1];
    v132 = qvalue(elt(env, 3)); /* i */
    fn = elt(env, 14); /* last0 */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v132 = acons(stack[-2], stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    goto v18;

v53:
    v132 = qvalue(elt(env, 10)); /* expand */
    if (v132 == nil) goto v102;
    v132 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 10)) = v132; /* expand */
    v133 = qvalue(elt(env, 11)); /* identity */
    v132 = stack[-1];
    v132 = cons(v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    goto v18;

v102:
    v132 = nil;
    goto v18;
/* error exit handlers */
v46:
    popv(4);
    return nil;
}



/* Code for dipcontevmin */

static Lisp_Object CC_dipcontevmin(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v3, v4;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontevmin");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v23;
/* end of prologue */
    v4 = nil;
    goto v28;

v28:
    v152 = stack[-1];
    if (v152 == nil) goto v248;
    v152 = stack[0];
    if (v152 == nil) goto v248;
    v152 = stack[-1];
    v3 = qcar(v152);
    v152 = stack[0];
    v152 = qcar(v152);
    if (((int32_t)(v3)) < ((int32_t)(v152))) goto v25;
    v152 = stack[0];
    v152 = qcar(v152);
    goto v13;

v13:
    v3 = v4;
    v152 = cons(v152, v3);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-2];
    v4 = v152;
    v152 = stack[-1];
    v152 = qcdr(v152);
    stack[-1] = v152;
    v152 = stack[0];
    v152 = qcdr(v152);
    stack[0] = v152;
    goto v28;

v25:
    v152 = stack[-1];
    v152 = qcar(v152);
    goto v13;

v248:
    v152 = v4;
    if (v152 == nil) goto v9;
    v3 = (Lisp_Object)1; /* 0 */
    v152 = v4;
    v152 = qcar(v152);
    if (!(v3 == v152)) goto v9;
    v152 = v4;
    v152 = qcdr(v152);
    v4 = v152;
    goto v248;

v9:
    v152 = v4;
        popv(3);
        return Lnreverse(nil, v152);
/* error exit handlers */
v76:
    popv(3);
    return nil;
}



/* Code for calc_den_tar */

static Lisp_Object CC_calc_den_tar(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_den_tar");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v39 = v2;
    v29 = v23;
/* end of prologue */
    fn = elt(env, 1); /* denlist */
    v39 = (*qfn2(fn))(qenv(fn), v29, v39);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[0];
    v29 = v39;
    v39 = v29;
    if (v39 == nil) goto v129;
    v39 = v29;
    v39 = qcdr(v39);
    if (v39 == nil) goto v86;
    v39 = v29;
    {
        popv(1);
        fn = elt(env, 2); /* constimes */
        return (*qfn1(fn))(qenv(fn), v39);
    }

v86:
    v39 = v29;
    v39 = qcar(v39);
    { popv(1); return onevalue(v39); }

v129:
    v39 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v39); }
/* error exit handlers */
v87:
    popv(1);
    return nil;
}



/* Code for simpquot */

static Lisp_Object CC_simpquot(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v262, v272, v278;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpquot");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v23;
/* end of prologue */
    v262 = stack[-1];
    fn = elt(env, 8); /* simpcar */
    stack[0] = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    v262 = stack[-1];
    v262 = qcdr(v262);
    v262 = qcar(v262);
    fn = elt(env, 9); /* simp */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    stack[-2] = stack[0];
    stack[0] = v262;
    v262 = stack[0];
    v262 = qcar(v262);
    if (v262 == nil) goto v80;
    v272 = qvalue(elt(env, 4)); /* dmode!* */
    v262 = elt(env, 5); /* (!:rd!: !:cr!:) */
    v262 = Lmemq(nil, v272, v262);
    if (v262 == nil) goto v113;
    v262 = stack[0];
    v262 = qcar(v262);
    if (!consp(v262)) goto v121;
    v262 = stack[0];
    v262 = qcar(v262);
    v262 = qcar(v262);
    if (!(!consp(v262))) goto v113;

v121:
    v262 = stack[0];
    v262 = qcdr(v262);
    if (!consp(v262)) goto v6;
    v262 = stack[0];
    v262 = qcdr(v262);
    v262 = qcar(v262);
    if (!(!consp(v262))) goto v113;

v6:
    v262 = stack[-2];
    v262 = qcdr(v262);
    if (!consp(v262)) goto v4;
    v262 = stack[-2];
    v262 = qcdr(v262);
    v262 = qcar(v262);
    if (!(!consp(v262))) goto v113;

v4:
    v262 = stack[0];
    v262 = qcdr(v262);
    fn = elt(env, 10); /* !:onep */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    if (v262 == nil) goto v113;
    v262 = stack[-2];
    v262 = qcdr(v262);
    fn = elt(env, 10); /* !:onep */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    if (v262 == nil) goto v113;
    v262 = stack[-2];
    v262 = qcar(v262);
    if (v262 == nil) goto v245;
    v262 = stack[-2];
    v272 = qcar(v262);
    v262 = stack[0];
    v262 = qcar(v262);
    fn = elt(env, 11); /* divd */
    v262 = (*qfn2(fn))(qenv(fn), v272, v262);
    nil = C_nil;
    if (exception_pending()) goto v133;
    v272 = v262;
    goto v65;

v65:
    v262 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v272, v262);

v245:
    v262 = qvalue(elt(env, 6)); /* nil */
    v272 = v262;
    goto v65;

v113:
    stack[0] = stack[-2];
    v262 = stack[-1];
    v262 = qcdr(v262);
    fn = elt(env, 12); /* simprecip */
    v262 = (*qfn1(fn))(qenv(fn), v262);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    fn = elt(env, 13); /* multsq */
    v262 = (*qfn2(fn))(qenv(fn), stack[0], v262);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-3];
    stack[-1] = v262;
    v262 = qvalue(elt(env, 7)); /* !*modular */
    if (v262 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v262 = stack[-1];
    v262 = qcdr(v262);
    if (!(v262 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v278 = elt(env, 1); /* alg */
    v272 = (Lisp_Object)3217; /* 201 */
    v262 = elt(env, 3); /* "Zero divisor" */
    fn = elt(env, 14); /* rerror */
    v262 = (*qfnn(fn))(qenv(fn), 3, v278, v272, v262);
    nil = C_nil;
    if (exception_pending()) goto v133;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v80:
    v262 = stack[-2];
    v262 = qcar(v262);
    if (v262 == nil) goto v38;
    v278 = elt(env, 1); /* alg */
    v272 = (Lisp_Object)321; /* 20 */
    v262 = elt(env, 3); /* "Zero divisor" */
    {
        popv(4);
        fn = elt(env, 14); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v278, v272, v262);
    }

v38:
    v278 = elt(env, 1); /* alg */
    v272 = (Lisp_Object)305; /* 19 */
    v262 = elt(env, 2); /* "0/0 formed" */
    {
        popv(4);
        fn = elt(env, 14); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v278, v272, v262);
    }
/* error exit handlers */
v133:
    popv(4);
    return nil;
}



/* Code for valuechk */

static Lisp_Object CC_valuechk(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v264, v244, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for valuechk");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v23;
/* end of prologue */
    v244 = stack[-2];
    v264 = elt(env, 1); /* number!-of!-args */
    v264 = get(v244, v264);
    env = stack[-4];
    stack[0] = v264;
    if (v264 == nil) goto v36;
    v264 = stack[-1];
    v244 = Llength(nil, v264);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    v264 = stack[0];
    if (!(equal(v244, v264))) goto v121;

v36:
    v264 = stack[0];
    if (!(v264 == nil)) goto v76;
    v264 = stack[-1];
    if (v264 == nil) goto v76;
    v264 = stack[-1];
    v264 = qcdr(v264);
    if (v264 == nil) goto v76;
    v244 = stack[-2];
    v264 = elt(env, 2); /* !:rd!: */
    v264 = get(v244, v264);
    env = stack[-4];
    if (!(v264 == nil)) goto v121;
    v244 = stack[-2];
    v264 = elt(env, 3); /* !:rn!: */
    v264 = get(v244, v264);
    env = stack[-4];
    if (!(v264 == nil)) goto v121;

v76:
    v244 = stack[-2];
    v264 = stack[-1];
    v264 = cons(v244, v264);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    fn = elt(env, 7); /* opfchk!! */
    v264 = (*qfn1(fn))(qenv(fn), v264);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    stack[-1] = v264;
    v264 = stack[-1];
    if (v264 == nil) goto v0;
    v244 = stack[-1];
    v264 = elt(env, 6); /* list */
    if (!consp(v244)) goto v266;
    v244 = qcar(v244);
    if (!(v244 == v264)) goto v266;
    v101 = stack[-1];
    v244 = (Lisp_Object)17; /* 1 */
    v264 = (Lisp_Object)17; /* 1 */
    v264 = acons(v101, v244, v264);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    v264 = ncons(v264);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    v244 = v264;
    goto v65;

v65:
    v264 = (Lisp_Object)17; /* 1 */
    v264 = cons(v244, v264);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 8); /* znumrnil */
        return (*qfn1(fn))(qenv(fn), v264);
    }

v266:
    v264 = stack[-1];
    v244 = v264;
    goto v65;

v0:
    v264 = nil;
    { popv(5); return onevalue(v264); }

v121:
    stack[-3] = elt(env, 4); /* alg */
    stack[0] = (Lisp_Object)273; /* 17 */
    v244 = elt(env, 5); /* "Wrong number of arguments to" */
    v264 = stack[-2];
    v264 = list2(v244, v264);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    fn = elt(env, 9); /* rerror */
    v264 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v264);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    goto v76;
/* error exit handlers */
v49:
    popv(5);
    return nil;
}



/* Code for ratpoly_ldeg */

static Lisp_Object CC_ratpoly_ldeg(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_ldeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v27 = v23;
/* end of prologue */
    v27 = qcar(v27);
    {
        fn = elt(env, 1); /* numpoly_ldeg */
        return (*qfn1(fn))(qenv(fn), v27);
    }
}



/* Code for vectorrd */

static Lisp_Object MS_CDECL CC_vectorrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vectorrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vectorrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    fn = elt(env, 3); /* matrixrowrd */
    v17 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[0];
    v31 = elt(env, 2); /* mat */
    v17 = list2(v31, v17);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* aeval */
        return (*qfn1(fn))(qenv(fn), v17);
    }
/* error exit handlers */
v86:
    popv(1);
    return nil;
}



/* Code for findelem2 */

static Lisp_Object MS_CDECL CC_findelem2(Lisp_Object env, int nargs,
                         Lisp_Object v23, Lisp_Object v2,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v56, v103, v222, v275;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "findelem2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findelem2");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v23,v2,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v22 = v7;
    v56 = v2;
    v103 = v23;
/* end of prologue */
    v222 = v103;
    v222 = Lconsp(nil, v222);
    env = stack[0];
    if (v222 == nil) goto v11;
    v222 = v103;
    v222 = qcar(v222);
    v275 = elt(env, 1); /* sparsemat */
    if (!(v222 == v275)) goto v11;
    v103 = qcdr(v103);
    v103 = qcar(v103);
    goto v11;

v11:
    v56 = *(Lisp_Object *)((char *)v103 + (CELL-TAG_VECTOR) + ((int32_t)v56/(16/CELL)));
    v22 = Latsoc(nil, v22, v56);
    v56 = v22;
    v22 = v56;
    if (v22 == nil) goto v248;
    v22 = v56;
    v22 = qcdr(v22);
    { popv(1); return onevalue(v22); }

v248:
    v22 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v22); }
}



/* Code for groebcplistmerge */

static Lisp_Object CC_groebcplistmerge(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcplistmerge");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v23;
/* end of prologue */
    v152 = stack[-2];
    if (v152 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v152 = stack[-1];
    if (v152 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v152 = stack[-2];
    v152 = qcar(v152);
    stack[-3] = v152;
    v152 = stack[-1];
    v152 = qcar(v152);
    stack[0] = v152;
    v3 = stack[-3];
    v152 = stack[0];
    fn = elt(env, 1); /* groebcpcompless!? */
    v152 = (*qfn2(fn))(qenv(fn), v3, v152);
    nil = C_nil;
    if (exception_pending()) goto v267;
    env = stack[-4];
    if (v152 == nil) goto v275;
    stack[0] = stack[-3];
    v152 = stack[-2];
    v3 = qcdr(v152);
    v152 = stack[-1];
    v152 = CC_groebcplistmerge(env, v3, v152);
    nil = C_nil;
    if (exception_pending()) goto v267;
    {
        Lisp_Object v281 = stack[0];
        popv(5);
        return cons(v281, v152);
    }

v275:
    v3 = stack[-2];
    v152 = stack[-1];
    v152 = qcdr(v152);
    v152 = CC_groebcplistmerge(env, v3, v152);
    nil = C_nil;
    if (exception_pending()) goto v267;
    {
        Lisp_Object v120 = stack[0];
        popv(5);
        return cons(v120, v152);
    }
/* error exit handlers */
v267:
    popv(5);
    return nil;
}



/* Code for matsm */

static Lisp_Object CC_matsm(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v121 = v23;
/* end of prologue */
    stack[-2] = nil;
    v55 = v121;
    v121 = elt(env, 1); /* matrix */
    fn = elt(env, 3); /* nssimp */
    v121 = (*qfn2(fn))(qenv(fn), v55, v121);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-3];
    stack[-1] = v121;
    goto v35;

v35:
    v121 = stack[-1];
    if (v121 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v121 = stack[-1];
    v121 = qcar(v121);
    v55 = v121;
    v121 = v55;
    stack[0] = qcar(v121);
    v121 = v55;
    v121 = qcdr(v121);
    fn = elt(env, 4); /* matsm1 */
    v121 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-3];
    fn = elt(env, 5); /* multsm */
    v121 = (*qfn2(fn))(qenv(fn), stack[0], v121);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-3];
    v55 = stack[-2];
    if (v55 == nil) goto v143;
    v55 = stack[-2];
    fn = elt(env, 6); /* addm */
    v121 = (*qfn2(fn))(qenv(fn), v55, v121);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-3];
    goto v143;

v143:
    stack[-2] = v121;
    v121 = stack[-1];
    v121 = qcdr(v121);
    stack[-1] = v121;
    goto v35;
/* error exit handlers */
v222:
    popv(4);
    return nil;
}



/* Code for vdp2a */

static Lisp_Object CC_vdp2a(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v23;
/* end of prologue */
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcdr(v28);
    v28 = qcar(v28);
    {
        fn = elt(env, 1); /* dip2a */
        return (*qfn1(fn))(qenv(fn), v28);
    }
}



/* Code for basisformp */

static Lisp_Object CC_basisformp(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basisformp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v23;
/* end of prologue */
    v86 = v32;
    if (!consp(v86)) goto v34;
    v86 = v32;
    v32 = qvalue(elt(env, 2)); /* basisforml!* */
    v86 = Lmemq(nil, v86, v32);
    return onevalue(v86);

v34:
    v86 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v86);
}



/* Code for lispreadp */

static Lisp_Object CC_lispreadp(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispreadp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v36 = v23;
/* end of prologue */
    v81 = elt(env, 1); /* read */
        return Leqcar(nil, v36, v81);
}



/* Code for physoppri */

static Lisp_Object CC_physoppri(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v303, v304, v199, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physoppri");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v23;
/* end of prologue */
    stack[-6] = nil;
    v303 = stack[-8];
    if (symbolp(v303)) goto v81;
    v303 = stack[-8];
    v303 = qcar(v303);
    goto v36;

v36:
    stack[-9] = v303;
    v303 = stack[-8];
    if (symbolp(v303)) goto v13;
    v303 = stack[-8];
    v303 = qcdr(v303);
    goto v33;

v33:
    stack[-7] = v303;
    stack[-5] = elt(env, 0); /* physoppri */
    stack[-4] = elt(env, 2); /* "x= " */
    stack[-3] = stack[-9];
    stack[-2] = elt(env, 3); /* " y= " */
    stack[-1] = stack[-7];
    stack[0] = elt(env, 4); /* "nat= " */
    v199 = elt(env, 5); /* !*nat */
    v304 = elt(env, 6); /* " contract= " */
    v303 = elt(env, 7); /* !*contract */
    v303 = list3(v199, v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = list3star(stack[-2], stack[-1], stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = list3star(stack[-5], stack[-4], stack[-3], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    fn = elt(env, 21); /* trwrite */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = qvalue(elt(env, 5)); /* !*nat */
    if (v303 == nil) goto v142;
    v303 = qvalue(elt(env, 7)); /* !*contract */
    if (!(v303 == nil)) goto v142;
    v303 = stack[-9];
    v303 = Lexplode(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lreverse(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    stack[-9] = v303;
    v303 = stack[-9];
    v304 = Llength(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = (Lisp_Object)33; /* 2 */
    v303 = (Lisp_Object)greaterp2(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    v303 = v303 ? lisp_true : nil;
    env = stack[-10];
    if (v303 == nil) goto v75;
    v303 = stack[-9];
    v303 = qcdr(v303);
    v304 = qcar(v303);
    v303 = elt(env, 14); /* !- */
    if (v304 == v303) goto v272;
    v303 = stack[-9];
    v304 = qcar(v303);
    v303 = elt(env, 16); /* !+ */
    if (v304 == v303) goto v150;
    v303 = stack[-9];
    v303 = Lreverse(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lcompress(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    stack[-9] = v303;
    goto v306;

v306:
    stack[0] = elt(env, 8); /* !" */
    v303 = stack[-9];
    v303 = Lexplode(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    stack[0] = cons(stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = elt(env, 8); /* !" */
    v303 = ncons(v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lappend(nil, stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lcompress(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    stack[-9] = v303;
    v303 = stack[-7];
    if (v303 == nil) goto v307;
    v304 = stack[-9];
    v303 = stack[-7];
    v303 = cons(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    goto v308;

v308:
    stack[-3] = v303;
    stack[-2] = elt(env, 0); /* physoppri */
    stack[-1] = elt(env, 2); /* "x= " */
    stack[0] = stack[-9];
    v200 = elt(env, 17); /* " z= " */
    v199 = stack[-6];
    v304 = elt(env, 18); /* " x1= " */
    v303 = stack[-3];
    v303 = list4(v200, v199, v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = list3star(stack[-2], stack[-1], stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    fn = elt(env, 21); /* trwrite */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = stack[-6];
    if (v303 == nil) goto v309;
    v199 = elt(env, 19); /* expt */
    v304 = stack[-3];
    v303 = stack[-6];
    v199 = list3(v199, v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v304 = elt(env, 19); /* expt */
    v303 = elt(env, 20); /* infix */
    v303 = get(v304, v303);
    env = stack[-10];
    fn = elt(env, 22); /* exptpri */
    v303 = (*qfn2(fn))(qenv(fn), v199, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v309:
    v303 = stack[-9];
    fn = elt(env, 23); /* prin2!* */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = stack[-7];
    if (v303 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v303 = elt(env, 9); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v303; /* obrkp!* */
    v199 = elt(env, 11); /* !*comma!* */
    v304 = (Lisp_Object)1; /* 0 */
    v303 = stack[-7];
    fn = elt(env, 24); /* inprint */
    v303 = (*qfnn(fn))(qenv(fn), 3, v199, v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v303; /* obrkp!* */
    v303 = elt(env, 13); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v307:
    v303 = stack[-9];
    goto v308;

v150:
    v303 = elt(env, 16); /* !+ */
    stack[-6] = v303;
    v304 = stack[-9];
    v303 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 25); /* pnth */
    v303 = (*qfn2(fn))(qenv(fn), v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lreverse(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lcompress(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    stack[-9] = v303;
    goto v306;

v272:
    v304 = elt(env, 14); /* !- */
    v303 = elt(env, 15); /* !1 */
    v303 = list2(v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lcompress(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    stack[-6] = v303;
    v304 = stack[-9];
    v303 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 25); /* pnth */
    v303 = (*qfn2(fn))(qenv(fn), v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lreverse(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lcompress(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    stack[-9] = v303;
    goto v306;

v75:
    v303 = stack[-9];
    v303 = Lreverse(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lcompress(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    stack[-9] = v303;
    goto v306;

v142:
    stack[0] = elt(env, 8); /* !" */
    v303 = stack[-9];
    v303 = Lexplode(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    stack[0] = cons(stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = elt(env, 8); /* !" */
    v303 = ncons(v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lappend(nil, stack[0], v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = Lcompress(nil, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    stack[-9] = v303;
    v303 = stack[-9];
    fn = elt(env, 23); /* prin2!* */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = stack[-7];
    if (v303 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    v303 = elt(env, 9); /* "(" */
    fn = elt(env, 23); /* prin2!* */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 10)) = v303; /* obrkp!* */
    v199 = elt(env, 11); /* !*comma!* */
    v304 = (Lisp_Object)1; /* 0 */
    v303 = stack[-7];
    fn = elt(env, 24); /* inprint */
    v303 = (*qfnn(fn))(qenv(fn), 3, v199, v304, v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    env = stack[-10];
    v303 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 10)) = v303; /* obrkp!* */
    v303 = elt(env, 13); /* ")" */
    fn = elt(env, 23); /* prin2!* */
    v303 = (*qfn1(fn))(qenv(fn), v303);
    nil = C_nil;
    if (exception_pending()) goto v305;
    { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }

v13:
    v303 = qvalue(elt(env, 1)); /* nil */
    goto v33;

v81:
    v303 = stack[-8];
    goto v36;
/* error exit handlers */
v305:
    popv(11);
    return nil;
}



/* Code for incident1 */

static Lisp_Object MS_CDECL CC_incident1(Lisp_Object env, int nargs,
                         Lisp_Object v23, Lisp_Object v2,
                         Lisp_Object v7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v265, v67, v273, v264, v244;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "incident1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for incident1");
#endif
    if (stack >= stacklimit)
    {
        push3(v7,v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v23,v2,v7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v273 = v7;
    v264 = v2;
    v244 = v23;
/* end of prologue */
    v67 = v244;
    v265 = v264;
    v265 = qcar(v265);
    v265 = qcar(v265);
    if (v67 == v265) goto v86;
    v67 = v244;
    v265 = v264;
    v265 = qcdr(v265);
    v265 = qcar(v265);
    v265 = qcar(v265);
    if (v67 == v265) goto v122;
    v67 = v244;
    v265 = v264;
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcar(v265);
    v265 = qcar(v265);
    if (v67 == v265) goto v310;
    v265 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v265); }

v310:
    v265 = v264;
    v265 = qcar(v265);
    stack[-1] = qcar(v265);
    stack[0] = v273;
    v265 = v264;
    v265 = qcdr(v265);
    v265 = qcar(v265);
    v265 = qcar(v265);
    v67 = v273;
    v265 = cons(v265, v67);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-2];
    v265 = ncons(v265);
    nil = C_nil;
    if (exception_pending()) goto v256;
    {
        Lisp_Object v48 = stack[-1];
        Lisp_Object v131 = stack[0];
        popv(3);
        return acons(v48, v131, v265);
    }

v122:
    v265 = v264;
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcar(v265);
    stack[-1] = qcar(v265);
    stack[0] = v273;
    v265 = v264;
    v265 = qcar(v265);
    v265 = qcar(v265);
    v67 = v273;
    v265 = cons(v265, v67);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-2];
    v265 = ncons(v265);
    nil = C_nil;
    if (exception_pending()) goto v256;
    {
        Lisp_Object v49 = stack[-1];
        Lisp_Object v302 = stack[0];
        popv(3);
        return acons(v49, v302, v265);
    }

v86:
    v265 = v264;
    v265 = qcdr(v265);
    v265 = qcar(v265);
    stack[-1] = qcar(v265);
    stack[0] = v273;
    v265 = v264;
    v265 = qcdr(v265);
    v265 = qcdr(v265);
    v265 = qcar(v265);
    v265 = qcar(v265);
    v67 = v273;
    v265 = cons(v265, v67);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-2];
    v265 = ncons(v265);
    nil = C_nil;
    if (exception_pending()) goto v256;
    {
        Lisp_Object v219 = stack[-1];
        Lisp_Object v263 = stack[0];
        popv(3);
        return acons(v219, v263, v265);
    }
/* error exit handlers */
v256:
    popv(3);
    return nil;
}



/* Code for !*a2f */

static Lisp_Object CC_Ha2f(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *a2f");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v27 = v23;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*q2f */
        return (*qfn1(fn))(qenv(fn), v27);
    }
/* error exit handlers */
v146:
    popv(1);
    return nil;
}



/* Code for lx2xx */

static Lisp_Object CC_lx2xx(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lx2xx");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v23;
/* end of prologue */
    v56 = stack[-2];
    if (!consp(v56)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v56 = stack[-2];
    v56 = qcar(v56);
    if (!consp(v56)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v56 = stack[-2];
    v56 = qcar(v56);
    if (!consp(v56)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v56 = stack[-2];
    v56 = qcar(v56);
    v56 = qcar(v56);
    if (!consp(v56)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v56 = stack[-2];
    v56 = qcdr(v56);
    v56 = qcar(v56);
    stack[-3] = v56;
    v56 = stack[-3];
    fn = elt(env, 1); /* lastnondomain */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-4];
    v56 = qcdr(v56);
    stack[-1] = v56;
    v56 = stack[-2];
    stack[0] = qcar(v56);
    v103 = stack[-1];
    v56 = stack[-3];
    fn = elt(env, 2); /* delet */
    v56 = (*qfn2(fn))(qenv(fn), v103, v56);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-4];
    fn = elt(env, 3); /* xxsort */
    v103 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-4];
    v56 = stack[-1];
    v103 = Lappend(nil, v103, v56);
    nil = C_nil;
    if (exception_pending()) goto v269;
    v56 = stack[-2];
    v56 = qcdr(v56);
    v56 = qcdr(v56);
    {
        Lisp_Object v138 = stack[0];
        popv(5);
        return list2star(v138, v103, v56);
    }
/* error exit handlers */
v269:
    popv(5);
    return nil;
}



/* Code for aex_deg */

static Lisp_Object CC_aex_deg(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_deg");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    v80 = v23;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v18 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-1];
    v80 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_deg */
        return (*qfn2(fn))(qenv(fn), v18, v80);
    }
/* error exit handlers */
v84:
    popv(2);
    return nil;
}



/* Code for intervalrd */

static Lisp_Object MS_CDECL CC_intervalrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "intervalrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intervalrd");
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
    fn = elt(env, 4); /* mathml */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    stack[-1] = v77;
    fn = elt(env, 4); /* mathml */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    stack[0] = v77;
    fn = elt(env, 5); /* lex */
    v77 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-2];
    v243 = qvalue(elt(env, 1)); /* char */
    v77 = elt(env, 2); /* (!/ i n t e r v a l) */
    if (equal(v243, v77)) goto v33;
    v243 = elt(env, 3); /* "</interval>" */
    v77 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 6); /* errorml */
    v77 = (*qfn2(fn))(qenv(fn), v243, v77);
    nil = C_nil;
    if (exception_pending()) goto v128;
    v77 = nil;
    { popv(3); return onevalue(v77); }

v33:
    v243 = stack[-1];
    v77 = stack[0];
    popv(3);
    return list2(v243, v77);
/* error exit handlers */
v128:
    popv(3);
    return nil;
}



/* Code for simpdf */

static Lisp_Object CC_simpdf(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v203, v315;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdf");
#endif
    if (stack >= stacklimit)
    {
        push(v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v23);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v23;
/* end of prologue */
    stack[-3] = nil;
    v203 = qvalue(elt(env, 1)); /* subfg!* */
    if (v203 == nil) goto v13;
    v203 = stack[-5];
    v203 = qcdr(v203);
    stack[-6] = v203;
    v203 = stack[-5];
    v203 = qcar(v203);
    fn = elt(env, 9); /* simp!* */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[-5] = v203;
    goto v28;

v28:
    v203 = stack[-6];
    if (v203 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v203 = stack[-5];
    v203 = qcar(v203);
    if (v203 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v203 = stack[-3];
    if (v203 == nil) goto v58;
    v315 = stack[-3];
    v203 = (Lisp_Object)1; /* 0 */
    if (v315 == v203) goto v58;
    v203 = stack[-3];
    goto v82;

v82:
    stack[-4] = v203;
    v203 = stack[-4];
    v315 = qcdr(v203);
    v203 = (Lisp_Object)17; /* 1 */
    if (!(v315 == v203)) goto v155;
    v203 = stack[-4];
    v203 = qcar(v203);
    if (!consp(v203)) goto v155;
    v203 = stack[-4];
    v203 = qcar(v203);
    stack[-2] = v203;
    v203 = stack[-2];
    if (!consp(v203)) goto v316;
    v203 = stack[-2];
    v203 = qcar(v203);
    if (!consp(v203)) goto v316;
    v203 = stack[-2];
    v203 = qcdr(v203);
    if (!(v203 == nil)) goto v255;
    v203 = stack[-2];
    v203 = qcar(v203);
    v315 = qcdr(v203);
    v203 = (Lisp_Object)17; /* 1 */
    if (!(v315 == v203)) goto v255;
    v203 = stack[-2];
    v203 = qcar(v203);
    v203 = qcar(v203);
    v315 = qcdr(v203);
    v203 = (Lisp_Object)17; /* 1 */
    if (!(v315 == v203)) goto v255;
    v203 = stack[-2];
    v203 = qcar(v203);
    v203 = qcar(v203);
    v203 = qcar(v203);
    stack[-4] = v203;
    goto v6;

v6:
    v203 = stack[-6];
    v203 = qcdr(v203);
    stack[-6] = v203;
    v203 = stack[-6];
    if (v203 == nil) goto v252;
    v203 = stack[-6];
    v203 = qcar(v203);
    fn = elt(env, 9); /* simp!* */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[-3] = v203;
    v203 = stack[-3];
    v203 = qcar(v203);
    if (v203 == nil) goto v317;
    v203 = stack[-3];
    fn = elt(env, 10); /* d2int */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[0] = v203;
    if (v203 == nil) goto v40;
    v203 = stack[-6];
    v203 = qcdr(v203);
    stack[-6] = v203;
    v203 = (Lisp_Object)17; /* 1 */
    stack[-1] = v203;
    goto v318;

v318:
    v315 = stack[0];
    v203 = stack[-1];
    v203 = difference2(v315, v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v203 = Lminusp(nil, v203);
    env = stack[-7];
    if (v203 == nil) goto v319;
    v203 = qvalue(elt(env, 7)); /* nil */
    stack[-3] = v203;
    goto v28;

v319:
    v315 = stack[-5];
    v203 = stack[-4];
    fn = elt(env, 11); /* diffsq */
    v203 = (*qfn2(fn))(qenv(fn), v315, v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[-5] = v203;
    v203 = stack[-1];
    v203 = add1(v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[-1] = v203;
    goto v318;

v40:
    v315 = stack[-5];
    v203 = stack[-4];
    fn = elt(env, 11); /* diffsq */
    v203 = (*qfn2(fn))(qenv(fn), v315, v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[-5] = v203;
    goto v28;

v317:
    v203 = stack[-6];
    v203 = qcdr(v203);
    stack[-6] = v203;
    v203 = qvalue(elt(env, 7)); /* nil */
    stack[-3] = v203;
    goto v28;

v252:
    v315 = stack[-5];
    v203 = stack[-4];
    fn = elt(env, 11); /* diffsq */
    v203 = (*qfn2(fn))(qenv(fn), v315, v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    stack[-5] = v203;
    goto v28;

v255:
    v203 = stack[-2];
    fn = elt(env, 12); /* prepf */
    v315 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v203 = elt(env, 8); /* "kernel" */
    fn = elt(env, 13); /* typerr */
    v203 = (*qfn2(fn))(qenv(fn), v315, v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    goto v6;

v316:
    v203 = stack[-2];
    v315 = qcar(v203);
    v203 = elt(env, 4); /* domain!-diff!-fn */
    v203 = get(v315, v203);
    env = stack[-7];
    if (v203 == nil) goto v135;
    stack[-1] = qvalue(elt(env, 5)); /* dmode!* */
    qvalue(elt(env, 5)) = nil; /* dmode!* */
    stack[0] = qvalue(elt(env, 6)); /* alglist!* */
    qvalue(elt(env, 6)) = nil; /* alglist!* */
    v203 = qvalue(elt(env, 7)); /* nil */
    v203 = ncons(v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-7];
    qvalue(elt(env, 6)) = v203; /* alglist!* */
    v203 = stack[-2];
    fn = elt(env, 12); /* prepf */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-7];
    stack[-4] = v203;
    v203 = stack[-4];
    fn = elt(env, 14); /* prekernp */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-7];
    if (!(v203 == nil)) goto v266;
    v315 = stack[-4];
    v203 = elt(env, 8); /* "kernel" */
    fn = elt(env, 13); /* typerr */
    v203 = (*qfn2(fn))(qenv(fn), v315, v203);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-7];
    goto v266;

v266:
    qvalue(elt(env, 6)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 5)) = stack[-1]; /* dmode!* */
    goto v6;

v135:
    v203 = stack[-2];
    fn = elt(env, 12); /* prepf */
    v315 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v203 = elt(env, 8); /* "kernel" */
    fn = elt(env, 13); /* typerr */
    v203 = (*qfn2(fn))(qenv(fn), v315, v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    goto v6;

v155:
    v203 = stack[-4];
    fn = elt(env, 15); /* prepsq */
    v315 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v203 = elt(env, 3); /* "kernel or integer" */
    fn = elt(env, 13); /* typerr */
    v203 = (*qfn2(fn))(qenv(fn), v315, v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    goto v6;

v58:
    v203 = stack[-6];
    v203 = qcar(v203);
    fn = elt(env, 9); /* simp!* */
    v203 = (*qfn1(fn))(qenv(fn), v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    goto v82;

v13:
    v315 = elt(env, 2); /* df */
    v203 = stack[-5];
    v315 = cons(v315, v203);
    nil = C_nil;
    if (exception_pending()) goto v205;
    env = stack[-7];
    v203 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 16); /* mksq */
        return (*qfn2(fn))(qenv(fn), v315, v203);
    }
/* error exit handlers */
v206:
    env = stack[-7];
    qvalue(elt(env, 6)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 5)) = stack[-1]; /* dmode!* */
    popv(8);
    return nil;
v205:
    popv(8);
    return nil;
}



/* Code for ndepends */

static Lisp_Object CC_ndepends(Lisp_Object env,
                         Lisp_Object v23, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ndepends");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v23);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v23,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v23;
/* end of prologue */
    v68 = stack[-1];
    if (v68 == nil) goto v27;
    v68 = stack[-1];
    if (is_number(v68)) goto v27;
    v68 = stack[0];
    if (is_number(v68)) goto v27;
    v250 = stack[-1];
    v68 = stack[0];
    if (equal(v250, v68)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v68 = stack[-1];
    if (!(!consp(v68))) goto v61;
    v250 = stack[-1];
    v68 = qvalue(elt(env, 2)); /* frlis!* */
    v68 = Lmemq(nil, v250, v68);
    if (v68 == nil) goto v61;
    v68 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v68); }

v61:
    v250 = stack[-1];
    v68 = qvalue(elt(env, 4)); /* depl!* */
    v68 = Lassoc(nil, v250, v68);
    v250 = v68;
    v68 = v250;
    if (v68 == nil) goto v21;
    v68 = v250;
    v250 = qcdr(v68);
    v68 = stack[0];
    fn = elt(env, 6); /* lndepends */
    v68 = (*qfn2(fn))(qenv(fn), v250, v68);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    goto v248;

v248:
    if (v68 == nil) goto v143;
    v68 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v68); }

v143:
    v68 = stack[-1];
    if (!consp(v68)) goto v247;
    v68 = stack[-1];
    v68 = qcar(v68);
    if (!(symbolp(v68))) goto v247;
    v68 = stack[-1];
    v250 = qcar(v68);
    v68 = elt(env, 5); /* dname */
    v68 = get(v250, v68);
    env = stack[-2];
    if (v68 == nil) goto v247;
    v68 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v68); }

v247:
    v68 = stack[-1];
    fn = elt(env, 7); /* atomf */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    if (!(v68 == nil)) goto v15;
    v68 = stack[-1];
    v250 = qcdr(v68);
    v68 = stack[0];
    fn = elt(env, 6); /* lndepends */
    v68 = (*qfn2(fn))(qenv(fn), v250, v68);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    if (!(v68 == nil)) goto v1;
    v68 = stack[-1];
    v250 = qcar(v68);
    v68 = stack[0];
    v68 = CC_ndepends(env, v250, v68);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    if (!(v68 == nil)) goto v1;

v15:
    v68 = stack[0];
    fn = elt(env, 7); /* atomf */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    if (!(v68 == nil)) goto v220;
    v68 = stack[0];
    v68 = qcar(v68);
    if (!(symbolp(v68))) goto v110;
    v68 = stack[0];
    v250 = qcar(v68);
    v68 = elt(env, 5); /* dname */
    v68 = get(v250, v68);
    env = stack[-2];
    if (!(v68 == nil)) goto v220;

v110:
    v250 = stack[-1];
    v68 = stack[0];
    v68 = qcdr(v68);
    {
        popv(3);
        fn = elt(env, 8); /* ndependsl */
        return (*qfn2(fn))(qenv(fn), v250, v68);
    }

v220:
    v68 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v68); }

v1:
    v68 = qvalue(elt(env, 3)); /* t */
    { popv(3); return onevalue(v68); }

v21:
    v68 = qvalue(elt(env, 1)); /* nil */
    goto v248;

v27:
    v68 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v68); }
/* error exit handlers */
v105:
    popv(3);
    return nil;
}



/* Code for r2speclist1 */

static Lisp_Object CC_r2speclist1(Lisp_Object env,
                         Lisp_Object v23)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2speclist1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v78 = v23;
/* end of prologue */
    v82 = v78;
    v79 = elt(env, 1); /* times */
    if (!consp(v82)) goto v30;
    v82 = qcar(v82);
    if (!(v82 == v79)) goto v30;
    v79 = v78;
    v79 = qcdr(v79);
    v82 = qcar(v79);
    v79 = v78;
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    v79 = qcar(v79);
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    {
        fn = elt(env, 2); /* r2speclist2 */
        return (*qfnn(fn))(qenv(fn), 3, v82, v79, v78);
    }

v30:
    v79 = (Lisp_Object)17; /* 1 */
    return cons(v79, v78);
}



setup_type const u29_setup[] =
{
    {"matrixrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrd},
    {"prlist",                  CC_prlist,      too_many_1,    wrong_no_1},
    {"suchp",                   CC_suchp,       too_many_1,    wrong_no_1},
    {"diplmon2sq",              too_few_2,      CC_diplmon2sq, wrong_no_2},
    {"gpexpp",                  CC_gpexpp,      too_many_1,    wrong_no_1},
    {"calc_coeffmap_",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_calc_coeffmap_},
    {"quotodd",                 too_few_2,      CC_quotodd,    wrong_no_2},
    {"lieninstruc",             CC_lieninstruc, too_many_1,    wrong_no_1},
    {"groeb=testc1",            CC_groebMtestc1,too_many_1,    wrong_no_1},
    {"diff-k-times-mod-p",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKkKtimesKmodKp},
    {"prepsq*0",                too_few_2,      CC_prepsqH0,   wrong_no_2},
    {"simpexpt2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt2},
    {"replace-next",            too_few_2,      CC_replaceKnext,wrong_no_2},
    {"mk+outer+list",           CC_mkLouterLlist,too_many_1,   wrong_no_1},
    {"matrixelems",             CC_matrixelems, too_many_1,    wrong_no_1},
    {"f4",                      CC_f4,          too_many_1,    wrong_no_1},
    {"insertocc",               too_few_2,      CC_insertocc,  wrong_no_2},
    {"exdf0",                   CC_exdf0,       too_many_1,    wrong_no_1},
    {"gfplus",                  too_few_2,      CC_gfplus,     wrong_no_2},
    {"gpargp",                  CC_gpargp,      too_many_1,    wrong_no_1},
    {"s_world_names",           CC_s_world_names,too_many_1,   wrong_no_1},
    {"tayexp-max2",             too_few_2,      CC_tayexpKmax2,wrong_no_2},
    {"my+nullsq+p",             CC_myLnullsqLp, too_many_1,    wrong_no_1},
    {"ctx_new",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_ctx_new},
    {"lowupperlimitrd",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_lowupperlimitrd},
    {"ldf-dep-var",             CC_ldfKdepKvar, too_many_1,    wrong_no_1},
    {"findoptrow",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_findoptrow},
    {"o-nextarg",               CC_oKnextarg,   too_many_1,    wrong_no_1},
    {"dipcontevmin",            too_few_2,      CC_dipcontevmin,wrong_no_2},
    {"calc_den_tar",            too_few_2,      CC_calc_den_tar,wrong_no_2},
    {"simpquot",                CC_simpquot,    too_many_1,    wrong_no_1},
    {"valuechk",                too_few_2,      CC_valuechk,   wrong_no_2},
    {"ratpoly_ldeg",            CC_ratpoly_ldeg,too_many_1,    wrong_no_1},
    {"vectorrd",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_vectorrd},
    {"findelem2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_findelem2},
    {"groebcplistmerge",        too_few_2,      CC_groebcplistmerge,wrong_no_2},
    {"matsm",                   CC_matsm,       too_many_1,    wrong_no_1},
    {"vdp2a",                   CC_vdp2a,       too_many_1,    wrong_no_1},
    {"basisformp",              CC_basisformp,  too_many_1,    wrong_no_1},
    {"lispreadp",               CC_lispreadp,   too_many_1,    wrong_no_1},
    {"physoppri",               CC_physoppri,   too_many_1,    wrong_no_1},
    {"incident1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_incident1},
    {"*a2f",                    CC_Ha2f,        too_many_1,    wrong_no_1},
    {"lx2xx",                   CC_lx2xx,       too_many_1,    wrong_no_1},
    {"aex_deg",                 too_few_2,      CC_aex_deg,    wrong_no_2},
    {"intervalrd",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_intervalrd},
    {"simpdf",                  CC_simpdf,      too_many_1,    wrong_no_1},
    {"ndepends",                too_few_2,      CC_ndepends,   wrong_no_2},
    {"r2speclist1",             CC_r2speclist1, too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u29", (two_args *)"12320 4389050 3205312", 0}
};

/* end of generated code */
