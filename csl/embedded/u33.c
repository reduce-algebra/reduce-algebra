
/* $destdir/generated-c\u33.c Machine generated C code */

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


/* Code for rand!-mons!-sparse */

static Lisp_Object MS_CDECL CC_randKmonsKsparse(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rand-mons-sparse");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rand-mons-sparse");
#endif
    if (stack >= stacklimit)
    {
        push5(v4,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v3;
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    stack[-7] = nil;
    v78 = stack[0];
    if (v78 == nil) goto v80;
    v79 = (Lisp_Object)17; /* 1 */
    v78 = stack[-1];
    v78 = difference2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = plus2(stack[-2], v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    goto v82;

v82:
    stack[-2] = v78;
    v79 = v78;
    v78 = stack[-3];
    fn = elt(env, 2); /* min */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    fn = elt(env, 3); /* rand!-comb */
    v78 = (*qfn2(fn))(qenv(fn), stack[-2], v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v79 = v78;
    v78 = stack[0];
    if (v78 == nil) goto v83;
    v78 = v79;
    stack[-5] = v78;
    v78 = stack[-5];
    if (v78 == nil) goto v84;
    v78 = stack[-5];
    v78 = qcar(v78);
    stack[0] = stack[-8];
    v79 = v78;
    v78 = stack[-1];
    v78 = plus2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    fn = elt(env, 4); /* !*kp2f */
    v78 = (*qfn2(fn))(qenv(fn), stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    stack[-3] = v78;
    stack[-4] = v78;
    goto v85;

v85:
    v78 = stack[-5];
    v78 = qcdr(v78);
    stack[-5] = v78;
    v78 = stack[-5];
    if (v78 == nil) { Lisp_Object res = stack[-4]; popv(11); return onevalue(res); }
    stack[-2] = stack[-3];
    v78 = stack[-5];
    v78 = qcar(v78);
    stack[0] = stack[-8];
    v79 = v78;
    v78 = stack[-1];
    v78 = plus2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    fn = elt(env, 4); /* !*kp2f */
    v78 = (*qfn2(fn))(qenv(fn), stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = Lrplacd(nil, stack[-2], v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = stack[-3];
    v78 = qcdr(v78);
    stack[-3] = v78;
    goto v85;

v84:
    v78 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v78); }

v83:
    v78 = v79;
    stack[-6] = v78;
    v78 = stack[-6];
    if (v78 == nil) goto v86;
    v78 = stack[-6];
    v78 = qcar(v78);
    stack[-2] = v78;
    v78 = (Lisp_Object)17; /* 1 */
    stack[-1] = v78;
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v79 = stack[-2];
    v78 = stack[-7];
    v79 = plus2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = stack[-9];
    fn = elt(env, 5); /* inttovec */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = cons(stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    stack[-2] = v78;
    v78 = stack[-8];
    stack[0] = v78;
    goto v87;

v87:
    v78 = stack[0];
    if (v78 == nil) goto v88;
    v78 = stack[0];
    v78 = qcar(v78);
    v79 = v78;
    v78 = stack[-2];
    v78 = qcdr(v78);
    stack[-2] = v78;
    v78 = qcar(v78);
    fn = elt(env, 4); /* !*kp2f */
    v79 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = stack[-1];
    fn = elt(env, 6); /* multf */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    stack[-1] = v78;
    v78 = stack[0];
    v78 = qcdr(v78);
    stack[0] = v78;
    goto v87;

v88:
    v78 = stack[-1];
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    stack[-4] = v78;
    stack[-5] = v78;
    goto v89;

v89:
    v78 = stack[-6];
    v78 = qcdr(v78);
    stack[-6] = v78;
    v78 = stack[-6];
    if (v78 == nil) { Lisp_Object res = stack[-5]; popv(11); return onevalue(res); }
    stack[-3] = stack[-4];
    v78 = stack[-6];
    v78 = qcar(v78);
    stack[-2] = v78;
    v78 = (Lisp_Object)17; /* 1 */
    stack[-1] = v78;
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v79 = stack[-2];
    v78 = stack[-7];
    v79 = plus2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = stack[-9];
    fn = elt(env, 5); /* inttovec */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = cons(stack[0], v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    stack[-2] = v78;
    v78 = stack[-8];
    stack[0] = v78;
    goto v90;

v90:
    v78 = stack[0];
    if (v78 == nil) goto v91;
    v78 = stack[0];
    v78 = qcar(v78);
    v79 = v78;
    v78 = stack[-2];
    v78 = qcdr(v78);
    stack[-2] = v78;
    v78 = qcar(v78);
    fn = elt(env, 4); /* !*kp2f */
    v79 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = stack[-1];
    fn = elt(env, 6); /* multf */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    stack[-1] = v78;
    v78 = stack[0];
    v78 = qcdr(v78);
    stack[0] = v78;
    goto v90;

v91:
    v78 = stack[-1];
    v78 = ncons(v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = Lrplacd(nil, stack[-3], v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = stack[-4];
    v78 = qcdr(v78);
    stack[-4] = v78;
    goto v89;

v86:
    v78 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v78); }

v80:
    v78 = stack[-8];
    v78 = Llength(nil, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    stack[-9] = v78;
    v78 = stack[-1];
    v78 = (Lisp_Object)zerop(v78);
    v78 = v78 ? lisp_true : nil;
    env = stack[-10];
    if (v78 == nil) goto v92;
    v78 = (Lisp_Object)1; /* 0 */
    goto v93;

v93:
    stack[-7] = v78;
    v79 = stack[-9];
    v78 = stack[-2];
    v79 = plus2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = stack[-9];
    fn = elt(env, 7); /* binomial */
    v79 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = stack[-7];
    v78 = difference2(v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    goto v82;

v92:
    stack[-4] = stack[-9];
    v78 = stack[-1];
    v78 = sub1(v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v79 = plus2(stack[-4], v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    v78 = stack[-9];
    fn = elt(env, 7); /* binomial */
    v78 = (*qfn2(fn))(qenv(fn), v79, v78);
    nil = C_nil;
    if (exception_pending()) goto v81;
    env = stack[-10];
    goto v93;
/* error exit handlers */
v81:
    popv(11);
    return nil;
}



/* Code for strand!-alg!-top */

static Lisp_Object MS_CDECL CC_strandKalgKtop(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v101, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "strand-alg-top");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for strand-alg-top");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v101 = stack[-2];
    v100 = stack[0];
    fn = elt(env, 2); /* deletez1 */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[-2] = v100;
    v102 = stack[0];
    v101 = stack[-1];
    v100 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* color!-strand */
    v100 = (*qfnn(fn))(qenv(fn), 3, v102, v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[0] = v100;
    v101 = stack[-2];
    v100 = stack[0];
    fn = elt(env, 4); /* contract!-strand */
    v100 = (*qfn2(fn))(qenv(fn), v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    stack[-2] = v100;
    v102 = stack[-2];
    v101 = stack[0];
    v100 = qvalue(elt(env, 1)); /* nil */
    {
        popv(4);
        fn = elt(env, 5); /* dstr!-to!-alg */
        return (*qfnn(fn))(qenv(fn), 3, v102, v101, v100);
    }
/* error exit handlers */
v103:
    popv(4);
    return nil;
}



/* Code for reduce!-weights */

static Lisp_Object MS_CDECL CC_reduceKweights(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "reduce-weights");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduce-weights");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v2;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = nil;
    v116 = stack[-5];
    v115 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v115 = (*qfn2(fn))(qenv(fn), v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-2] = v115;
    goto v118;

v118:
    v116 = stack[-5];
    v115 = stack[-4];
    fn = elt(env, 3); /* mv!-domainlist!-!+ */
    v115 = (*qfn2(fn))(qenv(fn), v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-1] = v115;
    v116 = stack[-1];
    v115 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v115 = (*qfn2(fn))(qenv(fn), v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[0] = v115;
    v116 = stack[0];
    v115 = stack[-2];
    fn = elt(env, 4); /* red!-weight!-less!-p */
    v115 = (*qfn2(fn))(qenv(fn), v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    if (v115 == nil) goto v119;
    v115 = qvalue(elt(env, 1)); /* t */
    stack[-6] = v115;
    v115 = stack[-1];
    stack[-5] = v115;
    v115 = stack[0];
    stack[-2] = v115;
    goto v118;

v119:
    v115 = stack[-6];
    if (!(v115 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }

v120:
    v116 = stack[-5];
    v115 = stack[-4];
    fn = elt(env, 5); /* mv!-domainlist!-!- */
    v115 = (*qfn2(fn))(qenv(fn), v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[-1] = v115;
    v116 = stack[-1];
    v115 = stack[-3];
    fn = elt(env, 2); /* red!-weight */
    v115 = (*qfn2(fn))(qenv(fn), v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    stack[0] = v115;
    v116 = stack[0];
    v115 = stack[-2];
    fn = elt(env, 4); /* red!-weight!-less!-p */
    v115 = (*qfn2(fn))(qenv(fn), v116, v115);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-7];
    if (v115 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v115 = stack[-1];
    stack[-5] = v115;
    v115 = stack[0];
    stack[-2] = v115;
    goto v120;
/* error exit handlers */
v117:
    popv(8);
    return nil;
}



/* Code for rationalizef */

static Lisp_Object CC_rationalizef(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rationalizef");
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
    v86 = stack[-2];
    fn = elt(env, 9); /* kernels */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    stack[0] = v86;
    stack[-3] = v86;
    goto v105;

v105:
    v86 = stack[-3];
    if (v86 == nil) goto v140;
    v86 = stack[-3];
    v86 = qcar(v86);
    stack[-1] = v86;
    v138 = stack[-1];
    v86 = elt(env, 1); /* expt */
    if (!consp(v138)) goto v141;
    v138 = qcar(v138);
    if (!(v138 == v86)) goto v141;
    v86 = stack[-1];
    v86 = qcdr(v86);
    v86 = qcdr(v86);
    v138 = qcar(v86);
    v86 = elt(env, 2); /* quotient */
    if (!consp(v138)) goto v141;
    v138 = qcar(v138);
    if (!(v138 == v86)) goto v141;
    v138 = stack[0];
    v86 = stack[-1];
    v86 = qcdr(v86);
    fn = elt(env, 10); /* lowertowerp */
    v86 = (*qfn2(fn))(qenv(fn), v138, v86);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    if (!(v86 == nil)) goto v114;

v141:
    v138 = stack[-1];
    v86 = elt(env, 4); /* i */
    if (v138 == v86) goto v142;
    v138 = stack[-1];
    v86 = elt(env, 1); /* expt */
    if (!consp(v138)) goto v82;
    v138 = qcar(v138);
    if (!(v138 == v86)) goto v82;
    v86 = stack[-1];
    v86 = qcdr(v86);
    v86 = qcdr(v86);
    v138 = qcar(v86);
    v86 = elt(env, 5); /* (quotient 1 2) */
    if (!(equal(v138, v86))) goto v82;

v142:
    v138 = stack[-2];
    v86 = stack[-1];
    fn = elt(env, 11); /* mkmain */
    v138 = (*qfn2(fn))(qenv(fn), v138, v86);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v86 = stack[-1];
    {
        popv(5);
        fn = elt(env, 12); /* conjquadratic */
        return (*qfn2(fn))(qenv(fn), v138, v86);
    }

v82:
    v138 = stack[-1];
    v86 = elt(env, 6); /* sqrt */
    if (!consp(v138)) goto v143;
    v138 = qcar(v138);
    if (v138 == v86) goto v142;
    else goto v143;

v143:
    v138 = stack[-1];
    v86 = elt(env, 1); /* expt */
    if (!consp(v138)) goto v144;
    v138 = qcar(v138);
    if (!(v138 == v86)) goto v144;
    v86 = stack[-1];
    v86 = qcdr(v86);
    v86 = qcdr(v86);
    v138 = qcar(v86);
    v86 = elt(env, 7); /* (quotient 1 3) */
    if (!(equal(v138, v86))) goto v144;
    v138 = stack[-2];
    v86 = stack[-1];
    fn = elt(env, 11); /* mkmain */
    v138 = (*qfn2(fn))(qenv(fn), v138, v86);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v86 = stack[-1];
    {
        popv(5);
        fn = elt(env, 13); /* conjcubic */
        return (*qfn2(fn))(qenv(fn), v138, v86);
    }

v144:
    v138 = stack[-1];
    v86 = elt(env, 1); /* expt */
    if (!consp(v138)) goto v114;
    v138 = qcar(v138);
    if (!(v138 == v86)) goto v114;
    v86 = stack[-1];
    v86 = qcdr(v86);
    v86 = qcdr(v86);
    v138 = qcar(v86);
    v86 = elt(env, 8); /* (quotient 1 4) */
    if (!(equal(v138, v86))) goto v114;
    v138 = stack[-2];
    v86 = stack[-1];
    fn = elt(env, 11); /* mkmain */
    v138 = (*qfn2(fn))(qenv(fn), v138, v86);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-4];
    v86 = stack[-1];
    {
        popv(5);
        fn = elt(env, 14); /* conjquartic */
        return (*qfn2(fn))(qenv(fn), v138, v86);
    }

v114:
    v86 = stack[-3];
    v86 = qcdr(v86);
    stack[-3] = v86;
    goto v105;

v140:
    v86 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v86); }
/* error exit handlers */
v139:
    popv(5);
    return nil;
}



/* Code for red_prepare */

static Lisp_Object CC_red_prepare(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_prepare");
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
    v74 = stack[-1];
    fn = elt(env, 1); /* bas_nr */
    stack[-2] = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    v74 = stack[-1];
    fn = elt(env, 2); /* bas_dpoly */
    stack[0] = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    v74 = stack[-1];
    fn = elt(env, 3); /* bas_rep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    v74 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* dp_from_ei */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    fn = elt(env, 5); /* dp_sum */
    v74 = (*qfn2(fn))(qenv(fn), stack[-1], v74);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    {
        Lisp_Object v137 = stack[-2];
        Lisp_Object v136 = stack[0];
        popv(4);
        fn = elt(env, 6); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v137, v136, v74);
    }
/* error exit handlers */
v147:
    popv(4);
    return nil;
}



/* Code for dv_skel2factor */

static Lisp_Object CC_dv_skel2factor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v82, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skel2factor");
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
    v115 = v1;
    stack[-4] = v0;
/* end of prologue */
    v82 = stack[-4];
    v82 = qcdr(v82);
    if (v82 == nil) goto v23;
    v82 = stack[-4];
    v82 = qcdr(v82);
    v82 = Lsublis(nil, v115, v82);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    stack[-5] = v82;
    v82 = stack[-5];
    fn = elt(env, 2); /* st_ad_numsorttree */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    stack[-5] = v82;
    v82 = stack[-5];
    v82 = qcdr(v82);
    fn = elt(env, 3); /* st_flatten */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    stack[-3] = v82;
    v82 = stack[-3];
    if (v82 == nil) goto v119;
    v82 = stack[-3];
    v82 = qcar(v82);
    fn = elt(env, 4); /* dv_ind2var */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    v82 = ncons(v82);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    stack[-1] = v82;
    stack[-2] = v82;
    goto v76;

v76:
    v82 = stack[-3];
    v82 = qcdr(v82);
    stack[-3] = v82;
    v82 = stack[-3];
    if (v82 == nil) goto v103;
    stack[0] = stack[-1];
    v82 = stack[-3];
    v82 = qcar(v82);
    fn = elt(env, 4); /* dv_ind2var */
    v82 = (*qfn1(fn))(qenv(fn), v82);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    v82 = ncons(v82);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    v82 = Lrplacd(nil, stack[0], v82);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-6];
    v82 = stack[-1];
    v82 = qcdr(v82);
    stack[-1] = v82;
    goto v76;

v103:
    v82 = stack[-2];
    goto v106;

v106:
    v115 = stack[-5];
    stack[0] = qcar(v115);
    v115 = stack[-4];
    v115 = qcar(v115);
    fn = elt(env, 5); /* dv_skel2factor1 */
    v82 = (*qfn2(fn))(qenv(fn), v115, v82);
    nil = C_nil;
    if (exception_pending()) goto v151;
    {
        Lisp_Object v152 = stack[0];
        popv(7);
        return cons(v152, v82);
    }

v119:
    v82 = qvalue(elt(env, 1)); /* nil */
    goto v106;

v23:
    v82 = stack[-4];
    v82 = qcar(v82);
    { popv(7); return onevalue(v82); }
/* error exit handlers */
v151:
    popv(7);
    return nil;
}



/* Code for small!-primep */

static Lisp_Object CC_smallKprimep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for small-primep");
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
/* copy arguments values to proper place */
    stack[-8] = v0;
/* end of prologue */
    v166 = stack[-8];
    v166 = Levenp(nil, v166);
    env = stack[-10];
    if (!(v166 == nil)) goto v118;
    v167 = stack[-8];
    v166 = (Lisp_Object)49; /* 3 */
    v167 = Cremainder(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    v166 = (Lisp_Object)1; /* 0 */
    if (v167 == v166) goto v118;
    v166 = stack[-8];
    v166 = sub1(v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    stack[-6] = v166;
    v166 = stack[-8];
    v166 = Lset_small_modulus(nil, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    stack[-3] = v166;
    v166 = (Lisp_Object)1; /* 0 */
    stack[-7] = v166;
    goto v169;

v169:
    v166 = stack[-6];
    v166 = Levenp(nil, v166);
    env = stack[-10];
    if (v166 == nil) goto v170;
    v167 = stack[-6];
    v166 = (Lisp_Object)33; /* 2 */
    v166 = quot2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    stack[-6] = v166;
    v166 = stack[-7];
    v166 = add1(v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    stack[-7] = v166;
    goto v169;

v170:
    v166 = (Lisp_Object)17; /* 1 */
    stack[-9] = v166;
    v166 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v166;
    goto v106;

v106:
    v166 = stack[-2];
    if (v166 == nil) goto v63;
    v167 = stack[-9];
    v166 = qvalue(elt(env, 3)); /* !*confidence!* */
    v166 = (Lisp_Object)lesseq2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    v166 = v166 ? lisp_true : nil;
    env = stack[-10];
    if (v166 == nil) goto v63;
    v167 = stack[-8];
    v166 = (Lisp_Object)33; /* 2 */
    v166 = difference2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    fn = elt(env, 4); /* random */
    v166 = (*qfn1(fn))(qenv(fn), v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    v166 = add1(v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    v167 = v166;
    v166 = stack[-6];
    v166 = Lmodular_expt(nil, v167, v166);
    env = stack[-10];
    stack[-5] = v166;
    v167 = stack[-5];
    v166 = (Lisp_Object)17; /* 1 */
    if (v167 == v166) goto v52;
    v166 = (Lisp_Object)17; /* 1 */
    stack[-1] = v166;
    goto v171;

v171:
    v167 = stack[-7];
    v166 = stack[-1];
    v166 = difference2(v167, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    v166 = Lminusp(nil, v166);
    env = stack[-10];
    if (v166 == nil) goto v56;
    v167 = stack[-5];
    v166 = (Lisp_Object)17; /* 1 */
    if (v167 == v166) goto v52;
    v166 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v166;
    goto v52;

v52:
    v166 = stack[-9];
    v166 = add1(v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    stack[-9] = v166;
    goto v106;

v56:
    v167 = stack[-5];
    v166 = stack[-5];
    v166 = Lmodular_times(nil, v167, v166);
    env = stack[-10];
    stack[-4] = v166;
    v167 = stack[-4];
    v166 = (Lisp_Object)17; /* 1 */
    if (!(v167 == v166)) goto v83;
    stack[0] = stack[-5];
    v166 = stack[-8];
    v166 = sub1(v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    if (equal(stack[0], v166)) goto v83;
    v167 = stack[-5];
    v166 = (Lisp_Object)17; /* 1 */
    if (v167 == v166) goto v83;
    v166 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v166;
    goto v126;

v126:
    v166 = stack[-1];
    v166 = add1(v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[-10];
    stack[-1] = v166;
    goto v171;

v83:
    v166 = stack[-4];
    stack[-5] = v166;
    goto v126;

v63:
    v166 = stack[-3];
    v166 = Lset_small_modulus(nil, v166);
    nil = C_nil;
    if (exception_pending()) goto v168;
    { Lisp_Object res = stack[-2]; popv(11); return onevalue(res); }

v118:
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v166); }
/* error exit handlers */
v168:
    popv(11);
    return nil;
}



/* Code for conditionml */

static Lisp_Object CC_conditionml(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conditionml");
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
    v172 = elt(env, 1); /* "<condition>" */
    fn = elt(env, 5); /* printout */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-1];
    v172 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 6); /* indent!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-1];
    v172 = stack[0];
    v172 = qcar(v172);
    fn = elt(env, 7); /* expression */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-1];
    v172 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 6); /* indent!* */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-1];
    v172 = elt(env, 4); /* "</condition>" */
    fn = elt(env, 5); /* printout */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v173;
    v172 = nil;
    { popv(2); return onevalue(v172); }
/* error exit handlers */
v173:
    popv(2);
    return nil;
}



/* Code for ps!:zerop!: */

static Lisp_Object CC_psTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:zerop:");
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
    v172 = v0;
/* end of prologue */
    fn = elt(env, 2); /* ps!:value */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[0];
    v174 = v172;
    v172 = v174;
    if (is_number(v172)) goto v175;
    v172 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v172); }

v175:
    v172 = v174;
        popv(1);
        return Lzerop(nil, v172);
/* error exit handlers */
v173:
    popv(1);
    return nil;
}



/* Code for groebreduceonestepint */

static Lisp_Object MS_CDECL CC_groebreduceonestepint(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v187, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "groebreduceonestepint");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebreduceonestepint");
#endif
    if (stack >= stacklimit)
    {
        push5(v4,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-4] = v3;
    stack[-3] = v2;
    stack[-6] = v1;
    stack[-2] = v0;
/* end of prologue */
    v186 = stack[-1];
    fn = elt(env, 7); /* vdpred */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[0] = v186;
    v187 = v186;
    v186 = v187;
    v186 = (v186 == nil ? lisp_true : nil);
    if (!(v186 == nil)) goto v146;
    v186 = v187;
    v186 = qcdr(v186);
    v186 = qcdr(v186);
    v186 = qcdr(v186);
    v186 = qcar(v186);
    v186 = (v186 == nil ? lisp_true : nil);
    goto v146;

v146:
    if (v186 == nil) goto v119;
    v186 = stack[-2];
    fn = elt(env, 7); /* vdpred */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[-2] = v186;
    v186 = stack[-6];
    qvalue(elt(env, 1)) = v186; /* secondvalue!* */
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v119:
    v187 = stack[-4];
    v186 = stack[-1];
    v186 = qcdr(v186);
    v186 = qcar(v186);
    fn = elt(env, 8); /* vevdif */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[-7] = v186;
    v186 = stack[-1];
    v186 = qcdr(v186);
    v186 = qcdr(v186);
    v186 = qcar(v186);
    stack[-5] = v186;
    v186 = qvalue(elt(env, 2)); /* !*groebdivide */
    if (v186 == nil) goto v134;
    v187 = stack[-3];
    v186 = stack[-5];
    fn = elt(env, 9); /* vbcgcd */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    goto v103;

v103:
    stack[-4] = v186;
    v187 = stack[-5];
    v186 = stack[-4];
    fn = elt(env, 10); /* vbcquot */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[-5] = v186;
    v187 = stack[-3];
    v186 = stack[-4];
    fn = elt(env, 10); /* vbcquot */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[-4] = v186;
    v186 = stack[-6];
    if (v186 == nil) goto v66;
    v186 = stack[-6];
    if (v186 == nil) goto v66;
    v186 = stack[-6];
    v186 = qcdr(v186);
    v186 = qcdr(v186);
    v186 = qcdr(v186);
    v186 = qcar(v186);
    if (v186 == nil) goto v66;
    v187 = stack[-6];
    v186 = stack[-5];
    fn = elt(env, 11); /* vdpvbcprod */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[-6] = v186;
    goto v66;

v66:
    v186 = qvalue(elt(env, 3)); /* !*groebprot */
    if (v186 == nil) goto v190;
    stack[-3] = stack[-5];
    v186 = stack[-4];
    fn = elt(env, 12); /* vbcneg */
    v188 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v187 = stack[-7];
    v186 = stack[-1];
    fn = elt(env, 13); /* groebreductionprotocol */
    v186 = (*qfnn(fn))(qenv(fn), 4, stack[-3], v188, v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    goto v190;

v190:
    v186 = stack[-2];
    fn = elt(env, 7); /* vdpred */
    stack[-3] = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[-2] = stack[-5];
    v187 = qvalue(elt(env, 4)); /* vdpvars!* */
    v186 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 14); /* vevmaptozero1 */
    stack[-1] = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v186 = stack[-4];
    fn = elt(env, 12); /* vbcneg */
    v187 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    v186 = stack[-7];
    fn = elt(env, 15); /* vdpilcomb1 */
    v186 = (*qfnn(fn))(qenv(fn), 6, stack[-3], stack[-2], stack[-1], stack[0], v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    stack[-2] = v186;
    v186 = stack[-6];
    qvalue(elt(env, 1)) = v186; /* secondvalue!* */
    v186 = stack[-5];
    qvalue(elt(env, 6)) = v186; /* thirdvalue!* */
    { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }

v134:
    v186 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 16); /* vbcfi */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-8];
    goto v103;
/* error exit handlers */
v189:
    popv(9);
    return nil;
}



/* Code for reset_opnums */

static Lisp_Object MS_CDECL CC_reset_opnums(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v193, v63;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "reset_opnums");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reset_opnums");
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
    v192 = qvalue(elt(env, 1)); /* oporder!* */
    stack[-4] = v192;
    v192 = (Lisp_Object)17; /* 1 */
    stack[-3] = v192;
    goto v62;

v62:
    v192 = stack[-4];
    if (v192 == nil) goto v98;
    v192 = stack[-4];
    v192 = qcar(v192);
    v193 = v192;
    v192 = stack[-4];
    v192 = qcdr(v192);
    stack[-4] = v192;
    v192 = v193;
    if (symbolp(v192)) goto v97;
    v192 = v193;
    v192 = qcar(v192);
    stack[-2] = v192;
    v192 = v193;
    v192 = qcdr(v192);
    goto v110;

v110:
    stack[-1] = stack[-2];
    stack[0] = elt(env, 3); /* opnum */
    v193 = v192;
    v192 = stack[-3];
    v63 = cons(v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    v193 = stack[-2];
    v192 = elt(env, 3); /* opnum */
    v192 = get(v193, v192);
    env = stack[-5];
    fn = elt(env, 4); /* !*xadd */
    v192 = (*qfn2(fn))(qenv(fn), v63, v192);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    v192 = Lputprop(nil, 3, stack[-1], stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    v192 = stack[-3];
    v192 = add1(v192);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-5];
    stack[-3] = v192;
    goto v62;

v97:
    v192 = v193;
    stack[-2] = v192;
    v192 = qvalue(elt(env, 2)); /* nil */
    goto v110;

v98:
    v192 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v192); }
/* error exit handlers */
v65:
    popv(6);
    return nil;
}



/* Code for mv2sf */

static Lisp_Object CC_mv2sf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v120, v196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv2sf");
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
    goto v105;

v105:
    v141 = stack[-1];
    if (v141 == nil) goto v62;
    v141 = stack[-1];
    v141 = qcar(v141);
    v196 = qcar(v141);
    v141 = stack[-1];
    v141 = qcar(v141);
    v120 = qcdr(v141);
    v141 = stack[0];
    fn = elt(env, 2); /* mv2sf1 */
    v120 = (*qfnn(fn))(qenv(fn), 3, v196, v120, v141);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    v141 = stack[-2];
    v141 = cons(v120, v141);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    stack[-2] = v141;
    v141 = stack[-1];
    v141 = qcdr(v141);
    stack[-1] = v141;
    goto v105;

v62:
    v141 = qvalue(elt(env, 1)); /* nil */
    v120 = v141;
    goto v23;

v23:
    v141 = stack[-2];
    if (v141 == nil) { popv(4); return onevalue(v120); }
    v141 = stack[-2];
    v141 = qcar(v141);
    fn = elt(env, 3); /* addf */
    v141 = (*qfn2(fn))(qenv(fn), v141, v120);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-3];
    v120 = v141;
    v141 = stack[-2];
    v141 = qcdr(v141);
    stack[-2] = v141;
    goto v23;
/* error exit handlers */
v71:
    popv(4);
    return nil;
}



/* Code for mo_deletecomp */

static Lisp_Object CC_mo_deletecomp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_deletecomp");
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
    v100 = v0;
/* end of prologue */
    v101 = v100;
    v101 = qcar(v101);
    if (v101 == nil) { popv(2); return onevalue(v100); }
    v101 = v100;
    v101 = qcar(v101);
    v101 = qcdr(v101);
    if (v101 == nil) goto v172;
    v101 = (Lisp_Object)1; /* 0 */
    v100 = qcar(v100);
    v100 = qcdr(v100);
    v100 = cons(v101, v100);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    stack[0] = v100;
    fn = elt(env, 2); /* mo!=deglist */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v170;
    {
        Lisp_Object v169 = stack[0];
        popv(2);
        return cons(v169, v100);
    }

v172:
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v100 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* mo!=deglist */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v170;
    {
        Lisp_Object v133 = stack[0];
        popv(2);
        return cons(v133, v100);
    }
/* error exit handlers */
v170:
    popv(2);
    return nil;
}



/* Code for pst_mkpst */

static Lisp_Object CC_pst_mkpst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_mkpst");
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
    v140 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* pst_mkpst1 */
    v140 = (*qfn1(fn))(qenv(fn), v140);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    v140 = cons(stack[0], v140);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* pst_equitable */
        return (*qfn1(fn))(qenv(fn), v140);
    }
/* error exit handlers */
v99:
    popv(2);
    return nil;
}



/* Code for maxfrom */

static Lisp_Object CC_maxfrom(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxfrom");
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
    v172 = v1;
    v174 = v0;
/* end of prologue */
    stack[0] = v174;
    v174 = add1(v172);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-1];
    v172 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v114 = stack[0];
        popv(2);
        fn = elt(env, 1); /* maxfrom1 */
        return (*qfnn(fn))(qenv(fn), 3, v114, v174, v172);
    }
/* error exit handlers */
v113:
    popv(2);
    return nil;
}



/* Code for get!-min!-degreelist */

static Lisp_Object CC_getKminKdegreelist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-min-degreelist");
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
    v198 = v0;
/* end of prologue */
    v129 = v198;
    if (v129 == nil) goto v4;
    v129 = v198;
    v129 = qcdr(v129);
    if (v129 == nil) goto v23;
    v129 = v198;
    v129 = qcar(v129);
    stack[0] = qcar(v129);
    v129 = v198;
    v129 = qcdr(v129);
    v129 = CC_getKminKdegreelist(env, v129);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    {
        Lisp_Object v190 = stack[0];
        popv(6);
        fn = elt(env, 2); /* taymindegreel */
        return (*qfn2(fn))(qenv(fn), v190, v129);
    }

v23:
    v129 = v198;
    v129 = qcar(v129);
    v129 = qcar(v129);
    stack[-4] = v129;
    v129 = stack[-4];
    if (v129 == nil) goto v74;
    v129 = stack[-4];
    v129 = qcar(v129);
    stack[0] = v129;
    v129 = (Lisp_Object)1; /* 0 */
    v198 = v129;
    goto v195;

v195:
    v129 = stack[0];
    if (v129 == nil) goto v135;
    v129 = stack[0];
    v129 = qcar(v129);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v129 = (*qfn2(fn))(qenv(fn), v129, v198);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    v198 = v129;
    v129 = stack[0];
    v129 = qcdr(v129);
    stack[0] = v129;
    goto v195;

v135:
    v129 = v198;
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    stack[-2] = v129;
    stack[-3] = v129;
    goto v113;

v113:
    v129 = stack[-4];
    v129 = qcdr(v129);
    stack[-4] = v129;
    v129 = stack[-4];
    if (v129 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v129 = stack[-4];
    v129 = qcar(v129);
    stack[0] = v129;
    v129 = (Lisp_Object)1; /* 0 */
    v198 = v129;
    goto v182;

v182:
    v129 = stack[0];
    if (v129 == nil) goto v150;
    v129 = stack[0];
    v129 = qcar(v129);
    fn = elt(env, 3); /* tayexp!-plus2 */
    v129 = (*qfn2(fn))(qenv(fn), v129, v198);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    v198 = v129;
    v129 = stack[0];
    v129 = qcdr(v129);
    stack[0] = v129;
    goto v182;

v150:
    v129 = v198;
    v129 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    v129 = Lrplacd(nil, stack[-1], v129);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-5];
    v129 = stack[-2];
    v129 = qcdr(v129);
    stack[-2] = v129;
    goto v113;

v74:
    v129 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v129); }

v4:
    v129 = elt(env, 0); /* get!-min!-degreelist */
    {
        popv(6);
        fn = elt(env, 4); /* confusion */
        return (*qfn1(fn))(qenv(fn), v129);
    }
/* error exit handlers */
v199:
    popv(6);
    return nil;
}



/* Code for mk_resimp_rep */

static Lisp_Object CC_mk_resimp_rep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_resimp_rep");
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
    v116 = stack[-5];
    fn = elt(env, 2); /* get_group_in */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-6] = v116;
    v116 = stack[-6];
    fn = elt(env, 3); /* get!*elements */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-4] = v116;
    v116 = stack[-4];
    if (v116 == nil) goto v114;
    v116 = stack[-4];
    v116 = qcar(v116);
    stack[0] = v116;
    v200 = v116;
    v116 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v116 = (*qfn2(fn))(qenv(fn), v200, v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+resimp!+mat */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v116 = list2(stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v116 = ncons(v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    stack[-2] = v116;
    stack[-3] = v116;
    goto v99;

v99:
    v116 = stack[-4];
    v116 = qcdr(v116);
    stack[-4] = v116;
    v116 = stack[-4];
    if (v116 == nil) goto v102;
    stack[-1] = stack[-2];
    v116 = stack[-4];
    v116 = qcar(v116);
    stack[0] = v116;
    v200 = v116;
    v116 = stack[-5];
    fn = elt(env, 4); /* get_rep_matrix_in */
    v116 = (*qfn2(fn))(qenv(fn), v200, v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    fn = elt(env, 5); /* mk!+resimp!+mat */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v116 = list2(stack[0], v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v116 = ncons(v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v116 = Lrplacd(nil, stack[-1], v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-7];
    v116 = stack[-2];
    v116 = qcdr(v116);
    stack[-2] = v116;
    goto v99;

v102:
    v116 = stack[-3];
    goto v98;

v98:
    stack[0] = v116;
    v116 = stack[-6];
    v200 = ncons(v116);
    nil = C_nil;
    if (exception_pending()) goto v201;
    v116 = stack[0];
        popv(8);
        return Lappend(nil, v200, v116);

v114:
    v116 = qvalue(elt(env, 1)); /* nil */
    goto v98;
/* error exit handlers */
v201:
    popv(8);
    return nil;
}



/* Code for limitom */

static Lisp_Object CC_limitom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v203, v163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for limitom");
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
    v203 = v0;
/* end of prologue */
    v202 = v203;
    v202 = qcdr(v202);
    v202 = qcdr(v202);
    v202 = qcar(v202);
    stack[-2] = v202;
    v202 = v203;
    v202 = qcdr(v202);
    v202 = qcdr(v202);
    v202 = qcdr(v202);
    v202 = qcar(v202);
    stack[0] = v202;
    v202 = v203;
    v202 = Lreverse(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = qcar(v202);
    stack[-3] = v202;
    v202 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 13); /* indent!* */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = elt(env, 3); /* "<OMS cd=""limit1"" name=""limit""/>" */
    fn = elt(env, 12); /* printout */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = stack[0];
    v203 = qcar(v202);
    v202 = elt(env, 4); /* lowlimit */
    if (!(v203 == v202)) goto v170;
    v202 = stack[0];
    v202 = qcdr(v202);
    v202 = qcar(v202);
    fn = elt(env, 14); /* objectom */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = elt(env, 5); /* "<OMS cd=""limit1"" name=""null""/>" */
    fn = elt(env, 12); /* printout */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    goto v170;

v170:
    v202 = stack[0];
    v203 = qcar(v202);
    v202 = elt(env, 6); /* condition */
    if (!(v203 == v202)) goto v148;
    v202 = stack[0];
    v202 = qcdr(v202);
    v202 = qcar(v202);
    v202 = Lreverse(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = qcar(v202);
    fn = elt(env, 14); /* objectom */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = stack[0];
    v202 = qcdr(v202);
    v202 = qcar(v202);
    v202 = qcdr(v202);
    v202 = qcar(v202);
    v202 = qcar(v202);
    v202 = qcdr(v202);
    v202 = qcar(v202);
    stack[0] = v202;
    v202 = elt(env, 7); /* "<OMS cd=""limit1"" name=""" */
    fn = elt(env, 12); /* printout */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = stack[0];
    v202 = Lprinc(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = elt(env, 8); /* """/>" */
    v202 = Lprinc(nil, v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    goto v148;

v148:
    stack[-1] = elt(env, 9); /* limit */
    stack[0] = qvalue(elt(env, 10)); /* nil */
    v163 = stack[-2];
    v203 = stack[-3];
    v202 = qvalue(elt(env, 10)); /* nil */
    v202 = list2star(v163, v203, v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = list2star(stack[-1], stack[0], v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    fn = elt(env, 15); /* lambdaom */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = qvalue(elt(env, 10)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-4];
    v202 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v204;
    v202 = nil;
    { popv(5); return onevalue(v202); }
/* error exit handlers */
v204:
    popv(5);
    return nil;
}



/* Code for dip2a */

static Lisp_Object CC_dip2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip2a");
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
    v99 = v0;
/* end of prologue */
    v98 = v99;
    if (v98 == nil) goto v4;
    v98 = v99;
    fn = elt(env, 1); /* dip2a1 */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dipreplus */
        return (*qfn1(fn))(qenv(fn), v98);
    }

v4:
    v98 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v98); }
/* error exit handlers */
v172:
    popv(1);
    return nil;
}



/* Code for natnump */

static Lisp_Object CC_natnump(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v145;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for natnump");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v145 = v0;
/* end of prologue */
    v114 = v145;
    v114 = integerp(v114);
    if (v114 == nil) goto v4;
    v114 = (Lisp_Object)1; /* 0 */
        return Lgeq(nil, v145, v114);

v4:
    v114 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v114);
}



/* Code for rdzchk */

static Lisp_Object MS_CDECL CC_rdzchk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rdzchk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rdzchk");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v207 = stack[-2];
    if (!consp(v207)) goto v99;
    v207 = stack[-2];
    v207 = qcdr(v207);
    v123 = qcar(v207);
    v207 = (Lisp_Object)1; /* 0 */
    if (v123 == v207) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v207 = stack[-1];
    v207 = qcdr(v207);
    v123 = qcar(v207);
    v207 = (Lisp_Object)1; /* 0 */
    v207 = (Lisp_Object)greaterp2(v123, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v207 = v207 ? lisp_true : nil;
    env = stack[-3];
    if (v207 == nil) goto v181;
    v207 = stack[0];
    v207 = qcdr(v207);
    v123 = qcar(v207);
    v207 = (Lisp_Object)1; /* 0 */
    v207 = (Lisp_Object)greaterp2(v123, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v207 = v207 ? lisp_true : nil;
    env = stack[-3];
    if (!(v207 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v181:
    v207 = stack[-1];
    v207 = qcdr(v207);
    v123 = qcar(v207);
    v207 = (Lisp_Object)1; /* 0 */
    v207 = (Lisp_Object)lessp2(v123, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v207 = v207 ? lisp_true : nil;
    env = stack[-3];
    if (v207 == nil) goto v126;
    v207 = stack[0];
    v207 = qcdr(v207);
    v123 = qcar(v207);
    v207 = (Lisp_Object)1; /* 0 */
    v207 = (Lisp_Object)lessp2(v123, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v207 = v207 ? lisp_true : nil;
    env = stack[-3];
    if (!(v207 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v126:
    v207 = stack[-2];
    fn = elt(env, 5); /* abs!: */
    stack[0] = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v207 = stack[-1];
    fn = elt(env, 5); /* abs!: */
    v123 = (*qfn1(fn))(qenv(fn), v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v207 = qvalue(elt(env, 3)); /* rd!-tolerance!* */
    fn = elt(env, 6); /* times!: */
    v207 = (*qfn2(fn))(qenv(fn), v123, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    fn = elt(env, 7); /* lessp!: */
    v207 = (*qfn2(fn))(qenv(fn), stack[0], v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    if (v207 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v207 = qvalue(elt(env, 4)); /* bfz!* */
    { popv(4); return onevalue(v207); }

v99:
    v123 = stack[-2];
    v207 = elt(env, 1); /* 0.0 */
    if (equal(v123, v207)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v123 = stack[-1];
    v207 = elt(env, 1); /* 0.0 */
    v207 = (Lisp_Object)greaterp2(v123, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v207 = v207 ? lisp_true : nil;
    env = stack[-3];
    if (v207 == nil) goto v95;
    v123 = stack[0];
    v207 = elt(env, 1); /* 0.0 */
    v207 = (Lisp_Object)greaterp2(v123, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v207 = v207 ? lisp_true : nil;
    env = stack[-3];
    if (!(v207 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v95:
    v123 = stack[-1];
    v207 = elt(env, 1); /* 0.0 */
    v207 = (Lisp_Object)lessp2(v123, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v207 = v207 ? lisp_true : nil;
    env = stack[-3];
    if (v207 == nil) goto v71;
    v123 = stack[0];
    v207 = elt(env, 1); /* 0.0 */
    v207 = (Lisp_Object)lessp2(v123, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v207 = v207 ? lisp_true : nil;
    env = stack[-3];
    if (!(v207 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v71:
    v207 = stack[-2];
    stack[0] = Labsval(nil, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v207 = stack[-1];
    v123 = Labsval(nil, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v207 = qvalue(elt(env, 2)); /* !!fleps1 */
    v207 = times2(v123, v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-3];
    v207 = (Lisp_Object)lessp2(stack[0], v207);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v207 = v207 ? lisp_true : nil;
    env = stack[-3];
    if (v207 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v207 = elt(env, 1); /* 0.0 */
    { popv(4); return onevalue(v207); }
/* error exit handlers */
v47:
    popv(4);
    return nil;
}



/* Code for ev!-edgeloop */

static Lisp_Object CC_evKedgeloop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v118, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-edgeloop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v145 = v1;
    v118 = v0;
/* end of prologue */
    v146 = qvalue(elt(env, 1)); /* ndim!* */
    v118 = qcar(v118);
    v145 = Lassoc(nil, v118, v145);
    v145 = qcdr(v145);
    {
        fn = elt(env, 2); /* binc */
        return (*qfn2(fn))(qenv(fn), v146, v145);
    }
}



/* Code for dp!=retimes */

static Lisp_Object CC_dpMretimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v100, v101;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=retimes");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v100 = v0;
/* end of prologue */

v23:
    v96 = v100;
    v101 = qcar(v96);
    v96 = (Lisp_Object)17; /* 1 */
    if (v101 == v96) goto v105;
    v96 = v100;
    v96 = qcdr(v96);
    if (v96 == nil) goto v147;
    v96 = elt(env, 1); /* times */
    return cons(v96, v100);

v147:
    v96 = v100;
    v96 = qcar(v96);
    return onevalue(v96);

v105:
    v96 = v100;
    v96 = qcdr(v96);
    if (v96 == nil) goto v75;
    v96 = v100;
    v96 = qcdr(v96);
    v100 = v96;
    goto v23;

v75:
    v96 = (Lisp_Object)17; /* 1 */
    return onevalue(v96);
}



/* Code for st_sorttree1 */

static Lisp_Object MS_CDECL CC_st_sorttree1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v266, v267, v268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_sorttree1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_sorttree1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v2;
    stack[-9] = v1;
    stack[-10] = v0;
/* end of prologue */
    stack[-11] = nil;
    stack[-7] = nil;
    stack[-1] = nil;
    v266 = (Lisp_Object)17; /* 1 */
    stack[-6] = v266;
    v266 = stack[-10];
    v266 = qcdr(v266);
    v266 = qcar(v266);
    if (is_number(v266)) goto v97;
    v266 = stack[-10];
    v267 = qcar(v266);
    v266 = elt(env, 1); /* !* */
    if (v267 == v266) goto v269;
    v266 = stack[-10];
    v266 = qcdr(v266);
    stack[0] = v266;
    goto v270;

v270:
    v266 = stack[0];
    if (v266 == nil) goto v271;
    v266 = stack[0];
    v266 = qcar(v266);
    v268 = v266;
    v267 = stack[-6];
    v266 = (Lisp_Object)1; /* 0 */
    if (v267 == v266) goto v272;
    v267 = stack[-9];
    v266 = stack[-8];
    v266 = CC_st_sorttree1(env, 3, v268, v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-2] = v266;
    v267 = stack[-6];
    v266 = stack[-2];
    v266 = qcdr(v266);
    v266 = qcar(v266);
    v266 = times2(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-6] = v266;
    v266 = stack[-2];
    v266 = qcdr(v266);
    v268 = qcdr(v266);
    v266 = stack[-2];
    v267 = qcar(v266);
    v266 = stack[-1];
    v266 = acons(v268, v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-1] = v266;
    goto v272;

v272:
    v266 = stack[0];
    v266 = qcdr(v266);
    stack[0] = v266;
    goto v270;

v271:
    v267 = stack[-6];
    v266 = (Lisp_Object)1; /* 0 */
    if (v267 == v266) goto v274;
    v266 = stack[-10];
    v267 = qcar(v266);
    v266 = elt(env, 3); /* !+ */
    if (v267 == v266) goto v275;
    v267 = stack[-1];
    v266 = stack[-8];
    fn = elt(env, 4); /* cdr_signsort */
    v266 = (*qfn2(fn))(qenv(fn), v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-1] = v266;
    v266 = stack[-1];
    v267 = qcar(v266);
    v266 = (Lisp_Object)1; /* 0 */
    if (v267 == v266) goto v276;
    v267 = stack[-6];
    v266 = stack[-1];
    v266 = qcar(v266);
    v266 = times2(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-6] = v266;
    v266 = stack[-1];
    v266 = qcdr(v266);
    stack[-1] = v266;
    goto v277;

v277:
    v266 = stack[-1];
    if (v266 == nil) goto v278;
    v266 = stack[-1];
    v266 = qcar(v266);
    v267 = qcar(v266);
    v266 = stack[-7];
    v266 = cons(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-7] = v266;
    v266 = stack[-1];
    v266 = qcar(v266);
    v267 = qcdr(v266);
    v266 = stack[-11];
    v266 = cons(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-11] = v266;
    v266 = stack[-1];
    v266 = qcdr(v266);
    stack[-1] = v266;
    goto v277;

v278:
    v266 = stack[-10];
    stack[0] = qcar(v266);
    v266 = stack[-7];
    v266 = Lreverse(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = cons(stack[0], v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-7] = v266;
    v266 = stack[-11];
    v266 = Lreverse(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    stack[-11] = v266;
    v268 = stack[-11];
    v267 = stack[-6];
    v266 = stack[-7];
    popv(13);
    return list2star(v268, v267, v266);

v276:
    v267 = qvalue(elt(env, 2)); /* nil */
    v266 = (Lisp_Object)1; /* 0 */
    v268 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v267, v266, v268);

v275:
    v267 = stack[-1];
    v266 = stack[-8];
    fn = elt(env, 5); /* cdr_sort */
    v266 = (*qfn2(fn))(qenv(fn), v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-1] = v266;
    goto v277;

v274:
    v267 = qvalue(elt(env, 2)); /* nil */
    v266 = (Lisp_Object)1; /* 0 */
    v268 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v267, v266, v268);

v269:
    v266 = stack[-10];
    v266 = qcdr(v266);
    stack[0] = v266;
    goto v154;

v154:
    v266 = stack[0];
    if (v266 == nil) goto v279;
    v266 = stack[0];
    v266 = qcar(v266);
    v268 = v266;
    v267 = stack[-6];
    v266 = (Lisp_Object)1; /* 0 */
    if (v267 == v266) goto v280;
    v267 = stack[-9];
    v266 = stack[-8];
    v266 = CC_st_sorttree1(env, 3, v268, v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-2] = v266;
    v267 = stack[-6];
    v266 = stack[-2];
    v266 = qcdr(v266);
    v266 = qcar(v266);
    v266 = times2(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-6] = v266;
    v266 = stack[-2];
    v267 = qcar(v266);
    v266 = stack[-11];
    v266 = cons(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-11] = v266;
    v266 = stack[-2];
    v266 = qcdr(v266);
    v267 = qcdr(v266);
    v266 = stack[-7];
    v266 = cons(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-7] = v266;
    goto v280;

v280:
    v266 = stack[0];
    v266 = qcdr(v266);
    stack[0] = v266;
    goto v154;

v279:
    v267 = stack[-6];
    v266 = (Lisp_Object)1; /* 0 */
    if (v267 == v266) goto v281;
    v266 = stack[-7];
    v266 = Lreverse(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-7] = v266;
    v266 = stack[-11];
    v266 = Lreverse(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-11] = v266;
    stack[0] = stack[-11];
    stack[-1] = stack[-6];
    v267 = elt(env, 1); /* !* */
    v266 = stack[-7];
    v266 = cons(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    {
        Lisp_Object v282 = stack[0];
        Lisp_Object v283 = stack[-1];
        popv(13);
        return list2star(v282, v283, v266);
    }

v281:
    v267 = qvalue(elt(env, 2)); /* nil */
    v266 = (Lisp_Object)1; /* 0 */
    v268 = qvalue(elt(env, 2)); /* nil */
    popv(13);
    return list2star(v267, v266, v268);

v97:
    v266 = stack[-10];
    v267 = qcar(v266);
    v266 = elt(env, 1); /* !* */
    if (v267 == v266) goto v118;
    v266 = stack[-10];
    v266 = qcdr(v266);
    stack[-5] = v266;
    v266 = stack[-5];
    if (v266 == nil) goto v204;
    v266 = stack[-5];
    v266 = qcar(v266);
    stack[-1] = v266;
    stack[0] = stack[-9];
    v266 = sub1(v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v266/(16/CELL)));
    v266 = cons(stack[-1], v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-3] = v266;
    stack[-4] = v266;
    goto v163;

v163:
    v266 = stack[-5];
    v266 = qcdr(v266);
    stack[-5] = v266;
    v266 = stack[-5];
    if (v266 == nil) goto v56;
    stack[-2] = stack[-3];
    v266 = stack[-5];
    v266 = qcar(v266);
    stack[-1] = v266;
    stack[0] = stack[-9];
    v266 = sub1(v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v266/(16/CELL)));
    v266 = cons(stack[-1], v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = Lrplacd(nil, stack[-2], v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = stack[-3];
    v266 = qcdr(v266);
    stack[-3] = v266;
    goto v163;

v56:
    v266 = stack[-4];
    goto v203;

v203:
    stack[-1] = v266;
    goto v271;

v204:
    v266 = qvalue(elt(env, 2)); /* nil */
    goto v203;

v118:
    v266 = stack[-10];
    v266 = qcdr(v266);
    stack[-4] = v266;
    v266 = stack[-4];
    if (v266 == nil) goto v135;
    v266 = stack[-4];
    v266 = qcar(v266);
    stack[0] = stack[-9];
    v266 = sub1(v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v266/(16/CELL)));
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    stack[-2] = v266;
    stack[-3] = v266;
    goto v195;

v195:
    v266 = stack[-4];
    v266 = qcdr(v266);
    stack[-4] = v266;
    v266 = stack[-4];
    if (v266 == nil) goto v132;
    stack[-1] = stack[-2];
    v266 = stack[-4];
    v266 = qcar(v266);
    stack[0] = stack[-9];
    v266 = sub1(v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v266/(16/CELL)));
    v266 = ncons(v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = Lrplacd(nil, stack[-1], v266);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-12];
    v266 = stack[-2];
    v266 = qcdr(v266);
    stack[-2] = v266;
    goto v195;

v132:
    v266 = stack[-3];
    goto v110;

v110:
    stack[-11] = v266;
    v268 = stack[-11];
    v267 = (Lisp_Object)17; /* 1 */
    v266 = stack[-10];
    popv(13);
    return list2star(v268, v267, v266);

v135:
    v266 = qvalue(elt(env, 2)); /* nil */
    goto v110;
/* error exit handlers */
v273:
    popv(13);
    return nil;
}



/* Code for taylorp */

static Lisp_Object CC_taylorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v111;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taylorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v111 = v0;
/* end of prologue */
    v75 = v111;
    if (!consp(v75)) goto v4;
    v75 = v111;
    v75 = qcar(v75);
    if (!consp(v75)) goto v62;
    v75 = v111;
    v75 = qcar(v75);
    v75 = qcar(v75);
    v111 = elt(env, 2); /* taylor */
        return Lflagp(nil, v75, v111);

v62:
    v75 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v75);

v4:
    v75 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v75);
}



/* Code for balance_mod */

static Lisp_Object CC_balance_mod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for balance_mod");
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
    v109 = stack[-1];
    v80 = stack[-1];
    v109 = plus2(v109, v80);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-2];
    v80 = stack[0];
    v80 = (Lisp_Object)greaterp2(v109, v80);
    nil = C_nil;
    if (exception_pending()) goto v119;
    v80 = v80 ? lisp_true : nil;
    if (v80 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v109 = stack[-1];
    v80 = stack[0];
    popv(3);
    return difference2(v109, v80);
/* error exit handlers */
v119:
    popv(3);
    return nil;
}



/* Code for remainder!-mod!-p */

static Lisp_Object CC_remainderKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v94, v95, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remainder-mod-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v94 = v1;
    v96 = v0;
/* end of prologue */
    v95 = v94;
    if (v95 == nil) goto v104;
    v95 = v94;
    if (!consp(v95)) goto v42;
    v95 = v94;
    v95 = qcar(v95);
    if (!consp(v95)) goto v42;
    v95 = v96;
    if (!consp(v95)) return onevalue(v96);
    v95 = v96;
    v95 = qcar(v95);
    if (!consp(v95)) return onevalue(v96);
    v95 = v94;
    v94 = qcar(v94);
    v94 = qcar(v94);
    v94 = qcar(v94);
    {
        fn = elt(env, 3); /* xremainder!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 3, v96, v95, v94);
    }

v42:
    v94 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v94);

v104:
    v94 = elt(env, 1); /* "B=0 IN REMAINDER-MOD-P" */
    {
        fn = elt(env, 4); /* errorf */
        return (*qfn1(fn))(qenv(fn), v94);
    }
}



/* Code for gcdlist */

static Lisp_Object CC_gcdlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v358, v359, v360;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdlist");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v358 = stack[0];
    if (v358 == nil) goto v4;
    v358 = stack[0];
    v358 = qcdr(v358);
    if (v358 == nil) goto v62;
    v358 = stack[0];
    v358 = qcar(v358);
    if (!consp(v358)) goto v75;
    v358 = stack[0];
    v358 = qcar(v358);
    v358 = qcar(v358);
    if (!consp(v358)) goto v75;
    stack[-1] = nil;
    goto v95;

v95:
    v358 = stack[0];
    if (v358 == nil) goto v94;
    v358 = stack[0];
    v358 = qcar(v358);
    if (v358 == nil) goto v134;
    v358 = stack[0];
    v358 = qcar(v358);
    if (!consp(v358)) goto v63;
    v358 = stack[0];
    v358 = qcar(v358);
    v358 = qcar(v358);
    if (!consp(v358)) goto v63;
    v358 = stack[0];
    stack[-2] = qcar(v358);
    v358 = stack[0];
    v358 = qcar(v358);
    fn = elt(env, 3); /* powers1 */
    v359 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = stack[-1];
    v358 = acons(stack[-2], v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-1] = v358;
    v358 = stack[0];
    v358 = qcdr(v358);
    stack[0] = v358;
    goto v95;

v63:
    v358 = stack[0];
    stack[-2] = qcdr(v358);
    v358 = stack[-1];
    fn = elt(env, 4); /* mapcarcar */
    v359 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = stack[0];
    v358 = qcar(v358);
    fn = elt(env, 5); /* gcdld */
    v358 = (*qfn2(fn))(qenv(fn), v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    fn = elt(env, 5); /* gcdld */
    v358 = (*qfn2(fn))(qenv(fn), stack[-2], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-1] = v358;
    v358 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v358;
    goto v95;

v134:
    v358 = stack[0];
    v358 = qcdr(v358);
    stack[0] = v358;
    goto v95;

v94:
    v358 = stack[-1];
    if (v358 == nil) goto v51;
    v358 = stack[-1];
    v358 = qcdr(v358);
    if (v358 == nil) goto v362;
    v358 = qvalue(elt(env, 1)); /* nil */
    stack[-13] = v358;
    v358 = qvalue(elt(env, 1)); /* nil */
    stack[-12] = v358;
    v358 = stack[-1];
    stack[-11] = v358;
    v358 = stack[-11];
    if (v358 == nil) goto v363;
    v358 = stack[-11];
    v358 = qcar(v358);
    stack[-7] = v358;
    stack[-6] = nil;
    v358 = stack[-7];
    v358 = qcdr(v358);
    stack[-5] = v358;
    v358 = stack[-5];
    if (v358 == nil) goto v158;
    v358 = stack[-5];
    v358 = qcar(v358);
    stack[-1] = v358;
    v358 = stack[-1];
    v360 = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v359 = qcdr(v358);
    v358 = stack[-6];
    v358 = acons(v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-6] = v358;
    v358 = stack[-1];
    stack[0] = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v359 = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = difference2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = cons(stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-3] = v358;
    stack[-4] = v358;
    goto v178;

v178:
    v358 = stack[-5];
    v358 = qcdr(v358);
    stack[-5] = v358;
    v358 = stack[-5];
    if (v358 == nil) goto v364;
    stack[-2] = stack[-3];
    v358 = stack[-5];
    v358 = qcar(v358);
    stack[-1] = v358;
    v358 = stack[-1];
    v360 = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v359 = qcdr(v358);
    v358 = stack[-6];
    v358 = acons(v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-6] = v358;
    v358 = stack[-1];
    stack[0] = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v359 = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = difference2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = cons(stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = Lrplacd(nil, stack[-2], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    goto v178;

v364:
    v358 = stack[-4];
    goto v263;

v263:
    stack[0] = v358;
    v358 = stack[-7];
    v358 = qcar(v358);
    fn = elt(env, 6); /* numeric!-content */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-1] = v358;
    v358 = stack[-12];
    if (v358 == nil) goto v365;
    v359 = stack[-13];
    v358 = stack[-6];
    fn = elt(env, 7); /* vintersection */
    v358 = (*qfn2(fn))(qenv(fn), v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-13] = v358;
    v359 = stack[-12];
    v358 = stack[-1];
    fn = elt(env, 8); /* gcddd */
    v358 = (*qfn2(fn))(qenv(fn), v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-12] = v358;
    goto v366;

v366:
    v358 = stack[-6];
    stack[-2] = v358;
    goto v16;

v16:
    v358 = stack[-2];
    if (v358 == nil) goto v367;
    v358 = stack[-2];
    v358 = qcar(v358);
    v360 = v358;
    v358 = v360;
    v359 = qcdr(v358);
    v358 = (Lisp_Object)1; /* 0 */
    if (v359 == v358) goto v368;
    v358 = v360;
    v358 = qcar(v358);
    v359 = v360;
    v359 = qcdr(v359);
    fn = elt(env, 9); /* mksp */
    v359 = (*qfn2(fn))(qenv(fn), v358, v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = (Lisp_Object)17; /* 1 */
    v358 = cons(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    fn = elt(env, 10); /* multf */
    v358 = (*qfn2(fn))(qenv(fn), stack[-1], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-1] = v358;
    goto v368;

v368:
    v358 = stack[-2];
    v358 = qcdr(v358);
    stack[-2] = v358;
    goto v16;

v367:
    v358 = stack[-7];
    v360 = qcar(v358);
    v359 = stack[-1];
    v358 = elt(env, 2); /* "Term content division failed" */
    fn = elt(env, 11); /* quotfail1 */
    v359 = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = stack[0];
    v358 = cons(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-9] = v358;
    stack[-10] = v358;
    goto v190;

v190:
    v358 = stack[-11];
    v358 = qcdr(v358);
    stack[-11] = v358;
    v358 = stack[-11];
    if (v358 == nil) goto v369;
    stack[-8] = stack[-9];
    v358 = stack[-11];
    v358 = qcar(v358);
    stack[-7] = v358;
    stack[-6] = nil;
    v358 = stack[-7];
    v358 = qcdr(v358);
    stack[-5] = v358;
    v358 = stack[-5];
    if (v358 == nil) goto v231;
    v358 = stack[-5];
    v358 = qcar(v358);
    stack[-1] = v358;
    v358 = stack[-1];
    v360 = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v359 = qcdr(v358);
    v358 = stack[-6];
    v358 = acons(v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-6] = v358;
    v358 = stack[-1];
    stack[0] = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v359 = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = difference2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = cons(stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-3] = v358;
    stack[-4] = v358;
    goto v370;

v370:
    v358 = stack[-5];
    v358 = qcdr(v358);
    stack[-5] = v358;
    v358 = stack[-5];
    if (v358 == nil) goto v276;
    stack[-2] = stack[-3];
    v358 = stack[-5];
    v358 = qcar(v358);
    stack[-1] = v358;
    v358 = stack[-1];
    v360 = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v359 = qcdr(v358);
    v358 = stack[-6];
    v358 = acons(v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-6] = v358;
    v358 = stack[-1];
    stack[0] = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v359 = qcar(v358);
    v358 = stack[-1];
    v358 = qcdr(v358);
    v358 = qcdr(v358);
    v358 = difference2(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = cons(stack[0], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = Lrplacd(nil, stack[-2], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = stack[-3];
    v358 = qcdr(v358);
    stack[-3] = v358;
    goto v370;

v276:
    v358 = stack[-4];
    goto v371;

v371:
    stack[0] = v358;
    v358 = stack[-7];
    v358 = qcar(v358);
    fn = elt(env, 6); /* numeric!-content */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-1] = v358;
    v358 = stack[-12];
    if (v358 == nil) goto v372;
    v359 = stack[-13];
    v358 = stack[-6];
    fn = elt(env, 7); /* vintersection */
    v358 = (*qfn2(fn))(qenv(fn), v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-13] = v358;
    v359 = stack[-12];
    v358 = stack[-1];
    fn = elt(env, 8); /* gcddd */
    v358 = (*qfn2(fn))(qenv(fn), v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-12] = v358;
    goto v373;

v373:
    v358 = stack[-6];
    stack[-2] = v358;
    goto v374;

v374:
    v358 = stack[-2];
    if (v358 == nil) goto v375;
    v358 = stack[-2];
    v358 = qcar(v358);
    v360 = v358;
    v358 = v360;
    v359 = qcdr(v358);
    v358 = (Lisp_Object)1; /* 0 */
    if (v359 == v358) goto v273;
    v358 = v360;
    v358 = qcar(v358);
    v359 = v360;
    v359 = qcdr(v359);
    fn = elt(env, 9); /* mksp */
    v359 = (*qfn2(fn))(qenv(fn), v358, v359);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = (Lisp_Object)17; /* 1 */
    v358 = cons(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    fn = elt(env, 10); /* multf */
    v358 = (*qfn2(fn))(qenv(fn), stack[-1], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-1] = v358;
    goto v273;

v273:
    v358 = stack[-2];
    v358 = qcdr(v358);
    stack[-2] = v358;
    goto v374;

v375:
    v358 = stack[-7];
    v360 = qcar(v358);
    v359 = stack[-1];
    v358 = elt(env, 2); /* "Term content division failed" */
    fn = elt(env, 11); /* quotfail1 */
    v359 = (*qfnn(fn))(qenv(fn), 3, v360, v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = stack[0];
    v358 = cons(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = Lrplacd(nil, stack[-8], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = stack[-9];
    v358 = qcdr(v358);
    stack[-9] = v358;
    goto v190;

v372:
    v358 = stack[-6];
    stack[-13] = v358;
    v358 = stack[-1];
    stack[-12] = v358;
    goto v373;

v231:
    v358 = qvalue(elt(env, 1)); /* nil */
    goto v371;

v369:
    v358 = stack[-10];
    goto v199;

v199:
    stack[0] = v358;
    v358 = stack[-13];
    stack[-1] = v358;
    goto v376;

v376:
    v358 = stack[-1];
    if (v358 == nil) goto v377;
    v358 = stack[-1];
    v358 = qcar(v358);
    stack[-2] = stack[-12];
    v359 = v358;
    v359 = qcar(v359);
    v358 = qcdr(v358);
    fn = elt(env, 9); /* mksp */
    v359 = (*qfn2(fn))(qenv(fn), v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = (Lisp_Object)17; /* 1 */
    v358 = cons(v359, v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    v358 = ncons(v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    fn = elt(env, 10); /* multf */
    v358 = (*qfn2(fn))(qenv(fn), stack[-2], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    stack[-12] = v358;
    v358 = stack[-1];
    v358 = qcdr(v358);
    stack[-1] = v358;
    goto v376;

v377:
    stack[-1] = stack[-12];
    v358 = stack[0];
    fn = elt(env, 12); /* gcdlist1 */
    v358 = (*qfn1(fn))(qenv(fn), v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    fn = elt(env, 10); /* multf */
    v358 = (*qfn2(fn))(qenv(fn), stack[-1], v358);
    nil = C_nil;
    if (exception_pending()) goto v361;
    env = stack[-14];
    {
        popv(15);
        fn = elt(env, 13); /* poly!-abs */
        return (*qfn1(fn))(qenv(fn), v358);
    }

v365:
    v358 = stack[-6];
    stack[-13] = v358;
    v358 = stack[-1];
    stack[-12] = v358;
    goto v366;

v158:
    v358 = qvalue(elt(env, 1)); /* nil */
    goto v263;

v363:
    v358 = qvalue(elt(env, 1)); /* nil */
    goto v199;

v362:
    v358 = stack[-1];
    v358 = qcar(v358);
    v358 = qcar(v358);
    {
        popv(15);
        fn = elt(env, 13); /* poly!-abs */
        return (*qfn1(fn))(qenv(fn), v358);
    }

v51:
    v358 = qvalue(elt(env, 1)); /* nil */
    { popv(15); return onevalue(v358); }

v75:
    v358 = stack[0];
    v359 = qcdr(v358);
    v358 = stack[0];
    v358 = qcar(v358);
    {
        popv(15);
        fn = elt(env, 5); /* gcdld */
        return (*qfn2(fn))(qenv(fn), v359, v358);
    }

v62:
    v358 = stack[0];
    v358 = qcar(v358);
    {
        popv(15);
        fn = elt(env, 13); /* poly!-abs */
        return (*qfn1(fn))(qenv(fn), v358);
    }

v4:
    v358 = qvalue(elt(env, 1)); /* nil */
    { popv(15); return onevalue(v358); }
/* error exit handlers */
v361:
    popv(15);
    return nil;
}



/* Code for checkexp */

static Lisp_Object CC_checkexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v93, v135, v94;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkexp");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    v135 = v1;
    v94 = v0;
/* end of prologue */
    v93 = v135;
    v69 = (Lisp_Object)1; /* 0 */
    if (v93 == v69) goto v104;
    v93 = v135;
    v69 = (Lisp_Object)17; /* 1 */
    if (v93 == v69) { popv(2); return onevalue(v94); }
    stack[-1] = elt(env, 1); /* expt */
    stack[0] = v94;
    v69 = v135;
    fn = elt(env, 2); /* preptayexp */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v100;
    {
        Lisp_Object v101 = stack[-1];
        Lisp_Object v102 = stack[0];
        popv(2);
        return list3(v101, v102, v69);
    }

v104:
    v69 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v69); }
/* error exit handlers */
v100:
    popv(2);
    return nil;
}



/* Code for change!+int!+to!+sq */

static Lisp_Object CC_changeLintLtoLsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for change+int+to+sq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v140 = v0;
/* end of prologue */
    v98 = v140;
    v140 = (Lisp_Object)17; /* 1 */
    return cons(v98, v140);
}



/* Code for pdiffvars */

static Lisp_Object CC_pdiffvars(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdiffvars");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    v69 = v1;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* ind */
    qvalue(elt(env, 1)) = nil; /* ind */
    qvalue(elt(env, 1)) = v69; /* ind */
    v69 = qvalue(elt(env, 1)); /* ind */
    if (v69 == nil) goto v98;
    v93 = stack[-1];
    v69 = qvalue(elt(env, 1)); /* ind */
    v69 = qcar(v69);
    fn = elt(env, 2); /* nth */
    stack[0] = (*qfn2(fn))(qenv(fn), v93, v69);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    v69 = qvalue(elt(env, 1)); /* ind */
    v93 = qcdr(v69);
    v69 = stack[-1];
    v69 = CC_pdiffvars(env, v93, v69);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    v69 = cons(stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    goto v20;

v20:
    qvalue(elt(env, 1)) = stack[-2]; /* ind */
    { popv(4); return onevalue(v69); }

v98:
    v69 = nil;
    goto v20;
/* error exit handlers */
v96:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* ind */
    popv(4);
    return nil;
}



/* Code for simpsqrtsq */

static Lisp_Object CC_simpsqrtsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsqrtsq");
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
    v99 = stack[0];
    v99 = qcar(v99);
    fn = elt(env, 1); /* simpsqrt2 */
    stack[-1] = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-2];
    v99 = stack[0];
    v99 = qcdr(v99);
    fn = elt(env, 1); /* simpsqrt2 */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v173;
    {
        Lisp_Object v113 = stack[-1];
        popv(3);
        return cons(v113, v99);
    }
/* error exit handlers */
v173:
    popv(3);
    return nil;
}



/* Code for simp_without_resimp */

static Lisp_Object CC_simp_without_resimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp_without_resimp");
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
    v105 = v0;
/* end of prologue */
    v20 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*resimp */
    qvalue(elt(env, 2)) = v20; /* !*resimp */
    v20 = v105;
    fn = elt(env, 3); /* simp */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*resimp */
    { popv(2); return onevalue(v20); }
/* error exit handlers */
v23:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*resimp */
    popv(2);
    return nil;
}



/* Code for dim!<!=deg */

static Lisp_Object CC_dimRMdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dim<=deg");
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
    v110 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* dimex!* */
    fn = elt(env, 3); /* deg!*form */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-1];
    fn = elt(env, 4); /* negf */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-1];
    fn = elt(env, 5); /* addf */
    v110 = (*qfn2(fn))(qenv(fn), stack[0], v110);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-1];
    v195 = v110;
    v110 = v195;
    v110 = (v110 == nil ? lisp_true : nil);
    if (!(v110 == nil)) { popv(2); return onevalue(v110); }
    v110 = v195;
    v110 = integerp(v110);
    if (v110 == nil) goto v145;
    v110 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Lleq(nil, v195, v110);

v145:
    v110 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v110); }
/* error exit handlers */
v165:
    popv(2);
    return nil;
}



/* Code for rassoc */

static Lisp_Object CC_rassoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v136, v76, v77;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rassoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v76 = v1;
    v77 = v0;
/* end of prologue */

v104:
    v137 = v76;
    if (!consp(v137)) goto v62;
    v136 = v77;
    v137 = v76;
    v137 = qcar(v137);
    v137 = qcdr(v137);
    if (equal(v136, v137)) goto v140;
    v137 = v76;
    v137 = qcdr(v137);
    v76 = v137;
    goto v104;

v140:
    v137 = v76;
    v137 = qcar(v137);
    return onevalue(v137);

v62:
    v137 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v137);
}



/* Code for find_bubles1 */

static Lisp_Object CC_find_bubles1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v136, v76, v77, v80, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v137 = v1;
    v136 = v0;
/* end of prologue */
    v109 = qvalue(elt(env, 1)); /* nil */
    v76 = v136;
    v80 = qcar(v76);
    v77 = qvalue(elt(env, 1)); /* nil */
    v76 = v136;
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v136 = qcdr(v136);
    v136 = qcdr(v136);
    v136 = qcar(v136);
    {
        fn = elt(env, 2); /* select_bubles */
        return (*qfnn(fn))(qenv(fn), 6, v109, v80, v77, v76, v136, v137);
    }
}



/* Code for subsq */

static Lisp_Object CC_subsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v134, v194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsq");
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
    v134 = stack[-1];
    v194 = qcar(v134);
    v134 = stack[0];
    fn = elt(env, 3); /* subf */
    v134 = (*qfn2(fn))(qenv(fn), v194, v134);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[-2] = v134;
    v134 = stack[-1];
    v194 = qcdr(v134);
    v134 = stack[0];
    fn = elt(env, 3); /* subf */
    v134 = (*qfn2(fn))(qenv(fn), v194, v134);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[-1] = v134;
    v134 = stack[-1];
    fn = elt(env, 4); /* subs2!* */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v134 = qcar(v134);
    if (!(v134 == nil)) goto v100;
    v134 = stack[-2];
    fn = elt(env, 4); /* subs2!* */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    v134 = qcar(v134);
    if (v134 == nil) goto v80;
    v134 = elt(env, 2); /* "Zero divisor" */
    fn = elt(env, 5); /* rederr */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    goto v100;

v100:
    v194 = stack[-2];
    v134 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* quotsq */
        return (*qfn2(fn))(qenv(fn), v194, v134);
    }

v80:
    v134 = elt(env, 1); /* "0/0 formed" */
    fn = elt(env, 5); /* rederr */
    v134 = (*qfn1(fn))(qenv(fn), v134);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    goto v100;
/* error exit handlers */
v141:
    popv(4);
    return nil;
}



/* Code for fs!:minusp!: */

static Lisp_Object CC_fsTminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:minusp:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v104 = v0;
/* end of prologue */
    v104 = qcdr(v104);
    {
        fn = elt(env, 1); /* fs!:minusp */
        return (*qfn1(fn))(qenv(fn), v104);
    }
}



/* Code for njets */

static Lisp_Object CC_njets(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for njets");
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
    v114 = v1;
    v145 = v0;
/* end of prologue */
    stack[-1] = v114;
    stack[0] = v114;
    v114 = v145;
    v114 = sub1(v114);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    v114 = plus2(stack[0], v114);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    {
        Lisp_Object v74 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* combin */
        return (*qfn2(fn))(qenv(fn), v74, v114);
    }
/* error exit handlers */
v97:
    popv(3);
    return nil;
}



/* Code for cl_smsimpl!-junct2 */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v4, Lisp_Object v104, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v200, v379, v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "cl_smsimpl-junct2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct2");
#endif
    if (stack >= stacklimit)
    {
        push6(v104,v4,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v2,v3,v4,v104);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v104;
    v200 = v4;
    v379 = v3;
    v58 = v2;
    stack[-2] = v1;
    v59 = v0;
/* end of prologue */
    fn = elt(env, 5); /* rl_smmkatl */
    v200 = (*qfnn(fn))(qenv(fn), 4, v59, v58, v379, v200);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    stack[-3] = v200;
    v200 = qvalue(elt(env, 1)); /* !*rlsichk */
    if (v200 == nil) goto v191;
    v200 = stack[-2];
    v379 = v200;
    v200 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v200;
    v200 = v379;
    stack[0] = v200;
    goto v110;

v110:
    v200 = stack[0];
    if (v200 == nil) goto v111;
    v200 = stack[0];
    v200 = qcar(v200);
    v379 = v200;
    v200 = stack[-2];
    fn = elt(env, 6); /* lto_insert */
    v200 = (*qfn2(fn))(qenv(fn), v379, v200);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    stack[-2] = v200;
    v200 = stack[0];
    v200 = qcdr(v200);
    stack[0] = v200;
    goto v110;

v111:
    v200 = qvalue(elt(env, 3)); /* !*rlsiso */
    if (v200 == nil) goto v183;
    v379 = stack[-3];
    v200 = elt(env, 4); /* rl_ordatp */
    fn = elt(env, 7); /* sort */
    v200 = (*qfn2(fn))(qenv(fn), v379, v200);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    stack[-3] = v200;
    goto v183;

v183:
    v379 = stack[-3];
    v200 = stack[-2];
    v200 = Lnconc(nil, v379, v200);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    v379 = v200;
    v200 = v379;
    if (!(v200 == nil)) { popv(5); return onevalue(v379); }
    v200 = stack[-1];
    fn = elt(env, 8); /* cl_flip */
    v200 = (*qfn1(fn))(qenv(fn), v200);
    nil = C_nil;
    if (exception_pending()) goto v201;
    popv(5);
    return ncons(v200);

v191:
    v200 = stack[-2];
    v200 = Lnreverse(nil, v200);
    env = stack[-4];
    stack[-2] = v200;
    goto v111;
/* error exit handlers */
v201:
    popv(5);
    return nil;
}



/* Code for cl_trygaussvar */

static Lisp_Object MS_CDECL CC_cl_trygaussvar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v164, v50, v52, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "cl_trygaussvar");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_trygaussvar");
#endif
    if (stack >= stacklimit)
    {
        push5(v4,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v3;
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v163 = stack[-4];
    fn = elt(env, 4); /* cl_atfp */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v380;
    env = stack[-5];
    if (v163 == nil) goto v76;
    v51 = stack[-4];
    v52 = stack[-3];
    v50 = stack[-2];
    v164 = stack[-1];
    v163 = stack[0];
    {
        popv(6);
        fn = elt(env, 5); /* rl_qefsolset */
        return (*qfnn(fn))(qenv(fn), 5, v51, v52, v50, v164, v163);
    }

v76:
    v163 = stack[-4];
    if (!consp(v163)) goto v165;
    v163 = stack[-4];
    v163 = qcar(v163);
    v164 = v163;
    goto v80;

v80:
    v163 = elt(env, 1); /* and */
    if (v164 == v163) goto v170;
    v163 = stack[-4];
    if (!consp(v163)) goto v183;
    v163 = stack[-4];
    v163 = qcar(v163);
    v164 = v163;
    goto v193;

v193:
    v163 = elt(env, 2); /* or */
    if (v164 == v163) goto v66;
    v163 = elt(env, 3); /* (failed) */
    { popv(6); return onevalue(v163); }

v66:
    v163 = stack[-4];
    v51 = qcdr(v163);
    v52 = stack[-3];
    v50 = stack[-2];
    v164 = stack[-1];
    v163 = stack[0];
    {
        popv(6);
        fn = elt(env, 6); /* cl_gaussor */
        return (*qfnn(fn))(qenv(fn), 5, v51, v52, v50, v164, v163);
    }

v183:
    v163 = stack[-4];
    v164 = v163;
    goto v193;

v170:
    v163 = stack[-4];
    v51 = qcdr(v163);
    v52 = stack[-3];
    v50 = stack[-2];
    v164 = stack[-1];
    v163 = stack[0];
    {
        popv(6);
        fn = elt(env, 7); /* cl_gaussand */
        return (*qfnn(fn))(qenv(fn), 5, v51, v52, v50, v164, v163);
    }

v165:
    v163 = stack[-4];
    v164 = v163;
    goto v80;
/* error exit handlers */
v380:
    popv(6);
    return nil;
}



/* Code for nextu */

static Lisp_Object CC_nextu(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nextu");
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
    v107 = v1;
    stack[0] = v0;
/* end of prologue */
    v106 = stack[0];
    if (v106 == nil) goto v104;
    v131 = v107;
    v106 = stack[0];
    v107 = qcar(v106);
    v106 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* subtractinds */
    v106 = (*qfnn(fn))(qenv(fn), 3, v131, v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    stack[-1] = v106;
    v106 = stack[-1];
    if (v106 == nil) goto v137;
    v106 = stack[0];
    v106 = qcdr(v106);
    v107 = qcar(v106);
    v106 = stack[-1];
    fn = elt(env, 3); /* evaluatecoeffts */
    v106 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    v131 = v106;
    v106 = v131;
    if (v106 == nil) goto v100;
    v107 = v131;
    v106 = (Lisp_Object)1; /* 0 */
    if (v107 == v106) goto v100;
    v107 = stack[-1];
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = qcdr(v106);
    popv(3);
    return list2star(v107, v131, v106);

v100:
    v106 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v106); }

v137:
    v106 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v106); }

v104:
    v106 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v106); }
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for depend!-sq */

static Lisp_Object CC_dependKsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-sq");
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
    v74 = stack[-1];
    v75 = qcar(v74);
    v74 = stack[0];
    fn = elt(env, 1); /* depend!-f */
    v74 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-2];
    if (!(v74 == nil)) { popv(3); return onevalue(v74); }
    v74 = stack[-1];
    v75 = qcdr(v74);
    v74 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* depend!-f */
        return (*qfn2(fn))(qenv(fn), v75, v74);
    }
/* error exit handlers */
v147:
    popv(3);
    return nil;
}



setup_type const u33_setup[] =
{
    {"rand-mons-sparse",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_randKmonsKsparse},
    {"strand-alg-top",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_strandKalgKtop},
    {"reduce-weights",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKweights},
    {"rationalizef",            CC_rationalizef,too_many_1,    wrong_no_1},
    {"red_prepare",             CC_red_prepare, too_many_1,    wrong_no_1},
    {"dv_skel2factor",          too_few_2,      CC_dv_skel2factor,wrong_no_2},
    {"small-primep",            CC_smallKprimep,too_many_1,    wrong_no_1},
    {"conditionml",             CC_conditionml, too_many_1,    wrong_no_1},
    {"ps:zerop:",               CC_psTzeropT,   too_many_1,    wrong_no_1},
    {"groebreduceonestepint",   wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebreduceonestepint},
    {"reset_opnums",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_reset_opnums},
    {"mv2sf",                   too_few_2,      CC_mv2sf,      wrong_no_2},
    {"mo_deletecomp",           CC_mo_deletecomp,too_many_1,   wrong_no_1},
    {"pst_mkpst",               CC_pst_mkpst,   too_many_1,    wrong_no_1},
    {"maxfrom",                 too_few_2,      CC_maxfrom,    wrong_no_2},
    {"get-min-degreelist",      CC_getKminKdegreelist,too_many_1,wrong_no_1},
    {"mk_resimp_rep",           CC_mk_resimp_rep,too_many_1,   wrong_no_1},
    {"limitom",                 CC_limitom,     too_many_1,    wrong_no_1},
    {"dip2a",                   CC_dip2a,       too_many_1,    wrong_no_1},
    {"natnump",                 CC_natnump,     too_many_1,    wrong_no_1},
    {"rdzchk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rdzchk},
    {"ev-edgeloop",             too_few_2,      CC_evKedgeloop,wrong_no_2},
    {"dp=retimes",              CC_dpMretimes,  too_many_1,    wrong_no_1},
    {"st_sorttree1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_sorttree1},
    {"taylorp",                 CC_taylorp,     too_many_1,    wrong_no_1},
    {"balance_mod",             too_few_2,      CC_balance_mod,wrong_no_2},
    {"remainder-mod-p",         too_few_2,      CC_remainderKmodKp,wrong_no_2},
    {"gcdlist",                 CC_gcdlist,     too_many_1,    wrong_no_1},
    {"checkexp",                too_few_2,      CC_checkexp,   wrong_no_2},
    {"change+int+to+sq",        CC_changeLintLtoLsq,too_many_1,wrong_no_1},
    {"pdiffvars",               too_few_2,      CC_pdiffvars,  wrong_no_2},
    {"simpsqrtsq",              CC_simpsqrtsq,  too_many_1,    wrong_no_1},
    {"simp_without_resimp",     CC_simp_without_resimp,too_many_1,wrong_no_1},
    {"dim<=deg",                CC_dimRMdeg,    too_many_1,    wrong_no_1},
    {"rassoc",                  too_few_2,      CC_rassoc,     wrong_no_2},
    {"find_bubles1",            too_few_2,      CC_find_bubles1,wrong_no_2},
    {"subsq",                   too_few_2,      CC_subsq,      wrong_no_2},
    {"fs:minusp:",              CC_fsTminuspT,  too_many_1,    wrong_no_1},
    {"njets",                   too_few_2,      CC_njets,      wrong_no_2},
    {"cl_smsimpl-junct2",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct2},
    {"cl_trygaussvar",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_trygaussvar},
    {"nextu",                   too_few_2,      CC_nextu,      wrong_no_2},
    {"depend-sq",               too_few_2,      CC_dependKsq,  wrong_no_2},
    {NULL, (one_args *)"u33", (two_args *)"2833 7296256 3599355", 0}
};

/* end of generated code */
