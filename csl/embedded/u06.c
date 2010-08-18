
/* $destdir/generated-c\u06.c Machine generated C code */

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


/* Code for divd */

static Lisp_Object CC_divd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for divd");
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
    goto v25;

v25:
    v22 = stack[-1];
    if (v22 == nil) goto v26;
    v22 = stack[-2];
    if (v22 == nil) goto v27;
    v22 = stack[-2];
    if (!consp(v22)) goto v28;
    v22 = stack[-2];
    v22 = qcar(v22);
    if (!consp(v22)) goto v28;
    v22 = stack[-2];
    v22 = qcar(v22);
    stack[0] = qcar(v22);
    v22 = stack[-2];
    v22 = qcar(v22);
    v23 = qcdr(v22);
    v22 = stack[-1];
    v23 = CC_divd(env, v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    v22 = stack[-3];
    v22 = acons(stack[0], v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    stack[-3] = v22;
    v22 = stack[-2];
    v22 = qcdr(v22);
    stack[-2] = v22;
    goto v25;

v28:
    stack[0] = stack[-3];
    v23 = stack[-2];
    v22 = stack[-1];
    fn = elt(env, 4); /* divdm */
    v22 = (*qfn2(fn))(qenv(fn), v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    {
        Lisp_Object v30 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v30, v22);
    }

v27:
    v22 = stack[-3];
    {
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v22);
    }

v26:
    v22 = stack[-2];
    if (v22 == nil) goto v31;
    stack[0] = stack[-3];
    v24 = elt(env, 1); /* poly */
    v23 = (Lisp_Object)33; /* 2 */
    v22 = elt(env, 3); /* "Zero divisor" */
    fn = elt(env, 6); /* rerror */
    v22 = (*qfnn(fn))(qenv(fn), 3, v24, v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    {
        Lisp_Object v32 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v32, v22);
    }

v31:
    stack[0] = stack[-3];
    v24 = elt(env, 1); /* poly */
    v23 = (Lisp_Object)17; /* 1 */
    v22 = elt(env, 2); /* "0/0 formed" */
    fn = elt(env, 6); /* rerror */
    v22 = (*qfnn(fn))(qenv(fn), 3, v24, v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-4];
    {
        Lisp_Object v33 = stack[0];
        popv(5);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v33, v22);
    }
/* error exit handlers */
v29:
    popv(5);
    return nil;
}



/* Code for dp_term */

static Lisp_Object CC_dp_term(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_term");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v1;
    v36 = v0;
/* end of prologue */
    return cons(v35, v36);
}



/* Code for maprint */

static Lisp_Object CC_maprint(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v37)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v82, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maprint");
#endif
    if (stack >= stacklimit)
    {
        push2(v37,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v81 = v37;
    stack[-3] = v1;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* p!*!* */
    qvalue(elt(env, 1)) = nil; /* p!*!* */
    qvalue(elt(env, 1)) = v81; /* p!*!* */
    stack[0] = nil;
    v81 = qvalue(elt(env, 1)); /* p!*!* */
    stack[-2] = v81;
    v81 = stack[-3];
    if (v81 == nil) goto v84;
    v81 = stack[-3];
    if (!consp(v81)) goto v85;
    v81 = stack[-3];
    v81 = qcar(v81);
    if (!consp(v81)) goto v2;
    v81 = stack[-3];
    v82 = qcar(v81);
    v81 = stack[-2];
    v81 = CC_maprint(env, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    goto v87;

v87:
    v81 = elt(env, 5); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v81 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 12)) = v81; /* obrkp!* */
    v81 = qvalue(elt(env, 10)); /* orig!* */
    stack[0] = v81;
    v82 = qvalue(elt(env, 11)); /* posn!* */
    v81 = (Lisp_Object)289; /* 18 */
    v81 = (Lisp_Object)lessp2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v81 = v81 ? lisp_true : nil;
    env = stack[-5];
    if (v81 == nil) goto v88;
    v81 = qvalue(elt(env, 11)); /* posn!* */
    goto v89;

v89:
    qvalue(elt(env, 10)) = v81; /* orig!* */
    v81 = stack[-3];
    v81 = qcdr(v81);
    if (v81 == nil) goto v90;
    v83 = elt(env, 13); /* !*comma!* */
    v82 = (Lisp_Object)1; /* 0 */
    v81 = stack[-3];
    v81 = qcdr(v81);
    fn = elt(env, 16); /* inprint */
    v81 = (*qfnn(fn))(qenv(fn), 3, v83, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    goto v90;

v90:
    v81 = qvalue(elt(env, 14)); /* t */
    qvalue(elt(env, 12)) = v81; /* obrkp!* */
    v81 = stack[0];
    qvalue(elt(env, 10)) = v81; /* orig!* */
    v81 = elt(env, 6); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v81 = stack[-3];
    goto v25;

v25:
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    { popv(6); return onevalue(v81); }

v88:
    v82 = qvalue(elt(env, 10)); /* orig!* */
    v81 = (Lisp_Object)49; /* 3 */
    v81 = plus2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    goto v89;

v2:
    v81 = stack[-3];
    v82 = qcar(v81);
    v81 = elt(env, 7); /* pprifn */
    v81 = get(v82, v81);
    env = stack[-5];
    stack[-1] = v81;
    if (v81 == nil) goto v91;
    v83 = stack[-1];
    v82 = stack[-3];
    v81 = stack[-2];
    v82 = Lapply2(nil, 3, v83, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v81 = elt(env, 8); /* failed */
    if (!(v82 == v81)) goto v92;

v91:
    v81 = stack[-3];
    v82 = qcar(v81);
    v81 = elt(env, 9); /* prifn */
    v81 = get(v82, v81);
    env = stack[-5];
    stack[-1] = v81;
    if (v81 == nil) goto v93;
    v82 = stack[-1];
    v81 = stack[-3];
    v82 = Lapply1(nil, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v81 = elt(env, 8); /* failed */
    if (!(v82 == v81)) goto v92;

v93:
    v81 = stack[-3];
    v82 = qcar(v81);
    v81 = elt(env, 4); /* infix */
    v81 = get(v82, v81);
    env = stack[-5];
    stack[-1] = v81;
    if (v81 == nil) goto v94;
    v82 = stack[-1];
    v81 = stack[-2];
    v81 = (Lisp_Object)greaterp2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v81 = v81 ? lisp_true : nil;
    env = stack[-5];
    v81 = (v81 == nil ? lisp_true : nil);
    stack[-2] = v81;
    v81 = stack[-2];
    if (v81 == nil) goto v95;
    v81 = qvalue(elt(env, 10)); /* orig!* */
    stack[0] = v81;
    v81 = elt(env, 5); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v82 = qvalue(elt(env, 11)); /* posn!* */
    v81 = (Lisp_Object)289; /* 18 */
    v81 = (Lisp_Object)lessp2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v81 = v81 ? lisp_true : nil;
    env = stack[-5];
    if (v81 == nil) goto v96;
    v81 = qvalue(elt(env, 11)); /* posn!* */
    goto v97;

v97:
    qvalue(elt(env, 10)) = v81; /* orig!* */
    goto v95;

v95:
    v81 = stack[-3];
    v83 = qcar(v81);
    v82 = stack[-1];
    v81 = stack[-3];
    v81 = qcdr(v81);
    fn = elt(env, 16); /* inprint */
    v81 = (*qfnn(fn))(qenv(fn), 3, v83, v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v81 = stack[-2];
    if (v81 == nil) goto v98;
    v81 = elt(env, 6); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v81 = stack[0];
    qvalue(elt(env, 10)) = v81; /* orig!* */
    goto v98;

v98:
    v81 = stack[-3];
    goto v25;

v96:
    v82 = qvalue(elt(env, 10)); /* orig!* */
    v81 = (Lisp_Object)49; /* 3 */
    v81 = plus2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    goto v97;

v94:
    v81 = stack[-3];
    v81 = qcar(v81);
    fn = elt(env, 15); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    goto v87;

v92:
    v81 = stack[-3];
    goto v25;

v85:
    v81 = stack[-3];
    v81 = Lsimple_vectorp(nil, v81);
    env = stack[-5];
    if (v81 == nil) goto v99;
    v82 = stack[-3];
    v81 = qvalue(elt(env, 1)); /* p!*!* */
    fn = elt(env, 17); /* vec!-maprin */
    v81 = (*qfn2(fn))(qenv(fn), v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    goto v18;

v18:
    v81 = stack[-3];
    goto v25;

v99:
    v81 = stack[-3];
    if (!(is_number(v81))) goto v100;
    v82 = stack[-3];
    v81 = (Lisp_Object)1; /* 0 */
    v81 = (Lisp_Object)lessp2(v82, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v81 = v81 ? lisp_true : nil;
    env = stack[-5];
    if (v81 == nil) goto v100;
    v83 = stack[-2];
    v82 = elt(env, 3); /* minus */
    v81 = elt(env, 4); /* infix */
    v81 = get(v82, v81);
    env = stack[-5];
    v81 = (Lisp_Object)lesseq2(v83, v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    v81 = v81 ? lisp_true : nil;
    env = stack[-5];
    if (!(v81 == nil)) goto v100;
    v81 = elt(env, 5); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v81 = stack[-3];
    fn = elt(env, 15); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    v81 = elt(env, 6); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    goto v18;

v100:
    v81 = stack[-3];
    fn = elt(env, 15); /* prin2!* */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-5];
    goto v18;

v84:
    v81 = qvalue(elt(env, 2)); /* nil */
    goto v25;
/* error exit handlers */
v86:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    popv(6);
    return nil;
}



/* Code for gperm2 */

static Lisp_Object MS_CDECL CC_gperm2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105, v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "gperm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm2");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v1;
    v104 = v0;
/* end of prologue */

v106:
    v105 = v104;
    if (v105 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v105 = v104;
    v105 = qcdr(v105);
    stack[-2] = v105;
    v105 = qcar(v104);
    v104 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* rev */
    v13 = (*qfn2(fn))(qenv(fn), v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-3];
    v12 = stack[-1];
    v105 = qvalue(elt(env, 1)); /* nil */
    v104 = stack[0];
    fn = elt(env, 3); /* gperm1 */
    v104 = (*qfnn(fn))(qenv(fn), 4, v13, v12, v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-3];
    stack[0] = v104;
    v104 = stack[-2];
    goto v106;
/* error exit handlers */
v77:
    popv(4);
    return nil;
}



/* Code for times!-in!-vector */

static Lisp_Object MS_CDECL CC_timesKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v37, Lisp_Object v5,
                         Lisp_Object v39, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v133, v134, v135, v136, v137, v138, v52, v97, v139, v140, v141, v142, v143;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "times-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push5(v39,v5,v37,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v37,v5,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v97 = v39;
    v139 = v5;
    v140 = v37;
    v141 = v1;
    v142 = v0;
/* end of prologue */
    v132 = v141;
    v131 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v132)) < ((int32_t)(v131))) goto v144;
    v132 = v139;
    v131 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v132)) < ((int32_t)(v131))) goto v144;
    v132 = v141;
    v131 = v139;
    v131 = (Lisp_Object)(int32_t)((int32_t)v132 + (int32_t)v131 - TAG_FIXNUM);
    v143 = v131;
    v131 = (Lisp_Object)1; /* 0 */
    v134 = v131;
    goto v78;

v78:
    v132 = v143;
    v131 = v134;
    v131 = (Lisp_Object)(int32_t)((int32_t)v132 - (int32_t)v131 + TAG_FIXNUM);
    v131 = ((intptr_t)(v131) < 0 ? lisp_true : nil);
    if (v131 == nil) goto v145;
    v131 = (Lisp_Object)1; /* 0 */
    v138 = v131;
    goto v10;

v10:
    v132 = v141;
    v131 = v138;
    v131 = (Lisp_Object)(int32_t)((int32_t)v132 - (int32_t)v131 + TAG_FIXNUM);
    v131 = ((intptr_t)(v131) < 0 ? lisp_true : nil);
    if (!(v131 == nil)) { popv(1); return onevalue(v143); }
    v132 = v142;
    v131 = v138;
    v131 = *(Lisp_Object *)((char *)v132 + (CELL-TAG_VECTOR) + ((int32_t)v131/(16/CELL)));
    v52 = v131;
    v131 = (Lisp_Object)1; /* 0 */
    v137 = v131;
    goto v146;

v146:
    v132 = v139;
    v131 = v137;
    v131 = (Lisp_Object)(int32_t)((int32_t)v132 - (int32_t)v131 + TAG_FIXNUM);
    v131 = ((intptr_t)(v131) < 0 ? lisp_true : nil);
    if (v131 == nil) goto v32;
    v131 = v138;
    v131 = (Lisp_Object)((int32_t)(v131) + 0x10);
    v138 = v131;
    goto v10;

v32:
    v132 = v138;
    v131 = v137;
    v131 = (Lisp_Object)(int32_t)((int32_t)v132 + (int32_t)v131 - TAG_FIXNUM);
    v136 = v97;
    v135 = v131;
    v132 = v97;
    v134 = *(Lisp_Object *)((char *)v132 + (CELL-TAG_VECTOR) + ((int32_t)v131/(16/CELL)));
    v133 = v52;
    v132 = v140;
    v131 = v137;
    v131 = *(Lisp_Object *)((char *)v132 + (CELL-TAG_VECTOR) + ((int32_t)v131/(16/CELL)));
    v131 = Lmodular_times(nil, v133, v131);
    env = stack[0];
    {   int32_t w = int_of_fixnum(v134) + int_of_fixnum(v131);
        if (w >= current_modulus) w -= current_modulus;
        v131 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v136 + (CELL-TAG_VECTOR) + ((int32_t)v135/(16/CELL))) = v131;
    v131 = v137;
    v131 = (Lisp_Object)((int32_t)(v131) + 0x10);
    v137 = v131;
    goto v146;

v145:
    v133 = v97;
    v132 = v134;
    v131 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v133 + (CELL-TAG_VECTOR) + ((int32_t)v132/(16/CELL))) = v131;
    v131 = v134;
    v131 = (Lisp_Object)((int32_t)(v131) + 0x10);
    v134 = v131;
    goto v78;

v144:
    v131 = (Lisp_Object)-15; /* -1 */
    { popv(1); return onevalue(v131); }
}



/* Code for kernord!-sort */

static Lisp_Object CC_kernordKsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord-sort");
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
    stack[0] = nil;
    goto v51;

v51:
    v13 = stack[-1];
    if (v13 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v13 = stack[-1];
    v147 = qcdr(v13);
    v13 = stack[-1];
    v13 = qcar(v13);
    fn = elt(env, 2); /* maxdeg */
    v13 = (*qfn2(fn))(qenv(fn), v147, v13);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    stack[-2] = v13;
    v13 = stack[-2];
    v147 = qcar(v13);
    v13 = stack[-1];
    fn = elt(env, 3); /* delallasc */
    v13 = (*qfn2(fn))(qenv(fn), v147, v13);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    stack[-1] = v13;
    v13 = stack[-2];
    v147 = qcar(v13);
    v13 = stack[0];
    v13 = cons(v147, v13);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-3];
    stack[0] = v13;
    goto v51;
/* error exit handlers */
v78:
    popv(4);
    return nil;
}



/* Code for treesizep1 */

static Lisp_Object CC_treesizep1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v80, v100;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for treesizep1");
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

v38:
    v80 = stack[-1];
    if (!consp(v80)) goto v51;
    v80 = stack[-1];
    v100 = qcar(v80);
    v80 = stack[0];
    v100 = CC_treesizep1(env, v100, v80);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-2];
    stack[0] = v100;
    v80 = (Lisp_Object)1; /* 0 */
    v80 = (Lisp_Object)greaterp2(v100, v80);
    nil = C_nil;
    if (exception_pending()) goto v126;
    v80 = v80 ? lisp_true : nil;
    env = stack[-2];
    if (v80 == nil) goto v19;
    v80 = stack[-1];
    v80 = qcdr(v80);
    stack[-1] = v80;
    goto v38;

v19:
    v80 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v80); }

v51:
    v80 = stack[0];
    popv(3);
    return sub1(v80);
/* error exit handlers */
v126:
    popv(3);
    return nil;
}



/* Code for simpexpon */

static Lisp_Object CC_simpexpon(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpon");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v34 = v0;
/* end of prologue */
    v35 = v34;
    v34 = elt(env, 1); /* simp!* */
    {
        fn = elt(env, 2); /* simpexpon1 */
        return (*qfn2(fn))(qenv(fn), v35, v34);
    }
}



/* Code for bfprin!:lst */

static Lisp_Object MS_CDECL CC_bfprinTlst(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v211, v212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bfprin:lst");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfprin:lst");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v37;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    stack[-7] = nil;
    v210 = (Lisp_Object)1; /* 0 */
    stack[-1] = v210;
    v210 = elt(env, 1); /* e */
    stack[-3] = v210;
    v210 = qvalue(elt(env, 2)); /* !*fort */
    if (v210 == nil) goto v17;
    v210 = qvalue(elt(env, 3)); /* fort_exponent */
    fn = elt(env, 11); /* reval */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-2] = v210;
    v210 = Lalpha_char_p(nil, v210);
    env = stack[-8];
    if (v210 == nil) goto v17;
    v210 = stack[-2];
    stack[-3] = v210;
    goto v214;

v214:
    v210 = stack[-6];
    v211 = qcar(v210);
    v210 = elt(env, 5); /* !- */
    if (!(v211 == v210)) goto v15;
    v211 = stack[-4];
    v210 = (Lisp_Object)17; /* 1 */
    if (!(v211 == v210)) goto v15;
    v210 = (Lisp_Object)33; /* 2 */
    stack[-4] = v210;
    v210 = stack[-5];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-5] = v210;
    goto v15;

v15:
    v211 = stack[-5];
    v210 = (Lisp_Object)1; /* 0 */
    if (v211 == v210) goto v6;
    v210 = stack[-6];
    v211 = qcar(v210);
    v210 = elt(env, 5); /* !- */
    if (v211 == v210) goto v9;
    stack[0] = stack[-5];
    v210 = stack[-4];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    v210 = plus2(stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-5] = v210;
    v210 = (Lisp_Object)17; /* 1 */
    stack[-4] = v210;
    goto v215;

v215:
    v210 = stack[-6];
    stack[0] = v210;
    goto v29;

v29:
    v210 = stack[0];
    if (v210 == nil) goto v216;
    v210 = stack[0];
    v210 = qcar(v210);
    v211 = v210;
    v210 = stack[-7];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    v210 = stack[-1];
    v210 = add1(v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-1] = v210;
    v210 = stack[-4];
    v210 = sub1(v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-4] = v210;
    v211 = stack[-1];
    v210 = (Lisp_Object)81; /* 5 */
    if (!(v211 == v210)) goto v133;
    v210 = qvalue(elt(env, 6)); /* !*nat */
    if (v210 == nil) goto v217;
    v210 = qvalue(elt(env, 7)); /* !*bfspace */
    if (v210 == nil) goto v217;
    v211 = elt(env, 8); /* !  */
    v210 = stack[-7];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    goto v217;

v217:
    v210 = (Lisp_Object)1; /* 0 */
    stack[-1] = v210;
    goto v133;

v133:
    v211 = stack[-4];
    v210 = (Lisp_Object)1; /* 0 */
    if (!(v211 == v210)) goto v218;
    v211 = elt(env, 9); /* !. */
    v210 = stack[-7];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    v210 = stack[-1];
    v210 = add1(v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-1] = v210;
    goto v218;

v218:
    v211 = stack[-1];
    v210 = (Lisp_Object)81; /* 5 */
    if (!(v211 == v210)) goto v219;
    v210 = qvalue(elt(env, 6)); /* !*nat */
    if (v210 == nil) goto v220;
    v210 = qvalue(elt(env, 7)); /* !*bfspace */
    if (v210 == nil) goto v220;
    v211 = elt(env, 8); /* !  */
    v210 = stack[-7];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    goto v220;

v220:
    v210 = (Lisp_Object)1; /* 0 */
    stack[-1] = v210;
    goto v219;

v219:
    v210 = stack[0];
    v210 = qcdr(v210);
    stack[0] = v210;
    goto v29;

v216:
    v211 = stack[-5];
    v210 = (Lisp_Object)1; /* 0 */
    if (!(v211 == v210)) goto v221;
    v210 = stack[-2];
    if (!(v210 == nil)) goto v221;

v222:
    v210 = stack[-7];
    v210 = Lnreverse(nil, v210);
    env = stack[-8];
    fn = elt(env, 12); /* smallcompress */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    fn = elt(env, 13); /* prin2!* */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    v210 = nil;
    { popv(9); return onevalue(v210); }

v221:
    v210 = qvalue(elt(env, 6)); /* !*nat */
    if (v210 == nil) goto v46;
    v210 = qvalue(elt(env, 7)); /* !*bfspace */
    if (v210 == nil) goto v46;
    v211 = stack[-1];
    v210 = (Lisp_Object)1; /* 0 */
    if (v211 == v210) goto v223;
    v211 = stack[-1];
    v210 = (Lisp_Object)17; /* 1 */
    if (v211 == v210) goto v83;
    v211 = stack[-1];
    v210 = (Lisp_Object)33; /* 2 */
    if (v211 == v210) goto v224;
    v211 = stack[-1];
    v210 = (Lisp_Object)49; /* 3 */
    if (v211 == v210) goto v225;
    v211 = stack[-1];
    v210 = (Lisp_Object)65; /* 4 */
    if (!(v211 == v210)) goto v226;
    stack[0] = elt(env, 8); /* !  */
    stack[-1] = stack[-3];
    v211 = elt(env, 8); /* !  */
    v210 = stack[-7];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    v210 = list2star(stack[0], stack[-1], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    v210 = (Lisp_Object)33; /* 2 */
    stack[-1] = v210;
    goto v226;

v226:
    v211 = stack[-5];
    v210 = (Lisp_Object)1; /* 0 */
    v210 = (Lisp_Object)greaterp2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    v210 = v210 ? lisp_true : nil;
    env = stack[-8];
    if (v210 == nil) goto v227;
    stack[0] = elt(env, 10); /* !+ */
    v210 = stack[-5];
    v210 = Lexplode(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    v210 = cons(stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    goto v228;

v228:
    stack[-6] = v210;
    v210 = stack[-6];
    stack[0] = v210;
    goto v229;

v229:
    v210 = stack[0];
    if (v210 == nil) goto v222;
    v210 = stack[0];
    v210 = qcar(v210);
    v211 = v210;
    v210 = stack[-7];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    v210 = stack[-1];
    v210 = add1(v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-1] = v210;
    v211 = stack[-1];
    v210 = (Lisp_Object)81; /* 5 */
    if (!(v211 == v210)) goto v230;
    v210 = qvalue(elt(env, 6)); /* !*nat */
    if (v210 == nil) goto v231;
    v210 = qvalue(elt(env, 7)); /* !*bfspace */
    if (v210 == nil) goto v231;
    v211 = elt(env, 8); /* !  */
    v210 = stack[-7];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    goto v231;

v231:
    v210 = (Lisp_Object)1; /* 0 */
    stack[-1] = v210;
    goto v230;

v230:
    v210 = stack[0];
    v210 = qcdr(v210);
    stack[0] = v210;
    goto v229;

v227:
    v210 = stack[-5];
    v210 = Lexplode(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    goto v228;

v225:
    stack[0] = elt(env, 8); /* !  */
    stack[-1] = stack[-3];
    v211 = elt(env, 8); /* !  */
    v210 = stack[-7];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    v210 = list2star(stack[0], stack[-1], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    v210 = (Lisp_Object)1; /* 0 */
    stack[-1] = v210;
    goto v226;

v224:
    stack[-1] = elt(env, 8); /* !  */
    stack[0] = elt(env, 8); /* !  */
    v212 = stack[-3];
    v211 = elt(env, 8); /* !  */
    v210 = stack[-7];
    v210 = list2star(v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    v210 = list2star(stack[-1], stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    v210 = (Lisp_Object)1; /* 0 */
    stack[-1] = v210;
    goto v226;

v83:
    stack[0] = elt(env, 8); /* !  */
    stack[-1] = stack[-3];
    v211 = elt(env, 8); /* !  */
    v210 = stack[-7];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    v210 = list2star(stack[0], stack[-1], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    v210 = (Lisp_Object)65; /* 4 */
    stack[-1] = v210;
    goto v226;

v223:
    v212 = elt(env, 8); /* !  */
    v211 = stack[-3];
    v210 = stack[-7];
    v210 = list2star(v212, v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    v210 = (Lisp_Object)33; /* 2 */
    stack[-1] = v210;
    goto v226;

v46:
    v211 = stack[-3];
    v210 = stack[-7];
    v210 = cons(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-7] = v210;
    goto v226;

v9:
    stack[0] = stack[-5];
    v211 = stack[-4];
    v210 = (Lisp_Object)33; /* 2 */
    v210 = difference2(v211, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    v210 = plus2(stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    stack[-5] = v210;
    v210 = (Lisp_Object)33; /* 2 */
    stack[-4] = v210;
    goto v215;

v6:
    stack[0] = stack[-4];
    v210 = stack[-6];
    v210 = Llength(nil, v210);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-8];
    if (!(equal(stack[0], v210))) goto v215;
    v210 = (Lisp_Object)-15; /* -1 */
    stack[-4] = v210;
    goto v215;

v17:
    v210 = qvalue(elt(env, 4)); /* nil */
    stack[-2] = v210;
    goto v214;
/* error exit handlers */
v213:
    popv(9);
    return nil;
}



/* Code for difff */

static Lisp_Object CC_difff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v243, v244, v245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difff");
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
    v243 = stack[-2];
    if (!consp(v243)) goto v26;
    v243 = stack[-2];
    v243 = qcar(v243);
    if (!consp(v243)) goto v130;
    v243 = stack[-2];
    v243 = qcar(v243);
    v244 = qcar(v243);
    v243 = (Lisp_Object)17; /* 1 */
    v243 = cons(v244, v243);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v244 = ncons(v243);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v243 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v244, v243);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v243 = stack[-2];
    v243 = qcar(v243);
    v244 = qcdr(v243);
    v243 = stack[-1];
    v243 = CC_difff(env, v244, v243);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v243);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v243 = stack[-2];
    v243 = qcar(v243);
    v244 = qcar(v243);
    v243 = stack[-1];
    fn = elt(env, 4); /* diffp */
    stack[0] = (*qfn2(fn))(qenv(fn), v244, v243);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v243 = stack[-2];
    v243 = qcar(v243);
    v244 = qcdr(v243);
    v243 = (Lisp_Object)17; /* 1 */
    v243 = cons(v244, v243);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v243 = (*qfn2(fn))(qenv(fn), stack[0], v243);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    fn = elt(env, 5); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v243);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v243 = stack[-2];
    v244 = qcdr(v243);
    v243 = stack[-1];
    v243 = CC_difff(env, v244, v243);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    {
        Lisp_Object v110 = stack[0];
        popv(5);
        fn = elt(env, 5); /* addsq */
        return (*qfn2(fn))(qenv(fn), v110, v243);
    }

v130:
    v243 = stack[-2];
    v244 = qcar(v243);
    v243 = elt(env, 2); /* domain!-diff!-fn */
    v243 = get(v244, v243);
    env = stack[-4];
    v244 = v243;
    v243 = v244;
    if (v243 == nil) goto v78;
    v245 = v244;
    v244 = stack[-2];
    v243 = stack[-1];
        popv(5);
        return Lapply2(nil, 3, v245, v244, v243);

v78:
    v244 = qvalue(elt(env, 1)); /* nil */
    v243 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v244, v243);

v26:
    v244 = qvalue(elt(env, 1)); /* nil */
    v243 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v244, v243);
/* error exit handlers */
v62:
    popv(5);
    return nil;
}



/* Code for simp!* */

static Lisp_Object CC_simpH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*");
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
    stack[-3] = qvalue(elt(env, 1)); /* !*asymp!* */
    qvalue(elt(env, 1)) = nil; /* !*asymp!* */
    v249 = stack[-2];
    v248 = elt(env, 2); /* !*sq */
    if (!consp(v249)) goto v127;
    v249 = qcar(v249);
    if (!(v249 == v248)) goto v127;
    v248 = stack[-2];
    v248 = qcdr(v248);
    v248 = qcdr(v248);
    v248 = qcar(v248);
    if (v248 == nil) goto v127;
    v248 = qvalue(elt(env, 3)); /* !*resimp */
    if (!(v248 == nil)) goto v127;
    v248 = stack[-2];
    v248 = qcdr(v248);
    v248 = qcar(v248);
    goto v38;

v38:
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    { popv(5); return onevalue(v248); }

v127:
    v249 = qvalue(elt(env, 4)); /* mul!* */
    v248 = qvalue(elt(env, 5)); /* !*sub2 */
    v248 = cons(v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-1] = v248;
    v248 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 4)) = v248; /* mul!* */
    v248 = stack[-2];
    fn = elt(env, 14); /* simp */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-2] = v248;
    v248 = qvalue(elt(env, 7)); /* !*nospurp */
    if (v248 == nil) goto v104;
    v249 = qvalue(elt(env, 4)); /* mul!* */
    v248 = elt(env, 8); /* (isimpq) */
    fn = elt(env, 15); /* union */
    v248 = (*qfn2(fn))(qenv(fn), v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    qvalue(elt(env, 4)) = v248; /* mul!* */
    goto v104;

v104:
    v248 = qvalue(elt(env, 4)); /* mul!* */
    stack[0] = v248;
    goto v250;

v250:
    v248 = stack[0];
    if (v248 == nil) goto v27;
    v248 = stack[0];
    v248 = qcar(v248);
    v249 = v248;
    v248 = stack[-2];
    v248 = Lapply1(nil, v249, v248);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-2] = v248;
    v248 = stack[0];
    v248 = qcdr(v248);
    stack[0] = v248;
    goto v250;

v27:
    v248 = stack[-1];
    v248 = qcar(v248);
    qvalue(elt(env, 4)) = v248; /* mul!* */
    v248 = stack[-2];
    fn = elt(env, 16); /* subs2 */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-2] = v248;
    v248 = qvalue(elt(env, 9)); /* !*combinelogs */
    if (v248 == nil) goto v238;
    v248 = stack[-2];
    fn = elt(env, 17); /* clogsq!* */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-2] = v248;
    goto v238;

v238:
    v249 = qvalue(elt(env, 10)); /* dmode!* */
    v248 = elt(env, 11); /* !:gi!: */
    if (!(v249 == v248)) goto v239;
    v248 = qvalue(elt(env, 12)); /* !*norationalgi */
    if (!(v248 == nil)) goto v239;
    v248 = stack[-2];
    fn = elt(env, 18); /* girationalize!: */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-2] = v248;
    goto v72;

v72:
    v248 = stack[-1];
    v248 = qcdr(v248);
    qvalue(elt(env, 5)) = v248; /* !*sub2 */
    v248 = qvalue(elt(env, 1)); /* !*asymp!* */
    if (v248 == nil) goto v30;
    v248 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v248 == nil) goto v30;
    v248 = stack[-2];
    fn = elt(env, 19); /* gcdchk */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-2] = v248;
    goto v30;

v30:
    v248 = stack[-2];
    goto v38;

v239:
    v248 = qvalue(elt(env, 13)); /* !*rationalize */
    if (v248 == nil) goto v23;
    v248 = stack[-2];
    fn = elt(env, 20); /* rationalizesq */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-2] = v248;
    goto v72;

v23:
    v248 = stack[-2];
    fn = elt(env, 21); /* rationalizei */
    v248 = (*qfn1(fn))(qenv(fn), v248);
    nil = C_nil;
    if (exception_pending()) goto v108;
    env = stack[-4];
    stack[-2] = v248;
    goto v72;
/* error exit handlers */
v108:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* !*asymp!* */
    popv(5);
    return nil;
}



/* Code for vdpgetprop */

static Lisp_Object CC_vdpgetprop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v125, v28, v252;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpgetprop");
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
    v28 = v1;
    v252 = v0;
/* end of prologue */
    v124 = v252;
    if (v124 == nil) goto v38;
    v125 = v252;
    v124 = elt(env, 2); /* vdp */
    if (!consp(v125)) goto v85;
    v125 = qcar(v125);
    if (!(v125 == v124)) goto v85;
    v124 = v28;
    v125 = v252;
    v125 = qcdr(v125);
    v125 = qcdr(v125);
    v125 = qcdr(v125);
    v125 = qcdr(v125);
    v125 = qcar(v125);
    v124 = Lassoc(nil, v124, v125);
    v125 = v124;
    v124 = v125;
    if (v124 == nil) goto v253;
    v124 = v125;
    v124 = qcdr(v124);
    { popv(3); return onevalue(v124); }

v253:
    v124 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v124); }

v85:
    stack[-1] = elt(env, 3); /* dipoly */
    stack[0] = (Lisp_Object)113; /* 7 */
    v124 = elt(env, 4); /* "vdpgetprop given a non-vdp as 1st parameter" 
*/
    v125 = v252;
    v124 = list3(v124, v125, v28);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-2];
    {
        Lisp_Object v8 = stack[-1];
        Lisp_Object v9 = stack[0];
        popv(3);
        fn = elt(env, 5); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v8, v9, v124);
    }

v38:
    v124 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v124); }
/* error exit handlers */
v207:
    popv(3);
    return nil;
}



/* Code for areallindices */

static Lisp_Object CC_areallindices(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for areallindices");
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

v254:
    v130 = stack[0];
    v130 = qcar(v130);
    fn = elt(env, 2); /* isanindex */
    v130 = (*qfn1(fn))(qenv(fn), v130);
    nil = C_nil;
    if (exception_pending()) goto v17;
    env = stack[-1];
    if (v130 == nil) goto v39;
    v130 = stack[0];
    v130 = qcdr(v130);
    v130 = (v130 == nil ? lisp_true : nil);
    if (!(v130 == nil)) { popv(2); return onevalue(v130); }
    v130 = stack[0];
    v130 = qcdr(v130);
    stack[0] = v130;
    goto v254;

v39:
    v130 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v130); }
/* error exit handlers */
v17:
    popv(2);
    return nil;
}



/* Code for contrsp2 */

static Lisp_Object MS_CDECL CC_contrsp2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v257;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "contrsp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contrsp2");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = (Lisp_Object)33; /* 2 */
    v256 = stack[-2];
    v256 = Llength(nil, v256);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    if (stack[-3] == v256) goto v85;
    v256 = nil;
    { popv(5); return onevalue(v256); }

v85:
    v257 = stack[0];
    v256 = stack[-2];
    v256 = qcar(v256);
    if (equal(v257, v256)) goto v128;
    v257 = stack[0];
    v256 = stack[-2];
    v256 = qcdr(v256);
    v256 = qcar(v256);
    if (equal(v257, v256)) goto v258;
    v256 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v256); }

v258:
    v256 = stack[-2];
    v257 = qcar(v256);
    v256 = stack[-1];
    popv(5);
    return cons(v257, v256);

v128:
    v256 = stack[-2];
    v256 = qcdr(v256);
    v257 = qcar(v256);
    v256 = stack[-1];
    popv(5);
    return cons(v257, v256);
/* error exit handlers */
v125:
    popv(5);
    return nil;
}



/* Code for mo!=deglist */

static Lisp_Object CC_moMdeglist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v261, v262;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=deglist");
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
    v261 = stack[-4];
    if (v261 == nil) goto v39;
    v261 = stack[-4];
    v262 = qcar(v261);
    v261 = qvalue(elt(env, 3)); /* cali!=degrees */
    v261 = Lassoc(nil, v262, v261);
    stack[-5] = v261;
    v261 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_degrees */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-6];
    stack[-3] = v261;
    v261 = stack[-3];
    if (v261 == nil) goto v236;
    v261 = stack[-3];
    v261 = qcar(v261);
    v262 = stack[-4];
    v262 = qcdr(v262);
    fn = elt(env, 5); /* mo!=sprod */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-6];
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-6];
    stack[-1] = v261;
    stack[-2] = v261;
    goto v118;

v118:
    v261 = stack[-3];
    v261 = qcdr(v261);
    stack[-3] = v261;
    v261 = stack[-3];
    if (v261 == nil) goto v204;
    stack[0] = stack[-1];
    v261 = stack[-3];
    v261 = qcar(v261);
    v262 = stack[-4];
    v262 = qcdr(v262);
    fn = elt(env, 5); /* mo!=sprod */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-6];
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-6];
    v261 = Lrplacd(nil, stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-6];
    v261 = stack[-1];
    v261 = qcdr(v261);
    stack[-1] = v261;
    goto v118;

v204:
    v261 = stack[-2];
    v262 = v261;
    goto v253;

v253:
    v261 = stack[-5];
    if (v261 == nil) goto v66;
    v261 = stack[-5];
    v261 = qcdr(v261);
    v261 = qcdr(v261);
    goto v75;

v75:
    {
        popv(7);
        fn = elt(env, 6); /* mo!=sum */
        return (*qfn2(fn))(qenv(fn), v262, v261);
    }

v66:
    v261 = qvalue(elt(env, 2)); /* nil */
    goto v75;

v236:
    v261 = qvalue(elt(env, 2)); /* nil */
    v262 = v261;
    goto v253;

v39:
    v261 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_degrees */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-6];
    stack[-3] = v261;
    v261 = stack[-3];
    if (v261 == nil) goto v247;
    v261 = (Lisp_Object)1; /* 0 */
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-6];
    stack[-1] = v261;
    stack[-2] = v261;
    goto v36;

v36:
    v261 = stack[-3];
    v261 = qcdr(v261);
    stack[-3] = v261;
    v261 = stack[-3];
    if (v261 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v261 = (Lisp_Object)1; /* 0 */
    v261 = ncons(v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-6];
    v261 = Lrplacd(nil, stack[0], v261);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-6];
    v261 = stack[-1];
    v261 = qcdr(v261);
    stack[-1] = v261;
    goto v36;

v247:
    v261 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v261); }
/* error exit handlers */
v263:
    popv(7);
    return nil;
}



/* Code for pdmult */

static Lisp_Object CC_pdmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v269, v270;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pdmult");
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
/* copy arguments values to proper place */
    stack[-8] = v1;
    v269 = v0;
/* end of prologue */
    stack[-9] = v269;
    v269 = stack[-9];
    if (v269 == nil) goto v36;
    v269 = stack[-9];
    v269 = qcar(v269);
    stack[-4] = v269;
    v269 = stack[-4];
    v270 = qcar(v269);
    v269 = stack[-8];
    fn = elt(env, 2); /* pair */
    v269 = (*qfn2(fn))(qenv(fn), v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    stack[-3] = v269;
    v269 = stack[-3];
    if (v269 == nil) goto v12;
    v269 = stack[-3];
    v269 = qcar(v269);
    v270 = v269;
    v270 = qcar(v270);
    v269 = qcdr(v269);
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 + (int32_t)v269 - TAG_FIXNUM);
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    stack[-1] = v269;
    stack[-2] = v269;
    goto v214;

v214:
    v269 = stack[-3];
    v269 = qcdr(v269);
    stack[-3] = v269;
    v269 = stack[-3];
    if (v269 == nil) goto v76;
    stack[0] = stack[-1];
    v269 = stack[-3];
    v269 = qcar(v269);
    v270 = v269;
    v270 = qcar(v270);
    v269 = qcdr(v269);
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 + (int32_t)v269 - TAG_FIXNUM);
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    v269 = Lrplacd(nil, stack[0], v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    v269 = stack[-1];
    v269 = qcdr(v269);
    stack[-1] = v269;
    goto v214;

v76:
    v269 = stack[-2];
    v270 = v269;
    goto v17;

v17:
    v269 = stack[-4];
    v269 = qcdr(v269);
    v269 = cons(v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    stack[-6] = v269;
    stack[-7] = v269;
    goto v51;

v51:
    v269 = stack[-9];
    v269 = qcdr(v269);
    stack[-9] = v269;
    v269 = stack[-9];
    if (v269 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v269 = stack[-9];
    v269 = qcar(v269);
    stack[-4] = v269;
    v269 = stack[-4];
    v270 = qcar(v269);
    v269 = stack[-8];
    fn = elt(env, 2); /* pair */
    v269 = (*qfn2(fn))(qenv(fn), v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    stack[-3] = v269;
    v269 = stack[-3];
    if (v269 == nil) goto v272;
    v269 = stack[-3];
    v269 = qcar(v269);
    v270 = v269;
    v270 = qcar(v270);
    v269 = qcdr(v269);
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 + (int32_t)v269 - TAG_FIXNUM);
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    stack[-1] = v269;
    stack[-2] = v269;
    goto v91;

v91:
    v269 = stack[-3];
    v269 = qcdr(v269);
    stack[-3] = v269;
    v269 = stack[-3];
    if (v269 == nil) goto v60;
    stack[0] = stack[-1];
    v269 = stack[-3];
    v269 = qcar(v269);
    v270 = v269;
    v270 = qcar(v270);
    v269 = qcdr(v269);
    v269 = (Lisp_Object)(int32_t)((int32_t)v270 + (int32_t)v269 - TAG_FIXNUM);
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    v269 = Lrplacd(nil, stack[0], v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    v269 = stack[-1];
    v269 = qcdr(v269);
    stack[-1] = v269;
    goto v91;

v60:
    v269 = stack[-2];
    v270 = v269;
    goto v30;

v30:
    v269 = stack[-4];
    v269 = qcdr(v269);
    v269 = cons(v270, v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    v269 = ncons(v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    v269 = Lrplacd(nil, stack[-5], v269);
    nil = C_nil;
    if (exception_pending()) goto v271;
    env = stack[-10];
    v269 = stack[-6];
    v269 = qcdr(v269);
    stack[-6] = v269;
    goto v51;

v272:
    v269 = qvalue(elt(env, 1)); /* nil */
    v270 = v269;
    goto v30;

v12:
    v269 = qvalue(elt(env, 1)); /* nil */
    v270 = v269;
    goto v17;

v36:
    v269 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v269); }
/* error exit handlers */
v271:
    popv(11);
    return nil;
}



/* Code for aronep!: */

static Lisp_Object CC_aronepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aronep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v0;
/* end of prologue */
    v36 = qcdr(v35);
    v35 = (Lisp_Object)17; /* 1 */
    v35 = (v36 == v35 ? lisp_true : nil);
    return onevalue(v35);
}



/* Code for clear!-column */

static Lisp_Object MS_CDECL CC_clearKcolumn(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v37,
                         Lisp_Object v5, Lisp_Object v39, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v300, v301, v302, v303, v304, v305, v166, v167, v306, v307;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "clear-column");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clear-column");
#endif
    if (stack >= stacklimit)
    {
        push4(v39,v5,v37,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v1,v37,v5,v39);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v39;
    stack[-1] = v5;
    v300 = v37;
    stack[-2] = v1;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* null!-space!-basis */
    qvalue(elt(env, 1)) = nil; /* null!-space!-basis */
    qvalue(elt(env, 1)) = v300; /* null!-space!-basis */
    v300 = (Lisp_Object)1; /* 0 */
    goto v214;

v214:
    v302 = stack[-1];
    v301 = v300;
    v302 = *(Lisp_Object *)((char *)v302 + (CELL-TAG_VECTOR) + ((int32_t)v301/(16/CELL)));
    v301 = stack[-2];
    v302 = *(Lisp_Object *)((char *)v302 + (CELL-TAG_VECTOR) + ((int32_t)v301/(16/CELL)));
    v301 = (Lisp_Object)1; /* 0 */
    if (v302 == v301) goto v308;
    v302 = v300;
    v301 = stack[-2];
    if (!(((int32_t)(v302)) < ((int32_t)(v301)))) goto v2;
    v302 = stack[-1];
    v301 = v300;
    v302 = *(Lisp_Object *)((char *)v302 + (CELL-TAG_VECTOR) + ((int32_t)v301/(16/CELL)));
    v301 = v300;
    v302 = *(Lisp_Object *)((char *)v302 + (CELL-TAG_VECTOR) + ((int32_t)v301/(16/CELL)));
    v301 = (Lisp_Object)1; /* 0 */
    if (!(v302 == v301)) goto v308;

v2:
    v302 = stack[-1];
    v301 = v300;
    v301 = *(Lisp_Object *)((char *)v302 + (CELL-TAG_VECTOR) + ((int32_t)v301/(16/CELL)));
    v307 = v301;
    v303 = stack[-1];
    v302 = v300;
    v301 = stack[-1];
    v300 = stack[-2];
    v300 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    *(Lisp_Object *)((char *)v303 + (CELL-TAG_VECTOR) + ((int32_t)v302/(16/CELL))) = v300;
    v301 = stack[-1];
    v300 = stack[-2];
    v302 = v307;
    *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL))) = v302;
    v301 = stack[-1];
    v300 = stack[-2];
    v301 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v300 = stack[-2];
    v300 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v300 = Lmodular_reciprocal(nil, v300);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v300);
        if (w != 0) w = current_modulus - w;
        v300 = fixnum_of_int(w);
    }
    v307 = v300;
    v300 = (Lisp_Object)1; /* 0 */
    v306 = v300;
    goto v310;

v310:
    v301 = stack[0];
    v300 = v306;
    v300 = (Lisp_Object)(int32_t)((int32_t)v301 - (int32_t)v300 + TAG_FIXNUM);
    v300 = ((intptr_t)(v300) < 0 ? lisp_true : nil);
    if (v300 == nil) goto v133;
    v300 = stack[-2];
    v304 = v300;
    goto v311;

v311:
    v301 = stack[0];
    v300 = v304;
    v300 = (Lisp_Object)(int32_t)((int32_t)v301 - (int32_t)v300 + TAG_FIXNUM);
    v300 = ((intptr_t)(v300) < 0 ? lisp_true : nil);
    if (v300 == nil) goto v312;
    v300 = qvalue(elt(env, 1)); /* null!-space!-basis */
    goto v51;

v51:
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    { popv(5); return onevalue(v300); }

v312:
    v301 = stack[-1];
    v300 = stack[-2];
    v303 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v302 = v304;
    v301 = stack[-1];
    v300 = stack[-2];
    v301 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v300 = v304;
    v301 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v300 = v307;
    v300 = Lmodular_times(nil, v301, v300);
    env = stack[-4];
    *(Lisp_Object *)((char *)v303 + (CELL-TAG_VECTOR) + ((int32_t)v302/(16/CELL))) = v300;
    v300 = v304;
    v300 = (Lisp_Object)((int32_t)(v300) + 0x10);
    v304 = v300;
    goto v311;

v133:
    v301 = v306;
    v300 = stack[-2];
    if (equal(v301, v300)) goto v313;
    v301 = stack[-1];
    v300 = v306;
    v301 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v300 = stack[-2];
    v300 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v167 = v300;
    v301 = v167;
    v300 = (Lisp_Object)1; /* 0 */
    if (v301 == v300) goto v313;
    v301 = v167;
    v300 = v307;
    v300 = Lmodular_times(nil, v301, v300);
    env = stack[-4];
    v167 = v300;
    v300 = stack[-2];
    v166 = v300;
    goto v314;

v314:
    v301 = stack[0];
    v300 = v166;
    v300 = (Lisp_Object)(int32_t)((int32_t)v301 - (int32_t)v300 + TAG_FIXNUM);
    v300 = ((intptr_t)(v300) < 0 ? lisp_true : nil);
    if (!(v300 == nil)) goto v313;
    v301 = stack[-1];
    v300 = v306;
    v305 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v304 = v166;
    v301 = stack[-1];
    v300 = v306;
    v301 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v300 = v166;
    v303 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v302 = v167;
    v301 = stack[-1];
    v300 = stack[-2];
    v301 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v300 = v166;
    v300 = *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL)));
    v300 = Lmodular_times(nil, v302, v300);
    env = stack[-4];
    {   int32_t w = int_of_fixnum(v303) + int_of_fixnum(v300);
        if (w >= current_modulus) w -= current_modulus;
        v300 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v305 + (CELL-TAG_VECTOR) + ((int32_t)v304/(16/CELL))) = v300;
    v300 = v166;
    v300 = (Lisp_Object)((int32_t)(v300) + 0x10);
    v166 = v300;
    goto v314;

v313:
    v300 = v306;
    v300 = (Lisp_Object)((int32_t)(v300) + 0x10);
    v306 = v300;
    goto v310;

v308:
    v302 = (Lisp_Object)((int32_t)(v300) + 0x10);
    v300 = v302;
    v301 = stack[0];
    if (!(((int32_t)(v302)) > ((int32_t)(v301)))) goto v214;
    v301 = stack[-2];
    v300 = qvalue(elt(env, 1)); /* null!-space!-basis */
    v300 = cons(v301, v300);
    nil = C_nil;
    if (exception_pending()) goto v309;
    env = stack[-4];
    goto v51;
/* error exit handlers */
v309:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* null!-space!-basis */
    popv(5);
    return nil;
}



/* Code for lto_insertq */

static Lisp_Object CC_lto_insertq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v241, v103, v128;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_insertq");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v241 = v1;
    v103 = v0;
/* end of prologue */
    v128 = v103;
    v99 = v241;
    v99 = Lmemq(nil, v128, v99);
    if (!(v99 == nil)) return onevalue(v241);
    v99 = v103;
    return cons(v99, v241);
}



/* Code for omobjs */

static Lisp_Object MS_CDECL CC_omobjs(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v13;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobjs");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omobjs");
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
    v13 = qvalue(elt(env, 1)); /* char */
    v12 = elt(env, 2); /* (!/ o m a) */
    if (equal(v13, v12)) goto v25;
    fn = elt(env, 4); /* omobj */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-1];
    stack[0] = v12;
    fn = elt(env, 5); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-1];
    v12 = CC_omobjs(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v209;
    v13 = stack[0];
    if (v13 == nil) goto v255;
    v13 = stack[0];
    popv(2);
    return cons(v13, v12);

v255:
    v13 = stack[0];
        popv(2);
        return Lappend(nil, v13, v12);

v25:
    v12 = nil;
    { popv(2); return onevalue(v12); }
/* error exit handlers */
v209:
    popv(2);
    return nil;
}



/* Code for ps!:get!-term */

static Lisp_Object CC_psTgetKterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v203, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:get-term");
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
    v91 = stack[-2];
    fn = elt(env, 4); /* ps!:order */
    stack[0] = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v91 = stack[-2];
    fn = elt(env, 5); /* ps!:last!-term */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v91;
    v203 = stack[-1];
    v91 = stack[-3];
    v91 = (Lisp_Object)lessp2(v203, v91);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v91 = v91 ? lisp_true : nil;
    env = stack[-4];
    if (v91 == nil) goto v21;
    v203 = qvalue(elt(env, 1)); /* nil */
    v91 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v203, v91);

v21:
    v203 = stack[-1];
    v91 = stack[0];
    v91 = (Lisp_Object)greaterp2(v203, v91);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v91 = v91 ? lisp_true : nil;
    env = stack[-4];
    if (v91 == nil) goto v215;
    v91 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v91); }

v215:
    v203 = stack[-1];
    v91 = stack[-3];
    stack[0] = difference2(v203, v91);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v91 = stack[-2];
    if (!consp(v91)) goto v123;
    v91 = stack[-2];
    v203 = qcar(v91);
    v91 = elt(env, 2); /* !:ps!: */
    if (v203 == v91) goto v246;
    v91 = stack[-2];
    v203 = qcar(v91);
    v91 = elt(env, 3); /* dname */
    v91 = get(v203, v91);
    env = stack[-4];
    if (!(v91 == nil)) goto v123;

v246:
    v203 = stack[-2];
    v91 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 6); /* ps!:getv */
    v91 = (*qfn2(fn))(qenv(fn), v203, v91);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    goto v77;

v77:
    v91 = Lassoc(nil, stack[0], v91);
    v203 = v91;
    v91 = v203;
    if (v91 == nil) goto v32;
    v91 = v203;
    v91 = qcdr(v91);
    { popv(5); return onevalue(v91); }

v32:
    v203 = qvalue(elt(env, 1)); /* nil */
    v91 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v203, v91);

v123:
    v248 = (Lisp_Object)1; /* 0 */
    v203 = stack[-2];
    v91 = (Lisp_Object)17; /* 1 */
    v91 = list2star(v248, v203, v91);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v91 = ncons(v91);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    goto v77;
/* error exit handlers */
v66:
    popv(5);
    return nil;
}



/* Code for letmtr3 */

static Lisp_Object MS_CDECL CC_letmtr3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v37, Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v335, v300, v301, v302;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "letmtr3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letmtr3");
#endif
    if (stack >= stacklimit)
    {
        push4(v5,v37,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v37,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v5;
    stack[-3] = v37;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = nil;
    v335 = stack[-5];
    v335 = qcdr(v335);
    v335 = qcdr(v335);
    if (v335 == nil) goto v103;
    v300 = stack[-3];
    v335 = elt(env, 1); /* sparsemat */
    if (!consp(v300)) goto v259;
    v300 = qcar(v300);
    if (!(v300 == v335)) goto v259;
    v335 = stack[-5];
    v335 = qcdr(v335);
    fn = elt(env, 8); /* revlis */
    v335 = (*qfn1(fn))(qenv(fn), v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    stack[-6] = v335;
    fn = elt(env, 9); /* numlis */
    v335 = (*qfn1(fn))(qenv(fn), v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    if (v335 == nil) goto v337;
    v335 = stack[-6];
    v300 = Llength(nil, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v335 = (Lisp_Object)33; /* 2 */
    if (!(v300 == v335)) goto v337;

v310:
    v335 = stack[-3];
    v335 = qcdr(v335);
    v300 = qcar(v335);
    v335 = stack[-6];
    v335 = qcar(v335);
    v335 = *(Lisp_Object *)((char *)v300 + (CELL-TAG_VECTOR) + ((int32_t)v335/(16/CELL)));
    v302 = v335;
    v335 = v302;
    if (v335 == nil) goto v97;
    v335 = stack[-6];
    v335 = qcdr(v335);
    v300 = qcar(v335);
    v335 = v302;
    v335 = Latsoc(nil, v300, v335);
    v301 = v335;
    v335 = v301;
    if (v335 == nil) goto v288;
    v300 = stack[-4];
    v335 = (Lisp_Object)1; /* 0 */
    if (!(v300 == v335)) goto v168;
    v300 = stack[-2];
    v335 = elt(env, 7); /* cx */
    if (v300 == v335) goto v168;
    v335 = v302;
    v335 = qcdr(v335);
    v335 = qcdr(v335);
    if (v335 == nil) goto v338;
    stack[0] = v302;
    v335 = v301;
    v300 = v302;
    v335 = Ldelete(nil, v335, v300);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v335 = qcdr(v335);
    v335 = Lrplacd(nil, stack[0], v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    goto v247;

v247:
    v335 = nil;
    { popv(8); return onevalue(v335); }

v338:
    v335 = stack[-3];
    v335 = qcdr(v335);
    v300 = qcar(v335);
    v335 = stack[-6];
    v335 = qcar(v335);
    v301 = qvalue(elt(env, 6)); /* nil */
    *(Lisp_Object *)((char *)v300 + (CELL-TAG_VECTOR) + ((int32_t)v335/(16/CELL))) = v301;
    goto v247;

v168:
    v300 = v301;
    v335 = stack[-4];
    v335 = Lrplacd(nil, v300, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    goto v247;

v288:
    v300 = stack[-4];
    v335 = (Lisp_Object)1; /* 0 */
    if (!(v300 == v335)) goto v42;
    v300 = stack[-2];
    v335 = elt(env, 7); /* cx */
    if (!(v300 == v335)) goto v247;

v42:
    v335 = stack[-6];
    v335 = qcdr(v335);
    v300 = qcar(v335);
    v301 = v302;
    v335 = stack[-4];
    fn = elt(env, 10); /* sortcolelem */
    v335 = (*qfnn(fn))(qenv(fn), 3, v300, v301, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    goto v247;

v97:
    v300 = stack[-4];
    v335 = (Lisp_Object)1; /* 0 */
    if (!(v300 == v335)) goto v339;
    v300 = stack[-2];
    v335 = elt(env, 7); /* cx */
    if (!(v300 == v335)) goto v247;

v339:
    v335 = stack[-3];
    v335 = qcdr(v335);
    stack[-2] = qcar(v335);
    v335 = stack[-6];
    stack[-1] = qcar(v335);
    v335 = qvalue(elt(env, 6)); /* nil */
    stack[0] = ncons(v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v335 = stack[-6];
    v335 = qcdr(v335);
    v300 = qcar(v335);
    v335 = stack[-4];
    v335 = cons(v300, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v335 = list2(stack[0], v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v335;
    goto v247;

v337:
    v300 = stack[-5];
    v335 = elt(env, 5); /* hold */
    {
        popv(8);
        fn = elt(env, 11); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v300, v335);
    }

v259:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v301 = elt(env, 3); /* "Matrix" */
    v335 = stack[-5];
    v300 = qcar(v335);
    v335 = elt(env, 4); /* "not set" */
    v335 = list3(v301, v300, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    fn = elt(env, 12); /* rerror */
    v335 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    goto v310;

v103:
    v300 = stack[-3];
    v335 = elt(env, 1); /* sparsemat */
    if (!consp(v300)) goto v80;
    v300 = qcar(v300);
    if (!(v300 == v335)) goto v80;
    v335 = stack[-5];
    v335 = qcdr(v335);
    fn = elt(env, 8); /* revlis */
    v335 = (*qfn1(fn))(qenv(fn), v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    stack[-6] = v335;
    fn = elt(env, 9); /* numlis */
    v335 = (*qfn1(fn))(qenv(fn), v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    if (v335 == nil) goto v9;
    v335 = stack[-6];
    v300 = Llength(nil, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    v335 = (Lisp_Object)17; /* 1 */
    if (!(v300 == v335)) goto v9;

v11:
    v335 = stack[-3];
    v335 = qcdr(v335);
    v301 = qcar(v335);
    v335 = stack[-5];
    v335 = qcdr(v335);
    v300 = qcar(v335);
    v335 = stack[-4];
    *(Lisp_Object *)((char *)v301 + (CELL-TAG_VECTOR) + ((int32_t)v300/(16/CELL))) = v335;
    goto v247;

v9:
    v300 = stack[-5];
    v335 = elt(env, 5); /* hold */
    {
        popv(8);
        fn = elt(env, 11); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v300, v335);
    }

v80:
    stack[-1] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v301 = elt(env, 3); /* "Matrix" */
    v335 = stack[-5];
    v300 = qcar(v335);
    v335 = elt(env, 4); /* "not set" */
    v335 = list3(v301, v300, v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-7];
    fn = elt(env, 12); /* rerror */
    v335 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v335);
    nil = C_nil;
    if (exception_pending()) goto v336;
    goto v11;
/* error exit handlers */
v336:
    popv(8);
    return nil;
}



/* Code for genp */

static Lisp_Object CC_genp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18, v255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for genp");
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
    v18 = v0;
/* end of prologue */
    v17 = v18;
    if (!consp(v17)) goto v242;
    v17 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v17); }

v242:
    v255 = v18;
    v17 = elt(env, 2); /* gen */
    v17 = get(v255, v17);
    env = stack[0];
    if (!(v17 == nil)) { popv(1); return onevalue(v17); }
    v17 = v18;
    {
        popv(1);
        fn = elt(env, 3); /* mgenp */
        return (*qfn1(fn))(qenv(fn), v17);
    }
}



/* Code for termordp */

static Lisp_Object CC_termordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for termordp");
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
    v144 = v0;
/* end of prologue */
    fn = elt(env, 1); /* wedgefax */
    stack[-1] = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    v144 = stack[0];
    fn = elt(env, 1); /* wedgefax */
    v144 = (*qfn1(fn))(qenv(fn), v144);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    {
        Lisp_Object v247 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* monordp */
        return (*qfn2(fn))(qenv(fn), v247, v144);
    }
/* error exit handlers */
v84:
    popv(3);
    return nil;
}



/* Code for cut!:ep */

static Lisp_Object CC_cutTep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v237;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cut:ep");
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
    v237 = stack[-2];
    v11 = elt(env, 1); /* !:rd!: */
    if (!consp(v237)) goto v308;
    v237 = qcar(v237);
    if (!(v237 == v11)) goto v308;
    v11 = stack[-2];
    v11 = qcdr(v11);
    if (!consp(v11)) goto v308;
    v11 = stack[-1];
    v11 = integerp(v11);
    if (v11 == nil) goto v308;
    v237 = stack[-1];
    v11 = stack[-2];
    v11 = qcdr(v11);
    v11 = qcdr(v11);
    v237 = difference2(v237, v11);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    stack[-1] = v237;
    v11 = (Lisp_Object)1; /* 0 */
    v11 = (Lisp_Object)lesseq2(v237, v11);
    nil = C_nil;
    if (exception_pending()) goto v206;
    v11 = v11 ? lisp_true : nil;
    env = stack[-4];
    if (!(v11 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-3] = elt(env, 1); /* !:rd!: */
    v11 = stack[-2];
    v11 = qcdr(v11);
    stack[0] = qcar(v11);
    v11 = stack[-1];
    v11 = negate(v11);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    stack[0] = Lash1(nil, stack[0], v11);
    nil = C_nil;
    if (exception_pending()) goto v206;
    env = stack[-4];
    v11 = stack[-2];
    v11 = qcdr(v11);
    v237 = qcdr(v11);
    v11 = stack[-1];
    v11 = plus2(v237, v11);
    nil = C_nil;
    if (exception_pending()) goto v206;
    {
        Lisp_Object v71 = stack[-3];
        Lisp_Object v72 = stack[0];
        popv(5);
        return list2star(v71, v72, v11);
    }

v308:
    v11 = elt(env, 0); /* cut!:ep */
    {
        popv(5);
        fn = elt(env, 2); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v11);
    }
/* error exit handlers */
v206:
    popv(5);
    return nil;
}



/* Code for ordpa */

static Lisp_Object CC_ordpa(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119, v120, v341, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ordpa");
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
    v120 = v1;
    v341 = v0;
/* end of prologue */

v38:
    v119 = v341;
    if (v119 == nil) goto v51;
    v119 = v120;
    if (v119 == nil) goto v144;
    v119 = v341;
    v119 = Lsimple_vectorp(nil, v119);
    env = stack[0];
    if (v119 == nil) goto v31;
    v119 = v120;
    v119 = Lsimple_vectorp(nil, v119);
    env = stack[0];
    if (v119 == nil) goto v79;
    v119 = v341;
    {
        popv(1);
        fn = elt(env, 3); /* ordpv */
        return (*qfn2(fn))(qenv(fn), v119, v120);
    }

v79:
    v119 = v120;
    v119 = (consp(v119) ? nil : lisp_true);
    { popv(1); return onevalue(v119); }

v31:
    v119 = v341;
    if (!consp(v119)) goto v102;
    v119 = v120;
    if (!consp(v119)) goto v206;
    v119 = v341;
    v29 = qcar(v119);
    v119 = v120;
    v119 = qcar(v119);
    if (equal(v29, v119)) goto v239;
    v119 = v341;
    v119 = qcar(v119);
    v341 = v119;
    v119 = v120;
    v119 = qcar(v119);
    v120 = v119;
    goto v38;

v239:
    v119 = v341;
    v119 = qcdr(v119);
    v341 = v119;
    v119 = v120;
    v119 = qcdr(v119);
    v120 = v119;
    goto v38;

v206:
    v119 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v119); }

v102:
    v119 = v120;
    if (!consp(v119)) goto v13;
    v119 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v119); }

v13:
    v119 = v341;
    if (is_number(v119)) goto v78;
    v119 = v120;
    if (symbolp(v119)) goto v8;
    v119 = v120;
    v119 = (is_number(v119) ? lisp_true : nil);
    { popv(1); return onevalue(v119); }

v8:
    v119 = v341;
        popv(1);
        return Lorderp(nil, v119, v120);

v78:
    v119 = v120;
    if (is_number(v119)) goto v74;
    v119 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v119); }

v74:
    v119 = v341;
    v119 = (Lisp_Object)lessp2(v119, v120);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v119 = v119 ? lisp_true : nil;
    v119 = (v119 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v119); }

v144:
    v119 = qvalue(elt(env, 1)); /* t */
    { popv(1); return onevalue(v119); }

v51:
    v119 = v120;
    v119 = (v119 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v119); }
/* error exit handlers */
v30:
    popv(1);
    return nil;
}



/* Code for getphystype */

static Lisp_Object CC_getphystype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v259, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystype");
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
    v259 = stack[0];
    fn = elt(env, 9); /* physopp */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    if (v259 == nil) goto v51;
    v259 = stack[0];
    fn = elt(env, 10); /* scalopp */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    if (v259 == nil) goto v242;
    v259 = elt(env, 1); /* scalar */
    { popv(3); return onevalue(v259); }

v242:
    v259 = stack[0];
    fn = elt(env, 11); /* vecopp */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    if (v259 == nil) goto v267;
    v259 = elt(env, 2); /* vector */
    { popv(3); return onevalue(v259); }

v267:
    v259 = stack[0];
    fn = elt(env, 12); /* tensopp */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    if (v259 == nil) goto v18;
    v259 = elt(env, 3); /* tensor */
    { popv(3); return onevalue(v259); }

v18:
    v259 = stack[0];
    fn = elt(env, 13); /* statep */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    if (v259 == nil) goto v19;
    v259 = elt(env, 4); /* state */
    { popv(3); return onevalue(v259); }

v19:
    v259 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v259); }

v51:
    v259 = stack[0];
    if (!consp(v259)) goto v80;
    v259 = stack[0];
    v119 = qcar(v259);
    v259 = elt(env, 6); /* phystype */
    v119 = get(v119, v259);
    env = stack[-2];
    v259 = v119;
    if (!(v119 == nil)) { popv(3); return onevalue(v259); }
    v259 = stack[0];
    v119 = qcar(v259);
    v259 = elt(env, 7); /* phystypefn */
    v119 = get(v119, v259);
    env = stack[-2];
    v259 = v119;
    if (v119 == nil) goto v14;
    v119 = v259;
    v259 = stack[0];
    v259 = qcdr(v259);
        popv(3);
        return Lapply1(nil, v119, v259);

v14:
    v259 = stack[0];
    fn = elt(env, 14); /* collectphystype */
    v119 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    v259 = v119;
    if (v119 == nil) goto v207;
    v119 = v259;
    v119 = qcdr(v119);
    if (v119 == nil) goto v308;
    v119 = elt(env, 4); /* state */
    v259 = Lmember(nil, v119, v259);
    if (v259 == nil) goto v204;
    v259 = elt(env, 4); /* state */
    { popv(3); return onevalue(v259); }

v204:
    stack[-1] = elt(env, 0); /* getphystype */
    v119 = elt(env, 8); /* "PHYSOP type conflict in" */
    v259 = stack[0];
    v259 = list2(v119, v259);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    {
        Lisp_Object v30 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* rederr2 */
        return (*qfn2(fn))(qenv(fn), v30, v259);
    }

v308:
    v259 = qcar(v259);
    { popv(3); return onevalue(v259); }

v207:
    v259 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v259); }

v80:
    v259 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v259); }
/* error exit handlers */
v29:
    popv(3);
    return nil;
}



/* Code for red!-weight1 */

static Lisp_Object CC_redKweight1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v250;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-weight1");
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
    goto v106;

v106:
    v27 = stack[-1];
    if (v27 == nil) goto v51;
    v27 = stack[-1];
    v27 = qcar(v27);
    v250 = Labsval(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-3];
    v27 = stack[0];
    v27 = qcar(v27);
    v250 = times2(v250, v27);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-3];
    v27 = stack[-2];
    v27 = cons(v250, v27);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-3];
    stack[-2] = v27;
    v27 = stack[-1];
    v27 = qcdr(v27);
    stack[-1] = v27;
    v27 = stack[0];
    v27 = qcdr(v27);
    stack[0] = v27;
    goto v106;

v51:
    v27 = (Lisp_Object)1; /* 0 */
    v250 = v27;
    goto v26;

v26:
    v27 = stack[-2];
    if (v27 == nil) { popv(4); return onevalue(v250); }
    v27 = stack[-2];
    v27 = qcar(v27);
    v27 = plus2(v27, v250);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-3];
    v250 = v27;
    v27 = stack[-2];
    v27 = qcdr(v27);
    stack[-2] = v27;
    goto v26;
/* error exit handlers */
v208:
    popv(4);
    return nil;
}



/* Code for oprin */

static Lisp_Object CC_oprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for oprin");
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
    v268 = stack[0];
    v9 = elt(env, 1); /* prtch */
    v9 = get(v268, v9);
    env = stack[-2];
    stack[-1] = v9;
    v9 = stack[-1];
    if (v9 == nil) goto v144;
    v9 = qvalue(elt(env, 3)); /* !*fort */
    if (v9 == nil) goto v17;
    v9 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v9);
    }

v17:
    v9 = qvalue(elt(env, 4)); /* !*list */
    if (v9 == nil) goto v73;
    v9 = qvalue(elt(env, 5)); /* obrkp!* */
    if (v9 == nil) goto v73;
    v268 = stack[0];
    v9 = elt(env, 6); /* (plus minus) */
    v9 = Lmemq(nil, v268, v9);
    if (v9 == nil) goto v73;
    v9 = qvalue(elt(env, 7)); /* testing!-width!* */
    if (v9 == nil) goto v77;
    v9 = qvalue(elt(env, 8)); /* t */
    qvalue(elt(env, 9)) = v9; /* overflowed!* */
    { popv(3); return onevalue(v9); }

v77:
    v9 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 12); /* terpri!* */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-2];
    v9 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v9);
    }

v73:
    v268 = stack[0];
    v9 = elt(env, 10); /* spaced */
    v9 = Lflagp(nil, v268, v9);
    env = stack[-2];
    if (v9 == nil) goto v233;
    v9 = elt(env, 2); /* " " */
    fn = elt(env, 11); /* prin2!* */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-2];
    v9 = stack[-1];
    fn = elt(env, 11); /* prin2!* */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-2];
    v9 = elt(env, 2); /* " " */
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v9);
    }

v233:
    v9 = stack[-1];
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v9);
    }

v144:
    v9 = elt(env, 2); /* " " */
    fn = elt(env, 11); /* prin2!* */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-2];
    v9 = stack[0];
    fn = elt(env, 11); /* prin2!* */
    v9 = (*qfn1(fn))(qenv(fn), v9);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-2];
    v9 = elt(env, 2); /* " " */
    {
        popv(3);
        fn = elt(env, 11); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v9);
    }
/* error exit handlers */
v340:
    popv(3);
    return nil;
}



/* Code for sc_kern */

static Lisp_Object CC_sc_kern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v242;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sc_kern");
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
    v242 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v242 = sub1(v242);
    nil = C_nil;
    if (exception_pending()) goto v84;
    v242 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v242/(16/CELL)));
    v242 = qcdr(v242);
    v242 = qcdr(v242);
    v242 = qcar(v242);
    { popv(1); return onevalue(v242); }
/* error exit handlers */
v84:
    popv(1);
    return nil;
}



/* Code for rnplus!: */

static Lisp_Object CC_rnplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v215, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnplus:");
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
    v215 = stack[-1];
    v215 = qcdr(v215);
    v16 = qcar(v215);
    v215 = stack[0];
    v215 = qcdr(v215);
    v215 = qcdr(v215);
    stack[-2] = times2(v16, v215);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    v215 = stack[-1];
    v215 = qcdr(v215);
    v16 = qcdr(v215);
    v215 = stack[0];
    v215 = qcdr(v215);
    v215 = qcar(v215);
    v215 = times2(v16, v215);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    stack[-2] = plus2(stack[-2], v215);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    v215 = stack[-1];
    v215 = qcdr(v215);
    v16 = qcdr(v215);
    v215 = stack[0];
    v215 = qcdr(v215);
    v215 = qcdr(v215);
    v215 = times2(v16, v215);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-3];
    {
        Lisp_Object v73 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v73, v215);
    }
/* error exit handlers */
v250:
    popv(4);
    return nil;
}



/* Code for matrix!+p */

static Lisp_Object CC_matrixLp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v73;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrix+p");
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
    v250 = stack[0];
    v73 = Llength(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    v250 = (Lisp_Object)17; /* 1 */
    v250 = (Lisp_Object)lessp2(v73, v250);
    nil = C_nil;
    if (exception_pending()) goto v257;
    v250 = v250 ? lisp_true : nil;
    env = stack[-4];
    if (v250 == nil) goto v51;
    v250 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v250); }

v51:
    v250 = stack[0];
    v250 = qcar(v250);
    v250 = Llength(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    stack[-3] = v250;
    v250 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v250;
    v250 = stack[0];
    v250 = qcdr(v250);
    stack[-1] = v250;
    goto v103;

v103:
    v250 = stack[-1];
    if (v250 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v250 = stack[-1];
    v250 = qcar(v250);
    stack[0] = stack[-3];
    v250 = Llength(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-4];
    if (equal(stack[0], v250)) goto v104;
    v250 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v250;
    goto v104;

v104:
    v250 = stack[-1];
    v250 = qcdr(v250);
    stack[-1] = v250;
    goto v103;
/* error exit handlers */
v257:
    popv(5);
    return nil;
}



/* Code for sfto_dcontentf1 */

static Lisp_Object CC_sfto_dcontentf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v215, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_dcontentf1");
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
    v215 = v0;
/* end of prologue */

v35:
    v16 = stack[0];
    v258 = (Lisp_Object)17; /* 1 */
    if (v16 == v258) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v258 = v215;
    if (!consp(v258)) goto v241;
    v258 = v215;
    v258 = qcar(v258);
    if (!consp(v258)) goto v241;
    v258 = v215;
    v258 = qcdr(v258);
    stack[-1] = v258;
    v258 = v215;
    v258 = qcar(v258);
    v215 = qcdr(v258);
    v258 = stack[0];
    v258 = CC_sfto_dcontentf1(env, v215, v258);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    stack[0] = v258;
    v258 = stack[-1];
    v215 = v258;
    goto v35;

v241:
    v258 = v215;
    fn = elt(env, 1); /* absf */
    v215 = (*qfn1(fn))(qenv(fn), v258);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v258 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* sfto_gcdf */
        return (*qfn2(fn))(qenv(fn), v215, v258);
    }
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for isarb_int */

static Lisp_Object CC_isarb_int(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v127, v214;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isarb_int");
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
    v127 = v0;
/* end of prologue */
    v128 = v127;
    v128 = Lconsp(nil, v128);
    env = stack[0];
    if (v128 == nil) goto v38;
    v128 = v127;
    v214 = qcar(v128);
    v128 = elt(env, 1); /* arbint */
    if (v214 == v128) goto v36;
    v128 = v127;
    v128 = qcdr(v128);
    fn = elt(env, 4); /* multi_isarb_int */
    v128 = (*qfn1(fn))(qenv(fn), v128);
    nil = C_nil;
    if (exception_pending()) goto v21;
    goto v38;

v38:
    v128 = nil;
    { popv(1); return onevalue(v128); }

v36:
    v128 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v128; /* found_int */
    goto v38;
/* error exit handlers */
v21:
    popv(1);
    return nil;
}



/* Code for rationalizei */

static Lisp_Object CC_rationalizei(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v298, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rationalizei");
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
    v298 = stack[-1];
    v298 = qcdr(v298);
    stack[-2] = v298;
    v69 = v298;
    v298 = v69;
    v298 = (consp(v298) ? nil : lisp_true);
    if (!(v298 == nil)) goto v87;
    v298 = v69;
    v298 = qcar(v298);
    v298 = (consp(v298) ? nil : lisp_true);
    goto v87;

v87:
    if (!(v298 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v69 = elt(env, 1); /* i */
    v298 = stack[-2];
    v298 = Lsmemq(nil, v69, v298);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    if (v298 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v69 = elt(env, 1); /* i */
    v298 = qvalue(elt(env, 2)); /* kord!* */
    v298 = cons(v69, v298);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    stack[0] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v298; /* kord!* */
    v298 = stack[-1];
    fn = elt(env, 4); /* reordsq */
    v298 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v342;
    env = stack[-3];
    stack[-2] = v298;
    qvalue(elt(env, 2)) = stack[0]; /* kord!* */
    v298 = stack[-2];
    v298 = qcdr(v298);
    stack[0] = v298;
    v298 = qcar(v298);
    v69 = qcar(v298);
    v298 = elt(env, 3); /* (i . 1) */
    if (!(equal(v69, v298))) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v298 = stack[0];
    v298 = qcdr(v298);
    if (!(v298 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v69 = elt(env, 1); /* i */
    v298 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* to */
    v69 = (*qfn2(fn))(qenv(fn), v69, v298);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    v298 = (Lisp_Object)17; /* 1 */
    v298 = cons(v69, v298);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    stack[-1] = ncons(v298);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    v298 = stack[-2];
    v298 = qcar(v298);
    fn = elt(env, 6); /* reorder */
    v298 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    fn = elt(env, 7); /* multf */
    v298 = (*qfn2(fn))(qenv(fn), stack[-1], v298);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    fn = elt(env, 8); /* negf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-3];
    v298 = stack[0];
    v298 = qcar(v298);
    v298 = qcdr(v298);
    fn = elt(env, 6); /* reorder */
    v298 = (*qfn1(fn))(qenv(fn), v298);
    nil = C_nil;
    if (exception_pending()) goto v3;
    {
        Lisp_Object v146 = stack[-1];
        popv(4);
        return cons(v146, v298);
    }
/* error exit handlers */
v342:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[0]; /* kord!* */
    popv(4);
    return nil;
v3:
    popv(4);
    return nil;
}



/* Code for testred */

static Lisp_Object CC_testred(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v272, v232, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testred");
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
    v232 = qvalue(elt(env, 2)); /* maxvar */
    v272 = stack[0];
    v272 = plus2(v232, v272);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-2];
    v232 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v272/(16/CELL)));
    v272 = (Lisp_Object)1; /* 0 */
    v272 = *(Lisp_Object *)((char *)v232 + (CELL-TAG_VECTOR) + ((int32_t)v272/(16/CELL)));
    if (v272 == nil) goto v38;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v232 = qvalue(elt(env, 2)); /* maxvar */
    v272 = stack[0];
    v272 = plus2(v232, v272);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-2];
    v232 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v272/(16/CELL)));
    v272 = (Lisp_Object)17; /* 1 */
    v272 = *(Lisp_Object *)((char *)v232 + (CELL-TAG_VECTOR) + ((int32_t)v272/(16/CELL)));
    v272 = qcar(v272);
    v232 = qcar(v272);
    v272 = (Lisp_Object)33; /* 2 */
    v272 = (Lisp_Object)lessp2(v232, v272);
    nil = C_nil;
    if (exception_pending()) goto v245;
    v272 = v272 ? lisp_true : nil;
    env = stack[-2];
    if (v272 == nil) goto v38;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v232 = qvalue(elt(env, 2)); /* maxvar */
    v272 = stack[0];
    v272 = plus2(v232, v272);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-2];
    v61 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v272/(16/CELL)));
    v232 = (Lisp_Object)1; /* 0 */
    v272 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v61 + (CELL-TAG_VECTOR) + ((int32_t)v232/(16/CELL))) = v272;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v232 = qvalue(elt(env, 2)); /* maxvar */
    v272 = stack[0];
    v272 = plus2(v232, v272);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-2];
    v232 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v272/(16/CELL)));
    v272 = (Lisp_Object)65; /* 4 */
    v272 = *(Lisp_Object *)((char *)v232 + (CELL-TAG_VECTOR) + ((int32_t)v272/(16/CELL)));
    stack[-1] = v272;
    goto v71;

v71:
    v272 = stack[-1];
    if (v272 == nil) goto v120;
    v272 = stack[-1];
    v272 = qcar(v272);
    stack[0] = v272;
    v272 = stack[0];
    v232 = qcar(v272);
    v272 = stack[0];
    v272 = qcdr(v272);
    v272 = qcar(v272);
    fn = elt(env, 4); /* downwght1 */
    v272 = (*qfn2(fn))(qenv(fn), v232, v272);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-2];
    v272 = stack[0];
    v272 = qcar(v272);
    v272 = CC_testred(env, v272);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-2];
    v272 = stack[-1];
    v272 = qcdr(v272);
    stack[-1] = v272;
    goto v71;

v120:
    v272 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v272); }

v38:
    v272 = nil;
    { popv(3); return onevalue(v272); }
/* error exit handlers */
v245:
    popv(3);
    return nil;
}



/* Code for xdegreemon */

static Lisp_Object CC_xdegreemon(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v251, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegreemon");
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
    v251 = v0;
/* end of prologue */
    v209 = qvalue(elt(env, 1)); /* xdegreelist!* */
    if (v209 == nil) goto v39;
    v209 = v251;
    stack[0] = v209;
    v209 = (Lisp_Object)1; /* 0 */
    v77 = v209;
    goto v84;

v84:
    v209 = stack[0];
    if (v209 == nil) { popv(2); return onevalue(v77); }
    v209 = stack[0];
    v209 = qcar(v209);
    v251 = v209;
    v209 = qvalue(elt(env, 1)); /* xdegreelist!* */
    v209 = Latsoc(nil, v251, v209);
    v209 = qcdr(v209);
    v251 = v77;
    v209 = plus2(v209, v251);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-1];
    v77 = v209;
    v209 = stack[0];
    v209 = qcdr(v209);
    stack[0] = v209;
    goto v84;

v39:
    v209 = v251;
    fn = elt(env, 2); /* mknwedge */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v258;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* xdegree */
        return (*qfn1(fn))(qenv(fn), v209);
    }
/* error exit handlers */
v258:
    popv(2);
    return nil;
}



/* Code for make!-set */

static Lisp_Object CC_makeKset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-set");
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
    v35 = v0;
/* end of prologue */
    v36 = v35;
    v35 = elt(env, 1); /* set!-ordp */
    fn = elt(env, 2); /* sort */
    v35 = (*qfn2(fn))(qenv(fn), v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* makelist */
        return (*qfn1(fn))(qenv(fn), v35);
    }
/* error exit handlers */
v144:
    popv(1);
    return nil;
}



/* Code for contr1!-strand */

static Lisp_Object CC_contr1Kstrand(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v247, v31, v267, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for contr1-strand");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v247 = v1;
    v31 = v0;
/* end of prologue */
    v85 = v31;
    v267 = v247;
    v31 = qvalue(elt(env, 1)); /* nil */
    v247 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* contr2!-strand */
        return (*qfnn(fn))(qenv(fn), 4, v85, v267, v31, v247);
    }
}



/* Code for getel1 */

static Lisp_Object MS_CDECL CC_getel1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v308, v340;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "getel1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getel1");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v37;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v25:
    v236 = stack[-1];
    if (v236 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v236 = stack[-1];
    v236 = qcar(v236);
    v236 = integerp(v236);
    if (v236 == nil) goto v267;
    v236 = stack[-1];
    v308 = qcar(v236);
    v236 = stack[0];
    v236 = qcar(v236);
    v236 = (Lisp_Object)geq2(v308, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    v236 = v236 ? lisp_true : nil;
    env = stack[-3];
    if (!(v236 == nil)) goto v215;
    v236 = stack[-1];
    v308 = qcar(v236);
    v236 = (Lisp_Object)1; /* 0 */
    v236 = (Lisp_Object)lessp2(v308, v236);
    nil = C_nil;
    if (exception_pending()) goto v237;
    v236 = v236 ? lisp_true : nil;
    env = stack[-3];
    if (!(v236 == nil)) goto v215;
    v308 = stack[-2];
    v236 = stack[-1];
    v236 = qcar(v236);
    v236 = *(Lisp_Object *)((char *)v308 + (CELL-TAG_VECTOR) + ((int32_t)v236/(16/CELL)));
    stack[-2] = v236;
    v236 = stack[-1];
    v236 = qcdr(v236);
    stack[-1] = v236;
    v236 = stack[0];
    v236 = qcdr(v236);
    stack[0] = v236;
    goto v25;

v215:
    v340 = elt(env, 2); /* rlisp */
    v308 = (Lisp_Object)337; /* 21 */
    v236 = elt(env, 3); /* "Array out of bounds" */
    {
        popv(4);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v340, v308, v236);
    }

v267:
    v236 = stack[-1];
    v308 = qcar(v236);
    v236 = elt(env, 1); /* "array index" */
    {
        popv(4);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v308, v236);
    }
/* error exit handlers */
v237:
    popv(4);
    return nil;
}



/* Code for mv!-pow!-minusp */

static Lisp_Object CC_mvKpowKminusp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v99;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow-minusp");
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

v254:
    v255 = stack[0];
    if (v255 == nil) goto v39;
    v255 = stack[0];
    v99 = qcar(v255);
    v255 = (Lisp_Object)1; /* 0 */
    v255 = (Lisp_Object)lessp2(v99, v255);
    nil = C_nil;
    if (exception_pending()) goto v103;
    v255 = v255 ? lisp_true : nil;
    env = stack[-1];
    if (!(v255 == nil)) { popv(2); return onevalue(v255); }
    v255 = stack[0];
    v255 = qcdr(v255);
    stack[0] = v255;
    goto v254;

v39:
    v255 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v255); }
/* error exit handlers */
v103:
    popv(2);
    return nil;
}



/* Code for bas_make1 */

static Lisp_Object MS_CDECL CC_bas_make1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v37, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bas_make1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_make1");
#endif
    if (stack >= stacklimit)
    {
        push3(v37,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v37);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v37;
    stack[-3] = v1;
    v241 = v0;
/* end of prologue */
    stack[-4] = v241;
    stack[-1] = stack[-3];
    v241 = stack[-3];
    stack[0] = Llength(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v241 = stack[-3];
    fn = elt(env, 1); /* dp_ecart */
    v103 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v241 = stack[-2];
    v241 = list2(v103, v241);
    nil = C_nil;
    if (exception_pending()) goto v20;
    {
        Lisp_Object v79 = stack[-4];
        Lisp_Object v80 = stack[-1];
        Lisp_Object v100 = stack[0];
        popv(6);
        return list3star(v79, v80, v100, v241);
    }
/* error exit handlers */
v20:
    popv(6);
    return nil;
}



/* Code for general!-times!-term!-mod!-p */

static Lisp_Object CC_generalKtimesKtermKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v313, v131, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-times-term-mod-p");
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
    v313 = stack[-1];
    if (v313 == nil) goto v38;
    v313 = stack[-1];
    if (!consp(v313)) goto v247;
    v313 = stack[-1];
    v313 = qcar(v313);
    if (!consp(v313)) goto v247;
    v313 = stack[-2];
    v313 = qcar(v313);
    v131 = qcar(v313);
    v313 = stack[-1];
    v313 = qcar(v313);
    v313 = qcar(v313);
    v313 = qcar(v313);
    if (equal(v131, v313)) goto v145;
    v313 = stack[-2];
    v313 = qcar(v313);
    v131 = qcar(v313);
    v313 = stack[-1];
    v313 = qcar(v313);
    v313 = qcar(v313);
    v313 = qcar(v313);
    fn = elt(env, 2); /* ordop */
    v313 = (*qfn2(fn))(qenv(fn), v131, v313);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    if (v313 == nil) goto v61;
    v313 = stack[-2];
    stack[0] = qcar(v313);
    v313 = stack[-2];
    v131 = qcdr(v313);
    v313 = stack[-1];
    fn = elt(env, 3); /* general!-times!-mod!-p */
    v131 = (*qfn2(fn))(qenv(fn), v131, v313);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v313 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v138 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v138, v131, v313);
    }

v61:
    v313 = stack[-1];
    v313 = qcar(v313);
    stack[-3] = qcar(v313);
    v131 = stack[-2];
    v313 = stack[-1];
    v313 = qcar(v313);
    v313 = qcdr(v313);
    stack[0] = CC_generalKtimesKtermKmodKp(env, v131, v313);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v131 = stack[-2];
    v313 = stack[-1];
    v313 = qcdr(v313);
    v313 = CC_generalKtimesKtermKmodKp(env, v131, v313);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    {
        Lisp_Object v52 = stack[-3];
        Lisp_Object v97 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v52, v97, v313);
    }

v145:
    v313 = stack[-2];
    v313 = qcar(v313);
    v132 = qcar(v313);
    v313 = stack[-2];
    v313 = qcar(v313);
    v131 = qcdr(v313);
    v313 = stack[-1];
    v313 = qcar(v313);
    v313 = qcar(v313);
    v313 = qcdr(v313);
    v313 = (Lisp_Object)(int32_t)((int32_t)v131 + (int32_t)v313 - TAG_FIXNUM);
    fn = elt(env, 5); /* mksp */
    stack[-3] = (*qfn2(fn))(qenv(fn), v132, v313);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v313 = stack[-2];
    v131 = qcdr(v313);
    v313 = stack[-1];
    v313 = qcar(v313);
    v313 = qcdr(v313);
    fn = elt(env, 3); /* general!-times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v131, v313);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v131 = stack[-2];
    v313 = stack[-1];
    v313 = qcdr(v313);
    v313 = CC_generalKtimesKtermKmodKp(env, v131, v313);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    {
        Lisp_Object v139 = stack[-3];
        Lisp_Object v140 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v139, v140, v313);
    }

v247:
    v313 = stack[-2];
    stack[0] = qcar(v313);
    v313 = stack[-2];
    v131 = qcdr(v313);
    v313 = stack[-1];
    fn = elt(env, 6); /* gen!-mult!-by!-const!-mod!-p */
    v131 = (*qfn2(fn))(qenv(fn), v131, v313);
    nil = C_nil;
    if (exception_pending()) goto v137;
    env = stack[-4];
    v313 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v141 = stack[0];
        popv(5);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v141, v131, v313);
    }

v38:
    v313 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v313); }
/* error exit handlers */
v137:
    popv(5);
    return nil;
}



/* Code for mapcons */

static Lisp_Object CC_mapcons(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v73, v74;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mapcons");
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
    stack[-3] = v1;
    v73 = v0;
/* end of prologue */
    stack[-4] = v73;
    v73 = stack[-4];
    if (v73 == nil) goto v36;
    v73 = stack[-4];
    v73 = qcar(v73);
    v74 = stack[-3];
    v73 = cons(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = ncons(v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    stack[-1] = v73;
    stack[-2] = v73;
    goto v51;

v51:
    v73 = stack[-4];
    v73 = qcdr(v73);
    stack[-4] = v73;
    v73 = stack[-4];
    if (v73 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v73 = stack[-4];
    v73 = qcar(v73);
    v74 = stack[-3];
    v73 = cons(v74, v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = ncons(v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = Lrplacd(nil, stack[0], v73);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-5];
    v73 = stack[-1];
    v73 = qcdr(v73);
    stack[-1] = v73;
    goto v51;

v36:
    v73 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v73); }
/* error exit handlers */
v75:
    popv(6);
    return nil;
}



/* Code for sfto_gcdf */

static Lisp_Object CC_sfto_gcdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf");
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
    v250 = qvalue(elt(env, 1)); /* !*rldavgcd */
    if (v250 == nil) goto v26;
    v73 = stack[-1];
    v250 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* sfto_davp */
    v250 = (*qfn2(fn))(qenv(fn), v73, v250);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-3];
    if (!(v250 == nil)) goto v84;
    v73 = stack[0];
    v250 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 4); /* sfto_davp */
    v250 = (*qfn2(fn))(qenv(fn), v73, v250);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-3];
    if (!(v250 == nil)) goto v84;
    v73 = stack[-1];
    v250 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); /* ezgcdf */
        return (*qfn2(fn))(qenv(fn), v73, v250);
    }

v84:
    v250 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* !*ezgcd */
    qvalue(elt(env, 3)) = v250; /* !*ezgcd */
    v73 = stack[-1];
    v250 = stack[0];
    fn = elt(env, 6); /* gcdf */
    v250 = (*qfn2(fn))(qenv(fn), v73, v250);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* !*ezgcd */
    { popv(4); return onevalue(v250); }

v26:
    v73 = stack[-1];
    v250 = stack[0];
    {
        popv(4);
        fn = elt(env, 6); /* gcdf */
        return (*qfn2(fn))(qenv(fn), v73, v250);
    }
/* error exit handlers */
v257:
    env = stack[-3];
    qvalue(elt(env, 3)) = stack[-2]; /* !*ezgcd */
    popv(4);
    return nil;
v256:
    popv(4);
    return nil;
}



/* Code for sq2sscfpl */

static Lisp_Object CC_sq2sscfpl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sq2sscfpl");
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
    v15 = stack[-1];
    if (v15 == nil) goto v38;
    v15 = stack[-1];
    if (!consp(v15)) goto v31;
    v15 = stack[-1];
    v15 = qcar(v15);
    if (!consp(v15)) goto v31;
    v15 = stack[-1];
    v27 = qcar(v15);
    v15 = stack[0];
    fn = elt(env, 2); /* sq2sstm */
    stack[-2] = (*qfn2(fn))(qenv(fn), v27, v15);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v15 = stack[-1];
    v27 = qcdr(v15);
    v15 = stack[0];
    v15 = CC_sq2sscfpl(env, v27, v15);
    nil = C_nil;
    if (exception_pending()) goto v145;
    {
        Lisp_Object v208 = stack[-2];
        popv(4);
        return Lappend(nil, v208, v15);
    }

v31:
    v15 = stack[0];
    v15 = qcdr(v15);
    v15 = add1(v15);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    fn = elt(env, 3); /* mkzl */
    v27 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-3];
    v15 = stack[-1];
    v15 = cons(v27, v15);
    nil = C_nil;
    if (exception_pending()) goto v145;
    popv(4);
    return ncons(v15);

v38:
    v15 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v15); }
/* error exit handlers */
v145:
    popv(4);
    return nil;
}



/* Code for rl_varlat */

static Lisp_Object CC_rl_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_varlat");
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
    v35 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_varlat!* */
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-1];
    {
        Lisp_Object v242 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v242, v35);
    }
/* error exit handlers */
v144:
    popv(2);
    return nil;
}



setup_type const u06_setup[] =
{
    {"divd",                    too_few_2,      CC_divd,       wrong_no_2},
    {"dp_term",                 too_few_2,      CC_dp_term,    wrong_no_2},
    {"maprint",                 too_few_2,      CC_maprint,    wrong_no_2},
    {"gperm2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm2},
    {"times-in-vector",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_timesKinKvector},
    {"kernord-sort",            CC_kernordKsort,too_many_1,    wrong_no_1},
    {"treesizep1",              too_few_2,      CC_treesizep1, wrong_no_2},
    {"simpexpon",               CC_simpexpon,   too_many_1,    wrong_no_1},
    {"bfprin:lst",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_bfprinTlst},
    {"difff",                   too_few_2,      CC_difff,      wrong_no_2},
    {"simp*",                   CC_simpH,       too_many_1,    wrong_no_1},
    {"vdpgetprop",              too_few_2,      CC_vdpgetprop, wrong_no_2},
    {"areallindices",           CC_areallindices,too_many_1,   wrong_no_1},
    {"contrsp2",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_contrsp2},
    {"mo=deglist",              CC_moMdeglist,  too_many_1,    wrong_no_1},
    {"pdmult",                  too_few_2,      CC_pdmult,     wrong_no_2},
    {"aronep:",                 CC_aronepT,     too_many_1,    wrong_no_1},
    {"clear-column",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_clearKcolumn},
    {"lto_insertq",             too_few_2,      CC_lto_insertq,wrong_no_2},
    {"omobjs",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobjs},
    {"ps:get-term",             too_few_2,      CC_psTgetKterm,wrong_no_2},
    {"letmtr3",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_letmtr3},
    {"genp",                    CC_genp,        too_many_1,    wrong_no_1},
    {"termordp",                too_few_2,      CC_termordp,   wrong_no_2},
    {"cut:ep",                  too_few_2,      CC_cutTep,     wrong_no_2},
    {"ordpa",                   too_few_2,      CC_ordpa,      wrong_no_2},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"red-weight1",             too_few_2,      CC_redKweight1,wrong_no_2},
    {"oprin",                   CC_oprin,       too_many_1,    wrong_no_1},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"rnplus:",                 too_few_2,      CC_rnplusT,    wrong_no_2},
    {"matrix+p",                CC_matrixLp,    too_many_1,    wrong_no_1},
    {"sfto_dcontentf1",         too_few_2,      CC_sfto_dcontentf1,wrong_no_2},
    {"isarb_int",               CC_isarb_int,   too_many_1,    wrong_no_1},
    {"rationalizei",            CC_rationalizei,too_many_1,    wrong_no_1},
    {"testred",                 CC_testred,     too_many_1,    wrong_no_1},
    {"xdegreemon",              CC_xdegreemon,  too_many_1,    wrong_no_1},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"contr1-strand",           too_few_2,      CC_contr1Kstrand,wrong_no_2},
    {"getel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_getel1},
    {"mv-pow-minusp",           CC_mvKpowKminusp,too_many_1,   wrong_no_1},
    {"bas_make1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_bas_make1},
    {"general-times-term-mod-p",too_few_2,      CC_generalKtimesKtermKmodKp,wrong_no_2},
    {"mapcons",                 too_few_2,      CC_mapcons,    wrong_no_2},
    {"sfto_gcdf",               too_few_2,      CC_sfto_gcdf,  wrong_no_2},
    {"sq2sscfpl",               too_few_2,      CC_sq2sscfpl,  wrong_no_2},
    {"rl_varlat",               CC_rl_varlat,   too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u06", (two_args *)"19993 1999235 7587150", 0}
};

/* end of generated code */
