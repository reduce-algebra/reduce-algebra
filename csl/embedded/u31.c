
/* $destdir/generated-c\u31.c Machine generated C code */

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


/* Code for mk!+inner!+product */

static Lisp_Object CC_mkLinnerLproduct(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+inner+product");
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
    stack[-1] = v1;
    stack[-3] = v0;
/* end of prologue */
    v19 = stack[-3];
    fn = elt(env, 6); /* get!+vec!+dim */
    stack[0] = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v19 = stack[-1];
    fn = elt(env, 6); /* get!+vec!+dim */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    if (equal(stack[0], v19)) goto v22;
    v19 = elt(env, 1); /* "Error in Gram_schmidt: each list in input must be the same length." 
*/
    fn = elt(env, 7); /* rederr */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    goto v22;

v22:
    v20 = qvalue(elt(env, 2)); /* nil */
    v19 = (Lisp_Object)17; /* 1 */
    v19 = cons(v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[0] = v19;
    v19 = qvalue(elt(env, 3)); /* !*complex */
    if (v19 == nil) goto v23;
    v19 = stack[-1];
    fn = elt(env, 8); /* mk!+conjugate!+vec */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[-4] = v19;
    goto v24;

v24:
    v19 = (Lisp_Object)17; /* 1 */
    stack[-2] = v19;
    goto v25;

v25:
    v19 = stack[-3];
    fn = elt(env, 6); /* get!+vec!+dim */
    v20 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v19 = stack[-2];
    v19 = difference2(v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v19 = Lminusp(nil, v19);
    env = stack[-5];
    if (v19 == nil) goto v26;
    v19 = qvalue(elt(env, 4)); /* t */
    stack[-1] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v19; /* !*sub2 */
    v19 = stack[0];
    fn = elt(env, 9); /* subs2 */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-5];
    stack[0] = v19;
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v26:
    stack[-1] = stack[0];
    v20 = stack[-3];
    v19 = stack[-2];
    fn = elt(env, 10); /* get!+vec!+entry */
    stack[0] = (*qfn2(fn))(qenv(fn), v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    v20 = stack[-4];
    v19 = stack[-2];
    fn = elt(env, 10); /* get!+vec!+entry */
    v19 = (*qfn2(fn))(qenv(fn), v20, v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    fn = elt(env, 11); /* multsq */
    v19 = (*qfn2(fn))(qenv(fn), stack[0], v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    fn = elt(env, 12); /* addsq */
    v19 = (*qfn2(fn))(qenv(fn), stack[-1], v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[0] = v19;
    v19 = stack[-2];
    v19 = add1(v19);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-5];
    stack[-2] = v19;
    goto v25;

v23:
    v19 = stack[-1];
    stack[-4] = v19;
    goto v24;
/* error exit handlers */
v27:
    env = stack[-5];
    qvalue(elt(env, 5)) = stack[-1]; /* !*sub2 */
    popv(6);
    return nil;
v21:
    popv(6);
    return nil;
}



/* Code for ratpoly_mvartest */

static Lisp_Object CC_ratpoly_mvartest(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_mvartest");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v1;
    v30 = v0;
/* end of prologue */
    v15 = v30;
    v15 = qcar(v15);
    if (v15 == nil) goto v10;
    v15 = v30;
    v15 = qcar(v15);
    if (is_number(v15)) goto v31;
    v15 = v30;
    v15 = qcar(v15);
    v15 = qcar(v15);
    v15 = qcar(v15);
    v15 = qcar(v15);
    v15 = (v15 == v16 ? lisp_true : nil);
    return onevalue(v15);

v31:
    v15 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v15);

v10:
    v15 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v15);
}



/* Code for ciom */

static Lisp_Object CC_ciom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ciom");
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
    v35 = elt(env, 1); /* "<OMATTR>" */
    fn = elt(env, 11); /* printout */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 12); /* indent!* */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = elt(env, 3); /* "<OMATP>" */
    fn = elt(env, 11); /* printout */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 12); /* indent!* */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = elt(env, 4); /* "<OMS cd=""typmml"" name=""type"">" */
    fn = elt(env, 11); /* printout */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = elt(env, 5); /* "<OMS cd=""typmml"" name=""" */
    fn = elt(env, 11); /* printout */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v35 = qcar(v35);
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v36 = Lintern(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = qvalue(elt(env, 6)); /* mmltypes!* */
    v35 = Lassoc(nil, v36, v35);
    v35 = Lprinc(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v35 = qcar(v35);
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v36 = Lintern(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = qvalue(elt(env, 6)); /* mmltypes!* */
    v35 = Lassoc(nil, v36, v35);
    v35 = qcdr(v35);
    v35 = qcar(v35);
    v35 = Lprinc(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = elt(env, 7); /* """>" */
    v35 = Lprinc(nil, v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 12); /* indent!* */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = elt(env, 9); /* "</OMATP>" */
    fn = elt(env, 11); /* printout */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = stack[0];
    v35 = qcdr(v35);
    v35 = qcdr(v35);
    v35 = qcar(v35);
    fn = elt(env, 13); /* objectom */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 12); /* indent!* */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-1];
    v35 = elt(env, 10); /* "</OMATTR>" */
    fn = elt(env, 11); /* printout */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v35 = nil;
    { popv(2); return onevalue(v35); }
/* error exit handlers */
v37:
    popv(2);
    return nil;
}



/* Code for binomial!-coefft!-mod!-p */

static Lisp_Object CC_binomialKcoefftKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v55, v56, v57, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binomial-coefft-mod-p");
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
    v55 = stack[-2];
    v54 = stack[-1];
    v54 = (Lisp_Object)lessp2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v59;
    v54 = v54 ? lisp_true : nil;
    env = stack[-4];
    if (v54 == nil) goto v60;
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v54); }

v60:
    v55 = stack[-2];
    v54 = stack[-1];
    if (equal(v55, v54)) goto v61;
    v55 = stack[-1];
    v54 = (Lisp_Object)17; /* 1 */
    if (v55 == v54) goto v29;
    v54 = (Lisp_Object)17; /* 1 */
    stack[-3] = v54;
    stack[0] = stack[-1];
    v55 = stack[-2];
    v54 = stack[-1];
    v54 = difference2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    fn = elt(env, 2); /* min */
    v54 = (*qfn2(fn))(qenv(fn), stack[0], v54);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    stack[0] = v54;
    v54 = stack[-2];
    v54 = Lmodular_number(nil, v54);
    env = stack[-4];
    stack[-2] = v54;
    v54 = stack[-1];
    v54 = Lmodular_number(nil, v54);
    env = stack[-4];
    v54 = (Lisp_Object)17; /* 1 */
    stack[-1] = v54;
    goto v62;

v62:
    v55 = stack[0];
    v54 = stack[-1];
    v54 = difference2(v55, v54);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    v54 = Lminusp(nil, v54);
    env = stack[-4];
    if (v54 == nil) goto v63;
    v54 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v54);
    }

v63:
    v54 = stack[-1];
    v54 = Lmodular_number(nil, v54);
    env = stack[-4];
    v58 = v54;
    v57 = stack[-3];
    v56 = stack[-2];
    v55 = v58;
    v54 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v55) - int_of_fixnum(v54);
        if (w < 0) w += current_modulus;
        v54 = fixnum_of_int(w);
    }
    {   int32_t w = int_of_fixnum(v56) - int_of_fixnum(v54);
        if (w < 0) w += current_modulus;
        v54 = fixnum_of_int(w);
    }
    v54 = Lmodular_times(nil, v57, v54);
    env = stack[-4];
    v55 = v58;
    v54 = Lmodular_quotient(nil, v54, v55);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    stack[-3] = v54;
    v54 = stack[-1];
    v54 = add1(v54);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    stack[-1] = v54;
    goto v62;

v29:
    v54 = stack[-2];
    v54 = Lmodular_number(nil, v54);
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v54);
    }

v61:
    v54 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v54); }
/* error exit handlers */
v59:
    popv(5);
    return nil;
}



/* Code for prepsq!*1 */

static Lisp_Object MS_CDECL CC_prepsqH1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v64, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v179, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prepsq*1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsq*1");
#endif
    if (stack >= stacklimit)
    {
        push3(v64,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v64);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v64;
    stack[-5] = v1;
    stack[-6] = v0;
/* end of prologue */
    v178 = stack[-6];
    if (!consp(v178)) goto v31;
    v178 = stack[-6];
    v178 = qcar(v178);
    if (!consp(v178)) goto v31;
    v178 = stack[-6];
    v178 = qcar(v178);
    v178 = qcar(v178);
    v179 = qcar(v178);
    v178 = qvalue(elt(env, 1)); /* factors!* */
    v178 = Lmember(nil, v179, v178);
    if (!(v178 == nil)) goto v181;
    v178 = stack[-6];
    v178 = qcar(v178);
    v178 = qcar(v178);
    v178 = qcar(v178);
    if (!consp(v178)) goto v31;
    v178 = stack[-6];
    v178 = qcar(v178);
    v178 = qcar(v178);
    v178 = qcar(v178);
    v179 = qcar(v178);
    v178 = qvalue(elt(env, 1)); /* factors!* */
    v178 = Lmember(nil, v179, v178);
    if (!(v178 == nil)) goto v181;

v31:
    v178 = stack[-5];
    if (!consp(v178)) goto v182;
    v178 = stack[-5];
    v178 = qcar(v178);
    if (!consp(v178)) goto v182;
    v178 = qvalue(elt(env, 4)); /* kord!* */
    stack[-3] = v178;
    goto v183;

v183:
    v178 = stack[-3];
    if (v178 == nil) goto v182;
    v178 = stack[-3];
    v178 = qcar(v178);
    stack[-2] = v178;
    v178 = (Lisp_Object)1; /* 0 */
    stack[-1] = v178;
    v179 = stack[-2];
    v178 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 11); /* to */
    v179 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = (Lisp_Object)17; /* 1 */
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[0] = v178;
    goto v185;

v185:
    v179 = stack[-5];
    v178 = stack[0];
    fn = elt(env, 12); /* quotfm */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-7] = v178;
    if (v178 == nil) goto v186;
    v178 = stack[-1];
    v178 = sub1(v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-1] = v178;
    v178 = stack[-7];
    stack[-5] = v178;
    goto v185;

v186:
    v179 = stack[-1];
    v178 = (Lisp_Object)1; /* 0 */
    v178 = (Lisp_Object)lessp2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    v178 = v178 ? lisp_true : nil;
    env = stack[-8];
    if (v178 == nil) goto v187;
    v180 = elt(env, 3); /* expt */
    v179 = stack[-2];
    v178 = stack[-1];
    v179 = list3(v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 13); /* mksp */
    v179 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = stack[-4];
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-4] = v178;
    goto v187;

v187:
    v178 = stack[-3];
    v178 = qcdr(v178);
    stack[-3] = v178;
    goto v183;

v182:
    v178 = stack[-6];
    fn = elt(env, 14); /* kernlp */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    if (v178 == nil) goto v188;
    v179 = stack[-4];
    v178 = stack[-6];
    fn = elt(env, 15); /* mkkl */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-6] = v178;
    v178 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v178;
    goto v188;

v188:
    v178 = qvalue(elt(env, 5)); /* dnl!* */
    if (v178 == nil) goto v189;
    v178 = qvalue(elt(env, 6)); /* !*allfac */
    if (v178 == nil) goto v190;
    v178 = stack[-6];
    fn = elt(env, 16); /* ckrn */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    goto v191;

v191:
    stack[-1] = v178;
    v179 = stack[-1];
    v178 = qvalue(elt(env, 5)); /* dnl!* */
    fn = elt(env, 17); /* ckrn!* */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-7] = v178;
    v179 = stack[-1];
    v178 = stack[-7];
    fn = elt(env, 18); /* quotof */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v179 = stack[-6];
    v178 = stack[-7];
    fn = elt(env, 18); /* quotof */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-6] = v178;
    v179 = stack[-5];
    v178 = stack[-7];
    fn = elt(env, 18); /* quotof */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-5] = v178;
    goto v189;

v189:
    v178 = qvalue(elt(env, 7)); /* upl!* */
    if (v178 == nil) goto v192;
    v178 = stack[-5];
    fn = elt(env, 16); /* ckrn */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[0] = v178;
    v179 = stack[0];
    v178 = qvalue(elt(env, 7)); /* upl!* */
    fn = elt(env, 17); /* ckrn!* */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-7] = v178;
    v179 = stack[0];
    v178 = stack[-7];
    fn = elt(env, 18); /* quotof */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[0] = v178;
    v179 = stack[-6];
    v178 = stack[-7];
    fn = elt(env, 18); /* quotof */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-6] = v178;
    v179 = stack[-5];
    v178 = stack[-7];
    fn = elt(env, 18); /* quotof */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-5] = v178;
    goto v193;

v193:
    stack[-1] = stack[-6];
    v179 = stack[-5];
    v178 = stack[0];
    fn = elt(env, 18); /* quotof */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = cons(stack[-1], v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    fn = elt(env, 19); /* canonsq */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-6] = v178;
    v178 = stack[-6];
    v179 = qcar(v178);
    v178 = stack[0];
    fn = elt(env, 18); /* quotof */
    v179 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = stack[-6];
    v178 = qcdr(v178);
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-6] = v178;
    v178 = qvalue(elt(env, 6)); /* !*allfac */
    if (v178 == nil) goto v194;
    v178 = stack[-6];
    v178 = qcar(v178);
    fn = elt(env, 16); /* ckrn */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-1] = v178;
    v178 = stack[-6];
    v178 = qcdr(v178);
    fn = elt(env, 16); /* ckrn */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[0] = v178;
    v179 = stack[-1];
    v178 = (Lisp_Object)17; /* 1 */
    if (!(v179 == v178)) goto v195;
    v179 = stack[0];
    v178 = (Lisp_Object)17; /* 1 */
    if (!(v179 == v178)) goto v195;

v194:
    v178 = stack[-4];
    if (v178 == nil) goto v196;
    v178 = stack[-4];
    fn = elt(env, 20); /* exchk */
    stack[0] = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = stack[-6];
    fn = elt(env, 21); /* prepsq */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    fn = elt(env, 22); /* aconc!* */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    fn = elt(env, 23); /* retimes */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    popv(9);
    return ncons(v178);

v196:
    v178 = stack[-6];
    fn = elt(env, 21); /* prepsq */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 24); /* rmplus */
        return (*qfn1(fn))(qenv(fn), v178);
    }

v195:
    v179 = stack[-1];
    v178 = stack[-6];
    v178 = qcar(v178);
    if (!(equal(v179, v178))) goto v197;
    v179 = stack[0];
    v178 = stack[-6];
    v178 = qcdr(v178);
    if (equal(v179, v178)) goto v194;
    else goto v197;

v197:
    v178 = stack[-6];
    v179 = qcdr(v178);
    v178 = stack[0];
    fn = elt(env, 18); /* quotof */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-5] = v178;
    v178 = stack[-6];
    v179 = qcar(v178);
    v178 = stack[-1];
    fn = elt(env, 18); /* quotof */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-6] = v178;
    v179 = stack[-4];
    v178 = stack[-1];
    fn = elt(env, 15); /* mkkl */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    fn = elt(env, 25); /* prepf */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-4] = v178;
    v178 = stack[0];
    fn = elt(env, 25); /* prepf */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-1] = v178;
    v179 = stack[-4];
    v178 = stack[-6];
    fn = elt(env, 26); /* addfactors */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-6] = v178;
    v179 = stack[-1];
    v178 = stack[-5];
    fn = elt(env, 26); /* addfactors */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-5] = v178;
    v179 = stack[-5];
    v178 = (Lisp_Object)17; /* 1 */
    if (v179 == v178) goto v198;
    v179 = stack[-6];
    v178 = elt(env, 9); /* minus */
    if (!consp(v179)) goto v199;
    v179 = qcar(v179);
    if (!(v179 == v178)) goto v199;
    stack[0] = elt(env, 9); /* minus */
    v180 = elt(env, 10); /* quotient */
    v178 = stack[-6];
    v178 = qcdr(v178);
    v179 = qcar(v178);
    v178 = stack[-5];
    v178 = list3(v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = list2(stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    goto v200;

v200:
    popv(9);
    return ncons(v178);

v199:
    v180 = elt(env, 10); /* quotient */
    v179 = stack[-6];
    v178 = stack[-5];
    v178 = list3(v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    goto v200;

v198:
    v178 = stack[-6];
    {
        popv(9);
        fn = elt(env, 24); /* rmplus */
        return (*qfn1(fn))(qenv(fn), v178);
    }

v192:
    v178 = qvalue(elt(env, 8)); /* !*div */
    if (v178 == nil) goto v201;
    v178 = stack[-5];
    fn = elt(env, 16); /* ckrn */
    v178 = (*qfn1(fn))(qenv(fn), v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[0] = v178;
    goto v193;

v201:
    v178 = (Lisp_Object)17; /* 1 */
    stack[0] = v178;
    goto v193;

v190:
    v178 = (Lisp_Object)17; /* 1 */
    goto v191;

v181:
    v179 = stack[-5];
    v178 = (Lisp_Object)17; /* 1 */
    if (v179 == v178) goto v202;
    v178 = stack[-6];
    v178 = qcar(v178);
    v178 = qcar(v178);
    v178 = qcdr(v178);
    stack[-2] = v178;
    v178 = stack[-5];
    stack[-1] = v178;
    v178 = stack[-6];
    v178 = qcar(v178);
    v178 = qcar(v178);
    v179 = qcar(v178);
    v178 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 11); /* to */
    v179 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = (Lisp_Object)17; /* 1 */
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = ncons(v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[0] = v178;
    goto v203;

v203:
    v179 = stack[-1];
    v178 = stack[0];
    fn = elt(env, 12); /* quotfm */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-7] = v178;
    if (v178 == nil) goto v204;
    v178 = stack[-7];
    stack[-1] = v178;
    v178 = stack[-2];
    v178 = sub1(v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[-2] = v178;
    goto v203;

v204:
    v178 = stack[-6];
    v178 = qcar(v178);
    v179 = qcdr(v178);
    v178 = stack[-1];
    stack[0] = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v179 = stack[-2];
    v178 = (Lisp_Object)1; /* 0 */
    v178 = (Lisp_Object)greaterp2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    v178 = v178 ? lisp_true : nil;
    env = stack[-8];
    if (v178 == nil) goto v205;
    v178 = stack[-6];
    v178 = qcar(v178);
    v178 = qcar(v178);
    v179 = qcar(v178);
    v178 = stack[-2];
    fn = elt(env, 11); /* to */
    v179 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = stack[-4];
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    goto v206;

v206:
    fn = elt(env, 27); /* prepsq!*0 */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[0] = v178;
    goto v207;

v207:
    v178 = stack[-6];
    v179 = qcdr(v178);
    v178 = stack[-5];
    v179 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = stack[-4];
    fn = elt(env, 27); /* prepsq!*0 */
    v178 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    {
        Lisp_Object v208 = stack[0];
        popv(9);
        fn = elt(env, 28); /* nconc!* */
        return (*qfn2(fn))(qenv(fn), v208, v178);
    }

v205:
    v179 = stack[-2];
    v178 = (Lisp_Object)1; /* 0 */
    v178 = (Lisp_Object)lessp2(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    v178 = v178 ? lisp_true : nil;
    env = stack[-8];
    if (v178 == nil) goto v209;
    v180 = elt(env, 3); /* expt */
    v178 = stack[-6];
    v178 = qcar(v178);
    v178 = qcar(v178);
    v179 = qcar(v178);
    v178 = stack[-2];
    v179 = list3(v180, v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 13); /* mksp */
    v179 = (*qfn2(fn))(qenv(fn), v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = stack[-4];
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    goto v206;

v209:
    v178 = stack[-4];
    goto v206;

v202:
    v178 = stack[-6];
    v178 = qcar(v178);
    v179 = qcdr(v178);
    v178 = stack[-5];
    stack[0] = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    v178 = stack[-6];
    v178 = qcar(v178);
    v179 = qcar(v178);
    v178 = stack[-4];
    v178 = cons(v179, v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    fn = elt(env, 27); /* prepsq!*0 */
    v178 = (*qfn2(fn))(qenv(fn), stack[0], v178);
    nil = C_nil;
    if (exception_pending()) goto v184;
    env = stack[-8];
    stack[0] = v178;
    goto v207;
/* error exit handlers */
v184:
    popv(9);
    return nil;
}



/* Code for mksqrt */

static Lisp_Object CC_mksqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v216, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksqrt");
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
    v13 = qvalue(elt(env, 1)); /* !*keepsqrts */
    if (v13 == nil) goto v217;
    v13 = qvalue(elt(env, 4)); /* !*!*sqrt */
    if (!(v13 == nil)) goto v218;
    v13 = qvalue(elt(env, 5)); /* t */
    qvalue(elt(env, 4)) = v13; /* !*!*sqrt */
    v14 = elt(env, 6); /* (x) */
    v216 = lisp_true;
    v13 = elt(env, 7); /* (let00 (quote ((equal (expt (sqrt x) 2) x)))) 
*/
    v13 = list3(v14, v216, v13);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    fn = elt(env, 9); /* forall */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    fn = elt(env, 10); /* aeval */
    v13 = (*qfn1(fn))(qenv(fn), v13);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    goto v218;

v218:
    v216 = elt(env, 8); /* sqrt */
    v13 = stack[0];
    popv(3);
    return list2(v216, v13);

v217:
    stack[-1] = elt(env, 2); /* expt */
    v14 = elt(env, 3); /* quotient */
    v216 = (Lisp_Object)17; /* 1 */
    v13 = (Lisp_Object)33; /* 2 */
    v13 = list3(v14, v216, v13);
    nil = C_nil;
    if (exception_pending()) goto v26;
    {
        Lisp_Object v35 = stack[-1];
        Lisp_Object v36 = stack[0];
        popv(3);
        return list3(v35, v36, v13);
    }
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for prsubsetrd */

static Lisp_Object CC_prsubsetrd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prsubsetrd");
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
    v8 = qvalue(elt(env, 1)); /* t */
    stack[-1] = v8;
    goto v214;

v214:
    v8 = stack[-3];
    v9 = Llength(nil, v8);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    v8 = (Lisp_Object)17; /* 1 */
    v8 = (Lisp_Object)greaterp2(v9, v8);
    nil = C_nil;
    if (exception_pending()) goto v224;
    v8 = v8 ? lisp_true : nil;
    env = stack[-4];
    if (v8 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v8 = stack[-3];
    stack[0] = qcar(v8);
    v8 = stack[-3];
    v8 = qcar(v8);
    fn = elt(env, 4); /* reval */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    if (equal(stack[0], v8)) goto v29;
    v8 = stack[-3];
    v8 = qcdr(v8);
    stack[0] = qcar(v8);
    v8 = stack[-3];
    v8 = qcdr(v8);
    v8 = qcar(v8);
    fn = elt(env, 4); /* reval */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    if (equal(stack[0], v8)) goto v29;
    v8 = stack[-1];
    if (v8 == nil) goto v37;
    v8 = stack[-3];
    v8 = qcar(v8);
    fn = elt(env, 4); /* reval */
    stack[0] = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    v8 = stack[-3];
    v8 = qcdr(v8);
    v8 = qcar(v8);
    fn = elt(env, 4); /* reval */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    fn = elt(env, 5); /* alg_prsubset */
    v8 = (*qfn2(fn))(qenv(fn), stack[0], v8);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    goto v41;

v41:
    stack[-1] = v8;
    v8 = stack[-3];
    v8 = qcdr(v8);
    stack[-3] = v8;
    goto v214;

v37:
    v8 = qvalue(elt(env, 2)); /* nil */
    goto v41;

v29:
    v8 = nil;
    stack[-3] = v8;
    stack[0] = elt(env, 3); /* prsubset */
    v8 = stack[-2];
    fn = elt(env, 6); /* eval_list_sets */
    v8 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    v8 = cons(stack[0], v8);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    stack[-1] = v8;
    goto v214;
/* error exit handlers */
v224:
    popv(5);
    return nil;
}



/* Code for boolvalue!* */

static Lisp_Object CC_boolvalueH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v223;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boolvalue*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v223 = v0;
/* end of prologue */
    v18 = v223;
    if (v18 == nil) goto v2;
    v18 = (Lisp_Object)1; /* 0 */
    v18 = (v223 == v18 ? lisp_true : nil);
    v18 = (v18 == nil ? lisp_true : nil);
    return onevalue(v18);

v2:
    v18 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v18);
}



/* Code for gfdiffer */

static Lisp_Object CC_gfdiffer(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v225, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfdiffer");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v225 = v1;
    v15 = v0;
/* end of prologue */
    v28 = v15;
    v28 = qcar(v28);
    if (!consp(v28)) goto v31;
    v28 = v15;
    {
        fn = elt(env, 1); /* gbfdiff */
        return (*qfn2(fn))(qenv(fn), v28, v225);
    }

v31:
    v28 = v15;
    {
        fn = elt(env, 2); /* gffdiff */
        return (*qfn2(fn))(qenv(fn), v28, v225);
    }
}



/* Code for replace2_parents */

static Lisp_Object MS_CDECL CC_replace2_parents(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v64, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v227;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace2_parents");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace2_parents");
#endif
    if (stack >= stacklimit)
    {
        push3(v64,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v64);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v64;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v227 = stack[-2];
    v33 = stack[0];
    v33 = qcar(v33);
    if (!(equal(v227, v33))) goto v225;
    v227 = stack[0];
    v33 = stack[-1];
    v33 = Lrplaca(nil, v227, v33);
    nil = C_nil;
    if (exception_pending()) goto v177;
    goto v225;

v225:
    v227 = stack[-2];
    v33 = stack[0];
    v33 = qcdr(v33);
    if (equal(v227, v33)) goto v32;
    v33 = nil;
    { popv(3); return onevalue(v33); }

v32:
    v227 = stack[0];
    v33 = stack[-1];
        popv(3);
        return Lrplacd(nil, v227, v33);
/* error exit handlers */
v177:
    popv(3);
    return nil;
}



/* Code for fs!:prepfn!: */

static Lisp_Object CC_fsTprepfnT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v220;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prepfn:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v220 = v0;
/* end of prologue */
    return onevalue(v220);
}



/* Code for mkindxlist */

static Lisp_Object CC_mkindxlist(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkindxlist");
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
    v21 = v0;
/* end of prologue */
    stack[-4] = v21;
    v21 = stack[-4];
    if (v21 == nil) goto v231;
    v21 = stack[-4];
    v21 = qcar(v21);
    v27 = v21;
    v21 = v27;
    v21 = integerp(v21);
    if (v21 == nil) goto v34;
    v21 = v27;
    fn = elt(env, 3); /* !*num2id */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    goto v223;

v223:
    v21 = ncons(v21);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    stack[-2] = v21;
    stack[-3] = v21;
    goto v232;

v232:
    v21 = stack[-4];
    v21 = qcdr(v21);
    stack[-4] = v21;
    v21 = stack[-4];
    if (v21 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v21 = stack[-4];
    v21 = qcar(v21);
    v27 = v21;
    v21 = v27;
    v21 = integerp(v21);
    if (v21 == nil) goto v233;
    v21 = v27;
    fn = elt(env, 3); /* !*num2id */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    goto v63;

v63:
    v21 = ncons(v21);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v21 = Lrplacd(nil, stack[-1], v21);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v21 = stack[-2];
    v21 = qcdr(v21);
    stack[-2] = v21;
    goto v232;

v233:
    v21 = v27;
    v21 = Lconsp(nil, v21);
    env = stack[-5];
    if (v21 == nil) goto v149;
    v21 = v27;
    v21 = qcdr(v21);
    v21 = qcar(v21);
    v21 = integerp(v21);
    if (v21 == nil) goto v149;
    stack[0] = elt(env, 2); /* minus */
    v21 = v27;
    v21 = qcdr(v21);
    v21 = qcar(v21);
    fn = elt(env, 3); /* !*num2id */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v21 = list2(stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    goto v63;

v149:
    v21 = v27;
    goto v63;

v34:
    v21 = v27;
    v21 = Lconsp(nil, v21);
    env = stack[-5];
    if (v21 == nil) goto v176;
    v21 = v27;
    v21 = qcdr(v21);
    v21 = qcar(v21);
    v21 = integerp(v21);
    if (v21 == nil) goto v176;
    stack[0] = elt(env, 2); /* minus */
    v21 = v27;
    v21 = qcdr(v21);
    v21 = qcar(v21);
    fn = elt(env, 3); /* !*num2id */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    v21 = list2(stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v46;
    env = stack[-5];
    goto v223;

v176:
    v21 = v27;
    goto v223;

v231:
    v21 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v21); }
/* error exit handlers */
v46:
    popv(6);
    return nil;
}



/* Code for num_signsort */

static Lisp_Object CC_num_signsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num_signsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v31 = v0;
/* end of prologue */
    v231 = v31;
    v31 = elt(env, 1); /* lambda_l73kgy_8 */
    {
        fn = elt(env, 2); /* ad_signsort */
        return (*qfn2(fn))(qenv(fn), v231, v31);
    }
}



/* Code for lambda_l73kgy_8 */

static Lisp_Object CC_lambda_l73kgy_8(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v235;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l73kgy_8");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v231 = v1;
    v235 = v0;
/* end of prologue */
        return Lleq(nil, v235, v231);
}



/* Code for split!-further */

static Lisp_Object MS_CDECL CC_splitKfurther(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v64, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v253, v254, v255, v256;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "split-further");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for split-further");
#endif
    if (stack >= stacklimit)
    {
        push3(v64,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v64);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v64;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v253 = stack[-3];
    if (v253 == nil) goto v107;
    v253 = stack[-3];
    v255 = qcdr(v253);
    v254 = stack[-2];
    v253 = stack[-1];
    v253 = CC_splitKfurther(env, 3, v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    stack[-4] = v253;
    v253 = stack[-4];
    v253 = qcdr(v253);
    stack[0] = v253;
    v253 = stack[-4];
    v253 = qcar(v253);
    stack[-4] = v253;
    v254 = qvalue(elt(env, 2)); /* number!-needed */
    v253 = (Lisp_Object)1; /* 0 */
    if (v254 == v253) goto v258;
    v255 = stack[-2];
    v254 = stack[-1];
    v253 = qvalue(elt(env, 3)); /* work!-vector1 */
    fn = elt(env, 7); /* copy!-vector */
    v253 = (*qfnn(fn))(qenv(fn), 3, v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    qvalue(elt(env, 4)) = v253; /* dwork1 */
    v253 = stack[-3];
    v253 = qcar(v253);
    v255 = qcar(v253);
    v253 = stack[-3];
    v253 = qcar(v253);
    v254 = qcdr(v253);
    v253 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 7); /* copy!-vector */
    v253 = (*qfnn(fn))(qenv(fn), 3, v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    qvalue(elt(env, 6)) = v253; /* dwork2 */
    v256 = qvalue(elt(env, 3)); /* work!-vector1 */
    v255 = qvalue(elt(env, 4)); /* dwork1 */
    v254 = qvalue(elt(env, 5)); /* work!-vector2 */
    v253 = qvalue(elt(env, 6)); /* dwork2 */
    fn = elt(env, 8); /* gcd!-in!-vector */
    v253 = (*qfnn(fn))(qenv(fn), 4, v256, v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    qvalue(elt(env, 4)) = v253; /* dwork1 */
    v254 = qvalue(elt(env, 4)); /* dwork1 */
    v253 = (Lisp_Object)1; /* 0 */
    if (v254 == v253) goto v258;
    v254 = qvalue(elt(env, 4)); /* dwork1 */
    v253 = stack[-3];
    v253 = qcar(v253);
    v253 = qcdr(v253);
    if (equal(v254, v253)) goto v258;
    v253 = stack[-3];
    v253 = qcar(v253);
    v255 = qcar(v253);
    v253 = stack[-3];
    v253 = qcar(v253);
    v254 = qcdr(v253);
    v253 = qvalue(elt(env, 5)); /* work!-vector2 */
    fn = elt(env, 7); /* copy!-vector */
    v253 = (*qfnn(fn))(qenv(fn), 3, v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    qvalue(elt(env, 6)) = v253; /* dwork2 */
    v256 = qvalue(elt(env, 5)); /* work!-vector2 */
    v255 = qvalue(elt(env, 6)); /* dwork2 */
    v254 = qvalue(elt(env, 3)); /* work!-vector1 */
    v253 = qvalue(elt(env, 4)); /* dwork1 */
    fn = elt(env, 9); /* quotfail!-in!-vector */
    v253 = (*qfnn(fn))(qenv(fn), 4, v256, v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    qvalue(elt(env, 6)) = v253; /* dwork2 */
    v253 = qvalue(elt(env, 4)); /* dwork1 */
    v253 = Lmkvect(nil, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    stack[-1] = v253;
    v255 = qvalue(elt(env, 3)); /* work!-vector1 */
    v254 = qvalue(elt(env, 4)); /* dwork1 */
    v253 = stack[-1];
    fn = elt(env, 7); /* copy!-vector */
    v253 = (*qfnn(fn))(qenv(fn), 3, v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    v255 = stack[-1];
    v254 = qvalue(elt(env, 4)); /* dwork1 */
    v253 = stack[-4];
    v253 = acons(v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    stack[-4] = v253;
    stack[-2] = qvalue(elt(env, 5)); /* work!-vector2 */
    stack[-1] = qvalue(elt(env, 6)); /* dwork2 */
    v253 = qvalue(elt(env, 6)); /* dwork2 */
    v253 = Lmkvect(nil, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    stack[-3] = v253;
    fn = elt(env, 7); /* copy!-vector */
    v253 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-1], v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    v255 = stack[-3];
    v254 = qvalue(elt(env, 6)); /* dwork2 */
    v253 = stack[0];
    v253 = acons(v255, v254, v253);
    nil = C_nil;
    if (exception_pending()) goto v257;
    env = stack[-5];
    stack[0] = v253;
    v253 = qvalue(elt(env, 2)); /* number!-needed */
    v253 = (Lisp_Object)((int32_t)(v253) - 0x10);
    qvalue(elt(env, 2)) = v253; /* number!-needed */
    v254 = stack[-4];
    v253 = stack[0];
    popv(6);
    return cons(v254, v253);

v258:
    v255 = stack[-4];
    v253 = stack[-3];
    v254 = qcar(v253);
    v253 = stack[0];
    popv(6);
    return list2star(v255, v254, v253);

v107:
    v253 = qvalue(elt(env, 1)); /* nil */
    popv(6);
    return ncons(v253);
/* error exit handlers */
v257:
    popv(6);
    return nil;
}



/* Code for mkrootsql */

static Lisp_Object CC_mkrootsql(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v175, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkrootsql");
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
    v175 = stack[-1];
    if (v175 == nil) goto v10;
    v175 = stack[-1];
    v175 = qcar(v175);
    v173 = qcdr(v175);
    v175 = (Lisp_Object)17; /* 1 */
    v175 = (Lisp_Object)greaterp2(v173, v175);
    nil = C_nil;
    if (exception_pending()) goto v8;
    v175 = v175 ? lisp_true : nil;
    env = stack[-3];
    if (v175 == nil) goto v41;
    v175 = stack[-1];
    v175 = qcar(v175);
    v173 = qcar(v175);
    v175 = stack[0];
    fn = elt(env, 1); /* mkrootsq */
    v173 = (*qfn2(fn))(qenv(fn), v173, v175);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-3];
    v175 = stack[-1];
    v175 = qcar(v175);
    v175 = qcdr(v175);
    fn = elt(env, 2); /* exptsq */
    stack[-2] = (*qfn2(fn))(qenv(fn), v173, v175);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-3];
    v175 = stack[-1];
    v173 = qcdr(v175);
    v175 = stack[0];
    v175 = CC_mkrootsql(env, v173, v175);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-3];
    {
        Lisp_Object v9 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v9, v175);
    }

v41:
    v175 = stack[-1];
    v175 = qcar(v175);
    v173 = qcar(v175);
    v175 = stack[0];
    fn = elt(env, 1); /* mkrootsq */
    stack[-2] = (*qfn2(fn))(qenv(fn), v173, v175);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-3];
    v175 = stack[-1];
    v173 = qcdr(v175);
    v175 = stack[0];
    v175 = CC_mkrootsql(env, v173, v175);
    nil = C_nil;
    if (exception_pending()) goto v8;
    env = stack[-3];
    {
        Lisp_Object v261 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v261, v175);
    }

v10:
    v175 = (Lisp_Object)17; /* 1 */
    {
        popv(4);
        fn = elt(env, 4); /* !*d2q */
        return (*qfn1(fn))(qenv(fn), v175);
    }
/* error exit handlers */
v8:
    popv(4);
    return nil;
}



/* Code for totalcompareconstants */

static Lisp_Object CC_totalcompareconstants(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v267, v268, v269;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for totalcompareconstants");
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
    v268 = stack[-2];
    v267 = stack[-1];
    if (equal(v268, v267)) goto v10;
    v267 = stack[-2];
    if (!consp(v267)) goto v214;
    v267 = stack[-2];
    v267 = qcar(v267);
    if (!consp(v267)) goto v214;
    v267 = stack[-1];
    if (!consp(v267)) goto v216;
    v267 = stack[-1];
    v267 = qcar(v267);
    if (!consp(v267)) goto v216;
    stack[-3] = qvalue(elt(env, 4)); /* wukord!* */
    qvalue(elt(env, 4)) = nil; /* wukord!* */
    stack[0] = qvalue(elt(env, 5)); /* wuvarlist!* */
    qvalue(elt(env, 5)) = nil; /* wuvarlist!* */
    v267 = stack[-2];
    v267 = qcar(v267);
    v267 = qcar(v267);
    v268 = qcar(v267);
    v267 = stack[-1];
    v267 = qcar(v267);
    v267 = qcar(v267);
    v267 = qcar(v267);
    fn = elt(env, 6); /* symbollessp */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    if (v267 == nil) goto v230;
    v267 = elt(env, 2); /* less */
    goto v252;

v252:
    qvalue(elt(env, 5)) = stack[0]; /* wuvarlist!* */
    qvalue(elt(env, 4)) = stack[-3]; /* wukord!* */
    { popv(5); return onevalue(v267); }

v230:
    v267 = stack[-1];
    v267 = qcar(v267);
    v267 = qcar(v267);
    v268 = qcar(v267);
    v267 = stack[-2];
    v267 = qcar(v267);
    v267 = qcar(v267);
    v267 = qcar(v267);
    fn = elt(env, 6); /* symbollessp */
    v267 = (*qfn2(fn))(qenv(fn), v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    if (v267 == nil) goto v44;
    v267 = elt(env, 3); /* greater */
    goto v252;

v44:
    v267 = stack[-2];
    v267 = qcar(v267);
    v268 = qcdr(v267);
    v267 = stack[-1];
    v267 = qcar(v267);
    v267 = qcdr(v267);
    v267 = CC_totalcompareconstants(env, v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    v269 = v267;
    v268 = v269;
    v267 = elt(env, 1); /* equal */
    if (v268 == v267) goto v245;
    v267 = v269;
    goto v252;

v245:
    v267 = stack[-2];
    v268 = qcdr(v267);
    v267 = stack[-1];
    v267 = qcdr(v267);
    v267 = CC_totalcompareconstants(env, v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-4];
    goto v252;

v216:
    v267 = elt(env, 3); /* greater */
    { popv(5); return onevalue(v267); }

v214:
    v267 = stack[-1];
    if (!consp(v267)) goto v222;
    v267 = stack[-1];
    v267 = qcar(v267);
    if (!consp(v267)) goto v222;
    v267 = elt(env, 2); /* less */
    { popv(5); return onevalue(v267); }

v222:
    v267 = stack[-2];
    v268 = v267;
    if (!(v268 == nil)) goto v23;
    v267 = (Lisp_Object)1; /* 0 */
    v268 = v267;
    goto v23;

v23:
    v267 = stack[-1];
    if (!(v267 == nil)) goto v271;
    v267 = (Lisp_Object)1; /* 0 */
    goto v271;

v271:
    v267 = (Lisp_Object)lessp2(v268, v267);
    nil = C_nil;
    if (exception_pending()) goto v272;
    v267 = v267 ? lisp_true : nil;
    env = stack[-4];
    if (v267 == nil) goto v25;
    v267 = elt(env, 2); /* less */
    { popv(5); return onevalue(v267); }

v25:
    v267 = elt(env, 3); /* greater */
    { popv(5); return onevalue(v267); }

v10:
    v267 = elt(env, 1); /* equal */
    { popv(5); return onevalue(v267); }
/* error exit handlers */
v272:
    popv(5);
    return nil;
v270:
    env = stack[-4];
    qvalue(elt(env, 5)) = stack[0]; /* wuvarlist!* */
    qvalue(elt(env, 4)) = stack[-3]; /* wukord!* */
    popv(5);
    return nil;
}



/* Code for aex_reducedtag */

static Lisp_Object CC_aex_reducedtag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v217;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_reducedtag");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v217 = v0;
/* end of prologue */
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcdr(v217);
    v217 = qcar(v217);
    return onevalue(v217);
}



/* Code for diffrd */

static Lisp_Object MS_CDECL CC_diffrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v227, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "diffrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffrd");
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
    fn = elt(env, 4); /* lex */
    v33 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-3];
    v227 = qvalue(elt(env, 1)); /* char */
    v33 = elt(env, 2); /* (b v a r) */
    if (equal(v227, v33)) goto v31;
    v33 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v33;
    v33 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = v33;
    goto v234;

v234:
    fn = elt(env, 5); /* mathml2 */
    v33 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-3];
    stack[0] = v33;
    fn = elt(env, 4); /* lex */
    v33 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-3];
    v213 = stack[0];
    v227 = stack[-2];
    v33 = stack[-1];
    {
        popv(4);
        fn = elt(env, 6); /* alg_df */
        return (*qfnn(fn))(qenv(fn), 3, v213, v227, v33);
    }

v31:
    fn = elt(env, 7); /* bvarrd */
    v33 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-3];
    stack[-2] = v33;
    v33 = stack[-2];
    v33 = qcdr(v33);
    v33 = qcar(v33);
    stack[-1] = v33;
    v33 = stack[-2];
    v33 = qcar(v33);
    stack[-2] = v33;
    fn = elt(env, 4); /* lex */
    v33 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v218;
    env = stack[-3];
    goto v234;
/* error exit handlers */
v218:
    popv(4);
    return nil;
}



/* Code for sroot1 */

static Lisp_Object CC_sroot1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v277, v278, v279, v280;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sroot1");
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
    stack[-2] = qvalue(elt(env, 1)); /* freevars */
    qvalue(elt(env, 1)) = nil; /* freevars */
    stack[-1] = qvalue(elt(env, 2)); /* substitution */
    qvalue(elt(env, 2)) = nil; /* substitution */
    v278 = qvalue(elt(env, 3)); /* rpt */
    v277 = elt(env, 4); /* inf */
    if (v278 == v277) goto v235;
    v278 = qvalue(elt(env, 3)); /* rpt */
    v277 = (Lisp_Object)1; /* 0 */
    v277 = (Lisp_Object)lesseq2(v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    v277 = v277 ? lisp_true : nil;
    env = stack[-5];
    if (!(v277 == nil)) goto v31;

v235:
    v277 = stack[-3];
    if (!consp(v277)) goto v31;
    v277 = stack[-3];
    v278 = qcar(v277);
    v277 = stack[0];
    v277 = qcdr(v277);
    v277 = qcar(v277);
    v277 = qcar(v277);
    if (!(equal(v278, v277))) goto v31;
    v277 = stack[0];
    v277 = qcdr(v277);
    v277 = qcar(v277);
    fn = elt(env, 12); /* findnewvars */
    v278 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    v277 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 13); /* union */
    v277 = (*qfn2(fn))(qenv(fn), v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    qvalue(elt(env, 1)) = v277; /* freevars */
    v277 = stack[0];
    v277 = qcdr(v277);
    v277 = qcdr(v277);
    v277 = qcar(v277);
    qvalue(elt(env, 2)) = v277; /* substitution */
    v277 = qvalue(elt(env, 1)); /* freevars */
    stack[-4] = v277;
    goto v35;

v35:
    v277 = stack[-4];
    if (v277 == nil) goto v26;
    v277 = stack[-4];
    v277 = qcar(v277);
    fn = elt(env, 14); /* newenv */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    v277 = stack[-4];
    v277 = qcdr(v277);
    stack[-4] = v277;
    goto v35;

v26:
    v277 = qvalue(elt(env, 6)); /* !*trpm */
    if (v277 == nil) goto v224;
    v277 = elt(env, 7); /* "Trying rule  " */
    v277 = Lprinc(nil, v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    v277 = stack[0];
    fn = elt(env, 15); /* rprint */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    v277 = elt(env, 8); /* "against      " */
    v277 = Lprinc(nil, v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    v277 = stack[-3];
    fn = elt(env, 15); /* rprint */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    goto v224;

v224:
    v277 = stack[0];
    v277 = qcdr(v277);
    v280 = qcar(v277);
    v279 = stack[-3];
    v278 = qvalue(elt(env, 9)); /* t */
    v277 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 16); /* amatch */
    v277 = (*qfnn(fn))(qenv(fn), 4, v280, v279, v278, v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    stack[-4] = v277;
    v277 = qvalue(elt(env, 6)); /* !*trpm */
    if (v277 == nil) goto v45;
    v277 = stack[-4];
    if (v277 == nil) goto v281;
    v277 = elt(env, 10); /* "producing    " */
    v277 = Lprinc(nil, v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    v277 = stack[-4];
    fn = elt(env, 17); /* embed!-null!-fn */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    stack[-4] = v277;
    fn = elt(env, 15); /* rprint */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    goto v282;

v282:
    v277 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    goto v45;

v45:
    v277 = qvalue(elt(env, 1)); /* freevars */
    stack[0] = v277;
    goto v247;

v247:
    v277 = stack[0];
    if (v277 == nil) goto v248;
    v277 = stack[0];
    v277 = qcar(v277);
    fn = elt(env, 18); /* restorenv */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    v277 = stack[0];
    v277 = qcdr(v277);
    stack[0] = v277;
    goto v247;

v248:
    v277 = stack[-4];
    if (v277 == nil) goto v166;
    v278 = qvalue(elt(env, 3)); /* rpt */
    v277 = elt(env, 4); /* inf */
    if (v278 == v277) goto v283;
    v277 = qvalue(elt(env, 3)); /* rpt */
    v277 = sub1(v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    qvalue(elt(env, 3)) = v277; /* rpt */
    goto v283;

v283:
    v277 = stack[-4];
    fn = elt(env, 17); /* embed!-null!-fn */
    v277 = (*qfn1(fn))(qenv(fn), v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    goto v232;

v232:
    qvalue(elt(env, 2)) = stack[-1]; /* substitution */
    qvalue(elt(env, 1)) = stack[-2]; /* freevars */
    { popv(6); return onevalue(v277); }

v166:
    v277 = stack[-3];
    goto v232;

v281:
    v277 = elt(env, 11); /* "failed" */
    v277 = Lprinc(nil, v277);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    v277 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v241;
    env = stack[-5];
    goto v282;

v31:
    v277 = stack[-3];
    goto v232;
/* error exit handlers */
v241:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-1]; /* substitution */
    qvalue(elt(env, 1)) = stack[-2]; /* freevars */
    popv(6);
    return nil;
}



/* Code for bflessp */

static Lisp_Object CC_bflessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v28, v225;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bflessp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v28 = v1;
    v225 = v0;
/* end of prologue */
    v29 = v225;
    if (!consp(v29)) goto v234;
    v29 = v28;
    v28 = v225;
    {
        fn = elt(env, 1); /* grpbf */
        return (*qfn2(fn))(qenv(fn), v29, v28);
    }

v234:
    v29 = v225;
        return Llessp(nil, v29, v28);
}



/* Code for mkprec */

static Lisp_Object MS_CDECL CC_mkprec(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v282, v289, v290;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkprec");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprec");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    v289 = qvalue(elt(env, 1)); /* fixedpreclis!* */
    v282 = qvalue(elt(env, 2)); /* preclis!* */
    v282 = Lappend(nil, v289, v282);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    stack[-3] = v282;
    v282 = (Lisp_Object)17; /* 1 */
    stack[-2] = v282;
    goto v107;

v107:
    v282 = stack[-3];
    if (v282 == nil) goto v60;
    v282 = stack[-3];
    v290 = qcar(v282);
    v289 = elt(env, 4); /* infix */
    v282 = stack[-2];
    v282 = Lputprop(nil, 3, v290, v289, v282);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v282 = stack[-3];
    stack[-1] = qcar(v282);
    stack[0] = elt(env, 5); /* op */
    v289 = stack[-2];
    v282 = stack[-2];
    v282 = list2(v289, v282);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v282 = ncons(v282);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v282 = Lputprop(nil, 3, stack[-1], stack[0], v282);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v282 = stack[-3];
    v289 = qcar(v282);
    v282 = elt(env, 6); /* unary */
    v282 = get(v289, v282);
    env = stack[-4];
    stack[0] = v282;
    if (v282 == nil) goto v211;
    v290 = stack[0];
    v289 = elt(env, 4); /* infix */
    v282 = stack[-2];
    v282 = Lputprop(nil, 3, v290, v289, v282);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    goto v211;

v211:
    v282 = stack[0];
    if (v282 == nil) goto v291;
    v289 = stack[0];
    v282 = elt(env, 7); /* nary */
    v282 = Lflagp(nil, v289, v282);
    env = stack[-4];
    if (!(v282 == nil)) goto v291;
    stack[-1] = stack[0];
    stack[0] = elt(env, 5); /* op */
    v289 = qvalue(elt(env, 3)); /* nil */
    v282 = stack[-2];
    v282 = list2(v289, v282);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    v282 = Lputprop(nil, 3, stack[-1], stack[0], v282);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    goto v291;

v291:
    v282 = stack[-3];
    v282 = qcdr(v282);
    stack[-3] = v282;
    v282 = stack[-2];
    v282 = add1(v282);
    nil = C_nil;
    if (exception_pending()) goto v57;
    env = stack[-4];
    stack[-2] = v282;
    goto v107;

v60:
    v282 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v282); }
/* error exit handlers */
v57:
    popv(5);
    return nil;
}



/* Code for defined_all_edge */

static Lisp_Object MS_CDECL CC_defined_all_edge(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v64, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v288, v219, v291;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "defined_all_edge");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defined_all_edge");
#endif
    if (stack >= stacklimit)
    {
        push3(v64,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v64);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v64;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v232:
    v288 = stack[-2];
    if (v288 == nil) goto v31;
    v288 = stack[-2];
    v219 = qcar(v288);
    v288 = stack[0];
    fn = elt(env, 3); /* def_edge */
    v288 = (*qfn2(fn))(qenv(fn), v219, v288);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-4];
    if (v288 == nil) goto v35;
    v288 = stack[-2];
    v288 = qcar(v288);
    fn = elt(env, 4); /* p_def_edge */
    v288 = (*qfn1(fn))(qenv(fn), v288);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-4];
    if (v288 == nil) goto v42;
    v288 = qvalue(elt(env, 2)); /* t */
    { popv(5); return onevalue(v288); }

v42:
    v219 = stack[-1];
    v288 = stack[-2];
    stack[0] = Lnconc(nil, v219, v288);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-4];
    v288 = stack[-2];
    v288 = qcar(v288);
    v288 = qcdr(v288);
    v291 = qcar(v288);
    v219 = qvalue(elt(env, 2)); /* t */
    v288 = qvalue(elt(env, 1)); /* nil */
    v288 = list2star(v291, v219, v288);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-4];
    {
        Lisp_Object v250 = stack[0];
        popv(5);
        fn = elt(env, 5); /* rep_edge_prop_ */
        return (*qfn2(fn))(qenv(fn), v250, v288);
    }

v35:
    v288 = stack[-2];
    v288 = qcdr(v288);
    stack[-3] = v288;
    v288 = stack[-2];
    v219 = qcar(v288);
    v288 = stack[-1];
    v288 = cons(v219, v288);
    nil = C_nil;
    if (exception_pending()) goto v173;
    env = stack[-4];
    stack[-1] = v288;
    v288 = stack[-3];
    stack[-2] = v288;
    goto v232;

v31:
    v288 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v288); }
/* error exit handlers */
v173:
    popv(5);
    return nil;
}



/* Code for quotofd */

static Lisp_Object CC_quotofd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v35;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotofd");
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
    goto v107;

v107:
    v26 = stack[-2];
    if (v26 == nil) goto v234;
    v26 = stack[-2];
    if (!consp(v26)) goto v34;
    v26 = stack[-2];
    v26 = qcar(v26);
    if (!consp(v26)) goto v34;
    v26 = stack[-2];
    v26 = qcar(v26);
    stack[0] = qcar(v26);
    v26 = stack[-2];
    v26 = qcar(v26);
    v35 = qcdr(v26);
    v26 = stack[-1];
    v35 = CC_quotofd(env, v35, v26);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    v26 = stack[-3];
    v26 = acons(stack[0], v35, v26);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    stack[-3] = v26;
    v26 = stack[-2];
    v26 = qcdr(v26);
    stack[-2] = v26;
    goto v107;

v34:
    stack[0] = stack[-3];
    v35 = stack[-2];
    v26 = stack[-1];
    fn = elt(env, 1); /* quotodd */
    v26 = (*qfn2(fn))(qenv(fn), v35, v26);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-4];
    {
        Lisp_Object v229 = stack[0];
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v229, v26);
    }

v234:
    v26 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v26);
    }
/* error exit handlers */
v4:
    popv(5);
    return nil;
}



/* Code for setmatelem */

static Lisp_Object CC_setmatelem(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v279, v280, v295;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setmatelem");
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
    v279 = stack[-3];
    v280 = Llength(nil, v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-5];
    v279 = (Lisp_Object)49; /* 3 */
    if (v280 == v279) goto v225;
    v280 = stack[-3];
    v279 = elt(env, 1); /* "matrix element" */
    fn = elt(env, 9); /* typerr */
    v279 = (*qfn2(fn))(qenv(fn), v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-5];
    goto v225;

v225:
    v279 = stack[-3];
    v280 = qcar(v279);
    v279 = elt(env, 2); /* avalue */
    v279 = get(v280, v279);
    env = stack[-5];
    stack[-4] = v279;
    v279 = stack[-4];
    if (v279 == nil) goto v25;
    v279 = stack[-4];
    v280 = qcar(v279);
    v279 = elt(env, 3); /* matrix */
    if (!(v280 == v279)) goto v25;
    v279 = stack[-4];
    v279 = qcdr(v279);
    v280 = qcar(v279);
    stack[-4] = v280;
    v279 = elt(env, 5); /* mat */
    if (!consp(v280)) goto v233;
    v280 = qcar(v280);
    if (!(v280 == v279)) goto v233;

v32:
    v279 = stack[-3];
    v279 = qcdr(v279);
    v279 = qcar(v279);
    fn = elt(env, 10); /* reval_without_mod */
    v279 = (*qfn1(fn))(qenv(fn), v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-5];
    stack[0] = v279;
    v279 = stack[0];
    v279 = integerp(v279);
    if (v279 == nil) goto v282;
    v280 = stack[0];
    v279 = (Lisp_Object)1; /* 0 */
    v279 = (Lisp_Object)lesseq2(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    v279 = v279 ? lisp_true : nil;
    env = stack[-5];
    if (!(v279 == nil)) goto v282;

v58:
    v279 = stack[-4];
    v280 = qcdr(v279);
    v279 = stack[0];
    fn = elt(env, 11); /* nth */
    v279 = (*qfn2(fn))(qenv(fn), v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-5];
    stack[-4] = v279;
    v279 = stack[-3];
    v279 = qcdr(v279);
    v279 = qcdr(v279);
    v279 = qcar(v279);
    fn = elt(env, 10); /* reval_without_mod */
    v279 = (*qfn1(fn))(qenv(fn), v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-5];
    stack[0] = v279;
    v279 = stack[0];
    v279 = integerp(v279);
    if (v279 == nil) goto v272;
    v280 = stack[0];
    v279 = (Lisp_Object)1; /* 0 */
    v279 = (Lisp_Object)lesseq2(v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    v279 = v279 ? lisp_true : nil;
    env = stack[-5];
    if (!(v279 == nil)) goto v272;

v296:
    v280 = stack[-4];
    v279 = stack[0];
    fn = elt(env, 12); /* pnth */
    v280 = (*qfn2(fn))(qenv(fn), v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    v279 = stack[-2];
        popv(6);
        return Lrplaca(nil, v280, v279);

v272:
    v280 = stack[0];
    v279 = elt(env, 8); /* "positive integer" */
    fn = elt(env, 9); /* typerr */
    v279 = (*qfn2(fn))(qenv(fn), v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-5];
    goto v296;

v282:
    v280 = stack[0];
    v279 = elt(env, 8); /* "positive integer" */
    fn = elt(env, 9); /* typerr */
    v279 = (*qfn2(fn))(qenv(fn), v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-5];
    goto v58;

v233:
    stack[-1] = elt(env, 3); /* matrix */
    stack[0] = (Lisp_Object)161; /* 10 */
    v295 = elt(env, 6); /* "Matrix" */
    v279 = stack[-3];
    v280 = qcar(v279);
    v279 = elt(env, 7); /* "not set" */
    v279 = list3(v295, v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-5];
    fn = elt(env, 13); /* rerror */
    v279 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-5];
    goto v32;

v25:
    v279 = stack[-3];
    v280 = qcar(v279);
    v279 = elt(env, 4); /* "matrix" */
    fn = elt(env, 9); /* typerr */
    v279 = (*qfn2(fn))(qenv(fn), v280, v279);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-5];
    goto v32;
/* error exit handlers */
v239:
    popv(6);
    return nil;
}



/* Code for arglength */

static Lisp_Object CC_arglength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arglength");
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
    v28 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* !*intstr */
    qvalue(elt(env, 1)) = nil; /* !*intstr */
    v29 = v28;
    if (v29 == nil) goto v217;
    v29 = qvalue(elt(env, 2)); /* t */
    qvalue(elt(env, 1)) = v29; /* !*intstr */
    v29 = v28;
    fn = elt(env, 3); /* reval */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    v28 = v29;
    v29 = v28;
    if (!consp(v29)) goto v17;
    v29 = v28;
    v29 = qcdr(v29);
    v29 = Llength(nil, v29);
    nil = C_nil;
    if (exception_pending()) goto v15;
    env = stack[-1];
    goto v10;

v10:
    qvalue(elt(env, 1)) = stack[0]; /* !*intstr */
    { popv(2); return onevalue(v29); }

v17:
    v29 = (Lisp_Object)-15; /* -1 */
    goto v10;

v217:
    v29 = (Lisp_Object)1; /* 0 */
    goto v10;
/* error exit handlers */
v15:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* !*intstr */
    popv(2);
    return nil;
}



/* Code for vecsimp!* */

static Lisp_Object CC_vecsimpH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vecsimp*");
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
    fn = elt(env, 1); /* vecp */
    v52 = (*qfn1(fn))(qenv(fn), v52);
    nil = C_nil;
    if (exception_pending()) goto v214;
    env = stack[-1];
    if (v52 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v52 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* vecsm!* */
        return (*qfn1(fn))(qenv(fn), v52);
    }
/* error exit handlers */
v214:
    popv(2);
    return nil;
}



/* Code for nonlnr */

static Lisp_Object CC_nonlnr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonlnr");
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

v298:
    v20 = stack[-1];
    if (!consp(v20)) goto v10;
    v20 = stack[-1];
    v20 = qcar(v20);
    if (!consp(v20)) goto v10;
    v20 = stack[-1];
    v20 = qcar(v20);
    v20 = qcar(v20);
    v149 = qcar(v20);
    v20 = stack[0];
    v20 = Lmember(nil, v149, v20);
    if (v20 == nil) goto v3;
    v20 = stack[-1];
    v20 = qcar(v20);
    v20 = qcar(v20);
    v149 = qcdr(v20);
    v20 = (Lisp_Object)17; /* 1 */
    v20 = (Lisp_Object)greaterp2(v149, v20);
    nil = C_nil;
    if (exception_pending()) goto v284;
    v20 = v20 ? lisp_true : nil;
    env = stack[-2];
    if (!(v20 == nil)) { popv(3); return onevalue(v20); }
    v20 = stack[-1];
    v20 = qcar(v20);
    v149 = qcdr(v20);
    v20 = stack[0];
    fn = elt(env, 2); /* freeofl */
    v20 = (*qfn2(fn))(qenv(fn), v149, v20);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-2];
    v20 = (v20 == nil ? lisp_true : nil);
    if (!(v20 == nil)) { popv(3); return onevalue(v20); }
    v20 = stack[-1];
    v149 = qcdr(v20);
    v20 = stack[0];
    stack[-1] = v149;
    stack[0] = v20;
    goto v298;

v3:
    v20 = stack[-1];
    v20 = qcar(v20);
    v20 = qcar(v20);
    v149 = qcar(v20);
    v20 = stack[0];
    fn = elt(env, 2); /* freeofl */
    v20 = (*qfn2(fn))(qenv(fn), v149, v20);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-2];
    v20 = (v20 == nil ? lisp_true : nil);
    if (!(v20 == nil)) { popv(3); return onevalue(v20); }
    v20 = stack[-1];
    v20 = qcar(v20);
    v149 = qcdr(v20);
    v20 = stack[0];
    v20 = CC_nonlnr(env, v149, v20);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-2];
    if (!(v20 == nil)) { popv(3); return onevalue(v20); }
    v20 = stack[-1];
    v149 = qcdr(v20);
    v20 = stack[0];
    stack[-1] = v149;
    stack[0] = v20;
    goto v298;

v10:
    v20 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v20); }
/* error exit handlers */
v284:
    popv(3);
    return nil;
}



/* Code for cl_rename!-vars */

static Lisp_Object CC_cl_renameKvars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_rename-vars");
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
    v235 = v0;
/* end of prologue */
    stack[0] = v235;
    fn = elt(env, 1); /* cl_replace!-varl */
    v235 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-1];
    fn = elt(env, 2); /* cl_rename!-vars1 */
    v235 = (*qfn2(fn))(qenv(fn), stack[0], v235);
    nil = C_nil;
    if (exception_pending()) goto v53;
    v235 = qcar(v235);
    { popv(2); return onevalue(v235); }
/* error exit handlers */
v53:
    popv(2);
    return nil;
}



/* Code for checkdifference */

static Lisp_Object CC_checkdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v15, v16, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checkdifference");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v1;
    v30 = v0;
/* end of prologue */
    v15 = v16;
    v225 = (Lisp_Object)1; /* 0 */
    if (v15 == v225) return onevalue(v30);
    v225 = elt(env, 1); /* difference */
    v15 = v30;
    return list3(v225, v15, v16);
}



/* Code for afactor */

static Lisp_Object CC_afactor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for afactor");
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
    stack[-4] = qvalue(elt(env, 1)); /* afactorvar */
    qvalue(elt(env, 1)) = nil; /* afactorvar */
    stack[-1] = qvalue(elt(env, 2)); /* !*noextend */
    qvalue(elt(env, 2)) = nil; /* !*noextend */
    stack[0] = qvalue(elt(env, 3)); /* !*sqfree */
    qvalue(elt(env, 3)) = nil; /* !*sqfree */
    v228 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v228; /* !*noextend */
    v228 = stack[-2];
    qvalue(elt(env, 1)) = v228; /* afactorvar */
    v228 = qvalue(elt(env, 5)); /* !*trfield */
    if (v228 == nil) goto v231;
    v228 = elt(env, 6); /* "We must factorise the following over: " */
    v228 = Lprinc(nil, v228);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-5];
    v228 = qvalue(elt(env, 7)); /* listofnewsqrts */
    stack[-2] = v228;
    goto v223;

v223:
    v228 = stack[-2];
    if (v228 == nil) goto v18;
    v228 = stack[-2];
    v228 = qcar(v228);
    v228 = Lprinc(nil, v228);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-5];
    v228 = elt(env, 9); /* " " */
    v228 = Lprinc(nil, v228);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-5];
    v228 = stack[-2];
    v228 = qcdr(v228);
    stack[-2] = v228;
    goto v223;

v18:
    v228 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-5];
    v228 = stack[-3];
    fn = elt(env, 11); /* printsf */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-5];
    goto v231;

v231:
    v228 = stack[-3];
    fn = elt(env, 12); /* algfactor */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-5];
    stack[-2] = v228;
    v228 = qvalue(elt(env, 5)); /* !*trfield */
    if (v228 == nil) goto v226;
    v228 = elt(env, 10); /* "factorizes as " */
    v228 = Lprintc(nil, v228);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-5];
    v228 = stack[-2];
    stack[-3] = v228;
    goto v210;

v210:
    v228 = stack[-3];
    if (v228 == nil) goto v226;
    v228 = stack[-3];
    v228 = qcar(v228);
    fn = elt(env, 11); /* printsf */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-5];
    v228 = stack[-3];
    v228 = qcdr(v228);
    stack[-3] = v228;
    goto v210;

v226:
    v228 = stack[-2];
    qvalue(elt(env, 3)) = stack[0]; /* !*sqfree */
    qvalue(elt(env, 2)) = stack[-1]; /* !*noextend */
    qvalue(elt(env, 1)) = stack[-4]; /* afactorvar */
    { popv(6); return onevalue(v228); }
/* error exit handlers */
v62:
    env = stack[-5];
    qvalue(elt(env, 3)) = stack[0]; /* !*sqfree */
    qvalue(elt(env, 2)) = stack[-1]; /* !*noextend */
    qvalue(elt(env, 1)) = stack[-4]; /* afactorvar */
    popv(6);
    return nil;
}



/* Code for expand!-imrepart */

static Lisp_Object CC_expandKimrepart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expand-imrepart");
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
    goto v107;

v107:
    v37 = stack[-1];
    if (!consp(v37)) goto v42;
    v37 = stack[-1];
    v37 = qcar(v37);
    if (!consp(v37)) goto v42;
    v37 = stack[-1];
    v37 = qcar(v37);
    v37 = qcar(v37);
    fn = elt(env, 1); /* expand!-imrepartpow */
    stack[0] = (*qfn1(fn))(qenv(fn), v37);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    v37 = stack[-1];
    v37 = qcar(v37);
    v37 = qcdr(v37);
    v37 = CC_expandKimrepart(env, v37);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    fn = elt(env, 2); /* multsq */
    v3 = (*qfn2(fn))(qenv(fn), stack[0], v37);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    v37 = stack[-2];
    v37 = cons(v3, v37);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    stack[-2] = v37;
    v37 = stack[-1];
    v37 = qcdr(v37);
    stack[-1] = v37;
    goto v107;

v42:
    v3 = stack[-1];
    v37 = (Lisp_Object)17; /* 1 */
    v37 = cons(v3, v37);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    v3 = v37;
    goto v217;

v217:
    v37 = stack[-2];
    if (v37 == nil) { popv(4); return onevalue(v3); }
    v37 = stack[-2];
    v37 = qcar(v37);
    fn = elt(env, 3); /* addsq */
    v37 = (*qfn2(fn))(qenv(fn), v37, v3);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-3];
    v3 = v37;
    v37 = stack[-2];
    v37 = qcdr(v37);
    stack[-2] = v37;
    goto v217;
/* error exit handlers */
v63:
    popv(4);
    return nil;
}



/* Code for integralir */

static Lisp_Object MS_CDECL CC_integralir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "integralir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for integralir");
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
    v7 = qvalue(elt(env, 1)); /* atts */
    v12 = elt(env, 2); /* name */
    fn = elt(env, 7); /* find */
    v12 = (*qfn2(fn))(qenv(fn), v7, v12);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    v12 = Lintern(nil, v12);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    stack[-1] = v12;
    v12 = elt(env, 3); /* (bvar x 1) */
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    stack[0] = v12;
    v7 = stack[-1];
    v12 = elt(env, 5); /* defint */
    if (!(v7 == v12)) goto v223;
    fn = elt(env, 8); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    fn = elt(env, 9); /* omobj */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    goto v223;

v223:
    fn = elt(env, 8); /* lex */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    fn = elt(env, 9); /* omobj */
    v12 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    stack[-2] = v12;
    v12 = stack[-2];
    v12 = Lconsp(nil, v12);
    env = stack[-3];
    if (v12 == nil) goto v41;
    v12 = stack[-2];
    v7 = qcar(v12);
    v12 = elt(env, 6); /* lambda */
    if (!(v7 == v12)) goto v41;
    v12 = stack[-2];
    fn = elt(env, 10); /* lambdavar */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    stack[0] = v12;
    v12 = stack[-2];
    fn = elt(env, 11); /* lambdafun */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    stack[-2] = v12;
    goto v41;

v41:
    v7 = stack[-1];
    v12 = qvalue(elt(env, 4)); /* nil */
    stack[-1] = list2(v7, v12);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    v12 = stack[-2];
    v12 = ncons(v12);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    v12 = Lappend(nil, stack[0], v12);
    nil = C_nil;
    if (exception_pending()) goto v251;
    {
        Lisp_Object v297 = stack[-1];
        popv(4);
        return Lappend(nil, v297, v12);
    }
/* error exit handlers */
v251:
    popv(4);
    return nil;
}



/* Code for mkexpt */

static Lisp_Object CC_mkexpt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v225, v15, v16, v30;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkexpt");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v16 = v1;
    v30 = v0;
/* end of prologue */
    v15 = v16;
    v225 = (Lisp_Object)17; /* 1 */
    if (v15 == v225) return onevalue(v30);
    v225 = elt(env, 1); /* expt */
    v15 = v30;
    return list3(v225, v15, v16);
}



/* Code for d2int */

static Lisp_Object CC_d2int(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v252, v233;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for d2int");
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
    v252 = v0;
/* end of prologue */
    v63 = v252;
    v233 = qcdr(v63);
    v63 = (Lisp_Object)17; /* 1 */
    if (v233 == v63) goto v10;
    v63 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v63); }

v10:
    v63 = v252;
    v63 = qcar(v63);
    v252 = v63;
    if (is_number(v63)) { popv(3); return onevalue(v252); }
    v63 = v252;
    if (!consp(v63)) goto v15;
    v63 = v252;
    v63 = qcar(v63);
    if (!(!consp(v63))) goto v223;

v15:
    v63 = v252;
    v233 = qcar(v63);
    v63 = elt(env, 2); /* !:rd!: */
    if (!(v233 == v63)) goto v223;
    v63 = v252;
    v63 = qcdr(v63);
    stack[-1] = v63;
    v63 = stack[-1];
    v63 = Ltruncate(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    stack[0] = v63;
    v63 = stack[0];
    v252 = Lfloat(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v63 = stack[-1];
    v63 = difference2(v252, v63);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v252 = Labsval(nil, v63);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v63 = qvalue(elt(env, 3)); /* !!fleps1 */
    v63 = (Lisp_Object)lessp2(v252, v63);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v63 = v63 ? lisp_true : nil;
    env = stack[-2];
    if (!(v63 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v63 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v63); }

v223:
    v63 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v63); }
/* error exit handlers */
v62:
    popv(3);
    return nil;
}



/* Code for findhr */

static Lisp_Object MS_CDECL CC_findhr(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v6, v202;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "findhr");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findhr");
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
    stack[-1] = nil;
    goto v52;

v52:
    v6 = qvalue(elt(env, 1)); /* headhisto */
    v233 = (Lisp_Object)1; /* 0 */
    v233 = (Lisp_Object)greaterp2(v6, v233);
    nil = C_nil;
    if (exception_pending()) goto v219;
    v233 = v233 ? lisp_true : nil;
    env = stack[-2];
    if (v233 == nil) goto v10;
    v6 = qvalue(elt(env, 2)); /* codhisto */
    v233 = qvalue(elt(env, 1)); /* headhisto */
    v233 = *(Lisp_Object *)((char *)v6 + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    stack[-1] = v233;
    if (!(v233 == nil)) goto v10;
    v233 = qvalue(elt(env, 1)); /* headhisto */
    v233 = sub1(v233);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-2];
    qvalue(elt(env, 1)) = v233; /* headhisto */
    goto v52;

v10:
    v233 = stack[-1];
    if (v233 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v233 = stack[-1];
    v233 = ncons(v233);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-2];
    qvalue(elt(env, 4)) = v233; /* psi */
    v233 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 5)) = v233; /* npsi */
    stack[0] = qvalue(elt(env, 6)); /* codmat */
    v6 = qvalue(elt(env, 7)); /* maxvar */
    v233 = stack[-1];
    v233 = plus2(v6, v233);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-2];
    v202 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v233/(16/CELL)));
    v6 = (Lisp_Object)1; /* 0 */
    v233 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v202 + (CELL-TAG_VECTOR) + ((int32_t)v6/(16/CELL))) = v233;
    v6 = stack[-1];
    v233 = qvalue(elt(env, 8)); /* rcoccup */
    v233 = cons(v6, v233);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-2];
    qvalue(elt(env, 8)) = v233; /* rcoccup */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v219:
    popv(3);
    return nil;
}



/* Code for endmodule */

static Lisp_Object MS_CDECL CC_endmodule(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "endmodule");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for endmodule");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v60 = qvalue(elt(env, 1)); /* mode!-list!* */
    if (!(v60 == nil)) goto v2;
    v60 = elt(env, 2); /* "ENDMODULE called outside module" */
    fn = elt(env, 8); /* rederr */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[0];
    goto v2;

v2:
    v60 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v60; /* exportslist!* */
    v60 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 5)) = v60; /* importslist!* */
    v60 = qvalue(elt(env, 3)); /* nil */
    v60 = ncons(v60);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[0];
    qvalue(elt(env, 6)) = v60; /* alglist!* */
    v60 = qvalue(elt(env, 1)); /* mode!-list!* */
    v60 = qcar(v60);
    qvalue(elt(env, 7)) = v60; /* !*mode */
    v60 = qvalue(elt(env, 1)); /* mode!-list!* */
    v60 = qcdr(v60);
    qvalue(elt(env, 1)) = v60; /* mode!-list!* */
    v60 = nil;
    { popv(1); return onevalue(v60); }
/* error exit handlers */
v18:
    popv(1);
    return nil;
}



/* Code for gbfdiff */

static Lisp_Object CC_gbfdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbfdiff");
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
    v16 = qcar(v15);
    v15 = stack[0];
    v15 = qcar(v15);
    fn = elt(env, 1); /* difbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    v15 = stack[-1];
    v16 = qcdr(v15);
    v15 = stack[0];
    v15 = qcdr(v15);
    fn = elt(env, 1); /* difbf */
    v15 = (*qfn2(fn))(qenv(fn), v16, v15);
    nil = C_nil;
    if (exception_pending()) goto v50;
    {
        Lisp_Object v221 = stack[-2];
        popv(4);
        return cons(v221, v15);
    }
/* error exit handlers */
v50:
    popv(4);
    return nil;
}



/* Code for mkforttab */

static Lisp_Object MS_CDECL CC_mkforttab(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v17;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "mkforttab");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkforttab");
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
    stack[0] = elt(env, 1); /* forttab */
    v17 = qvalue(elt(env, 2)); /* fortcurrind!* */
    v61 = (Lisp_Object)97; /* 6 */
    v61 = plus2(v17, v61);
    nil = C_nil;
    if (exception_pending()) goto v18;
    {
        Lisp_Object v223 = stack[0];
        popv(1);
        return list2(v223, v61);
    }
/* error exit handlers */
v18:
    popv(1);
    return nil;
}



/* Code for asymmetrize!-inds */

static Lisp_Object CC_asymmetrizeKinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v315, v316;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for asymmetrize-inds");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    v315 = (Lisp_Object)1; /* 0 */
    stack[-10] = v315;
    v315 = stack[-9];
    stack[-7] = v315;
    v315 = stack[-7];
    if (v315 == nil) goto v260;
    v315 = stack[-7];
    v315 = qcar(v315);
    v316 = v315;
    if (!consp(v316)) goto v221;
    stack[-3] = v315;
    v315 = stack[-3];
    if (v315 == nil) goto v47;
    v315 = stack[-3];
    v315 = qcar(v315);
    v316 = stack[-8];
    fn = elt(env, 2); /* nth */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    stack[-1] = v315;
    stack[-2] = v315;
    goto v177;

v177:
    v315 = stack[-3];
    v315 = qcdr(v315);
    stack[-3] = v315;
    v315 = stack[-3];
    if (v315 == nil) goto v233;
    stack[0] = stack[-1];
    v315 = stack[-3];
    v315 = qcar(v315);
    v316 = stack[-8];
    fn = elt(env, 2); /* nth */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = Lrplacd(nil, stack[0], v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = stack[-1];
    v315 = qcdr(v315);
    stack[-1] = v315;
    goto v177;

v233:
    v315 = stack[-2];
    goto v16;

v16:
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    stack[-5] = v315;
    stack[-6] = v315;
    goto v17;

v17:
    v315 = stack[-7];
    v315 = qcdr(v315);
    stack[-7] = v315;
    v315 = stack[-7];
    if (v315 == nil) goto v284;
    stack[-4] = stack[-5];
    v315 = stack[-7];
    v315 = qcar(v315);
    v316 = v315;
    if (!consp(v316)) goto v58;
    stack[-3] = v315;
    v315 = stack[-3];
    if (v315 == nil) goto v318;
    v315 = stack[-3];
    v315 = qcar(v315);
    v316 = stack[-8];
    fn = elt(env, 2); /* nth */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    stack[-1] = v315;
    stack[-2] = v315;
    goto v246;

v246:
    v315 = stack[-3];
    v315 = qcdr(v315);
    stack[-3] = v315;
    v315 = stack[-3];
    if (v315 == nil) goto v243;
    stack[0] = stack[-1];
    v315 = stack[-3];
    v315 = qcar(v315);
    v316 = stack[-8];
    fn = elt(env, 2); /* nth */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = Lrplacd(nil, stack[0], v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = stack[-1];
    v315 = qcdr(v315);
    stack[-1] = v315;
    goto v246;

v243:
    v315 = stack[-2];
    goto v319;

v319:
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = Lrplacd(nil, stack[-4], v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = stack[-5];
    v315 = qcdr(v315);
    stack[-5] = v315;
    goto v17;

v318:
    v315 = qvalue(elt(env, 1)); /* nil */
    goto v319;

v58:
    v316 = stack[-8];
    fn = elt(env, 2); /* nth */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    goto v319;

v284:
    v315 = stack[-6];
    goto v61;

v61:
    stack[0] = v315;
    v315 = stack[0];
    fn = elt(env, 3); /* repeats */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    if (v315 == nil) goto v320;
    v315 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v315); }

v320:
    v315 = stack[0];
    v315 = qcar(v315);
    if (!consp(v315)) goto v253;
    v315 = stack[0];
    fn = elt(env, 4); /* indordln */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v316 = v315;
    goto v152;

v152:
    stack[-5] = v316;
    v315 = stack[0];
    fn = elt(env, 5); /* permp */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    if (v315 == nil) goto v321;
    v315 = (Lisp_Object)17; /* 1 */
    goto v258;

v258:
    stack[0] = v315;
    v315 = stack[-9];
    v315 = qcar(v315);
    if (!consp(v315)) goto v322;
    v315 = stack[-9];
    fn = elt(env, 6); /* flatindl */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    stack[-9] = v315;
    v315 = stack[-5];
    fn = elt(env, 6); /* flatindl */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    stack[-5] = v315;
    goto v322;

v322:
    v316 = stack[-9];
    v315 = stack[-5];
    fn = elt(env, 7); /* pair */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    stack[-5] = v315;
    stack[-6] = stack[0];
    v315 = stack[-8];
    stack[-7] = v315;
    v315 = stack[-7];
    if (v315 == nil) goto v143;
    v315 = stack[-7];
    v315 = qcar(v315);
    stack[-1] = v315;
    v315 = stack[-5];
    if (v315 == nil) goto v323;
    v315 = stack[-5];
    v315 = qcar(v315);
    stack[0] = qcar(v315);
    v315 = stack[-10];
    v315 = add1(v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    stack[-10] = v315;
    if (!(equal(stack[0], v315))) goto v323;
    v315 = stack[-5];
    v315 = qcar(v315);
    v315 = qcdr(v315);
    v316 = v315;
    v315 = stack[-5];
    v315 = qcdr(v315);
    stack[-5] = v315;
    v315 = v316;
    goto v324;

v324:
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    stack[-3] = v315;
    stack[-4] = v315;
    goto v325;

v325:
    v315 = stack[-7];
    v315 = qcdr(v315);
    stack[-7] = v315;
    v315 = stack[-7];
    if (v315 == nil) goto v326;
    stack[-2] = stack[-3];
    v315 = stack[-7];
    v315 = qcar(v315);
    stack[-1] = v315;
    v315 = stack[-5];
    if (v315 == nil) goto v327;
    v315 = stack[-5];
    v315 = qcar(v315);
    stack[0] = qcar(v315);
    v315 = stack[-10];
    v315 = add1(v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    stack[-10] = v315;
    if (!(equal(stack[0], v315))) goto v327;
    v315 = stack[-5];
    v315 = qcar(v315);
    v315 = qcdr(v315);
    v316 = v315;
    v315 = stack[-5];
    v315 = qcdr(v315);
    stack[-5] = v315;
    v315 = v316;
    goto v328;

v328:
    v315 = ncons(v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = Lrplacd(nil, stack[-2], v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v315 = stack[-3];
    v315 = qcdr(v315);
    stack[-3] = v315;
    goto v325;

v327:
    v315 = stack[-1];
    goto v328;

v326:
    v315 = stack[-4];
    goto v147;

v147:
    {
        Lisp_Object v188 = stack[-6];
        popv(12);
        return cons(v188, v315);
    }

v323:
    v315 = stack[-1];
    goto v324;

v143:
    v315 = qvalue(elt(env, 1)); /* nil */
    goto v147;

v321:
    v315 = (Lisp_Object)-15; /* -1 */
    goto v258;

v253:
    v315 = stack[0];
    fn = elt(env, 8); /* indordn */
    v315 = (*qfn1(fn))(qenv(fn), v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    v316 = v315;
    goto v152;

v47:
    v315 = qvalue(elt(env, 1)); /* nil */
    goto v16;

v221:
    v316 = stack[-8];
    fn = elt(env, 2); /* nth */
    v315 = (*qfn2(fn))(qenv(fn), v316, v315);
    nil = C_nil;
    if (exception_pending()) goto v317;
    env = stack[-11];
    goto v16;

v260:
    v315 = qvalue(elt(env, 1)); /* nil */
    goto v61;
/* error exit handlers */
v317:
    popv(12);
    return nil;
}



/* Code for mo_support */

static Lisp_Object CC_mo_support(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_support");
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
    v227 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 3); /* ring_names */
    v227 = (*qfn1(fn))(qenv(fn), v227);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-4];
    stack[-1] = v227;
    goto v217;

v217:
    v227 = stack[-1];
    if (v227 == nil) goto v232;
    v227 = stack[-1];
    v227 = qcar(v227);
    stack[0] = v227;
    v227 = stack[0];
    fn = elt(env, 4); /* mo_from_a */
    v213 = (*qfn1(fn))(qenv(fn), v227);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-4];
    v227 = stack[-2];
    fn = elt(env, 5); /* mo_divides!? */
    v227 = (*qfn2(fn))(qenv(fn), v213, v227);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-4];
    if (v227 == nil) goto v260;
    v213 = stack[0];
    v227 = stack[-3];
    v227 = cons(v213, v227);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-4];
    stack[-3] = v227;
    goto v260;

v260:
    v227 = stack[-1];
    v227 = qcdr(v227);
    stack[-1] = v227;
    goto v217;

v232:
    v227 = stack[-3];
        popv(5);
        return Lnreverse(nil, v227);
/* error exit handlers */
v276:
    popv(5);
    return nil;
}



/* Code for nonmult */

static Lisp_Object CC_nonmult(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v260, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonmult");
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
    v260 = qvalue(elt(env, 1)); /* vjets */
    v34 = Lreverse(nil, v260);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v260 = stack[0];
    fn = elt(env, 2); /* nth */
    stack[0] = (*qfn2(fn))(qenv(fn), v34, v260);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-1];
    v260 = qvalue(elt(env, 1)); /* vjets */
    v260 = Lreverse(nil, v260);
    nil = C_nil;
    if (exception_pending()) goto v22;
    v260 = Lmember(nil, stack[0], v260);
    v260 = qcdr(v260);
        popv(2);
        return Lreverse(nil, v260);
/* error exit handlers */
v22:
    popv(2);
    return nil;
}



/* Code for arminusp!: */

static Lisp_Object CC_arminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arminusp:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v10 = v0;
/* end of prologue */
    v10 = qcdr(v10);
    {
        fn = elt(env, 1); /* minusf */
        return (*qfn1(fn))(qenv(fn), v10);
    }
}



/* Code for cl_sitheo */

static Lisp_Object CC_cl_sitheo(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v291, v11;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sitheo");
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
    stack[-1] = nil;
    stack[0] = qvalue(elt(env, 1)); /* !*rlsiexpla */
    qvalue(elt(env, 1)) = nil; /* !*rlsiexpla */
    v219 = qvalue(elt(env, 2)); /* !*rlsithok */
    if (v219 == nil) goto v61;
    v219 = stack[-2];
    goto v232;

v232:
    qvalue(elt(env, 1)) = stack[0]; /* !*rlsiexpla */
    { popv(5); return onevalue(v219); }

v61:
    v219 = stack[-2];
    if (v219 == nil) goto v229;
    v219 = stack[-2];
    v219 = qcar(v219);
    stack[-3] = v219;
    v219 = stack[-2];
    v219 = qcdr(v219);
    stack[-2] = v219;
    v291 = stack[-3];
    v219 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 7); /* cl_simplat */
    v219 = (*qfn2(fn))(qenv(fn), v291, v219);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    v11 = v219;
    v291 = v11;
    v219 = elt(env, 4); /* false */
    if (v291 == v219) goto v32;
    v291 = v11;
    v219 = elt(env, 6); /* true */
    if (v291 == v219) goto v61;
    v291 = v11;
    v219 = stack[-1];
    v219 = cons(v291, v219);
    nil = C_nil;
    if (exception_pending()) goto v250;
    env = stack[-4];
    stack[-1] = v219;
    goto v61;

v32:
    v219 = elt(env, 5); /* inctheo */
    stack[-3] = v219;
    v219 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v219;
    goto v61;

v229:
    v291 = stack[-3];
    v219 = elt(env, 5); /* inctheo */
    if (v291 == v219) goto v3;
    v219 = stack[-1];
    goto v232;

v3:
    v219 = elt(env, 5); /* inctheo */
    goto v232;
/* error exit handlers */
v250:
    env = stack[-4];
    qvalue(elt(env, 1)) = stack[0]; /* !*rlsiexpla */
    popv(5);
    return nil;
}



/* Code for simp0 */

static Lisp_Object CC_simp0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v275;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp0");
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
    stack[-5] = qvalue(elt(env, 1)); /* !*factor */
    qvalue(elt(env, 1)) = nil; /* !*factor */
    v275 = stack[-4];
    v27 = elt(env, 2); /* !*sq */
    if (!consp(v275)) goto v28;
    v275 = qcar(v275);
    if (!(v275 == v27)) goto v28;
    v27 = stack[-4];
    v27 = qcdr(v27);
    v27 = qcar(v27);
    fn = elt(env, 9); /* prepsq!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    v27 = CC_simp0(env, v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    goto v232;

v232:
    qvalue(elt(env, 1)) = stack[-5]; /* !*factor */
    { popv(7); return onevalue(v27); }

v28:
    v275 = stack[-4];
    v27 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 10); /* frvarsof */
    v27 = (*qfn2(fn))(qenv(fn), v275, v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    fn = elt(env, 11); /* setkorder */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    stack[-2] = v27;
    v275 = qvalue(elt(env, 4)); /* subfg!* */
    v27 = qvalue(elt(env, 5)); /* !*sub2 */
    v27 = cons(v275, v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    stack[-3] = v27;
    v27 = qvalue(elt(env, 3)); /* nil */
    v27 = ncons(v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    qvalue(elt(env, 6)) = v27; /* alglist!* */
    v27 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v27; /* subfg!* */
    v27 = stack[-4];
    if (!consp(v27)) goto v212;
    v27 = stack[-4];
    v27 = qcar(v27);
    if (!(symbolp(v27))) goto v219;
    v27 = stack[-4];
    v275 = qcar(v27);
    v27 = elt(env, 7); /* simp0fn */
    v27 = Lflagp(nil, v275, v27);
    env = stack[-6];
    if (!(v27 == nil)) goto v212;
    v27 = stack[-4];
    v275 = qcar(v27);
    v27 = elt(env, 8); /* rtype */
    v27 = get(v275, v27);
    env = stack[-6];
    if (!(v27 == nil)) goto v212;

v219:
    v27 = stack[-4];
    fn = elt(env, 12); /* simpiden */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    stack[-1] = v27;
    goto v175;

v175:
    stack[0] = qvalue(elt(env, 6)); /* alglist!* */
    v275 = stack[-4];
    v27 = qvalue(elt(env, 6)); /* alglist!* */
    v27 = qcar(v27);
    fn = elt(env, 13); /* delasc */
    v27 = (*qfn2(fn))(qenv(fn), v275, v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    v27 = Lrplaca(nil, stack[0], v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    v27 = stack[-3];
    v27 = qcar(v27);
    qvalue(elt(env, 4)) = v27; /* subfg!* */
    v27 = stack[-3];
    v27 = qcdr(v27);
    qvalue(elt(env, 5)) = v27; /* !*sub2 */
    v27 = stack[-2];
    fn = elt(env, 11); /* setkorder */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    v27 = stack[-1];
    goto v232;

v212:
    v27 = stack[-4];
    fn = elt(env, 14); /* simp */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-6];
    stack[-1] = v27;
    goto v175;
/* error exit handlers */
v43:
    env = stack[-6];
    qvalue(elt(env, 1)) = stack[-5]; /* !*factor */
    popv(7);
    return nil;
}



/* Code for nlist */

static Lisp_Object CC_nlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nlist");
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
    goto v231;

v231:
    v49 = stack[0];
    v24 = (Lisp_Object)1; /* 0 */
    if (v49 == v24) goto v234;
    v49 = stack[-1];
    v24 = stack[-2];
    v24 = cons(v49, v24);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    stack[-2] = v24;
    v24 = stack[0];
    v24 = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-3];
    stack[0] = v24;
    goto v231;

v234:
    v24 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v24);
    }
/* error exit handlers */
v32:
    popv(4);
    return nil;
}



/* Code for bc_mkat */

static Lisp_Object CC_bc_mkat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v214, v61, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc_mkat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v214 = v1;
    v61 = v0;
/* end of prologue */
    v214 = qcar(v214);
    v17 = qvalue(elt(env, 1)); /* nil */
    return list3(v61, v214, v17);
}



/* Code for transposerd */

static Lisp_Object MS_CDECL CC_transposerd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "transposerd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for transposerd");
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
    v17 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-1];
    v60 = elt(env, 1); /* tp */
    v17 = list2(v60, v17);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-1];
    fn = elt(env, 3); /* aeval */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v223;
    env = stack[-1];
    stack[0] = v17;
    fn = elt(env, 4); /* lex */
    v17 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v223;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v223:
    popv(2);
    return nil;
}



/* Code for simpu */

static Lisp_Object CC_simpu(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v271, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpu");
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
    v38 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* u */
    v271 = v38;
    stack[0] = qcar(v271);
    v271 = v38;
    v271 = qcdr(v271);
    fn = elt(env, 2); /* ordn */
    v271 = (*qfn1(fn))(qenv(fn), v271);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    v271 = Lreverse(nil, v271);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    v38 = list2star(stack[-1], stack[0], v271);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    v271 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* mksp */
    v38 = (*qfn2(fn))(qenv(fn), v38, v271);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    v271 = (Lisp_Object)17; /* 1 */
    v271 = cons(v38, v271);
    nil = C_nil;
    if (exception_pending()) goto v226;
    env = stack[-2];
    v38 = ncons(v271);
    nil = C_nil;
    if (exception_pending()) goto v226;
    v271 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v38, v271);
/* error exit handlers */
v226:
    popv(3);
    return nil;
}



/* Code for simppartdf */

static Lisp_Object CC_simppartdf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simppartdf");
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
    v10 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitpartdf */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v10);
    }
/* error exit handlers */
v107:
    popv(1);
    return nil;
}



/* Code for greaterpcdr */

static Lisp_Object CC_greaterpcdr(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v53;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for greaterpcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v52 = v1;
    v53 = v0;
/* end of prologue */
    v53 = qcdr(v53);
    v52 = qcdr(v52);
        return Lgreaterp(nil, v53, v52);
}



/* Code for mo!=expvec2a1 */

static Lisp_Object CC_moMexpvec2a1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v288, v219, v291;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=expvec2a1");
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
    goto v107;

v107:
    v288 = stack[-1];
    if (v288 == nil) goto v234;
    v288 = stack[-1];
    v219 = qcar(v288);
    v288 = (Lisp_Object)1; /* 0 */
    if (v219 == v288) goto v53;
    v288 = stack[-1];
    v219 = qcar(v288);
    v288 = (Lisp_Object)17; /* 1 */
    if (v219 == v288) goto v271;
    v291 = elt(env, 1); /* expt */
    v288 = stack[0];
    v219 = qcar(v288);
    v288 = stack[-1];
    v288 = qcar(v288);
    v219 = list3(v291, v219, v288);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    v288 = stack[-2];
    v288 = cons(v219, v288);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    stack[-2] = v288;
    v288 = stack[-1];
    v288 = qcdr(v288);
    stack[-1] = v288;
    v288 = stack[0];
    v288 = qcdr(v288);
    stack[0] = v288;
    goto v107;

v271:
    v288 = stack[0];
    v219 = qcar(v288);
    v288 = stack[-2];
    v288 = cons(v219, v288);
    nil = C_nil;
    if (exception_pending()) goto v175;
    env = stack[-3];
    stack[-2] = v288;
    v288 = stack[-1];
    v288 = qcdr(v288);
    stack[-1] = v288;
    v288 = stack[0];
    v288 = qcdr(v288);
    stack[0] = v288;
    goto v107;

v53:
    v288 = stack[-1];
    v288 = qcdr(v288);
    stack[-1] = v288;
    v288 = stack[0];
    v288 = qcdr(v288);
    stack[0] = v288;
    goto v107;

v234:
    v288 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v288);
    }
/* error exit handlers */
v175:
    popv(4);
    return nil;
}



/* Code for cgp_lbc */

static Lisp_Object CC_cgp_lbc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_lbc");
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
    v10 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dip_lbc */
        return (*qfn1(fn))(qenv(fn), v10);
    }
/* error exit handlers */
v107:
    popv(1);
    return nil;
}



/* Code for cols2rows2 */

static Lisp_Object CC_cols2rows2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v271, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cols2rows2");
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
    v38 = stack[0];
    v271 = (Lisp_Object)1; /* 0 */
    if (v38 == v271) goto v107;
    v38 = stack[-1];
    v271 = stack[0];
    fn = elt(env, 1); /* ithlistelem */
    stack[-2] = (*qfn2(fn))(qenv(fn), v38, v271);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v271 = stack[0];
    v271 = sub1(v271);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-3];
    v271 = CC_cols2rows2(env, stack[-1], v271);
    nil = C_nil;
    if (exception_pending()) goto v33;
    {
        Lisp_Object v227 = stack[-2];
        popv(4);
        return cons(v227, v271);
    }

v107:
    v271 = nil;
    { popv(4); return onevalue(v271); }
/* error exit handlers */
v33:
    popv(4);
    return nil;
}



/* Code for findnthroot */

static Lisp_Object CC_findnthroot(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v220;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findnthroot");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v220 = v0;
/* end of prologue */
    v220 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v220);
}



setup_type const u31_setup[] =
{
    {"mk+inner+product",        too_few_2,      CC_mkLinnerLproduct,wrong_no_2},
    {"ratpoly_mvartest",        too_few_2,      CC_ratpoly_mvartest,wrong_no_2},
    {"ciom",                    CC_ciom,        too_many_1,    wrong_no_1},
    {"binomial-coefft-mod-p",   too_few_2,      CC_binomialKcoefftKmodKp,wrong_no_2},
    {"prepsq*1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_prepsqH1},
    {"mksqrt",                  CC_mksqrt,      too_many_1,    wrong_no_1},
    {"prsubsetrd",              CC_prsubsetrd,  too_many_1,    wrong_no_1},
    {"boolvalue*",              CC_boolvalueH,  too_many_1,    wrong_no_1},
    {"gfdiffer",                too_few_2,      CC_gfdiffer,   wrong_no_2},
    {"replace2_parents",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_replace2_parents},
    {"fs:prepfn:",              CC_fsTprepfnT,  too_many_1,    wrong_no_1},
    {"mkindxlist",              CC_mkindxlist,  too_many_1,    wrong_no_1},
    {"num_signsort",            CC_num_signsort,too_many_1,    wrong_no_1},
    {"lambda_l73kgy_8",         too_few_2,      CC_lambda_l73kgy_8,wrong_no_2},
    {"split-further",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitKfurther},
    {"mkrootsql",               too_few_2,      CC_mkrootsql,  wrong_no_2},
    {"totalcompareconstants",   too_few_2,      CC_totalcompareconstants,wrong_no_2},
    {"aex_reducedtag",          CC_aex_reducedtag,too_many_1,  wrong_no_1},
    {"diffrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffrd},
    {"sroot1",                  too_few_2,      CC_sroot1,     wrong_no_2},
    {"bflessp",                 too_few_2,      CC_bflessp,    wrong_no_2},
    {"mkprec",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkprec},
    {"defined_all_edge",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_defined_all_edge},
    {"quotofd",                 too_few_2,      CC_quotofd,    wrong_no_2},
    {"setmatelem",              too_few_2,      CC_setmatelem, wrong_no_2},
    {"arglength",               CC_arglength,   too_many_1,    wrong_no_1},
    {"vecsimp*",                CC_vecsimpH,    too_many_1,    wrong_no_1},
    {"nonlnr",                  too_few_2,      CC_nonlnr,     wrong_no_2},
    {"cl_rename-vars",          CC_cl_renameKvars,too_many_1,  wrong_no_1},
    {"checkdifference",         too_few_2,      CC_checkdifference,wrong_no_2},
    {"afactor",                 too_few_2,      CC_afactor,    wrong_no_2},
    {"expand-imrepart",         CC_expandKimrepart,too_many_1, wrong_no_1},
    {"integralir",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_integralir},
    {"mkexpt",                  too_few_2,      CC_mkexpt,     wrong_no_2},
    {"d2int",                   CC_d2int,       too_many_1,    wrong_no_1},
    {"findhr",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_findhr},
    {"endmodule",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_endmodule},
    {"gbfdiff",                 too_few_2,      CC_gbfdiff,    wrong_no_2},
    {"mkforttab",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mkforttab},
    {"asymmetrize-inds",        too_few_2,      CC_asymmetrizeKinds,wrong_no_2},
    {"mo_support",              CC_mo_support,  too_many_1,    wrong_no_1},
    {"nonmult",                 CC_nonmult,     too_many_1,    wrong_no_1},
    {"arminusp:",               CC_arminuspT,   too_many_1,    wrong_no_1},
    {"cl_sitheo",               CC_cl_sitheo,   too_many_1,    wrong_no_1},
    {"simp0",                   CC_simp0,       too_many_1,    wrong_no_1},
    {"nlist",                   too_few_2,      CC_nlist,      wrong_no_2},
    {"bc_mkat",                 too_few_2,      CC_bc_mkat,    wrong_no_2},
    {"transposerd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_transposerd},
    {"simpu",                   CC_simpu,       too_many_1,    wrong_no_1},
    {"simppartdf",              CC_simppartdf,  too_many_1,    wrong_no_1},
    {"greaterpcdr",             too_few_2,      CC_greaterpcdr,wrong_no_2},
    {"mo=expvec2a1",            too_few_2,      CC_moMexpvec2a1,wrong_no_2},
    {"cgp_lbc",                 CC_cgp_lbc,     too_many_1,    wrong_no_1},
    {"cols2rows2",              too_few_2,      CC_cols2rows2, wrong_no_2},
    {"findnthroot",             CC_findnthroot, too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u31", (two_args *)"2607 3798820 9638077", 0}
};

/* end of generated code */
