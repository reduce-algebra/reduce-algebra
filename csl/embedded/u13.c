
/* $destdir/generated-c\u13.c Machine generated C code */

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


/* Code for nzeros */

static Lisp_Object CC_nzeros(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nzeros");
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
    goto v8;

v8:
    v7 = stack[0];
    v6 = (Lisp_Object)1; /* 0 */
    if (v7 == v6) goto v9;
    v7 = (Lisp_Object)1; /* 0 */
    v6 = stack[-1];
    v6 = cons(v7, v6);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    stack[-1] = v6;
    v6 = stack[0];
    v6 = sub1(v6);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    stack[0] = v6;
    goto v8;

v9:
    v6 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v6);
    }
/* error exit handlers */
v10:
    popv(3);
    return nil;
}



/* Code for pv_times1 */

static Lisp_Object MS_CDECL CC_pv_times1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pv_times1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times1");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v11,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v7 = v3;
    stack[0] = v11;
    v6 = v0;
/* end of prologue */

v15:
    v14 = v6;
    if (v14 == nil) { popv(3); return onevalue(v7); }
    v14 = v6;
    v14 = qcdr(v14);
    stack[-1] = v14;
    v14 = qcar(v6);
    v6 = stack[0];
    fn = elt(env, 1); /* pv_times2 */
    v6 = (*qfnn(fn))(qenv(fn), 3, v14, v6, v7);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    v7 = v6;
    v6 = stack[-1];
    goto v15;
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for raiseind!: */

static Lisp_Object CC_raiseindT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for raiseind:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v17 = v0;
/* end of prologue */
    v18 = v17;
    if (!consp(v18)) return onevalue(v17);
    v17 = qcdr(v17);
    v17 = qcar(v17);
    return onevalue(v17);
}



/* Code for ord2 */

static Lisp_Object CC_ord2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ord2");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */
    v21 = stack[-1];
    v14 = stack[0];
    fn = elt(env, 1); /* ordp */
    v14 = (*qfn2(fn))(qenv(fn), v21, v14);
    nil = C_nil;
    if (exception_pending()) goto v22;
    if (v14 == nil) goto v23;
    v21 = stack[-1];
    v14 = stack[0];
    popv(2);
    return list2(v21, v14);

v23:
    v21 = stack[0];
    v14 = stack[-1];
    popv(2);
    return list2(v21, v14);
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for findremainder */

static Lisp_Object CC_findremainder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v16, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findremainder");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v10 = v11;
    v16 = v0;
/* end of prologue */
    stack[0] = v10;
    goto v27;

v27:
    v10 = stack[0];
    if (v10 == nil) { popv(2); return onevalue(v16); }
    v10 = stack[0];
    v10 = qcar(v10);
    v22 = v16;
    v16 = v10;
    v10 = qcar(v10);
    v10 = qcar(v10);
    v10 = qcar(v10);
    fn = elt(env, 2); /* wupseudodivide */
    v10 = (*qfnn(fn))(qenv(fn), 3, v22, v16, v10);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    v10 = qcdr(v10);
    v16 = v10;
    v10 = stack[0];
    v10 = qcdr(v10);
    stack[0] = v10;
    goto v27;
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for freevarinexptchk */

static Lisp_Object CC_freevarinexptchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freevarinexptchk");
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

v29:
    v6 = stack[0];
    if (!consp(v6)) goto v13;
    v6 = stack[0];
    v6 = qcar(v6);
    if (!consp(v6)) goto v13;
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = qcar(v6);
    v6 = qcdr(v6);
    v6 = (is_number(v6) ? lisp_true : nil);
    v6 = (v6 == nil ? lisp_true : nil);
    if (!(v6 == nil)) { popv(2); return onevalue(v6); }
    v6 = stack[0];
    v6 = qcar(v6);
    v6 = qcdr(v6);
    v6 = CC_freevarinexptchk(env, v6);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-1];
    if (!(v6 == nil)) { popv(2); return onevalue(v6); }
    v6 = stack[0];
    v6 = qcdr(v6);
    stack[0] = v6;
    goto v29;

v13:
    v6 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v6); }
/* error exit handlers */
v14:
    popv(2);
    return nil;
}



/* Code for rl_simpbop */

static Lisp_Object CC_rl_simpbop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpbop");
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
    v36 = v0;
/* end of prologue */
    v35 = v36;
    stack[-4] = qcar(v35);
    v35 = v36;
    v35 = qcdr(v35);
    stack[-3] = v35;
    v35 = stack[-3];
    if (v35 == nil) goto v37;
    v35 = stack[-3];
    v35 = qcar(v35);
    fn = elt(env, 2); /* rl_simp1 */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    stack[-1] = v35;
    stack[-2] = v35;
    goto v4;

v4:
    v35 = stack[-3];
    v35 = qcdr(v35);
    stack[-3] = v35;
    v35 = stack[-3];
    if (v35 == nil) goto v21;
    stack[0] = stack[-1];
    v35 = stack[-3];
    v35 = qcar(v35);
    fn = elt(env, 2); /* rl_simp1 */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    v35 = Lrplacd(nil, stack[0], v35);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-5];
    v35 = stack[-1];
    v35 = qcdr(v35);
    stack[-1] = v35;
    goto v4;

v21:
    v35 = stack[-2];
    goto v27;

v27:
    {
        Lisp_Object v39 = stack[-4];
        popv(6);
        return cons(v39, v35);
    }

v37:
    v35 = qvalue(elt(env, 1)); /* nil */
    goto v27;
/* error exit handlers */
v38:
    popv(6);
    return nil;
}



/* Code for find_sub_df */

static Lisp_Object CC_find_sub_df(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_sub_df");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */

v29:
    v7 = stack[0];
    if (v7 == nil) goto v40;
    v14 = stack[-1];
    v7 = stack[0];
    v7 = qcar(v7);
    fn = elt(env, 2); /* is_sub_df */
    v7 = (*qfn2(fn))(qenv(fn), v14, v7);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    if (!(v7 == nil)) { popv(3); return onevalue(v7); }
    v14 = stack[-1];
    v7 = stack[0];
    v7 = qcdr(v7);
    stack[-1] = v14;
    stack[0] = v7;
    goto v29;

v40:
    v7 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v7); }
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for revalx */

static Lisp_Object CC_revalx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revalx");
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
    v42 = v0;
/* end of prologue */
    v41 = v42;
    if (!consp(v41)) goto v18;
    v41 = v42;
    v41 = qcar(v41);
    if (!consp(v41)) goto v18;
    v41 = v42;
    fn = elt(env, 1); /* prepf */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[0];
    goto v13;

v13:
    {
        popv(1);
        fn = elt(env, 2); /* reval */
        return (*qfn1(fn))(qenv(fn), v41);
    }

v18:
    v41 = v42;
    goto v13;
/* error exit handlers */
v43:
    popv(1);
    return nil;
}



/* Code for simpindexvar */

static Lisp_Object CC_simpindexvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpindexvar");
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
    v40 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitindexvar */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v40);
    }
/* error exit handlers */
v27:
    popv(1);
    return nil;
}



/* Code for cstimes */

static Lisp_Object CC_cstimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39, v48, v49;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cstimes");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v39 = v11;
    v48 = v0;
/* end of prologue */

v27:
    v38 = v48;
    if (v38 == nil) goto v30;
    v38 = v48;
    v49 = qcar(v38);
    v38 = (Lisp_Object)17; /* 1 */
    if (v49 == v38) goto v21;
    v38 = v48;
    v38 = qcdr(v38);
    stack[0] = v38;
    v38 = v48;
    v38 = qcar(v38);
    v38 = cons(v38, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v39 = v38;
    v38 = stack[0];
    v48 = v38;
    goto v27;

v21:
    v38 = v48;
    v38 = qcdr(v38);
    v48 = v38;
    goto v27;

v30:
    v38 = v39;
    if (v38 == nil) goto v18;
    v38 = v39;
    v38 = qcdr(v38);
    if (v38 == nil) goto v42;
    v38 = elt(env, 1); /* times */
    popv(2);
    return cons(v38, v39);

v42:
    v38 = v39;
    v38 = qcar(v38);
    { popv(2); return onevalue(v38); }

v18:
    v38 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v38); }
/* error exit handlers */
v50:
    popv(2);
    return nil;
}



/* Code for mo_from_a */

static Lisp_Object CC_mo_from_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_from_a");
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
    stack[-3] = v0;
/* end of prologue */
    stack[0] = stack[-3];
    v61 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v61 = Lmember(nil, stack[0], v61);
    if (v61 == nil) goto v5;
    v61 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[-4] = v61;
    v61 = stack[-4];
    if (v61 == nil) goto v64;
    v61 = stack[-4];
    v61 = qcar(v61);
    v62 = v61;
    v61 = stack[-3];
    if (equal(v62, v61)) goto v65;
    v61 = (Lisp_Object)1; /* 0 */
    goto v66;

v66:
    v61 = ncons(v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[-1] = v61;
    stack[-2] = v61;
    goto v10;

v10:
    v61 = stack[-4];
    v61 = qcdr(v61);
    stack[-4] = v61;
    v61 = stack[-4];
    if (v61 == nil) goto v67;
    stack[0] = stack[-1];
    v61 = stack[-4];
    v61 = qcar(v61);
    v62 = v61;
    v61 = stack[-3];
    if (equal(v62, v61)) goto v68;
    v61 = (Lisp_Object)1; /* 0 */
    goto v69;

v69:
    v61 = ncons(v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v61 = Lrplacd(nil, stack[0], v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[-1] = v61;
    goto v10;

v68:
    v61 = (Lisp_Object)17; /* 1 */
    goto v69;

v67:
    v61 = stack[-2];
    goto v21;

v21:
    fn = elt(env, 5); /* mo!=shorten */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[0] = v61;
    fn = elt(env, 6); /* mo!=deglist */
    v61 = (*qfn1(fn))(qenv(fn), v61);
    nil = C_nil;
    if (exception_pending()) goto v63;
    {
        Lisp_Object v70 = stack[0];
        popv(6);
        return cons(v70, v61);
    }

v65:
    v61 = (Lisp_Object)17; /* 1 */
    goto v66;

v64:
    v61 = qvalue(elt(env, 3)); /* nil */
    goto v21;

v5:
    v62 = stack[-3];
    v61 = elt(env, 2); /* "dpoly variable" */
    {
        popv(6);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v62, v61);
    }
/* error exit handlers */
v63:
    popv(6);
    return nil;
}



/* Code for ibalp_simpatom */

static Lisp_Object CC_ibalp_simpatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpatom");
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
    v52 = stack[0];
    v80 = (Lisp_Object)1; /* 0 */
    if (v52 == v80) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v52 = stack[0];
    v80 = (Lisp_Object)17; /* 1 */
    if (v52 == v80) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v80 = stack[0];
    if (symbolp(v80)) goto v2;
    v80 = stack[0];
    if (!(v80 == nil)) goto v81;
    v52 = elt(env, 2); /* "nil" */
    v80 = elt(env, 3); /* "Boolean term" */
    fn = elt(env, 6); /* typerr */
    v80 = (*qfn2(fn))(qenv(fn), v52, v80);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    goto v81;

v81:
    v80 = stack[0];
    if (!(is_number(v80))) goto v83;
    v52 = elt(env, 4); /* "number" */
    v80 = stack[0];
    v52 = list2(v52, v80);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    v80 = elt(env, 3); /* "Boolean term" */
    fn = elt(env, 6); /* typerr */
    v80 = (*qfn2(fn))(qenv(fn), v52, v80);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    goto v83;

v83:
    v80 = stack[0];
    v80 = Lstringp(nil, v80);
    env = stack[-1];
    if (v80 == nil) goto v68;
    v52 = elt(env, 5); /* "string" */
    v80 = stack[0];
    v52 = list2(v52, v80);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    v80 = elt(env, 3); /* "Boolean term" */
    fn = elt(env, 6); /* typerr */
    v80 = (*qfn2(fn))(qenv(fn), v52, v80);
    nil = C_nil;
    if (exception_pending()) goto v82;
    goto v68;

v68:
    v80 = nil;
    { popv(2); return onevalue(v80); }

v2:
    v80 = stack[0];
    fn = elt(env, 7); /* rl_gettype */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    if (v80 == nil) goto v84;
    v80 = stack[0];
    fn = elt(env, 8); /* reval */
    v80 = (*qfn1(fn))(qenv(fn), v80);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 9); /* ibalp_simpterm */
        return (*qfn1(fn))(qenv(fn), v80);
    }

v84:
    v80 = stack[0];
    v52 = ncons(v80);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-1];
    v80 = elt(env, 1); /* used!* */
    v80 = Lflag(nil, v52, v80);
    nil = C_nil;
    if (exception_pending()) goto v82;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v82:
    popv(2);
    return nil;
}



/* Code for mathml2 */

static Lisp_Object MS_CDECL CC_mathml2(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mathml2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mathml2");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    {
        fn = elt(env, 2); /* sub_math */
        return (*qfnn(fn))(qenv(fn), 0);
    }
}



/* Code for numeric!-content */

static Lisp_Object CC_numericKcontent(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numeric-content");
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

v13:
    v36 = stack[0];
    if (!consp(v36)) goto v15;
    v36 = stack[0];
    v36 = qcar(v36);
    if (!consp(v36)) goto v15;
    v36 = stack[0];
    v36 = qcdr(v36);
    if (v36 == nil) goto v5;
    v36 = stack[0];
    v36 = qcar(v36);
    v36 = qcdr(v36);
    v36 = CC_numericKcontent(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v86 = v36;
    v85 = v86;
    v36 = (Lisp_Object)17; /* 1 */
    if (v85 == v36) { popv(3); return onevalue(v86); }
    stack[-1] = v86;
    v36 = stack[0];
    v36 = qcdr(v36);
    v36 = CC_numericKcontent(env, v36);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    fn = elt(env, 1); /* gcddd */
    v36 = (*qfn2(fn))(qenv(fn), stack[-1], v36);
    nil = C_nil;
    if (exception_pending()) goto v87;
    v86 = v36;
    { popv(3); return onevalue(v86); }

v5:
    v36 = stack[0];
    v36 = qcar(v36);
    v36 = qcdr(v36);
    stack[0] = v36;
    goto v13;

v15:
    v36 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* absf */
        return (*qfn1(fn))(qenv(fn), v36);
    }
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for primep */

static Lisp_Object CC_primep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for primep");
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

v13:
    v97 = stack[0];
    v97 = integerp(v97);
    if (v97 == nil) goto v33;
    v98 = stack[0];
    v97 = (Lisp_Object)1; /* 0 */
    v97 = (Lisp_Object)lessp2(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v99;
    v97 = v97 ? lisp_true : nil;
    env = stack[-2];
    if (v97 == nil) goto v14;
    v97 = stack[0];
    v97 = negate(v97);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    stack[0] = v97;
    goto v13;

v14:
    v98 = stack[0];
    v97 = (Lisp_Object)17; /* 1 */
    if (v98 == v97) goto v6;
    v98 = stack[0];
    v97 = qvalue(elt(env, 3)); /* !*last!-prime!-in!-list!* */
    v97 = (Lisp_Object)lesseq2(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v99;
    v97 = v97 ? lisp_true : nil;
    env = stack[-2];
    if (v97 == nil) goto v48;
    v97 = stack[0];
    v98 = qvalue(elt(env, 4)); /* !*primelist!* */
    v97 = Lmember(nil, v97, v98);
    { popv(3); return onevalue(v97); }

v48:
    v98 = stack[0];
    v97 = qvalue(elt(env, 5)); /* !*last!-prime!-squared!* */
    v97 = (Lisp_Object)lesseq2(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v99;
    v97 = v97 ? lisp_true : nil;
    env = stack[-2];
    if (v97 == nil) goto v51;
    v97 = qvalue(elt(env, 4)); /* !*primelist!* */
    stack[-1] = v97;
    goto v100;

v100:
    v97 = stack[-1];
    if (v97 == nil) goto v75;
    v98 = stack[0];
    v97 = stack[-1];
    v97 = qcar(v97);
    v98 = Cremainder(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-2];
    v97 = (Lisp_Object)1; /* 0 */
    if (v98 == v97) goto v75;
    v97 = stack[-1];
    v97 = qcdr(v97);
    stack[-1] = v97;
    goto v100;

v75:
    v97 = stack[-1];
    v97 = (v97 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v97); }

v51:
    v98 = stack[0];
    v97 = qvalue(elt(env, 6)); /* largest!-small!-modulus */
    v97 = (Lisp_Object)greaterp2(v98, v97);
    nil = C_nil;
    if (exception_pending()) goto v99;
    v97 = v97 ? lisp_true : nil;
    env = stack[-2];
    if (v97 == nil) goto v63;
    v97 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* general!-primep */
        return (*qfn1(fn))(qenv(fn), v97);
    }

v63:
    v97 = stack[0];
    {
        popv(3);
        fn = elt(env, 8); /* small!-primep */
        return (*qfn1(fn))(qenv(fn), v97);
    }

v6:
    v97 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v97); }

v33:
    v98 = stack[0];
    v97 = elt(env, 1); /* "integer" */
    {
        popv(3);
        fn = elt(env, 9); /* typerr */
        return (*qfn2(fn))(qenv(fn), v98, v97);
    }
/* error exit handlers */
v99:
    popv(3);
    return nil;
}



/* Code for exptcompare */

static Lisp_Object CC_exptcompare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v84, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptcompare");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v84 = v11;
    v46 = v0;
/* end of prologue */
    v64 = v46;
    if (!consp(v64)) goto v40;
    v64 = v84;
    if (!consp(v64)) goto v78;
    v64 = v46;
    v64 = qcar(v64);
    v84 = qcar(v84);
        return Lgreaterp(nil, v64, v84);

v78:
    v64 = qvalue(elt(env, 2)); /* t */
    return onevalue(v64);

v40:
    v64 = v84;
    if (!consp(v64)) goto v18;
    v64 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v64);

v18:
    v64 = v46;
        return Lgreaterp(nil, v64, v84);
}



/* Code for constsml */

static Lisp_Object CC_constsml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constsml");
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
    v68 = stack[0];
    if (!(is_number(v68))) goto v40;
    v68 = elt(env, 1); /* "<cn" */
    fn = elt(env, 13); /* printout */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v68 = stack[0];
    v68 = Lfloatp(nil, v68);
    env = stack[-1];
    if (v68 == nil) goto v18;
    v68 = elt(env, 2); /* " type=""real""> " */
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    goto v33;

v33:
    v68 = stack[0];
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v68 = elt(env, 5); /* " </cn>" */
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    goto v40;

v40:
    v68 = stack[0];
    if (!(symbolp(v68))) goto v21;
    v68 = stack[0];
    v101 = Lintern(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v68 = qvalue(elt(env, 6)); /* constants!* */
    v68 = Lmember(nil, v101, v68);
    if (v68 == nil) goto v44;
    v68 = elt(env, 7); /* "<cn type=""constant""> " */
    fn = elt(env, 13); /* printout */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v68 = stack[0];
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v68 = elt(env, 5); /* " </cn>" */
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    goto v21;

v21:
    v68 = nil;
    { popv(2); return onevalue(v68); }

v44:
    v68 = elt(env, 8); /* "<ci" */
    fn = elt(env, 13); /* printout */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v68 = stack[0];
    fn = elt(env, 14); /* listp */
    v68 = (*qfn1(fn))(qenv(fn), v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    if (v68 == nil) goto v83;
    v68 = elt(env, 9); /* " type=""list""> " */
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    goto v48;

v48:
    v68 = stack[0];
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v68 = elt(env, 11); /* " </ci>" */
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    goto v21;

v83:
    v68 = stack[0];
    v68 = Lsimple_vectorp(nil, v68);
    env = stack[-1];
    if (v68 == nil) goto v100;
    v68 = elt(env, 10); /* " type=""vector""> " */
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    goto v48;

v100:
    v68 = elt(env, 4); /* "> " */
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    goto v48;

v18:
    v68 = stack[0];
    v68 = integerp(v68);
    if (v68 == nil) goto v25;
    v68 = elt(env, 3); /* " type=""integer""> " */
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    goto v33;

v25:
    v68 = elt(env, 4); /* "> " */
    v68 = Lprinc(nil, v68);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    goto v33;
/* error exit handlers */
v102:
    popv(2);
    return nil;
}



/* Code for vdpred */

static Lisp_Object CC_vdpred(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpred");
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
    stack[-3] = v0;
/* end of prologue */
    v90 = stack[-3];
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v90 = qcar(v90);
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    stack[-4] = v90;
    v90 = stack[-4];
    if (v90 == nil) goto v43;
    stack[-2] = elt(env, 1); /* vdp */
    v90 = stack[-4];
    stack[-1] = qcar(v90);
    v90 = stack[-4];
    v90 = qcdr(v90);
    stack[0] = qcar(v90);
    v105 = stack[-4];
    v90 = qvalue(elt(env, 2)); /* nil */
    v90 = list2(v105, v90);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v90 = list3star(stack[-2], stack[-1], stack[0], v90);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    stack[-4] = v90;
    v90 = qvalue(elt(env, 3)); /* !*gsugar */
    if (v90 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v105 = stack[-3];
    v90 = elt(env, 4); /* sugar */
    fn = elt(env, 5); /* vdpgetprop */
    v105 = (*qfn2(fn))(qenv(fn), v105, v90);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v90 = v105;
    if (v105 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v105 = stack[-4];
    fn = elt(env, 6); /* gsetsugar */
    v90 = (*qfn2(fn))(qenv(fn), v105, v90);
    nil = C_nil;
    if (exception_pending()) goto v71;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

v43:
    stack[-2] = elt(env, 1); /* vdp */
    stack[-1] = qvalue(elt(env, 2)); /* nil */
    v90 = qvalue(elt(env, 2)); /* nil */
    stack[0] = ncons(v90);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-5];
    v105 = qvalue(elt(env, 2)); /* nil */
    v90 = qvalue(elt(env, 2)); /* nil */
    v90 = list2(v105, v90);
    nil = C_nil;
    if (exception_pending()) goto v71;
    {
        Lisp_Object v94 = stack[-2];
        Lisp_Object v92 = stack[-1];
        Lisp_Object v106 = stack[0];
        popv(6);
        return list3star(v94, v92, v106, v90);
    }
/* error exit handlers */
v71:
    popv(6);
    return nil;
}



/* Code for cut!:mt */

static Lisp_Object CC_cutTmt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cut:mt");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v11;
    stack[-2] = v0;
/* end of prologue */
    v109 = stack[-2];
    v56 = elt(env, 1); /* !:rd!: */
    if (!consp(v109)) goto v90;
    v109 = qcar(v109);
    if (!(v109 == v56)) goto v90;
    v56 = stack[-2];
    v56 = qcdr(v56);
    if (!consp(v56)) goto v90;
    v56 = stack[-1];
    v56 = integerp(v56);
    if (v56 == nil) goto v90;
    v109 = stack[-1];
    v56 = (Lisp_Object)1; /* 0 */
    v56 = (Lisp_Object)greaterp2(v109, v56);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v56 = v56 ? lisp_true : nil;
    env = stack[-4];
    if (v56 == nil) goto v90;
    v56 = stack[-2];
    v56 = qcdr(v56);
    v56 = qcar(v56);
    v56 = Labsval(nil, v56);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-4];
    fn = elt(env, 2); /* msd */
    v109 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-4];
    v56 = stack[-1];
    v109 = difference2(v109, v56);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-4];
    stack[-1] = v109;
    v56 = (Lisp_Object)1; /* 0 */
    v56 = (Lisp_Object)lesseq2(v109, v56);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v56 = v56 ? lisp_true : nil;
    env = stack[-4];
    if (!(v56 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v56 = stack[-2];
    v56 = qcdr(v56);
    stack[0] = qcar(v56);
    v56 = stack[-1];
    v56 = negate(v56);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-4];
    v56 = stack[-2];
    v56 = qcdr(v56);
    v109 = qcdr(v56);
    v56 = stack[-1];
    v56 = plus2(v109, v56);
    nil = C_nil;
    if (exception_pending()) goto v106;
    {
        Lisp_Object v110 = stack[-3];
        Lisp_Object v111 = stack[0];
        popv(5);
        return list2star(v110, v111, v56);
    }

v90:
    v56 = elt(env, 0); /* cut!:mt */
    {
        popv(5);
        fn = elt(env, 3); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v56);
    }
/* error exit handlers */
v106:
    popv(5);
    return nil;
}



/* Code for gpexp1p */

static Lisp_Object CC_gpexp1p(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpexp1p");
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

v29:
    v37 = stack[0];
    v37 = (v37 == nil ? lisp_true : nil);
    if (!(v37 == nil)) { popv(2); return onevalue(v37); }
    v37 = stack[0];
    v37 = qcar(v37);
    fn = elt(env, 2); /* gpexpp */
    v37 = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    if (v37 == nil) goto v30;
    v37 = stack[0];
    v37 = qcdr(v37);
    stack[0] = v37;
    goto v29;

v30:
    v37 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v37); }
/* error exit handlers */
v19:
    popv(2);
    return nil;
}



/* Code for deleteall */

static Lisp_Object CC_deleteall(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v28, v64, v84;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deleteall");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */
    v64 = nil;
    goto v15;

v15:
    v96 = stack[0];
    if (v96 == nil) { popv(4); return onevalue(v64); }
    v96 = stack[0];
    v96 = qcar(v96);
    v84 = v96;
    v96 = stack[0];
    v96 = qcdr(v96);
    stack[0] = v96;
    v28 = v84;
    v96 = stack[-1];
    if (equal(v28, v96)) goto v15;
    stack[-2] = v64;
    v96 = v84;
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    v96 = Lnconc(nil, stack[-2], v96);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    v64 = v96;
    goto v15;
/* error exit handlers */
v32:
    popv(4);
    return nil;
}



/* Code for mkarray1 */

static Lisp_Object CC_mkarray1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v108;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkarray1");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v11;
    stack[-5] = v0;
/* end of prologue */
    v100 = stack[-5];
    if (v100 == nil) goto v33;
    v100 = stack[-5];
    v100 = qcar(v100);
    v100 = sub1(v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    stack[-6] = v100;
    v100 = stack[-6];
    v100 = Lmkvect(nil, v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    stack[-3] = v100;
    v100 = (Lisp_Object)1; /* 0 */
    stack[-2] = v100;
    goto v77;

v77:
    v108 = stack[-6];
    v100 = stack[-2];
    v100 = difference2(v108, v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    v100 = Lminusp(nil, v100);
    env = stack[-7];
    if (!(v100 == nil)) { Lisp_Object res = stack[-3]; popv(8); return onevalue(res); }
    stack[-1] = stack[-3];
    stack[0] = stack[-2];
    v100 = stack[-5];
    v108 = qcdr(v100);
    v100 = stack[-4];
    v100 = CC_mkarray1(env, v108, v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v100;
    v100 = stack[-2];
    v100 = add1(v100);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    stack[-2] = v100;
    goto v77;

v33:
    v108 = stack[-4];
    v100 = elt(env, 1); /* symbolic */
    if (v108 == v100) goto v8;
    v100 = (Lisp_Object)1; /* 0 */
    { popv(8); return onevalue(v100); }

v8:
    v100 = qvalue(elt(env, 2)); /* nil */
    { popv(8); return onevalue(v100); }
/* error exit handlers */
v68:
    popv(8);
    return nil;
}



/* Code for subsetp */

static Lisp_Object CC_subsetp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v21, v10, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsetp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v11;
    v10 = v0;
/* end of prologue */

v29:
    v14 = v10;
    v14 = (v14 == nil ? lisp_true : nil);
    if (!(v14 == nil)) return onevalue(v14);
    v14 = v10;
    v16 = qcar(v14);
    v14 = v21;
    v14 = Lmember(nil, v16, v14);
    if (v14 == nil) goto v8;
    v14 = v10;
    v10 = qcdr(v14);
    v14 = v21;
    v21 = v14;
    goto v29;

v8:
    v14 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v14);
}



/* Code for general!-reduce!-mod!-p */

static Lisp_Object CC_generalKreduceKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reduce-mod-p");
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
    v96 = stack[-1];
    if (v96 == nil) goto v13;
    v96 = stack[-1];
    if (!consp(v96)) goto v9;
    v96 = stack[-1];
    v96 = qcar(v96);
    if (!consp(v96)) goto v9;
    v96 = stack[-1];
    v96 = qcar(v96);
    stack[-2] = qcar(v96);
    v96 = stack[-1];
    v96 = qcar(v96);
    v96 = qcdr(v96);
    stack[0] = CC_generalKreduceKmodKp(env, v96);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v96 = stack[-1];
    v96 = qcdr(v96);
    v96 = CC_generalKreduceKmodKp(env, v96);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    {
        Lisp_Object v47 = stack[-2];
        Lisp_Object v31 = stack[0];
        popv(4);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v47, v31, v96);
    }

v9:
    v96 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-number */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v96);
    }

v13:
    v96 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v96); }
/* error exit handlers */
v46:
    popv(4);
    return nil;
}



/* Code for vintersection */

static Lisp_Object CC_vintersection(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v117;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vintersection");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */

v29:
    v116 = stack[-1];
    if (v116 == nil) goto v9;
    v116 = stack[-1];
    v116 = qcar(v116);
    v117 = qcar(v116);
    v116 = stack[0];
    v116 = Lassoc(nil, v117, v116);
    stack[-2] = v116;
    if (v116 == nil) goto v25;
    v116 = stack[-1];
    v116 = qcar(v116);
    v117 = qcdr(v116);
    v116 = stack[-2];
    v116 = qcdr(v116);
    v116 = (Lisp_Object)greaterp2(v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    v116 = v116 ? lisp_true : nil;
    env = stack[-3];
    if (v116 == nil) goto v102;
    v116 = stack[-2];
    v117 = qcdr(v116);
    v116 = (Lisp_Object)1; /* 0 */
    if (v117 == v116) goto v87;
    v116 = stack[-1];
    v117 = qcdr(v116);
    v116 = stack[0];
    v116 = CC_vintersection(env, v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    {
        Lisp_Object v119 = stack[-2];
        popv(4);
        return cons(v119, v116);
    }

v87:
    v116 = stack[-1];
    v117 = qcdr(v116);
    v116 = stack[0];
    stack[-1] = v117;
    stack[0] = v116;
    goto v29;

v102:
    v116 = stack[-1];
    v116 = qcar(v116);
    v117 = qcdr(v116);
    v116 = (Lisp_Object)1; /* 0 */
    if (v117 == v116) goto v92;
    v116 = stack[-1];
    stack[-2] = qcar(v116);
    v116 = stack[-1];
    v117 = qcdr(v116);
    v116 = stack[0];
    v116 = CC_vintersection(env, v117, v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    {
        Lisp_Object v120 = stack[-2];
        popv(4);
        return cons(v120, v116);
    }

v92:
    v116 = stack[-1];
    v117 = qcdr(v116);
    v116 = stack[0];
    stack[-1] = v117;
    stack[0] = v116;
    goto v29;

v25:
    v116 = stack[-1];
    v117 = qcdr(v116);
    v116 = stack[0];
    stack[-1] = v117;
    stack[0] = v116;
    goto v29;

v9:
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v116); }
/* error exit handlers */
v118:
    popv(4);
    return nil;
}



/* Code for ibalp_istotal */

static Lisp_Object CC_ibalp_istotal(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v79;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_istotal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v19 = v0;
/* end of prologue */

v29:
    v79 = v19;
    v79 = (v79 == nil ? lisp_true : nil);
    if (!(v79 == nil)) return onevalue(v79);
    v79 = v19;
    v79 = qcar(v79);
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    v79 = qcar(v79);
    if (v79 == nil) goto v30;
    v19 = qcdr(v19);
    goto v29;

v30:
    v19 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v19);
}



/* Code for attributesml */

static Lisp_Object CC_attributesml(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for attributesml");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */
    v76 = stack[-1];
    if (v76 == nil) goto v15;
    v76 = elt(env, 2); /* " " */
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v76 = stack[-1];
    v76 = qcar(v76);
    v76 = qcar(v76);
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v76 = elt(env, 3); /* "=""" */
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v76 = stack[-1];
    v76 = qcar(v76);
    v58 = qcar(v76);
    v76 = elt(env, 4); /* definitionurl */
    if (v58 == v76) goto v39;
    v76 = stack[-1];
    v76 = qcar(v76);
    v76 = qcdr(v76);
    v58 = qcar(v76);
    v76 = elt(env, 5); /* vectorml */
    if (v58 == v76) goto v28;
    v76 = stack[-1];
    v76 = qcar(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    goto v25;

v25:
    v76 = elt(env, 8); /* """" */
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v76 = stack[-1];
    v58 = qcdr(v76);
    v76 = stack[0];
    v76 = CC_attributesml(env, v58, v76);
    nil = C_nil;
    if (exception_pending()) goto v68;
    goto v27;

v27:
    v76 = nil;
    { popv(3); return onevalue(v76); }

v28:
    v76 = elt(env, 6); /* "vector" */
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    goto v25;

v39:
    v76 = stack[-1];
    v76 = qcar(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    fn = elt(env, 9); /* list2string */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    goto v25;

v15:
    v76 = stack[0];
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-2];
    v76 = elt(env, 1); /* ">" */
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v68;
    goto v27;
/* error exit handlers */
v68:
    popv(3);
    return nil;
}



/* Code for maxtype */

static Lisp_Object CC_maxtype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v20;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxtype");
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
    v20 = v0;
/* end of prologue */
    v37 = v20;
    if (!consp(v37)) return onevalue(v20);
    v37 = v20;
    v37 = qcdr(v37);
    v37 = Lconsp(nil, v37);
    if (v37 == nil) goto v5;
    v37 = v20;
    v37 = qcdr(v37);
    v37 = qcar(v37);
    return onevalue(v37);

v5:
    v37 = v20;
    v37 = qcar(v37);
    return onevalue(v37);
}



/* Code for !*wedgepf2pf */

static Lisp_Object CC_Hwedgepf2pf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v21, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *wedgepf2pf");
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
    goto v40;

v40:
    v14 = stack[0];
    if (v14 == nil) goto v9;
    v14 = stack[0];
    v14 = qcar(v14);
    v14 = qcar(v14);
    fn = elt(env, 1); /* mkuwedge */
    v10 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v14 = stack[0];
    v14 = qcar(v14);
    v21 = qcdr(v14);
    v14 = stack[-1];
    v14 = acons(v10, v21, v14);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    stack[-1] = v14;
    v14 = stack[0];
    v14 = qcdr(v14);
    stack[0] = v14;
    goto v40;

v9:
    v14 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v14);
    }
/* error exit handlers */
v96:
    popv(3);
    return nil;
}



/* Code for prepreform */

static Lisp_Object CC_prepreform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepreform");
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
    v41 = v0;
/* end of prologue */
    stack[0] = v41;
    v42 = qvalue(elt(env, 1)); /* ordl!* */
    v41 = qvalue(elt(env, 2)); /* factors!* */
    v41 = Lappend(nil, v42, v41);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    {
        Lisp_Object v20 = stack[0];
        popv(2);
        fn = elt(env, 3); /* prepreform1 */
        return (*qfn2(fn))(qenv(fn), v20, v41);
    }
/* error exit handlers */
v37:
    popv(2);
    return nil;
}



/* Code for class */

static Lisp_Object CC_class(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for class");
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
    v16 = stack[0];
    fn = elt(env, 3); /* ord */
    v22 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    v16 = (Lisp_Object)1; /* 0 */
    if (v22 == v16) goto v13;
    v22 = qvalue(elt(env, 1)); /* ordering */
    v16 = elt(env, 2); /* lex */
    if (v22 == v16) goto v20;
    v16 = stack[0];
    v16 = qcdr(v16);
    goto v37;

v37:
    v16 = Lreverse(nil, v16);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-1];
    fn = elt(env, 4); /* leftzeros */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v28;
    v16 = (Lisp_Object)((int32_t)(v16) + 0x10);
    { popv(2); return onevalue(v16); }

v20:
    v16 = stack[0];
    goto v37;

v13:
    v16 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v16); }
/* error exit handlers */
v28:
    popv(2);
    return nil;
}



/* Code for expt!-mod!-p */

static Lisp_Object CC_exptKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expt-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v121 = v11;
    stack[0] = v0;
/* end of prologue */
    v54 = v121;
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) goto v40;
    v54 = v121;
    v53 = (Lisp_Object)17; /* 1 */
    if (v54 == v53) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v54 = v121;
    v53 = (Lisp_Object)33; /* 2 */
    v53 = Ldivide(nil, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    stack[-1] = v53;
    v54 = stack[0];
    v53 = stack[-1];
    v53 = qcar(v53);
    v53 = CC_exptKmodKp(env, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    v121 = v53;
    v53 = v121;
    v54 = v121;
    fn = elt(env, 1); /* times!-mod!-p */
    v53 = (*qfn2(fn))(qenv(fn), v53, v54);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    v121 = v53;
    v53 = stack[-1];
    v54 = qcdr(v53);
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) { popv(3); return onevalue(v121); }
    v54 = v121;
    v53 = stack[0];
    fn = elt(env, 1); /* times!-mod!-p */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v121 = v53;
    { popv(3); return onevalue(v121); }

v40:
    v53 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v53); }
/* error exit handlers */
v55:
    popv(3);
    return nil;
}



/* Code for extmult */

static Lisp_Object CC_extmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extmult");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v11;
    stack[-3] = v0;
/* end of prologue */
    v119 = stack[-3];
    if (v119 == nil) goto v40;
    v119 = stack[-2];
    if (v119 == nil) goto v40;
    v119 = stack[-3];
    v119 = qcar(v119);
    v119 = qcar(v119);
    v120 = qcar(v119);
    v119 = stack[-2];
    v119 = qcar(v119);
    v119 = qcar(v119);
    fn = elt(env, 2); /* ordexn */
    v119 = (*qfn2(fn))(qenv(fn), v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v120 = v119;
    v119 = v120;
    if (v119 == nil) goto v88;
    v119 = v120;
    stack[-4] = qcdr(v119);
    v119 = v120;
    v119 = qcar(v119);
    if (v119 == nil) goto v50;
    v119 = stack[-3];
    v119 = qcar(v119);
    v120 = qcdr(v119);
    v119 = stack[-2];
    v119 = qcar(v119);
    v119 = qcdr(v119);
    fn = elt(env, 3); /* c!:subs2multf */
    v119 = (*qfn2(fn))(qenv(fn), v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    fn = elt(env, 4); /* negf */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    stack[-1] = v119;
    goto v69;

v69:
    v119 = stack[-3];
    v119 = qcar(v119);
    v120 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v119 = stack[-2];
    v119 = qcdr(v119);
    stack[0] = CC_extmult(env, v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v119 = stack[-3];
    v120 = qcdr(v119);
    v119 = stack[-2];
    v119 = CC_extmult(env, v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    fn = elt(env, 5); /* extadd */
    v119 = (*qfn2(fn))(qenv(fn), stack[0], v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    {
        Lisp_Object v127 = stack[-4];
        Lisp_Object v128 = stack[-1];
        popv(6);
        return acons(v127, v128, v119);
    }

v50:
    v119 = stack[-3];
    v119 = qcar(v119);
    v120 = qcdr(v119);
    v119 = stack[-2];
    v119 = qcar(v119);
    v119 = qcdr(v119);
    fn = elt(env, 3); /* c!:subs2multf */
    v119 = (*qfn2(fn))(qenv(fn), v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    stack[-1] = v119;
    goto v69;

v88:
    v119 = stack[-3];
    v120 = qcdr(v119);
    v119 = stack[-2];
    stack[0] = CC_extmult(env, v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v119 = stack[-3];
    v119 = qcar(v119);
    v120 = ncons(v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    v119 = stack[-2];
    v119 = qcdr(v119);
    v119 = CC_extmult(env, v120, v119);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-5];
    {
        Lisp_Object v129 = stack[0];
        popv(6);
        fn = elt(env, 5); /* extadd */
        return (*qfn2(fn))(qenv(fn), v129, v119);
    }

v40:
    v119 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v119); }
/* error exit handlers */
v126:
    popv(6);
    return nil;
}



/* Code for ibalp_vmember */

static Lisp_Object CC_ibalp_vmember(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_vmember");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */

v29:
    v7 = stack[0];
    if (v7 == nil) goto v40;
    v14 = stack[-1];
    v7 = stack[0];
    v7 = qcar(v7);
    fn = elt(env, 2); /* ibalp_vequal */
    v7 = (*qfn2(fn))(qenv(fn), v14, v7);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-2];
    if (!(v7 == nil)) { popv(3); return onevalue(v7); }
    v14 = stack[-1];
    v7 = stack[0];
    v7 = qcdr(v7);
    stack[-1] = v14;
    stack[0] = v7;
    goto v29;

v40:
    v7 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v7); }
/* error exit handlers */
v16:
    popv(3);
    return nil;
}



/* Code for nary */

static Lisp_Object CC_nary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nary");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */
    v39 = stack[-1];
    v48 = qcar(v39);
    v39 = elt(env, 1); /* e */
    if (!(v48 == v39)) goto v10;
    v48 = stack[0];
    v39 = elt(env, 2); /* power */
    if (!(v48 == v39)) goto v10;
    v39 = stack[-1];
    v48 = qcdr(v39);
    v39 = elt(env, 3); /* exp */
    fn = elt(env, 10); /* unary */
    v39 = (*qfn2(fn))(qenv(fn), v48, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    goto v27;

v27:
    v39 = nil;
    { popv(3); return onevalue(v39); }

v10:
    v39 = elt(env, 4); /* "<apply>" */
    fn = elt(env, 11); /* printout */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v39 = elt(env, 5); /* "<" */
    v39 = Lprinc(nil, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v39 = stack[0];
    v39 = Lprinc(nil, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v39 = stack[-1];
    v48 = qcar(v39);
    v39 = elt(env, 6); /* "/" */
    fn = elt(env, 12); /* attributesml */
    v39 = (*qfn2(fn))(qenv(fn), v48, v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v39 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 13); /* indent!* */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v39 = stack[-1];
    v39 = qcdr(v39);
    fn = elt(env, 14); /* multi_elem */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v39 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-2];
    v39 = elt(env, 9); /* "</apply>" */
    fn = elt(env, 11); /* printout */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v50;
    goto v27;
/* error exit handlers */
v50:
    popv(3);
    return nil;
}



/* Code for ldt!-tvar */

static Lisp_Object CC_ldtKtvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v25, v23;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-tvar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v78 = v0;
/* end of prologue */
    v78 = qcar(v78);
    v78 = qcar(v78);
    v25 = v78;
    v78 = v25;
    v23 = elt(env, 1); /* df */
    if (!consp(v78)) return onevalue(v25);
    v78 = qcar(v78);
    if (!(v78 == v23)) return onevalue(v25);
    v78 = v25;
    v78 = qcdr(v78);
    v78 = qcar(v78);
    return onevalue(v78);
}



/* Code for add_minus */

static Lisp_Object CC_add_minus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v136, v137;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for add_minus");
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
    v136 = stack[-1];
    if (!consp(v136)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v136 = stack[-1];
    v137 = qcar(v136);
    v136 = elt(env, 1); /* !:rd!: */
    if (!(v137 == v136)) goto v10;
    v136 = stack[-1];
    v137 = qcdr(v136);
    v136 = (Lisp_Object)1; /* 0 */
    v136 = (Lisp_Object)geq2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v138;
    v136 = v136 ? lisp_true : nil;
    env = stack[-3];
    if (!(v136 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v10:
    v136 = stack[-1];
    v137 = qcar(v136);
    v136 = elt(env, 1); /* !:rd!: */
    if (!(v137 == v136)) goto v139;
    v136 = stack[-1];
    v137 = qcdr(v136);
    v136 = (Lisp_Object)1; /* 0 */
    v136 = (Lisp_Object)lessp2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v138;
    v136 = v136 ? lisp_true : nil;
    env = stack[-3];
    if (v136 == nil) goto v139;
    stack[-2] = elt(env, 2); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v136 = stack[-1];
    v136 = qcdr(v136);
    v136 = Labsval(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    v136 = cons(stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v138;
    {
        Lisp_Object v140 = stack[-2];
        popv(4);
        return list2(v140, v136);
    }

v139:
    v136 = stack[-1];
    v137 = qcar(v136);
    v136 = elt(env, 2); /* minus */
    if (!(v137 == v136)) goto v105;
    v136 = stack[-1];
    v136 = qcdr(v136);
    v136 = qcar(v136);
    if (is_number(v136)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    else goto v105;

v105:
    v136 = stack[-1];
    v137 = qcar(v136);
    v136 = elt(env, 2); /* minus */
    if (!(v137 == v136)) goto v99;
    v136 = stack[-1];
    v136 = qcdr(v136);
    v136 = qcar(v136);
    v137 = qcdr(v136);
    v136 = (Lisp_Object)1; /* 0 */
    v136 = (Lisp_Object)lessp2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v138;
    v136 = v136 ? lisp_true : nil;
    env = stack[-3];
    if (v136 == nil) goto v99;
    stack[0] = elt(env, 1); /* !:rd!: */
    v136 = stack[-1];
    v136 = qcdr(v136);
    v136 = qcar(v136);
    v136 = qcdr(v136);
    v136 = Labsval(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v138;
    {
        Lisp_Object v141 = stack[0];
        popv(4);
        return cons(v141, v136);
    }

v99:
    v136 = stack[-1];
    v137 = qcar(v136);
    v136 = elt(env, 2); /* minus */
    if (v137 == v136) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v136 = stack[-1];
    v137 = qcdr(v136);
    v136 = (Lisp_Object)1; /* 0 */
    v136 = (Lisp_Object)lessp2(v137, v136);
    nil = C_nil;
    if (exception_pending()) goto v138;
    v136 = v136 ? lisp_true : nil;
    env = stack[-3];
    if (v136 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = elt(env, 2); /* minus */
    stack[0] = elt(env, 1); /* !:rd!: */
    v136 = stack[-1];
    v136 = qcdr(v136);
    v136 = Labsval(nil, v136);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    v136 = cons(stack[0], v136);
    nil = C_nil;
    if (exception_pending()) goto v138;
    {
        Lisp_Object v142 = stack[-2];
        popv(4);
        return list2(v142, v136);
    }
/* error exit handlers */
v138:
    popv(4);
    return nil;
}



/* Code for xord_deglex */

static Lisp_Object CC_xord_deglex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v50, v107, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_deglex");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */
    v83 = stack[-1];
    v50 = qcar(v83);
    v83 = (Lisp_Object)17; /* 1 */
    if (v50 == v83) goto v40;
    v83 = stack[0];
    v50 = qcar(v83);
    v83 = (Lisp_Object)17; /* 1 */
    if (v50 == v83) goto v5;
    v83 = stack[-1];
    fn = elt(env, 3); /* xdegreemon */
    stack[-2] = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v83 = stack[0];
    fn = elt(env, 3); /* xdegreemon */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-3];
    v67 = stack[-2];
    v107 = v83;
    v50 = v67;
    v83 = v107;
    if (equal(v50, v83)) goto v60;
    v83 = v67;
    v50 = v107;
        popv(4);
        return Lgreaterp(nil, v83, v50);

v60:
    v50 = stack[-1];
    v83 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v50, v83);
    }

v5:
    v83 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v83); }

v40:
    v83 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v83); }
/* error exit handlers */
v113:
    popv(4);
    return nil;
}



/* Code for reduce_pv0 */

static Lisp_Object MS_CDECL CC_reduce_pv0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce_pv0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce_pv0");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v11,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v3;
    stack[-4] = v11;
    stack[0] = v0;
/* end of prologue */
    v145 = stack[-4];
    if (v145 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v145 = stack[0];
    if (v145 == nil) goto v8;
    v145 = stack[0];
    stack[-5] = v145;
    goto v79;

v79:
    v145 = stack[-5];
    if (v145 == nil) goto v19;
    v145 = stack[-4];
    if (v145 == nil) goto v19;
    v145 = stack[-5];
    v145 = qcar(v145);
    v131 = qcdr(v145);
    v145 = stack[-4];
    v145 = qcar(v145);
    v145 = qcdr(v145);
    v145 = (Lisp_Object)greaterp2(v131, v145);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v145 = v145 ? lisp_true : nil;
    env = stack[-6];
    if (v145 == nil) goto v19;
    v145 = stack[-5];
    v145 = qcdr(v145);
    stack[-5] = v145;
    goto v79;

v19:
    v145 = stack[-5];
    if (v145 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v145 = stack[-4];
    if (v145 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v145 = stack[-4];
    v145 = qcar(v145);
    v131 = qcdr(v145);
    v145 = stack[-5];
    v145 = qcar(v145);
    v145 = qcdr(v145);
    if (!(equal(v131, v145))) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v145 = stack[-5];
    v145 = qcar(v145);
    v131 = qcar(v145);
    v145 = stack[-4];
    v145 = qcar(v145);
    v145 = qcar(v145);
    fn = elt(env, 3); /* lcm */
    v145 = (*qfn2(fn))(qenv(fn), v131, v145);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    stack[-2] = v145;
    v131 = stack[-2];
    v145 = stack[-5];
    v145 = qcar(v145);
    v145 = qcar(v145);
    v145 = quot2(v131, v145);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    stack[0] = stack[-4];
    v131 = stack[-2];
    v145 = stack[-4];
    v145 = qcar(v145);
    v145 = qcar(v145);
    v145 = quot2(v131, v145);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    v145 = negate(v145);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    fn = elt(env, 4); /* pv_multc */
    v145 = (*qfn2(fn))(qenv(fn), stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    fn = elt(env, 5); /* pv_add */
    v145 = (*qfn2(fn))(qenv(fn), stack[-1], v145);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    stack[0] = v145;
    v145 = stack[-3];
    if (v145 == nil) goto v146;
    v145 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v145; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v146:
    stack[-1] = qvalue(elt(env, 2)); /* pv_den */
    v131 = stack[-2];
    v145 = stack[-5];
    v145 = qcar(v145);
    v145 = qcar(v145);
    v145 = quot2(v131, v145);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    v145 = times2(stack[-1], v145);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-6];
    qvalue(elt(env, 2)) = v145; /* pv_den */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }

v8:
    v145 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v145); }
/* error exit handlers */
v132:
    popv(7);
    return nil;
}



/* Code for ibalp_tvb */

static Lisp_Object CC_ibalp_tvb(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_tvb");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v11;
    v81 = v0;
/* end of prologue */
    stack[-2] = v81;
    goto v27;

v27:
    v81 = stack[-2];
    if (v81 == nil) goto v8;
    v81 = stack[-2];
    v81 = qcar(v81);
    stack[0] = v81;
    v81 = stack[0];
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    v104 = qcar(v81);
    v81 = stack[-1];
    v81 = (Lisp_Object)geq2(v104, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v81 = v81 ? lisp_true : nil;
    env = stack[-3];
    if (v81 == nil) goto v42;
    v81 = stack[0];
    v104 = qcdr(v81);
    v81 = stack[0];
    v81 = qcdr(v81);
    v81 = qcdr(v81);
    v81 = qcar(v81);
    fn = elt(env, 2); /* ibalp_var!-unset */
    v81 = (*qfn2(fn))(qenv(fn), v104, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-3];
    goto v42;

v42:
    v81 = stack[-2];
    v81 = qcdr(v81);
    stack[-2] = v81;
    goto v27;

v8:
    v81 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v81); }
/* error exit handlers */
v86:
    popv(4);
    return nil;
}



/* Code for vdp_poly */

static Lisp_Object CC_vdp_poly(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v15;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_poly");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v15 = v0;
/* end of prologue */
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    v15 = qcdr(v15);
    v15 = qcar(v15);
    return onevalue(v15);
}



/* Code for variableom */

static Lisp_Object CC_variableom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variableom");
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
    v85 = stack[0];
    v86 = Lintern(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v85 = qvalue(elt(env, 1)); /* constantsom!* */
    v85 = Lassoc(nil, v86, v85);
    stack[-1] = v85;
    v85 = stack[-1];
    if (v85 == nil) goto v28;
    v85 = elt(env, 2); /* "<OMS " */
    fn = elt(env, 9); /* printout */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v85 = elt(env, 3); /* "cd=""" */
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v85 = stack[-1];
    v85 = qcdr(v85);
    v85 = qcar(v85);
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v85 = elt(env, 4); /* """ " */
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v85 = elt(env, 5); /* "name=""" */
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v85 = stack[-1];
    v85 = qcdr(v85);
    v85 = qcdr(v85);
    v85 = qcar(v85);
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v85 = elt(env, 6); /* """/>" */
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    goto v4;

v4:
    v85 = nil;
    { popv(3); return onevalue(v85); }

v28:
    v85 = stack[0];
    if (v85 == nil) goto v4;
    v85 = elt(env, 8); /* "<OMV " */
    fn = elt(env, 9); /* printout */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v85 = elt(env, 5); /* "name=""" */
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v85 = stack[0];
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-2];
    v85 = elt(env, 6); /* """/>" */
    v85 = Lprinc(nil, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    goto v4;
/* error exit handlers */
v87:
    popv(3);
    return nil;
}



/* Code for redcodmat */

static Lisp_Object MS_CDECL CC_redcodmat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "redcodmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redcodmat");
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
    v78 = qvalue(elt(env, 1)); /* rowmin */
    stack[0] = v78;
    goto v33;

v33:
    v25 = qvalue(elt(env, 2)); /* rowmax */
    v78 = stack[0];
    v78 = difference2(v25, v78);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    v78 = Lminusp(nil, v78);
    env = stack[-1];
    if (v78 == nil) goto v15;
    v78 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v78); }

v15:
    v78 = stack[0];
    fn = elt(env, 4); /* testred */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    v78 = stack[0];
    v78 = add1(v78);
    nil = C_nil;
    if (exception_pending()) goto v1;
    env = stack[-1];
    stack[0] = v78;
    goto v33;
/* error exit handlers */
v1:
    popv(2);
    return nil;
}



/* Code for bcplus!? */

static Lisp_Object CC_bcplusW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v19;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcplus?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v20 = v0;
/* end of prologue */
    v20 = qcar(v20);
    v19 = v20;
    v20 = v19;
    if (is_number(v20)) goto v5;
    v20 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v20);

v5:
    v20 = (Lisp_Object)1; /* 0 */
        return Lgreaterp(nil, v19, v20);
}



/* Code for lid */

static Lisp_Object CC_lid(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lid");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v0;
/* end of prologue */
    v17 = v33;
    if (!consp(v17)) return onevalue(v33);
    v33 = qcar(v33);
    return onevalue(v33);
}



/* Code for evaluate1 */

static Lisp_Object CC_evaluate1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v148, v149, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate1");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v148 = v11;
    v149 = v0;
/* end of prologue */
    v147 = v149;
    if (is_number(v147)) goto v40;
    v147 = v149;
    if (v147 == nil) goto v40;
    v147 = v149;
    v147 = Lconsp(nil, v147);
    env = stack[0];
    if (v147 == nil) goto v6;
    v147 = v149;
    v126 = qcar(v147);
    v147 = elt(env, 1); /* dname */
    v147 = get(v126, v147);
    env = stack[0];
    if (!(v147 == nil)) { popv(1); return onevalue(v149); }

v6:
    v126 = v149;
    v147 = v148;
    v147 = Lassoc(nil, v126, v147);
    v126 = v147;
    v147 = v126;
    if (v147 == nil) goto v47;
    v147 = v126;
    v147 = qcdr(v147);
    { popv(1); return onevalue(v147); }

v47:
    v147 = v149;
    if (!consp(v147)) goto v36;
    v147 = v149;
    v147 = qcar(v147);
    v149 = qcdr(v149);
    {
        popv(1);
        fn = elt(env, 12); /* evaluate2 */
        return (*qfnn(fn))(qenv(fn), 3, v147, v149, v148);
    }

v36:
    v148 = v149;
    v147 = elt(env, 2); /* i */
    if (v148 == v147) goto v107;
    v148 = v149;
    v147 = elt(env, 7); /* e */
    if (v148 == v147) goto v103;
    v148 = v149;
    v147 = elt(env, 8); /* pi */
    if (v148 == v147) goto v103;
    v147 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 10)) = v147; /* !*evaluateerror */
    v148 = v149;
    v147 = elt(env, 11); /* "number" */
    {
        popv(1);
        fn = elt(env, 13); /* typerr */
        return (*qfn2(fn))(qenv(fn), v148, v147);
    }

v103:
    v147 = v149;
    fn = elt(env, 14); /* simp */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    v147 = qcar(v147);
    {
        popv(1);
        fn = elt(env, 15); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v147);
    }

v107:
    v148 = qvalue(elt(env, 3)); /* dmode!* */
    v147 = elt(env, 4); /* ivalue */
    v147 = get(v148, v147);
    env = stack[0];
    v149 = v147;
    if (v147 == nil) goto v55;
    v148 = v149;
    v147 = elt(env, 5); /* (nil) */
    fn = elt(env, 16); /* apply */
    v147 = (*qfn2(fn))(qenv(fn), v148, v147);
    nil = C_nil;
    if (exception_pending()) goto v127;
    v147 = qcar(v147);
    { popv(1); return onevalue(v147); }

v55:
    v147 = elt(env, 6); /* "i used as indeterminate value" */
    {
        popv(1);
        fn = elt(env, 17); /* rederr */
        return (*qfn1(fn))(qenv(fn), v147);
    }

v40:
    v147 = v149;
    {
        popv(1);
        fn = elt(env, 15); /* force!-to!-dm */
        return (*qfn1(fn))(qenv(fn), v147);
    }
/* error exit handlers */
v127:
    popv(1);
    return nil;
}



/* Code for indordp */

static Lisp_Object CC_indordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v39, v48, v49, v83;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v49 = v11;
    v83 = v0;
/* end of prologue */
    v38 = qvalue(elt(env, 1)); /* indxl!* */
    v48 = v38;
    v39 = v83;
    v38 = v48;
    v38 = Lmemq(nil, v39, v38);
    if (!(v38 == nil)) goto v27;
    v38 = qvalue(elt(env, 2)); /* t */
    return onevalue(v38);

v27:
    v38 = v48;
    if (v38 == nil) goto v1;
    v39 = v83;
    v38 = v48;
    v38 = qcar(v38);
    if (v39 == v38) goto v16;
    v39 = v49;
    v38 = v48;
    v38 = qcar(v38);
    if (v39 == v38) goto v60;
    v38 = v48;
    v38 = qcdr(v38);
    v48 = v38;
    goto v27;

v60:
    v38 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v38);

v16:
    v38 = qvalue(elt(env, 2)); /* t */
    return onevalue(v38);

v1:
    v38 = v83;
    v39 = v49;
        return Lorderp(nil, v38, v39);
}



/* Code for zero!-roads */

static Lisp_Object CC_zeroKroads(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zero-roads");
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

v29:
    v21 = stack[0];
    if (v21 == nil) goto v13;
    v21 = stack[0];
    v21 = qcar(v21);
    fn = elt(env, 2); /* z!-roads */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    v10 = v21;
    v21 = v10;
    if (v21 == nil) goto v12;
    stack[-1] = v10;
    v21 = stack[0];
    v21 = qcdr(v21);
    v21 = CC_zeroKroads(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v96;
    {
        Lisp_Object v28 = stack[-1];
        popv(3);
        return cons(v28, v21);
    }

v12:
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[0] = v21;
    goto v29;

v13:
    v21 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v21); }
/* error exit handlers */
v96:
    popv(3);
    return nil;
}



/* Code for dssoc */

static Lisp_Object CC_dssoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v24, v6, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dssoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v11;
    v7 = v0;
/* end of prologue */

v40:
    v12 = v6;
    if (v12 == nil) goto v9;
    v24 = v7;
    v12 = v6;
    v12 = qcar(v12);
    v12 = qcdr(v12);
    if (equal(v24, v12)) goto v33;
    v12 = v6;
    v12 = qcdr(v12);
    v6 = v12;
    goto v40;

v33:
    v12 = v6;
    v12 = qcar(v12);
    return onevalue(v12);

v9:
    v12 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v12);
}



/* Code for cl_simplat */

static Lisp_Object CC_cl_simplat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v21, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_simplat");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v21 = v11;
    v10 = v0;
/* end of prologue */
    v14 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v14 == nil) goto v30;
    v14 = v10;
    fn = elt(env, 3); /* rl_simplat1 */
    v21 = (*qfn2(fn))(qenv(fn), v14, v21);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[0];
    v14 = elt(env, 2); /* cl_identifyat */
    {
        popv(1);
        fn = elt(env, 4); /* cl_apply2ats */
        return (*qfn2(fn))(qenv(fn), v21, v14);
    }

v30:
    v14 = v10;
    {
        popv(1);
        fn = elt(env, 3); /* rl_simplat1 */
        return (*qfn2(fn))(qenv(fn), v14, v21);
    }
/* error exit handlers */
v16:
    popv(1);
    return nil;
}



/* Code for qsort */

static Lisp_Object CC_qsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qsort");
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
    v54 = v0;
/* end of prologue */
    stack[-2] = nil;
    stack[-1] = nil;
    v53 = v54;
    if (v53 == nil) goto v33;
    v53 = v54;
    v53 = qcar(v53);
    stack[-3] = v53;
    v53 = v54;
    v53 = qcdr(v53);
    stack[0] = v53;
    goto v9;

v9:
    v53 = stack[0];
    if (v53 == nil) goto v39;
    v54 = stack[-3];
    v53 = stack[0];
    v53 = qcar(v53);
    fn = elt(env, 2); /* ordop */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    if (v53 == nil) goto v65;
    v53 = stack[0];
    v54 = qcar(v53);
    v53 = stack[-1];
    v53 = cons(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-1] = v53;
    goto v23;

v23:
    v53 = stack[0];
    v53 = qcdr(v53);
    stack[0] = v53;
    goto v9;

v65:
    v53 = stack[0];
    v54 = qcar(v53);
    v53 = stack[-2];
    v53 = cons(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-2] = v53;
    goto v23;

v39:
    v53 = stack[-2];
    stack[0] = CC_qsort(env, v53);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-2] = stack[-3];
    v53 = stack[-1];
    v53 = CC_qsort(env, v53);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v53 = cons(stack[-2], v53);
    nil = C_nil;
    if (exception_pending()) goto v69;
    {
        Lisp_Object v68 = stack[0];
        popv(5);
        return Lappend(nil, v68, v53);
    }

v33:
    v53 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v53); }
/* error exit handlers */
v69:
    popv(5);
    return nil;
}



/* Code for squared!+matrix!+p */

static Lisp_Object CC_squaredLmatrixLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for squared+matrix+p");
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
    v19 = stack[0];
    fn = elt(env, 2); /* matrix!+p */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-2];
    if (v19 == nil) goto v40;
    v19 = stack[0];
    fn = elt(env, 3); /* get!+row!+nr */
    stack[-1] = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-2];
    v19 = stack[0];
    fn = elt(env, 4); /* get!+col!+nr */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v25;
    env = stack[-2];
    if (!(equal(stack[-1], v19))) goto v40;
    v19 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v19); }

v40:
    v19 = nil;
    { popv(3); return onevalue(v19); }
/* error exit handlers */
v25:
    popv(3);
    return nil;
}



/* Code for ibalp_vequal */

static Lisp_Object CC_ibalp_vequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_vequal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v17 = v11;
    v18 = v0;
/* end of prologue */
    v18 = qcar(v18);
    v17 = qcar(v17);
    v17 = (v18 == v17 ? lisp_true : nil);
    return onevalue(v17);
}



/* Code for rl_ordatp */

static Lisp_Object CC_rl_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_ordatp");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v42 = v11;
    v43 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_ordatp!* */
    v42 = list2(v43, v42);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-1];
    {
        Lisp_Object v19 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v19, v42);
    }
/* error exit handlers */
v20:
    popv(2);
    return nil;
}



/* Code for stats_getargs */

static Lisp_Object MS_CDECL CC_stats_getargs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v37;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "stats_getargs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stats_getargs");
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
    fn = elt(env, 2); /* mathml */
    v43 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v37 = v43;
    v43 = v37;
    if (v43 == nil) goto v15;
    stack[0] = v37;
    v43 = CC_stats_getargs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v19;
    {
        Lisp_Object v79 = stack[0];
        popv(2);
        return cons(v79, v43);
    }

v15:
    v43 = nil;
    { popv(2); return onevalue(v43); }
/* error exit handlers */
v19:
    popv(2);
    return nil;
}



/* Code for vdpzero */

static Lisp_Object MS_CDECL CC_vdpzero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vdpzero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpzero");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v26 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* a2vdp */
        return (*qfn1(fn))(qenv(fn), v26);
    }
}



/* Code for cdarx */

static Lisp_Object CC_cdarx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cdarx");
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
    v34 = v0;
/* end of prologue */
    v33 = v34;
    v34 = elt(env, 1); /* cdar */
    fn = elt(env, 2); /* carx */
    v34 = (*qfn2(fn))(qenv(fn), v33, v34);
    errexit();
    v34 = qcdr(v34);
    return onevalue(v34);
}



/* Code for setel */

static Lisp_Object CC_setel(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v107, v67, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setel");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v11;
    stack[-2] = v0;
/* end of prologue */
    v50 = stack[-2];
    v107 = qcar(v50);
    v50 = elt(env, 1); /* dimension */
    v50 = get(v107, v50);
    env = stack[-4];
    stack[-3] = v50;
    v50 = stack[-3];
    stack[0] = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v50 = stack[-2];
    v50 = qcdr(v50);
    v50 = Llength(nil, v50);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    if (equal(stack[0], v50)) goto v81;
    v67 = elt(env, 2); /* rlisp */
    v107 = (Lisp_Object)353; /* 22 */
    v50 = elt(env, 3); /* "Incorrect array reference" */
    {
        popv(5);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v67, v107, v50);
    }

v81:
    v50 = stack[-2];
    v107 = qcar(v50);
    v50 = elt(env, 4); /* avalue */
    v50 = get(v107, v50);
    env = stack[-4];
    v50 = qcdr(v50);
    v95 = qcar(v50);
    v50 = stack[-2];
    v67 = qcdr(v50);
    v107 = stack[-1];
    v50 = stack[-3];
    {
        popv(5);
        fn = elt(env, 6); /* setel1 */
        return (*qfnn(fn))(qenv(fn), 4, v95, v67, v107, v50);
    }
/* error exit handlers */
v139:
    popv(5);
    return nil;
}



/* Code for mkkl */

static Lisp_Object CC_mkkl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v12, v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkkl");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v2 = v11;
    v12 = v0;
/* end of prologue */

v27:
    v24 = v12;
    if (v24 == nil) { popv(2); return onevalue(v2); }
    v24 = v12;
    v24 = qcdr(v24);
    stack[0] = v24;
    v12 = qcar(v12);
    v2 = cons(v12, v2);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    v2 = ncons(v2);
    nil = C_nil;
    if (exception_pending()) goto v7;
    env = stack[-1];
    v12 = stack[0];
    goto v27;
/* error exit handlers */
v7:
    popv(2);
    return nil;
}



/* Code for qremd */

static Lisp_Object CC_qremd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qremd");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v11;
    stack[-2] = v0;
/* end of prologue */
    v149 = stack[-2];
    if (v149 == nil) goto v30;
    v126 = stack[-1];
    v149 = (Lisp_Object)17; /* 1 */
    if (v126 == v149) goto v5;
    v126 = qvalue(elt(env, 1)); /* dmode!* */
    v149 = elt(env, 2); /* field */
    v149 = Lflagp(nil, v126, v149);
    env = stack[-4];
    if (v149 == nil) goto v2;
    v149 = stack[-1];
    fn = elt(env, 3); /* !:recip */
    v126 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v149 = stack[-2];
    fn = elt(env, 4); /* multd */
    v149 = (*qfn2(fn))(qenv(fn), v126, v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    popv(5);
    return ncons(v149);

v2:
    v149 = stack[-2];
    if (!consp(v149)) goto v85;
    v149 = stack[-2];
    v149 = qcar(v149);
    if (!consp(v149)) goto v85;
    v149 = stack[-2];
    v149 = qcar(v149);
    v126 = qcdr(v149);
    v149 = stack[-1];
    fn = elt(env, 5); /* qremf */
    v149 = (*qfn2(fn))(qenv(fn), v126, v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[-3] = v149;
    v149 = stack[-2];
    v149 = qcar(v149);
    v126 = qcar(v149);
    v149 = (Lisp_Object)17; /* 1 */
    v149 = cons(v126, v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v126 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v149 = stack[-3];
    v149 = qcar(v149);
    fn = elt(env, 6); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v126, v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v149 = stack[-2];
    v149 = qcar(v149);
    v126 = qcar(v149);
    v149 = (Lisp_Object)17; /* 1 */
    v149 = cons(v126, v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v126 = ncons(v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v149 = stack[-3];
    v149 = qcdr(v149);
    fn = elt(env, 6); /* multf */
    v149 = (*qfn2(fn))(qenv(fn), v126, v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    stack[0] = cons(stack[0], v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    v149 = stack[-2];
    v126 = qcdr(v149);
    v149 = stack[-1];
    v149 = CC_qremd(env, v126, v149);
    nil = C_nil;
    if (exception_pending()) goto v135;
    env = stack[-4];
    {
        Lisp_Object v151 = stack[0];
        popv(5);
        fn = elt(env, 7); /* praddf */
        return (*qfn2(fn))(qenv(fn), v151, v149);
    }

v85:
    v126 = stack[-2];
    v149 = stack[-1];
    {
        popv(5);
        fn = elt(env, 8); /* !:divide */
        return (*qfn2(fn))(qenv(fn), v126, v149);
    }

v5:
    v149 = stack[-2];
    popv(5);
    return ncons(v149);

v30:
    v126 = stack[-2];
    v149 = stack[-2];
    popv(5);
    return cons(v126, v149);
/* error exit handlers */
v135:
    popv(5);
    return nil;
}



/* Code for moduntag */

static Lisp_Object CC_moduntag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for moduntag");
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
    goto v34;

v34:
    v35 = stack[0];
    v104 = elt(env, 1); /* !:mod!: */
    if (!consp(v35)) goto v30;
    v35 = qcar(v35);
    if (!(v35 == v104)) goto v30;
    v35 = stack[-1];
    v104 = stack[0];
    v104 = qcdr(v104);
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v35, v104);
    }

v30:
    v104 = stack[0];
    if (!consp(v104)) goto v6;
    v104 = stack[0];
    v104 = qcar(v104);
    v35 = CC_moduntag(env, v104);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    v104 = stack[-1];
    v104 = cons(v35, v104);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-2];
    stack[-1] = v104;
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[0] = v104;
    goto v34;

v6:
    v35 = stack[-1];
    v104 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v35, v104);
    }
/* error exit handlers */
v86:
    popv(3);
    return nil;
}



/* Code for form1 */

static Lisp_Object MS_CDECL CC_form1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v232, v233, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "form1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form1");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v11,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v11;
    stack[-3] = v0;
/* end of prologue */

v29:
    v231 = stack[-3];
    if (!consp(v231)) goto v8;
    v231 = stack[-3];
    v231 = qcar(v231);
    if (!consp(v231)) goto v67;
    v233 = stack[-3];
    v232 = stack[-2];
    v231 = stack[-1];
    {
        popv(6);
        fn = elt(env, 27); /* form2 */
        return (*qfnn(fn))(qenv(fn), 3, v233, v232, v231);
    }

v67:
    v231 = stack[-3];
    v231 = qcar(v231);
    if (symbolp(v231)) goto v94;
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = elt(env, 4); /* "operator" */
    fn = elt(env, 28); /* typerr */
    v231 = (*qfn2(fn))(qenv(fn), v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    goto v236;

v236:
    v232 = stack[-1];
    v231 = elt(env, 7); /* symbolic */
    if (v232 == v231) goto v237;
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = elt(env, 19); /* opfn */
    v231 = Lflagp(nil, v232, v231);
    env = stack[-5];
    if (!(v231 == nil)) goto v237;

v238:
    v231 = stack[-3];
    v233 = qcdr(v231);
    v232 = stack[-2];
    v231 = stack[-1];
    fn = elt(env, 29); /* formlis */
    v231 = (*qfnn(fn))(qenv(fn), 3, v233, v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    stack[-4] = v231;
    v232 = stack[-4];
    v231 = stack[-3];
    v231 = qcdr(v231);
    if (equal(v232, v231)) goto v239;
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = stack[-4];
    v231 = cons(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    goto v240;

v240:
    stack[0] = v231;
    v232 = stack[-1];
    v231 = elt(env, 7); /* symbolic */
    if (v232 == v231) goto v241;
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = elt(env, 13); /* stat */
    v231 = get(v232, v231);
    env = stack[-5];
    if (!(v231 == nil)) goto v241;
    v231 = stack[-3];
    v231 = qcdr(v231);
    if (v231 == nil) goto v242;
    v231 = stack[-3];
    v231 = qcdr(v231);
    v232 = qcar(v231);
    v231 = elt(env, 20); /* quote */
    if (!consp(v232)) goto v242;
    v232 = qcar(v232);
    if (!(v232 == v231)) goto v242;
    v231 = qvalue(elt(env, 21)); /* !*micro!-version */
    if (v231 == nil) goto v241;
    v231 = qvalue(elt(env, 22)); /* !*defn */
    if (!(v231 == nil)) goto v241;

v242:
    v232 = stack[0];
    v231 = stack[-2];
    fn = elt(env, 30); /* intexprnp */
    v231 = (*qfn2(fn))(qenv(fn), v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    if (v231 == nil) goto v243;
    v231 = qvalue(elt(env, 23)); /* !*composites */
    if (!(v231 == nil)) goto v243;
    v232 = qvalue(elt(env, 24)); /* current!-modulus */
    v231 = (Lisp_Object)17; /* 1 */
    if (!(v232 == v231)) goto v243;

v241:
    v232 = stack[0];
    v231 = stack[-1];
    {
        popv(6);
        fn = elt(env, 31); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v232, v231);
    }

v243:
    v232 = stack[-1];
    v231 = elt(env, 25); /* algebraic */
    if (v232 == v231) goto v244;
    v234 = stack[0];
    v233 = stack[-2];
    v232 = stack[-1];
    v231 = elt(env, 25); /* algebraic */
    {
        popv(6);
        fn = elt(env, 32); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v234, v233, v232, v231);
    }

v244:
    stack[0] = elt(env, 26); /* list */
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = stack[-2];
    fn = elt(env, 33); /* algid */
    v232 = (*qfn2(fn))(qenv(fn), v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    v231 = stack[-4];
    {
        Lisp_Object v245 = stack[0];
        popv(6);
        return list2star(v245, v232, v231);
    }

v239:
    v231 = stack[-3];
    goto v240;

v237:
    v231 = stack[-3];
    fn = elt(env, 34); /* argnochk */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    goto v238;

v94:
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = elt(env, 5); /* comment */
    if (v232 == v231) goto v52;
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = elt(env, 6); /* noform */
    v231 = Lflagp(nil, v232, v231);
    env = stack[-5];
    if (!(v231 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v231 = stack[-3];
    v231 = qcar(v231);
    fn = elt(env, 35); /* arrayp */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    if (v231 == nil) goto v119;
    v232 = stack[-1];
    v231 = elt(env, 7); /* symbolic */
    if (!(v232 == v231)) goto v119;
    stack[0] = elt(env, 8); /* getel */
    v233 = stack[-3];
    v232 = stack[-2];
    v231 = stack[-1];
    fn = elt(env, 36); /* intargfn */
    v231 = (*qfnn(fn))(qenv(fn), 3, v233, v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    {
        Lisp_Object v246 = stack[0];
        popv(6);
        return list2(v246, v231);
    }

v119:
    v231 = stack[-3];
    v231 = qcdr(v231);
    if (v231 == nil) goto v247;
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = elt(env, 9); /* rtype */
    v232 = get(v232, v231);
    env = stack[-5];
    v231 = elt(env, 10); /* vector */
    if (v232 == v231) goto v248;
    v231 = stack[-3];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    v231 = Lsimple_vectorp(nil, v231);
    env = stack[-5];
    if (!(v231 == nil)) goto v248;
    v231 = stack[-3];
    v231 = qcdr(v231);
    v232 = qcar(v231);
    v231 = elt(env, 11); /* vecfn */
    v231 = Lflagpcar(nil, v232, v231);
    env = stack[-5];
    if (!(v231 == nil)) goto v248;

v247:
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = elt(env, 2); /* modefn */
    v231 = Lflagp(nil, v232, v231);
    env = stack[-5];
    if (v231 == nil) goto v249;
    v231 = stack[-3];
    v231 = qcdr(v231);
    v234 = qcar(v231);
    v233 = stack[-2];
    v232 = stack[-1];
    v231 = stack[-3];
    v231 = qcar(v231);
    {
        popv(6);
        fn = elt(env, 32); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v234, v233, v232, v231);
    }

v249:
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = elt(env, 12); /* formfn */
    v231 = get(v232, v231);
    env = stack[-5];
    stack[-4] = v231;
    if (v231 == nil) goto v250;
    v234 = stack[-4];
    v233 = stack[-3];
    v232 = stack[-2];
    v231 = stack[-1];
    v232 = Lapply3(nil, 4, v234, v233, v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    v231 = stack[-1];
    {
        popv(6);
        fn = elt(env, 31); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v232, v231);
    }

v250:
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = elt(env, 13); /* stat */
    v232 = get(v232, v231);
    env = stack[-5];
    v231 = elt(env, 14); /* rlis */
    if (v232 == v231) goto v251;
    v231 = stack[-3];
    v232 = qcar(v231);
    v231 = elt(env, 15); /* !*comma!* */
    if (!(v232 == v231)) goto v236;
    v231 = stack[-3];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    if (!consp(v231)) goto v252;
    v231 = stack[-3];
    v231 = qcdr(v231);
    v231 = qcdr(v231);
    v231 = qcar(v231);
    if (!(!consp(v231))) goto v252;
    v231 = stack[-3];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    v232 = qcar(v231);
    v231 = elt(env, 16); /* type */
    v231 = Lflagp(nil, v232, v231);
    env = stack[-5];
    if (v231 == nil) goto v252;
    v231 = stack[-3];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    v231 = qcar(v231);
    fn = elt(env, 37); /* blocktyperr */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    goto v236;

v252:
    stack[-4] = elt(env, 17); /* rlisp */
    stack[0] = (Lisp_Object)161; /* 10 */
    v232 = elt(env, 18); /* "Syntax error: , invalid after" */
    v231 = stack[-3];
    v231 = qcdr(v231);
    v231 = qcar(v231);
    v231 = list2(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    fn = elt(env, 38); /* rerror */
    v231 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    goto v236;

v251:
    v233 = stack[-3];
    v232 = stack[-2];
    v231 = stack[-1];
    fn = elt(env, 39); /* formrlis */
    v232 = (*qfnn(fn))(qenv(fn), 3, v233, v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    v231 = stack[-1];
    {
        popv(6);
        fn = elt(env, 31); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v232, v231);
    }

v248:
    v233 = stack[-3];
    v232 = stack[-2];
    v231 = stack[-1];
    {
        popv(6);
        fn = elt(env, 40); /* getvect */
        return (*qfnn(fn))(qenv(fn), 3, v233, v232, v231);
    }

v52:
    v231 = stack[-3];
    fn = elt(env, 41); /* lastpair */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-5];
    v233 = qcar(v231);
    v232 = stack[-2];
    v231 = stack[-1];
    stack[-3] = v233;
    stack[-2] = v232;
    stack[-1] = v231;
    goto v29;

v8:
    v231 = stack[-3];
    if (!(symbolp(v231))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v232 = stack[-3];
    v231 = elt(env, 1); /* ed */
    if (v232 == v231) goto v43;
    v232 = stack[-3];
    v231 = elt(env, 2); /* modefn */
    v231 = Lflagp(nil, v232, v231);
    env = stack[-5];
    if (v231 == nil) goto v32;
    v231 = stack[-3];
    {
        popv(6);
        fn = elt(env, 42); /* set!-global!-mode */
        return (*qfn1(fn))(qenv(fn), v231);
    }

v32:
    v232 = stack[-1];
    v231 = elt(env, 3); /* idfn */
    v231 = get(v232, v231);
    stack[-4] = v231;
    if (v231 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v233 = stack[-4];
    v232 = stack[-3];
    v231 = stack[-2];
        popv(6);
        return Lapply2(nil, 3, v233, v232, v231);

v43:
    v231 = stack[-3];
    popv(6);
    return ncons(v231);
/* error exit handlers */
v235:
    popv(6);
    return nil;
}



/* Code for variablesir */

static Lisp_Object MS_CDECL CC_variablesir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "variablesir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variablesir");
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
    v31 = qvalue(elt(env, 1)); /* char */
    v47 = elt(env, 2); /* (!/ o m b v a r) */
    if (equal(v31, v47)) goto v27;
    fn = elt(env, 4); /* omvir */
    v47 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-1];
    stack[0] = v47;
    fn = elt(env, 5); /* lex */
    v47 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-1];
    v47 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v77;
    v31 = stack[0];
    if (v31 == nil) goto v25;
    v31 = stack[0];
    popv(2);
    return cons(v31, v47);

v25:
    v31 = stack[0];
        popv(2);
        return Lappend(nil, v31, v47);

v27:
    v47 = nil;
    { popv(2); return onevalue(v47); }
/* error exit handlers */
v77:
    popv(2);
    return nil;
}



/* Code for list!-mgen */

static Lisp_Object CC_listKmgen(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list-mgen");
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
    v10 = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = nil; /* i */
    v21 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v21; /* i */
    v21 = v10;
    stack[0] = v21;
    goto v30;

v30:
    v21 = stack[0];
    if (v21 == nil) goto v9;
    v21 = stack[0];
    v21 = qcar(v21);
    v10 = v21;
    v21 = v10;
    if (!(!consp(v21))) goto v20;
    v21 = v10;
    fn = elt(env, 3); /* mgenp */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    if (v21 == nil) goto v20;
    v21 = qvalue(elt(env, 1)); /* i */
    v21 = add1(v21);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-2];
    qvalue(elt(env, 1)) = v21; /* i */
    goto v20;

v20:
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[0] = v21;
    goto v30;

v9:
    v21 = qvalue(elt(env, 1)); /* i */
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    { popv(3); return onevalue(v21); }
/* error exit handlers */
v96:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* i */
    popv(3);
    return nil;
}



/* Code for groebbuchcrit4t */

static Lisp_Object CC_groebbuchcrit4t(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47, v31, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebbuchcrit4t");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v11;
    v31 = v0;
/* end of prologue */

v40:
    v46 = v31;
    if (v46 == nil) goto v9;
    v46 = v47;
    if (v46 == nil) goto v9;
    v46 = v31;
    v32 = qcar(v46);
    v46 = (Lisp_Object)1; /* 0 */
    if (v32 == v46) goto v16;
    v46 = v47;
    v32 = qcar(v46);
    v46 = (Lisp_Object)1; /* 0 */
    if (v32 == v46) goto v16;
    v46 = qvalue(elt(env, 2)); /* t */
    return onevalue(v46);

v16:
    v46 = v31;
    v46 = qcdr(v46);
    v31 = v46;
    v46 = v47;
    v46 = qcdr(v46);
    v47 = v46;
    goto v40;

v9:
    v46 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v46);
}



/* Code for gfrsq */

static Lisp_Object CC_gfrsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfrsq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v8 = v0;
/* end of prologue */
    v34 = v8;
    {
        fn = elt(env, 1); /* gfdot */
        return (*qfn2(fn))(qenv(fn), v34, v8);
    }
}



/* Code for !:dmpluslst */

static Lisp_Object CC_Tdmpluslst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmpluslst");
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
    v2 = v0;
/* end of prologue */
    v1 = v2;
    if (v1 == nil) goto v13;
    v1 = v2;
    v1 = qcdr(v1);
    if (v1 == nil) goto v9;
    v1 = v2;
    stack[0] = qcar(v1);
    v1 = v2;
    v1 = qcdr(v1);
    v1 = CC_Tdmpluslst(env, v1);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-1];
    {
        Lisp_Object v6 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:plus */
        return (*qfn2(fn))(qenv(fn), v6, v1);
    }

v9:
    v1 = v2;
    v1 = qcar(v1);
    { popv(2); return onevalue(v1); }

v13:
    v1 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v1); }
/* error exit handlers */
v24:
    popv(2);
    return nil;
}



/* Code for evalequal */

static Lisp_Object CC_evalequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v85, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v11;
    stack[-2] = v0;
/* end of prologue */
    v36 = stack[-2];
    fn = elt(env, 3); /* getrtype */
    stack[0] = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    stack[-3] = stack[0];
    v36 = stack[-1];
    fn = elt(env, 3); /* getrtype */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    if (equal(stack[0], v36)) goto v30;
    v36 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v36); }

v30:
    v36 = stack[-3];
    if (v36 == nil) goto v12;
    v85 = stack[-2];
    v36 = stack[-1];
    v36 = (equal(v85, v36) ? lisp_true : nil);
    { popv(5); return onevalue(v36); }

v12:
    v86 = elt(env, 2); /* difference */
    v85 = stack[-2];
    v36 = stack[-1];
    v36 = list3(v86, v85, v36);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    fn = elt(env, 4); /* reval */
    v36 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    stack[-3] = v36;
    if (is_number(v36)) goto v64;
    v36 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v36); }

v64:
    v36 = stack[-3];
        popv(5);
        return Lzerop(nil, v36);
/* error exit handlers */
v39:
    popv(5);
    return nil;
}



/* Code for sf_member */

static Lisp_Object CC_sf_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sf_member");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v11;
    stack[-1] = v0;
/* end of prologue */

v29:
    v66 = stack[0];
    if (!consp(v66)) goto v40;
    v66 = stack[0];
    v66 = qcar(v66);
    if (!consp(v66)) goto v40;
    v65 = stack[-1];
    v66 = stack[0];
    v66 = qcar(v66);
    v66 = qcar(v66);
    v66 = qcar(v66);
    fn = elt(env, 2); /* mvar_member */
    v66 = (*qfn2(fn))(qenv(fn), v65, v66);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    if (!(v66 == nil)) { popv(3); return onevalue(v66); }
    v65 = stack[-1];
    v66 = stack[0];
    v66 = qcar(v66);
    v66 = qcdr(v66);
    v66 = CC_sf_member(env, v65, v66);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-2];
    if (!(v66 == nil)) { popv(3); return onevalue(v66); }
    v65 = stack[-1];
    v66 = stack[0];
    v66 = qcdr(v66);
    stack[-1] = v65;
    stack[0] = v66;
    goto v29;

v40:
    v66 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v66); }
/* error exit handlers */
v35:
    popv(3);
    return nil;
}



/* Code for mo_times_ei */

static Lisp_Object CC_mo_times_ei(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v47, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_times_ei");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v31 = v11;
    v47 = v0;
/* end of prologue */
    v46 = v31;
    v46 = qcar(v46);
    if (v46 == nil) goto v40;
    v46 = v31;
    v46 = qcar(v46);
    v46 = qcar(v46);
    v46 = (Lisp_Object)(int32_t)((int32_t)v47 + (int32_t)v46 - TAG_FIXNUM);
    v47 = v31;
    v47 = qcar(v47);
    v47 = qcdr(v47);
    v46 = cons(v46, v47);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-1];
    goto v21;

v21:
    stack[0] = v46;
    fn = elt(env, 1); /* mo!=deglist */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v77;
    {
        Lisp_Object v60 = stack[0];
        popv(2);
        return cons(v60, v46);
    }

v40:
    v46 = v47;
    v46 = ncons(v46);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-1];
    goto v21;
/* error exit handlers */
v77:
    popv(2);
    return nil;
}



/* Code for general!-expt!-mod!-p */

static Lisp_Object CC_generalKexptKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-expt-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v121 = v11;
    stack[0] = v0;
/* end of prologue */
    v54 = v121;
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) goto v40;
    v54 = v121;
    v53 = (Lisp_Object)17; /* 1 */
    if (v54 == v53) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v54 = v121;
    v53 = (Lisp_Object)33; /* 2 */
    v53 = Ldivide(nil, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    stack[-1] = v53;
    v54 = stack[0];
    v53 = stack[-1];
    v53 = qcar(v53);
    v53 = CC_generalKexptKmodKp(env, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    v121 = v53;
    v53 = v121;
    v54 = v121;
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v53 = (*qfn2(fn))(qenv(fn), v53, v54);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-2];
    v121 = v53;
    v53 = stack[-1];
    v54 = qcdr(v53);
    v53 = (Lisp_Object)1; /* 0 */
    if (v54 == v53) { popv(3); return onevalue(v121); }
    v54 = v121;
    v53 = stack[0];
    fn = elt(env, 1); /* general!-times!-mod!-p */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v55;
    v121 = v53;
    { popv(3); return onevalue(v121); }

v40:
    v53 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v53); }
/* error exit handlers */
v55:
    popv(3);
    return nil;
}



/* Code for formc */

static Lisp_Object MS_CDECL CC_formc(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v11,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v139, v75, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formc");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formc");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v11,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v11;
    stack[-2] = v0;
/* end of prologue */
    v125 = qvalue(elt(env, 1)); /* !*rlisp88 */
    if (v125 == nil) goto v28;
    v139 = stack[-2];
    v125 = elt(env, 2); /* modefn */
    v125 = Lflagpcar(nil, v139, v125);
    env = stack[-3];
    if (v125 == nil) goto v28;
    v125 = stack[-2];
    v139 = qcar(v125);
    v125 = elt(env, 3); /* symbolic */
    if (v139 == v125) goto v28;
    v139 = elt(env, 4); /* "algebraic expression" */
    v125 = elt(env, 5); /* "Rlisp88 form" */
    {
        popv(4);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v139, v125);
    }

v28:
    v139 = stack[0];
    v125 = elt(env, 6); /* algebraic */
    if (!(v139 == v125)) goto v87;
    v139 = stack[-2];
    v125 = stack[-1];
    fn = elt(env, 8); /* intexprnp */
    v125 = (*qfn2(fn))(qenv(fn), v139, v125);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-3];
    if (!(v125 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v87:
    v100 = stack[-2];
    v75 = stack[-1];
    v139 = elt(env, 3); /* symbolic */
    v125 = stack[0];
    {
        popv(4);
        fn = elt(env, 9); /* convertmode */
        return (*qfnn(fn))(qenv(fn), 4, v100, v75, v139, v125);
    }
/* error exit handlers */
v121:
    popv(4);
    return nil;
}



/* Code for ibalp_simpterm */

static Lisp_Object CC_ibalp_simpterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_simpterm");
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
    stack[0] = v0;
/* end of prologue */

v29:
    v93 = stack[0];
    if (!consp(v93)) goto v15;
    v93 = stack[0];
    v93 = qcar(v93);
    stack[-1] = v93;
    v93 = stack[-1];
    fn = elt(env, 3); /* ibalp_boolfp */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    if (v93 == nil) goto v4;
    stack[-4] = stack[-1];
    v93 = stack[0];
    v93 = qcdr(v93);
    stack[-3] = v93;
    v93 = stack[-3];
    if (v93 == nil) goto v22;
    v93 = stack[-3];
    v93 = qcar(v93);
    v93 = CC_ibalp_simpterm(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    stack[-1] = v93;
    stack[-2] = v93;
    goto v7;

v7:
    v93 = stack[-3];
    v93 = qcdr(v93);
    stack[-3] = v93;
    v93 = stack[-3];
    if (v93 == nil) goto v81;
    stack[0] = stack[-1];
    v93 = stack[-3];
    v93 = qcar(v93);
    v93 = CC_ibalp_simpterm(env, v93);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    v93 = ncons(v93);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    v93 = Lrplacd(nil, stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    v93 = stack[-1];
    v93 = qcdr(v93);
    stack[-1] = v93;
    goto v7;

v81:
    v93 = stack[-2];
    goto v78;

v78:
    {
        Lisp_Object v74 = stack[-4];
        popv(6);
        return cons(v74, v93);
    }

v22:
    v93 = qvalue(elt(env, 1)); /* nil */
    goto v78;

v4:
    v93 = stack[0];
    fn = elt(env, 4); /* reval */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    stack[0] = v93;
    v71 = stack[0];
    v93 = stack[-1];
    if (!consp(v71)) goto v139;
    v71 = qcar(v71);
    if (!(v71 == v93)) goto v139;
    v71 = stack[-1];
    v93 = elt(env, 2); /* "Boolean function" */
    fn = elt(env, 5); /* typerr */
    v93 = (*qfn2(fn))(qenv(fn), v71, v93);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    goto v139;

v139:
    v93 = stack[0];
    stack[0] = v93;
    goto v29;

v15:
    v93 = stack[0];
    {
        popv(6);
        fn = elt(env, 6); /* ibalp_simpatom */
        return (*qfn1(fn))(qenv(fn), v93);
    }
/* error exit handlers */
v73:
    popv(6);
    return nil;
}



/* Code for !*!*a2s */

static Lisp_Object CC_HHa2s(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v11)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for **a2s");
#endif
    if (stack >= stacklimit)
    {
        push2(v11,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v103 = v11;
    stack[-3] = v0;
/* end of prologue */
    v103 = stack[-3];
    if (v103 == nil) goto v40;
    v102 = stack[-3];
    v103 = elt(env, 2); /* nochange */
    v103 = Lflagpcar(nil, v102, v103);
    env = stack[-5];
    if (v103 == nil) goto v21;
    v103 = stack[-3];
    v102 = qcar(v103);
    v103 = elt(env, 3); /* getel */
    if (!(v102 == v103)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v21:
    v102 = elt(env, 4); /* random */
    v103 = stack[-3];
    fn = elt(env, 11); /* smember */
    v103 = (*qfn2(fn))(qenv(fn), v102, v103);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-5];
    if (v103 == nil) goto v121;
    stack[-4] = elt(env, 5); /* lambda */
    stack[-2] = elt(env, 6); /* (!*uncached) */
    stack[-1] = elt(env, 7); /* progn */
    stack[0] = elt(env, 8); /* (declare (special !*uncached)) */
    v102 = qvalue(elt(env, 9)); /* !*!*a2sfn */
    v103 = stack[-3];
    v103 = list2(v102, v103);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-5];
    v103 = list3(stack[-1], stack[0], v103);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-5];
    v103 = list3(stack[-4], stack[-2], v103);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-5];
    v102 = qvalue(elt(env, 10)); /* t */
    popv(6);
    return list2(v103, v102);

v121:
    v102 = qvalue(elt(env, 9)); /* !*!*a2sfn */
    v103 = stack[-3];
    popv(6);
    return list2(v102, v103);

v40:
    v103 = elt(env, 1); /* "tell Hearn!!" */
    {
        popv(6);
        fn = elt(env, 12); /* rederr */
        return (*qfn1(fn))(qenv(fn), v103);
    }
/* error exit handlers */
v109:
    popv(6);
    return nil;
}



setup_type const u13_setup[] =
{
    {"nzeros",                  CC_nzeros,      too_many_1,    wrong_no_1},
    {"pv_times1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_pv_times1},
    {"raiseind:",               CC_raiseindT,   too_many_1,    wrong_no_1},
    {"ord2",                    too_few_2,      CC_ord2,       wrong_no_2},
    {"findremainder",           too_few_2,      CC_findremainder,wrong_no_2},
    {"freevarinexptchk",        CC_freevarinexptchk,too_many_1,wrong_no_1},
    {"rl_simpbop",              CC_rl_simpbop,  too_many_1,    wrong_no_1},
    {"find_sub_df",             too_few_2,      CC_find_sub_df,wrong_no_2},
    {"revalx",                  CC_revalx,      too_many_1,    wrong_no_1},
    {"simpindexvar",            CC_simpindexvar,too_many_1,    wrong_no_1},
    {"cstimes",                 too_few_2,      CC_cstimes,    wrong_no_2},
    {"mo_from_a",               CC_mo_from_a,   too_many_1,    wrong_no_1},
    {"ibalp_simpatom",          CC_ibalp_simpatom,too_many_1,  wrong_no_1},
    {"mathml2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mathml2},
    {"numeric-content",         CC_numericKcontent,too_many_1, wrong_no_1},
    {"primep",                  CC_primep,      too_many_1,    wrong_no_1},
    {"exptcompare",             too_few_2,      CC_exptcompare,wrong_no_2},
    {"constsml",                CC_constsml,    too_many_1,    wrong_no_1},
    {"vdpred",                  CC_vdpred,      too_many_1,    wrong_no_1},
    {"cut:mt",                  too_few_2,      CC_cutTmt,     wrong_no_2},
    {"gpexp1p",                 CC_gpexp1p,     too_many_1,    wrong_no_1},
    {"deleteall",               too_few_2,      CC_deleteall,  wrong_no_2},
    {"mkarray1",                too_few_2,      CC_mkarray1,   wrong_no_2},
    {"subsetp",                 too_few_2,      CC_subsetp,    wrong_no_2},
    {"general-reduce-mod-p",    CC_generalKreduceKmodKp,too_many_1,wrong_no_1},
    {"vintersection",           too_few_2,      CC_vintersection,wrong_no_2},
    {"ibalp_istotal",           CC_ibalp_istotal,too_many_1,   wrong_no_1},
    {"attributesml",            too_few_2,      CC_attributesml,wrong_no_2},
    {"maxtype",                 CC_maxtype,     too_many_1,    wrong_no_1},
    {"*wedgepf2pf",             CC_Hwedgepf2pf, too_many_1,    wrong_no_1},
    {"prepreform",              CC_prepreform,  too_many_1,    wrong_no_1},
    {"class",                   CC_class,       too_many_1,    wrong_no_1},
    {"expt-mod-p",              too_few_2,      CC_exptKmodKp, wrong_no_2},
    {"extmult",                 too_few_2,      CC_extmult,    wrong_no_2},
    {"ibalp_vmember",           too_few_2,      CC_ibalp_vmember,wrong_no_2},
    {"nary",                    too_few_2,      CC_nary,       wrong_no_2},
    {"ldt-tvar",                CC_ldtKtvar,    too_many_1,    wrong_no_1},
    {"add_minus",               CC_add_minus,   too_many_1,    wrong_no_1},
    {"xord_deglex",             too_few_2,      CC_xord_deglex,wrong_no_2},
    {"reduce_pv0",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduce_pv0},
    {"ibalp_tvb",               too_few_2,      CC_ibalp_tvb,  wrong_no_2},
    {"vdp_poly",                CC_vdp_poly,    too_many_1,    wrong_no_1},
    {"variableom",              CC_variableom,  too_many_1,    wrong_no_1},
    {"redcodmat",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_redcodmat},
    {"bcplus?",                 CC_bcplusW,     too_many_1,    wrong_no_1},
    {"lid",                     CC_lid,         too_many_1,    wrong_no_1},
    {"evaluate1",               too_few_2,      CC_evaluate1,  wrong_no_2},
    {"indordp",                 too_few_2,      CC_indordp,    wrong_no_2},
    {"zero-roads",              CC_zeroKroads,  too_many_1,    wrong_no_1},
    {"dssoc",                   too_few_2,      CC_dssoc,      wrong_no_2},
    {"cl_simplat",              too_few_2,      CC_cl_simplat, wrong_no_2},
    {"qsort",                   CC_qsort,       too_many_1,    wrong_no_1},
    {"squared+matrix+p",        CC_squaredLmatrixLp,too_many_1,wrong_no_1},
    {"ibalp_vequal",            too_few_2,      CC_ibalp_vequal,wrong_no_2},
    {"rl_ordatp",               too_few_2,      CC_rl_ordatp,  wrong_no_2},
    {"stats_getargs",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_stats_getargs},
    {"vdpzero",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpzero},
    {"cdarx",                   CC_cdarx,       too_many_1,    wrong_no_1},
    {"setel",                   too_few_2,      CC_setel,      wrong_no_2},
    {"mkkl",                    too_few_2,      CC_mkkl,       wrong_no_2},
    {"qremd",                   too_few_2,      CC_qremd,      wrong_no_2},
    {"moduntag",                CC_moduntag,    too_many_1,    wrong_no_1},
    {"form1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_form1},
    {"variablesir",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_variablesir},
    {"list-mgen",               CC_listKmgen,   too_many_1,    wrong_no_1},
    {"groebbuchcrit4t",         too_few_2,      CC_groebbuchcrit4t,wrong_no_2},
    {"gfrsq",                   CC_gfrsq,       too_many_1,    wrong_no_1},
    {":dmpluslst",              CC_Tdmpluslst,  too_many_1,    wrong_no_1},
    {"evalequal",               too_few_2,      CC_evalequal,  wrong_no_2},
    {"sf_member",               too_few_2,      CC_sf_member,  wrong_no_2},
    {"mo_times_ei",             too_few_2,      CC_mo_times_ei,wrong_no_2},
    {"general-expt-mod-p",      too_few_2,      CC_generalKexptKmodKp,wrong_no_2},
    {"formc",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_formc},
    {"ibalp_simpterm",          CC_ibalp_simpterm,too_many_1,  wrong_no_1},
    {"**a2s",                   too_few_2,      CC_HHa2s,      wrong_no_2},
    {NULL, (one_args *)"u13", (two_args *)"10978 2848584 8173505", 0}
};

/* end of generated code */
