
/* $destdir/generated-c\u20.c Machine generated C code */

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


/* Code for subs3t */

static Lisp_Object CC_subs3t(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v80, v81, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3t");
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
    v80 = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    v79 = stack[-4];
    stack[0] = qcar(v79);
    v79 = stack[-4];
    v79 = qcdr(v79);
    if (!consp(v79)) goto v83;
    v79 = stack[-4];
    v79 = qcdr(v79);
    v79 = qcar(v79);
    if (!consp(v79)) goto v83;
    v79 = v80;
    goto v84;

v84:
    fn = elt(env, 7); /* mtchk */
    v79 = (*qfn2(fn))(qenv(fn), stack[0], v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    stack[-3] = v79;
    v79 = stack[-3];
    if (v79 == nil) goto v86;
    v79 = stack[-3];
    v79 = qcar(v79);
    v79 = qcar(v79);
    if (v79 == nil) goto v87;
    v79 = stack[-4];
    v81 = qcdr(v79);
    v80 = stack[-3];
    v79 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 8); /* subs3f1 */
    v79 = (*qfnn(fn))(qenv(fn), 3, v81, v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    stack[-2] = v79;
    v79 = qvalue(elt(env, 2)); /* mchfg!* */
    if (v79 == nil) goto v86;
    v79 = stack[-4];
    v80 = qcar(v79);
    v79 = (Lisp_Object)17; /* 1 */
    v79 = cons(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v80 = ncons(v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = (Lisp_Object)17; /* 1 */
    v80 = cons(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = stack[-2];
    {
        popv(7);
        fn = elt(env, 9); /* multsq */
        return (*qfn2(fn))(qenv(fn), v80, v79);
    }

v86:
    v79 = stack[-4];
    v80 = ncons(v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    v79 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v80, v79);

v87:
    v79 = stack[-3];
    v79 = qcar(v79);
    v79 = qcdr(v79);
    v79 = qcdr(v79);
    stack[-3] = v79;
    v79 = stack[-3];
    v79 = qcdr(v79);
    v79 = qcar(v79);
    v79 = qcar(v79);
    stack[-1] = v79;
    v79 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v79; /* mchfg!* */
    v79 = stack[-4];
    v81 = qcdr(v79);
    v80 = qvalue(elt(env, 3)); /* !*match */
    v79 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 8); /* subs3f1 */
    v79 = (*qfnn(fn))(qenv(fn), 3, v81, v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    stack[-2] = v79;
    v79 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v79; /* mchfg!* */
    v79 = stack[-1];
    v80 = qcar(v79);
    v79 = stack[-4];
    v79 = qcar(v79);
    v79 = qcar(v79);
    if (equal(v80, v79)) goto v88;
    v79 = stack[-1];
    v79 = qcar(v79);
    fn = elt(env, 10); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = stack[-4];
    v79 = qcar(v79);
    v79 = qcar(v79);
    fn = elt(env, 10); /* simp */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    if (equal(stack[0], v79)) goto v89;
    v82 = elt(env, 0); /* subs3t */
    v81 = stack[-4];
    v80 = stack[-3];
    v79 = stack[-1];
    v79 = list4(v82, v81, v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    fn = elt(env, 11); /* errach */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    goto v89;

v89:
    v79 = stack[-1];
    v80 = qcdr(v79);
    v79 = stack[-4];
    v79 = qcar(v79);
    v79 = qcdr(v79);
    if (equal(v80, v79)) goto v90;
    v79 = stack[-4];
    v79 = qcar(v79);
    stack[0] = qcar(v79);
    v79 = stack[-4];
    v79 = qcar(v79);
    v80 = qcdr(v79);
    v79 = stack[-1];
    v79 = qcdr(v79);
    v79 = difference2(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    fn = elt(env, 12); /* to */
    v80 = (*qfn2(fn))(qenv(fn), stack[0], v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = (Lisp_Object)17; /* 1 */
    v79 = cons(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v80 = ncons(v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = (Lisp_Object)17; /* 1 */
    v80 = cons(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = stack[-2];
    fn = elt(env, 9); /* multsq */
    v79 = (*qfn2(fn))(qenv(fn), v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    stack[-2] = v79;
    goto v90;

v90:
    v79 = stack[-3];
    fn = elt(env, 13); /* simpcar */
    v80 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = stack[-2];
    fn = elt(env, 9); /* multsq */
    v79 = (*qfn2(fn))(qenv(fn), v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    stack[-2] = v79;
    v79 = stack[-3];
    v79 = qcdr(v79);
    v79 = qcar(v79);
    v79 = qcdr(v79);
    stack[-3] = v79;
    v79 = stack[-3];
    if (v79 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    v79 = (Lisp_Object)17; /* 1 */
    stack[-1] = v79;
    goto v91;

v91:
    v79 = stack[-3];
    if (v79 == nil) goto v92;
    v79 = stack[-3];
    v79 = qcar(v79);
    v79 = qcar(v79);
    if (!consp(v79)) goto v93;
    v79 = stack[-3];
    v79 = qcar(v79);
    v79 = qcar(v79);
    fn = elt(env, 14); /* sfp */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    if (!(v79 == nil)) goto v93;
    v79 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = qvalue(elt(env, 5)); /* subfg!* */
    qvalue(elt(env, 5)) = v79; /* subfg!* */
    v79 = stack[-3];
    v79 = qcar(v79);
    v79 = qcar(v79);
    fn = elt(env, 10); /* simp */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-6];
    stack[0] = v79;
    v79 = stack[0];
    fn = elt(env, 15); /* kernp */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-6];
    if (v79 == nil) goto v95;
    v79 = stack[0];
    v79 = qcar(v79);
    v79 = qcar(v79);
    v79 = qcar(v79);
    v80 = qcar(v79);
    stack[0] = v80;
    v79 = stack[-3];
    v79 = qcar(v79);
    v79 = qcar(v79);
    v79 = qcar(v79);
    if (!consp(v80)) goto v95;
    v80 = qcar(v80);
    if (!(v80 == v79)) goto v95;
    v79 = stack[0];
    goto v96;

v96:
    qvalue(elt(env, 5)) = stack[-4]; /* subfg!* */
    goto v97;

v97:
    stack[0] = v79;
    v79 = stack[0];
    fn = elt(env, 16); /* noncomp */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    if (!(v79 == nil)) goto v98;
    v79 = qvalue(elt(env, 6)); /* !*mcd */
    if (!(v79 == nil)) goto v99;

v98:
    v79 = qvalue(elt(env, 4)); /* t */
    stack[-5] = v79;
    goto v99;

v99:
    v79 = stack[-5];
    if (v79 == nil) goto v100;
    v79 = stack[-3];
    v79 = qcar(v79);
    v79 = qcdr(v79);
    v79 = negate(v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    goto v101;

v101:
    fn = elt(env, 17); /* mksp */
    v80 = (*qfn2(fn))(qenv(fn), stack[0], v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = (Lisp_Object)17; /* 1 */
    v79 = cons(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = ncons(v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    fn = elt(env, 18); /* multf */
    v79 = (*qfn2(fn))(qenv(fn), stack[-1], v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    stack[-1] = v79;
    v79 = stack[-3];
    v79 = qcdr(v79);
    stack[-3] = v79;
    goto v91;

v100:
    v79 = stack[-3];
    v79 = qcar(v79);
    v79 = qcdr(v79);
    goto v101;

v95:
    v79 = stack[-3];
    v79 = qcar(v79);
    v79 = qcar(v79);
    fn = elt(env, 19); /* revop1 */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-6];
    goto v96;

v93:
    v79 = stack[-3];
    v79 = qcar(v79);
    v79 = qcar(v79);
    goto v97;

v92:
    v79 = stack[-5];
    if (v79 == nil) goto v102;
    v80 = stack[-1];
    v79 = stack[-2];
    v79 = qcar(v79);
    fn = elt(env, 18); /* multf */
    v80 = (*qfn2(fn))(qenv(fn), v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    v79 = stack[-2];
    v79 = qcdr(v79);
    popv(7);
    return cons(v80, v79);

v102:
    v79 = stack[-2];
    stack[0] = qcar(v79);
    v80 = stack[-1];
    v79 = stack[-2];
    v79 = qcdr(v79);
    fn = elt(env, 18); /* multf */
    v79 = (*qfn2(fn))(qenv(fn), v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    {
        Lisp_Object v103 = stack[0];
        popv(7);
        return cons(v103, v79);
    }

v88:
    v80 = stack[-1];
    v79 = stack[-4];
    v79 = qcar(v79);
    if (equal(v80, v79)) goto v90;
    v79 = stack[-4];
    v79 = qcar(v79);
    stack[0] = qcar(v79);
    v79 = stack[-4];
    v79 = qcar(v79);
    v80 = qcdr(v79);
    v79 = stack[-1];
    v79 = qcdr(v79);
    v79 = difference2(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    fn = elt(env, 12); /* to */
    v80 = (*qfn2(fn))(qenv(fn), stack[0], v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = (Lisp_Object)17; /* 1 */
    v79 = cons(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v80 = ncons(v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = (Lisp_Object)17; /* 1 */
    v80 = cons(v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v79 = stack[-2];
    fn = elt(env, 9); /* multsq */
    v79 = (*qfn2(fn))(qenv(fn), v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    stack[-2] = v79;
    goto v90;

v83:
    v79 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 20); /* sizchk */
    v79 = (*qfn2(fn))(qenv(fn), v80, v79);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    goto v84;
/* error exit handlers */
v94:
    env = stack[-6];
    qvalue(elt(env, 5)) = stack[-4]; /* subfg!* */
    popv(7);
    return nil;
v85:
    popv(7);
    return nil;
}



/* Code for nf */

static Lisp_Object MS_CDECL CC_nf(Lisp_Object env, int nargs,
                         Lisp_Object v1, Lisp_Object v104,
                         Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v141, v142, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "nf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nf");
#endif
    if (stack >= stacklimit)
    {
        push3(v31,v104,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v1,v104,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v31;
    v141 = v104;
    v142 = v1;
/* end of prologue */
    stack[-10] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v141; /* gg */
    v141 = qvalue(elt(env, 1)); /* gg */
    if (v141 == nil) goto v87;
    stack[-3] = nil;
    v141 = (Lisp_Object)1; /* 0 */
    stack[0] = v141;
    v141 = v142;
    stack[-8] = v141;
    v141 = qvalue(elt(env, 1)); /* gg */
    stack[-2] = v141;
    goto v143;

v143:
    v141 = stack[-8];
    if (v141 == nil) goto v144;
    v141 = stack[-8];
    v141 = qcar(v141);
    v141 = qcar(v141);
    stack[-7] = v141;
    goto v145;

v145:
    v141 = stack[-2];
    if (v141 == nil) goto v146;
    v142 = stack[-7];
    v141 = stack[-2];
    v141 = qcar(v141);
    v141 = qcdr(v141);
    fn = elt(env, 13); /* dless */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    if (v141 == nil) goto v146;
    v141 = stack[-2];
    v141 = qcdr(v141);
    stack[-2] = v141;
    goto v145;

v146:
    v141 = stack[-2];
    if (v141 == nil) goto v144;
    v141 = stack[-2];
    stack[-1] = v141;
    goto v147;

v147:
    v141 = stack[-1];
    if (v141 == nil) goto v148;
    v141 = stack[-1];
    v141 = qcar(v141);
    v142 = qcdr(v141);
    v141 = stack[-7];
    fn = elt(env, 14); /* dd */
    stack[-4] = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    v142 = stack[-9];
    v141 = (Lisp_Object)33; /* 2 */
    v141 = plus2(v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    if (!(((int32_t)(stack[-4])) < ((int32_t)(v141)))) goto v148;
    v141 = stack[-1];
    v141 = qcdr(v141);
    stack[-1] = v141;
    goto v147;

v148:
    v141 = stack[-1];
    if (v141 == nil) goto v149;
    v142 = qvalue(elt(env, 4)); /* gv */
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcar(v141);
    v141 = *(Lisp_Object *)((char *)v142 + (CELL-TAG_VECTOR) + ((int32_t)v141/(16/CELL)));
    stack[-6] = v141;
    v141 = stack[-8];
    v141 = qcar(v141);
    v142 = qcdr(v141);
    v141 = stack[-6];
    v141 = qcar(v141);
    v141 = qcdr(v141);
    fn = elt(env, 15); /* gcdf!* */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    stack[-4] = v141;
    v141 = stack[-8];
    v141 = qcar(v141);
    v142 = qcdr(v141);
    v141 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    stack[-5] = v141;
    v141 = stack[-6];
    v141 = qcar(v141);
    v142 = qcdr(v141);
    v141 = stack[-4];
    fn = elt(env, 16); /* cdiv */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    stack[-4] = v141;
    v142 = stack[-8];
    v141 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    stack[-8] = v141;
    v142 = stack[-3];
    v141 = stack[-4];
    fn = elt(env, 17); /* pcmult */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    stack[-3] = v141;
    v142 = stack[-6];
    v141 = stack[-5];
    fn = elt(env, 17); /* pcmult */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    stack[-6] = v141;
    v141 = stack[-6];
    stack[-4] = qcdr(v141);
    v142 = stack[-7];
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcdr(v141);
    fn = elt(env, 18); /* dquot */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    fn = elt(env, 19); /* pdmult */
    v141 = (*qfn2(fn))(qenv(fn), stack[-4], v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    stack[-4] = v141;
    v141 = qvalue(elt(env, 5)); /* tred */
    if (v141 == nil) goto v150;
    v141 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    v141 = elt(env, 6); /* "r e d u c t i o n :  " */
    v141 = Lprinc(nil, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    v141 = stack[-7];
    v141 = Lprinc(nil, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    v141 = elt(env, 7); /* "/" */
    v141 = Lprinc(nil, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    v141 = stack[-1];
    v141 = qcar(v141);
    v141 = qcdr(v141);
    v141 = Lprinc(nil, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    v141 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    goto v150;

v150:
    v141 = qvalue(elt(env, 8)); /* stars */
    if (v141 == nil) goto v151;
    v141 = elt(env, 9); /* "*" */
    v141 = Lprinc(nil, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    goto v151;

v151:
    v141 = stack[0];
    v141 = (Lisp_Object)((int32_t)(v141) + 0x10);
    stack[0] = v141;
    v141 = stack[-8];
    v142 = qcdr(v141);
    v141 = stack[-4];
    fn = elt(env, 20); /* pdif */
    v141 = (*qfn2(fn))(qenv(fn), v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    stack[-8] = v141;
    goto v143;

v149:
    v141 = qvalue(elt(env, 3)); /* redtails */
    if (v141 == nil) goto v144;
    v32 = stack[-7];
    v141 = stack[-8];
    v141 = qcar(v141);
    v142 = qcdr(v141);
    v141 = stack[-3];
    v141 = acons(v32, v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    stack[-3] = v141;
    v141 = stack[-8];
    v141 = qcdr(v141);
    stack[-8] = v141;
    goto v143;

v144:
    v142 = qvalue(elt(env, 10)); /* reductions */
    v141 = stack[0];
    v141 = (Lisp_Object)(int32_t)((int32_t)v142 + (int32_t)v141 - TAG_FIXNUM);
    qvalue(elt(env, 10)) = v141; /* reductions */
    v141 = qvalue(elt(env, 11)); /* nforms */
    v141 = (Lisp_Object)((int32_t)(v141) + 0x10);
    qvalue(elt(env, 11)) = v141; /* nforms */
    v141 = stack[-3];
    v142 = Lnreverse(nil, v141);
    env = stack[-11];
    v141 = stack[-8];
    v141 = Lappend(nil, v142, v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    fn = elt(env, 21); /* gcdout */
    v141 = (*qfn1(fn))(qenv(fn), v141);
    nil = C_nil;
    if (exception_pending()) goto v101;
    env = stack[-11];
    stack[-4] = v141;
    v141 = stack[-4];
    if (!(v141 == nil)) goto v152;
    v141 = qvalue(elt(env, 12)); /* zeros */
    v141 = (Lisp_Object)((int32_t)(v141) + 0x10);
    qvalue(elt(env, 12)) = v141; /* zeros */
    goto v152;

v152:
    v141 = stack[-4];
    goto v13;

v13:
    qvalue(elt(env, 1)) = stack[-10]; /* gg */
    { popv(12); return onevalue(v141); }

v87:
    v141 = v142;
    goto v13;
/* error exit handlers */
v101:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-10]; /* gg */
    popv(12);
    return nil;
}



/* Code for safe!-modrecip */

static Lisp_Object CC_safeKmodrecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157, v158, v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for safe-modrecip");
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
    v158 = v0;
/* end of prologue */
    stack[-1] = qvalue(elt(env, 1)); /* !*msg */
    qvalue(elt(env, 1)) = nil; /* !*msg */
    stack[0] = qvalue(elt(env, 2)); /* !*protfg */
    qvalue(elt(env, 2)) = nil; /* !*protfg */
    v157 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v157; /* !*msg */
    v157 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v157; /* !*protfg */
    v159 = v158;
    v157 = elt(env, 5); /* !:mod!: */
    if (!consp(v159)) goto v160;
    v159 = qcar(v159);
    if (!(v159 == v157)) goto v160;
    v157 = v158;
    v157 = qcdr(v157);
    v158 = v157;
    goto v160;

v160:
    v157 = elt(env, 6); /* general!-modular!-reciprocal */
    v159 = list2(v157, v158);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    v158 = qvalue(elt(env, 3)); /* nil */
    v157 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 8); /* errorset */
    v157 = (*qfnn(fn))(qenv(fn), 3, v159, v158, v157);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    stack[-2] = v157;
    v157 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 7)) = v157; /* erfg!* */
    v157 = stack[-2];
    fn = elt(env, 9); /* errorp */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v139;
    env = stack[-3];
    if (v157 == nil) goto v161;
    v157 = qvalue(elt(env, 3)); /* nil */
    goto v4;

v4:
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    { popv(4); return onevalue(v157); }

v161:
    v157 = stack[-2];
    v157 = qcar(v157);
    goto v4;
/* error exit handlers */
v139:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[0]; /* !*protfg */
    qvalue(elt(env, 1)) = stack[-1]; /* !*msg */
    popv(4);
    return nil;
}



/* Code for ofsf_smupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v104, Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v138, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smupdknowl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smupdknowl");
#endif
    if (stack >= stacklimit)
    {
        push4(v31,v104,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v104,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v31;
    stack[-2] = v104;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v172:
    v65 = stack[-3];
    if (v65 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    v138 = stack[-4];
    v65 = elt(env, 2); /* and */
    if (v138 == v65) goto v122;
    v65 = stack[-3];
    v65 = qcar(v65);
    fn = elt(env, 4); /* ofsf_negateat */
    v65 = (*qfn1(fn))(qenv(fn), v65);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-6];
    goto v84;

v84:
    v138 = v65;
    v65 = stack[-3];
    v65 = qcdr(v65);
    stack[-3] = v65;
    v65 = stack[-1];
    fn = elt(env, 5); /* ofsf_at2ir */
    v65 = (*qfn2(fn))(qenv(fn), v138, v65);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-6];
    v64 = v65;
    v65 = v64;
    v138 = qcar(v65);
    v65 = stack[-2];
    v65 = Lassoc(nil, v138, v65);
    stack[-5] = v65;
    if (v65 == nil) goto v69;
    stack[0] = stack[-5];
    v65 = v64;
    v65 = qcdr(v65);
    v138 = qcar(v65);
    v65 = stack[-5];
    v65 = qcdr(v65);
    fn = elt(env, 6); /* ofsf_sminsert */
    v65 = (*qfn2(fn))(qenv(fn), v138, v65);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-6];
    fn = elt(env, 7); /* setcdr */
    v65 = (*qfn2(fn))(qenv(fn), stack[0], v65);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-6];
    v65 = stack[-5];
    v138 = qcdr(v65);
    v65 = elt(env, 3); /* false */
    if (!(v138 == v65)) goto v172;
    v65 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v65;
    v65 = elt(env, 3); /* false */
    stack[-2] = v65;
    goto v172;

v69:
    v138 = v64;
    v65 = stack[-2];
    v65 = cons(v138, v65);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-6];
    stack[-2] = v65;
    goto v172;

v122:
    v65 = stack[-3];
    v65 = qcar(v65);
    goto v84;
/* error exit handlers */
v173:
    popv(7);
    return nil;
}



/* Code for lto_almerge */

static Lisp_Object CC_lto_almerge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v183, v184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_almerge");
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
    v182 = v0;
/* end of prologue */

v185:
    v183 = v182;
    if (v183 == nil) goto v105;
    v183 = v182;
    v183 = qcdr(v183);
    if (v183 == nil) goto v186;
    v183 = v182;
    v183 = qcdr(v183);
    v183 = qcdr(v183);
    if (v183 == nil) goto v75;
    v183 = v182;
    stack[0] = qcar(v183);
    v183 = qcdr(v182);
    v182 = stack[-3];
    v182 = CC_lto_almerge(env, v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v182 = list2(stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v183 = stack[-3];
    stack[-3] = v183;
    goto v185;

v75:
    v183 = v182;
    v183 = qcdr(v183);
    v183 = qcar(v183);
    stack[-4] = v183;
    v182 = qcar(v182);
    stack[-2] = v182;
    goto v187;

v187:
    v182 = stack[-2];
    if (v182 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v182 = stack[-2];
    v182 = qcar(v182);
    v183 = v182;
    v182 = v183;
    v184 = qcar(v182);
    v182 = stack[-4];
    v182 = Lassoc(nil, v184, v182);
    v184 = v182;
    v182 = v184;
    if (v182 == nil) goto v164;
    stack[-1] = v184;
    stack[0] = stack[-3];
    v182 = v183;
    v182 = qcdr(v182);
    v183 = v184;
    v183 = qcdr(v183);
    v182 = list2(v182, v183);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    fn = elt(env, 2); /* apply */
    v182 = (*qfn2(fn))(qenv(fn), stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    fn = elt(env, 3); /* setcdr */
    v182 = (*qfn2(fn))(qenv(fn), stack[-1], v182);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    goto v188;

v188:
    v182 = stack[-2];
    v182 = qcdr(v182);
    stack[-2] = v182;
    goto v187;

v164:
    v182 = stack[-4];
    v182 = cons(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-4] = v182;
    goto v188;

v186:
    v182 = qcar(v182);
    { popv(6); return onevalue(v182); }

v105:
    v182 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v182); }
/* error exit handlers */
v134:
    popv(6);
    return nil;
}



/* Code for prepreform1 */

static Lisp_Object CC_prepreform1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepreform1");
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
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */

v185:
    v45 = stack[0];
    if (!consp(v45)) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v45 = stack[0];
    v121 = qcar(v45);
    v45 = elt(env, 1); /* dname */
    v45 = get(v121, v45);
    env = stack[-7];
    if (!(v45 == nil)) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    stack[-6] = nil;
    v45 = stack[-5];
    stack[-1] = v45;
    goto v171;

v171:
    v45 = stack[-6];
    if (!(v45 == nil)) goto v106;
    v45 = stack[-1];
    if (v45 == nil) goto v106;
    v45 = stack[-1];
    v121 = qcar(v45);
    v45 = stack[0];
    v45 = qcdr(v45);
    v45 = Lsmemq(nil, v121, v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    if (v45 == nil) goto v158;
    v45 = qvalue(elt(env, 3)); /* t */
    stack[-6] = v45;
    goto v171;

v158:
    v45 = stack[-1];
    v45 = qcdr(v45);
    stack[-1] = v45;
    goto v171;

v106:
    v45 = stack[-6];
    if (v45 == nil) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v45 = stack[0];
    v121 = qcar(v45);
    v45 = elt(env, 4); /* (plus difference minus times quotient) */
    v45 = Lmemq(nil, v121, v45);
    if (!(v45 == nil)) goto v72;
    v45 = stack[0];
    v121 = qcar(v45);
    v45 = elt(env, 5); /* simpfn */
    v45 = get(v121, v45);
    env = stack[-7];
    if (!(v45 == nil)) goto v70;

v72:
    v45 = qvalue(elt(env, 2)); /* nil */
    stack[-6] = v45;
    goto v70;

v70:
    v45 = stack[0];
    v121 = qcar(v45);
    v45 = elt(env, 6); /* !*sq */
    if (v121 == v45) goto v201;
    v45 = stack[0];
    stack[-4] = qcar(v45);
    v45 = stack[0];
    v45 = qcdr(v45);
    stack[-3] = v45;
    v45 = stack[-3];
    if (v45 == nil) goto v202;
    v45 = stack[-3];
    v45 = qcar(v45);
    v121 = v45;
    v45 = stack[-6];
    if (v45 == nil) goto v203;
    v45 = v121;
    fn = elt(env, 7); /* simp!* */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    fn = elt(env, 8); /* sqhorner!* */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    fn = elt(env, 9); /* prepsq!* */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    v121 = v45;
    goto v88;

v88:
    v45 = stack[-5];
    v45 = CC_prepreform1(env, v121, v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    stack[-1] = v45;
    stack[-2] = v45;
    goto v204;

v204:
    v45 = stack[-3];
    v45 = qcdr(v45);
    stack[-3] = v45;
    v45 = stack[-3];
    if (v45 == nil) goto v49;
    stack[0] = stack[-1];
    v45 = stack[-3];
    v45 = qcar(v45);
    v121 = v45;
    v45 = stack[-6];
    if (v45 == nil) goto v123;
    v45 = v121;
    fn = elt(env, 7); /* simp!* */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    fn = elt(env, 8); /* sqhorner!* */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    fn = elt(env, 9); /* prepsq!* */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    v121 = v45;
    goto v205;

v205:
    v45 = stack[-5];
    v45 = CC_prepreform1(env, v121, v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    v45 = Lrplacd(nil, stack[0], v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    v45 = stack[-1];
    v45 = qcdr(v45);
    stack[-1] = v45;
    goto v204;

v123:
    v45 = v121;
    v121 = v45;
    goto v205;

v49:
    v45 = stack[-2];
    goto v176;

v176:
    {
        Lisp_Object v117 = stack[-4];
        popv(8);
        return cons(v117, v45);
    }

v203:
    v45 = v121;
    v121 = v45;
    goto v88;

v202:
    v45 = qvalue(elt(env, 2)); /* nil */
    goto v176;

v201:
    v45 = stack[0];
    v45 = qcdr(v45);
    v45 = qcar(v45);
    fn = elt(env, 8); /* sqhorner!* */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    fn = elt(env, 9); /* prepsq!* */
    v121 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-7];
    v45 = stack[-5];
    stack[0] = v121;
    stack[-5] = v45;
    goto v185;
/* error exit handlers */
v200:
    popv(8);
    return nil;
}



/* Code for formclis */

static Lisp_Object MS_CDECL CC_formclis(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v104, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v207, v156, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formclis");
#endif
    if (stack >= stacklimit)
    {
        push3(v104,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v104);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v104;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v13;

v13:
    v207 = stack[-2];
    if (v207 == nil) goto v208;
    v207 = stack[-2];
    v83 = qcar(v207);
    v156 = stack[-1];
    v207 = stack[0];
    fn = elt(env, 1); /* formc */
    v156 = (*qfnn(fn))(qenv(fn), 3, v83, v156, v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    v207 = stack[-3];
    v207 = cons(v156, v207);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-4];
    stack[-3] = v207;
    v207 = stack[-2];
    v207 = qcdr(v207);
    stack[-2] = v207;
    goto v13;

v208:
    v207 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* reversip!* */
        return (*qfn1(fn))(qenv(fn), v207);
    }
/* error exit handlers */
v209:
    popv(5);
    return nil;
}



/* Code for cgb_buch!-ev_divides!? */

static Lisp_Object CC_cgb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgb_buch-ev_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v172 = v1;
    v87 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v172, v87);
    }
}



/* Code for unaryir */

static Lisp_Object CC_unaryir(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unaryir");
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
    v154 = qvalue(elt(env, 1)); /* atts */
    v153 = elt(env, 2); /* name */
    fn = elt(env, 4); /* find */
    v153 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v153 = Lintern(nil, v153);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    stack[-2] = v153;
    v154 = qvalue(elt(env, 1)); /* atts */
    v153 = elt(env, 3); /* cd */
    fn = elt(env, 4); /* find */
    v153 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v153 = Lintern(nil, v153);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-3];
    v154 = v153;
    v153 = stack[-1];
    if (equal(v154, v153)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v153 = stack[-2];
    {
        popv(4);
        fn = elt(env, 5); /* encodeir */
        return (*qfn1(fn))(qenv(fn), v153);
    }
/* error exit handlers */
v146:
    popv(4);
    return nil;
}



/* Code for n_nary */

static Lisp_Object CC_n_nary(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for n_nary");
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
    v72 = qcar(v74);
    v74 = elt(env, 1); /* e */
    if (!(v72 == v74)) goto v210;
    v72 = stack[0];
    v74 = elt(env, 2); /* power */
    if (!(v72 == v74)) goto v210;
    v74 = stack[-1];
    v72 = qcdr(v74);
    v74 = elt(env, 3); /* exp */
    fn = elt(env, 9); /* unary */
    v74 = (*qfn2(fn))(qenv(fn), v72, v74);
    nil = C_nil;
    if (exception_pending()) goto v214;
    goto v4;

v4:
    v74 = nil;
    { popv(3); return onevalue(v74); }

v210:
    v74 = elt(env, 4); /* "<apply>" */
    fn = elt(env, 10); /* printout */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    v74 = elt(env, 5); /* "<" */
    v74 = Lprinc(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    v74 = stack[0];
    v74 = Lprinc(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    v74 = elt(env, 6); /* "/>" */
    v74 = Lprinc(nil, v74);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    v72 = qvalue(elt(env, 7)); /* indent */
    v74 = (Lisp_Object)49; /* 3 */
    v74 = plus2(v72, v74);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    qvalue(elt(env, 7)) = v74; /* indent */
    v74 = stack[-1];
    fn = elt(env, 11); /* multi_elem */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    v72 = qvalue(elt(env, 7)); /* indent */
    v74 = (Lisp_Object)49; /* 3 */
    v74 = difference2(v72, v74);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-2];
    qvalue(elt(env, 7)) = v74; /* indent */
    v74 = elt(env, 8); /* "</apply>" */
    fn = elt(env, 10); /* printout */
    v74 = (*qfn1(fn))(qenv(fn), v74);
    nil = C_nil;
    if (exception_pending()) goto v214;
    goto v4;
/* error exit handlers */
v214:
    popv(3);
    return nil;
}



/* Code for testpr */

static Lisp_Object MS_CDECL CC_testpr(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v104, Lisp_Object v31, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v203, v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "testpr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testpr");
#endif
    if (stack >= stacklimit)
    {
        push4(v31,v104,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v104,v31);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v31;
    stack[-6] = v104;
    stack[0] = v1;
    v131 = v0;
/* end of prologue */
    stack[-3] = nil;
    v203 = qvalue(elt(env, 1)); /* jsi */
    stack[-2] = v203;
    stack[-1] = qvalue(elt(env, 2)); /* codmat */
    v203 = qvalue(elt(env, 3)); /* maxvar */
    v131 = plus2(v203, v131);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-8];
    v203 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v131/(16/CELL)));
    v131 = (Lisp_Object)65; /* 4 */
    v131 = *(Lisp_Object *)((char *)v203 + (CELL-TAG_VECTOR) + ((int32_t)v131/(16/CELL)));
    stack[-7] = v131;
    stack[-1] = qvalue(elt(env, 2)); /* codmat */
    v203 = qvalue(elt(env, 3)); /* maxvar */
    v131 = stack[0];
    v131 = plus2(v203, v131);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-8];
    v203 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v131/(16/CELL)));
    v131 = (Lisp_Object)65; /* 4 */
    v131 = *(Lisp_Object *)((char *)v203 + (CELL-TAG_VECTOR) + ((int32_t)v131/(16/CELL)));
    stack[-4] = v131;
    goto v211;

v211:
    v131 = stack[-2];
    if (v131 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v131 = stack[-7];
    if (v131 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    v131 = stack[-2];
    v203 = qcar(v131);
    stack[-1] = v203;
    v131 = stack[-7];
    v131 = qcar(v131);
    v131 = qcar(v131);
    v224 = v131;
    if (equal(v203, v131)) goto v196;
    v131 = stack[-1];
    v203 = v224;
    v131 = (Lisp_Object)greaterp2(v131, v203);
    nil = C_nil;
    if (exception_pending()) goto v225;
    v131 = v131 ? lisp_true : nil;
    env = stack[-8];
    if (v131 == nil) goto v226;
    v131 = stack[-7];
    v131 = qcdr(v131);
    stack[-7] = v131;
    goto v211;

v226:
    v131 = stack[-2];
    v131 = qcdr(v131);
    stack[-2] = v131;
    goto v211;

v196:
    v203 = stack[-1];
    v131 = stack[-4];
    fn = elt(env, 5); /* pnthxzz */
    v131 = (*qfn2(fn))(qenv(fn), v203, v131);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-8];
    stack[-4] = v131;
    v131 = stack[-7];
    v131 = qcar(v131);
    v131 = qcdr(v131);
    v203 = qcar(v131);
    v131 = stack[-5];
    fn = elt(env, 6); /* dm!-times */
    stack[0] = (*qfn2(fn))(qenv(fn), v203, v131);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-8];
    v131 = stack[-4];
    v131 = qcar(v131);
    v131 = qcdr(v131);
    v203 = qcar(v131);
    v131 = stack[-6];
    fn = elt(env, 6); /* dm!-times */
    v131 = (*qfn2(fn))(qenv(fn), v203, v131);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-8];
    fn = elt(env, 7); /* dm!-difference */
    v131 = (*qfn2(fn))(qenv(fn), stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-8];
    fn = elt(env, 8); /* zeropp */
    v131 = (*qfn1(fn))(qenv(fn), v131);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-8];
    if (v131 == nil) goto v71;
    v203 = stack[-1];
    v131 = stack[-3];
    v131 = cons(v203, v131);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-8];
    stack[-3] = v131;
    goto v71;

v71:
    v131 = stack[-2];
    v131 = qcdr(v131);
    stack[-2] = v131;
    v131 = stack[-7];
    v131 = qcdr(v131);
    stack[-7] = v131;
    goto v211;
/* error exit handlers */
v225:
    popv(9);
    return nil;
}



/* Code for treesizep */

static Lisp_Object CC_treesizep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for treesizep");
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
    v116 = v1;
    v120 = v0;
/* end of prologue */
    fn = elt(env, 1); /* treesizep1 */
    v120 = (*qfn2(fn))(qenv(fn), v120, v116);
    errexit();
    v116 = (Lisp_Object)1; /* 0 */
    v116 = (v120 == v116 ? lisp_true : nil);
    return onevalue(v116);
}



/* Code for convprc2 */

static Lisp_Object CC_convprc2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v229, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convprc2");
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
    v164 = stack[-1];
    fn = elt(env, 4); /* convprec */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    stack[-1] = v164;
    v164 = stack[0];
    fn = elt(env, 4); /* convprec */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    qvalue(elt(env, 1)) = v164; /* yy!! */
    v164 = qvalue(elt(env, 2)); /* !*roundbf */
    if (v164 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v164 = qvalue(elt(env, 1)); /* yy!! */
    v229 = v164;
    v229 = Lfloatp(nil, v229);
    env = stack[-2];
    if (v229 == nil) goto v124;
    fn = elt(env, 5); /* fl2bf */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    goto v186;

v186:
    qvalue(elt(env, 1)) = v164; /* yy!! */
    v164 = stack[-1];
    v164 = Lfloatp(nil, v164);
    env = stack[-2];
    if (v164 == nil) goto v169;
    v164 = stack[-1];
    {
        popv(3);
        fn = elt(env, 5); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v164);
    }

v169:
    v164 = stack[-1];
    if (!consp(v164)) goto v230;
    v164 = stack[-1];
    goto v140;

v140:
    {
        popv(3);
        fn = elt(env, 6); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v164);
    }

v230:
    v164 = stack[-1];
    v164 = integerp(v164);
    if (v164 == nil) goto v231;
    v220 = elt(env, 3); /* !:rd!: */
    v229 = stack[-1];
    v164 = (Lisp_Object)1; /* 0 */
    v164 = list2star(v220, v229, v164);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    goto v140;

v231:
    v164 = stack[-1];
    fn = elt(env, 7); /* read!:num */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    goto v140;

v124:
    v229 = v164;
    if (!(!consp(v229))) goto v107;
    v229 = v164;
    v229 = integerp(v229);
    if (v229 == nil) goto v170;
    v220 = elt(env, 3); /* !:rd!: */
    v229 = v164;
    v164 = (Lisp_Object)1; /* 0 */
    v164 = list2star(v220, v229, v164);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    goto v107;

v107:
    fn = elt(env, 6); /* csl_normbf */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    goto v186;

v170:
    fn = elt(env, 7); /* read!:num */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    goto v107;
/* error exit handlers */
v71:
    popv(3);
    return nil;
}



/* Code for repeats */

static Lisp_Object CC_repeats(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v154, v77, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repeats");
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
    v78 = nil;
    goto v20;

v20:
    v154 = stack[0];
    if (v154 == nil) goto v227;
    v154 = stack[0];
    v77 = qcar(v154);
    v154 = stack[0];
    v154 = qcdr(v154);
    v154 = Lmember(nil, v77, v154);
    if (v154 == nil) goto v207;
    v154 = stack[0];
    v154 = qcar(v154);
    v77 = v78;
    v154 = cons(v154, v77);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-1];
    v78 = v154;
    v154 = stack[0];
    v154 = qcdr(v154);
    stack[0] = v154;
    goto v20;

v207:
    v154 = stack[0];
    v154 = qcdr(v154);
    stack[0] = v154;
    goto v20;

v227:
    v154 = v78;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v154);
    }
/* error exit handlers */
v146:
    popv(2);
    return nil;
}



/* Code for edges_parents */

static Lisp_Object CC_edges_parents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for edges_parents");
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
    v76 = stack[0];
    if (v76 == nil) goto v38;
    v76 = stack[0];
    v76 = qcar(v76);
    fn = elt(env, 2); /* edge_new_parents */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    stack[-1] = v76;
    v76 = stack[0];
    v76 = qcdr(v76);
    v76 = CC_edges_parents(env, v76);
    nil = C_nil;
    if (exception_pending()) goto v112;
    {
        Lisp_Object v106 = stack[-1];
        popv(3);
        return Lappend(nil, v106, v76);
    }

v38:
    v76 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v76); }
/* error exit handlers */
v112:
    popv(3);
    return nil;
}



/* Code for red!=hidelt */

static Lisp_Object CC_redMhidelt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=hidelt");
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
    v171 = stack[-2];
    fn = elt(env, 1); /* bas_dpoly */
    v171 = (*qfn1(fn))(qenv(fn), v171);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    stack[-3] = v171;
    v171 = stack[-2];
    fn = elt(env, 2); /* bas_nr */
    stack[-1] = (*qfn1(fn))(qenv(fn), v171);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v171 = stack[-3];
    stack[0] = qcdr(v171);
    v171 = stack[-2];
    fn = elt(env, 3); /* bas_rep */
    stack[-2] = (*qfn1(fn))(qenv(fn), v171);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    v171 = stack[-3];
    v171 = qcar(v171);
    v171 = ncons(v171);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    fn = elt(env, 4); /* red!=hide */
    v171 = (*qfn1(fn))(qenv(fn), v171);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    fn = elt(env, 5); /* dp_sum */
    v171 = (*qfn2(fn))(qenv(fn), stack[-2], v171);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-4];
    {
        Lisp_Object v210 = stack[-1];
        Lisp_Object v207 = stack[0];
        popv(5);
        fn = elt(env, 6); /* bas_make1 */
        return (*qfnn(fn))(qenv(fn), 3, v210, v207, v171);
    }
/* error exit handlers */
v187:
    popv(5);
    return nil;
}



/* Code for insert */

static Lisp_Object CC_insert(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v104)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v232, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert");
#endif
    if (stack >= stacklimit)
    {
        push2(v104,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v104);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v232 = v104;
    stack[-1] = v1;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v232; /* gg */
    stack[0] = nil;
    goto v91;

v91:
    v232 = qvalue(elt(env, 1)); /* gg */
    if (v232 == nil) goto v145;
    v232 = stack[-1];
    v211 = qcdr(v232);
    v232 = qvalue(elt(env, 1)); /* gg */
    v232 = qcar(v232);
    v232 = qcdr(v232);
    fn = elt(env, 3); /* dless */
    v232 = (*qfn2(fn))(qenv(fn), v211, v232);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    if (v232 == nil) goto v145;
    v232 = qvalue(elt(env, 1)); /* gg */
    v211 = qcar(v232);
    v232 = stack[0];
    v232 = cons(v211, v232);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    stack[0] = v232;
    v232 = qvalue(elt(env, 1)); /* gg */
    v232 = qcdr(v232);
    qvalue(elt(env, 1)) = v232; /* gg */
    goto v91;

v145:
    v232 = stack[0];
    stack[0] = Lnreverse(nil, v232);
    env = stack[-3];
    v211 = stack[-1];
    v232 = qvalue(elt(env, 1)); /* gg */
    v232 = cons(v211, v232);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    v232 = Lappend(nil, stack[0], v232);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* gg */
    { popv(4); return onevalue(v232); }
/* error exit handlers */
v74:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* gg */
    popv(4);
    return nil;
}



/* Code for nonlnrsys */

static Lisp_Object CC_nonlnrsys(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v206;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonlnrsys");
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

v185:
    v160 = stack[-1];
    if (v160 == nil) goto v20;
    v160 = stack[-1];
    v206 = qcar(v160);
    v160 = stack[0];
    fn = elt(env, 2); /* nonlnr */
    v160 = (*qfn2(fn))(qenv(fn), v206, v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-2];
    if (!(v160 == nil)) { popv(3); return onevalue(v160); }
    v160 = stack[-1];
    v206 = qcdr(v160);
    v160 = stack[0];
    stack[-1] = v206;
    stack[0] = v160;
    goto v185;

v20:
    v160 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v160); }
/* error exit handlers */
v207:
    popv(3);
    return nil;
}



/* Code for horner!-rule!-for!-one!-var */

static Lisp_Object MS_CDECL CC_hornerKruleKforKoneKvar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v104, Lisp_Object v31,
                         Lisp_Object v38, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204, v134, v135, v234, v216, v202, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "horner-rule-for-one-var");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule-for-one-var");
#endif
    if (stack >= stacklimit)
    {
        push5(v38,v31,v104,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v104,v31,v38);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v134 = v38;
    v135 = v31;
    v234 = v104;
    v216 = v1;
    v202 = v0;
/* end of prologue */

v185:
    v204 = v202;
    if (!consp(v204)) goto v227;
    v204 = v202;
    v204 = qcar(v204);
    if (!consp(v204)) goto v227;
    v204 = v202;
    v204 = qcar(v204);
    v204 = qcar(v204);
    v235 = qcar(v204);
    v204 = v216;
    if (!(equal(v235, v204))) goto v227;
    v204 = v202;
    v204 = qcar(v204);
    v204 = qcar(v204);
    v204 = qcdr(v204);
    stack[-5] = v204;
    v204 = v202;
    stack[-4] = qcdr(v204);
    stack[-3] = v216;
    stack[-2] = v234;
    v204 = v234;
    v204 = (Lisp_Object)zerop(v204);
    v204 = v204 ? lisp_true : nil;
    env = stack[-6];
    if (v204 == nil) goto v67;
    v204 = v202;
    v204 = qcar(v204);
    v204 = qcdr(v204);
    v134 = v204;
    goto v167;

v167:
    v204 = stack[-5];
    v202 = stack[-4];
    v216 = stack[-3];
    v234 = stack[-2];
    v135 = v134;
    v134 = v204;
    goto v185;

v67:
    v204 = v202;
    v204 = qcar(v204);
    stack[-1] = qcdr(v204);
    stack[0] = v135;
    v135 = v234;
    v204 = stack[-5];
    v204 = (Lisp_Object)(int32_t)((int32_t)v134 - (int32_t)v204 + TAG_FIXNUM);
    v204 = Lexpt(nil, v135, v204);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-6];
    fn = elt(env, 1); /* !*n2f */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-6];
    fn = elt(env, 2); /* multf */
    v204 = (*qfn2(fn))(qenv(fn), stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-6];
    fn = elt(env, 3); /* addf */
    v204 = (*qfn2(fn))(qenv(fn), stack[-1], v204);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-6];
    v134 = v204;
    goto v167;

v227:
    v204 = v234;
    v204 = (Lisp_Object)zerop(v204);
    v204 = v204 ? lisp_true : nil;
    env = stack[-6];
    if (!(v204 == nil)) { popv(7); return onevalue(v202); }
    stack[-1] = v202;
    stack[0] = v135;
    v204 = v234;
    v204 = Lexpt(nil, v204, v134);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-6];
    fn = elt(env, 1); /* !*n2f */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-6];
    fn = elt(env, 2); /* multf */
    v204 = (*qfn2(fn))(qenv(fn), stack[0], v204);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-6];
    {
        Lisp_Object v132 = stack[-1];
        popv(7);
        fn = elt(env, 3); /* addf */
        return (*qfn2(fn))(qenv(fn), v132, v204);
    }
/* error exit handlers */
v60:
    popv(7);
    return nil;
}



/* Code for cnrd */

static Lisp_Object MS_CDECL CC_cnrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v46, v243;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cnrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cnrd");
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
    v46 = qvalue(elt(env, 2)); /* atts */
    v121 = elt(env, 3); /* type */
    fn = elt(env, 16); /* find */
    v121 = (*qfn2(fn))(qenv(fn), v46, v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    v121 = Lintern(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    stack[-1] = v121;
    v46 = qvalue(elt(env, 2)); /* atts */
    v121 = elt(env, 4); /* base */
    fn = elt(env, 16); /* find */
    v121 = (*qfn2(fn))(qenv(fn), v46, v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    stack[0] = v121;
    fn = elt(env, 17); /* lex */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    v121 = qvalue(elt(env, 5)); /* char */
    stack[-4] = v121;
    fn = elt(env, 17); /* lex */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    v46 = stack[-1];
    v121 = elt(env, 6); /* constant */
    if (v46 == v121) goto v155;
    v121 = stack[-1];
    if (v121 == nil) goto v146;
    v46 = stack[-1];
    v121 = elt(env, 7); /* (real integer) */
    v121 = Lmember(nil, v46, v121);
    if (v121 == nil) goto v244;
    v121 = stack[0];
    if (v121 == nil) goto v245;
    stack[-3] = elt(env, 8); /* based_integer */
    stack[-2] = qvalue(elt(env, 1)); /* nil */
    stack[-1] = stack[0];
    stack[0] = elt(env, 9); /* string */
    v121 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v46 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    v121 = qvalue(elt(env, 1)); /* nil */
    v46 = list2star(stack[0], v46, v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    v121 = qvalue(elt(env, 1)); /* nil */
    v121 = list2star(stack[-1], v46, v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    {
        Lisp_Object v117 = stack[-3];
        Lisp_Object v118 = stack[-2];
        popv(6);
        return list2star(v117, v118, v121);
    }

v245:
    v121 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v121);
    }

v244:
    v121 = stack[-1];
    v46 = Lintern(nil, v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    v121 = elt(env, 10); /* (rational complex!-cartesian complex!-polar) 
*/
    v121 = Lmember(nil, v46, v121);
    if (v121 == nil) goto v65;
    fn = elt(env, 19); /* seprd */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    stack[-2] = v121;
    v46 = stack[-1];
    v121 = elt(env, 11); /* rational */
    if (v46 == v121) goto v175;
    v46 = stack[-1];
    v121 = elt(env, 12); /* complex!-cartesian */
    if (v46 == v121) goto v246;
    v46 = stack[-1];
    v121 = elt(env, 14); /* complex!-polar */
    if (!(v46 == v121)) goto v65;
    fn = elt(env, 17); /* lex */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    stack[-1] = elt(env, 15); /* complex_polar */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v121 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v243 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    v46 = stack[-2];
    v121 = qvalue(elt(env, 1)); /* nil */
    v121 = list2star(v243, v46, v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    {
        Lisp_Object v247 = stack[-1];
        Lisp_Object v248 = stack[0];
        popv(6);
        return list2star(v247, v248, v121);
    }

v65:
    v121 = nil;
    { popv(6); return onevalue(v121); }

v246:
    fn = elt(env, 17); /* lex */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    stack[-1] = elt(env, 13); /* complex_cartesian */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v121 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v243 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    v46 = stack[-2];
    v121 = qvalue(elt(env, 1)); /* nil */
    v121 = list2star(v243, v46, v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    {
        Lisp_Object v249 = stack[-1];
        Lisp_Object v250 = stack[0];
        popv(6);
        return list2star(v249, v250, v121);
    }

v175:
    fn = elt(env, 17); /* lex */
    v121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    v121 = stack[-4];
    fn = elt(env, 18); /* compress!* */
    v46 = (*qfn1(fn))(qenv(fn), v121);
    nil = C_nil;
    if (exception_pending()) goto v200;
    env = stack[-5];
    v121 = stack[-2];
    {
        popv(6);
        fn = elt(env, 11); /* rational */
        return (*qfn2(fn))(qenv(fn), v46, v121);
    }

v146:
    v121 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v121);
    }

v155:
    v121 = stack[-4];
    {
        popv(6);
        fn = elt(env, 18); /* compress!* */
        return (*qfn1(fn))(qenv(fn), v121);
    }
/* error exit handlers */
v200:
    popv(6);
    return nil;
}



/* Code for rootextractsq */

static Lisp_Object CC_rootextractsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rootextractsq");
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
    v112 = v0;
/* end of prologue */
    v107 = v112;
    v107 = qcar(v107);
    if (v107 == nil) { popv(3); return onevalue(v112); }
    v107 = v112;
    fn = elt(env, 1); /* subs2q */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-2];
    stack[-1] = v107;
    v107 = stack[-1];
    v107 = qcar(v107);
    fn = elt(env, 2); /* rootextractf */
    stack[0] = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-2];
    v107 = stack[-1];
    v107 = qcdr(v107);
    fn = elt(env, 2); /* rootextractf */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v143;
    {
        Lisp_Object v155 = stack[0];
        popv(3);
        return cons(v155, v107);
    }
/* error exit handlers */
v143:
    popv(3);
    return nil;
}



/* Code for dipnumcontent */

static Lisp_Object CC_dipnumcontent(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipnumcontent");
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

v4:
    v206 = stack[0];
    fn = elt(env, 1); /* bcone!? */
    v206 = (*qfn1(fn))(qenv(fn), v206);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    if (!(v206 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v206 = stack[-1];
    if (v206 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v206 = stack[-1];
    v206 = qcdr(v206);
    v206 = qcdr(v206);
    stack[-2] = v206;
    v187 = stack[0];
    v206 = stack[-1];
    v206 = qcdr(v206);
    v206 = qcar(v206);
    fn = elt(env, 2); /* vbcgcd */
    v206 = (*qfn2(fn))(qenv(fn), v187, v206);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    stack[0] = v206;
    v206 = stack[-2];
    stack[-1] = v206;
    goto v4;
/* error exit handlers */
v83:
    popv(4);
    return nil;
}



/* Code for xriterion_1 */

static Lisp_Object MS_CDECL CC_xriterion_1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v104, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v254, v255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xriterion_1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xriterion_1");
#endif
    if (stack >= stacklimit)
    {
        push3(v104,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v104);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v104;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v185:
    v193 = stack[-1];
    if (v193 == nil) goto v4;
    v193 = stack[-2];
    v193 = qcdr(v193);
    v254 = qcar(v193);
    v193 = elt(env, 2); /* spoly_pair */
    if (v254 == v193) goto v124;
    v193 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v193); }

v124:
    v193 = stack[-1];
    v193 = qcar(v193);
    stack[-3] = v193;
    v254 = stack[-3];
    v193 = stack[-2];
    v193 = qcdr(v193);
    v193 = qcdr(v193);
    v193 = qcar(v193);
    if (equal(v254, v193)) goto v160;
    v254 = stack[-3];
    v193 = stack[-2];
    v193 = qcdr(v193);
    v193 = qcdr(v193);
    v193 = qcdr(v193);
    v193 = qcar(v193);
    if (equal(v254, v193)) goto v145;
    v193 = stack[-3];
    fn = elt(env, 7); /* xval */
    v254 = (*qfn1(fn))(qenv(fn), v193);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v193 = stack[-2];
    v193 = qcar(v193);
    fn = elt(env, 8); /* xdiv */
    v193 = (*qfn2(fn))(qenv(fn), v254, v193);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    if (v193 == nil) goto v139;
    v254 = stack[-3];
    v193 = stack[-2];
    v193 = qcdr(v193);
    v193 = qcdr(v193);
    v193 = qcar(v193);
    fn = elt(env, 9); /* make_spoly_pair */
    v193 = (*qfn2(fn))(qenv(fn), v254, v193);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v254 = v193;
    v193 = v254;
    v193 = (v193 == nil ? lisp_true : nil);
    if (!(v193 == nil)) goto v136;
    v193 = stack[0];
    fn = elt(env, 10); /* find_item */
    v193 = (*qfn2(fn))(qenv(fn), v254, v193);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v193 = (v193 == nil ? lisp_true : nil);
    goto v136;

v136:
    if (v193 == nil) goto v256;
    v254 = stack[-3];
    v193 = stack[-2];
    v193 = qcdr(v193);
    v193 = qcdr(v193);
    v193 = qcdr(v193);
    v193 = qcar(v193);
    fn = elt(env, 9); /* make_spoly_pair */
    v193 = (*qfn2(fn))(qenv(fn), v254, v193);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v254 = v193;
    v193 = v254;
    v193 = (v193 == nil ? lisp_true : nil);
    if (!(v193 == nil)) goto v257;
    v193 = stack[0];
    fn = elt(env, 10); /* find_item */
    v193 = (*qfn2(fn))(qenv(fn), v254, v193);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    v193 = (v193 == nil ? lisp_true : nil);
    goto v257;

v257:
    if (v193 == nil) goto v163;
    v193 = qvalue(elt(env, 3)); /* !*trxideal */
    if (v193 == nil) goto v235;
    v254 = elt(env, 4); /* "criterion 1 hit" */
    v193 = elt(env, 5); /* last */
    fn = elt(env, 11); /* writepri */
    v193 = (*qfn2(fn))(qenv(fn), v254, v193);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    goto v235;

v235:
    v193 = qvalue(elt(env, 6)); /* t */
    goto v155;

v155:
    if (!(v193 == nil)) { popv(5); return onevalue(v193); }
    v255 = stack[-2];
    v193 = stack[-1];
    v254 = qcdr(v193);
    v193 = stack[0];
    stack[-2] = v255;
    stack[-1] = v254;
    stack[0] = v193;
    goto v185;

v163:
    v193 = qvalue(elt(env, 1)); /* nil */
    goto v155;

v256:
    v193 = qvalue(elt(env, 1)); /* nil */
    goto v155;

v139:
    v193 = qvalue(elt(env, 1)); /* nil */
    goto v155;

v145:
    v193 = qvalue(elt(env, 1)); /* nil */
    goto v155;

v160:
    v193 = qvalue(elt(env, 1)); /* nil */
    goto v155;

v4:
    v193 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v193); }
/* error exit handlers */
v225:
    popv(5);
    return nil;
}



/* Code for !:dmtimeslst */

static Lisp_Object CC_Tdmtimeslst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmtimeslst");
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
    v106 = v0;
/* end of prologue */
    v112 = v106;
    if (v112 == nil) goto v38;
    v112 = v106;
    v112 = qcdr(v112);
    if (v112 == nil) goto v227;
    v112 = v106;
    stack[0] = qcar(v112);
    v112 = v106;
    v112 = qcdr(v112);
    v112 = CC_Tdmtimeslst(env, v112);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-1];
    {
        Lisp_Object v155 = stack[0];
        popv(2);
        fn = elt(env, 1); /* !:times */
        return (*qfn2(fn))(qenv(fn), v155, v112);
    }

v227:
    v112 = v106;
    v112 = qcar(v112);
    { popv(2); return onevalue(v112); }

v38:
    v112 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v112); }
/* error exit handlers */
v143:
    popv(2);
    return nil;
}



/* Code for getphystypetimes */

static Lisp_Object CC_getphystypetimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypetimes");
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
    stack[-1] = qvalue(elt(env, 1)); /* nil */
    v78 = stack[0];
    fn = elt(env, 3); /* collectphystype */
    v78 = (*qfn1(fn))(qenv(fn), v78);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    fn = elt(env, 4); /* deleteall */
    v78 = (*qfn2(fn))(qenv(fn), stack[-1], v78);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    v209 = v78;
    if (v78 == nil) goto v13;
    v78 = v209;
    v78 = qcdr(v78);
    if (v78 == nil) goto v120;
    stack[-1] = elt(env, 0); /* getphystypetimes */
    v209 = elt(env, 2); /* "PHYSOP type mismatch in" */
    v78 = stack[0];
    v78 = list2(v209, v78);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-2];
    fn = elt(env, 5); /* rederr2 */
    v78 = (*qfn2(fn))(qenv(fn), stack[-1], v78);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v78 = nil;
    { popv(3); return onevalue(v78); }

v120:
    v78 = v209;
    v78 = qcar(v78);
    { popv(3); return onevalue(v78); }

v13:
    v78 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v78); }
/* error exit handlers */
v170:
    popv(3);
    return nil;
}



/* Code for bas_newnumber */

static Lisp_Object CC_bas_newnumber(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v91;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bas_newnumber");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v172 = v1;
    v91 = v0;
/* end of prologue */
    v172 = qcdr(v172);
    return cons(v91, v172);
}



/* Code for pcdiv */

static Lisp_Object CC_pcdiv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v197;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pcdiv");
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
    stack[-4] = v1;
    v166 = v0;
/* end of prologue */
    stack[-5] = v166;
    v166 = stack[-5];
    if (v166 == nil) goto v172;
    v166 = stack[-5];
    v166 = qcar(v166);
    v197 = v166;
    v166 = v197;
    stack[0] = qcar(v166);
    v166 = v197;
    v197 = qcdr(v166);
    v166 = stack[-4];
    fn = elt(env, 2); /* cdiv */
    v166 = (*qfn2(fn))(qenv(fn), v197, v166);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v166 = cons(stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    stack[-2] = v166;
    stack[-3] = v166;
    goto v227;

v227:
    v166 = stack[-5];
    v166 = qcdr(v166);
    stack[-5] = v166;
    v166 = stack[-5];
    if (v166 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v166 = stack[-5];
    v166 = qcar(v166);
    v197 = v166;
    v166 = v197;
    stack[0] = qcar(v166);
    v166 = v197;
    v197 = qcdr(v166);
    v166 = stack[-4];
    fn = elt(env, 2); /* cdiv */
    v166 = (*qfn2(fn))(qenv(fn), v197, v166);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v166 = cons(stack[0], v166);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v166 = ncons(v166);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v166 = Lrplacd(nil, stack[-1], v166);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-6];
    v166 = stack[-2];
    v166 = qcdr(v166);
    stack[-2] = v166;
    goto v227;

v172:
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v166); }
/* error exit handlers */
v179:
    popv(7);
    return nil;
}



/* Code for numlist_ordp */

static Lisp_Object CC_numlist_ordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v186, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numlist_ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v92 = v1;
    v186 = v0;
/* end of prologue */
    v213 = v186;
    v186 = v92;
    v92 = elt(env, 1); /* lambda_l73kgw_3 */
    {
        fn = elt(env, 2); /* cons_ordp */
        return (*qfnn(fn))(qenv(fn), 3, v213, v186, v92);
    }
}



/* Code for lambda_l73kgw_3 */

static Lisp_Object CC_lambda_l73kgw_3(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v172;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l73kgw_3");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v87 = v1;
    v172 = v0;
/* end of prologue */
        return Lleq(nil, v172, v87);
}



/* Code for get!-free!-form */

static Lisp_Object CC_getKfreeKform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v242, v66;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-free-form");
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
    v242 = stack[-1];
    v167 = qvalue(elt(env, 1)); /* frasc!* */
    v167 = Latsoc(nil, v242, v167);
    stack[0] = v167;
    if (v167 == nil) goto v115;
    v167 = stack[0];
    v167 = qcdr(v167);
    { popv(4); return onevalue(v167); }

v115:
    v242 = stack[-1];
    v167 = elt(env, 2); /* !~ */
    if (!consp(v242)) goto v156;
    v242 = qcar(v242);
    if (!(v242 == v167)) goto v156;
    v167 = stack[-1];
    v167 = qcdr(v167);
    v167 = qcar(v167);
    stack[-1] = v167;
    v167 = elt(env, 3); /* (!! !~ !! !~) */
    stack[0] = v167;
    v167 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v167;
    goto v145;

v145:
    v167 = stack[-1];
    v167 = Lexplode(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-3];
    v167 = Lappend(nil, stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-3];
    v167 = Lcompress(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-3];
    v167 = Lintern(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-3];
    stack[0] = v167;
    v66 = stack[-1];
    v242 = stack[0];
    v167 = qvalue(elt(env, 1)); /* frasc!* */
    v167 = acons(v66, v242, v167);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-3];
    qvalue(elt(env, 1)) = v167; /* frasc!* */
    v167 = stack[-2];
    if (v167 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v167 = stack[0];
    v242 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v179;
    env = stack[-3];
    v167 = elt(env, 6); /* optional */
    v167 = Lflag(nil, v242, v167);
    nil = C_nil;
    if (exception_pending()) goto v179;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v156:
    v167 = elt(env, 5); /* (!! !~) */
    stack[0] = v167;
    goto v145;
/* error exit handlers */
v179:
    popv(4);
    return nil;
}



/* Code for simpexpt11 */

static Lisp_Object MS_CDECL CC_simpexpt11(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v104, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v199, v260, v252;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpexpt11");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt11");
#endif
    if (stack >= stacklimit)
    {
        push3(v104,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v104);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v104;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v199 = qvalue(elt(env, 1)); /* !*precise_complex */
    if (v199 == nil) goto v208;
    v252 = stack[-3];
    v260 = stack[-2];
    v199 = stack[-1];
    {
        popv(6);
        fn = elt(env, 2); /* simpexpt2 */
        return (*qfnn(fn))(qenv(fn), 3, v252, v260, v199);
    }

v208:
    v199 = stack[-2];
    v199 = qcdr(v199);
    if (!consp(v199)) goto v198;
    v199 = stack[-2];
    v199 = qcdr(v199);
    v199 = qcar(v199);
    if (!consp(v199)) goto v198;
    v199 = stack[-2];
    v260 = qcar(v199);
    v199 = stack[-2];
    v199 = qcdr(v199);
    fn = elt(env, 3); /* qremf */
    v199 = (*qfn2(fn))(qenv(fn), v260, v199);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    stack[-4] = v199;
    v199 = qcar(v199);
    if (v199 == nil) goto v198;
    v199 = stack[-4];
    v199 = qcdr(v199);
    if (v199 == nil) goto v198;
    stack[0] = stack[-3];
    v199 = stack[-4];
    v260 = qcar(v199);
    v199 = (Lisp_Object)17; /* 1 */
    v260 = cons(v260, v199);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    v199 = stack[-1];
    fn = elt(env, 4); /* simpexpt1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, stack[0], v260, v199);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    v199 = stack[-4];
    v260 = qcdr(v199);
    v199 = stack[-2];
    v199 = qcdr(v199);
    v260 = cons(v260, v199);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    v199 = stack[-1];
    fn = elt(env, 4); /* simpexpt1 */
    v199 = (*qfnn(fn))(qenv(fn), 3, stack[-3], v260, v199);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    {
        Lisp_Object v251 = stack[0];
        popv(6);
        fn = elt(env, 5); /* multsq */
        return (*qfn2(fn))(qenv(fn), v251, v199);
    }

v198:
    v252 = stack[-3];
    v260 = stack[-2];
    v199 = stack[-1];
    {
        popv(6);
        fn = elt(env, 2); /* simpexpt2 */
        return (*qfnn(fn))(qenv(fn), 3, v252, v260, v199);
    }
/* error exit handlers */
v217:
    popv(6);
    return nil;
}



/* Code for matrixrowom */

static Lisp_Object CC_matrixrowom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrowom");
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
    v107 = stack[0];
    if (v107 == nil) goto v20;
    v107 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 6); /* printout */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v107 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 7); /* indent!* */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v107 = elt(env, 3); /* "<OMS cd=""linalg1"" name=""matrixrow""/>" */
    fn = elt(env, 6); /* printout */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v107 = stack[0];
    v107 = qcar(v107);
    fn = elt(env, 8); /* multiom */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v107 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 7); /* indent!* */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v107 = elt(env, 5); /* "</OMA>" */
    fn = elt(env, 6); /* printout */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-1];
    v107 = stack[0];
    v107 = qcdr(v107);
    v107 = CC_matrixrowom(env, v107);
    nil = C_nil;
    if (exception_pending()) goto v106;
    goto v20;

v20:
    v107 = nil;
    { popv(2); return onevalue(v107); }
/* error exit handlers */
v106:
    popv(2);
    return nil;
}



/* Code for ft!:zerop */

static Lisp_Object CC_ftTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v146;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ft:zerop");
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
    v209 = v0;
/* end of prologue */
    stack[0] = v209;
    v146 = (Lisp_Object)161; /* 10 */
    v209 = qvalue(elt(env, 1)); /* !:prec!: */
    v209 = Lexpt(nil, v146, v209);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    v209 = times2(stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-1];
    stack[0] = v209;
    v146 = stack[0];
    v209 = (Lisp_Object)-799; /* -50 */
    v209 = (Lisp_Object)greaterp2(v146, v209);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v209 = v209 ? lisp_true : nil;
    env = stack[-1];
    if (v209 == nil) goto v124;
    v146 = stack[0];
    v209 = (Lisp_Object)801; /* 50 */
        popv(2);
        return Llessp(nil, v146, v209);

v124:
    v209 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v209); }
/* error exit handlers */
v170:
    popv(2);
    return nil;
}



/* Code for dipsum */

static Lisp_Object CC_dipsum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54, v262;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipsum");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v53 = stack[-6];
    if (v53 == nil) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    v53 = stack[-5];
    if (v53 == nil) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    stack[-7] = nil;
    stack[-2] = nil;
    stack[0] = nil;
    goto v112;

v112:
    v53 = stack[-7];
    if (!(v53 == nil)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    v53 = stack[-6];
    if (v53 == nil) goto v207;
    v53 = stack[-5];
    if (v53 == nil) goto v77;
    v53 = stack[-6];
    v53 = qcar(v53);
    stack[-4] = v53;
    v53 = stack[-5];
    v53 = qcar(v53);
    stack[-3] = v53;
    v54 = stack[-4];
    v53 = stack[-3];
    fn = elt(env, 3); /* evcomp */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-8];
    stack[-1] = v53;
    v54 = stack[-1];
    v53 = (Lisp_Object)17; /* 1 */
    v53 = Leqn(nil, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-8];
    if (v53 == nil) goto v220;
    v262 = stack[-4];
    v53 = stack[-6];
    v53 = qcdr(v53);
    v54 = qcar(v53);
    v53 = qvalue(elt(env, 1)); /* nil */
    v53 = list2star(v262, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-8];
    stack[-1] = v53;
    v53 = stack[-6];
    v53 = qcdr(v53);
    v53 = qcdr(v53);
    stack[-6] = v53;
    goto v210;

v210:
    v53 = stack[-1];
    if (v53 == nil) goto v112;
    v53 = stack[0];
    if (v53 == nil) goto v255;
    v53 = stack[-2];
    v54 = qcdr(v53);
    v53 = stack[-1];
    fn = elt(env, 4); /* setcdr */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-8];
    v53 = stack[-1];
    stack[-2] = v53;
    goto v112;

v255:
    v53 = stack[-1];
    stack[-2] = v53;
    stack[0] = v53;
    goto v112;

v220:
    v54 = stack[-1];
    v53 = (Lisp_Object)-15; /* -1 */
    v53 = Leqn(nil, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-8];
    if (v53 == nil) goto v257;
    v262 = stack[-3];
    v53 = stack[-5];
    v53 = qcdr(v53);
    v54 = qcar(v53);
    v53 = qvalue(elt(env, 1)); /* nil */
    v53 = list2star(v262, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-8];
    stack[-1] = v53;
    v53 = stack[-5];
    v53 = qcdr(v53);
    v53 = qcdr(v53);
    stack[-5] = v53;
    goto v210;

v257:
    v53 = stack[-6];
    v53 = qcdr(v53);
    v54 = qcar(v53);
    v53 = stack[-5];
    v53 = qcdr(v53);
    v53 = qcar(v53);
    fn = elt(env, 5); /* bcsum */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-8];
    stack[-1] = v53;
    v53 = stack[-1];
    fn = elt(env, 6); /* bczero!? */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-8];
    if (v53 == nil) goto v263;
    v53 = qvalue(elt(env, 1)); /* nil */
    goto v134;

v134:
    stack[-1] = v53;
    v53 = stack[-6];
    v53 = qcdr(v53);
    v53 = qcdr(v53);
    stack[-6] = v53;
    v53 = stack[-5];
    v53 = qcdr(v53);
    v53 = qcdr(v53);
    stack[-5] = v53;
    goto v210;

v263:
    v262 = stack[-4];
    v54 = stack[-1];
    v53 = qvalue(elt(env, 1)); /* nil */
    v53 = list2star(v262, v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-8];
    goto v134;

v77:
    v53 = stack[-6];
    stack[-1] = v53;
    v53 = qvalue(elt(env, 2)); /* t */
    stack[-7] = v53;
    goto v210;

v207:
    v53 = stack[-5];
    stack[-1] = v53;
    v53 = qvalue(elt(env, 2)); /* t */
    stack[-7] = v53;
    goto v210;
/* error exit handlers */
v56:
    popv(9);
    return nil;
}



/* Code for evaluate */

static Lisp_Object MS_CDECL CC_evaluate(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v104, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168, v169, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evaluate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate");
#endif
    if (stack >= stacklimit)
    {
        push3(v104,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v104);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v169 = v104;
    v139 = v1;
    stack[-5] = v0;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* !*evaluateerror */
    qvalue(elt(env, 1)) = nil; /* !*evaluateerror */
    v168 = qvalue(elt(env, 2)); /* !*protfg */
    v168 = (v168 == nil ? lisp_true : nil);
    stack[-3] = v168;
    v168 = v139;
    fn = elt(env, 8); /* pair */
    v168 = (*qfn2(fn))(qenv(fn), v168, v169);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-7];
    stack[-6] = v168;
    v169 = qvalue(elt(env, 3)); /* nil */
    v168 = qvalue(elt(env, 4)); /* t */
    stack[-2] = qvalue(elt(env, 5)); /* !*msg */
    qvalue(elt(env, 5)) = v169; /* !*msg */
    stack[-1] = qvalue(elt(env, 2)); /* !*protfg */
    qvalue(elt(env, 2)) = v168; /* !*protfg */
    stack[0] = elt(env, 6); /* evaluate0 */
    v168 = stack[-5];
    stack[-5] = Lmkquote(nil, v168);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-7];
    v168 = stack[-6];
    v168 = Lmkquote(nil, v168);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-7];
    v139 = list3(stack[0], stack[-5], v168);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-7];
    v169 = stack[-3];
    v168 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 9); /* errorset */
    v168 = (*qfnn(fn))(qenv(fn), 3, v139, v169, v168);
    nil = C_nil;
    if (exception_pending()) goto v259;
    env = stack[-7];
    stack[0] = v168;
    qvalue(elt(env, 2)) = stack[-1]; /* !*protfg */
    qvalue(elt(env, 5)) = stack[-2]; /* !*msg */
    v168 = stack[0];
    fn = elt(env, 10); /* errorp */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-7];
    if (v168 == nil) goto v223;
    v168 = elt(env, 7); /* "error during function evaluation (e.g. singularity)" 
*/
    fn = elt(env, 11); /* rederr */
    v168 = (*qfn1(fn))(qenv(fn), v168);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-7];
    goto v223;

v223:
    v168 = stack[0];
    v168 = qcar(v168);
    qvalue(elt(env, 1)) = stack[-4]; /* !*evaluateerror */
    { popv(8); return onevalue(v168); }
/* error exit handlers */
v259:
    env = stack[-7];
    qvalue(elt(env, 2)) = stack[-1]; /* !*protfg */
    qvalue(elt(env, 5)) = stack[-2]; /* !*msg */
    qvalue(elt(env, 1)) = stack[-4]; /* !*evaluateerror */
    popv(8);
    return nil;
v73:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-4]; /* !*evaluateerror */
    popv(8);
    return nil;
}



/* Code for mo_zero */

static Lisp_Object MS_CDECL CC_mo_zero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mo_zero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_zero");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v208 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* mo!=deglist */
    v208 = (*qfn1(fn))(qenv(fn), v208);
    nil = C_nil;
    if (exception_pending()) goto v172;
    {
        Lisp_Object v91 = stack[0];
        popv(1);
        return cons(v91, v208);
    }
/* error exit handlers */
v172:
    popv(1);
    return nil;
}



/* Code for sc_rep */

static Lisp_Object CC_sc_rep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sc_rep");
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
    v91 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v91 = sub1(v91);
    nil = C_nil;
    if (exception_pending()) goto v186;
    v91 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v91/(16/CELL)));
    v91 = qcdr(v91);
    v91 = qcar(v91);
    { popv(1); return onevalue(v91); }
/* error exit handlers */
v186:
    popv(1);
    return nil;
}



/* Code for get!*elements */

static Lisp_Object CC_getHelements(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*elements");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v91 = v0;
/* end of prologue */
    v92 = elt(env, 1); /* elems */
    return get(v91, v92);
}



/* Code for evrevgradlexcomp */

static Lisp_Object CC_evrevgradlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evrevgradlexcomp");
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

v20:
    v148 = stack[-2];
    if (v148 == nil) goto v227;
    v148 = stack[-1];
    if (v148 == nil) goto v172;
    v148 = stack[-2];
    v147 = qcar(v148);
    v148 = stack[-1];
    v148 = qcar(v148);
    v148 = Leqn(nil, v147, v148);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    if (v148 == nil) goto v160;
    v148 = stack[-2];
    v148 = qcdr(v148);
    stack[-2] = v148;
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    goto v20;

v160:
    v148 = stack[-2];
    fn = elt(env, 2); /* evtdeg */
    stack[0] = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v148 = stack[-1];
    fn = elt(env, 2); /* evtdeg */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v148;
    v147 = stack[-3];
    v148 = stack[0];
    v148 = Leqn(nil, v147, v148);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    if (v148 == nil) goto v140;
    v147 = stack[-2];
    v148 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* evinvlexcomp */
        return (*qfn2(fn))(qenv(fn), v147, v148);
    }

v140:
    v147 = stack[-3];
    v148 = stack[0];
    if (((int32_t)(v147)) > ((int32_t)(v148))) goto v232;
    v148 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v148); }

v232:
    v148 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v148); }

v172:
    v148 = elt(env, 1); /* (0) */
    stack[-1] = v148;
    goto v20;

v227:
    v148 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v148); }
/* error exit handlers */
v66:
    popv(5);
    return nil;
}



/* Code for indordn */

static Lisp_Object CC_indordn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v78, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordn");
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
    v209 = v0;
/* end of prologue */
    v78 = v209;
    if (v78 == nil) goto v38;
    v78 = v209;
    v78 = qcdr(v78);
    if (v78 == nil) { popv(2); return onevalue(v209); }
    v78 = v209;
    v78 = qcdr(v78);
    v78 = qcdr(v78);
    if (v78 == nil) goto v120;
    v78 = v209;
    stack[0] = qcar(v78);
    v78 = v209;
    v78 = qcdr(v78);
    v78 = CC_indordn(env, v78);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    {
        Lisp_Object v170 = stack[0];
        popv(2);
        fn = elt(env, 2); /* indordad */
        return (*qfn2(fn))(qenv(fn), v170, v78);
    }

v120:
    v78 = v209;
    v78 = qcar(v78);
    v209 = qcdr(v209);
    v209 = qcar(v209);
    {
        popv(2);
        fn = elt(env, 3); /* indord2 */
        return (*qfn2(fn))(qenv(fn), v78, v209);
    }

v38:
    v78 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v78); }
/* error exit handlers */
v145:
    popv(2);
    return nil;
}



/* Code for changearg */

static Lisp_Object MS_CDECL CC_changearg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v104, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v256, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "changearg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for changearg");
#endif
    if (stack >= stacklimit)
    {
        push3(v104,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v104);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v104;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v13;

v13:
    v258 = stack[0];
    if (!consp(v258)) goto v92;
    v258 = stack[0];
    v256 = qcar(v258);
    v258 = stack[-2];
    v258 = Lmemq(nil, v256, v258);
    if (v258 == nil) goto v168;
    stack[-2] = stack[-3];
    v258 = stack[0];
    v256 = qcar(v258);
    v258 = stack[-1];
    v258 = cons(v256, v258);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-4];
    {
        Lisp_Object v66 = stack[-2];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v66, v258);
    }

v168:
    v148 = stack[-2];
    v256 = stack[-1];
    v258 = stack[0];
    v258 = qcar(v258);
    v256 = CC_changearg(env, 3, v148, v256, v258);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-4];
    v258 = stack[-3];
    v258 = cons(v256, v258);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-4];
    stack[-3] = v258;
    v258 = stack[0];
    v258 = qcdr(v258);
    stack[0] = v258;
    goto v13;

v92:
    v256 = stack[-3];
    v258 = stack[0];
    {
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v256, v258);
    }
/* error exit handlers */
v242:
    popv(5);
    return nil;
}



/* Code for extract_dummy_ids */

static Lisp_Object CC_extract_dummy_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v154, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for extract_dummy_ids");
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
    v77 = nil;
    goto v20;

v20:
    v153 = stack[0];
    if (v153 == nil) goto v227;
    v153 = stack[0];
    v154 = qcar(v153);
    v153 = qvalue(elt(env, 1)); /* dummy_id!* */
    v153 = Lmemq(nil, v154, v153);
    if (v153 == nil) goto v210;
    v153 = stack[0];
    v153 = qcar(v153);
    v154 = v77;
    v153 = cons(v153, v154);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[-1];
    v77 = v153;
    v153 = stack[0];
    v153 = qcdr(v153);
    stack[0] = v153;
    goto v20;

v210:
    v153 = stack[0];
    v153 = qcdr(v153);
    stack[0] = v153;
    goto v20;

v227:
    v153 = v77;
    {
        popv(2);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v153);
    }
/* error exit handlers */
v209:
    popv(2);
    return nil;
}



/* Code for subsublis */

static Lisp_Object CC_subsublis(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v270, v271, v272;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subsublis");
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
    stack[-3] = v0;
/* end of prologue */

v208:
    v271 = stack[0];
    v270 = stack[-3];
    v270 = Lassoc(nil, v271, v270);
    v271 = v270;
    if (v270 == nil) goto v76;
    v270 = v271;
    v270 = qcdr(v270);
    { popv(6); return onevalue(v270); }

v76:
    v271 = stack[0];
    v270 = elt(env, 1); /* sqrt */
    if (!consp(v271)) goto v122;
    v271 = qcar(v271);
    if (!(v271 == v270)) goto v122;
    v272 = elt(env, 2); /* expt */
    v270 = stack[0];
    v270 = qcdr(v270);
    v271 = qcar(v270);
    v270 = elt(env, 3); /* (quotient 1 2) */
    v271 = list3(v272, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    v270 = stack[-3];
    v270 = Lassoc(nil, v271, v270);
    v271 = v270;
    if (v270 == nil) goto v122;
    v270 = v271;
    v270 = qcdr(v270);
    { popv(6); return onevalue(v270); }

v122:
    v270 = stack[0];
    if (!consp(v270)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v270 = stack[0];
    v270 = qcar(v270);
    if (symbolp(v270)) goto v176;
    v270 = stack[0];
    stack[-4] = v270;
    v270 = stack[-4];
    if (v270 == nil) goto v258;
    v270 = stack[-4];
    v270 = qcar(v270);
    v271 = stack[-3];
    v270 = CC_subsublis(env, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    stack[-1] = v270;
    stack[-2] = v270;
    goto v73;

v73:
    v270 = stack[-4];
    v270 = qcdr(v270);
    stack[-4] = v270;
    v270 = stack[-4];
    if (v270 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v270 = stack[-4];
    v270 = qcar(v270);
    v271 = stack[-3];
    v270 = CC_subsublis(env, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    v270 = Lrplacd(nil, stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    v270 = stack[-1];
    v270 = qcdr(v270);
    stack[-1] = v270;
    goto v73;

v258:
    v270 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v270); }

v176:
    v270 = stack[0];
    v271 = qcar(v270);
    v270 = elt(env, 5); /* subfunc */
    v270 = get(v271, v270);
    env = stack[-5];
    v271 = v270;
    if (v270 == nil) goto v60;
    v272 = v271;
    v271 = stack[-3];
    v270 = stack[0];
        popv(6);
        return Lapply2(nil, 3, v272, v271, v270);

v60:
    v270 = stack[0];
    v271 = qcar(v270);
    v270 = elt(env, 6); /* dname */
    v270 = get(v271, v270);
    env = stack[-5];
    if (!(v270 == nil)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v270 = stack[0];
    v271 = qcar(v270);
    v270 = elt(env, 7); /* !*sq */
    if (v271 == v270) goto v255;
    v270 = stack[0];
    stack[-4] = v270;
    v270 = stack[-4];
    if (v270 == nil) goto v205;
    v270 = stack[-4];
    v270 = qcar(v270);
    v271 = stack[-3];
    v270 = CC_subsublis(env, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    stack[-1] = v270;
    stack[-2] = v270;
    goto v128;

v128:
    v270 = stack[-4];
    v270 = qcdr(v270);
    stack[-4] = v270;
    v270 = stack[-4];
    if (v270 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v270 = stack[-4];
    v270 = qcar(v270);
    v271 = stack[-3];
    v270 = CC_subsublis(env, v271, v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    v270 = ncons(v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    v270 = Lrplacd(nil, stack[0], v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    v270 = stack[-1];
    v270 = qcdr(v270);
    stack[-1] = v270;
    goto v128;

v205:
    v270 = qvalue(elt(env, 4)); /* nil */
    { popv(6); return onevalue(v270); }

v255:
    stack[-1] = stack[-3];
    v270 = stack[0];
    v270 = qcdr(v270);
    v270 = qcar(v270);
    fn = elt(env, 8); /* prepsq */
    v270 = (*qfn1(fn))(qenv(fn), v270);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-5];
    stack[-3] = stack[-1];
    stack[0] = v270;
    goto v208;
/* error exit handlers */
v273:
    popv(6);
    return nil;
}



/* Code for sfto_sqfpartf */

static Lisp_Object CC_sfto_sqfpartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v232;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_sqfpartf");
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
    v139 = stack[-3];
    if (!consp(v139)) goto v227;
    v139 = stack[-3];
    v139 = qcar(v139);
    if (!consp(v139)) goto v227;
    v139 = stack[-3];
    fn = elt(env, 1); /* sfto_ucontentf */
    v139 = (*qfn1(fn))(qenv(fn), v139);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    stack[0] = v139;
    v232 = stack[-3];
    v139 = stack[0];
    fn = elt(env, 2); /* quotf */
    v139 = (*qfn2(fn))(qenv(fn), v232, v139);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    stack[-4] = v139;
    v139 = stack[0];
    stack[-2] = CC_sfto_sqfpartf(env, v139);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    stack[-1] = stack[-4];
    stack[0] = stack[-4];
    v232 = stack[-4];
    v139 = stack[-3];
    v139 = qcar(v139);
    v139 = qcar(v139);
    v139 = qcar(v139);
    fn = elt(env, 3); /* diff */
    v139 = (*qfn2(fn))(qenv(fn), v232, v139);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    fn = elt(env, 4); /* sfto_gcdf!* */
    v139 = (*qfn2(fn))(qenv(fn), stack[0], v139);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    fn = elt(env, 2); /* quotf */
    v139 = (*qfn2(fn))(qenv(fn), stack[-1], v139);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    {
        Lisp_Object v73 = stack[-2];
        popv(6);
        fn = elt(env, 5); /* multf */
        return (*qfn2(fn))(qenv(fn), v73, v139);
    }

v227:
    v139 = (Lisp_Object)17; /* 1 */
    { popv(6); return onevalue(v139); }
/* error exit handlers */
v72:
    popv(6);
    return nil;
}



/* Code for exptf1 */

static Lisp_Object CC_exptf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v223;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptf1");
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
    v223 = stack[0];
    v222 = (Lisp_Object)1; /* 0 */
    if (v223 == v222) goto v20;
    v222 = stack[-1];
    stack[-2] = v222;
    goto v171;

v171:
    v222 = stack[0];
    v223 = sub1(v222);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    stack[0] = v223;
    v222 = (Lisp_Object)1; /* 0 */
    v222 = (Lisp_Object)greaterp2(v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v180;
    v222 = v222 ? lisp_true : nil;
    env = stack[-3];
    if (v222 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v223 = stack[-1];
    v222 = stack[-2];
    fn = elt(env, 2); /* multf */
    v222 = (*qfn2(fn))(qenv(fn), v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-3];
    stack[-2] = v222;
    goto v171;

v20:
    v222 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v222); }
/* error exit handlers */
v180:
    popv(4);
    return nil;
}



/* Code for cl_sacatl */

static Lisp_Object MS_CDECL CC_cl_sacatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v104, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v173, v218, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_sacatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sacatl");
#endif
    if (stack >= stacklimit)
    {
        push3(v104,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v104);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v104;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v185:
    v173 = stack[-1];
    if (v173 == nil) goto v105;
    v218 = stack[-2];
    v173 = stack[-1];
    fn = elt(env, 6); /* rl_sacatlp */
    v173 = (*qfn2(fn))(qenv(fn), v218, v173);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    if (v173 == nil) goto v107;
    v219 = stack[-2];
    v173 = stack[-1];
    v218 = qcar(v173);
    v173 = stack[0];
    fn = elt(env, 7); /* rl_sacat */
    v173 = (*qfnn(fn))(qenv(fn), 3, v219, v218, v173);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v219 = v173;
    v173 = v219;
    if (v173 == nil) goto v212;
    v218 = v219;
    v173 = elt(env, 3); /* (keep1 keep) */
    v173 = Lmemq(nil, v218, v173);
    if (v173 == nil) goto v136;
    v218 = elt(env, 4); /* keep1 */
    v173 = stack[-1];
    v173 = qcdr(v173);
    popv(4);
    return cons(v218, v173);

v136:
    v218 = v219;
    v173 = elt(env, 5); /* keep2 */
    if (v218 == v173) goto v69;
    v218 = v219;
    v173 = stack[-1];
    v173 = qcdr(v173);
    popv(4);
    return cons(v218, v173);

v69:
    v218 = qvalue(elt(env, 2)); /* nil */
    v173 = stack[-1];
    v173 = qcdr(v173);
    popv(4);
    return cons(v218, v173);

v212:
    v219 = stack[-2];
    v173 = stack[-1];
    v218 = qcdr(v173);
    v173 = stack[0];
    stack[-2] = v219;
    stack[-1] = v218;
    stack[0] = v173;
    goto v185;

v107:
    v218 = qvalue(elt(env, 2)); /* nil */
    v173 = stack[-1];
    popv(4);
    return cons(v218, v173);

v105:
    v173 = elt(env, 1); /* (nil) */
    { popv(4); return onevalue(v173); }
/* error exit handlers */
v175:
    popv(4);
    return nil;
}



/* Code for ombindir */

static Lisp_Object MS_CDECL CC_ombindir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ombindir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ombindir");
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
    fn = elt(env, 2); /* lex */
    v160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    fn = elt(env, 3); /* omobj */
    v160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    stack[-1] = v160;
    fn = elt(env, 2); /* lex */
    v160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    fn = elt(env, 4); /* variablesir */
    v160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    fn = elt(env, 5); /* tobvarir */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    stack[0] = v160;
    fn = elt(env, 2); /* lex */
    v160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    fn = elt(env, 3); /* omobj */
    v160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    stack[-2] = v160;
    fn = elt(env, 2); /* lex */
    v160 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v160 = elt(env, 1); /* (!/ o m b i n d) */
    fn = elt(env, 6); /* checktag */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v160 = stack[-2];
    v160 = ncons(v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-3];
    v160 = Lappend(nil, stack[0], v160);
    nil = C_nil;
    if (exception_pending()) goto v207;
    {
        Lisp_Object v156 = stack[-1];
        popv(4);
        return Lappend(nil, v156, v160);
    }
/* error exit handlers */
v207:
    popv(4);
    return nil;
}



/* Code for ps!:expansion!-point */

static Lisp_Object CC_psTexpansionKpoint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v154, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expansion-point");
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
    v154 = v0;
/* end of prologue */
    v153 = v154;
    if (!consp(v153)) goto v38;
    v153 = v154;
    v77 = qcar(v153);
    v153 = elt(env, 1); /* !:ps!: */
    if (v77 == v153) goto v187;
    v153 = v154;
    v77 = qcar(v153);
    v153 = elt(env, 2); /* dname */
    v153 = get(v77, v153);
    env = stack[0];
    if (!(v153 == nil)) goto v38;

v187:
    v153 = (Lisp_Object)49; /* 3 */
    {
        popv(1);
        fn = elt(env, 4); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v154, v153);
    }

v38:
    v153 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v153); }
}



/* Code for expdrmacro */

static Lisp_Object CC_expdrmacro(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v77, v78, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expdrmacro");
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
    v77 = stack[0];
    fn = elt(env, 6); /* getrmacro */
    v77 = (*qfn1(fn))(qenv(fn), v77);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    v209 = v77;
    if (v77 == nil) goto v13;
    v78 = stack[0];
    v77 = elt(env, 1); /* noexpand */
    v77 = Lflagp(nil, v78, v77);
    env = stack[-1];
    if (!(v77 == nil)) goto v13;
    v77 = qvalue(elt(env, 3)); /* !*cref */
    if (v77 == nil) { popv(2); return onevalue(v209); }
    v78 = stack[0];
    v77 = elt(env, 4); /* expand */
    v77 = Lflagp(nil, v78, v77);
    env = stack[-1];
    if (!(v77 == nil)) { popv(2); return onevalue(v209); }
    v77 = qvalue(elt(env, 5)); /* !*force */
    if (!(v77 == nil)) { popv(2); return onevalue(v209); }
    v77 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v77); }

v13:
    v77 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v77); }
/* error exit handlers */
v145:
    popv(2);
    return nil;
}



/* Code for groebsavelterm */

static Lisp_Object CC_groebsavelterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsavelterm");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v75 = v0;
/* end of prologue */
    v124 = qvalue(elt(env, 1)); /* !*groelterms */
    if (v124 == nil) goto v20;
    v124 = v75;
    if (v124 == nil) goto v20;
    v124 = v75;
    v124 = qcdr(v124);
    v124 = qcdr(v124);
    v124 = qcdr(v124);
    v124 = qcar(v124);
    if (v124 == nil) goto v20;
    v124 = v75;
    v124 = qcdr(v124);
    v124 = qcdr(v124);
    v124 = qcar(v124);
    {
        fn = elt(env, 2); /* groebsaveltermbc */
        return (*qfn1(fn))(qenv(fn), v124);
    }

v20:
    v124 = nil;
    return onevalue(v124);
}



/* Code for coordp */

static Lisp_Object CC_coordp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v87;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v208 = v0;
/* end of prologue */
    v87 = qvalue(elt(env, 1)); /* coord!* */
    v208 = Lmemq(nil, v208, v87);
    return onevalue(v208);
}



/* Code for evaluate!-horner */

static Lisp_Object CC_evaluateKhorner(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v222, v223, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate-horner");
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
    v223 = stack[-1];
    v222 = qvalue(elt(env, 1)); /* horner!-cache!* */
    v222 = Lassoc(nil, v223, v222);
    stack[-2] = v222;
    v222 = stack[-2];
    if (v222 == nil) goto v116;
    v222 = stack[-2];
    v222 = qcdr(v222);
    { popv(4); return onevalue(v222); }

v116:
    v222 = stack[-1];
    fn = elt(env, 2); /* simp!* */
    v222 = (*qfn1(fn))(qenv(fn), v222);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    stack[-2] = v222;
    v222 = stack[-2];
    v222 = qcar(v222);
    fn = elt(env, 3); /* hornerf */
    stack[0] = (*qfn1(fn))(qenv(fn), v222);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    v222 = stack[-2];
    v222 = qcdr(v222);
    fn = elt(env, 3); /* hornerf */
    v222 = (*qfn1(fn))(qenv(fn), v222);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    v222 = cons(stack[0], v222);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    fn = elt(env, 4); /* prepsq */
    v222 = (*qfn1(fn))(qenv(fn), v222);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    stack[-2] = v222;
    v161 = stack[-1];
    v223 = stack[-2];
    v222 = qvalue(elt(env, 1)); /* horner!-cache!* */
    v222 = acons(v161, v223, v222);
    nil = C_nil;
    if (exception_pending()) goto v157;
    env = stack[-3];
    qvalue(elt(env, 1)) = v222; /* horner!-cache!* */
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v157:
    popv(4);
    return nil;
}



/* Code for fortexp */

static Lisp_Object CC_fortexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v208, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v208 = v0;
/* end of prologue */
    v87 = v208;
    v208 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* fortexp1 */
        return (*qfn2(fn))(qenv(fn), v87, v208);
    }
}



/* Code for nzero */

static Lisp_Object CC_nzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nzero");
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
    goto v208;

v208:
    v160 = stack[0];
    v155 = (Lisp_Object)1; /* 0 */
    if (v160 == v155) goto v227;
    v160 = (Lisp_Object)1; /* 0 */
    v155 = stack[-1];
    v155 = cons(v160, v155);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    stack[-1] = v155;
    v155 = stack[0];
    v155 = sub1(v155);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    stack[0] = v155;
    goto v208;

v227:
    v155 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v155);
    }
/* error exit handlers */
v210:
    popv(3);
    return nil;
}



/* Code for tensorp */

static Lisp_Object CC_tensorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v84;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v84 = v0;
/* end of prologue */
    v120 = v84;
    if (!consp(v120)) goto v38;
    v120 = v84;
    v120 = qcar(v120);
    v84 = elt(env, 2); /* tensor */
        return Lflagp(nil, v120, v84);

v38:
    v120 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v120);
}



setup_type const u20_setup[] =
{
    {"subs3t",                  too_few_2,      CC_subs3t,     wrong_no_2},
    {"nf",                      wrong_no_na,    wrong_no_nb,   (n_args *)CC_nf},
    {"safe-modrecip",           CC_safeKmodrecip,too_many_1,   wrong_no_1},
    {"ofsf_smupdknowl",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smupdknowl},
    {"lto_almerge",             too_few_2,      CC_lto_almerge,wrong_no_2},
    {"prepreform1",             too_few_2,      CC_prepreform1,wrong_no_2},
    {"formclis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclis},
    {"cgb_buch-ev_divides?",    too_few_2,      CC_cgb_buchKev_dividesW,wrong_no_2},
    {"unaryir",                 too_few_2,      CC_unaryir,    wrong_no_2},
    {"n_nary",                  too_few_2,      CC_n_nary,     wrong_no_2},
    {"testpr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_testpr},
    {"treesizep",               too_few_2,      CC_treesizep,  wrong_no_2},
    {"convprc2",                too_few_2,      CC_convprc2,   wrong_no_2},
    {"repeats",                 CC_repeats,     too_many_1,    wrong_no_1},
    {"edges_parents",           CC_edges_parents,too_many_1,   wrong_no_1},
    {"red=hidelt",              CC_redMhidelt,  too_many_1,    wrong_no_1},
    {"insert",                  too_few_2,      CC_insert,     wrong_no_2},
    {"nonlnrsys",               too_few_2,      CC_nonlnrsys,  wrong_no_2},
    {"horner-rule-for-one-var", wrong_no_na,    wrong_no_nb,   (n_args *)CC_hornerKruleKforKoneKvar},
    {"cnrd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cnrd},
    {"rootextractsq",           CC_rootextractsq,too_many_1,   wrong_no_1},
    {"dipnumcontent",           too_few_2,      CC_dipnumcontent,wrong_no_2},
    {"xriterion_1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_xriterion_1},
    {":dmtimeslst",             CC_Tdmtimeslst, too_many_1,    wrong_no_1},
    {"getphystypetimes",        CC_getphystypetimes,too_many_1,wrong_no_1},
    {"bas_newnumber",           too_few_2,      CC_bas_newnumber,wrong_no_2},
    {"pcdiv",                   too_few_2,      CC_pcdiv,      wrong_no_2},
    {"numlist_ordp",            too_few_2,      CC_numlist_ordp,wrong_no_2},
    {"lambda_l73kgw_3",         too_few_2,      CC_lambda_l73kgw_3,wrong_no_2},
    {"get-free-form",           CC_getKfreeKform,too_many_1,   wrong_no_1},
    {"simpexpt11",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpexpt11},
    {"matrixrowom",             CC_matrixrowom, too_many_1,    wrong_no_1},
    {"ft:zerop",                CC_ftTzerop,    too_many_1,    wrong_no_1},
    {"dipsum",                  too_few_2,      CC_dipsum,     wrong_no_2},
    {"evaluate",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_evaluate},
    {"mo_zero",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mo_zero},
    {"sc_rep",                  CC_sc_rep,      too_many_1,    wrong_no_1},
    {"get*elements",            CC_getHelements,too_many_1,    wrong_no_1},
    {"evrevgradlexcomp",        too_few_2,      CC_evrevgradlexcomp,wrong_no_2},
    {"indordn",                 CC_indordn,     too_many_1,    wrong_no_1},
    {"changearg",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_changearg},
    {"extract_dummy_ids",       CC_extract_dummy_ids,too_many_1,wrong_no_1},
    {"subsublis",               too_few_2,      CC_subsublis,  wrong_no_2},
    {"sfto_sqfpartf",           CC_sfto_sqfpartf,too_many_1,   wrong_no_1},
    {"exptf1",                  too_few_2,      CC_exptf1,     wrong_no_2},
    {"cl_sacatl",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_sacatl},
    {"ombindir",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_ombindir},
    {"ps:expansion-point",      CC_psTexpansionKpoint,too_many_1,wrong_no_1},
    {"expdrmacro",              CC_expdrmacro,  too_many_1,    wrong_no_1},
    {"groebsavelterm",          CC_groebsavelterm,too_many_1,  wrong_no_1},
    {"coordp",                  CC_coordp,      too_many_1,    wrong_no_1},
    {"evaluate-horner",         CC_evaluateKhorner,too_many_1, wrong_no_1},
    {"fortexp",                 CC_fortexp,     too_many_1,    wrong_no_1},
    {"nzero",                   CC_nzero,       too_many_1,    wrong_no_1},
    {"tensorp",                 CC_tensorp,     too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u20", (two_args *)"11863 3062760 7755486", 0}
};

/* end of generated code */
