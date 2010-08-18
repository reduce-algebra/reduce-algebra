
/* $destdir/generated-c\u45.c Machine generated C code */

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


/* Code for mchcomb */

static Lisp_Object MS_CDECL CC_mchcomb(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67, v68, v69, v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mchcomb");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mchcomb");
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
/* copy arguments values to proper place */
    stack[-6] = v2;
    stack[-7] = v1;
    stack[-8] = v0;
/* end of prologue */
    v67 = stack[-8];
    stack[0] = Llength(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v67 = stack[-7];
    v67 = Llength(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v67 = difference2(stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v67 = add1(v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    stack[0] = v67;
    v68 = stack[0];
    v67 = (Lisp_Object)17; /* 1 */
    v67 = (Lisp_Object)lessp2(v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    v67 = v67 ? lisp_true : nil;
    env = stack[-10];
    if (v67 == nil) goto v73;
    v67 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v67); }

v73:
    v68 = stack[0];
    v67 = (Lisp_Object)17; /* 1 */
    if (v68 == v67) goto v74;
    v68 = qvalue(elt(env, 2)); /* frlis!* */
    v67 = stack[-7];
    fn = elt(env, 4); /* smemqlp */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    if (v67 == nil) goto v75;
    v68 = stack[-8];
    v67 = stack[0];
    fn = elt(env, 5); /* comb */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    stack[-9] = v67;
    goto v76;

v76:
    v67 = stack[-9];
    if (v67 == nil) goto v77;
    v67 = stack[-9];
    v67 = qcar(v67);
    stack[-2] = v67;
    v67 = qvalue(elt(env, 3)); /* ncmp!* */
    if (v67 == nil) goto v78;
    v71 = stack[-2];
    v70 = stack[-8];
    v69 = qvalue(elt(env, 1)); /* nil */
    v68 = qvalue(elt(env, 1)); /* nil */
    v67 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 6); /* mchcomb2 */
    v67 = (*qfnn(fn))(qenv(fn), 5, v71, v70, v69, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    stack[0] = v67;
    v67 = stack[0];
    if (v67 == nil) goto v79;
    v69 = stack[-6];
    v68 = stack[-2];
    v67 = stack[0];
    v67 = qcar(v67);
    stack[-1] = acons(v69, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v67 = stack[0];
    v67 = qcdr(v67);
    if (v67 == nil) goto v80;
    v67 = stack[-7];
    v67 = Lreverse(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v68 = v67;
    goto v81;

v81:
    v67 = stack[-6];
    fn = elt(env, 7); /* mchsarg */
    v67 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    goto v82;

v82:
    stack[-5] = v67;
    v67 = stack[-5];
    fn = elt(env, 8); /* lastpair */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    stack[-4] = v67;
    v67 = stack[-9];
    v67 = qcdr(v67);
    stack[-9] = v67;
    v67 = stack[-4];
    if (!consp(v67)) goto v76;
    else goto v83;

v83:
    v67 = stack[-9];
    if (v67 == nil) { Lisp_Object res = stack[-5]; popv(11); return onevalue(res); }
    stack[-3] = stack[-4];
    v67 = stack[-9];
    v67 = qcar(v67);
    stack[-2] = v67;
    v67 = qvalue(elt(env, 3)); /* ncmp!* */
    if (v67 == nil) goto v84;
    v71 = stack[-2];
    v70 = stack[-8];
    v69 = qvalue(elt(env, 1)); /* nil */
    v68 = qvalue(elt(env, 1)); /* nil */
    v67 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 6); /* mchcomb2 */
    v67 = (*qfnn(fn))(qenv(fn), 5, v71, v70, v69, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    stack[0] = v67;
    v67 = stack[0];
    if (v67 == nil) goto v85;
    v69 = stack[-6];
    v68 = stack[-2];
    v67 = stack[0];
    v67 = qcar(v67);
    stack[-1] = acons(v69, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v67 = stack[0];
    v67 = qcdr(v67);
    if (v67 == nil) goto v86;
    v67 = stack[-7];
    v67 = Lreverse(nil, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v68 = v67;
    goto v87;

v87:
    v67 = stack[-6];
    fn = elt(env, 7); /* mchsarg */
    v67 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    goto v88;

v88:
    v67 = Lrplacd(nil, stack[-3], v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v67 = stack[-4];
    fn = elt(env, 8); /* lastpair */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    stack[-4] = v67;
    v67 = stack[-9];
    v67 = qcdr(v67);
    stack[-9] = v67;
    goto v83;

v86:
    v67 = stack[-7];
    v68 = v67;
    goto v87;

v85:
    v67 = qvalue(elt(env, 1)); /* nil */
    goto v88;

v84:
    stack[-1] = stack[-6];
    stack[0] = stack[-2];
    v68 = stack[-8];
    v67 = stack[-2];
    fn = elt(env, 9); /* setdiff */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v69 = acons(stack[-1], stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v68 = stack[-7];
    v67 = stack[-6];
    fn = elt(env, 7); /* mchsarg */
    v67 = (*qfnn(fn))(qenv(fn), 3, v69, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    goto v88;

v80:
    v67 = stack[-7];
    v68 = v67;
    goto v81;

v79:
    v67 = qvalue(elt(env, 1)); /* nil */
    goto v82;

v78:
    stack[-1] = stack[-6];
    stack[0] = stack[-2];
    v68 = stack[-8];
    v67 = stack[-2];
    fn = elt(env, 9); /* setdiff */
    v67 = (*qfn2(fn))(qenv(fn), v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v69 = acons(stack[-1], stack[0], v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    v68 = stack[-7];
    v67 = stack[-6];
    fn = elt(env, 7); /* mchsarg */
    v67 = (*qfnn(fn))(qenv(fn), 3, v69, v68, v67);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-10];
    goto v82;

v77:
    v67 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v67); }

v75:
    v67 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v67); }

v74:
    v69 = stack[-8];
    v68 = stack[-7];
    v67 = stack[-6];
    {
        popv(11);
        fn = elt(env, 7); /* mchsarg */
        return (*qfnn(fn))(qenv(fn), 3, v69, v68, v67);
    }
/* error exit handlers */
v72:
    popv(11);
    return nil;
}



/* Code for numpoly_nullp */

static Lisp_Object CC_numpoly_nullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v91;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_nullp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v65 = v0;
/* end of prologue */
    v91 = v65;
    v91 = (v91 == nil ? lisp_true : nil);
    if (!(v91 == nil)) return onevalue(v91);
    v91 = v65;
    v65 = (Lisp_Object)1; /* 0 */
    v65 = (v91 == v65 ? lisp_true : nil);
    return onevalue(v65);
}



/* Code for bra_mk */

static Lisp_Object MS_CDECL CC_bra_mk(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v65, v91, v66;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "bra_mk");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bra_mk");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v65 = v2;
    v91 = v1;
    v66 = v0;
/* end of prologue */
    return list3(v66, v91, v65);
}



/* Code for cos!: */

static Lisp_Object CC_cosT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v183, v184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cos:");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-11] = v1;
    stack[0] = v0;
/* end of prologue */

v185:
    v182 = stack[-11];
    v182 = integerp(v182);
    if (v182 == nil) goto v186;
    v183 = stack[-11];
    v182 = (Lisp_Object)1; /* 0 */
    v182 = (Lisp_Object)lesseq2(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v187;
    v182 = v182 ? lisp_true : nil;
    env = stack[-13];
    if (!(v182 == nil)) goto v186;
    v182 = stack[0];
    fn = elt(env, 6); /* bfzerop!: */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-13];
    if (v182 == nil) goto v188;
    v182 = qvalue(elt(env, 1)); /* bfone!* */
    { popv(14); return onevalue(v182); }

v188:
    v182 = stack[0];
    fn = elt(env, 7); /* minusp!: */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-13];
    if (v182 == nil) goto v189;
    v182 = stack[0];
    fn = elt(env, 8); /* minus!: */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-13];
    stack[0] = v182;
    goto v185;

v189:
    stack[-6] = qvalue(elt(env, 2)); /* !!sclc */
    qvalue(elt(env, 2)) = nil; /* !!sclc */
    v183 = stack[-11];
    v182 = (Lisp_Object)113; /* 7 */
    v182 = plus2(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-12] = v182;
    v182 = stack[0];
    v182 = qcdr(v182);
    v182 = qcar(v182);
    v182 = Labsval(nil, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    fn = elt(env, 9); /* msd */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-10] = v182;
    v183 = stack[-12];
    v182 = stack[-10];
    v182 = plus2(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    fn = elt(env, 10); /* !:pi */
    v183 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = qvalue(elt(env, 3)); /* !:bf!-0!.25 */
    fn = elt(env, 11); /* times!: */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-1] = v182;
    v183 = stack[0];
    v182 = stack[-1];
    fn = elt(env, 12); /* lessp!: */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    if (v182 == nil) goto v47;
    v182 = (Lisp_Object)1; /* 0 */
    stack[-10] = v182;
    v182 = stack[0];
    stack[-8] = v182;
    goto v191;

v191:
    v182 = qvalue(elt(env, 1)); /* bfone!* */
    stack[-9] = v182;
    v183 = stack[-10];
    v182 = (Lisp_Object)129; /* 8 */
    v182 = (Lisp_Object)geq2(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    v182 = v182 ? lisp_true : nil;
    env = stack[-13];
    if (v182 == nil) goto v192;
    v183 = stack[-10];
    v182 = (Lisp_Object)129; /* 8 */
    v182 = Cremainder(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-10] = v182;
    goto v192;

v192:
    v183 = stack[-10];
    v182 = (Lisp_Object)65; /* 4 */
    v182 = (Lisp_Object)geq2(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    v182 = v182 ? lisp_true : nil;
    env = stack[-13];
    if (v182 == nil) goto v193;
    v182 = stack[-9];
    fn = elt(env, 8); /* minus!: */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-9] = v182;
    v183 = stack[-10];
    v182 = (Lisp_Object)65; /* 4 */
    v182 = difference2(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-10] = v182;
    goto v193;

v193:
    v183 = stack[-10];
    v182 = (Lisp_Object)33; /* 2 */
    v182 = (Lisp_Object)geq2(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    v182 = v182 ? lisp_true : nil;
    env = stack[-13];
    if (v182 == nil) goto v194;
    v182 = stack[-9];
    fn = elt(env, 8); /* minus!: */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-9] = v182;
    goto v194;

v194:
    v183 = stack[-10];
    v182 = (Lisp_Object)1; /* 0 */
    if (v183 == v182) goto v195;
    v183 = stack[-10];
    v182 = (Lisp_Object)17; /* 1 */
    if (v183 == v182) goto v196;
    v183 = stack[-10];
    v182 = (Lisp_Object)33; /* 2 */
    if (v183 == v182) goto v197;
    v183 = stack[-1];
    v182 = stack[-8];
    fn = elt(env, 13); /* difference!: */
    v183 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = stack[-12];
    fn = elt(env, 14); /* cut!:mt */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-8] = v182;
    goto v195;

v195:
    stack[-1] = elt(env, 4); /* !:rd!: */
    stack[0] = (Lisp_Object)33; /* 2 */
    v182 = stack[-12];
    v182 = negate(v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = list2star(stack[-1], stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-4] = v182;
    v182 = qvalue(elt(env, 1)); /* bfone!* */
    stack[0] = v182;
    stack[-2] = v182;
    stack[-7] = v182;
    v183 = stack[-8];
    v182 = stack[-8];
    fn = elt(env, 11); /* times!: */
    stack[-1] = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = stack[-12];
    v182 = negate(v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    fn = elt(env, 15); /* cut!:ep */
    v182 = (*qfn2(fn))(qenv(fn), stack[-1], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    fn = elt(env, 8); /* minus!: */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-8] = v182;
    v182 = (Lisp_Object)17; /* 1 */
    stack[-10] = v182;
    v182 = (Lisp_Object)1; /* 0 */
    stack[-5] = v182;
    goto v198;

v198:
    v182 = stack[0];
    fn = elt(env, 16); /* abs!: */
    v183 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = stack[-4];
    fn = elt(env, 17); /* greaterp!: */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    if (v182 == nil) goto v199;
    v183 = stack[-5];
    v182 = (Lisp_Object)33; /* 2 */
    v182 = plus2(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-5] = v182;
    stack[-1] = elt(env, 4); /* !:rd!: */
    stack[-3] = stack[-10];
    stack[0] = stack[-5];
    v182 = stack[-5];
    v182 = sub1(v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = times2(stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v183 = times2(stack[-3], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-10] = v183;
    v182 = (Lisp_Object)1; /* 0 */
    v182 = list2star(stack[-1], v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-3] = v182;
    v183 = stack[-2];
    v182 = stack[-8];
    fn = elt(env, 11); /* times!: */
    stack[0] = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = stack[-12];
    v182 = negate(v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    fn = elt(env, 15); /* cut!:ep */
    v182 = (*qfn2(fn))(qenv(fn), stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-2] = v182;
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = stack[-12];
    v182 = stack[-3];
    fn = elt(env, 18); /* order!: */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[0] = difference2(stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = stack[-2];
    fn = elt(env, 18); /* order!: */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = plus2(stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    fn = elt(env, 19); /* max */
    v182 = (*qfn2(fn))(qenv(fn), stack[-1], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v184 = stack[-2];
    v183 = stack[-3];
    fn = elt(env, 20); /* divide!: */
    v182 = (*qfnn(fn))(qenv(fn), 3, v184, v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[0] = v182;
    v183 = stack[-7];
    v182 = stack[0];
    fn = elt(env, 21); /* plus!: */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-7] = v182;
    v183 = stack[-5];
    v182 = (Lisp_Object)321; /* 20 */
    v182 = Cremainder(v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = (Lisp_Object)zerop(v182);
    v182 = v182 ? lisp_true : nil;
    env = stack[-13];
    if (v182 == nil) goto v198;
    stack[-1] = stack[-7];
    v182 = stack[-12];
    v182 = negate(v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    fn = elt(env, 15); /* cut!:ep */
    v182 = (*qfn2(fn))(qenv(fn), stack[-1], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-7] = v182;
    goto v198;

v199:
    v183 = stack[-9];
    v182 = stack[-7];
    fn = elt(env, 11); /* times!: */
    v183 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = stack[-11];
    fn = elt(env, 22); /* round!:mt */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    goto v200;

v200:
    qvalue(elt(env, 2)) = stack[-6]; /* !!sclc */
    { popv(14); return onevalue(v182); }

v197:
    v183 = stack[-8];
    v182 = stack[-12];
    fn = elt(env, 14); /* cut!:mt */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-8] = v182;
    v182 = stack[0];
    qvalue(elt(env, 2)) = v182; /* !!sclc */
    stack[0] = stack[-9];
    v183 = stack[-8];
    v182 = stack[-11];
    fn = elt(env, 23); /* sin!: */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    fn = elt(env, 11); /* times!: */
    v182 = (*qfn2(fn))(qenv(fn), stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    goto v200;

v196:
    v183 = stack[-1];
    v182 = stack[-8];
    fn = elt(env, 13); /* difference!: */
    v183 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    v182 = stack[-12];
    fn = elt(env, 14); /* cut!:mt */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-8] = v182;
    v182 = stack[0];
    qvalue(elt(env, 2)) = v182; /* !!sclc */
    stack[0] = stack[-9];
    v183 = stack[-8];
    v182 = stack[-11];
    fn = elt(env, 23); /* sin!: */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    fn = elt(env, 11); /* times!: */
    v182 = (*qfn2(fn))(qenv(fn), stack[0], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    goto v200;

v47:
    v183 = stack[0];
    v182 = stack[-1];
    fn = elt(env, 24); /* quotient!: */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-3] = v182;
    fn = elt(env, 25); /* conv!:bf2i */
    v182 = (*qfn1(fn))(qenv(fn), v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-10] = v182;
    stack[-2] = stack[0];
    v183 = stack[-3];
    v182 = stack[-1];
    fn = elt(env, 11); /* times!: */
    v182 = (*qfn2(fn))(qenv(fn), v183, v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    fn = elt(env, 13); /* difference!: */
    v182 = (*qfn2(fn))(qenv(fn), stack[-2], v182);
    nil = C_nil;
    if (exception_pending()) goto v190;
    env = stack[-13];
    stack[-8] = v182;
    goto v191;

v186:
    v182 = elt(env, 0); /* cos!: */
    {
        popv(14);
        fn = elt(env, 26); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v182);
    }
/* error exit handlers */
v190:
    env = stack[-13];
    qvalue(elt(env, 2)) = stack[-6]; /* !!sclc */
    popv(14);
    return nil;
v187:
    popv(14);
    return nil;
}



/* Code for fortexp1 */

static Lisp_Object CC_fortexp1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v321, v322, v323;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortexp1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-1] = v0;
/* end of prologue */

v185:
    v321 = stack[-1];
    if (!consp(v321)) goto v186;
    v321 = stack[-1];
    fn = elt(env, 27); /* listp */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    if (v321 == nil) goto v65;
    v321 = stack[-1];
    v321 = Llength(nil, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lonep(nil, v321);
    env = stack[-9];
    if (v321 == nil) goto v65;
    v321 = stack[-1];
    {
        popv(10);
        fn = elt(env, 28); /* fortranname */
        return (*qfn1(fn))(qenv(fn), v321);
    }

v65:
    v321 = stack[-1];
    v321 = qcar(v321);
    fn = elt(env, 29); /* optype */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    if (v321 == nil) goto v13;
    v321 = stack[-1];
    v321 = qcar(v321);
    fn = elt(env, 30); /* fortranprecedence */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[-4] = v321;
    v321 = stack[-1];
    v321 = qcar(v321);
    fn = elt(env, 31); /* fortranop */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[-2] = v321;
    v321 = stack[-1];
    v321 = qcdr(v321);
    stack[-1] = v321;
    v321 = stack[-1];
    v321 = Llength(nil, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lonep(nil, v321);
    env = stack[-9];
    if (v321 == nil) goto v83;
    stack[0] = stack[-2];
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = stack[-4];
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = cons(stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = v321;
    goto v325;

v325:
    v322 = stack[-3];
    v321 = stack[-4];
    v321 = (Lisp_Object)geq2(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    v321 = v321 ? lisp_true : nil;
    env = stack[-9];
    if (v321 == nil) { Lisp_Object res = stack[0]; popv(10); return onevalue(res); }
    v321 = stack[0];
    fn = elt(env, 32); /* insertparens */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    stack[0] = v321;
    { Lisp_Object res = stack[0]; popv(10); return onevalue(res); }

v83:
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = stack[-4];
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = v321;
    v322 = stack[-2];
    v321 = elt(env, 1); /* !+ */
    if (v322 == v321) goto v326;
    v322 = stack[-2];
    v321 = elt(env, 4); /* !*!* */
    if (!(v322 == v321)) goto v149;

v327:
    v321 = stack[-1];
    v321 = qcdr(v321);
    stack[-1] = v321;
    if (v321 == nil) goto v325;
    v321 = stack[-1];
    v321 = qcar(v321);
    if (!(is_number(v321))) goto v328;
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = (Lisp_Object)1; /* 0 */
    v321 = (Lisp_Object)lessp2(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    v321 = v321 ? lisp_true : nil;
    env = stack[-9];
    if (v321 == nil) goto v328;
    v321 = stack[-2];
    v321 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = Lappend(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = stack[-4];
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    fn = elt(env, 32); /* insertparens */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lappend(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = v321;
    goto v327;

v328:
    v321 = stack[-2];
    v321 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = Lappend(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = stack[-4];
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lappend(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = v321;
    goto v327;

v149:
    v321 = stack[-1];
    v321 = qcdr(v321);
    stack[-1] = v321;
    if (v321 == nil) goto v325;
    v321 = stack[-2];
    v321 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = Lappend(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = stack[-4];
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lappend(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = v321;
    goto v149;

v326:
    v321 = stack[-1];
    v321 = qcdr(v321);
    stack[-1] = v321;
    if (v321 == nil) goto v325;
    v321 = stack[-1];
    v321 = qcar(v321);
    if (!consp(v321)) goto v45;
    v321 = stack[-1];
    v321 = qcar(v321);
    v322 = qcar(v321);
    v321 = elt(env, 3); /* minus */
    if (!(v322 == v321)) goto v45;

v329:
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = stack[-4];
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lappend(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = v321;
    goto v326;

v45:
    v321 = stack[-2];
    v321 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lappend(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = v321;
    goto v329;

v13:
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = elt(env, 5); /* literal */
    if (v322 == v321) goto v105;
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = elt(env, 6); /* range */
    if (v322 == v321) goto v68;
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = elt(env, 8); /* !:rd!: */
    if (v322 == v321) goto v330;
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = elt(env, 16); /* !:crn!: */
    if (v322 == v321) goto v331;
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = elt(env, 17); /* !:gi!: */
    if (v322 == v321) goto v100;
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = elt(env, 18); /* !:cr!: */
    if (v322 == v321) goto v332;
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = elt(env, 24); /* !*fortranname!* */
    v321 = get(v322, v321);
    env = stack[-9];
    stack[-7] = v321;
    v321 = stack[-1];
    v321 = qcar(v321);
    fn = elt(env, 28); /* fortranname */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[-8] = v321;
    v321 = stack[-1];
    v321 = qcdr(v321);
    stack[-1] = v321;
    v321 = stack[-1];
    stack[-6] = v321;
    goto v333;

v333:
    v321 = stack[-6];
    if (v321 == nil) goto v334;
    v321 = stack[-6];
    v321 = qcar(v321);
    stack[-2] = v321;
    stack[-1] = elt(env, 21); /* !, */
    v321 = stack[-7];
    if (v321 == nil) goto v335;
    v321 = stack[-2];
    v321 = integerp(v321);
    if (v321 == nil) goto v336;
    v321 = stack[-2];
    v321 = Lfloat(nil, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    goto v337;

v337:
    v321 = cons(stack[-1], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[-5] = v321;
    v321 = stack[-5];
    fn = elt(env, 33); /* lastpair */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[-4] = v321;
    v321 = stack[-6];
    v321 = qcdr(v321);
    stack[-6] = v321;
    v321 = stack[-4];
    if (!consp(v321)) goto v333;
    else goto v338;

v338:
    v321 = stack[-6];
    if (v321 == nil) goto v339;
    stack[-3] = stack[-4];
    v321 = stack[-6];
    v321 = qcar(v321);
    stack[-2] = v321;
    stack[-1] = elt(env, 21); /* !, */
    v321 = stack[-7];
    if (v321 == nil) goto v340;
    v321 = stack[-2];
    v321 = integerp(v321);
    if (v321 == nil) goto v341;
    v321 = stack[-2];
    v321 = Lfloat(nil, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    goto v342;

v342:
    v321 = cons(stack[-1], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lrplacd(nil, stack[-3], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = stack[-4];
    fn = elt(env, 33); /* lastpair */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[-4] = v321;
    v321 = stack[-6];
    v321 = qcdr(v321);
    stack[-6] = v321;
    goto v338;

v341:
    v321 = stack[-2];
    fn = elt(env, 34); /* isfloat */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    if (!(v321 == nil)) goto v343;
    v322 = stack[-8];
    v321 = elt(env, 25); /* (real dble) */
    v321 = Lmemq(nil, v322, v321);
    if (!(v321 == nil)) goto v343;
    v321 = elt(env, 26); /* real */
    fn = elt(env, 28); /* fortranname */
    stack[0] = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v322 = stack[-2];
    v321 = (Lisp_Object)1; /* 0 */
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    fn = elt(env, 32); /* insertparens */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = cons(stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    goto v342;

v343:
    v322 = stack[-2];
    v321 = (Lisp_Object)1; /* 0 */
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    goto v342;

v340:
    v322 = stack[-2];
    v321 = (Lisp_Object)1; /* 0 */
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    goto v342;

v339:
    v321 = stack[-5];
    goto v344;

v344:
    v321 = qcdr(v321);
    stack[0] = stack[-8];
    fn = elt(env, 32); /* insertparens */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    {
        Lisp_Object v345 = stack[0];
        popv(10);
        return cons(v345, v321);
    }

v336:
    v321 = stack[-2];
    fn = elt(env, 34); /* isfloat */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    if (!(v321 == nil)) goto v346;
    v322 = stack[-8];
    v321 = elt(env, 25); /* (real dble) */
    v321 = Lmemq(nil, v322, v321);
    if (!(v321 == nil)) goto v346;
    v321 = elt(env, 26); /* real */
    fn = elt(env, 28); /* fortranname */
    stack[0] = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v322 = stack[-2];
    v321 = (Lisp_Object)1; /* 0 */
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    fn = elt(env, 32); /* insertparens */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = cons(stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    goto v337;

v346:
    v322 = stack[-2];
    v321 = (Lisp_Object)1; /* 0 */
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    goto v337;

v335:
    v322 = stack[-2];
    v321 = (Lisp_Object)1; /* 0 */
    v321 = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    goto v337;

v334:
    v321 = qvalue(elt(env, 2)); /* nil */
    goto v344;

v332:
    v321 = qvalue(elt(env, 12)); /* !*double */
    if (v321 == nil) goto v347;
    v321 = qvalue(elt(env, 19)); /* !*f90 */
    if (v321 == nil) goto v347;
    stack[-4] = elt(env, 20); /* cmplx!( */
    v322 = elt(env, 8); /* !:rd!: */
    v321 = stack[-1];
    v321 = qcdr(v321);
    v321 = qcar(v321);
    v322 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = stack[-3];
    stack[-2] = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = elt(env, 21); /* !, */
    v322 = elt(env, 8); /* !:rd!: */
    v321 = stack[-1];
    v321 = qcdr(v321);
    v321 = qcdr(v321);
    v322 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = stack[-3];
    stack[-1] = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v323 = elt(env, 21); /* !, */
    v322 = elt(env, 22); /* kind!(1!.0!D0!) */
    v321 = elt(env, 23); /* !) */
    v321 = list3(v323, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lappend(nil, stack[-1], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = cons(stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lappend(nil, stack[-2], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    {
        Lisp_Object v348 = stack[-4];
        popv(10);
        return cons(v348, v321);
    }

v347:
    stack[-4] = elt(env, 20); /* cmplx!( */
    v322 = elt(env, 8); /* !:rd!: */
    v321 = stack[-1];
    v321 = qcdr(v321);
    v321 = qcar(v321);
    v322 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = stack[-3];
    stack[-2] = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = elt(env, 21); /* !, */
    v322 = elt(env, 8); /* !:rd!: */
    v321 = stack[-1];
    v321 = qcdr(v321);
    v321 = qcdr(v321);
    v322 = cons(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = stack[-3];
    stack[-1] = CC_fortexp1(env, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = elt(env, 23); /* !) */
    v321 = ncons(v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lappend(nil, stack[-1], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = cons(stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = Lappend(nil, stack[-2], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    {
        Lisp_Object v349 = stack[-4];
        popv(10);
        return cons(v349, v321);
    }

v100:
    v321 = stack[-1];
    fn = elt(env, 35); /* !*gi2cr */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[-1] = v321;
    goto v185;

v331:
    v321 = stack[-1];
    fn = elt(env, 36); /* !*crn2cr */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[-1] = v321;
    goto v185;

v330:
    v321 = stack[-1];
    v321 = qcdr(v321);
    if (!consp(v321)) goto v350;
    stack[-3] = qvalue(elt(env, 9)); /* !:lower!-sci!: */
    qvalue(elt(env, 9)) = nil; /* !:lower!-sci!: */
    stack[-2] = qvalue(elt(env, 10)); /* !:upper!-sci!: */
    qvalue(elt(env, 10)) = nil; /* !:upper!-sci!: */
    v321 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 9)) = v321; /* !:lower!-sci!: */
    v321 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 10)) = v321; /* !:upper!-sci!: */
    v321 = stack[-1];
    fn = elt(env, 37); /* rd!:explode */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-4] = v321;
    v321 = stack[-4];
    v321 = qcar(v321);
    stack[-1] = v321;
    v321 = stack[-4];
    v321 = qcdr(v321);
    stack[0] = qcar(v321);
    v321 = stack[-4];
    v321 = qcdr(v321);
    v321 = qcdr(v321);
    v321 = qcar(v321);
    v321 = sub1(v321);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v321 = plus2(stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-4] = v321;
    v323 = elt(env, 5); /* literal */
    v321 = stack[-1];
    v322 = qcar(v321);
    v321 = elt(env, 11); /* !. */
    v322 = list3(v323, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v321 = stack[-1];
    v321 = qcdr(v321);
    v321 = Lappend(nil, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-1] = v321;
    v322 = stack[-4];
    v321 = (Lisp_Object)1; /* 0 */
    if (v322 == v321) goto v113;
    stack[0] = stack[-1];
    v321 = qvalue(elt(env, 12)); /* !*double */
    if (v321 == nil) goto v108;
    v321 = elt(env, 13); /* !D */
    v322 = v321;
    goto v352;

v352:
    v321 = stack[-4];
    v321 = list2(v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    v321 = Lappend(nil, stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-1] = v321;
    goto v353;

v353:
    v321 = stack[-1];
    fn = elt(env, 38); /* fortliteral */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    qvalue(elt(env, 10)) = stack[-2]; /* !:upper!-sci!: */
    qvalue(elt(env, 9)) = stack[-3]; /* !:lower!-sci!: */
    { popv(10); return onevalue(v321); }

v108:
    v321 = elt(env, 14); /* !E */
    v322 = v321;
    goto v352;

v113:
    v321 = qvalue(elt(env, 12)); /* !*double */
    if (v321 == nil) goto v353;
    v322 = stack[-1];
    v321 = elt(env, 15); /* (!D 0) */
    v321 = Lappend(nil, v322, v321);
    nil = C_nil;
    if (exception_pending()) goto v351;
    env = stack[-9];
    stack[-1] = v321;
    goto v353;

v350:
    v321 = stack[-1];
    v321 = qcdr(v321);
    popv(10);
    return ncons(v321);

v68:
    v321 = stack[-1];
    v321 = qcdr(v321);
    v321 = qcar(v321);
    fn = elt(env, 39); /* fortexp */
    stack[-2] = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    stack[0] = elt(env, 7); /* !: */
    v321 = stack[-1];
    v321 = qcdr(v321);
    v321 = qcdr(v321);
    v321 = qcar(v321);
    fn = elt(env, 39); /* fortexp */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    env = stack[-9];
    v321 = cons(stack[0], v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    {
        Lisp_Object v354 = stack[-2];
        popv(10);
        return Lappend(nil, v354, v321);
    }

v105:
    v321 = stack[-1];
    {
        popv(10);
        fn = elt(env, 38); /* fortliteral */
        return (*qfn1(fn))(qenv(fn), v321);
    }

v186:
    v321 = stack[-1];
    fn = elt(env, 28); /* fortranname */
    v321 = (*qfn1(fn))(qenv(fn), v321);
    nil = C_nil;
    if (exception_pending()) goto v324;
    popv(10);
    return ncons(v321);
/* error exit handlers */
v351:
    env = stack[-9];
    qvalue(elt(env, 10)) = stack[-2]; /* !:upper!-sci!: */
    qvalue(elt(env, 9)) = stack[-3]; /* !:lower!-sci!: */
    popv(10);
    return nil;
v324:
    popv(10);
    return nil;
}



/* Code for delength */

static Lisp_Object CC_delength(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v362, v363, v364;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delength");
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
    v363 = v0;
/* end of prologue */
    v362 = v363;
    v362 = Lconsp(nil, v362);
    env = stack[-2];
    if (v362 == nil) goto v55;
    v362 = v363;
    v364 = qcar(v362);
    v362 = elt(env, 1); /* plus */
    if (v364 == v362) goto v66;
    v362 = v363;
    v364 = qcar(v362);
    v362 = elt(env, 2); /* times */
    if (v364 == v362) goto v66;
    v362 = v363;
    v364 = qcar(v362);
    v362 = elt(env, 3); /* quotient */
    if (v364 == v362) goto v66;
    v362 = v363;
    v364 = qcar(v362);
    v362 = elt(env, 4); /* minus */
    if (v364 == v362) goto v66;
    v362 = v363;
    v364 = qcar(v362);
    v362 = elt(env, 5); /* equal */
    if (v364 == v362) goto v66;
    v362 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v362); }

v66:
    v362 = v363;
    v362 = qcdr(v362);
    stack[-1] = v362;
    v362 = (Lisp_Object)1; /* 0 */
    stack[0] = v362;
    goto v76;

v76:
    v362 = stack[-1];
    if (v362 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v362 = stack[-1];
    v362 = qcar(v362);
    v363 = CC_delength(env, v362);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    v362 = stack[0];
    v362 = plus2(v363, v362);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-2];
    stack[0] = v362;
    v362 = stack[-1];
    v362 = qcdr(v362);
    stack[-1] = v362;
    goto v76;

v55:
    v362 = v363;
    if (v362 == nil) goto v92;
    v362 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v362); }

v92:
    v362 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v362); }
/* error exit handlers */
v47:
    popv(3);
    return nil;
}



/* Code for mk_world1 */

static Lisp_Object MS_CDECL CC_mk_world1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v66, v365;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mk_world1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_world1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    v91 = v0;
/* end of prologue */
    fn = elt(env, 1); /* map_2_from_map_1 */
    v365 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v181;
    v66 = stack[-1];
    v91 = stack[0];
    popv(2);
    return list3(v365, v66, v91);
/* error exit handlers */
v181:
    popv(2);
    return nil;
}



/* Code for simpdfp */

static Lisp_Object CC_simpdfp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v393, v394, v395, v396, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpdfp");
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
    stack[0] = v0;
/* end of prologue */
    v393 = stack[0];
    v394 = Llength(nil, v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v393 = (Lisp_Object)33; /* 2 */
    v393 = (Lisp_Object)lessp2(v394, v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    v393 = v393 ? lisp_true : nil;
    env = stack[-6];
    if (v393 == nil) goto v90;
    v394 = elt(env, 2); /* dfp */
    v393 = stack[0];
    v394 = cons(v394, v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v393 = elt(env, 11); /* "generic differential" */
    fn = elt(env, 12); /* typerr */
    v393 = (*qfn2(fn))(qenv(fn), v394, v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    v393 = nil;
    { popv(7); return onevalue(v393); }

v90:
    v393 = stack[0];
    v393 = qcar(v393);
    fn = elt(env, 13); /* reval */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    stack[-5] = v393;
    v393 = stack[-5];
    v393 = Lconsp(nil, v393);
    env = stack[-6];
    if (v393 == nil) goto v102;
    v393 = stack[-5];
    v393 = qcar(v393);
    stack[-1] = v393;
    v393 = stack[0];
    v393 = qcdr(v393);
    v393 = qcar(v393);
    fn = elt(env, 13); /* reval */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v131 = v393;
    v394 = v131;
    v393 = qvalue(elt(env, 1)); /* frlis!* */
    v393 = Lmember(nil, v394, v393);
    if (!(v393 == nil)) goto v398;
    v394 = v131;
    v393 = elt(env, 3); /* list */
    if (!consp(v394)) goto v399;
    v394 = qcar(v394);
    if (!(v394 == v393)) goto v399;

v398:
    v394 = stack[-1];
    v393 = elt(env, 5); /* generic_function */
    v393 = get(v394, v393);
    env = stack[-6];
    v396 = v393;
    v393 = qvalue(elt(env, 6)); /* t */
    v394 = v396;
    if (v394 == nil) goto v400;
    v395 = v131;
    v394 = elt(env, 3); /* list */
    if (!consp(v395)) goto v400;
    v395 = qcar(v395);
    if (!(v395 == v394)) goto v400;
    v394 = v131;
    v394 = qcdr(v394);
    v395 = v394;
    goto v401;

v401:
    v394 = v395;
    if (v394 == nil) goto v400;
    v394 = v395;
    v394 = qcar(v394);
    if (v393 == nil) goto v25;
    v393 = v396;
    v393 = Lmember(nil, v394, v393);
    goto v402;

v402:
    v394 = v395;
    v394 = qcdr(v394);
    v395 = v394;
    goto v401;

v25:
    v393 = qvalue(elt(env, 4)); /* nil */
    goto v402;

v400:
    if (v393 == nil) goto v147;
    v394 = v131;
    v393 = elt(env, 7); /* (list) */
    if (equal(v394, v393)) goto v403;
    v393 = v396;
    if (v393 == nil) goto v297;
    v394 = stack[-1];
    v393 = elt(env, 8); /* dfp_commute */
    v393 = Lflagp(nil, v394, v393);
    env = stack[-6];
    if (v393 == nil) goto v297;
    v393 = v396;
    stack[-1] = qvalue(elt(env, 9)); /* kord!* */
    qvalue(elt(env, 9)) = v393; /* kord!* */
    stack[0] = elt(env, 3); /* list */
    v393 = v131;
    v394 = qcdr(v393);
    v393 = elt(env, 10); /* ordp */
    fn = elt(env, 14); /* sort */
    v393 = (*qfn2(fn))(qenv(fn), v394, v393);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-6];
    v393 = cons(stack[0], v393);
    nil = C_nil;
    if (exception_pending()) goto v404;
    env = stack[-6];
    v131 = v393;
    qvalue(elt(env, 9)) = stack[-1]; /* kord!* */
    goto v297;

v297:
    v394 = elt(env, 2); /* dfp */
    v393 = stack[-5];
    v395 = v131;
    v393 = list3(v394, v393, v395);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    stack[0] = v393;
    v394 = stack[0];
    v393 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 15); /* mksq */
        return (*qfn2(fn))(qenv(fn), v394, v393);
    }

v403:
    v394 = stack[-5];
    v393 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 15); /* mksq */
        return (*qfn2(fn))(qenv(fn), v394, v393);
    }

v147:
    v394 = qvalue(elt(env, 4)); /* nil */
    v393 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v394, v393);

v399:
    stack[-4] = v131;
    v393 = stack[0];
    v393 = qcdr(v393);
    v393 = qcdr(v393);
    stack[-3] = v393;
    v393 = stack[-3];
    if (v393 == nil) goto v405;
    v393 = stack[-3];
    v393 = qcar(v393);
    fn = elt(env, 13); /* reval */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v393 = ncons(v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    stack[-1] = v393;
    stack[-2] = v393;
    goto v45;

v45:
    v393 = stack[-3];
    v393 = qcdr(v393);
    stack[-3] = v393;
    v393 = stack[-3];
    if (v393 == nil) goto v41;
    stack[0] = stack[-1];
    v393 = stack[-3];
    v393 = qcar(v393);
    fn = elt(env, 13); /* reval */
    v393 = (*qfn1(fn))(qenv(fn), v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v393 = ncons(v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v393 = Lrplacd(nil, stack[0], v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v393 = stack[-1];
    v393 = qcdr(v393);
    stack[-1] = v393;
    goto v45;

v41:
    v393 = stack[-2];
    goto v49;

v49:
    v393 = cons(stack[-4], v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v131 = v393;
    stack[0] = elt(env, 3); /* list */
    v394 = v131;
    v393 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 16); /* dfp!-normalize */
    v393 = (*qfn2(fn))(qenv(fn), v394, v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v393 = cons(stack[0], v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v131 = v393;
    v394 = elt(env, 2); /* dfp */
    v393 = stack[-5];
    v395 = v131;
    v393 = list3(v394, v393, v395);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 17); /* simp */
        return (*qfn1(fn))(qenv(fn), v393);
    }

v405:
    v393 = qvalue(elt(env, 4)); /* nil */
    goto v49;

v102:
    v393 = stack[0];
    v393 = qcdr(v393);
    v394 = qcar(v393);
    v393 = qvalue(elt(env, 1)); /* frlis!* */
    v393 = Lmember(nil, v394, v393);
    if (v393 == nil) goto v406;
    v394 = elt(env, 2); /* dfp */
    v393 = stack[0];
    v394 = cons(v394, v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    v393 = (Lisp_Object)17; /* 1 */
    {
        popv(7);
        fn = elt(env, 15); /* mksq */
        return (*qfn2(fn))(qenv(fn), v394, v393);
    }

v406:
    v394 = stack[-5];
    v393 = stack[0];
    v393 = qcdr(v393);
    v393 = qcar(v393);
    v393 = qcdr(v393);
    v393 = cons(v394, v393);
    nil = C_nil;
    if (exception_pending()) goto v397;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 18); /* simpdf */
        return (*qfn1(fn))(qenv(fn), v393);
    }
/* error exit handlers */
v404:
    env = stack[-6];
    qvalue(elt(env, 9)) = stack[-1]; /* kord!* */
    popv(7);
    return nil;
v397:
    popv(7);
    return nil;
}



/* Code for permp!: */

static Lisp_Object CC_permpT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v358, v357, v409;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for permp:");
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
    v358 = v1;
    v357 = v0;
/* end of prologue */

v185:
    v75 = v357;
    if (v75 == nil) goto v186;
    v75 = v357;
    v409 = qcar(v75);
    v75 = v358;
    v75 = qcar(v75);
    if (equal(v409, v75)) goto v90;
    v75 = v357;
    stack[0] = qcdr(v75);
    v75 = v358;
    v75 = qcar(v75);
    v357 = qcar(v357);
    v358 = qcdr(v358);
    v75 = Lsubst(nil, 3, v75, v357, v358);
    nil = C_nil;
    if (exception_pending()) goto v320;
    env = stack[-1];
    v75 = CC_permpT(env, stack[0], v75);
    nil = C_nil;
    if (exception_pending()) goto v320;
    v75 = (v75 == nil ? lisp_true : nil);
    { popv(2); return onevalue(v75); }

v90:
    v75 = v357;
    v75 = qcdr(v75);
    v357 = v75;
    v75 = v358;
    v75 = qcdr(v75);
    v358 = v75;
    goto v185;

v186:
    v75 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v75); }
/* error exit handlers */
v320:
    popv(2);
    return nil;
}



/* Code for horner!-rule!-in!-order!-mod!-p */

static Lisp_Object MS_CDECL CC_hornerKruleKinKorderKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v374, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v386, v422, v327, v423, v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "horner-rule-in-order-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for horner-rule-in-order-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push4(v374,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v374);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v374;
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v424:
    v386 = stack[-1];
    if (!consp(v386)) goto v92;
    v386 = stack[-1];
    v386 = qcar(v386);
    if (!consp(v386)) goto v92;
    v386 = stack[-1];
    v386 = qcar(v386);
    v386 = qcar(v386);
    v422 = qcar(v386);
    v386 = stack[0];
    v386 = qcar(v386);
    v386 = qcar(v386);
    if (equal(v422, v386)) goto v425;
    v422 = stack[-1];
    v386 = stack[0];
    v386 = qcdr(v386);
    fn = elt(env, 1); /* evaluate!-in!-order!-mod!-p */
    v423 = (*qfn2(fn))(qenv(fn), v422, v386);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-5];
    v327 = stack[-3];
    v386 = stack[0];
    v386 = qcar(v386);
    v422 = qcdr(v386);
    v386 = stack[-2];
    v386 = Lmodular_expt(nil, v422, v386);
    env = stack[-5];
    v386 = Lmodular_times(nil, v327, v386);
    {   int32_t w = int_of_fixnum(v423) + int_of_fixnum(v386);
        if (w >= current_modulus) w -= current_modulus;
        v386 = fixnum_of_int(w);
    }
    { popv(6); return onevalue(v386); }

v425:
    v386 = stack[-1];
    v386 = qcar(v386);
    v386 = qcar(v386);
    v386 = qcdr(v386);
    stack[-4] = v386;
    v386 = stack[-1];
    v386 = qcar(v386);
    v422 = qcdr(v386);
    v386 = stack[0];
    v386 = qcdr(v386);
    fn = elt(env, 1); /* evaluate!-in!-order!-mod!-p */
    v81 = (*qfn2(fn))(qenv(fn), v422, v386);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-5];
    v423 = stack[-3];
    v386 = stack[0];
    v386 = qcar(v386);
    v327 = qcdr(v386);
    v422 = stack[-2];
    v386 = stack[-4];
    v386 = (Lisp_Object)(int32_t)((int32_t)v422 - (int32_t)v386 + TAG_FIXNUM);
    v386 = Lmodular_expt(nil, v327, v386);
    env = stack[-5];
    v386 = Lmodular_times(nil, v423, v386);
    env = stack[-5];
    {   int32_t w = int_of_fixnum(v81) + int_of_fixnum(v386);
        if (w >= current_modulus) w -= current_modulus;
        v423 = fixnum_of_int(w);
    }
    v327 = stack[-4];
    v386 = stack[-1];
    v422 = qcdr(v386);
    v386 = stack[0];
    stack[-3] = v423;
    stack[-2] = v327;
    stack[-1] = v422;
    stack[0] = v386;
    goto v424;

v92:
    v386 = stack[-1];
    fn = elt(env, 2); /* !*d2n */
    v423 = (*qfn1(fn))(qenv(fn), v386);
    nil = C_nil;
    if (exception_pending()) goto v426;
    env = stack[-5];
    v327 = stack[-3];
    v386 = stack[0];
    v386 = qcar(v386);
    v422 = qcdr(v386);
    v386 = stack[-2];
    v386 = Lmodular_expt(nil, v422, v386);
    env = stack[-5];
    v386 = Lmodular_times(nil, v327, v386);
    {   int32_t w = int_of_fixnum(v423) + int_of_fixnum(v386);
        if (w >= current_modulus) w -= current_modulus;
        v386 = fixnum_of_int(w);
    }
    { popv(6); return onevalue(v386); }
/* error exit handlers */
v426:
    popv(6);
    return nil;
}



/* Code for evaluateuconst */

static Lisp_Object CC_evaluateuconst(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v174, v175;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluateuconst");
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
    v174 = stack[0];
    if (v174 == nil) goto v65;
    v174 = stack[0];
    if (!consp(v174)) goto v65;
    v174 = stack[0];
    v174 = qcar(v174);
    if (!consp(v174)) goto v65;
    v174 = stack[0];
    v174 = qcar(v174);
    v174 = qcar(v174);
    v175 = qcar(v174);
    v174 = qvalue(elt(env, 1)); /* cmap */
    v175 = Lassoc(nil, v175, v174);
    v174 = v175;
    if (v175 == nil) goto v59;
    v175 = qvalue(elt(env, 2)); /* cval */
    v174 = qcdr(v174);
    v174 = *(Lisp_Object *)((char *)v175 + (CELL-TAG_VECTOR) + ((int32_t)v174/(16/CELL)));
    goto v176;

v176:
    stack[-1] = v174;
    v174 = stack[0];
    v174 = qcar(v174);
    v174 = qcdr(v174);
    v174 = CC_evaluateuconst(env, v174);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-2];
    fn = elt(env, 3); /* !*multsq */
    v174 = (*qfn2(fn))(qenv(fn), stack[-1], v174);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-2];
    stack[-1] = v174;
    v174 = stack[0];
    v174 = qcdr(v174);
    v174 = CC_evaluateuconst(env, v174);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-2];
    {
        Lisp_Object v364 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* !*addsq */
        return (*qfn2(fn))(qenv(fn), v364, v174);
    }

v59:
    v174 = stack[0];
    v174 = qcar(v174);
    v175 = qcar(v174);
    v174 = (Lisp_Object)17; /* 1 */
    v174 = cons(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-2];
    v175 = ncons(v174);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-2];
    v174 = (Lisp_Object)17; /* 1 */
    v174 = cons(v175, v174);
    nil = C_nil;
    if (exception_pending()) goto v363;
    env = stack[-2];
    goto v176;

v65:
    v175 = stack[0];
    v174 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v175, v174);
/* error exit handlers */
v363:
    popv(3);
    return nil;
}



/* Code for multtaylor1 */

static Lisp_Object MS_CDECL CC_multtaylor1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v443, v444, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "multtaylor1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multtaylor1");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[-6] = nil;
    v443 = stack[-3];
    stack[-5] = v443;
    v443 = stack[-5];
    if (v443 == nil) goto v181;
    v443 = stack[-5];
    v443 = qcar(v443);
    v443 = qcdr(v443);
    v443 = qcdr(v443);
    v443 = qcar(v443);
    v443 = ncons(v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    stack[-1] = v443;
    stack[-4] = v443;
    goto v66;

v66:
    v443 = stack[-5];
    v443 = qcdr(v443);
    stack[-5] = v443;
    v443 = stack[-5];
    if (v443 == nil) goto v102;
    stack[0] = stack[-1];
    v443 = stack[-5];
    v443 = qcar(v443);
    v443 = qcdr(v443);
    v443 = qcdr(v443);
    v443 = qcar(v443);
    v443 = ncons(v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v443 = Lrplacd(nil, stack[0], v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v443 = stack[-1];
    v443 = qcdr(v443);
    stack[-1] = v443;
    goto v66;

v102:
    v443 = stack[-4];
    goto v91;

v91:
    stack[-4] = v443;
    v443 = stack[-3];
    stack[-5] = v443;
    v443 = stack[-5];
    if (v443 == nil) goto v413;
    v443 = stack[-5];
    v443 = qcar(v443);
    v443 = qcdr(v443);
    v443 = qcdr(v443);
    v443 = qcdr(v443);
    v443 = qcar(v443);
    v443 = ncons(v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    stack[-1] = v443;
    stack[-3] = v443;
    goto v28;

v28:
    v443 = stack[-5];
    v443 = qcdr(v443);
    stack[-5] = v443;
    v443 = stack[-5];
    if (v443 == nil) goto v445;
    stack[0] = stack[-1];
    v443 = stack[-5];
    v443 = qcar(v443);
    v443 = qcdr(v443);
    v443 = qcdr(v443);
    v443 = qcdr(v443);
    v443 = qcar(v443);
    v443 = ncons(v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v443 = Lrplacd(nil, stack[0], v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v443 = stack[-1];
    v443 = qcdr(v443);
    stack[-1] = v443;
    goto v28;

v445:
    v443 = stack[-3];
    goto v356;

v356:
    stack[-5] = v443;
    v443 = stack[-2];
    stack[-3] = v443;
    goto v48;

v48:
    v443 = stack[-3];
    if (v443 == nil) goto v20;
    v443 = stack[-3];
    v443 = qcar(v443);
    stack[-2] = v443;
    v443 = stack[-7];
    stack[-1] = v443;
    goto v446;

v446:
    v443 = stack[-1];
    if (v443 == nil) goto v317;
    v443 = stack[-1];
    v443 = qcar(v443);
    stack[0] = v443;
    v443 = stack[-2];
    v444 = qcar(v443);
    v443 = stack[0];
    v443 = qcar(v443);
    fn = elt(env, 2); /* add!-degrees */
    v443 = (*qfn2(fn))(qenv(fn), v444, v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    stack[-8] = v443;
    v444 = stack[-5];
    v443 = stack[-8];
    fn = elt(env, 3); /* exceeds!-order */
    v443 = (*qfn2(fn))(qenv(fn), v444, v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    if (v443 == nil) goto v447;
    v198 = stack[-5];
    v444 = stack[-4];
    v443 = stack[-8];
    fn = elt(env, 4); /* min2!-order */
    v443 = (*qfnn(fn))(qenv(fn), 3, v198, v444, v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    stack[-5] = v443;
    goto v420;

v420:
    v443 = stack[-1];
    v443 = qcdr(v443);
    stack[-1] = v443;
    goto v446;

v447:
    v443 = stack[-2];
    v444 = qcdr(v443);
    v443 = stack[0];
    v443 = qcdr(v443);
    fn = elt(env, 5); /* multsq */
    v443 = (*qfn2(fn))(qenv(fn), v444, v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v444 = v443;
    v443 = v444;
    v443 = qcar(v443);
    if (v443 == nil) goto v420;
    v198 = stack[-8];
    v443 = stack[-6];
    v443 = Lassoc(nil, v198, v443);
    v198 = v443;
    v443 = v198;
    if (v443 == nil) goto v381;
    stack[0] = v198;
    v443 = v198;
    v443 = qcdr(v443);
    fn = elt(env, 6); /* addsq */
    v443 = (*qfn2(fn))(qenv(fn), v443, v444);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v443 = Lrplacd(nil, stack[0], v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    goto v420;

v381:
    v443 = stack[-8];
    v444 = cons(v443, v444);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v443 = stack[-6];
    fn = elt(env, 7); /* enter!-sorted */
    v443 = (*qfn2(fn))(qenv(fn), v444, v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    stack[-6] = v443;
    goto v420;

v317:
    v443 = stack[-3];
    v443 = qcdr(v443);
    stack[-3] = v443;
    goto v48;

v20:
    stack[-4] = stack[-5];
    v443 = stack[-6];
    stack[-5] = v443;
    goto v146;

v146:
    v443 = stack[-5];
    if (v443 == nil) goto v19;
    v443 = stack[-5];
    v443 = qcar(v443);
    stack[0] = v443;
    v443 = stack[0];
    v443 = qcdr(v443);
    fn = elt(env, 8); /* subs2!* */
    v443 = (*qfn1(fn))(qenv(fn), v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v444 = v443;
    v444 = qcar(v444);
    if (v444 == nil) goto v448;
    v444 = stack[0];
    v444 = qcar(v444);
    v443 = cons(v444, v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v443 = ncons(v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    goto v145;

v145:
    stack[-3] = v443;
    v443 = stack[-3];
    fn = elt(env, 9); /* lastpair */
    v443 = (*qfn1(fn))(qenv(fn), v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    stack[-2] = v443;
    v443 = stack[-5];
    v443 = qcdr(v443);
    stack[-5] = v443;
    v443 = stack[-2];
    if (!consp(v443)) goto v146;
    else goto v147;

v147:
    v443 = stack[-5];
    if (v443 == nil) goto v371;
    stack[-1] = stack[-2];
    v443 = stack[-5];
    v443 = qcar(v443);
    stack[0] = v443;
    v443 = stack[0];
    v443 = qcdr(v443);
    fn = elt(env, 8); /* subs2!* */
    v443 = (*qfn1(fn))(qenv(fn), v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v444 = v443;
    v444 = qcar(v444);
    if (v444 == nil) goto v449;
    v444 = stack[0];
    v444 = qcar(v444);
    v443 = cons(v444, v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v443 = ncons(v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    goto v140;

v140:
    v443 = Lrplacd(nil, stack[-1], v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    v443 = stack[-2];
    fn = elt(env, 9); /* lastpair */
    v443 = (*qfn1(fn))(qenv(fn), v443);
    nil = C_nil;
    if (exception_pending()) goto v366;
    env = stack[-9];
    stack[-2] = v443;
    v443 = stack[-5];
    v443 = qcdr(v443);
    stack[-5] = v443;
    goto v147;

v449:
    v443 = nil;
    goto v140;

v371:
    v443 = stack[-3];
    goto v150;

v150:
    {
        Lisp_Object v393 = stack[-4];
        popv(10);
        return cons(v393, v443);
    }

v448:
    v443 = nil;
    goto v145;

v19:
    v443 = qvalue(elt(env, 1)); /* nil */
    goto v150;

v413:
    v443 = qvalue(elt(env, 1)); /* nil */
    goto v356;

v181:
    v443 = qvalue(elt(env, 1)); /* nil */
    goto v91;
/* error exit handlers */
v366:
    popv(10);
    return nil;
}



/* Code for mk!+inner!+mat */

static Lisp_Object CC_mkLinnerLmat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+inner+mat");
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
    v165 = v0;
/* end of prologue */
    v165 = qcdr(v165);
    stack[-7] = v165;
    v165 = stack[-7];
    if (v165 == nil) goto v66;
    v165 = stack[-7];
    v165 = qcar(v165);
    stack[-3] = v165;
    v165 = stack[-3];
    if (v165 == nil) goto v73;
    v165 = stack[-3];
    v165 = qcar(v165);
    fn = elt(env, 3); /* simp */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    stack[-1] = v165;
    stack[-2] = v165;
    goto v64;

v64:
    v165 = stack[-3];
    v165 = qcdr(v165);
    stack[-3] = v165;
    v165 = stack[-3];
    if (v165 == nil) goto v407;
    stack[0] = stack[-1];
    v165 = stack[-3];
    v165 = qcar(v165);
    fn = elt(env, 3); /* simp */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    v165 = Lrplacd(nil, stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    v165 = stack[-1];
    v165 = qcdr(v165);
    stack[-1] = v165;
    goto v64;

v407:
    v165 = stack[-2];
    goto v63;

v63:
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    stack[-5] = v165;
    stack[-6] = v165;
    goto v90;

v90:
    v165 = stack[-7];
    v165 = qcdr(v165);
    stack[-7] = v165;
    v165 = stack[-7];
    if (v165 == nil) goto v390;
    stack[-4] = stack[-5];
    v165 = stack[-7];
    v165 = qcar(v165);
    stack[-3] = v165;
    v165 = stack[-3];
    if (v165 == nil) goto v362;
    v165 = stack[-3];
    v165 = qcar(v165);
    fn = elt(env, 3); /* simp */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    stack[-1] = v165;
    stack[-2] = v165;
    goto v451;

v451:
    v165 = stack[-3];
    v165 = qcdr(v165);
    stack[-3] = v165;
    v165 = stack[-3];
    if (v165 == nil) goto v48;
    stack[0] = stack[-1];
    v165 = stack[-3];
    v165 = qcar(v165);
    fn = elt(env, 3); /* simp */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    v165 = Lrplacd(nil, stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    v165 = stack[-1];
    v165 = qcdr(v165);
    stack[-1] = v165;
    goto v451;

v48:
    v165 = stack[-2];
    goto v326;

v326:
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    v165 = Lrplacd(nil, stack[-4], v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    v165 = stack[-5];
    v165 = qcdr(v165);
    stack[-5] = v165;
    goto v90;

v362:
    v165 = qvalue(elt(env, 1)); /* nil */
    goto v326;

v390:
    v165 = stack[-6];
    goto v452;

v452:
    stack[0] = v165;
    v165 = stack[0];
    fn = elt(env, 4); /* matrix!+p */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    env = stack[-8];
    if (!(v165 == nil)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    v165 = elt(env, 2); /* "incorrect input in mkinnermat" */
    fn = elt(env, 5); /* rederr */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v422;
    v165 = nil;
    { popv(9); return onevalue(v165); }

v73:
    v165 = qvalue(elt(env, 1)); /* nil */
    goto v63;

v66:
    v165 = qvalue(elt(env, 1)); /* nil */
    goto v452;
/* error exit handlers */
v422:
    popv(9);
    return nil;
}



/* Code for prinindexs */

static Lisp_Object CC_prinindexs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v29, v5, v406;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinindexs");
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
    v406 = v0;
/* end of prologue */
    v5 = nil;
    v28 = v406;
    v29 = v28;
    goto v186;

v186:
    v28 = v29;
    if (v28 == nil) goto v372;
    v28 = v29;
    v28 = qcar(v28);
    if (!consp(v28)) goto v180;
    v28 = qvalue(elt(env, 2)); /* t */
    v5 = v28;
    goto v180;

v180:
    v28 = v29;
    v28 = qcdr(v28);
    v29 = v28;
    goto v186;

v372:
    v28 = v5;
    if (v28 == nil) goto v63;
    v29 = elt(env, 3); /* !*comma!* */
    v28 = (Lisp_Object)1; /* 0 */
    v5 = v406;
    fn = elt(env, 4); /* inprinla */
    v28 = (*qfnn(fn))(qenv(fn), 3, v29, v28, v5);
    nil = C_nil;
    if (exception_pending()) goto v76;
    goto v419;

v419:
    v28 = nil;
    { popv(2); return onevalue(v28); }

v63:
    v28 = v406;
    stack[0] = v28;
    goto v189;

v189:
    v28 = stack[0];
    if (v28 == nil) goto v419;
    v28 = stack[0];
    v28 = qcar(v28);
    fn = elt(env, 5); /* prinlatom */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[-1];
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v189;
/* error exit handlers */
v76:
    popv(2);
    return nil;
}



/* Code for infinityp */

static Lisp_Object CC_infinityp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v180, v181, v408;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for infinityp");
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
    v180 = v0;
/* end of prologue */
    v180 = Lexplode(nil, v180);
    nil = C_nil;
    if (exception_pending()) goto v391;
    env = stack[0];
    v180 = qcar(v180);
    v408 = v180;
    v181 = v408;
    v180 = elt(env, 1); /* !- */
    v180 = (v181 == v180 ? lisp_true : nil);
    if (!(v180 == nil)) goto v372;
    v180 = v408;
    v180 = Ldigitp(nil, v180);
    goto v372;

v372:
    v180 = (v180 == nil ? lisp_true : nil);
    { popv(1); return onevalue(v180); }
/* error exit handlers */
v391:
    popv(1);
    return nil;
}



/* Code for all_defined */

static Lisp_Object CC_all_defined(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v418, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_defined");
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
    v418 = v0;
/* end of prologue */
    stack[-1] = v418;
    fn = elt(env, 1); /* map__edges */
    v180 = (*qfn1(fn))(qenv(fn), v418);
    nil = C_nil;
    if (exception_pending()) goto v391;
    env = stack[-2];
    v418 = stack[0];
    fn = elt(env, 2); /* defined_append */
    v418 = (*qfn2(fn))(qenv(fn), v180, v418);
    nil = C_nil;
    if (exception_pending()) goto v391;
    env = stack[-2];
    {
        Lisp_Object v427 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* all_defined_map_ */
        return (*qfn2(fn))(qenv(fn), v427, v418);
    }
/* error exit handlers */
v391:
    popv(3);
    return nil;
}



/* Code for formclear */

static Lisp_Object MS_CDECL CC_formclear(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v391, v427, v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclear");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formclear");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v391 = v2;
    v427 = v1;
    v188 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* clear */
    v188 = qcdr(v188);
    fn = elt(env, 2); /* formclear1 */
    v391 = (*qfnn(fn))(qenv(fn), 3, v188, v427, v391);
    nil = C_nil;
    if (exception_pending()) goto v360;
    {
        Lisp_Object v419 = stack[0];
        popv(1);
        return list2(v419, v391);
    }
/* error exit handlers */
v360:
    popv(1);
    return nil;
}



/* Code for x!*!*p!-w */

static Lisp_Object MS_CDECL CC_xHHpKw(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v360, v419;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "x**p-w");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for x**p-w");
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
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    v360 = v1;
    v419 = v0;
/* end of prologue */
    fn = elt(env, 1); /* to */
    v419 = (*qfn2(fn))(qenv(fn), v419, v360);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v360 = (Lisp_Object)17; /* 1 */
    v360 = cons(v419, v360);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v419 = ncons(v360);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-1];
    v360 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* general!-difference!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v419, v360);
    }
/* error exit handlers */
v64:
    popv(2);
    return nil;
}



/* Code for derivative!-mod!-p */

static Lisp_Object CC_derivativeKmodKp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v171, v74;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for derivative-mod-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v74 = v0;
/* end of prologue */
    v61 = v74;
    if (!consp(v61)) goto v55;
    v61 = v74;
    v61 = qcar(v61);
    if (!consp(v61)) goto v55;
    v61 = v74;
    v61 = qcar(v61);
    v61 = qcar(v61);
    v171 = qcdr(v61);
    v61 = (Lisp_Object)17; /* 1 */
    if (v171 == v61) goto v90;
    v61 = v74;
    v171 = v74;
    v171 = qcar(v171);
    v171 = qcar(v171);
    v171 = qcar(v171);
    {
        fn = elt(env, 2); /* derivative!-mod!-p!-1 */
        return (*qfn2(fn))(qenv(fn), v61, v171);
    }

v90:
    v61 = v74;
    v61 = qcar(v61);
    v61 = qcdr(v61);
    return onevalue(v61);

v55:
    v61 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v61);
}



/* Code for rl_pnf */

static Lisp_Object CC_rl_pnf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v452;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_pnf");
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
    v452 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_pnf!* */
    v452 = ncons(v452);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-1];
    {
        Lisp_Object v92 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v92, v452);
    }
/* error exit handlers */
v89:
    popv(2);
    return nil;
}



/* Code for insertglue */

static Lisp_Object CC_insertglue(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v456, v400, v457, v158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insertglue");
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
    v456 = (Lisp_Object)1; /* 0 */
    stack[-1] = v456;
    stack[-2] = v456;
    v456 = qvalue(elt(env, 1)); /* nil */
    stack[-5] = v456;
    v456 = stack[-4];
    stack[-3] = v456;
    goto v365;

v365:
    v456 = stack[-4];
    if (v456 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v456 = stack[-5];
    v400 = v456;
    v456 = stack[-4];
    v456 = qcar(v456);
    stack[-5] = v456;
    v158 = v400;
    v457 = stack[-5];
    v400 = stack[-2];
    v456 = stack[-1];
    fn = elt(env, 10); /* interglue */
    v456 = (*qfnn(fn))(qenv(fn), 4, v158, v457, v400, v456);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    v400 = v456;
    v456 = v400;
    if (v456 == nil) goto v99;
    v456 = stack[-4];
    v456 = cons(v400, v456);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    v456 = Lrplacd(nil, stack[0], v456);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    goto v99;

v99:
    v456 = stack[-4];
    stack[0] = v456;
    v456 = stack[-4];
    v456 = qcdr(v456);
    stack[-4] = v456;
    v400 = stack[-5];
    v456 = elt(env, 2); /* class */
    v400 = get(v400, v456);
    env = stack[-6];
    v456 = elt(env, 3); /* inn */
    if (v400 == v456) goto v389;
    v400 = stack[-5];
    v456 = elt(env, 2); /* class */
    v400 = get(v400, v456);
    env = stack[-6];
    v456 = elt(env, 8); /* opn */
    if (v400 == v456) goto v447;
    v400 = stack[-5];
    v456 = elt(env, 2); /* class */
    v400 = get(v400, v456);
    env = stack[-6];
    v456 = elt(env, 9); /* clo */
    if (!(v400 == v456)) goto v365;
    v456 = stack[-1];
    v456 = sub1(v456);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    stack[-1] = v456;
    goto v365;

v447:
    v456 = stack[-1];
    v456 = add1(v456);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    stack[-1] = v456;
    goto v365;

v389:
    v400 = stack[-5];
    v456 = elt(env, 4); /* textag */
    v400 = get(v400, v456);
    env = stack[-6];
    v456 = elt(env, 5); /* (beg sup sub frc mat) */
    v456 = Lmemq(nil, v400, v456);
    if (v456 == nil) goto v41;
    v400 = stack[-5];
    v456 = elt(env, 4); /* textag */
    v400 = get(v400, v456);
    env = stack[-6];
    v456 = elt(env, 6); /* frc */
    if (!(v400 == v456)) goto v425;
    v400 = stack[-2];
    v456 = (Lisp_Object)1; /* 0 */
    if (!(v400 == v456)) goto v425;

v41:
    v400 = stack[-5];
    v456 = elt(env, 4); /* textag */
    v400 = get(v400, v456);
    env = stack[-6];
    v456 = elt(env, 7); /* end */
    if (!(v400 == v456)) goto v365;
    v400 = stack[-2];
    v456 = (Lisp_Object)1; /* 0 */
    v456 = (Lisp_Object)greaterp2(v400, v456);
    nil = C_nil;
    if (exception_pending()) goto v14;
    v456 = v456 ? lisp_true : nil;
    env = stack[-6];
    if (v456 == nil) goto v365;
    v456 = stack[-2];
    v456 = sub1(v456);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    stack[-2] = v456;
    goto v365;

v425:
    v456 = stack[-2];
    v456 = add1(v456);
    nil = C_nil;
    if (exception_pending()) goto v14;
    env = stack[-6];
    stack[-2] = v456;
    goto v365;
/* error exit handlers */
v14:
    popv(7);
    return nil;
}



/* Code for smallest!-increment */

static Lisp_Object CC_smallestKincrement(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v460, v37, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smallest-increment");
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
    v460 = stack[-3];
    if (v460 == nil) goto v55;
    v460 = stack[-3];
    v460 = qcar(v460);
    v460 = qcar(v460);
    stack[-4] = v460;
    v460 = stack[-4];
    if (v460 == nil) goto v188;
    v460 = stack[-4];
    v460 = qcar(v460);
    fn = elt(env, 2); /* get!-denom!-l */
    v460 = (*qfn1(fn))(qenv(fn), v460);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    v460 = ncons(v460);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    stack[-1] = v460;
    stack[-2] = v460;
    goto v418;

v418:
    v460 = stack[-4];
    v460 = qcdr(v460);
    stack[-4] = v460;
    v460 = stack[-4];
    if (v460 == nil) goto v62;
    stack[0] = stack[-1];
    v460 = stack[-4];
    v460 = qcar(v460);
    fn = elt(env, 2); /* get!-denom!-l */
    v460 = (*qfn1(fn))(qenv(fn), v460);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    v460 = ncons(v460);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    v460 = Lrplacd(nil, stack[0], v460);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    v460 = stack[-1];
    v460 = qcdr(v460);
    stack[-1] = v460;
    goto v418;

v62:
    v460 = stack[-2];
    goto v365;

v365:
    v37 = v460;
    v460 = stack[-3];
    v460 = qcdr(v460);
    stack[0] = v460;
    goto v57;

v57:
    v460 = stack[0];
    if (v460 == nil) goto v56;
    v460 = stack[0];
    v460 = qcar(v460);
    v460 = qcar(v460);
    fn = elt(env, 3); /* get!-denom!-ll */
    v460 = (*qfn2(fn))(qenv(fn), v37, v460);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    v37 = v460;
    v460 = stack[0];
    v460 = qcdr(v460);
    stack[0] = v460;
    goto v57;

v56:
    v460 = v37;
    stack[-3] = v460;
    v460 = stack[-3];
    if (v460 == nil) goto v175;
    v460 = stack[-3];
    v460 = qcar(v460);
    v32 = v460;
    v37 = v32;
    v460 = (Lisp_Object)17; /* 1 */
    if (v37 == v460) goto v462;
    v460 = (Lisp_Object)17; /* 1 */
    v37 = v32;
    fn = elt(env, 4); /* mkrn */
    v460 = (*qfn2(fn))(qenv(fn), v460, v37);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    goto v463;

v463:
    v460 = ncons(v460);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    stack[-1] = v460;
    stack[-2] = v460;
    goto v355;

v355:
    v460 = stack[-3];
    v460 = qcdr(v460);
    stack[-3] = v460;
    v460 = stack[-3];
    if (v460 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v460 = stack[-3];
    v460 = qcar(v460);
    v32 = v460;
    v37 = v32;
    v460 = (Lisp_Object)17; /* 1 */
    if (v37 == v460) goto v421;
    v460 = (Lisp_Object)17; /* 1 */
    v37 = v32;
    fn = elt(env, 4); /* mkrn */
    v460 = (*qfn2(fn))(qenv(fn), v460, v37);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    goto v412;

v412:
    v460 = ncons(v460);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    v460 = Lrplacd(nil, stack[0], v460);
    nil = C_nil;
    if (exception_pending()) goto v461;
    env = stack[-5];
    v460 = stack[-1];
    v460 = qcdr(v460);
    stack[-1] = v460;
    goto v355;

v421:
    v460 = v32;
    goto v412;

v462:
    v460 = v32;
    goto v463;

v175:
    v460 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v460); }

v188:
    v460 = qvalue(elt(env, 1)); /* nil */
    goto v365;

v55:
    v460 = elt(env, 0); /* smallest!-increment */
    {
        popv(6);
        fn = elt(env, 5); /* confusion */
        return (*qfn1(fn))(qenv(fn), v460);
    }
/* error exit handlers */
v461:
    popv(6);
    return nil;
}



/* Code for ratpoly_nullp */

static Lisp_Object CC_ratpoly_nullp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v66, v365;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_nullp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v66 = v0;
/* end of prologue */
    v365 = v66;
    v365 = qcar(v365);
    v365 = (v365 == nil ? lisp_true : nil);
    if (!(v365 == nil)) return onevalue(v365);
    v365 = qcar(v66);
    v66 = (Lisp_Object)1; /* 0 */
    v66 = (v365 == v66 ? lisp_true : nil);
    return onevalue(v66);
}



/* Code for ps!:minus!-erule */

static Lisp_Object CC_psTminusKerule(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:minus-erule");
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
    v92 = v1;
    v65 = v0;
/* end of prologue */
    v65 = qcdr(v65);
    v65 = qcar(v65);
    fn = elt(env, 1); /* ps!:evaluate */
    v92 = (*qfn2(fn))(qenv(fn), v65, v92);
    nil = C_nil;
    if (exception_pending()) goto v91;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* negsq */
        return (*qfn1(fn))(qenv(fn), v92);
    }
/* error exit handlers */
v91:
    popv(1);
    return nil;
}



/* Code for pi!* */

static Lisp_Object MS_CDECL CC_piH(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v418, v180;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "pi*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pi*");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v180 = qvalue(elt(env, 1)); /* !:prec!: */
    v418 = (Lisp_Object)16001; /* 1000 */
    v418 = (Lisp_Object)greaterp2(v180, v418);
    nil = C_nil;
    if (exception_pending()) goto v181;
    v418 = v418 ? lisp_true : nil;
    env = stack[0];
    if (v418 == nil) goto v65;
    v418 = qvalue(elt(env, 2)); /* !:bprec!: */
    {
        popv(1);
        fn = elt(env, 3); /* !:bigpi */
        return (*qfn1(fn))(qenv(fn), v418);
    }

v65:
    v418 = qvalue(elt(env, 2)); /* !:bprec!: */
    {
        popv(1);
        fn = elt(env, 4); /* !:pi */
        return (*qfn1(fn))(qenv(fn), v418);
    }
/* error exit handlers */
v181:
    popv(1);
    return nil;
}



/* Code for lengthf */

static Lisp_Object CC_lengthf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v376, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lengthf");
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
    v376 = stack[-1];
    if (v376 == nil) goto v55;
    v376 = stack[-1];
    if (!consp(v376)) goto v186;
    v9 = stack[-1];
    v376 = elt(env, 1); /* plus */
    if (!consp(v9)) goto v442;
    v9 = qcar(v9);
    if (!(v9 == v376)) goto v442;
    stack[0] = (Lisp_Object)49; /* 3 */
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = Llength(nil, v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v376 = sub1(v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    stack[0] = times2(stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = CC_lengthf(env, v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    {
        Lisp_Object v141 = stack[0];
        popv(4);
        return plus2(v141, v376);
    }

v442:
    v9 = stack[-1];
    v376 = elt(env, 2); /* times */
    if (!consp(v9)) goto v319;
    v9 = qcar(v9);
    if (!(v9 == v376)) goto v319;

v29:
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = Llength(nil, v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    stack[0] = sub1(v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = CC_lengthf(env, v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    {
        Lisp_Object v105 = stack[0];
        popv(4);
        return plus2(v105, v376);
    }

v319:
    v9 = stack[-1];
    v376 = elt(env, 3); /* minus */
    if (!consp(v9)) goto v178;
    v9 = qcar(v9);
    if (v9 == v376) goto v29;
    else goto v178;

v178:
    v9 = stack[-1];
    v376 = elt(env, 4); /* quotient */
    if (!consp(v9)) goto v467;
    v9 = qcar(v9);
    if (!(v9 == v376)) goto v467;
    v376 = qvalue(elt(env, 5)); /* !*rational */
    if (v376 == nil) goto v385;
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcar(v376);
    fn = elt(env, 15); /* flatsizec */
    stack[0] = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    v376 = qcar(v376);
    fn = elt(env, 15); /* flatsizec */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    fn = elt(env, 16); /* max */
    v376 = (*qfn2(fn))(qenv(fn), stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v376 = add1(v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    popv(4);
    return add1(v376);

v385:
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcar(v376);
    fn = elt(env, 15); /* flatsizec */
    stack[0] = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    v376 = qcar(v376);
    fn = elt(env, 15); /* flatsizec */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v376 = plus2(stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    popv(4);
    return add1(v376);

v467:
    v9 = stack[-1];
    v376 = elt(env, 6); /* expt */
    if (!consp(v9)) goto v420;
    v9 = qcar(v9);
    if (!(v9 == v376)) goto v420;
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcar(v376);
    fn = elt(env, 15); /* flatsizec */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    popv(4);
    return add1(v376);

v420:
    v9 = stack[-1];
    v376 = elt(env, 7); /* dx */
    if (!consp(v9)) goto v164;
    v9 = qcar(v9);
    if (!(v9 == v376)) goto v164;

v458:
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcar(v376);
    fn = elt(env, 15); /* flatsizec */
    v9 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    v376 = (Lisp_Object)65; /* 4 */
    popv(4);
    return plus2(v9, v376);

v164:
    v9 = stack[-1];
    v376 = elt(env, 8); /* du */
    if (!consp(v9)) goto v80;
    v9 = qcar(v9);
    if (v9 == v376) goto v458;
    else goto v80;

v80:
    v9 = stack[-1];
    v376 = elt(env, 9); /* xi */
    if (!consp(v9)) goto v468;
    v9 = qcar(v9);
    if (!(v9 == v376)) goto v468;

v307:
    stack[0] = (Lisp_Object)33; /* 2 */
    v376 = stack[-1];
    v376 = Llength(nil, v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    {
        Lisp_Object v111 = stack[0];
        popv(4);
        return times2(v111, v376);
    }

v468:
    v9 = stack[-1];
    v376 = elt(env, 10); /* eta */
    if (!consp(v9)) goto v456;
    v9 = qcar(v9);
    if (v9 == v376) goto v307;
    else goto v456;

v456:
    v9 = stack[-1];
    v376 = elt(env, 11); /* c */
    if (!consp(v9)) goto v469;
    v9 = qcar(v9);
    if (v9 == v376) goto v307;
    else goto v469;

v469:
    v9 = stack[-1];
    v376 = elt(env, 12); /* x */
    if (!consp(v9)) goto v401;
    v9 = qcar(v9);
    if (v9 == v376) goto v307;
    else goto v401;

v401:
    v9 = stack[-1];
    v376 = elt(env, 13); /* u */
    if (!consp(v9)) goto v470;
    v9 = qcar(v9);
    if (v9 == v376) goto v307;
    else goto v470;

v470:
    v9 = stack[-1];
    v376 = elt(env, 14); /* df */
    if (!consp(v9)) goto v436;
    v9 = qcar(v9);
    if (!(v9 == v376)) goto v436;
    stack[-2] = (Lisp_Object)65; /* 4 */
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcar(v376);
    stack[0] = CC_lengthf(env, v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    v376 = CC_lengthf(env, v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v376 = plus2(stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    {
        Lisp_Object v13 = stack[-2];
        popv(4);
        return plus2(v13, v376);
    }

v436:
    v376 = stack[-1];
    v376 = qcar(v376);
    stack[0] = CC_lengthf(env, v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    env = stack[-3];
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = CC_lengthf(env, v376);
    nil = C_nil;
    if (exception_pending()) goto v143;
    {
        Lisp_Object v11 = stack[0];
        popv(4);
        return plus2(v11, v376);
    }

v186:
    v376 = stack[-1];
    {
        popv(4);
        fn = elt(env, 15); /* flatsizec */
        return (*qfn1(fn))(qenv(fn), v376);
    }

v55:
    v376 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v376); }
/* error exit handlers */
v143:
    popv(4);
    return nil;
}



/* Code for mod!-domainvalchk */

static Lisp_Object CC_modKdomainvalchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v358, v357, v409;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod-domainvalchk");
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
    v409 = v1;
    v358 = v0;
/* end of prologue */
    v357 = v358;
    v358 = elt(env, 1); /* expt */
    if (v357 == v358) goto v365;
    v358 = qvalue(elt(env, 2)); /* nil */
    goto v372;

v372:
    v409 = v358;
    v357 = v409;
    v358 = elt(env, 3); /* failed */
    if (v357 == v358) goto v471;
    v357 = v409;
    v358 = (Lisp_Object)17; /* 1 */
    popv(1);
    return cons(v357, v358);

v471:
    v358 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v358); }

v365:
    v358 = v409;
    v358 = qcar(v358);
    v357 = v409;
    v357 = qcdr(v357);
    v357 = qcar(v357);
    fn = elt(env, 4); /* mod!-expt!-fract */
    v358 = (*qfn2(fn))(qenv(fn), v358, v357);
    nil = C_nil;
    if (exception_pending()) goto v319;
    env = stack[0];
    goto v372;
/* error exit handlers */
v319:
    popv(1);
    return nil;
}



setup_type const u45_setup[] =
{
    {"mchcomb",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mchcomb},
    {"numpoly_nullp",           CC_numpoly_nullp,too_many_1,   wrong_no_1},
    {"bra_mk",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_bra_mk},
    {"cos:",                    too_few_2,      CC_cosT,       wrong_no_2},
    {"fortexp1",                too_few_2,      CC_fortexp1,   wrong_no_2},
    {"delength",                CC_delength,    too_many_1,    wrong_no_1},
    {"mk_world1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_mk_world1},
    {"simpdfp",                 CC_simpdfp,     too_many_1,    wrong_no_1},
    {"permp:",                  too_few_2,      CC_permpT,     wrong_no_2},
    {"horner-rule-in-order-mod-p",wrong_no_na,  wrong_no_nb,   (n_args *)CC_hornerKruleKinKorderKmodKp},
    {"evaluateuconst",          CC_evaluateuconst,too_many_1,  wrong_no_1},
    {"multtaylor1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_multtaylor1},
    {"mk+inner+mat",            CC_mkLinnerLmat,too_many_1,    wrong_no_1},
    {"prinindexs",              CC_prinindexs,  too_many_1,    wrong_no_1},
    {"infinityp",               CC_infinityp,   too_many_1,    wrong_no_1},
    {"all_defined",             too_few_2,      CC_all_defined,wrong_no_2},
    {"formclear",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclear},
    {"x**p-w",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_xHHpKw},
    {"derivative-mod-p",        CC_derivativeKmodKp,too_many_1,wrong_no_1},
    {"rl_pnf",                  CC_rl_pnf,      too_many_1,    wrong_no_1},
    {"insertglue",              CC_insertglue,  too_many_1,    wrong_no_1},
    {"smallest-increment",      CC_smallestKincrement,too_many_1,wrong_no_1},
    {"ratpoly_nullp",           CC_ratpoly_nullp,too_many_1,   wrong_no_1},
    {"ps:minus-erule",          too_few_2,      CC_psTminusKerule,wrong_no_2},
    {"pi*",                     wrong_no_na,    wrong_no_nb,   (n_args *)CC_piH},
    {"lengthf",                 CC_lengthf,     too_many_1,    wrong_no_1},
    {"mod-domainvalchk",        too_few_2,      CC_modKdomainvalchk,wrong_no_2},
    {NULL, (one_args *)"u45", (two_args *)"6298 8205541 7487576", 0}
};

/* end of generated code */
