
/* $destdir/generated-c\u50.c Machine generated C code */

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


/* Code for simptensor */

static Lisp_Object CC_simptensor(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simptensor");
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
    stack[0] = nil;
    v112 = stack[-4];
    v111 = elt(env, 1); /* list */
    fn = elt(env, 11); /* splitlist!: */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[-5] = v111;
    v111 = stack[-5];
    if (!(v111 == nil)) goto v115;
    v111 = stack[-4];
    v111 = qcdr(v111);
    fn = elt(env, 12); /* extract_vars */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v112 = v111;
    v111 = v112;
    if (v111 == nil) goto v115;
    v111 = v112;
    stack[-5] = v111;
    v111 = qvalue(elt(env, 2)); /* t */
    stack[0] = v111;
    goto v115;

v115:
    v111 = stack[-5];
    if (v111 == nil) goto v116;
    v111 = stack[-4];
    v112 = qcdr(v111);
    v111 = stack[-5];
    fn = elt(env, 13); /* setdiff */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    goto v117;

v117:
    stack[-1] = v111;
    v111 = stack[0];
    if (v111 == nil) goto v118;
    v112 = elt(env, 1); /* list */
    v111 = stack[-5];
    v111 = cons(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    goto v119;

v119:
    stack[-5] = v111;
    v111 = stack[-5];
    fn = elt(env, 14); /* reval */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[-5] = v111;
    v111 = stack[-1];
    stack[-3] = v111;
    v111 = stack[-3];
    if (v111 == nil) goto v120;
    v111 = stack[-3];
    v111 = qcar(v111);
    fn = elt(env, 15); /* revalind */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[-1] = v111;
    stack[-2] = v111;
    goto v121;

v121:
    v111 = stack[-3];
    v111 = qcdr(v111);
    stack[-3] = v111;
    v111 = stack[-3];
    if (v111 == nil) goto v122;
    stack[0] = stack[-1];
    v111 = stack[-3];
    v111 = qcar(v111);
    fn = elt(env, 15); /* revalind */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = Lrplacd(nil, stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = stack[-1];
    v111 = qcdr(v111);
    stack[-1] = v111;
    goto v121;

v122:
    v111 = stack[-2];
    goto v123;

v123:
    fn = elt(env, 16); /* mkindxlist */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[0] = v111;
    v111 = stack[0];
    stack[-3] = v111;
    v111 = stack[-3];
    if (v111 == nil) goto v124;
    v111 = stack[-3];
    v111 = qcar(v111);
    fn = elt(env, 14); /* reval */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[-1] = v111;
    stack[-2] = v111;
    goto v125;

v125:
    v111 = stack[-3];
    v111 = qcdr(v111);
    stack[-3] = v111;
    v111 = stack[-3];
    if (v111 == nil) goto v126;
    stack[0] = stack[-1];
    v111 = stack[-3];
    v111 = qcar(v111);
    fn = elt(env, 14); /* reval */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = Lrplacd(nil, stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = stack[-1];
    v111 = qcdr(v111);
    stack[-1] = v111;
    goto v125;

v126:
    v111 = stack[-2];
    goto v127;

v127:
    stack[0] = v111;
    v111 = stack[0];
    stack[-3] = v111;
    v111 = stack[-3];
    if (v111 == nil) goto v128;
    v111 = stack[-3];
    v111 = qcar(v111);
    fn = elt(env, 15); /* revalind */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[-1] = v111;
    stack[-2] = v111;
    goto v129;

v129:
    v111 = stack[-3];
    v111 = qcdr(v111);
    stack[-3] = v111;
    v111 = stack[-3];
    if (v111 == nil) goto v130;
    stack[0] = stack[-1];
    v111 = stack[-3];
    v111 = qcar(v111);
    fn = elt(env, 15); /* revalind */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = Lrplacd(nil, stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = stack[-1];
    v111 = qcdr(v111);
    stack[-1] = v111;
    goto v129;

v130:
    v111 = stack[-2];
    goto v131;

v131:
    fn = elt(env, 16); /* mkindxlist */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[0] = v111;
    v111 = stack[-4];
    v112 = qcar(v111);
    v111 = stack[0];
    v111 = cons(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[0] = v111;
    v111 = stack[0];
    v111 = qcdr(v111);
    fn = elt(env, 17); /* split_cov_cont_ids */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[-1] = v111;
    v112 = stack[-1];
    v111 = stack[-4];
    v111 = qcar(v111);
    fn = elt(env, 18); /* num_ids_range */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = stack[-1];
    fn = elt(env, 19); /* mk_dummy_ids */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = stack[-1];
    fn = elt(env, 20); /* verify_tens_ids */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = stack[-4];
    v112 = qcar(v111);
    v111 = elt(env, 4); /* bloc_diagonal */
    v111 = get(v112, v111);
    env = stack[-6];
    v112 = v111;
    v111 = v112;
    if (v111 == nil) goto v132;
    v111 = stack[-1];
    v111 = Lapply1(nil, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    goto v133;

v133:
    if (v111 == nil) goto v134;
    v112 = qvalue(elt(env, 3)); /* nil */
    v111 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v112, v111);

v134:
    v111 = stack[0];
    v112 = qcar(v111);
    v111 = elt(env, 5); /* partic_tens */
    v111 = get(v112, v111);
    env = stack[-6];
    v113 = v111;
    if (v111 == nil) goto v135;
    v111 = stack[-4];
    v112 = qcar(v111);
    v111 = elt(env, 6); /* generic */
    v111 = Lflagp(nil, v112, v111);
    env = stack[-6];
    if (v111 == nil) goto v136;
    v112 = v113;
    v111 = elt(env, 7); /* simpdelt */
    if (v112 == v111) goto v137;
    v112 = stack[0];
    v111 = stack[-5];
        popv(7);
        return Lapply2(nil, 3, v113, v112, v111);

v137:
    v112 = stack[0];
    v111 = stack[-5];
    v112 = Lapply2(nil, 3, v113, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v111 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v112, v111);

v136:
    v112 = v113;
    v111 = stack[0];
    v112 = Lapply1(nil, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    v111 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v112, v111);

v135:
    v111 = stack[0];
    v112 = qcar(v111);
    v111 = elt(env, 8); /* symmetric */
    v111 = Lflagp(nil, v112, v111);
    env = stack[-6];
    if (v111 == nil) goto v138;
    v111 = stack[0];
    stack[-1] = qcar(v111);
    v111 = stack[-5];
    if (v111 == nil) goto v139;
    stack[-2] = stack[-5];
    v111 = stack[0];
    v111 = qcdr(v111);
    fn = elt(env, 21); /* ordn */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    fn = elt(env, 22); /* cont_before_cov */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = cons(stack[-2], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    goto v140;

v140:
    v112 = cons(stack[-1], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 23); /* mksq */
        return (*qfn2(fn))(qenv(fn), v112, v111);
    }

v139:
    v111 = stack[0];
    v111 = qcdr(v111);
    fn = elt(env, 21); /* ordn */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    fn = elt(env, 22); /* cont_before_cov */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    goto v140;

v138:
    v111 = stack[0];
    v112 = qcar(v111);
    v111 = elt(env, 9); /* antisymmetric */
    v111 = Lflagp(nil, v112, v111);
    env = stack[-6];
    if (v111 == nil) goto v141;
    v111 = stack[-4];
    fn = elt(env, 24); /* affinep */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    if (v111 == nil) goto v142;
    v111 = stack[0];
    v111 = qcdr(v111);
    goto v143;

v143:
    fn = elt(env, 25); /* repeats */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    if (v111 == nil) goto v144;
    v112 = qvalue(elt(env, 3)); /* nil */
    v111 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v112, v111);

v144:
    v111 = stack[0];
    v111 = qcdr(v111);
    fn = elt(env, 21); /* ordn */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    fn = elt(env, 22); /* cont_before_cov */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    stack[-1] = v111;
    v112 = stack[-1];
    v111 = stack[0];
    v111 = qcdr(v111);
    fn = elt(env, 26); /* permp!: */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    if (v111 == nil) goto v145;
    v111 = stack[0];
    stack[0] = qcar(v111);
    v111 = stack[-5];
    if (v111 == nil) goto v146;
    v112 = stack[-5];
    v111 = stack[-1];
    v111 = cons(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    goto v147;

v147:
    v112 = cons(stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 23); /* mksq */
        return (*qfn2(fn))(qenv(fn), v112, v111);
    }

v146:
    v111 = stack[-1];
    goto v147;

v145:
    v111 = stack[0];
    stack[0] = qcar(v111);
    v111 = stack[-5];
    if (v111 == nil) goto v148;
    v112 = stack[-5];
    v111 = stack[-1];
    v111 = cons(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    goto v149;

v149:
    v112 = cons(stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v111 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 23); /* mksq */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 27); /* negsq */
        return (*qfn1(fn))(qenv(fn), v111);
    }

v148:
    v111 = stack[-1];
    goto v149;

v142:
    v111 = stack[0];
    v111 = qcdr(v111);
    fn = elt(env, 17); /* split_cov_cont_ids */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v112 = v111;
    v112 = qcar(v112);
    v111 = qcdr(v111);
    v111 = qcar(v111);
    v111 = Lappend(nil, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    goto v143;

v141:
    v111 = stack[-4];
    v112 = qcar(v111);
    v111 = elt(env, 10); /* symtree */
    v112 = get(v112, v111);
    env = stack[-6];
    v111 = v112;
    if (v112 == nil) goto v150;
    v112 = stack[0];
    v112 = qcdr(v112);
    fn = elt(env, 28); /* symtree_zerop */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    if (v111 == nil) goto v151;
    v112 = qvalue(elt(env, 3)); /* nil */
    v111 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v112, v111);

v151:
    v111 = stack[-5];
    if (v111 == nil) goto v152;
    v111 = stack[0];
    v113 = qcar(v111);
    v112 = stack[-5];
    v111 = stack[0];
    v111 = qcdr(v111);
    v111 = list2star(v113, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v112 = v111;
    goto v153;

v153:
    v111 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 23); /* mksq */
        return (*qfn2(fn))(qenv(fn), v112, v111);
    }

v152:
    v111 = stack[0];
    v112 = v111;
    goto v153;

v150:
    v111 = stack[-5];
    if (v111 == nil) goto v154;
    v111 = stack[0];
    v113 = qcar(v111);
    v112 = stack[-5];
    v111 = stack[0];
    v111 = qcdr(v111);
    v111 = list2star(v113, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v114;
    env = stack[-6];
    v112 = v111;
    goto v155;

v155:
    v111 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 23); /* mksq */
        return (*qfn2(fn))(qenv(fn), v112, v111);
    }

v154:
    v111 = stack[0];
    v112 = v111;
    goto v155;

v132:
    v111 = nil;
    goto v133;

v128:
    v111 = qvalue(elt(env, 3)); /* nil */
    goto v131;

v124:
    v111 = qvalue(elt(env, 3)); /* nil */
    goto v127;

v120:
    v111 = qvalue(elt(env, 3)); /* nil */
    goto v123;

v118:
    v111 = stack[-5];
    if (v111 == nil) goto v156;
    v111 = stack[-5];
    v111 = qcar(v111);
    goto v119;

v156:
    v111 = nil;
    goto v119;

v116:
    v111 = stack[-4];
    v111 = qcdr(v111);
    goto v117;
/* error exit handlers */
v114:
    popv(7);
    return nil;
}



/* Code for gfminus */

static Lisp_Object CC_gfminus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v159;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfminus");
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
    v159 = stack[0];
    v159 = qcar(v159);
    fn = elt(env, 1); /* bfminus */
    stack[-1] = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-2];
    v159 = stack[0];
    v159 = qcdr(v159);
    fn = elt(env, 1); /* bfminus */
    v159 = (*qfn1(fn))(qenv(fn), v159);
    nil = C_nil;
    if (exception_pending()) goto v110;
    {
        Lisp_Object v160 = stack[-1];
        popv(3);
        return cons(v160, v159);
    }
/* error exit handlers */
v110:
    popv(3);
    return nil;
}



/* Code for ofsf_smmkatl!-or */

static Lisp_Object MS_CDECL CC_ofsf_smmkatlKor(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v161,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v181, v182;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_smmkatl-or");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl-or");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v161,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v3;
    v180 = v161;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = v180;
    goto v183;

v183:
    v180 = stack[-5];
    if (v180 == nil) goto v110;
    v180 = stack[-5];
    v180 = qcar(v180);
    v181 = v180;
    v182 = qcar(v181);
    v181 = stack[-4];
    v181 = Latsoc(nil, v182, v181);
    v182 = v181;
    v181 = v182;
    if (v181 == nil) goto v184;
    v181 = v180;
    v180 = stack[-3];
    fn = elt(env, 3); /* ofsf_smmkatl!-or1 */
    v180 = (*qfnn(fn))(qenv(fn), 3, v182, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    goto v186;

v186:
    stack[-2] = v180;
    v180 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    stack[-1] = v180;
    v180 = stack[-5];
    v180 = qcdr(v180);
    stack[-5] = v180;
    v180 = stack[-1];
    if (!consp(v180)) goto v183;
    else goto v187;

v187:
    v180 = stack[-5];
    if (v180 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v180 = stack[-5];
    v180 = qcar(v180);
    v181 = v180;
    v182 = qcar(v181);
    v181 = stack[-4];
    v181 = Latsoc(nil, v182, v181);
    v182 = v181;
    v181 = v182;
    if (v181 == nil) goto v188;
    v181 = v180;
    v180 = stack[-3];
    fn = elt(env, 3); /* ofsf_smmkatl!-or1 */
    v180 = (*qfnn(fn))(qenv(fn), 3, v182, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    goto v121;

v121:
    v180 = Lrplacd(nil, stack[0], v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    v180 = stack[-1];
    fn = elt(env, 4); /* lastpair */
    v180 = (*qfn1(fn))(qenv(fn), v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    stack[-1] = v180;
    v180 = stack[-5];
    v180 = qcdr(v180);
    stack[-5] = v180;
    goto v187;

v188:
    v182 = elt(env, 2); /* or */
    v181 = v180;
    v180 = stack[-3];
    fn = elt(env, 5); /* ofsf_ir2atl */
    v180 = (*qfnn(fn))(qenv(fn), 3, v182, v181, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    goto v121;

v184:
    v181 = elt(env, 2); /* or */
    v182 = v180;
    v180 = stack[-3];
    fn = elt(env, 5); /* ofsf_ir2atl */
    v180 = (*qfnn(fn))(qenv(fn), 3, v181, v182, v180);
    nil = C_nil;
    if (exception_pending()) goto v185;
    env = stack[-6];
    goto v186;

v110:
    v180 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v180); }
/* error exit handlers */
v185:
    popv(7);
    return nil;
}



/* Code for deleteq */

static Lisp_Object CC_deleteq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v175, v176;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deleteq");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v161;
    stack[-1] = v0;
/* end of prologue */
    v176 = nil;
    goto v104;

v104:
    v177 = stack[-1];
    if (v177 == nil) goto v164;
    v177 = stack[-1];
    v175 = qcar(v177);
    v177 = stack[0];
    if (v175 == v177) goto v193;
    v177 = stack[-1];
    v177 = qcar(v177);
    v175 = v176;
    v177 = cons(v177, v175);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-2];
    v176 = v177;
    v177 = stack[-1];
    v177 = qcdr(v177);
    stack[-1] = v177;
    goto v104;

v193:
    v175 = v176;
    v177 = stack[-1];
    v177 = qcdr(v177);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v175, v177);
    }

v164:
    v177 = v176;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v177);
    }
/* error exit handlers */
v106:
    popv(3);
    return nil;
}



/* Code for find!-expts */

static Lisp_Object CC_findKexpts(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v205, v206, v207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find-expts");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v161;
    stack[-2] = v0;
/* end of prologue */
    v205 = stack[-2];
    if (!consp(v205)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v205 = stack[-2];
    v205 = qcar(v205);
    if (!consp(v205)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v205 = stack[-2];
    v205 = qcar(v205);
    stack[0] = qcdr(v205);
    v205 = stack[-2];
    v206 = qcdr(v205);
    v205 = stack[-1];
    v205 = CC_findKexpts(env, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v205 = CC_findKexpts(env, stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    stack[-1] = v205;
    v205 = stack[-2];
    v205 = qcar(v205);
    v205 = qcar(v205);
    v205 = qcar(v205);
    stack[-2] = v205;
    v206 = stack[-2];
    v205 = elt(env, 1); /* sqrt */
    if (!consp(v206)) goto v156;
    v206 = qcar(v206);
    if (!(v206 == v205)) goto v156;
    v207 = elt(env, 2); /* expt */
    v205 = stack[-2];
    v205 = qcdr(v205);
    v206 = qcar(v205);
    v205 = elt(env, 3); /* (quotient 1 2) */
    v205 = list3(v207, v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v156:
    v206 = stack[-2];
    v205 = elt(env, 2); /* expt */
    if (!consp(v206)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v206 = qcar(v206);
    if (!(v206 == v205)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v205 = stack[-2];
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v206 = qcar(v205);
    v205 = elt(env, 4); /* quotient */
    if (!consp(v206)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v206 = qcar(v206);
    if (!(v206 == v205)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v205 = stack[-2];
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcar(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcar(v205);
    if (!(is_number(v205))) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v205 = stack[-2];
    v205 = qcdr(v205);
    v206 = qcar(v205);
    v205 = stack[-1];
    v205 = Lassoc(nil, v206, v205);
    stack[-3] = v205;
    v205 = stack[-3];
    if (!(v205 == nil)) goto v208;
    v205 = stack[-2];
    v205 = qcdr(v205);
    stack[0] = qcar(v205);
    v205 = elt(env, 5); /* g */
    v206 = Lgensym1(nil, v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v205 = (Lisp_Object)17; /* 1 */
    v205 = list2star(stack[0], v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    stack[-3] = v205;
    v206 = stack[-3];
    v205 = stack[-1];
    v205 = cons(v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    stack[-1] = v205;
    goto v208;

v208:
    v205 = stack[-3];
    stack[0] = qcdr(v205);
    v205 = stack[-3];
    v205 = qcdr(v205);
    v206 = qcdr(v205);
    v205 = stack[-2];
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcar(v205);
    v205 = qcdr(v205);
    v205 = qcdr(v205);
    v205 = qcar(v205);
    fn = elt(env, 6); /* lcm */
    v205 = (*qfn2(fn))(qenv(fn), v206, v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[-4];
    v205 = Lrplacd(nil, stack[0], v205);
    nil = C_nil;
    if (exception_pending()) goto v86;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
/* error exit handlers */
v86:
    popv(5);
    return nil;
}



/* Code for dfrel2 */

static Lisp_Object MS_CDECL CC_dfrel2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v161,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dfrel2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dfrel2");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v161,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v161;
    stack[-3] = v0;
/* end of prologue */

v214:
    v212 = stack[-1];
    if (v212 == nil) goto v104;
    v212 = stack[-3];
    v213 = qcar(v212);
    v212 = stack[-1];
    v212 = qcar(v212);
    fn = elt(env, 3); /* dfdeg */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    stack[-4] = v212;
    v212 = stack[-2];
    v213 = qcar(v212);
    v212 = stack[-1];
    v212 = qcar(v212);
    fn = elt(env, 3); /* dfdeg */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v215;
    env = stack[-5];
    stack[0] = v212;
    v213 = stack[-4];
    v212 = stack[0];
    v212 = (Lisp_Object)lessp2(v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v215;
    v212 = v212 ? lisp_true : nil;
    env = stack[-5];
    if (v212 == nil) goto v107;
    v212 = qvalue(elt(env, 1)); /* t */
    { popv(6); return onevalue(v212); }

v107:
    v213 = stack[0];
    v212 = stack[-4];
    v212 = (Lisp_Object)lessp2(v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v215;
    v212 = v212 ? lisp_true : nil;
    env = stack[-5];
    if (v212 == nil) goto v216;
    v212 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v212); }

v216:
    v98 = stack[-3];
    v213 = stack[-2];
    v212 = stack[-1];
    v212 = qcdr(v212);
    stack[-3] = v98;
    stack[-2] = v213;
    stack[-1] = v212;
    goto v214;

v104:
    v212 = (Lisp_Object)1; /* 0 */
    { popv(6); return onevalue(v212); }
/* error exit handlers */
v215:
    popv(6);
    return nil;
}



/* Code for clogf */

static Lisp_Object CC_clogf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v212, v213, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clogf");
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
    stack[-1] = nil;
    v212 = stack[-2];
    fn = elt(env, 3); /* kernels */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    stack[-3] = v212;
    v212 = stack[-3];
    stack[0] = v212;
    goto v157;

v157:
    v212 = stack[0];
    if (v212 == nil) goto v221;
    v212 = stack[0];
    v212 = qcar(v212);
    v98 = v212;
    v213 = v98;
    v212 = elt(env, 2); /* log */
    if (!consp(v213)) goto v174;
    v213 = qcar(v213);
    if (!(v213 == v212)) goto v174;
    v213 = v98;
    v212 = stack[-1];
    v212 = cons(v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    stack[-1] = v212;
    goto v174;

v174:
    v212 = stack[0];
    v212 = qcdr(v212);
    stack[0] = v212;
    goto v157;

v221:
    v212 = stack[-1];
    if (v212 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v213 = stack[-3];
    v212 = stack[-1];
    fn = elt(env, 4); /* setdiff */
    v212 = (*qfn2(fn))(qenv(fn), v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    stack[-3] = v212;
    v213 = stack[-3];
    v212 = stack[-1];
    v212 = Lnconc(nil, v213, v212);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    fn = elt(env, 5); /* setkorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    stack[-3] = v212;
    v212 = stack[-2];
    fn = elt(env, 6); /* reorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    fn = elt(env, 7); /* clogf1 */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    stack[-2] = v212;
    v212 = stack[-3];
    fn = elt(env, 5); /* setkorder */
    v212 = (*qfn1(fn))(qenv(fn), v212);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[-4];
    v212 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* reorder */
        return (*qfn1(fn))(qenv(fn), v212);
    }
/* error exit handlers */
v121:
    popv(5);
    return nil;
}



/* Code for clear */

static Lisp_Object CC_clear(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clear");
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
    fn = elt(env, 6); /* rmsubs */
    v170 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    stack[-1] = elt(env, 1); /* clear1 */
    v170 = stack[0];
    v170 = Lmkquote(nil, v170);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    v186 = list2(stack[-1], v170);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    v170 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 7); /* errorset!* */
    v170 = (*qfn2(fn))(qenv(fn), v186, v170);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    stack[0] = v170;
    v170 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 4)) = v170; /* frasc!* */
    qvalue(elt(env, 5)) = v170; /* mcond!* */
    v170 = stack[0];
    fn = elt(env, 8); /* errorp */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-2];
    if (v170 == nil) goto v223;
    v170 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v116;
    v170 = nil;
    { popv(3); return onevalue(v170); }

v223:
    v170 = stack[0];
    v170 = qcar(v170);
    { popv(3); return onevalue(v170); }
/* error exit handlers */
v116:
    popv(3);
    return nil;
}



/* Code for zfactor */

static Lisp_Object CC_zfactor(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zfactor");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v221 = v0;
/* end of prologue */
    v157 = v221;
    v221 = qvalue(elt(env, 1)); /* t */
    {
        fn = elt(env, 2); /* zfactor1 */
        return (*qfn2(fn))(qenv(fn), v157, v221);
    }
}



/* Code for mk_relation_mat */

static Lisp_Object CC_mk_relation_mat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v224, v177;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_relation_mat");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v161;
    stack[0] = v0;
/* end of prologue */
    v224 = stack[-1];
    v224 = qcar(v224);
    v224 = qcdr(v224);
    v224 = qcar(v224);
    fn = elt(env, 2); /* get!+row!+nr */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-3];
    fn = elt(env, 3); /* mk!+unit!+mat */
    v224 = (*qfn1(fn))(qenv(fn), v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-3];
    v177 = v224;
    v224 = stack[0];
    stack[-2] = v224;
    goto v109;

v109:
    v224 = stack[-2];
    if (v224 == nil) { popv(4); return onevalue(v177); }
    v224 = stack[-2];
    v224 = qcar(v224);
    stack[0] = v177;
    v177 = v224;
    v224 = stack[-1];
    fn = elt(env, 4); /* get_mat */
    v224 = (*qfn2(fn))(qenv(fn), v177, v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-3];
    fn = elt(env, 5); /* mk!+mat!+mult!+mat */
    v224 = (*qfn2(fn))(qenv(fn), stack[0], v224);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-3];
    v177 = v224;
    v224 = stack[-2];
    v224 = qcdr(v224);
    stack[-2] = v224;
    goto v109;
/* error exit handlers */
v225:
    popv(4);
    return nil;
}



/* Code for aex_fromrp */

static Lisp_Object CC_aex_fromrp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_fromrp");
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
    v174 = v0;
/* end of prologue */
    stack[-2] = elt(env, 1); /* aex */
    stack[-1] = v174;
    fn = elt(env, 3); /* ctx_new */
    stack[0] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v227;
    env = stack[-3];
    v204 = qvalue(elt(env, 2)); /* t */
    v174 = qvalue(elt(env, 2)); /* t */
    v174 = list2(v204, v174);
    nil = C_nil;
    if (exception_pending()) goto v227;
    {
        Lisp_Object v223 = stack[-2];
        Lisp_Object v178 = stack[-1];
        Lisp_Object v179 = stack[0];
        popv(4);
        return list3star(v223, v178, v179, v174);
    }
/* error exit handlers */
v227:
    popv(4);
    return nil;
}



/* Code for ofsf_multsurep */

static Lisp_Object CC_ofsf_multsurep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v186, v105, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_multsurep");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v105 = v161;
    v117 = v0;
/* end of prologue */
    v170 = v117;
    v186 = qcar(v170);
    v170 = elt(env, 1); /* equal */
    if (v186 == v170) goto v109;
    v170 = v117;
    v186 = v105;
    {
        fn = elt(env, 2); /* ofsf_multsurep!-neq */
        return (*qfn2(fn))(qenv(fn), v170, v186);
    }

v109:
    v170 = v117;
    v186 = v105;
    {
        fn = elt(env, 3); /* ofsf_multsurep!-equal */
        return (*qfn2(fn))(qenv(fn), v170, v186);
    }
}



/* Code for exptchk0 */

static Lisp_Object MS_CDECL CC_exptchk0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v161,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v236, v237, v238;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "exptchk0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptchk0");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v161,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v161;
    stack[-2] = v0;
/* end of prologue */
    v236 = stack[-2];
    if (v236 == nil) goto v221;
    v236 = stack[-2];
    if (!consp(v236)) goto v193;
    v236 = stack[-2];
    v236 = qcar(v236);
    if (!consp(v236)) goto v193;
    v236 = stack[-2];
    v236 = qcar(v236);
    v236 = qcar(v236);
    v237 = qcar(v236);
    v236 = stack[0];
    fn = elt(env, 2); /* expttermp */
    v236 = (*qfn2(fn))(qenv(fn), v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    if (v236 == nil) goto v240;
    v236 = stack[-2];
    v236 = qcar(v236);
    stack[-3] = qcdr(v236);
    v236 = stack[-2];
    v236 = qcar(v236);
    v237 = qcar(v236);
    v236 = stack[-1];
    v237 = cons(v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v236 = stack[0];
    stack[-3] = CC_exptchk0(env, 3, stack[-3], v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v236 = stack[-2];
    v238 = qcdr(v236);
    v237 = stack[-1];
    v236 = stack[0];
    v236 = CC_exptchk0(env, 3, v238, v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    {
        Lisp_Object v241 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* addsq */
        return (*qfn2(fn))(qenv(fn), v241, v236);
    }

v240:
    v236 = stack[-2];
    v236 = qcar(v236);
    v237 = qcar(v236);
    v236 = (Lisp_Object)17; /* 1 */
    v236 = cons(v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v237 = ncons(v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v236 = (Lisp_Object)17; /* 1 */
    stack[-3] = cons(v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v236 = stack[-2];
    v236 = qcar(v236);
    v238 = qcdr(v236);
    v237 = stack[-1];
    v236 = stack[0];
    v236 = CC_exptchk0(env, 3, v238, v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    fn = elt(env, 4); /* multsq */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[-3], v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v236 = stack[-2];
    v238 = qcdr(v236);
    v237 = stack[-1];
    v236 = stack[0];
    v236 = CC_exptchk0(env, 3, v238, v237, v236);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    {
        Lisp_Object v90 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* addsq */
        return (*qfn2(fn))(qenv(fn), v90, v236);
    }

v193:
    v237 = stack[-2];
    v236 = stack[-1];
    {
        popv(5);
        fn = elt(env, 5); /* exptunwind */
        return (*qfn2(fn))(qenv(fn), v237, v236);
    }

v221:
    v237 = qvalue(elt(env, 1)); /* nil */
    v236 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v237, v236);
/* error exit handlers */
v239:
    popv(5);
    return nil;
}



/* Code for texaeval */

static Lisp_Object CC_texaeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v242;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for texaeval");
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
    v108 = qvalue(elt(env, 1)); /* !*lasimp */
    if (v108 == nil) goto v115;
    stack[0] = elt(env, 2); /* tex */
    v108 = v242;
    fn = elt(env, 3); /* aeval */
    v108 = (*qfn1(fn))(qenv(fn), v108);
    nil = C_nil;
    if (exception_pending()) goto v223;
    {
        Lisp_Object v178 = stack[0];
        popv(1);
        return list2(v178, v108);
    }

v115:
    v108 = elt(env, 2); /* tex */
    popv(1);
    return list2(v108, v242);
/* error exit handlers */
v223:
    popv(1);
    return nil;
}



/* Code for lispstmtp */

static Lisp_Object CC_lispstmtp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v245, v211;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispstmtp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v211 = v0;
/* end of prologue */
    v244 = v211;
    v244 = (consp(v244) ? nil : lisp_true);
    if (!(v244 == nil)) return onevalue(v244);
    v244 = v211;
    v245 = qcar(v244);
    v244 = qvalue(elt(env, 1)); /* !*lispstmtops!* */
    v244 = Lmemq(nil, v245, v244);
    if (!(v244 == nil)) return onevalue(v244);
    v244 = v211;
    v244 = qcar(v244);
    if (!consp(v244)) goto v223;
    v244 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v244);

v223:
    v244 = v211;
    v245 = qcar(v244);
    v244 = qvalue(elt(env, 3)); /* !*lisparithexpops!* */
    v244 = Lmemq(nil, v245, v244);
    if (!(v244 == nil)) goto v242;
    v244 = v211;
    v245 = qcar(v244);
    v244 = qvalue(elt(env, 4)); /* !*lisplogexpops!* */
    v244 = Lmemq(nil, v245, v244);
    if (!(v244 == nil)) goto v242;
    v244 = v211;
    v245 = qcar(v244);
    v244 = qvalue(elt(env, 5)); /* !*lispstmtgpops!* */
    v244 = Lmemq(nil, v245, v244);
    if (!(v244 == nil)) goto v242;
    v244 = v211;
    v244 = qcar(v244);
    v245 = qvalue(elt(env, 6)); /* !*lispdefops!* */
    v244 = Lmemq(nil, v244, v245);
    goto v242;

v242:
    v244 = (v244 == nil ? lisp_true : nil);
    return onevalue(v244);
}



/* Code for list_of_parents */

static Lisp_Object CC_list_of_parents(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list_of_parents");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v161;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v17;

v17:
    v106 = stack[-1];
    if (v106 == nil) goto v158;
    v106 = stack[-1];
    v107 = qcar(v106);
    v106 = stack[0];
    fn = elt(env, 2); /* list_of_parent */
    v107 = (*qfn2(fn))(qenv(fn), v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    v106 = stack[-2];
    v106 = cons(v107, v106);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    stack[-2] = v106;
    v106 = stack[-1];
    v106 = qcdr(v106);
    stack[-1] = v106;
    goto v17;

v158:
    v106 = qvalue(elt(env, 1)); /* nil */
    v107 = v106;
    goto v164;

v164:
    v106 = stack[-2];
    if (v106 == nil) { popv(4); return onevalue(v107); }
    v106 = stack[-2];
    v106 = qcar(v106);
    v106 = Lappend(nil, v106, v107);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-3];
    v107 = v106;
    v106 = stack[-2];
    v106 = qcdr(v106);
    stack[-2] = v106;
    goto v164;
/* error exit handlers */
v118:
    popv(4);
    return nil;
}



/* Code for getsetvarlis */

static Lisp_Object CC_getsetvarlis(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getsetvarlis");
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
    goto v7;

v7:
    v167 = stack[0];
    if (v167 == nil) goto v158;
    v167 = stack[0];
    if (!consp(v167)) goto v193;
    v167 = stack[0];
    v167 = qcar(v167);
    if (!consp(v167)) goto v116;
    v167 = stack[0];
    v167 = qcar(v167);
    v249 = qcar(v167);
    v167 = elt(env, 2); /* (setel setk) */
    v167 = Lmemq(nil, v249, v167);
    if (v167 == nil) goto v213;
    v167 = stack[0];
    v167 = qcar(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v249 = CC_getsetvarlis(env, v167);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    v167 = stack[-1];
    v167 = cons(v249, v167);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    stack[-1] = v167;
    v167 = stack[0];
    v167 = qcdr(v167);
    stack[0] = v167;
    goto v7;

v213:
    v167 = stack[0];
    v167 = qcar(v167);
    v249 = qcar(v167);
    v167 = elt(env, 3); /* setq */
    if (v249 == v167) goto v120;
    v167 = stack[0];
    v249 = qcar(v167);
    v167 = stack[-1];
    v167 = cons(v249, v167);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    stack[-1] = v167;
    v167 = stack[0];
    v167 = qcdr(v167);
    stack[0] = v167;
    goto v7;

v120:
    v167 = stack[0];
    v167 = qcar(v167);
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v249 = Lmkquote(nil, v167);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    v167 = stack[-1];
    v167 = cons(v249, v167);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    stack[-1] = v167;
    v167 = stack[0];
    v167 = qcdr(v167);
    stack[0] = v167;
    goto v7;

v116:
    v167 = stack[0];
    v249 = qcar(v167);
    v167 = stack[-1];
    v167 = cons(v249, v167);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    stack[-1] = v167;
    v167 = stack[0];
    v167 = qcdr(v167);
    stack[0] = v167;
    goto v7;

v193:
    v249 = elt(env, 1); /* "getsetvarlis" */
    v167 = stack[0];
    v167 = list2(v249, v167);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    fn = elt(env, 4); /* errach */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-2];
    {
        Lisp_Object v232 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v232, v167);
    }

v158:
    v167 = stack[-1];
    {
        popv(3);
        fn = elt(env, 5); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v167);
    }
/* error exit handlers */
v234:
    popv(3);
    return nil;
}



/* Code for constant_exprp */

static Lisp_Object CC_constant_exprp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v253, v233, v234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for constant_exprp");
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
    v233 = v0;
/* end of prologue */
    v253 = v233;
    if (!consp(v253)) goto v55;
    v253 = v233;
    v234 = qcar(v253);
    v253 = elt(env, 5); /* realvalued */
    v253 = Lflagp(nil, v234, v253);
    env = stack[0];
    if (!(v253 == nil)) goto v176;
    v253 = v233;
    v234 = qcar(v253);
    v253 = elt(env, 6); /* alwaysrealvalued */
    v253 = Lflagp(nil, v234, v253);
    env = stack[0];
    if (!(v253 == nil)) goto v176;
    v253 = v233;
    v234 = qcar(v253);
    v253 = elt(env, 7); /* (plus minus difference times quotient) */
    v253 = Lmemq(nil, v234, v253);
    if (!(v253 == nil)) goto v176;
    v253 = v233;
    v234 = qcar(v253);
    v253 = elt(env, 8); /* !:rd!: */
    v253 = get(v234, v253);
    env = stack[0];
    if (!(v253 == nil)) goto v176;
    v253 = qvalue(elt(env, 9)); /* !*complex */
    if (v253 == nil) goto v175;
    v253 = v233;
    v234 = qcar(v253);
    v253 = elt(env, 10); /* !:cr!: */
    v253 = get(v234, v253);
    env = stack[0];
    if (!(v253 == nil)) goto v176;

v175:
    v253 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v253); }

v176:
    v253 = v233;
    v253 = qcdr(v253);
    if (!consp(v253)) goto v254;
    v253 = v233;
    v253 = qcdr(v253);
    {
        popv(1);
        fn = elt(env, 11); /* constant_expr_listp */
        return (*qfn1(fn))(qenv(fn), v253);
    }

v254:
    v253 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v253); }

v55:
    v253 = v233;
    v253 = (is_number(v253) ? lisp_true : nil);
    if (!(v253 == nil)) { popv(1); return onevalue(v253); }
    v234 = v233;
    v253 = elt(env, 1); /* constant */
    v253 = Lflagp(nil, v234, v253);
    env = stack[0];
    if (!(v253 == nil)) { popv(1); return onevalue(v253); }
    v253 = elt(env, 2); /* i */
    if (v233 == v253) goto v117;
    v253 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v253); }

v117:
    v253 = elt(env, 2); /* i */
    v233 = elt(env, 4); /* idvalfn */
    popv(1);
    return get(v253, v233);
}



/* Code for get!*nr!*real!*irred!*reps */

static Lisp_Object CC_getHnrHrealHirredHreps(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v187;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*nr*real*irred*reps");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v183 = v0;
/* end of prologue */
    v187 = elt(env, 1); /* realrepnumber */
    return get(v183, v187);
}



/* Code for cl_subandcut */

static Lisp_Object MS_CDECL CC_cl_subandcut(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v161,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v264, v265, v266, v267, v268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_subandcut");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_subandcut");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v161,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v3;
    stack[-4] = v161;
    stack[-5] = v0;
/* end of prologue */
    v264 = (Lisp_Object)1; /* 0 */
    stack[0] = v264;
    v264 = stack[-5];
    stack[-1] = v264;
    goto v159;

v159:
    v264 = stack[-5];
    if (v264 == nil) goto v187;
    v264 = stack[-4];
    if (v264 == nil) goto v187;
    v264 = stack[-5];
    v265 = qcar(v264);
    v264 = stack[-4];
    v264 = qcar(v264);
    if (!(equal(v265, v264))) goto v187;
    v264 = stack[0];
    v264 = add1(v264);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    stack[0] = v264;
    v264 = stack[-5];
    v264 = qcdr(v264);
    stack[-5] = v264;
    v264 = stack[-4];
    v264 = qcdr(v264);
    stack[-4] = v264;
    goto v159;

v187:
    v264 = stack[-5];
    if (v264 == nil) goto v189;
    v264 = stack[-4];
    if (v264 == nil) goto v189;
    v264 = elt(env, 2); /* keep1 */
    stack[-6] = v264;
    v264 = stack[-5];
    v266 = qcar(v264);
    v264 = stack[-4];
    v265 = qcar(v264);
    v264 = stack[-3];
    fn = elt(env, 5); /* rl_sacat */
    v264 = (*qfnn(fn))(qenv(fn), 3, v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    stack[-2] = v264;
    v265 = stack[-2];
    v264 = elt(env, 3); /* keep2 */
    if (v265 == v264) goto v166;
    v265 = stack[-2];
    v264 = elt(env, 2); /* keep1 */
    if (v265 == v264) goto v197;
    v264 = stack[-2];
    if (v264 == nil) goto v194;
    v268 = stack[-1];
    v267 = stack[0];
    v266 = stack[-2];
    v264 = stack[-5];
    v265 = qcdr(v264);
    v264 = stack[-4];
    v264 = qcdr(v264);
    {
        popv(8);
        fn = elt(env, 6); /* cl_trycut */
        return (*qfnn(fn))(qenv(fn), 5, v268, v267, v266, v265, v264);
    }

v194:
    v264 = stack[-5];
    v265 = qcar(v264);
    v264 = stack[-4];
    v264 = qcar(v264);
    fn = elt(env, 7); /* rl_ordatp */
    v264 = (*qfn2(fn))(qenv(fn), v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    if (v264 == nil) goto v196;
    v264 = elt(env, 3); /* keep2 */
    stack[-6] = v264;
    v264 = stack[-5];
    stack[-2] = v264;
    v264 = stack[-4];
    stack[-5] = v264;
    v264 = stack[-2];
    stack[-4] = v264;
    goto v196;

v196:
    v264 = stack[-5];
    if (v264 == nil) goto v270;
    v264 = stack[-5];
    v266 = qcar(v264);
    v265 = stack[-4];
    v264 = stack[-3];
    fn = elt(env, 8); /* cl_sacatl */
    v264 = (*qfnn(fn))(qenv(fn), 3, v266, v265, v264);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-7];
    stack[-2] = v264;
    v264 = stack[-2];
    v264 = qcdr(v264);
    stack[-4] = v264;
    v264 = stack[-2];
    v264 = qcar(v264);
    stack[-2] = v264;
    v264 = stack[-5];
    v264 = qcdr(v264);
    stack[-5] = v264;
    v265 = stack[-2];
    v264 = elt(env, 2); /* keep1 */
    if (v265 == v264) goto v196;
    v264 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v264;
    goto v196;

v270:
    v265 = stack[-2];
    v264 = elt(env, 2); /* keep1 */
    if (v265 == v264) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    v264 = elt(env, 4); /* failed */
    { popv(8); return onevalue(v264); }

v197:
    v264 = stack[-5];
    v264 = qcdr(v264);
    stack[-5] = v264;
    v264 = stack[-4];
    v264 = qcdr(v264);
    stack[-4] = v264;
    goto v196;

v166:
    v264 = elt(env, 3); /* keep2 */
    stack[-6] = v264;
    v264 = stack[-5];
    v264 = qcdr(v264);
    stack[-2] = v264;
    v264 = stack[-4];
    v264 = qcdr(v264);
    stack[-5] = v264;
    v264 = stack[-2];
    stack[-4] = v264;
    goto v196;

v189:
    v264 = stack[-5];
    if (!(v264 == nil)) goto v203;
    v264 = stack[-4];
    if (!(v264 == nil)) goto v203;
    v264 = elt(env, 2); /* keep1 */
    { popv(8); return onevalue(v264); }

v203:
    v264 = stack[-4];
    if (v264 == nil) goto v201;
    v264 = elt(env, 2); /* keep1 */
    goto v172;

v172:
    if (!(v264 == nil)) { popv(8); return onevalue(v264); }
    v264 = elt(env, 3); /* keep2 */
    { popv(8); return onevalue(v264); }

v201:
    v264 = qvalue(elt(env, 1)); /* nil */
    goto v172;
/* error exit handlers */
v269:
    popv(8);
    return nil;
}



/* Code for comm1 */

static Lisp_Object CC_comm1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v217, v156;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comm1");
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
    v156 = stack[0];
    v217 = elt(env, 1); /* end */
    if (!(v156 == v217)) goto v174;

v104:
    fn = elt(env, 8); /* scan */
    v217 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    goto v174;

v174:
    v156 = qvalue(elt(env, 2)); /* cursym!* */
    v217 = elt(env, 3); /* !*semicol!* */
    if (v156 == v217) goto v222;
    v156 = stack[0];
    v217 = elt(env, 1); /* end */
    if (!(v156 == v217)) goto v107;
    v156 = qvalue(elt(env, 2)); /* cursym!* */
    v217 = elt(env, 4); /* (end else then until !*rpar!* !*rsqbkt!*) */
    v217 = Lmemq(nil, v156, v217);
    if (!(v217 == nil)) goto v222;

v107:
    v156 = stack[0];
    v217 = elt(env, 1); /* end */
    if (!(v156 == v217)) goto v104;
    v217 = stack[-1];
    if (!(v217 == nil)) goto v104;
    v217 = elt(env, 6); /* "END-COMMENT NO LONGER SUPPORTED" */
    v217 = ncons(v217);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    fn = elt(env, 9); /* lprim */
    v217 = (*qfn1(fn))(qenv(fn), v217);
    nil = C_nil;
    if (exception_pending()) goto v211;
    env = stack[-2];
    v217 = qvalue(elt(env, 7)); /* t */
    stack[-1] = v217;
    goto v104;

v222:
    v217 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v217); }
/* error exit handlers */
v211:
    popv(3);
    return nil;
}



/* Code for radf1 */

static Lisp_Object CC_radf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v275, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for radf1");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v161;
    v124 = v0;
/* end of prologue */
    stack[-4] = nil;
    v275 = (Lisp_Object)17; /* 1 */
    stack[-6] = v275;
    v275 = v124;
    stack[-2] = v275;
    goto v183;

v183:
    v275 = stack[-2];
    if (v275 == nil) goto v94;
    v275 = stack[-2];
    v275 = qcar(v275);
    stack[-1] = v275;
    v275 = stack[-1];
    v124 = qcdr(v275);
    v275 = stack[-5];
    v275 = Ldivide(nil, v124, v275);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-7];
    stack[-3] = v275;
    v275 = stack[-3];
    v124 = qcar(v275);
    v275 = (Lisp_Object)1; /* 0 */
    if (v124 == v275) goto v162;
    v124 = stack[-1];
    v275 = (Lisp_Object)17; /* 1 */
    v275 = cons(v124, v275);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-7];
    stack[0] = ncons(v275);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-7];
    v275 = stack[-1];
    v124 = qcar(v275);
    v275 = stack[-3];
    v275 = qcar(v275);
    fn = elt(env, 2); /* exptf */
    v124 = (*qfn2(fn))(qenv(fn), v124, v275);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-7];
    v275 = stack[-5];
    fn = elt(env, 3); /* check!-radf!-sign */
    v124 = (*qfnn(fn))(qenv(fn), 3, stack[0], v124, v275);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-7];
    v275 = stack[-6];
    fn = elt(env, 4); /* multf */
    v275 = (*qfn2(fn))(qenv(fn), v124, v275);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-7];
    stack[-6] = v275;
    goto v162;

v162:
    v275 = stack[-3];
    v124 = qcdr(v275);
    v275 = (Lisp_Object)1; /* 0 */
    if (v124 == v275) goto v123;
    v275 = stack[-1];
    v124 = qcar(v275);
    v275 = (Lisp_Object)17; /* 1 */
    v275 = cons(v124, v275);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-7];
    fn = elt(env, 5); /* prepsq!* */
    v124 = (*qfn1(fn))(qenv(fn), v275);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-7];
    v275 = stack[-3];
    v275 = qcdr(v275);
    fn = elt(env, 6); /* mkexpt */
    v124 = (*qfn2(fn))(qenv(fn), v124, v275);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-7];
    v275 = stack[-4];
    v275 = cons(v124, v275);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-7];
    stack[-4] = v275;
    goto v123;

v123:
    v275 = stack[-2];
    v275 = qcdr(v275);
    stack[-2] = v275;
    goto v183;

v94:
    v124 = stack[-6];
    v275 = stack[-4];
    popv(8);
    return cons(v124, v275);
/* error exit handlers */
v263:
    popv(8);
    return nil;
}



/* Code for partitop */

static Lisp_Object CC_partitop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v302, v303;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partitop");
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
    stack[-2] = qvalue(elt(env, 1)); /* alglist!* */
    qvalue(elt(env, 1)) = nil; /* alglist!* */
    v302 = qvalue(elt(env, 2)); /* nil */
    v302 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    qvalue(elt(env, 1)) = v302; /* alglist!* */
    v302 = stack[-1];
    if (!consp(v302)) goto v160;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 5); /* partitfn */
    v302 = get(v303, v302);
    env = stack[-3];
    stack[0] = v302;
    if (v302 == nil) goto v234;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 6); /* full */
    v302 = Lflagp(nil, v303, v302);
    env = stack[-3];
    if (v302 == nil) goto v231;
    v303 = stack[0];
    v302 = stack[-1];
    v302 = Lapply1(nil, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v7:
    qvalue(elt(env, 1)) = stack[-2]; /* alglist!* */
    { popv(4); return onevalue(v302); }

v231:
    v303 = stack[0];
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = Lapply1(nil, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v234:
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 7); /* !*sq */
    if (v303 == v302) goto v253;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 8); /* plus */
    if (v303 == v302) goto v275;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 9); /* minus */
    if (v303 == v302) goto v305;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 10); /* difference */
    if (v303 == v302) goto v306;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 11); /* times */
    if (v303 == v302) goto v307;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 12); /* quotient */
    if (v303 == v302) goto v308;
    v302 = stack[-1];
    v303 = qcar(v302);
    v302 = elt(env, 13); /* recip */
    if (v303 == v302) goto v309;
    v302 = stack[-1];
    fn = elt(env, 14); /* simp!* */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    stack[0] = v302;
    v302 = qcar(v302);
    if (v302 == nil) goto v59;
    v303 = (Lisp_Object)17; /* 1 */
    v302 = stack[0];
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    v302 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v59:
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v7;

v309:
    stack[0] = (Lisp_Object)17; /* 1 */
    v302 = stack[-1];
    v302 = qcdr(v302);
    fn = elt(env, 15); /* simprecip */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    v302 = cons(stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    v302 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v308:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    stack[0] = CC_partitop(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    fn = elt(env, 15); /* simprecip */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    fn = elt(env, 16); /* multpfsq */
    v302 = (*qfn2(fn))(qenv(fn), stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v307:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v302 = CC_partitop(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    stack[0] = v302;
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    stack[-1] = v302;
    goto v132;

v132:
    v302 = stack[-1];
    if (v302 == nil) goto v310;
    v302 = stack[-1];
    v302 = qcar(v302);
    v302 = CC_partitop(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    fn = elt(env, 17); /* multpfs */
    v302 = (*qfn2(fn))(qenv(fn), stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    stack[0] = v302;
    v302 = stack[-1];
    v302 = qcdr(v302);
    stack[-1] = v302;
    goto v132;

v310:
    v302 = stack[0];
    goto v7;

v306:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    stack[0] = CC_partitop(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    stack[-1] = CC_partitop(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    v303 = (Lisp_Object)-15; /* -1 */
    v302 = (Lisp_Object)17; /* 1 */
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    fn = elt(env, 16); /* multpfsq */
    v302 = (*qfn2(fn))(qenv(fn), stack[-1], v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    fn = elt(env, 18); /* addpf */
    v302 = (*qfn2(fn))(qenv(fn), stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v305:
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    stack[0] = CC_partitop(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    v303 = (Lisp_Object)-15; /* -1 */
    v302 = (Lisp_Object)17; /* 1 */
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    fn = elt(env, 16); /* multpfsq */
    v302 = (*qfn2(fn))(qenv(fn), stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v275:
    v302 = stack[-1];
    v302 = qcdr(v302);
    stack[-1] = v302;
    goto v194;

v194:
    v302 = stack[-1];
    if (v302 == nil) goto v185;
    v302 = stack[-1];
    v302 = qcar(v302);
    v303 = CC_partitop(env, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    v302 = stack[0];
    fn = elt(env, 18); /* addpf */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    stack[0] = v302;
    v302 = stack[-1];
    v302 = qcdr(v302);
    stack[-1] = v302;
    goto v194;

v185:
    v302 = stack[0];
    goto v7;

v253:
    v302 = stack[-1];
    fn = elt(env, 14); /* simp!* */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    fn = elt(env, 19); /* partitsq!* */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v160:
    v303 = stack[-1];
    v302 = elt(env, 3); /* avalue */
    v302 = get(v303, v302);
    env = stack[-3];
    stack[0] = v302;
    if (v302 == nil) goto v170;
    v302 = stack[0];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    fn = elt(env, 14); /* simp!* */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    fn = elt(env, 19); /* partitsq!* */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v170:
    v303 = stack[-1];
    v302 = elt(env, 4); /* fdegree */
    v302 = get(v303, v302);
    env = stack[-3];
    v303 = v302;
    v302 = v303;
    if (v302 == nil) goto v176;
    v302 = v303;
    v302 = qcar(v302);
    goto v189;

v189:
    if (v302 == nil) goto v179;
    v302 = stack[-1];
    fn = elt(env, 20); /* mkupf */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v179:
    v302 = stack[-1];
    fn = elt(env, 14); /* simp!* */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    stack[0] = v302;
    v302 = qcar(v302);
    if (v302 == nil) goto v156;
    v303 = (Lisp_Object)17; /* 1 */
    v302 = stack[0];
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    v302 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v304;
    env = stack[-3];
    goto v7;

v156:
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v7;

v176:
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v189;
/* error exit handlers */
v304:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* alglist!* */
    popv(4);
    return nil;
}



/* Code for formcond */

static Lisp_Object MS_CDECL CC_formcond(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v161,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v204, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formcond");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formcond");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v161,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v174 = v3;
    v204 = v161;
    v193 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* cond */
    v193 = qcdr(v193);
    fn = elt(env, 2); /* formcond1 */
    v174 = (*qfnn(fn))(qenv(fn), 3, v193, v204, v174);
    nil = C_nil;
    if (exception_pending()) goto v242;
    {
        Lisp_Object v227 = stack[0];
        popv(1);
        return cons(v227, v174);
    }
/* error exit handlers */
v242:
    popv(1);
    return nil;
}



/* Code for latexprin */

static Lisp_Object CC_latexprin(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v105, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for latexprin");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v117 = v0;
/* end of prologue */
    v105 = v117;
    v186 = elt(env, 1); /* tex */
    if (!consp(v105)) goto v242;
    v105 = qcar(v105);
    if (!(v105 == v186)) goto v242;
    v186 = v117;
    v186 = qcdr(v186);
    v105 = qcar(v186);
    v186 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 2); /* maprintla */
        return (*qfn2(fn))(qenv(fn), v105, v186);
    }

v242:
    v105 = v117;
    v186 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 2); /* maprintla */
        return (*qfn2(fn))(qenv(fn), v105, v186);
    }
}



/* Code for defined_append */

static Lisp_Object CC_defined_append(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v177, v175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for defined_append");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v161;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v104;

v104:
    v177 = stack[-1];
    if (v177 == nil) goto v187;
    v177 = stack[-1];
    v175 = qcar(v177);
    v177 = stack[0];
    fn = elt(env, 1); /* defined_edge */
    v177 = (*qfn2(fn))(qenv(fn), v175, v177);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    if (v177 == nil) goto v189;
    v177 = stack[-1];
    v175 = qcar(v177);
    v177 = stack[-2];
    v177 = cons(v175, v177);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    stack[-2] = v177;
    v177 = stack[-1];
    v177 = qcdr(v177);
    stack[-1] = v177;
    goto v104;

v189:
    v177 = stack[-1];
    v177 = qcdr(v177);
    stack[-1] = v177;
    goto v104;

v187:
    v175 = stack[-2];
    v177 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v175, v177);
    }
/* error exit handlers */
v106:
    popv(4);
    return nil;
}



/* Code for compactf0 */

static Lisp_Object MS_CDECL CC_compactf0(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v161,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v89, v127, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "compactf0");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for compactf0");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v161,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v3;
    stack[-6] = v161;
    stack[-1] = v0;
/* end of prologue */
    v93 = stack[-1];
    fn = elt(env, 3); /* kernels */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    stack[-7] = v93;
    v93 = stack[-6];
    fn = elt(env, 3); /* kernels */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    stack[0] = v93;
    v89 = elt(env, 1); /* !~ */
    v93 = stack[-6];
    v93 = Lsmemq(nil, v89, v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    if (v93 == nil) goto v108;
    v89 = stack[-7];
    v93 = stack[0];
    fn = elt(env, 4); /* compactfmatch */
    v93 = (*qfn2(fn))(qenv(fn), v89, v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    stack[-3] = v93;
    goto v189;

v189:
    v93 = stack[-3];
    if (v93 == nil) { Lisp_Object res = stack[-1]; popv(9); return onevalue(res); }
    v93 = stack[-3];
    v93 = qcar(v93);
    stack[-2] = v93;
    v93 = stack[-2];
    if (v93 == nil) goto v172;
    stack[0] = elt(env, 1); /* !~ */
    v89 = stack[-2];
    v93 = stack[-5];
    v93 = Lsublis(nil, v89, v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    stack[-4] = v93;
    v93 = Lsmemq(nil, stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    if (!(v93 == nil)) goto v172;
    v93 = stack[-4];
    fn = elt(env, 5); /* eval */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    if (v93 == nil) goto v172;
    stack[0] = elt(env, 1); /* !~ */
    v89 = stack[-6];
    v93 = stack[-2];
    fn = elt(env, 6); /* subf */
    v93 = (*qfn2(fn))(qenv(fn), v89, v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    v93 = qcar(v93);
    stack[-4] = v93;
    v93 = Lsmemq(nil, stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    if (!(v93 == nil)) goto v172;
    stack[-2] = stack[-1];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v93 = stack[-4];
    fn = elt(env, 3); /* kernels */
    v93 = (*qfn1(fn))(qenv(fn), v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    fn = elt(env, 7); /* compactf1 */
    v93 = (*qfnn(fn))(qenv(fn), 4, stack[-2], stack[-1], stack[0], v93);
    nil = C_nil;
    if (exception_pending()) goto v208;
    env = stack[-8];
    stack[-1] = v93;
    goto v172;

v172:
    v93 = stack[-3];
    v93 = qcdr(v93);
    stack[-3] = v93;
    goto v189;

v108:
    v125 = stack[-1];
    v127 = stack[-6];
    v89 = stack[-7];
    v93 = stack[0];
    {
        popv(9);
        fn = elt(env, 7); /* compactf1 */
        return (*qfnn(fn))(qenv(fn), 4, v125, v127, v89, v93);
    }
/* error exit handlers */
v208:
    popv(9);
    return nil;
}



/* Code for ar!-augment */

static Lisp_Object CC_arKaugment(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v271;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ar-augment");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v161;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v104;

v104:
    v116 = stack[-1];
    if (v116 == nil) goto v164;
    v116 = stack[-1];
    v271 = qcar(v116);
    v116 = stack[0];
    v116 = qcar(v116);
    v271 = Lappend(nil, v271, v116);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    v116 = stack[-2];
    v116 = cons(v271, v116);
    nil = C_nil;
    if (exception_pending()) goto v189;
    env = stack[-3];
    stack[-2] = v116;
    v116 = stack[-1];
    v116 = qcdr(v116);
    stack[-1] = v116;
    v116 = stack[0];
    v116 = qcdr(v116);
    stack[0] = v116;
    goto v104;

v164:
    v116 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v116);
    }
/* error exit handlers */
v189:
    popv(4);
    return nil;
}



/* Code for basic!-kern1 */

static Lisp_Object CC_basicKkern1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v245;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basic-kern1");
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
    v244 = stack[-3];
    if (!consp(v244)) goto v17;
    v244 = stack[-3];
    v244 = qcar(v244);
    fn = elt(env, 2); /* algebraic!-function */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    if (v244 == nil) goto v102;
    v244 = stack[-3];
    v244 = qcdr(v244);
    stack[-4] = v244;
    v244 = stack[-4];
    if (v244 == nil) goto v178;
    v244 = stack[-4];
    v244 = qcar(v244);
    fn = elt(env, 3); /* simp */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    stack[-1] = v244;
    stack[-2] = v244;
    goto v193;

v193:
    v244 = stack[-4];
    v244 = qcdr(v244);
    stack[-4] = v244;
    v244 = stack[-4];
    if (v244 == nil) goto v235;
    stack[0] = stack[-1];
    v244 = stack[-4];
    v244 = qcar(v244);
    fn = elt(env, 3); /* simp */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    v244 = ncons(v244);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    v244 = Lrplacd(nil, stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v213;
    env = stack[-5];
    v244 = stack[-1];
    v244 = qcdr(v244);
    stack[-1] = v244;
    goto v193;

v235:
    v244 = stack[-2];
    goto v204;

v204:
    fn = elt(env, 4); /* allbkern */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v213;
    v245 = v244;
    if (!(v244 == nil)) { popv(6); return onevalue(v245); }

v102:
    v244 = stack[-3];
    popv(6);
    return ncons(v244);

v178:
    v244 = qvalue(elt(env, 1)); /* nil */
    goto v204;

v17:
    v244 = stack[-3];
    popv(6);
    return ncons(v244);
/* error exit handlers */
v213:
    popv(6);
    return nil;
}



/* Code for bdstest */

static Lisp_Object CC_bdstest(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bdstest");
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
    v204 = stack[0];
    v204 = qcar(v204);
    fn = elt(env, 1); /* r2bf */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-2];
    fn = elt(env, 2); /* rootrnd */
    stack[-1] = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-2];
    v204 = stack[0];
    v204 = qcdr(v204);
    fn = elt(env, 1); /* r2bf */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-2];
    fn = elt(env, 2); /* rootrnd */
    v204 = (*qfn1(fn))(qenv(fn), v204);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-2];
    stack[0] = v204;
    fn = elt(env, 3); /* equal!: */
    v204 = (*qfn2(fn))(qenv(fn), stack[-1], v204);
    nil = C_nil;
    if (exception_pending()) goto v242;
    if (!(v204 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v204 = nil;
    { popv(3); return onevalue(v204); }
/* error exit handlers */
v242:
    popv(3);
    return nil;
}



/* Code for trailing!.coefft */

static Lisp_Object CC_trailingQcoefft(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v186, v105, v117;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for trailing.coefft");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v186 = v161;
    v105 = v0;
/* end of prologue */

v7:
    v170 = v105;
    if (!consp(v170)) return onevalue(v105);
    v170 = v105;
    v170 = qcar(v170);
    if (!consp(v170)) return onevalue(v105);
    v170 = v105;
    v170 = qcar(v170);
    v170 = qcar(v170);
    v117 = qcar(v170);
    v170 = v186;
    if (!(equal(v117, v170))) return onevalue(v105);
    v170 = v105;
    v170 = qcdr(v170);
    v105 = v170;
    goto v7;
}



/* Code for ofsf_maybenonzerol */

static Lisp_Object MS_CDECL CC_ofsf_maybenonzerol(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v161,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v219, v189, v190;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_maybenonzerol");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_maybenonzerol");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v161,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v161;
    stack[-2] = v0;
/* end of prologue */
    v219 = elt(env, 1); /* (nil) */
    stack[-3] = v219;
    goto v157;

v157:
    v219 = stack[-2];
    if (v219 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v219 = stack[-2];
    v190 = qcar(v219);
    v189 = stack[-1];
    v219 = stack[0];
    fn = elt(env, 3); /* ofsf_maybenonzero */
    v219 = (*qfnn(fn))(qenv(fn), 3, v190, v189, v219);
    nil = C_nil;
    if (exception_pending()) goto v176;
    env = stack[-4];
    v189 = v219;
    v219 = stack[-2];
    v219 = qcdr(v219);
    stack[-2] = v219;
    v219 = v189;
    v219 = qcar(v219);
    if (v219 == nil) goto v157;
    v219 = v189;
    stack[-3] = v219;
    v219 = qvalue(elt(env, 2)); /* nil */
    stack[-2] = v219;
    goto v157;
/* error exit handlers */
v176:
    popv(5);
    return nil;
}



/* Code for addlc */

static Lisp_Object CC_addlc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v217, v156, v244;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addlc");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v244 = v161;
    v156 = v0;
/* end of prologue */
    v217 = v156;
    v103 = (Lisp_Object)17; /* 1 */
    if (v217 == v103) return onevalue(v244);
    v103 = v156;
    v103 = qcar(v103);
    v103 = qcdr(v103);
    v156 = v103;
    v217 = v156;
    v103 = (Lisp_Object)17; /* 1 */
    if (v217 == v103) return onevalue(v244);
    v217 = v156;
    v103 = (Lisp_Object)-15; /* -1 */
    if (v217 == v103) return onevalue(v244);
    v103 = v156;
    if (!consp(v103)) goto v202;
    v103 = v156;
    v217 = qcar(v103);
    v103 = elt(env, 1); /* field */
    v103 = Lflagp(nil, v217, v103);
    if (!(v103 == nil)) return onevalue(v244);

v202:
    v103 = v156;
    v217 = v244;
    return cons(v103, v217);
}



/* Code for find!-non!-zero */

static Lisp_Object CC_findKnonKzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v243, v118, v209;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find-non-zero");
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
    v243 = (Lisp_Object)17; /* 1 */
    stack[0] = v243;
    goto v17;

v17:
    v243 = (Lisp_Object)17; /* 1 */
    v209 = v243;
    v243 = stack[-1];
    v243 = qcar(v243);
    stack[-2] = v243;
    goto v115;

v115:
    v243 = stack[-2];
    v118 = qcar(v243);
    v243 = (Lisp_Object)1; /* 0 */
    if (v118 == v243) goto v109;
    v243 = stack[0];
    v118 = v209;
    popv(4);
    return cons(v243, v118);

v109:
    v243 = stack[-2];
    v243 = qcdr(v243);
    stack[-2] = v243;
    v243 = v209;
    v243 = add1(v243);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    v209 = v243;
    v243 = stack[-2];
    if (!(v243 == nil)) goto v115;
    v243 = stack[-1];
    v243 = qcdr(v243);
    stack[-1] = v243;
    v243 = stack[0];
    v243 = add1(v243);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    stack[0] = v243;
    v243 = stack[-1];
    if (!(v243 == nil)) goto v17;
    v243 = elt(env, 0); /* find!-non!-zero */
    fn = elt(env, 1); /* confusion */
    v243 = (*qfn1(fn))(qenv(fn), v243);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    goto v17;
/* error exit handlers */
v172:
    popv(4);
    return nil;
}



/* Code for kern!-list */

static Lisp_Object CC_kernKlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v235, v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kern-list");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v161;
    v235 = v0;
/* end of prologue */
    stack[-3] = nil;
    fn = elt(env, 2); /* kernels */
    v235 = (*qfn1(fn))(qenv(fn), v235);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    stack[-1] = v235;
    goto v164;

v164:
    v235 = stack[-1];
    if (v235 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v235 = stack[-1];
    v235 = qcar(v235);
    stack[0] = v235;
    v224 = stack[0];
    v235 = stack[-2];
    fn = elt(env, 3); /* depend!-p */
    v235 = (*qfn2(fn))(qenv(fn), v224, v235);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    if (v235 == nil) goto v192;
    v224 = stack[0];
    v235 = stack[-3];
    v235 = cons(v224, v235);
    nil = C_nil;
    if (exception_pending()) goto v225;
    env = stack[-4];
    stack[-3] = v235;
    goto v192;

v192:
    v235 = stack[-1];
    v235 = qcdr(v235);
    stack[-1] = v235;
    goto v164;
/* error exit handlers */
v225:
    popv(5);
    return nil;
}



/* Code for ratpoly_1 */

static Lisp_Object MS_CDECL CC_ratpoly_1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ratpoly_1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_1");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v75 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* simp */
        return (*qfn1(fn))(qenv(fn), v75);
    }
}



/* Code for spmultsm */

static Lisp_Object CC_spmultsm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v263, v299, v311, v185;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spmultsm");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v161;
    stack[-7] = v0;
/* end of prologue */
    v263 = stack[-6];
    v263 = qcdr(v263);
    v263 = qcdr(v263);
    v263 = qcar(v263);
    stack[-8] = v263;
    v263 = stack[-8];
    v263 = qcdr(v263);
    v299 = qcar(v263);
    v263 = stack[-8];
    fn = elt(env, 2); /* mkempspmat */
    v263 = (*qfn2(fn))(qenv(fn), v299, v263);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-5] = v263;
    v263 = (Lisp_Object)17; /* 1 */
    stack[-1] = v263;
    goto v116;

v116:
    v263 = stack[-8];
    v263 = qcdr(v263);
    v299 = qcar(v263);
    v263 = stack[-1];
    v263 = difference2(v299, v263);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v263 = Lminusp(nil, v263);
    env = stack[-9];
    if (v263 == nil) goto v176;
    v263 = stack[-5];
    popv(10);
    return ncons(v263);

v176:
    v299 = stack[-6];
    v263 = stack[-1];
    fn = elt(env, 3); /* findrow */
    v263 = (*qfn2(fn))(qenv(fn), v299, v263);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v299 = v263;
    v263 = stack[-1];
    stack[-4] = v263;
    v263 = v299;
    if (v263 == nil) goto v209;
    v263 = v299;
    v263 = qcdr(v263);
    stack[0] = v263;
    goto v102;

v102:
    v263 = stack[0];
    if (v263 == nil) goto v209;
    v263 = stack[0];
    v263 = qcar(v263);
    v299 = v263;
    v263 = v299;
    v263 = qcar(v263);
    stack[-3] = v263;
    v263 = v299;
    v263 = qcdr(v263);
    fn = elt(env, 4); /* simp */
    v263 = (*qfn1(fn))(qenv(fn), v263);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v299 = stack[-7];
    fn = elt(env, 5); /* multsq */
    v263 = (*qfn2(fn))(qenv(fn), v299, v263);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-2] = v263;
    v263 = stack[-2];
    fn = elt(env, 6); /* mk!*sq */
    v263 = (*qfn1(fn))(qenv(fn), v263);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-2] = v263;
    v299 = stack[-2];
    v263 = (Lisp_Object)1; /* 0 */
    if (v299 == v263) goto v301;
    v311 = stack[-5];
    v299 = stack[-4];
    v263 = stack[-3];
    v185 = list3(v311, v299, v263);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    v311 = stack[-2];
    v299 = stack[-5];
    v263 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 7); /* letmtr3 */
    v263 = (*qfnn(fn))(qenv(fn), 4, v185, v311, v299, v263);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    goto v301;

v301:
    v263 = stack[0];
    v263 = qcdr(v263);
    stack[0] = v263;
    goto v102;

v209:
    v263 = stack[-1];
    v263 = add1(v263);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-9];
    stack[-1] = v263;
    goto v116;
/* error exit handlers */
v312:
    popv(10);
    return nil;
}



/* Code for nestminusp!: */

static Lisp_Object CC_nestminuspT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v190, v235, v224;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nestminusp:");
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
    v224 = v0;
/* end of prologue */
    v190 = v224;
    v190 = integerp(v190);
    if (v190 == nil) goto v160;
    v190 = (Lisp_Object)1; /* 0 */
    v235 = v190;
    goto v158;

v158:
    v190 = (Lisp_Object)1; /* 0 */
    if (v235 == v190) goto v193;
    v190 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v190); }

v193:
    v190 = v224;
    v190 = integerp(v190);
    if (v190 == nil) goto v117;
    v190 = v224;
    fn = elt(env, 2); /* simp */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v177;
    env = stack[0];
    goto v223;

v223:
    v190 = qcar(v190);
    {
        popv(1);
        fn = elt(env, 3); /* minusf */
        return (*qfn1(fn))(qenv(fn), v190);
    }

v117:
    v190 = v224;
    v190 = qcdr(v190);
    v190 = qcdr(v190);
    v190 = qcdr(v190);
    goto v223;

v160:
    v190 = v224;
    v190 = qcdr(v190);
    v190 = qcar(v190);
    v235 = v190;
    goto v158;
/* error exit handlers */
v177:
    popv(1);
    return nil;
}



/* Code for tp */

static Lisp_Object CC_tp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tp");
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
    v7 = v0;
/* end of prologue */
    fn = elt(env, 1); /* matsm */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* tp1 */
        return (*qfn1(fn))(qenv(fn), v7);
    }
/* error exit handlers */
v104:
    popv(1);
    return nil;
}



/* Code for evweightedcomp2 */

static Lisp_Object MS_CDECL CC_evweightedcomp2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v161,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v99, v95, v123, v121;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "evweightedcomp2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evweightedcomp2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v99 = v3;
    v95 = v161;
    v123 = v0;
/* end of prologue */

v104:
    v100 = v95;
    if (v100 == nil) return onevalue(v123);
    v100 = v99;
    if (v100 == nil) goto v187;
    v100 = v99;
    v121 = qcar(v100);
    v100 = (Lisp_Object)1; /* 0 */
    if (v121 == v100) goto v110;
    v100 = v99;
    v121 = qcar(v100);
    v100 = (Lisp_Object)17; /* 1 */
    if (v121 == v100) goto v190;
    v100 = v95;
    v121 = qcar(v100);
    v100 = v99;
    v100 = qcar(v100);
    v100 = fixnum_of_int((int32_t)(int_of_fixnum(v121) * int_of_fixnum(v100)));
    v100 = (Lisp_Object)(int32_t)((int32_t)v100 + (int32_t)v123 - TAG_FIXNUM);
    v123 = v100;
    v100 = v95;
    v100 = qcdr(v100);
    v95 = v100;
    v100 = v99;
    v100 = qcdr(v100);
    v99 = v100;
    goto v104;

v190:
    v100 = v95;
    v100 = qcar(v100);
    v100 = (Lisp_Object)(int32_t)((int32_t)v123 + (int32_t)v100 - TAG_FIXNUM);
    v123 = v100;
    v100 = v95;
    v100 = qcdr(v100);
    v95 = v100;
    v100 = v99;
    v100 = qcdr(v100);
    v99 = v100;
    goto v104;

v110:
    v100 = v95;
    v100 = qcdr(v100);
    v95 = v100;
    v100 = v99;
    v100 = qcdr(v100);
    v99 = v100;
    goto v104;

v187:
    v100 = elt(env, 1); /* (1 1 1 1 1) */
    v99 = v100;
    goto v104;
}



/* Code for mksetshare */

static Lisp_Object CC_mksetshare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v220, v192, v174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mksetshare");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v220 = v161;
    v192 = v0;
/* end of prologue */
    stack[0] = v192;
    v174 = elt(env, 1); /* progn */
    v192 = elt(env, 2); /* (setq alglist!* (cons nil nil)) */
    v220 = list3(v174, v192, v220);
    nil = C_nil;
    if (exception_pending()) goto v193;
    env = stack[-1];
    {
        Lisp_Object v108 = stack[0];
        popv(2);
        fn = elt(env, 3); /* mksetq */
        return (*qfn2(fn))(qenv(fn), v108, v220);
    }
/* error exit handlers */
v193:
    popv(2);
    return nil;
}



/* Code for coeff_ordn1 */

static Lisp_Object CC_coeff_ordn1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v202, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeff_ordn1");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v161;
    stack[-1] = v0;
/* end of prologue */

v214:
    v209 = stack[-1];
    if (v209 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v209 = stack[-1];
    v173 = qcar(v209);
    v209 = stack[-1];
    v202 = qcdr(v209);
    v209 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* p_subsatlaslist */
    v209 = (*qfnn(fn))(qenv(fn), 3, v173, v202, v209);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-3];
    v202 = v209;
    v209 = v202;
    if (v209 == nil) goto v219;
    v209 = stack[0];
    stack[-1] = v202;
    stack[0] = v209;
    goto v214;

v219:
    v209 = stack[-1];
    stack[-2] = qcdr(v209);
    v209 = stack[-1];
    v202 = qcar(v209);
    v209 = stack[0];
    v209 = cons(v202, v209);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-3];
    stack[-1] = stack[-2];
    stack[0] = v209;
    goto v214;
/* error exit handlers */
v216:
    popv(4);
    return nil;
}



/* Code for fs!:intequiv!: */

static Lisp_Object CC_fsTintequivT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:intequiv:");
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
    v210 = v0;
/* end of prologue */
    v210 = qcdr(v210);
    stack[0] = v210;
    v200 = stack[0];
    v210 = (Lisp_Object)49; /* 3 */
    v210 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v210/(16/CELL)));
    if (v210 == nil) goto v158;
    v210 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v210); }

v158:
    v210 = stack[0];
    fn = elt(env, 3); /* fs!:null!-angle */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-1];
    if (v210 == nil) goto v160;
    v200 = stack[0];
    v210 = (Lisp_Object)17; /* 1 */
    v200 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v210/(16/CELL)));
    v210 = elt(env, 2); /* cos */
    if (v200 == v210) goto v189;
    v210 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v210); }

v189:
    v200 = stack[0];
    v210 = (Lisp_Object)1; /* 0 */
    v210 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v210/(16/CELL)));
    v210 = qcar(v210);
    v210 = integerp(v210);
    if (v210 == nil) goto v218;
    v200 = stack[0];
    v210 = (Lisp_Object)1; /* 0 */
    v210 = *(Lisp_Object *)((char *)v200 + (CELL-TAG_VECTOR) + ((int32_t)v210/(16/CELL)));
    v200 = qcdr(v210);
    v210 = (Lisp_Object)17; /* 1 */
    v210 = (v200 == v210 ? lisp_true : nil);
    { popv(2); return onevalue(v210); }

v218:
    v210 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v210); }

v160:
    v210 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v210); }
/* error exit handlers */
v212:
    popv(2);
    return nil;
}



/* Code for put!-avalue */

static Lisp_Object MS_CDECL CC_putKavalue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v161,
                         Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v246, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "put-avalue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for put-avalue");
#endif
    if (stack >= stacklimit)
    {
        push3(v3,v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v161,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v161;
    stack[0] = v0;
/* end of prologue */
    v246 = stack[-2];
    v240 = elt(env, 1); /* scalar */
    if (v246 == v240) goto v220;
    v246 = stack[0];
    v240 = stack[-1];
    fn = elt(env, 6); /* smember */
    v240 = (*qfn2(fn))(qenv(fn), v246, v240);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    if (v240 == nil) goto v247;
    v240 = stack[0];
    {
        popv(5);
        fn = elt(env, 7); /* recursiveerror */
        return (*qfn1(fn))(qenv(fn), v240);
    }

v247:
    stack[-3] = stack[0];
    stack[0] = elt(env, 5); /* avalue */
    v246 = stack[-2];
    v240 = stack[-1];
    v240 = list2(v246, v240);
    nil = C_nil;
    if (exception_pending()) goto v233;
    {
        Lisp_Object v234 = stack[-3];
        Lisp_Object v232 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v234, v232, v240);
    }

v220:
    v246 = stack[-1];
    v240 = elt(env, 2); /* !*sq */
    if (!consp(v246)) goto v160;
    v246 = qcar(v246);
    if (!(v246 == v240)) goto v160;
    v246 = stack[0];
    v240 = stack[-1];
    v240 = qcdr(v240);
    v240 = qcar(v240);
    fn = elt(env, 8); /* sq_member */
    v240 = (*qfn2(fn))(qenv(fn), v246, v240);
    nil = C_nil;
    if (exception_pending()) goto v233;
    env = stack[-4];
    if (v240 == nil) goto v160;
    v240 = stack[0];
    {
        popv(5);
        fn = elt(env, 7); /* recursiveerror */
        return (*qfn1(fn))(qenv(fn), v240);
    }

v160:
    v240 = qvalue(elt(env, 3)); /* !*reduce4 */
    if (v240 == nil) goto v202;
    v96 = stack[0];
    v246 = stack[-1];
    v240 = elt(env, 4); /* generic */
    {
        popv(5);
        fn = elt(env, 9); /* putobject */
        return (*qfnn(fn))(qenv(fn), 3, v96, v246, v240);
    }

v202:
    stack[-3] = stack[0];
    stack[0] = elt(env, 5); /* avalue */
    v246 = stack[-2];
    v240 = stack[-1];
    v240 = list2(v246, v240);
    nil = C_nil;
    if (exception_pending()) goto v233;
    {
        Lisp_Object v229 = stack[-3];
        Lisp_Object v92 = stack[0];
        popv(5);
        return Lputprop(nil, 3, v229, v92, v240);
    }
/* error exit handlers */
v233:
    popv(5);
    return nil;
}



/* Code for ar!-rhside */

static Lisp_Object CC_arKrhside(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v161)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ar-rhside");
#endif
    if (stack >= stacklimit)
    {
        push2(v161,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v161);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v161;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v104;

v104:
    v105 = stack[-2];
    if (v105 == nil) goto v164;
    v105 = stack[-2];
    stack[0] = qcar(v105);
    v105 = stack[-1];
    v105 = add1(v105);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-4];
    fn = elt(env, 1); /* pnth */
    v117 = (*qfn2(fn))(qenv(fn), stack[0], v105);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-4];
    v105 = stack[-3];
    v105 = cons(v117, v105);
    nil = C_nil;
    if (exception_pending()) goto v219;
    env = stack[-4];
    stack[-3] = v105;
    v105 = stack[-2];
    v105 = qcdr(v105);
    stack[-2] = v105;
    goto v104;

v164:
    v105 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v105);
    }
/* error exit handlers */
v219:
    popv(5);
    return nil;
}



/* Code for msolve!-result */

static Lisp_Object CC_msolveKresult(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v324, v264, v265;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-result");
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
    v265 = v0;
/* end of prologue */
    v264 = v265;
    v324 = elt(env, 1); /* failed */
    if (v264 == v324) { popv(11); return onevalue(v265); }
    stack[-9] = elt(env, 2); /* list */
    v324 = v265;
    stack[-8] = v324;
    v324 = stack[-8];
    if (v324 == nil) goto v191;
    v324 = stack[-8];
    v324 = qcar(v324);
    stack[-4] = elt(env, 2); /* list */
    stack[-3] = v324;
    v324 = stack[-3];
    if (v324 == nil) goto v118;
    v324 = stack[-3];
    v324 = qcar(v324);
    v265 = elt(env, 4); /* equal */
    v264 = v324;
    v264 = qcar(v264);
    v324 = qcdr(v324);
    v324 = list3(v265, v264, v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = ncons(v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    stack[-1] = v324;
    stack[-2] = v324;
    goto v107;

v107:
    v324 = stack[-3];
    v324 = qcdr(v324);
    stack[-3] = v324;
    v324 = stack[-3];
    if (v324 == nil) goto v121;
    stack[0] = stack[-1];
    v324 = stack[-3];
    v324 = qcar(v324);
    v265 = elt(env, 4); /* equal */
    v264 = v324;
    v264 = qcar(v264);
    v324 = qcdr(v324);
    v324 = list3(v265, v264, v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = ncons(v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = Lrplacd(nil, stack[0], v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = stack[-1];
    v324 = qcdr(v324);
    stack[-1] = v324;
    goto v107;

v121:
    v324 = stack[-2];
    goto v235;

v235:
    v324 = cons(stack[-4], v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = ncons(v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    stack[-6] = v324;
    stack[-7] = v324;
    goto v227;

v227:
    v324 = stack[-8];
    v324 = qcdr(v324);
    stack[-8] = v324;
    v324 = stack[-8];
    if (v324 == nil) goto v234;
    stack[-5] = stack[-6];
    v324 = stack[-8];
    v324 = qcar(v324);
    stack[-4] = elt(env, 2); /* list */
    stack[-3] = v324;
    v324 = stack[-3];
    if (v324 == nil) goto v325;
    v324 = stack[-3];
    v324 = qcar(v324);
    v265 = elt(env, 4); /* equal */
    v264 = v324;
    v264 = qcar(v264);
    v324 = qcdr(v324);
    v324 = list3(v265, v264, v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = ncons(v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    stack[-1] = v324;
    stack[-2] = v324;
    goto v236;

v236:
    v324 = stack[-3];
    v324 = qcdr(v324);
    stack[-3] = v324;
    v324 = stack[-3];
    if (v324 == nil) goto v259;
    stack[0] = stack[-1];
    v324 = stack[-3];
    v324 = qcar(v324);
    v265 = elt(env, 4); /* equal */
    v264 = v324;
    v264 = qcar(v264);
    v324 = qcdr(v324);
    v324 = list3(v265, v264, v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = ncons(v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = Lrplacd(nil, stack[0], v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = stack[-1];
    v324 = qcdr(v324);
    stack[-1] = v324;
    goto v236;

v259:
    v324 = stack[-2];
    goto v300;

v300:
    v324 = cons(stack[-4], v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = ncons(v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = Lrplacd(nil, stack[-5], v324);
    nil = C_nil;
    if (exception_pending()) goto v269;
    env = stack[-10];
    v324 = stack[-6];
    v324 = qcdr(v324);
    stack[-6] = v324;
    goto v227;

v325:
    v324 = qvalue(elt(env, 3)); /* nil */
    goto v300;

v234:
    v324 = stack[-7];
    goto v222;

v222:
    {
        Lisp_Object v290 = stack[-9];
        popv(11);
        return cons(v290, v324);
    }

v118:
    v324 = qvalue(elt(env, 3)); /* nil */
    goto v235;

v191:
    v324 = qvalue(elt(env, 3)); /* nil */
    goto v222;
/* error exit handlers */
v269:
    popv(11);
    return nil;
}



setup_type const u50_setup[] =
{
    {"simptensor",              CC_simptensor,  too_many_1,    wrong_no_1},
    {"gfminus",                 CC_gfminus,     too_many_1,    wrong_no_1},
    {"ofsf_smmkatl-or",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatlKor},
    {"deleteq",                 too_few_2,      CC_deleteq,    wrong_no_2},
    {"find-expts",              too_few_2,      CC_findKexpts, wrong_no_2},
    {"dfrel2",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_dfrel2},
    {"clogf",                   CC_clogf,       too_many_1,    wrong_no_1},
    {"clear",                   CC_clear,       too_many_1,    wrong_no_1},
    {"zfactor",                 CC_zfactor,     too_many_1,    wrong_no_1},
    {"mk_relation_mat",         too_few_2,      CC_mk_relation_mat,wrong_no_2},
    {"aex_fromrp",              CC_aex_fromrp,  too_many_1,    wrong_no_1},
    {"ofsf_multsurep",          too_few_2,      CC_ofsf_multsurep,wrong_no_2},
    {"exptchk0",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_exptchk0},
    {"texaeval",                CC_texaeval,    too_many_1,    wrong_no_1},
    {"lispstmtp",               CC_lispstmtp,   too_many_1,    wrong_no_1},
    {"list_of_parents",         too_few_2,      CC_list_of_parents,wrong_no_2},
    {"getsetvarlis",            CC_getsetvarlis,too_many_1,    wrong_no_1},
    {"constant_exprp",          CC_constant_exprp,too_many_1,  wrong_no_1},
    {"get*nr*real*irred*reps",  CC_getHnrHrealHirredHreps,too_many_1,wrong_no_1},
    {"cl_subandcut",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_subandcut},
    {"comm1",                   CC_comm1,       too_many_1,    wrong_no_1},
    {"radf1",                   too_few_2,      CC_radf1,      wrong_no_2},
    {"partitop",                CC_partitop,    too_many_1,    wrong_no_1},
    {"formcond",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formcond},
    {"latexprin",               CC_latexprin,   too_many_1,    wrong_no_1},
    {"defined_append",          too_few_2,      CC_defined_append,wrong_no_2},
    {"compactf0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_compactf0},
    {"ar-augment",              too_few_2,      CC_arKaugment, wrong_no_2},
    {"basic-kern1",             CC_basicKkern1, too_many_1,    wrong_no_1},
    {"bdstest",                 CC_bdstest,     too_many_1,    wrong_no_1},
    {"trailing.coefft",         too_few_2,      CC_trailingQcoefft,wrong_no_2},
    {"ofsf_maybenonzerol",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_maybenonzerol},
    {"addlc",                   too_few_2,      CC_addlc,      wrong_no_2},
    {"find-non-zero",           CC_findKnonKzero,too_many_1,   wrong_no_1},
    {"kern-list",               too_few_2,      CC_kernKlist,  wrong_no_2},
    {"ratpoly_1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_1},
    {"spmultsm",                too_few_2,      CC_spmultsm,   wrong_no_2},
    {"nestminusp:",             CC_nestminuspT, too_many_1,    wrong_no_1},
    {"tp",                      CC_tp,          too_many_1,    wrong_no_1},
    {"evweightedcomp2",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_evweightedcomp2},
    {"mksetshare",              too_few_2,      CC_mksetshare, wrong_no_2},
    {"coeff_ordn1",             too_few_2,      CC_coeff_ordn1,wrong_no_2},
    {"fs:intequiv:",            CC_fsTintequivT,too_many_1,    wrong_no_1},
    {"put-avalue",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_putKavalue},
    {"ar-rhside",               too_few_2,      CC_arKrhside,  wrong_no_2},
    {"msolve-result",           CC_msolveKresult,too_many_1,   wrong_no_1},
    {NULL, (one_args *)"u50", (two_args *)"3268 8766450 9611117", 0}
};

/* end of generated code */
