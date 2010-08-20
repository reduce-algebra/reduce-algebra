
/* $destdir/generated-c\u55.c Machine generated C code */

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


/* Code for in_list1 */

static Lisp_Object CC_in_list1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for in_list1");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v23 = qvalue(elt(env, 1)); /* !*echo */
    stack[-1] = v23;
    v23 = qvalue(elt(env, 2)); /* !*reduce4 */
    if (v23 == nil) goto v26;
    v23 = stack[-3];
    fn = elt(env, 12); /* type */
    v24 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    v23 = elt(env, 3); /* string */
    if (v24 == v23) goto v28;
    v24 = stack[-3];
    v23 = elt(env, 3); /* string */
    fn = elt(env, 13); /* typerr */
    v23 = (*qfn2(fn))(qenv(fn), v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    goto v26;

v26:
    v23 = stack[-3];
    fn = elt(env, 14); /* mkfil!* */
    v24 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    stack[-3] = v24;
    v23 = elt(env, 4); /* input */
    fn = elt(env, 15); /* open */
    v23 = (*qfn2(fn))(qenv(fn), v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    stack[-4] = v23;
    v23 = stack[-4];
    v23 = Lrds(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    stack[0] = v23;
    v24 = stack[-3];
    v23 = qvalue(elt(env, 5)); /* linelist!* */
    v23 = Lassoc(nil, v24, v23);
    if (!(v23 == nil)) goto v29;

v29:
    v23 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 7)) = v23; /* curline!* */
    v25 = stack[-3];
    v24 = stack[-4];
    v23 = (Lisp_Object)17; /* 1 */
    v23 = list3(v25, v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    qvalue(elt(env, 8)) = v23; /* ifl!* */
    v24 = qvalue(elt(env, 8)); /* ifl!* */
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    v23 = cons(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    qvalue(elt(env, 9)) = v23; /* ipl!* */
    v23 = stack[-2];
    qvalue(elt(env, 1)) = v23; /* !*echo */
    fn = elt(env, 16); /* begin1 */
    v23 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    v23 = stack[0];
    v23 = Lrds(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    v23 = stack[-4];
    v23 = Lclose(nil, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    v23 = stack[-1];
    qvalue(elt(env, 1)) = v23; /* !*echo */
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    if (!(v23 == nil)) goto v30;
    v23 = qvalue(elt(env, 10)); /* contl!* */
    if (v23 == nil) goto v30;
    v23 = qvalue(elt(env, 6)); /* nil */
    { popv(6); return onevalue(v23); }

v30:
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    if (v23 == nil) goto v31;
    v24 = stack[-3];
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    v23 = qcar(v23);
    v23 = qcar(v23);
    if (!(v24 == v23)) goto v31;
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    v23 = qcdr(v23);
    qvalue(elt(env, 9)) = v23; /* ipl!* */
    goto v32;

v32:
    v23 = nil;
    { popv(6); return onevalue(v23); }

v31:
    v25 = elt(env, 11); /* "FILE STACK CONFUSION" */
    v24 = stack[-3];
    v23 = qvalue(elt(env, 9)); /* ipl!* */
    v23 = list3(v25, v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    fn = elt(env, 17); /* rederr */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    goto v32;

v28:
    v23 = stack[-3];
    fn = elt(env, 18); /* value */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    stack[-3] = v23;
    goto v26;
/* error exit handlers */
v27:
    popv(6);
    return nil;
}



/* Code for ps!:sqrt!-erule */

static Lisp_Object CC_psTsqrtKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v82, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:sqrt-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v1;
    v81 = v0;
/* end of prologue */
    v81 = qcdr(v81);
    v81 = qcar(v81);
    stack[-8] = v81;
    v82 = qvalue(elt(env, 1)); /* nil */
    v81 = (Lisp_Object)17; /* 1 */
    v81 = cons(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    stack[0] = v81;
    v81 = stack[-8];
    fn = elt(env, 4); /* ps!:order */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    stack[-5] = v81;
    v81 = qvalue(elt(env, 2)); /* ps */
    fn = elt(env, 4); /* ps!:order */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    stack[-6] = v81;
    v82 = stack[-7];
    v81 = stack[-6];
    if (equal(v82, v81)) goto v17;
    v81 = (Lisp_Object)17; /* 1 */
    stack[-4] = v81;
    goto v85;

v85:
    v82 = stack[-7];
    v81 = stack[-6];
    v82 = difference2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    v81 = stack[-4];
    v81 = difference2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    v81 = Lminusp(nil, v81);
    env = stack[-9];
    if (v81 == nil) goto v86;
    stack[-1] = stack[0];
    stack[0] = (Lisp_Object)33; /* 2 */
    v82 = stack[-7];
    v81 = stack[-6];
    v81 = difference2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    v82 = times2(stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    v81 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    v82 = stack[-8];
    v81 = stack[-5];
    fn = elt(env, 5); /* ps!:evaluate */
    v81 = (*qfn2(fn))(qenv(fn), v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    fn = elt(env, 6); /* multsq */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    {
        Lisp_Object v87 = stack[-1];
        popv(10);
        fn = elt(env, 7); /* quotsq */
        return (*qfn2(fn))(qenv(fn), v87, v81);
    }

v86:
    stack[-3] = stack[0];
    v82 = stack[-4];
    v81 = (Lisp_Object)49; /* 3 */
    stack[0] = times2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    v82 = (Lisp_Object)33; /* 2 */
    v81 = stack[-7];
    v81 = times2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    v82 = difference2(stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    v81 = stack[-5];
    v81 = plus2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    v83 = v81;
    v82 = v83;
    v81 = (Lisp_Object)1; /* 0 */
    if (v82 == v81) goto v24;
    v81 = v83;
    v82 = v81;
    goto v88;

v88:
    v81 = (Lisp_Object)17; /* 1 */
    stack[-2] = cons(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    stack[0] = stack[-8];
    v82 = stack[-4];
    v81 = stack[-5];
    v81 = plus2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    fn = elt(env, 5); /* ps!:evaluate */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    stack[0] = qvalue(elt(env, 2)); /* ps */
    v82 = stack[-7];
    v81 = stack[-4];
    v81 = difference2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    fn = elt(env, 5); /* ps!:evaluate */
    v81 = (*qfn2(fn))(qenv(fn), stack[0], v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    fn = elt(env, 6); /* multsq */
    v81 = (*qfn2(fn))(qenv(fn), stack[-1], v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    fn = elt(env, 6); /* multsq */
    v81 = (*qfn2(fn))(qenv(fn), stack[-2], v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    fn = elt(env, 8); /* addsq */
    v81 = (*qfn2(fn))(qenv(fn), stack[-3], v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    stack[0] = v81;
    v81 = stack[-4];
    v81 = add1(v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    stack[-4] = v81;
    goto v85;

v24:
    v81 = qvalue(elt(env, 1)); /* nil */
    v82 = v81;
    goto v88;

v17:
    v82 = stack[-8];
    v81 = stack[-5];
    fn = elt(env, 5); /* ps!:evaluate */
    v81 = (*qfn2(fn))(qenv(fn), v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    fn = elt(env, 9); /* prepsqxx */
    v82 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    v81 = elt(env, 3); /* (quotient 1 2) */
    v81 = list2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-9];
    {
        popv(10);
        fn = elt(env, 10); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v81);
    }
/* error exit handlers */
v84:
    popv(10);
    return nil;
}



/* Code for symbid */

static Lisp_Object CC_symbid(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98, v46, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbid");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v46 = v1;
    stack[0] = v0;
/* end of prologue */
    v97 = qvalue(elt(env, 1)); /* fname!* */
    if (v97 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v98 = qvalue(elt(env, 2)); /* ftype!* */
    v97 = elt(env, 3); /* (macro smacro) */
    v97 = Lmemq(nil, v98, v97);
    if (!(v97 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v97 = stack[0];
    v98 = v46;
    v97 = Latsoc(nil, v97, v98);
    if (!(v97 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v97 = stack[0];
    v97 = Lsymbol_specialp(nil, v97);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    if (!(v97 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v97 = stack[0];
    v97 = Lsymbol_globalp(nil, v97);
    env = stack[-1];
    if (!(v97 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v97 = stack[0];
    if (v97 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v98 = stack[0];
    v97 = qvalue(elt(env, 4)); /* t */
    if (v98 == v97) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v98 = stack[0];
    v97 = elt(env, 5); /* share */
    v97 = Lflagp(nil, v98, v97);
    env = stack[-1];
    if (!(v97 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v97 = qvalue(elt(env, 6)); /* !*comp */
    if (!(v97 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v97 = qvalue(elt(env, 7)); /* !*cref */
    if (!(v97 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v98 = stack[0];
    v97 = elt(env, 8); /* constant!? */
    v97 = get(v98, v97);
    env = stack[-1];
    if (!(v97 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v47 = elt(env, 9); /* "nonlocal use of undeclared variable" */
    v46 = stack[0];
    v98 = elt(env, 10); /* "in procedure" */
    v97 = qvalue(elt(env, 1)); /* fname!* */
    v97 = list4(v47, v46, v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    fn = elt(env, 11); /* lprim */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v99;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v99:
    popv(2);
    return nil;
}



/* Code for compex */

static Lisp_Object CC_compex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compex");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v17 = v0;
/* end of prologue */
    stack[-3] = v17;
    v17 = stack[-3];
    if (v17 == nil) goto v103;
    v17 = stack[-3];
    v17 = qcar(v17);
    fn = elt(env, 2); /* constrexp */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v17 = ncons(v17);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    stack[-1] = v17;
    stack[-2] = v17;
    goto v104;

v104:
    v17 = stack[-3];
    v17 = qcdr(v17);
    stack[-3] = v17;
    v17 = stack[-3];
    if (v17 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v17 = stack[-3];
    v17 = qcar(v17);
    fn = elt(env, 2); /* constrexp */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v17 = ncons(v17);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v17 = Lrplacd(nil, stack[0], v17);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v17 = stack[-1];
    v17 = qcdr(v17);
    stack[-1] = v17;
    goto v104;

v103:
    v17 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v17); }
/* error exit handlers */
v78:
    popv(5);
    return nil;
}



/* Code for num */

static Lisp_Object CC_num(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v106 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[0];
    v107 = qcar(v106);
    v106 = (Lisp_Object)17; /* 1 */
    v106 = cons(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v106);
    }
/* error exit handlers */
v95:
    popv(1);
    return nil;
}



/* Code for mx */

static Lisp_Object CC_mx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mx");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v95 = stack[0];
    v95 = qcar(v95);
    fn = elt(env, 1); /* reval */
    stack[-1] = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    v95 = stack[0];
    v95 = qcdr(v95);
    v95 = qcar(v95);
    fn = elt(env, 1); /* reval */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    {
        Lisp_Object v80 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* pm_m1 */
        return (*qfn2(fn))(qenv(fn), v80, v95);
    }
/* error exit handlers */
v79:
    popv(3);
    return nil;
}



/* Code for gtraversopairlist */

static Lisp_Object MS_CDECL CC_gtraversopairlist(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v84, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "gtraversopairlist");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gtraversopairlist");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v102;
    stack[0] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-3] = nil;
    stack[-2] = nil;
    v84 = stack[-6];
    v125 = stack[-5];
    fn = elt(env, 6); /* gtraversopairsdiscard1 */
    v125 = (*qfn2(fn))(qenv(fn), v84, v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    stack[-5] = v125;
    v125 = stack[-6];
    v125 = qcdr(v125);
    v125 = qcar(v125);
    stack[-4] = v125;
    v125 = stack[0];
    stack[-1] = v125;
    goto v94;

v94:
    v125 = stack[-1];
    if (v125 == nil) goto v22;
    v125 = stack[-1];
    v125 = qcar(v125);
    stack[0] = v125;
    v84 = stack[-4];
    v125 = stack[0];
    v125 = qcdr(v125);
    v125 = qcar(v125);
    stack[-7] = v125;
    fn = elt(env, 7); /* groebbuchcrit4t */
    v125 = (*qfn2(fn))(qenv(fn), v84, v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    if (v125 == nil) goto v15;
    v125 = qvalue(elt(env, 2)); /* gmodule!* */
    if (v125 == nil) goto v127;
    v87 = stack[-7];
    v84 = stack[-4];
    v125 = qvalue(elt(env, 2)); /* gmodule!* */
    fn = elt(env, 8); /* gevcompatible1 */
    v125 = (*qfnn(fn))(qenv(fn), 3, v87, v84, v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    if (!(v125 == nil)) goto v127;

v128:
    v125 = stack[-1];
    v125 = qcdr(v125);
    stack[-1] = v125;
    goto v94;

v127:
    v84 = stack[0];
    v125 = stack[-6];
    fn = elt(env, 9); /* groebmakepair */
    v84 = (*qfn2(fn))(qenv(fn), v84, v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v125 = stack[-2];
    v125 = cons(v84, v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    stack[-2] = v125;
    goto v128;

v15:
    v84 = stack[-4];
    v125 = stack[-7];
    fn = elt(env, 10); /* vevlcm */
    v84 = (*qfn2(fn))(qenv(fn), v84, v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v125 = stack[-3];
    v125 = cons(v84, v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    stack[-3] = v125;
    goto v128;

v22:
    v125 = stack[-3];
    stack[-3] = v125;
    goto v129;

v129:
    v125 = stack[-3];
    if (v125 == nil) goto v130;
    v125 = stack[-3];
    v125 = qcar(v125);
    stack[-1] = v125;
    v125 = stack[-2];
    stack[0] = v125;
    goto v131;

v131:
    v125 = stack[0];
    if (v125 == nil) goto v132;
    v125 = stack[0];
    v125 = qcar(v125);
    v87 = v125;
    v125 = v87;
    v84 = qcar(v125);
    v125 = stack[-1];
    if (!(equal(v84, v125))) goto v133;
    v84 = v87;
    v125 = stack[-2];
    v125 = Ldelete(nil, v84, v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    stack[-2] = v125;
    goto v133;

v133:
    v125 = stack[0];
    v125 = qcdr(v125);
    stack[0] = v125;
    goto v131;

v132:
    v125 = stack[-3];
    v125 = qcdr(v125);
    stack[-3] = v125;
    goto v129;

v130:
    v125 = qvalue(elt(env, 3)); /* !*gtraverso!-sloppy */
    if (v125 == nil) goto v58;
    v125 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 4)) = v125; /* !*gsugar */
    goto v58;

v58:
    v125 = stack[-2];
    fn = elt(env, 11); /* groebcplistsort */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    stack[-2] = v125;
    v125 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 4)) = v125; /* !*gsugar */
    v125 = stack[-2];
    v84 = v125;
    v125 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v125;
    v125 = v84;
    stack[-3] = v125;
    goto v134;

v134:
    v125 = stack[-3];
    if (v125 == nil) goto v135;
    v125 = stack[-3];
    v125 = qcar(v125);
    stack[-1] = v125;
    v125 = qvalue(elt(env, 1)); /* nil */
    v84 = v125;
    v125 = stack[-2];
    stack[0] = v125;
    goto v136;

v136:
    v125 = stack[0];
    if (v125 == nil) goto v137;
    v125 = stack[0];
    v125 = qcar(v125);
    if (!(v84 == nil)) goto v138;
    v84 = stack[-1];
    v84 = qcar(v84);
    v125 = qcar(v125);
    fn = elt(env, 12); /* vevmtest!? */
    v125 = (*qfn2(fn))(qenv(fn), v84, v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    v84 = v125;
    goto v138;

v138:
    v125 = stack[0];
    v125 = qcdr(v125);
    stack[0] = v125;
    goto v136;

v137:
    v125 = v84;
    if (!(v125 == nil)) goto v139;
    v84 = stack[-1];
    v125 = stack[-2];
    fn = elt(env, 13); /* groebcplistsortin */
    v125 = (*qfn2(fn))(qenv(fn), v84, v125);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-8];
    stack[-2] = v125;
    goto v139;

v139:
    v125 = stack[-3];
    v125 = qcdr(v125);
    stack[-3] = v125;
    goto v134;

v135:
    v84 = stack[-5];
    v125 = stack[-2];
    v125 = Lnreverse(nil, v125);
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 14); /* groebcplistmerge */
        return (*qfn2(fn))(qenv(fn), v84, v125);
    }
/* error exit handlers */
v126:
    popv(9);
    return nil;
}



/* Code for rrest */

static Lisp_Object CC_rrest(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rrest");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v71 = elt(env, 1); /* cdr */
    v70 = stack[-1];
    v70 = cons(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-5];
    fn = elt(env, 6); /* argnochk */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-5];
    v70 = stack[-1];
    v70 = qcar(v70);
    stack[-1] = v70;
    v70 = stack[-1];
    fn = elt(env, 7); /* listeval0 */
    v71 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-5];
    stack[0] = v71;
    v70 = elt(env, 2); /* list */
    if (!consp(v71)) goto v19;
    v71 = qcar(v71);
    if (!(v71 == v70)) goto v19;

v147:
    v70 = stack[0];
    v70 = qcdr(v70);
    if (v70 == nil) goto v148;
    stack[-4] = elt(env, 2); /* list */
    v70 = stack[0];
    v70 = qcdr(v70);
    v70 = qcdr(v70);
    stack[-3] = v70;
    v70 = stack[-3];
    if (v70 == nil) goto v97;
    v70 = stack[-3];
    v70 = qcar(v70);
    fn = elt(env, 8); /* reval */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-5];
    v70 = ncons(v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-5];
    stack[-1] = v70;
    stack[-2] = v70;
    goto v73;

v73:
    v70 = stack[-3];
    v70 = qcdr(v70);
    stack[-3] = v70;
    v70 = stack[-3];
    if (v70 == nil) goto v149;
    stack[0] = stack[-1];
    v70 = stack[-3];
    v70 = qcar(v70);
    fn = elt(env, 8); /* reval */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-5];
    v70 = ncons(v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-5];
    v70 = Lrplacd(nil, stack[0], v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-5];
    v70 = stack[-1];
    v70 = qcdr(v70);
    stack[-1] = v70;
    goto v73;

v149:
    v70 = stack[-2];
    goto v72;

v72:
    {
        Lisp_Object v3 = stack[-4];
        popv(6);
        return cons(v3, v70);
    }

v97:
    v70 = qvalue(elt(env, 5)); /* nil */
    goto v72;

v148:
    v71 = stack[-1];
    v70 = elt(env, 4); /* "non-empty list" */
    fn = elt(env, 9); /* typerr */
    v70 = (*qfn2(fn))(qenv(fn), v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    v70 = nil;
    { popv(6); return onevalue(v70); }

v19:
    v70 = stack[-1];
    fn = elt(env, 10); /* aeval */
    v71 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-5];
    stack[0] = v71;
    v70 = elt(env, 2); /* list */
    if (!consp(v71)) goto v150;
    v71 = qcar(v71);
    if (v71 == v70) goto v147;
    else goto v150;

v150:
    v71 = stack[-1];
    v70 = elt(env, 3); /* "list" */
    fn = elt(env, 9); /* typerr */
    v70 = (*qfn2(fn))(qenv(fn), v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-5];
    goto v147;
/* error exit handlers */
v2:
    popv(6);
    return nil;
}



/* Code for drop_dec_with */

static Lisp_Object MS_CDECL CC_drop_dec_with(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v6, v67;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "drop_dec_with");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for drop_dec_with");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v102;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    v141 = stack[-2];
    if (v141 == nil) goto v22;
    v6 = stack[-3];
    v141 = elt(env, 1); /* dec_with_rl */
    v141 = get(v6, v141);
    env = stack[-6];
    goto v159;

v159:
    stack[-1] = v141;
    goto v100;

v100:
    v141 = stack[-1];
    if (v141 == nil) goto v28;
    v141 = stack[-1];
    v141 = qcar(v141);
    stack[0] = v141;
    v6 = stack[-4];
    v141 = stack[0];
    v141 = Ldelete(nil, v6, v141);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[0] = v141;
    v141 = stack[0];
    v6 = Llength(nil, v141);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    v141 = (Lisp_Object)17; /* 1 */
    v141 = (Lisp_Object)greaterp2(v6, v141);
    nil = C_nil;
    if (exception_pending()) goto v71;
    v141 = v141 ? lisp_true : nil;
    env = stack[-6];
    if (v141 == nil) goto v148;
    v6 = stack[0];
    v141 = stack[-5];
    v141 = cons(v6, v141);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-6];
    stack[-5] = v141;
    goto v148;

v148:
    v141 = stack[-1];
    v141 = qcdr(v141);
    stack[-1] = v141;
    goto v100;

v28:
    v141 = stack[-2];
    if (v141 == nil) goto v160;
    v67 = stack[-3];
    v6 = elt(env, 1); /* dec_with_rl */
    v141 = stack[-5];
    v141 = Lputprop(nil, 3, v67, v6, v141);
    nil = C_nil;
    if (exception_pending()) goto v71;
    goto v86;

v86:
    v141 = nil;
    { popv(7); return onevalue(v141); }

v160:
    v67 = stack[-3];
    v6 = elt(env, 2); /* dec_with */
    v141 = stack[-5];
    v141 = Lputprop(nil, 3, v67, v6, v141);
    nil = C_nil;
    if (exception_pending()) goto v71;
    goto v86;

v22:
    v6 = stack[-3];
    v141 = elt(env, 2); /* dec_with */
    v141 = get(v6, v141);
    env = stack[-6];
    goto v159;
/* error exit handlers */
v71:
    popv(7);
    return nil;
}



/* Code for dpropagator */

static Lisp_Object MS_CDECL CC_dpropagator(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v118, v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dpropagator");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dpropagator");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v102;
    v120 = v1;
    v118 = v0;
/* end of prologue */
    fn = elt(env, 2); /* propagator */
    v120 = (*qfn2(fn))(qenv(fn), v118, v120);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-5];
    v165 = v120;
    v118 = v165;
    v120 = (Lisp_Object)1; /* 0 */
    if (v118 == v120) { popv(6); return onevalue(v165); }
    v118 = v165;
    v120 = (Lisp_Object)17; /* 1 */
    if (v118 == v120) goto v100;
    v120 = v165;
    v120 = qcdr(v120);
    stack[-4] = v120;
    v120 = stack[-4];
    if (v120 == nil) goto v166;
    v120 = stack[-4];
    v120 = qcar(v120);
    v118 = v120;
    v120 = stack[-3];
    fn = elt(env, 3); /* mod!-index */
    v120 = (*qfn2(fn))(qenv(fn), v118, v120);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-5];
    v120 = ncons(v120);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-5];
    stack[-1] = v120;
    stack[-2] = v120;
    goto v78;

v78:
    v120 = stack[-4];
    v120 = qcdr(v120);
    stack[-4] = v120;
    v120 = stack[-4];
    if (v120 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v120 = stack[-4];
    v120 = qcar(v120);
    v118 = v120;
    v120 = stack[-3];
    fn = elt(env, 3); /* mod!-index */
    v120 = (*qfn2(fn))(qenv(fn), v118, v120);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-5];
    v120 = ncons(v120);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-5];
    v120 = Lrplacd(nil, stack[0], v120);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-5];
    v120 = stack[-1];
    v120 = qcdr(v120);
    stack[-1] = v120;
    goto v78;

v166:
    v120 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v120); }

v100:
    v118 = qvalue(elt(env, 1)); /* nil */
    v120 = stack[-3];
    popv(6);
    return cons(v118, v120);
/* error exit handlers */
v141:
    popv(6);
    return nil;
}



/* Code for frlp */

static Lisp_Object CC_frlp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v146, v167;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for frlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v146 = v0;
/* end of prologue */

v168:
    v94 = v146;
    v94 = (v94 == nil ? lisp_true : nil);
    if (!(v94 == nil)) return onevalue(v94);
    v94 = v146;
    v167 = qcar(v94);
    v94 = qvalue(elt(env, 1)); /* frlis!* */
    v94 = Lmemq(nil, v167, v94);
    if (v94 == nil) goto v112;
    v94 = v146;
    v94 = qcdr(v94);
    v146 = v94;
    goto v168;

v112:
    v94 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v94);
}



/* Code for put!-kvalue */

static Lisp_Object MS_CDECL CC_putKkvalue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "put-kvalue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for put-kvalue");
#endif
    if (stack >= stacklimit)
    {
        push4(v11,v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v102,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v11;
    stack[-2] = v102;
    stack[-3] = v1;
    stack[0] = v0;
/* end of prologue */
    v14 = stack[-1];
    v140 = elt(env, 1); /* !*sq */
    if (!consp(v14)) goto v28;
    v14 = qcar(v14);
    if (!(v14 == v140)) goto v28;
    v14 = stack[-2];
    v140 = stack[-1];
    v140 = qcdr(v140);
    v140 = qcar(v140);
    fn = elt(env, 3); /* sq_member */
    v140 = (*qfn2(fn))(qenv(fn), v14, v140);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    goto v159;

v159:
    if (v140 == nil) goto v18;
    v140 = stack[-2];
    {
        popv(6);
        fn = elt(env, 4); /* recursiveerror */
        return (*qfn1(fn))(qenv(fn), v140);
    }

v18:
    stack[-4] = stack[0];
    stack[0] = elt(env, 2); /* kvalue */
    v14 = stack[-2];
    v140 = stack[-1];
    v140 = list2(v14, v140);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    fn = elt(env, 5); /* aconc */
    v140 = (*qfn2(fn))(qenv(fn), stack[-3], v140);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v89 = stack[-4];
        Lisp_Object v86 = stack[0];
        popv(6);
        return Lputprop(nil, 3, v89, v86, v140);
    }

v28:
    v14 = stack[-2];
    v140 = stack[-1];
    fn = elt(env, 6); /* smember */
    v140 = (*qfn2(fn))(qenv(fn), v14, v140);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-5];
    goto v159;
/* error exit handlers */
v90:
    popv(6);
    return nil;
}



/* Code for restorealldfs */

static Lisp_Object CC_restorealldfs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for restorealldfs");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v92 = v0;
/* end of prologue */
    fn = elt(env, 2); /* fullcopy */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    stack[-2] = v92;
    v92 = stack[-2];
    stack[-1] = v92;
    goto v104;

v104:
    v92 = stack[-2];
    if (!consp(v92)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v92 = stack[-2];
    v92 = qcar(v92);
    if (!consp(v92)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v92 = stack[-2];
    v92 = qcar(v92);
    v92 = qcar(v92);
    v92 = qcar(v92);
    if (!consp(v92)) goto v105;
    v92 = stack[-2];
    v92 = qcar(v92);
    v92 = qcar(v92);
    v92 = qcar(v92);
    v153 = qcar(v92);
    v92 = elt(env, 1); /* translate2 */
    v92 = get(v153, v92);
    env = stack[-3];
    v153 = v92;
    if (v92 == nil) goto v105;
    v92 = stack[-2];
    v92 = qcar(v92);
    stack[0] = qcar(v92);
    v92 = v153;
    v153 = qcar(v92);
    v92 = stack[-2];
    v92 = qcar(v92);
    v92 = qcar(v92);
    v92 = qcar(v92);
    v92 = Lapply1(nil, v153, v92);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    fn = elt(env, 3); /* setcar */
    v92 = (*qfn2(fn))(qenv(fn), stack[0], v92);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-3];
    goto v105;

v105:
    v92 = stack[-2];
    v92 = qcar(v92);
    v92 = qcdr(v92);
    stack[-2] = v92;
    goto v104;
/* error exit handlers */
v140:
    popv(4);
    return nil;
}



/* Code for canonical */

static Lisp_Object CC_canonical(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for canonical");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*distribute */
    qvalue(elt(env, 1)) = nil; /* !*distribute */
    v74 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v74;
    v74 = stack[-2];
    v74 = qcar(v74);
    fn = elt(env, 5); /* simp!* */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    stack[-2] = v74;
    v74 = stack[-2];
    v74 = qcdr(v74);
    stack[-3] = v74;
    v74 = elt(env, 3); /* distribute */
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    fn = elt(env, 6); /* on */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v74 = stack[-2];
    v74 = qcar(v74);
    fn = elt(env, 7); /* distri_pol */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    stack[-2] = v74;
    goto v164;

v164:
    v74 = stack[-2];
    if (!consp(v74)) goto v170;
    v74 = stack[-2];
    v74 = qcar(v74);
    if (!consp(v74)) goto v170;
    v74 = stack[-2];
    v74 = qcar(v74);
    v74 = ncons(v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    fn = elt(env, 8); /* dv_canon_monomial */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    fn = elt(env, 9); /* addf */
    v74 = (*qfn2(fn))(qenv(fn), stack[-1], v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    stack[-1] = v74;
    v74 = stack[-2];
    v74 = qcdr(v74);
    stack[-2] = v74;
    goto v164;

v170:
    v75 = stack[-1];
    v74 = stack[-2];
    fn = elt(env, 9); /* addf */
    v74 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    stack[-1] = v74;
    stack[-2] = elt(env, 4); /* !*sq */
    v75 = stack[-1];
    v74 = stack[-3];
    v75 = cons(v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    v74 = qvalue(elt(env, 2)); /* nil */
    v74 = list3(stack[-2], v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    fn = elt(env, 5); /* simp!* */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*distribute */
    { popv(5); return onevalue(v74); }
/* error exit handlers */
v7:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*distribute */
    popv(5);
    return nil;
}



/* Code for pseudo!-divide */

static Lisp_Object CC_pseudoKdivide(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pseudo-divide");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v106 = v0;
/* end of prologue */
    v95 = v106;
    v107 = qvalue(elt(env, 1)); /* nil */
    v106 = qvalue(elt(env, 2)); /* t */
    {
        fn = elt(env, 3); /* poly!-divide!* */
        return (*qfnn(fn))(qenv(fn), 3, v95, v107, v106);
    }
}



/* Code for evalwhereexp */

static Lisp_Object CC_evalwhereexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalwhereexp");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v93 = v0;
/* end of prologue */
    v76 = v93;
    v76 = qcar(v76);
    stack[-2] = qcdr(v76);
    stack[-1] = elt(env, 1); /* aeval */
    stack[0] = elt(env, 1); /* aeval */
    v76 = v93;
    v93 = qcdr(v76);
    v76 = elt(env, 2); /* where */
    fn = elt(env, 4); /* carx */
    v76 = (*qfn2(fn))(qenv(fn), v93, v76);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    v76 = list2(stack[0], v76);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    v76 = Lmkquote(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    v76 = list2(stack[-1], v76);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    v93 = list2(stack[-2], v76);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-3];
    v76 = qvalue(elt(env, 3)); /* nil */
    {
        popv(4);
        fn = elt(env, 5); /* evalletsub */
        return (*qfn2(fn))(qenv(fn), v93, v76);
    }
/* error exit handlers */
v123:
    popv(4);
    return nil;
}



/* Code for nsubsf */

static Lisp_Object MS_CDECL CC_nsubsf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v178;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "nsubsf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nsubsf");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v54 = stack[0];
    if (v54 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v178 = stack[0];
    v54 = (Lisp_Object)1; /* 0 */
    if (v178 == v54) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v54 = stack[-3];
    v54 = ncons(v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    fn = elt(env, 2); /* setkorder */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[-5] = v54;
    v54 = stack[-4];
    fn = elt(env, 3); /* reorder */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[-4] = v54;
    v178 = stack[-3];
    v54 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* to */
    v178 = (*qfn2(fn))(qenv(fn), v178, v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    v54 = (Lisp_Object)17; /* 1 */
    v54 = cons(v178, v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[-1] = ncons(v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    v54 = stack[0];
    v54 = integerp(v54);
    if (v54 == nil) goto v12;
    v54 = stack[0];
    goto v144;

v144:
    fn = elt(env, 5); /* addf */
    v54 = (*qfn2(fn))(qenv(fn), stack[-1], v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[-2] = v54;
    v54 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v54;
    goto v159;

v159:
    v54 = stack[-4];
    if (!consp(v54)) goto v179;
    v54 = stack[-4];
    v54 = qcar(v54);
    if (!consp(v54)) goto v179;
    v54 = stack[-4];
    v54 = qcar(v54);
    v54 = qcar(v54);
    v178 = qcar(v54);
    v54 = stack[-3];
    if (!(v178 == v54)) goto v179;
    v178 = stack[-1];
    v54 = stack[-4];
    v54 = qcar(v54);
    v54 = qcdr(v54);
    fn = elt(env, 5); /* addf */
    v54 = (*qfn2(fn))(qenv(fn), v178, v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[-1] = v54;
    v178 = stack[-4];
    v54 = stack[-3];
    fn = elt(env, 6); /* degr */
    stack[0] = (*qfn2(fn))(qenv(fn), v178, v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    v54 = stack[-4];
    v178 = qcdr(v54);
    v54 = stack[-3];
    fn = elt(env, 6); /* degr */
    v54 = (*qfn2(fn))(qenv(fn), v178, v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    v54 = difference2(stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[0] = v54;
    v54 = stack[-4];
    v54 = qcdr(v54);
    stack[-4] = v54;
    goto v62;

v62:
    v178 = stack[0];
    v54 = (Lisp_Object)1; /* 0 */
    v54 = (Lisp_Object)lesseq2(v178, v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v54 = v54 ? lisp_true : nil;
    env = stack[-6];
    if (!(v54 == nil)) goto v159;
    v178 = stack[-1];
    v54 = stack[-2];
    fn = elt(env, 7); /* multf */
    v54 = (*qfn2(fn))(qenv(fn), v178, v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[-1] = v54;
    v54 = stack[0];
    v54 = sub1(v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[0] = v54;
    goto v62;

v179:
    v178 = stack[-1];
    v54 = stack[-4];
    fn = elt(env, 5); /* addf */
    v54 = (*qfn2(fn))(qenv(fn), v178, v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    stack[-1] = v54;
    v54 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    v54 = stack[-1];
    {
        popv(7);
        fn = elt(env, 3); /* reorder */
        return (*qfn1(fn))(qenv(fn), v54);
    }

v12:
    v178 = stack[0];
    v54 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* to */
    v178 = (*qfn2(fn))(qenv(fn), v178, v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    v54 = (Lisp_Object)17; /* 1 */
    v54 = cons(v178, v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    v54 = ncons(v54);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[-6];
    goto v144;
/* error exit handlers */
v111:
    popv(7);
    return nil;
}



/* Code for ofsf_optsubstat */

static Lisp_Object MS_CDECL CC_ofsf_optsubstat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_optsubstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_optsubstat");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v16 = v102;
    stack[-2] = v1;
    stack[0] = v0;
/* end of prologue */
    v142 = stack[0];
    v142 = qcdr(v142);
    v142 = qcar(v142);
    fn = elt(env, 2); /* ofsf_optsplitterm */
    v16 = (*qfn2(fn))(qenv(fn), v142, v16);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    stack[-3] = v16;
    if (v16 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v16 = stack[0];
    stack[-1] = qcar(v16);
    v16 = stack[-3];
    v142 = qcar(v16);
    v16 = stack[-2];
    v16 = qcar(v16);
    fn = elt(env, 3); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v142, v16);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v16 = stack[-3];
    v142 = qcdr(v16);
    v16 = stack[-2];
    v16 = qcdr(v16);
    fn = elt(env, 3); /* multf */
    v16 = (*qfn2(fn))(qenv(fn), v142, v16);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    fn = elt(env, 4); /* addf */
    v16 = (*qfn2(fn))(qenv(fn), stack[0], v16);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-4];
    v142 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v153 = stack[-1];
        popv(5);
        return list3(v153, v16, v142);
    }
/* error exit handlers */
v92:
    popv(5);
    return nil;
}



/* Code for bra_ordp */

static Lisp_Object CC_bra_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bra_ordp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v106 = v0;
/* end of prologue */
    fn = elt(env, 1); /* bra_cd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v106 = stack[0];
    fn = elt(env, 1); /* bra_cd */
    v106 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    {
        Lisp_Object v147 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* cd_ordp */
        return (*qfn2(fn))(qenv(fn), v147, v106);
    }
/* error exit handlers */
v96:
    popv(3);
    return nil;
}



/* Code for findsquareroot */

static Lisp_Object CC_findsquareroot(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v166, v148;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findsquareroot");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v154 = stack[0];
    if (!consp(v154)) goto v9;
    v154 = stack[0];
    v154 = qcar(v154);
    if (!consp(v154)) goto v9;
    v154 = stack[0];
    v154 = qcar(v154);
    v154 = qcar(v154);
    v154 = qcar(v154);
    v148 = v154;
    v154 = v148;
    if (!consp(v154)) goto v21;
    v166 = v148;
    v154 = elt(env, 2); /* sqrt */
    if (!consp(v166)) goto v167;
    v166 = qcar(v166);
    if (v166 == v154) { popv(2); return onevalue(v148); }
    else goto v167;

v167:
    v154 = stack[0];
    v154 = qcar(v154);
    v154 = qcdr(v154);
    v154 = CC_findsquareroot(env, v154);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-1];
    v148 = v154;
    v154 = v148;
    if (!(v154 == nil)) { popv(2); return onevalue(v148); }
    v154 = stack[0];
    v154 = qcdr(v154);
    v154 = CC_findsquareroot(env, v154);
    nil = C_nil;
    if (exception_pending()) goto v121;
    v148 = v154;
    { popv(2); return onevalue(v148); }

v21:
    v154 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v154); }

v9:
    v154 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v154); }
/* error exit handlers */
v121:
    popv(2);
    return nil;
}



/* Code for simppsexplim */

static Lisp_Object CC_simppsexplim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simppsexplim");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v77 = v0;
/* end of prologue */
    v29 = qvalue(elt(env, 1)); /* ps!:exp!-lim */
    stack[0] = v29;
    v29 = v77;
    if (v29 == nil) goto v22;
    v29 = elt(env, 2); /* psexplim */
    fn = elt(env, 4); /* carx */
    v29 = (*qfn2(fn))(qenv(fn), v77, v29);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-1];
    fn = elt(env, 5); /* ieval */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-1];
    qvalue(elt(env, 1)) = v29; /* ps!:exp!-lim */
    goto v22;

v22:
    v77 = stack[0];
    v29 = (Lisp_Object)1; /* 0 */
    if (v77 == v29) goto v20;
    v77 = stack[0];
    v29 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v77, v29);

v20:
    v77 = qvalue(elt(env, 3)); /* nil */
    v29 = (Lisp_Object)17; /* 1 */
    popv(2);
    return cons(v77, v29);
/* error exit handlers */
v154:
    popv(2);
    return nil;
}



/* Code for delnil */

static Lisp_Object CC_delnil(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delnil");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v20 = nil;
    goto v10;

v10:
    v19 = stack[0];
    if (v19 == nil) goto v108;
    v19 = stack[0];
    v19 = qcar(v19);
    if (v19 == nil) goto v167;
    v19 = stack[0];
    v19 = qcar(v19);
    v19 = cons(v19, v20);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-1];
    v20 = v19;
    v19 = stack[0];
    v19 = qcdr(v19);
    stack[0] = v19;
    goto v10;

v167:
    v19 = stack[0];
    v19 = qcdr(v19);
    stack[0] = v19;
    goto v10;

v108:
    v19 = v20;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v19);
    }
/* error exit handlers */
v100:
    popv(2);
    return nil;
}



/* Code for transferrow */

static Lisp_Object CC_transferrow(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transferrow");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v31 = qvalue(elt(env, 2)); /* maxvar */
    v183 = stack[-2];
    v183 = plus2(v31, v183);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v31 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v183/(16/CELL)));
    v183 = (Lisp_Object)33; /* 2 */
    v31 = *(Lisp_Object *)((char *)v31 + (CELL-TAG_VECTOR) + ((int32_t)v183/(16/CELL)));
    v183 = elt(env, 3); /* plus */
    if (v31 == v183) goto v10;
    v183 = stack[-2];
    fn = elt(env, 6); /* transferrow1 */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    if (v183 == nil) goto v119;
    v31 = stack[-2];
    v183 = stack[0];
    {
        popv(5);
        fn = elt(env, 7); /* transferrow2 */
        return (*qfn2(fn))(qenv(fn), v31, v183);
    }

v119:
    v183 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v183); }

v10:
    v183 = stack[-2];
    fn = elt(env, 6); /* transferrow1 */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    if (v183 == nil) goto v144;
    stack[-3] = qvalue(elt(env, 1)); /* codmat */
    stack[-1] = qvalue(elt(env, 2)); /* maxvar */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v31 = qvalue(elt(env, 2)); /* maxvar */
    v183 = stack[-2];
    v183 = plus2(v31, v183);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v31 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v183/(16/CELL)));
    v183 = (Lisp_Object)49; /* 3 */
    v183 = *(Lisp_Object *)((char *)v31 + (CELL-TAG_VECTOR) + ((int32_t)v183/(16/CELL)));
    v183 = plus2(stack[-1], v183);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-4];
    v31 = *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)v183/(16/CELL)));
    v183 = (Lisp_Object)33; /* 2 */
    v183 = *(Lisp_Object *)((char *)v31 + (CELL-TAG_VECTOR) + ((int32_t)v183/(16/CELL)));
    v31 = elt(env, 5); /* times */
    v183 = (v183 == v31 ? lisp_true : nil);
    { popv(5); return onevalue(v183); }

v144:
    v183 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v183); }
/* error exit handlers */
v132:
    popv(5);
    return nil;
}



/* Code for new_simpexpt */

static Lisp_Object CC_new_simpexpt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for new_simpexpt");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* !*precise */
    qvalue(elt(env, 1)) = nil; /* !*precise */
    stack[-4] = qvalue(elt(env, 2)); /* !*factor */
    qvalue(elt(env, 2)) = nil; /* !*factor */
    stack[-3] = qvalue(elt(env, 3)); /* !*exp */
    qvalue(elt(env, 3)) = nil; /* !*exp */
    stack[-2] = qvalue(elt(env, 4)); /* !*mcd */
    qvalue(elt(env, 4)) = nil; /* !*mcd */
    stack[-1] = qvalue(elt(env, 5)); /* !*allfac */
    qvalue(elt(env, 5)) = nil; /* !*allfac */
    v184 = elt(env, 6); /* exp */
    v165 = elt(env, 7); /* mcd */
    v165 = list2(v184, v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    fn = elt(env, 15); /* on */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    v184 = elt(env, 8); /* precise */
    v165 = elt(env, 9); /* allfac */
    v165 = list2(v184, v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    fn = elt(env, 16); /* off */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    v165 = stack[-5];
    v184 = qcar(v165);
    v165 = elt(env, 10); /* minus */
    if (!consp(v184)) goto v145;
    v184 = qcar(v184);
    if (!(v184 == v165)) goto v145;
    v184 = elt(env, 10); /* minus */
    v165 = (Lisp_Object)17; /* 1 */
    v184 = list2(v184, v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    v165 = stack[-5];
    v165 = qcdr(v165);
    v165 = qcar(v165);
    v165 = list2(v184, v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    fn = elt(env, 14); /* original_simpexpt */
    stack[0] = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    v165 = stack[-5];
    v165 = qcar(v165);
    v165 = qcdr(v165);
    v184 = qcar(v165);
    v165 = stack[-5];
    v165 = qcdr(v165);
    v165 = qcar(v165);
    v165 = list2(v184, v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    v165 = CC_new_simpexpt(env, v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    fn = elt(env, 17); /* multsq */
    v165 = (*qfn2(fn))(qenv(fn), stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    goto v112;

v112:
    qvalue(elt(env, 5)) = stack[-1]; /* !*allfac */
    qvalue(elt(env, 4)) = stack[-2]; /* !*mcd */
    qvalue(elt(env, 3)) = stack[-3]; /* !*exp */
    qvalue(elt(env, 2)) = stack[-4]; /* !*factor */
    qvalue(elt(env, 1)) = stack[-6]; /* !*precise */
    { popv(8); return onevalue(v165); }

v145:
    v165 = qvalue(elt(env, 11)); /* !*redefmsg */
    stack[0] = v165;
    v165 = qvalue(elt(env, 12)); /* nil */
    qvalue(elt(env, 11)) = v165; /* !*redefmsg */
    v184 = elt(env, 13); /* simpexpt */
    v165 = elt(env, 14); /* original_simpexpt */
    fn = elt(env, 18); /* copyd */
    v165 = (*qfn2(fn))(qenv(fn), v184, v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    v165 = stack[-5];
    fn = elt(env, 13); /* simpexpt */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    stack[-5] = v165;
    v184 = elt(env, 13); /* simpexpt */
    v165 = elt(env, 0); /* new_simpexpt */
    fn = elt(env, 18); /* copyd */
    v165 = (*qfn2(fn))(qenv(fn), v184, v165);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-7];
    v165 = stack[0];
    qvalue(elt(env, 11)) = v165; /* !*redefmsg */
    v165 = stack[-5];
    goto v112;
/* error exit handlers */
v185:
    env = stack[-7];
    qvalue(elt(env, 5)) = stack[-1]; /* !*allfac */
    qvalue(elt(env, 4)) = stack[-2]; /* !*mcd */
    qvalue(elt(env, 3)) = stack[-3]; /* !*exp */
    qvalue(elt(env, 2)) = stack[-4]; /* !*factor */
    qvalue(elt(env, 1)) = stack[-6]; /* !*precise */
    popv(8);
    return nil;
}



/* Code for iscale */

static Lisp_Object CC_iscale(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v21, v171;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for iscale");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v21 = v1;
    v171 = v0;
/* end of prologue */
    v164 = v21;
    v164 = qcdr(v164);
    stack[0] = qcar(v164);
    v164 = v171;
    v21 = qcdr(v21);
    v21 = qcdr(v21);
    v164 = plus2(v164, v21);
    nil = C_nil;
    if (exception_pending()) goto v94;
    {
        Lisp_Object v146 = stack[0];
        popv(1);
        return Lash1(nil, v146, v164);
    }
/* error exit handlers */
v94:
    popv(1);
    return nil;
}



/* Code for indvarpf */

static Lisp_Object CC_indvarpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indvarpf");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */

v168:
    v18 = stack[0];
    if (!consp(v18)) goto v9;
    v18 = stack[0];
    v18 = qcar(v18);
    if (!consp(v18)) goto v9;
    v18 = stack[0];
    v18 = qcar(v18);
    v18 = qcar(v18);
    v18 = qcar(v18);
    fn = elt(env, 2); /* sfp */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    if (v18 == nil) goto v156;
    v18 = stack[0];
    v18 = qcar(v18);
    v18 = qcar(v18);
    v18 = qcar(v18);
    v18 = CC_indvarpf(env, v18);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    goto v79;

v79:
    if (!(v18 == nil)) { popv(2); return onevalue(v18); }
    v18 = stack[0];
    v18 = qcar(v18);
    v18 = qcdr(v18);
    v18 = CC_indvarpf(env, v18);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    if (!(v18 == nil)) { popv(2); return onevalue(v18); }
    v18 = stack[0];
    v18 = qcdr(v18);
    stack[0] = v18;
    goto v168;

v156:
    v18 = stack[0];
    v18 = qcar(v18);
    v18 = qcar(v18);
    v18 = qcar(v18);
    fn = elt(env, 3); /* freeindp */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    goto v79;

v9:
    v18 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v18); }
/* error exit handlers */
v170:
    popv(2);
    return nil;
}



/* Code for not_included */

static Lisp_Object CC_not_included(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v148, v186, v121, v15;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for not_included");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v1;
    v121 = v0;
/* end of prologue */
    v166 = qvalue(elt(env, 1)); /* t */
    v186 = v166;
    goto v112;

v112:
    v166 = v121;
    if (v166 == nil) goto v108;
    v166 = v186;
    if (v166 == nil) goto v108;
    v166 = v15;
    v186 = v166;
    goto v164;

v164:
    v166 = v186;
    if (v166 == nil) goto v158;
    v166 = v121;
    v148 = qcar(v166);
    v166 = v186;
    v166 = qcar(v166);
    if (equal(v148, v166)) goto v158;
    v166 = v186;
    v166 = qcdr(v166);
    v186 = v166;
    goto v164;

v158:
    v166 = v121;
    v166 = qcdr(v166);
    v121 = v166;
    goto v112;

v108:
    v166 = v186;
    if (v166 == nil) goto v77;
    v166 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v166);

v77:
    v166 = qvalue(elt(env, 1)); /* t */
    return onevalue(v166);
}



/* Code for replace1_edge */

static Lisp_Object MS_CDECL CC_replace1_edge(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v154, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace1_edge");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace1_edge");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v45:
    v48 = stack[0];
    if (v48 == nil) goto v112;
    v48 = stack[-2];
    v154 = qcar(v48);
    v48 = stack[0];
    v48 = qcar(v48);
    v48 = qcar(v48);
    if (!(v154 == v48)) goto v26;
    v48 = stack[0];
    v154 = qcar(v48);
    v48 = stack[-1];
    fn = elt(env, 2); /* replace_edge2 */
    v48 = (*qfn2(fn))(qenv(fn), v154, v48);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    goto v26;

v26:
    v166 = stack[-2];
    v154 = stack[-1];
    v48 = stack[0];
    v48 = qcar(v48);
    fn = elt(env, 3); /* replace1_parents */
    v48 = (*qfnn(fn))(qenv(fn), 3, v166, v154, v48);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-3];
    v48 = stack[0];
    v48 = qcdr(v48);
    stack[0] = v48;
    goto v45;

v112:
    v48 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v48); }
/* error exit handlers */
v15:
    popv(4);
    return nil;
}



/* Code for random!-prime */

static Lisp_Object MS_CDECL CC_randomKprime(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188, v189;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "random-prime");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for random-prime");
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
    stack[-4] = nil;
    stack[-3] = nil;
    v188 = qvalue(elt(env, 1)); /* largest!-small!-modulus */
    stack[-1] = v188;
    stack[0] = stack[-1];
    v189 = (Lisp_Object)33; /* 2 */
    v188 = (Lisp_Object)385; /* 24 */
    v188 = Lexpt(nil, v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v188 = (Lisp_Object)greaterp2(stack[0], v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    v188 = v188 ? lisp_true : nil;
    env = stack[-5];
    if (v188 == nil) goto v144;
    v189 = (Lisp_Object)33; /* 2 */
    v188 = (Lisp_Object)385; /* 24 */
    v188 = Lexpt(nil, v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    stack[-1] = v188;
    goto v144;

v144:
    v189 = stack[-1];
    v188 = (Lisp_Object)33; /* 2 */
    v188 = quot2(v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    stack[0] = v188;
    v188 = qvalue(elt(env, 2)); /* current!-modulus */
    stack[-2] = v188;
    goto v48;

v48:
    v189 = stack[-3];
    v188 = (Lisp_Object)17; /* 1 */
    if (v189 == v188) goto v18;
    fn = elt(env, 4); /* next!-random!-number */
    v189 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v188 = stack[-1];
    v188 = Cremainder(v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    stack[-4] = v188;
    v189 = stack[-4];
    v188 = stack[0];
    v188 = (Lisp_Object)lessp2(v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    v188 = v188 ? lisp_true : nil;
    env = stack[-5];
    if (v188 == nil) goto v85;
    v189 = stack[-4];
    v188 = stack[0];
    v188 = plus2(v189, v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    stack[-4] = v188;
    goto v85;

v85:
    v188 = stack[-4];
    v188 = Levenp(nil, v188);
    env = stack[-5];
    if (v188 == nil) goto v181;
    v188 = stack[-4];
    v188 = add1(v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    stack[-4] = v188;
    goto v181;

v181:
    v188 = stack[-4];
    fn = elt(env, 5); /* set!-modulus */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    v188 = (Lisp_Object)46817; /* 2926 */
    v189 = Lmodular_number(nil, v188);
    env = stack[-5];
    v188 = stack[-4];
    v188 = (Lisp_Object)((int32_t)(v188) - 0x10);
    v188 = Lmodular_expt(nil, v189, v188);
    env = stack[-5];
    stack[-3] = v188;
    v189 = stack[-3];
    v188 = (Lisp_Object)17; /* 1 */
    if (!(v189 == v188)) goto v48;
    v188 = (Lisp_Object)53041; /* 3315 */
    v189 = Lmodular_number(nil, v188);
    env = stack[-5];
    v188 = stack[-4];
    v188 = (Lisp_Object)((int32_t)(v188) - 0x10);
    v189 = Lmodular_expt(nil, v189, v188);
    env = stack[-5];
    v188 = (Lisp_Object)17; /* 1 */
    if (!(v189 == v188)) goto v185;
    v188 = stack[-4];
    fn = elt(env, 6); /* pseudo!-prime!-p */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-5];
    if (v188 == nil) goto v48;
    else goto v185;

v185:
    v188 = (Lisp_Object)1; /* 0 */
    stack[-3] = v188;
    goto v48;

v18:
    v188 = stack[-2];
    fn = elt(env, 5); /* set!-modulus */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v190;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v190:
    popv(6);
    return nil;
}



/* Code for compactf */

static Lisp_Object MS_CDECL CC_compactf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v162, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactf");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v102;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v99 = (Lisp_Object)1; /* 0 */
    stack[0] = v99;
    v99 = qvalue(elt(env, 1)); /* !*trcompact */
    if (v99 == nil) goto v93;
    v99 = elt(env, 2); /* "*** Arguments on entering compactf:" */
    fn = elt(env, 6); /* prin2t */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    v162 = stack[-3];
    v99 = (Lisp_Object)17; /* 1 */
    v99 = cons(v162, v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    fn = elt(env, 7); /* mk!*sq */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    fn = elt(env, 8); /* mathprint */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    v162 = stack[-2];
    v99 = (Lisp_Object)17; /* 1 */
    v99 = cons(v162, v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    fn = elt(env, 7); /* mk!*sq */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    fn = elt(env, 8); /* mathprint */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    goto v93;

v93:
    v162 = stack[-4];
    v99 = stack[-3];
    if (equal(v162, v99)) goto v144;
    v99 = stack[-3];
    stack[-4] = v99;
    v181 = stack[-3];
    v162 = stack[-2];
    v99 = stack[-1];
    fn = elt(env, 9); /* compactf0 */
    v99 = (*qfnn(fn))(qenv(fn), 3, v181, v162, v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    stack[-3] = v99;
    v99 = stack[0];
    v99 = add1(v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    stack[0] = v99;
    goto v93;

v144:
    v99 = qvalue(elt(env, 1)); /* !*trcompact */
    if (v99 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v162 = stack[0];
    v99 = (Lisp_Object)33; /* 2 */
    v99 = (Lisp_Object)greaterp2(v162, v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    v99 = v99 ? lisp_true : nil;
    env = stack[-5];
    if (v99 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v99 = elt(env, 4); /* " *** Compactf looped " */
    v99 = Lprinc(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    v99 = stack[0];
    v99 = Lprinc(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-5];
    v99 = elt(env, 5); /* " times" */
    fn = elt(env, 6); /* prin2t */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v161;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
/* error exit handlers */
v161:
    popv(6);
    return nil;
}



/* Code for pst_isolate */

static Lisp_Object CC_pst_isolate(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_isolate");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v1;
    v28 = v0;
/* end of prologue */
    v100 = v28;
    v28 = stack[-1];
    v28 = qcdr(v28);
    fn = elt(env, 1); /* pst_isolate1 */
    v28 = (*qfn2(fn))(qenv(fn), v100, v28);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    fn = elt(env, 2); /* pst_reduce */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    stack[-2] = v28;
    stack[0] = stack[-2];
    v28 = stack[-1];
    v100 = qcar(v28);
    v28 = stack[-2];
    v28 = qcar(v28);
    v28 = Lappend(nil, v100, v28);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-3];
    v28 = Lrplaca(nil, stack[0], v28);
    nil = C_nil;
    if (exception_pending()) goto v26;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v26:
    popv(4);
    return nil;
}



/* Code for general!-xquotient!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKxquotientKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v111, v196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "general-xquotient-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-xquotient-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v102;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v56 = stack[-2];
    if (v56 == nil) goto v45;
    v56 = stack[-2];
    if (!consp(v56)) goto v159;
    v56 = stack[-2];
    v56 = qcar(v56);
    if (!consp(v56)) goto v159;
    v56 = stack[-2];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v111 = qcar(v56);
    v56 = stack[0];
    if (!(equal(v111, v56))) goto v159;
    v56 = stack[-2];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v111 = qcdr(v56);
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v56 = qcdr(v56);
    if (((int32_t)(v111)) < ((int32_t)(v56))) goto v159;
    v56 = stack[-2];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v111 = qcdr(v56);
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v56 = qcdr(v56);
    if (equal(v111, v56)) goto v122;
    v56 = stack[-2];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v196 = qcar(v56);
    v56 = stack[-2];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v111 = qcdr(v56);
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v56 = qcdr(v56);
    v56 = (Lisp_Object)(int32_t)((int32_t)v111 - (int32_t)v56 + TAG_FIXNUM);
    fn = elt(env, 3); /* mksp */
    stack[-3] = (*qfn2(fn))(qenv(fn), v196, v56);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    v56 = stack[-2];
    v56 = qcar(v56);
    v111 = qcdr(v56);
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcdr(v56);
    fn = elt(env, 4); /* general!-quotient!-mod!-p */
    v56 = (*qfn2(fn))(qenv(fn), v111, v56);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    v56 = cons(stack[-3], v56);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[-3] = v56;
    v56 = stack[-2];
    stack[-2] = qcdr(v56);
    v56 = stack[-3];
    fn = elt(env, 5); /* general!-negate!-term */
    v111 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    v56 = stack[-1];
    v56 = qcdr(v56);
    fn = elt(env, 6); /* general!-times!-term!-mod!-p */
    v56 = (*qfn2(fn))(qenv(fn), v111, v56);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    fn = elt(env, 7); /* general!-plus!-mod!-p */
    v56 = (*qfn2(fn))(qenv(fn), stack[-2], v56);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[-2] = v56;
    v196 = stack[-2];
    v111 = stack[-1];
    v56 = stack[0];
    v56 = CC_generalKxquotientKmodKp(env, 3, v196, v111, v56);
    nil = C_nil;
    if (exception_pending()) goto v197;
    {
        Lisp_Object v198 = stack[-3];
        popv(5);
        return cons(v198, v56);
    }

v122:
    v56 = stack[-2];
    v56 = qcar(v56);
    v111 = qcdr(v56);
    v56 = stack[-1];
    v56 = qcar(v56);
    v56 = qcdr(v56);
    fn = elt(env, 4); /* general!-quotient!-mod!-p */
    v56 = (*qfn2(fn))(qenv(fn), v111, v56);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    stack[0] = v56;
    v111 = stack[0];
    v56 = stack[-1];
    fn = elt(env, 8); /* general!-times!-mod!-p */
    v56 = (*qfn2(fn))(qenv(fn), v111, v56);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    fn = elt(env, 9); /* general!-difference!-mod!-p */
    v56 = (*qfn2(fn))(qenv(fn), stack[-2], v56);
    nil = C_nil;
    if (exception_pending()) goto v197;
    env = stack[-4];
    if (v56 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v56 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v56; /* exact!-quotient!-flag */
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v159:
    v56 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v56; /* exact!-quotient!-flag */
    { popv(5); return onevalue(v56); }

v45:
    v56 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v56); }
/* error exit handlers */
v197:
    popv(5);
    return nil;
}



/* Code for quotfail!-mod!-p */

static Lisp_Object CC_quotfailKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v94, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v94 = v1;
    v146 = v0;
/* end of prologue */
    v22 = qvalue(elt(env, 1)); /* t */
    qvalue(elt(env, 2)) = v22; /* exact!-quotient!-flag */
    v22 = v146;
    fn = elt(env, 4); /* quotient!-mod!-p */
    v22 = (*qfn2(fn))(qenv(fn), v22, v94);
    nil = C_nil;
    if (exception_pending()) goto v167;
    env = stack[0];
    v94 = v22;
    v22 = qvalue(elt(env, 2)); /* exact!-quotient!-flag */
    if (!(v22 == nil)) { popv(1); return onevalue(v94); }
    v22 = elt(env, 3); /* "QUOTIENT NOT EXACT (MOD P)" */
    fn = elt(env, 5); /* errorf */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v167;
    v22 = nil;
    { popv(1); return onevalue(v22); }
/* error exit handlers */
v167:
    popv(1);
    return nil;
}



/* Code for sfto_yun!-updecf */

static Lisp_Object CC_sfto_yunKupdecf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_yun-updecf");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    stack[-1] = nil;
    v52 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v52; /* !*gcd */
    v172 = (Lisp_Object)17; /* 1 */
    v52 = (Lisp_Object)17; /* 1 */
    v52 = cons(v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    stack[-2] = v52;
    v52 = stack[-6];
    v52 = qcar(v52);
    v52 = qcar(v52);
    v52 = qcar(v52);
    stack[-5] = v52;
    stack[-3] = stack[-6];
    v172 = stack[-6];
    v52 = stack[-5];
    fn = elt(env, 3); /* diff */
    v52 = (*qfn2(fn))(qenv(fn), v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    stack[0] = v52;
    fn = elt(env, 4); /* sfto_gcdf */
    v52 = (*qfn2(fn))(qenv(fn), stack[-3], v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    stack[-3] = v52;
    v172 = stack[-6];
    v52 = stack[-3];
    fn = elt(env, 5); /* quotf */
    v52 = (*qfn2(fn))(qenv(fn), v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    stack[-4] = v52;
    v172 = stack[0];
    v52 = stack[-3];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    v172 = stack[-4];
    v52 = stack[-5];
    fn = elt(env, 3); /* diff */
    v52 = (*qfn2(fn))(qenv(fn), v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    fn = elt(env, 6); /* negf */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    fn = elt(env, 7); /* addf */
    v52 = (*qfn2(fn))(qenv(fn), stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    stack[-3] = v52;
    goto v13;

v13:
    v52 = stack[-1];
    v52 = (v52 == nil ? lisp_true : nil);
    stack[-1] = v52;
    v172 = stack[-4];
    v52 = stack[-3];
    fn = elt(env, 4); /* sfto_gcdf */
    v52 = (*qfn2(fn))(qenv(fn), v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    stack[-6] = v52;
    v52 = stack[-1];
    if (v52 == nil) goto v6;
    stack[0] = stack[-2];
    v52 = stack[-2];
    v172 = qcar(v52);
    v52 = stack[-6];
    fn = elt(env, 8); /* multf */
    v52 = (*qfn2(fn))(qenv(fn), v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    fn = elt(env, 9); /* setcar */
    v52 = (*qfn2(fn))(qenv(fn), stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    goto v69;

v69:
    v172 = stack[-4];
    v52 = stack[-6];
    fn = elt(env, 5); /* quotf */
    v52 = (*qfn2(fn))(qenv(fn), v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    stack[-4] = v52;
    v172 = stack[-3];
    v52 = stack[-6];
    fn = elt(env, 5); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    v172 = stack[-4];
    v52 = stack[-5];
    fn = elt(env, 3); /* diff */
    v52 = (*qfn2(fn))(qenv(fn), v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    fn = elt(env, 6); /* negf */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    fn = elt(env, 7); /* addf */
    v52 = (*qfn2(fn))(qenv(fn), stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    stack[-3] = v52;
    v52 = stack[-4];
    if (!consp(v52)) goto v12;
    v52 = stack[-4];
    v52 = qcar(v52);
    if (!(!consp(v52))) goto v13;

v12:
    v52 = stack[-2];
    qvalue(elt(env, 1)) = stack[-7]; /* !*gcd */
    { popv(9); return onevalue(v52); }

v6:
    stack[0] = stack[-2];
    v52 = stack[-2];
    v172 = qcdr(v52);
    v52 = stack[-6];
    fn = elt(env, 8); /* multf */
    v52 = (*qfn2(fn))(qenv(fn), v172, v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    fn = elt(env, 10); /* setcdr */
    v52 = (*qfn2(fn))(qenv(fn), stack[0], v52);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-8];
    goto v69;
/* error exit handlers */
v201:
    env = stack[-8];
    qvalue(elt(env, 1)) = stack[-7]; /* !*gcd */
    popv(9);
    return nil;
}



/* Code for evalletsub2 */

static Lisp_Object CC_evalletsub2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalletsub2");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v156 = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* newrule!* */
    qvalue(elt(env, 1)) = nil; /* newrule!* */
    stack[-2] = qvalue(elt(env, 2)); /* oldrules!* */
    qvalue(elt(env, 2)) = nil; /* oldrules!* */
    stack[-1] = qvalue(elt(env, 3)); /* props!* */
    qvalue(elt(env, 3)) = nil; /* props!* */
    v19 = stack[-3];
    v19 = qcar(v19);
    fn = elt(env, 5); /* set_rules */
    v156 = (*qfn2(fn))(qenv(fn), v19, v156);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-5];
    stack[0] = v156;
    v156 = stack[-3];
    v156 = qcdr(v156);
    v19 = qcar(v156);
    v156 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 6); /* errorset!* */
    v156 = (*qfn2(fn))(qenv(fn), v19, v156);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-5];
    stack[-3] = v156;
    v156 = stack[0];
    fn = elt(env, 7); /* restore_rules */
    v156 = (*qfn1(fn))(qenv(fn), v156);
    nil = C_nil;
    if (exception_pending()) goto v128;
    env = stack[-5];
    v156 = stack[-3];
    qvalue(elt(env, 3)) = stack[-1]; /* props!* */
    qvalue(elt(env, 2)) = stack[-2]; /* oldrules!* */
    qvalue(elt(env, 1)) = stack[-4]; /* newrule!* */
    { popv(6); return onevalue(v156); }
/* error exit handlers */
v128:
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[-1]; /* props!* */
    qvalue(elt(env, 2)) = stack[-2]; /* oldrules!* */
    qvalue(elt(env, 1)) = stack[-4]; /* newrule!* */
    popv(6);
    return nil;
}



/* Code for aex_lc */

static Lisp_Object CC_aex_lc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v101, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_lc");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v100 = v1;
    stack[0] = v0;
/* end of prologue */
    v101 = stack[0];
    fn = elt(env, 2); /* aex_mvaroccurtest */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    if (v100 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v100 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_lc */
    stack[-1] = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    v100 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v144 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-2];
    v101 = qvalue(elt(env, 1)); /* nil */
    v100 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v150 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v150, v144, v101, v100);
    }
/* error exit handlers */
v163:
    popv(3);
    return nil;
}



/* Code for bc_dcont */

static Lisp_Object CC_bc_dcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_dcont");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v10 = qcar(v10);
    {
        fn = elt(env, 1); /* sfto_dcontentf */
        return (*qfn1(fn))(qenv(fn), v10);
    }
}



/* Code for rread */

static Lisp_Object MS_CDECL CC_rread(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rread");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rread");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v9 = elt(env, 1); /* " '" */
    fn = elt(env, 2); /* prin2x */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* rread1 */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v10:
    popv(1);
    return nil;
}



/* Code for f2vdp */

static Lisp_Object CC_f2vdp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v74, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f2vdp");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v75 = v0;
/* end of prologue */
    v74 = v75;
    v13 = (Lisp_Object)1; /* 0 */
    if (v74 == v13) goto v147;
    v13 = v75;
    if (v13 == nil) goto v147;
    v13 = v75;
    fn = elt(env, 3); /* f2dip */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v74 = v13;
    stack[-2] = elt(env, 1); /* vdp */
    v13 = v74;
    stack[-1] = qcar(v13);
    v13 = v74;
    v13 = qcdr(v13);
    stack[0] = qcar(v13);
    v13 = qvalue(elt(env, 2)); /* nil */
    v13 = list2(v74, v13);
    nil = C_nil;
    if (exception_pending()) goto v86;
    {
        Lisp_Object v7 = stack[-2];
        Lisp_Object v8 = stack[-1];
        Lisp_Object v97 = stack[0];
        popv(4);
        return list3star(v7, v8, v97, v13);
    }

v147:
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    v74 = qvalue(elt(env, 2)); /* nil */
    v13 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v74, v13);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    v74 = qvalue(elt(env, 2)); /* nil */
    v13 = qvalue(elt(env, 2)); /* nil */
    v13 = list2(v74, v13);
    nil = C_nil;
    if (exception_pending()) goto v86;
    {
        Lisp_Object v98 = stack[-2];
        Lisp_Object v46 = stack[-1];
        Lisp_Object v47 = stack[0];
        popv(4);
        return list3star(v98, v46, v47, v13);
    }
/* error exit handlers */
v86:
    popv(4);
    return nil;
}



/* Code for formclear1 */

static Lisp_Object MS_CDECL CC_formclear1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v151, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclear1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formclear1");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v102;
    stack[-5] = v1;
    v65 = v0;
/* end of prologue */
    stack[-6] = elt(env, 1); /* list */
    stack[-3] = v65;
    v65 = stack[-3];
    if (v65 == nil) goto v157;
    v65 = stack[-3];
    v65 = qcar(v65);
    v130 = v65;
    v151 = v130;
    v65 = elt(env, 3); /* share */
    v65 = Lflagp(nil, v151, v65);
    env = stack[-7];
    if (v65 == nil) goto v123;
    v65 = v130;
    v65 = Lmkquote(nil, v65);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-7];
    goto v145;

v145:
    v65 = ncons(v65);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-7];
    stack[-1] = v65;
    stack[-2] = v65;
    goto v96;

v96:
    v65 = stack[-3];
    v65 = qcdr(v65);
    stack[-3] = v65;
    v65 = stack[-3];
    if (v65 == nil) goto v16;
    stack[0] = stack[-1];
    v65 = stack[-3];
    v65 = qcar(v65);
    v130 = v65;
    v151 = v130;
    v65 = elt(env, 3); /* share */
    v65 = Lflagp(nil, v151, v65);
    env = stack[-7];
    if (v65 == nil) goto v127;
    v65 = v130;
    v65 = Lmkquote(nil, v65);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-7];
    goto v75;

v75:
    v65 = ncons(v65);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-7];
    v65 = Lrplacd(nil, stack[0], v65);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-7];
    v65 = stack[-1];
    v65 = qcdr(v65);
    stack[-1] = v65;
    goto v96;

v127:
    v151 = stack[-5];
    v65 = stack[-4];
    fn = elt(env, 4); /* form1 */
    v65 = (*qfnn(fn))(qenv(fn), 3, v130, v151, v65);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-7];
    goto v75;

v16:
    v65 = stack[-2];
    goto v108;

v108:
    {
        Lisp_Object v31 = stack[-6];
        popv(8);
        return cons(v31, v65);
    }

v123:
    v151 = stack[-5];
    v65 = stack[-4];
    fn = elt(env, 4); /* form1 */
    v65 = (*qfnn(fn))(qenv(fn), 3, v130, v151, v65);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-7];
    goto v145;

v157:
    v65 = qvalue(elt(env, 2)); /* nil */
    goto v108;
/* error exit handlers */
v183:
    popv(8);
    return nil;
}



/* Code for declared!-as!-float */

static Lisp_Object CC_declaredKasKfloat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for declared-as-float");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v155 = v0;
/* end of prologue */
    v156 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* symtabget */
    v155 = (*qfn2(fn))(qenv(fn), v156, v155);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[0];
    v156 = v155;
    if (v155 == nil) goto v104;
    v155 = v156;
    v155 = qcdr(v155);
    v155 = qcar(v155);
    v156 = elt(env, 2); /* (real real!*8 real!*16 double! precision double float) 
*/
    v155 = Lmemq(nil, v155, v156);
    { popv(1); return onevalue(v155); }

v104:
    v155 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v155); }
/* error exit handlers */
v19:
    popv(1);
    return nil;
}



/* Code for coeff_edges */

static Lisp_Object CC_coeff_edges(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff_edges");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v45;

v45:
    v17 = stack[0];
    if (v17 == nil) goto v104;
    v17 = stack[0];
    v17 = qcar(v17);
    fn = elt(env, 2); /* atlas_edges */
    v152 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    v17 = stack[-1];
    v17 = cons(v152, v17);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    stack[-1] = v17;
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[0] = v17;
    goto v45;

v104:
    v17 = qvalue(elt(env, 1)); /* nil */
    v152 = v17;
    goto v108;

v108:
    v17 = stack[-1];
    if (v17 == nil) { popv(3); return onevalue(v152); }
    v17 = stack[-1];
    v17 = qcar(v17);
    fn = elt(env, 3); /* union_edges */
    v17 = (*qfn2(fn))(qenv(fn), v17, v152);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    v152 = v17;
    v17 = stack[-1];
    v17 = qcdr(v17);
    stack[-1] = v17;
    goto v108;
/* error exit handlers */
v170:
    popv(3);
    return nil;
}



/* Code for addfd */

static Lisp_Object CC_addfd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addfd");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v45;

v45:
    v183 = stack[-1];
    if (v183 == nil) goto v106;
    v183 = stack[0];
    if (v183 == nil) goto v171;
    v183 = stack[-1];
    if (!consp(v183)) goto v18;
    v183 = stack[-1];
    v183 = qcar(v183);
    if (!consp(v183)) goto v18;
    v183 = stack[0];
    if (!consp(v183)) goto v72;
    v183 = stack[0];
    v183 = qcar(v183);
    if (!consp(v183)) goto v72;
    v183 = stack[-1];
    v183 = qcar(v183);
    v31 = qcar(v183);
    v183 = stack[0];
    v183 = qcar(v183);
    v183 = qcar(v183);
    fn = elt(env, 1); /* ordp */
    v183 = (*qfn2(fn))(qenv(fn), v31, v183);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    if (v183 == nil) goto v65;
    v183 = stack[-1];
    v31 = qcar(v183);
    v183 = stack[-2];
    v183 = cons(v31, v183);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    stack[-2] = v183;
    v183 = stack[-1];
    v183 = qcdr(v183);
    stack[-1] = v183;
    goto v45;

v65:
    v183 = stack[0];
    v31 = qcar(v183);
    v183 = stack[-2];
    v183 = cons(v31, v183);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    stack[-2] = v183;
    v183 = stack[0];
    v183 = qcdr(v183);
    stack[0] = v183;
    goto v45;

v72:
    v31 = stack[0];
    v183 = stack[-1];
    fn = elt(env, 2); /* addd */
    v183 = (*qfn2(fn))(qenv(fn), v31, v183);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    {
        Lisp_Object v132 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v132, v183);
    }

v18:
    v31 = stack[-1];
    v183 = stack[0];
    fn = elt(env, 2); /* addd */
    v183 = (*qfn2(fn))(qenv(fn), v31, v183);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    {
        Lisp_Object v131 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v131, v183);
    }

v171:
    v31 = stack[-2];
    v183 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v31, v183);
    }

v106:
    v31 = stack[-2];
    v183 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v31, v183);
    }
/* error exit handlers */
v175:
    popv(4);
    return nil;
}



/* Code for tayminpowerlist */

static Lisp_Object CC_tayminpowerlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayminpowerlist");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v21 = v0;
/* end of prologue */
    v164 = v21;
    if (v164 == nil) goto v9;
    stack[0] = v21;
    v164 = v21;
    v164 = qcar(v164);
    v164 = qcar(v164);
    v164 = Llength(nil, v164);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    {
        Lisp_Object v94 = stack[0];
        popv(2);
        fn = elt(env, 1); /* tayminpowerlist1 */
        return (*qfn2(fn))(qenv(fn), v94, v164);
    }

v9:
    v164 = elt(env, 0); /* tayminpowerlist */
    {
        popv(2);
        fn = elt(env, 2); /* confusion */
        return (*qfn1(fn))(qenv(fn), v164);
    }
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for acfsf_prepat */

static Lisp_Object CC_acfsf_prepat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for acfsf_prepat");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0;
/* end of prologue */
    v79 = stack[-1];
    fn = elt(env, 1); /* acfsf_op */
    stack[-2] = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-3];
    v79 = stack[-1];
    fn = elt(env, 2); /* acfsf_arg2l */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-3];
    fn = elt(env, 3); /* prepf */
    stack[0] = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-3];
    v79 = stack[-1];
    fn = elt(env, 4); /* acfsf_arg2r */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-3];
    fn = elt(env, 3); /* prepf */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v164;
    {
        Lisp_Object v21 = stack[-2];
        Lisp_Object v171 = stack[0];
        popv(4);
        return list3(v21, v171, v79);
    }
/* error exit handlers */
v164:
    popv(4);
    return nil;
}



/* Code for inszzzr */

static Lisp_Object CC_inszzzr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for inszzzr");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v45;

v45:
    v70 = stack[-1];
    if (v70 == nil) goto v94;
    v70 = stack[-1];
    v70 = qcar(v70);
    v71 = qcar(v70);
    v70 = stack[-2];
    v70 = qcar(v70);
    v70 = (Lisp_Object)greaterp2(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v4;
    v70 = v70 ? lisp_true : nil;
    env = stack[-4];
    if (!(v70 == nil)) goto v94;
    v70 = stack[-1];
    v70 = qcar(v70);
    v71 = qcar(v70);
    v70 = stack[-2];
    v70 = qcar(v70);
    if (equal(v71, v70)) goto v154;
    v70 = stack[-1];
    v71 = qcar(v70);
    v70 = stack[-3];
    v70 = cons(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    stack[-3] = v70;
    v70 = stack[-1];
    v70 = qcdr(v70);
    stack[-1] = v70;
    goto v45;

v154:
    v70 = stack[-1];
    v70 = qcar(v70);
    stack[0] = qcdr(v70);
    v70 = stack[-1];
    v70 = qcar(v70);
    v70 = qcdr(v70);
    v71 = qcar(v70);
    v70 = stack[-2];
    v70 = qcdr(v70);
    v70 = qcar(v70);
    fn = elt(env, 1); /* dm!-plus */
    v70 = (*qfn2(fn))(qenv(fn), v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v70 = Lrplaca(nil, stack[0], v70);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v70 = stack[-1];
    v70 = qcar(v70);
    v70 = qcdr(v70);
    v70 = qcar(v70);
    fn = elt(env, 2); /* zeropp */
    v70 = (*qfn1(fn))(qenv(fn), v70);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    if (v70 == nil) goto v161;
    v71 = stack[-3];
    v70 = stack[-1];
    v70 = qcdr(v70);
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v71, v70);
    }

v161:
    v71 = stack[-3];
    v70 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v71, v70);
    }

v94:
    stack[0] = stack[-3];
    v71 = stack[-2];
    v70 = stack[-1];
    v70 = cons(v71, v70);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    {
        Lisp_Object v2 = stack[0];
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v2, v70);
    }
/* error exit handlers */
v4:
    popv(5);
    return nil;
}



/* Code for sign!-of */

static Lisp_Object CC_signKof(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sign-of");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v96 = v0;
/* end of prologue */
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[0];
    fn = elt(env, 2); /* simp!-sign */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[0];
    v96 = qcar(v96);
    v147 = v96;
    v96 = v147;
    if (is_number(v96)) { popv(1); return onevalue(v147); }
    v96 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v96); }
/* error exit handlers */
v79:
    popv(1);
    return nil;
}



/* Code for tstpolyarg */

static Lisp_Object CC_tstpolyarg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v156, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tstpolyarg");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v19 = v1;
    v156 = v0;
/* end of prologue */
    v155 = qvalue(elt(env, 1)); /* !*ratarg */
    if (v155 == nil) goto v106;
    v155 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v155); }

v106:
    v155 = (Lisp_Object)17; /* 1 */
    if (v156 == v155) goto v112;
    v155 = v19;
    fn = elt(env, 4); /* prepsq */
    v156 = (*qfn1(fn))(qenv(fn), v155);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[0];
    v155 = elt(env, 3); /* "polynomial" */
    {
        popv(1);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v156, v155);
    }

v112:
    v155 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v155); }
/* error exit handlers */
v20:
    popv(1);
    return nil;
}



/* Code for exformp */

static Lisp_Object CC_exformp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v61, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exformp");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */

v10:
    v63 = stack[0];
    if (v63 == nil) goto v108;
    v63 = stack[0];
    if (is_number(v63)) goto v108;
    v63 = stack[0];
    if (!(!consp(v63))) goto v96;
    v61 = stack[0];
    v63 = qvalue(elt(env, 2)); /* frlis!* */
    v63 = Lmemq(nil, v61, v63);
    if (v63 == nil) goto v96;
    v63 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v63); }

v96:
    v63 = stack[0];
    if (!consp(v63)) goto v20;
    v63 = stack[0];
    v61 = qcar(v63);
    v63 = elt(env, 5); /* indexvar */
    v63 = Lflagp(nil, v61, v63);
    env = stack[-1];
    if (v63 == nil) goto v14;
    v63 = stack[0];
    v63 = qcdr(v63);
    v23 = Llength(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v63 = stack[0];
    v61 = qcar(v63);
    v63 = elt(env, 6); /* ifdegree */
    v63 = get(v61, v63);
    v63 = Lassoc(nil, v23, v63);
    { popv(2); return onevalue(v63); }

v14:
    v63 = stack[0];
    v61 = qcar(v63);
    v63 = elt(env, 7); /* !*sq */
    if (v61 == v63) goto v85;
    v63 = stack[0];
    v61 = qcar(v63);
    v63 = elt(env, 8); /* (wedge d partdf hodge innerprod liedf) */
    v63 = Lmemq(nil, v61, v63);
    if (v63 == nil) goto v119;
    v63 = qvalue(elt(env, 3)); /* t */
    { popv(2); return onevalue(v63); }

v119:
    v63 = stack[0];
    v61 = qcar(v63);
    v63 = elt(env, 9); /* dname */
    v63 = get(v61, v63);
    env = stack[-1];
    if (v63 == nil) goto v141;
    v63 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v63); }

v141:
    v63 = stack[0];
    v63 = qcdr(v63);
    fn = elt(env, 10); /* lexformp */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v61 = v63;
    if (!(v63 == nil)) { popv(2); return onevalue(v61); }
    v63 = stack[0];
    v63 = qcar(v63);
    v63 = CC_exformp(env, v63);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    v61 = v63;
    if (!(v63 == nil)) { popv(2); return onevalue(v61); }
    v63 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v63); }

v85:
    v63 = stack[0];
    v63 = qcdr(v63);
    v63 = qcar(v63);
    fn = elt(env, 11); /* prepsq */
    v63 = (*qfn1(fn))(qenv(fn), v63);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-1];
    stack[0] = v63;
    goto v10;

v20:
    v63 = stack[0];
    v61 = elt(env, 4); /* fdegree */
    popv(2);
    return get(v63, v61);

v108:
    v63 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v63); }
/* error exit handlers */
v25:
    popv(2);
    return nil;
}



/* Code for unreval */

static Lisp_Object CC_unreval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171, v22, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unreval");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v22 = v0;
/* end of prologue */
    v171 = v22;
    if (!consp(v171)) return onevalue(v22);
    v171 = v22;
    v171 = qcar(v171);
    v94 = elt(env, 1); /* (aeval reval) */
    v171 = Lmemq(nil, v171, v94);
    if (v171 == nil) return onevalue(v22);
    v171 = v22;
    v171 = qcdr(v171);
    v171 = qcar(v171);
    return onevalue(v171);
}



/* Code for redexpp */

static Lisp_Object CC_redexpp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v128, v26;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redexpp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v26 = v0;
/* end of prologue */
    v144 = v26;
    v144 = (consp(v144) ? nil : lisp_true);
    if (!(v144 == nil)) return onevalue(v144);
    v144 = v26;
    v128 = qcar(v144);
    v144 = qvalue(elt(env, 1)); /* !*redarithexpops!* */
    v144 = Lmemq(nil, v128, v144);
    if (!(v144 == nil)) return onevalue(v144);
    v144 = v26;
    v128 = qcar(v144);
    v144 = qvalue(elt(env, 2)); /* !*redlogexpops!* */
    v144 = Lmemq(nil, v128, v144);
    if (!(v144 == nil)) return onevalue(v144);
    v144 = v26;
    v144 = qcar(v144);
    v128 = qvalue(elt(env, 3)); /* !*redreswds!* */
    v144 = Lmemq(nil, v144, v128);
    v144 = (v144 == nil ? lisp_true : nil);
    return onevalue(v144);
}



/* Code for contain_edge */

static Lisp_Object CC_contain_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v28, v100, v101;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contain_edge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v1;
    v100 = v0;
/* end of prologue */

v168:
    v20 = v28;
    if (v20 == nil) goto v10;
    v20 = v100;
    v101 = qcar(v20);
    v20 = v28;
    v20 = qcar(v20);
    v20 = Lassoc(nil, v101, v20);
    if (!(v20 == nil)) return onevalue(v20);
    v20 = v28;
    v20 = qcdr(v20);
    v28 = v20;
    goto v168;

v10:
    v20 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v20);
}



/* Code for mo_dlexcomp */

static Lisp_Object CC_mo_dlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_dlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v157 = v1;
    v158 = v0;
/* end of prologue */
    v158 = qcar(v158);
    v157 = qcar(v157);
    fn = elt(env, 1); /* mo!=lexcomp */
    v158 = (*qfn2(fn))(qenv(fn), v158, v157);
    errexit();
    v157 = (Lisp_Object)17; /* 1 */
    v157 = (v158 == v157 ? lisp_true : nil);
    return onevalue(v157);
}



/* Code for fix_or_str */

static Lisp_Object CC_fix_or_str(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v159;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fix_or_str");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v112 = v0;
/* end of prologue */
    v159 = v112;
    v159 = integerp(v159);
    if (!(v159 == nil)) return onevalue(v159);
        return Lstringp(nil, v112);
}



/* Code for ggvars3 */

static Lisp_Object CC_ggvars3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v167, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ggvars3");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v146 = v1;
    v167 = v0;
/* end of prologue */

v45:
    v145 = v167;
    if (v145 == nil) { popv(2); return onevalue(v146); }
    v145 = v167;
    v145 = qcdr(v145);
    stack[0] = v145;
    v167 = qcar(v167);
    fn = elt(env, 1); /* ggvars2 */
    v146 = (*qfn2(fn))(qenv(fn), v167, v146);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-1];
    v167 = stack[0];
    goto v45;
/* error exit handlers */
v156:
    popv(2);
    return nil;
}



/* Code for reduce!-vec!-by!-one!-var!-mod!-p */

static Lisp_Object MS_CDECL CC_reduceKvecKbyKoneKvarKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v102, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v143, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-vec-by-one-var-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-vec-by-one-var-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v102,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v102);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v102;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v142 = stack[-3];
    v142 = Lmkvect(nil, v142);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-7];
    stack[-6] = v142;
    v142 = (Lisp_Object)17; /* 1 */
    stack[-2] = v142;
    goto v157;

v157:
    v143 = stack[-3];
    v142 = stack[-2];
    v142 = difference2(v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-7];
    v142 = Lminusp(nil, v142);
    env = stack[-7];
    if (!(v142 == nil)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    stack[-1] = stack[-6];
    stack[0] = stack[-2];
    v143 = stack[-5];
    v142 = stack[-2];
    v169 = *(Lisp_Object *)((char *)v143 + (CELL-TAG_VECTOR) + ((int32_t)v142/(16/CELL)));
    v142 = stack[-4];
    v143 = qcar(v142);
    v142 = stack[-4];
    v142 = qcdr(v142);
    fn = elt(env, 2); /* evaluate!-mod!-p */
    v142 = (*qfnn(fn))(qenv(fn), 3, v169, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v142;
    v142 = stack[-2];
    v142 = add1(v142);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-7];
    stack[-2] = v142;
    goto v157;
/* error exit handlers */
v140:
    popv(8);
    return nil;
}



/* Code for taysimpf */

static Lisp_Object CC_taysimpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249, v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taysimpf");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-6] = nil;
    stack[-4] = nil;
    v250 = qvalue(elt(env, 1)); /* nil */
    v249 = (Lisp_Object)17; /* 1 */
    v249 = cons(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-5] = v249;
    goto v79;

v79:
    v249 = stack[0];
    if (v249 == nil) goto v147;
    v249 = stack[0];
    if (!consp(v249)) goto v150;
    v249 = stack[0];
    v249 = qcar(v249);
    if (!consp(v249)) goto v150;
    v250 = elt(env, 2); /* taylor!* */
    v249 = stack[0];
    v249 = qcar(v249);
    fn = elt(env, 5); /* smember */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    if (v249 == nil) goto v143;
    v249 = stack[0];
    v249 = qcar(v249);
    fn = elt(env, 6); /* taysimpt */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-1] = v249;
    v249 = stack[-1];
    fn = elt(env, 7); /* kernp */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    if (v249 == nil) goto v190;
    v249 = stack[-1];
    v249 = qcar(v249);
    v249 = qcar(v249);
    v249 = qcar(v249);
    v250 = qcar(v249);
    v249 = elt(env, 2); /* taylor!* */
    if (!consp(v250)) goto v190;
    v250 = qcar(v250);
    if (!(v250 == v249)) goto v190;
    v249 = stack[-6];
    if (v249 == nil) goto v151;
    v250 = stack[-6];
    v249 = stack[-1];
    v249 = qcar(v249);
    v249 = qcar(v249);
    v249 = qcar(v249);
    v249 = qcar(v249);
    fn = elt(env, 8); /* comp!.tp!.!-p */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    if (v249 == nil) goto v195;
    v250 = stack[-6];
    v249 = stack[-1];
    v249 = qcar(v249);
    v249 = qcar(v249);
    v249 = qcar(v249);
    v249 = qcar(v249);
    fn = elt(env, 9); /* addtaylor */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-6] = v249;
    goto v94;

v94:
    v249 = stack[0];
    if (!consp(v249)) goto v252;
    v249 = stack[0];
    v249 = qcar(v249);
    if (!consp(v249)) goto v252;
    v249 = stack[0];
    v249 = qcdr(v249);
    goto v179;

v179:
    stack[0] = v249;
    goto v79;

v252:
    v249 = qvalue(elt(env, 1)); /* nil */
    goto v179;

v195:
    v249 = qvalue(elt(env, 3)); /* t */
    stack[-4] = v249;
    v250 = stack[-5];
    v249 = stack[-1];
    fn = elt(env, 10); /* addsq */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-5] = v249;
    goto v94;

v151:
    v249 = stack[-1];
    v249 = qcar(v249);
    v249 = qcar(v249);
    v249 = qcar(v249);
    v249 = qcar(v249);
    stack[-6] = v249;
    goto v94;

v190:
    v250 = stack[-5];
    v249 = stack[-1];
    fn = elt(env, 10); /* addsq */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-5] = v249;
    goto v94;

v143:
    stack[-1] = stack[-5];
    v249 = stack[0];
    v249 = qcar(v249);
    v250 = ncons(v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = (Lisp_Object)17; /* 1 */
    v249 = cons(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    fn = elt(env, 10); /* addsq */
    v249 = (*qfn2(fn))(qenv(fn), stack[-1], v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-5] = v249;
    goto v94;

v150:
    v250 = stack[0];
    v249 = (Lisp_Object)17; /* 1 */
    v250 = cons(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = stack[-5];
    fn = elt(env, 10); /* addsq */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-5] = v249;
    goto v94;

v147:
    v249 = stack[-6];
    if (v249 == nil) goto v192;
    v249 = stack[-6];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    if (v249 == nil) goto v192;
    v249 = stack[-6];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    v249 = qcar(v249);
    if (v249 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    else goto v192;

v192:
    v249 = stack[-5];
    v249 = qcar(v249);
    if (!(v249 == nil)) goto v35;
    v249 = stack[-6];
    if (v249 == nil) goto v35;
    v250 = stack[-6];
    v249 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 11); /* mksp */
    v250 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = (Lisp_Object)17; /* 1 */
    v249 = cons(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v250 = ncons(v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v249 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v250, v249);

v35:
    v249 = stack[-6];
    if (v249 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v249 = stack[-6];
    fn = elt(env, 12); /* taylor!*!-zerop */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    if (!(v249 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v249 = stack[-6];
    fn = elt(env, 13); /* taylor!*!-nzconstantp */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    if (v249 == nil) goto v253;
    v250 = elt(env, 2); /* taylor!* */
    v249 = stack[-5];
    fn = elt(env, 5); /* smember */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    if (!(v249 == nil)) goto v253;
    v249 = stack[-6];
    fn = elt(env, 14); /* get!-cst!-coeff */
    v250 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = stack[-5];
    {
        popv(8);
        fn = elt(env, 10); /* addsq */
        return (*qfn2(fn))(qenv(fn), v250, v249);
    }

v253:
    v249 = qvalue(elt(env, 4)); /* !*taylorautoexpand */
    if (!(v249 == nil)) goto v109;
    v249 = stack[-6];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    stack[-3] = v249;
    goto v254;

v254:
    v249 = stack[-3];
    if (v249 == nil) goto v255;
    v249 = stack[-3];
    v249 = qcar(v249);
    v250 = qcar(v249);
    v249 = qvalue(elt(env, 1)); /* nil */
    v249 = Lappend(nil, v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-2] = v249;
    v249 = stack[-2];
    fn = elt(env, 15); /* lastpair */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-1] = v249;
    v249 = stack[-3];
    v249 = qcdr(v249);
    stack[-3] = v249;
    v249 = stack[-1];
    if (!consp(v249)) goto v254;
    else goto v256;

v256:
    v249 = stack[-3];
    if (v249 == nil) goto v257;
    stack[0] = stack[-1];
    v249 = stack[-3];
    v249 = qcar(v249);
    v250 = qcar(v249);
    v249 = qvalue(elt(env, 1)); /* nil */
    v249 = Lappend(nil, v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = Lrplacd(nil, stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = stack[-1];
    fn = elt(env, 15); /* lastpair */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-1] = v249;
    v249 = stack[-3];
    v249 = qcdr(v249);
    stack[-3] = v249;
    goto v256;

v257:
    v249 = stack[-2];
    v250 = v249;
    goto v258;

v258:
    v249 = stack[-5];
    fn = elt(env, 16); /* smemberlp */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    if (v249 == nil) goto v109;
    v250 = stack[-6];
    v249 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 11); /* mksp */
    v250 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = (Lisp_Object)17; /* 1 */
    v249 = cons(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v250 = ncons(v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = (Lisp_Object)17; /* 1 */
    v250 = cons(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = stack[-5];
    {
        popv(8);
        fn = elt(env, 10); /* addsq */
        return (*qfn2(fn))(qenv(fn), v250, v249);
    }

v109:
    v249 = stack[-4];
    if (v249 == nil) goto v259;
    v250 = stack[-6];
    v249 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 11); /* mksp */
    v250 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = (Lisp_Object)17; /* 1 */
    v249 = cons(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v250 = ncons(v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = (Lisp_Object)17; /* 1 */
    v250 = cons(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = stack[-5];
    {
        popv(8);
        fn = elt(env, 10); /* addsq */
        return (*qfn2(fn))(qenv(fn), v250, v249);
    }

v259:
    v250 = stack[-5];
    v249 = stack[-6];
    v249 = qcdr(v249);
    v249 = qcdr(v249);
    v249 = qcar(v249);
    fn = elt(env, 17); /* taylorexpand */
    v249 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    stack[-5] = v249;
    stack[0] = stack[-5];
    v250 = stack[-6];
    v249 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 11); /* mksp */
    v250 = (*qfn2(fn))(qenv(fn), v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = (Lisp_Object)17; /* 1 */
    v249 = cons(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v250 = ncons(v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    v249 = (Lisp_Object)17; /* 1 */
    v249 = cons(v250, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    fn = elt(env, 18); /* addtaylor!-as!-sq */
    v249 = (*qfn2(fn))(qenv(fn), stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 19); /* taysimpsq!* */
        return (*qfn1(fn))(qenv(fn), v249);
    }

v255:
    v249 = qvalue(elt(env, 1)); /* nil */
    v250 = v249;
    goto v258;
/* error exit handlers */
v251:
    popv(8);
    return nil;
}



setup_type const u55_setup[] =
{
    {"in_list1",                too_few_2,      CC_in_list1,   wrong_no_2},
    {"ps:sqrt-erule",           too_few_2,      CC_psTsqrtKerule,wrong_no_2},
    {"symbid",                  too_few_2,      CC_symbid,     wrong_no_2},
    {"compex",                  CC_compex,      too_many_1,    wrong_no_1},
    {"num",                     CC_num,         too_many_1,    wrong_no_1},
    {"mx",                      CC_mx,          too_many_1,    wrong_no_1},
    {"gtraversopairlist",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_gtraversopairlist},
    {"rrest",                   CC_rrest,       too_many_1,    wrong_no_1},
    {"drop_dec_with",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_drop_dec_with},
    {"dpropagator",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_dpropagator},
    {"frlp",                    CC_frlp,        too_many_1,    wrong_no_1},
    {"put-kvalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKkvalue},
    {"restorealldfs",           CC_restorealldfs,too_many_1,   wrong_no_1},
    {"canonical",               CC_canonical,   too_many_1,    wrong_no_1},
    {"pseudo-divide",           CC_pseudoKdivide,too_many_1,   wrong_no_1},
    {"evalwhereexp",            CC_evalwhereexp,too_many_1,    wrong_no_1},
    {"nsubsf",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_nsubsf},
    {"ofsf_optsubstat",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_optsubstat},
    {"bra_ordp",                too_few_2,      CC_bra_ordp,   wrong_no_2},
    {"findsquareroot",          CC_findsquareroot,too_many_1,  wrong_no_1},
    {"simppsexplim",            CC_simppsexplim,too_many_1,    wrong_no_1},
    {"delnil",                  CC_delnil,      too_many_1,    wrong_no_1},
    {"transferrow",             too_few_2,      CC_transferrow,wrong_no_2},
    {"new_simpexpt",            CC_new_simpexpt,too_many_1,    wrong_no_1},
    {"iscale",                  too_few_2,      CC_iscale,     wrong_no_2},
    {"indvarpf",                CC_indvarpf,    too_many_1,    wrong_no_1},
    {"not_included",            too_few_2,      CC_not_included,wrong_no_2},
    {"replace1_edge",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_replace1_edge},
    {"random-prime",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_randomKprime},
    {"compactf",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf},
    {"pst_isolate",             too_few_2,      CC_pst_isolate,wrong_no_2},
    {"general-xquotient-mod-p", wrong_no_na,    wrong_no_nb,   (n_args *)CC_generalKxquotientKmodKp},
    {"quotfail-mod-p",          too_few_2,      CC_quotfailKmodKp,wrong_no_2},
    {"sfto_yun-updecf",         CC_sfto_yunKupdecf,too_many_1, wrong_no_1},
    {"evalletsub2",             too_few_2,      CC_evalletsub2,wrong_no_2},
    {"aex_lc",                  too_few_2,      CC_aex_lc,     wrong_no_2},
    {"bc_dcont",                CC_bc_dcont,    too_many_1,    wrong_no_1},
    {"rread",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_rread},
    {"f2vdp",                   CC_f2vdp,       too_many_1,    wrong_no_1},
    {"formclear1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclear1},
    {"declared-as-float",       CC_declaredKasKfloat,too_many_1,wrong_no_1},
    {"coeff_edges",             CC_coeff_edges, too_many_1,    wrong_no_1},
    {"addfd",                   too_few_2,      CC_addfd,      wrong_no_2},
    {"tayminpowerlist",         CC_tayminpowerlist,too_many_1, wrong_no_1},
    {"acfsf_prepat",            CC_acfsf_prepat,too_many_1,    wrong_no_1},
    {"inszzzr",                 too_few_2,      CC_inszzzr,    wrong_no_2},
    {"sign-of",                 CC_signKof,     too_many_1,    wrong_no_1},
    {"tstpolyarg",              too_few_2,      CC_tstpolyarg, wrong_no_2},
    {"exformp",                 CC_exformp,     too_many_1,    wrong_no_1},
    {"unreval",                 CC_unreval,     too_many_1,    wrong_no_1},
    {"redexpp",                 CC_redexpp,     too_many_1,    wrong_no_1},
    {"contain_edge",            too_few_2,      CC_contain_edge,wrong_no_2},
    {"mo_dlexcomp",             too_few_2,      CC_mo_dlexcomp,wrong_no_2},
    {"fix_or_str",              CC_fix_or_str,  too_many_1,    wrong_no_1},
    {"ggvars3",                 too_few_2,      CC_ggvars3,    wrong_no_2},
    {"reduce-vec-by-one-var-mod-p",wrong_no_na, wrong_no_nb,   (n_args *)CC_reduceKvecKbyKoneKvarKmodKp},
    {"taysimpf",                CC_taysimpf,    too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u55", (two_args *)"17381 7260011 8816735", 0}
};

/* end of generated code */
