
/* $destdir/generated-c\u42.c Machine generated C code */

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


/* Code for i2cr!* */

static Lisp_Object CC_i2crH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for i2cr*");
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
    v3 = v0;
/* end of prologue */
    fn = elt(env, 3); /* chkint!* */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[0];
    v4 = v3;
    if (!consp(v3)) goto v6;
    v3 = qvalue(elt(env, 2)); /* bfz!* */
    goto v7;

v7:
    {
        popv(1);
        fn = elt(env, 4); /* mkcr */
        return (*qfn2(fn))(qenv(fn), v4, v3);
    }

v6:
    v3 = elt(env, 1); /* 0.0 */
    goto v7;
/* error exit handlers */
v5:
    popv(1);
    return nil;
}



/* Code for rule!-list */

static Lisp_Object CC_ruleKlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v44, v45, v46, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rule-list");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v8;
    stack[-2] = v0;
/* end of prologue */

v48:
    v43 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v43; /* frasc!* */
    v43 = stack[-2];
    if (v43 == nil) goto v6;
    stack[0] = stack[-2];
    v43 = qvalue(elt(env, 1)); /* nil */
    v43 = ncons(v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    if (equal(stack[0], v43)) goto v6;
    v43 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 3)) = v43; /* mcond!* */
    v43 = stack[-2];
    v43 = qcar(v43);
    stack[-3] = v43;
    v43 = stack[-3];
    if (symbolp(v43)) goto v50;
    v43 = stack[-3];
    v44 = qcar(v43);
    v43 = elt(env, 6); /* list */
    if (v44 == v43) goto v51;
    v43 = stack[-3];
    v44 = qcar(v43);
    v43 = elt(env, 8); /* equal */
    if (v44 == v43) goto v52;
    v43 = stack[-3];
    v44 = qcar(v43);
    v43 = elt(env, 10); /* replaceby */
    if (v44 == v43) goto v53;
    v44 = stack[-3];
    v43 = elt(env, 11); /* "rule" */
    fn = elt(env, 14); /* typerr */
    v43 = (*qfn2(fn))(qenv(fn), v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    goto v53;

v53:
    v43 = stack[-3];
    v43 = qcdr(v43);
    v43 = qcar(v43);
    fn = elt(env, 15); /* remove!-free!-vars */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    stack[0] = v43;
    v43 = stack[-3];
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v44 = qcar(v43);
    v43 = elt(env, 12); /* when */
    if (!consp(v44)) goto v54;
    v44 = qcar(v44);
    if (!(v44 == v43)) goto v54;
    v43 = stack[-3];
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v43 = qcar(v43);
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v43 = qcar(v43);
    fn = elt(env, 16); /* remove!-free!-vars!* */
    v45 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    v44 = qvalue(elt(env, 1)); /* nil */
    v43 = elt(env, 13); /* algebraic */
    fn = elt(env, 17); /* formbool */
    v43 = (*qfnn(fn))(qenv(fn), 3, v45, v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    qvalue(elt(env, 3)) = v43; /* mcond!* */
    v43 = stack[-3];
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v43 = qcar(v43);
    v43 = qcdr(v43);
    v43 = qcar(v43);
    fn = elt(env, 16); /* remove!-free!-vars!* */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    goto v55;

v55:
    v47 = stack[0];
    v46 = v43;
    v45 = qvalue(elt(env, 2)); /* frasc!* */
    v44 = qvalue(elt(env, 3)); /* mcond!* */
    v43 = stack[-1];
    fn = elt(env, 18); /* rule!* */
    v43 = (*qfnn(fn))(qenv(fn), 5, v47, v46, v45, v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    v43 = stack[-2];
    v43 = qcdr(v43);
    stack[-2] = v43;
    goto v48;

v54:
    v43 = stack[-3];
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v43 = qcar(v43);
    fn = elt(env, 16); /* remove!-free!-vars!* */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    goto v55;

v52:
    v43 = elt(env, 9); /* "Please use => instead of = in rules" */
    fn = elt(env, 19); /* lprim */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    goto v53;

v51:
    v43 = stack[-3];
    v44 = qcdr(v43);
    v43 = stack[-2];
    v43 = qcdr(v43);
    v43 = Lappend(nil, v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    stack[-2] = v43;
    goto v48;

v50:
    v44 = stack[-3];
    v43 = elt(env, 5); /* avalue */
    v43 = get(v44, v43);
    env = stack[-4];
    v45 = v43;
    if (v43 == nil) goto v56;
    v43 = v45;
    v44 = qcar(v43);
    v43 = elt(env, 6); /* list */
    if (!(v44 == v43)) goto v56;
    v43 = v45;
    v43 = qcdr(v43);
    v43 = qcar(v43);
    v43 = qcdr(v43);
    v44 = Lreverse(nil, v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    v43 = stack[-2];
    v43 = qcdr(v43);
    v43 = Lappend(nil, v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    stack[-2] = v43;
    goto v48;

v56:
    v44 = stack[-3];
    v43 = elt(env, 7); /* "rule list" */
    fn = elt(env, 14); /* typerr */
    v43 = (*qfn2(fn))(qenv(fn), v44, v43);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-4];
    goto v53;

v6:
    v43 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 3)) = v43; /* mcond!* */
    { popv(5); return onevalue(v43); }
/* error exit handlers */
v49:
    popv(5);
    return nil;
}



/* Code for freeof!-df */

static Lisp_Object CC_freeofKdf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v63, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeof-df");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v63 = stack[-1];
    if (!consp(v63)) goto v15;
    v63 = stack[-1];
    v64 = qcar(v63);
    v63 = elt(env, 2); /* df */
    if (v64 == v63) goto v42;
    v63 = stack[-1];
    v64 = qcdr(v63);
    v63 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* freeof!-dfl */
        return (*qfn2(fn))(qenv(fn), v64, v63);
    }

v42:
    v63 = stack[-1];
    v63 = qcdr(v63);
    v64 = qcar(v63);
    v63 = stack[0];
    v63 = CC_freeofKdf(env, v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-2];
    if (v63 == nil) goto v4;
    v64 = stack[0];
    v63 = stack[-1];
    v63 = qcdr(v63);
    v63 = qcdr(v63);
    fn = elt(env, 5); /* smember */
    v63 = (*qfn2(fn))(qenv(fn), v64, v63);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v63 = (v63 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v63); }

v4:
    v63 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v63); }

v15:
    v63 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v63); }
/* error exit handlers */
v65:
    popv(3);
    return nil;
}



/* Code for operator */

static Lisp_Object CC_operator(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for operator");
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
    v3 = v0;
/* end of prologue */
    stack[0] = v3;
    goto v15;

v15:
    v3 = stack[0];
    if (v3 == nil) goto v48;
    v3 = stack[0];
    v3 = qcar(v3);
    fn = elt(env, 2); /* mkop */
    v3 = (*qfn1(fn))(qenv(fn), v3);
    nil = C_nil;
    if (exception_pending()) goto v5;
    env = stack[-1];
    v3 = stack[0];
    v3 = qcdr(v3);
    stack[0] = v3;
    goto v15;

v48:
    v3 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v3); }
/* error exit handlers */
v5:
    popv(2);
    return nil;
}



/* Code for product!-set2 */

static Lisp_Object CC_productKset2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v37;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for product-set2");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v8;
    v71 = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = v71;
    goto v48;

v48:
    v71 = stack[-2];
    if (v71 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v71 = stack[-2];
    v71 = qcar(v71);
    stack[-1] = v71;
    v71 = stack[-3];
    stack[0] = v71;
    goto v41;

v41:
    v71 = stack[0];
    if (v71 == nil) goto v5;
    v71 = stack[0];
    v71 = qcar(v71);
    v37 = stack[-1];
    v37 = list2(v37, v71);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    v71 = stack[-4];
    v71 = cons(v37, v71);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-5];
    stack[-4] = v71;
    v71 = stack[0];
    v71 = qcdr(v71);
    stack[0] = v71;
    goto v41;

v5:
    v71 = stack[-2];
    v71 = qcdr(v71);
    stack[-2] = v71;
    goto v48;
/* error exit handlers */
v72:
    popv(6);
    return nil;
}



/* Code for groebsimpcontnormalform */

static Lisp_Object CC_groebsimpcontnormalform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsimpcontnormalform");
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
    v56 = stack[-2];
    if (v56 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v56 = stack[-2];
    v56 = qcdr(v56);
    v56 = qcdr(v56);
    v56 = qcdr(v56);
    v56 = qcar(v56);
    if (v56 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v56 = stack[-2];
    fn = elt(env, 3); /* gsugar */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    stack[0] = v56;
    v56 = stack[-2];
    v56 = qcdr(v56);
    v56 = qcdr(v56);
    v56 = qcar(v56);
    stack[-3] = v56;
    v56 = stack[-2];
    fn = elt(env, 4); /* vdpsimpcont */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    stack[-2] = v56;
    v80 = stack[-2];
    v56 = stack[0];
    fn = elt(env, 5); /* gsetsugar */
    v56 = (*qfn2(fn))(qenv(fn), v80, v56);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    v56 = qvalue(elt(env, 1)); /* !*groebprot */
    if (v56 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v80 = stack[-3];
    v56 = stack[-2];
    v56 = qcdr(v56);
    v56 = qcdr(v56);
    v56 = qcar(v56);
    if (equal(v80, v56)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[-1] = elt(env, 2); /* quotient */
    v56 = stack[-2];
    v56 = qcdr(v56);
    v56 = qcdr(v56);
    v56 = qcar(v56);
    fn = elt(env, 6); /* vbc2a */
    stack[0] = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    v56 = stack[-3];
    fn = elt(env, 6); /* vbc2a */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    v56 = list3(stack[-1], stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    fn = elt(env, 7); /* reval */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-4];
    fn = elt(env, 8); /* groebreductionprotocol2 */
    v56 = (*qfn1(fn))(qenv(fn), v56);
    nil = C_nil;
    if (exception_pending()) goto v33;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
/* error exit handlers */
v33:
    popv(5);
    return nil;
}



/* Code for evalsubset */

static Lisp_Object CC_evalsubset(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v84, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalsubset");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v83 = v8;
    v84 = v0;
/* end of prologue */
    v85 = elt(env, 1); /* subset */
    fn = elt(env, 2); /* evalsetbool */
    v83 = (*qfnn(fn))(qenv(fn), 3, v85, v84, v83);
    nil = C_nil;
    if (exception_pending()) goto v86;
    env = stack[0];
    v84 = v83;
    v83 = v84;
    if (!consp(v83)) { popv(1); return onevalue(v84); }
    v83 = v84;
    {
        popv(1);
        fn = elt(env, 3); /* evalsymsubset */
        return (*qfn1(fn))(qenv(fn), v83);
    }
/* error exit handlers */
v86:
    popv(1);
    return nil;
}



/* Code for gffdot */

static Lisp_Object CC_gffdot(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v89;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gffdot");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v88 = stack[-1];
    v89 = qcar(v88);
    v88 = stack[0];
    v88 = qcar(v88);
    stack[-2] = times2(v89, v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[-3];
    v88 = stack[-1];
    v89 = qcdr(v88);
    v88 = stack[0];
    v88 = qcdr(v88);
    v88 = times2(v89, v88);
    nil = C_nil;
    if (exception_pending()) goto v90;
    {
        Lisp_Object v78 = stack[-2];
        popv(4);
        return plus2(v78, v88);
    }
/* error exit handlers */
v90:
    popv(4);
    return nil;
}



/* Code for clogsq */

static Lisp_Object CC_clogsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clogsq");
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
    v81 = stack[0];
    v81 = qcar(v81);
    fn = elt(env, 1); /* clogf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-2];
    v81 = stack[0];
    v81 = qcdr(v81);
    fn = elt(env, 1); /* clogf */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v61;
    {
        Lisp_Object v62 = stack[-1];
        popv(3);
        return cons(v62, v81);
    }
/* error exit handlers */
v61:
    popv(3);
    return nil;
}



/* Code for dp_from_a */

static Lisp_Object CC_dp_from_a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v104, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_from_a");
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
    v104 = stack[0];
    v103 = elt(env, 1); /* list */
    if (!consp(v104)) goto v61;
    v104 = qcar(v104);
    if (!(v104 == v103)) goto v61;

v83:
    v104 = stack[0];
    v103 = elt(env, 3); /* "dpoly" */
    {
        popv(6);
        fn = elt(env, 8); /* typerr */
        return (*qfn2(fn))(qenv(fn), v104, v103);
    }

v61:
    v104 = stack[0];
    v103 = elt(env, 2); /* mat */
    if (!consp(v104)) goto v15;
    v104 = qcar(v104);
    if (v104 == v103) goto v83;
    else goto v15;

v15:
    v103 = stack[0];
    if (!consp(v103)) goto v60;
    v103 = stack[0];
    v103 = qcar(v103);
    if (!(!consp(v103))) goto v39;
    v103 = stack[0];
    v103 = qcar(v103);
    if (!(symbolp(v103))) goto v39;
    v103 = stack[0];
    v104 = qcar(v103);
    v103 = elt(env, 5); /* dp!=fn */
    v103 = get(v104, v103);
    env = stack[-5];
    v105 = v103;
    v104 = v105;
    v103 = elt(env, 6); /* dp!=fnpow */
    if (v104 == v103) goto v32;
    v103 = v105;
    if (v103 == nil) goto v106;
    stack[-4] = v105;
    v103 = stack[0];
    v103 = qcdr(v103);
    stack[-3] = v103;
    v103 = stack[-3];
    if (v103 == nil) goto v107;
    v103 = stack[-3];
    v103 = qcar(v103);
    v103 = CC_dp_from_a(env, v103);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    v103 = ncons(v103);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    stack[-1] = v103;
    stack[-2] = v103;
    goto v108;

v108:
    v103 = stack[-3];
    v103 = qcdr(v103);
    stack[-3] = v103;
    v103 = stack[-3];
    if (v103 == nil) goto v109;
    stack[0] = stack[-1];
    v103 = stack[-3];
    v103 = qcar(v103);
    v103 = CC_dp_from_a(env, v103);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    v103 = ncons(v103);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    v103 = Lrplacd(nil, stack[0], v103);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    v103 = stack[-1];
    v103 = qcdr(v103);
    stack[-1] = v103;
    goto v108;

v109:
    v103 = stack[-2];
    goto v110;

v110:
    v103 = ncons(v103);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    {
        Lisp_Object v111 = stack[-4];
        popv(6);
        fn = elt(env, 9); /* apply */
        return (*qfn2(fn))(qenv(fn), v111, v103);
    }

v107:
    v103 = qvalue(elt(env, 7)); /* nil */
    goto v110;

v106:
    v103 = stack[0];
    {
        popv(6);
        fn = elt(env, 10); /* dp!=a2dpatom */
        return (*qfn1(fn))(qenv(fn), v103);
    }

v32:
    v103 = stack[0];
    v103 = qcdr(v103);
    v103 = qcar(v103);
    v104 = CC_dp_from_a(env, v103);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-5];
    v103 = stack[0];
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    v103 = qcar(v103);
    {
        popv(6);
        fn = elt(env, 6); /* dp!=fnpow */
        return (*qfn2(fn))(qenv(fn), v104, v103);
    }

v39:
    v103 = stack[0];
    v104 = qcar(v103);
    v103 = elt(env, 4); /* "dpoly operator" */
    {
        popv(6);
        fn = elt(env, 8); /* typerr */
        return (*qfn2(fn))(qenv(fn), v104, v103);
    }

v60:
    v103 = stack[0];
    {
        popv(6);
        fn = elt(env, 10); /* dp!=a2dpatom */
        return (*qfn1(fn))(qenv(fn), v103);
    }
/* error exit handlers */
v19:
    popv(6);
    return nil;
}



/* Code for boolean!-eval2 */

static Lisp_Object CC_booleanKeval2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v123, v124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for boolean-eval2");
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

v1:
    v123 = stack[0];
    v122 = elt(env, 1); /* boolean */
    if (!consp(v123)) goto v42;
    v123 = qcar(v123);
    if (!(v123 == v122)) goto v42;
    v122 = stack[0];
    v122 = qcdr(v122);
    v122 = qcar(v122);
    stack[0] = v122;
    goto v1;

v42:
    v123 = stack[0];
    v122 = elt(env, 2); /* and */
    if (!consp(v123)) goto v69;
    v123 = qcar(v123);
    if (!(v123 == v122)) goto v69;

v125:
    v122 = stack[0];
    stack[-4] = qcar(v122);
    v122 = stack[0];
    v122 = qcdr(v122);
    stack[-3] = v122;
    v122 = stack[-3];
    if (v122 == nil) goto v126;
    v122 = stack[-3];
    v122 = qcar(v122);
    v122 = CC_booleanKeval2(env, v122);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-1] = v122;
    stack[-2] = v122;
    goto v65;

v65:
    v122 = stack[-3];
    v122 = qcdr(v122);
    stack[-3] = v122;
    v122 = stack[-3];
    if (v122 == nil) goto v127;
    stack[0] = stack[-1];
    v122 = stack[-3];
    v122 = qcar(v122);
    v122 = CC_booleanKeval2(env, v122);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v122 = ncons(v122);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v122 = Lrplacd(nil, stack[0], v122);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v122 = stack[-1];
    v122 = qcdr(v122);
    stack[-1] = v122;
    goto v65;

v127:
    v122 = stack[-2];
    goto v77;

v77:
    {
        Lisp_Object v103 = stack[-4];
        popv(6);
        return cons(v103, v122);
    }

v126:
    v122 = qvalue(elt(env, 5)); /* nil */
    goto v77;

v69:
    v123 = stack[0];
    v122 = elt(env, 3); /* or */
    if (!consp(v123)) goto v58;
    v123 = qcar(v123);
    if (v123 == v122) goto v125;
    else goto v58;

v58:
    v123 = stack[0];
    v122 = elt(env, 4); /* not */
    if (!consp(v123)) goto v52;
    v123 = qcar(v123);
    if (v123 == v122) goto v125;
    else goto v52;

v52:
    v122 = qvalue(elt(env, 6)); /* t */
    stack[-1] = qvalue(elt(env, 7)); /* !*protfg */
    qvalue(elt(env, 7)) = v122; /* !*protfg */
    v124 = stack[0];
    v123 = qvalue(elt(env, 5)); /* nil */
    v122 = elt(env, 8); /* algebraic */
    fn = elt(env, 11); /* formbool */
    v124 = (*qfnn(fn))(qenv(fn), 3, v124, v123, v122);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    v123 = qvalue(elt(env, 5)); /* nil */
    v122 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 12); /* errorset */
    v122 = (*qfnn(fn))(qenv(fn), 3, v124, v123, v122);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-5];
    stack[-2] = v122;
    qvalue(elt(env, 7)) = stack[-1]; /* !*protfg */
    v122 = stack[-2];
    fn = elt(env, 13); /* errorp */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    if (v122 == nil) goto v93;
    v122 = qvalue(elt(env, 6)); /* t */
    qvalue(elt(env, 9)) = v122; /* bool!-break!* */
    v122 = qvalue(elt(env, 5)); /* nil */
    qvalue(elt(env, 10)) = v122; /* erfg!* */
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

v93:
    v122 = stack[-2];
    v122 = qcar(v122);
    { popv(6); return onevalue(v122); }
/* error exit handlers */
v104:
    env = stack[-5];
    qvalue(elt(env, 7)) = stack[-1]; /* !*protfg */
    popv(6);
    return nil;
v20:
    popv(6);
    return nil;
}



/* Code for general!-negate!-term */

static Lisp_Object CC_generalKnegateKterm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-negate-term");
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
    v81 = v0;
/* end of prologue */
    v6 = v81;
    stack[0] = qcar(v6);
    v6 = v81;
    v6 = qcdr(v6);
    fn = elt(env, 1); /* general!-minus!-mod!-p */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v87;
    {
        Lisp_Object v61 = stack[0];
        popv(1);
        return cons(v61, v6);
    }
/* error exit handlers */
v87:
    popv(1);
    return nil;
}



/* Code for preptaylor!*2 */

static Lisp_Object CC_preptaylorH2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v51, v118;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for preptaylor*2");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v99 = stack[-1];
    v99 = qcdr(v99);
    fn = elt(env, 4); /* prepsq!* */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    v118 = v99;
    v51 = (Lisp_Object)1; /* 0 */
    if (v118 == v51) goto v48;
    v118 = v99;
    v51 = elt(env, 2); /* quotient */
    if (!consp(v118)) goto v32;
    v118 = qcar(v118);
    if (!(v118 == v51)) goto v32;
    v51 = v99;
    v51 = qcdr(v51);
    v118 = qcar(v51);
    v51 = elt(env, 3); /* minus */
    if (!consp(v118)) goto v32;
    v118 = qcar(v118);
    if (!(v118 == v51)) goto v32;
    stack[-2] = elt(env, 3); /* minus */
    v118 = elt(env, 2); /* quotient */
    v51 = v99;
    v51 = qcdr(v51);
    v51 = qcar(v51);
    v51 = qcdr(v51);
    v51 = qcar(v51);
    v99 = qcdr(v99);
    v99 = qcdr(v99);
    v99 = qcar(v99);
    v99 = list3(v118, v51, v99);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    v99 = list2(stack[-2], v99);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    stack[-2] = v99;
    goto v132;

v132:
    v99 = stack[-1];
    v51 = qcar(v99);
    v99 = stack[0];
    fn = elt(env, 5); /* preptaycoeff */
    v99 = (*qfn2(fn))(qenv(fn), v51, v99);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    v99 = cons(stack[-2], v99);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-3];
    fn = elt(env, 6); /* retimes */
    v99 = (*qfn1(fn))(qenv(fn), v99);
    nil = C_nil;
    if (exception_pending()) goto v131;
    popv(4);
    return ncons(v99);

v32:
    stack[-2] = v99;
    goto v132;

v48:
    v99 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v99); }
/* error exit handlers */
v131:
    popv(4);
    return nil;
}



/* Code for letscalar */

static Lisp_Object MS_CDECL CC_letscalar(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v66, Lisp_Object v16,
                         Lisp_Object v36, Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v196, v197, v198, v199, v200;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "letscalar");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for letscalar");
#endif
    if (stack >= stacklimit)
    {
        push6(v15,v36,v16,v66,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v8,v66,v16,v36,v15);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v15;
    stack[-3] = v36;
    stack[-4] = v16;
    stack[-5] = v66;
    stack[-6] = v8;
    stack[-7] = v0;
/* end of prologue */
    v195 = stack[-4];
    if (!consp(v195)) goto v82;
    v195 = stack[-4];
    v195 = qcar(v195);
    if (symbolp(v195)) goto v89;
    v196 = stack[-7];
    v195 = elt(env, 1); /* hold */
    {
        popv(10);
        fn = elt(env, 25); /* errpri2 */
        return (*qfn2(fn))(qenv(fn), v196, v195);
    }

v89:
    v195 = stack[-4];
    v196 = qcar(v195);
    v195 = elt(env, 2); /* df */
    if (v196 == v195) goto v201;
    v195 = stack[-4];
    v195 = qcar(v195);
    fn = elt(env, 26); /* getrtype */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    if (v195 == nil) goto v203;
    v195 = stack[-4];
    fn = elt(env, 27); /* reval */
    v198 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v197 = stack[-6];
    v196 = stack[-5];
    v195 = stack[-3];
    {
        popv(10);
        fn = elt(env, 28); /* let2 */
        return (*qfnn(fn))(qenv(fn), 4, v198, v197, v196, v195);
    }

v203:
    v195 = stack[-4];
    v196 = qcar(v195);
    v195 = elt(env, 4); /* simpfn */
    v195 = get(v196, v195);
    env = stack[-9];
    if (!(v195 == nil)) goto v204;
    v195 = stack[-4];
    v196 = qcar(v195);
    v195 = elt(env, 5); /* "operator" */
    fn = elt(env, 29); /* redmsg */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v195 = stack[-4];
    v195 = qcar(v195);
    fn = elt(env, 30); /* mkop */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v199 = stack[-7];
    v198 = stack[-6];
    v197 = stack[-5];
    v196 = stack[-3];
    v195 = stack[-2];
    {
        popv(10);
        fn = elt(env, 31); /* let3 */
        return (*qfnn(fn))(qenv(fn), 5, v199, v198, v197, v196, v195);
    }

v204:
    v196 = stack[-4];
    v195 = elt(env, 18); /* expt */
    if (!consp(v196)) goto v205;
    v196 = qcar(v196);
    if (!(v196 == v195)) goto v205;
    v195 = stack[-4];
    v195 = qcdr(v195);
    v195 = qcdr(v195);
    v196 = qcar(v195);
    v195 = qvalue(elt(env, 19)); /* frlis!* */
    v195 = Lmemq(nil, v196, v195);
    if (v195 == nil) goto v205;
    stack[-8] = stack[-7];
    stack[-1] = stack[-6];
    stack[0] = stack[-5];
    v196 = stack[-4];
    v195 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 32); /* to */
    v196 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v195 = (Lisp_Object)17; /* 1 */
    v195 = cons(v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v196 = ncons(v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v195 = (Lisp_Object)17; /* 1 */
    v197 = cons(v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v196 = stack[-3];
    v195 = stack[-2];
    fn = elt(env, 33); /* letexprn */
    v195 = (*qfnn(fn))(qenv(fn), 6, stack[-8], stack[-1], stack[0], v197, v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    goto v206;

v206:
    v195 = qvalue(elt(env, 21)); /* t */
    stack[0] = qvalue(elt(env, 24)); /* !*precise */
    qvalue(elt(env, 24)) = v195; /* !*precise */
    v195 = stack[-4];
    fn = elt(env, 34); /* simp0 */
    v195 = (*qfn1(fn))(qenv(fn), v195);
    nil = C_nil;
    if (exception_pending()) goto v207;
    env = stack[-9];
    stack[-4] = v195;
    qvalue(elt(env, 24)) = stack[0]; /* !*precise */
    v195 = stack[-4];
    v195 = qcar(v195);
    if (!consp(v195)) goto v208;
    v195 = stack[-4];
    v195 = qcar(v195);
    v195 = qcar(v195);
    if (!consp(v195)) goto v208;
    v200 = stack[-7];
    v199 = stack[-6];
    v198 = stack[-5];
    v197 = stack[-4];
    v196 = stack[-3];
    v195 = stack[-2];
    {
        popv(10);
        fn = elt(env, 33); /* letexprn */
        return (*qfnn(fn))(qenv(fn), 6, v200, v199, v198, v197, v196, v195);
    }

v208:
    v195 = stack[-7];
    {
        popv(10);
        fn = elt(env, 35); /* errpri1 */
        return (*qfn1(fn))(qenv(fn), v195);
    }

v205:
    v196 = stack[-4];
    v195 = elt(env, 20); /* sqrt */
    if (!consp(v196)) goto v206;
    v196 = qcar(v196);
    if (!(v196 == v195)) goto v206;
    v195 = qvalue(elt(env, 21)); /* t */
    qvalue(elt(env, 22)) = v195; /* !*sqrtrulep */
    v197 = elt(env, 18); /* expt */
    v195 = stack[-4];
    v195 = qcdr(v195);
    v196 = qcar(v195);
    v195 = elt(env, 23); /* (quotient 1 2) */
    v198 = list3(v197, v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v197 = stack[-6];
    v196 = stack[-5];
    v195 = stack[-3];
    fn = elt(env, 28); /* let2 */
    v195 = (*qfnn(fn))(qenv(fn), 4, v198, v197, v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    goto v206;

v201:
    v199 = stack[-7];
    v198 = stack[-6];
    v197 = stack[-5];
    v196 = stack[-4];
    v195 = stack[-3];
    fn = elt(env, 36); /* letdf */
    v195 = (*qfnn(fn))(qenv(fn), 5, v199, v198, v197, v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    if (v195 == nil) goto v204;
    v195 = qvalue(elt(env, 3)); /* nil */
    { popv(10); return onevalue(v195); }

v82:
    v195 = stack[-3];
    if (!(v195 == nil)) goto v204;
    v195 = stack[-5];
    if (!(v195 == nil)) goto v204;
    v196 = stack[-4];
    v195 = elt(env, 6); /* avalue */
    v195 = Lremprop(nil, v196, v195);
    env = stack[-9];
    v196 = stack[-4];
    v195 = elt(env, 7); /* rtype */
    v195 = Lremprop(nil, v196, v195);
    env = stack[-9];
    v195 = stack[-4];
    v196 = ncons(v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v195 = elt(env, 8); /* antisymmetric */
    v195 = Lremflag(nil, v196, v195);
    env = stack[-9];
    v196 = stack[-4];
    v195 = elt(env, 9); /* infix */
    v195 = Lremprop(nil, v196, v195);
    env = stack[-9];
    v196 = stack[-4];
    v195 = elt(env, 10); /* kvalue */
    v195 = Lremprop(nil, v196, v195);
    env = stack[-9];
    v195 = stack[-4];
    v196 = ncons(v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v195 = elt(env, 11); /* linear */
    v195 = Lremflag(nil, v196, v195);
    env = stack[-9];
    v195 = stack[-4];
    v196 = ncons(v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v195 = elt(env, 12); /* noncom */
    v195 = Lremflag(nil, v196, v195);
    env = stack[-9];
    v196 = stack[-4];
    v195 = elt(env, 13); /* op */
    v195 = Lremprop(nil, v196, v195);
    env = stack[-9];
    v196 = stack[-4];
    v195 = elt(env, 14); /* opmtch */
    v195 = Lremprop(nil, v196, v195);
    env = stack[-9];
    v196 = stack[-4];
    v195 = elt(env, 4); /* simpfn */
    v195 = Lremprop(nil, v196, v195);
    env = stack[-9];
    v195 = stack[-4];
    v196 = ncons(v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v195 = elt(env, 15); /* symmetric */
    v195 = Lremflag(nil, v196, v195);
    env = stack[-9];
    v196 = stack[-4];
    v195 = qvalue(elt(env, 16)); /* wtl!* */
    fn = elt(env, 37); /* delasc */
    v195 = (*qfn2(fn))(qenv(fn), v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    qvalue(elt(env, 16)) = v195; /* wtl!* */
    v196 = stack[-4];
    v195 = elt(env, 17); /* opfn */
    v195 = Lflagp(nil, v196, v195);
    env = stack[-9];
    if (v195 == nil) goto v209;
    v195 = stack[-4];
    v196 = ncons(v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v195 = elt(env, 17); /* opfn */
    v195 = Lremflag(nil, v196, v195);
    env = stack[-9];
    v195 = stack[-4];
    v195 = Lremd(nil, v195);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    goto v209;

v209:
    fn = elt(env, 38); /* rmsubs */
    v195 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v202;
    env = stack[-9];
    v195 = qvalue(elt(env, 3)); /* nil */
    { popv(10); return onevalue(v195); }
/* error exit handlers */
v207:
    env = stack[-9];
    qvalue(elt(env, 24)) = stack[0]; /* !*precise */
    popv(10);
    return nil;
v202:
    popv(10);
    return nil;
}



/* Code for nonpolyp */

static Lisp_Object CC_nonpolyp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v211, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nonpolyp");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */

v212:
    v211 = stack[-1];
    if (!consp(v211)) goto v15;
    v211 = stack[-1];
    v211 = qcar(v211);
    if (!consp(v211)) goto v15;
    v211 = stack[-1];
    v211 = qcar(v211);
    v211 = qcar(v211);
    v126 = qcar(v211);
    v211 = stack[0];
    if (v126 == v211) goto v3;
    v211 = stack[-1];
    v211 = qcar(v211);
    v211 = qcar(v211);
    v126 = qcar(v211);
    v211 = stack[0];
    fn = elt(env, 2); /* depend!-p */
    v211 = (*qfn2(fn))(qenv(fn), v126, v211);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    goto v70;

v70:
    if (!(v211 == nil)) { popv(3); return onevalue(v211); }
    v211 = stack[-1];
    v211 = qcar(v211);
    v126 = qcdr(v211);
    v211 = stack[0];
    v211 = CC_nonpolyp(env, v126, v211);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    if (!(v211 == nil)) { popv(3); return onevalue(v211); }
    v211 = stack[-1];
    v126 = qcdr(v211);
    v211 = stack[0];
    stack[-1] = v126;
    stack[0] = v211;
    goto v212;

v3:
    v211 = qvalue(elt(env, 1)); /* nil */
    goto v70;

v15:
    v211 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v211); }
/* error exit handlers */
v74:
    popv(3);
    return nil;
}



/* Code for dvfsf_0mk2 */

static Lisp_Object CC_dvfsf_0mk2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81, v121, v87;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dvfsf_0mk2");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v81 = v8;
    v121 = v0;
/* end of prologue */
    v87 = qvalue(elt(env, 1)); /* nil */
    return list3(v121, v81, v87);
}



/* Code for vp1 */

static Lisp_Object MS_CDECL CC_vp1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v66, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v65, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "vp1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vp1");
#endif
    if (stack >= stacklimit)
    {
        push3(v66,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v66);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v66;
    stack[-1] = v8;
    stack[-2] = v0;
/* end of prologue */
    v34 = nil;
    goto v213;

v213:
    v72 = stack[0];
    if (v72 == nil) goto v81;
    v65 = stack[-2];
    v72 = stack[0];
    v72 = qcar(v72);
    if (equal(v65, v72)) goto v69;
    v72 = (Lisp_Object)1; /* 0 */
    v65 = v34;
    v72 = cons(v72, v65);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    v34 = v72;
    v72 = stack[0];
    v72 = qcdr(v72);
    stack[0] = v72;
    goto v213;

v69:
    stack[-2] = v34;
    v72 = stack[0];
    v72 = qcdr(v72);
    fn = elt(env, 2); /* vp2 */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    v72 = cons(stack[-1], v72);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    {
        Lisp_Object v129 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v129, v72);
    }

v81:
    stack[0] = v34;
    v72 = elt(env, 1); /* "Var not in z-list after all" */
    fn = elt(env, 4); /* interr */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v126;
    env = stack[-3];
    {
        Lisp_Object v35 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v35, v72);
    }
/* error exit handlers */
v126:
    popv(4);
    return nil;
}



/* Code for ps!:constmult!-erule */

static Lisp_Object CC_psTconstmultKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:constmult-erule");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v42 = v8;
    v83 = v0;
/* end of prologue */
    v41 = v83;
    v41 = qcdr(v41);
    stack[0] = qcar(v41);
    v41 = v83;
    v41 = qcdr(v41);
    v41 = qcdr(v41);
    v41 = qcar(v41);
    fn = elt(env, 1); /* ps!:evaluate */
    v41 = (*qfn2(fn))(qenv(fn), v41, v42);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-1];
    {
        Lisp_Object v86 = stack[0];
        popv(2);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v86, v41);
    }
/* error exit handlers */
v85:
    popv(2);
    return nil;
}



/* Code for subeval */

static Lisp_Object CC_subeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v63, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subeval");
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
    stack[-2] = qvalue(elt(env, 1)); /* sublist!* */
    qvalue(elt(env, 1)) = nil; /* sublist!* */
    v64 = elt(env, 2); /* sub */
    v63 = elt(env, 3); /* psopfn */
    v57 = elt(env, 4); /* subeval0 */
    v57 = Lputprop(nil, 3, v64, v63, v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[0] = elt(env, 4); /* subeval0 */
    v57 = stack[-1];
    v57 = Lmkquote(nil, v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    v57 = list2(stack[0], v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    fn = elt(env, 6); /* errorset2 */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    stack[0] = v57;
    v64 = elt(env, 2); /* sub */
    v63 = elt(env, 3); /* psopfn */
    v57 = elt(env, 0); /* subeval */
    v57 = Lputprop(nil, 3, v64, v63, v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    v57 = stack[0];
    fn = elt(env, 7); /* errorp */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    if (v57 == nil) goto v119;
    v57 = qvalue(elt(env, 5)); /* errmsg!* */
    if (v57 == nil) goto v130;
    v57 = qvalue(elt(env, 5)); /* errmsg!* */
    fn = elt(env, 8); /* rederr */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    goto v119;

v119:
    v57 = stack[0];
    v57 = qcar(v57);
    qvalue(elt(env, 1)) = stack[-2]; /* sublist!* */
    { popv(4); return onevalue(v57); }

v130:
    v57 = elt(env, 2); /* sub */
    fn = elt(env, 8); /* rederr */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-3];
    goto v119;
/* error exit handlers */
v34:
    env = stack[-3];
    qvalue(elt(env, 1)) = stack[-2]; /* sublist!* */
    popv(4);
    return nil;
}



/* Code for matrix_input_test */

static Lisp_Object CC_matrix_input_test(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v60, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrix_input_test");
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
    v60 = v0;
/* end of prologue */
    v69 = v60;
    v53 = elt(env, 1); /* mat */
    if (!consp(v69)) goto v62;
    v69 = qcar(v69);
    if (v69 == v53) { popv(1); return onevalue(v60); }
    else goto v62;

v62:
    v69 = elt(env, 2); /* "ERROR: `" */
    v53 = elt(env, 3); /* "' is non matrix input." */
    v53 = list3(v69, v60, v53);
    nil = C_nil;
    if (exception_pending()) goto v90;
    env = stack[0];
    fn = elt(env, 4); /* rederr */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v90;
    v53 = nil;
    { popv(1); return onevalue(v53); }
/* error exit handlers */
v90:
    popv(1);
    return nil;
}



/* Code for fast_setmat */

static Lisp_Object MS_CDECL CC_fast_setmat(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v66, Lisp_Object v16, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v183, v184, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "fast_setmat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fast_setmat");
#endif
    if (stack >= stacklimit)
    {
        push4(v16,v66,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v8,v66,v16);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v16;
    v183 = v66;
    v184 = v8;
    stack[0] = v0;
/* end of prologue */
    v17 = stack[0];
    v183 = list3(v17, v184, v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    stack[-6] = v183;
    v183 = stack[0];
    stack[-4] = qcdr(v183);
    v183 = stack[-6];
    v183 = qcdr(v183);
    stack[-3] = v183;
    v183 = stack[-3];
    if (v183 == nil) goto v40;
    v183 = stack[-3];
    v183 = qcar(v183);
    v184 = v183;
    v183 = v184;
    v183 = integerp(v183);
    if (v183 == nil) goto v65;
    v183 = v184;
    goto v38;

v38:
    v183 = ncons(v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    stack[-1] = v183;
    stack[-2] = v183;
    goto v58;

v58:
    v183 = stack[-3];
    v183 = qcdr(v183);
    stack[-3] = v183;
    v183 = stack[-3];
    if (v183 == nil) goto v74;
    stack[0] = stack[-1];
    v183 = stack[-3];
    v183 = qcar(v183);
    v184 = v183;
    v183 = v184;
    v183 = integerp(v183);
    if (v183 == nil) goto v118;
    v183 = v184;
    goto v203;

v203:
    v183 = ncons(v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    v183 = Lrplacd(nil, stack[0], v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    v183 = stack[-1];
    v183 = qcdr(v183);
    stack[-1] = v183;
    goto v58;

v118:
    v183 = v184;
    fn = elt(env, 2); /* reval */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    goto v203;

v74:
    v183 = stack[-2];
    goto v50;

v50:
    v183 = qcar(v183);
    fn = elt(env, 3); /* nth */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[-4], v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    v183 = stack[-6];
    v183 = qcdr(v183);
    stack[-4] = v183;
    v183 = stack[-4];
    if (v183 == nil) goto v27;
    v183 = stack[-4];
    v183 = qcar(v183);
    v184 = v183;
    v183 = v184;
    v183 = integerp(v183);
    if (v183 == nil) goto v115;
    v183 = v184;
    goto v190;

v190:
    v183 = ncons(v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    stack[-1] = v183;
    stack[-2] = v183;
    goto v96;

v96:
    v183 = stack[-4];
    v183 = qcdr(v183);
    stack[-4] = v183;
    v183 = stack[-4];
    if (v183 == nil) goto v223;
    stack[0] = stack[-1];
    v183 = stack[-4];
    v183 = qcar(v183);
    v184 = v183;
    v183 = v184;
    v183 = integerp(v183);
    if (v183 == nil) goto v185;
    v183 = v184;
    goto v20;

v20:
    v183 = ncons(v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    v183 = Lrplacd(nil, stack[0], v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    v183 = stack[-1];
    v183 = qcdr(v183);
    stack[-1] = v183;
    goto v96;

v185:
    v183 = v184;
    fn = elt(env, 2); /* reval */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    goto v20;

v223:
    v183 = stack[-2];
    goto v97;

v97:
    v183 = qcdr(v183);
    v183 = qcar(v183);
    fn = elt(env, 4); /* pnth */
    v184 = (*qfn2(fn))(qenv(fn), stack[-3], v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    v183 = stack[-5];
        popv(8);
        return Lrplaca(nil, v184, v183);

v115:
    v183 = v184;
    fn = elt(env, 2); /* reval */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    goto v190;

v27:
    v183 = qvalue(elt(env, 1)); /* nil */
    goto v97;

v65:
    v183 = v184;
    fn = elt(env, 2); /* reval */
    v183 = (*qfn1(fn))(qenv(fn), v183);
    nil = C_nil;
    if (exception_pending()) goto v222;
    env = stack[-7];
    goto v38;

v40:
    v183 = qvalue(elt(env, 1)); /* nil */
    goto v50;
/* error exit handlers */
v222:
    popv(8);
    return nil;
}



/* Code for indexvp */

static Lisp_Object CC_indexvp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v3;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indexvp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v70 = v3;
    if (!consp(v70)) goto v36;
    v70 = v3;
    v70 = qcar(v70);
    v3 = elt(env, 2); /* indexvar */
        return Lflagp(nil, v70, v3);

v36:
    v70 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v70);
}



/* Code for lf!=less */

static Lisp_Object CC_lfMless(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lf=less");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v8;
    v42 = v0;
/* end of prologue */
    v83 = elt(env, 1); /* cali */
    v41 = elt(env, 2); /* varlessp */
    stack[-2] = get(v83, v41);
    env = stack[-3];
    v41 = v42;
    fn = elt(env, 3); /* lf!=lvar */
    stack[0] = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v88;
    env = stack[-3];
    v41 = stack[-1];
    fn = elt(env, 3); /* lf!=lvar */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v88;
    {
        Lisp_Object v89 = stack[-2];
        Lisp_Object v53 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v89, v53, v41);
    }
/* error exit handlers */
v88:
    popv(4);
    return nil;
}



/* Code for st_flatten */

static Lisp_Object CC_st_flatten(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v211, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_flatten");
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
    v126 = v0;
/* end of prologue */
    v211 = v126;
    v211 = qcdr(v211);
    v211 = qcar(v211);
    if (is_number(v211)) goto v36;
    v211 = v126;
    v211 = qcdr(v211);
    stack[-3] = v211;
    goto v62;

v62:
    v211 = stack[-3];
    if (v211 == nil) goto v42;
    v211 = stack[-3];
    v211 = qcar(v211);
    v211 = CC_st_flatten(env, v211);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    fn = elt(env, 2); /* copy */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    stack[-2] = v211;
    v211 = stack[-2];
    fn = elt(env, 3); /* lastpair */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    stack[-1] = v211;
    v211 = stack[-3];
    v211 = qcdr(v211);
    stack[-3] = v211;
    v211 = stack[-1];
    if (!consp(v211)) goto v62;
    else goto v70;

v70:
    v211 = stack[-3];
    if (v211 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v211 = stack[-3];
    v211 = qcar(v211);
    v211 = CC_st_flatten(env, v211);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    fn = elt(env, 2); /* copy */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    v211 = Lrplacd(nil, stack[0], v211);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    v211 = stack[-1];
    fn = elt(env, 3); /* lastpair */
    v211 = (*qfn1(fn))(qenv(fn), v211);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-4];
    stack[-1] = v211;
    v211 = stack[-3];
    v211 = qcdr(v211);
    stack[-3] = v211;
    goto v70;

v42:
    v211 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v211); }

v36:
    v211 = v126;
    v211 = qcdr(v211);
    { popv(5); return onevalue(v211); }
/* error exit handlers */
v224:
    popv(5);
    return nil;
}



/* Code for ofsf_chsimpat */

static Lisp_Object CC_ofsf_chsimpat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v220, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_chsimpat");
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
    v220 = v0;
/* end of prologue */
    fn = elt(env, 5); /* ofsf_chsimpat1 */
    v220 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    stack[-3] = v220;
    v220 = stack[-3];
    if (v220 == nil) goto v82;
    v220 = stack[-3];
    v220 = qcar(v220);
    fn = elt(env, 6); /* ofsf_simpat */
    v220 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v220 = ncons(v220);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    stack[-1] = v220;
    stack[-2] = v220;
    goto v213;

v213:
    v220 = stack[-3];
    v220 = qcdr(v220);
    stack[-3] = v220;
    v220 = stack[-3];
    if (v220 == nil) goto v84;
    stack[0] = stack[-1];
    v220 = stack[-3];
    v220 = qcar(v220);
    fn = elt(env, 6); /* ofsf_simpat */
    v220 = (*qfn1(fn))(qenv(fn), v220);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v220 = ncons(v220);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v220 = Lrplacd(nil, stack[0], v220);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-4];
    v220 = stack[-1];
    v220 = qcdr(v220);
    stack[-1] = v220;
    goto v213;

v84:
    v220 = stack[-2];
    goto v14;

v14:
    v203 = v220;
    v220 = v203;
    if (v220 == nil) goto v76;
    v220 = v203;
    v220 = qcdr(v220);
    if (v220 == nil) goto v76;
    v220 = elt(env, 2); /* and */
    popv(5);
    return cons(v220, v203);

v76:
    v220 = v203;
    if (v220 == nil) goto v74;
    v220 = v203;
    v220 = qcar(v220);
    { popv(5); return onevalue(v220); }

v74:
    v203 = elt(env, 2); /* and */
    v220 = elt(env, 2); /* and */
    if (v203 == v220) goto v129;
    v220 = elt(env, 4); /* false */
    { popv(5); return onevalue(v220); }

v129:
    v220 = elt(env, 3); /* true */
    { popv(5); return onevalue(v220); }

v82:
    v220 = qvalue(elt(env, 1)); /* nil */
    goto v14;
/* error exit handlers */
v51:
    popv(5);
    return nil;
}



/* Code for mk_rep_mat */

static Lisp_Object CC_mk_rep_mat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_rep_mat");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v8;
    stack[0] = v0;
/* end of prologue */
    v210 = stack[-1];
    v210 = qcar(v210);
    v210 = qcdr(v210);
    v210 = qcar(v210);
    fn = elt(env, 2); /* get!+row!+nr */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-3];
    fn = elt(env, 3); /* mk!+unit!+mat */
    v210 = (*qfn1(fn))(qenv(fn), v210);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-3];
    v59 = v210;
    v210 = stack[0];
    stack[-2] = v210;
    goto v121;

v121:
    v210 = stack[-2];
    if (v210 == nil) { popv(4); return onevalue(v59); }
    v210 = stack[-2];
    v210 = qcar(v210);
    stack[0] = v59;
    v59 = v210;
    v210 = stack[-1];
    fn = elt(env, 4); /* get_rep_of_generator */
    v210 = (*qfn2(fn))(qenv(fn), v59, v210);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-3];
    fn = elt(env, 5); /* mk!+mat!+mult!+mat */
    v210 = (*qfn2(fn))(qenv(fn), stack[0], v210);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-3];
    v59 = v210;
    v210 = stack[-2];
    v210 = qcdr(v210);
    stack[-2] = v210;
    goto v121;
/* error exit handlers */
v76:
    popv(4);
    return nil;
}



/* Code for get_num_part */

static Lisp_Object CC_get_num_part(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v179, v229;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_num_part");
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
    goto v1;

v1:
    v229 = stack[0];
    v179 = (Lisp_Object)1; /* 0 */
    if (v229 == v179) goto v62;
    v179 = stack[0];
    if (is_number(v179)) goto v53;
    v179 = stack[0];
    if (!consp(v179)) goto v50;
    v229 = stack[0];
    v179 = elt(env, 1); /* !:rd!: */
    if (!consp(v229)) goto v230;
    v229 = qcar(v229);
    if (!(v229 == v179)) goto v230;
    v179 = stack[0];
    v179 = qcdr(v179);
    if (!consp(v179)) goto v73;
    v179 = stack[0];
    fn = elt(env, 5); /* bf2flr */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    {
        Lisp_Object v232 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v232, v179);
    }

v73:
    v229 = stack[-1];
    v179 = stack[0];
    v179 = qcdr(v179);
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v229, v179);
    }

v230:
    v229 = stack[0];
    v179 = elt(env, 2); /* !:dn!: */
    if (!consp(v229)) goto v108;
    v229 = qcar(v229);
    if (!(v229 == v179)) goto v108;
    v179 = stack[0];
    v179 = qcdr(v179);
    fn = elt(env, 7); /* rdwrap2 */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    {
        Lisp_Object v233 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v233, v179);
    }

v108:
    v229 = stack[0];
    v179 = elt(env, 3); /* minus */
    if (!consp(v229)) goto v103;
    v229 = qcar(v229);
    if (!(v229 == v179)) goto v103;
    v179 = stack[0];
    v179 = qcdr(v179);
    v179 = qcar(v179);
    v179 = CC_get_num_part(env, v179);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    v229 = v179;
    if (is_number(v229)) goto v234;
    v229 = elt(env, 3); /* minus */
    v179 = list2(v229, v179);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    goto v190;

v190:
    {
        Lisp_Object v235 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v235, v179);
    }

v234:
    v179 = Lfloat(nil, v179);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    v179 = negate(v179);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    goto v190;

v103:
    v229 = stack[0];
    v179 = elt(env, 4); /* expt */
    if (!consp(v229)) goto v236;
    v229 = qcar(v229);
    if (!(v229 == v179)) goto v236;
    v179 = stack[0];
    fn = elt(env, 8); /* rdwrap!-expt */
    v179 = (*qfn1(fn))(qenv(fn), v179);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    {
        Lisp_Object v237 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v237, v179);
    }

v236:
    v179 = stack[0];
    v179 = qcar(v179);
    v229 = CC_get_num_part(env, v179);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    v179 = stack[-1];
    v179 = cons(v229, v179);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    stack[-1] = v179;
    v179 = stack[0];
    v179 = qcdr(v179);
    stack[0] = v179;
    goto v1;

v50:
    v229 = stack[-1];
    v179 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v229, v179);
    }

v53:
    v179 = stack[0];
    v179 = Lfloat(nil, v179);
    nil = C_nil;
    if (exception_pending()) goto v231;
    env = stack[-2];
    {
        Lisp_Object v177 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v177, v179);
    }

v62:
    v229 = stack[-1];
    v179 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v229, v179);
    }
/* error exit handlers */
v231:
    popv(3);
    return nil;
}



/* Code for expttermp1 */

static Lisp_Object CC_expttermp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v72, v65, v34;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for expttermp1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v72 = v8;
    v65 = v0;
/* end of prologue */

v212:
    v117 = v72;
    if (v117 == nil) goto v15;
    v34 = v65;
    v117 = v72;
    v117 = qcar(v117);
    v117 = (equal(v34, v117) ? lisp_true : nil);
    if (!(v117 == nil)) return onevalue(v117);
    v117 = v72;
    v34 = qcar(v117);
    v117 = elt(env, 2); /* expt */
    if (!consp(v34)) goto v84;
    v34 = qcar(v34);
    if (!(v34 == v117)) goto v84;
    v34 = v65;
    v117 = v72;
    v117 = qcar(v117);
    v117 = qcdr(v117);
    v117 = qcar(v117);
    v117 = (equal(v34, v117) ? lisp_true : nil);
    goto v83;

v83:
    if (!(v117 == nil)) return onevalue(v117);
    v117 = v72;
    v117 = qcdr(v117);
    v72 = v117;
    goto v212;

v84:
    v117 = qvalue(elt(env, 1)); /* nil */
    goto v83;

v15:
    v117 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v117);
}



/* Code for xreduce1 */

static Lisp_Object MS_CDECL CC_xreduce1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v66, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v119, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xreduce1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xreduce1");
#endif
    if (stack >= stacklimit)
    {
        push3(v66,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v66);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v66;
    stack[-1] = v8;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v6;

v6:
    v67 = stack[-2];
    v119 = stack[-1];
    v120 = stack[0];
    fn = elt(env, 1); /* weak_xreduce1 */
    v120 = (*qfnn(fn))(qenv(fn), 3, v67, v119, v120);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    stack[-2] = v120;
    if (v120 == nil) goto v90;
    v120 = stack[-2];
    v119 = qcar(v120);
    v120 = stack[-3];
    v120 = cons(v119, v120);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-4];
    stack[-3] = v120;
    v120 = stack[-2];
    v120 = qcdr(v120);
    stack[-2] = v120;
    goto v6;

v90:
    v120 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v120);
    }
/* error exit handlers */
v59:
    popv(5);
    return nil;
}



/* Code for exp!* */

static Lisp_Object CC_expH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v1, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exp*");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v1 = v0;
/* end of prologue */
    v2 = v1;
    v1 = qvalue(elt(env, 1)); /* !:bprec!: */
    {
        fn = elt(env, 2); /* exp!: */
        return (*qfn2(fn))(qenv(fn), v2, v1);
    }
}



/* Code for binc */

static Lisp_Object CC_binc(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v120, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for binc");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    v119 = v0;
/* end of prologue */
    v120 = (Lisp_Object)1; /* 0 */
    v194 = stack[0];
    if (v120 == v194) goto v15;
    v120 = (Lisp_Object)1; /* 0 */
    v194 = stack[0];
    fn = elt(env, 1); /* mk!-numr */
    v194 = (*qfnn(fn))(qenv(fn), 3, v119, v120, v194);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    fn = elt(env, 2); /* constimes */
    stack[-1] = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v194 = stack[0];
    fn = elt(env, 3); /* factorial */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    {
        Lisp_Object v201 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* listquotient */
        return (*qfn2(fn))(qenv(fn), v201, v194);
    }

v15:
    v194 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v194); }
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for make!-image!-mod!-p */

static Lisp_Object CC_makeKimageKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v58, v201;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-image-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v201 = stack[-1];
    v58 = stack[0];
    fn = elt(env, 3); /* degree!-in!-variable */
    v58 = (*qfn2(fn))(qenv(fn), v201, v58);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[-2] = v58;
    v201 = stack[-1];
    v58 = stack[0];
    fn = elt(env, 4); /* make!-univariate!-image!-mod!-p */
    v58 = (*qfn2(fn))(qenv(fn), v201, v58);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    stack[-1] = v58;
    v201 = stack[-1];
    v58 = stack[0];
    fn = elt(env, 3); /* degree!-in!-variable */
    v201 = (*qfn2(fn))(qenv(fn), v201, v58);
    nil = C_nil;
    if (exception_pending()) goto v40;
    env = stack[-3];
    v58 = stack[-2];
    if (equal(v201, v58)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v58 = qvalue(elt(env, 1)); /* t */
    qvalue(elt(env, 2)) = v58; /* unlucky!-case */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v40:
    popv(4);
    return nil;
}



/* Code for intargfn */

static Lisp_Object MS_CDECL CC_intargfn(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v66, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v75, v73, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "intargfn");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intargfn");
#endif
    if (stack >= stacklimit)
    {
        push3(v66,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v66);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v66;
    stack[-2] = v8;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v34 = stack[-3];
    v34 = qcdr(v34);
    stack[0] = v34;
    goto v7;

v7:
    v34 = stack[0];
    if (v34 == nil) goto v50;
    v34 = stack[0];
    v211 = qcar(v34);
    v73 = stack[-2];
    v75 = elt(env, 1); /* integer */
    v34 = stack[-1];
    fn = elt(env, 4); /* convertmode */
    v75 = (*qfnn(fn))(qenv(fn), 4, v211, v73, v75, v34);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-5];
    v34 = stack[-4];
    v34 = cons(v75, v34);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-5];
    stack[-4] = v34;
    v34 = stack[0];
    v34 = qcdr(v34);
    stack[0] = v34;
    goto v7;

v50:
    stack[0] = elt(env, 2); /* list */
    v34 = stack[-3];
    v73 = qcar(v34);
    v75 = stack[-2];
    v34 = elt(env, 3); /* algebraic */
    fn = elt(env, 5); /* form1 */
    stack[-1] = (*qfnn(fn))(qenv(fn), 3, v73, v75, v34);
    nil = C_nil;
    if (exception_pending()) goto v224;
    env = stack[-5];
    v34 = stack[-4];
    fn = elt(env, 6); /* reversip!* */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    nil = C_nil;
    if (exception_pending()) goto v224;
    {
        Lisp_Object v56 = stack[0];
        Lisp_Object v80 = stack[-1];
        popv(6);
        return list2star(v56, v80, v34);
    }
/* error exit handlers */
v224:
    popv(6);
    return nil;
}



/* Code for dp_2a */

static Lisp_Object CC_dp_2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_2a");
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
    v81 = v0;
/* end of prologue */
    v6 = v81;
    if (v6 == nil) goto v36;
    v6 = v81;
    fn = elt(env, 1); /* dp!=2a */
    v6 = (*qfn1(fn))(qenv(fn), v6);
    nil = C_nil;
    if (exception_pending()) goto v121;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* dp!=replus */
        return (*qfn1(fn))(qenv(fn), v6);
    }

v36:
    v6 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v6); }
/* error exit handlers */
v121:
    popv(1);
    return nil;
}



/* Code for solvevars */

static Lisp_Object CC_solvevars(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v194;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvevars");
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
    v194 = v0;
/* end of prologue */
    v79 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v79;
    v79 = v194;
    fn = elt(env, 2); /* allbkern */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    stack[-1] = v79;
    goto v213;

v213:
    v79 = stack[-1];
    if (v79 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v79 = stack[-1];
    v79 = qcar(v79);
    stack[0] = v79;
    v79 = stack[0];
    fn = elt(env, 3); /* constant_exprp */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    if (!(v79 == nil)) goto v3;
    v194 = stack[0];
    v79 = stack[-2];
    fn = elt(env, 4); /* ordad */
    v79 = (*qfn2(fn))(qenv(fn), v194, v79);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-3];
    stack[-2] = v79;
    goto v3;

v3:
    v79 = stack[-1];
    v79 = qcdr(v79);
    stack[-1] = v79;
    goto v213;
/* error exit handlers */
v50:
    popv(4);
    return nil;
}



/* Code for grpbf */

static Lisp_Object CC_grpbf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v172, v173;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for grpbf");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v8;
    stack[-3] = v0;
/* end of prologue */
    v172 = stack[-3];
    v172 = qcdr(v172);
    v173 = qcar(v172);
    v172 = stack[-2];
    v172 = qcdr(v172);
    v172 = qcar(v172);
    stack[-4] = v173;
    stack[-1] = v172;
    v173 = stack[-4];
    v172 = (Lisp_Object)1; /* 0 */
    if (v173 == v172) goto v41;
    v173 = stack[-1];
    v172 = (Lisp_Object)1; /* 0 */
    if (v173 == v172) goto v67;
    v173 = stack[-4];
    v172 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)greaterp2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v172 = v172 ? lisp_true : nil;
    env = stack[-5];
    if (v172 == nil) goto v224;
    v173 = stack[-1];
    v172 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)lessp2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v172 = v172 ? lisp_true : nil;
    env = stack[-5];
    if (v172 == nil) goto v224;
    v172 = qvalue(elt(env, 1)); /* t */
    { popv(6); return onevalue(v172); }

v224:
    v173 = stack[-4];
    v172 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)lessp2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v172 = v172 ? lisp_true : nil;
    env = stack[-5];
    if (v172 == nil) goto v118;
    v173 = stack[-1];
    v172 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)greaterp2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v172 = v172 ? lisp_true : nil;
    env = stack[-5];
    if (v172 == nil) goto v118;
    v172 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v172); }

v118:
    v172 = stack[-3];
    fn = elt(env, 3); /* order!: */
    stack[0] = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-5];
    v172 = stack[-2];
    fn = elt(env, 3); /* order!: */
    v172 = (*qfn1(fn))(qenv(fn), v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-5];
    stack[0] = difference2(stack[0], v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-5];
    v172 = stack[-3];
    v172 = qcdr(v172);
    v173 = qcdr(v172);
    v172 = stack[-2];
    v172 = qcdr(v172);
    v172 = qcdr(v172);
    v172 = difference2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-5];
    stack[-2] = stack[0];
    stack[0] = v172;
    v173 = stack[-2];
    v172 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)greaterp2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v172 = v172 ? lisp_true : nil;
    env = stack[-5];
    if (v172 == nil) goto v188;
    v173 = stack[-4];
    v172 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v173, v172);

v188:
    v173 = stack[-2];
    v172 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)lessp2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v172 = v172 ? lisp_true : nil;
    env = stack[-5];
    if (v172 == nil) goto v226;
    v173 = stack[-4];
    v172 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Llessp(nil, v173, v172);

v226:
    v173 = stack[0];
    v172 = (Lisp_Object)1; /* 0 */
    if (v173 == v172) goto v183;
    v173 = stack[0];
    v172 = (Lisp_Object)1; /* 0 */
    v172 = (Lisp_Object)greaterp2(v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v172 = v172 ? lisp_true : nil;
    env = stack[-5];
    if (v172 == nil) goto v176;
    v173 = stack[-4];
    v172 = stack[0];
    v173 = Lash1(nil, v173, v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    v172 = stack[-1];
        popv(6);
        return Lgreaterp(nil, v173, v172);

v176:
    stack[-2] = stack[-4];
    v172 = stack[0];
    v172 = negate(v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-5];
    v172 = Lash1(nil, stack[-1], v172);
    nil = C_nil;
    if (exception_pending()) goto v247;
    {
        Lisp_Object v170 = stack[-2];
        popv(6);
        return Lgreaterp(nil, v170, v172);
    }

v183:
    v173 = stack[-4];
    v172 = stack[-1];
        popv(6);
        return Lgreaterp(nil, v173, v172);

v67:
    v173 = stack[-4];
    v172 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Lgreaterp(nil, v173, v172);

v41:
    v173 = stack[-1];
    v172 = (Lisp_Object)1; /* 0 */
        popv(6);
        return Llessp(nil, v173, v172);
/* error exit handlers */
v247:
    popv(6);
    return nil;
}



/* Code for cl_gaussintersection */

static Lisp_Object CC_cl_gaussintersection(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_gaussintersection");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v98 = stack[-1];
    v221 = qcar(v98);
    v98 = elt(env, 1); /* gignore */
    if (!(v221 == v98)) goto v76;
    v98 = stack[0];
    v221 = qcar(v98);
    v98 = elt(env, 1); /* gignore */
    if (!(v221 == v98)) goto v76;
    v98 = stack[-1];
    v98 = qcdr(v98);
    v98 = qcdr(v98);
    stack[-2] = Llength(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v98 = stack[0];
    v98 = qcdr(v98);
    v98 = qcdr(v98);
    v98 = Llength(nil, v98);
    nil = C_nil;
    if (exception_pending()) goto v30;
    env = stack[-3];
    v98 = (Lisp_Object)lessp2(stack[-2], v98);
    nil = C_nil;
    if (exception_pending()) goto v30;
    v98 = v98 ? lisp_true : nil;
    if (v98 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v76:
    v98 = stack[-1];
    v221 = qcar(v98);
    v98 = elt(env, 1); /* gignore */
    if (v221 == v98) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v98 = stack[0];
    v221 = qcar(v98);
    v98 = elt(env, 1); /* gignore */
    if (v221 == v98) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v221 = stack[-1];
    v98 = stack[0];
    fn = elt(env, 2); /* rl_bettergaussp */
    v98 = (*qfn2(fn))(qenv(fn), v221, v98);
    nil = C_nil;
    if (exception_pending()) goto v30;
    if (v98 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v30:
    popv(4);
    return nil;
}



/* Code for replace!-nth */

static Lisp_Object MS_CDECL CC_replaceKnth(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v66, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "replace-nth");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for replace-nth");
#endif
    if (stack >= stacklimit)
    {
        push3(v66,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v8,v66);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v66;
    stack[-1] = v8;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v82;

v82:
    v130 = stack[-1];
    v125 = (Lisp_Object)17; /* 1 */
    if (v130 == v125) goto v3;
    v125 = stack[-2];
    v130 = qcar(v125);
    v125 = stack[-3];
    v125 = cons(v130, v125);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-4];
    stack[-3] = v125;
    v125 = stack[-2];
    v125 = qcdr(v125);
    stack[-2] = v125;
    v125 = stack[-1];
    v125 = sub1(v125);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-4];
    stack[-1] = v125;
    goto v82;

v3:
    stack[-1] = stack[-3];
    v130 = stack[0];
    v125 = stack[-2];
    v125 = qcdr(v125);
    v125 = cons(v130, v125);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-4];
    {
        Lisp_Object v57 = stack[-1];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v57, v125);
    }
/* error exit handlers */
v38:
    popv(5);
    return nil;
}



/* Code for conjsq */

static Lisp_Object CC_conjsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v69;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conjsq");
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
    fn = elt(env, 2); /* impartsq */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    stack[-1] = v60;
    v60 = stack[-1];
    v60 = qcar(v60);
    if (v60 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v60 = stack[0];
    fn = elt(env, 3); /* repartsq */
    stack[0] = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    v60 = elt(env, 1); /* i */
    fn = elt(env, 4); /* simp */
    v69 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    v60 = stack[-1];
    fn = elt(env, 5); /* multsq */
    v60 = (*qfn2(fn))(qenv(fn), v69, v60);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    fn = elt(env, 6); /* negsq */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-2];
    {
        Lisp_Object v194 = stack[0];
        popv(3);
        fn = elt(env, 7); /* addsq */
        return (*qfn2(fn))(qenv(fn), v194, v60);
    }
/* error exit handlers */
v79:
    popv(3);
    return nil;
}



/* Code for xpwrlcmp */

static Lisp_Object CC_xpwrlcmp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v127, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpwrlcmp");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v127 = stack[-1];
    if (!consp(v127)) goto v15;
    v132 = stack[-1];
    v127 = elt(env, 1); /* expt */
    if (!consp(v132)) goto v120;
    v132 = qcar(v132);
    if (!(v132 == v127)) goto v120;
    v127 = stack[-1];
    v127 = qcdr(v127);
    v132 = qcar(v127);
    v127 = stack[0];
    if (!(equal(v132, v127))) goto v120;
    v127 = stack[-1];
    v127 = qcdr(v127);
    v127 = qcdr(v127);
    v127 = qcar(v127);
    {
        popv(4);
        fn = elt(env, 3); /* getdenom */
        return (*qfn1(fn))(qenv(fn), v127);
    }

v120:
    v132 = stack[-1];
    v127 = elt(env, 2); /* sqrt */
    if (!consp(v132)) goto v75;
    v132 = qcar(v132);
    if (!(v132 == v127)) goto v75;
    v127 = stack[-1];
    v127 = qcdr(v127);
    v132 = qcar(v127);
    v127 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* getdenomx */
        return (*qfn2(fn))(qenv(fn), v132, v127);
    }

v75:
    v127 = stack[-1];
    v132 = qcar(v127);
    v127 = stack[0];
    stack[-2] = CC_xpwrlcmp(env, v132, v127);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-3];
    v127 = stack[-1];
    v132 = qcdr(v127);
    v127 = stack[0];
    v127 = CC_xpwrlcmp(env, v132, v127);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-3];
    {
        Lisp_Object v230 = stack[-2];
        popv(4);
        fn = elt(env, 5); /* lcm */
        return (*qfn2(fn))(qenv(fn), v230, v127);
    }

v15:
    v127 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v127); }
/* error exit handlers */
v203:
    popv(4);
    return nil;
}



/* Code for gf2bf */

static Lisp_Object CC_gf2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v108, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gf2bf");
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
    goto v15;

v15:
    v110 = stack[0];
    if (v110 == nil) goto v95;
    v110 = stack[0];
    if (!consp(v110)) goto v6;
    v108 = stack[0];
    v110 = elt(env, 1); /* !:rd!: */
    if (!consp(v108)) goto v51;
    v108 = qcar(v108);
    if (!(v108 == v110)) goto v51;
    v110 = stack[0];
    v110 = qcdr(v110);
    if (!consp(v110)) goto v51;
    v108 = stack[-1];
    v110 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v108, v110);
    }

v51:
    v110 = stack[0];
    v110 = qcar(v110);
    v108 = CC_gf2bf(env, v110);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-2];
    v110 = stack[-1];
    v110 = cons(v108, v110);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-2];
    stack[-1] = v110;
    v110 = stack[0];
    v110 = qcdr(v110);
    stack[0] = v110;
    goto v15;

v6:
    v110 = stack[0];
    v110 = Lfloatp(nil, v110);
    env = stack[-2];
    if (v110 == nil) goto v79;
    v110 = stack[0];
    fn = elt(env, 3); /* fl2bf */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-2];
    {
        Lisp_Object v107 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v107, v110);
    }

v79:
    v110 = stack[0];
    if (!consp(v110)) goto v210;
    v110 = stack[0];
    goto v58;

v58:
    fn = elt(env, 4); /* csl_normbf */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-2];
    {
        Lisp_Object v228 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v228, v110);
    }

v210:
    v110 = stack[0];
    v110 = integerp(v110);
    if (v110 == nil) goto v65;
    v26 = elt(env, 1); /* !:rd!: */
    v108 = stack[0];
    v110 = (Lisp_Object)1; /* 0 */
    v110 = list2star(v26, v108, v110);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-2];
    goto v58;

v65:
    v110 = stack[0];
    fn = elt(env, 5); /* read!:num */
    v110 = (*qfn1(fn))(qenv(fn), v110);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-2];
    goto v58;

v95:
    v110 = stack[-1];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v110);
    }
/* error exit handlers */
v249:
    popv(3);
    return nil;
}



/* Code for !:dmexpt */

static Lisp_Object CC_Tdmexpt(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dmexpt");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v8;
    stack[-1] = v0;
/* end of prologue */
    v76 = stack[0];
    fn = elt(env, 2); /* !:dm2fix */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    v125 = v76;
    v125 = integerp(v125);
    if (v125 == nil) goto v3;
    v125 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* !:expt */
        return (*qfn2(fn))(qenv(fn), v125, v76);
    }

v3:
    v76 = stack[-1];
    fn = elt(env, 4); /* force!-to!-dm */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    stack[-1] = v76;
    v76 = stack[0];
    fn = elt(env, 4); /* force!-to!-dm */
    v76 = (*qfn1(fn))(qenv(fn), v76);
    nil = C_nil;
    if (exception_pending()) goto v77;
    env = stack[-2];
    stack[0] = v76;
    v76 = qvalue(elt(env, 1)); /* !*complex */
    if (v76 == nil) goto v58;
    v125 = stack[-1];
    v76 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* crexpt!* */
        return (*qfn2(fn))(qenv(fn), v125, v76);
    }

v58:
    v125 = stack[-1];
    v76 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* rdexpt!* */
        return (*qfn2(fn))(qenv(fn), v125, v76);
    }
/* error exit handlers */
v77:
    popv(3);
    return nil;
}



/* Code for ext_edges */

static Lisp_Object CC_ext_edges(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ext_edges");
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
    goto v15;

v15:
    v72 = stack[0];
    if (v72 == nil) goto v7;
    v72 = stack[0];
    v72 = qcar(v72);
    v65 = qcar(v72);
    v72 = stack[0];
    v72 = qcdr(v72);
    v72 = Lassoc(nil, v65, v72);
    if (!(v72 == nil)) goto v119;
    v72 = stack[0];
    v72 = qcar(v72);
    v65 = qcar(v72);
    v72 = qvalue(elt(env, 1)); /* !_0edge */
    v72 = qcar(v72);
    if (v65 == v72) goto v119;
    v72 = stack[0];
    v65 = qcar(v72);
    v72 = stack[-1];
    v72 = cons(v65, v72);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    stack[-1] = v72;
    v72 = stack[0];
    v72 = qcdr(v72);
    stack[0] = v72;
    goto v15;

v119:
    v72 = stack[0];
    v65 = qcar(v72);
    v72 = stack[0];
    v72 = qcdr(v72);
    fn = elt(env, 2); /* delete_edge */
    v72 = (*qfn2(fn))(qenv(fn), v65, v72);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-2];
    stack[0] = v72;
    goto v15;

v7:
    v72 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v72);
    }
/* error exit handlers */
v73:
    popv(3);
    return nil;
}



/* Code for invbase!* */

static Lisp_Object MS_CDECL CC_invbaseH(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v319, v320, v321, v322;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "invbase*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for invbase*");
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
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* end of prologue */
    stack[-14] = qvalue(elt(env, 1)); /* thirdway */
    qvalue(elt(env, 1)) = nil; /* thirdway */
    stack[-13] = qvalue(elt(env, 2)); /* shortway */
    qvalue(elt(env, 2)) = nil; /* shortway */
    stack[-12] = nil;
    v319 = qvalue(elt(env, 3)); /* !*trinvbase */
    if (v319 == nil) goto v62;
    v319 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    goto v62;

v62:
    v319 = (Lisp_Object)-15; /* -1 */
    qvalue(elt(env, 4)) = v319; /* maxord */
    stack[-11] = v319;
    v319 = qvalue(elt(env, 5)); /* path */
    if (v319 == nil) goto v53;
    v319 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    goto v53;

v53:
    v321 = qvalue(elt(env, 6)); /* nil */
    v320 = qvalue(elt(env, 7)); /* gg */
    v319 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 20); /* redall */
    v319 = (*qfnn(fn))(qenv(fn), 3, v321, v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    qvalue(elt(env, 7)) = v319; /* gg */
    v320 = qvalue(elt(env, 7)); /* gg */
    v319 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 21); /* newbasis */
    v319 = (*qfn2(fn))(qenv(fn), v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = (Lisp_Object)1; /* 0 */
    stack[-10] = v319;
    v319 = qvalue(elt(env, 7)); /* gg */
    stack[0] = v319;
    goto v77;

v77:
    v319 = stack[0];
    if (v319 == nil) goto v128;
    v319 = stack[0];
    v319 = qcar(v319);
    stack[-1] = stack[-10];
    v319 = qcdr(v319);
    fn = elt(env, 22); /* ord */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = plus2(stack[-1], v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    stack[-10] = v319;
    v319 = stack[0];
    v319 = qcdr(v319);
    stack[0] = v319;
    goto v77;

v128:
    stack[0] = stack[-10];
    v319 = qvalue(elt(env, 8)); /* varlist */
    v319 = Llength(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = sub1(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = plus2(stack[0], v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    stack[-10] = v319;
    goto v121;

v121:
    v319 = qvalue(elt(env, 7)); /* gg */
    v319 = Lreverse(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    stack[-15] = v319;
    goto v99;

v99:
    v319 = stack[-15];
    if (v319 == nil) goto v31;
    v320 = qvalue(elt(env, 9)); /* bv */
    v319 = stack[-15];
    v319 = qcar(v319);
    v319 = qcar(v319);
    v319 = *(Lisp_Object *)((char *)v320 + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    if (!(v319 == nil)) goto v31;
    v319 = stack[-15];
    v319 = qcdr(v319);
    stack[-15] = v319;
    goto v99;

v31:
    v319 = stack[-15];
    if (v319 == nil) goto v87;
    v319 = stack[-15];
    v319 = qcar(v319);
    v319 = qcdr(v319);
    v320 = qcar(v319);
    v319 = qvalue(elt(env, 7)); /* gg */
    v319 = qcar(v319);
    v319 = qcdr(v319);
    v319 = qcar(v319);
    if (!(equal(v320, v319))) goto v217;
    v319 = stack[-11];
    v320 = stack[-15];
    v320 = qcar(v320);
    v320 = qcdr(v320);
    v320 = qcar(v320);
    stack[-11] = v320;
    v320 = qvalue(elt(env, 3)); /* !*trinvbase */
    if (v320 == nil) goto v182;
    v320 = stack[-11];
    v319 = (Lisp_Object)greaterp2(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    v319 = v319 ? lisp_true : nil;
    env = stack[-16];
    if (v319 == nil) goto v182;
    v319 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = elt(env, 10); /* "---------- ORDER = " */
    v319 = Lprinc(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = qvalue(elt(env, 7)); /* gg */
    v319 = qcar(v319);
    v319 = qcdr(v319);
    v319 = qcar(v319);
    v319 = Lprinc(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = elt(env, 11); /* " ----------" */
    v319 = Lprinc(nil, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    goto v182;

v182:
    v320 = stack[-11];
    v319 = stack[-10];
    v319 = (Lisp_Object)greaterp2(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    v319 = v319 ? lisp_true : nil;
    env = stack[-16];
    if (v319 == nil) goto v138;
    v321 = qvalue(elt(env, 6)); /* nil */
    v320 = qvalue(elt(env, 7)); /* gg */
    v319 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 20); /* redall */
    v319 = (*qfnn(fn))(qenv(fn), 3, v321, v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    qvalue(elt(env, 7)) = v319; /* gg */
    v320 = qvalue(elt(env, 7)); /* gg */
    v319 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 21); /* newbasis */
    v319 = (*qfn2(fn))(qenv(fn), v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = qvalue(elt(env, 6)); /* nil */
    v319 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    qvalue(elt(env, 12)) = v319; /* alglist!* */
    stack[-9] = elt(env, 13); /* list */
    v319 = qvalue(elt(env, 7)); /* gg */
    stack[-8] = v319;
    v319 = stack[-8];
    if (v319 == nil) goto v324;
    v319 = stack[-8];
    v319 = qcar(v319);
    stack[-4] = elt(env, 14); /* plus */
    v320 = qvalue(elt(env, 15)); /* gv */
    v319 = qcar(v319);
    v319 = *(Lisp_Object *)((char *)v320 + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    stack[-3] = v319;
    v319 = stack[-3];
    if (v319 == nil) goto v325;
    v319 = stack[-3];
    v319 = qcar(v319);
    v320 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = qvalue(elt(env, 8)); /* varlist */
    fn = elt(env, 23); /* !*di2q */
    v319 = (*qfn2(fn))(qenv(fn), v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    fn = elt(env, 24); /* prepsq */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    stack[-1] = v319;
    stack[-2] = v319;
    goto v326;

v326:
    v319 = stack[-3];
    v319 = qcdr(v319);
    stack[-3] = v319;
    v319 = stack[-3];
    if (v319 == nil) goto v327;
    stack[0] = stack[-1];
    v319 = stack[-3];
    v319 = qcar(v319);
    v320 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = qvalue(elt(env, 8)); /* varlist */
    fn = elt(env, 23); /* !*di2q */
    v319 = (*qfn2(fn))(qenv(fn), v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    fn = elt(env, 24); /* prepsq */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = Lrplacd(nil, stack[0], v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = stack[-1];
    v319 = qcdr(v319);
    stack[-1] = v319;
    goto v326;

v327:
    v319 = stack[-2];
    goto v328;

v328:
    v319 = cons(stack[-4], v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    stack[-6] = v319;
    stack[-7] = v319;
    goto v329;

v329:
    v319 = stack[-8];
    v319 = qcdr(v319);
    stack[-8] = v319;
    v319 = stack[-8];
    if (v319 == nil) goto v330;
    stack[-5] = stack[-6];
    v319 = stack[-8];
    v319 = qcar(v319);
    stack[-4] = elt(env, 14); /* plus */
    v320 = qvalue(elt(env, 15)); /* gv */
    v319 = qcar(v319);
    v319 = *(Lisp_Object *)((char *)v320 + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    stack[-3] = v319;
    v319 = stack[-3];
    if (v319 == nil) goto v331;
    v319 = stack[-3];
    v319 = qcar(v319);
    v320 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = qvalue(elt(env, 8)); /* varlist */
    fn = elt(env, 23); /* !*di2q */
    v319 = (*qfn2(fn))(qenv(fn), v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    fn = elt(env, 24); /* prepsq */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    stack[-1] = v319;
    stack[-2] = v319;
    goto v332;

v332:
    v319 = stack[-3];
    v319 = qcdr(v319);
    stack[-3] = v319;
    v319 = stack[-3];
    if (v319 == nil) goto v333;
    stack[0] = stack[-1];
    v319 = stack[-3];
    v319 = qcar(v319);
    v320 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = qvalue(elt(env, 8)); /* varlist */
    fn = elt(env, 23); /* !*di2q */
    v319 = (*qfn2(fn))(qenv(fn), v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    fn = elt(env, 24); /* prepsq */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = Lrplacd(nil, stack[0], v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = stack[-1];
    v319 = qcdr(v319);
    stack[-1] = v319;
    goto v332;

v333:
    v319 = stack[-2];
    goto v157;

v157:
    v319 = cons(stack[-4], v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = Lrplacd(nil, stack[-5], v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = stack[-6];
    v319 = qcdr(v319);
    stack[-6] = v319;
    goto v329;

v331:
    v319 = qvalue(elt(env, 6)); /* nil */
    goto v157;

v330:
    v319 = stack[-7];
    goto v47;

v47:
    v319 = cons(stack[-9], v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    qvalue(elt(env, 16)) = v319; /* invtempbasis */
    v319 = elt(env, 17); /* "Maximum degree bound exceeded." */
    fn = elt(env, 25); /* rederr */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    goto v138;

v138:
    v320 = qvalue(elt(env, 4)); /* maxord */
    v319 = qvalue(elt(env, 7)); /* gg */
    v319 = qcar(v319);
    v319 = qcdr(v319);
    v319 = qcar(v319);
    fn = elt(env, 26); /* max */
    v319 = (*qfn2(fn))(qenv(fn), v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    qvalue(elt(env, 4)) = v319; /* maxord */
    v319 = qvalue(elt(env, 7)); /* gg */
    v319 = qcar(v319);
    v319 = qcdr(v319);
    v320 = qcar(v319);
    v319 = qvalue(elt(env, 4)); /* maxord */
    v319 = (Lisp_Object)lessp2(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    v319 = v319 ? lisp_true : nil;
    env = stack[-16];
    if (v319 == nil) goto v217;
    v319 = qvalue(elt(env, 18)); /* t */
    stack[-12] = v319;
    goto v217;

v217:
    v319 = stack[-12];
    if (!(v319 == nil)) goto v87;
    v319 = stack[-15];
    v319 = qcar(v319);
    v319 = qcar(v319);
    v320 = v319;
    v321 = qvalue(elt(env, 15)); /* gv */
    v319 = v320;
    v319 = *(Lisp_Object *)((char *)v321 + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    stack[-6] = v319;
    v321 = qvalue(elt(env, 9)); /* bv */
    v319 = qvalue(elt(env, 6)); /* nil */
    *(Lisp_Object *)((char *)v321 + (CELL-TAG_VECTOR) + ((int32_t)v320/(16/CELL))) = v319;
    v319 = stack[-6];
    fn = elt(env, 27); /* ljet */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    fn = elt(env, 28); /* class */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    fn = elt(env, 29); /* nonmult */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    stack[-5] = v319;
    goto v334;

v334:
    v319 = stack[-5];
    if (v319 == nil) goto v121;
    v319 = stack[-5];
    v319 = qcar(v319);
    stack[0] = v319;
    v319 = qvalue(elt(env, 19)); /* ng */
    v319 = add1(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    qvalue(elt(env, 19)) = v319; /* ng */
    v320 = stack[-6];
    v319 = stack[0];
    fn = elt(env, 30); /* pdmult */
    v319 = (*qfn2(fn))(qenv(fn), v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v322 = v319;
    v321 = qvalue(elt(env, 15)); /* gv */
    v320 = qvalue(elt(env, 19)); /* ng */
    v319 = v322;
    *(Lisp_Object *)((char *)v321 + (CELL-TAG_VECTOR) + ((int32_t)v320/(16/CELL))) = v319;
    v321 = qvalue(elt(env, 9)); /* bv */
    v320 = qvalue(elt(env, 19)); /* ng */
    v319 = qvalue(elt(env, 18)); /* t */
    *(Lisp_Object *)((char *)v321 + (CELL-TAG_VECTOR) + ((int32_t)v320/(16/CELL))) = v319;
    stack[-1] = qvalue(elt(env, 7)); /* gg */
    stack[0] = qvalue(elt(env, 19)); /* ng */
    v319 = v322;
    fn = elt(env, 27); /* ljet */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = cons(stack[0], v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v320 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 20); /* redall */
    v319 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    qvalue(elt(env, 7)) = v319; /* gg */
    v319 = qvalue(elt(env, 1)); /* thirdway */
    if (v319 == nil) goto v335;
    v320 = qvalue(elt(env, 7)); /* gg */
    v319 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 21); /* newbasis */
    v319 = (*qfn2(fn))(qenv(fn), v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    goto v336;

v336:
    v319 = stack[-5];
    v319 = qcdr(v319);
    stack[-5] = v319;
    goto v334;

v335:
    v319 = qvalue(elt(env, 2)); /* shortway */
    if (v319 == nil) goto v336;
    v319 = qvalue(elt(env, 7)); /* gg */
    stack[-4] = v319;
    goto v337;

v337:
    v319 = stack[-4];
    if (v319 == nil) goto v336;
    v319 = stack[-4];
    v319 = qcar(v319);
    v321 = v319;
    v319 = v321;
    v320 = qcar(v319);
    v319 = qvalue(elt(env, 19)); /* ng */
    if (equal(v320, v319)) goto v338;
    stack[-3] = qvalue(elt(env, 15)); /* gv */
    v319 = v321;
    stack[-2] = qcar(v319);
    v319 = qvalue(elt(env, 15)); /* gv */
    v320 = v321;
    v320 = qcar(v320);
    stack[-1] = *(Lisp_Object *)((char *)v319 + (CELL-TAG_VECTOR) + ((int32_t)v320/(16/CELL)));
    stack[0] = qvalue(elt(env, 19)); /* ng */
    v320 = qvalue(elt(env, 15)); /* gv */
    v319 = qvalue(elt(env, 19)); /* ng */
    v319 = *(Lisp_Object *)((char *)v320 + (CELL-TAG_VECTOR) + ((int32_t)v319/(16/CELL)));
    fn = elt(env, 27); /* ljet */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = cons(stack[0], v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v320 = ncons(v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v319 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 31); /* nf */
    v319 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v319;
    goto v338;

v338:
    v319 = stack[-4];
    v319 = qcdr(v319);
    stack[-4] = v319;
    goto v337;

v87:
    fn = elt(env, 32); /* stat */
    v319 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    v320 = stack[-11];
    v319 = stack[-10];
    v319 = (Lisp_Object)lesseq2(v320, v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    v319 = v319 ? lisp_true : nil;
    env = stack[-16];
    if (v319 == nil) goto v339;
    v319 = qvalue(elt(env, 7)); /* gg */
    fn = elt(env, 33); /* dim */
    v319 = (*qfn1(fn))(qenv(fn), v319);
    nil = C_nil;
    if (exception_pending()) goto v323;
    env = stack[-16];
    goto v339;

v339:
    v319 = nil;
    qvalue(elt(env, 2)) = stack[-13]; /* shortway */
    qvalue(elt(env, 1)) = stack[-14]; /* thirdway */
    { popv(17); return onevalue(v319); }

v325:
    v319 = qvalue(elt(env, 6)); /* nil */
    goto v328;

v324:
    v319 = qvalue(elt(env, 6)); /* nil */
    goto v47;
/* error exit handlers */
v323:
    env = stack[-16];
    qvalue(elt(env, 2)) = stack[-13]; /* shortway */
    qvalue(elt(env, 1)) = stack[-14]; /* thirdway */
    popv(17);
    return nil;
}



/* Code for ofsf_qefsolset */

static Lisp_Object MS_CDECL CC_ofsf_qefsolset(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v8,
                         Lisp_Object v66, Lisp_Object v16,
                         Lisp_Object v36, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v340, v131, v28, v219, v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "ofsf_qefsolset");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_qefsolset");
#endif
    if (stack >= stacklimit)
    {
        push5(v36,v16,v66,v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v8,v66,v16,v36);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v36;
    stack[-1] = v16;
    stack[-2] = v66;
    stack[-3] = v8;
    stack[-4] = v0;
/* end of prologue */
    v340 = stack[-4];
    v131 = qcar(v340);
    v340 = elt(env, 1); /* equal */
    if (v131 == v340) goto v1;
    v340 = elt(env, 2); /* (failed) */
    { popv(6); return onevalue(v340); }

v1:
    v340 = stack[-4];
    fn = elt(env, 7); /* ofsf_varlat */
    v340 = (*qfn1(fn))(qenv(fn), v340);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    v131 = stack[-3];
    v340 = Lmemq(nil, v131, v340);
    if (v340 == nil) goto v83;
    v29 = stack[-4];
    v219 = stack[-3];
    v28 = stack[-2];
    v131 = stack[-1];
    v340 = stack[0];
    {
        popv(6);
        fn = elt(env, 8); /* ofsf_findeqsol */
        return (*qfnn(fn))(qenv(fn), 5, v29, v219, v28, v131, v340);
    }

v83:
    v340 = qvalue(elt(env, 3)); /* !*rlqegen */
    if (v340 == nil) goto v71;
    v131 = stack[0];
    v340 = stack[-4];
    v340 = qcdr(v340);
    v340 = qcar(v340);
    fn = elt(env, 9); /* ofsf_valassp */
    v340 = (*qfn2(fn))(qenv(fn), v131, v340);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    if (v340 == nil) goto v71;
    stack[-1] = elt(env, 4); /* gignore */
    stack[0] = qvalue(elt(env, 5)); /* nil */
    v28 = elt(env, 6); /* neq */
    v340 = stack[-4];
    v340 = qcdr(v340);
    v131 = qcar(v340);
    v340 = qvalue(elt(env, 5)); /* nil */
    v340 = list3(v28, v131, v340);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-5];
    v340 = ncons(v340);
    nil = C_nil;
    if (exception_pending()) goto v92;
    {
        Lisp_Object v110 = stack[-1];
        Lisp_Object v108 = stack[0];
        popv(6);
        return list2star(v110, v108, v340);
    }

v71:
    v340 = elt(env, 2); /* (failed) */
    { popv(6); return onevalue(v340); }
/* error exit handlers */
v92:
    popv(6);
    return nil;
}



/* Code for conjgd */

static Lisp_Object CC_conjgd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v342, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for conjgd");
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
    v342 = stack[-1];
    if (!consp(v342)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v342 = stack[-1];
    if (!consp(v342)) goto v4;
    v342 = stack[-1];
    v342 = qcar(v342);
    if (!(!consp(v342))) goto v82;

v4:
    v342 = stack[-1];
    v93 = qcar(v342);
    v342 = elt(env, 1); /* cmpxfn */
    v342 = get(v93, v342);
    env = stack[-3];
    v93 = v342;
    if (v342 == nil) goto v82;
    stack[-2] = v93;
    v342 = stack[-1];
    v342 = qcdr(v342);
    stack[0] = qcar(v342);
    v342 = stack[-1];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    if (is_number(v342)) goto v201;
    v342 = stack[-1];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    if (!consp(v342)) goto v71;
    v342 = stack[-1];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = qcar(v342);
    if (!(!consp(v342))) goto v98;

v71:
    v342 = stack[-1];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = qcar(v342);
    if (is_number(v342)) goto v98;
    v342 = stack[-1];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    fn = elt(env, 3); /* !:minus */
    v342 = (*qfn1(fn))(qenv(fn), v342);
    nil = C_nil;
    if (exception_pending()) goto v122;
    goto v78;

v78:
    {
        Lisp_Object v123 = stack[-2];
        Lisp_Object v124 = stack[0];
        popv(4);
        return Lapply2(nil, 3, v123, v124, v342);
    }

v98:
    v342 = stack[-1];
    v93 = qcar(v342);
    v342 = elt(env, 2); /* realtype */
    v93 = get(v93, v342);
    env = stack[-3];
    v342 = stack[-1];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = cons(v93, v342);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    fn = elt(env, 3); /* !:minus */
    v342 = (*qfn1(fn))(qenv(fn), v342);
    nil = C_nil;
    if (exception_pending()) goto v122;
    v342 = qcdr(v342);
    goto v78;

v201:
    v342 = stack[-1];
    v342 = qcdr(v342);
    v342 = qcdr(v342);
    v342 = negate(v342);
    nil = C_nil;
    if (exception_pending()) goto v122;
    goto v78;

v82:
    v342 = stack[-1];
    if (!consp(v342)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v342 = stack[-1];
    v342 = qcar(v342);
    if (!consp(v342)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v342 = stack[-1];
    v342 = qcar(v342);
    v93 = qcar(v342);
    v342 = (Lisp_Object)17; /* 1 */
    v342 = cons(v93, v342);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    stack[0] = ncons(v342);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v342 = stack[-1];
    v342 = qcar(v342);
    v342 = qcdr(v342);
    v342 = CC_conjgd(env, v342);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    fn = elt(env, 4); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v342);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    v342 = stack[-1];
    v342 = qcdr(v342);
    v342 = CC_conjgd(env, v342);
    nil = C_nil;
    if (exception_pending()) goto v122;
    env = stack[-3];
    {
        Lisp_Object v216 = stack[0];
        popv(4);
        fn = elt(env, 5); /* addf */
        return (*qfn2(fn))(qenv(fn), v216, v342);
    }
/* error exit handlers */
v122:
    popv(4);
    return nil;
}



/* Code for aex_mult */

static Lisp_Object CC_aex_mult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mult");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v8;
    stack[-2] = v0;
/* end of prologue */
    v59 = stack[-2];
    fn = elt(env, 2); /* aex_ex */
    stack[0] = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    v59 = stack[-1];
    fn = elt(env, 2); /* aex_ex */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    fn = elt(env, 3); /* ratpoly_mult */
    stack[-3] = (*qfn2(fn))(qenv(fn), stack[0], v59);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    v59 = stack[-2];
    fn = elt(env, 4); /* aex_ctx */
    stack[0] = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    v59 = stack[-1];
    fn = elt(env, 4); /* aex_ctx */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    fn = elt(env, 5); /* ctx_union */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v59);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    v59 = stack[-2];
    fn = elt(env, 6); /* aex_lcnttag */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    if (v59 == nil) goto v78;
    v59 = stack[-1];
    fn = elt(env, 6); /* aex_lcnttag */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v130;
    env = stack[-4];
    v39 = v59;
    goto v1;

v1:
    v59 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v102 = stack[-3];
        Lisp_Object v77 = stack[0];
        popv(5);
        fn = elt(env, 7); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v102, v77, v39, v59);
    }

v78:
    v59 = qvalue(elt(env, 1)); /* nil */
    v39 = v59;
    goto v1;
/* error exit handlers */
v130:
    popv(5);
    return nil;
}



/* Code for !*s2i */

static Lisp_Object CC_Hs2i(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v3;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *s2i");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v70 = v3;
    v70 = integerp(v70);
    if (!(v70 == nil)) return onevalue(v3);
    v70 = elt(env, 1); /* "integer" */
    {
        fn = elt(env, 2); /* typerr */
        return (*qfn2(fn))(qenv(fn), v3, v70);
    }
}



/* Code for bfdivide */

static Lisp_Object CC_bfdivide(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v53, v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfdivide");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v53 = v8;
    v60 = v0;
/* end of prologue */
    v89 = v60;
    if (!consp(v89)) goto v48;
    v89 = qvalue(elt(env, 1)); /* !:bprec!: */
    fn = elt(env, 2); /* divide!: */
    v89 = (*qfnn(fn))(qenv(fn), 3, v60, v53, v89);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v89);
    }

v48:
    v89 = v60;
    popv(1);
    return quot2(v89, v53);
/* error exit handlers */
v69:
    popv(1);
    return nil;
}



/* Code for calc_map_ */

static Lisp_Object CC_calc_map_(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v8)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v190, v191, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for calc_map_");
#endif
    if (stack >= stacklimit)
    {
        push2(v8,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v8);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v8;
    v191 = v0;
/* end of prologue */
    v190 = v191;
    v190 = qcar(v190);
    stack[-2] = v190;
    v190 = v191;
    v190 = qcdr(v190);
    v190 = qcar(v190);
    stack[-5] = v190;
    v190 = v191;
    v190 = qcdr(v190);
    v190 = qcdr(v190);
    v190 = qcar(v190);
    stack[-3] = v190;
    v190 = v191;
    v190 = qcdr(v190);
    v190 = qcdr(v190);
    v190 = qcdr(v190);
    stack[-1] = v190;
    v191 = stack[-4];
    v190 = stack[-2];
    fn = elt(env, 2); /* actual_alst */
    v190 = (*qfn2(fn))(qenv(fn), v191, v190);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-6];
    stack[0] = v190;
    v190 = stack[0];
    if (!(v190 == nil)) goto v58;
    v190 = stack[-2];
    if (v190 == nil) goto v58;
    v190 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(v190); }

v58:
    v191 = stack[0];
    v190 = stack[-3];
    v190 = qcdr(v190);
    v190 = Lassoc(nil, v191, v190);
    stack[-2] = v190;
    v190 = stack[-2];
    if (v190 == nil) goto v65;
    v190 = stack[-2];
    v190 = qcdr(v190);
    stack[-2] = v190;
    goto v203;

v203:
    v191 = stack[-1];
    v190 = stack[-4];
    fn = elt(env, 3); /* calc_den_tar */
    v190 = (*qfn2(fn))(qenv(fn), v191, v190);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-6];
    v24 = v190;
    v191 = v24;
    v190 = (Lisp_Object)17; /* 1 */
    if (v191 == v190) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    v191 = elt(env, 1); /* quotient */
    v190 = stack[-2];
    popv(7);
    return list3(v191, v190, v24);

v65:
    v191 = stack[-5];
    v190 = stack[0];
    fn = elt(env, 4); /* calc_map_tar */
    v190 = (*qfn2(fn))(qenv(fn), v191, v190);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-6];
    fn = elt(env, 5); /* reval */
    v190 = (*qfn1(fn))(qenv(fn), v190);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-6];
    stack[-2] = v190;
    v191 = stack[0];
    v190 = stack[-2];
    v190 = cons(v191, v190);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-6];
    v190 = ncons(v190);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-6];
    v190 = Lnconc(nil, stack[-3], v190);
    nil = C_nil;
    if (exception_pending()) goto v341;
    env = stack[-6];
    goto v203;
/* error exit handlers */
v341:
    popv(7);
    return nil;
}



setup_type const u42_setup[] =
{
    {"i2cr*",                   CC_i2crH,       too_many_1,    wrong_no_1},
    {"rule-list",               too_few_2,      CC_ruleKlist,  wrong_no_2},
    {"freeof-df",               too_few_2,      CC_freeofKdf,  wrong_no_2},
    {"operator",                CC_operator,    too_many_1,    wrong_no_1},
    {"product-set2",            too_few_2,      CC_productKset2,wrong_no_2},
    {"groebsimpcontnormalform", CC_groebsimpcontnormalform,too_many_1,wrong_no_1},
    {"evalsubset",              too_few_2,      CC_evalsubset, wrong_no_2},
    {"gffdot",                  too_few_2,      CC_gffdot,     wrong_no_2},
    {"clogsq",                  CC_clogsq,      too_many_1,    wrong_no_1},
    {"dp_from_a",               CC_dp_from_a,   too_many_1,    wrong_no_1},
    {"boolean-eval2",           CC_booleanKeval2,too_many_1,   wrong_no_1},
    {"general-negate-term",     CC_generalKnegateKterm,too_many_1,wrong_no_1},
    {"preptaylor*2",            too_few_2,      CC_preptaylorH2,wrong_no_2},
    {"letscalar",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_letscalar},
    {"nonpolyp",                too_few_2,      CC_nonpolyp,   wrong_no_2},
    {"dvfsf_0mk2",              too_few_2,      CC_dvfsf_0mk2, wrong_no_2},
    {"vp1",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_vp1},
    {"ps:constmult-erule",      too_few_2,      CC_psTconstmultKerule,wrong_no_2},
    {"subeval",                 CC_subeval,     too_many_1,    wrong_no_1},
    {"matrix_input_test",       CC_matrix_input_test,too_many_1,wrong_no_1},
    {"fast_setmat",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_fast_setmat},
    {"indexvp",                 CC_indexvp,     too_many_1,    wrong_no_1},
    {"lf=less",                 too_few_2,      CC_lfMless,    wrong_no_2},
    {"st_flatten",              CC_st_flatten,  too_many_1,    wrong_no_1},
    {"ofsf_chsimpat",           CC_ofsf_chsimpat,too_many_1,   wrong_no_1},
    {"mk_rep_mat",              too_few_2,      CC_mk_rep_mat, wrong_no_2},
    {"get_num_part",            CC_get_num_part,too_many_1,    wrong_no_1},
    {"expttermp1",              too_few_2,      CC_expttermp1, wrong_no_2},
    {"xreduce1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreduce1},
    {"exp*",                    CC_expH,        too_many_1,    wrong_no_1},
    {"binc",                    too_few_2,      CC_binc,       wrong_no_2},
    {"make-image-mod-p",        too_few_2,      CC_makeKimageKmodKp,wrong_no_2},
    {"intargfn",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_intargfn},
    {"dp_2a",                   CC_dp_2a,       too_many_1,    wrong_no_1},
    {"solvevars",               CC_solvevars,   too_many_1,    wrong_no_1},
    {"grpbf",                   too_few_2,      CC_grpbf,      wrong_no_2},
    {"cl_gaussintersection",    too_few_2,      CC_cl_gaussintersection,wrong_no_2},
    {"replace-nth",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_replaceKnth},
    {"conjsq",                  CC_conjsq,      too_many_1,    wrong_no_1},
    {"xpwrlcmp",                too_few_2,      CC_xpwrlcmp,   wrong_no_2},
    {"gf2bf",                   CC_gf2bf,       too_many_1,    wrong_no_1},
    {":dmexpt",                 too_few_2,      CC_Tdmexpt,    wrong_no_2},
    {"ext_edges",               CC_ext_edges,   too_many_1,    wrong_no_1},
    {"invbase*",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_invbaseH},
    {"ofsf_qefsolset",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_qefsolset},
    {"conjgd",                  CC_conjgd,      too_many_1,    wrong_no_1},
    {"aex_mult",                too_few_2,      CC_aex_mult,   wrong_no_2},
    {"*s2i",                    CC_Hs2i,        too_many_1,    wrong_no_1},
    {"bfdivide",                too_few_2,      CC_bfdivide,   wrong_no_2},
    {"calc_map_",               too_few_2,      CC_calc_map_,  wrong_no_2},
    {NULL, (one_args *)"u42", (two_args *)"17132 930876 5402265", 0}
};

/* end of generated code */
