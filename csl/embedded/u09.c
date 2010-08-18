
/* $destdir/generated-c\u09.c Machine generated C code */

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


/* Code for simp */

static Lisp_Object CC_simp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v134, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp");
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
    v133 = qvalue(elt(env, 1)); /* varstack!* */
    stack[-6] = qvalue(elt(env, 1)); /* varstack!* */
    qvalue(elt(env, 1)) = v133; /* varstack!* */
    v133 = stack[-5];
    v133 = integerp(v133);
    if (v133 == nil) goto v136;
    v134 = stack[-5];
    v133 = (Lisp_Object)1; /* 0 */
    if (v134 == v133) goto v137;
    v133 = qvalue(elt(env, 3)); /* dmode!* */
    if (!(v133 == nil)) goto v138;
    v134 = stack[-5];
    v133 = (Lisp_Object)17; /* 1 */
    v133 = cons(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v140:
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    { popv(8); return onevalue(v133); }

v138:
    v134 = stack[-5];
    v133 = qvalue(elt(env, 1)); /* varstack!* */
    v133 = cons(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    qvalue(elt(env, 1)) = v133; /* varstack!* */
    v134 = qvalue(elt(env, 4)); /* simpcount!* */
    v133 = qvalue(elt(env, 5)); /* simplimit!* */
    v133 = (Lisp_Object)greaterp2(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    v133 = v133 ? lisp_true : nil;
    env = stack[-7];
    if (v133 == nil) goto v141;
    v133 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 4)) = v133; /* simpcount!* */
    v135 = elt(env, 6); /* alg */
    v134 = (Lisp_Object)193; /* 12 */
    v133 = elt(env, 7); /* "Simplification recursion too deep" */
    fn = elt(env, 34); /* rerror */
    v133 = (*qfnn(fn))(qenv(fn), 3, v135, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v142;

v142:
    v133 = qvalue(elt(env, 4)); /* simpcount!* */
    v133 = add1(v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    qvalue(elt(env, 4)) = v133; /* simpcount!* */
    v133 = stack[-5];
    if (!consp(v133)) goto v143;
    v133 = stack[-5];
    v133 = qcar(v133);
    if (!(symbolp(v133))) goto v144;
    v133 = stack[-5];
    v133 = qcar(v133);
    if (v133 == nil) goto v144;
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 17); /* opfn */
    v133 = Lflagp(nil, v134, v133);
    env = stack[-7];
    if (v133 == nil) goto v145;
    v133 = stack[-5];
    fn = elt(env, 35); /* opfneval */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    stack[-1] = v133;
    fn = elt(env, 36); /* getrtype */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v134 = v133;
    if (v133 == nil) goto v146;
    v133 = elt(env, 18); /* yetunknowntype */
    if (!(v134 == v133)) goto v147;
    v133 = stack[-1];
    fn = elt(env, 37); /* reval */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    stack[-1] = v133;
    fn = elt(env, 36); /* getrtype */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    if (!(v133 == nil)) goto v147;
    v133 = stack[-1];
    v133 = CC_simp(env, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v147:
    v134 = stack[-5];
    v133 = elt(env, 19); /* "scalar" */
    fn = elt(env, 38); /* typerr */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v148;

v148:
    v133 = nil;
    goto v140;

v146:
    v133 = stack[-1];
    fn = elt(env, 39); /* simp_without_resimp */
    v134 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v145:
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 20); /* psopfn */
    v133 = get(v134, v133);
    env = stack[-7];
    stack[-1] = v133;
    if (v133 == nil) goto v149;
    stack[0] = stack[-1];
    v133 = stack[-5];
    fn = elt(env, 41); /* argnochk */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = qcdr(v133);
    v133 = Lapply1(nil, stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    stack[-1] = v133;
    fn = elt(env, 36); /* getrtype */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    if (v133 == nil) goto v150;
    v134 = stack[-5];
    v133 = elt(env, 19); /* "scalar" */
    fn = elt(env, 38); /* typerr */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v148;

v150:
    v134 = stack[-1];
    v133 = stack[-5];
    if (equal(v134, v133)) goto v151;
    v133 = stack[-1];
    fn = elt(env, 39); /* simp_without_resimp */
    v134 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v151:
    v134 = stack[-1];
    v133 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 42); /* to */
    v134 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = (Lisp_Object)17; /* 1 */
    v133 = cons(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v134 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = (Lisp_Object)17; /* 1 */
    v134 = cons(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v149:
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 21); /* polyfn */
    v133 = get(v134, v133);
    env = stack[-7];
    stack[-1] = v133;
    if (v133 == nil) goto v152;
    v133 = stack[-5];
    fn = elt(env, 41); /* argnochk */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    stack[-4] = stack[-1];
    v133 = stack[-5];
    v133 = qcdr(v133);
    stack[-3] = v133;
    v133 = stack[-3];
    if (v133 == nil) goto v153;
    v133 = stack[-3];
    v133 = qcar(v133);
    fn = elt(env, 43); /* simp!* */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    fn = elt(env, 44); /* !*q2f */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    stack[-1] = v133;
    stack[-2] = v133;
    goto v154;

v154:
    v133 = stack[-3];
    v133 = qcdr(v133);
    stack[-3] = v133;
    v133 = stack[-3];
    if (v133 == nil) goto v155;
    stack[0] = stack[-1];
    v133 = stack[-3];
    v133 = qcar(v133);
    fn = elt(env, 43); /* simp!* */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    fn = elt(env, 44); /* !*q2f */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = Lrplacd(nil, stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[-1] = v133;
    goto v154;

v155:
    v133 = stack[-2];
    goto v156;

v156:
    fn = elt(env, 45); /* lispapply */
    v134 = (*qfn2(fn))(qenv(fn), stack[-4], v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = (Lisp_Object)17; /* 1 */
    v134 = cons(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v153:
    v133 = qvalue(elt(env, 2)); /* nil */
    goto v156;

v152:
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 22); /* opmtch */
    v133 = get(v134, v133);
    env = stack[-7];
    if (v133 == nil) goto v157;
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 23); /* simpfn */
    v134 = get(v134, v133);
    env = stack[-7];
    v133 = elt(env, 24); /* simpiden */
    if (v134 == v133) goto v157;
    v133 = stack[-5];
    fn = elt(env, 46); /* opmtchrevop */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    stack[-1] = v133;
    if (v133 == nil) goto v157;
    v133 = stack[-1];
    v134 = CC_simp(env, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v157:
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 23); /* simpfn */
    v133 = get(v134, v133);
    env = stack[-7];
    stack[-1] = v133;
    if (v133 == nil) goto v158;
    stack[0] = stack[-1];
    v134 = stack[-1];
    v133 = elt(env, 24); /* simpiden */
    if (v134 == v133) goto v159;
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 25); /* full */
    v133 = Lflagp(nil, v134, v133);
    env = stack[-7];
    if (!(v133 == nil)) goto v159;
    v133 = stack[-5];
    fn = elt(env, 41); /* argnochk */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = qcdr(v133);
    goto v160;

v160:
    v134 = Lapply1(nil, stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v159:
    v133 = stack[-5];
    fn = elt(env, 41); /* argnochk */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v160;

v158:
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 26); /* rtype */
    v133 = get(v134, v133);
    env = stack[-7];
    stack[-1] = v133;
    if (v133 == nil) goto v161;
    v134 = stack[-1];
    v133 = elt(env, 27); /* getelemfn */
    v133 = get(v134, v133);
    env = stack[-7];
    stack[-1] = v133;
    if (v133 == nil) goto v161;
    v134 = stack[-1];
    v133 = stack[-5];
    v133 = Lapply1(nil, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v134 = CC_simp(env, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v161:
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 28); /* boolean */
    v133 = Lflagp(nil, v134, v133);
    env = stack[-7];
    if (!(v133 == nil)) goto v162;
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 29); /* infix */
    v133 = get(v134, v133);
    env = stack[-7];
    if (!(v133 == nil)) goto v162;
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 32); /* nochange */
    v133 = Lflagp(nil, v134, v133);
    env = stack[-7];
    if (v133 == nil) goto v163;
    v133 = stack[-5];
    fn = elt(env, 47); /* lispeval */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v134 = CC_simp(env, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v163:
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 20); /* psopfn */
    v133 = get(v134, v133);
    env = stack[-7];
    if (!(v133 == nil)) goto v164;
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 33); /* rtypefn */
    v133 = get(v134, v133);
    env = stack[-7];
    if (!(v133 == nil)) goto v164;
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 14); /* "operator" */
    fn = elt(env, 48); /* redmsg */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    v133 = qcar(v133);
    fn = elt(env, 49); /* mkop */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v134 = stack[-5];
    v133 = qvalue(elt(env, 1)); /* varstack!* */
    v133 = Ldelete(nil, v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    qvalue(elt(env, 1)) = v133; /* varstack!* */
    v133 = stack[-5];
    v134 = CC_simp(env, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v164:
    v134 = stack[-5];
    v133 = elt(env, 19); /* "scalar" */
    fn = elt(env, 38); /* typerr */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v148;

v162:
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 30); /* prtch */
    v133 = get(v134, v133);
    env = stack[-7];
    stack[-1] = v133;
    if (v133 == nil) goto v165;
    v133 = stack[-1];
    v134 = v133;
    goto v166;

v166:
    v133 = elt(env, 31); /* "algebraic operator" */
    fn = elt(env, 38); /* typerr */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v148;

v165:
    v133 = stack[-5];
    v133 = qcar(v133);
    v134 = v133;
    goto v166;

v144:
    v133 = stack[-5];
    v133 = qcar(v133);
    if (!consp(v133)) goto v167;
    v133 = stack[-5];
    v133 = qcar(v133);
    v133 = qcar(v133);
    if (!(symbolp(v133))) goto v168;
    v133 = stack[-5];
    v133 = qcar(v133);
    v134 = qcar(v133);
    v133 = elt(env, 15); /* name */
    v133 = get(v134, v133);
    env = stack[-7];
    if (v133 == nil) goto v168;
    v134 = stack[-5];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v168:
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 16); /* mat */
    if (!consp(v134)) goto v169;
    v134 = qcar(v134);
    if (!(v134 == v133)) goto v169;
    v133 = stack[-5];
    v133 = qcdr(v133);
    fn = elt(env, 50); /* revlis */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    stack[-1] = v133;
    fn = elt(env, 51); /* numlis */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    if (v133 == nil) goto v169;
    v133 = stack[-1];
    v134 = Llength(nil, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = (Lisp_Object)33; /* 2 */
    if (!(v134 == v133)) goto v169;
    v133 = stack[-5];
    v133 = qcar(v133);
    v134 = qcdr(v133);
    v133 = stack[-1];
    v133 = qcar(v133);
    fn = elt(env, 52); /* nth */
    v134 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-1];
    v133 = qcdr(v133);
    v133 = qcar(v133);
    fn = elt(env, 52); /* nth */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v134 = CC_simp(env, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v169:
    v134 = stack[-5];
    v133 = qvalue(elt(env, 12)); /* t */
    fn = elt(env, 53); /* errpri2 */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v148;

v167:
    v133 = stack[-5];
    v134 = qcar(v133);
    v133 = elt(env, 14); /* "operator" */
    fn = elt(env, 38); /* typerr */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v148;

v143:
    v133 = stack[-5];
    fn = elt(env, 54); /* simpatom */
    v134 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    v133 = stack[-5];
    fn = elt(env, 40); /* !*ssave */
    v133 = (*qfn2(fn))(qenv(fn), v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v141:
    v134 = stack[-5];
    v133 = elt(env, 8); /* !*sq */
    if (!consp(v134)) goto v170;
    v134 = qcar(v134);
    if (!(v134 == v133)) goto v170;
    v133 = stack[-5];
    v133 = qcdr(v133);
    v133 = qcdr(v133);
    v133 = qcar(v133);
    if (v133 == nil) goto v170;
    v133 = qvalue(elt(env, 9)); /* !*resimp */
    if (!(v133 == nil)) goto v170;
    v133 = stack[-5];
    v133 = qcdr(v133);
    v133 = qcar(v133);
    goto v140;

v170:
    v133 = qvalue(elt(env, 10)); /* !*uncached */
    if (!(v133 == nil)) goto v142;
    v134 = stack[-5];
    v133 = qvalue(elt(env, 11)); /* alglist!* */
    v133 = qcar(v133);
    v133 = Lassoc(nil, v134, v133);
    stack[-1] = v133;
    if (v133 == nil) goto v142;
    v133 = stack[-1];
    v133 = qcdr(v133);
    v133 = qcar(v133);
    if (v133 == nil) goto v171;
    v133 = qvalue(elt(env, 12)); /* t */
    qvalue(elt(env, 13)) = v133; /* !*sub2 */
    goto v171;

v171:
    v133 = stack[-1];
    v133 = qcdr(v133);
    v133 = qcdr(v133);
    goto v140;

v137:
    v134 = qvalue(elt(env, 2)); /* nil */
    v133 = (Lisp_Object)17; /* 1 */
    v133 = cons(v134, v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v140;

v136:
    v134 = stack[-5];
    v133 = qvalue(elt(env, 1)); /* varstack!* */
    v133 = Lmember(nil, v134, v133);
    if (v133 == nil) goto v138;
    v133 = stack[-5];
    fn = elt(env, 55); /* recursiveerror */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-7];
    goto v138;
/* error exit handlers */
v139:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* varstack!* */
    popv(8);
    return nil;
}



/* Code for downwght1 */

static Lisp_Object CC_downwght1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for downwght1");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v219 = v172;
    stack[-4] = v0;
/* end of prologue */
    fn = elt(env, 3); /* dm!-abs */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 4); /* !:onep */
    v219 = (*qfn1(fn))(qenv(fn), v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    if (v219 == nil) goto v222;
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v220 = qvalue(elt(env, 2)); /* maxvar */
    v219 = stack[-4];
    v219 = plus2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-5] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v220 = qvalue(elt(env, 2)); /* maxvar */
    v219 = stack[-4];
    v219 = plus2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v220 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = (Lisp_Object)17; /* 1 */
    v219 = *(Lisp_Object *)((char *)v220 + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = qcar(v219);
    v219 = qcar(v219);
    stack[-2] = sub1(v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v220 = qvalue(elt(env, 2)); /* maxvar */
    v219 = stack[-4];
    v219 = plus2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v220 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = (Lisp_Object)17; /* 1 */
    v219 = *(Lisp_Object *)((char *)v220 + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = qcar(v219);
    stack[-1] = qcdr(v219);
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v220 = qvalue(elt(env, 2)); /* maxvar */
    v219 = stack[-4];
    v219 = plus2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v220 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = (Lisp_Object)17; /* 1 */
    v219 = *(Lisp_Object *)((char *)v220 + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = qcdr(v219);
    v219 = sub1(v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v219 = acons(stack[-2], stack[-1], v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    *(Lisp_Object *)((char *)stack[-5] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v219;
    { popv(7); return onevalue(v219); }

v222:
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v220 = qvalue(elt(env, 2)); /* maxvar */
    v219 = stack[-4];
    v219 = plus2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-5] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v220 = qvalue(elt(env, 2)); /* maxvar */
    v219 = stack[-4];
    v219 = plus2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v220 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = (Lisp_Object)17; /* 1 */
    v219 = *(Lisp_Object *)((char *)v220 + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = qcar(v219);
    v219 = qcar(v219);
    stack[-2] = sub1(v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v220 = qvalue(elt(env, 2)); /* maxvar */
    v219 = stack[-4];
    v219 = plus2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v220 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = (Lisp_Object)17; /* 1 */
    v219 = *(Lisp_Object *)((char *)v220 + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = qcar(v219);
    v219 = qcdr(v219);
    stack[-1] = sub1(v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v220 = qvalue(elt(env, 2)); /* maxvar */
    v219 = stack[-4];
    v219 = plus2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v220 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v219 = (Lisp_Object)17; /* 1 */
    v219 = *(Lisp_Object *)((char *)v220 + (CELL-TAG_VECTOR) + ((int32_t)v219/(16/CELL)));
    v220 = qcdr(v219);
    v219 = (Lisp_Object)65; /* 4 */
    v219 = difference2(v220, v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v219 = acons(stack[-2], stack[-1], v219);
    nil = C_nil;
    if (exception_pending()) goto v221;
    *(Lisp_Object *)((char *)stack[-5] + (CELL-TAG_VECTOR) + ((int32_t)stack[-3]/(16/CELL))) = v219;
    { popv(7); return onevalue(v219); }
/* error exit handlers */
v221:
    popv(7);
    return nil;
}



/* Code for revalind */

static Lisp_Object CC_revalind(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227, v228, v217;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revalind");
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
    stack[0] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v227 = qvalue(elt(env, 2)); /* nil */
    v227 = ncons(v227);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    qvalue(elt(env, 1)) = v227; /* alglist!* */
    v227 = qvalue(elt(env, 3)); /* subfg!* */
    stack[-2] = v227;
    v227 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v227; /* subfg!* */
    v217 = elt(env, 4); /* !0 */
    v228 = (Lisp_Object)1; /* 0 */
    v227 = stack[-1];
    v227 = Lsubst(nil, 3, v217, v228, v227);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    stack[-1] = v227;
    v227 = stack[-1];
    fn = elt(env, 5); /* simp */
    v227 = (*qfn1(fn))(qenv(fn), v227);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    fn = elt(env, 6); /* prepsq */
    v227 = (*qfn1(fn))(qenv(fn), v227);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v228 = v227;
    v227 = stack[-2];
    qvalue(elt(env, 3)) = v227; /* subfg!* */
    v227 = v228;
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    { popv(4); return onevalue(v227); }
/* error exit handlers */
v196:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[0]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for getphystypesf */

static Lisp_Object CC_getphystypesf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypesf");
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

v229:
    v137 = stack[0];
    if (v137 == nil) goto v21;
    v137 = stack[0];
    fn = elt(env, 2); /* domain!*p */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-1];
    if (!(v137 == nil)) goto v21;
    v137 = stack[0];
    v137 = qcar(v137);
    v137 = qcar(v137);
    v137 = qcar(v137);
    fn = elt(env, 3); /* getphystype */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v228;
    env = stack[-1];
    if (!(v137 == nil)) { popv(2); return onevalue(v137); }
    v137 = stack[0];
    v137 = qcar(v137);
    v137 = qcdr(v137);
    stack[0] = v137;
    goto v229;

v21:
    v137 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v137); }
/* error exit handlers */
v228:
    popv(2);
    return nil;
}



/* Code for divdm */

static Lisp_Object CC_divdm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v236, v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divdm");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    stack[-1] = v0;
/* end of prologue */
    v235 = stack[-1];
    if (!(!consp(v235))) goto v237;
    v235 = stack[0];
    if (!(!consp(v235))) goto v237;
    v236 = stack[-1];
    v235 = stack[0];
    v236 = Cremainder(v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-2];
    v235 = (Lisp_Object)1; /* 0 */
    if (v236 == v235) goto v218;
    v236 = stack[-1];
    v235 = stack[0];
    fn = elt(env, 2); /* mkrn */
    v235 = (*qfn2(fn))(qenv(fn), v236, v235);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* !:rn2rd */
        return (*qfn1(fn))(qenv(fn), v235);
    }

v218:
    v236 = stack[-1];
    v235 = stack[0];
    popv(3);
    return quot2(v236, v235);

v237:
    v123 = stack[-1];
    v236 = stack[0];
    v235 = elt(env, 1); /* quotient */
    {
        popv(3);
        fn = elt(env, 4); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v123, v236, v235);
    }
/* error exit handlers */
v142:
    popv(3);
    return nil;
}



/* Code for red_divtest */

static Lisp_Object CC_red_divtest(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_divtest");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    stack[-1] = v0;
/* end of prologue */

v89:
    v129 = stack[-1];
    if (v129 == nil) goto v238;
    v129 = stack[-1];
    v129 = qcar(v129);
    fn = elt(env, 2); /* bas_dpoly */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    fn = elt(env, 3); /* dp_lmon */
    v130 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    v129 = stack[0];
    fn = elt(env, 4); /* mo_vdivides!? */
    v129 = (*qfn2(fn))(qenv(fn), v130, v129);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    if (v129 == nil) goto v227;
    v129 = stack[-1];
    v129 = qcar(v129);
    { popv(3); return onevalue(v129); }

v227:
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v89;

v238:
    v129 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v129); }
/* error exit handlers */
v234:
    popv(3);
    return nil;
}



/* Code for !*id2num */

static Lisp_Object CC_Hid2num(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v223;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *id2num");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v225 = v0;
/* end of prologue */
    v223 = qvalue(elt(env, 1)); /* pair_id_num!* */
    v225 = Lassoc(nil, v225, v223);
    v223 = v225;
    if (v225 == nil) goto v1;
    v225 = v223;
    v225 = qcdr(v225);
    return onevalue(v225);

v1:
    v225 = nil;
    return onevalue(v225);
}



/* Code for b!:ordexn */

static Lisp_Object CC_bTordexn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v246;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:ordexn");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v172;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    stack[-3] = nil;
    goto v140;

v140:
    v170 = stack[-1];
    if (v170 == nil) goto v216;
    v246 = stack[-2];
    v170 = stack[-1];
    v170 = qcar(v170);
    if (equal(v246, v170)) goto v217;
    v170 = stack[-2];
    if (v170 == nil) goto v247;
    v246 = stack[-2];
    v170 = stack[-1];
    v170 = qcar(v170);
    v170 = (Lisp_Object)greaterp2(v246, v170);
    nil = C_nil;
    if (exception_pending()) goto v248;
    v170 = v170 ? lisp_true : nil;
    env = stack[-4];
    if (v170 == nil) goto v247;
    v246 = stack[-2];
    v170 = stack[-3];
    v170 = cons(v246, v170);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-4];
    v246 = Lreverse(nil, v170);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-4];
    v170 = stack[-1];
    v170 = Lappend(nil, v246, v170);
    nil = C_nil;
    if (exception_pending()) goto v248;
    {
        Lisp_Object v249 = stack[0];
        popv(5);
        return cons(v249, v170);
    }

v247:
    v170 = stack[-1];
    v246 = qcar(v170);
    v170 = stack[-3];
    v170 = cons(v246, v170);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-4];
    stack[-3] = v170;
    v170 = stack[-1];
    v170 = qcdr(v170);
    stack[-1] = v170;
    v170 = stack[0];
    v170 = (v170 == nil ? lisp_true : nil);
    stack[0] = v170;
    goto v140;

v217:
    v170 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v170); }

v216:
    v246 = stack[-2];
    v170 = stack[-3];
    v170 = cons(v246, v170);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-4];
    v170 = Lreverse(nil, v170);
    nil = C_nil;
    if (exception_pending()) goto v248;
    {
        Lisp_Object v117 = stack[0];
        popv(5);
        return cons(v117, v170);
    }
/* error exit handlers */
v248:
    popv(5);
    return nil;
}



/* Code for general!-reciprocal!-by!-gcd */

static Lisp_Object MS_CDECL CC_generalKreciprocalKbyKgcd(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v172,
                         Lisp_Object v226, Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v206, v201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "general-reciprocal-by-gcd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reciprocal-by-gcd");
#endif
    if (stack >= stacklimit)
    {
        push4(v2,v226,v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v172,v226,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v2;
    stack[-3] = v226;
    stack[-4] = v172;
    stack[-5] = v0;
/* end of prologue */

v262:
    v206 = stack[-4];
    v205 = (Lisp_Object)1; /* 0 */
    if (v206 == v205) goto v222;
    v206 = stack[-4];
    v205 = (Lisp_Object)17; /* 1 */
    if (v206 == v205) goto v198;
    v206 = stack[-5];
    v205 = stack[-4];
    v205 = quot2(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    stack[-6] = v205;
    stack[-1] = stack[-4];
    stack[0] = stack[-5];
    v206 = stack[-4];
    v205 = stack[-6];
    v205 = times2(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    stack[-4] = difference2(stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    stack[0] = stack[-2];
    v206 = stack[-2];
    v205 = stack[-6];
    v205 = times2(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    v205 = difference2(stack[-3], v205);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[-7];
    stack[-5] = stack[-1];
    stack[-3] = stack[0];
    stack[-2] = v205;
    goto v262;

v198:
    v206 = stack[-2];
    v205 = (Lisp_Object)1; /* 0 */
    v205 = (Lisp_Object)lessp2(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v115;
    v205 = v205 ? lisp_true : nil;
    env = stack[-7];
    if (v205 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    v205 = stack[-2];
    v206 = qvalue(elt(env, 3)); /* current!-modulus */
    popv(8);
    return plus2(v205, v206);

v222:
    v201 = elt(env, 1); /* alg */
    v206 = (Lisp_Object)129; /* 8 */
    v205 = elt(env, 2); /* "Invalid modular division" */
    {
        popv(8);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v201, v206, v205);
    }
/* error exit handlers */
v115:
    popv(8);
    return nil;
}



/* Code for color1 */

static Lisp_Object MS_CDECL CC_color1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v172,
                         Lisp_Object v226, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v294, v295, v296, v297;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "color1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for color1");
#endif
    if (stack >= stacklimit)
    {
        push3(v226,v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v172,v226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v226;
    stack[-1] = v172;
    v296 = v0;
/* end of prologue */

v140:
    v294 = v296;
    v294 = qcar(v294);
    v294 = qcar(v294);
    if (v294 == nil) goto v298;
    v294 = v296;
    v294 = qcdr(v294);
    if (v294 == nil) goto v298;
    v295 = elt(env, 1); /* qg */
    v294 = v296;
    v294 = qcdr(v294);
    v294 = Lassoc(nil, v295, v294);
    v297 = v294;
    if (v294 == nil) goto v299;
    v294 = v297;
    v294 = qcdr(v294);
    v295 = qcar(v294);
    v294 = v297;
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v294 = qcar(v294);
    if (v295 == v294) goto v300;
    v294 = v297;
    v294 = qcdr(v294);
    v295 = qcar(v294);
    v294 = v297;
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v294 = qcar(v294);
    if (v295 == v294) goto v300;
    v294 = v297;
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v295 = qcar(v294);
    v294 = v297;
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v294 = qcar(v294);
    if (v295 == v294) goto v300;
    v294 = v296;
    v295 = v297;
    fn = elt(env, 6); /* removeg */
    v294 = (*qfn2(fn))(qenv(fn), v294, v295);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    v296 = v294;
    v294 = v296;
    stack[-2] = qcar(v294);
    v294 = v296;
    v294 = qcdr(v294);
    if (v294 == nil) goto v188;
    v294 = v296;
    v295 = qcdr(v294);
    v294 = stack[-1];
    v294 = cons(v295, v294);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    v295 = v294;
    goto v143;

v143:
    v294 = stack[0];
    v296 = stack[-2];
    stack[-1] = v295;
    stack[0] = v294;
    goto v140;

v188:
    v294 = stack[-1];
    v295 = v294;
    goto v143;

v300:
    v295 = qvalue(elt(env, 2)); /* nil */
    v294 = (Lisp_Object)17; /* 1 */
    v294 = cons(v295, v294);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    v296 = ncons(v294);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    v295 = stack[-1];
    v294 = stack[0];
    stack[-1] = v295;
    stack[0] = v294;
    goto v140;

v299:
    v295 = elt(env, 3); /* g3 */
    v294 = v296;
    v294 = qcdr(v294);
    v294 = Lassoc(nil, v295, v294);
    v297 = v294;
    if (v294 == nil) goto v302;
    v294 = v297;
    v294 = qcdr(v294);
    v295 = qcar(v294);
    v294 = v297;
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v294 = qcar(v294);
    if (v295 == v294) goto v303;
    v294 = v297;
    v294 = qcdr(v294);
    v295 = qcar(v294);
    v294 = v297;
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v294 = qcar(v294);
    if (v295 == v294) goto v303;
    v294 = v297;
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v295 = qcar(v294);
    v294 = v297;
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v294 = qcdr(v294);
    v294 = qcar(v294);
    if (v295 == v294) goto v303;
    v294 = v296;
    v295 = v297;
    fn = elt(env, 7); /* split3gv */
    v294 = (*qfn2(fn))(qenv(fn), v294, v295);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    v296 = v294;
    v294 = v296;
    stack[-2] = qcar(v294);
    v294 = v296;
    v295 = qcdr(v294);
    v294 = stack[-1];
    v295 = cons(v295, v294);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    v294 = stack[0];
    v296 = stack[-2];
    stack[-1] = v295;
    stack[0] = v294;
    goto v140;

v303:
    v295 = qvalue(elt(env, 2)); /* nil */
    v294 = (Lisp_Object)17; /* 1 */
    v294 = cons(v295, v294);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    v296 = ncons(v294);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    v295 = stack[-1];
    v294 = stack[0];
    stack[-1] = v295;
    stack[0] = v294;
    goto v140;

v302:
    stack[0] = elt(env, 4); /* "Invalid structure of c0-graph." */
    v294 = v296;
    if (v294 == nil) goto v304;
    v294 = v296;
    v294 = qcdr(v294);
    if (v294 == nil) goto v90;
    v294 = elt(env, 5); /* times */
    v295 = v296;
    v294 = cons(v294, v295);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    goto v305;

v305:
    v294 = list2(stack[0], v294);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    fn = elt(env, 8); /* cerror */
    v294 = (*qfn1(fn))(qenv(fn), v294);
    nil = C_nil;
    if (exception_pending()) goto v301;
    v294 = nil;
    { popv(4); return onevalue(v294); }

v90:
    v294 = v296;
    v294 = qcar(v294);
    goto v305;

v304:
    v294 = qvalue(elt(env, 2)); /* nil */
    goto v305;

v298:
    v294 = stack[-1];
    if (v294 == nil) goto v259;
    v294 = stack[-1];
    v294 = qcar(v294);
    stack[-2] = v294;
    v294 = stack[-1];
    v294 = qcdr(v294);
    stack[-1] = v294;
    v294 = v296;
    v295 = qcar(v294);
    v294 = stack[0];
    fn = elt(env, 9); /* addsq */
    v294 = (*qfn2(fn))(qenv(fn), v295, v294);
    nil = C_nil;
    if (exception_pending()) goto v301;
    env = stack[-3];
    stack[0] = v294;
    v294 = stack[-2];
    v296 = v294;
    goto v140;

v259:
    v294 = v296;
    v295 = qcar(v294);
    v294 = stack[0];
    {
        popv(4);
        fn = elt(env, 9); /* addsq */
        return (*qfn2(fn))(qenv(fn), v295, v294);
    }
/* error exit handlers */
v301:
    popv(4);
    return nil;
}



/* Code for eolcheck */

static Lisp_Object MS_CDECL CC_eolcheck(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v306;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "eolcheck");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eolcheck");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v245 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (!(v245 == nil)) goto v307;
    v245 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v245); }

v307:
    v306 = qvalue(elt(env, 3)); /* nxtsym!* */
    v245 = qvalue(elt(env, 4)); /* !$eol!$ */
    if (v306 == v245) goto v227;
    v245 = nil;
    { popv(1); return onevalue(v245); }

v227:
    v306 = qvalue(elt(env, 5)); /* cursym!* */
    v245 = elt(env, 6); /* end */
    if (v306 == v245) goto v259;
    fn = elt(env, 8); /* token */
    v245 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v308;
    env = stack[0];
    goto v132;

v132:
    qvalue(elt(env, 3)) = v245; /* nxtsym!* */
    goto v307;

v259:
    v245 = elt(env, 7); /* !; */
    goto v132;
/* error exit handlers */
v308:
    popv(1);
    return nil;
}



/* Code for basicom */

static Lisp_Object CC_basicom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basicom");
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
    v218 = stack[0];
    if (is_number(v218)) goto v1;
    v218 = stack[0];
    if (!(symbolp(v218))) goto v89;
    v218 = stack[0];
    fn = elt(env, 1); /* variableom */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v130;
    goto v89;

v89:
    v218 = nil;
    { popv(2); return onevalue(v218); }

v1:
    v218 = stack[0];
    v218 = integerp(v218);
    if (v218 == nil) goto v298;
    v218 = stack[0];
    fn = elt(env, 2); /* integerom */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-1];
    goto v298;

v298:
    v218 = stack[0];
    v218 = Lfloatp(nil, v218);
    env = stack[-1];
    if (v218 == nil) goto v89;
    v218 = stack[0];
    fn = elt(env, 3); /* floatom */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v130;
    goto v89;
/* error exit handlers */
v130:
    popv(2);
    return nil;
}



/* Code for writepri */

static Lisp_Object CC_writepri(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v307, v222;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for writepri");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    v239 = v0;
/* end of prologue */
    fn = elt(env, 2); /* eval */
    v222 = (*qfn1(fn))(qenv(fn), v239);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-1];
    v307 = qvalue(elt(env, 1)); /* nil */
    v239 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* assgnpri */
        return (*qfnn(fn))(qenv(fn), 3, v222, v307, v239);
    }
/* error exit handlers */
v225:
    popv(2);
    return nil;
}



/* Code for vevlcm */

static Lisp_Object CC_vevlcm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v242, v121;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevlcm");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    stack[-1] = v0;
/* end of prologue */
    v121 = nil;
    goto v238;

v238:
    v244 = stack[-1];
    if (v244 == nil) goto v140;
    v244 = stack[0];
    if (v244 == nil) goto v140;
    v244 = stack[-1];
    v242 = qcar(v244);
    v244 = stack[0];
    v244 = qcar(v244);
    if (((int32_t)(v242)) > ((int32_t)(v244))) goto v137;
    v244 = stack[0];
    v244 = qcar(v244);
    goto v224;

v224:
    v242 = v121;
    v244 = cons(v244, v242);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-2];
    v121 = v244;
    v244 = stack[-1];
    v244 = qcdr(v244);
    stack[-1] = v244;
    v244 = stack[0];
    v244 = qcdr(v244);
    stack[0] = v244;
    goto v238;

v137:
    v244 = stack[-1];
    v244 = qcar(v244);
    goto v224;

v140:
    v244 = v121;
    v244 = Lnreverse(nil, v244);
    env = stack[-2];
    v121 = v244;
    v244 = stack[-1];
    if (v244 == nil) goto v214;
    v242 = v121;
    v244 = stack[-1];
    v244 = Lnconc(nil, v242, v244);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v121 = v244;
    { popv(3); return onevalue(v121); }

v214:
    v244 = stack[0];
    if (v244 == nil) { popv(3); return onevalue(v121); }
    v242 = v121;
    v244 = stack[0];
    v244 = Lnconc(nil, v242, v244);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v121 = v244;
    { popv(3); return onevalue(v121); }
/* error exit handlers */
v247:
    popv(3);
    return nil;
}



/* Code for mkuwedge */

static Lisp_Object CC_mkuwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkuwedge");
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
    v216 = v0;
/* end of prologue */
    v131 = v216;
    v131 = qcdr(v131);
    if (v131 == nil) goto v313;
    v131 = elt(env, 1); /* wedge */
    v216 = cons(v131, v216);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[0];
    fn = elt(env, 2); /* fkern */
    v216 = (*qfn1(fn))(qenv(fn), v216);
    nil = C_nil;
    if (exception_pending()) goto v132;
    v216 = qcar(v216);
    { popv(1); return onevalue(v216); }

v313:
    v216 = qcar(v216);
    { popv(1); return onevalue(v216); }
/* error exit handlers */
v132:
    popv(1);
    return nil;
}



/* Code for rd!:minus */

static Lisp_Object CC_rdTminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v216, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:minus");
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
    v131 = v0;
/* end of prologue */
    v216 = v131;
    v216 = qcdr(v216);
    if (!consp(v216)) goto v262;
    v216 = v131;
    {
        popv(1);
        fn = elt(env, 2); /* minus!: */
        return (*qfn1(fn))(qenv(fn), v216);
    }

v262:
    stack[0] = elt(env, 1); /* !:rd!: */
    v216 = v131;
    v216 = qcdr(v216);
    v216 = negate(v216);
    nil = C_nil;
    if (exception_pending()) goto v259;
    {
        Lisp_Object v137 = stack[0];
        popv(1);
        return cons(v137, v216);
    }
/* error exit handlers */
v259:
    popv(1);
    return nil;
}



/* Code for deletemult!* */

static Lisp_Object CC_deletemultH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v126, v315;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deletemult*");
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
    stack[0] = v0;
/* end of prologue */
    v125 = stack[0];
    if (v125 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v125 = stack[0];
    v125 = qcar(v125);
    v125 = ncons(v125);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    stack[-2] = v125;
    v125 = stack[0];
    v125 = qcdr(v125);
    stack[0] = v125;
    v125 = stack[0];
    stack[-1] = v125;
    goto v225;

v225:
    v125 = stack[-1];
    if (v125 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v125 = stack[-1];
    v125 = qcar(v125);
    v315 = v125;
    v126 = v315;
    v125 = stack[-2];
    v125 = Lmember(nil, v126, v125);
    if (!(v125 == nil)) goto v129;
    stack[0] = stack[-2];
    v125 = v315;
    v125 = ncons(v125);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    v125 = Lnconc(nil, stack[0], v125);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-3];
    goto v129;

v129:
    v125 = stack[-1];
    v125 = qcdr(v125);
    stack[-1] = v125;
    goto v225;
/* error exit handlers */
v138:
    popv(4);
    return nil;
}



/* Code for compactfmatch2 */

static Lisp_Object CC_compactfmatch2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v234;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactfmatch2");
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
    v258 = stack[0];
    if (!consp(v258)) goto v21;
    v258 = stack[0];
    v234 = qcar(v258);
    v258 = elt(env, 2); /* !~ */
    if (v234 == v258) goto v238;
    v258 = stack[0];
    v258 = qcar(v258);
    stack[-1] = CC_compactfmatch2(env, v258);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-2];
    v258 = stack[0];
    v258 = qcdr(v258);
    v258 = CC_compactfmatch2(env, v258);
    nil = C_nil;
    if (exception_pending()) goto v245;
    {
        Lisp_Object v306 = stack[-1];
        popv(3);
        return Lappend(nil, v306, v258);
    }

v238:
    v258 = stack[0];
    popv(3);
    return ncons(v258);

v21:
    v258 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v258); }
/* error exit handlers */
v245:
    popv(3);
    return nil;
}



/* Code for dividef */

static Lisp_Object CC_dividef(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v214, v125, v126;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dividef");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v213 = v172;
    v214 = v0;
/* end of prologue */
    v213 = Ldivide(nil, v214, v213);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[0];
    v126 = v213;
    v213 = v126;
    v214 = qcar(v213);
    v213 = (Lisp_Object)1; /* 0 */
    if (v214 == v213) goto v223;
    v213 = v126;
    v213 = qcar(v213);
    v125 = v213;
    goto v306;

v306:
    v213 = v126;
    v214 = qcdr(v213);
    v213 = (Lisp_Object)1; /* 0 */
    if (v214 == v213) goto v317;
    v213 = v126;
    v213 = qcdr(v213);
    goto v307;

v307:
    popv(1);
    return cons(v125, v213);

v317:
    v213 = qvalue(elt(env, 1)); /* nil */
    goto v307;

v223:
    v213 = qvalue(elt(env, 1)); /* nil */
    v125 = v213;
    goto v306;
/* error exit handlers */
v315:
    popv(1);
    return nil;
}



/* Code for arintequiv!: */

static Lisp_Object CC_arintequivT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v308, v198, v127;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arintequiv:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v127 = v0;
/* end of prologue */
    v308 = v127;
    v308 = qcdr(v308);
    if (is_number(v308)) goto v21;
    v308 = v127;
    v308 = qcdr(v308);
    v198 = qcar(v308);
    v308 = elt(env, 1); /* !:rn!: */
    if (!(v198 == v308)) goto v317;
    v308 = v127;
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    v198 = qcdr(v308);
    v308 = (Lisp_Object)17; /* 1 */
    if (!(v198 == v308)) goto v317;
    v308 = v127;
    v308 = qcdr(v308);
    v308 = qcdr(v308);
    v308 = qcar(v308);
    return onevalue(v308);

v317:
    v308 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v308);

v21:
    v308 = v127;
    v308 = qcdr(v308);
    return onevalue(v308);
}



/* Code for gionep!: */

static Lisp_Object CC_gionepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v228, v217, v218;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gionep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v218 = v0;
/* end of prologue */
    v228 = v218;
    v228 = qcdr(v228);
    v217 = qcar(v228);
    v228 = (Lisp_Object)17; /* 1 */
    if (v217 == v228) goto v313;
    v228 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v228);

v313:
    v228 = v218;
    v228 = qcdr(v228);
    v217 = qcdr(v228);
    v228 = (Lisp_Object)1; /* 0 */
    v228 = (v217 == v228 ? lisp_true : nil);
    return onevalue(v228);
}



/* Code for ibalp_varlt1 */

static Lisp_Object CC_ibalp_varlt1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124, v241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlt1");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    v241 = v0;
/* end of prologue */
    v124 = v241;
    v123 = (Lisp_Object)1; /* 0 */
    if (v124 == v123) goto v140;
    v124 = v241;
    v123 = (Lisp_Object)17; /* 1 */
    if (v124 == v123) goto v140;
    v123 = v241;
    if (symbolp(v123)) goto v130;
    v123 = v241;
    fn = elt(env, 2); /* ibalp_argn */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-2];
    stack[-1] = v123;
    goto v127;

v127:
    v123 = stack[-1];
    if (v123 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v123 = stack[-1];
    v123 = qcar(v123);
    v124 = v123;
    v123 = stack[0];
    v123 = CC_ibalp_varlt1(env, v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-2];
    stack[0] = v123;
    v123 = stack[-1];
    v123 = qcdr(v123);
    stack[-1] = v123;
    goto v127;

v130:
    v124 = v241;
    v123 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* lto_insertq */
        return (*qfn2(fn))(qenv(fn), v124, v123);
    }

v140:
    v123 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v123); }
/* error exit handlers */
v256:
    popv(3);
    return nil;
}



/* Code for naryrd */

static Lisp_Object MS_CDECL CC_naryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "naryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for naryrd");
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
    v224 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v132;
    env = stack[-1];
    v216 = v224;
    v224 = v216;
    if (v224 == nil) goto v140;
    stack[0] = v216;
    v224 = CC_naryrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v132;
    {
        Lisp_Object v259 = stack[0];
        popv(2);
        return cons(v259, v224);
    }

v140:
    v224 = nil;
    { popv(2); return onevalue(v224); }
/* error exit handlers */
v132:
    popv(2);
    return nil;
}



/* Code for ps!:putv */

static Lisp_Object MS_CDECL CC_psTputv(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v172,
                         Lisp_Object v226, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v142, v320;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ps:putv");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:putv");
#endif
    if (stack >= stacklimit)
    {
        push3(v226,v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v172,v226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v226;
    stack[-1] = v172;
    v320 = v0;
/* end of prologue */
    v142 = v320;
    v241 = elt(env, 1); /* !:ps!: */
    if (!consp(v142)) goto v321;
    v142 = qcar(v142);
    if (!(v142 == v241)) goto v321;
    v241 = v320;
    v241 = qcdr(v241);
    if (symbolp(v241)) goto v216;
    v241 = v320;
    v320 = qcdr(v241);
    v142 = stack[-1];
    v241 = stack[0];
    *(Lisp_Object *)((char *)v320 + (CELL-TAG_VECTOR) + ((int32_t)v142/(16/CELL))) = v241;
    { popv(3); return onevalue(v241); }

v216:
    v241 = v320;
    v241 = qcdr(v241);
    fn = elt(env, 4); /* eval */
    v320 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v311;
    v142 = stack[-1];
    v241 = stack[0];
    *(Lisp_Object *)((char *)v320 + (CELL-TAG_VECTOR) + ((int32_t)v142/(16/CELL))) = v241;
    { popv(3); return onevalue(v241); }

v321:
    stack[-1] = elt(env, 2); /* tps */
    stack[0] = (Lisp_Object)33; /* 2 */
    v241 = elt(env, 3); /* "PS:PUTV: not a ps" */
    v142 = v320;
    v241 = list2(v241, v142);
    nil = C_nil;
    if (exception_pending()) goto v311;
    env = stack[-2];
    {
        Lisp_Object v312 = stack[-1];
        Lisp_Object v243 = stack[0];
        popv(3);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v312, v243, v241);
    }
/* error exit handlers */
v311:
    popv(3);
    return nil;
}



/* Code for zeropp */

static Lisp_Object CC_zeropp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v259, v137;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zeropp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v137 = v0;
/* end of prologue */
    v132 = v137;
    if (!consp(v132)) goto v21;
    v132 = v137;
    v259 = qcar(v132);
    v132 = elt(env, 1); /* !:rd!: */
    if (v259 == v132) goto v262;
    v132 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v132);

v262:
    v132 = v137;
    {
        fn = elt(env, 3); /* rd!:zerop */
        return (*qfn1(fn))(qenv(fn), v132);
    }

v21:
    v132 = v137;
        return Lzerop(nil, v132);
}



/* Code for vevdif */

static Lisp_Object CC_vevdif(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v253, v205, v206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevdif");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v172;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    v205 = nil;
    v253 = stack[-4];
    stack[-1] = v253;
    v253 = stack[-3];
    stack[0] = v253;
    goto v240;

v240:
    v253 = stack[-1];
    if (v253 == nil) goto v310;
    v253 = stack[0];
    if (v253 == nil) goto v310;
    v253 = v205;
    if (!(v253 == nil)) goto v310;
    v253 = stack[-1];
    v205 = qcar(v253);
    v253 = stack[0];
    v253 = qcar(v253);
    v253 = (Lisp_Object)(int32_t)((int32_t)v205 - (int32_t)v253 + TAG_FIXNUM);
    stack[-2] = v253;
    v205 = stack[-2];
    v253 = stack[-5];
    v253 = cons(v205, v253);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[-5] = v253;
    v205 = stack[-2];
    v253 = (Lisp_Object)1; /* 0 */
    v253 = ((intptr_t)v205 < (intptr_t)v253) ? lisp_true : nil;
    v205 = v253;
    v253 = stack[-1];
    v253 = qcdr(v253);
    stack[-1] = v253;
    v253 = stack[0];
    v253 = qcdr(v253);
    stack[0] = v253;
    goto v240;

v310:
    v253 = v205;
    if (!(v253 == nil)) goto v230;
    v253 = stack[0];
    if (v253 == nil) goto v250;
    v253 = stack[0];
    if (v253 == nil) goto v250;
    v253 = stack[0];
    v205 = qcar(v253);
    v253 = (Lisp_Object)1; /* 0 */
    if (!(v205 == v253)) goto v230;
    v253 = stack[0];
    v253 = qcdr(v253);
    fn = elt(env, 5); /* vevzero!?1 */
    v253 = (*qfn1(fn))(qenv(fn), v253);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    if (!(v253 == nil)) goto v250;

v230:
    v253 = stack[-4];
    v253 = Lprint(nil, v253);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v253 = stack[-3];
    v253 = Lprint(nil, v253);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v253 = elt(env, 2); /* backtrace */
    fn = elt(env, 6); /* getd */
    v253 = (*qfn1(fn))(qenv(fn), v253);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    if (v253 == nil) goto v325;
    fn = elt(env, 2); /* backtrace */
    v253 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    goto v325;

v325:
    v206 = elt(env, 3); /* dipoly */
    v205 = (Lisp_Object)81; /* 5 */
    v253 = elt(env, 4); /* "Vevdif, difference would be < 0" */
    {
        popv(7);
        fn = elt(env, 7); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v206, v205, v253);
    }

v250:
    v253 = stack[-5];
    v205 = Lnreverse(nil, v253);
    v253 = stack[-1];
        popv(7);
        return Lnconc(nil, v205, v253);
/* error exit handlers */
v114:
    popv(7);
    return nil;
}



/* Code for split!-road */

static Lisp_Object CC_splitKroad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v319, v316, v231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split-road");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v172;
    stack[-2] = v0;
/* end of prologue */
    v319 = stack[-1];
    stack[-3] = qcar(v319);
    v319 = stack[-2];
    v231 = qcar(v319);
    v319 = stack[-2];
    v316 = qcdr(v319);
    v319 = stack[-1];
    v319 = qcdr(v319);
    v319 = qcar(v319);
    fn = elt(env, 1); /* sroad */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v231, v316, v319);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-4];
    v319 = stack[-2];
    v231 = qcar(v319);
    v319 = stack[-2];
    v316 = qcdr(v319);
    v319 = stack[-1];
    v319 = qcdr(v319);
    v319 = qcdr(v319);
    v319 = qcar(v319);
    fn = elt(env, 1); /* sroad */
    v319 = (*qfnn(fn))(qenv(fn), 3, v231, v316, v319);
    nil = C_nil;
    if (exception_pending()) goto v237;
    {
        Lisp_Object v213 = stack[-3];
        Lisp_Object v214 = stack[0];
        popv(5);
        return list3(v213, v214, v319);
    }
/* error exit handlers */
v237:
    popv(5);
    return nil;
}



/* Code for mv!-pow!-!- */

static Lisp_Object CC_mvKpowKK(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v317, v245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow--");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v1;

v1:
    v317 = stack[-1];
    if (v317 == nil) goto v262;
    v317 = stack[-1];
    v245 = qcar(v317);
    v317 = stack[0];
    v317 = qcar(v317);
    v245 = difference2(v245, v317);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    v317 = stack[-2];
    v317 = cons(v245, v317);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-3];
    stack[-2] = v317;
    v317 = stack[-1];
    v317 = qcdr(v317);
    stack[-1] = v317;
    v317 = stack[0];
    v317 = qcdr(v317);
    stack[0] = v317;
    goto v1;

v262:
    v317 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v317);
    }
/* error exit handlers */
v127:
    popv(4);
    return nil;
}



/* Code for multop */

static Lisp_Object CC_multop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v316, v231, v232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multop");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    v232 = v0;
/* end of prologue */
    v316 = qvalue(elt(env, 1)); /* kord!* */
    if (v316 == nil) goto v307;
    v316 = v232;
    v231 = qcar(v316);
    v316 = elt(env, 2); /* k!* */
    if (v231 == v316) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v231 = v232;
    v316 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* rmultpf */
        return (*qfn2(fn))(qenv(fn), v231, v316);
    }

v307:
    v231 = v232;
    v316 = (Lisp_Object)17; /* 1 */
    v316 = cons(v231, v316);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-1];
    v231 = ncons(v316);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-1];
    v316 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* multf */
        return (*qfn2(fn))(qenv(fn), v231, v316);
    }
/* error exit handlers */
v136:
    popv(2);
    return nil;
}



/* Code for red_better */

static Lisp_Object CC_red_better(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v310;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_better");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    v310 = v0;
/* end of prologue */
    fn = elt(env, 1); /* bas_dplen */
    stack[-1] = (*qfn1(fn))(qenv(fn), v310);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-2];
    v310 = stack[0];
    fn = elt(env, 1); /* bas_dplen */
    v310 = (*qfn1(fn))(qenv(fn), v310);
    nil = C_nil;
    if (exception_pending()) goto v307;
    {
        Lisp_Object v222 = stack[-1];
        popv(3);
        return Llessp(nil, v222, v310);
    }
/* error exit handlers */
v307:
    popv(3);
    return nil;
}



/* Code for ofsf_varlat */

static Lisp_Object CC_ofsf_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_varlat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v1 = qcdr(v1);
    v1 = qcar(v1);
    {
        fn = elt(env, 1); /* kernels */
        return (*qfn1(fn))(qenv(fn), v1);
    }
}



/* Code for sfto_davp */

static Lisp_Object CC_sfto_davp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v249;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_davp");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    stack[-1] = v0;
/* end of prologue */

v1:
    v248 = stack[-1];
    if (!consp(v248)) goto v262;
    v248 = stack[-1];
    v248 = qcar(v248);
    if (!consp(v248)) goto v262;
    v248 = stack[-1];
    v248 = qcar(v248);
    v248 = qcar(v248);
    v249 = qcdr(v248);
    v248 = (Lisp_Object)33; /* 2 */
    v248 = (Lisp_Object)greaterp2(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v323;
    v248 = v248 ? lisp_true : nil;
    env = stack[-2];
    if (v248 == nil) goto v209;
    v248 = stack[0];
    if (v248 == nil) goto v126;
    v248 = stack[-1];
    v248 = qcar(v248);
    v248 = qcar(v248);
    v249 = qcar(v248);
    v248 = stack[0];
    if (equal(v249, v248)) goto v126;
    v248 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v248); }

v126:
    v248 = stack[-1];
    v248 = qcar(v248);
    v249 = qcdr(v248);
    v248 = stack[-1];
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = CC_sfto_davp(env, v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    if (v248 == nil) goto v243;
    v248 = stack[-1];
    v248 = qcdr(v248);
    v249 = v248;
    v248 = stack[-1];
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcar(v248);
    stack[0] = v248;
    v248 = v249;
    stack[-1] = v248;
    goto v1;

v243:
    v248 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v248); }

v209:
    v248 = stack[-1];
    v248 = qcar(v248);
    v249 = qcdr(v248);
    v248 = stack[0];
    v248 = CC_sfto_davp(env, v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-2];
    if (v248 == nil) goto v141;
    v248 = stack[-1];
    v248 = qcdr(v248);
    stack[-1] = v248;
    goto v1;

v141:
    v248 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v248); }

v262:
    v248 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v248); }
/* error exit handlers */
v323:
    popv(3);
    return nil;
}



/* Code for updtemplate */

static Lisp_Object MS_CDECL CC_updtemplate(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v172,
                         Lisp_Object v226, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v328, v329;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "updtemplate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for updtemplate");
#endif
    if (stack >= stacklimit)
    {
        push3(v226,v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v172,v226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v226;
    v115 = v172;
    stack[-6] = v0;
/* end of prologue */
    stack[-4] = v115;
    v115 = stack[-4];
    if (v115 == nil) goto v222;
    v115 = stack[-4];
    v115 = qcar(v115);
    stack[0] = v115;
    v328 = stack[-6];
    v115 = stack[0];
    v328 = Lsubla(nil, v328, v115);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    stack[-7] = v328;
    v115 = stack[0];
    if (equal(v328, v115)) goto v227;
    v328 = stack[-7];
    v115 = stack[-5];
    fn = elt(env, 2); /* reval!-without */
    v328 = (*qfn2(fn))(qenv(fn), v328, v115);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    v329 = v328;
    v115 = stack[-7];
    if (equal(v328, v115)) goto v211;
    v115 = v329;
    goto v137;

v137:
    v115 = ncons(v115);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    stack[-2] = v115;
    stack[-3] = v115;
    goto v310;

v310:
    v115 = stack[-4];
    v115 = qcdr(v115);
    stack[-4] = v115;
    v115 = stack[-4];
    if (v115 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v115 = stack[-4];
    v115 = qcar(v115);
    stack[0] = v115;
    v328 = stack[-6];
    v115 = stack[0];
    v328 = Lsubla(nil, v328, v115);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    stack[-7] = v328;
    v115 = stack[0];
    if (equal(v328, v115)) goto v210;
    v328 = stack[-7];
    v115 = stack[-5];
    fn = elt(env, 2); /* reval!-without */
    v328 = (*qfn2(fn))(qenv(fn), v328, v115);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    v329 = v328;
    v115 = stack[-7];
    if (equal(v328, v115)) goto v199;
    v115 = v329;
    goto v209;

v209:
    v115 = ncons(v115);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    v115 = Lrplacd(nil, stack[-1], v115);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    v115 = stack[-2];
    v115 = qcdr(v115);
    stack[-2] = v115;
    goto v310;

v199:
    v115 = stack[-7];
    goto v209;

v210:
    v115 = stack[0];
    goto v209;

v211:
    v115 = stack[-7];
    goto v137;

v227:
    v115 = stack[0];
    goto v137;

v222:
    v115 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v115); }
/* error exit handlers */
v192:
    popv(9);
    return nil;
}



/* Code for subs3f1 */

static Lisp_Object MS_CDECL CC_subs3f1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v172,
                         Lisp_Object v226, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v195, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subs3f1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3f1");
#endif
    if (stack >= stacklimit)
    {
        push3(v226,v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v172,v226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v226;
    stack[-1] = v172;
    stack[-2] = v0;
/* end of prologue */
    v195 = qvalue(elt(env, 1)); /* nil */
    v194 = (Lisp_Object)17; /* 1 */
    v194 = cons(v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-4];
    stack[-3] = v194;
    goto v238;

v238:
    v194 = stack[-2];
    if (v194 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v194 = stack[-2];
    if (!consp(v194)) goto v196;
    v194 = stack[-2];
    v194 = qcar(v194);
    if (!consp(v194)) goto v196;
    v194 = stack[0];
    if (v194 == nil) goto v212;
    v194 = stack[-2];
    v194 = qcar(v194);
    v194 = qcdr(v194);
    if (!consp(v194)) goto v331;
    v194 = stack[-2];
    v194 = qcar(v194);
    v194 = qcdr(v194);
    v194 = qcar(v194);
    if (!(!consp(v194))) goto v212;

v331:
    v194 = stack[-2];
    v194 = qcar(v194);
    v195 = ncons(v194);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-4];
    v194 = (Lisp_Object)17; /* 1 */
    v194 = cons(v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-4];
    v174 = v194;
    goto v300;

v300:
    v194 = stack[-3];
    v195 = v174;
    fn = elt(env, 6); /* addsq */
    v194 = (*qfn2(fn))(qenv(fn), v194, v195);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-4];
    stack[-3] = v194;
    v194 = stack[-2];
    v194 = qcdr(v194);
    stack[-2] = v194;
    goto v238;

v212:
    v194 = stack[-2];
    v195 = qcar(v194);
    v194 = stack[-1];
    fn = elt(env, 7); /* subs3t */
    v194 = (*qfn2(fn))(qenv(fn), v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-4];
    v174 = v194;
    v194 = stack[0];
    if (v194 == nil) goto v300;
    v194 = qvalue(elt(env, 2)); /* mchfg!* */
    if (v194 == nil) goto v300;
    v194 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v194; /* mchfg!* */
    v194 = v174;
    v195 = qcar(v194);
    v194 = stack[-2];
    if (!(equal(v195, v194))) goto v261;
    v194 = v174;
    v195 = qcdr(v194);
    v194 = (Lisp_Object)17; /* 1 */
    if (!(v195 == v194)) goto v261;
    v195 = stack[-2];
    v194 = (Lisp_Object)17; /* 1 */
    v194 = cons(v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-4];
    v174 = v194;
    goto v300;

v261:
    v194 = qvalue(elt(env, 3)); /* !*resubs */
    if (v194 == nil) goto v300;
    v194 = qvalue(elt(env, 4)); /* !*sub2 */
    if (!(v194 == nil)) goto v252;
    v194 = qvalue(elt(env, 5)); /* powlis1!* */
    if (!(v194 == nil)) goto v252;

v247:
    v194 = v174;
    fn = elt(env, 8); /* subs3q */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-4];
    v174 = v194;
    goto v300;

v252:
    v194 = v174;
    fn = elt(env, 9); /* subs2q */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-4];
    v174 = v194;
    goto v247;

v196:
    stack[0] = stack[-3];
    v195 = stack[-2];
    v194 = (Lisp_Object)17; /* 1 */
    v194 = cons(v195, v194);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-4];
    {
        Lisp_Object v112 = stack[0];
        popv(5);
        fn = elt(env, 6); /* addsq */
        return (*qfn2(fn))(qenv(fn), v112, v194);
    }
/* error exit handlers */
v290:
    popv(5);
    return nil;
}



/* Code for ibalp_mk2 */

static Lisp_Object MS_CDECL CC_ibalp_mk2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v172,
                         Lisp_Object v226, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v239, v307, v222;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ibalp_mk2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v239 = v226;
    v307 = v172;
    v222 = v0;
/* end of prologue */
    return list3(v222, v307, v239);
}



/* Code for simpexpon1 */

static Lisp_Object CC_simpexpon1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v321, v237;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpon1");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v172;
    stack[-2] = v0;
/* end of prologue */
    v321 = qvalue(elt(env, 1)); /* !*numval */
    if (v321 == nil) goto v258;
    v237 = qvalue(elt(env, 2)); /* dmode!* */
    v321 = elt(env, 3); /* !:rd!: */
    if (v237 == v321) goto v227;
    v237 = qvalue(elt(env, 2)); /* dmode!* */
    v321 = elt(env, 4); /* !:cr!: */
    if (!(v237 == v321)) goto v258;

v227:
    v237 = stack[-1];
    v321 = stack[-2];
        popv(5);
        return Lapply1(nil, v237, v321);

v258:
    stack[-3] = qvalue(elt(env, 2)); /* dmode!* */
    qvalue(elt(env, 2)) = nil; /* dmode!* */
    stack[0] = qvalue(elt(env, 5)); /* alglist!* */
    qvalue(elt(env, 5)) = nil; /* alglist!* */
    v321 = qvalue(elt(env, 6)); /* nil */
    v321 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    qvalue(elt(env, 5)) = v321; /* alglist!* */
    v237 = stack[-1];
    v321 = stack[-2];
    v321 = Lapply1(nil, v237, v321);
    nil = C_nil;
    if (exception_pending()) goto v315;
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 2)) = stack[-3]; /* dmode!* */
    { popv(5); return onevalue(v321); }
/* error exit handlers */
v315:
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; /* alglist!* */
    qvalue(elt(env, 2)) = stack[-3]; /* dmode!* */
    popv(5);
    return nil;
}



/* Code for testredh */

static Lisp_Object CC_testredh(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testredh");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v124 = qvalue(elt(env, 2)); /* maxvar */
    v123 = stack[0];
    v123 = plus2(v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-2];
    v124 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v123/(16/CELL)));
    v123 = (Lisp_Object)1; /* 0 */
    v123 = *(Lisp_Object *)((char *)v124 + (CELL-TAG_VECTOR) + ((int32_t)v123/(16/CELL)));
    if (v123 == nil) goto v89;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v124 = qvalue(elt(env, 2)); /* maxvar */
    v123 = stack[0];
    v123 = plus2(v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-2];
    v124 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v123/(16/CELL)));
    v123 = (Lisp_Object)17; /* 1 */
    v123 = *(Lisp_Object *)((char *)v124 + (CELL-TAG_VECTOR) + ((int32_t)v123/(16/CELL)));
    v123 = qcar(v123);
    v124 = qcar(v123);
    v123 = (Lisp_Object)33; /* 2 */
    v123 = (Lisp_Object)lessp2(v124, v123);
    nil = C_nil;
    if (exception_pending()) goto v320;
    v123 = v123 ? lisp_true : nil;
    env = stack[-2];
    if (v123 == nil) goto v89;
    v123 = stack[0];
    fn = elt(env, 3); /* rowdel */
    v123 = (*qfn1(fn))(qenv(fn), v123);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-2];
    v123 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* testredzz */
        return (*qfn1(fn))(qenv(fn), v123);
    }

v89:
    v123 = nil;
    { popv(3); return onevalue(v123); }
/* error exit handlers */
v320:
    popv(3);
    return nil;
}



/* Code for unbind */

static Lisp_Object CC_unbind(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v216, v131, v132;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unbind");
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
    v224 = v0;
/* end of prologue */
    v132 = v224;
    v131 = elt(env, 1); /* binding */
    v216 = v224;
    v224 = elt(env, 1); /* binding */
    v224 = get(v216, v224);
    v224 = qcdr(v224);
        return Lputprop(nil, 3, v132, v131, v224);
}



/* Code for on */

static Lisp_Object CC_on(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for on");
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
    v223 = v0;
/* end of prologue */
    stack[0] = v223;
    goto v89;

v89:
    v223 = stack[0];
    if (v223 == nil) goto v262;
    v223 = stack[0];
    v223 = qcar(v223);
    fn = elt(env, 2); /* on1 */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-1];
    v223 = stack[0];
    v223 = qcdr(v223);
    stack[0] = v223;
    goto v89;

v262:
    v223 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v223); }
/* error exit handlers */
v216:
    popv(2);
    return nil;
}



/* Code for groebcpcompless!? */

static Lisp_Object CC_groebcpcomplessW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v206, v201, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebcpcompless?");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    stack[-1] = v0;
/* end of prologue */
    v205 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v205 == nil) goto v250;
    v205 = stack[-1];
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v206 = qcar(v205);
    v205 = stack[0];
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcar(v205);
    stack[-2] = difference2(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-3];
    v205 = stack[-1];
    v206 = qcar(v205);
    v205 = stack[0];
    v205 = qcar(v205);
    fn = elt(env, 3); /* vevcomp */
    v205 = (*qfn2(fn))(qenv(fn), v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-3];
    v202 = stack[-2];
    v201 = v205;
    v206 = v202;
    v205 = (Lisp_Object)1; /* 0 */
    if (v206 == v205) goto v318;
    v206 = v202;
    v205 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v206, v205);

v318:
    v206 = v201;
    v205 = (Lisp_Object)1; /* 0 */
    if (v206 == v205) goto v333;
    v206 = v201;
    v205 = (Lisp_Object)1; /* 0 */
        popv(4);
        return Llessp(nil, v206, v205);

v333:
    v205 = stack[-1];
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v206 = qcar(v205);
    v205 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    stack[-1] = (*qfn2(fn))(qenv(fn), v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v292;
    env = stack[-3];
    v205 = stack[0];
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v206 = qcar(v205);
    v205 = elt(env, 2); /* number */
    fn = elt(env, 4); /* vdpgetprop */
    v205 = (*qfn2(fn))(qenv(fn), v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v292;
    {
        Lisp_Object v114 = stack[-1];
        popv(4);
        return Llessp(nil, v114, v205);
    }

v250:
    v205 = stack[-1];
    v206 = qcar(v205);
    v205 = stack[0];
    v205 = qcar(v205);
    {
        popv(4);
        fn = elt(env, 5); /* vevcompless!? */
        return (*qfn2(fn))(qenv(fn), v206, v205);
    }
/* error exit handlers */
v292:
    popv(4);
    return nil;
}



/* Code for evenfree */

static Lisp_Object CC_evenfree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v319, v316;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evenfree");
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
    v319 = stack[0];
    if (v319 == nil) goto v21;
    v319 = stack[0];
    if (is_number(v319)) goto v310;
    v319 = stack[0];
    v319 = qcar(v319);
    v316 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-2];
    v319 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v319 = (*qfn2(fn))(qenv(fn), v316, v319);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-2];
    v319 = qcdr(v319);
    fn = elt(env, 3); /* absf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-2];
    v319 = stack[0];
    v319 = qcdr(v319);
    v319 = CC_evenfree(env, v319);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-2];
    {
        Lisp_Object v136 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* addf */
        return (*qfn2(fn))(qenv(fn), v136, v319);
    }

v310:
    v316 = stack[0];
    v319 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* qremd */
    v319 = (*qfn2(fn))(qenv(fn), v316, v319);
    nil = C_nil;
    if (exception_pending()) goto v314;
    env = stack[-2];
    v319 = qcdr(v319);
    {
        popv(3);
        fn = elt(env, 3); /* absf */
        return (*qfn1(fn))(qenv(fn), v319);
    }

v21:
    v319 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v319); }
/* error exit handlers */
v314:
    popv(3);
    return nil;
}



/* Code for contr2!-strand */

static Lisp_Object MS_CDECL CC_contr2Kstrand(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v172,
                         Lisp_Object v226, Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v334, v199, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "contr2-strand");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr2-strand");
#endif
    if (stack >= stacklimit)
    {
        push4(v2,v226,v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v172,v226,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v226;
    stack[-2] = v172;
    stack[-3] = v0;
/* end of prologue */

v229:
    v202 = stack[-3];
    if (v202 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v202 = stack[-3];
    v334 = qcar(v202);
    v202 = stack[-2];
    fn = elt(env, 3); /* contrsp */
    v202 = (*qfn2(fn))(qenv(fn), v334, v202);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    v199 = v202;
    v202 = v199;
    if (v202 == nil) goto v141;
    v202 = v199;
    v334 = qcar(v202);
    v202 = v199;
    v202 = qcdr(v202);
    v202 = Lmember(nil, v334, v202);
    if (v202 == nil) goto v129;
    v334 = stack[-3];
    v202 = stack[-1];
        popv(5);
        return Lappend(nil, v334, v202);

v129:
    v202 = stack[0];
    if (v202 == nil) goto v124;
    v202 = stack[-3];
    v334 = qcdr(v202);
    v202 = stack[-1];
    {
        popv(5);
        fn = elt(env, 4); /* contr2 */
        return (*qfnn(fn))(qenv(fn), 3, v199, v334, v202);
    }

v124:
    v202 = stack[-3];
    v334 = qcdr(v202);
    v202 = stack[-1];
    fn = elt(env, 4); /* contr2 */
    v200 = (*qfnn(fn))(qenv(fn), 3, v199, v334, v202);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    v199 = stack[-2];
    v334 = qvalue(elt(env, 1)); /* nil */
    v202 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v200;
    stack[-2] = v199;
    stack[-1] = v334;
    stack[0] = v202;
    goto v229;

v141:
    v202 = stack[-3];
    stack[0] = qcdr(v202);
    v202 = stack[-3];
    v334 = qcar(v202);
    v202 = stack[-1];
    v334 = cons(v334, v202);
    nil = C_nil;
    if (exception_pending()) goto v328;
    env = stack[-4];
    v202 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = stack[0];
    stack[-1] = v334;
    stack[0] = v202;
    goto v229;
/* error exit handlers */
v328:
    popv(5);
    return nil;
}



/* Code for mo!=revlexcomp */

static Lisp_Object CC_moMrevlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=revlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    stack[-1] = v0;
/* end of prologue */
    v127 = stack[-1];
    stack[-2] = Llength(nil, v127);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-3];
    v127 = stack[0];
    v127 = Llength(nil, v127);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v127))) goto v89;
    v127 = stack[0];
    stack[-2] = Llength(nil, v127);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-3];
    v127 = stack[-1];
    v127 = Llength(nil, v127);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-3];
    if (((int32_t)(stack[-2])) > ((int32_t)(v127))) goto v222;
    v127 = stack[-1];
    stack[-1] = Lreverse(nil, v127);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-3];
    v127 = stack[0];
    v127 = Lreverse(nil, v127);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-3];
    fn = elt(env, 1); /* mo!=degcomp */
    v127 = (*qfn2(fn))(qenv(fn), stack[-1], v127);
    nil = C_nil;
    if (exception_pending()) goto v231;
    popv(4);
    return negate(v127);

v222:
    v127 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v127); }

v89:
    v127 = (Lisp_Object)-15; /* -1 */
    { popv(4); return onevalue(v127); }
/* error exit handlers */
v231:
    popv(4);
    return nil;
}



/* Code for dd */

static Lisp_Object CC_dd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249, v117, v116;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dd");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    stack[-2] = v0;
/* end of prologue */
    v117 = stack[0];
    v249 = stack[-2];
    fn = elt(env, 5); /* dquot */
    v249 = (*qfn2(fn))(qenv(fn), v117, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v116 = v249;
    v249 = v116;
    if (v249 == nil) goto v259;
    v117 = qvalue(elt(env, 1)); /* ordering */
    v249 = elt(env, 2); /* lex */
    if (v117 == v249) goto v317;
    v249 = v116;
    v249 = qcdr(v249);
    v116 = v249;
    goto v317;

v317:
    v249 = v116;
    fn = elt(env, 6); /* leftzeros */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    stack[-3] = v249;
    v249 = qvalue(elt(env, 3)); /* nc */
    if (!(v249 == nil)) goto v125;
    stack[-1] = stack[-3];
    v249 = qvalue(elt(env, 4)); /* varlist */
    stack[0] = Llength(nil, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v249 = stack[-2];
    fn = elt(env, 7); /* class */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v249 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v249 + TAG_FIXNUM);
    if (((int32_t)(stack[-1])) < ((int32_t)(v249))) goto v125;
    v249 = (Lisp_Object)49; /* 3 */
    { popv(5); return onevalue(v249); }

v125:
    v249 = qvalue(elt(env, 3)); /* nc */
    if (v249 == nil) goto v254;
    stack[0] = stack[-3];
    v249 = qvalue(elt(env, 4)); /* varlist */
    v249 = Llength(nil, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-4];
    v117 = qvalue(elt(env, 3)); /* nc */
    v249 = (Lisp_Object)(int32_t)((int32_t)v249 - (int32_t)v117 + TAG_FIXNUM);
    if (((int32_t)(stack[0])) < ((int32_t)(v249))) goto v254;
    v249 = (Lisp_Object)65; /* 4 */
    { popv(5); return onevalue(v249); }

v254:
    v249 = (Lisp_Object)33; /* 2 */
    { popv(5); return onevalue(v249); }

v259:
    v117 = stack[-2];
    v249 = stack[0];
    fn = elt(env, 8); /* dless */
    v249 = (*qfn2(fn))(qenv(fn), v117, v249);
    nil = C_nil;
    if (exception_pending()) goto v251;
    if (v249 == nil) goto v196;
    v249 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v249); }

v196:
    v249 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v249); }
/* error exit handlers */
v251:
    popv(5);
    return nil;
}



/* Code for artimes!: */

static Lisp_Object CC_artimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v227, v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for artimes:");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v227 = v172;
    v228 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* dmode!* */
    qvalue(elt(env, 1)) = nil; /* dmode!* */
    stack[-1] = qvalue(elt(env, 2)); /* !*exp */
    qvalue(elt(env, 2)) = nil; /* !*exp */
    v137 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 2)) = v137; /* !*exp */
    stack[0] = elt(env, 4); /* !:ar!: */
    v137 = v228;
    v137 = qcdr(v137);
    v227 = qcdr(v227);
    fn = elt(env, 5); /* multf */
    v137 = (*qfn2(fn))(qenv(fn), v137, v227);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-3];
    fn = elt(env, 6); /* reducepowers */
    v137 = (*qfn1(fn))(qenv(fn), v137);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-3];
    v137 = cons(stack[0], v137);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v137); }
/* error exit handlers */
v130:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-1]; /* !*exp */
    qvalue(elt(env, 1)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for conv!:bf2i */

static Lisp_Object CC_convTbf2i(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v239;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conv:bf2i");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v240 = v0;
/* end of prologue */
    v239 = v240;
    v239 = qcdr(v239);
    v239 = qcar(v239);
    v240 = qcdr(v240);
    v240 = qcdr(v240);
        return Lash1(nil, v239, v240);
}



/* Code for noncomperm */

static Lisp_Object CC_noncomperm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v292, v114, v300;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomperm");
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
    v292 = stack[-4];
    if (v292 == nil) goto v21;
    v292 = stack[-4];
    stack[-5] = v292;
    goto v307;

v307:
    v292 = stack[-5];
    if (v292 == nil) goto v224;
    v292 = stack[-5];
    v292 = qcar(v292);
    stack[0] = v292;
    v114 = stack[0];
    v292 = stack[-4];
    fn = elt(env, 3); /* noncomdel */
    v292 = (*qfn2(fn))(qenv(fn), v114, v292);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    v300 = v292;
    v114 = v300;
    v292 = elt(env, 2); /* failed */
    if (v114 == v292) goto v306;
    v292 = v300;
    v114 = CC_noncomperm(env, v292);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    v292 = stack[0];
    fn = elt(env, 4); /* mapcons */
    v292 = (*qfn2(fn))(qenv(fn), v114, v292);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    goto v245;

v245:
    stack[-3] = v292;
    v292 = stack[-3];
    fn = elt(env, 5); /* lastpair */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    stack[-2] = v292;
    v292 = stack[-5];
    v292 = qcdr(v292);
    stack[-5] = v292;
    v292 = stack[-2];
    if (!consp(v292)) goto v307;
    else goto v222;

v222:
    v292 = stack[-5];
    if (v292 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v292 = stack[-5];
    v292 = qcar(v292);
    stack[0] = v292;
    v114 = stack[0];
    v292 = stack[-4];
    fn = elt(env, 3); /* noncomdel */
    v292 = (*qfn2(fn))(qenv(fn), v114, v292);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    v300 = v292;
    v114 = v300;
    v292 = elt(env, 2); /* failed */
    if (v114 == v292) goto v254;
    v292 = v300;
    v114 = CC_noncomperm(env, v292);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    v292 = stack[0];
    fn = elt(env, 4); /* mapcons */
    v292 = (*qfn2(fn))(qenv(fn), v114, v292);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    goto v284;

v284:
    v292 = Lrplacd(nil, stack[-1], v292);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    v292 = stack[-2];
    fn = elt(env, 5); /* lastpair */
    v292 = (*qfn1(fn))(qenv(fn), v292);
    nil = C_nil;
    if (exception_pending()) goto v291;
    env = stack[-6];
    stack[-2] = v292;
    v292 = stack[-5];
    v292 = qcdr(v292);
    stack[-5] = v292;
    goto v222;

v254:
    v292 = qvalue(elt(env, 1)); /* nil */
    goto v284;

v306:
    v292 = qvalue(elt(env, 1)); /* nil */
    goto v245;

v224:
    v292 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v292); }

v21:
    v292 = stack[-4];
    popv(7);
    return ncons(v292);
/* error exit handlers */
v291:
    popv(7);
    return nil;
}



/* Code for sfto_gcdf!* */

static Lisp_Object CC_sfto_gcdfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v310, v240, v239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf*");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v240 = v172;
    v239 = v0;
/* end of prologue */
    v310 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*gcd */
    qvalue(elt(env, 2)) = v310; /* !*gcd */
    v310 = v239;
    fn = elt(env, 3); /* sfto_gcdf */
    v310 = (*qfn2(fn))(qenv(fn), v310, v240);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v310); }
/* error exit handlers */
v222:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for cl_atmlc */

static Lisp_Object CC_cl_atmlc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v309, v326;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atmlc");
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
    v309 = v0;
/* end of prologue */
    v326 = v309;
    v309 = (Lisp_Object)17; /* 1 */
    v309 = cons(v326, v309);
    errexit();
    return ncons(v309);
}



/* Code for ibalp_atomp */

static Lisp_Object CC_ibalp_atomp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v315;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_atomp");
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
    v315 = stack[0];
    v126 = elt(env, 1); /* true */
    v126 = (v315 == v126 ? lisp_true : nil);
    if (!(v126 == nil)) goto v1;
    v315 = stack[0];
    v126 = elt(env, 2); /* false */
    v126 = (v315 == v126 ? lisp_true : nil);
    goto v1;

v1:
    if (!(v126 == nil)) { popv(2); return onevalue(v126); }
    v126 = stack[0];
    if (!consp(v126)) goto v234;
    v126 = stack[0];
    v126 = qcar(v126);
    v315 = v126;
    goto v218;

v218:
    v126 = elt(env, 3); /* equal */
    if (v315 == v126) goto v227;
    v126 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v126); }

v227:
    v126 = stack[0];
    fn = elt(env, 5); /* ibalp_arg2l */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v230;
    env = stack[-1];
    if (symbolp(v126)) goto v321;
    v126 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v126); }

v321:
    v126 = stack[0];
    fn = elt(env, 6); /* ibalp_arg2r */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v230;
    v126 = (is_number(v126) ? lisp_true : nil);
    { popv(2); return onevalue(v126); }

v234:
    v126 = stack[0];
    v315 = v126;
    goto v218;
/* error exit handlers */
v230:
    popv(2);
    return nil;
}



/* Code for sub_math */

static Lisp_Object MS_CDECL CC_sub_math(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v322, v332;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "sub_math");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sub_math");
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
    v332 = qvalue(elt(env, 1)); /* char */
    v322 = elt(env, 2); /* (a p p l y) */
    if (equal(v332, v322)) goto v140;
    v332 = qvalue(elt(env, 1)); /* char */
    v322 = elt(env, 5); /* (v e c t o r) */
    if (equal(v332, v322)) goto v233;
    v322 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 9); /* compress!* */
    v332 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    v322 = qvalue(elt(env, 8)); /* rdelems!* */
    v322 = Lassoc(nil, v332, v322);
    stack[-1] = v322;
    if (v322 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v322 = stack[-1];
    v322 = qcdr(v322);
    v332 = qcar(v322);
    v322 = nil;
    fn = elt(env, 10); /* apply */
    v322 = (*qfn2(fn))(qenv(fn), v332, v322);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    stack[-2] = v322;
    v322 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 9); /* compress!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    v322 = stack[-1];
    fn = elt(env, 11); /* third */
    v322 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    if (equal(stack[0], v322)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v322 = stack[-1];
    v322 = qcdr(v322);
    fn = elt(env, 11); /* third */
    v332 = (*qfn1(fn))(qenv(fn), v322);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    v322 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 12); /* errorml */
    v322 = (*qfn2(fn))(qenv(fn), v332, v322);
    nil = C_nil;
    if (exception_pending()) goto v206;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v233:
    fn = elt(env, 13); /* vectorrd */
    v322 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    stack[-2] = v322;
    v332 = qvalue(elt(env, 1)); /* char */
    v322 = elt(env, 6); /* (!/ v e c t o r) */
    if (equal(v332, v322)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v332 = elt(env, 7); /* "</vector>" */
    v322 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 12); /* errorml */
    v322 = (*qfn2(fn))(qenv(fn), v332, v322);
    nil = C_nil;
    if (exception_pending()) goto v206;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v140:
    fn = elt(env, 14); /* applyml */
    v322 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-3];
    stack[-2] = v322;
    v332 = qvalue(elt(env, 1)); /* char */
    v322 = elt(env, 3); /* (!/ a p p l y) */
    if (equal(v332, v322)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v332 = elt(env, 4); /* "</apply>" */
    v322 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 12); /* errorml */
    v322 = (*qfn2(fn))(qenv(fn), v332, v322);
    nil = C_nil;
    if (exception_pending()) goto v206;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v206:
    popv(4);
    return nil;
}



/* Code for ps!:expression */

static Lisp_Object CC_psTexpression(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v306, v308, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expression");
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
    v308 = v0;
/* end of prologue */
    v306 = v308;
    if (!consp(v306)) { popv(1); return onevalue(v308); }
    v306 = v308;
    v198 = qcar(v306);
    v306 = elt(env, 1); /* !:ps!: */
    if (v198 == v306) goto v258;
    v306 = v308;
    v198 = qcar(v306);
    v306 = elt(env, 2); /* dname */
    v306 = get(v198, v306);
    env = stack[0];
    if (!(v306 == nil)) { popv(1); return onevalue(v308); }

v258:
    v306 = (Lisp_Object)97; /* 6 */
    {
        popv(1);
        fn = elt(env, 3); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v308, v306);
    }
}



/* Code for matsm!*1 */

static Lisp_Object CC_matsmH1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v281, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm*1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v281 = v0;
/* end of prologue */
    stack[-8] = elt(env, 1); /* mat */
    stack[-7] = v281;
    v281 = stack[-7];
    if (v281 == nil) goto v223;
    v281 = stack[-7];
    v281 = qcar(v281);
    stack[-3] = v281;
    v281 = stack[-3];
    if (v281 == nil) goto v317;
    v281 = stack[-3];
    v281 = qcar(v281);
    fn = elt(env, 4); /* subs2!* */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    stack[-1] = v281;
    stack[-2] = v281;
    goto v196;

v196:
    v281 = stack[-3];
    v281 = qcdr(v281);
    stack[-3] = v281;
    v281 = stack[-3];
    if (v281 == nil) goto v213;
    stack[0] = stack[-1];
    v281 = stack[-3];
    v281 = qcar(v281);
    fn = elt(env, 4); /* subs2!* */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v281 = Lrplacd(nil, stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v281 = stack[-1];
    v281 = qcdr(v281);
    stack[-1] = v281;
    goto v196;

v213:
    v281 = stack[-2];
    goto v130;

v130:
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    stack[-5] = v281;
    stack[-6] = v281;
    goto v307;

v307:
    v281 = stack[-7];
    v281 = qcdr(v281);
    stack[-7] = v281;
    v281 = stack[-7];
    if (v281 == nil) goto v242;
    stack[-4] = stack[-5];
    v281 = stack[-7];
    v281 = qcar(v281);
    stack[-3] = v281;
    v281 = stack[-3];
    if (v281 == nil) goto v117;
    v281 = stack[-3];
    v281 = qcar(v281);
    fn = elt(env, 4); /* subs2!* */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    stack[-1] = v281;
    stack[-2] = v281;
    goto v254;

v254:
    v281 = stack[-3];
    v281 = qcdr(v281);
    stack[-3] = v281;
    v281 = stack[-3];
    if (v281 == nil) goto v206;
    stack[0] = stack[-1];
    v281 = stack[-3];
    v281 = qcar(v281);
    fn = elt(env, 4); /* subs2!* */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    fn = elt(env, 5); /* !*q2a */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v281 = Lrplacd(nil, stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v281 = stack[-1];
    v281 = qcdr(v281);
    stack[-1] = v281;
    goto v254;

v206:
    v281 = stack[-2];
    goto v141;

v141:
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v281 = Lrplacd(nil, stack[-4], v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v281 = stack[-5];
    v281 = qcdr(v281);
    stack[-5] = v281;
    goto v307;

v117:
    v281 = qvalue(elt(env, 2)); /* nil */
    goto v141;

v242:
    v281 = stack[-6];
    goto v238;

v238:
    v281 = cons(stack[-8], v281);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-9];
    v148 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 3)) = v148; /* !*sub2 */
    { popv(10); return onevalue(v281); }

v317:
    v281 = qvalue(elt(env, 2)); /* nil */
    goto v130;

v223:
    v281 = qvalue(elt(env, 2)); /* nil */
    goto v238;
/* error exit handlers */
v112:
    popv(10);
    return nil;
}



/* Code for isimplicit */

static Lisp_Object CC_isimplicit(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v306, v308, v198;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isimplicit");
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
    v306 = elt(env, 1); /* implicit!  */
    v306 = Lexplode(nil, v306);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[-2];
    stack[-1] = v306;
    v306 = stack[0];
    v306 = Lexplode(nil, v306);
    nil = C_nil;
    if (exception_pending()) goto v319;
    v308 = v306;
    v306 = lisp_true;
    v198 = v306;
    goto v240;

v240:
    v306 = v198;
    if (v306 == nil) { popv(3); return onevalue(v198); }
    v306 = stack[-1];
    if (v306 == nil) { popv(3); return onevalue(v198); }
    v306 = v308;
    v198 = qcar(v306);
    v306 = stack[-1];
    v306 = qcar(v306);
    v306 = (equal(v198, v306) ? lisp_true : nil);
    v198 = v306;
    v306 = stack[-1];
    v306 = qcdr(v306);
    stack[-1] = v306;
    v306 = v308;
    v306 = qcdr(v306);
    v308 = v306;
    goto v240;
/* error exit handlers */
v319:
    popv(3);
    return nil;
}



/* Code for bsubs */

static Lisp_Object CC_bsubs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bsubs");
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
    stack[0] = v0;
/* end of prologue */
    v124 = stack[0];
    if (v124 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v124 = stack[0];
    if (!consp(v124)) goto v238;
    v124 = stack[0];
    stack[-3] = v124;
    v124 = stack[-3];
    if (v124 == nil) goto v196;
    v124 = stack[-3];
    v124 = qcar(v124);
    v124 = CC_bsubs(env, v124);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    stack[-1] = v124;
    stack[-2] = v124;
    goto v217;

v217:
    v124 = stack[-3];
    v124 = qcdr(v124);
    stack[-3] = v124;
    v124 = stack[-3];
    if (v124 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v124 = stack[-3];
    v124 = qcar(v124);
    v124 = CC_bsubs(env, v124);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    v124 = Lrplacd(nil, stack[0], v124);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    v124 = stack[-1];
    v124 = qcdr(v124);
    stack[-1] = v124;
    goto v217;

v196:
    v124 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v124); }

v238:
    v124 = stack[0];
    fn = elt(env, 2); /* bound */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    if (v124 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v124 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); /* binding */
        return (*qfn1(fn))(qenv(fn), v124);
    }
/* error exit handlers */
v257:
    popv(5);
    return nil;
}



/* Code for off */

static Lisp_Object CC_off(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for off");
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
    v223 = v0;
/* end of prologue */
    stack[0] = v223;
    goto v89;

v89:
    v223 = stack[0];
    if (v223 == nil) goto v262;
    v223 = stack[0];
    v223 = qcar(v223);
    fn = elt(env, 2); /* off1 */
    v223 = (*qfn1(fn))(qenv(fn), v223);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-1];
    v223 = stack[0];
    v223 = qcdr(v223);
    stack[0] = v223;
    goto v89;

v262:
    v223 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v223); }
/* error exit handlers */
v216:
    popv(2);
    return nil;
}



/* Code for dipprodin1 */

static Lisp_Object MS_CDECL CC_dipprodin1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v172,
                         Lisp_Object v226, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v138;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipprodin1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipprodin1");
#endif
    if (stack >= stacklimit)
    {
        push3(v226,v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v172,v226);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v226;
    stack[-1] = v172;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v140;

v140:
    v215 = stack[0];
    if (v215 == nil) goto v240;
    v138 = stack[-1];
    v215 = stack[0];
    v215 = qcar(v215);
    fn = elt(env, 2); /* evsum */
    v138 = (*qfn2(fn))(qenv(fn), v138, v215);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v215 = stack[-3];
    v215 = cons(v138, v215);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[-3] = v215;
    v138 = stack[-2];
    v215 = stack[0];
    v215 = qcdr(v215);
    v215 = qcar(v215);
    fn = elt(env, 3); /* bcprod */
    v138 = (*qfn2(fn))(qenv(fn), v138, v215);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    v215 = stack[-3];
    v215 = cons(v138, v215);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-4];
    stack[-3] = v215;
    v215 = stack[0];
    v215 = qcdr(v215);
    v215 = qcdr(v215);
    stack[0] = v215;
    goto v140;

v240:
    v138 = stack[-3];
    v215 = qvalue(elt(env, 1)); /* dipzero */
    {
        popv(5);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v138, v215);
    }
/* error exit handlers */
v123:
    popv(5);
    return nil;
}



/* Code for prepsq!*2 */

static Lisp_Object CC_prepsqH2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v239, v307;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*2");
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
    v240 = v0;
/* end of prologue */
    v307 = v240;
    v239 = (Lisp_Object)17; /* 1 */
    v240 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* prepsq!*1 */
    v240 = (*qfnn(fn))(qenv(fn), 3, v307, v239, v240);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* replus */
        return (*qfn1(fn))(qenv(fn), v240);
    }
/* error exit handlers */
v222:
    popv(1);
    return nil;
}



/* Code for red!-weight!-less!-p */

static Lisp_Object CC_redKweightKlessKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v306, v308, v198;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight-less-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v306 = v172;
    v308 = v0;
/* end of prologue */
    v245 = v308;
    v198 = qcar(v245);
    v245 = v306;
    v245 = qcar(v245);
    if (equal(v198, v245)) goto v222;
    v245 = v308;
    v245 = qcar(v245);
    v306 = qcar(v306);
        return Llessp(nil, v245, v306);

v222:
    v245 = v308;
    v245 = qcdr(v245);
    v306 = qcdr(v306);
        return Llessp(nil, v245, v306);
}



/* Code for pv_times3 */

static Lisp_Object CC_pv_times3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v218;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_times3");
#endif
    if (stack >= stacklimit)
    {
        push2(v172,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v172);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v172;
    stack[-1] = v0;
/* end of prologue */
    v217 = stack[-1];
    v218 = qcar(v217);
    v217 = stack[0];
    v217 = qcar(v217);
    stack[-2] = times2(v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-3];
    v217 = stack[-1];
    v218 = qcdr(v217);
    v217 = stack[0];
    v217 = qcdr(v217);
    fn = elt(env, 1); /* pappend */
    v217 = (*qfn2(fn))(qenv(fn), v218, v217);
    nil = C_nil;
    if (exception_pending()) goto v258;
    {
        Lisp_Object v234 = stack[-2];
        popv(4);
        return cons(v234, v217);
    }
/* error exit handlers */
v258:
    popv(4);
    return nil;
}



/* Code for lto_catsoc */

static Lisp_Object CC_lto_catsoc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v172)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v223;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_catsoc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v225 = v172;
    v223 = v0;
/* end of prologue */
    v225 = Latsoc(nil, v223, v225);
    v223 = v225;
    v225 = v223;
    if (v225 == nil) goto v239;
    v225 = v223;
    v225 = qcdr(v225);
    return onevalue(v225);

v239:
    v225 = nil;
    return onevalue(v225);
}



setup_type const u09_setup[] =
{
    {"simp",                    CC_simp,        too_many_1,    wrong_no_1},
    {"downwght1",               too_few_2,      CC_downwght1,  wrong_no_2},
    {"revalind",                CC_revalind,    too_many_1,    wrong_no_1},
    {"getphystypesf",           CC_getphystypesf,too_many_1,   wrong_no_1},
    {"divdm",                   too_few_2,      CC_divdm,      wrong_no_2},
    {"red_divtest",             too_few_2,      CC_red_divtest,wrong_no_2},
    {"*id2num",                 CC_Hid2num,     too_many_1,    wrong_no_1},
    {"b:ordexn",                too_few_2,      CC_bTordexn,   wrong_no_2},
    {"general-reciprocal-by-gcd",wrong_no_na,   wrong_no_nb,   (n_args *)CC_generalKreciprocalKbyKgcd},
    {"color1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_color1},
    {"eolcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eolcheck},
    {"basicom",                 CC_basicom,     too_many_1,    wrong_no_1},
    {"writepri",                too_few_2,      CC_writepri,   wrong_no_2},
    {"vevlcm",                  too_few_2,      CC_vevlcm,     wrong_no_2},
    {"mkuwedge",                CC_mkuwedge,    too_many_1,    wrong_no_1},
    {"rd:minus",                CC_rdTminus,    too_many_1,    wrong_no_1},
    {"deletemult*",             CC_deletemultH, too_many_1,    wrong_no_1},
    {"compactfmatch2",          CC_compactfmatch2,too_many_1,  wrong_no_1},
    {"dividef",                 too_few_2,      CC_dividef,    wrong_no_2},
    {"arintequiv:",             CC_arintequivT, too_many_1,    wrong_no_1},
    {"gionep:",                 CC_gionepT,     too_many_1,    wrong_no_1},
    {"ibalp_varlt1",            too_few_2,      CC_ibalp_varlt1,wrong_no_2},
    {"naryrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_naryrd},
    {"ps:putv",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_psTputv},
    {"zeropp",                  CC_zeropp,      too_many_1,    wrong_no_1},
    {"vevdif",                  too_few_2,      CC_vevdif,     wrong_no_2},
    {"split-road",              too_few_2,      CC_splitKroad, wrong_no_2},
    {"mv-pow--",                too_few_2,      CC_mvKpowKK,   wrong_no_2},
    {"multop",                  too_few_2,      CC_multop,     wrong_no_2},
    {"red_better",              too_few_2,      CC_red_better, wrong_no_2},
    {"ofsf_varlat",             CC_ofsf_varlat, too_many_1,    wrong_no_1},
    {"sfto_davp",               too_few_2,      CC_sfto_davp,  wrong_no_2},
    {"updtemplate",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_updtemplate},
    {"subs3f1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_subs3f1},
    {"ibalp_mk2",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_mk2},
    {"simpexpon1",              too_few_2,      CC_simpexpon1, wrong_no_2},
    {"testredh",                CC_testredh,    too_many_1,    wrong_no_1},
    {"unbind",                  CC_unbind,      too_many_1,    wrong_no_1},
    {"on",                      CC_on,          too_many_1,    wrong_no_1},
    {"groebcpcompless?",        too_few_2,      CC_groebcpcomplessW,wrong_no_2},
    {"evenfree",                CC_evenfree,    too_many_1,    wrong_no_1},
    {"contr2-strand",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_contr2Kstrand},
    {"mo=revlexcomp",           too_few_2,      CC_moMrevlexcomp,wrong_no_2},
    {"dd",                      too_few_2,      CC_dd,         wrong_no_2},
    {"artimes:",                too_few_2,      CC_artimesT,   wrong_no_2},
    {"conv:bf2i",               CC_convTbf2i,   too_many_1,    wrong_no_1},
    {"noncomperm",              CC_noncomperm,  too_many_1,    wrong_no_1},
    {"sfto_gcdf*",              too_few_2,      CC_sfto_gcdfH, wrong_no_2},
    {"cl_atmlc",                CC_cl_atmlc,    too_many_1,    wrong_no_1},
    {"ibalp_atomp",             CC_ibalp_atomp, too_many_1,    wrong_no_1},
    {"sub_math",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_sub_math},
    {"ps:expression",           CC_psTexpression,too_many_1,   wrong_no_1},
    {"matsm*1",                 CC_matsmH1,     too_many_1,    wrong_no_1},
    {"isimplicit",              CC_isimplicit,  too_many_1,    wrong_no_1},
    {"bsubs",                   CC_bsubs,       too_many_1,    wrong_no_1},
    {"off",                     CC_off,         too_many_1,    wrong_no_1},
    {"dipprodin1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipprodin1},
    {"prepsq*2",                CC_prepsqH2,    too_many_1,    wrong_no_1},
    {"red-weight-less-p",       too_few_2,      CC_redKweightKlessKp,wrong_no_2},
    {"pv_times3",               too_few_2,      CC_pv_times3,  wrong_no_2},
    {"lto_catsoc",              too_few_2,      CC_lto_catsoc, wrong_no_2},
    {NULL, (one_args *)"u09", (two_args *)"10642 6492315 5496231", 0}
};

/* end of generated code */
