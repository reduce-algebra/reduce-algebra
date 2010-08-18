
/* $destdir/generated-c\u51.c Machine generated C code */

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


/* Code for simpsqrt */

static Lisp_Object CC_simpsqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpsqrt");
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
    v23 = v0;
/* end of prologue */
    v22 = v23;
    v21 = (Lisp_Object)1; /* 0 */
    if (v22 == v21) goto v24;
    v21 = qvalue(elt(env, 2)); /* !*keepsqrts */
    if (v21 == nil) goto v25;
    v21 = v23;
    v21 = qcar(v21);
    fn = elt(env, 6); /* xsimp */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    stack[-1] = v21;
    v21 = stack[-1];
    v21 = qcar(v21);
    if (v21 == nil) goto v27;
    v21 = stack[-1];
    v22 = qcdr(v21);
    v21 = (Lisp_Object)17; /* 1 */
    if (!(v22 == v21)) goto v28;
    v21 = stack[-1];
    v21 = qcar(v21);
    if (!consp(v21)) goto v29;
    v21 = stack[-1];
    v21 = qcar(v21);
    v21 = qcar(v21);
    if (!(!consp(v21))) goto v28;

v29:
    v21 = stack[-1];
    v21 = qcar(v21);
    fn = elt(env, 7); /* !:minusp */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    if (v21 == nil) goto v28;
    v21 = stack[-1];
    v22 = qcar(v21);
    v21 = (Lisp_Object)-15; /* -1 */
    if (v22 == v21) goto v30;
    v21 = elt(env, 4); /* i */
    fn = elt(env, 8); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v21 = stack[-1];
    v21 = qcar(v21);
    fn = elt(env, 9); /* !:minus */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    fn = elt(env, 10); /* prepd */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v21 = ncons(v21);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v21 = CC_simpsqrt(env, v21);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    {
        Lisp_Object v31 = stack[0];
        popv(3);
        fn = elt(env, 11); /* multsq */
        return (*qfn2(fn))(qenv(fn), v31, v21);
    }

v30:
    v21 = elt(env, 4); /* i */
    {
        popv(3);
        fn = elt(env, 8); /* simp */
        return (*qfn1(fn))(qenv(fn), v21);
    }

v28:
    stack[0] = elt(env, 5); /* sqrt */
    v21 = stack[-1];
    v21 = ncons(v21);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    fn = elt(env, 12); /* domainvalchk */
    v21 = (*qfn2(fn))(qenv(fn), stack[0], v21);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v22 = v21;
    if (!(v21 == nil)) { popv(3); return onevalue(v22); }
    v22 = stack[-1];
    v21 = (Lisp_Object)33; /* 2 */
    {
        popv(3);
        fn = elt(env, 13); /* simprad */
        return (*qfn2(fn))(qenv(fn), v22, v21);
    }

v27:
    v22 = qvalue(elt(env, 1)); /* nil */
    v21 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v22, v21);

v25:
    v21 = v23;
    stack[0] = qcar(v21);
    v21 = elt(env, 3); /* (quotient 1 2) */
    fn = elt(env, 14); /* simpexpon */
    v22 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    v21 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v32 = stack[0];
        popv(3);
        fn = elt(env, 15); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v32, v22, v21);
    }

v24:
    v22 = qvalue(elt(env, 1)); /* nil */
    v21 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v22, v21);
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for fctrf */

static Lisp_Object CC_fctrf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v61, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctrf");
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
    v61 = qvalue(elt(env, 1)); /* !*exp */
    v60 = qvalue(elt(env, 2)); /* ncmp!* */
    stack[-6] = qvalue(elt(env, 1)); /* !*exp */
    qvalue(elt(env, 1)) = v61; /* !*exp */
    stack[-4] = qvalue(elt(env, 2)); /* ncmp!* */
    qvalue(elt(env, 2)) = v60; /* ncmp!* */
    stack[-3] = qvalue(elt(env, 3)); /* !*ezgcd */
    qvalue(elt(env, 3)) = nil; /* !*ezgcd */
    stack[-2] = qvalue(elt(env, 4)); /* !*gcd */
    qvalue(elt(env, 4)) = nil; /* !*gcd */
    stack[-1] = nil;
    v60 = stack[-5];
    if (!consp(v60)) goto v63;
    v60 = stack[-5];
    v60 = qcar(v60);
    if (!consp(v60)) goto v63;
    v60 = qvalue(elt(env, 2)); /* ncmp!* */
    if (v60 == nil) goto v24;
    v60 = stack[-5];
    fn = elt(env, 16); /* noncomfp */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    if (!(v60 == nil)) goto v24;
    v60 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 2)) = v60; /* ncmp!* */
    goto v24;

v24:
    v60 = qvalue(elt(env, 6)); /* t */
    qvalue(elt(env, 4)) = v60; /* !*gcd */
    v60 = qvalue(elt(env, 7)); /* !*limitedfactors */
    if (!(v60 == nil)) goto v15;
    v60 = qvalue(elt(env, 8)); /* dmode!* */
    if (!(v60 == nil)) goto v15;
    v60 = qvalue(elt(env, 6)); /* t */
    qvalue(elt(env, 3)) = v60; /* !*ezgcd */
    goto v15;

v15:
    v60 = qvalue(elt(env, 9)); /* !*mcd */
    if (v60 == nil) goto v65;
    v60 = qvalue(elt(env, 1)); /* !*exp */
    if (!(v60 == nil)) goto v66;
    v60 = qvalue(elt(env, 6)); /* t */
    qvalue(elt(env, 1)) = v60; /* !*exp */
    v61 = stack[-5];
    v60 = (Lisp_Object)17; /* 1 */
    v60 = cons(v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    fn = elt(env, 17); /* resimp */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    fn = elt(env, 18); /* !*q2f */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    stack[-5] = v60;
    goto v66;

v66:
    v61 = qvalue(elt(env, 8)); /* dmode!* */
    v60 = elt(env, 12); /* !:rn!: */
    if (!(v61 == v60)) goto v67;
    v60 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 8)) = v60; /* dmode!* */
    v60 = qvalue(elt(env, 5)); /* nil */
    v60 = ncons(v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    qvalue(elt(env, 13)) = v60; /* alglist!* */
    v60 = stack[-5];
    fn = elt(env, 19); /* prepf */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    fn = elt(env, 20); /* simp */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    stack[0] = v60;
    v60 = stack[0];
    v60 = qcdr(v60);
    if (!consp(v60)) goto v68;
    v60 = (Lisp_Object)17; /* 1 */
    stack[-1] = v60;
    goto v67;

v67:
    v60 = qvalue(elt(env, 2)); /* ncmp!* */
    if (!(v60 == nil)) goto v69;
    v60 = stack[-5];
    fn = elt(env, 21); /* sf2ss */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    stack[0] = v60;
    v60 = stack[0];
    fn = elt(env, 22); /* homogp */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    if (v60 == nil) goto v69;
    v60 = qvalue(elt(env, 14)); /* !*trfac */
    if (v60 == nil) goto v70;
    v60 = elt(env, 15); /* "This polynomial is homogeneous - variables scaled" 
*/
    fn = elt(env, 23); /* prin2t */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    goto v70;

v70:
    v60 = stack[0];
    v60 = qcar(v60);
    v60 = qcar(v60);
    stack[-1] = qcar(v60);
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcar(v60);
    v60 = qcar(v60);
    v60 = qcar(v60);
    fn = elt(env, 24); /* listsum */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    v60 = cons(stack[-1], v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    stack[-5] = v60;
    v60 = stack[0];
    stack[-1] = qcar(v60);
    v60 = stack[0];
    v60 = qcdr(v60);
    v60 = qcar(v60);
    fn = elt(env, 25); /* subs0 */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    v61 = Lreverse(nil, v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    v60 = (Lisp_Object)17; /* 1 */
    v60 = list2star(stack[-1], v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    fn = elt(env, 26); /* ss2sf */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    fn = elt(env, 27); /* fctrf1 */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    stack[0] = v60;
    v61 = stack[-5];
    v60 = stack[0];
    fn = elt(env, 28); /* rconst */
    v60 = (*qfn2(fn))(qenv(fn), v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    stack[0] = v60;
    v60 = stack[0];
    stack[-1] = qcar(v60);
    v60 = stack[0];
    v60 = qcdr(v60);
    fn = elt(env, 29); /* sort!-factors */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    v60 = cons(stack[-1], v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    goto v19;

v19:
    qvalue(elt(env, 4)) = stack[-2]; /* !*gcd */
    qvalue(elt(env, 3)) = stack[-3]; /* !*ezgcd */
    qvalue(elt(env, 2)) = stack[-4]; /* ncmp!* */
    qvalue(elt(env, 1)) = stack[-6]; /* !*exp */
    { popv(8); return onevalue(v60); }

v69:
    v60 = stack[-5];
    fn = elt(env, 27); /* fctrf1 */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    stack[-5] = v60;
    v60 = stack[-1];
    if (v60 == nil) goto v71;
    v60 = qvalue(elt(env, 5)); /* nil */
    v60 = ncons(v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    qvalue(elt(env, 13)) = v60; /* alglist!* */
    v60 = elt(env, 12); /* !:rn!: */
    qvalue(elt(env, 8)) = v60; /* dmode!* */
    stack[0] = stack[-5];
    v60 = stack[-5];
    v61 = qcar(v60);
    v60 = stack[-1];
    fn = elt(env, 30); /* quotf!* */
    v60 = (*qfn2(fn))(qenv(fn), v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    fn = elt(env, 31); /* setcar */
    v60 = (*qfn2(fn))(qenv(fn), stack[0], v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    goto v71;

v71:
    v60 = stack[-5];
    stack[0] = qcar(v60);
    v60 = stack[-5];
    v60 = qcdr(v60);
    fn = elt(env, 29); /* sort!-factors */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    v60 = cons(stack[0], v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    goto v19;

v68:
    v60 = stack[0];
    v60 = qcdr(v60);
    stack[-1] = v60;
    v60 = stack[0];
    v60 = qcar(v60);
    stack[-5] = v60;
    goto v67;

v65:
    v62 = elt(env, 10); /* poly */
    v61 = (Lisp_Object)241; /* 15 */
    v60 = elt(env, 11); /* "Factorization invalid with MCD off" */
    fn = elt(env, 32); /* rerror */
    v60 = (*qfnn(fn))(qenv(fn), 3, v62, v61, v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    goto v66;

v63:
    v60 = stack[-5];
    v60 = ncons(v60);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-7];
    goto v19;
/* error exit handlers */
v64:
    env = stack[-7];
    qvalue(elt(env, 4)) = stack[-2]; /* !*gcd */
    qvalue(elt(env, 3)) = stack[-3]; /* !*ezgcd */
    qvalue(elt(env, 2)) = stack[-4]; /* ncmp!* */
    qvalue(elt(env, 1)) = stack[-6]; /* !*exp */
    popv(8);
    return nil;
}



/* Code for pickupu */

static Lisp_Object MS_CDECL CC_pickupu(Lisp_Object env, int nargs,
                         Lisp_Object v72, Lisp_Object v73,
                         Lisp_Object v74, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v70, v86, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pickupu");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pickupu");
#endif
    if (stack >= stacklimit)
    {
        push3(v74,v73,v72);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v72,v73,v74);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v74;
    stack[-3] = v73;
    v5 = v72;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* rhs!* */
    qvalue(elt(env, 1)) = nil; /* rhs!* */
    qvalue(elt(env, 1)) = v5; /* rhs!* */
    stack[-1] = nil;
    v5 = qvalue(elt(env, 1)); /* rhs!* */
    qvalue(elt(env, 2)) = v5; /* pt */
    goto v88;

v88:
    v5 = qvalue(elt(env, 2)); /* pt */
    if (v5 == nil) goto v18;
    v5 = qvalue(elt(env, 2)); /* pt */
    v70 = qcar(v5);
    v5 = stack[-3];
    fn = elt(env, 6); /* nextu */
    v5 = (*qfn2(fn))(qenv(fn), v70, v5);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    stack[0] = v5;
    v5 = stack[0];
    if (v5 == nil) goto v63;
    v5 = stack[0];
    v70 = qcar(v5);
    v5 = qvalue(elt(env, 4)); /* lorder */
    fn = elt(env, 7); /* testord */
    v5 = (*qfn2(fn))(qenv(fn), v70, v5);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    if (v5 == nil) goto v89;
    v70 = stack[-1];
    v5 = stack[0];
    v5 = qcar(v5);
    fn = elt(env, 8); /* checkcoeffts */
    v5 = (*qfn2(fn))(qenv(fn), v70, v5);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    if (v5 == nil) goto v63;
    v70 = qvalue(elt(env, 5)); /* ulist */
    v5 = stack[0];
    fn = elt(env, 9); /* checku */
    v5 = (*qfn2(fn))(qenv(fn), v70, v5);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    if (!(v5 == nil)) goto v63;
    v5 = stack[0];
    v70 = qcar(v5);
    v5 = qvalue(elt(env, 1)); /* rhs!* */
    fn = elt(env, 10); /* checku1 */
    v5 = (*qfn2(fn))(qenv(fn), v70, v5);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    if (!(v5 == nil)) goto v89;
    v5 = stack[-2];
    if (v5 == nil) goto v90;
    v5 = stack[0];
    v87 = ncons(v5);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    v86 = stack[-3];
    v5 = qvalue(elt(env, 2)); /* pt */
    v70 = qcdr(v5);
    v5 = qvalue(elt(env, 1)); /* rhs!* */
    fn = elt(env, 11); /* patchuptan */
    v5 = (*qfnn(fn))(qenv(fn), 4, v87, v86, v70, v5);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    stack[0] = v5;
    goto v90;

v90:
    v5 = stack[0];
    goto v34;

v34:
    qvalue(elt(env, 1)) = stack[-4]; /* rhs!* */
    { popv(6); return onevalue(v5); }

v89:
    v5 = qvalue(elt(env, 2)); /* pt */
    v5 = qcar(v5);
    v70 = qcdr(v5);
    v5 = stack[-1];
    v5 = cons(v70, v5);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-5];
    stack[-1] = v5;
    goto v63;

v63:
    v5 = qvalue(elt(env, 2)); /* pt */
    v5 = qcdr(v5);
    qvalue(elt(env, 2)) = v5; /* pt */
    goto v88;

v18:
    v5 = qvalue(elt(env, 3)); /* nil */
    goto v34;
/* error exit handlers */
v53:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* rhs!* */
    popv(6);
    return nil;
}



/* Code for giremainder */

static Lisp_Object CC_giremainder(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v131, v132, v133;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giremainder");
#endif
    if (stack >= stacklimit)
    {
        push2(v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v132 = v72;
    v133 = v0;
/* end of prologue */
    v131 = v133;
    v131 = qcdr(v131);
    v131 = qcar(v131);
    stack[-7] = v131;
    v131 = v133;
    v131 = qcdr(v131);
    v131 = qcdr(v131);
    stack[-6] = v131;
    v131 = v132;
    v131 = qcdr(v131);
    v131 = qcar(v131);
    stack[-5] = v131;
    v131 = v132;
    v131 = qcdr(v131);
    v131 = qcdr(v131);
    stack[-4] = v131;
    v132 = stack[-5];
    v131 = stack[-5];
    stack[0] = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v132 = stack[-4];
    v131 = stack[-4];
    v131 = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = plus2(stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    stack[-3] = v131;
    v132 = stack[-7];
    v131 = stack[-5];
    stack[0] = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v132 = stack[-6];
    v131 = stack[-4];
    v131 = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = plus2(stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    stack[-2] = v131;
    v132 = stack[-6];
    v131 = stack[-5];
    stack[0] = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v132 = stack[-4];
    v131 = stack[-7];
    v131 = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = difference2(stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    stack[-1] = v131;
    v132 = (Lisp_Object)33; /* 2 */
    v131 = stack[-2];
    stack[0] = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v132 = stack[-2];
    v131 = (Lisp_Object)1; /* 0 */
    v131 = (Lisp_Object)lessp2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v131 = v131 ? lisp_true : nil;
    env = stack[-8];
    if (v131 == nil) goto v22;
    v131 = stack[-3];
    v131 = negate(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = add1(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    goto v89;

v89:
    stack[0] = plus2(stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v132 = (Lisp_Object)33; /* 2 */
    v131 = stack[-3];
    v131 = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = Ldivide(nil, stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = qcar(v131);
    stack[-2] = v131;
    v132 = (Lisp_Object)33; /* 2 */
    v131 = stack[-1];
    stack[0] = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v132 = stack[-1];
    v131 = (Lisp_Object)1; /* 0 */
    v131 = (Lisp_Object)lessp2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v131 = v131 ? lisp_true : nil;
    env = stack[-8];
    if (v131 == nil) goto v135;
    v131 = stack[-3];
    v131 = negate(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = add1(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    goto v136;

v136:
    stack[0] = plus2(stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v132 = (Lisp_Object)33; /* 2 */
    v131 = stack[-3];
    v131 = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = Ldivide(nil, stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = qcar(v131);
    stack[-1] = v131;
    stack[-3] = stack[-7];
    v132 = stack[-2];
    v131 = stack[-5];
    stack[0] = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v132 = stack[-1];
    v131 = stack[-4];
    v131 = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = difference2(stack[0], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = difference2(stack[-3], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    stack[0] = v131;
    stack[-3] = stack[-6];
    v132 = stack[-1];
    v131 = stack[-5];
    stack[-1] = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v132 = stack[-2];
    v131 = stack[-4];
    v131 = times2(v132, v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = plus2(stack[-1], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v131 = difference2(stack[-3], v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    v132 = v131;
    v133 = elt(env, 1); /* !:gi!: */
    v131 = stack[0];
    popv(9);
    return list2star(v133, v131, v132);

v135:
    v131 = stack[-3];
    v131 = sub1(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    goto v136;

v22:
    v131 = stack[-3];
    v131 = sub1(v131);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-8];
    goto v89;
/* error exit handlers */
v134:
    popv(9);
    return nil;
}



/* Code for ofsf_xor */

static Lisp_Object CC_ofsf_xor(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v137, v25, v138;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_xor");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v25 = v72;
    v138 = v0;
/* end of prologue */
    v137 = v138;
    if (!(v137 == nil)) goto v19;
    v137 = v25;
    if (!(v137 == nil)) goto v19;
    v137 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v137);

v19:
    v137 = v138;
    if (v137 == nil) goto v139;
    v137 = v25;
    goto v63;

v63:
    v137 = (v137 == nil ? lisp_true : nil);
    return onevalue(v137);

v139:
    v137 = qvalue(elt(env, 1)); /* nil */
    goto v63;
}



/* Code for mkop */

static Lisp_Object CC_mkop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v144, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkop");
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
    v29 = stack[0];
    if (v29 == nil) goto v20;
    v29 = stack[0];
    fn = elt(env, 8); /* gettype */
    v144 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    v67 = v144;
    v29 = elt(env, 3); /* operator */
    if (v144 == v29) goto v84;
    v29 = v67;
    if (v29 == nil) goto v146;
    v144 = v67;
    v29 = elt(env, 5); /* (fluid global procedure scalar) */
    v29 = Lmemq(nil, v144, v29);
    if (!(v29 == nil)) goto v146;
    v144 = stack[0];
    v29 = elt(env, 3); /* operator */
    fn = elt(env, 9); /* typerr */
    v29 = (*qfn2(fn))(qenv(fn), v144, v29);
    nil = C_nil;
    if (exception_pending()) goto v145;
    goto v33;

v33:
    v29 = nil;
    { popv(2); return onevalue(v29); }

v146:
    v67 = stack[0];
    v144 = elt(env, 6); /* simpfn */
    v29 = elt(env, 7); /* simpiden */
    v29 = Lputprop(nil, 3, v67, v144, v29);
    nil = C_nil;
    if (exception_pending()) goto v145;
    goto v33;

v84:
    v144 = stack[0];
    v29 = elt(env, 4); /* "already defined as operator" */
    v29 = list2(v144, v29);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-1];
    fn = elt(env, 10); /* lprim */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v145;
    goto v33;

v20:
    v144 = elt(env, 1); /* "Local variable" */
    v29 = elt(env, 2); /* "operator" */
    fn = elt(env, 9); /* typerr */
    v29 = (*qfn2(fn))(qenv(fn), v144, v29);
    nil = C_nil;
    if (exception_pending()) goto v145;
    goto v33;
/* error exit handlers */
v145:
    popv(2);
    return nil;
}



/* Code for leqgrt */

static Lisp_Object MS_CDECL CC_leqgrt(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v72,
                         Lisp_Object v73, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v151;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "leqgrt");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for leqgrt");
#endif
    if (stack >= stacklimit)
    {
        push3(v73,v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v72,v73);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v73;
    stack[-1] = v72;
    stack[-2] = v0;
/* end of prologue */
    v151 = stack[-1];
    v3 = stack[0];
    v3 = (Lisp_Object)lesseq2(v151, v3);
    nil = C_nil;
    if (exception_pending()) goto v152;
    v3 = v3 ? lisp_true : nil;
    env = stack[-3];
    if (v3 == nil) goto v46;
    v151 = stack[-2];
    v3 = stack[-1];
    v3 = Leqn(nil, v151, v3);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-3];
    goto v43;

v43:
    if (!(v3 == nil)) { popv(4); return onevalue(v3); }
    v3 = stack[0];
    v3 = add1(v3);
    nil = C_nil;
    if (exception_pending()) goto v152;
    {
        Lisp_Object v153 = stack[-1];
        popv(4);
        return Lgeq(nil, v153, v3);
    }

v46:
    v3 = qvalue(elt(env, 1)); /* nil */
    goto v43;
/* error exit handlers */
v152:
    popv(4);
    return nil;
}



/* Code for setequal */

static Lisp_Object CC_setequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v142;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v72;
    stack[-1] = v0;
/* end of prologue */
    v142 = stack[-1];
    v138 = stack[0];
    fn = elt(env, 2); /* subsetp */
    v138 = (*qfn2(fn))(qenv(fn), v142, v138);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-2];
    if (v138 == nil) goto v35;
    v142 = stack[0];
    v138 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* subsetp */
        return (*qfn2(fn))(qenv(fn), v142, v138);
    }

v35:
    v138 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v138); }
/* error exit handlers */
v84:
    popv(3);
    return nil;
}



/* Code for remred */

static Lisp_Object CC_remred(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v155, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remred");
#endif
    if (stack >= stacklimit)
    {
        push2(v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v72;
    stack[-5] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = nil; /* gg */
    v155 = stack[-5];
    v155 = Lreverse(nil, v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    stack[-5] = v155;
    goto v24;

v24:
    v155 = stack[-5];
    if (v155 == nil) goto v88;
    v155 = stack[-5];
    v155 = qcar(v155);
    stack[-2] = v155;
    v155 = stack[-5];
    v155 = qcdr(v155);
    stack[-5] = v155;
    v155 = qvalue(elt(env, 3)); /* t */
    stack[-1] = v155;
    v155 = qvalue(elt(env, 1)); /* gg */
    stack[-3] = v155;
    goto v149;

v149:
    v155 = stack[-1];
    if (v155 == nil) goto v148;
    v155 = stack[-3];
    if (v155 == nil) goto v148;
    v155 = stack[-3];
    v155 = qcar(v155);
    v90 = v155;
    v155 = stack[-3];
    v155 = qcdr(v155);
    stack[-3] = v155;
    v155 = v90;
    v90 = qcdr(v155);
    v155 = stack[-2];
    v155 = qcdr(v155);
    fn = elt(env, 4); /* dd */
    stack[0] = (*qfn2(fn))(qenv(fn), v90, v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    v90 = stack[-4];
    v155 = (Lisp_Object)33; /* 2 */
    v155 = plus2(v90, v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    v155 = (Lisp_Object)geq2(stack[0], v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    v155 = v155 ? lisp_true : nil;
    env = stack[-7];
    if (v155 == nil) goto v149;
    v155 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v155;
    goto v149;

v148:
    v155 = stack[-1];
    if (v155 == nil) goto v24;
    v90 = stack[-2];
    v155 = qvalue(elt(env, 1)); /* gg */
    v155 = cons(v90, v155);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-7];
    qvalue(elt(env, 1)) = v155; /* gg */
    goto v24;

v88:
    v155 = qvalue(elt(env, 1)); /* gg */
    qvalue(elt(env, 1)) = stack[-6]; /* gg */
    { popv(8); return onevalue(v155); }
/* error exit handlers */
v156:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* gg */
    popv(8);
    return nil;
}



/* Code for !:recip */

static Lisp_Object CC_Trecip(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9, v8, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :recip");
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
    v9 = stack[0];
    if (!(is_number(v9))) goto v82;
    v9 = stack[0];
    v8 = Labsval(nil, v9);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-1];
    v9 = (Lisp_Object)17; /* 1 */
    if (v8 == v9) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v9 = qvalue(elt(env, 1)); /* dmode!* */
    if (v9 == nil) goto v147;
    v8 = qvalue(elt(env, 1)); /* dmode!* */
    v9 = elt(env, 2); /* (!:rd!: !:cr!:) */
    v9 = Lmemq(nil, v8, v9);
    if (!(v9 == nil)) goto v147;
    v8 = qvalue(elt(env, 1)); /* dmode!* */
    v9 = elt(env, 3); /* i2d */
    v8 = get(v8, v9);
    env = stack[-1];
    v9 = stack[0];
    v9 = Lapply1(nil, v8, v9);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-1];
    stack[0] = v9;
    goto v82;

v82:
    v161 = (Lisp_Object)17; /* 1 */
    v8 = stack[0];
    v9 = elt(env, 4); /* quotient */
    fn = elt(env, 6); /* dcombine */
    v9 = (*qfnn(fn))(qenv(fn), 3, v161, v8, v9);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-1];
    v161 = v9;
    v9 = v161;
    if (!consp(v9)) { popv(2); return onevalue(v161); }
    v9 = v161;
    v8 = qcar(v9);
    v9 = elt(env, 5); /* !:rn!: */
    if (!(v8 == v9)) { popv(2); return onevalue(v161); }
    v9 = v161;
    {
        popv(2);
        fn = elt(env, 7); /* !:rn2rd */
        return (*qfn1(fn))(qenv(fn), v9);
    }

v147:
    v8 = (Lisp_Object)17; /* 1 */
    v9 = stack[0];
    fn = elt(env, 8); /* mkrn */
    v9 = (*qfn2(fn))(qenv(fn), v8, v9);
    nil = C_nil;
    if (exception_pending()) goto v156;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 7); /* !:rn2rd */
        return (*qfn1(fn))(qenv(fn), v9);
    }
/* error exit handlers */
v156:
    popv(2);
    return nil;
}



/* Code for open */

static Lisp_Object CC_open(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v55, v56, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for open");
#endif
    if (stack >= stacklimit)
    {
        push2(v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v56 = v72;
    v167 = v0;
/* end of prologue */
    v55 = v56;
    v166 = elt(env, 1); /* input */
    if (v55 == v166) goto v63;
    v55 = v56;
    v166 = elt(env, 2); /* output */
    if (v55 == v166) goto v160;
    v55 = v56;
    v166 = elt(env, 3); /* append */
    if (v55 == v166) goto v57;
    v166 = elt(env, 4); /* "bad direction ~A in open" */
    v55 = v56;
    {
        popv(2);
        fn = elt(env, 5); /* error */
        return (*qfn2(fn))(qenv(fn), v166, v55);
    }

v57:
    stack[0] = v167;
    v55 = (Lisp_Object)33; /* 2 */
    v166 = (Lisp_Object)641; /* 40 */
    v166 = plus2(v55, v166);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    {
        Lisp_Object v78 = stack[0];
        popv(2);
        fn = elt(env, 6); /* internal!-open */
        return (*qfn2(fn))(qenv(fn), v78, v166);
    }

v160:
    stack[0] = v167;
    v55 = (Lisp_Object)33; /* 2 */
    v166 = (Lisp_Object)833; /* 52 */
    v166 = plus2(v55, v166);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-1];
    {
        Lisp_Object v79 = stack[0];
        popv(2);
        fn = elt(env, 6); /* internal!-open */
        return (*qfn2(fn))(qenv(fn), v79, v166);
    }

v63:
    v55 = v167;
    v166 = (Lisp_Object)1041; /* 65 */
    {
        popv(2);
        fn = elt(env, 6); /* internal!-open */
        return (*qfn2(fn))(qenv(fn), v55, v166);
    }
/* error exit handlers */
v30:
    popv(2);
    return nil;
}



/* Code for simp!:ps!: */

static Lisp_Object CC_simpTpsT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp:ps:");
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
    fn = elt(env, 1); /* simp!:ps1 */
    v19 = (*qfn1(fn))(qenv(fn), v20);
    errexit();
    v20 = (Lisp_Object)17; /* 1 */
    return cons(v19, v20);
}



/* Code for mappend */

static Lisp_Object CC_mappend(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v13;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mappend");
#endif
    if (stack >= stacklimit)
    {
        push2(v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v72;
    v58 = v0;
/* end of prologue */
    stack[-4] = v58;
    v58 = stack[-4];
    if (v58 == nil) goto v19;
    v58 = stack[-4];
    v58 = qcar(v58);
    v13 = stack[-3];
    v58 = Lappend(nil, v13, v58);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    stack[-1] = v58;
    stack[-2] = v58;
    goto v43;

v43:
    v58 = stack[-4];
    v58 = qcdr(v58);
    stack[-4] = v58;
    v58 = stack[-4];
    if (v58 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v58 = stack[-4];
    v58 = qcar(v58);
    v13 = stack[-3];
    v58 = Lappend(nil, v13, v58);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    v58 = ncons(v58);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    v58 = Lrplacd(nil, stack[0], v58);
    nil = C_nil;
    if (exception_pending()) goto v169;
    env = stack[-5];
    v58 = stack[-1];
    v58 = qcdr(v58);
    stack[-1] = v58;
    goto v43;

v19:
    v58 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v58); }
/* error exit handlers */
v169:
    popv(6);
    return nil;
}



/* Code for a2dipatom */

static Lisp_Object CC_a2dipatom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v163, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for a2dipatom");
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
    v59 = stack[0];
    v163 = (Lisp_Object)1; /* 0 */
    if (v59 == v163) goto v36;
    v163 = stack[0];
    if (is_number(v163)) goto v148;
    v59 = stack[0];
    v163 = qvalue(elt(env, 2)); /* dipvars!* */
    v163 = Lmember(nil, v59, v163);
    if (v163 == nil) goto v148;
    v163 = stack[0];
    fn = elt(env, 4); /* mkexpvec */
    stack[0] = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    v163 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* a2bc */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    v59 = qvalue(elt(env, 3)); /* nil */
    {
        Lisp_Object v12 = stack[0];
        popv(3);
        return list2star(v12, v163, v59);
    }

v148:
    fn = elt(env, 6); /* evzero */
    stack[-1] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    v163 = stack[0];
    fn = elt(env, 5); /* a2bc */
    v163 = (*qfn1(fn))(qenv(fn), v163);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-2];
    v59 = qvalue(elt(env, 3)); /* nil */
    {
        Lisp_Object v81 = stack[-1];
        popv(3);
        return list2star(v81, v163, v59);
    }

v36:
    v163 = qvalue(elt(env, 1)); /* dipzero */
    { popv(3); return onevalue(v163); }
/* error exit handlers */
v13:
    popv(3);
    return nil;
}



/* Code for xadd */

static Lisp_Object MS_CDECL CC_xadd(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v72,
                         Lisp_Object v73, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v179;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xadd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xadd");
#endif
    if (stack >= stacklimit)
    {
        push3(v73,v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v72,v73);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v73;
    stack[-1] = v72;
    stack[-2] = v0;
/* end of prologue */
    v51 = stack[-2];
    v179 = qcar(v51);
    v51 = stack[-1];
    v51 = Lassoc(nil, v179, v51);
    stack[-3] = v51;
    v51 = stack[-3];
    if (v51 == nil) goto v150;
    v51 = stack[0];
    if (v51 == nil) goto v130;
    v179 = stack[-3];
    v51 = stack[-1];
    v51 = Ldelete(nil, v179, v51);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    stack[-1] = v51;
    v51 = stack[-3];
    v51 = qcdr(v51);
    if (!consp(v51)) goto v13;
    v51 = stack[-3];
    v179 = Llength(nil, v51);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    v51 = (Lisp_Object)81; /* 5 */
    if (!(v179 == v51)) goto v13;
    v51 = stack[-3];
    v51 = qcdr(v51);
    stack[-3] = v51;
    goto v13;

v13:
    v51 = stack[-3];
    v51 = qcdr(v51);
    if (!consp(v51)) goto v123;
    v51 = stack[-3];
    v51 = qcdr(v51);
    v51 = qcdr(v51);
    v179 = qcar(v51);
    v51 = stack[-3];
    v51 = qcdr(v51);
    v51 = qcar(v51);
    v51 = qcdr(v51);
    fn = elt(env, 3); /* updoldrules */
    v51 = (*qfn2(fn))(qenv(fn), v179, v51);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-4];
    goto v123;

v123:
    v179 = stack[0];
    v51 = elt(env, 1); /* replace */
    if (v179 == v51) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v179 = stack[-2];
    v51 = stack[-1];
    v51 = cons(v179, v51);
    nil = C_nil;
    if (exception_pending()) goto v113;
    stack[-1] = v51;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v130:
    v51 = stack[-3];
    v51 = qcdr(v51);
    if (!(!consp(v51))) goto v28;
    v51 = stack[-3];
    v179 = qcdr(v51);
    v51 = stack[-2];
    v51 = qcdr(v51);
    if (!(equal(v179, v51))) goto v28;

v120:
    v179 = stack[-3];
    v51 = stack[-1];
    v51 = Ldelete(nil, v179, v51);
    nil = C_nil;
    if (exception_pending()) goto v113;
    stack[-1] = v51;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v28:
    v51 = stack[-3];
    v51 = qcdr(v51);
    if (!consp(v51)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v51 = stack[-3];
    v51 = qcdr(v51);
    v179 = qcar(v51);
    v51 = stack[-2];
    v51 = qcdr(v51);
    v51 = qcar(v51);
    if (equal(v179, v51)) goto v120;
    else { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v150:
    v51 = stack[0];
    if (v51 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v179 = stack[0];
    v51 = elt(env, 1); /* replace */
    if (v179 == v51) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v179 = stack[-2];
    v51 = stack[-1];
    v51 = cons(v179, v51);
    nil = C_nil;
    if (exception_pending()) goto v113;
    stack[-1] = v51;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
/* error exit handlers */
v113:
    popv(5);
    return nil;
}



/* Code for crprimp */

static Lisp_Object CC_crprimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v152, v153, v168;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for crprimp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v168 = v0;
/* end of prologue */
    v153 = v168;
    v152 = (Lisp_Object)17; /* 1 */
    if (v153 == v152) goto v36;
    v153 = v168;
    v152 = (Lisp_Object)-15; /* -1 */
    if (v153 == v152) goto v137;
    v152 = elt(env, 3); /* times */
    v153 = v168;
    v168 = elt(env, 1); /* i */
    return list3(v152, v153, v168);

v137:
    v152 = elt(env, 2); /* minus */
    v153 = elt(env, 1); /* i */
    return list2(v152, v153);

v36:
    v152 = elt(env, 1); /* i */
    return onevalue(v152);
}



/* Code for rungekuttastep */

static Lisp_Object MS_CDECL CC_rungekuttastep(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v72,
                         Lisp_Object v73, Lisp_Object v74,
                         Lisp_Object v36, Lisp_Object v35, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v192, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "rungekuttastep");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rungekuttastep");
#endif
    if (stack >= stacklimit)
    {
        push6(v35,v36,v74,v73,v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v72,v73,v74,v36,v35);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v35;
    stack[-6] = v36;
    stack[-7] = v74;
    stack[-8] = v73;
    stack[-9] = v72;
    stack[-10] = v0;
/* end of prologue */
    stack[-1] = stack[-10];
    stack[0] = stack[-9];
    v193 = stack[-8];
    v192 = stack[-7];
    v192 = cons(v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    fn = elt(env, 1); /* list!-evaluate */
    v192 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    stack[-11] = v192;
    stack[-3] = stack[-10];
    stack[-2] = stack[-9];
    v193 = stack[-8];
    v192 = stack[-5];
    fn = elt(env, 2); /* !:plus */
    stack[-1] = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    stack[0] = stack[-7];
    v193 = stack[-5];
    v192 = stack[-11];
    fn = elt(env, 3); /* scal!*list */
    v192 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    fn = elt(env, 4); /* list!+list */
    v192 = (*qfn2(fn))(qenv(fn), stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    v192 = cons(stack[-1], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    fn = elt(env, 1); /* list!-evaluate */
    v192 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-2], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    stack[-4] = v192;
    stack[-3] = stack[-10];
    stack[-2] = stack[-9];
    v193 = stack[-8];
    v192 = stack[-5];
    fn = elt(env, 2); /* !:plus */
    stack[-1] = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    stack[0] = stack[-7];
    v193 = stack[-5];
    v192 = stack[-4];
    fn = elt(env, 3); /* scal!*list */
    v192 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    fn = elt(env, 4); /* list!+list */
    v192 = (*qfn2(fn))(qenv(fn), stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    v192 = cons(stack[-1], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    fn = elt(env, 1); /* list!-evaluate */
    v192 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-2], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    stack[-1] = v192;
    stack[-2] = stack[-10];
    stack[-3] = stack[-9];
    v193 = stack[-8];
    v192 = stack[-6];
    fn = elt(env, 2); /* !:plus */
    stack[-5] = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    stack[0] = stack[-7];
    v193 = stack[-6];
    v192 = stack[-1];
    fn = elt(env, 3); /* scal!*list */
    v192 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    fn = elt(env, 4); /* list!+list */
    v192 = (*qfn2(fn))(qenv(fn), stack[0], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    v192 = cons(stack[-5], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    fn = elt(env, 1); /* list!-evaluate */
    v192 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[-3], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    stack[0] = v192;
    stack[-2] = stack[-7];
    v193 = stack[-6];
    v192 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 5); /* !:!:quotient */
    stack[-3] = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    stack[-5] = stack[-11];
    v193 = (Lisp_Object)33; /* 2 */
    v192 = stack[-4];
    fn = elt(env, 3); /* scal!*list */
    stack[-4] = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    v193 = (Lisp_Object)33; /* 2 */
    v192 = stack[-1];
    fn = elt(env, 3); /* scal!*list */
    v193 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    v192 = stack[0];
    fn = elt(env, 4); /* list!+list */
    v192 = (*qfn2(fn))(qenv(fn), v193, v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    fn = elt(env, 4); /* list!+list */
    v192 = (*qfn2(fn))(qenv(fn), stack[-4], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    fn = elt(env, 4); /* list!+list */
    v192 = (*qfn2(fn))(qenv(fn), stack[-5], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    fn = elt(env, 3); /* scal!*list */
    v192 = (*qfn2(fn))(qenv(fn), stack[-3], v192);
    nil = C_nil;
    if (exception_pending()) goto v194;
    env = stack[-12];
    {
        Lisp_Object v195 = stack[-2];
        popv(13);
        fn = elt(env, 4); /* list!+list */
        return (*qfn2(fn))(qenv(fn), v195, v192);
    }
/* error exit handlers */
v194:
    popv(13);
    return nil;
}



/* Code for basisvectorp */

static Lisp_Object CC_basisvectorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v18;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for basisvectorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */
    v150 = v18;
    if (!consp(v150)) goto v36;
    v150 = v18;
    v18 = qvalue(elt(env, 2)); /* basisvectorl!* */
    v150 = Lmemq(nil, v150, v18);
    return onevalue(v150);

v36:
    v150 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v150);
}



/* Code for dstr!-to!-alg */

static Lisp_Object MS_CDECL CC_dstrKtoKalg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v72,
                         Lisp_Object v73, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v186, v199;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dstr-to-alg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dstr-to-alg");
#endif
    if (stack >= stacklimit)
    {
        push3(v73,v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v72,v73);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v186 = v73;
    stack[-5] = v72;
    stack[-6] = v0;
/* end of prologue */

v200:
    v112 = stack[-6];
    if (v112 == nil) goto v24;
    v112 = stack[-6];
    v199 = qcar(v112);
    v112 = stack[-5];
    fn = elt(env, 2); /* dvertex!-to!-projector */
    v112 = (*qfnn(fn))(qenv(fn), 3, v199, v112, v186);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    v199 = (Lisp_Object)1; /* 0 */
    v186 = v112;
    if (v199 == v186) goto v164;
    v186 = v112;
    v186 = qcdr(v186);
    v186 = qcar(v186);
    if (v186 == nil) goto v12;
    v186 = v112;
    stack[-7] = qcar(v186);
    v112 = qcdr(v112);
    stack[-4] = v112;
    v112 = stack[-4];
    if (v112 == nil) goto v86;
    v112 = stack[-4];
    v112 = qcar(v112);
    v186 = v112;
    stack[0] = qcar(v186);
    v186 = stack[-6];
    v199 = qcdr(v186);
    v186 = stack[-5];
    v112 = qcdr(v112);
    v112 = CC_dstrKtoKalg(env, 3, v199, v186, v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    fn = elt(env, 3); /* cvitimes2 */
    v112 = (*qfn2(fn))(qenv(fn), stack[0], v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    v112 = ncons(v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    stack[-2] = v112;
    stack[-3] = v112;
    goto v76;

v76:
    v112 = stack[-4];
    v112 = qcdr(v112);
    stack[-4] = v112;
    v112 = stack[-4];
    if (v112 == nil) goto v201;
    stack[-1] = stack[-2];
    v112 = stack[-4];
    v112 = qcar(v112);
    v186 = v112;
    stack[0] = qcar(v186);
    v186 = stack[-6];
    v199 = qcdr(v186);
    v186 = stack[-5];
    v112 = qcdr(v112);
    v112 = CC_dstrKtoKalg(env, 3, v199, v186, v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    fn = elt(env, 3); /* cvitimes2 */
    v112 = (*qfn2(fn))(qenv(fn), stack[0], v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    v112 = ncons(v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    v112 = Lrplacd(nil, stack[-1], v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    v112 = stack[-2];
    v112 = qcdr(v112);
    stack[-2] = v112;
    goto v76;

v201:
    v112 = stack[-3];
    goto v75;

v75:
    fn = elt(env, 4); /* consplus */
    v112 = (*qfn1(fn))(qenv(fn), v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    {
        Lisp_Object v193 = stack[-7];
        popv(9);
        fn = elt(env, 3); /* cvitimes2 */
        return (*qfn2(fn))(qenv(fn), v193, v112);
    }

v86:
    v112 = qvalue(elt(env, 1)); /* nil */
    goto v75;

v12:
    v199 = (Lisp_Object)17; /* 1 */
    v186 = v112;
    v186 = qcar(v186);
    if (v199 == v186) goto v140;
    v186 = v112;
    stack[0] = qcar(v186);
    v186 = stack[-6];
    v199 = qcdr(v186);
    v186 = stack[-5];
    v112 = qcdr(v112);
    v112 = qcdr(v112);
    v112 = CC_dstrKtoKalg(env, 3, v199, v186, v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    {
        Lisp_Object v37 = stack[0];
        popv(9);
        fn = elt(env, 3); /* cvitimes2 */
        return (*qfn2(fn))(qenv(fn), v37, v112);
    }

v140:
    v186 = stack[-6];
    v199 = qcdr(v186);
    v186 = stack[-5];
    v112 = qcdr(v112);
    v112 = qcdr(v112);
    stack[-6] = v199;
    stack[-5] = v186;
    v186 = v112;
    goto v200;

v164:
    v112 = (Lisp_Object)1; /* 0 */
    { popv(9); return onevalue(v112); }

v24:
    v112 = stack[-5];
    fn = elt(env, 5); /* mk!-coeff1 */
    v112 = (*qfn2(fn))(qenv(fn), v186, v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    v112 = ncons(v112);
    nil = C_nil;
    if (exception_pending()) goto v192;
    env = stack[-8];
    {
        popv(9);
        fn = elt(env, 6); /* consrecip */
        return (*qfn1(fn))(qenv(fn), v112);
    }
/* error exit handlers */
v192:
    popv(9);
    return nil;
}



/* Code for simpfourier */

static Lisp_Object CC_simpfourier(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v14, v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpfourier");
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
    v160 = stack[0];
    v14 = Llength(nil, v160);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    v160 = (Lisp_Object)17; /* 1 */
    if (v14 == v160) goto v35;
    v15 = elt(env, 1); /* fourier */
    v14 = (Lisp_Object)17; /* 1 */
    v160 = elt(env, 2); /* "Argument should be single expression" */
    fn = elt(env, 3); /* rerror */
    v160 = (*qfnn(fn))(qenv(fn), 3, v15, v14, v160);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    goto v35;

v35:
    v160 = stack[0];
    v160 = qcar(v160);
    fn = elt(env, 4); /* simp!* */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    fn = elt(env, 5); /* prepsq */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 6); /* simpfourier1 */
        return (*qfn1(fn))(qenv(fn), v160);
    }
/* error exit handlers */
v16:
    popv(2);
    return nil;
}



/* Code for invlex */

static Lisp_Object CC_invlex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v231, v232, v233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for invlex");
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
    stack[0] = v0;
/* end of prologue */
    v231 = stack[0];
    v231 = qcar(v231);
    fn = elt(env, 12); /* reval */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    stack[0] = v231;
    v232 = stack[0];
    v231 = elt(env, 1); /* list */
    if (!consp(v232)) goto v19;
    v232 = qcar(v232);
    if (!(v232 == v231)) goto v19;

v20:
    v231 = stack[0];
    v231 = qcdr(v231);
    stack[-3] = v231;
    v231 = stack[-3];
    if (v231 == nil) goto v15;
    v231 = stack[-3];
    v231 = qcar(v231);
    fn = elt(env, 12); /* reval */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    v233 = v231;
    v232 = elt(env, 4); /* equal */
    if (!consp(v233)) goto v153;
    v233 = qcar(v233);
    if (!(v233 == v232)) goto v153;
    v233 = elt(env, 5); /* difference */
    v232 = v231;
    v232 = qcdr(v232);
    v232 = qcar(v232);
    v231 = qcdr(v231);
    v231 = qcdr(v231);
    v231 = qcar(v231);
    v231 = list3(v233, v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    fn = elt(env, 12); /* reval */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    goto v153;

v153:
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    stack[-1] = v231;
    stack[-2] = v231;
    goto v149;

v149:
    v231 = stack[-3];
    v231 = qcdr(v231);
    stack[-3] = v231;
    v231 = stack[-3];
    if (v231 == nil) goto v128;
    stack[0] = stack[-1];
    v231 = stack[-3];
    v231 = qcar(v231);
    fn = elt(env, 12); /* reval */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    v233 = v231;
    v232 = elt(env, 4); /* equal */
    if (!consp(v233)) goto v235;
    v233 = qcar(v233);
    if (!(v233 == v232)) goto v235;
    v233 = elt(env, 5); /* difference */
    v232 = v231;
    v232 = qcdr(v232);
    v232 = qcar(v232);
    v231 = qcdr(v231);
    v231 = qcdr(v231);
    v231 = qcar(v231);
    v231 = list3(v233, v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    fn = elt(env, 12); /* reval */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    goto v235;

v235:
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    v231 = Lrplacd(nil, stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    v231 = stack[-1];
    v231 = qcdr(v231);
    stack[-1] = v231;
    goto v149;

v128:
    v231 = stack[-2];
    goto v148;

v148:
    stack[0] = v231;
    v231 = qvalue(elt(env, 6)); /* invsysvars!* */
    if (!(v231 == nil)) goto v236;
    v231 = stack[0];
    fn = elt(env, 13); /* gvarlis */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    goto v236;

v236:
    stack[-10] = v231;
    v232 = elt(env, 1); /* list */
    v231 = stack[0];
    stack[0] = cons(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    v232 = elt(env, 1); /* list */
    v231 = stack[-10];
    v231 = cons(v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    fn = elt(env, 14); /* readsys */
    v231 = (*qfn2(fn))(qenv(fn), stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    fn = elt(env, 15); /* invlex!* */
    v231 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    v231 = elt(env, 7); /* lex */
    stack[-9] = qvalue(elt(env, 8)); /* ordering */
    qvalue(elt(env, 8)) = v231; /* ordering */
    v231 = qvalue(elt(env, 9)); /* gg */
    stack[-8] = v231;
    v231 = stack[-8];
    if (v231 == nil) goto v117;
    v231 = stack[-8];
    v231 = qcar(v231);
    stack[-4] = elt(env, 10); /* plus */
    v232 = qvalue(elt(env, 11)); /* gv */
    v231 = qcar(v231);
    v231 = *(Lisp_Object *)((char *)v232 + (CELL-TAG_VECTOR) + ((int32_t)v231/(16/CELL)));
    stack[-3] = v231;
    v231 = stack[-3];
    if (v231 == nil) goto v41;
    v231 = stack[-3];
    v231 = qcar(v231);
    v232 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = stack[-10];
    fn = elt(env, 16); /* !*di2q */
    v231 = (*qfn2(fn))(qenv(fn), v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    fn = elt(env, 17); /* prepsq */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-1] = v231;
    stack[-2] = v231;
    goto v238;

v238:
    v231 = stack[-3];
    v231 = qcdr(v231);
    stack[-3] = v231;
    v231 = stack[-3];
    if (v231 == nil) goto v195;
    stack[0] = stack[-1];
    v231 = stack[-3];
    v231 = qcar(v231);
    v232 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = stack[-10];
    fn = elt(env, 16); /* !*di2q */
    v231 = (*qfn2(fn))(qenv(fn), v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    fn = elt(env, 17); /* prepsq */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = Lrplacd(nil, stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = stack[-1];
    v231 = qcdr(v231);
    stack[-1] = v231;
    goto v238;

v195:
    v231 = stack[-2];
    goto v115;

v115:
    v231 = cons(stack[-4], v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-6] = v231;
    stack[-7] = v231;
    goto v48;

v48:
    v231 = stack[-8];
    v231 = qcdr(v231);
    stack[-8] = v231;
    v231 = stack[-8];
    if (v231 == nil) goto v239;
    stack[-5] = stack[-6];
    v231 = stack[-8];
    v231 = qcar(v231);
    stack[-4] = elt(env, 10); /* plus */
    v232 = qvalue(elt(env, 11)); /* gv */
    v231 = qcar(v231);
    v231 = *(Lisp_Object *)((char *)v232 + (CELL-TAG_VECTOR) + ((int32_t)v231/(16/CELL)));
    stack[-3] = v231;
    v231 = stack[-3];
    if (v231 == nil) goto v240;
    v231 = stack[-3];
    v231 = qcar(v231);
    v232 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = stack[-10];
    fn = elt(env, 16); /* !*di2q */
    v231 = (*qfn2(fn))(qenv(fn), v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    fn = elt(env, 17); /* prepsq */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    stack[-1] = v231;
    stack[-2] = v231;
    goto v241;

v241:
    v231 = stack[-3];
    v231 = qcdr(v231);
    stack[-3] = v231;
    v231 = stack[-3];
    if (v231 == nil) goto v242;
    stack[0] = stack[-1];
    v231 = stack[-3];
    v231 = qcar(v231);
    v232 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = stack[-10];
    fn = elt(env, 16); /* !*di2q */
    v231 = (*qfn2(fn))(qenv(fn), v232, v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    fn = elt(env, 17); /* prepsq */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = Lrplacd(nil, stack[0], v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = stack[-1];
    v231 = qcdr(v231);
    stack[-1] = v231;
    goto v241;

v242:
    v231 = stack[-2];
    goto v243;

v243:
    v231 = cons(stack[-4], v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = ncons(v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = Lrplacd(nil, stack[-5], v231);
    nil = C_nil;
    if (exception_pending()) goto v237;
    env = stack[-11];
    v231 = stack[-6];
    v231 = qcdr(v231);
    stack[-6] = v231;
    goto v48;

v240:
    v231 = qvalue(elt(env, 3)); /* nil */
    goto v243;

v239:
    v231 = stack[-7];
    goto v47;

v47:
    qvalue(elt(env, 8)) = stack[-9]; /* ordering */
    v232 = elt(env, 1); /* list */
    popv(12);
    return cons(v232, v231);

v41:
    v231 = qvalue(elt(env, 3)); /* nil */
    goto v115;

v117:
    v231 = qvalue(elt(env, 3)); /* nil */
    goto v47;

v15:
    v231 = qvalue(elt(env, 3)); /* nil */
    goto v148;

v19:
    v231 = elt(env, 2); /* "Argument to invlex not a list" */
    fn = elt(env, 18); /* rederr */
    v231 = (*qfn1(fn))(qenv(fn), v231);
    nil = C_nil;
    if (exception_pending()) goto v234;
    env = stack[-11];
    goto v20;
/* error exit handlers */
v237:
    env = stack[-11];
    qvalue(elt(env, 8)) = stack[-9]; /* ordering */
    popv(12);
    return nil;
v234:
    popv(12);
    return nil;
}



/* Code for num_ids_range */

static Lisp_Object CC_num_ids_range(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v53, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for num_ids_range");
#endif
    if (stack >= stacklimit)
    {
        push2(v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v72;
    v53 = v0;
/* end of prologue */
    v244 = qvalue(elt(env, 1)); /* !*onespace */
    if (v244 == nil) goto v33;
    v54 = v53;
    v53 = qvalue(elt(env, 2)); /* dimex!* */
    v244 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 9); /* out_of_range */
    v244 = (*qfnn(fn))(qenv(fn), 3, v54, v53, v244);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    if (v244 == nil) goto v15;
    v54 = elt(env, 4); /* cantens */
    v53 = (Lisp_Object)49; /* 3 */
    v244 = elt(env, 5); /* "numeric indices out of range" */
    {
        popv(4);
        fn = elt(env, 10); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v54, v53, v244);
    }

v15:
    v244 = qvalue(elt(env, 3)); /* nil */
    { popv(4); return onevalue(v244); }

v33:
    v244 = qvalue(elt(env, 6)); /* numindxl!* */
    if (v244 == nil) goto v153;
    v244 = v53;
    fn = elt(env, 11); /* flattens1 */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    fn = elt(env, 12); /* extract_numid */
    stack[0] = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v54 = qvalue(elt(env, 6)); /* numindxl!* */
    v53 = stack[-1];
    v244 = elt(env, 7); /* belong_to_space */
    v244 = get(v53, v244);
    env = stack[-3];
    v244 = Lsubla(nil, v54, v244);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v53 = stack[0];
    fn = elt(env, 13); /* lst_belong_interval */
    v244 = (*qfn2(fn))(qenv(fn), v53, v244);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    if (v244 == nil) goto v122;
    v244 = nil;
    { popv(4); return onevalue(v244); }

v122:
    v54 = elt(env, 4); /* cantens */
    v53 = (Lisp_Object)49; /* 3 */
    v244 = elt(env, 8); /* "numeric indices do not belong to (sub)-space" 
*/
    {
        popv(4);
        fn = elt(env, 10); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v54, v53, v244);
    }

v153:
    stack[-2] = v53;
    v53 = stack[-1];
    v244 = elt(env, 7); /* belong_to_space */
    v244 = get(v53, v244);
    env = stack[-3];
    fn = elt(env, 14); /* get_dim_space */
    stack[0] = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v53 = stack[-1];
    v244 = elt(env, 7); /* belong_to_space */
    v244 = get(v53, v244);
    env = stack[-3];
    fn = elt(env, 15); /* get_sign_space */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    fn = elt(env, 9); /* out_of_range */
    v244 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v244);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    if (v244 == nil) goto v56;
    v54 = elt(env, 4); /* cantens */
    v53 = (Lisp_Object)49; /* 3 */
    v244 = elt(env, 5); /* "numeric indices out of range" */
    {
        popv(4);
        fn = elt(env, 10); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v54, v53, v244);
    }

v56:
    v244 = qvalue(elt(env, 3)); /* nil */
    { popv(4); return onevalue(v244); }
/* error exit handlers */
v22:
    popv(4);
    return nil;
}



/* Code for pst_equitable1 */

static Lisp_Object CC_pst_equitable1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v259, v260, v261;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_equitable1");
#endif
    if (stack >= stacklimit)
    {
        push2(v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = v72;
    stack[-9] = v0;
/* end of prologue */
    v259 = stack[-8];
    if (v259 == nil) goto v165;
    v259 = stack[-9];
    stack[-3] = v259;
    v259 = stack[-9];
    v259 = Llength(nil, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-2] = v259;
    v259 = stack[-8];
    v259 = qcdr(v259);
    fn = elt(env, 2); /* upbve */
    v260 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = stack[-2];
    v259 = plus2(v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = sub1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = Lmkvect(nil, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-10] = v259;
    v259 = (Lisp_Object)17; /* 1 */
    stack[-4] = v259;
    goto v170;

v170:
    v259 = stack[-8];
    v259 = qcdr(v259);
    fn = elt(env, 2); /* upbve */
    v260 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = stack[-4];
    v259 = difference2(v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = Lminusp(nil, v259);
    env = stack[-11];
    if (v259 == nil) goto v146;
    v259 = stack[-8];
    v259 = qcar(v259);
    stack[-7] = v259;
    v259 = stack[-8];
    v259 = qcdr(v259);
    fn = elt(env, 2); /* upbve */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = add1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-2] = v259;
    goto v124;

v124:
    v259 = stack[-10];
    fn = elt(env, 2); /* upbve */
    v260 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = stack[-2];
    v259 = difference2(v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = Lminusp(nil, v259);
    env = stack[-11];
    if (v259 == nil) goto v263;
    v259 = stack[-7];
    fn = elt(env, 3); /* fullcopy */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-5] = v259;
    v259 = stack[-5];
    v259 = Llength(nil, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-2] = v259;
    v259 = stack[-10];
    fn = elt(env, 2); /* upbve */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[0] = v259;
    goto v264;

v264:
    v259 = stack[-7];
    if (v259 == nil) goto v265;
    v260 = stack[-2];
    v259 = stack[0];
    v259 = (Lisp_Object)lessp2(v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    v259 = v259 ? lisp_true : nil;
    env = stack[-11];
    if (v259 == nil) goto v265;
    v259 = stack[-7];
    v259 = qcar(v259);
    stack[-6] = v259;
    v259 = stack[-7];
    v259 = qcdr(v259);
    stack[-7] = v259;
    v259 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v259;
    v259 = (Lisp_Object)1; /* 0 */
    stack[-2] = v259;
    goto v114;

v114:
    v259 = stack[-5];
    if (v259 == nil) goto v118;
    v259 = stack[-5];
    v259 = qcar(v259);
    v260 = v259;
    v259 = stack[-5];
    v259 = qcdr(v259);
    stack[-5] = v259;
    v259 = v260;
    v259 = qcdr(v259);
    if (v259 == nil) goto v199;
    v261 = v260;
    v260 = stack[-6];
    v259 = stack[-10];
    fn = elt(env, 4); /* pst_partition */
    v259 = (*qfnn(fn))(qenv(fn), 3, v261, v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    goto v221;

v221:
    stack[-3] = v259;
    v259 = stack[-3];
    v259 = Llength(nil, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-1] = v259;
    v260 = stack[-4];
    v259 = stack[-3];
    v259 = Lappend(nil, v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-4] = v259;
    v260 = stack[-2];
    v259 = stack[-1];
    v259 = plus2(v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-2] = v259;
    v260 = stack[-1];
    v259 = (Lisp_Object)33; /* 2 */
    v259 = (Lisp_Object)geq2(v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    v259 = v259 ? lisp_true : nil;
    env = stack[-11];
    if (v259 == nil) goto v114;
    v259 = stack[-3];
    v260 = qcdr(v259);
    v259 = stack[-7];
    v259 = Lappend(nil, v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-7] = v259;
    goto v114;

v199:
    v259 = v260;
    v259 = ncons(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    goto v221;

v118:
    v259 = stack[-4];
    stack[-5] = v259;
    goto v264;

v265:
    stack[0] = stack[-5];
    v259 = stack[-9];
    v259 = Llength(nil, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = add1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    fn = elt(env, 5); /* pnth */
    v259 = (*qfn2(fn))(qenv(fn), stack[0], v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-4] = v259;
    v259 = stack[-8];
    fn = elt(env, 6); /* pst_termnodep */
    v259 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    if (!(v259 == nil)) goto v266;
    v259 = (Lisp_Object)17; /* 1 */
    stack[-3] = v259;
    goto v267;

v267:
    v259 = stack[-8];
    v259 = qcdr(v259);
    fn = elt(env, 2); /* upbve */
    v260 = (*qfn1(fn))(qenv(fn), v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = stack[-3];
    v259 = difference2(v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = Lminusp(nil, v259);
    env = stack[-11];
    if (!(v259 == nil)) goto v266;
    v259 = stack[-8];
    stack[0] = qcdr(v259);
    v259 = stack[-3];
    v259 = sub1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v259/(16/CELL)));
    stack[-5] = v259;
    v259 = stack[-8];
    stack[-2] = qcdr(v259);
    v259 = stack[-3];
    stack[-1] = sub1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = stack[-5];
    stack[0] = qcar(v259);
    v260 = stack[-9];
    v259 = stack[-5];
    v259 = qcdr(v259);
    v259 = CC_pst_equitable1(env, v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = cons(stack[0], v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v259;
    v259 = stack[-3];
    v259 = add1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-3] = v259;
    goto v267;

v266:
    v260 = stack[-4];
    v259 = stack[-8];
    v259 = qcdr(v259);
    popv(12);
    return cons(v260, v259);

v263:
    stack[-1] = stack[-10];
    v259 = stack[-2];
    stack[0] = sub1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = stack[-3];
    v259 = qcar(v259);
    v259 = ncons(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v259;
    v259 = stack[-3];
    v259 = qcdr(v259);
    stack[-3] = v259;
    v259 = stack[-2];
    v260 = ncons(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = stack[-7];
    v259 = cons(v260, v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-7] = v259;
    v259 = stack[-2];
    v259 = add1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-2] = v259;
    goto v124;

v146:
    stack[-2] = stack[-10];
    v259 = stack[-4];
    stack[-1] = sub1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = stack[-8];
    stack[0] = qcdr(v259);
    v259 = stack[-4];
    v259 = sub1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    v259 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v259/(16/CELL)));
    v259 = qcar(v259);
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[-1]/(16/CELL))) = v259;
    v259 = stack[-4];
    v259 = add1(v259);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-11];
    stack[-4] = v259;
    goto v170;

v165:
    v259 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v259); }
/* error exit handlers */
v262:
    popv(12);
    return nil;
}



/* Code for ratleqp */

static Lisp_Object CC_ratleqp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratleqp");
#endif
    if (stack >= stacklimit)
    {
        push2(v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v72;
    v17 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ratdif */
    v18 = (*qfn2(fn))(qenv(fn), v17, v18);
    errexit();
    v17 = qcar(v18);
    v18 = (Lisp_Object)1; /* 0 */
        return Lleq(nil, v17, v18);
}



/* Code for gcdlist1 */

static Lisp_Object CC_gcdlist1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v281, v282, v283;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdlist1");
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
    stack[0] = v0;
/* end of prologue */
    stack[-6] = qvalue(elt(env, 1)); /* reduction!-count */
    qvalue(elt(env, 1)) = nil; /* reduction!-count */
    v281 = stack[0];
    v281 = qcar(v281);
    v281 = qcdr(v281);
    stack[-4] = v281;
    stack[-2] = v281;
    v281 = stack[0];
    v281 = qcdr(v281);
    stack[-3] = v281;
    goto v139;

v139:
    v281 = stack[-3];
    if (v281 == nil) goto v63;
    v281 = stack[-3];
    v281 = qcar(v281);
    stack[-1] = v281;
    v282 = stack[-2];
    v281 = stack[-1];
    v281 = qcdr(v281);
    fn = elt(env, 4); /* vunion */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-2] = v281;
    v282 = stack[-4];
    v281 = stack[-1];
    v281 = qcdr(v281);
    fn = elt(env, 5); /* vintersection */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-4] = v281;
    v281 = stack[-3];
    v281 = qcdr(v281);
    stack[-3] = v281;
    goto v139;

v63:
    v281 = stack[-4];
    if (v281 == nil) goto v285;
    v281 = stack[-4];
    stack[-1] = v281;
    goto v58;

v58:
    v281 = stack[-1];
    if (v281 == nil) goto v162;
    v281 = stack[-1];
    v281 = qcar(v281);
    v282 = v281;
    v281 = stack[-2];
    fn = elt(env, 6); /* vdelete */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-2] = v281;
    v281 = stack[-1];
    v281 = qcdr(v281);
    stack[-1] = v281;
    goto v58;

v162:
    v282 = stack[-4];
    v281 = elt(env, 3); /* lesspcdr */
    fn = elt(env, 7); /* sort */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-4] = v281;
    v281 = stack[-4];
    v281 = qcar(v281);
    v282 = qcdr(v281);
    v281 = (Lisp_Object)17; /* 1 */
    if (v282 == v281) goto v190;
    v281 = stack[-2];
    if (v281 == nil) goto v45;
    v282 = stack[-2];
    v281 = stack[-4];
    v281 = Lappend(nil, v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 8); /* mapcarcar */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 9); /* setkorder */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-5] = v281;
    v281 = qvalue(elt(env, 2)); /* nil */
    stack[-4] = v281;
    v281 = stack[0];
    stack[-1] = v281;
    goto v227;

v227:
    v281 = stack[-1];
    if (v281 == nil) goto v40;
    v281 = stack[-1];
    v281 = qcar(v281);
    v281 = qcar(v281);
    fn = elt(env, 10); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = stack[-2];
    fn = elt(env, 8); /* mapcarcar */
    v282 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = stack[-4];
    fn = elt(env, 11); /* split!-wrt!-variables */
    v281 = (*qfnn(fn))(qenv(fn), 3, stack[0], v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-4] = v281;
    v281 = stack[-1];
    v281 = qcdr(v281);
    stack[-1] = v281;
    goto v227;

v40:
    v281 = stack[-5];
    fn = elt(env, 9); /* setkorder */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = stack[-4];
    stack[-5] = v281;
    v281 = stack[-5];
    if (v281 == nil) goto v94;
    v281 = stack[-5];
    v281 = qcar(v281);
    stack[-1] = v281;
    v281 = stack[-1];
    fn = elt(env, 10); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v282 = stack[-1];
    v281 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 12); /* total!-degree!-in!-powers */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = cons(stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-3] = v281;
    stack[-4] = v281;
    goto v286;

v286:
    v281 = stack[-5];
    v281 = qcdr(v281);
    stack[-5] = v281;
    v281 = stack[-5];
    if (v281 == nil) goto v287;
    stack[-2] = stack[-3];
    v281 = stack[-5];
    v281 = qcar(v281);
    stack[-1] = v281;
    v281 = stack[-1];
    fn = elt(env, 10); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v282 = stack[-1];
    v281 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 12); /* total!-degree!-in!-powers */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = cons(stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = Lrplacd(nil, stack[-2], v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = stack[-3];
    v281 = qcdr(v281);
    stack[-3] = v281;
    goto v286;

v287:
    v281 = stack[-4];
    goto v288;

v288:
    v281 = CC_gcdlist1(env, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    goto v46;

v46:
    qvalue(elt(env, 1)) = stack[-6]; /* reduction!-count */
    { popv(8); return onevalue(v281); }

v94:
    v281 = qvalue(elt(env, 2)); /* nil */
    goto v288;

v45:
    v282 = stack[0];
    v281 = stack[-4];
    fn = elt(env, 13); /* gcdlist2 */
    v281 = (*qfn2(fn))(qenv(fn), v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    goto v46;

v190:
    v282 = stack[-4];
    v281 = stack[-2];
    v281 = Lappend(nil, v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    fn = elt(env, 8); /* mapcarcar */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-5] = v281;
    v281 = stack[-5];
    fn = elt(env, 9); /* setkorder */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-4] = v281;
    v281 = stack[0];
    stack[-3] = v281;
    v281 = stack[-3];
    if (v281 == nil) goto v174;
    v281 = stack[-3];
    v281 = qcar(v281);
    v281 = qcar(v281);
    fn = elt(env, 10); /* reorder */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[-1] = v281;
    stack[-2] = v281;
    goto v70;

v70:
    v281 = stack[-3];
    v281 = qcdr(v281);
    stack[-3] = v281;
    v281 = stack[-3];
    if (v281 == nil) goto v32;
    stack[0] = stack[-1];
    v281 = stack[-3];
    v281 = qcar(v281);
    v281 = qcar(v281);
    fn = elt(env, 10); /* reorder */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = ncons(v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = Lrplacd(nil, stack[0], v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = stack[-1];
    v281 = qcdr(v281);
    stack[-1] = v281;
    goto v70;

v32:
    v281 = stack[-2];
    v283 = v281;
    goto v121;

v121:
    v282 = qvalue(elt(env, 2)); /* nil */
    v281 = stack[-5];
    fn = elt(env, 14); /* gcdlist3 */
    v281 = (*qfnn(fn))(qenv(fn), 3, v283, v282, v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    stack[0] = v281;
    v281 = stack[-4];
    fn = elt(env, 9); /* setkorder */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    v281 = stack[0];
    fn = elt(env, 10); /* reorder */
    v281 = (*qfn1(fn))(qenv(fn), v281);
    nil = C_nil;
    if (exception_pending()) goto v284;
    env = stack[-7];
    goto v46;

v174:
    v281 = qvalue(elt(env, 2)); /* nil */
    v283 = v281;
    goto v121;

v285:
    v281 = (Lisp_Object)17; /* 1 */
    goto v46;
/* error exit handlers */
v284:
    env = stack[-7];
    qvalue(elt(env, 1)) = stack[-6]; /* reduction!-count */
    popv(8);
    return nil;
}



/* Code for mchkminus */

static Lisp_Object CC_mchkminus(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v219, v136;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchkminus");
#endif
    if (stack >= stacklimit)
    {
        push2(v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v72;
    stack[-1] = v0;
/* end of prologue */
    v201 = stack[0];
    v219 = qcar(v201);
    v201 = elt(env, 1); /* (times quotient) */
    v201 = Lmemq(nil, v219, v201);
    if (v201 == nil) goto v35;
    v201 = stack[-1];
    if (!consp(v201)) goto v141;
    v201 = stack[-1];
    v219 = qcar(v201);
    v201 = stack[0];
    v201 = qcar(v201);
    if (!(v219 == v201)) goto v141;
    v201 = stack[-1];
    v201 = qcdr(v201);
    v201 = qcar(v201);
    if (is_number(v201)) goto v76;
    v201 = stack[-1];
    v201 = qcdr(v201);
    v201 = qcar(v201);
    v201 = Lconsp(nil, v201);
    env = stack[-2];
    if (v201 == nil) goto v235;
    v201 = stack[-1];
    v201 = qcdr(v201);
    v201 = qcar(v201);
    v219 = qcar(v201);
    v201 = elt(env, 6); /* dname */
    v201 = get(v219, v201);
    env = stack[-2];
    if (!(v201 == nil)) goto v76;

v235:
    v201 = stack[0];
    v219 = qcar(v201);
    v201 = elt(env, 7); /* quotient */
    if (v219 == v201) goto v76;
    v219 = elt(env, 8); /* (minus 1) */
    v201 = stack[-1];
    v201 = qcdr(v201);
    v136 = cons(v219, v201);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    v201 = stack[0];
    v219 = qcdr(v201);
    v201 = elt(env, 3); /* times */
    {
        popv(3);
        fn = elt(env, 9); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v136, v219, v201);
    }

v76:
    v219 = elt(env, 5); /* minus */
    v201 = stack[-1];
    v201 = qcdr(v201);
    v201 = qcar(v201);
    v219 = list2(v219, v201);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    v201 = stack[-1];
    v201 = qcdr(v201);
    v201 = qcdr(v201);
    v136 = cons(v219, v201);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    v201 = stack[0];
    v219 = qcdr(v201);
    v201 = stack[0];
    v201 = qcar(v201);
    {
        popv(3);
        fn = elt(env, 9); /* mcharg */
        return (*qfnn(fn))(qenv(fn), 3, v136, v219, v201);
    }

v141:
    v201 = stack[0];
    v219 = qcar(v201);
    v201 = elt(env, 3); /* times */
    if (v219 == v201) goto v152;
    v219 = elt(env, 5); /* minus */
    v201 = stack[-1];
    v219 = list2(v219, v201);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    v201 = stack[0];
    {
        popv(3);
        fn = elt(env, 10); /* mchkopt */
        return (*qfn2(fn))(qenv(fn), v219, v201);
    }

v152:
    v136 = stack[-1];
    v219 = stack[0];
    v201 = elt(env, 4); /* ((minus 1) (minus 1)) */
    {
        popv(3);
        fn = elt(env, 11); /* mchkopt1 */
        return (*qfnn(fn))(qenv(fn), 3, v136, v219, v201);
    }

v35:
    v201 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v201); }
/* error exit handlers */
v47:
    popv(3);
    return nil;
}



/* Code for rl_susibin */

static Lisp_Object CC_rl_susibin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v72)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v150, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_susibin");
#endif
    if (stack >= stacklimit)
    {
        push2(v72,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v72);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v150 = v72;
    v18 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_susibin!* */
    v150 = list2(v18, v150);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-1];
    {
        Lisp_Object v180 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v180, v150);
    }
/* error exit handlers */
v165:
    popv(2);
    return nil;
}



/* Code for subeval0 */

static Lisp_Object CC_subeval0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v297, v271, v272;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subeval0");
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
    stack[-5] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v49;

v49:
    v297 = stack[-4];
    v297 = qcdr(v297);
    if (v297 == nil) goto v46;
    v297 = stack[-4];
    v271 = qcar(v297);
    v297 = elt(env, 2); /* equal */
    if (!consp(v271)) goto v160;
    v271 = qcar(v271);
    if (!(v271 == v297)) goto v160;
    v297 = stack[-4];
    v297 = qcar(v297);
    v297 = qcdr(v297);
    stack[0] = qcar(v297);
    v297 = stack[-4];
    v297 = qcar(v297);
    v297 = qcdr(v297);
    v297 = qcdr(v297);
    v297 = qcar(v297);
    fn = elt(env, 9); /* reval */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    stack[-3] = v297;
    if (equal(stack[0], v297)) goto v18;
    v297 = stack[-4];
    v297 = qcar(v297);
    v272 = qcar(v297);
    v297 = stack[-4];
    v297 = qcar(v297);
    v297 = qcdr(v297);
    v271 = qcar(v297);
    v297 = stack[-3];
    v271 = list3(v272, v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    v297 = stack[-5];
    v297 = cons(v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    stack[-5] = v297;
    goto v18;

v18:
    v297 = stack[-4];
    v297 = qcdr(v297);
    stack[-4] = v297;
    goto v49;

v160:
    v297 = stack[-4];
    v271 = qcar(v297);
    v297 = stack[-5];
    v297 = cons(v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    stack[-5] = v297;
    goto v18;

v46:
    v297 = stack[-5];
    if (v297 == nil) goto v154;
    v297 = stack[-5];
    v271 = Lnreverse(nil, v297);
    env = stack[-6];
    v297 = stack[-4];
    v297 = Lnconc(nil, v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    stack[-4] = v297;
    v271 = stack[-4];
    v297 = qvalue(elt(env, 3)); /* sublist!* */
    v297 = Lmember(nil, v271, v297);
    if (v297 == nil) goto v119;
    v271 = elt(env, 4); /* sub */
    v297 = stack[-4];
    v271 = cons(v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    v297 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* mksp */
    v271 = (*qfn2(fn))(qenv(fn), v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    v297 = (Lisp_Object)17; /* 1 */
    v297 = cons(v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    v271 = ncons(v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    v297 = (Lisp_Object)17; /* 1 */
    v297 = cons(v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 11); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v297);
    }

v119:
    v271 = stack[-4];
    v297 = qvalue(elt(env, 3)); /* sublist!* */
    v297 = cons(v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    qvalue(elt(env, 3)) = v297; /* sublist!* */
    v297 = stack[-4];
    if (v297 == nil) goto v51;
    v297 = stack[-4];
    v297 = qcdr(v297);
    if (!(v297 == nil)) goto v181;

v51:
    v297 = elt(env, 5); /* "SUB requires at least 2 arguments" */
    fn = elt(env, 12); /* rederr */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    goto v181;

v181:
    v297 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 6)); /* !*evallhseqp */
    qvalue(elt(env, 6)) = v297; /* !*evallhseqp */
    goto v118;

v118:
    v297 = stack[-4];
    v297 = qcdr(v297);
    if (v297 == nil) goto v117;
    v297 = stack[-4];
    v297 = qcar(v297);
    fn = elt(env, 9); /* reval */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-6];
    stack[-5] = v297;
    v297 = stack[-5];
    fn = elt(env, 13); /* getrtype */
    v271 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-6];
    v297 = elt(env, 7); /* list */
    if (v271 == v297) goto v40;
    v297 = stack[-5];
    fn = elt(env, 14); /* eqexpr */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-6];
    if (!(v297 == nil)) goto v103;
    v297 = stack[-4];
    v271 = qcar(v297);
    v297 = qvalue(elt(env, 8)); /* t */
    fn = elt(env, 15); /* errpri2 */
    v297 = (*qfn2(fn))(qenv(fn), v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-6];
    goto v103;

v103:
    v297 = stack[-5];
    v297 = qcdr(v297);
    v297 = qcar(v297);
    stack[-3] = v297;
    v297 = stack[-3];
    fn = elt(env, 13); /* getrtype */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-6];
    if (!(v297 == nil)) goto v64;
    v297 = stack[-3];
    fn = elt(env, 16); /* !*a2kwoweight */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-6];
    stack[-3] = v297;
    goto v64;

v64:
    v297 = stack[-5];
    v297 = qcdr(v297);
    v297 = qcdr(v297);
    v297 = qcar(v297);
    fn = elt(env, 13); /* getrtype */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-6];
    if (v297 == nil) goto v275;
    v272 = stack[-3];
    v297 = stack[-5];
    v297 = qcdr(v297);
    v297 = qcdr(v297);
    v271 = qcar(v297);
    v297 = stack[-1];
    v297 = acons(v272, v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-6];
    stack[-1] = v297;
    goto v258;

v258:
    v297 = stack[-4];
    v297 = qcdr(v297);
    stack[-4] = v297;
    goto v118;

v275:
    v272 = stack[-3];
    v297 = stack[-5];
    v297 = qcdr(v297);
    v297 = qcdr(v297);
    v271 = qcar(v297);
    v297 = stack[-2];
    v297 = acons(v272, v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-6];
    stack[-2] = v297;
    goto v258;

v40:
    v297 = stack[-5];
    v271 = qcdr(v297);
    v297 = stack[-4];
    v297 = qcdr(v297);
    v297 = Lappend(nil, v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-6];
    stack[-4] = v297;
    goto v118;

v117:
    qvalue(elt(env, 6)) = stack[0]; /* !*evallhseqp */
    v297 = stack[-4];
    v297 = qcar(v297);
    fn = elt(env, 17); /* aeval */
    v297 = (*qfn1(fn))(qenv(fn), v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    stack[-5] = v297;
    v271 = stack[-1];
    v297 = stack[-2];
    v271 = Lappend(nil, v271, v297);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-6];
    v297 = stack[-5];
    {
        popv(7);
        fn = elt(env, 18); /* subeval1 */
        return (*qfn2(fn))(qenv(fn), v271, v297);
    }

v154:
    v297 = stack[-4];
    v297 = qcar(v297);
    { popv(7); return onevalue(v297); }
/* error exit handlers */
v216:
    env = stack[-6];
    qvalue(elt(env, 6)) = stack[0]; /* !*evallhseqp */
    popv(7);
    return nil;
v298:
    popv(7);
    return nil;
}



/* Code for dipsimpconti */

static Lisp_Object CC_dipsimpconti(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v301, v228;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipsimpconti");
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
    v45 = stack[-3];
    if (v45 == nil) goto v24;
    v45 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* bcfd */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    stack[-4] = v45;
    v45 = qvalue(elt(env, 2)); /* !*groebdivide */
    if (v45 == nil) goto v138;
    v45 = stack[-3];
    fn = elt(env, 6); /* dipcontenti */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    goto v137;

v137:
    stack[-4] = v45;
    v45 = stack[-4];
    v45 = qcar(v45);
    stack[0] = v45;
    v45 = stack[0];
    fn = elt(env, 7); /* bcplus!? */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    if (!(v45 == nil)) goto v83;
    v45 = stack[0];
    fn = elt(env, 8); /* bcneg */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    stack[0] = v45;
    goto v83;

v83:
    v45 = stack[-3];
    v45 = qcdr(v45);
    v45 = qcar(v45);
    fn = elt(env, 7); /* bcplus!? */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    if (!(v45 == nil)) goto v58;
    v45 = stack[0];
    fn = elt(env, 8); /* bcneg */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    stack[0] = v45;
    goto v58;

v58:
    v45 = stack[0];
    fn = elt(env, 9); /* bcone!? */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    if (v45 == nil) goto v280;
    v45 = stack[-4];
    v45 = qcdr(v45);
    if (!(v45 == nil)) goto v280;
    v301 = qvalue(elt(env, 1)); /* nil */
    v45 = stack[-3];
    popv(6);
    return cons(v301, v45);

v280:
    v45 = stack[-4];
    v45 = qcdr(v45);
    stack[-2] = v45;
    v301 = qvalue(elt(env, 4)); /* groebmonfac */
    v45 = (Lisp_Object)1; /* 0 */
    if (v301 == v45) goto v79;
    v45 = stack[-4];
    v45 = qcdr(v45);
    fn = elt(env, 10); /* dipcontlowerev */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    stack[-2] = v45;
    goto v79;

v79:
    v45 = stack[-3];
    stack[-1] = v45;
    v45 = stack[0];
    fn = elt(env, 9); /* bcone!? */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    if (v45 == nil) goto v89;
    v45 = stack[-2];
    if (!(v45 == nil)) goto v89;

v290:
    v45 = stack[-4];
    v45 = qcdr(v45);
    if (v45 == nil) goto v236;
    v45 = stack[-4];
    v301 = qcdr(v45);
    v45 = stack[-2];
    fn = elt(env, 11); /* evdif */
    v45 = (*qfn2(fn))(qenv(fn), v301, v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    stack[-2] = v45;
    v45 = stack[-2];
    if (v45 == nil) goto v118;
    v45 = stack[-1];
    v301 = qcar(v45);
    v45 = stack[-2];
    fn = elt(env, 11); /* evdif */
    v45 = (*qfn2(fn))(qenv(fn), v301, v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    fn = elt(env, 12); /* evzero!? */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    if (!(v45 == nil)) goto v118;
    v45 = stack[-2];
    v301 = v45;
    goto v120;

v120:
    v45 = stack[-1];
    popv(6);
    return cons(v301, v45);

v118:
    v45 = qvalue(elt(env, 1)); /* nil */
    v301 = v45;
    goto v120;

v236:
    v301 = qvalue(elt(env, 1)); /* nil */
    v45 = stack[-1];
    popv(6);
    return cons(v301, v45);

v89:
    v228 = stack[-3];
    v301 = stack[0];
    v45 = stack[-2];
    fn = elt(env, 13); /* dipreduceconti */
    v45 = (*qfnn(fn))(qenv(fn), 3, v228, v301, v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    stack[-1] = v45;
    goto v290;

v138:
    v45 = qvalue(elt(env, 3)); /* !*groebrm */
    if (v45 == nil) goto v158;
    stack[0] = stack[-4];
    v45 = stack[-3];
    fn = elt(env, 14); /* dipmonfac */
    v45 = (*qfn1(fn))(qenv(fn), v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    v45 = cons(stack[0], v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    goto v137;

v158:
    v45 = stack[-4];
    v45 = ncons(v45);
    nil = C_nil;
    if (exception_pending()) goto v116;
    env = stack[-5];
    goto v137;

v24:
    v301 = qvalue(elt(env, 1)); /* nil */
    v45 = stack[-3];
    popv(6);
    return cons(v301, v45);
/* error exit handlers */
v116:
    popv(6);
    return nil;
}



/* Code for evalsymsubset */

static Lisp_Object CC_evalsymsubset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v28, v188, v75;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalsymsubset");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v197 = v0;
/* end of prologue */
    v28 = v197;
    v28 = qcar(v28);
    v197 = qcdr(v197);
    v197 = qcar(v197);
    v75 = v28;
    v188 = v197;
    v28 = v188;
    v197 = elt(env, 1); /* union */
    if (!consp(v28)) goto v24;
    v28 = qcar(v28);
    if (!(v28 == v197)) goto v24;
    v28 = v75;
    v197 = v188;
    v197 = qcdr(v197);
    v197 = Lmember(nil, v28, v197);
    goto v88;

v88:
    if (!(v197 == nil)) return onevalue(v197);
    v28 = v75;
    v197 = elt(env, 3); /* intersection */
    if (!consp(v28)) goto v3;
    v28 = qcar(v28);
    if (!(v28 == v197)) goto v3;
    v28 = v188;
    v197 = v75;
    v197 = qcdr(v197);
    v197 = Lmember(nil, v28, v197);
    goto v164;

v164:
    if (!(v197 == nil)) return onevalue(v197);
    v28 = v75;
    v197 = elt(env, 4); /* setdiff */
    if (!consp(v28)) goto v126;
    v28 = qcar(v28);
    if (!(v28 == v197)) goto v126;
    v197 = v75;
    v197 = qcdr(v197);
    v28 = qcar(v197);
    v197 = v188;
    v197 = (equal(v28, v197) ? lisp_true : nil);
    if (!(v197 == nil)) return onevalue(v197);
    v28 = v188;
    v197 = elt(env, 1); /* union */
    if (!consp(v28)) goto v68;
    v28 = qcar(v28);
    if (!(v28 == v197)) goto v68;
    v197 = v75;
    v197 = qcdr(v197);
    v197 = qcar(v197);
    v28 = v188;
    v28 = qcdr(v28);
    v197 = Lmember(nil, v197, v28);
    return onevalue(v197);

v68:
    v197 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v197);

v126:
    v197 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v197);

v3:
    v197 = qvalue(elt(env, 2)); /* nil */
    goto v164;

v24:
    v197 = qvalue(elt(env, 2)); /* nil */
    goto v88;
}



setup_type const u51_setup[] =
{
    {"simpsqrt",                CC_simpsqrt,    too_many_1,    wrong_no_1},
    {"fctrf",                   CC_fctrf,       too_many_1,    wrong_no_1},
    {"pickupu",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_pickupu},
    {"giremainder",             too_few_2,      CC_giremainder,wrong_no_2},
    {"ofsf_xor",                too_few_2,      CC_ofsf_xor,   wrong_no_2},
    {"mkop",                    CC_mkop,        too_many_1,    wrong_no_1},
    {"leqgrt",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_leqgrt},
    {"setequal",                too_few_2,      CC_setequal,   wrong_no_2},
    {"remred",                  too_few_2,      CC_remred,     wrong_no_2},
    {":recip",                  CC_Trecip,      too_many_1,    wrong_no_1},
    {"open",                    too_few_2,      CC_open,       wrong_no_2},
    {"simp:ps:",                CC_simpTpsT,    too_many_1,    wrong_no_1},
    {"mappend",                 too_few_2,      CC_mappend,    wrong_no_2},
    {"a2dipatom",               CC_a2dipatom,   too_many_1,    wrong_no_1},
    {"xadd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_xadd},
    {"crprimp",                 CC_crprimp,     too_many_1,    wrong_no_1},
    {"rungekuttastep",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_rungekuttastep},
    {"basisvectorp",            CC_basisvectorp,too_many_1,    wrong_no_1},
    {"dstr-to-alg",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_dstrKtoKalg},
    {"simpfourier",             CC_simpfourier, too_many_1,    wrong_no_1},
    {"invlex",                  CC_invlex,      too_many_1,    wrong_no_1},
    {"num_ids_range",           too_few_2,      CC_num_ids_range,wrong_no_2},
    {"pst_equitable1",          too_few_2,      CC_pst_equitable1,wrong_no_2},
    {"ratleqp",                 too_few_2,      CC_ratleqp,    wrong_no_2},
    {"gcdlist1",                CC_gcdlist1,    too_many_1,    wrong_no_1},
    {"mchkminus",               too_few_2,      CC_mchkminus,  wrong_no_2},
    {"rl_susibin",              too_few_2,      CC_rl_susibin, wrong_no_2},
    {"subeval0",                CC_subeval0,    too_many_1,    wrong_no_1},
    {"dipsimpconti",            CC_dipsimpconti,too_many_1,    wrong_no_1},
    {"evalsymsubset",           CC_evalsymsubset,too_many_1,   wrong_no_1},
    {NULL, (one_args *)"u51", (two_args *)"6403 1921929 7164192", 0}
};

/* end of generated code */
