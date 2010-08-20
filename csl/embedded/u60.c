
/* $destdir/generated-c\u60.c Machine generated C code */

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


/* Code for simpsqrti */

static Lisp_Object CC_simpsqrti(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsqrti");
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

v37:
    v35 = stack[0];
    if (!consp(v35)) goto v38;
    v35 = stack[0];
    v36 = qcar(v35);
    v35 = elt(env, 2); /* times */
    if (v36 == v35) goto v39;
    v35 = stack[0];
    v36 = qcar(v35);
    v35 = elt(env, 5); /* quotient */
    if (v36 == v35) goto v40;
    v35 = stack[0];
    v36 = qcar(v35);
    v35 = elt(env, 6); /* expt */
    if (!(v36 == v35)) goto v41;
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    v35 = qcar(v35);
    if (!(is_number(v35))) goto v41;
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v35 = Levenp(nil, v35);
    env = stack[-5];
    if (v35 == nil) goto v42;
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[-1] = qcar(v35);
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    v36 = qcar(v35);
    v35 = (Lisp_Object)33; /* 2 */
    v35 = quot2(v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v35 = list2(stack[-1], v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 8); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v35);
    }

v42:
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v35 = CC_simpsqrti(env, v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    fn = elt(env, 9); /* mk!*sq */
    v36 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v35 = list2(v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 8); /* simpexpt */
        return (*qfn1(fn))(qenv(fn), v35);
    }

v41:
    v35 = stack[0];
    v36 = qcar(v35);
    v35 = elt(env, 7); /* !*sq */
    if (v36 == v35) goto v44;
    v35 = stack[0];
    fn = elt(env, 10); /* simp!* */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    fn = elt(env, 11); /* tidysqrt */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 12); /* simpsqrtsq */
        return (*qfn1(fn))(qenv(fn), v35);
    }

v44:
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcar(v35);
    {
        popv(6);
        fn = elt(env, 12); /* simpsqrtsq */
        return (*qfn1(fn))(qenv(fn), v35);
    }

v40:
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcar(v35);
    stack[-1] = CC_simpsqrti(env, v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v35 = CC_simpsqrti(env, v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    fn = elt(env, 13); /* invsq */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    {
        Lisp_Object v45 = stack[-1];
        popv(6);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v45, v35);
    }

v39:
    stack[-4] = elt(env, 3); /* multsq */
    v35 = stack[0];
    v35 = qcdr(v35);
    stack[-3] = v35;
    v35 = stack[-3];
    if (v35 == nil) goto v46;
    v35 = stack[-3];
    v35 = qcar(v35);
    v35 = CC_simpsqrti(env, v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    stack[-1] = v35;
    stack[-2] = v35;
    goto v47;

v47:
    v35 = stack[-3];
    v35 = qcdr(v35);
    stack[-3] = v35;
    v35 = stack[-3];
    if (v35 == nil) goto v48;
    stack[0] = stack[-1];
    v35 = stack[-3];
    v35 = qcar(v35);
    v35 = CC_simpsqrti(env, v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v35 = Lrplacd(nil, stack[0], v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v35 = stack[-1];
    v35 = qcdr(v35);
    stack[-1] = v35;
    goto v47;

v48:
    v35 = stack[-2];
    goto v49;

v49:
    {
        Lisp_Object v50 = stack[-4];
        popv(6);
        fn = elt(env, 14); /* mapply */
        return (*qfn2(fn))(qenv(fn), v50, v35);
    }

v46:
    v35 = qvalue(elt(env, 4)); /* nil */
    goto v49;

v38:
    v35 = stack[0];
    if (is_number(v35)) goto v51;
    v36 = stack[0];
    v35 = elt(env, 1); /* avalue */
    v35 = get(v36, v35);
    env = stack[-5];
    v36 = v35;
    if (v35 == nil) goto v52;
    v35 = v36;
    v35 = qcdr(v35);
    v35 = qcar(v35);
    stack[0] = v35;
    goto v37;

v52:
    v36 = stack[0];
    v35 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* mksp */
    v36 = (*qfn2(fn))(qenv(fn), v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v35 = (Lisp_Object)17; /* 1 */
    v35 = cons(v36, v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    v35 = ncons(v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-5];
    fn = elt(env, 16); /* simpsqrt2 */
    v36 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v35 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v36, v35);

v51:
    v35 = stack[0];
    fn = elt(env, 16); /* simpsqrt2 */
    v36 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v43;
    v35 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v36, v35);
/* error exit handlers */
v43:
    popv(6);
    return nil;
}



/* Code for modsqrt1 */

static Lisp_Object CC_modsqrt1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modsqrt1");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v53;
    stack[-3] = v0;
/* end of prologue */
    stack[0] = nil;
    v70 = (Lisp_Object)1; /* 0 */
    stack[-4] = v70;
    v70 = (Lisp_Object)1; /* 0 */
    stack[-1] = v70;
    goto v71;

v71:
    v70 = stack[0];
    if (!(v70 == nil)) goto v72;
    v48 = stack[-4];
    v70 = stack[-2];
    v70 = (Lisp_Object)lessp2(v48, v70);
    nil = C_nil;
    if (exception_pending()) goto v73;
    v70 = v70 ? lisp_true : nil;
    env = stack[-5];
    if (v70 == nil) goto v72;
    v48 = stack[-1];
    v70 = stack[-3];
    if (equal(v48, v70)) goto v74;
    v48 = stack[-1];
    v70 = stack[-4];
    v48 = (Lisp_Object)(int32_t)((int32_t)v48 + (int32_t)v70 - TAG_FIXNUM);
    v70 = stack[-4];
    v70 = (Lisp_Object)(int32_t)((int32_t)v48 + (int32_t)v70 - TAG_FIXNUM);
    v70 = (Lisp_Object)((int32_t)(v70) + 0x10);
    stack[-1] = v70;
    goto v75;

v75:
    v48 = stack[-1];
    v70 = stack[-2];
    if (((int32_t)(v48)) > ((int32_t)(v70))) goto v23;
    v70 = stack[-4];
    v70 = (Lisp_Object)((int32_t)(v70) + 0x10);
    stack[-4] = v70;
    goto v71;

v23:
    v48 = stack[-1];
    v70 = stack[-2];
    v70 = (Lisp_Object)(int32_t)((int32_t)v48 - (int32_t)v70 + TAG_FIXNUM);
    stack[-1] = v70;
    goto v75;

v74:
    v70 = stack[-4];
    stack[0] = v70;
    goto v71;

v72:
    v70 = stack[0];
    if (!(v70 == nil)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v48 = elt(env, 2); /* sqrt */
    v70 = stack[-3];
    v48 = list2(v48, v70);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    v70 = elt(env, 3); /* "expression mod p" */
    fn = elt(env, 4); /* typerr */
    v70 = (*qfn2(fn))(qenv(fn), v48, v70);
    nil = C_nil;
    if (exception_pending()) goto v73;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
/* error exit handlers */
v73:
    popv(6);
    return nil;
}



/* Code for r2bf */

static Lisp_Object CC_r2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v90, v91, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2bf");
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

v61:
    v90 = stack[0];
    if (!consp(v90)) goto v38;
    v91 = stack[0];
    v90 = elt(env, 1); /* !:rd!: */
    if (!consp(v91)) goto v92;
    v91 = qcar(v91);
    if (!(v91 == v90)) goto v92;
    v90 = stack[0];
    v90 = qcdr(v90);
    if (!(!consp(v90))) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v92:
    v90 = stack[0];
    v90 = qcar(v90);
    if (is_number(v90)) goto v22;
    v91 = stack[0];
    v90 = elt(env, 3); /* quotient */
    if (!consp(v91)) goto v93;
    v91 = qcar(v91);
    if (!(v91 == v90)) goto v93;
    v10 = elt(env, 1); /* !:rd!: */
    v90 = stack[0];
    v90 = qcdr(v90);
    v91 = qcar(v90);
    v90 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v10, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v10 = elt(env, 1); /* !:rd!: */
    v90 = stack[0];
    v90 = qcdr(v90);
    v90 = qcdr(v90);
    v91 = qcar(v90);
    v90 = (Lisp_Object)1; /* 0 */
    v91 = list2star(v10, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v90 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 5); /* divide!: */
    v90 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v90);
    }

v93:
    v91 = stack[0];
    v90 = elt(env, 4); /* !:rn!: */
    if (!consp(v91)) goto v95;
    v91 = qcar(v91);
    if (!(v91 == v90)) goto v95;
    v90 = stack[0];
    v90 = qcdr(v90);
    stack[0] = v90;
    goto v61;

v95:
    v90 = stack[0];
    v90 = qcdr(v90);
    v90 = qcar(v90);
    stack[0] = v90;
    goto v61;

v22:
    v10 = elt(env, 1); /* !:rd!: */
    v90 = stack[0];
    v91 = qcar(v90);
    v90 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v10, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v10 = elt(env, 1); /* !:rd!: */
    v90 = stack[0];
    v91 = qcdr(v90);
    v90 = (Lisp_Object)1; /* 0 */
    v91 = list2star(v10, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v90 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 5); /* divide!: */
    v90 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v90);
    }

v38:
    v90 = stack[0];
    v90 = Lfloatp(nil, v90);
    env = stack[-2];
    if (v90 == nil) goto v96;
    v90 = stack[0];
    {
        popv(3);
        fn = elt(env, 7); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v90);
    }

v96:
    v90 = stack[0];
    if (!consp(v90)) goto v97;
    v90 = stack[0];
    goto v98;

v98:
    {
        popv(3);
        fn = elt(env, 6); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v90);
    }

v97:
    v90 = stack[0];
    v90 = integerp(v90);
    if (v90 == nil) goto v99;
    v10 = elt(env, 1); /* !:rd!: */
    v91 = stack[0];
    v90 = (Lisp_Object)1; /* 0 */
    v90 = list2star(v10, v91, v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    goto v98;

v99:
    v90 = stack[0];
    fn = elt(env, 8); /* read!:num */
    v90 = (*qfn1(fn))(qenv(fn), v90);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    goto v98;
/* error exit handlers */
v94:
    popv(3);
    return nil;
}



/* Code for substinulist */

static Lisp_Object CC_substinulist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v102;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for substinulist");
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
    v75 = stack[-2];
    if (v75 == nil) goto v61;
    v75 = stack[-2];
    v75 = qcar(v75);
    v75 = qcdr(v75);
    stack[-3] = v75;
    v75 = stack[-3];
    v75 = qcar(v75);
    fn = elt(env, 2); /* evaluateuconst */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    v102 = v75;
    v75 = v102;
    v75 = qcar(v75);
    if (v75 == nil) goto v98;
    v75 = stack[-2];
    v75 = qcar(v75);
    stack[-1] = qcar(v75);
    stack[0] = v102;
    v75 = stack[-3];
    v102 = qcdr(v75);
    v75 = (Lisp_Object)17; /* 1 */
    v75 = cons(v102, v75);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    fn = elt(env, 3); /* !*invsq */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    fn = elt(env, 4); /* !*multsq */
    v75 = (*qfn2(fn))(qenv(fn), stack[0], v75);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    v75 = cons(stack[-1], v75);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    v75 = ncons(v75);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    v102 = v75;
    goto v103;

v103:
    stack[0] = v102;
    v75 = stack[-2];
    v75 = qcdr(v75);
    v75 = CC_substinulist(env, v75);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    {
        Lisp_Object v104 = stack[0];
        popv(5);
        fn = elt(env, 5); /* plusdf */
        return (*qfn2(fn))(qenv(fn), v104, v75);
    }

v98:
    v75 = qvalue(elt(env, 1)); /* nil */
    v102 = v75;
    goto v103;

v61:
    v75 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v75); }
/* error exit handlers */
v59:
    popv(5);
    return nil;
}



/* Code for cpr_buchcrit4t */

static Lisp_Object CC_cpr_buchcrit4t(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cpr_buchcrit4t");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v71 = v53;
    v106 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ev_disjointp */
    v71 = (*qfn2(fn))(qenv(fn), v106, v71);
    errexit();
    v71 = (v71 == nil ? lisp_true : nil);
    return onevalue(v71);
}



/* Code for rerror */

static Lisp_Object MS_CDECL CC_rerror(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v53,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v107, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rerror");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rerror");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v38 = v34;
    v107 = v53;
    v105 = v0;
/* end of prologue */
    v107 = v38;
    qvalue(elt(env, 1)) = v107; /* errmsg!* */
    {
        fn = elt(env, 2); /* rederr */
        return (*qfn1(fn))(qenv(fn), v38);
    }
}



/* Code for int!-simp */

static Lisp_Object CC_intKsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for int-simp");
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
    v108 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[0];
    fn = elt(env, 2); /* resimp */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* subs2 */
        return (*qfn1(fn))(qenv(fn), v108);
    }
/* error exit handlers */
v38:
    popv(1);
    return nil;
}



/* Code for i2crn!* */

static Lisp_Object CC_i2crnH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2crn*");
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
    v97 = v0;
/* end of prologue */
    v111 = v97;
    v97 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v111, v97);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    v111 = (Lisp_Object)1; /* 0 */
    v97 = (Lisp_Object)17; /* 1 */
    v97 = cons(v111, v97);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-1];
    {
        Lisp_Object v112 = stack[0];
        popv(2);
        fn = elt(env, 1); /* mkcrn */
        return (*qfn2(fn))(qenv(fn), v112, v97);
    }
/* error exit handlers */
v68:
    popv(2);
    return nil;
}



/* Code for fnewsym */

static Lisp_Object MS_CDECL CC_fnewsym(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "fnewsym");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnewsym");
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
    v88 = elt(env, 1); /* newsym */
    fn = elt(env, 3); /* getd */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    if (v88 == nil) goto v72;
    fn = elt(env, 1); /* newsym */
    v88 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    stack[-1] = v88;
    goto v56;

v56:
    v88 = stack[-1];
    v88 = Lintern(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    stack[-1] = v88;
    v88 = stack[-1];
    v89 = ncons(v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    v88 = elt(env, 1); /* newsym */
    v88 = Lflag(nil, v89, v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v72:
    v88 = elt(env, 2); /* g */
    v88 = Lgensym1(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    stack[-1] = v88;
    v88 = stack[-1];
    fn = elt(env, 4); /* letterpart */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    stack[0] = Lexplode(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    v88 = stack[-1];
    fn = elt(env, 5); /* digitpart */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    v88 = Lexplode(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    v88 = Lappend(nil, stack[0], v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    v88 = Lcompress(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-2];
    stack[-1] = v88;
    goto v56;
/* error exit handlers */
v114:
    popv(3);
    return nil;
}



/* Code for dipreduceconti */

static Lisp_Object MS_CDECL CC_dipreduceconti(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v53,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipreduceconti");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipreduceconti");
#endif
    if (stack >= stacklimit)
    {
        push3(v34,v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v53,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v34;
    stack[-1] = v53;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v38;

v38:
    v27 = stack[-2];
    if (v27 == nil) goto v100;
    v27 = stack[0];
    if (v27 == nil) goto v118;
    v27 = stack[-2];
    v24 = qcar(v27);
    v27 = stack[0];
    fn = elt(env, 1); /* evdif */
    v27 = (*qfn2(fn))(qenv(fn), v24, v27);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    v24 = v27;
    goto v120;

v120:
    v27 = stack[-3];
    v27 = cons(v24, v27);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    stack[-3] = v27;
    v27 = stack[-2];
    v27 = qcdr(v27);
    v24 = qcar(v27);
    v27 = stack[-1];
    fn = elt(env, 2); /* bcquot */
    v24 = (*qfn2(fn))(qenv(fn), v24, v27);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    v27 = stack[-3];
    v27 = cons(v24, v27);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-4];
    stack[-3] = v27;
    v27 = stack[-2];
    v27 = qcdr(v27);
    v27 = qcdr(v27);
    stack[-2] = v27;
    goto v38;

v118:
    v27 = stack[-2];
    v27 = qcar(v27);
    v24 = v27;
    goto v120;

v100:
    v27 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v27);
    }
/* error exit handlers */
v119:
    popv(5);
    return nil;
}



/* Code for remove_items */

static Lisp_Object CC_remove_items(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove_items");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v53;
    stack[-1] = v0;
/* end of prologue */
    v92 = stack[-1];
    v92 = qcdr(v92);
    if (v92 == nil) goto v38;
    v92 = stack[-1];
    v92 = qcdr(v92);
    v115 = qcar(v92);
    v92 = stack[0];
    v92 = CC_remove_items(env, v115, v92);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v92 = stack[-1];
    v92 = qcdr(v92);
    v115 = qcdr(v92);
    v92 = stack[0];
    v92 = CC_remove_items(env, v115, v92);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    v115 = stack[0];
    v92 = stack[-1];
    v92 = qcar(v92);
    fn = elt(env, 2); /* xnp */
    v92 = (*qfn2(fn))(qenv(fn), v115, v92);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-2];
    if (v92 == nil) goto v31;
    v92 = stack[-1];
    fn = elt(env, 3); /* remove_root_item */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v122;
    goto v31;

v31:
    v92 = nil;
    { popv(3); return onevalue(v92); }

v38:
    v92 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v92); }
/* error exit handlers */
v122:
    popv(3);
    return nil;
}



/* Code for precedence */

static Lisp_Object CC_precedence(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v126, v127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for precedence");
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
    stack[-2] = nil;
    v125 = stack[-4];
    v126 = qcar(v125);
    v125 = qvalue(elt(env, 1)); /* preclis!* */
    v125 = Ldelete(nil, v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    qvalue(elt(env, 1)) = v125; /* preclis!* */
    v125 = stack[-4];
    v125 = qcdr(v125);
    v125 = qcar(v125);
    stack[-3] = v125;
    v125 = qvalue(elt(env, 1)); /* preclis!* */
    stack[-5] = v125;
    goto v38;

v38:
    v125 = stack[-5];
    if (v125 == nil) goto v68;
    v126 = stack[-3];
    v125 = stack[-5];
    v125 = qcar(v125);
    if (!(v126 == v125)) goto v69;
    v125 = stack[-2];
    fn = elt(env, 5); /* reversip!* */
    stack[0] = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v125 = stack[-5];
    v127 = qcar(v125);
    v125 = stack[-4];
    v126 = qcar(v125);
    v125 = stack[-5];
    v125 = qcdr(v125);
    v125 = list2star(v127, v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    fn = elt(env, 6); /* nconc!* */
    v125 = (*qfn2(fn))(qenv(fn), stack[0], v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    qvalue(elt(env, 1)) = v125; /* preclis!* */
    fn = elt(env, 7); /* mkprec */
    v125 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    v125 = qvalue(elt(env, 4)); /* nil */
    { popv(7); return onevalue(v125); }

v69:
    v125 = stack[-5];
    v126 = qcar(v125);
    v125 = stack[-2];
    v125 = cons(v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    stack[-2] = v125;
    v125 = stack[-5];
    v125 = qcdr(v125);
    stack[-5] = v125;
    goto v38;

v68:
    stack[-1] = elt(env, 2); /* rlisp */
    stack[0] = (Lisp_Object)257; /* 16 */
    v126 = stack[-3];
    v125 = elt(env, 3); /* "not found" */
    v125 = list2(v126, v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    fn = elt(env, 8); /* rerror */
    v125 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v125);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-6];
    goto v69;
/* error exit handlers */
v85:
    popv(7);
    return nil;
}



/* Code for redstmtp */

static Lisp_Object CC_redstmtp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v118, v65;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redstmtp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v65 = v0;
/* end of prologue */
    v113 = v65;
    v113 = (consp(v113) ? nil : lisp_true);
    if (!(v113 == nil)) return onevalue(v113);
    v113 = v65;
    v118 = qcar(v113);
    v113 = qvalue(elt(env, 1)); /* !*redstmtops!* */
    v113 = Lmemq(nil, v118, v113);
    if (!(v113 == nil)) return onevalue(v113);
    v113 = v65;
    v113 = qcar(v113);
    if (!consp(v113)) goto v67;
    v113 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v113);

v67:
    v113 = v65;
    v113 = qcar(v113);
    v118 = qvalue(elt(env, 3)); /* !*redreswds!* */
    v113 = Lmemq(nil, v113, v118);
    v113 = (v113 == nil ? lisp_true : nil);
    return onevalue(v113);
}



/* Code for clearrules */

static Lisp_Object CC_clearrules(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clearrules");
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
    v71 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* !*sqrtrulep */
    qvalue(elt(env, 2)) = v71; /* !*sqrtrulep */
    v71 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* rule!-list */
    v71 = (*qfn2(fn))(qenv(fn), v106, v71);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*sqrtrulep */
    { popv(2); return onevalue(v71); }
/* error exit handlers */
v110:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*sqrtrulep */
    popv(2);
    return nil;
}



/* Code for stp */

static Lisp_Object CC_stp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for stp");
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
    v109 = v0;
/* end of prologue */
    v110 = v109;
    v110 = Lconsp(nil, v110);
    env = stack[0];
    if (v110 == nil) goto v61;
    v109 = qcar(v109);
    {
        popv(1);
        fn = elt(env, 2); /* spp */
        return (*qfn1(fn))(qenv(fn), v109);
    }

v61:
    v109 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v109); }
}



/* Code for replace_edge2 */

static Lisp_Object CC_replace_edge2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace_edge2");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v53;
    stack[-1] = v0;
/* end of prologue */
    v98 = stack[-1];
    v33 = stack[0];
    v33 = qcar(v33);
    v33 = Lrplaca(nil, v98, v33);
    nil = C_nil;
    if (exception_pending()) goto v111;
    v98 = stack[-1];
    v33 = stack[0];
    v33 = qcdr(v33);
        popv(2);
        return Lrplacd(nil, v98, v33);
/* error exit handlers */
v111:
    popv(2);
    return nil;
}



/* Code for force!-lc */

static Lisp_Object CC_forceKlc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v96, v129;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for force-lc");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v128 = v53;
    v96 = v0;
/* end of prologue */
    v129 = v96;
    v129 = qcar(v129);
    v129 = qcar(v129);
    v96 = qcdr(v96);
    return acons(v129, v128, v96);
}



/* Code for dpmat_gbtag */

static Lisp_Object CC_dpmat_gbtag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dpmat_gbtag");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v100 = v0;
/* end of prologue */
    v72 = v100;
    v100 = (Lisp_Object)97; /* 6 */
    {
        fn = elt(env, 1); /* nth */
        return (*qfn2(fn))(qenv(fn), v72, v100);
    }
}



/* Code for multivariatep */

static Lisp_Object CC_multivariatep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v92;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multivariatep");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v53;
    stack[-1] = v0;
/* end of prologue */

v56:
    v25 = stack[-1];
    if (!consp(v25)) goto v107;
    v25 = stack[-1];
    v25 = qcar(v25);
    if (!consp(v25)) goto v107;
    v25 = stack[-1];
    v25 = qcar(v25);
    v25 = qcar(v25);
    v92 = qcar(v25);
    v25 = stack[0];
    if (v92 == v25) goto v30;
    v25 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v25); }

v30:
    v25 = stack[-1];
    v25 = qcar(v25);
    v92 = qcdr(v25);
    v25 = stack[0];
    v25 = CC_multivariatep(env, v92, v25);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-2];
    if (v25 == nil) goto v99;
    v25 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v25); }

v99:
    v25 = stack[-1];
    v25 = qcdr(v25);
    stack[-1] = v25;
    goto v56;

v107:
    v25 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v25); }
/* error exit handlers */
v130:
    popv(3);
    return nil;
}



/* Code for modsqrt */

static Lisp_Object CC_modsqrt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modsqrt");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v53;
    stack[-1] = v0;
/* end of prologue */
    v29 = stack[0];
    stack[-2] = qvalue(elt(env, 1)); /* current!-modulus */
    qvalue(elt(env, 1)) = v29; /* current!-modulus */
    v29 = stack[0];
    v29 = integerp(v29);
    if (v29 == nil) goto v98;
    v27 = stack[0];
    v29 = (Lisp_Object)33; /* 2 */
    v29 = (Lisp_Object)lessp2(v27, v29);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v29 = v29 ? lisp_true : nil;
    env = stack[-3];
    if (!(v29 == nil)) goto v98;

v108:
    v29 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-number */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    stack[-1] = v29;
    v27 = stack[0];
    v29 = (Lisp_Object)801; /* 50 */
    v29 = (Lisp_Object)lessp2(v27, v29);
    nil = C_nil;
    if (exception_pending()) goto v75;
    v29 = v29 ? lisp_true : nil;
    env = stack[-3];
    if (v29 == nil) goto v26;
    v27 = stack[-1];
    v29 = stack[0];
    fn = elt(env, 4); /* modsqrt1 */
    v29 = (*qfn2(fn))(qenv(fn), v27, v29);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    goto v30;

v30:
    qvalue(elt(env, 1)) = stack[-2]; /* current!-modulus */
    { popv(4); return onevalue(v29); }

v26:
    v27 = stack[-1];
    v29 = stack[0];
    fn = elt(env, 5); /* modsqrt2 */
    v29 = (*qfn2(fn))(qenv(fn), v27, v29);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    goto v30;

v98:
    v27 = stack[0];
    v29 = elt(env, 2); /* "modulus for root computation" */
    fn = elt(env, 6); /* typerr */
    v29 = (*qfn2(fn))(qenv(fn), v27, v29);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-3];
    goto v108;
/* error exit handlers */
v75:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* current!-modulus */
    popv(4);
    return nil;
}



/* Code for common!-increment */

static Lisp_Object CC_commonKincrement(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v47, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for common-increment");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v53;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v105;

v105:
    v133 = stack[-1];
    v133 = qcar(v133);
    if (!consp(v133)) goto v51;
    v133 = stack[-1];
    v133 = qcar(v133);
    v133 = qcdr(v133);
    v133 = qcdr(v133);
    v47 = v133;
    goto v72;

v72:
    v133 = stack[0];
    v133 = qcar(v133);
    if (!consp(v133)) goto v134;
    v133 = stack[0];
    v133 = qcar(v133);
    v133 = qcdr(v133);
    v133 = qcdr(v133);
    goto v71;

v71:
    fn = elt(env, 1); /* lcmn */
    v133 = (*qfn2(fn))(qenv(fn), v47, v133);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v125 = v133;
    v47 = v125;
    v133 = (Lisp_Object)17; /* 1 */
    if (v47 == v133) goto v115;
    v133 = (Lisp_Object)17; /* 1 */
    v47 = v125;
    fn = elt(env, 2); /* mkrn */
    v133 = (*qfn2(fn))(qenv(fn), v133, v47);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    v47 = v133;
    goto v124;

v124:
    v133 = stack[-2];
    v133 = cons(v47, v133);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-3];
    stack[-2] = v133;
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[-1] = v133;
    v133 = stack[0];
    v133 = qcdr(v133);
    stack[0] = v133;
    v133 = stack[-1];
    if (!(v133 == nil)) goto v105;
    v133 = stack[0];
    if (v133 == nil) goto v19;
    v133 = elt(env, 0); /* common!-increment */
    fn = elt(env, 3); /* confusion */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v46;
    v133 = nil;
    { popv(4); return onevalue(v133); }

v19:
    v133 = stack[-2];
        popv(4);
        return Lnreverse(nil, v133);

v115:
    v133 = v125;
    v47 = v133;
    goto v124;

v134:
    v133 = (Lisp_Object)17; /* 1 */
    goto v71;

v51:
    v133 = (Lisp_Object)17; /* 1 */
    v47 = v133;
    goto v72;
/* error exit handlers */
v46:
    popv(4);
    return nil;
}



/* Code for order */

static Lisp_Object CC_order(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for order");
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
    fn = elt(env, 3); /* rmsubs */
    v24 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-2];
    v24 = stack[0];
    if (v24 == nil) goto v51;
    v24 = stack[0];
    v24 = qcar(v24);
    if (!(v24 == nil)) goto v51;
    v24 = stack[0];
    v24 = qcdr(v24);
    if (!(v24 == nil)) goto v51;
    v24 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v24; /* ordl!* */
    { popv(3); return onevalue(v24); }

v51:
    v24 = stack[0];
    fn = elt(env, 4); /* kernel!-list */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-2];
    stack[-1] = v24;
    goto v33;

v33:
    v24 = stack[-1];
    if (v24 == nil) goto v67;
    v24 = stack[-1];
    v24 = qcar(v24);
    stack[0] = v24;
    v136 = stack[0];
    v24 = qvalue(elt(env, 2)); /* ordl!* */
    v24 = Lmember(nil, v136, v24);
    if (v24 == nil) goto v26;
    v136 = stack[0];
    v24 = qvalue(elt(env, 2)); /* ordl!* */
    v24 = Ldelete(nil, v136, v24);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-2];
    qvalue(elt(env, 2)) = v24; /* ordl!* */
    goto v26;

v26:
    v136 = qvalue(elt(env, 2)); /* ordl!* */
    v24 = stack[0];
    fn = elt(env, 5); /* aconc!* */
    v24 = (*qfn2(fn))(qenv(fn), v136, v24);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-2];
    qvalue(elt(env, 2)) = v24; /* ordl!* */
    v24 = stack[-1];
    v24 = qcdr(v24);
    stack[-1] = v24;
    goto v33;

v67:
    v24 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v24); }
/* error exit handlers */
v102:
    popv(3);
    return nil;
}



/* Code for get_nr_irred_reps */

static Lisp_Object CC_get_nr_irred_reps(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v51;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_nr_irred_reps");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v51 = v0;
/* end of prologue */
    v110 = qvalue(elt(env, 1)); /* !*complex */
    if (v110 == nil) goto v72;
    v110 = v51;
    {
        fn = elt(env, 2); /* get!*nr!*complex!*irred!*reps */
        return (*qfn1(fn))(qenv(fn), v110);
    }

v72:
    v110 = v51;
    {
        fn = elt(env, 3); /* get!*nr!*real!*irred!*reps */
        return (*qfn1(fn))(qenv(fn), v110);
    }
}



/* Code for ev_max!# */

static Lisp_Object CC_ev_maxC(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v129, v120, v33;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev_max#");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v129 = v53;
    v120 = v0;
/* end of prologue */
    v33 = v120;
    v96 = v129;
    if (((int32_t)(v33)) > ((int32_t)(v96))) return onevalue(v120);
    else return onevalue(v129);
}



/* Code for ssetvars1 */

static Lisp_Object CC_ssetvars1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v162, v2, v1, v163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ssetvars1");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v53;
    stack[-9] = v0;
/* end of prologue */
    v161 = stack[-9];
    fn = elt(env, 5); /* eval */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    stack[-5] = v161;
    goto v72;

v72:
    v161 = stack[-5];
    if (v161 == nil) goto v100;
    v161 = stack[-5];
    v161 = qcar(v161);
    stack[-4] = v161;
    v161 = qvalue(elt(env, 1)); /* nil */
    stack[-7] = v161;
    v161 = qvalue(elt(env, 2)); /* rowmin */
    v161 = sub1(v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    qvalue(elt(env, 2)) = v161; /* rowmin */
    v162 = stack[-4];
    v161 = stack[-9];
    v161 = get(v162, v161);
    env = stack[-11];
    stack[-3] = v161;
    goto v134;

v134:
    v161 = stack[-3];
    if (v161 == nil) goto v165;
    v161 = stack[-3];
    v161 = qcar(v161);
    stack[-2] = v161;
    v161 = qvalue(elt(env, 2)); /* rowmin */
    stack[0] = v161;
    v161 = stack[-2];
    v161 = qcdr(v161);
    if (symbolp(v161)) goto v29;
    v161 = stack[-2];
    v161 = qcdr(v161);
    fn = elt(env, 6); /* constp */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    if (!(v161 == nil)) goto v29;
    v162 = stack[0];
    v161 = stack[-2];
    v161 = qcdr(v161);
    v161 = cons(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    goto v130;

v130:
    stack[-10] = v161;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v162 = qvalue(elt(env, 4)); /* maxvar */
    v161 = stack[-2];
    v161 = qcar(v161);
    v161 = plus2(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    v162 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL)));
    v161 = (Lisp_Object)65; /* 4 */
    v161 = *(Lisp_Object *)((char *)v162 + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL)));
    stack[-6] = v161;
    if (v161 == nil) goto v166;
    v161 = stack[-6];
    v161 = qcar(v161);
    v162 = qcar(v161);
    v161 = qvalue(elt(env, 2)); /* rowmin */
    if (!(equal(v162, v161))) goto v166;

v76:
    v161 = stack[-10];
    v161 = qcdr(v161);
    if (symbolp(v161)) goto v167;
    v161 = stack[-10];
    v161 = qcdr(v161);
    fn = elt(env, 6); /* constp */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    if (!(v161 == nil)) goto v167;
    v161 = stack[-2];
    v162 = qcar(v161);
    v161 = stack[-10];
    v161 = qcdr(v161);
    v161 = cons(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    v162 = v161;
    goto v168;

v168:
    v161 = stack[-7];
    fn = elt(env, 7); /* inszzz */
    v161 = (*qfn2(fn))(qenv(fn), v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    stack[-7] = v161;
    v161 = stack[-3];
    v161 = qcdr(v161);
    stack[-3] = v161;
    goto v134;

v167:
    v161 = stack[-2];
    v2 = qcar(v161);
    v161 = stack[-10];
    v162 = qcdr(v161);
    v161 = qvalue(elt(env, 1)); /* nil */
    v161 = list2star(v2, v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    v162 = v161;
    goto v168;

v166:
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v162 = qvalue(elt(env, 4)); /* maxvar */
    v161 = stack[-2];
    v161 = qcar(v161);
    v161 = plus2(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    stack[-1] = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v161/(16/CELL)));
    stack[0] = (Lisp_Object)65; /* 4 */
    v162 = stack[-10];
    v161 = stack[-6];
    v161 = cons(v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v161;
    goto v76;

v29:
    v2 = stack[0];
    v161 = stack[-2];
    v162 = qcdr(v161);
    v161 = qvalue(elt(env, 1)); /* nil */
    v161 = list2star(v2, v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    goto v130;

v165:
    v2 = stack[-4];
    v162 = stack[-9];
    v161 = qvalue(elt(env, 2)); /* rowmin */
    v161 = Lputprop(nil, 3, v2, v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    v163 = qvalue(elt(env, 2)); /* rowmin */
    v1 = stack[-8];
    v2 = stack[-4];
    v162 = qvalue(elt(env, 1)); /* nil */
    v161 = stack[-7];
    fn = elt(env, 8); /* setrow */
    v161 = (*qfnn(fn))(qenv(fn), 5, v163, v1, v2, v162, v161);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-11];
    v161 = stack[-5];
    v161 = qcdr(v161);
    stack[-5] = v161;
    goto v72;

v100:
    v161 = nil;
    { popv(12); return onevalue(v161); }
/* error exit handlers */
v164:
    popv(12);
    return nil;
}



/* Code for idqsimpcont */

static Lisp_Object CC_idqsimpcont(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v109;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idqsimpcont");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v109 = v0;
/* end of prologue */
    v106 = qvalue(elt(env, 1)); /* !*vdpinteger */
    if (v106 == nil) goto v105;
    v106 = v109;
    {
        fn = elt(env, 2); /* idqsimpconti */
        return (*qfn1(fn))(qenv(fn), v106);
    }

v105:
    v106 = v109;
    {
        fn = elt(env, 3); /* idqsimpcontr */
        return (*qfn1(fn))(qenv(fn), v106);
    }
}



/* Code for spoly_pair */

static Lisp_Object CC_spoly_pair(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v171, v172;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spoly_pair");
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
    v171 = v0;
/* end of prologue */
    v170 = v171;
    v170 = qcdr(v170);
    v170 = qcdr(v170);
    v170 = qcar(v170);
    stack[-2] = v170;
    v170 = v171;
    v170 = qcdr(v170);
    v170 = qcdr(v170);
    v170 = qcdr(v170);
    v170 = qcar(v170);
    stack[-1] = v170;
    v170 = v171;
    v170 = qcar(v170);
    stack[0] = v170;
    v170 = stack[-2];
    fn = elt(env, 1); /* xval */
    v171 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v170 = stack[0];
    fn = elt(env, 2); /* xdiv */
    v170 = (*qfn2(fn))(qenv(fn), v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    fn = elt(env, 3); /* mknwedge */
    v172 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v171 = (Lisp_Object)17; /* 1 */
    v170 = (Lisp_Object)17; /* 1 */
    v170 = list2star(v172, v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v171 = ncons(v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v170 = stack[-2];
    fn = elt(env, 4); /* wedgepf */
    v170 = (*qfn2(fn))(qenv(fn), v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    stack[-2] = v170;
    v170 = stack[-1];
    fn = elt(env, 1); /* xval */
    v171 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v170 = stack[0];
    fn = elt(env, 2); /* xdiv */
    v170 = (*qfn2(fn))(qenv(fn), v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    fn = elt(env, 3); /* mknwedge */
    v172 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v171 = (Lisp_Object)17; /* 1 */
    v170 = (Lisp_Object)17; /* 1 */
    v170 = list2star(v172, v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v171 = ncons(v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v170 = stack[-1];
    fn = elt(env, 4); /* wedgepf */
    v170 = (*qfn2(fn))(qenv(fn), v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    stack[-1] = v170;
    v171 = stack[-2];
    v170 = stack[-1];
    v170 = qcar(v170);
    v170 = qcdr(v170);
    fn = elt(env, 5); /* multpfsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v171 = stack[-1];
    v170 = stack[-2];
    v170 = qcar(v170);
    v170 = qcdr(v170);
    fn = elt(env, 5); /* multpfsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    v171 = (Lisp_Object)-15; /* -1 */
    v170 = (Lisp_Object)17; /* 1 */
    v170 = cons(v171, v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    fn = elt(env, 5); /* multpfsq */
    v170 = (*qfn2(fn))(qenv(fn), stack[-1], v170);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-3];
    {
        Lisp_Object v173 = stack[0];
        popv(4);
        fn = elt(env, 6); /* addpf */
        return (*qfn2(fn))(qenv(fn), v173, v170);
    }
/* error exit handlers */
v155:
    popv(4);
    return nil;
}



/* Code for hdiffterm */

static Lisp_Object CC_hdiffterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v169, v73, v170, v171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for hdiffterm");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v170 = v53;
    stack[0] = v0;
/* end of prologue */
    v73 = stack[0];
    v169 = (Lisp_Object)33; /* 2 */
    v169 = *(Lisp_Object *)((char *)v73 + (CELL-TAG_VECTOR) + ((int32_t)v169/(16/CELL)));
    v73 = v170;
    v169 = *(Lisp_Object *)((char *)v169 + (CELL-TAG_VECTOR) + ((int32_t)v73/(16/CELL)));
    v171 = v169;
    v73 = v171;
    v169 = (Lisp_Object)1; /* 0 */
    if (v73 == v169) goto v32;
    v73 = v171;
    v169 = (Lisp_Object)17; /* 1 */
    v170 = cons(v73, v169);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    v73 = stack[0];
    v169 = (Lisp_Object)1; /* 0 */
    v169 = *(Lisp_Object *)((char *)v73 + (CELL-TAG_VECTOR) + ((int32_t)v169/(16/CELL)));
    fn = elt(env, 4); /* multsq */
    v169 = (*qfn2(fn))(qenv(fn), v170, v169);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    v171 = v169;
    v73 = stack[0];
    v169 = (Lisp_Object)17; /* 1 */
    v73 = *(Lisp_Object *)((char *)v73 + (CELL-TAG_VECTOR) + ((int32_t)v169/(16/CELL)));
    v169 = elt(env, 2); /* cos */
    if (v73 == v169) goto v23;
    v170 = elt(env, 2); /* cos */
    v73 = stack[0];
    v169 = (Lisp_Object)33; /* 2 */
    v169 = *(Lisp_Object *)((char *)v73 + (CELL-TAG_VECTOR) + ((int32_t)v169/(16/CELL)));
    v73 = v171;
    {
        popv(3);
        fn = elt(env, 5); /* make!-term */
        return (*qfnn(fn))(qenv(fn), 3, v170, v169, v73);
    }

v23:
    stack[-1] = elt(env, 3); /* sin */
    v73 = stack[0];
    v169 = (Lisp_Object)33; /* 2 */
    stack[0] = *(Lisp_Object *)((char *)v73 + (CELL-TAG_VECTOR) + ((int32_t)v169/(16/CELL)));
    v169 = v171;
    fn = elt(env, 6); /* negsq */
    v169 = (*qfn1(fn))(qenv(fn), v169);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    {
        Lisp_Object v156 = stack[-1];
        Lisp_Object v155 = stack[0];
        popv(3);
        fn = elt(env, 5); /* make!-term */
        return (*qfnn(fn))(qenv(fn), 3, v156, v155, v169);
    }

v32:
    v169 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v169); }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for xprinf2 */

static Lisp_Object CC_xprinf2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xprinf2");
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
    goto v38;

v38:
    v28 = stack[0];
    if (!consp(v28)) goto v108;
    v28 = stack[0];
    v28 = qcar(v28);
    if (!consp(v28)) goto v108;
    v28 = stack[0];
    v29 = qcar(v28);
    v28 = stack[-1];
    fn = elt(env, 5); /* xprint */
    v28 = (*qfn2(fn))(qenv(fn), v29, v28);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    v28 = qvalue(elt(env, 2)); /* t */
    stack[-1] = v28;
    goto v38;

v108:
    v28 = stack[0];
    if (v28 == nil) goto v30;
    v28 = stack[0];
    fn = elt(env, 6); /* minusf */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    if (v28 == nil) goto v118;
    v28 = elt(env, 3); /* minus */
    fn = elt(env, 7); /* oprin */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v28 = stack[0];
    fn = elt(env, 8); /* !:minus */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    stack[0] = v28;
    goto v74;

v74:
    v28 = stack[0];
    if (!consp(v28)) goto v122;
    v28 = stack[0];
    fn = elt(env, 9); /* maprin */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v136;
    goto v130;

v130:
    v28 = nil;
    { popv(3); return onevalue(v28); }

v122:
    v28 = stack[0];
    fn = elt(env, 10); /* prin2!* */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v136;
    goto v130;

v118:
    v28 = stack[-1];
    if (v28 == nil) goto v74;
    v28 = elt(env, 4); /* plus */
    fn = elt(env, 7); /* oprin */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    goto v74;

v30:
    v28 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v28); }
/* error exit handlers */
v136:
    popv(3);
    return nil;
}



/* Code for count!-linear!-factors!-mod!-p */

static Lisp_Object MS_CDECL CC_countKlinearKfactorsKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v53,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213, v214, v215, v216;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "count-linear-factors-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for count-linear-factors-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push3(v34,v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v53,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v34;
    stack[-2] = v53;
    stack[-3] = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* linear!-factors */
    qvalue(elt(env, 1)) = nil; /* linear!-factors */
    v212 = (Lisp_Object)1; /* 0 */
    v216 = v212;
    goto v96;

v96:
    v213 = qvalue(elt(env, 2)); /* dpoly */
    v212 = v216;
    v212 = (Lisp_Object)(int32_t)((int32_t)v213 - (int32_t)v212 + TAG_FIXNUM);
    v212 = ((intptr_t)(v212) < 0 ? lisp_true : nil);
    if (v212 == nil) goto v112;
    v214 = qvalue(elt(env, 5)); /* current!-modulus */
    v213 = stack[-3];
    v212 = stack[-1];
    fn = elt(env, 6); /* make!-x!-to!-p */
    v212 = (*qfnn(fn))(qenv(fn), 3, v214, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    stack[-4] = v212;
    v212 = (Lisp_Object)1; /* 0 */
    v216 = v212;
    goto v102;

v102:
    v213 = stack[-4];
    v212 = v216;
    v212 = (Lisp_Object)(int32_t)((int32_t)v213 - (int32_t)v212 + TAG_FIXNUM);
    v212 = ((intptr_t)(v212) < 0 ? lisp_true : nil);
    if (v212 == nil) goto v39;
    v213 = stack[-4];
    v212 = (Lisp_Object)17; /* 1 */
    if (((int32_t)(v213)) < ((int32_t)(v212))) goto v175;
    v215 = stack[-3];
    v214 = (Lisp_Object)17; /* 1 */
    v213 = stack[-3];
    v212 = (Lisp_Object)17; /* 1 */
    v213 = *(Lisp_Object *)((char *)v213 + (CELL-TAG_VECTOR) + ((int32_t)v212/(16/CELL)));
    v212 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v213) - int_of_fixnum(v212);
        if (w < 0) w += current_modulus;
        v212 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL))) = v212;
    v213 = stack[-4];
    v212 = (Lisp_Object)17; /* 1 */
    if (!(v213 == v212)) goto v4;
    v213 = stack[-3];
    v212 = (Lisp_Object)17; /* 1 */
    v213 = *(Lisp_Object *)((char *)v213 + (CELL-TAG_VECTOR) + ((int32_t)v212/(16/CELL)));
    v212 = (Lisp_Object)1; /* 0 */
    if (!(v213 == v212)) goto v4;
    v213 = stack[-3];
    v212 = (Lisp_Object)1; /* 0 */
    v213 = *(Lisp_Object *)((char *)v213 + (CELL-TAG_VECTOR) + ((int32_t)v212/(16/CELL)));
    v212 = (Lisp_Object)1; /* 0 */
    if (v213 == v212) goto v143;
    v212 = (Lisp_Object)1; /* 0 */
    stack[-4] = v212;
    goto v4;

v4:
    v213 = stack[-4];
    v212 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v213)) < ((int32_t)(v212))) goto v218;
    v215 = stack[-3];
    v214 = stack[-4];
    v213 = stack[-2];
    v212 = qvalue(elt(env, 2)); /* dpoly */
    fn = elt(env, 7); /* gcd!-in!-vector */
    v212 = (*qfnn(fn))(qenv(fn), 4, v215, v214, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    stack[-1] = v212;
    goto v219;

v219:
    v212 = stack[-1];
    v212 = Lmkvect(nil, v212);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    qvalue(elt(env, 1)) = v212; /* linear!-factors */
    v212 = (Lisp_Object)1; /* 0 */
    v216 = v212;
    goto v220;

v220:
    v213 = stack[-1];
    v212 = v216;
    v212 = (Lisp_Object)(int32_t)((int32_t)v213 - (int32_t)v212 + TAG_FIXNUM);
    v212 = ((intptr_t)(v212) < 0 ? lisp_true : nil);
    if (v212 == nil) goto v221;
    v215 = qvalue(elt(env, 4)); /* poly!-vector */
    v214 = qvalue(elt(env, 2)); /* dpoly */
    v213 = qvalue(elt(env, 1)); /* linear!-factors */
    v212 = stack[-1];
    fn = elt(env, 8); /* quotfail!-in!-vector */
    v212 = (*qfnn(fn))(qenv(fn), 4, v215, v214, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    qvalue(elt(env, 2)) = v212; /* dpoly */
    v214 = stack[-1];
    v213 = qvalue(elt(env, 1)); /* linear!-factors */
    v212 = stack[-4];
    v212 = list3(v214, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[0]; /* linear!-factors */
    { popv(6); return onevalue(v212); }

v221:
    v215 = qvalue(elt(env, 1)); /* linear!-factors */
    v214 = v216;
    v213 = stack[-3];
    v212 = v216;
    v212 = *(Lisp_Object *)((char *)v213 + (CELL-TAG_VECTOR) + ((int32_t)v212/(16/CELL)));
    *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL))) = v212;
    v212 = v216;
    v212 = (Lisp_Object)((int32_t)(v212) + 0x10);
    v216 = v212;
    goto v220;

v218:
    v214 = stack[-2];
    v213 = qvalue(elt(env, 2)); /* dpoly */
    v212 = stack[-3];
    fn = elt(env, 9); /* copy!-vector */
    v212 = (*qfnn(fn))(qenv(fn), 3, v214, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v217;
    env = stack[-5];
    stack[-1] = v212;
    goto v219;

v143:
    v212 = (Lisp_Object)-15; /* -1 */
    stack[-4] = v212;
    goto v4;

v175:
    v213 = stack[-4];
    v212 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v213)) < ((int32_t)(v212)))) goto v166;
    v214 = stack[-3];
    v213 = (Lisp_Object)1; /* 0 */
    v212 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v213/(16/CELL))) = v212;
    goto v166;

v166:
    v214 = stack[-3];
    v213 = (Lisp_Object)17; /* 1 */
    v212 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v212);
        if (w != 0) w = current_modulus - w;
        v212 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v214 + (CELL-TAG_VECTOR) + ((int32_t)v213/(16/CELL))) = v212;
    v212 = (Lisp_Object)17; /* 1 */
    stack[-4] = v212;
    goto v4;

v39:
    v215 = stack[-3];
    v214 = v216;
    v213 = stack[-1];
    v212 = v216;
    v212 = *(Lisp_Object *)((char *)v213 + (CELL-TAG_VECTOR) + ((int32_t)v212/(16/CELL)));
    *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL))) = v212;
    v212 = v216;
    v212 = (Lisp_Object)((int32_t)(v212) + 0x10);
    v216 = v212;
    goto v102;

v112:
    v215 = stack[-2];
    v214 = v216;
    v213 = qvalue(elt(env, 4)); /* poly!-vector */
    v212 = v216;
    v212 = *(Lisp_Object *)((char *)v213 + (CELL-TAG_VECTOR) + ((int32_t)v212/(16/CELL)));
    *(Lisp_Object *)((char *)v215 + (CELL-TAG_VECTOR) + ((int32_t)v214/(16/CELL))) = v212;
    v212 = v216;
    v212 = (Lisp_Object)((int32_t)(v212) + 0x10);
    v216 = v212;
    goto v96;
/* error exit handlers */
v217:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[0]; /* linear!-factors */
    popv(6);
    return nil;
}



/* Code for exprsize */

static Lisp_Object CC_exprsize(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v121, v74;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exprsize");
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
    v121 = (Lisp_Object)1; /* 0 */
    stack[-1] = v121;
    goto v56;

v56:
    v121 = stack[0];
    if (v121 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v121 = stack[0];
    if (!consp(v121)) goto v106;
    v121 = stack[0];
    v121 = qcar(v121);
    v74 = CC_exprsize(env, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    v121 = stack[-1];
    v121 = plus2(v74, v121);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-2];
    stack[-1] = v121;
    v121 = stack[0];
    v121 = qcdr(v121);
    stack[0] = v121;
    goto v56;

v106:
    v121 = stack[-1];
    popv(3);
    return add1(v121);
/* error exit handlers */
v123:
    popv(3);
    return nil;
}



/* Code for linineqnormalize */

static Lisp_Object CC_linineqnormalize(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v143, v226;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for linineqnormalize");
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
    v145 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-1] = v145;
    goto v106;

v106:
    v145 = stack[-1];
    if (v145 == nil) goto v71;
    v145 = stack[-1];
    v145 = qcar(v145);
    v143 = v145;
    v145 = v143;
    v145 = qcar(v145);
    stack[-3] = v145;
    v145 = v143;
    v145 = qcdr(v145);
    stack[0] = v145;
    stack[-2] = stack[-3];
    v145 = stack[0];
    fn = elt(env, 4); /* negsq */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 5); /* addsq */
    v145 = (*qfn2(fn))(qenv(fn), stack[-2], v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-3] = v145;
    v145 = stack[-3];
    v145 = qcar(v145);
    stack[-3] = v145;
    v145 = stack[-3];
    stack[0] = v145;
    v145 = stack[-3];
    if (!consp(v145)) goto v114;
    v145 = stack[-3];
    v145 = qcar(v145);
    if (!consp(v145)) goto v114;
    v145 = stack[0];
    v145 = qcar(v145);
    v145 = qcdr(v145);
    goto v124;

v124:
    stack[-2] = v145;
    goto v131;

v131:
    v145 = stack[0];
    if (!consp(v145)) goto v116;
    v145 = stack[0];
    v145 = qcar(v145);
    if (!consp(v145)) goto v116;
    v143 = stack[-2];
    v145 = stack[0];
    v145 = qcar(v145);
    v145 = qcdr(v145);
    fn = elt(env, 6); /* gcdf */
    v145 = (*qfn2(fn))(qenv(fn), v143, v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-2] = v145;
    v145 = stack[0];
    v145 = qcdr(v145);
    stack[0] = v145;
    goto v131;

v116:
    v145 = stack[0];
    fn = elt(env, 7); /* negf */
    v145 = (*qfn1(fn))(qenv(fn), v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[0] = v145;
    v143 = stack[-3];
    v145 = stack[0];
    fn = elt(env, 8); /* addf */
    v143 = (*qfn2(fn))(qenv(fn), v143, v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v145 = (Lisp_Object)17; /* 1 */
    stack[-3] = cons(v143, v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v143 = (Lisp_Object)17; /* 1 */
    v145 = stack[-2];
    v145 = cons(v143, v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 9); /* multsq */
    v145 = (*qfn2(fn))(qenv(fn), stack[-3], v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-3] = v145;
    v143 = stack[0];
    v145 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v143, v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    v143 = (Lisp_Object)17; /* 1 */
    v145 = stack[-2];
    v145 = cons(v143, v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    fn = elt(env, 9); /* multsq */
    v145 = (*qfn2(fn))(qenv(fn), stack[0], v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[0] = v145;
    v143 = stack[-3];
    v145 = stack[-4];
    v145 = Lassoc(nil, v143, v145);
    stack[-2] = v145;
    v145 = stack[-2];
    if (v145 == nil) goto v93;
    v145 = stack[-2];
    v143 = qcdr(v145);
    v145 = stack[0];
    fn = elt(env, 10); /* sqlessp */
    v145 = (*qfn2(fn))(qenv(fn), v143, v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    if (v145 == nil) goto v11;
    v143 = stack[-2];
    v145 = stack[0];
    v145 = Lrplacd(nil, v143, v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    goto v11;

v11:
    v145 = stack[-1];
    v145 = qcdr(v145);
    stack[-1] = v145;
    goto v106;

v93:
    v226 = stack[-3];
    v143 = stack[0];
    v145 = stack[-4];
    v145 = acons(v226, v143, v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-5];
    stack[-4] = v145;
    goto v11;

v114:
    v145 = (Lisp_Object)17; /* 1 */
    goto v124;

v71:
    v145 = qvalue(elt(env, 2)); /* !*trlinineq */
    if (v145 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v143 = elt(env, 3); /* "normalized and reduced:" */
    v145 = stack[-4];
    fn = elt(env, 11); /* linineqprint2 */
    v145 = (*qfn2(fn))(qenv(fn), v143, v145);
    nil = C_nil;
    if (exception_pending()) goto v227;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
/* error exit handlers */
v227:
    popv(6);
    return nil;
}



/* Code for crzchk */

static Lisp_Object MS_CDECL CC_crzchk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v53,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v84, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "crzchk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crzchk");
#endif
    if (stack >= stacklimit)
    {
        push3(v34,v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v53,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v34;
    stack[-1] = v53;
    stack[-2] = v0;
/* end of prologue */
    v48 = stack[-2];
    v48 = qcar(v48);
    if (!consp(v48)) goto v96;
    v48 = stack[-2];
    fn = elt(env, 5); /* bfrsq */
    stack[-3] = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v48 = stack[-1];
    fn = elt(env, 5); /* bfrsq */
    v84 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v48 = qvalue(elt(env, 3)); /* cr!-tolerance!* */
    fn = elt(env, 6); /* csl_timbf */
    v48 = (*qfn2(fn))(qenv(fn), v84, v48);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    fn = elt(env, 7); /* lessp!: */
    v48 = (*qfn2(fn))(qenv(fn), stack[-3], v48);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    if (v48 == nil) goto v49;
    v48 = qvalue(elt(env, 4)); /* bfz!* */
    v84 = qvalue(elt(env, 4)); /* bfz!* */
    popv(5);
    return cons(v48, v84);

v49:
    v48 = stack[-2];
    v157 = qcar(v48);
    v48 = stack[-1];
    v84 = qcar(v48);
    v48 = stack[0];
    v48 = qcar(v48);
    fn = elt(env, 8); /* rdzchk */
    stack[-3] = (*qfnn(fn))(qenv(fn), 3, v157, v84, v48);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v48 = stack[-2];
    v157 = qcdr(v48);
    v48 = stack[-1];
    v84 = qcdr(v48);
    v48 = stack[0];
    v48 = qcdr(v48);
    fn = elt(env, 8); /* rdzchk */
    v48 = (*qfnn(fn))(qenv(fn), 3, v157, v84, v48);
    nil = C_nil;
    if (exception_pending()) goto v170;
    {
        Lisp_Object v171 = stack[-3];
        popv(5);
        return cons(v171, v48);
    }

v96:
    v48 = stack[-2];
    fn = elt(env, 5); /* bfrsq */
    stack[-3] = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v48 = stack[-1];
    fn = elt(env, 5); /* bfrsq */
    v84 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v48 = qvalue(elt(env, 1)); /* !!fleps2 */
    v48 = times2(v84, v48);
    nil = C_nil;
    if (exception_pending()) goto v170;
    env = stack[-4];
    v48 = (Lisp_Object)lessp2(stack[-3], v48);
    nil = C_nil;
    if (exception_pending()) goto v170;
    v48 = v48 ? lisp_true : nil;
    env = stack[-4];
    if (v48 == nil) goto v49;
    v48 = elt(env, 2); /* 0.0 */
    v84 = elt(env, 2); /* 0.0 */
    popv(5);
    return cons(v48, v84);
/* error exit handlers */
v170:
    popv(5);
    return nil;
}



/* Code for gd_revalevalop */

static Lisp_Object CC_gd_revalevalop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_revalevalop");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    v17 = v53;
    stack[-5] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    v172 = elt(env, 1); /* geg */
    stack[-6] = v172;
    v172 = v17;
    stack[-1] = v172;
    goto v106;

v106:
    v172 = stack[-1];
    if (v172 == nil) goto v71;
    v172 = stack[-1];
    v172 = qcar(v172);
    stack[0] = v172;
    v172 = stack[0];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v17 = qcar(v172);
    v172 = elt(env, 3); /* ger */
    if (v17 == v172) goto v67;
    v17 = stack[0];
    v172 = stack[-4];
    v172 = cons(v17, v172);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[-4] = v172;
    goto v24;

v24:
    v172 = stack[0];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v17 = qcar(v172);
    v172 = stack[-3];
    v172 = cons(v17, v172);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[-3] = v172;
    v172 = stack[0];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v17 = qcar(v172);
    v172 = stack[-2];
    v172 = cons(v17, v172);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[-2] = v172;
    v172 = stack[-1];
    v172 = qcdr(v172);
    stack[-1] = v172;
    goto v106;

v67:
    v172 = elt(env, 3); /* ger */
    stack[-6] = v172;
    v18 = elt(env, 4); /* ge */
    v172 = stack[0];
    v172 = qcdr(v172);
    v17 = qcdr(v172);
    v172 = stack[-4];
    v172 = acons(v18, v17, v172);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    stack[-4] = v172;
    goto v24;

v71:
    v172 = stack[-3];
    v172 = Lnreverse(nil, v172);
    env = stack[-7];
    stack[-3] = v172;
    v172 = stack[-2];
    v172 = Lnreverse(nil, v172);
    env = stack[-7];
    stack[-2] = v172;
    v172 = stack[-4];
    v172 = Lnreverse(nil, v172);
    env = stack[-7];
    stack[-4] = v172;
    stack[0] = stack[-5];
    stack[-1] = stack[-6];
    v17 = stack[-3];
    v172 = stack[-2];
    v17 = list2(v17, v172);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-7];
    v172 = stack[-4];
    {
        Lisp_Object v210 = stack[0];
        Lisp_Object v166 = stack[-1];
        popv(8);
        fn = elt(env, 5); /* gd_revalevalop1 */
        return (*qfnn(fn))(qenv(fn), 4, v210, v166, v17, v172);
    }
/* error exit handlers */
v83:
    popv(8);
    return nil;
}



/* Code for ofsf_ignshift */

static Lisp_Object CC_ofsf_ignshift(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v102, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ignshift");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v53;
    stack[-1] = v0;
/* end of prologue */
    v75 = stack[-1];
    v75 = qcdr(v75);
    v102 = qcar(v75);
    v75 = stack[0];
    fn = elt(env, 5); /* sfto_reorder */
    v75 = (*qfn2(fn))(qenv(fn), v102, v75);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-2];
    v119 = v75;
    v75 = v119;
    if (!consp(v75)) goto v128;
    v75 = v119;
    v75 = qcar(v75);
    if (!consp(v75)) goto v128;
    v75 = v119;
    v75 = qcdr(v75);
    if (!(v75 == nil)) goto v128;
    v75 = v119;
    v75 = qcar(v75);
    v75 = qcar(v75);
    v102 = qcar(v75);
    v75 = stack[0];
    if (!(v102 == v75)) goto v128;
    v75 = qvalue(elt(env, 1)); /* !*rlpos */
    if (!(v75 == nil)) goto v99;
    v75 = stack[-1];
    v102 = qcar(v75);
    v75 = elt(env, 2); /* (equal neq) */
    v75 = Lmemq(nil, v102, v75);
    if (!(v75 == nil)) goto v99;
    v75 = v119;
    v75 = qcar(v75);
    v75 = qcar(v75);
    v75 = qcdr(v75);
    v75 = Levenp(nil, v75);
    env = stack[-2];
    if (!(v75 == nil)) goto v99;
    v75 = elt(env, 4); /* odd */
    { popv(3); return onevalue(v75); }

v99:
    v75 = elt(env, 3); /* ignore */
    { popv(3); return onevalue(v75); }

v128:
    v75 = nil;
    { popv(3); return onevalue(v75); }
/* error exit handlers */
v60:
    popv(3);
    return nil;
}



/* Code for preptaylor!* */

static Lisp_Object CC_preptaylorH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v129, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaylor*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v96 = v0;
/* end of prologue */
    v129 = v96;
    v129 = qcdr(v129);
    v120 = qcar(v129);
    v96 = qcdr(v96);
    v96 = qcdr(v96);
    v129 = qcar(v96);
    v96 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* preptaylor!*1 */
        return (*qfnn(fn))(qenv(fn), 3, v120, v129, v96);
    }
}



/* Code for mk!+null!+vec */

static Lisp_Object CC_mkLnullLvec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v102;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+null+vec");
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
    v102 = qvalue(elt(env, 1)); /* nil */
    v75 = (Lisp_Object)17; /* 1 */
    v75 = cons(v102, v75);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-6];
    stack[-5] = v75;
    v75 = (Lisp_Object)17; /* 1 */
    stack[-3] = v75;
    v102 = stack[-4];
    v75 = stack[-3];
    v75 = difference2(v102, v75);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-6];
    v75 = Lminusp(nil, v75);
    env = stack[-6];
    if (v75 == nil) goto v32;
    v75 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v75); }

v32:
    v75 = stack[-5];
    v75 = ncons(v75);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-6];
    stack[-1] = v75;
    stack[-2] = v75;
    goto v120;

v120:
    v75 = stack[-3];
    v75 = add1(v75);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-6];
    stack[-3] = v75;
    v102 = stack[-4];
    v75 = stack[-3];
    v75 = difference2(v102, v75);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-6];
    v75 = Lminusp(nil, v75);
    env = stack[-6];
    if (!(v75 == nil)) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v75 = stack[-5];
    v75 = ncons(v75);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-6];
    v75 = Lrplacd(nil, stack[0], v75);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-6];
    v75 = stack[-1];
    v75 = qcdr(v75);
    stack[-1] = v75;
    goto v120;
/* error exit handlers */
v23:
    popv(7);
    return nil;
}



/* Code for vdp_putprop */

static Lisp_Object MS_CDECL CC_vdp_putprop(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v53,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v116, v131, v28, v29;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vdp_putprop");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_putprop");
#endif
    if (stack >= stacklimit)
    {
        push3(v34,v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v53,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v131 = v34;
    v28 = v53;
    stack[0] = v0;
/* end of prologue */
    v103 = stack[0];
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    v116 = v103;
    v29 = v28;
    v103 = v116;
    v103 = qcar(v103);
    v103 = Latsoc(nil, v29, v103);
    v29 = v103;
    v103 = v29;
    if (v103 == nil) goto v65;
    v103 = v29;
    v116 = v131;
    v103 = Lrplacd(nil, v103, v116);
    nil = C_nil;
    if (exception_pending()) goto v136;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v65:
    stack[-1] = v116;
    v103 = v28;
    v116 = qcar(v116);
    v103 = acons(v103, v131, v116);
    nil = C_nil;
    if (exception_pending()) goto v136;
    env = stack[-2];
    v103 = Lrplaca(nil, stack[-1], v103);
    nil = C_nil;
    if (exception_pending()) goto v136;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
v136:
    popv(3);
    return nil;
}



/* Code for bc_sum */

static Lisp_Object CC_bc_sum(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_sum");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v72 = v53;
    v71 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* addf */
        return (*qfn2(fn))(qenv(fn), v71, v72);
    }
}



/* Code for ps!:big!-o */

static Lisp_Object CC_psTbigKo(Lisp_Object env,
                         Lisp_Object v53, Lisp_Object v34)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:big-o");
#endif
    if (stack >= stacklimit)
    {
        push2(v34,v53);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v53,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v34;
    v117 = v53;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v117; /* ps */
    stack[-1] = elt(env, 2); /* "O" */
    v117 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 4); /* ps!:mkvar */
    stack[0] = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v117 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 5); /* ps!:expansion!-point */
    v113 = (*qfn1(fn))(qenv(fn), v117);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v117 = elt(env, 3); /* ps!:inf */
    v117 = (v113 == v117 ? lisp_true : nil);
    fn = elt(env, 6); /* ps!:mkpow */
    v117 = (*qfnn(fn))(qenv(fn), 3, stack[0], stack[-2], v117);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    v117 = cons(stack[-1], v117);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    { popv(5); return onevalue(v117); }
/* error exit handlers */
v89:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* ps */
    popv(5);
    return nil;
}



/* Code for bf2flr */

static Lisp_Object CC_bf2flr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v230, v231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bf2flr");
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
    stack[-2] = nil;
    v230 = stack[-3];
    fn = elt(env, 8); /* bfzerop!: */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    if (v230 == nil) goto v110;
    v230 = elt(env, 1); /* 0.0 */
    { popv(6); return onevalue(v230); }

v110:
    v231 = stack[-3];
    v230 = qvalue(elt(env, 2)); /* !!nbfpd */
    fn = elt(env, 9); /* round!:mt */
    v230 = (*qfn2(fn))(qenv(fn), v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    stack[-3] = v230;
    v230 = qcdr(v230);
    v230 = qcdr(v230);
    stack[-4] = v230;
    stack[0] = qvalue(elt(env, 3)); /* !!minflbf */
    v230 = stack[-3];
    fn = elt(env, 10); /* abs!: */
    v230 = (*qfn1(fn))(qenv(fn), v230);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    stack[-1] = v230;
    fn = elt(env, 11); /* grpbf */
    v230 = (*qfn2(fn))(qenv(fn), stack[0], v230);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    if (!(v230 == nil)) goto v67;
    v231 = stack[-1];
    v230 = qvalue(elt(env, 4)); /* !!maxflbf */
    fn = elt(env, 11); /* grpbf */
    v230 = (*qfn2(fn))(qenv(fn), v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    if (!(v230 == nil)) goto v67;

v64:
    v231 = stack[-4];
    v230 = (Lisp_Object)1; /* 0 */
    v230 = (Lisp_Object)lessp2(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v82;
    v230 = v230 ? lisp_true : nil;
    env = stack[-5];
    if (v230 == nil) goto v160;
    v231 = stack[-4];
    v230 = qvalue(elt(env, 2)); /* !!nbfpd */
    v230 = plus2(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    stack[-4] = v230;
    v230 = qvalue(elt(env, 5)); /* t */
    stack[-2] = v230;
    goto v160;

v160:
    v231 = elt(env, 6); /* 2.0 */
    v230 = stack[-4];
    v230 = Lexpt(nil, v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    stack[-4] = v230;
    v231 = stack[-4];
    v230 = elt(env, 1); /* 0.0 */
    if (!(equal(v231, v230))) goto v232;
    v230 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    goto v232;

v232:
    v230 = stack[-2];
    if (v230 == nil) goto v233;
    stack[0] = stack[-4];
    v230 = stack[-3];
    v230 = qcdr(v230);
    v231 = qcar(v230);
    v230 = qvalue(elt(env, 7)); /* !!flbint */
    v230 = quot2(v231, v230);
    nil = C_nil;
    if (exception_pending()) goto v82;
    {
        Lisp_Object v78 = stack[0];
        popv(6);
        return times2(v78, v230);
    }

v233:
    v231 = stack[-4];
    v230 = stack[-3];
    v230 = qcdr(v230);
    v230 = qcar(v230);
    popv(6);
    return times2(v231, v230);

v67:
    v230 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-5];
    goto v64;
/* error exit handlers */
v82:
    popv(6);
    return nil;
}



/* Code for simpco */

static Lisp_Object CC_simpco(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v59, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpco");
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
    v60 = stack[0];
    v59 = Llength(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    v60 = (Lisp_Object)33; /* 2 */
    if (!(v59 == v60)) goto v97;
    v60 = stack[0];
    v60 = qcar(v60);
    v60 = integerp(v60);
    if (!(v60 == nil)) goto v38;

v97:
    v59 = stack[0];
    v60 = elt(env, 1); /* "nested coefficient" */
    fn = elt(env, 5); /* typerr */
    v60 = (*qfn2(fn))(qenv(fn), v59, v60);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    goto v38;

v38:
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcar(v60);
    fn = elt(env, 6); /* simp */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    v104 = v60;
    v60 = stack[0];
    v60 = qcar(v60);
    v59 = v60;
    v60 = v104;
    v60 = qcar(v60);
    if (v60 == nil) goto v101;
    stack[-1] = elt(env, 3); /* !:nest!: */
    stack[0] = v59;
    v60 = qvalue(elt(env, 4)); /* dmode!* */
    v59 = v104;
    v60 = cons(v60, v59);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-2];
    v60 = list2star(stack[-1], stack[0], v60);
    nil = C_nil;
    if (exception_pending()) goto v225;
    v59 = v60;
    goto v88;

v88:
    v60 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v59, v60);

v101:
    v60 = qvalue(elt(env, 2)); /* nil */
    v59 = v60;
    goto v88;
/* error exit handlers */
v225:
    popv(3);
    return nil;
}



/* Code for redmsg */

static Lisp_Object CC_redmsg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v103, v116, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for redmsg");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v53;
    stack[-1] = v0;
/* end of prologue */
    v62 = qvalue(elt(env, 1)); /* !*wsm */
    if (!(v62 == nil)) goto v56;
    v62 = qvalue(elt(env, 2)); /* !*msg */
    if (v62 == nil) goto v56;
    v103 = stack[0];
    v62 = elt(env, 3); /* "operator" */
    if (!(equal(v103, v62))) goto v56;
    fn = elt(env, 8); /* terminalp */
    v62 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    if (v62 == nil) goto v25;
    v131 = elt(env, 5); /* "Declare" */
    v116 = stack[-1];
    v103 = stack[0];
    v62 = elt(env, 6); /* "?" */
    v62 = list4(v131, v116, v103, v62);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    fn = elt(env, 9); /* yesp */
    v62 = (*qfn1(fn))(qenv(fn), v62);
    nil = C_nil;
    if (exception_pending()) goto v27;
    if (!(v62 == nil)) { popv(3); return onevalue(v62); }
        popv(3);
        return Lerror0(nil, 0);

v25:
    v116 = stack[-1];
    v103 = elt(env, 7); /* "declared" */
    v62 = stack[0];
    v62 = list3(v116, v103, v62);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 10); /* lprim */
        return (*qfn1(fn))(qenv(fn), v62);
    }

v56:
    v62 = qvalue(elt(env, 4)); /* nil */
    { popv(3); return onevalue(v62); }
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for cvt5 */

static Lisp_Object CC_cvt5(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cvt5");
#endif
    if (stack >= stacklimit)
    {
        push2(v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v53;
    v111 = v0;
/* end of prologue */
    v67 = v111;
    v111 = (Lisp_Object)321; /* 20 */
    fn = elt(env, 1); /* round!:mt */
    stack[-1] = (*qfn2(fn))(qenv(fn), v67, v111);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    v67 = stack[0];
    v111 = (Lisp_Object)321; /* 20 */
    fn = elt(env, 1); /* round!:mt */
    v111 = (*qfn2(fn))(qenv(fn), v67, v111);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-2];
    {
        Lisp_Object v121 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* equal!: */
        return (*qfn2(fn))(qenv(fn), v121, v111);
    }
/* error exit handlers */
v134:
    popv(3);
    return nil;
}



/* Code for compactsq */

static Lisp_Object MS_CDECL CC_compactsq(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v53,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v21, v20, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactsq");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactsq");
#endif
    if (stack >= stacklimit)
    {
        push3(v34,v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v53,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v34;
    stack[-2] = v53;
    stack[-3] = v0;
/* end of prologue */
    v19 = stack[-2];
    v21 = qcdr(v19);
    v19 = (Lisp_Object)17; /* 1 */
    if (v21 == v19) goto v38;
    stack[0] = elt(env, 1); /* "Relation denominator" */
    v19 = stack[-2];
    v19 = qcdr(v19);
    fn = elt(env, 4); /* prepf */
    v16 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-5];
    v20 = elt(env, 2); /* "discarded" */
    v21 = qvalue(elt(env, 3)); /* nil */
    v19 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 5); /* msgpri */
    v19 = (*qfnn(fn))(qenv(fn), 5, stack[0], v16, v20, v21, v19);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-5];
    goto v38;

v38:
    v19 = stack[-2];
    v19 = qcar(v19);
    stack[-2] = v19;
    v19 = stack[-3];
    v20 = qcar(v19);
    v21 = stack[-2];
    v19 = stack[-1];
    fn = elt(env, 6); /* compactf */
    v21 = (*qfnn(fn))(qenv(fn), 3, v20, v21, v19);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-5];
    v19 = (Lisp_Object)17; /* 1 */
    stack[-4] = cons(v21, v19);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-5];
    stack[0] = (Lisp_Object)17; /* 1 */
    v19 = stack[-3];
    v20 = qcdr(v19);
    v21 = stack[-2];
    v19 = stack[-1];
    fn = elt(env, 6); /* compactf */
    v19 = (*qfnn(fn))(qenv(fn), 3, v20, v21, v19);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-5];
    v19 = cons(stack[0], v19);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-5];
    {
        Lisp_Object v46 = stack[-4];
        popv(6);
        fn = elt(env, 7); /* multsq */
        return (*qfn2(fn))(qenv(fn), v46, v19);
    }
/* error exit handlers */
v211:
    popv(6);
    return nil;
}



/* Code for dp!=fnprod */

static Lisp_Object CC_dpMfnprod(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=fnprod");
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
    v74 = v0;
/* end of prologue */
    v30 = v74;
    v30 = qcar(v30);
    v74 = qcdr(v74);
    stack[0] = v74;
    goto v107;

v107:
    v74 = stack[0];
    if (v74 == nil) { popv(2); return onevalue(v30); }
    v74 = stack[0];
    v74 = qcar(v74);
    fn = elt(env, 2); /* dp_prod */
    v74 = (*qfn2(fn))(qenv(fn), v30, v74);
    nil = C_nil;
    if (exception_pending()) goto v123;
    env = stack[-1];
    v30 = v74;
    v74 = stack[0];
    v74 = qcdr(v74);
    stack[0] = v74;
    goto v107;
/* error exit handlers */
v123:
    popv(2);
    return nil;
}



/* Code for montest */

static Lisp_Object CC_montest(Lisp_Object env,
                         Lisp_Object v53)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for montest");
#endif
    if (stack >= stacklimit)
    {
        push(v53);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v53);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v122 = v53;
/* end of prologue */
    stack[-3] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    qvalue(elt(env, 1)) = v122; /* gg */
    v122 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v122;
    v122 = qvalue(elt(env, 3)); /* varlist */
    v122 = Llength(nil, v122);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    stack[-1] = v122;
    v122 = (Lisp_Object)17; /* 1 */
    stack[0] = v122;
    goto v111;

v111:
    v135 = stack[-1];
    v122 = stack[0];
    v122 = difference2(v135, v122);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    v122 = Lminusp(nil, v122);
    env = stack[-4];
    if (v122 == nil) goto v65;
    v122 = stack[-2];
    qvalue(elt(env, 1)) = stack[-3]; /* gg */
    { popv(5); return onevalue(v122); }

v65:
    v135 = qvalue(elt(env, 1)); /* gg */
    v122 = stack[0];
    fn = elt(env, 5); /* monicmember */
    v122 = (*qfn2(fn))(qenv(fn), v135, v122);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    if (!(v122 == nil)) goto v123;
    v122 = qvalue(elt(env, 4)); /* nil */
    stack[-2] = v122;
    v122 = stack[-1];
    v122 = add1(v122);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    stack[0] = v122;
    goto v123;

v123:
    v122 = stack[0];
    v122 = add1(v122);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-4];
    stack[0] = v122;
    goto v111;
/* error exit handlers */
v103:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[-3]; /* gg */
    popv(5);
    return nil;
}



/* Code for mkqmatr */

static Lisp_Object CC_mkqmatr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkqmatr");
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
    v42 = stack[-6];
    fn = elt(env, 3); /* mkqcol */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    stack[-7] = v42;
    v42 = qvalue(elt(env, 1)); /* arbase!* */
    v42 = Lreverse(nil, v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v42 = qcdr(v42);
    stack[-4] = v42;
    goto v106;

v106:
    v42 = stack[-4];
    if (v42 == nil) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    v42 = stack[-4];
    v42 = qcar(v42);
    v140 = v42;
    v42 = (Lisp_Object)17; /* 1 */
    v42 = cons(v140, v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = ncons(v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v42 = stack[-6];
    fn = elt(env, 4); /* multf */
    v42 = (*qfn2(fn))(qenv(fn), v140, v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    fn = elt(env, 5); /* reducepowers */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    stack[-5] = v42;
    v42 = qvalue(elt(env, 1)); /* arbase!* */
    stack[-3] = v42;
    v42 = stack[-3];
    if (v42 == nil) goto v135;
    v42 = stack[-3];
    v42 = qcar(v42);
    v140 = v42;
    v42 = v140;
    if (!consp(v42)) goto v119;
    v42 = stack[-5];
    if (!consp(v42)) goto v176;
    v42 = stack[-5];
    v42 = qcar(v42);
    if (!consp(v42)) goto v176;
    v42 = stack[-5];
    v42 = qcar(v42);
    v42 = qcar(v42);
    if (equal(v140, v42)) goto v47;
    v140 = (Lisp_Object)1; /* 0 */
    v42 = (Lisp_Object)17; /* 1 */
    v42 = cons(v140, v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = v42;
    goto v24;

v24:
    v42 = stack[-7];
    v42 = qcar(v42);
    v42 = cons(v140, v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = v42;
    v42 = stack[-7];
    v42 = qcdr(v42);
    stack[-7] = v42;
    v42 = v140;
    v42 = ncons(v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    stack[-1] = v42;
    stack[-2] = v42;
    goto v115;

v115:
    v42 = stack[-3];
    v42 = qcdr(v42);
    stack[-3] = v42;
    v42 = stack[-3];
    if (v42 == nil) goto v209;
    stack[0] = stack[-1];
    v42 = stack[-3];
    v42 = qcar(v42);
    v140 = v42;
    v42 = v140;
    if (!consp(v42)) goto v12;
    v42 = stack[-5];
    if (!consp(v42)) goto v205;
    v42 = stack[-5];
    v42 = qcar(v42);
    if (!consp(v42)) goto v205;
    v42 = stack[-5];
    v42 = qcar(v42);
    v42 = qcar(v42);
    if (equal(v140, v42)) goto v94;
    v140 = (Lisp_Object)1; /* 0 */
    v42 = (Lisp_Object)17; /* 1 */
    v42 = cons(v140, v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = v42;
    goto v80;

v80:
    v42 = stack[-7];
    v42 = qcar(v42);
    v42 = cons(v140, v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = v42;
    v42 = stack[-7];
    v42 = qcdr(v42);
    stack[-7] = v42;
    v42 = v140;
    v42 = ncons(v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v42 = Lrplacd(nil, stack[0], v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v42 = stack[-1];
    v42 = qcdr(v42);
    stack[-1] = v42;
    goto v115;

v94:
    v42 = stack[-5];
    v42 = qcar(v42);
    v42 = qcdr(v42);
    fn = elt(env, 6); /* ratn */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = v42;
    v42 = stack[-5];
    v42 = qcdr(v42);
    stack[-5] = v42;
    v42 = v140;
    v140 = v42;
    goto v80;

v205:
    v140 = (Lisp_Object)1; /* 0 */
    v42 = (Lisp_Object)17; /* 1 */
    v42 = cons(v140, v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = v42;
    goto v80;

v12:
    v42 = stack[-5];
    fn = elt(env, 6); /* ratn */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = v42;
    goto v80;

v209:
    v42 = stack[-2];
    goto v92;

v92:
    stack[-7] = v42;
    v42 = stack[-4];
    v42 = qcdr(v42);
    stack[-4] = v42;
    goto v106;

v47:
    v42 = stack[-5];
    v42 = qcar(v42);
    v42 = qcdr(v42);
    fn = elt(env, 6); /* ratn */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = v42;
    v42 = stack[-5];
    v42 = qcdr(v42);
    stack[-5] = v42;
    v42 = v140;
    v140 = v42;
    goto v24;

v176:
    v140 = (Lisp_Object)1; /* 0 */
    v42 = (Lisp_Object)17; /* 1 */
    v42 = cons(v140, v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = v42;
    goto v24;

v119:
    v42 = stack[-5];
    fn = elt(env, 6); /* ratn */
    v42 = (*qfn1(fn))(qenv(fn), v42);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-8];
    v140 = v42;
    goto v24;

v135:
    v42 = qvalue(elt(env, 2)); /* nil */
    goto v92;
/* error exit handlers */
v219:
    popv(9);
    return nil;
}



/* Code for msolve */

static Lisp_Object CC_msolve(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v246, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve");
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
    stack[-1] = v0;
/* end of prologue */
    stack[-6] = nil;
    stack[0] = nil;
    v245 = stack[-1];
    v245 = qcar(v245);
    fn = elt(env, 5); /* reval */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    stack[-2] = v245;
    v246 = stack[-2];
    v245 = elt(env, 1); /* list */
    if (!consp(v246)) goto v67;
    v246 = qcar(v246);
    if (!(v246 == v245)) goto v67;
    v245 = stack[-2];
    v245 = qcdr(v245);
    goto v106;

v106:
    stack[-2] = v245;
    v245 = stack[-1];
    v245 = qcdr(v245);
    if (v245 == nil) goto v74;
    v245 = stack[-1];
    v245 = qcdr(v245);
    v245 = qcar(v245);
    fn = elt(env, 5); /* reval */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    stack[-6] = v245;
    v246 = stack[-6];
    v245 = elt(env, 1); /* list */
    if (!consp(v246)) goto v26;
    v246 = qcar(v246);
    if (!(v246 == v245)) goto v26;
    v245 = stack[-6];
    v245 = qcdr(v245);
    goto v89;

v89:
    stack[-6] = v245;
    goto v74;

v74:
    v245 = stack[-2];
    stack[-4] = v245;
    v245 = stack[-4];
    if (v245 == nil) goto v102;
    v245 = stack[-4];
    v245 = qcar(v245);
    v219 = v245;
    v246 = v219;
    v245 = elt(env, 3); /* equal */
    if (!consp(v246)) goto v86;
    v246 = qcar(v246);
    if (!(v246 == v245)) goto v86;
    v245 = elt(env, 4); /* difference */
    v246 = v219;
    v246 = qcdr(v246);
    v245 = cons(v245, v246);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    v219 = v245;
    goto v86;

v86:
    v245 = v219;
    fn = elt(env, 6); /* simp */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    v246 = qcar(v245);
    v245 = (Lisp_Object)17; /* 1 */
    v245 = cons(v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    stack[-5] = v245;
    v245 = stack[-5];
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    fn = elt(env, 7); /* solvevars */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    fn = elt(env, 8); /* union */
    v245 = (*qfn2(fn))(qenv(fn), stack[0], v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    stack[0] = v245;
    v245 = stack[-5];
    v245 = qcar(v245);
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    stack[-2] = v245;
    stack[-3] = v245;
    goto v24;

v24:
    v245 = stack[-4];
    v245 = qcdr(v245);
    stack[-4] = v245;
    v245 = stack[-4];
    if (v245 == nil) goto v228;
    stack[-1] = stack[-2];
    v245 = stack[-4];
    v245 = qcar(v245);
    v219 = v245;
    v246 = v219;
    v245 = elt(env, 3); /* equal */
    if (!consp(v246)) goto v142;
    v246 = qcar(v246);
    if (!(v246 == v245)) goto v142;
    v245 = elt(env, 4); /* difference */
    v246 = v219;
    v246 = qcdr(v246);
    v245 = cons(v245, v246);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    v219 = v245;
    goto v142;

v142:
    v245 = v219;
    fn = elt(env, 6); /* simp */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    v246 = qcar(v245);
    v245 = (Lisp_Object)17; /* 1 */
    v245 = cons(v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    stack[-5] = v245;
    v245 = stack[-5];
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    fn = elt(env, 7); /* solvevars */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    fn = elt(env, 8); /* union */
    v245 = (*qfn2(fn))(qenv(fn), stack[0], v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    stack[0] = v245;
    v245 = stack[-5];
    v245 = qcar(v245);
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    v245 = Lrplacd(nil, stack[-1], v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    v245 = stack[-2];
    v245 = qcdr(v245);
    stack[-2] = v245;
    goto v24;

v228:
    v245 = stack[-3];
    goto v27;

v27:
    v246 = v245;
    v245 = stack[-6];
    if (!(v245 == nil)) goto v247;
    v245 = stack[0];
    stack[-6] = v245;
    goto v247;

v247:
    v245 = v246;
    v245 = qcdr(v245);
    if (v245 == nil) goto v226;
    v245 = stack[-6];
    fn = elt(env, 9); /* msolve!-psys */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    goto v5;

v5:
    {
        popv(8);
        fn = elt(env, 10); /* msolve!-result */
        return (*qfn1(fn))(qenv(fn), v245);
    }

v226:
    v245 = v246;
    v246 = qcar(v245);
    v245 = stack[-6];
    fn = elt(env, 11); /* msolve!-poly */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    goto v5;

v102:
    v245 = qvalue(elt(env, 2)); /* nil */
    goto v27;

v26:
    v245 = stack[-6];
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    goto v89;

v67:
    v245 = stack[-2];
    v245 = ncons(v245);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-7];
    goto v106;
/* error exit handlers */
v41:
    popv(8);
    return nil;
}



/* Code for unique!-f!-nos */

static Lisp_Object MS_CDECL CC_uniqueKfKnos(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v53,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v251, v252;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "unique-f-nos");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unique-f-nos");
#endif
    if (stack >= stacklimit)
    {
        push3(v34,v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v53,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v34;
    stack[-1] = v53;
    stack[-7] = v0;
/* end of prologue */
    v250 = stack[-7];
    v250 = qcdr(v250);
    v250 = Llength(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    stack[-5] = v250;
    v250 = stack[-1];
    if (is_number(v250)) goto v98;
    v250 = stack[-1];
    v250 = qcar(v250);
    v250 = qcdr(v250);
    stack[-1] = v250;
    goto v98;

v98:
    v250 = stack[-5];
    stack[-2] = Lmkvect(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    stack[-8] = stack[-2];
    stack[0] = (Lisp_Object)1; /* 0 */
    v251 = stack[-1];
    v250 = stack[-7];
    v250 = qcar(v250);
    v250 = times2(v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    v250 = Labsval(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v250;
    v250 = stack[-5];
    stack[-3] = Lmkvect(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    stack[-2] = stack[-3];
    stack[0] = (Lisp_Object)1; /* 0 */
    v251 = stack[-1];
    v250 = stack[-7];
    v250 = qcar(v250);
    v250 = times2(v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    v250 = Labsval(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v250;
    v250 = stack[-7];
    v250 = qcdr(v250);
    stack[-7] = v250;
    v250 = (Lisp_Object)17; /* 1 */
    stack[-1] = v250;
    goto v104;

v104:
    v251 = stack[-5];
    v250 = stack[-1];
    v250 = (Lisp_Object)(int32_t)((int32_t)v251 - (int32_t)v250 + TAG_FIXNUM);
    v250 = ((intptr_t)(v250) < 0 ? lisp_true : nil);
    if (!(v250 == nil)) { Lisp_Object res = stack[-2]; popv(10); return onevalue(res); }
    v250 = stack[-7];
    v250 = qcar(v250);
    v251 = qcar(v250);
    v250 = stack[-6];
    fn = elt(env, 2); /* make!-image */
    v250 = (*qfn2(fn))(qenv(fn), v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    v250 = Labsval(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    stack[-4] = v250;
    v252 = stack[-2];
    v251 = stack[-1];
    v250 = stack[-4];
    *(Lisp_Object *)((char *)v252 + (CELL-TAG_VECTOR) + ((int32_t)v251/(16/CELL))) = v250;
    v250 = stack[-7];
    v250 = qcdr(v250);
    stack[-7] = v250;
    v250 = stack[-1];
    v250 = (Lisp_Object)((int32_t)(v250) - 0x10);
    stack[0] = v250;
    goto v157;

v157:
    v250 = stack[0];
    v250 = ((intptr_t)(v250) < 0 ? lisp_true : nil);
    if (v250 == nil) goto v156;
    v250 = stack[-2];
    if (v250 == nil) goto v10;
    v252 = stack[-8];
    v251 = stack[-1];
    v250 = stack[-4];
    *(Lisp_Object *)((char *)v252 + (CELL-TAG_VECTOR) + ((int32_t)v251/(16/CELL))) = v250;
    goto v91;

v91:
    v250 = stack[-1];
    v250 = (Lisp_Object)((int32_t)(v250) + 0x10);
    stack[-1] = v250;
    goto v104;

v10:
    v250 = stack[-5];
    v250 = add1(v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    stack[-1] = v250;
    goto v91;

v156:
    v251 = stack[-8];
    v250 = stack[0];
    v250 = *(Lisp_Object *)((char *)v251 + (CELL-TAG_VECTOR) + ((int32_t)v250/(16/CELL)));
    stack[-3] = v250;
    goto v81;

v81:
    v250 = stack[-3];
    v250 = Lonep(nil, v250);
    env = stack[-9];
    if (v250 == nil) goto v208;
    v250 = stack[-4];
    v250 = Lonep(nil, v250);
    env = stack[-9];
    if (v250 == nil) goto v76;
    v250 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v250;
    v250 = (Lisp_Object)-15; /* -1 */
    stack[0] = v250;
    goto v76;

v76:
    v250 = stack[0];
    v250 = (Lisp_Object)((int32_t)(v250) - 0x10);
    stack[0] = v250;
    goto v157;

v208:
    v251 = stack[-3];
    v250 = stack[-4];
    v250 = Lgcd(nil, v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    stack[-3] = v250;
    v251 = stack[-4];
    v250 = stack[-3];
    v250 = quot2(v251, v250);
    nil = C_nil;
    if (exception_pending()) goto v253;
    env = stack[-9];
    stack[-4] = v250;
    goto v81;
/* error exit handlers */
v253:
    popv(10);
    return nil;
}



/* Code for ofsf_anegrel */

static Lisp_Object CC_ofsf_anegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v97, v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_anegrel");
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
    v111 = v0;
/* end of prologue */
    v97 = v111;
    v32 = elt(env, 1); /* ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp)) 
*/
    v32 = Latsoc(nil, v97, v32);
    v32 = qcdr(v32);
    if (!(v32 == nil)) { popv(1); return onevalue(v32); }
    v32 = elt(env, 2); /* "ofsf_anegrel: unknown operator " */
    v97 = v111;
    v32 = list2(v32, v97);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* rederr */
        return (*qfn1(fn))(qenv(fn), v32);
    }
/* error exit handlers */
v67:
    popv(1);
    return nil;
}



/* Code for addtaylor!* */

static Lisp_Object MS_CDECL CC_addtaylorH(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v53,
                         Lisp_Object v34, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v133, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "addtaylor*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addtaylor*");
#endif
    if (stack >= stacklimit)
    {
        push3(v34,v53,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v53,v34);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v34;
    stack[-2] = v53;
    stack[-3] = v0;
/* end of prologue */
    v47 = stack[-1];
    v16 = stack[-3];
    v16 = qcdr(v16);
    v133 = qcar(v16);
    v16 = stack[-2];
    v16 = qcdr(v16);
    v16 = qcar(v16);
    fn = elt(env, 4); /* addtaylor1 */
    v16 = (*qfnn(fn))(qenv(fn), 3, v47, v133, v16);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    stack[-4] = elt(env, 1); /* taylor!* */
    v133 = v16;
    stack[0] = qcdr(v133);
    v133 = stack[-1];
    v16 = qcar(v16);
    fn = elt(env, 5); /* replace!-next */
    stack[-1] = (*qfn2(fn))(qenv(fn), v133, v16);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v16 = qvalue(elt(env, 2)); /* !*taylorkeeporiginal */
    if (v16 == nil) goto v15;
    v16 = stack[-3];
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    v16 = qcar(v16);
    if (v16 == nil) goto v15;
    v16 = stack[-2];
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    v16 = qcar(v16);
    if (v16 == nil) goto v15;
    v16 = stack[-3];
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    v133 = qcar(v16);
    v16 = stack[-2];
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    v16 = qcdr(v16);
    v16 = qcar(v16);
    fn = elt(env, 6); /* addsq */
    v16 = (*qfn2(fn))(qenv(fn), v133, v16);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-5];
    v133 = v16;
    goto v101;

v101:
    v16 = qvalue(elt(env, 3)); /* nil */
    v16 = list2(v133, v16);
    nil = C_nil;
    if (exception_pending()) goto v87;
    {
        Lisp_Object v233 = stack[-4];
        Lisp_Object v54 = stack[0];
        Lisp_Object v86 = stack[-1];
        popv(6);
        return list3star(v233, v54, v86, v16);
    }

v15:
    v16 = qvalue(elt(env, 3)); /* nil */
    v133 = v16;
    goto v101;
/* error exit handlers */
v87:
    popv(6);
    return nil;
}



setup_type const u60_setup[] =
{
    {"simpsqrti",               CC_simpsqrti,   too_many_1,    wrong_no_1},
    {"modsqrt1",                too_few_2,      CC_modsqrt1,   wrong_no_2},
    {"r2bf",                    CC_r2bf,        too_many_1,    wrong_no_1},
    {"substinulist",            CC_substinulist,too_many_1,    wrong_no_1},
    {"cpr_buchcrit4t",          too_few_2,      CC_cpr_buchcrit4t,wrong_no_2},
    {"rerror",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rerror},
    {"int-simp",                CC_intKsimp,    too_many_1,    wrong_no_1},
    {"i2crn*",                  CC_i2crnH,      too_many_1,    wrong_no_1},
    {"fnewsym",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnewsym},
    {"dipreduceconti",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipreduceconti},
    {"remove_items",            too_few_2,      CC_remove_items,wrong_no_2},
    {"precedence",              CC_precedence,  too_many_1,    wrong_no_1},
    {"redstmtp",                CC_redstmtp,    too_many_1,    wrong_no_1},
    {"clearrules",              CC_clearrules,  too_many_1,    wrong_no_1},
    {"stp",                     CC_stp,         too_many_1,    wrong_no_1},
    {"replace_edge2",           too_few_2,      CC_replace_edge2,wrong_no_2},
    {"force-lc",                too_few_2,      CC_forceKlc,   wrong_no_2},
    {"dpmat_gbtag",             CC_dpmat_gbtag, too_many_1,    wrong_no_1},
    {"multivariatep",           too_few_2,      CC_multivariatep,wrong_no_2},
    {"modsqrt",                 too_few_2,      CC_modsqrt,    wrong_no_2},
    {"common-increment",        too_few_2,      CC_commonKincrement,wrong_no_2},
    {"order",                   CC_order,       too_many_1,    wrong_no_1},
    {"get_nr_irred_reps",       CC_get_nr_irred_reps,too_many_1,wrong_no_1},
    {"ev_max#",                 too_few_2,      CC_ev_maxC,    wrong_no_2},
    {"ssetvars1",               too_few_2,      CC_ssetvars1,  wrong_no_2},
    {"idqsimpcont",             CC_idqsimpcont, too_many_1,    wrong_no_1},
    {"spoly_pair",              CC_spoly_pair,  too_many_1,    wrong_no_1},
    {"hdiffterm",               too_few_2,      CC_hdiffterm,  wrong_no_2},
    {"xprinf2",                 CC_xprinf2,     too_many_1,    wrong_no_1},
    {"count-linear-factors-mod-p",wrong_no_na,  wrong_no_nb,   (n_args *)CC_countKlinearKfactorsKmodKp},
    {"exprsize",                CC_exprsize,    too_many_1,    wrong_no_1},
    {"linineqnormalize",        CC_linineqnormalize,too_many_1,wrong_no_1},
    {"crzchk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_crzchk},
    {"gd_revalevalop",          too_few_2,      CC_gd_revalevalop,wrong_no_2},
    {"ofsf_ignshift",           too_few_2,      CC_ofsf_ignshift,wrong_no_2},
    {"preptaylor*",             CC_preptaylorH, too_many_1,    wrong_no_1},
    {"mk+null+vec",             CC_mkLnullLvec, too_many_1,    wrong_no_1},
    {"vdp_putprop",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdp_putprop},
    {"bc_sum",                  too_few_2,      CC_bc_sum,     wrong_no_2},
    {"ps:big-o",                too_few_2,      CC_psTbigKo,   wrong_no_2},
    {"bf2flr",                  CC_bf2flr,      too_many_1,    wrong_no_1},
    {"simpco",                  CC_simpco,      too_many_1,    wrong_no_1},
    {"redmsg",                  too_few_2,      CC_redmsg,     wrong_no_2},
    {"cvt5",                    too_few_2,      CC_cvt5,       wrong_no_2},
    {"compactsq",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactsq},
    {"dp=fnprod",               CC_dpMfnprod,   too_many_1,    wrong_no_1},
    {"montest",                 CC_montest,     too_many_1,    wrong_no_1},
    {"mkqmatr",                 CC_mkqmatr,     too_many_1,    wrong_no_1},
    {"msolve",                  CC_msolve,      too_many_1,    wrong_no_1},
    {"unique-f-nos",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_uniqueKfKnos},
    {"ofsf_anegrel",            CC_ofsf_anegrel,too_many_1,    wrong_no_1},
    {"addtaylor*",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_addtaylorH},
    {NULL, (one_args *)"u60", (two_args *)"8584 7486523 8786804", 0}
};

/* end of generated code */
