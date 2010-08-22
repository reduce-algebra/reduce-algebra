
/* $destdir/generated-c\u44.c Machine generated C code */

/* Signature: 00000000 21-Aug-2010 */

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


/* Code for dv_skelsplit1 */

static Lisp_Object CC_dv_skelsplit1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skelsplit1");
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
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v1;
    stack[-11] = v0;
/* end of prologue */
    stack[-12] = nil;
    stack[-9] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    stack[-6] = nil;
    v99 = stack[-11];
    v99 = qcdr(v99);
    v99 = qcar(v99);
    if (is_number(v99)) goto v101;
    v99 = stack[-11];
    v99 = qcdr(v99);
    v99 = Llength(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[0] = v99;
    v99 = stack[0];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = Lmkvect(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-5] = v99;
    v99 = stack[0];
    stack[-4] = v99;
    v99 = stack[-11];
    v99 = qcdr(v99);
    v99 = Lreverse(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-3] = v99;
    goto v103;

v103:
    v99 = stack[-3];
    if (v99 == nil) goto v104;
    v99 = stack[-3];
    v99 = qcar(v99);
    stack[-2] = v99;
    stack[-1] = stack[-5];
    v99 = stack[-4];
    stack[0] = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v100 = stack[-2];
    v99 = stack[-10];
    v99 = CC_dv_skelsplit1(env, v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v99;
    stack[0] = stack[-5];
    v99 = stack[-4];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    v100 = qcar(v99);
    v99 = stack[-6];
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-6] = v99;
    v100 = stack[-4];
    v99 = stack[-12];
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-12] = v99;
    v99 = stack[-4];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-4] = v99;
    v99 = stack[-3];
    v99 = qcdr(v99);
    stack[-3] = v99;
    goto v103;

v104:
    v99 = stack[-6];
    stack[-3] = v99;
    goto v105;

v105:
    v99 = stack[-3];
    if (v99 == nil) goto v106;
    v99 = stack[-3];
    v99 = qcar(v99);
    fn = elt(env, 3); /* copy */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-2] = v99;
    v99 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-1] = v99;
    v99 = stack[-3];
    v99 = qcdr(v99);
    stack[-3] = v99;
    v99 = stack[-1];
    if (!consp(v99)) goto v105;
    else goto v107;

v107:
    v99 = stack[-3];
    if (v99 == nil) goto v108;
    stack[0] = stack[-1];
    v99 = stack[-3];
    v99 = qcar(v99);
    fn = elt(env, 3); /* copy */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = Lrplacd(nil, stack[0], v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = stack[-1];
    fn = elt(env, 4); /* lastpair */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-1] = v99;
    v99 = stack[-3];
    v99 = qcdr(v99);
    stack[-3] = v99;
    goto v107;

v108:
    v99 = stack[-2];
    goto v109;

v109:
    stack[-6] = v99;
    goto v110;

v110:
    v99 = stack[-11];
    v100 = qcar(v99);
    v99 = elt(env, 2); /* !* */
    if (v100 == v99) goto v111;
    v99 = stack[-12];
    stack[-3] = v99;
    goto v112;

v112:
    v99 = stack[-3];
    if (v99 == nil) goto v113;
    v99 = stack[-3];
    v99 = qcar(v99);
    stack[-2] = v99;
    v99 = stack[-9];
    if (v99 == nil) goto v114;
    stack[0] = stack[-5];
    v99 = stack[-2];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    v100 = qcar(v99);
    v99 = stack[-9];
    v99 = qcar(v99);
    if (equal(v100, v99)) goto v115;
    v100 = stack[-9];
    v99 = stack[-7];
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-7] = v99;
    stack[0] = stack[-5];
    v99 = stack[-2];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    stack[-1] = qcar(v99);
    stack[0] = stack[-5];
    v99 = stack[-2];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    v100 = qcdr(v99);
    v99 = qvalue(elt(env, 1)); /* nil */
    v99 = list2star(stack[-1], v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-9] = v99;
    goto v116;

v116:
    v99 = stack[-3];
    v99 = qcdr(v99);
    stack[-3] = v99;
    goto v112;

v115:
    stack[-1] = stack[-9];
    stack[0] = stack[-5];
    v99 = stack[-2];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    v100 = qcdr(v99);
    v99 = stack[-9];
    v99 = qcdr(v99);
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = Lrplacd(nil, stack[-1], v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    goto v116;

v114:
    stack[0] = stack[-5];
    v99 = stack[-2];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    stack[-1] = qcar(v99);
    stack[0] = stack[-5];
    v99 = stack[-2];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    v100 = qcdr(v99);
    v99 = qvalue(elt(env, 1)); /* nil */
    v99 = list2star(stack[-1], v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-9] = v99;
    goto v116;

v113:
    v100 = stack[-9];
    v99 = stack[-7];
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-7] = v99;
    v99 = stack[-7];
    stack[-1] = v99;
    goto v117;

v117:
    v99 = stack[-1];
    if (v99 == nil) goto v118;
    v99 = stack[-1];
    v99 = qcar(v99);
    v100 = v99;
    v99 = v100;
    v99 = qcdr(v99);
    if (v99 == nil) goto v119;
    v99 = stack[-11];
    stack[0] = qcar(v99);
    v99 = v100;
    v99 = qcdr(v99);
    v99 = Lreverse(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = cons(stack[0], v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v100 = v99;
    v99 = stack[-8];
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-8] = v99;
    goto v119;

v119:
    v99 = stack[-1];
    v99 = qcdr(v99);
    stack[-1] = v99;
    goto v117;

v118:
    v99 = stack[-8];
    v100 = Llength(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = (Lisp_Object)17; /* 1 */
    if (v100 == v99) goto v120;
    v100 = elt(env, 2); /* !* */
    v99 = stack[-8];
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    stack[-8] = v99;
    goto v121;

v121:
    v100 = stack[-6];
    v99 = stack[-8];
    popv(14);
    return cons(v100, v99);

v120:
    v99 = stack[-8];
    v99 = qcar(v99);
    stack[-8] = v99;
    goto v121;

v111:
    v99 = stack[-12];
    v99 = Lreverse(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-2] = v99;
    goto v122;

v122:
    v99 = stack[-2];
    if (v99 == nil) goto v123;
    v99 = stack[-2];
    v99 = qcar(v99);
    stack[-1] = v99;
    stack[0] = stack[-5];
    v99 = stack[-1];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    v99 = qcdr(v99);
    if (v99 == nil) goto v124;
    stack[0] = stack[-5];
    v99 = stack[-1];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    v100 = qcdr(v99);
    v99 = stack[-8];
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-8] = v99;
    goto v124;

v124:
    v99 = stack[-2];
    v99 = qcdr(v99);
    stack[-2] = v99;
    goto v122;

v123:
    v99 = stack[-8];
    v100 = Llength(nil, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = (Lisp_Object)17; /* 1 */
    if (v100 == v99) goto v125;
    v99 = stack[-8];
    if (v99 == nil) goto v126;
    v100 = elt(env, 2); /* !* */
    v99 = stack[-8];
    v99 = cons(v100, v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    stack[-8] = v99;
    goto v126;

v126:
    v100 = stack[-6];
    v99 = stack[-8];
    popv(14);
    return cons(v100, v99);

v125:
    v99 = stack[-8];
    v99 = qcar(v99);
    stack[-8] = v99;
    goto v126;

v106:
    v99 = qvalue(elt(env, 1)); /* nil */
    goto v109;

v101:
    v99 = stack[-10];
    stack[-5] = v99;
    v99 = stack[-11];
    v99 = qcdr(v99);
    stack[-12] = v99;
    v99 = stack[-11];
    v99 = qcdr(v99);
    stack[-4] = v99;
    v99 = stack[-4];
    if (v99 == nil) goto v127;
    v99 = stack[-4];
    v99 = qcar(v99);
    stack[0] = stack[-5];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    v99 = qcar(v99);
    v99 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    stack[-2] = v99;
    stack[-3] = v99;
    goto v128;

v128:
    v99 = stack[-4];
    v99 = qcdr(v99);
    stack[-4] = v99;
    v99 = stack[-4];
    if (v99 == nil) goto v129;
    stack[-1] = stack[-2];
    v99 = stack[-4];
    v99 = qcar(v99);
    stack[0] = stack[-5];
    v99 = sub1(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v99/(16/CELL)));
    v99 = qcar(v99);
    v99 = ncons(v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = Lrplacd(nil, stack[-1], v99);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-13];
    v99 = stack[-2];
    v99 = qcdr(v99);
    stack[-2] = v99;
    goto v128;

v129:
    v99 = stack[-3];
    goto v130;

v130:
    stack[-6] = v99;
    goto v110;

v127:
    v99 = qvalue(elt(env, 1)); /* nil */
    goto v130;
/* error exit handlers */
v102:
    popv(14);
    return nil;
}



/* Code for reduce!-mod!-eig */

static Lisp_Object CC_reduceKmodKeig(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v148, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-mod-eig");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v147 = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[0] = v147;
    goto v75;

v75:
    v147 = stack[0];
    if (v147 == nil) goto v27;
    v148 = stack[-1];
    v147 = stack[0];
    v147 = qcar(v147);
    v147 = qcdr(v147);
    fn = elt(env, 2); /* reduce!-mod!-eigf */
    v147 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    stack[-6] = v147;
    v147 = qcar(v147);
    if (v147 == nil) goto v151;
    v147 = stack[0];
    v147 = qcar(v147);
    v149 = qcar(v147);
    v148 = stack[-6];
    v147 = stack[-2];
    v147 = acons(v149, v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    stack[-2] = v147;
    goto v151;

v151:
    v147 = stack[0];
    v147 = qcdr(v147);
    stack[0] = v147;
    goto v75;

v27:
    v147 = (Lisp_Object)17; /* 1 */
    stack[-6] = v147;
    v147 = stack[-2];
    stack[0] = v147;
    goto v152;

v152:
    v147 = stack[0];
    if (v147 == nil) goto v153;
    v148 = stack[-6];
    v147 = stack[0];
    v147 = qcar(v147);
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    fn = elt(env, 3); /* lcm */
    v147 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    stack[-6] = v147;
    v147 = stack[0];
    v147 = qcdr(v147);
    stack[0] = v147;
    goto v152;

v153:
    v147 = stack[-2];
    v147 = Lreverse(nil, v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    stack[-5] = v147;
    v147 = stack[-5];
    if (v147 == nil) goto v154;
    v147 = stack[-5];
    v147 = qcar(v147);
    stack[-1] = qcar(v147);
    v147 = stack[-5];
    v147 = qcar(v147);
    v147 = qcdr(v147);
    stack[0] = qcar(v147);
    v148 = stack[-6];
    v147 = stack[-5];
    v147 = qcar(v147);
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    fn = elt(env, 4); /* quotf */
    v147 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    fn = elt(env, 5); /* multf */
    v147 = (*qfn2(fn))(qenv(fn), stack[0], v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    v147 = cons(stack[-1], v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    v147 = ncons(v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    stack[-3] = v147;
    stack[-4] = v147;
    goto v90;

v90:
    v147 = stack[-5];
    v147 = qcdr(v147);
    stack[-5] = v147;
    v147 = stack[-5];
    if (v147 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    stack[-2] = stack[-3];
    v147 = stack[-5];
    v147 = qcar(v147);
    stack[-1] = qcar(v147);
    v147 = stack[-5];
    v147 = qcar(v147);
    v147 = qcdr(v147);
    stack[0] = qcar(v147);
    v148 = stack[-6];
    v147 = stack[-5];
    v147 = qcar(v147);
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    fn = elt(env, 4); /* quotf */
    v147 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    fn = elt(env, 5); /* multf */
    v147 = (*qfn2(fn))(qenv(fn), stack[0], v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    v147 = cons(stack[-1], v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    v147 = ncons(v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    v147 = Lrplacd(nil, stack[-2], v147);
    nil = C_nil;
    if (exception_pending()) goto v150;
    env = stack[-7];
    v147 = stack[-3];
    v147 = qcdr(v147);
    stack[-3] = v147;
    goto v90;

v154:
    v147 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v147); }
/* error exit handlers */
v150:
    popv(8);
    return nil;
}



/* Code for spreadvar */

static Lisp_Object MS_CDECL CC_spreadvar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v155, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v136, v161;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "spreadvar");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spreadvar");
#endif
    if (stack >= stacklimit)
    {
        push3(v155,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v155);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v136 = v155;
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v19:
    v137 = stack[-1];
    if (!consp(v137)) { popv(4); return onevalue(v136); }
    v137 = stack[-1];
    v137 = qcar(v137);
    if (!consp(v137)) { popv(4); return onevalue(v136); }
    v137 = stack[-1];
    v137 = qcar(v137);
    v137 = qcar(v137);
    v161 = qcar(v137);
    v137 = stack[0];
    if (!(equal(v161, v137))) goto v162;
    v137 = stack[-1];
    v137 = qcar(v137);
    v137 = qcar(v137);
    v161 = qcdr(v137);
    v137 = v136;
    v137 = Lmember(nil, v161, v137);
    if (!(v137 == nil)) goto v162;
    v137 = stack[-1];
    v137 = qcar(v137);
    v137 = qcar(v137);
    v137 = qcdr(v137);
    v137 = cons(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    v136 = v137;
    goto v162;

v162:
    v137 = stack[-1];
    v137 = qcdr(v137);
    stack[-2] = v137;
    v137 = stack[-1];
    v137 = qcar(v137);
    v161 = qcdr(v137);
    v137 = stack[0];
    v137 = CC_spreadvar(env, 3, v161, v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    v136 = v137;
    v137 = stack[-2];
    stack[-1] = v137;
    goto v19;
/* error exit handlers */
v163:
    popv(4);
    return nil;
}



/* Code for deg */

static Lisp_Object CC_deg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg");
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
    v168 = qvalue(elt(env, 1)); /* gdmode!* */
    stack[-2] = qvalue(elt(env, 2)); /* dmode!* */
    qvalue(elt(env, 2)) = v168; /* dmode!* */
    v168 = stack[-1];
    fn = elt(env, 3); /* simp!* */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    stack[-1] = v168;
    v169 = stack[-1];
    v168 = stack[0];
    fn = elt(env, 4); /* tstpolyarg2 */
    v168 = (*qfn2(fn))(qenv(fn), v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    v168 = stack[-1];
    v169 = qcar(v168);
    v168 = stack[0];
    fn = elt(env, 5); /* numrdeg */
    v168 = (*qfn2(fn))(qenv(fn), v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v168); }
/* error exit handlers */
v87:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for sfto_lmultf */

static Lisp_Object CC_sfto_lmultf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_lmultf");
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
    goto v4;

v4:
    v98 = stack[0];
    if (v98 == nil) goto v19;
    v98 = stack[0];
    v145 = qcar(v98);
    v98 = stack[-1];
    v98 = cons(v145, v98);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-2];
    stack[-1] = v98;
    v98 = stack[0];
    v98 = qcdr(v98);
    stack[0] = v98;
    goto v4;

v19:
    v98 = (Lisp_Object)17; /* 1 */
    v145 = v98;
    goto v5;

v5:
    v98 = stack[-1];
    if (v98 == nil) { popv(3); return onevalue(v145); }
    v98 = stack[-1];
    v98 = qcar(v98);
    fn = elt(env, 1); /* multf */
    v98 = (*qfn2(fn))(qenv(fn), v98, v145);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-2];
    v145 = v98;
    v98 = stack[-1];
    v98 = qcdr(v98);
    stack[-1] = v98;
    goto v5;
/* error exit handlers */
v172:
    popv(3);
    return nil;
}



/* Code for exceeds!-order!-variant */

static Lisp_Object CC_exceedsKorderKvariant(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exceeds-order-variant");
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

v177:
    v175 = stack[-1];
    if (v175 == nil) goto v20;
    v175 = stack[0];
    v175 = qcar(v175);
    stack[-2] = v175;
    v175 = (Lisp_Object)1; /* 0 */
    v176 = v175;
    goto v168;

v168:
    v175 = stack[-2];
    if (v175 == nil) goto v130;
    v175 = stack[-2];
    v175 = qcar(v175);
    fn = elt(env, 2); /* tayexp!-plus2 */
    v175 = (*qfn2(fn))(qenv(fn), v175, v176);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    v176 = v175;
    v175 = stack[-2];
    v175 = qcdr(v175);
    stack[-2] = v175;
    goto v168;

v130:
    v175 = v176;
    v176 = v175;
    v175 = stack[-1];
    v175 = qcar(v175);
    fn = elt(env, 3); /* tayexp!-greaterp */
    v175 = (*qfn2(fn))(qenv(fn), v176, v175);
    nil = C_nil;
    if (exception_pending()) goto v178;
    env = stack[-3];
    if (!(v175 == nil)) { popv(4); return onevalue(v175); }
    v175 = stack[-1];
    v176 = qcdr(v175);
    v175 = stack[0];
    v175 = qcdr(v175);
    stack[-1] = v176;
    stack[0] = v175;
    goto v177;

v20:
    v175 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v175); }
/* error exit handlers */
v178:
    popv(4);
    return nil;
}



/* Code for available!*p */

static Lisp_Object CC_availableHp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for available*p");
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
    v151 = stack[0];
    if (symbolp(v151)) goto v180;
    v151 = elt(env, 1); /* "this is no group identifier" */
    fn = elt(env, 3); /* rederr */
    v151 = (*qfn1(fn))(qenv(fn), v151);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-1];
    goto v180;

v180:
    v151 = stack[0];
    v174 = elt(env, 2); /* available */
        popv(2);
        return Lflagp(nil, v151, v174);
/* error exit handlers */
v164:
    popv(2);
    return nil;
}



/* Code for makevar */

static Lisp_Object CC_makevar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makevar");
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
    v167 = v0;
/* end of prologue */
    stack[-1] = Lexplode(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    v167 = stack[0];
    v167 = Lexplode(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-2];
    v167 = Lnconc(nil, stack[-1], v167);
    nil = C_nil;
    if (exception_pending()) goto v179;
        popv(3);
        return Lcompress(nil, v167);
/* error exit handlers */
v179:
    popv(3);
    return nil;
}



/* Code for cl_cxfp */

static Lisp_Object CC_cl_cxfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v195, v196;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_cxfp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v195 = v0;
/* end of prologue */
    v194 = v195;
    if (!consp(v194)) goto v50;
    v194 = v195;
    v194 = qcar(v194);
    goto v12;

v12:
    v196 = v194;
    v195 = v196;
    v194 = elt(env, 1); /* true */
    v194 = (v195 == v194 ? lisp_true : nil);
    if (!(v194 == nil)) goto v179;
    v195 = v196;
    v194 = elt(env, 2); /* false */
    v194 = (v195 == v194 ? lisp_true : nil);
    goto v179;

v179:
    if (!(v194 == nil)) return onevalue(v194);
    v195 = v196;
    v194 = elt(env, 3); /* or */
    v194 = (v195 == v194 ? lisp_true : nil);
    if (!(v194 == nil)) goto v98;
    v195 = v196;
    v194 = elt(env, 4); /* and */
    v194 = (v195 == v194 ? lisp_true : nil);
    goto v98;

v98:
    if (!(v194 == nil)) goto v171;
    v195 = v196;
    v194 = elt(env, 5); /* not */
    v194 = (v195 == v194 ? lisp_true : nil);
    goto v171;

v171:
    if (!(v194 == nil)) goto v197;
    v195 = v196;
    v194 = elt(env, 6); /* impl */
    v194 = (v195 == v194 ? lisp_true : nil);
    if (!(v194 == nil)) goto v197;
    v195 = v196;
    v194 = elt(env, 7); /* repl */
    v194 = (v195 == v194 ? lisp_true : nil);
    if (!(v194 == nil)) goto v197;
    v195 = v196;
    v194 = elt(env, 8); /* equiv */
    v194 = (v195 == v194 ? lisp_true : nil);
    goto v197;

v197:
    if (!(v194 == nil)) return onevalue(v194);
    v195 = v196;
    v194 = elt(env, 9); /* ex */
    v194 = (v195 == v194 ? lisp_true : nil);
    if (!(v194 == nil)) goto v198;
    v195 = v196;
    v194 = elt(env, 10); /* all */
    v194 = (v195 == v194 ? lisp_true : nil);
    goto v198;

v198:
    if (!(v194 == nil)) return onevalue(v194);
    v195 = v196;
    v194 = elt(env, 11); /* bex */
    v194 = (v195 == v194 ? lisp_true : nil);
    if (!(v194 == nil)) return onevalue(v194);
    v194 = v196;
    v195 = elt(env, 12); /* ball */
    v194 = (v194 == v195 ? lisp_true : nil);
    return onevalue(v194);

v50:
    v194 = v195;
    goto v12;
}



/* Code for applyml */

static Lisp_Object MS_CDECL CC_applyml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "applyml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for applyml");
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
    fn = elt(env, 8); /* lex */
    v144 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    v144 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 9); /* compress!* */
    v156 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    v144 = qvalue(elt(env, 2)); /* rdlist!* */
    v144 = Lassoc(nil, v156, v144);
    stack[-1] = v144;
    if (v144 == nil) goto v159;
    v144 = stack[-1];
    v144 = qcdr(v144);
    fn = elt(env, 10); /* first */
    stack[0] = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    v144 = stack[-1];
    v144 = qcdr(v144);
    fn = elt(env, 11); /* rest */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    {
        Lisp_Object v136 = stack[0];
        popv(3);
        fn = elt(env, 12); /* apply */
        return (*qfn2(fn))(qenv(fn), v136, v144);
    }

v159:
    v156 = qvalue(elt(env, 1)); /* char */
    v144 = elt(env, 3); /* (i d e n t !/) */
    if (equal(v156, v144)) goto v130;
    v156 = qvalue(elt(env, 1)); /* char */
    v144 = elt(env, 4); /* (c o m p o s e !/) */
    if (equal(v156, v144)) goto v130;
    v156 = qvalue(elt(env, 1)); /* char */
    v144 = elt(env, 6); /* (i n v e r s e !/) */
    if (equal(v156, v144)) goto v96;
    v144 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 9); /* compress!* */
    v156 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-2];
    v144 = (Lisp_Object)273; /* 17 */
    fn = elt(env, 13); /* errorml */
    v144 = (*qfn2(fn))(qenv(fn), v156, v144);
    nil = C_nil;
    if (exception_pending()) goto v137;
    v144 = nil;
    { popv(3); return onevalue(v144); }

v96:
    v144 = qvalue(elt(env, 7)); /* t */
    { popv(3); return onevalue(v144); }

v130:
    v144 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v144); }
/* error exit handlers */
v137:
    popv(3);
    return nil;
}



/* Code for pm!:gensym */

static Lisp_Object MS_CDECL CC_pmTgensym(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "pm:gensym");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pm:gensym");
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
    stack[-1] = elt(env, 1); /* !? */
    stack[0] = elt(env, 2); /* !_ */
    v202 = qvalue(elt(env, 3)); /* pm!:gensym!-count!* */
    v202 = add1(v202);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    qvalue(elt(env, 3)) = v202; /* pm!:gensym!-count!* */
    v202 = Lexplode(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-2];
    v202 = list2star(stack[-1], stack[0], v202);
    nil = C_nil;
    if (exception_pending()) goto v101;
        popv(3);
        return Lcompress(nil, v202);
/* error exit handlers */
v101:
    popv(3);
    return nil;
}



/* Code for exdfpf */

static Lisp_Object CC_exdfpf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v139, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exdfpf");
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
    stack[-3] = nil;
    goto v4;

v4:
    v208 = stack[-2];
    if (v208 == nil) goto v19;
    v208 = stack[-2];
    v208 = qcar(v208);
    v139 = qcar(v208);
    v208 = (Lisp_Object)17; /* 1 */
    if (v139 == v208) goto v164;
    v208 = stack[-2];
    v208 = qcar(v208);
    v208 = qcar(v208);
    fn = elt(env, 2); /* exdfk */
    v139 = (*qfn1(fn))(qenv(fn), v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v208 = stack[-2];
    v208 = qcar(v208);
    v208 = qcdr(v208);
    fn = elt(env, 3); /* multpfsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v139, v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v208 = stack[-2];
    v208 = qcar(v208);
    v208 = qcdr(v208);
    fn = elt(env, 4); /* exdf0 */
    stack[0] = (*qfn1(fn))(qenv(fn), v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v208 = stack[-2];
    v208 = qcar(v208);
    v208 = qcar(v208);
    v140 = ncons(v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v139 = (Lisp_Object)17; /* 1 */
    v208 = (Lisp_Object)17; /* 1 */
    v208 = list2star(v140, v139, v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v208 = ncons(v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    fn = elt(env, 5); /* wedgepf2 */
    v208 = (*qfn2(fn))(qenv(fn), stack[0], v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    fn = elt(env, 6); /* mkuniquewedge */
    v208 = (*qfn1(fn))(qenv(fn), v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    fn = elt(env, 7); /* addpf */
    v208 = (*qfn2(fn))(qenv(fn), stack[-1], v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v139 = v208;
    goto v179;

v179:
    v208 = stack[-3];
    v208 = cons(v139, v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    stack[-3] = v208;
    v208 = stack[-2];
    v208 = qcdr(v208);
    stack[-2] = v208;
    goto v4;

v164:
    v208 = stack[-2];
    v208 = qcar(v208);
    v208 = qcdr(v208);
    fn = elt(env, 4); /* exdf0 */
    v208 = (*qfn1(fn))(qenv(fn), v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v139 = v208;
    goto v179;

v19:
    v208 = qvalue(elt(env, 1)); /* nil */
    v139 = v208;
    goto v5;

v5:
    v208 = stack[-3];
    if (v208 == nil) { popv(5); return onevalue(v139); }
    v208 = stack[-3];
    v208 = qcar(v208);
    fn = elt(env, 7); /* addpf */
    v208 = (*qfn2(fn))(qenv(fn), v208, v139);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v139 = v208;
    v208 = stack[-3];
    v208 = qcdr(v208);
    stack[-3] = v208;
    goto v5;
/* error exit handlers */
v209:
    popv(5);
    return nil;
}



/* Code for cr!:prep */

static Lisp_Object CC_crTprep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cr:prep");
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
    v193 = elt(env, 1); /* !:rd!: */
    v128 = stack[0];
    v128 = qcdr(v128);
    v128 = qcar(v128);
    v128 = cons(v193, v128);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    v193 = elt(env, 1); /* !:rd!: */
    v128 = stack[0];
    v128 = qcdr(v128);
    v128 = qcdr(v128);
    v128 = cons(v193, v128);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    v128 = cons(stack[-1], v128);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* crprep1 */
        return (*qfn1(fn))(qenv(fn), v128);
    }
/* error exit handlers */
v210:
    popv(3);
    return nil;
}



/* Code for tvectorp */

static Lisp_Object CC_tvectorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tvectorp");
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
    v165 = v0;
/* end of prologue */
    v165 = qcar(v165);
    v165 = qcar(v165);
    fn = elt(env, 2); /* deg!*form */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[0];
    v168 = v165;
    v165 = v168;
    if (is_number(v165)) goto v101;
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v165); }

v101:
    v165 = (Lisp_Object)1; /* 0 */
        popv(1);
        return Llessp(nil, v168, v165);
/* error exit handlers */
v169:
    popv(1);
    return nil;
}



/* Code for new_provev */

static Lisp_Object CC_new_provev(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v172, v173, v96;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for new_provev");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v173 = v1;
    v96 = v0;
/* end of prologue */
    v172 = v96;
    v199 = v173;
    v199 = Lmember(nil, v172, v199);
    if (v199 == nil) goto v20;
    v199 = v96;
    v199 = qcdr(v199);
    v199 = qcar(v199);
    v172 = qcar(v199);
    v199 = v173;
    v199 = Lassoc(nil, v172, v199);
    if (v199 == nil) return onevalue(v173);
    v199 = v96;
    v199 = qcdr(v199);
    v199 = qcar(v199);
    v172 = qcdr(v199);
    v199 = v173;
    v199 = Lassoc(nil, v172, v199);
    if (v199 == nil) return onevalue(v173);
    v199 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v199);

v20:
    v199 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v199);
}



/* Code for compactf3 */

static Lisp_Object MS_CDECL CC_compactf3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v155, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v160, v210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactf3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactf3");
#endif
    if (stack >= stacklimit)
    {
        push3(v155,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v155);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v155;
    stack[-1] = v1;
    v160 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* mv!-vars!* */
    qvalue(elt(env, 1)) = nil; /* mv!-vars!* */
    v159 = stack[0];
    qvalue(elt(env, 1)) = v159; /* mv!-vars!* */
    v159 = stack[0];
    fn = elt(env, 3); /* sf2mv */
    v210 = (*qfn2(fn))(qenv(fn), v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-3];
    v160 = stack[-1];
    v159 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* mv!-compact */
    v160 = (*qfnn(fn))(qenv(fn), 3, v210, v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-3];
    v159 = stack[0];
    fn = elt(env, 5); /* mv2sf */
    v159 = (*qfn2(fn))(qenv(fn), v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* mv!-vars!* */
    { popv(4); return onevalue(v159); }
/* error exit handlers */
v170:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* mv!-vars!* */
    popv(4);
    return nil;
}



/* Code for dp!=prod */

static Lisp_Object CC_dpMprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v211, v212, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=prod");
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
    v212 = v0;
/* end of prologue */
    v211 = v212;
    if (v211 == nil) goto v20;
    v211 = stack[-1];
    if (v211 == nil) goto v20;
    stack[-2] = nil;
    v211 = v212;
    stack[0] = v211;
    goto v174;

v174:
    v211 = stack[0];
    if (v211 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v211 = stack[0];
    v211 = qcar(v211);
    v212 = v211;
    v157 = qcdr(v212);
    v212 = qcar(v211);
    v211 = stack[-1];
    fn = elt(env, 2); /* dp_times_bcmo */
    v212 = (*qfnn(fn))(qenv(fn), 3, v157, v212, v211);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-3];
    v211 = stack[-2];
    fn = elt(env, 3); /* dp_sum */
    v211 = (*qfn2(fn))(qenv(fn), v212, v211);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-3];
    stack[-2] = v211;
    v211 = stack[0];
    v211 = qcdr(v211);
    stack[0] = v211;
    goto v174;

v20:
    v211 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v211); }
/* error exit handlers */
v176:
    popv(4);
    return nil;
}



/* Code for newbasis */

static Lisp_Object CC_newbasis(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v155)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v190, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newbasis");
#endif
    if (stack >= stacklimit)
    {
        push2(v155,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v155);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v155;
    v143 = v1;
/* end of prologue */
    stack[-5] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v143; /* gg */
    stack[-2] = nil;
    v143 = qvalue(elt(env, 1)); /* gg */
    v143 = Lreverse(nil, v143);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    stack[-3] = v143;
    goto v192;

v192:
    v143 = stack[-3];
    if (v143 == nil) goto v202;
    stack[-1] = qvalue(elt(env, 3)); /* gv */
    v143 = stack[-3];
    v143 = qcar(v143);
    stack[0] = qcar(v143);
    v190 = qvalue(elt(env, 3)); /* gv */
    v143 = stack[-3];
    v143 = qcar(v143);
    v143 = qcar(v143);
    v88 = *(Lisp_Object *)((char *)v190 + (CELL-TAG_VECTOR) + ((int32_t)v143/(16/CELL)));
    v190 = stack[-2];
    v143 = stack[-4];
    fn = elt(env, 4); /* nf */
    v143 = (*qfnn(fn))(qenv(fn), 3, v88, v190, v143);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v143;
    v143 = stack[-3];
    v190 = qcar(v143);
    v143 = stack[-2];
    v143 = cons(v190, v143);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-6];
    stack[-2] = v143;
    v143 = stack[-3];
    v143 = qcdr(v143);
    stack[-3] = v143;
    goto v192;

v202:
    v143 = nil;
    qvalue(elt(env, 1)) = stack[-5]; /* gg */
    { popv(7); return onevalue(v143); }
/* error exit handlers */
v136:
    env = stack[-6];
    qvalue(elt(env, 1)) = stack[-5]; /* gg */
    popv(7);
    return nil;
}



/* Code for pst_d */

static Lisp_Object MS_CDECL CC_pst_d(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v155, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v251, v116, v252;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pst_d");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_d");
#endif
    if (stack >= stacklimit)
    {
        push3(v155,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v155);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v155;
    stack[-9] = v1;
    stack[-2] = v0;
/* end of prologue */
    v251 = stack[-2];
    fn = elt(env, 2); /* listp */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    if (v251 == nil) goto v19;
    v251 = stack[-9];
    fn = elt(env, 2); /* listp */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    if (v251 == nil) goto v254;
    v251 = stack[-2];
    stack[-10] = v251;
    v251 = stack[-10];
    if (v251 == nil) goto v93;
    v251 = stack[-10];
    v251 = qcar(v251);
    stack[-4] = v251;
    v251 = stack[-9];
    stack[-3] = v251;
    v251 = stack[-3];
    if (v251 == nil) goto v145;
    v251 = stack[-3];
    v251 = qcar(v251);
    v252 = stack[-4];
    v116 = v251;
    v251 = stack[-8];
    v251 = CC_pst_d(env, 3, v252, v116, v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    stack[-1] = v251;
    stack[-2] = v251;
    goto v171;

v171:
    v251 = stack[-3];
    v251 = qcdr(v251);
    stack[-3] = v251;
    v251 = stack[-3];
    if (v251 == nil) goto v190;
    stack[0] = stack[-1];
    v251 = stack[-3];
    v251 = qcar(v251);
    v252 = stack[-4];
    v116 = v251;
    v251 = stack[-8];
    v251 = CC_pst_d(env, 3, v252, v116, v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = Lrplacd(nil, stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = stack[-1];
    v251 = qcdr(v251);
    stack[-1] = v251;
    goto v171;

v190:
    v251 = stack[-2];
    goto v170;

v170:
    fn = elt(env, 3); /* ordn */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    stack[-6] = v251;
    stack[-7] = v251;
    goto v164;

v164:
    v251 = stack[-10];
    v251 = qcdr(v251);
    stack[-10] = v251;
    v251 = stack[-10];
    if (v251 == nil) goto v198;
    stack[-5] = stack[-6];
    v251 = stack[-10];
    v251 = qcar(v251);
    stack[-4] = v251;
    v251 = stack[-9];
    stack[-3] = v251;
    v251 = stack[-3];
    if (v251 == nil) goto v255;
    v251 = stack[-3];
    v251 = qcar(v251);
    v252 = stack[-4];
    v116 = v251;
    v251 = stack[-8];
    v251 = CC_pst_d(env, 3, v252, v116, v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    stack[-1] = v251;
    stack[-2] = v251;
    goto v256;

v256:
    v251 = stack[-3];
    v251 = qcdr(v251);
    stack[-3] = v251;
    v251 = stack[-3];
    if (v251 == nil) goto v257;
    stack[0] = stack[-1];
    v251 = stack[-3];
    v251 = qcar(v251);
    v252 = stack[-4];
    v116 = v251;
    v251 = stack[-8];
    v251 = CC_pst_d(env, 3, v252, v116, v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = Lrplacd(nil, stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = stack[-1];
    v251 = qcdr(v251);
    stack[-1] = v251;
    goto v256;

v257:
    v251 = stack[-2];
    goto v81;

v81:
    fn = elt(env, 3); /* ordn */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = Lrplacd(nil, stack[-5], v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = stack[-6];
    v251 = qcdr(v251);
    stack[-6] = v251;
    goto v164;

v255:
    v251 = qvalue(elt(env, 1)); /* nil */
    goto v81;

v198:
    v251 = stack[-7];
    goto v162;

v162:
    {
        popv(12);
        fn = elt(env, 3); /* ordn */
        return (*qfn1(fn))(qenv(fn), v251);
    }

v145:
    v251 = qvalue(elt(env, 1)); /* nil */
    goto v170;

v93:
    v251 = qvalue(elt(env, 1)); /* nil */
    goto v162;

v254:
    v251 = stack[-2];
    stack[-3] = v251;
    v251 = stack[-3];
    if (v251 == nil) goto v108;
    v251 = stack[-3];
    v251 = qcar(v251);
    v252 = v251;
    v116 = stack[-9];
    v251 = stack[-8];
    v251 = CC_pst_d(env, 3, v252, v116, v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    stack[-1] = v251;
    stack[-2] = v251;
    goto v258;

v258:
    v251 = stack[-3];
    v251 = qcdr(v251);
    stack[-3] = v251;
    v251 = stack[-3];
    if (v251 == nil) goto v111;
    stack[0] = stack[-1];
    v251 = stack[-3];
    v251 = qcar(v251);
    v252 = v251;
    v116 = stack[-9];
    v251 = stack[-8];
    v251 = CC_pst_d(env, 3, v252, v116, v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = Lrplacd(nil, stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = stack[-1];
    v251 = qcdr(v251);
    stack[-1] = v251;
    goto v258;

v111:
    v251 = stack[-2];
    goto v259;

v259:
    {
        popv(12);
        fn = elt(env, 3); /* ordn */
        return (*qfn1(fn))(qenv(fn), v251);
    }

v108:
    v251 = qvalue(elt(env, 1)); /* nil */
    goto v259;

v19:
    v251 = stack[-9];
    fn = elt(env, 2); /* listp */
    v251 = (*qfn1(fn))(qenv(fn), v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    if (v251 == nil) goto v260;
    v251 = stack[-9];
    stack[-4] = v251;
    v251 = stack[-4];
    if (v251 == nil) goto v261;
    v251 = stack[-4];
    v251 = qcar(v251);
    v252 = stack[-2];
    v116 = v251;
    v251 = stack[-8];
    v251 = CC_pst_d(env, 3, v252, v116, v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    stack[-1] = v251;
    stack[-3] = v251;
    goto v262;

v262:
    v251 = stack[-4];
    v251 = qcdr(v251);
    stack[-4] = v251;
    v251 = stack[-4];
    if (v251 == nil) goto v263;
    stack[0] = stack[-1];
    v251 = stack[-4];
    v251 = qcar(v251);
    v252 = stack[-2];
    v116 = v251;
    v251 = stack[-8];
    v251 = CC_pst_d(env, 3, v252, v116, v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = ncons(v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = Lrplacd(nil, stack[0], v251);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-11];
    v251 = stack[-1];
    v251 = qcdr(v251);
    stack[-1] = v251;
    goto v262;

v263:
    v251 = stack[-3];
    goto v264;

v264:
    {
        popv(12);
        fn = elt(env, 3); /* ordn */
        return (*qfn1(fn))(qenv(fn), v251);
    }

v261:
    v251 = qvalue(elt(env, 1)); /* nil */
    goto v264;

v260:
    v252 = stack[-2];
    v116 = stack[-9];
    v251 = stack[-8];
    {
        popv(12);
        fn = elt(env, 4); /* pst_d1 */
        return (*qfnn(fn))(qenv(fn), 3, v252, v116, v251);
    }
/* error exit handlers */
v253:
    popv(12);
    return nil;
}



/* Code for bagp */

static Lisp_Object CC_bagp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v174;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bagp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v174 = v0;
/* end of prologue */
    v151 = v174;
    if (!consp(v151)) goto v50;
    v151 = v174;
    v151 = qcar(v151);
    v174 = elt(env, 2); /* bag */
        return Lflagp(nil, v151, v174);

v50:
    v151 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v151);
}



/* Code for dependsp */

static Lisp_Object CC_dependsp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dependsp");
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
    v256 = stack[0];
    if (v256 == nil) goto v20;
    v82 = stack[-1];
    v256 = stack[0];
    fn = elt(env, 5); /* depends */
    v256 = (*qfn2(fn))(qenv(fn), v82, v256);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-3];
    if (!(v256 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v256 = stack[-1];
    if (!consp(v256)) goto v95;
    v256 = stack[-1];
    v82 = qcar(v256);
    v256 = elt(env, 3); /* !*sq */
    if (v82 == v256) goto v96;
    v256 = stack[-1];
    fn = elt(env, 6); /* taylorp */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-3];
    if (v256 == nil) goto v188;
    v82 = stack[0];
    v256 = qvalue(elt(env, 4)); /* taylorvariable */
    if (v82 == v256) goto v178;
    v256 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v256); }

v178:
    v256 = qvalue(elt(env, 4)); /* taylorvariable */
    { popv(4); return onevalue(v256); }

v188:
    v82 = stack[-1];
    v256 = stack[0];
    if (equal(v82, v256)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v256 = stack[-1];
    stack[-2] = v256;
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-1] = v256;
    goto v207;

v207:
    v256 = stack[-1];
    if (v256 == nil) goto v266;
    v256 = stack[-1];
    v82 = qcar(v256);
    v256 = stack[0];
    v256 = CC_dependsp(env, v82, v256);
    nil = C_nil;
    if (exception_pending()) goto v182;
    env = stack[-3];
    if (!(v256 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-1] = v256;
    goto v207;

v266:
    v256 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v256); }

v96:
    v256 = stack[-1];
    v256 = qcdr(v256);
    v82 = qcar(v256);
    v256 = stack[0];
    {
        popv(4);
        fn = elt(env, 7); /* involvesq */
        return (*qfn2(fn))(qenv(fn), v82, v256);
    }

v95:
    v82 = stack[-1];
    v256 = stack[0];
    if (v82 == v256) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v256 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v256); }

v20:
    v256 = qvalue(elt(env, 1)); /* t */
    { popv(4); return onevalue(v256); }
/* error exit handlers */
v182:
    popv(4);
    return nil;
}



/* Code for bf2rn1 */

static Lisp_Object CC_bf2rn1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v281, v282, v223, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bf2rn1");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0;
/* end of prologue */
    stack[-10] = nil;
    stack[-8] = nil;
    stack[-7] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    stack[0] = nil;
    v281 = stack[-9];
    v281 = qcdr(v281);
    v282 = qcar(v281);
    v281 = (Lisp_Object)1; /* 0 */
    v281 = (Lisp_Object)lessp2(v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    v281 = v281 ? lisp_true : nil;
    env = stack[-11];
    if (v281 == nil) goto v179;
    v281 = qvalue(elt(env, 1)); /* t */
    stack[-10] = v281;
    v281 = stack[-9];
    fn = elt(env, 4); /* minus!: */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    stack[-9] = v281;
    goto v179;

v179:
    v281 = stack[-9];
    stack[-3] = v281;
    goto v202;

v202:
    v281 = stack[-9];
    v281 = qcdr(v281);
    v282 = qcar(v281);
    v281 = stack[-9];
    v281 = qcdr(v281);
    v281 = qcdr(v281);
    v62 = v282;
    v223 = v281;
    v282 = v223;
    v281 = (Lisp_Object)1; /* 0 */
    if (v282 == v281) goto v145;
    v281 = v62;
    v282 = v223;
    v281 = ash(v281, v282);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    goto v98;

v98:
    stack[-1] = v281;
    v223 = elt(env, 2); /* !:rd!: */
    v282 = stack[-1];
    v281 = (Lisp_Object)1; /* 0 */
    v281 = list2star(v223, v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    fn = elt(env, 5); /* csl_normbf */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    fn = elt(env, 6); /* difbf */
    v281 = (*qfn2(fn))(qenv(fn), stack[-9], v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    stack[-9] = v281;
    v281 = stack[-4];
    if (v281 == nil) goto v284;
    stack[-2] = stack[-8];
    v282 = stack[-1];
    v281 = stack[-7];
    v281 = times2(v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    v281 = plus2(stack[-2], v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    v282 = v281;
    v281 = stack[-7];
    stack[-8] = v281;
    v281 = v282;
    stack[-7] = v281;
    v281 = stack[0];
    stack[-2] = v281;
    stack[0] = stack[-6];
    v282 = stack[-1];
    v281 = stack[-5];
    v281 = times2(v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    v281 = plus2(stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    v282 = v281;
    v281 = stack[-5];
    stack[-6] = v281;
    v281 = v282;
    stack[-5] = v281;
    goto v131;

v131:
    stack[-1] = stack[-3];
    v223 = elt(env, 2); /* !:rd!: */
    v282 = stack[-7];
    v281 = (Lisp_Object)1; /* 0 */
    stack[0] = list2star(v223, v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    v223 = elt(env, 2); /* !:rd!: */
    v282 = stack[-5];
    v281 = (Lisp_Object)1; /* 0 */
    v282 = list2star(v223, v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    v281 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 7); /* divide!: */
    v281 = (*qfnn(fn))(qenv(fn), 3, stack[0], v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    fn = elt(env, 5); /* csl_normbf */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    fn = elt(env, 6); /* difbf */
    v281 = (*qfn2(fn))(qenv(fn), stack[-1], v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    fn = elt(env, 8); /* abs!: */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    stack[0] = v281;
    v281 = stack[-9];
    fn = elt(env, 9); /* bfzerop!: */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    if (!(v281 == nil)) goto v243;
    v281 = stack[0];
    fn = elt(env, 9); /* bfzerop!: */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    if (!(v281 == nil)) goto v243;
    v281 = stack[-2];
    if (v281 == nil) goto v242;
    v282 = stack[-2];
    v281 = stack[0];
    fn = elt(env, 10); /* greaterp!: */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    if (!(v281 == nil)) goto v242;
    v281 = stack[-10];
    if (v281 == nil) goto v285;
    v281 = stack[-8];
    v282 = negate(v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    v281 = stack[-6];
    popv(12);
    return cons(v282, v281);

v285:
    v282 = stack[-8];
    v281 = stack[-6];
    popv(12);
    return cons(v282, v281);

v242:
    v281 = stack[-9];
    fn = elt(env, 11); /* invbf */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    env = stack[-11];
    stack[-9] = v281;
    goto v202;

v243:
    v281 = stack[-10];
    if (v281 == nil) goto v286;
    v281 = stack[-7];
    v282 = negate(v281);
    nil = C_nil;
    if (exception_pending()) goto v283;
    v281 = stack[-5];
    popv(12);
    return cons(v282, v281);

v286:
    v282 = stack[-7];
    v281 = stack[-5];
    popv(12);
    return cons(v282, v281);

v284:
    v281 = qvalue(elt(env, 1)); /* t */
    stack[-4] = v281;
    v281 = (Lisp_Object)17; /* 1 */
    stack[-8] = v281;
    v281 = stack[-1];
    stack[-7] = v281;
    v281 = (Lisp_Object)1; /* 0 */
    stack[-6] = v281;
    v281 = (Lisp_Object)17; /* 1 */
    stack[-5] = v281;
    goto v131;

v145:
    v281 = v62;
    goto v98;
/* error exit handlers */
v283:
    popv(12);
    return nil;
}



/* Code for glsoleig */

static Lisp_Object MS_CDECL CC_glsoleig(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v155, Lisp_Object v12, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v287, v208, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "glsoleig");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for glsoleig");
#endif
    if (stack >= stacklimit)
    {
        push4(v12,v155,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v155,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v12;
    stack[-2] = v155;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v139 = nil;
    stack[0] = nil;
    v287 = stack[-2];
    v287 = qcar(v287);
    v287 = qcar(v287);
    stack[-5] = v287;
    goto v75;

v75:
    v287 = stack[-5];
    if (v287 == nil) goto v192;
    v287 = stack[-5];
    v208 = qcar(v287);
    v287 = stack[-4];
    if (equal(v208, v287)) goto v214;
    v287 = stack[-5];
    v208 = qcar(v287);
    v287 = stack[-3];
    v287 = Lmember(nil, v208, v287);
    if (v287 == nil) goto v137;
    v287 = stack[-5];
    v287 = qcdr(v287);
    stack[-5] = v287;
    v287 = v139;
    if (v287 == nil) goto v75;
    v287 = stack[0];
    v287 = (v287 == nil ? lisp_true : nil);
    stack[0] = v287;
    goto v75;

v137:
    v287 = v139;
    if (v287 == nil) goto v104;
    v287 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v287); }

v104:
    v287 = stack[-5];
    v287 = qcar(v287);
    v287 = ncons(v287);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    v139 = v287;
    v287 = stack[-5];
    v287 = qcdr(v287);
    stack[-5] = v287;
    goto v75;

v214:
    v287 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v287); }

v192:
    v287 = v139;
    v287 = qcar(v287);
    if (v287 == nil) goto v162;
    v287 = v139;
    v208 = qcar(v287);
    v287 = stack[-1];
    v287 = Lassoc(nil, v208, v287);
    stack[-1] = qcdr(v287);
    v287 = stack[0];
    if (v287 == nil) goto v212;
    v287 = stack[-2];
    v287 = qcar(v287);
    v287 = qcdr(v287);
    fn = elt(env, 2); /* negf */
    v287 = (*qfn1(fn))(qenv(fn), v287);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-6];
    goto v160;

v160:
    {
        Lisp_Object v184 = stack[-1];
        popv(7);
        fn = elt(env, 3); /* multf */
        return (*qfn2(fn))(qenv(fn), v184, v287);
    }

v212:
    v287 = stack[-2];
    v287 = qcar(v287);
    v287 = qcdr(v287);
    goto v160;

v162:
    v287 = stack[-2];
    v287 = qcar(v287);
    v287 = qcdr(v287);
    { popv(7); return onevalue(v287); }
/* error exit handlers */
v141:
    popv(7);
    return nil;
}



/* Code for make!-image!-lc!-list1 */

static Lisp_Object MS_CDECL CC_makeKimageKlcKlist1(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v155,
                         Lisp_Object v12, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v289, v246, v131, v132, v181;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-image-lc-list1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-image-lc-list1");
#endif
    if (stack >= stacklimit)
    {
        push3(v12,v155,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v1,v155,v12);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v246 = v12;
    stack[-1] = v155;
    v289 = v1;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v246; /* varlist */
    goto v201;

v201:
    v246 = stack[-1];
    if (v246 == nil) goto v167;
    v246 = v289;
    if (!consp(v246)) goto v95;
    v246 = v289;
    v246 = qcar(v246);
    if (!consp(v246)) goto v95;
    v246 = v289;
    v246 = qcar(v246);
    v246 = qcar(v246);
    v131 = qcar(v246);
    v246 = stack[-1];
    v246 = qcar(v246);
    v246 = qcar(v246);
    if (equal(v131, v246)) goto v176;
    v246 = stack[-1];
    v246 = qcdr(v246);
    stack[-1] = v246;
    v246 = qvalue(elt(env, 1)); /* varlist */
    v246 = qcdr(v246);
    qvalue(elt(env, 1)) = v246; /* varlist */
    goto v201;

v176:
    v181 = v289;
    v246 = stack[-1];
    v246 = qcar(v246);
    v132 = qcar(v246);
    v246 = stack[-1];
    v246 = qcar(v246);
    v131 = qcdr(v246);
    v246 = qvalue(elt(env, 3)); /* polyzero */
    v289 = qcar(v289);
    v289 = qcar(v289);
    v289 = qcdr(v289);
    fn = elt(env, 4); /* horner!-rule!-for!-one!-var */
    v246 = (*qfnn(fn))(qenv(fn), 5, v181, v132, v131, v246, v289);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v289 = qvalue(elt(env, 1)); /* varlist */
    v289 = qcdr(v289);
    v289 = cons(v246, v289);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v246 = v289;
    v246 = qcar(v246);
    if (v246 == nil) goto v265;
    stack[0] = v289;
    v131 = qcar(v289);
    v289 = stack[-1];
    v246 = qcdr(v289);
    v289 = qvalue(elt(env, 1)); /* varlist */
    v289 = qcdr(v289);
    v289 = CC_makeKimageKlcKlist1(env, 3, v131, v246, v289);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v289 = cons(stack[0], v289);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    goto v19;

v19:
    qvalue(elt(env, 1)) = stack[-2]; /* varlist */
    { popv(4); return onevalue(v289); }

v265:
    v246 = (Lisp_Object)1; /* 0 */
    v289 = qcdr(v289);
    v289 = cons(v246, v289);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v289 = ncons(v289);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    goto v19;

v95:
    fn = elt(env, 5); /* !*d2n */
    v246 = (*qfn1(fn))(qenv(fn), v289);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v289 = qvalue(elt(env, 1)); /* varlist */
    v289 = qcdr(v289);
    v289 = cons(v246, v289);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v289 = ncons(v289);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    goto v19;

v167:
    v289 = qvalue(elt(env, 2)); /* nil */
    goto v19;
/* error exit handlers */
v196:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* varlist */
    popv(4);
    return nil;
}



/* Code for bfprin0 */

static Lisp_Object CC_bfprin0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfprin0");
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
    v145 = v0;
/* end of prologue */
    stack[0] = v145;
    v145 = qvalue(elt(env, 1)); /* !:print!-prec!: */
    if (v145 == nil) goto v169;
    v145 = qvalue(elt(env, 1)); /* !:print!-prec!: */
    goto v166;

v166:
    fn = elt(env, 3); /* round!:dec1 */
    v145 = (*qfn2(fn))(qenv(fn), stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-1];
    v146 = v145;
    v146 = qcar(v146);
    v145 = qcdr(v145);
    fn = elt(env, 4); /* bfprin0x */
    v145 = (*qfn2(fn))(qenv(fn), v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v172;
    v145 = nil;
    { popv(2); return onevalue(v145); }

v169:
    v146 = qvalue(elt(env, 2)); /* !:prec!: */
    v145 = (Lisp_Object)33; /* 2 */
    v145 = difference2(v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-1];
    goto v166;
/* error exit handlers */
v172:
    popv(2);
    return nil;
}



/* Code for negdf */

static Lisp_Object CC_negdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negdf");
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
    goto v20;

v20:
    v159 = stack[-1];
    if (v159 == nil) goto v5;
    v159 = stack[-1];
    v159 = qcar(v159);
    stack[0] = qcar(v159);
    v159 = stack[-1];
    v159 = qcar(v159);
    v159 = qcdr(v159);
    fn = elt(env, 1); /* negsq */
    v160 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    v159 = stack[-2];
    v159 = acons(stack[0], v160, v159);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-3];
    stack[-2] = v159;
    v159 = stack[-1];
    v159 = qcdr(v159);
    stack[-1] = v159;
    goto v20;

v5:
    v159 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v159);
    }
/* error exit handlers */
v200:
    popv(4);
    return nil;
}



/* Code for unary */

static Lisp_Object CC_unary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unary");
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
    stack[-1] = v0;
/* end of prologue */
    v160 = elt(env, 1); /* "<apply>" */
    fn = elt(env, 6); /* printout */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-2];
    v160 = elt(env, 2); /* "<" */
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-2];
    v160 = stack[0];
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-2];
    v160 = elt(env, 3); /* "/>" */
    v160 = Lprinc(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-2];
    v210 = qvalue(elt(env, 4)); /* indent */
    v160 = (Lisp_Object)49; /* 3 */
    v160 = plus2(v210, v160);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-2];
    qvalue(elt(env, 4)) = v160; /* indent */
    v160 = stack[-1];
    v160 = qcar(v160);
    fn = elt(env, 7); /* expression */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-2];
    v210 = qvalue(elt(env, 4)); /* indent */
    v160 = (Lisp_Object)49; /* 3 */
    v160 = difference2(v210, v160);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-2];
    qvalue(elt(env, 4)) = v160; /* indent */
    v160 = elt(env, 5); /* "</apply>" */
    fn = elt(env, 6); /* printout */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v200;
    v160 = nil;
    { popv(3); return onevalue(v160); }
/* error exit handlers */
v200:
    popv(3);
    return nil;
}



/* Code for powmtch */

static Lisp_Object MS_CDECL CC_powmtch(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v155, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v92, v135, v137, v136;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "powmtch");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for powmtch");
#endif
    if (stack >= stacklimit)
    {
        push3(v155,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v155);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v156 = v155;
    v92 = v1;
    v135 = v0;
/* end of prologue */

v177:
    v137 = v92;
    if (v137 == nil) goto v4;
    v136 = v135;
    v137 = v92;
    v137 = qcar(v137);
    v137 = Latsoc(nil, v136, v137);
    v136 = v137;
    v137 = v136;
    if (v137 == nil) goto v200;
    v137 = v136;
    v136 = qcdr(v137);
    v137 = v156;
    if (equal(v136, v137)) goto v200;
    v92 = qcdr(v92);
    goto v177;

v200:
    v137 = v92;
    stack[0] = qcar(v137);
    v92 = qcdr(v92);
    v156 = CC_powmtch(env, 3, v135, v92, v156);
    nil = C_nil;
    if (exception_pending()) goto v189;
    {
        Lisp_Object v90 = stack[0];
        popv(1);
        return cons(v90, v156);
    }

v4:
    v156 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v156); }
/* error exit handlers */
v189:
    popv(1);
    return nil;
}



/* Code for groebinvokecritb */

static Lisp_Object CC_groebinvokecritb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v247, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebinvokecritb");
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
    v247 = stack[-1];
    stack[-3] = v247;
    goto v4;

v4:
    v247 = stack[-3];
    if (v247 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v247 = stack[-3];
    v247 = qcar(v247);
    stack[0] = v247;
    v247 = stack[-2];
    v247 = qcdr(v247);
    v248 = qcar(v247);
    v247 = stack[0];
    v247 = qcar(v247);
    fn = elt(env, 3); /* buchvevdivides!? */
    v247 = (*qfn2(fn))(qenv(fn), v248, v247);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    if (v247 == nil) goto v101;
    v247 = stack[-2];
    v247 = qcdr(v247);
    v248 = qcar(v247);
    v247 = stack[0];
    v247 = qcdr(v247);
    v247 = qcar(v247);
    v247 = qcdr(v247);
    v247 = qcar(v247);
    fn = elt(env, 4); /* vevlcm */
    v248 = (*qfn2(fn))(qenv(fn), v248, v247);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    v247 = stack[0];
    v247 = qcar(v247);
    if (equal(v248, v247)) goto v101;
    v247 = stack[-2];
    v247 = qcdr(v247);
    v248 = qcar(v247);
    v247 = stack[0];
    v247 = qcdr(v247);
    v247 = qcdr(v247);
    v247 = qcar(v247);
    v247 = qcdr(v247);
    v247 = qcar(v247);
    fn = elt(env, 4); /* vevlcm */
    v248 = (*qfn2(fn))(qenv(fn), v248, v247);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    v247 = stack[0];
    v247 = qcar(v247);
    if (equal(v248, v247)) goto v101;
    v247 = qvalue(elt(env, 2)); /* bcount!* */
    v247 = add1(v247);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    qvalue(elt(env, 2)) = v247; /* bcount!* */
    v248 = stack[0];
    v247 = stack[-1];
    v247 = Ldelete(nil, v248, v247);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-4];
    stack[-1] = v247;
    goto v101;

v101:
    v247 = stack[-3];
    v247 = qcdr(v247);
    stack[-3] = v247;
    goto v4;
/* error exit handlers */
v104:
    popv(5);
    return nil;
}



/* Code for vdplsortin */

static Lisp_Object CC_vdplsortin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v169, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdplsortin");
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
    stack[0] = v1;
    v169 = v0;
/* end of prologue */
    v168 = stack[0];
    if (v168 == nil) goto v20;
    v93 = v169;
    v169 = stack[0];
    v168 = stack[0];
    fn = elt(env, 1); /* vdplsortin1 */
    v168 = (*qfnn(fn))(qenv(fn), 3, v93, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v94;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v20:
    v168 = v169;
    popv(1);
    return ncons(v168);
/* error exit handlers */
v94:
    popv(1);
    return nil;
}



/* Code for quotfail */

static Lisp_Object CC_quotfail(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v191, v98, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfail");
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
    stack[-1] = v0;
/* end of prologue */
    v191 = stack[-1];
    if (v191 == nil) goto v20;
    v98 = stack[-1];
    v191 = stack[0];
    fn = elt(env, 3); /* quotf */
    v191 = (*qfn2(fn))(qenv(fn), v98, v191);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-2];
    v98 = v191;
    v191 = v98;
    if (!(v191 == nil)) { popv(3); return onevalue(v98); }
    v145 = elt(env, 2); /* "UNEXPECTED DIVISION FAILURE" */
    v98 = stack[-1];
    v191 = stack[0];
    v191 = list3(v145, v98, v191);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-2];
    fn = elt(env, 4); /* errorf */
    v191 = (*qfn1(fn))(qenv(fn), v191);
    nil = C_nil;
    if (exception_pending()) goto v172;
    v191 = nil;
    { popv(3); return onevalue(v191); }

v20:
    v191 = qvalue(elt(env, 1)); /* polyzero */
    { popv(3); return onevalue(v191); }
/* error exit handlers */
v172:
    popv(3);
    return nil;
}



/* Code for preptaylor!*!* */

static Lisp_Object CC_preptaylorHH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaylor**");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v166 = v0;
/* end of prologue */
    v180 = qvalue(elt(env, 1)); /* convert!-taylor!* */
    if (v180 == nil) return onevalue(v166);
    v180 = v166;
    {
        fn = elt(env, 2); /* preptaylor!* */
        return (*qfn1(fn))(qenv(fn), v180);
    }
}



/* Code for vp2df */

static Lisp_Object MS_CDECL CC_vp2df(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v155, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v144, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vp2df");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vp2df");
#endif
    if (stack >= stacklimit)
    {
        push3(v155,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v155);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v155;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v144 = stack[-2];
    v89 = elt(env, 1); /* sqrt */
    if (!consp(v144)) goto v158;
    v144 = qcar(v144);
    if (!(v144 == v89)) goto v158;
    v144 = stack[-1];
    v89 = (Lisp_Object)17; /* 1 */
    v89 = (Lisp_Object)greaterp2(v144, v89);
    nil = C_nil;
    if (exception_pending()) goto v136;
    v89 = v89 ? lisp_true : nil;
    env = stack[-3];
    if (v89 == nil) goto v158;
    v156 = stack[-2];
    v144 = stack[-1];
    v89 = stack[0];
    fn = elt(env, 2); /* vp1 */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v156, v144, v89);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    v89 = stack[0];
    fn = elt(env, 3); /* vp2 */
    v89 = (*qfn1(fn))(qenv(fn), v89);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    {
        Lisp_Object v161 = stack[-1];
        popv(4);
        fn = elt(env, 4); /* mulpower */
        return (*qfn2(fn))(qenv(fn), v161, v89);
    }

v158:
    v156 = stack[-2];
    v144 = stack[-1];
    v89 = stack[0];
    fn = elt(env, 2); /* vp1 */
    v156 = (*qfnn(fn))(qenv(fn), 3, v156, v144, v89);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-3];
    v144 = (Lisp_Object)17; /* 1 */
    v89 = (Lisp_Object)17; /* 1 */
    v89 = list2star(v156, v144, v89);
    nil = C_nil;
    if (exception_pending()) goto v136;
    popv(4);
    return ncons(v89);
/* error exit handlers */
v136:
    popv(4);
    return nil;
}



/* Code for canprod */

static Lisp_Object CC_canprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v301, v302, v44, v303;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for canprod");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[0] = nil;
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    v301 = stack[-3];
    if (!consp(v301)) goto v210;
    v301 = stack[-3];
    v301 = qcar(v301);
    if (!consp(v301)) goto v210;
    v301 = stack[-3];
    v301 = qcdr(v301);
    if (!(v301 == nil)) goto v210;
    v301 = stack[-4];
    if (!consp(v301)) goto v145;
    v301 = stack[-4];
    v301 = qcar(v301);
    if (!consp(v301)) goto v145;
    v301 = stack[-4];
    v301 = qcdr(v301);
    if (!(v301 == nil)) goto v210;

v145:
    v301 = stack[-4];
    if (!consp(v301)) goto v96;
    v301 = stack[-4];
    v301 = qcar(v301);
    if (!(!consp(v301))) goto v199;

v96:
    v301 = stack[-3];
    if (!consp(v301)) goto v273;
    v301 = stack[-3];
    v301 = qcar(v301);
    if (!(!consp(v301))) goto v199;

v273:
    v302 = stack[-2];
    v301 = stack[-4];
    fn = elt(env, 2); /* reprod */
    v301 = (*qfn2(fn))(qenv(fn), v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    fn = elt(env, 2); /* reprod */
    v301 = (*qfn2(fn))(qenv(fn), stack[0], v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    stack[0] = v301;
    stack[-2] = stack[-5];
    v302 = stack[-1];
    v301 = stack[-3];
    fn = elt(env, 2); /* reprod */
    v301 = (*qfn2(fn))(qenv(fn), v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    fn = elt(env, 2); /* reprod */
    v301 = (*qfn2(fn))(qenv(fn), stack[-2], v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    stack[-5] = v301;
    v301 = stack[-5];
    fn = elt(env, 3); /* minusf */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    if (v301 == nil) goto v61;
    v301 = stack[0];
    fn = elt(env, 4); /* negf */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    stack[0] = v301;
    v301 = stack[-5];
    fn = elt(env, 4); /* negf */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    stack[-5] = v301;
    goto v61;

v61:
    v302 = stack[0];
    v301 = stack[-5];
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    fn = elt(env, 5); /* cancel */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    stack[-5] = v301;
    v301 = stack[-5];
    v301 = qcar(v301);
    stack[0] = v301;
    v301 = stack[0];
    if (!consp(v301)) goto v62;
    v301 = stack[0];
    v301 = qcar(v301);
    if (!consp(v301)) goto v62;
    v301 = stack[0];
    v301 = qcdr(v301);
    if (!(v301 == nil)) goto v62;
    v301 = stack[0];
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = (Lisp_Object)17; /* 1 */
    if (!(v302 == v301)) goto v62;
    v301 = stack[0];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = (Lisp_Object)17; /* 1 */
    if (!(v302 == v301)) goto v62;
    v301 = stack[0];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    stack[-2] = v301;
    fn = elt(env, 6); /* sfp */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    if (v301 == nil) goto v62;
    v301 = stack[-2];
    stack[0] = v301;
    goto v62;

v62:
    v301 = stack[-5];
    v301 = qcdr(v301);
    stack[-5] = v301;
    v301 = stack[-5];
    if (!consp(v301)) goto v114;
    v301 = stack[-5];
    v301 = qcar(v301);
    if (!consp(v301)) goto v114;
    v301 = stack[-5];
    v301 = qcdr(v301);
    if (!(v301 == nil)) goto v114;
    v301 = stack[-5];
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = (Lisp_Object)17; /* 1 */
    if (!(v302 == v301)) goto v114;
    v301 = stack[-5];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v302 = qcdr(v301);
    v301 = (Lisp_Object)17; /* 1 */
    if (!(v302 == v301)) goto v114;
    v301 = stack[-5];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v301 = qcar(v301);
    stack[-2] = v301;
    fn = elt(env, 6); /* sfp */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    if (v301 == nil) goto v114;
    v301 = stack[-2];
    stack[-5] = v301;
    goto v114;

v114:
    v302 = stack[0];
    v301 = stack[-5];
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 7); /* canonsq */
        return (*qfn1(fn))(qenv(fn), v301);
    }

v199:
    v301 = stack[-4];
    fn = elt(env, 8); /* sfpf */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    if (v301 == nil) goto v206;
    v301 = stack[-4];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v303 = qcar(v301);
    v301 = stack[-4];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v44 = qcdr(v301);
    v302 = stack[0];
    v301 = stack[-5];
    fn = elt(env, 9); /* cprod1 */
    v301 = (*qfnn(fn))(qenv(fn), 4, v303, v44, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    v302 = v301;
    v301 = v302;
    v301 = qcar(v301);
    stack[0] = v301;
    v301 = v302;
    v301 = qcdr(v301);
    stack[-5] = v301;
    v301 = stack[-4];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    stack[-4] = v301;
    goto v145;

v206:
    v301 = stack[-3];
    fn = elt(env, 8); /* sfpf */
    v301 = (*qfn1(fn))(qenv(fn), v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    if (v301 == nil) goto v138;
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v303 = qcar(v301);
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcar(v301);
    v44 = qcdr(v301);
    v302 = stack[-5];
    v301 = stack[0];
    fn = elt(env, 9); /* cprod1 */
    v301 = (*qfnn(fn))(qenv(fn), 4, v303, v44, v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    v302 = v301;
    v301 = v302;
    v301 = qcar(v301);
    stack[-5] = v301;
    v301 = v302;
    v301 = qcdr(v301);
    stack[0] = v301;
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    stack[-3] = v301;
    goto v145;

v138:
    v301 = stack[-4];
    if (!consp(v301)) goto v181;
    v301 = stack[-4];
    v301 = qcar(v301);
    if (!consp(v301)) goto v181;
    v301 = stack[-3];
    if (!consp(v301)) goto v305;
    v301 = stack[-3];
    v301 = qcar(v301);
    if (!consp(v301)) goto v305;
    v301 = stack[-4];
    v301 = qcar(v301);
    v302 = qcar(v301);
    v301 = stack[-2];
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    stack[-2] = v301;
    v301 = stack[-3];
    v301 = qcar(v301);
    v302 = qcar(v301);
    v301 = stack[-1];
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    stack[-1] = v301;
    v301 = stack[-4];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    stack[-4] = v301;
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    stack[-3] = v301;
    goto v145;

v305:
    v301 = stack[-4];
    v301 = qcar(v301);
    v302 = qcar(v301);
    v301 = stack[-2];
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    stack[-2] = v301;
    v301 = stack[-4];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    stack[-4] = v301;
    goto v145;

v181:
    v301 = stack[-3];
    v301 = qcar(v301);
    v302 = qcar(v301);
    v301 = stack[-1];
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    stack[-1] = v301;
    v301 = stack[-3];
    v301 = qcar(v301);
    v301 = qcdr(v301);
    stack[-3] = v301;
    goto v145;

v210:
    v302 = stack[-4];
    v301 = stack[-3];
    v301 = cons(v302, v301);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 5); /* cancel */
        return (*qfn1(fn))(qenv(fn), v301);
    }
/* error exit handlers */
v304:
    popv(7);
    return nil;
}



/* Code for ps!:plus!-erule */

static Lisp_Object CC_psTplusKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:plus-erule");
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
    stack[0] = v0;
/* end of prologue */
    v173 = qvalue(elt(env, 1)); /* nil */
    v172 = (Lisp_Object)17; /* 1 */
    v172 = cons(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    v173 = v172;
    v172 = stack[0];
    v172 = qcdr(v172);
    stack[-2] = v172;
    goto v179;

v179:
    v172 = stack[-2];
    if (v172 == nil) { popv(4); return onevalue(v173); }
    v172 = stack[-2];
    v172 = qcar(v172);
    stack[0] = v173;
    v173 = v172;
    v172 = stack[-1];
    fn = elt(env, 2); /* ps!:evaluate */
    v172 = (*qfn2(fn))(qenv(fn), v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    fn = elt(env, 3); /* addsq */
    v172 = (*qfn2(fn))(qenv(fn), stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    v173 = v172;
    v172 = stack[-2];
    v172 = qcdr(v172);
    stack[-2] = v172;
    goto v179;
/* error exit handlers */
v152:
    popv(4);
    return nil;
}



/* Code for mkratnum */

static Lisp_Object CC_mkratnum(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v215, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkratnum");
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
/* copy arguments values to proper place */
    v211 = v0;
/* end of prologue */
    v152 = v211;
    if (!consp(v152)) goto v50;
    v152 = v211;
    v215 = qcar(v152);
    v152 = elt(env, 1); /* !:gi!: */
    if (v215 == v152) goto v93;
    v152 = v211;
    v215 = qcar(v152);
    v152 = elt(env, 3); /* !:rn!: */
    v152 = get(v215, v152);
    v215 = v211;
        return Lapply1(nil, v152, v215);

v93:
    v215 = elt(env, 1); /* !:gi!: */
    v152 = elt(env, 2); /* !:crn!: */
    v152 = get(v215, v152);
    v215 = v211;
        return Lapply1(nil, v152, v215);

v50:
    v152 = v211;
    {
        fn = elt(env, 4); /* !*i2rn */
        return (*qfn1(fn))(qenv(fn), v152);
    }
}



/* Code for dsimptimes */

static Lisp_Object CC_dsimptimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dsimptimes");
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
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v208 = stack[-1];
    if (v208 == nil) goto v20;
    v208 = stack[-1];
    v208 = qcdr(v208);
    if (v208 == nil) goto v202;
    v208 = stack[-1];
    v139 = qcar(v208);
    v208 = stack[0];
    fn = elt(env, 2); /* dsimp */
    v208 = (*qfn2(fn))(qenv(fn), v139, v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    stack[-4] = v208;
    v208 = stack[-1];
    v139 = qcdr(v208);
    v208 = stack[0];
    v208 = CC_dsimptimes(env, v139, v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    stack[-3] = v208;
    goto v171;

v171:
    v208 = stack[-3];
    if (v208 == nil) goto v215;
    v208 = stack[-3];
    v208 = qcar(v208);
    v139 = stack[-4];
    fn = elt(env, 3); /* mappend */
    v208 = (*qfn2(fn))(qenv(fn), v139, v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    stack[-2] = v208;
    v208 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v208 = (*qfn1(fn))(qenv(fn), v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    stack[-1] = v208;
    v208 = stack[-3];
    v208 = qcdr(v208);
    stack[-3] = v208;
    v208 = stack[-1];
    if (!consp(v208)) goto v171;
    else goto v280;

v280:
    v208 = stack[-3];
    if (v208 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v208 = stack[-3];
    v208 = qcar(v208);
    v139 = stack[-4];
    fn = elt(env, 3); /* mappend */
    v208 = (*qfn2(fn))(qenv(fn), v139, v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    v208 = Lrplacd(nil, stack[0], v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    v208 = stack[-1];
    fn = elt(env, 4); /* lastpair */
    v208 = (*qfn1(fn))(qenv(fn), v208);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-5];
    stack[-1] = v208;
    v208 = stack[-3];
    v208 = qcdr(v208);
    stack[-3] = v208;
    goto v280;

v215:
    v208 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v208); }

v202:
    v208 = stack[-1];
    v139 = qcar(v208);
    v208 = stack[0];
    {
        popv(6);
        fn = elt(env, 2); /* dsimp */
        return (*qfn2(fn))(qenv(fn), v139, v208);
    }

v20:
    v208 = elt(env, 0); /* dsimptimes */
    {
        popv(6);
        fn = elt(env, 5); /* errach */
        return (*qfn1(fn))(qenv(fn), v208);
    }
/* error exit handlers */
v209:
    popv(6);
    return nil;
}



/* Code for remove_critical_pairs */

static Lisp_Object CC_remove_critical_pairs(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove_critical_pairs");
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
    stack[0] = v1;
    v179 = v0;
/* end of prologue */
    v101 = v179;
    if (v101 == nil) { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
    v101 = stack[0];
    fn = elt(env, 1); /* remove_items */
    v179 = (*qfn2(fn))(qenv(fn), v101, v179);
    nil = C_nil;
    if (exception_pending()) goto v174;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }
/* error exit handlers */
v174:
    popv(1);
    return nil;
}



/* Code for partdff */

static Lisp_Object CC_partdff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v307, v194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partdff");
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
    stack[-4] = nil;
    goto v19;

v19:
    v307 = stack[-3];
    if (!consp(v307)) goto v308;
    v307 = stack[-3];
    v307 = qcar(v307);
    if (!consp(v307)) goto v308;
    v307 = qvalue(elt(env, 1)); /* !*product!-rule */
    if (v307 == nil) goto v128;
    v307 = stack[-3];
    v307 = qcar(v307);
    v194 = qcar(v307);
    v307 = (Lisp_Object)17; /* 1 */
    v307 = cons(v194, v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v194 = ncons(v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v307 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v194, v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v307 = stack[-3];
    v307 = qcar(v307);
    v194 = qcdr(v307);
    v307 = stack[-2];
    v307 = CC_partdff(env, v194, v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    fn = elt(env, 3); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v307 = stack[-3];
    v307 = qcar(v307);
    v194 = qcar(v307);
    v307 = stack[-2];
    fn = elt(env, 4); /* partdfpow */
    stack[0] = (*qfn2(fn))(qenv(fn), v194, v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v307 = stack[-3];
    v307 = qcar(v307);
    v194 = qcdr(v307);
    v307 = (Lisp_Object)17; /* 1 */
    v307 = cons(v194, v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    fn = elt(env, 3); /* multsq */
    v307 = (*qfn2(fn))(qenv(fn), stack[0], v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    fn = elt(env, 5); /* addsq */
    v307 = (*qfn2(fn))(qenv(fn), stack[-1], v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v194 = v307;
    goto v164;

v164:
    v307 = stack[-4];
    v307 = cons(v194, v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    stack[-4] = v307;
    v307 = stack[-3];
    v307 = qcdr(v307);
    stack[-3] = v307;
    goto v19;

v128:
    v307 = stack[-3];
    v194 = qcar(v307);
    v307 = stack[-2];
    fn = elt(env, 6); /* partdft */
    v307 = (*qfn2(fn))(qenv(fn), v194, v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v194 = v307;
    goto v164;

v308:
    v194 = qvalue(elt(env, 2)); /* nil */
    v307 = (Lisp_Object)17; /* 1 */
    v307 = cons(v194, v307);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v194 = v307;
    goto v27;

v27:
    v307 = stack[-4];
    if (v307 == nil) { popv(6); return onevalue(v194); }
    v307 = stack[-4];
    v307 = qcar(v307);
    fn = elt(env, 5); /* addsq */
    v307 = (*qfn2(fn))(qenv(fn), v307, v194);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-5];
    v194 = v307;
    v307 = stack[-4];
    v307 = qcdr(v307);
    stack[-4] = v307;
    goto v27;
/* error exit handlers */
v133:
    popv(6);
    return nil;
}



/* Code for p_eq_vertex */

static Lisp_Object CC_p_eq_vertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v200, v170, v171;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for p_eq_vertex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v200 = v1;
    v170 = v0;
/* end of prologue */

v20:
    v197 = v170;
    if (v197 == nil) goto v5;
    v197 = v200;
    if (v197 == nil) goto v166;
    v197 = v170;
    v197 = qcar(v197);
    v171 = qcar(v197);
    v197 = v200;
    v197 = qcar(v197);
    v197 = qcar(v197);
    if (v171 == v197) goto v179;
    v197 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v197);

v179:
    v197 = v170;
    v197 = qcdr(v197);
    v170 = v197;
    v197 = v200;
    v197 = qcdr(v197);
    v200 = v197;
    goto v20;

v166:
    v197 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v197);

v5:
    v197 = v200;
    v197 = (v197 == nil ? lisp_true : nil);
    return onevalue(v197);
}



/* Code for mod!* */

static Lisp_Object CC_modH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod*");
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
    v200 = stack[0];
    fn = elt(env, 2); /* dpmat_coldegs */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-3];
    stack[-2] = qvalue(elt(env, 1)); /* cali!=degrees */
    qvalue(elt(env, 1)) = v200; /* cali!=degrees */
    v200 = stack[-1];
    fn = elt(env, 3); /* dp_neworder */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[-1] = v200;
    v200 = stack[0];
    fn = elt(env, 4); /* dpmat_list */
    stack[0] = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v170 = (Lisp_Object)1; /* 0 */
    v200 = stack[-1];
    fn = elt(env, 5); /* bas_make */
    v200 = (*qfn2(fn))(qenv(fn), v170, v200);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    fn = elt(env, 6); /* red_redpol */
    v200 = (*qfn2(fn))(qenv(fn), stack[0], v200);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    stack[0] = v200;
    v200 = stack[0];
    v200 = qcar(v200);
    fn = elt(env, 7); /* bas_dpoly */
    v170 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v200 = stack[0];
    v200 = qcdr(v200);
    v200 = cons(v170, v200);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* cali!=degrees */
    { popv(4); return onevalue(v200); }
/* error exit handlers */
v145:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* cali!=degrees */
    popv(4);
    return nil;
v98:
    popv(4);
    return nil;
}



/* Code for r2flbf */

static Lisp_Object CC_r2flbf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2flbf");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v167 = v0;
/* end of prologue */
    v166 = qvalue(elt(env, 1)); /* !*bftag */
    if (v166 == nil) goto v27;
    v166 = v167;
    {
        fn = elt(env, 2); /* r2bf */
        return (*qfn1(fn))(qenv(fn), v166);
    }

v27:
    v166 = v167;
    {
        fn = elt(env, 3); /* r2fl */
        return (*qfn1(fn))(qenv(fn), v166);
    }
}



/* Code for evaluate!-in!-vector */

static Lisp_Object MS_CDECL CC_evaluateKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v155, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v211, v212, v157, v158, v129;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push3(v155,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v155);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v157 = v155;
    v212 = v1;
    v158 = v0;
/* end of prologue */
    v211 = v158;
    v215 = v212;
    v215 = *(Lisp_Object *)((char *)v211 + (CELL-TAG_VECTOR) + ((int32_t)v215/(16/CELL)));
    v211 = v215;
    v215 = v212;
    v215 = (Lisp_Object)((int32_t)(v215) - 0x10);
    v129 = v215;
    goto v101;

v101:
    v215 = v129;
    v215 = ((intptr_t)(v215) < 0 ? lisp_true : nil);
    if (!(v215 == nil)) { popv(1); return onevalue(v211); }
    v212 = v158;
    v215 = v129;
    v212 = *(Lisp_Object *)((char *)v212 + (CELL-TAG_VECTOR) + ((int32_t)v215/(16/CELL)));
    v215 = v157;
    v215 = Lmodular_times(nil, v211, v215);
    env = stack[0];
    {   int32_t w = int_of_fixnum(v212) + int_of_fixnum(v215);
        if (w >= current_modulus) w -= current_modulus;
        v215 = fixnum_of_int(w);
    }
    v211 = v215;
    v215 = v129;
    v215 = (Lisp_Object)((int32_t)(v215) - 0x10);
    v129 = v215;
    goto v101;
}



/* Code for read!-comment1 */

static Lisp_Object CC_readKcomment1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for read-comment1");
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
    v94 = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* !*lower */
    qvalue(elt(env, 1)) = nil; /* !*lower */
    v94 = qvalue(elt(env, 2)); /* !*raise */
    stack[0] = v94;
    v94 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 2)) = v94; /* !*raise */
    goto v4;

v4:
    v94 = qvalue(elt(env, 4)); /* crchar!* */
    fn = elt(env, 7); /* delcp */
    v94 = (*qfn1(fn))(qenv(fn), v94);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    if (v94 == nil) goto v201;
    v87 = qvalue(elt(env, 4)); /* crchar!* */
    v94 = qvalue(elt(env, 5)); /* !$eol!$ */
    if (v87 == v94) goto v201;
    v94 = elt(env, 6); /* !  */
    qvalue(elt(env, 4)) = v94; /* crchar!* */
    v94 = stack[0];
    qvalue(elt(env, 2)) = v94; /* !*raise */
    fn = elt(env, 8); /* condterpri */
    v94 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    v94 = nil;
    qvalue(elt(env, 1)) = stack[-1]; /* !*lower */
    { popv(3); return onevalue(v94); }

v201:
    fn = elt(env, 9); /* readch1 */
    v94 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-2];
    qvalue(elt(env, 4)) = v94; /* crchar!* */
    goto v4;
/* error exit handlers */
v193:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* !*lower */
    popv(3);
    return nil;
}



/* Code for checkcoeffts */

static Lisp_Object CC_checkcoeffts(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkcoeffts");
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
    stack[-1] = v0;
/* end of prologue */

v177:
    v97 = stack[-1];
    if (v97 == nil) goto v20;
    v97 = stack[-1];
    v97 = qcar(v97);
    v153 = qcar(v97);
    v97 = stack[0];
    fn = elt(env, 3); /* evaluatecoeffts */
    v97 = (*qfn2(fn))(qenv(fn), v153, v97);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v153 = v97;
    v97 = v153;
    if (v97 == nil) goto v191;
    v97 = (Lisp_Object)1; /* 0 */
    if (v153 == v97) goto v191;
    v97 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v97); }

v191:
    v97 = stack[-1];
    v153 = qcdr(v97);
    v97 = stack[0];
    stack[-1] = v153;
    stack[0] = v97;
    goto v177;

v20:
    v97 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v97); }
/* error exit handlers */
v211:
    popv(3);
    return nil;
}



/* Code for addto!-all!-taytpelorders */

static Lisp_Object CC_addtoKallKtaytpelorders(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v156, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addto-all-taytpelorders");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    goto v4;

v4:
    v156 = stack[-4];
    if (v156 == nil) goto v27;
    v156 = stack[-4];
    v156 = qcar(v156);
    stack[-2] = qcar(v156);
    v156 = stack[-4];
    v156 = qcar(v156);
    v156 = qcdr(v156);
    stack[-1] = qcar(v156);
    v156 = stack[-4];
    v156 = qcar(v156);
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v92 = qcar(v156);
    v156 = stack[-3];
    v156 = qcar(v156);
    fn = elt(env, 1); /* tayexp!-plus2 */
    stack[0] = (*qfn2(fn))(qenv(fn), v92, v156);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-6];
    v156 = stack[-4];
    v156 = qcar(v156);
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v156 = qcdr(v156);
    v92 = qcar(v156);
    v156 = stack[-3];
    v156 = qcar(v156);
    fn = elt(env, 1); /* tayexp!-plus2 */
    v156 = (*qfn2(fn))(qenv(fn), v92, v156);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-6];
    v92 = list4(stack[-2], stack[-1], stack[0], v156);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-6];
    v156 = stack[-5];
    v156 = cons(v92, v156);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[-6];
    stack[-5] = v156;
    v156 = stack[-4];
    v156 = qcdr(v156);
    stack[-4] = v156;
    v156 = stack[-3];
    v156 = qcdr(v156);
    stack[-3] = v156;
    goto v4;

v27:
    v156 = stack[-5];
    {
        popv(7);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v156);
    }
/* error exit handlers */
v91:
    popv(7);
    return nil;
}



setup_type const u44_setup[] =
{
    {"dv_skelsplit1",           too_few_2,      CC_dv_skelsplit1,wrong_no_2},
    {"reduce-mod-eig",          too_few_2,      CC_reduceKmodKeig,wrong_no_2},
    {"spreadvar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_spreadvar},
    {"deg",                     too_few_2,      CC_deg,        wrong_no_2},
    {"sfto_lmultf",             CC_sfto_lmultf, too_many_1,    wrong_no_1},
    {"exceeds-order-variant",   too_few_2,      CC_exceedsKorderKvariant,wrong_no_2},
    {"available*p",             CC_availableHp, too_many_1,    wrong_no_1},
    {"makevar",                 too_few_2,      CC_makevar,    wrong_no_2},
    {"cl_cxfp",                 CC_cl_cxfp,     too_many_1,    wrong_no_1},
    {"applyml",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_applyml},
    {"pm:gensym",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pmTgensym},
    {"exdfpf",                  CC_exdfpf,      too_many_1,    wrong_no_1},
    {"cr:prep",                 CC_crTprep,     too_many_1,    wrong_no_1},
    {"tvectorp",                CC_tvectorp,    too_many_1,    wrong_no_1},
    {"new_provev",              too_few_2,      CC_new_provev, wrong_no_2},
    {"compactf3",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf3},
    {"dp=prod",                 too_few_2,      CC_dpMprod,    wrong_no_2},
    {"newbasis",                too_few_2,      CC_newbasis,   wrong_no_2},
    {"pst_d",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_pst_d},
    {"bagp",                    CC_bagp,        too_many_1,    wrong_no_1},
    {"dependsp",                too_few_2,      CC_dependsp,   wrong_no_2},
    {"bf2rn1",                  CC_bf2rn1,      too_many_1,    wrong_no_1},
    {"glsoleig",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_glsoleig},
    {"make-image-lc-list1",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKimageKlcKlist1},
    {"bfprin0",                 CC_bfprin0,     too_many_1,    wrong_no_1},
    {"negdf",                   CC_negdf,       too_many_1,    wrong_no_1},
    {"unary",                   too_few_2,      CC_unary,      wrong_no_2},
    {"powmtch",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_powmtch},
    {"groebinvokecritb",        too_few_2,      CC_groebinvokecritb,wrong_no_2},
    {"vdplsortin",              too_few_2,      CC_vdplsortin, wrong_no_2},
    {"quotfail",                too_few_2,      CC_quotfail,   wrong_no_2},
    {"preptaylor**",            CC_preptaylorHH,too_many_1,    wrong_no_1},
    {"vp2df",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_vp2df},
    {"canprod",                 too_few_2,      CC_canprod,    wrong_no_2},
    {"ps:plus-erule",           too_few_2,      CC_psTplusKerule,wrong_no_2},
    {"mkratnum",                CC_mkratnum,    too_many_1,    wrong_no_1},
    {"dsimptimes",              too_few_2,      CC_dsimptimes, wrong_no_2},
    {"remove_critical_pairs",   too_few_2,      CC_remove_critical_pairs,wrong_no_2},
    {"partdff",                 too_few_2,      CC_partdff,    wrong_no_2},
    {"p_eq_vertex",             too_few_2,      CC_p_eq_vertex,wrong_no_2},
    {"mod*",                    too_few_2,      CC_modH,       wrong_no_2},
    {"r2flbf",                  CC_r2flbf,      too_many_1,    wrong_no_1},
    {"evaluate-in-vector",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluateKinKvector},
    {"read-comment1",           CC_readKcomment1,too_many_1,   wrong_no_1},
    {"checkcoeffts",            too_few_2,      CC_checkcoeffts,wrong_no_2},
    {"addto-all-taytpelorders", too_few_2,      CC_addtoKallKtaytpelorders,wrong_no_2},
    {NULL, (one_args *)"u44", (two_args *)"7797 4730534 5868648", 0}
};

/* end of generated code */
