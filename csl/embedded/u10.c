
/* $destdir/generated-c\u10.c Machine generated C code */

/* Signature: 00000000 13-Aug-2010 */

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
extern Lisp_Object gchook, resources, callstack;
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
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
#endif
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
extern jmp_buf *errorset_buffer;
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


/* Code for ibalp_var!-wclist */

static Lisp_Object CC_ibalp_varKwclist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-wclist");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0;
/* end of prologue */
    stack[-3] = nil;
    v23 = stack[-4];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcar(v23);
    stack[-2] = v23;
    goto v25;

v25:
    v23 = stack[-2];
    if (v23 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v23 = stack[-2];
    v23 = qcar(v23);
    stack[-1] = v23;
    v23 = stack[-1];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcar(v23);
    if (!(v23 == nil)) goto v26;
    v23 = stack[-1];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    stack[0] = qcdr(v23);
    v24 = stack[-4];
    v23 = stack[-1];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcar(v23);
    fn = elt(env, 2); /* delq */
    v23 = (*qfn2(fn))(qenv(fn), v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v23 = (*qfn2(fn))(qenv(fn), stack[0], v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    v23 = stack[-4];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    stack[0] = qcdr(v23);
    v24 = stack[-1];
    v23 = stack[-4];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcar(v23);
    fn = elt(env, 2); /* delq */
    v23 = (*qfn2(fn))(qenv(fn), v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v23 = (*qfn2(fn))(qenv(fn), stack[0], v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    v23 = stack[-1];
    fn = elt(env, 4); /* ibalp_getnewwl */
    v23 = (*qfn1(fn))(qenv(fn), v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    stack[-5] = v23;
    v23 = stack[-5];
    if (v23 == nil) goto v28;
    v23 = stack[-1];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    stack[0] = qcdr(v23);
    v24 = stack[-5];
    v23 = stack[-1];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcar(v23);
    v23 = cons(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v23 = (*qfn2(fn))(qenv(fn), stack[0], v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    v23 = stack[-5];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    stack[0] = qcdr(v23);
    v24 = stack[-1];
    v23 = stack[-5];
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcdr(v23);
    v23 = qcar(v23);
    v23 = cons(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v23 = (*qfn2(fn))(qenv(fn), stack[0], v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    goto v26;

v26:
    v23 = stack[-2];
    v23 = qcdr(v23);
    stack[-2] = v23;
    goto v25;

v28:
    v24 = stack[-1];
    v23 = stack[-3];
    v23 = cons(v24, v23);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-6];
    stack[-3] = v23;
    goto v26;
/* error exit handlers */
v27:
    popv(7);
    return nil;
}



/* Code for omvir */

static Lisp_Object MS_CDECL CC_omvir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omvir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omvir");
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
    v19 = qvalue(elt(env, 1)); /* atts */
    v18 = elt(env, 2); /* name */
    fn = elt(env, 6); /* find */
    v18 = (*qfn2(fn))(qenv(fn), v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    stack[0] = v18;
    v19 = qvalue(elt(env, 1)); /* atts */
    v18 = elt(env, 3); /* hex */
    fn = elt(env, 6); /* find */
    v18 = (*qfn2(fn))(qenv(fn), v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    if (v18 == nil) goto v40;
    v19 = elt(env, 4); /* "wrong att" */
    v18 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 7); /* errorml */
    v18 = (*qfn2(fn))(qenv(fn), v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    goto v40;

v40:
    v19 = qvalue(elt(env, 1)); /* atts */
    v18 = elt(env, 5); /* dec */
    fn = elt(env, 6); /* find */
    v18 = (*qfn2(fn))(qenv(fn), v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-1];
    if (v18 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v19 = elt(env, 4); /* "wrong att" */
    v18 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 7); /* errorml */
    v18 = (*qfn2(fn))(qenv(fn), v19, v18);
    nil = C_nil;
    if (exception_pending()) goto v39;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v39:
    popv(2);
    return nil;
}



/* Code for c!:subs2multf */

static Lisp_Object CC_cTsubs2multf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v29, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:subs2multf");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v29 = v31;
    v30 = v0;
/* end of prologue */
    v49 = qvalue(elt(env, 1)); /* !*sub2 */
    stack[0] = qvalue(elt(env, 1)); /* !*sub2 */
    qvalue(elt(env, 1)) = v49; /* !*sub2 */
    v49 = v30;
    fn = elt(env, 4); /* multf */
    v29 = (*qfn2(fn))(qenv(fn), v49, v29);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v49 = (Lisp_Object)17; /* 1 */
    v49 = cons(v29, v49);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    fn = elt(env, 5); /* subs2 */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    v30 = v49;
    v49 = v30;
    v29 = qcdr(v49);
    v49 = (Lisp_Object)17; /* 1 */
    if (v29 == v49) goto v50;
    v30 = elt(env, 2); /* matrix */
    v29 = (Lisp_Object)225; /* 14 */
    v49 = elt(env, 3); /* "Sub error in glnrsolve" */
    fn = elt(env, 6); /* rerror */
    v49 = (*qfnn(fn))(qenv(fn), 3, v30, v29, v49);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    goto v36;

v36:
    qvalue(elt(env, 1)) = stack[0]; /* !*sub2 */
    { popv(2); return onevalue(v49); }

v50:
    v49 = v30;
    v49 = qcar(v49);
    goto v36;
/* error exit handlers */
v18:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*sub2 */
    popv(2);
    return nil;
}



/* Code for listdiff */

static Lisp_Object CC_listdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listdiff");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    v53 = v0;
/* end of prologue */

v54:
    v6 = stack[0];
    if (v6 == nil) { popv(2); return onevalue(v53); }
    v6 = v53;
    if (v6 == nil) goto v45;
    v6 = stack[0];
    v6 = qcar(v6);
    v53 = Ldelete(nil, v6, v53);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-1];
    v6 = stack[0];
    v6 = qcdr(v6);
    stack[0] = v6;
    goto v54;

v45:
    v53 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v53); }
/* error exit handlers */
v26:
    popv(2);
    return nil;
}



/* Code for equal!: */

static Lisp_Object CC_equalT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for equal:");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v18 = stack[-1];
    v18 = qcdr(v18);
    v18 = qcar(v18);
    v18 = (Lisp_Object)zerop(v18);
    v18 = v18 ? lisp_true : nil;
    env = stack[-3];
    if (v18 == nil) goto v56;
    v18 = stack[0];
    v18 = qcdr(v18);
    v18 = qcar(v18);
    v18 = (Lisp_Object)zerop(v18);
    v18 = v18 ? lisp_true : nil;
    env = stack[-3];
    goto v57;

v57:
    if (!(v18 == nil)) { popv(4); return onevalue(v18); }
    v18 = stack[-1];
    fn = elt(env, 2); /* csl_normbf */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[-1] = v18;
    v18 = qcdr(v18);
    stack[-2] = qcdr(v18);
    v18 = stack[0];
    fn = elt(env, 2); /* csl_normbf */
    v18 = (*qfn1(fn))(qenv(fn), v18);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-3];
    stack[0] = v18;
    v18 = qcdr(v18);
    v18 = qcdr(v18);
    if (equal(stack[-2], v18)) goto v59;
    v18 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v18); }

v59:
    v18 = stack[-1];
    v18 = qcdr(v18);
    v19 = qcar(v18);
    v18 = stack[0];
    v18 = qcdr(v18);
    v18 = qcar(v18);
    v18 = (equal(v19, v18) ? lisp_true : nil);
    { popv(4); return onevalue(v18); }

v56:
    v18 = qvalue(elt(env, 1)); /* nil */
    goto v57;
/* error exit handlers */
v58:
    popv(4);
    return nil;
}



/* Code for has_parents */

static Lisp_Object CC_has_parents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v34, v26;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for has_parents");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v0;
/* end of prologue */
    v6 = qcdr(v6);
    v6 = qcar(v6);
    v26 = v6;
    v6 = v26;
    v34 = qcar(v6);
    v6 = elt(env, 1); /* !? */
    if (v34 == v6) goto v56;
    v6 = v26;
    v6 = qcdr(v6);
    v34 = elt(env, 1); /* !? */
        return Lneq(nil, v6, v34);

v56:
    v6 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v6);
}



/* Code for red!-ratios1 */

static Lisp_Object CC_redKratios1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v43, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-ratios1");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */

v65:
    v32 = stack[-1];
    if (v32 == nil) goto v54;
    v32 = stack[-1];
    v50 = qcdr(v32);
    v32 = stack[0];
    v43 = qcdr(v32);
    v32 = stack[-1];
    v33 = qcar(v32);
    v32 = stack[0];
    v32 = qcar(v32);
    fn = elt(env, 2); /* red!-ratios2 */
    v32 = (*qfnn(fn))(qenv(fn), 4, v50, v43, v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    if (!(v32 == nil)) { popv(3); return onevalue(v32); }
    v32 = stack[-1];
    v33 = qcdr(v32);
    v32 = stack[0];
    v32 = qcdr(v32);
    stack[-1] = v33;
    stack[0] = v32;
    goto v65;

v54:
    v32 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v32); }
/* error exit handlers */
v55:
    popv(3);
    return nil;
}



/* Code for mo_neg */

static Lisp_Object CC_mo_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_neg");
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
    stack[-2] = v0;
/* end of prologue */
    v67 = stack[-2];
    v67 = qcar(v67);
    stack[-4] = v67;
    v67 = stack[-4];
    if (v67 == nil) goto v47;
    v67 = stack[-4];
    v67 = qcar(v67);
    v67 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    stack[-1] = v67;
    stack[-3] = v67;
    goto v69;

v69:
    v67 = stack[-4];
    v67 = qcdr(v67);
    stack[-4] = v67;
    v67 = stack[-4];
    if (v67 == nil) goto v26;
    stack[0] = stack[-1];
    v67 = stack[-4];
    v67 = qcar(v67);
    v67 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v67 = Lrplacd(nil, stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    goto v69;

v26:
    v67 = stack[-3];
    stack[-4] = v67;
    goto v54;

v54:
    v67 = stack[-2];
    v67 = qcdr(v67);
    stack[-3] = v67;
    v67 = stack[-3];
    if (v67 == nil) goto v70;
    v67 = stack[-3];
    v67 = qcar(v67);
    v67 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    stack[-1] = v67;
    stack[-2] = v67;
    goto v39;

v39:
    v67 = stack[-3];
    v67 = qcdr(v67);
    stack[-3] = v67;
    v67 = stack[-3];
    if (v67 == nil) goto v71;
    stack[0] = stack[-1];
    v67 = stack[-3];
    v67 = qcar(v67);
    v67 = negate(v67);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v67 = ncons(v67);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v67 = Lrplacd(nil, stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v67 = stack[-1];
    v67 = qcdr(v67);
    stack[-1] = v67;
    goto v39;

v71:
    v67 = stack[-2];
    goto v22;

v22:
    {
        Lisp_Object v72 = stack[-4];
        popv(6);
        return cons(v72, v67);
    }

v70:
    v67 = qvalue(elt(env, 1)); /* nil */
    goto v22;

v47:
    v67 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v67;
    goto v54;
/* error exit handlers */
v68:
    popv(6);
    return nil;
}



/* Code for freeof */

static Lisp_Object CC_freeof(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v34, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v34 = stack[0];
    v6 = stack[-1];
    fn = elt(env, 2); /* smember */
    v6 = (*qfn2(fn))(qenv(fn), v34, v6);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    if (!(v6 == nil)) goto v41;
    v34 = stack[0];
    v6 = stack[-1];
    v26 = qvalue(elt(env, 1)); /* depl!* */
    v6 = Lassoc(nil, v6, v26);
    v6 = Lmember(nil, v34, v6);
    goto v41;

v41:
    v6 = (v6 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v6); }
/* error exit handlers */
v73:
    popv(3);
    return nil;
}



/* Code for rl_simplat1 */

static Lisp_Object CC_rl_simplat1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simplat1");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v47 = v31;
    v48 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_simplat1!* */
    v47 = list2(v48, v47);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-1];
    {
        Lisp_Object v35 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v35, v47);
    }
/* error exit handlers */
v42:
    popv(2);
    return nil;
}



/* Code for gcdf2 */

static Lisp_Object CC_gcdf2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdf2");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v31;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* asymplis!* */
    qvalue(elt(env, 1)) = nil; /* asymplis!* */
    v111 = stack[-5];
    fn = elt(env, 4); /* num!-exponents */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    if (v111 == nil) goto v37;
    v111 = stack[-4];
    fn = elt(env, 4); /* num!-exponents */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    if (v111 == nil) goto v37;
    v111 = qvalue(elt(env, 2)); /* !*gcd */
    if (v111 == nil) goto v49;
    v112 = stack[-5];
    v111 = stack[-4];
    fn = elt(env, 5); /* kernord */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-3] = v111;
    v112 = Llength(nil, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v111 = (Lisp_Object)17; /* 1 */
    v111 = (Lisp_Object)greaterp2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v111 = v111 ? lisp_true : nil;
    env = stack[-7];
    if (v111 == nil) goto v49;
    v111 = stack[-3];
    fn = elt(env, 6); /* setkorder */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-3] = v111;
    v111 = stack[-5];
    fn = elt(env, 7); /* reorder */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-5] = v111;
    v111 = stack[-4];
    fn = elt(env, 7); /* reorder */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-4] = v111;
    goto v39;

v39:
    v111 = stack[-5];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v112 = qcar(v111);
    v111 = stack[-4];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = qcar(v111);
    if (v112 == v111) goto v19;
    v111 = stack[-5];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = qcar(v111);
    fn = elt(env, 8); /* noncomp */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    if (v111 == nil) goto v115;
    v111 = stack[-4];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = qcar(v111);
    fn = elt(env, 8); /* noncomp */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    if (v111 == nil) goto v115;
    v113 = stack[-5];
    v112 = stack[-4];
    v111 = stack[-4];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = qcar(v111);
    fn = elt(env, 9); /* gcdfnc */
    v111 = (*qfnn(fn))(qenv(fn), 3, v113, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v111;
    goto v18;

v18:
    v111 = stack[-3];
    if (v111 == nil) goto v116;
    v111 = stack[-3];
    v111 = qcar(v111);
    fn = elt(env, 6); /* setkorder */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v111 = stack[-2];
    fn = elt(env, 7); /* reorder */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v111;
    goto v116;

v116:
    v111 = stack[-2];
    goto v57;

v57:
    qvalue(elt(env, 1)) = stack[-6]; /* asymplis!* */
    { popv(8); return onevalue(v111); }

v115:
    v111 = stack[-5];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v112 = qcar(v111);
    v111 = stack[-4];
    v111 = qcar(v111);
    v111 = qcar(v111);
    v111 = qcar(v111);
    fn = elt(env, 10); /* ordop */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    if (v111 == nil) goto v117;
    v111 = stack[-5];
    fn = elt(env, 11); /* comfac */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v112 = qcdr(v111);
    v111 = stack[-4];
    fn = elt(env, 12); /* gcdf1 */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v111;
    goto v18;

v117:
    v111 = stack[-4];
    fn = elt(env, 11); /* comfac */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v112 = qcdr(v111);
    v111 = stack[-5];
    fn = elt(env, 12); /* gcdf1 */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v111;
    goto v18;

v19:
    v111 = stack[-5];
    fn = elt(env, 11); /* comfac */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-1] = v111;
    v111 = stack[-4];
    fn = elt(env, 11); /* comfac */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[0] = v111;
    v111 = stack[-1];
    v112 = qcdr(v111);
    v111 = stack[0];
    v111 = qcdr(v111);
    fn = elt(env, 12); /* gcdf1 */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v111;
    v111 = stack[-1];
    fn = elt(env, 13); /* comfac!-to!-poly */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    fn = elt(env, 14); /* quotf1 */
    v111 = (*qfn2(fn))(qenv(fn), stack[-5], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-5] = v111;
    v111 = stack[0];
    fn = elt(env, 13); /* comfac!-to!-poly */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    fn = elt(env, 14); /* quotf1 */
    v111 = (*qfn2(fn))(qenv(fn), stack[-4], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-4] = v111;
    v111 = qvalue(elt(env, 2)); /* !*gcd */
    if (v111 == nil) goto v118;
    v112 = stack[-5];
    v111 = stack[-4];
    fn = elt(env, 15); /* gcdk */
    v112 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v111 = stack[-2];
    fn = elt(env, 16); /* multf */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v111;
    goto v119;

v119:
    v111 = stack[-1];
    v111 = qcar(v111);
    if (v111 == nil) goto v18;
    v111 = stack[0];
    v111 = qcar(v111);
    if (v111 == nil) goto v18;
    v111 = stack[-1];
    v111 = qcar(v111);
    v112 = qcdr(v111);
    v111 = stack[0];
    v111 = qcar(v111);
    v111 = qcdr(v111);
    v111 = (Lisp_Object)greaterp2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v111 = v111 ? lisp_true : nil;
    env = stack[-7];
    if (v111 == nil) goto v120;
    v111 = stack[0];
    v112 = qcar(v111);
    v111 = (Lisp_Object)17; /* 1 */
    v111 = cons(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v112 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v111 = stack[-2];
    fn = elt(env, 16); /* multf */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v111;
    goto v18;

v120:
    v111 = stack[-1];
    v112 = qcar(v111);
    v111 = (Lisp_Object)17; /* 1 */
    v111 = cons(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v112 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    v111 = stack[-2];
    fn = elt(env, 16); /* multf */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v111;
    goto v18;

v118:
    v111 = stack[-4];
    if (v111 == nil) goto v121;
    v112 = stack[-5];
    v111 = stack[-4];
    fn = elt(env, 14); /* quotf1 */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    if (v111 == nil) goto v121;
    v112 = stack[-4];
    v111 = stack[-2];
    fn = elt(env, 16); /* multf */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v111;
    goto v119;

v121:
    v111 = stack[-5];
    if (v111 == nil) goto v119;
    v112 = stack[-4];
    v111 = stack[-5];
    fn = elt(env, 14); /* quotf1 */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    if (v111 == nil) goto v119;
    v112 = stack[-5];
    v111 = stack[-2];
    fn = elt(env, 16); /* multf */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-7];
    stack[-2] = v111;
    goto v119;

v49:
    v111 = qvalue(elt(env, 3)); /* nil */
    stack[-3] = v111;
    goto v39;

v37:
    v111 = (Lisp_Object)17; /* 1 */
    goto v57;
/* error exit handlers */
v114:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* asymplis!* */
    popv(8);
    return nil;
}



/* Code for kernp */

static Lisp_Object CC_kernp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v20, v70;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    v123 = v20;
    v70 = qcdr(v123);
    v123 = (Lisp_Object)17; /* 1 */
    if (v70 == v123) goto v54;
    v123 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v123);

v54:
    v123 = v20;
    v123 = qcar(v123);
    v20 = v123;
    v70 = v123;
    v123 = v70;
    v123 = (consp(v123) ? nil : lisp_true);
    if (!(v123 == nil)) goto v42;
    v123 = v70;
    v123 = qcar(v123);
    v123 = (consp(v123) ? nil : lisp_true);
    goto v42;

v42:
    if (v123 == nil) goto v62;
    v123 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v123);

v62:
    v123 = v20;
    v123 = qcdr(v123);
    if (v123 == nil) goto v124;
    v123 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v123);

v124:
    v123 = v20;
    v123 = qcar(v123);
    v70 = qcdr(v123);
    v123 = (Lisp_Object)17; /* 1 */
    if (v70 == v123) goto v55;
    v123 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v123);

v55:
    v123 = v20;
    v123 = qcar(v123);
    v123 = qcar(v123);
    v20 = qcdr(v123);
    v123 = (Lisp_Object)17; /* 1 */
    v123 = (v20 == v123 ? lisp_true : nil);
    return onevalue(v123);
}



/* Code for ibalp_getvar!-zmom */

static Lisp_Object CC_ibalp_getvarKzmom(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_getvar-zmom");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v12 = v31;
    stack[0] = v0;
/* end of prologue */
    stack[-4] = nil;
    fn = elt(env, 2); /* ibalp_minclnr */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    stack[-5] = v12;
    v12 = (Lisp_Object)-15; /* -1 */
    stack[-3] = v12;
    v12 = stack[0];
    stack[-1] = v12;
    goto v62;

v62:
    v12 = stack[-1];
    if (v12 == nil) goto v130;
    v12 = stack[-1];
    v12 = qcar(v12);
    stack[0] = v12;
    v12 = stack[0];
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    if (!(v12 == nil)) goto v60;
    v12 = stack[0];
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v128 = qcar(v12);
    stack[-2] = v128;
    v12 = stack[-3];
    v12 = (Lisp_Object)greaterp2(v128, v12);
    nil = C_nil;
    if (exception_pending()) goto v129;
    v12 = v12 ? lisp_true : nil;
    env = stack[-6];
    if (v12 == nil) goto v60;
    v12 = stack[0];
    v128 = qcdr(v12);
    v12 = stack[-5];
    fn = elt(env, 3); /* ibalp_isinminclause */
    v12 = (*qfn2(fn))(qenv(fn), v128, v12);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[-6];
    if (v12 == nil) goto v60;
    v12 = stack[0];
    v12 = qcdr(v12);
    stack[-4] = v12;
    v12 = stack[-2];
    stack[-3] = v12;
    goto v60;

v60:
    v12 = stack[-1];
    v12 = qcdr(v12);
    stack[-1] = v12;
    goto v62;

v130:
    v12 = stack[-4];
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v128 = qcar(v12);
    v12 = stack[-4];
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcdr(v12);
    v12 = qcar(v12);
    v12 = (Lisp_Object)greaterp2(v128, v12);
    nil = C_nil;
    if (exception_pending()) goto v129;
    v12 = v12 ? lisp_true : nil;
    if (v12 == nil) goto v118;
    v12 = (Lisp_Object)17; /* 1 */
    goto v131;

v131:
    v128 = stack[-4];
    popv(7);
    return cons(v128, v12);

v118:
    v12 = (Lisp_Object)1; /* 0 */
    goto v131;
/* error exit handlers */
v129:
    popv(7);
    return nil;
}



/* Code for integerom */

static Lisp_Object CC_integerom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for integerom");
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
    v37 = elt(env, 1); /* "<OMI> " */
    fn = elt(env, 3); /* printout */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    v37 = stack[0];
    v37 = Lprinc(nil, v37);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-1];
    v37 = elt(env, 2); /* " </OMI>" */
    v37 = Lprinc(nil, v37);
    nil = C_nil;
    if (exception_pending()) goto v45;
    v37 = nil;
    { popv(2); return onevalue(v37); }
/* error exit handlers */
v45:
    popv(2);
    return nil;
}



/* Code for rnconc */

static Lisp_Object CC_rnconc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnconc");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v19 = stack[-1];
    if (v19 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v19 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v19 == nil) goto v63;
    v19 = stack[-1];
    fn = elt(env, 3); /* noncomfp1 */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    if (v19 == nil) goto v63;
    v19 = stack[0];
    fn = elt(env, 3); /* noncomfp1 */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    if (v19 == nil) goto v63;
    v132 = stack[-1];
    v19 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v132, v19);
    }

v63:
    v19 = stack[-1];
    v132 = v19;
    goto v73;

v73:
    v19 = v132;
    v19 = qcdr(v19);
    if (v19 == nil) goto v55;
    v19 = v132;
    v19 = qcdr(v19);
    v132 = v19;
    goto v73;

v55:
    v19 = stack[0];
    v19 = Lrplacd(nil, v132, v19);
    nil = C_nil;
    if (exception_pending()) goto v58;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for dp_times_bcmo */

static Lisp_Object MS_CDECL CC_dp_times_bcmo(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dp_times_bcmo");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_times_bcmo");
#endif
    if (stack >= stacklimit)
    {
        push3(v5,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v137 = v5;
    stack[-5] = v31;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = v137;
    v137 = stack[-7];
    if (v137 == nil) goto v69;
    v137 = stack[-7];
    v137 = qcar(v137);
    stack[-1] = v137;
    v138 = stack[-5];
    v137 = stack[-1];
    v137 = qcar(v137);
    fn = elt(env, 2); /* mo_sum */
    stack[0] = (*qfn2(fn))(qenv(fn), v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-8];
    v138 = stack[-6];
    v137 = stack[-1];
    v137 = qcdr(v137);
    fn = elt(env, 3); /* bc_prod */
    v137 = (*qfn2(fn))(qenv(fn), v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-8];
    v137 = cons(stack[0], v137);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-8];
    v137 = ncons(v137);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-8];
    stack[-3] = v137;
    stack[-4] = v137;
    goto v25;

v25:
    v137 = stack[-7];
    v137 = qcdr(v137);
    stack[-7] = v137;
    v137 = stack[-7];
    if (v137 == nil) { Lisp_Object res = stack[-4]; popv(9); return onevalue(res); }
    stack[-2] = stack[-3];
    v137 = stack[-7];
    v137 = qcar(v137);
    stack[-1] = v137;
    v138 = stack[-5];
    v137 = stack[-1];
    v137 = qcar(v137);
    fn = elt(env, 2); /* mo_sum */
    stack[0] = (*qfn2(fn))(qenv(fn), v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-8];
    v138 = stack[-6];
    v137 = stack[-1];
    v137 = qcdr(v137);
    fn = elt(env, 3); /* bc_prod */
    v137 = (*qfn2(fn))(qenv(fn), v138, v137);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-8];
    v137 = cons(stack[0], v137);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-8];
    v137 = ncons(v137);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-8];
    v137 = Lrplacd(nil, stack[-2], v137);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-8];
    v137 = stack[-3];
    v137 = qcdr(v137);
    stack[-3] = v137;
    goto v25;

v69:
    v137 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v137); }
/* error exit handlers */
v68:
    popv(9);
    return nil;
}



/* Code for dl_get */

static Lisp_Object CC_dl_get(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dl_get");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v37 = v0;
/* end of prologue */
    v38 = v37;
    v37 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* dl_get2 */
        return (*qfn2(fn))(qenv(fn), v38, v37);
    }
}



/* Code for kernord */

static Lisp_Object CC_kernord(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v36 = v31;
    stack[0] = v0;
/* end of prologue */
    v139 = stack[0];
    fn = elt(env, 1); /* kernord!-split */
    v36 = (*qfn2(fn))(qenv(fn), v139, v36);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    stack[0] = v36;
    v36 = stack[0];
    v36 = qcar(v36);
    fn = elt(env, 2); /* kernord!-sort */
    stack[-1] = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-2];
    v36 = stack[0];
    v36 = qcdr(v36);
    fn = elt(env, 2); /* kernord!-sort */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v63;
    {
        Lisp_Object v60 = stack[-1];
        popv(3);
        return Lappend(nil, v60, v36);
    }
/* error exit handlers */
v63:
    popv(3);
    return nil;
}



/* Code for mconv */

static Lisp_Object CC_mconv(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mconv");
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
    v22 = qvalue(elt(env, 1)); /* dmode!* */
    fn = elt(env, 2); /* dmconv0 */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-1];
    v22 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* mconv1 */
        return (*qfn1(fn))(qenv(fn), v22);
    }
/* error exit handlers */
v56:
    popv(2);
    return nil;
}



/* Code for make!-univariate!-image!-mod!-p */

static Lisp_Object CC_makeKunivariateKimageKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-univariate-image-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v31;
    stack[-2] = v0;
/* end of prologue */
    v131 = stack[-2];
    if (!consp(v131)) goto v54;
    v131 = stack[-2];
    v131 = qcar(v131);
    if (!consp(v131)) goto v54;
    v131 = stack[-2];
    v131 = qcar(v131);
    v131 = qcar(v131);
    v28 = qcar(v131);
    v131 = stack[-1];
    if (equal(v28, v131)) goto v124;
    v131 = stack[-2];
    v131 = qcar(v131);
    v131 = qcar(v131);
    v28 = qcar(v131);
    v131 = stack[-2];
    v131 = qcar(v131);
    v131 = qcar(v131);
    v131 = qcdr(v131);
    fn = elt(env, 2); /* image!-of!-power */
    stack[0] = (*qfn2(fn))(qenv(fn), v28, v131);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v131 = stack[-2];
    v131 = qcar(v131);
    v28 = qcdr(v131);
    v131 = stack[-1];
    v131 = CC_makeKunivariateKimageKmodKp(env, v28, v131);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    fn = elt(env, 3); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v131 = stack[-2];
    v28 = qcdr(v131);
    v131 = stack[-1];
    v131 = CC_makeKunivariateKimageKmodKp(env, v28, v131);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    {
        Lisp_Object v12 = stack[0];
        popv(5);
        fn = elt(env, 4); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v12, v131);
    }

v124:
    v131 = stack[-2];
    v131 = qcar(v131);
    stack[-3] = qcar(v131);
    v131 = stack[-2];
    v131 = qcar(v131);
    v28 = qcdr(v131);
    v131 = stack[-1];
    stack[0] = CC_makeKunivariateKimageKmodKp(env, v28, v131);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    v131 = stack[-2];
    v28 = qcdr(v131);
    v131 = stack[-1];
    v131 = CC_makeKunivariateKimageKmodKp(env, v28, v131);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-4];
    {
        Lisp_Object v128 = stack[-3];
        Lisp_Object v146 = stack[0];
        popv(5);
        fn = elt(env, 5); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v128, v146, v131);
    }

v54:
    v131 = stack[-2];
    if (v131 == nil) goto v147;
    v131 = stack[-2];
    v131 = Lmodular_number(nil, v131);
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 6); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v131);
    }

v147:
    v131 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v131); }
/* error exit handlers */
v11:
    popv(5);
    return nil;
}



/* Code for searchtm */

static Lisp_Object CC_searchtm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for searchtm");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v63 = v0;
/* end of prologue */
    v52 = v63;
    if (!consp(v52)) goto v41;
    v52 = v63;
    v52 = qcar(v52);
    if (!consp(v52)) goto v41;
    v52 = v63;
    v52 = qcar(v52);
    stack[0] = qcar(v52);
    v52 = v63;
    v52 = qcdr(v52);
    fn = elt(env, 2); /* searchpl */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v53;
    {
        Lisp_Object v6 = stack[0];
        popv(1);
        return cons(v6, v52);
    }

v41:
    v52 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v52); }
/* error exit handlers */
v53:
    popv(1);
    return nil;
}



/* Code for removeg1 */

static Lisp_Object MS_CDECL CC_removeg1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v193, v194, v195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "removeg1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg1");
#endif
    if (stack >= stacklimit)
    {
        push3(v5,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v5;
    stack[-4] = v31;
    stack[-5] = v0;
/* end of prologue */
    v193 = stack[-5];
    v192 = stack[-4];
    fn = elt(env, 8); /* removev */
    v192 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v193 = stack[-5];
    v192 = stack[-3];
    fn = elt(env, 8); /* removev */
    v192 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = stack[-4];
    v192 = qcdr(v192);
    v193 = qcar(v192);
    v192 = stack[-3];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcar(v192);
    if (!(v193 == v192)) goto v71;
    v192 = stack[-4];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v193 = qcar(v192);
    v192 = stack[-3];
    v192 = qcdr(v192);
    v192 = qcar(v192);
    if (!(v193 == v192)) goto v71;
    v193 = qvalue(elt(env, 1)); /* n!*!*2!-1 */
    v192 = stack[-5];
    v192 = qcar(v192);
    fn = elt(env, 9); /* multsq */
    v193 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = stack[-5];
    v192 = qcdr(v192);
    v192 = cons(v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    popv(8);
    return ncons(v192);

v71:
    v192 = stack[-5];
    v193 = qcdr(v192);
    v192 = stack[-4];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcar(v192);
    fn = elt(env, 10); /* finde */
    v192 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    stack[-6] = v192;
    v192 = stack[-4];
    v192 = qcdr(v192);
    v193 = qcar(v192);
    v192 = stack[-3];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcar(v192);
    if (v193 == v192) goto v143;
    v192 = stack[-5];
    v193 = qcdr(v192);
    v192 = stack[-3];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v192 = qcar(v192);
    fn = elt(env, 10); /* finde */
    v192 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    stack[-2] = v192;
    v192 = stack[-4];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v193 = qcar(v192);
    v192 = stack[-3];
    v192 = qcdr(v192);
    v192 = qcar(v192);
    if (v193 == v192) goto v197;
    v192 = stack[-6];
    if (v192 == nil) goto v198;
    v192 = stack[-2];
    if (!(v192 == nil)) goto v199;

v198:
    stack[0] = elt(env, 6); /* "Invalid structure of c-graph" */
    v192 = stack[-5];
    if (v192 == nil) goto v200;
    v192 = stack[-5];
    v192 = qcdr(v192);
    if (v192 == nil) goto v201;
    v193 = elt(env, 7); /* times */
    v192 = stack[-5];
    v192 = cons(v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    goto v202;

v202:
    v192 = list2(stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    fn = elt(env, 11); /* cerror */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    goto v199;

v199:
    v192 = stack[-6];
    v192 = qcar(v192);
    stack[-6] = v192;
    v192 = stack[-2];
    v192 = qcar(v192);
    stack[-2] = v192;
    v192 = stack[-6];
    v193 = qcdr(v192);
    v192 = stack[-3];
    v192 = qcdr(v192);
    v192 = qcar(v192);
    v192 = Lrplaca(nil, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = stack[-2];
    v193 = qcdr(v192);
    v192 = stack[-4];
    v192 = qcdr(v192);
    v192 = qcar(v192);
    v192 = Lrplaca(nil, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = stack[-5];
    stack[0] = qcar(v192);
    v192 = stack[-5];
    v192 = qcdr(v192);
    fn = elt(env, 12); /* mkcopy */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = cons(stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    stack[-1] = v192;
    v192 = stack[-1];
    v192 = qcdr(v192);
    stack[0] = v192;
    v193 = stack[-6];
    v192 = stack[0];
    v192 = Lmember(nil, v193, v192);
    v192 = qcar(v192);
    stack[-6] = v192;
    v193 = stack[-2];
    v192 = stack[0];
    v192 = Lmember(nil, v193, v192);
    v192 = qcar(v192);
    stack[-2] = v192;
    v192 = stack[-6];
    v193 = qcdr(v192);
    v192 = stack[-4];
    v192 = qcdr(v192);
    v192 = qcar(v192);
    v192 = Lrplaca(nil, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = stack[-2];
    v193 = qcdr(v192);
    v192 = stack[-3];
    v192 = qcdr(v192);
    v192 = qcar(v192);
    v192 = Lrplaca(nil, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    stack[-2] = stack[-5];
    v193 = (Lisp_Object)-15; /* -1 */
    v192 = (Lisp_Object)17; /* 1 */
    v193 = cons(v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = qvalue(elt(env, 4)); /* su_order */
    fn = elt(env, 13); /* quotsq */
    v193 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = stack[-1];
    v192 = qcar(v192);
    fn = elt(env, 9); /* multsq */
    v193 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    v192 = stack[0];
    {
        Lisp_Object v203 = stack[-2];
        popv(8);
        return list2star(v203, v193, v192);
    }

v201:
    v192 = stack[-5];
    v192 = qcar(v192);
    goto v202;

v200:
    v192 = qvalue(elt(env, 5)); /* nil */
    goto v202;

v197:
    v192 = stack[-2];
    if (v192 == nil) goto v204;
    v192 = stack[-2];
    v192 = qcar(v192);
    v193 = qcdr(v192);
    v192 = stack[-4];
    v192 = qcdr(v192);
    v192 = qcar(v192);
    v192 = Lrplaca(nil, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    goto v205;

v205:
    v193 = qvalue(elt(env, 1)); /* n!*!*2!-1 */
    v192 = qvalue(elt(env, 4)); /* su_order */
    fn = elt(env, 13); /* quotsq */
    v193 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = stack[-5];
    v192 = qcar(v192);
    fn = elt(env, 9); /* multsq */
    v193 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = stack[-5];
    v192 = qcdr(v192);
    v192 = cons(v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    popv(8);
    return ncons(v192);

v204:
    v195 = elt(env, 2); /* "Free edge" */
    v192 = stack[-3];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v194 = qcar(v192);
    v193 = elt(env, 3); /* "in vertex" */
    v192 = stack[-3];
    v192 = list4(v195, v194, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    fn = elt(env, 11); /* cerror */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    goto v205;

v143:
    v192 = stack[-6];
    if (v192 == nil) goto v104;
    v192 = stack[-6];
    v192 = qcar(v192);
    v193 = qcdr(v192);
    v192 = stack[-3];
    v192 = qcdr(v192);
    v192 = qcar(v192);
    v192 = Lrplaca(nil, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    goto v206;

v206:
    v193 = qvalue(elt(env, 1)); /* n!*!*2!-1 */
    v192 = qvalue(elt(env, 4)); /* su_order */
    fn = elt(env, 13); /* quotsq */
    v193 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = stack[-5];
    v192 = qcar(v192);
    fn = elt(env, 9); /* multsq */
    v193 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    v192 = stack[-5];
    v192 = qcdr(v192);
    v192 = cons(v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    popv(8);
    return ncons(v192);

v104:
    v195 = elt(env, 2); /* "Free edge" */
    v192 = stack[-4];
    v192 = qcdr(v192);
    v192 = qcdr(v192);
    v194 = qcar(v192);
    v193 = elt(env, 3); /* "in vertex" */
    v192 = stack[-4];
    v192 = list4(v195, v194, v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    fn = elt(env, 11); /* cerror */
    v192 = (*qfn1(fn))(qenv(fn), v192);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-7];
    goto v206;
/* error exit handlers */
v196:
    popv(8);
    return nil;
}



/* Code for ibalp_litlp */

static Lisp_Object CC_ibalp_litlp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_litlp");
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

v65:
    v46 = stack[0];
    v46 = (v46 == nil ? lisp_true : nil);
    if (!(v46 == nil)) { popv(2); return onevalue(v46); }
    v46 = stack[0];
    v46 = qcar(v46);
    fn = elt(env, 2); /* ibalp_litp */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-1];
    if (v46 == nil) goto v25;
    v46 = stack[0];
    v46 = qcdr(v46);
    stack[0] = v46;
    goto v65;

v25:
    v46 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v46); }
/* error exit handlers */
v35:
    popv(2);
    return nil;
}



/* Code for omiir */

static Lisp_Object MS_CDECL CC_omiir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omiir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omiir");
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
    fn = elt(env, 2); /* lex */
    v25 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-1];
    v25 = qvalue(elt(env, 1)); /* char */
    v25 = Lcompress(nil, v25);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-1];
    stack[0] = v25;
    fn = elt(env, 2); /* lex */
    v25 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v38;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v38:
    popv(2);
    return nil;
}



/* Code for getcomb */

static Lisp_Object CC_getcomb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getcomb");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v59 = v31;
    stack[0] = v0;
/* end of prologue */
    v32 = v59;
    v59 = qvalue(elt(env, 1)); /* i */
    fn = elt(env, 4); /* nextcomb */
    v59 = (*qfn2(fn))(qenv(fn), v32, v59);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    qvalue(elt(env, 2)) = v59; /* comb */
    v59 = qvalue(elt(env, 2)); /* comb */
    v59 = qcar(v59);
    v32 = qvalue(elt(env, 2)); /* comb */
    v32 = qcdr(v32);
    qvalue(elt(env, 2)) = v32; /* comb */
    v32 = v59;
    if (v32 == nil) goto v191;
    stack[-1] = v59;
    v32 = stack[0];
    fn = elt(env, 5); /* setdiff */
    v59 = (*qfn2(fn))(qenv(fn), v32, v59);
    nil = C_nil;
    if (exception_pending()) goto v50;
    {
        Lisp_Object v144 = stack[-1];
        popv(3);
        return cons(v144, v59);
    }

v191:
    v59 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v59); }
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for dipilcomb1 */

static Lisp_Object MS_CDECL CC_dipilcomb1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v5, Lisp_Object v13,
                         Lisp_Object v41, Lisp_Object v54, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242, v243, v244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "dipilcomb1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipilcomb1");
#endif
    if (stack >= stacklimit)
    {
        push6(v54,v41,v13,v5,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v31,v5,v13,v41,v54);
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
    stack[-10] = v54;
    stack[-11] = v41;
    stack[-12] = v13;
    stack[-13] = v5;
    stack[-14] = v31;
    stack[-15] = v0;
/* end of prologue */
    v242 = qvalue(elt(env, 1)); /* !*gcd */
    stack[-1] = v242;
    stack[-16] = nil;
    stack[-9] = nil;
    stack[0] = qvalue(elt(env, 1)); /* !*gcd */
    qvalue(elt(env, 1)) = nil; /* !*gcd */
    v243 = stack[-14];
    v242 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    if (v242 == nil) goto v6;
    v243 = stack[-11];
    v242 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    if (v242 == nil) goto v6;
    v242 = stack[-1];
    goto v60;

v60:
    qvalue(elt(env, 1)) = v242; /* !*gcd */
    v242 = stack[-13];
    fn = elt(env, 5); /* evzero!? */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    v242 = (v242 == nil ? lisp_true : nil);
    stack[-7] = v242;
    v242 = stack[-10];
    fn = elt(env, 5); /* evzero!? */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    v242 = (v242 == nil ? lisp_true : nil);
    stack[-6] = v242;
    v242 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v242;
    stack[-5] = v242;
    v242 = qvalue(elt(env, 3)); /* nil */
    stack[-8] = v242;
    stack[-2] = v242;
    stack[-3] = v242;
    goto v52;

v52:
    v242 = stack[-5];
    if (v242 == nil) goto v123;
    v242 = stack[-15];
    if (v242 == nil) goto v246;
    v242 = stack[-15];
    v242 = qcar(v242);
    stack[-16] = v242;
    v242 = stack[-7];
    if (v242 == nil) goto v17;
    v243 = stack[-16];
    v242 = stack[-13];
    fn = elt(env, 6); /* evsum */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    stack[-16] = v242;
    goto v17;

v17:
    v242 = qvalue(elt(env, 3)); /* nil */
    stack[-5] = v242;
    goto v123;

v123:
    v242 = stack[-4];
    if (v242 == nil) goto v247;
    v242 = stack[-12];
    if (v242 == nil) goto v248;
    v242 = stack[-12];
    v242 = qcar(v242);
    stack[-9] = v242;
    v242 = stack[-6];
    if (v242 == nil) goto v249;
    v243 = stack[-9];
    v242 = stack[-10];
    fn = elt(env, 6); /* evsum */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    stack[-9] = v242;
    goto v249;

v249:
    v242 = qvalue(elt(env, 3)); /* nil */
    stack[-4] = v242;
    goto v247;

v247:
    v243 = stack[-16];
    v242 = stack[-9];
    fn = elt(env, 7); /* evcomp */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    v244 = v242;
    v243 = v244;
    v242 = (Lisp_Object)17; /* 1 */
    if (v243 == v242) goto v250;
    v243 = v244;
    v242 = (Lisp_Object)-15; /* -1 */
    if (v243 == v242) goto v251;
    v242 = qvalue(elt(env, 1)); /* !*gcd */
    if (v242 == nil) goto v252;
    v242 = stack[-15];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    if (v242 == nil) goto v167;
    v242 = stack[-12];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    if (!(v242 == nil)) goto v252;

v167:
    v242 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v242; /* !*gcd */
    goto v252;

v252:
    v242 = stack[-15];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = stack[-14];
    fn = elt(env, 8); /* bcprod */
    stack[-1] = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    v242 = stack[-12];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = stack[-11];
    fn = elt(env, 8); /* bcprod */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    fn = elt(env, 9); /* bcsum */
    v242 = (*qfn2(fn))(qenv(fn), stack[-1], v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    stack[-1] = v242;
    v242 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    if (!(v242 == nil)) goto v253;
    v244 = stack[-16];
    v243 = stack[-1];
    v242 = qvalue(elt(env, 3)); /* nil */
    v242 = list2star(v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    v242 = Lnconc(nil, stack[-2], v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    stack[-3] = v242;
    v242 = stack[-3];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    stack[-2] = v242;
    goto v253;

v253:
    v242 = stack[-15];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    stack[-15] = v242;
    v242 = stack[-12];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    stack[-12] = v242;
    v242 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v242;
    stack[-5] = v242;
    goto v254;

v254:
    v242 = stack[-8];
    if (!(v242 == nil)) goto v52;
    v242 = stack[-3];
    stack[-2] = v242;
    stack[-8] = v242;
    goto v52;

v251:
    v242 = qvalue(elt(env, 1)); /* !*gcd */
    if (v242 == nil) goto v255;
    v242 = stack[-12];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    if (!(v242 == nil)) goto v255;
    v242 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v242; /* !*gcd */
    goto v255;

v255:
    v242 = stack[-12];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = stack[-11];
    fn = elt(env, 8); /* bcprod */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    stack[-1] = v242;
    v242 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    if (!(v242 == nil)) goto v256;
    v244 = stack[-9];
    v243 = stack[-1];
    v242 = qvalue(elt(env, 3)); /* nil */
    v242 = list2star(v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    v242 = Lnconc(nil, stack[-2], v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    stack[-3] = v242;
    v242 = stack[-3];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    stack[-2] = v242;
    goto v256;

v256:
    v242 = stack[-12];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    stack[-12] = v242;
    v242 = qvalue(elt(env, 2)); /* t */
    stack[-4] = v242;
    goto v254;

v250:
    v242 = qvalue(elt(env, 1)); /* !*gcd */
    if (v242 == nil) goto v178;
    v242 = stack[-15];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    if (!(v242 == nil)) goto v178;
    v242 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v242; /* !*gcd */
    goto v178;

v178:
    v242 = stack[-15];
    v242 = qcdr(v242);
    v243 = qcar(v242);
    v242 = stack[-14];
    fn = elt(env, 8); /* bcprod */
    v242 = (*qfn2(fn))(qenv(fn), v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    stack[-1] = v242;
    v242 = stack[-1];
    fn = elt(env, 10); /* bczero!? */
    v242 = (*qfn1(fn))(qenv(fn), v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    if (!(v242 == nil)) goto v257;
    v244 = stack[-16];
    v243 = stack[-1];
    v242 = qvalue(elt(env, 3)); /* nil */
    v242 = list2star(v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    v242 = Lnconc(nil, stack[-2], v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    stack[-3] = v242;
    v242 = stack[-3];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    stack[-2] = v242;
    goto v257;

v257:
    v242 = stack[-15];
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    stack[-15] = v242;
    v242 = qvalue(elt(env, 2)); /* t */
    stack[-5] = v242;
    goto v254;

v248:
    stack[-1] = stack[-8];
    stack[-2] = stack[-15];
    v244 = stack[-13];
    v243 = stack[-14];
    v242 = qvalue(elt(env, 3)); /* nil */
    v242 = list2star(v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    fn = elt(env, 11); /* dipprod */
    v242 = (*qfn2(fn))(qenv(fn), stack[-2], v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    v242 = Lnconc(nil, stack[-1], v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    goto v51;

v51:
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    { popv(18); return onevalue(v242); }

v246:
    v242 = stack[-12];
    if (v242 == nil) goto v92;
    stack[-1] = stack[-8];
    stack[-2] = stack[-12];
    v244 = stack[-10];
    v243 = stack[-11];
    v242 = qvalue(elt(env, 3)); /* nil */
    v242 = list2star(v244, v243, v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    fn = elt(env, 11); /* dipprod */
    v242 = (*qfn2(fn))(qenv(fn), stack[-2], v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    v242 = Lnconc(nil, stack[-1], v242);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-17];
    goto v51;

v92:
    v242 = stack[-8];
    goto v51;

v6:
    v242 = nil;
    goto v60;
/* error exit handlers */
v245:
    env = stack[-17];
    qvalue(elt(env, 1)) = stack[0]; /* !*gcd */
    popv(18);
    return nil;
}



/* Code for !*kp2f */

static Lisp_Object CC_Hkp2f(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *kp2f");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v60 = stack[0];
    v63 = (Lisp_Object)1; /* 0 */
    v63 = (Lisp_Object)greaterp2(v60, v63);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v63 = v63 ? lisp_true : nil;
    env = stack[-2];
    if (v63 == nil) goto v139;
    v60 = stack[-1];
    v63 = stack[0];
    fn = elt(env, 1); /* mksq */
    v63 = (*qfn2(fn))(qenv(fn), v60, v63);
    nil = C_nil;
    if (exception_pending()) goto v34;
    v63 = qcar(v63);
    { popv(3); return onevalue(v63); }

v139:
    v63 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v63); }
/* error exit handlers */
v34:
    popv(3);
    return nil;
}



/* Code for dp_neg */

static Lisp_Object CC_dp_neg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_neg");
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
    v258 = v0;
/* end of prologue */
    stack[-4] = v258;
    v258 = stack[-4];
    if (v258 == nil) goto v38;
    v258 = stack[-4];
    v258 = qcar(v258);
    v135 = v258;
    v258 = v135;
    stack[0] = qcar(v258);
    v258 = v135;
    v258 = qcdr(v258);
    fn = elt(env, 2); /* bc_neg */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v258 = cons(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    stack[-2] = v258;
    stack[-3] = v258;
    goto v57;

v57:
    v258 = stack[-4];
    v258 = qcdr(v258);
    stack[-4] = v258;
    v258 = stack[-4];
    if (v258 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v258 = stack[-4];
    v258 = qcar(v258);
    v135 = v258;
    v258 = v135;
    stack[0] = qcar(v258);
    v258 = v135;
    v258 = qcdr(v258);
    fn = elt(env, 2); /* bc_neg */
    v258 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v258 = cons(stack[0], v258);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v258 = ncons(v258);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v258 = Lrplacd(nil, stack[-1], v258);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v258 = stack[-2];
    v258 = qcdr(v258);
    stack[-2] = v258;
    goto v57;

v38:
    v258 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v258); }
/* error exit handlers */
v87:
    popv(6);
    return nil;
}



/* Code for pdif */

static Lisp_Object CC_pdif(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdif");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v45 = v31;
    v69 = v0;
/* end of prologue */
    stack[0] = v69;
    fn = elt(env, 1); /* pneg */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-1];
    {
        Lisp_Object v62 = stack[0];
        popv(2);
        fn = elt(env, 2); /* psum */
        return (*qfn2(fn))(qenv(fn), v62, v45);
    }
/* error exit handlers */
v211:
    popv(2);
    return nil;
}



/* Code for gperm3 */

static Lisp_Object CC_gperm3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v34, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm3");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v34 = v31;
    v6 = v0;
/* end of prologue */

v22:
    v26 = v6;
    if (v26 == nil) { popv(2); return onevalue(v34); }
    v26 = v6;
    v26 = qcdr(v26);
    stack[0] = v26;
    v26 = v34;
    v34 = qcar(v6);
    v6 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* gperm2 */
    v6 = (*qfnn(fn))(qenv(fn), 3, v26, v34, v6);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    v34 = v6;
    v6 = stack[0];
    goto v22;
/* error exit handlers */
v145:
    popv(2);
    return nil;
}



/* Code for dcombine */

static Lisp_Object MS_CDECL CC_dcombine(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v299, v300, v301, v302, v303;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dcombine");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dcombine");
#endif
    if (stack >= stacklimit)
    {
        push3(v5,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v5;
    stack[-2] = v31;
    stack[-3] = v0;
/* end of prologue */
    v299 = stack[-3];
    if (!consp(v299)) goto v47;
    v299 = stack[-2];
    if (!consp(v299)) goto v132;
    v299 = stack[-3];
    v300 = qcar(v299);
    v299 = stack[-2];
    v299 = qcar(v299);
    if (v300 == v299) goto v68;
    v299 = stack[-3];
    v300 = qcar(v299);
    v299 = stack[-2];
    v299 = qcar(v299);
    stack[-4] = v300;
    stack[0] = v299;
    v300 = stack[-4];
    v299 = stack[0];
    v301 = get(v300, v299);
    env = stack[-5];
    v300 = elt(env, 2); /* (!:crn!: !:gi!:) */
    v299 = elt(env, 3); /* (!:rd!: !:cr!:) */
    v303 = v301;
    v302 = v300;
    v301 = v299;
    v299 = v303;
    if (v299 == nil) goto v304;
    v299 = v303;
    if (!(!consp(v299))) goto v304;
    v300 = stack[-4];
    v299 = elt(env, 4); /* cmpxfn */
    v299 = get(v300, v299);
    env = stack[-5];
    if (v299 == nil) goto v305;
    v300 = stack[0];
    v299 = elt(env, 4); /* cmpxfn */
    v299 = get(v300, v299);
    env = stack[-5];
    if (!(v299 == nil)) goto v305;

v306:
    v300 = stack[0];
    v299 = elt(env, 5); /* !:ps!: */
    if (!(v300 == v299)) goto v304;

v307:
    v300 = v303;
    v299 = stack[-3];
    v299 = Lapply1(nil, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    stack[-3] = v299;
    v300 = stack[0];
    v299 = stack[-1];
    v299 = get(v300, v299);
    env = stack[-5];
    v303 = v299;
    goto v162;

v162:
    v301 = v303;
    v300 = stack[-3];
    v299 = stack[-2];
    v299 = Lapply2(nil, 3, v301, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    goto v54;

v54:
    stack[-3] = v299;
    v299 = qvalue(elt(env, 12)); /* !*rounded */
    if (v299 == nil) goto v309;
    v299 = qvalue(elt(env, 13)); /* !*roundall */
    if (v299 == nil) goto v309;
    v299 = stack[-3];
    if (!consp(v299)) goto v309;
    v299 = stack[-3];
    v300 = qcar(v299);
    stack[-2] = v300;
    v299 = elt(env, 9); /* !:rn!: */
    if (!(v300 == v299)) goto v310;
    v299 = stack[-3];
    v299 = qcdr(v299);
    v300 = qcdr(v299);
    v299 = (Lisp_Object)17; /* 1 */
    if (v300 == v299) goto v310;
    v299 = stack[-3];
    fn = elt(env, 15); /* !*rn2rd */
    v299 = (*qfn1(fn))(qenv(fn), v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    goto v311;

v311:
    {
        popv(6);
        fn = elt(env, 16); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v299);
    }

v310:
    v300 = stack[-2];
    v299 = elt(env, 11); /* !:crn!: */
    if (!(v300 == v299)) goto v312;
    v299 = stack[-3];
    v299 = qcdr(v299);
    v299 = qcar(v299);
    v300 = qcdr(v299);
    v299 = (Lisp_Object)17; /* 1 */
    if (!(v300 == v299)) goto v153;
    v299 = stack[-3];
    v299 = qcdr(v299);
    v299 = qcdr(v299);
    v300 = qcdr(v299);
    v299 = (Lisp_Object)17; /* 1 */
    if (!(v300 == v299)) goto v153;

v312:
    v299 = stack[-3];
    goto v311;

v153:
    v299 = stack[-3];
    fn = elt(env, 17); /* !*crn2cr */
    v299 = (*qfn1(fn))(qenv(fn), v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    goto v311;

v309:
    v300 = stack[-1];
    v299 = elt(env, 14); /* divide */
    if (v300 == v299) goto v313;
    v299 = stack[-3];
    {
        popv(6);
        fn = elt(env, 16); /* int!-equiv!-chk */
        return (*qfn1(fn))(qenv(fn), v299);
    }

v313:
    v299 = stack[-3];
    v299 = qcar(v299);
    fn = elt(env, 16); /* int!-equiv!-chk */
    stack[0] = (*qfn1(fn))(qenv(fn), v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    v299 = stack[-3];
    v299 = qcdr(v299);
    fn = elt(env, 16); /* int!-equiv!-chk */
    v299 = (*qfn1(fn))(qenv(fn), v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    {
        Lisp_Object v314 = stack[0];
        popv(6);
        return cons(v314, v299);
    }

v304:
    v300 = stack[0];
    v299 = elt(env, 6); /* noconvert */
    v299 = Lflagp(nil, v300, v299);
    env = stack[-5];
    if (!(v299 == nil)) goto v307;
    v300 = stack[-4];
    v299 = v302;
    v299 = Lmemq(nil, v300, v299);
    if (v299 == nil) goto v315;
    v300 = stack[0];
    v299 = elt(env, 7); /* !:rd!: */
    if (!(v300 == v299)) goto v315;

v316:
    v300 = stack[-4];
    v299 = elt(env, 8); /* !:cr!: */
    v300 = get(v300, v299);
    env = stack[-5];
    v299 = stack[-3];
    v299 = Lapply1(nil, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    stack[-3] = v299;
    v299 = elt(env, 8); /* !:cr!: */
    stack[-4] = v299;
    goto v317;

v317:
    v300 = stack[0];
    v299 = stack[-4];
    v300 = get(v300, v299);
    env = stack[-5];
    v299 = stack[-2];
    v299 = Lapply1(nil, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    stack[-2] = v299;
    v300 = stack[-4];
    v299 = stack[-1];
    v299 = get(v300, v299);
    env = stack[-5];
    v303 = v299;
    goto v162;

v315:
    v300 = stack[-4];
    v299 = elt(env, 7); /* !:rd!: */
    if (!(v300 == v299)) goto v318;
    v299 = stack[0];
    v300 = v302;
    v299 = Lmemq(nil, v299, v300);
    if (!(v299 == nil)) goto v316;

v318:
    v300 = stack[-4];
    v299 = elt(env, 9); /* !:rn!: */
    if (!(v300 == v299)) goto v255;
    v300 = stack[0];
    v299 = elt(env, 10); /* !:gi!: */
    if (!(v300 == v299)) goto v255;

v220:
    v300 = stack[-4];
    v299 = elt(env, 11); /* !:crn!: */
    v300 = get(v300, v299);
    env = stack[-5];
    v299 = stack[-3];
    v299 = Lapply1(nil, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    stack[-3] = v299;
    v299 = elt(env, 11); /* !:crn!: */
    stack[-4] = v299;
    goto v317;

v255:
    v300 = stack[-4];
    v299 = elt(env, 10); /* !:gi!: */
    if (!(v300 == v299)) goto v317;
    v300 = stack[0];
    v299 = elt(env, 9); /* !:rn!: */
    if (v300 == v299) goto v220;
    else goto v317;

v305:
    v300 = stack[-4];
    v299 = v301;
    v299 = Lmemq(nil, v300, v299);
    if (v299 == nil) goto v307;
    v299 = stack[0];
    v300 = v301;
    v299 = Lmemq(nil, v299, v300);
    if (v299 == nil) goto v306;
    else goto v307;

v68:
    v299 = stack[-3];
    v300 = qcar(v299);
    v299 = stack[-1];
    v301 = get(v300, v299);
    env = stack[-5];
    v300 = stack[-3];
    v299 = stack[-2];
    v299 = Lapply2(nil, 3, v301, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    goto v54;

v132:
    v299 = stack[-3];
    v300 = qcar(v299);
    v299 = stack[-1];
    stack[-4] = get(v300, v299);
    env = stack[-5];
    stack[0] = stack[-3];
    v299 = stack[-3];
    v300 = qcar(v299);
    v299 = elt(env, 1); /* i2d */
    v300 = get(v300, v299);
    env = stack[-5];
    v299 = stack[-2];
    v299 = Lapply1(nil, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    v299 = Lapply2(nil, 3, stack[-4], stack[0], v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    goto v54;

v47:
    v299 = stack[-2];
    v300 = qcar(v299);
    v299 = stack[-1];
    stack[0] = get(v300, v299);
    env = stack[-5];
    v299 = stack[-2];
    v300 = qcar(v299);
    v299 = elt(env, 1); /* i2d */
    v300 = get(v300, v299);
    env = stack[-5];
    v299 = stack[-3];
    v300 = Lapply1(nil, v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    v299 = stack[-2];
    v299 = Lapply2(nil, 3, stack[0], v300, v299);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[-5];
    goto v54;
/* error exit handlers */
v308:
    popv(6);
    return nil;
}



/* Code for freeofl */

static Lisp_Object CC_freeofl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeofl");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */

v65:
    v44 = stack[0];
    v44 = (v44 == nil ? lisp_true : nil);
    if (!(v44 == nil)) { popv(3); return onevalue(v44); }
    v145 = stack[-1];
    v44 = stack[0];
    v44 = qcar(v44);
    fn = elt(env, 2); /* freeof */
    v44 = (*qfn2(fn))(qenv(fn), v145, v44);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-2];
    if (v44 == nil) goto v37;
    v145 = stack[-1];
    v44 = stack[0];
    v44 = qcdr(v44);
    stack[-1] = v145;
    stack[0] = v44;
    goto v65;

v37:
    v44 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v44); }
/* error exit handlers */
v40:
    popv(3);
    return nil;
}



/* Code for exchk1 */

static Lisp_Object MS_CDECL CC_exchk1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v5, Lisp_Object v13, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v205, v316, v328;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "exchk1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exchk1");
#endif
    if (stack >= stacklimit)
    {
        push4(v13,v5,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v31,v5,v13);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v13;
    stack[-2] = v5;
    stack[-3] = v31;
    stack[-4] = v0;
/* end of prologue */

v56:
    v173 = stack[-4];
    if (v173 == nil) goto v42;
    v173 = stack[-4];
    v173 = qcar(v173);
    v205 = qcar(v173);
    v173 = elt(env, 1); /* expt */
    if (!consp(v205)) goto v93;
    v205 = qcar(v205);
    if (!(v205 == v173)) goto v93;
    v316 = elt(env, 2); /* times */
    v173 = stack[-4];
    v173 = qcar(v173);
    v205 = qcdr(v173);
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcdr(v173);
    v173 = qcdr(v173);
    v173 = qcar(v173);
    v173 = list3(v316, v205, v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    fn = elt(env, 3); /* simpexpon */
    v173 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    stack[-5] = v173;
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcdr(v173);
    v173 = qcar(v173);
    if (is_number(v173)) goto v330;
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcdr(v173);
    v205 = qcar(v173);
    v173 = stack[-2];
    v173 = Lassoc(nil, v205, v173);
    v205 = v173;
    if (v205 == nil) goto v184;
    stack[0] = v173;
    v205 = stack[-5];
    v173 = qcdr(v173);
    fn = elt(env, 4); /* addsq */
    v173 = (*qfn2(fn))(qenv(fn), v205, v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    v173 = Lrplacd(nil, stack[0], v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    goto v180;

v180:
    v173 = stack[-4];
    v328 = qcdr(v173);
    v316 = stack[-3];
    v205 = stack[-2];
    v173 = stack[-1];
    stack[-4] = v328;
    stack[-3] = v316;
    stack[-2] = v205;
    stack[-1] = v173;
    goto v56;

v184:
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcdr(v173);
    v316 = qcar(v173);
    v205 = stack[-5];
    v173 = stack[-2];
    v173 = acons(v316, v205, v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    stack[-2] = v173;
    goto v180;

v330:
    v205 = stack[-5];
    v173 = stack[-1];
    fn = elt(env, 5); /* assoc2 */
    v173 = (*qfn2(fn))(qenv(fn), v205, v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    v205 = v173;
    if (v205 == nil) goto v296;
    stack[0] = v173;
    v205 = qcar(v173);
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcdr(v173);
    v173 = qcar(v173);
    v173 = times2(v205, v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    v173 = Lrplaca(nil, stack[0], v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    goto v180;

v296:
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    v173 = qcdr(v173);
    v316 = qcar(v173);
    v205 = stack[-5];
    v173 = stack[-1];
    v173 = acons(v316, v205, v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    stack[-1] = v173;
    goto v180;

v93:
    v173 = stack[-4];
    v173 = qcar(v173);
    v205 = qcdr(v173);
    v173 = (Lisp_Object)17; /* 1 */
    if (v205 == v173) goto v24;
    v173 = stack[-4];
    v173 = qcdr(v173);
    stack[-5] = v173;
    stack[0] = elt(env, 1); /* expt */
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    fn = elt(env, 6); /* sqchk */
    v205 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcdr(v173);
    v205 = list3(stack[0], v205, v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    v173 = stack[-3];
    v173 = cons(v205, v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    stack[-3] = v173;
    v173 = stack[-5];
    stack[-4] = v173;
    goto v56;

v24:
    v173 = stack[-4];
    v173 = qcdr(v173);
    stack[-5] = v173;
    v173 = stack[-4];
    v173 = qcar(v173);
    v173 = qcar(v173);
    fn = elt(env, 6); /* sqchk */
    v205 = (*qfn1(fn))(qenv(fn), v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    v173 = stack[-3];
    v173 = cons(v205, v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    stack[-3] = v173;
    v173 = stack[-5];
    stack[-4] = v173;
    goto v56;

v42:
    v205 = stack[-1];
    v173 = stack[-2];
    v205 = Lappend(nil, v205, v173);
    nil = C_nil;
    if (exception_pending()) goto v329;
    env = stack[-6];
    v173 = stack[-3];
    {
        popv(7);
        fn = elt(env, 7); /* exchk2 */
        return (*qfn2(fn))(qenv(fn), v205, v173);
    }
/* error exit handlers */
v329:
    popv(7);
    return nil;
}



/* Code for ibalp_litp */

static Lisp_Object CC_ibalp_litp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_litp");
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
    v145 = stack[0];
    fn = elt(env, 3); /* ibalp_atomp */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-1];
    if (!(v145 == nil)) { popv(2); return onevalue(v145); }
    v145 = stack[0];
    if (!consp(v145)) goto v47;
    v145 = stack[0];
    v145 = qcar(v145);
    v73 = v145;
    goto v69;

v69:
    v145 = elt(env, 1); /* not */
    if (v73 == v145) goto v60;
    v145 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v145); }

v60:
    v145 = stack[0];
    v145 = qcdr(v145);
    v145 = qcar(v145);
    {
        popv(2);
        fn = elt(env, 3); /* ibalp_atomp */
        return (*qfn1(fn))(qenv(fn), v145);
    }

v47:
    v145 = stack[0];
    v73 = v145;
    goto v69;
/* error exit handlers */
v40:
    popv(2);
    return nil;
}



/* Code for setdmode1 */

static Lisp_Object CC_setdmode1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v304, v93, v335;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setdmode1");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v304 = v31;
    stack[-5] = v0;
/* end of prologue */
    v93 = stack[-5];
    v24 = elt(env, 1); /* tag */
    v24 = get(v93, v24);
    env = stack[-7];
    stack[-6] = v24;
    v24 = qvalue(elt(env, 2)); /* dmode!* */
    stack[-4] = v24;
    v24 = v304;
    if (v24 == nil) goto v48;
    v304 = stack[-5];
    v24 = elt(env, 6); /* (rounded complex!-rounded) */
    v24 = Lmemq(nil, v304, v24);
    if (v24 == nil) goto v126;
    fn = elt(env, 13); /* !!mfefix */
    v24 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    goto v126;

v126:
    v304 = stack[-6];
    v24 = stack[-4];
    if (v304 == v24) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v304 = stack[-6];
    v24 = elt(env, 7); /* realtype */
    v24 = get(v304, v24);
    env = stack[-7];
    stack[-3] = v24;
    if (!(v24 == nil)) goto v14;
    v24 = stack[-6];
    stack[-3] = v24;
    goto v14;

v14:
    v24 = qvalue(elt(env, 8)); /* domainlist!* */
    stack[-2] = v24;
    goto v68;

v68:
    v24 = stack[-2];
    if (v24 == nil) goto v239;
    v24 = stack[-2];
    v24 = qcar(v24);
    stack[-1] = v24;
    v304 = stack[-1];
    v24 = elt(env, 9); /* !:gi!: */
    if (v304 == v24) goto v131;
    v304 = stack[-1];
    v24 = stack[-3];
    if (v304 == v24) goto v131;
    v24 = elt(env, 10); /* !* */
    stack[0] = Lexplode(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v304 = stack[-1];
    v24 = elt(env, 4); /* dname */
    v24 = get(v304, v24);
    env = stack[-7];
    v24 = Lexplode(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v24 = Lappend(nil, stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v24 = Lcompress(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v304 = Lintern(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v24 = qvalue(elt(env, 3)); /* nil */
    v24 = Lset(nil, v304, v24);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    goto v131;

v131:
    v24 = stack[-2];
    v24 = qcdr(v24);
    stack[-2] = v24;
    goto v68;

v239:
    fn = elt(env, 14); /* rmsubs */
    v24 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v304 = stack[-4];
    v24 = elt(env, 4); /* dname */
    v24 = get(v304, v24);
    env = stack[-7];
    stack[-4] = v24;
    v24 = stack[-4];
    if (v24 == nil) goto v247;
    v335 = elt(env, 11); /* "Domain mode" */
    v93 = stack[-4];
    v304 = elt(env, 12); /* "changed to" */
    v24 = stack[-5];
    v24 = list4(v335, v93, v304, v24);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    fn = elt(env, 15); /* lprim */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    goto v247;

v247:
    v24 = stack[-6];
    qvalue(elt(env, 2)) = v24; /* dmode!* */
    qvalue(elt(env, 5)) = v24; /* gdmode!* */
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v48:
    v24 = stack[-4];
    if (v24 == nil) goto v139;
    v93 = stack[-5];
    v304 = stack[-4];
    v24 = elt(env, 4); /* dname */
    v24 = get(v304, v24);
    env = stack[-7];
    stack[-4] = v24;
    if (v93 == v24) goto v60;
    v304 = stack[-5];
    v24 = stack[-4];
    {
        popv(8);
        fn = elt(env, 16); /* offmoderr */
        return (*qfn2(fn))(qenv(fn), v304, v24);
    }

v60:
    fn = elt(env, 14); /* rmsubs */
    v24 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v24 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v24; /* dmode!* */
    qvalue(elt(env, 5)) = v24; /* gdmode!* */
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v139:
    v24 = qvalue(elt(env, 3)); /* nil */
    { popv(8); return onevalue(v24); }
/* error exit handlers */
v336:
    popv(8);
    return nil;
}



/* Code for wedgepf */

static Lisp_Object CC_wedgepf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wedgepf");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v69 = v31;
    v147 = v0;
/* end of prologue */
    stack[0] = v147;
    fn = elt(env, 1); /* !*pf2wedgepf */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    fn = elt(env, 2); /* wedgepf2 */
    v69 = (*qfn2(fn))(qenv(fn), stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* !*wedgepf2pf */
        return (*qfn1(fn))(qenv(fn), v69);
    }
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



/* Code for statep!* */

static Lisp_Object CC_statepH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for statep*");
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
    v38 = v0;
/* end of prologue */
    fn = elt(env, 2); /* getphystype */
    v38 = (*qfn1(fn))(qenv(fn), v38);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[0];
    v45 = elt(env, 1); /* state */
    v38 = (v38 == v45 ? lisp_true : nil);
    { popv(1); return onevalue(v38); }
/* error exit handlers */
v69:
    popv(1);
    return nil;
}



/* Code for map__edges */

static Lisp_Object CC_map__edges(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for map__edges");
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
    goto v22;

v22:
    v33 = stack[0];
    if (v33 == nil) goto v57;
    v33 = stack[0];
    v43 = qcar(v33);
    v33 = stack[-1];
    v33 = cons(v43, v33);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    stack[-1] = v33;
    v33 = stack[0];
    v33 = qcdr(v33);
    stack[0] = v33;
    goto v22;

v57:
    v33 = qvalue(elt(env, 1)); /* nil */
    v43 = v33;
    goto v56;

v56:
    v33 = stack[-1];
    if (v33 == nil) { popv(3); return onevalue(v43); }
    v33 = stack[-1];
    v33 = qcar(v33);
    fn = elt(env, 2); /* union_edges */
    v33 = (*qfn2(fn))(qenv(fn), v33, v43);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-2];
    v43 = v33;
    v33 = stack[-1];
    v33 = qcdr(v33);
    stack[-1] = v33;
    goto v56;
/* error exit handlers */
v241:
    popv(3);
    return nil;
}



/* Code for simptimes */

static Lisp_Object CC_simptimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v297;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simptimes");
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
    stack[-2] = nil;
    v119 = stack[-1];
    if (v119 == nil) goto v62;
    v297 = qvalue(elt(env, 1)); /* tstack!* */
    v119 = (Lisp_Object)1; /* 0 */
    if (!(v297 == v119)) goto v22;
    v119 = qvalue(elt(env, 2)); /* mul!* */
    if (v119 == nil) goto v22;
    v119 = qvalue(elt(env, 2)); /* mul!* */
    stack[-2] = v119;
    v119 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v119; /* mul!* */
    goto v22;

v22:
    v119 = qvalue(elt(env, 1)); /* tstack!* */
    v119 = add1(v119);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    qvalue(elt(env, 1)) = v119; /* tstack!* */
    v119 = stack[-1];
    fn = elt(env, 5); /* simpcar */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    stack[0] = v119;
    goto v57;

v57:
    v119 = stack[-1];
    v119 = qcdr(v119);
    stack[-1] = v119;
    v119 = stack[0];
    v119 = qcar(v119);
    if (v119 == nil) goto v25;
    v119 = stack[-1];
    if (v119 == nil) goto v56;
    v119 = stack[-1];
    fn = elt(env, 5); /* simpcar */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    fn = elt(env, 6); /* multsq */
    v119 = (*qfn2(fn))(qenv(fn), stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    stack[0] = v119;
    goto v57;

v56:
    v119 = qvalue(elt(env, 2)); /* mul!* */
    if (v119 == nil) goto v25;
    v297 = qvalue(elt(env, 1)); /* tstack!* */
    v119 = (Lisp_Object)17; /* 1 */
    v119 = (Lisp_Object)greaterp2(v297, v119);
    nil = C_nil;
    if (exception_pending()) goto v142;
    v119 = v119 ? lisp_true : nil;
    env = stack[-3];
    if (!(v119 == nil)) goto v25;
    v119 = qvalue(elt(env, 2)); /* mul!* */
    v297 = qcar(v119);
    v119 = stack[0];
    v119 = Lapply1(nil, v297, v119);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    stack[0] = v119;
    v119 = qvalue(elt(env, 3)); /* nil */
    v119 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    qvalue(elt(env, 4)) = v119; /* alglist!* */
    v119 = qvalue(elt(env, 2)); /* mul!* */
    v119 = qcdr(v119);
    qvalue(elt(env, 2)) = v119; /* mul!* */
    goto v56;

v25:
    v119 = qvalue(elt(env, 1)); /* tstack!* */
    v119 = sub1(v119);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-3];
    qvalue(elt(env, 1)) = v119; /* tstack!* */
    v297 = qvalue(elt(env, 1)); /* tstack!* */
    v119 = (Lisp_Object)1; /* 0 */
    if (!(v297 == v119)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v119 = stack[-2];
    qvalue(elt(env, 2)) = v119; /* mul!* */
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v62:
    v297 = (Lisp_Object)17; /* 1 */
    v119 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v297, v119);
/* error exit handlers */
v142:
    popv(4);
    return nil;
}



/* Code for bc_zero!? */

static Lisp_Object CC_bc_zeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v145, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_zero?");
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
    v145 = v0;
/* end of prologue */
    v44 = v145;
    if (v44 == nil) goto v41;
    v73 = v145;
    v44 = (Lisp_Object)1; /* 0 */
    if (v73 == v44) goto v41;
    v44 = qvalue(elt(env, 2)); /* !*hardzerotest */
    if (v44 == nil) goto v6;
    v44 = v145;
    v44 = Lconsp(nil, v44);
    env = stack[0];
    if (v44 == nil) goto v6;
    v44 = v145;
    fn = elt(env, 4); /* prepf */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[0];
    fn = elt(env, 5); /* simp */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v124;
    env = stack[0];
    v44 = qcar(v44);
    fn = elt(env, 6); /* bc!=simp */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v124;
    v44 = (v44 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v44); }

v6:
    v44 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v44); }

v41:
    v44 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v44); }
/* error exit handlers */
v124:
    popv(1);
    return nil;
}



/* Code for general!-times!-mod!-p */

static Lisp_Object CC_generalKtimesKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v254;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-times-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v31;
    stack[-2] = v0;
/* end of prologue */
    v180 = stack[-2];
    if (v180 == nil) goto v54;
    v180 = stack[-1];
    if (v180 == nil) goto v54;
    v180 = stack[-2];
    if (!consp(v180)) goto v46;
    v180 = stack[-2];
    v180 = qcar(v180);
    if (!consp(v180)) goto v46;
    v180 = stack[-1];
    if (!consp(v180)) goto v73;
    v180 = stack[-1];
    v180 = qcar(v180);
    if (!consp(v180)) goto v73;
    v180 = stack[-2];
    v180 = qcar(v180);
    v180 = qcar(v180);
    v254 = qcar(v180);
    v180 = stack[-1];
    v180 = qcar(v180);
    v180 = qcar(v180);
    v180 = qcar(v180);
    if (equal(v254, v180)) goto v92;
    v180 = stack[-2];
    v180 = qcar(v180);
    v180 = qcar(v180);
    v254 = qcar(v180);
    v180 = stack[-1];
    v180 = qcar(v180);
    v180 = qcar(v180);
    v180 = qcar(v180);
    fn = elt(env, 2); /* ordop */
    v180 = (*qfn2(fn))(qenv(fn), v254, v180);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-4];
    if (v180 == nil) goto v333;
    v180 = stack[-2];
    v180 = qcar(v180);
    stack[-3] = qcar(v180);
    v180 = stack[-2];
    v180 = qcar(v180);
    v254 = qcdr(v180);
    v180 = stack[-1];
    stack[0] = CC_generalKtimesKmodKp(env, v254, v180);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-4];
    v180 = stack[-2];
    v254 = qcdr(v180);
    v180 = stack[-1];
    v180 = CC_generalKtimesKmodKp(env, v254, v180);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-4];
    {
        Lisp_Object v339 = stack[-3];
        Lisp_Object v331 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v339, v331, v180);
    }

v333:
    v180 = stack[-1];
    v180 = qcar(v180);
    stack[-3] = qcar(v180);
    v254 = stack[-2];
    v180 = stack[-1];
    v180 = qcar(v180);
    v180 = qcdr(v180);
    stack[0] = CC_generalKtimesKmodKp(env, v254, v180);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-4];
    v254 = stack[-2];
    v180 = stack[-1];
    v180 = qcdr(v180);
    v180 = CC_generalKtimesKmodKp(env, v254, v180);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-4];
    {
        Lisp_Object v4 = stack[-3];
        Lisp_Object v228 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v4, v228, v180);
    }

v92:
    v180 = stack[-2];
    v254 = qcar(v180);
    v180 = stack[-1];
    fn = elt(env, 4); /* general!-times!-term!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v254, v180);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-4];
    v180 = stack[-1];
    v254 = qcar(v180);
    v180 = stack[-2];
    v180 = qcdr(v180);
    fn = elt(env, 4); /* general!-times!-term!-mod!-p */
    v180 = (*qfn2(fn))(qenv(fn), v254, v180);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-4];
    fn = elt(env, 5); /* general!-plus!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-4];
    v180 = stack[-2];
    v254 = qcdr(v180);
    v180 = stack[-1];
    v180 = qcdr(v180);
    v180 = CC_generalKtimesKmodKp(env, v254, v180);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-4];
    {
        Lisp_Object v290 = stack[0];
        popv(5);
        fn = elt(env, 5); /* general!-plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v290, v180);
    }

v73:
    v254 = stack[-2];
    v180 = stack[-1];
    {
        popv(5);
        fn = elt(env, 6); /* gen!-mult!-by!-const!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v254, v180);
    }

v46:
    v254 = stack[-1];
    v180 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* gen!-mult!-by!-const!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v254, v180);
    }

v54:
    v180 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v180); }
/* error exit handlers */
v306:
    popv(5);
    return nil;
}



/* Code for xcomment */

static Lisp_Object CC_xcomment(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v52, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xcomment");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v63 = v31;
    v52 = v0;
/* end of prologue */
    v51 = v63;
    if (v51 == nil) { popv(2); return onevalue(v52); }
    stack[0] = elt(env, 1); /* comment */
    v51 = v63;
    v51 = Lnreverse(nil, v51);
    env = stack[-1];
    fn = elt(env, 2); /* aconc */
    v51 = (*qfn2(fn))(qenv(fn), v51, v52);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v51 = cons(stack[0], v51);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v52 = v51;
    { popv(2); return onevalue(v52); }
/* error exit handlers */
v53:
    popv(2);
    return nil;
}



/* Code for ibalp_simpat */

static Lisp_Object CC_ibalp_simpat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpat");
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
    v42 = stack[-1];
    stack[-2] = qcar(v42);
    v42 = stack[-1];
    v42 = qcdr(v42);
    v42 = qcar(v42);
    fn = elt(env, 1); /* ibalp_simpterm */
    stack[0] = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v42 = stack[-1];
    v42 = qcdr(v42);
    v42 = qcdr(v42);
    v42 = qcar(v42);
    fn = elt(env, 1); /* ibalp_simpterm */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    {
        Lisp_Object v52 = stack[-2];
        Lisp_Object v63 = stack[0];
        popv(4);
        fn = elt(env, 2); /* ibalp_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v52, v63, v42);
    }
/* error exit handlers */
v51:
    popv(4);
    return nil;
}



/* Code for setcloc!* */

static Lisp_Object MS_CDECL CC_setclocH(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v35, v36;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "setcloc*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setcloc*");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v42 = qvalue(elt(env, 1)); /* ifl!* */
    if (v42 == nil) goto v13;
    v42 = qvalue(elt(env, 1)); /* ifl!* */
    v36 = qcar(v42);
    v35 = (Lisp_Object)17; /* 1 */
    v42 = qvalue(elt(env, 3)); /* curline!* */
    v42 = list2star(v36, v35, v42);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[0];
    goto v5;

v5:
    qvalue(elt(env, 4)) = v42; /* cloc!* */
    { popv(1); return onevalue(v42); }

v13:
    v42 = qvalue(elt(env, 2)); /* nil */
    goto v5;
/* error exit handlers */
v139:
    popv(1);
    return nil;
}



/* Code for xord_gradlex */

static Lisp_Object CC_xord_gradlex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_gradlex");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v58 = stack[-1];
    v123 = qcar(v58);
    v58 = (Lisp_Object)17; /* 1 */
    if (v123 == v58) goto v54;
    v58 = stack[0];
    v123 = qcar(v58);
    v58 = (Lisp_Object)17; /* 1 */
    if (v123 == v58) goto v62;
    v58 = stack[-1];
    stack[-2] = Llength(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v58 = stack[0];
    v58 = Llength(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    if (equal(stack[-2], v58)) goto v64;
    v58 = stack[-1];
    stack[-1] = Llength(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-3];
    v58 = stack[0];
    v58 = Llength(nil, v58);
    nil = C_nil;
    if (exception_pending()) goto v135;
    {
        Lisp_Object v109 = stack[-1];
        popv(4);
        return Lgreaterp(nil, v109, v58);
    }

v64:
    v123 = stack[-1];
    v58 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v123, v58);
    }

v62:
    v58 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v58); }

v54:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v58); }
/* error exit handlers */
v135:
    popv(4);
    return nil;
}



/* Code for rdprep1 */

static Lisp_Object CC_rdprep1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rdprep1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v46 = v0;
/* end of prologue */
    v48 = v46;
    v48 = qcdr(v48);
    if (!consp(v48)) return onevalue(v46);
    v48 = qvalue(elt(env, 1)); /* !:bprec!: */
    {
        fn = elt(env, 2); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v46, v48);
    }
}



/* Code for mkinds */

static Lisp_Object CC_mkinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v50;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkinds");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v31;
    stack[-1] = v0;
/* end of prologue */
    v50 = stack[0];
    v43 = (Lisp_Object)1; /* 0 */
    if (v50 == v43) goto v54;
    v50 = stack[-1];
    v43 = stack[0];
    v43 = cons(v50, v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    stack[-2] = v43;
    v43 = stack[0];
    v43 = sub1(v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v43 = CC_mkinds(env, stack[-1], v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    {
        Lisp_Object v29 = stack[-2];
        popv(4);
        return cons(v29, v43);
    }

v54:
    v43 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v43); }
/* error exit handlers */
v49:
    popv(4);
    return nil;
}



/* Code for aminusp!: */

static Lisp_Object CC_aminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aminusp:");
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
    stack[-2] = nil;
    v20 = qvalue(elt(env, 1)); /* !*modular */
    if (v20 == nil) goto v42;
    v70 = elt(env, 2); /* modular */
    v20 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 7); /* setdmode */
    v20 = (*qfn2(fn))(qenv(fn), v70, v20);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    stack[-2] = v20;
    goto v42;

v42:
    stack[0] = elt(env, 4); /* aminusp!:1 */
    v20 = stack[-1];
    v20 = Lmkquote(nil, v20);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    v20 = list2(stack[0], v20);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    fn = elt(env, 8); /* errorset2 */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    stack[0] = v20;
    v20 = stack[-2];
    if (v20 == nil) goto v6;
    v70 = elt(env, 2); /* modular */
    v20 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 7); /* setdmode */
    v20 = (*qfn2(fn))(qenv(fn), v70, v20);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    goto v6;

v6:
    v20 = stack[0];
    fn = elt(env, 9); /* errorp */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    if (v20 == nil) goto v39;
    v70 = stack[-1];
    v20 = elt(env, 6); /* "arithmetic expression" */
    fn = elt(env, 10); /* typerr */
    v20 = (*qfn2(fn))(qenv(fn), v70, v20);
    nil = C_nil;
    if (exception_pending()) goto v246;
    v20 = nil;
    { popv(4); return onevalue(v20); }

v39:
    v20 = stack[0];
    v20 = qcar(v20);
    { popv(4); return onevalue(v20); }
/* error exit handlers */
v246:
    popv(4);
    return nil;
}



/* Code for rmplus */

static Lisp_Object CC_rmplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v42, v35;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rmplus");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v42 = v0;
/* end of prologue */
    v46 = v42;
    v35 = elt(env, 1); /* plus */
    if (!consp(v46)) goto v62;
    v46 = qcar(v46);
    if (!(v46 == v35)) goto v62;
    v46 = v42;
    v46 = qcdr(v46);
    return onevalue(v46);

v62:
    v46 = v42;
    return ncons(v46);
}



/* Code for tr_write */

static Lisp_Object CC_tr_write(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v63;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tr_write");
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
    v63 = v0;
/* end of prologue */
    v52 = qvalue(elt(env, 1)); /* !*trsolve */
    if (v52 == nil) goto v54;
    v52 = v63;
    stack[0] = v52;
    goto v37;

v37:
    v52 = stack[0];
    if (v52 == nil) goto v25;
    v52 = stack[0];
    v52 = qcar(v52);
    v52 = Lprinc(nil, v52);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    v52 = stack[0];
    v52 = qcdr(v52);
    stack[0] = v52;
    goto v37;

v25:
        popv(2);
        return Lterpri(nil, 0);

v54:
    v52 = nil;
    { popv(2); return onevalue(v52); }
/* error exit handlers */
v53:
    popv(2);
    return nil;
}



/* Code for wtchk */

static Lisp_Object CC_wtchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v340, v341, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wtchk");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v31;
    stack[-2] = v0;
/* end of prologue */
    v340 = stack[-1];
    if (v340 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v340 = stack[-2];
    stack[-3] = ncons(v340);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    stack[0] = elt(env, 1); /* k!* */
    v341 = stack[-1];
    v340 = stack[-2];
    v340 = qcar(v340);
    v340 = qcdr(v340);
    v340 = times2(v341, v340);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    fn = elt(env, 3); /* to */
    v341 = (*qfn2(fn))(qenv(fn), stack[0], v340);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    v340 = (Lisp_Object)17; /* 1 */
    v340 = cons(v341, v340);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    v340 = ncons(v340);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    fn = elt(env, 4); /* quotf */
    v340 = (*qfn2(fn))(qenv(fn), stack[-3], v340);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    v341 = v340;
    v340 = v341;
    if (v340 == nil) goto v66;
    v340 = v341;
    v340 = qcar(v340);
    { popv(5); return onevalue(v340); }

v66:
    v21 = elt(env, 2); /* "weight confusion" */
    v341 = stack[-2];
    v340 = stack[-1];
    v340 = list3(v21, v341, v340);
    nil = C_nil;
    if (exception_pending()) goto v140;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 5); /* errach */
        return (*qfn1(fn))(qenv(fn), v340);
    }
/* error exit handlers */
v140:
    popv(5);
    return nil;
}



/* Code for removeg2 */

static Lisp_Object MS_CDECL CC_removeg2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v31,
                         Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v89, v288, v344;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "removeg2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removeg2");
#endif
    if (stack >= stacklimit)
    {
        push3(v5,v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v31,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v5;
    stack[-4] = v31;
    stack[-5] = v0;
/* end of prologue */
    v91 = stack[-4];
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v91 = qcar(v91);
    v89 = v91;
    v91 = stack[-3];
    v288 = qcar(v91);
    v91 = elt(env, 1); /* g3 */
    if (!(v288 == v91)) goto v59;
    v288 = v89;
    v91 = stack[-3];
    v91 = qcdr(v91);
    v91 = Lmemq(nil, v288, v91);
    if (v91 == nil) goto v59;
    v91 = stack[-3];
    fn = elt(env, 5); /* revv0 */
    v91 = (*qfn2(fn))(qenv(fn), v91, v89);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    goto v61;

v61:
    stack[-3] = v91;
    v89 = stack[-3];
    v91 = elt(env, 4); /* qg */
    v91 = Lrplaca(nil, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    v91 = stack[-5];
    stack[0] = qcar(v91);
    v91 = stack[-5];
    v91 = qcdr(v91);
    fn = elt(env, 6); /* mkcopy */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    v91 = cons(stack[0], v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    stack[-6] = v91;
    v89 = stack[-4];
    v91 = stack[-6];
    v91 = Lmember(nil, v89, v91);
    v91 = qcar(v91);
    stack[-1] = v91;
    v89 = stack[-3];
    v91 = stack[-6];
    v91 = Lmember(nil, v89, v91);
    v91 = qcar(v91);
    stack[0] = v91;
    v91 = stack[-4];
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v91 = qcar(v91);
    stack[-2] = v91;
    v91 = stack[-4];
    v91 = qcdr(v91);
    v89 = qcdr(v91);
    v91 = stack[-4];
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v91 = qcar(v91);
    v91 = Lrplaca(nil, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    v91 = stack[-4];
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v89 = qcdr(v91);
    v91 = stack[-3];
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v91 = qcar(v91);
    v91 = Lrplaca(nil, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    v91 = stack[-3];
    v91 = qcdr(v91);
    v89 = qcdr(v91);
    v91 = stack[-2];
    v91 = Lrplaca(nil, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    v91 = stack[-1];
    v91 = qcdr(v91);
    v91 = qcar(v91);
    stack[-2] = v91;
    v91 = stack[-1];
    v89 = qcdr(v91);
    v91 = stack[-1];
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v91 = qcar(v91);
    v91 = Lrplaca(nil, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    v91 = stack[-1];
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v89 = qcdr(v91);
    v91 = stack[0];
    v91 = qcdr(v91);
    v91 = qcdr(v91);
    v91 = qcar(v91);
    v91 = Lrplaca(nil, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    v91 = stack[0];
    v91 = qcdr(v91);
    v89 = qcdr(v91);
    v91 = stack[0];
    v91 = qcdr(v91);
    v91 = qcar(v91);
    v91 = Lrplaca(nil, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    v91 = stack[0];
    v89 = qcdr(v91);
    v91 = stack[-2];
    v91 = Lrplaca(nil, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    stack[0] = stack[-5];
    v91 = stack[-6];
    v91 = qcar(v91);
    fn = elt(env, 7); /* negsq */
    v89 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    v91 = stack[-6];
    v91 = qcdr(v91);
    {
        Lisp_Object v120 = stack[0];
        popv(8);
        return list2star(v120, v89, v91);
    }

v59:
    v344 = elt(env, 2); /* "Edge" */
    v288 = v89;
    v89 = elt(env, 3); /* "is absent in vertex" */
    v91 = stack[-3];
    v91 = list4(v344, v288, v89, v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    fn = elt(env, 8); /* cerror */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v287;
    env = stack[-7];
    goto v61;
/* error exit handlers */
v287:
    popv(8);
    return nil;
}



/* Code for rl_gettype */

static Lisp_Object CC_rl_gettype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v53, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_gettype");
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
    v53 = v0;
/* end of prologue */
    v6 = v53;
    v60 = elt(env, 1); /* avalue */
    v60 = get(v6, v60);
    env = stack[0];
    v6 = v60;
    v60 = v6;
    if (v60 == nil) goto v42;
    v60 = v6;
    v60 = qcar(v60);
    { popv(1); return onevalue(v60); }

v42:
    v60 = v53;
    v53 = elt(env, 2); /* rtype */
    popv(1);
    return get(v60, v53);
}



/* Code for bind */

static Lisp_Object CC_bind(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v31)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v53, v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bind");
#endif
    if (stack >= stacklimit)
    {
        push2(v31,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v53 = v31;
    v60 = v0;
/* end of prologue */
    stack[-1] = v60;
    stack[0] = elt(env, 1); /* binding */
    v6 = v53;
    v53 = v60;
    v60 = elt(env, 1); /* binding */
    v60 = get(v53, v60);
    env = stack[-2];
    v60 = cons(v6, v60);
    nil = C_nil;
    if (exception_pending()) goto v44;
    {
        Lisp_Object v145 = stack[-1];
        Lisp_Object v73 = stack[0];
        popv(3);
        return Lputprop(nil, 3, v145, v73, v60);
    }
/* error exit handlers */
v44:
    popv(3);
    return nil;
}



setup_type const u10_setup[] =
{
    {"ibalp_var-wclist",        CC_ibalp_varKwclist,too_many_1,wrong_no_1},
    {"omvir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omvir},
    {"c:subs2multf",            too_few_2,      CC_cTsubs2multf,wrong_no_2},
    {"listdiff",                too_few_2,      CC_listdiff,   wrong_no_2},
    {"equal:",                  too_few_2,      CC_equalT,     wrong_no_2},
    {"has_parents",             CC_has_parents, too_many_1,    wrong_no_1},
    {"red-ratios1",             too_few_2,      CC_redKratios1,wrong_no_2},
    {"mo_neg",                  CC_mo_neg,      too_many_1,    wrong_no_1},
    {"freeof",                  too_few_2,      CC_freeof,     wrong_no_2},
    {"rl_simplat1",             too_few_2,      CC_rl_simplat1,wrong_no_2},
    {"gcdf2",                   too_few_2,      CC_gcdf2,      wrong_no_2},
    {"kernp",                   CC_kernp,       too_many_1,    wrong_no_1},
    {"ibalp_getvar-zmom",       too_few_2,      CC_ibalp_getvarKzmom,wrong_no_2},
    {"integerom",               CC_integerom,   too_many_1,    wrong_no_1},
    {"rnconc",                  too_few_2,      CC_rnconc,     wrong_no_2},
    {"dp_times_bcmo",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_dp_times_bcmo},
    {"dl_get",                  CC_dl_get,      too_many_1,    wrong_no_1},
    {"kernord",                 too_few_2,      CC_kernord,    wrong_no_2},
    {"mconv",                   CC_mconv,       too_many_1,    wrong_no_1},
    {"make-univariate-image-mod-p",too_few_2,   CC_makeKunivariateKimageKmodKp,wrong_no_2},
    {"searchtm",                CC_searchtm,    too_many_1,    wrong_no_1},
    {"removeg1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg1},
    {"ibalp_litlp",             CC_ibalp_litlp, too_many_1,    wrong_no_1},
    {"omiir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omiir},
    {"getcomb",                 too_few_2,      CC_getcomb,    wrong_no_2},
    {"dipilcomb1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipilcomb1},
    {"*kp2f",                   too_few_2,      CC_Hkp2f,      wrong_no_2},
    {"dp_neg",                  CC_dp_neg,      too_many_1,    wrong_no_1},
    {"pdif",                    too_few_2,      CC_pdif,       wrong_no_2},
    {"gperm3",                  too_few_2,      CC_gperm3,     wrong_no_2},
    {"dcombine",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_dcombine},
    {"freeofl",                 too_few_2,      CC_freeofl,    wrong_no_2},
    {"exchk1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_exchk1},
    {"ibalp_litp",              CC_ibalp_litp,  too_many_1,    wrong_no_1},
    {"setdmode1",               too_few_2,      CC_setdmode1,  wrong_no_2},
    {"wedgepf",                 too_few_2,      CC_wedgepf,    wrong_no_2},
    {"statep*",                 CC_statepH,     too_many_1,    wrong_no_1},
    {"map__edges",              CC_map__edges,  too_many_1,    wrong_no_1},
    {"simptimes",               CC_simptimes,   too_many_1,    wrong_no_1},
    {"bc_zero?",                CC_bc_zeroW,    too_many_1,    wrong_no_1},
    {"general-times-mod-p",     too_few_2,      CC_generalKtimesKmodKp,wrong_no_2},
    {"xcomment",                too_few_2,      CC_xcomment,   wrong_no_2},
    {"ibalp_simpat",            CC_ibalp_simpat,too_many_1,    wrong_no_1},
    {"setcloc*",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_setclocH},
    {"xord_gradlex",            too_few_2,      CC_xord_gradlex,wrong_no_2},
    {"rdprep1",                 CC_rdprep1,     too_many_1,    wrong_no_1},
    {"mkinds",                  too_few_2,      CC_mkinds,     wrong_no_2},
    {"aminusp:",                CC_aminuspT,    too_many_1,    wrong_no_1},
    {"rmplus",                  CC_rmplus,      too_many_1,    wrong_no_1},
    {"tr_write",                CC_tr_write,    too_many_1,    wrong_no_1},
    {"wtchk",                   too_few_2,      CC_wtchk,      wrong_no_2},
    {"removeg2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_removeg2},
    {"rl_gettype",              CC_rl_gettype,  too_many_1,    wrong_no_1},
    {"bind",                    too_few_2,      CC_bind,       wrong_no_2},
    {NULL, (one_args *)"u10", (two_args *)"18871 5280214 5071479", 0}
};

/* end of generated code */
