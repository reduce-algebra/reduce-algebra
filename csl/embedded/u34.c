
/* $destdir/generated-c\u34.c Machine generated C code */

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


/* Code for vdp_setsugar */

static Lisp_Object CC_vdp_setsugar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdp_setsugar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v1;
    v7 = v0;
/* end of prologue */
    v6 = qvalue(elt(env, 1)); /* !*cgbsugar */
    if (v6 == nil) return onevalue(v7);
    v6 = elt(env, 2); /* sugar */
    {
        fn = elt(env, 3); /* vdp_putprop */
        return (*qfnn(fn))(qenv(fn), 3, v7, v6, v5);
    }
}



/* Code for diff2 */

static Lisp_Object CC_diff2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35, v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff2");
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
    v36 = v0;
/* end of prologue */
    v34 = v36;
    v34 = qcar(v34);
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    v34 = qcar(v34);
    stack[-5] = v34;
    v34 = v36;
    v34 = qcar(v34);
    v34 = qcdr(v34);
    v34 = qcar(v34);
    stack[-4] = v34;
    v35 = stack[-5];
    v34 = (Lisp_Object)17; /* 1 */
    if (v35 == v34) { popv(8); return onevalue(v36); }
    v34 = v36;
    v34 = Lreverse(nil, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v34 = qcar(v34);
    stack[-6] = v34;
    stack[-3] = elt(env, 1); /* diff */
    stack[-2] = qvalue(elt(env, 2)); /* nil */
    stack[-1] = elt(env, 3); /* bvar */
    v36 = stack[-4];
    v35 = (Lisp_Object)17; /* 1 */
    v34 = qvalue(elt(env, 2)); /* nil */
    stack[0] = list2star(v36, v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v34 = stack[-6];
    v34 = ncons(v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v34 = acons(stack[-1], stack[0], v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v34 = list2star(stack[-3], stack[-2], v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    stack[-6] = v34;
    v34 = stack[-5];
    v34 = sub1(v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    stack[-5] = v34;
    goto v38;

v38:
    v35 = stack[-5];
    v34 = (Lisp_Object)1; /* 0 */
    v34 = (Lisp_Object)greaterp2(v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    v34 = v34 ? lisp_true : nil;
    env = stack[-7];
    if (v34 == nil) goto v39;
    stack[-3] = elt(env, 1); /* diff */
    stack[-2] = qvalue(elt(env, 2)); /* nil */
    stack[-1] = elt(env, 3); /* bvar */
    v36 = stack[-4];
    v35 = (Lisp_Object)17; /* 1 */
    v34 = qvalue(elt(env, 2)); /* nil */
    stack[0] = list2star(v36, v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v34 = stack[-6];
    v34 = ncons(v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v34 = acons(stack[-1], stack[0], v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    v34 = list2star(stack[-3], stack[-2], v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    stack[-6] = v34;
    v34 = stack[-5];
    v34 = sub1(v34);
    nil = C_nil;
    if (exception_pending()) goto v37;
    env = stack[-7];
    stack[-5] = v34;
    goto v38;

v39:
    v34 = stack[-6];
    v34 = qcdr(v34);
    v34 = qcdr(v34);
    { popv(8); return onevalue(v34); }
/* error exit handlers */
v37:
    popv(8);
    return nil;
}



/* Code for resetparser */

static Lisp_Object MS_CDECL CC_resetparser(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "resetparser");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for resetparser");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v40 = qvalue(elt(env, 1)); /* !*slin */
    if (v40 == nil) goto v15;
    v40 = nil;
    return onevalue(v40);

v15:
    v40 = qvalue(elt(env, 2)); /* t */
    {
        fn = elt(env, 3); /* comm1 */
        return (*qfn1(fn))(qenv(fn), v40);
    }
}



/* Code for lengthn */

static Lisp_Object CC_lengthn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v42;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lengthn");
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
    v42 = stack[0];
    if (v42 == nil) goto v10;
    v42 = stack[0];
    v42 = qcar(v42);
    if (is_number(v42)) goto v43;
    v42 = stack[0];
    v42 = qcdr(v42);
    v42 = CC_lengthn(env, v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    popv(3);
    return add1(v42);

v43:
    v42 = stack[0];
    v42 = qcar(v42);
    stack[-1] = sub1(v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    v42 = stack[0];
    v42 = qcdr(v42);
    v42 = CC_lengthn(env, v42);
    nil = C_nil;
    if (exception_pending()) goto v44;
    {
        Lisp_Object v45 = stack[-1];
        popv(3);
        return plus2(v45, v42);
    }

v10:
    v42 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v42); }
/* error exit handlers */
v44:
    popv(3);
    return nil;
}



/* Code for dipcontenti */

static Lisp_Object CC_dipcontenti(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v47, v48, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontenti");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v49 = v0;
/* end of prologue */
    v26 = v49;
    if (v26 == nil) goto v10;
    v26 = v49;
    v26 = qcdr(v26);
    v26 = qcdr(v26);
    v48 = v26;
    v26 = v48;
    if (v26 == nil) goto v3;
    v26 = v49;
    v26 = qcdr(v26);
    v47 = qcar(v26);
    v26 = qvalue(elt(env, 1)); /* !*groebrm */
    if (v26 == nil) goto v50;
    v26 = v49;
    v26 = qcar(v26);
    goto v51;

v51:
    {
        fn = elt(env, 3); /* dipcontenti1 */
        return (*qfnn(fn))(qenv(fn), 3, v47, v26, v48);
    }

v50:
    v26 = qvalue(elt(env, 2)); /* nil */
    goto v51;

v3:
    v26 = v49;
    v26 = qcdr(v26);
    v47 = qcar(v26);
    v26 = qvalue(elt(env, 1)); /* !*groebrm */
    if (v26 == nil) goto v52;
    v26 = v49;
    v26 = qcar(v26);
    goto v6;

v6:
    return cons(v47, v26);

v52:
    v26 = qvalue(elt(env, 2)); /* nil */
    goto v6;

v10:
    v26 = (Lisp_Object)17; /* 1 */
    return onevalue(v26);
}



/* Code for exptbf */

static Lisp_Object MS_CDECL CC_exptbf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "exptbf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exptbf");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v58:
    v57 = stack[-1];
    v57 = Levenp(nil, v57);
    env = stack[-3];
    if (!(v57 == nil)) goto v5;
    v27 = stack[0];
    v57 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v57 = (*qfn2(fn))(qenv(fn), v27, v57);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    stack[0] = v57;
    goto v5;

v5:
    v27 = stack[-1];
    v57 = (Lisp_Object)-15; /* -1 */
    v57 = ash(v27, v57);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    stack[-1] = v57;
    v27 = stack[-1];
    v57 = (Lisp_Object)1; /* 0 */
    if (v27 == v57) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v27 = stack[-2];
    v57 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v57 = (*qfn2(fn))(qenv(fn), v27, v57);
    nil = C_nil;
    if (exception_pending()) goto v59;
    env = stack[-3];
    stack[-2] = v57;
    goto v58;
/* error exit handlers */
v59:
    popv(4);
    return nil;
}



/* Code for mkassign */

static Lisp_Object CC_mkassign(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63, v64;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkassign");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v62 = v1;
    v63 = v0;
/* end of prologue */
    v64 = elt(env, 1); /* setq */
    return list3(v64, v63, v62);
}



/* Code for listminimize */

static Lisp_Object CC_listminimize(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v7, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listminimize");
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
    v6 = v1;
    v7 = v0;
/* end of prologue */
    v65 = v7;
    if (v65 == nil) goto v19;
    v65 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* cali!=min */
    v6 = (*qfnn(fn))(qenv(fn), 3, v65, v7, v6);
    errexit();
        return Lreverse(nil, v6);

v19:
    v6 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v6);
}



/* Code for addnew */

static Lisp_Object MS_CDECL CC_addnew(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v57, v27, v25, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "addnew");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for addnew");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v28;
    v25 = v1;
    v68 = v0;
/* end of prologue */
    v27 = qvalue(elt(env, 1)); /* gv */
    v57 = v25;
    v54 = v68;
    *(Lisp_Object *)((char *)v27 + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL))) = v54;
    v27 = qvalue(elt(env, 2)); /* bv */
    v57 = v25;
    v54 = qvalue(elt(env, 3)); /* t */
    *(Lisp_Object *)((char *)v27 + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL))) = v54;
    v54 = v68;
    if (v54 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = v25;
    v54 = v68;
    fn = elt(env, 4); /* ljet */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v57 = cons(stack[-1], v54);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-2];
    v54 = stack[0];
    fn = elt(env, 5); /* insert */
    v54 = (*qfn2(fn))(qenv(fn), v57, v54);
    nil = C_nil;
    if (exception_pending()) goto v69;
    { popv(3); return onevalue(v54); }
/* error exit handlers */
v69:
    popv(3);
    return nil;
}



/* Code for lesspcar */

static Lisp_Object CC_lesspcar(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lesspcar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v43 = v1;
    v62 = v0;
/* end of prologue */
    v62 = qcar(v62);
    v43 = qcar(v43);
        return Llessp(nil, v62, v43);
}



/* Code for coeffs!-to!-form1 */

static Lisp_Object MS_CDECL CC_coeffsKtoKform1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v47, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "coeffs-to-form1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeffs-to-form1");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v28;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v47 = stack[-1];
    v26 = (Lisp_Object)1; /* 0 */
    v26 = (Lisp_Object)greaterp2(v47, v26);
    nil = C_nil;
    if (exception_pending()) goto v73;
    v26 = v26 ? lisp_true : nil;
    env = stack[-5];
    if (v26 == nil) goto v50;
    v26 = stack[-3];
    stack[-4] = qcdr(v26);
    stack[0] = stack[-2];
    v26 = stack[-1];
    v26 = sub1(v26);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    v26 = CC_coeffsKtoKform1(env, 3, stack[-4], stack[0], v26);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-5];
    stack[0] = v26;
    v26 = stack[-3];
    v26 = qcar(v26);
    if (v26 == nil) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    v47 = stack[-2];
    v26 = stack[-1];
    fn = elt(env, 1); /* to */
    v48 = (*qfn2(fn))(qenv(fn), v47, v26);
    nil = C_nil;
    if (exception_pending()) goto v73;
    v26 = stack[-3];
    v47 = qcar(v26);
    v26 = stack[0];
    popv(6);
    return acons(v48, v47, v26);

v50:
    v26 = stack[-3];
    v26 = qcar(v26);
    { popv(6); return onevalue(v26); }
/* error exit handlers */
v73:
    popv(6);
    return nil;
}



/* Code for vdelete */

static Lisp_Object CC_vdelete(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v57, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdelete");
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
    v27 = nil;
    goto v58;

v58:
    v54 = stack[0];
    if (v54 == nil) goto v75;
    v54 = stack[-1];
    v57 = qcar(v54);
    v54 = stack[0];
    v54 = qcar(v54);
    v54 = qcar(v54);
    if (equal(v57, v54)) goto v33;
    v54 = stack[0];
    v54 = qcar(v54);
    v57 = v27;
    v54 = cons(v54, v57);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    v27 = v54;
    v54 = stack[0];
    v54 = qcdr(v54);
    stack[0] = v54;
    goto v58;

v33:
    v57 = v27;
    v54 = stack[0];
    v54 = qcdr(v54);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v57, v54);
    }

v75:
    v54 = v27;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v54);
    }
/* error exit handlers */
v71:
    popv(3);
    return nil;
}



/* Code for rule!* */

static Lisp_Object MS_CDECL CC_ruleH(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v28, Lisp_Object v15,
                         Lisp_Object v10, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103, v104, v105, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "rule*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rule*");
#endif
    if (stack >= stacklimit)
    {
        push5(v10,v15,v28,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v28,v15,v10);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v10;
    stack[-1] = v15;
    stack[-2] = v28;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v102 = stack[-2];
    qvalue(elt(env, 1)) = v102; /* frasc!* */
    v103 = stack[-1];
    v102 = qvalue(elt(env, 2)); /* t */
    v102 = (v103 == v102 ? lisp_true : nil);
    if (!(v102 == nil)) goto v61;
    v103 = stack[-2];
    v102 = stack[-1];
    v102 = Lsubla(nil, v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    goto v61;

v61:
    qvalue(elt(env, 3)) = v102; /* mcond!* */
    v102 = stack[0];
    if (v102 == nil) goto v108;
    v103 = stack[0];
    v102 = elt(env, 4); /* old */
    if (v103 == v102) goto v108;
    v105 = stack[-4];
    v104 = stack[-3];
    v103 = stack[-2];
    v102 = stack[-1];
    v102 = list4(v105, v104, v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    qvalue(elt(env, 5)) = v102; /* newrule!* */
    v102 = stack[-4];
    if (!(symbolp(v102))) goto v109;
    v103 = stack[-4];
    v102 = elt(env, 6); /* rtype */
    v102 = get(v103, v102);
    env = stack[-5];
    v103 = v102;
    if (v102 == nil) goto v110;
    stack[-1] = stack[-4];
    v102 = elt(env, 6); /* rtype */
    v103 = cons(v102, v103);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v102 = qvalue(elt(env, 7)); /* props!* */
    v102 = acons(stack[-1], v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    qvalue(elt(env, 7)) = v102; /* props!* */
    v103 = stack[-4];
    v102 = elt(env, 6); /* rtype */
    v102 = Lremprop(nil, v103, v102);
    env = stack[-5];
    goto v110;

v110:
    v103 = stack[-4];
    v102 = elt(env, 8); /* avalue */
    v102 = get(v103, v102);
    env = stack[-5];
    v103 = v102;
    if (v102 == nil) goto v109;
    v102 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 12); /* updoldrules */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    v103 = stack[-4];
    v102 = elt(env, 8); /* avalue */
    v102 = Lremprop(nil, v103, v102);
    env = stack[-5];
    goto v109;

v109:
    v103 = stack[-3];
    v102 = (Lisp_Object)1; /* 0 */
    if (!(v103 == v102)) goto v108;
    v103 = stack[-4];
    v102 = elt(env, 10); /* expt */
    if (!consp(v103)) goto v108;
    v103 = qcar(v103);
    if (!(v103 == v102)) goto v108;
    v102 = stack[-4];
    v102 = qcdr(v102);
    v102 = qcar(v102);
    if (!(symbolp(v102))) goto v108;
    v102 = stack[-4];
    v102 = qcdr(v102);
    v102 = qcdr(v102);
    v102 = qcar(v102);
    if (!(is_number(v102))) goto v108;
    v102 = stack[-4];
    v102 = qcdr(v102);
    v103 = qcar(v102);
    v102 = qvalue(elt(env, 11)); /* asymplis!* */
    v102 = Lassoc(nil, v103, v102);
    v103 = v102;
    if (v102 == nil) goto v108;
    v102 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 12); /* updoldrules */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v107;
    env = stack[-5];
    goto v108;

v108:
    v106 = stack[-4];
    v105 = stack[-3];
    v104 = stack[-2];
    v103 = stack[0];
    v102 = elt(env, 4); /* old */
    if (v103 == v102) goto v111;
    v102 = stack[0];
    goto v112;

v112:
    {
        popv(6);
        fn = elt(env, 13); /* rule */
        return (*qfnn(fn))(qenv(fn), 4, v106, v105, v104, v102);
    }

v111:
    v102 = qvalue(elt(env, 2)); /* t */
    goto v112;
/* error exit handlers */
v107:
    popv(6);
    return nil;
}



/* Code for quotf!* */

static Lisp_Object CC_quotfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v39, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotf*");
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
    v116 = stack[-1];
    if (v116 == nil) goto v19;
    v39 = stack[-1];
    v116 = stack[0];
    fn = elt(env, 3); /* quotf */
    v116 = (*qfn2(fn))(qenv(fn), v39, v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    v39 = v116;
    v116 = v39;
    if (!(v116 == nil)) { popv(3); return onevalue(v39); }
    v39 = stack[-1];
    v116 = stack[0];
    v116 = cons(v39, v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    fn = elt(env, 4); /* rationalizesq */
    v116 = (*qfn1(fn))(qenv(fn), v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    v117 = v116;
    v116 = v117;
    v39 = qcdr(v116);
    v116 = (Lisp_Object)17; /* 1 */
    if (v39 == v116) goto v24;
    v117 = elt(env, 2); /* "DIVISION FAILED" */
    v39 = stack[-1];
    v116 = stack[0];
    v116 = list3(v117, v39, v116);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 5); /* errach */
        return (*qfn1(fn))(qenv(fn), v116);
    }

v24:
    v116 = v117;
    v116 = qcar(v116);
    { popv(3); return onevalue(v116); }

v19:
    v116 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v116); }
/* error exit handlers */
v118:
    popv(3);
    return nil;
}



/* Code for operator_fn */

static Lisp_Object CC_operator_fn(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for operator_fn");
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
    v69 = stack[0];
    v101 = qcar(v69);
    v69 = elt(env, 1); /* ((arcsinh . sinh) (arcsech . sech) (arccosh . cosh) (arccsch csch) (arctanh . tanh) (arccoth . coth)) 
*/
    v69 = Latsoc(nil, v101, v69);
    stack[-1] = v69;
    v69 = stack[-1];
    if (v69 == nil) goto v65;
    v69 = elt(env, 2); /* "<apply><inverse/>" */
    fn = elt(env, 8); /* printout */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v69 = stack[-1];
    v69 = qcdr(v69);
    v69 = Lprinc(nil, v69);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    goto v52;

v52:
    v101 = qvalue(elt(env, 6)); /* indent */
    v69 = (Lisp_Object)49; /* 3 */
    v69 = plus2(v101, v69);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    qvalue(elt(env, 6)) = v69; /* indent */
    v69 = stack[0];
    v69 = qcdr(v69);
    fn = elt(env, 9); /* multi_args */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v101 = qvalue(elt(env, 6)); /* indent */
    v69 = (Lisp_Object)49; /* 3 */
    v69 = difference2(v101, v69);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    qvalue(elt(env, 6)) = v69; /* indent */
    v69 = elt(env, 7); /* "</apply>" */
    fn = elt(env, 8); /* printout */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v31;
    v69 = nil;
    { popv(3); return onevalue(v69); }

v65:
    v69 = elt(env, 4); /* "<apply><fn><ci>" */
    fn = elt(env, 8); /* printout */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v69 = stack[0];
    v69 = qcar(v69);
    v69 = Lprinc(nil, v69);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    v69 = elt(env, 5); /* "</ci></fn>" */
    v69 = Lprinc(nil, v69);
    nil = C_nil;
    if (exception_pending()) goto v31;
    env = stack[-2];
    goto v52;
/* error exit handlers */
v31:
    popv(3);
    return nil;
}



/* Code for newsym1 */

static Lisp_Object MS_CDECL CC_newsym1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v115, v41;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "newsym1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newsym1");
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
    v115 = qvalue(elt(env, 1)); /* cindex!* */
    v115 = Lexplode(nil, v115);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-1];
    stack[0] = v115;
    v115 = qvalue(elt(env, 1)); /* cindex!* */
    v115 = add1(v115);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-1];
    qvalue(elt(env, 1)) = v115; /* cindex!* */
    v41 = qvalue(elt(env, 2)); /* cname!* */
    v115 = stack[0];
    v115 = Lappend(nil, v41, v115);
    nil = C_nil;
    if (exception_pending()) goto v3;
        popv(2);
        return Lcompress(nil, v115);
/* error exit handlers */
v3:
    popv(2);
    return nil;
}



/* Code for !*kp2q */

static Lisp_Object CC_Hkp2q(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *kp2q");
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
    v59 = stack[0];
    v71 = (Lisp_Object)1; /* 0 */
    v71 = (Lisp_Object)greaterp2(v59, v71);
    nil = C_nil;
    if (exception_pending()) goto v120;
    v71 = v71 ? lisp_true : nil;
    env = stack[-2];
    if (v71 == nil) goto v58;
    v59 = stack[-1];
    v71 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* mksq */
        return (*qfn2(fn))(qenv(fn), v59, v71);
    }

v58:
    v71 = stack[0];
    v71 = (Lisp_Object)zerop(v71);
    v71 = v71 ? lisp_true : nil;
    env = stack[-2];
    if (v71 == nil) goto v24;
    v59 = (Lisp_Object)17; /* 1 */
    v71 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v59, v71);

v24:
    v71 = stack[0];
    v71 = negate(v71);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    fn = elt(env, 2); /* mksq */
    v71 = (*qfn2(fn))(qenv(fn), stack[-1], v71);
    nil = C_nil;
    if (exception_pending()) goto v120;
    env = stack[-2];
    stack[-1] = v71;
    v71 = qcar(v71);
    if (v71 == nil) goto v52;
    v71 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* revpr */
        return (*qfn1(fn))(qenv(fn), v71);
    }

v52:
    v71 = elt(env, 1); /* "Zero divisor" */
    {
        popv(3);
        fn = elt(env, 4); /* rederr */
        return (*qfn1(fn))(qenv(fn), v71);
    }
/* error exit handlers */
v120:
    popv(3);
    return nil;
}



/* Code for mk_binding */

static Lisp_Object CC_mk_binding(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_binding");
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
    v46 = stack[-1];
    v72 = qcar(v46);
    v46 = stack[0];
    fn = elt(env, 2); /* can_be_proved */
    v46 = (*qfn2(fn))(qenv(fn), v72, v46);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-2];
    if (v46 == nil) goto v19;
    v46 = stack[-1];
    v72 = qcdr(v46);
    v46 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* edge_bind */
        return (*qfn2(fn))(qenv(fn), v72, v46);
    }

v19:
    v46 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v46); }
/* error exit handlers */
v74:
    popv(3);
    return nil;
}



/* Code for gcdld */

static Lisp_Object CC_gcdld(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v59, v69, v101;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcdld");
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
    v59 = v1;
    v69 = v0;
/* end of prologue */

v60:
    v101 = v59;
    v71 = (Lisp_Object)17; /* 1 */
    if (v101 == v71) goto v75;
    v101 = v59;
    v71 = (Lisp_Object)-15; /* -1 */
    if (v101 == v71) goto v75;
    v71 = v69;
    if (v71 == nil) goto v46;
    v71 = v69;
    v71 = qcar(v71);
    if (v71 == nil) goto v44;
    v71 = v69;
    v71 = qcdr(v71);
    stack[0] = v71;
    v71 = v59;
    v59 = v69;
    v59 = qcar(v59);
    fn = elt(env, 1); /* gcd!-with!-number */
    v71 = (*qfn2(fn))(qenv(fn), v71, v59);
    nil = C_nil;
    if (exception_pending()) goto v50;
    env = stack[-1];
    v59 = v71;
    v71 = stack[0];
    v69 = v71;
    goto v60;

v44:
    v71 = v69;
    v71 = qcdr(v71);
    v69 = v71;
    goto v60;

v46:
    v71 = v59;
        popv(2);
        return Labsval(nil, v71);

v75:
    v71 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(v71); }
/* error exit handlers */
v50:
    popv(2);
    return nil;
}



/* Code for mo_zero!? */

static Lisp_Object CC_mo_zeroW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_zero?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v19 = v0;
/* end of prologue */
    v19 = qcar(v19);
    {
        fn = elt(env, 1); /* mo!=zero */
        return (*qfn1(fn))(qenv(fn), v19);
    }
}



/* Code for prim!-part */

static Lisp_Object CC_primKpart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prim-part");
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
    v60 = v0;
/* end of prologue */
    stack[0] = v60;
    fn = elt(env, 1); /* comfac */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    fn = elt(env, 2); /* comfac!-to!-poly */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-1];
    {
        Lisp_Object v63 = stack[0];
        popv(2);
        fn = elt(env, 3); /* quotf1 */
        return (*qfn2(fn))(qenv(fn), v63, v60);
    }
/* error exit handlers */
v62:
    popv(2);
    return nil;
}



/* Code for !*q2f */

static Lisp_Object CC_Hq2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v46, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *q2f");
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
    v72 = v0;
/* end of prologue */
    v33 = v72;
    v46 = qcdr(v33);
    v33 = (Lisp_Object)17; /* 1 */
    if (v46 == v33) goto v10;
    v33 = v72;
    fn = elt(env, 2); /* prepsq */
    v46 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[0];
    v33 = elt(env, 1); /* polynomial */
    {
        popv(1);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v46, v33);
    }

v10:
    v33 = v72;
    v33 = qcar(v33);
    { popv(1); return onevalue(v33); }
/* error exit handlers */
v42:
    popv(1);
    return nil;
}



/* Code for rl_smrmknowl */

static Lisp_Object CC_rl_smrmknowl(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v2;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smrmknowl");
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
    v41 = v1;
    v2 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smrmknowl!* */
    v41 = list2(v2, v41);
    nil = C_nil;
    if (exception_pending()) goto v4;
    env = stack[-1];
    {
        Lisp_Object v5 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v5, v41);
    }
/* error exit handlers */
v4:
    popv(2);
    return nil;
}



/* Code for ofsf_facequal */

static Lisp_Object CC_ofsf_facequal(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v125, v126;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_facequal");
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
    v124 = v0;
/* end of prologue */
    fn = elt(env, 7); /* fctrf */
    v124 = (*qfn1(fn))(qenv(fn), v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    v124 = qcdr(v124);
    stack[-3] = v124;
    v124 = stack[-3];
    if (v124 == nil) goto v43;
    v124 = stack[-3];
    v124 = qcar(v124);
    v126 = elt(env, 2); /* equal */
    v125 = qcar(v124);
    v124 = qvalue(elt(env, 1)); /* nil */
    v124 = list3(v126, v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    stack[-1] = v124;
    stack[-2] = v124;
    goto v128;

v128:
    v124 = stack[-3];
    v124 = qcdr(v124);
    stack[-3] = v124;
    v124 = stack[-3];
    if (v124 == nil) goto v113;
    stack[0] = stack[-1];
    v124 = stack[-3];
    v124 = qcar(v124);
    v126 = elt(env, 2); /* equal */
    v125 = qcar(v124);
    v124 = qvalue(elt(env, 1)); /* nil */
    v124 = list3(v126, v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    v124 = Lrplacd(nil, stack[0], v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-4];
    v124 = stack[-1];
    v124 = qcdr(v124);
    stack[-1] = v124;
    goto v128;

v113:
    v124 = stack[-2];
    goto v58;

v58:
    v125 = v124;
    v124 = v125;
    if (v124 == nil) goto v73;
    v124 = v125;
    v124 = qcdr(v124);
    if (v124 == nil) goto v73;
    v124 = elt(env, 3); /* or */
    popv(5);
    return cons(v124, v125);

v73:
    v124 = v125;
    if (v124 == nil) goto v8;
    v124 = v125;
    v124 = qcar(v124);
    { popv(5); return onevalue(v124); }

v8:
    v125 = elt(env, 3); /* or */
    v124 = elt(env, 4); /* and */
    if (v125 == v124) goto v98;
    v124 = elt(env, 6); /* false */
    { popv(5); return onevalue(v124); }

v98:
    v124 = elt(env, 5); /* true */
    { popv(5); return onevalue(v124); }

v43:
    v124 = qvalue(elt(env, 1)); /* nil */
    goto v58;
/* error exit handlers */
v127:
    popv(5);
    return nil;
}



/* Code for xadd!* */

static Lisp_Object MS_CDECL CC_xaddH(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v148, v149, v150;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xadd*");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xadd*");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-9] = v28;
    stack[-10] = v1;
    stack[-11] = v0;
/* end of prologue */
    v148 = stack[-10];
    stack[-12] = v148;
    goto v61;

v61:
    v148 = stack[-12];
    if (v148 == nil) goto v70;
    v148 = stack[-11];
    v149 = qcar(v148);
    v148 = stack[-12];
    v148 = qcar(v148);
    v148 = qcar(v148);
    if (!(equal(v149, v148))) goto v43;
    v148 = stack[-11];
    v148 = qcdr(v148);
    v149 = qcar(v148);
    v148 = stack[-12];
    v148 = qcar(v148);
    v148 = qcdr(v148);
    v148 = qcar(v148);
    if (!(equal(v149, v148))) goto v43;

v70:
    v148 = stack[-12];
    if (v148 == nil) goto v53;
    v148 = stack[-12];
    v149 = qcar(v148);
    v148 = stack[-10];
    v148 = Ldelete(nil, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    stack[-10] = v148;
    v148 = stack[-12];
    v148 = qcar(v148);
    stack[-12] = v148;
    v148 = stack[-9];
    if (v148 == nil) goto v53;
    v148 = qvalue(elt(env, 2)); /* newrule!* */
    if (v148 == nil) goto v53;
    v148 = stack[-12];
    v149 = qcar(v148);
    v148 = qvalue(elt(env, 2)); /* newrule!* */
    v148 = qcar(v148);
    stack[0] = v148;
    if (equal(v149, v148)) goto v152;
    v148 = stack[-12];
    v148 = qcar(v148);
    fn = elt(env, 7); /* powlisp */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    if (v148 == nil) goto v152;
    stack[-8] = elt(env, 3); /* plus */
    stack[-7] = stack[0];
    stack[-6] = elt(env, 4); /* difference */
    v148 = stack[-12];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    stack[-5] = qcar(v148);
    stack[-4] = elt(env, 5); /* times */
    v148 = stack[-12];
    v148 = qcar(v148);
    stack[-3] = v148;
    v148 = stack[-3];
    if (v148 == nil) goto v153;
    v148 = stack[-3];
    v148 = qcar(v148);
    v150 = elt(env, 6); /* expt */
    v149 = v148;
    v149 = qcar(v149);
    v148 = qcdr(v148);
    v148 = list3(v150, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    stack[-1] = v148;
    stack[-2] = v148;
    goto v154;

v154:
    v148 = stack[-3];
    v148 = qcdr(v148);
    stack[-3] = v148;
    v148 = stack[-3];
    if (v148 == nil) goto v155;
    stack[0] = stack[-1];
    v148 = stack[-3];
    v148 = qcar(v148);
    v150 = elt(env, 6); /* expt */
    v149 = v148;
    v149 = qcar(v149);
    v148 = qcdr(v148);
    v148 = list3(v150, v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    v148 = ncons(v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    v148 = Lrplacd(nil, stack[0], v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    v148 = stack[-1];
    v148 = qcdr(v148);
    stack[-1] = v148;
    goto v154;

v155:
    v148 = stack[-2];
    goto v156;

v156:
    v148 = cons(stack[-4], v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    v148 = list3(stack[-6], stack[-5], v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    v148 = list3(stack[-8], stack[-7], v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    fn = elt(env, 8); /* simp */
    v148 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    fn = elt(env, 9); /* prepsq */
    v149 = (*qfn1(fn))(qenv(fn), v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    v148 = stack[-12];
    v148 = qcdr(v148);
    v148 = qcar(v148);
    v148 = qcdr(v148);
    fn = elt(env, 10); /* updoldrules */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    goto v53;

v53:
    v148 = stack[-9];
    if (v148 == nil) { Lisp_Object res = stack[-10]; popv(14); return onevalue(res); }
    v149 = stack[-11];
    v148 = stack[-10];
    v148 = cons(v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    stack[-10] = v148;
    { Lisp_Object res = stack[-10]; popv(14); return onevalue(res); }

v153:
    v148 = qvalue(elt(env, 1)); /* nil */
    goto v156;

v152:
    v148 = stack[-12];
    v148 = qcdr(v148);
    v148 = qcdr(v148);
    v149 = qcar(v148);
    v148 = stack[-12];
    v148 = qcdr(v148);
    v148 = qcar(v148);
    v148 = qcdr(v148);
    fn = elt(env, 10); /* updoldrules */
    v148 = (*qfn2(fn))(qenv(fn), v149, v148);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-13];
    goto v53;

v43:
    v148 = stack[-12];
    v148 = qcdr(v148);
    stack[-12] = v148;
    goto v61;
/* error exit handlers */
v151:
    popv(14);
    return nil;
}



/* Code for csymbolrd */

static Lisp_Object MS_CDECL CC_csymbolrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5, v6, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "csymbolrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for csymbolrd");
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
    fn = elt(env, 2); /* fnrd */
    v5 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    stack[0] = v5;
    fn = elt(env, 3); /* stats_getargs */
    v5 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v32;
    env = stack[-1];
    v6 = v5;
    v5 = stack[0];
    v7 = qvalue(elt(env, 1)); /* nil */
    popv(2);
    return list2star(v5, v7, v6);
/* error exit handlers */
v32:
    popv(2);
    return nil;
}



/* Code for den */

static Lisp_Object CC_den(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for den");
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
    v43 = v0;
/* end of prologue */
    fn = elt(env, 1); /* simp!* */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[0];
    v62 = qcdr(v43);
    v43 = (Lisp_Object)17; /* 1 */
    v43 = cons(v62, v43);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v43);
    }
/* error exit handlers */
v63:
    popv(1);
    return nil;
}



/* Code for newvar */

static Lisp_Object CC_newvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newvar");
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
    v72 = stack[0];
    if (symbolp(v72)) goto v3;
    v42 = stack[0];
    v72 = elt(env, 1); /* "free variable" */
    {
        popv(3);
        fn = elt(env, 3); /* typerr */
        return (*qfn2(fn))(qenv(fn), v42, v72);
    }

v3:
    v72 = elt(env, 2); /* != */
    stack[-1] = Lexplode(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    v72 = stack[0];
    v72 = Lexplode(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    v72 = Lappend(nil, stack[-1], v72);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-2];
    v72 = Lcompress(nil, v72);
    nil = C_nil;
    if (exception_pending()) goto v44;
        popv(3);
        return Lintern(nil, v72);
/* error exit handlers */
v44:
    popv(3);
    return nil;
}



/* Code for gbftimes */

static Lisp_Object CC_gbftimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v117, v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbftimes");
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
    v117 = v1;
    v157 = v0;
/* end of prologue */
    v39 = v157;
    v39 = qcar(v39);
    stack[-4] = v39;
    v39 = v157;
    v39 = qcdr(v39);
    stack[-3] = v39;
    v39 = v117;
    v39 = qcar(v39);
    stack[-2] = v39;
    v39 = v117;
    v39 = qcdr(v39);
    stack[-1] = v39;
    v117 = stack[-4];
    v39 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    stack[0] = (*qfn2(fn))(qenv(fn), v117, v39);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    v117 = stack[-3];
    v39 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    v39 = (*qfn2(fn))(qenv(fn), v117, v39);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    fn = elt(env, 2); /* difbf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v39);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    v117 = stack[-4];
    v39 = stack[-1];
    fn = elt(env, 1); /* csl_timbf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v117, v39);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    v117 = stack[-3];
    v39 = stack[-2];
    fn = elt(env, 1); /* csl_timbf */
    v39 = (*qfn2(fn))(qenv(fn), v117, v39);
    nil = C_nil;
    if (exception_pending()) goto v158;
    env = stack[-5];
    fn = elt(env, 3); /* plubf */
    v39 = (*qfn2(fn))(qenv(fn), stack[-1], v39);
    nil = C_nil;
    if (exception_pending()) goto v158;
    {
        Lisp_Object v159 = stack[0];
        popv(6);
        return cons(v159, v39);
    }
/* error exit handlers */
v158:
    popv(6);
    return nil;
}



/* Code for delete_edge */

static Lisp_Object CC_delete_edge(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v57, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delete_edge");
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
    v27 = nil;
    goto v58;

v58:
    v54 = stack[0];
    if (v54 == nil) goto v75;
    v54 = stack[-1];
    v57 = qcar(v54);
    v54 = stack[0];
    v54 = qcar(v54);
    v54 = qcar(v54);
    if (v57 == v54) goto v33;
    v54 = stack[0];
    v54 = qcar(v54);
    v57 = v27;
    v54 = cons(v54, v57);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    v27 = v54;
    v54 = stack[0];
    v54 = qcdr(v54);
    stack[0] = v54;
    goto v58;

v33:
    v57 = v27;
    v54 = stack[0];
    v54 = qcdr(v54);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v57, v54);
    }

v75:
    v54 = v27;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v54);
    }
/* error exit handlers */
v71:
    popv(3);
    return nil;
}



/* Code for mo_from_ei */

static Lisp_Object CC_mo_from_ei(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v72, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_from_ei");
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
    v42 = v0;
/* end of prologue */
    v72 = v42;
    v46 = (Lisp_Object)1; /* 0 */
    if (v72 == v46) goto v10;
    v46 = v42;
    v46 = ncons(v46);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-1];
    stack[0] = v46;
    fn = elt(env, 1); /* mo!=deglist */
    v46 = (*qfn1(fn))(qenv(fn), v46);
    nil = C_nil;
    if (exception_pending()) goto v74;
    {
        Lisp_Object v44 = stack[0];
        popv(2);
        return cons(v44, v46);
    }

v10:
    {
        popv(2);
        fn = elt(env, 2); /* mo_zero */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v74:
    popv(2);
    return nil;
}



/* Code for flattens1 */

static Lisp_Object CC_flattens1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flattens1");
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

v10:
    v74 = stack[0];
    if (!consp(v74)) goto v128;
    v74 = stack[0];
    v74 = qcdr(v74);
    if (v74 == nil) goto v46;
    v74 = stack[0];
    v74 = qcar(v74);
    stack[-1] = CC_flattens1(env, v74);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-2];
    v74 = stack[0];
    v74 = qcdr(v74);
    v74 = CC_flattens1(env, v74);
    nil = C_nil;
    if (exception_pending()) goto v52;
    {
        Lisp_Object v114 = stack[-1];
        popv(3);
        return Lappend(nil, v114, v74);
    }

v46:
    v74 = stack[0];
    v74 = qcar(v74);
    stack[0] = v74;
    goto v10;

v128:
    v74 = stack[0];
    popv(3);
    return ncons(v74);
/* error exit handlers */
v52:
    popv(3);
    return nil;
}



/* Code for pst_d1 */

static Lisp_Object MS_CDECL CC_pst_d1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v28, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "pst_d1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_d1");
#endif
    if (stack >= stacklimit)
    {
        push3(v28,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v28);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v28;
    stack[-11] = v1;
    v111 = v0;
/* end of prologue */
    stack[0] = stack[-10];
    v111 = sub1(v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v111/(16/CELL)));
    stack[-12] = v111;
    v111 = stack[-12];
    if (v111 == nil) goto v4;
    v111 = stack[-12];
    v111 = qcar(v111);
    stack[-6] = v111;
    stack[0] = stack[-10];
    v111 = stack[-11];
    v111 = sub1(v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v111/(16/CELL)));
    stack[-5] = v111;
    v111 = stack[-5];
    if (v111 == nil) goto v53;
    v111 = stack[-5];
    v111 = qcar(v111);
    stack[-1] = v111;
    v111 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v111 = (*qfn2(fn))(qenv(fn), stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = qcar(v111);
    fn = elt(env, 4); /* ordn */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    stack[-3] = v111;
    stack[-4] = v111;
    goto v52;

v52:
    v111 = stack[-5];
    v111 = qcdr(v111);
    stack[-5] = v111;
    v111 = stack[-5];
    if (v111 == nil) goto v118;
    stack[-2] = stack[-3];
    v111 = stack[-5];
    v111 = qcar(v111);
    stack[-1] = v111;
    v111 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v111 = (*qfn2(fn))(qenv(fn), stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = qcar(v111);
    fn = elt(env, 4); /* ordn */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = Lrplacd(nil, stack[-2], v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = stack[-3];
    v111 = qcdr(v111);
    stack[-3] = v111;
    goto v52;

v118:
    v111 = stack[-4];
    goto v45;

v45:
    fn = elt(env, 4); /* ordn */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    stack[-8] = v111;
    stack[-9] = v111;
    goto v75;

v75:
    v111 = stack[-12];
    v111 = qcdr(v111);
    stack[-12] = v111;
    v111 = stack[-12];
    if (v111 == nil) { Lisp_Object res = stack[-9]; popv(14); return onevalue(res); }
    stack[-7] = stack[-8];
    v111 = stack[-12];
    v111 = qcar(v111);
    stack[-6] = v111;
    stack[0] = stack[-10];
    v111 = stack[-11];
    v111 = sub1(v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v111/(16/CELL)));
    stack[-5] = v111;
    v111 = stack[-5];
    if (v111 == nil) goto v167;
    v111 = stack[-5];
    v111 = qcar(v111);
    stack[-1] = v111;
    v111 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v111 = (*qfn2(fn))(qenv(fn), stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = qcar(v111);
    fn = elt(env, 4); /* ordn */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    stack[-3] = v111;
    stack[-4] = v111;
    goto v136;

v136:
    v111 = stack[-5];
    v111 = qcdr(v111);
    stack[-5] = v111;
    v111 = stack[-5];
    if (v111 == nil) goto v155;
    stack[-2] = stack[-3];
    v111 = stack[-5];
    v111 = qcar(v111);
    stack[-1] = v111;
    v111 = stack[-6];
    fn = elt(env, 2); /* sc_kern */
    stack[0] = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = stack[-1];
    fn = elt(env, 2); /* sc_kern */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    fn = elt(env, 3); /* pa_coinc_split */
    v111 = (*qfn2(fn))(qenv(fn), stack[0], v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = qcar(v111);
    fn = elt(env, 4); /* ordn */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = Lrplacd(nil, stack[-2], v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = stack[-3];
    v111 = qcdr(v111);
    stack[-3] = v111;
    goto v136;

v155:
    v111 = stack[-4];
    goto v168;

v168:
    fn = elt(env, 4); /* ordn */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = ncons(v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = Lrplacd(nil, stack[-7], v111);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-13];
    v111 = stack[-8];
    v111 = qcdr(v111);
    stack[-8] = v111;
    goto v75;

v167:
    v111 = qvalue(elt(env, 1)); /* nil */
    goto v168;

v53:
    v111 = qvalue(elt(env, 1)); /* nil */
    goto v45;

v4:
    v111 = qvalue(elt(env, 1)); /* nil */
    { popv(14); return onevalue(v111); }
/* error exit handlers */
v103:
    popv(14);
    return nil;
}



/* Code for gcd!-in!-vector */

static Lisp_Object MS_CDECL CC_gcdKinKvector(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v28, Lisp_Object v15, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v193, v194, v195, v196, v197, v198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gcd-in-vector");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcd-in-vector");
#endif
    if (stack >= stacklimit)
    {
        push4(v15,v28,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v28,v15);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v15;
    stack[-1] = v28;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v194 = stack[-2];
    v193 = (Lisp_Object)1; /* 0 */
    if (v194 == v193) goto v72;
    v194 = stack[0];
    v193 = (Lisp_Object)1; /* 0 */
    if (v194 == v193) goto v72;
    v194 = stack[-2];
    v193 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v194)) < ((int32_t)(v193))) goto v24;
    v194 = stack[0];
    v193 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v194)) < ((int32_t)(v193)))) goto v30;

v24:
    v193 = elt(env, 1); /* "GCD WITH ZERO NOT ALLOWED" */
    fn = elt(env, 3); /* errorf */
    v193 = (*qfn1(fn))(qenv(fn), v193);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    goto v30;

v30:
    v196 = stack[-3];
    v195 = stack[-2];
    v194 = stack[-1];
    v193 = stack[0];
    fn = elt(env, 4); /* remainder!-in!-vector */
    v193 = (*qfnn(fn))(qenv(fn), 4, v196, v195, v194, v193);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    stack[-2] = v193;
    v194 = stack[-2];
    v193 = (Lisp_Object)1; /* 0 */
    if (v194 == v193) goto v166;
    v194 = stack[-2];
    v193 = (Lisp_Object)-15; /* -1 */
    if (v194 == v193) goto v124;
    v196 = stack[-1];
    v195 = stack[0];
    v194 = stack[-3];
    v193 = stack[-2];
    fn = elt(env, 4); /* remainder!-in!-vector */
    v193 = (*qfnn(fn))(qenv(fn), 4, v196, v195, v194, v193);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    stack[0] = v193;
    v194 = stack[0];
    v193 = (Lisp_Object)1; /* 0 */
    if (v194 == v193) goto v112;
    v194 = stack[0];
    v193 = (Lisp_Object)-15; /* -1 */
    if (!(v194 == v193)) goto v30;
    v194 = stack[-3];
    v193 = stack[-2];
    v193 = *(Lisp_Object *)((char *)v194 + (CELL-TAG_VECTOR) + ((int32_t)v193/(16/CELL)));
    v193 = Lmodular_reciprocal(nil, v193);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    v198 = v193;
    v194 = v198;
    v193 = (Lisp_Object)17; /* 1 */
    if (v194 == v193) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v193 = (Lisp_Object)1; /* 0 */
    v197 = v193;
    goto v200;

v200:
    v194 = stack[-2];
    v193 = v197;
    v193 = (Lisp_Object)(int32_t)((int32_t)v194 - (int32_t)v193 + TAG_FIXNUM);
    v193 = ((intptr_t)(v193) < 0 ? lisp_true : nil);
    if (!(v193 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v196 = stack[-3];
    v195 = v197;
    v194 = stack[-3];
    v193 = v197;
    v194 = *(Lisp_Object *)((char *)v194 + (CELL-TAG_VECTOR) + ((int32_t)v193/(16/CELL)));
    v193 = v198;
    v193 = Lmodular_times(nil, v194, v193);
    env = stack[-4];
    *(Lisp_Object *)((char *)v196 + (CELL-TAG_VECTOR) + ((int32_t)v195/(16/CELL))) = v193;
    v193 = v197;
    v193 = (Lisp_Object)((int32_t)(v193) + 0x10);
    v197 = v193;
    goto v200;

v112:
    v195 = stack[-3];
    v194 = (Lisp_Object)1; /* 0 */
    v193 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v195 + (CELL-TAG_VECTOR) + ((int32_t)v194/(16/CELL))) = v193;
    v193 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v193); }

v124:
    v194 = stack[-1];
    v193 = stack[0];
    v193 = *(Lisp_Object *)((char *)v194 + (CELL-TAG_VECTOR) + ((int32_t)v193/(16/CELL)));
    v193 = Lmodular_reciprocal(nil, v193);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    v198 = v193;
    v193 = (Lisp_Object)1; /* 0 */
    v197 = v193;
    goto v156;

v156:
    v194 = stack[0];
    v193 = v197;
    v193 = (Lisp_Object)(int32_t)((int32_t)v194 - (int32_t)v193 + TAG_FIXNUM);
    v193 = ((intptr_t)(v193) < 0 ? lisp_true : nil);
    if (!(v193 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v196 = stack[-3];
    v195 = v197;
    v194 = stack[-1];
    v193 = v197;
    v194 = *(Lisp_Object *)((char *)v194 + (CELL-TAG_VECTOR) + ((int32_t)v193/(16/CELL)));
    v193 = v198;
    v193 = Lmodular_times(nil, v194, v193);
    env = stack[-4];
    *(Lisp_Object *)((char *)v196 + (CELL-TAG_VECTOR) + ((int32_t)v195/(16/CELL))) = v193;
    v193 = v197;
    v193 = (Lisp_Object)((int32_t)(v193) + 0x10);
    v197 = v193;
    goto v156;

v166:
    v195 = stack[-3];
    v194 = (Lisp_Object)1; /* 0 */
    v193 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v195 + (CELL-TAG_VECTOR) + ((int32_t)v194/(16/CELL))) = v193;
    v193 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v193); }

v72:
    v195 = stack[-3];
    v194 = (Lisp_Object)1; /* 0 */
    v193 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v195 + (CELL-TAG_VECTOR) + ((int32_t)v194/(16/CELL))) = v193;
    v193 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v193); }
/* error exit handlers */
v199:
    popv(5);
    return nil;
}



/* Code for cl_smsimpl!-junct1 */

static Lisp_Object MS_CDECL CC_cl_smsimplKjunct1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v28, Lisp_Object v15,
                         Lisp_Object v10, Lisp_Object v19,
                         Lisp_Object v58, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v228, v229, v230, v231, v232, v233;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 7, "cl_smsimpl-junct1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_smsimpl-junct1");
#endif
    if (stack >= stacklimit)
    {
        push6(v58,v19,v10,v15,v28,v1);
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v28,v15,v10,v19);
        pop(v58);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v58;
    stack[-4] = v19;
    stack[-5] = v10;
    stack[-6] = v15;
    stack[-7] = v28;
    v228 = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    goto v41;

v41:
    v228 = stack[-7];
    if (v228 == nil) goto v234;
    v228 = stack[-7];
    v228 = qcar(v228);
    stack[-9] = v228;
    v228 = stack[-7];
    v228 = qcdr(v228);
    stack[-7] = v228;
    stack[-10] = stack[-9];
    stack[0] = stack[-5];
    v228 = stack[-4];
    v229 = sub1(v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    v228 = stack[-8];
    fn = elt(env, 15); /* cl_simpl1 */
    v228 = (*qfnn(fn))(qenv(fn), 4, stack[-10], stack[0], v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    stack[-10] = v228;
    v228 = stack[-10];
    if (!consp(v228)) goto v51;
    v228 = stack[-10];
    v228 = qcar(v228);
    goto v67;

v67:
    v230 = v228;
    v229 = v230;
    v228 = stack[-3];
    if (v229 == v228) goto v101;
    v229 = v230;
    v228 = stack[-8];
    if (v229 == v228) goto v39;
    v229 = v230;
    v228 = elt(env, 3); /* true */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 4); /* false */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 5); /* or */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 6); /* and */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 7); /* not */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 8); /* impl */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 9); /* repl */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 10); /* equiv */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 11); /* ex */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 12); /* all */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 13); /* bex */
    if (v229 == v228) goto v176;
    v229 = v230;
    v228 = elt(env, 14); /* ball */
    if (v229 == v228) goto v176;
    v228 = qvalue(elt(env, 2)); /* !*rlsiidem */
    if (v228 == nil) goto v236;
    v228 = stack[-2];
    v229 = Lnreverse(nil, v228);
    env = stack[-11];
    v228 = stack[-7];
    v228 = Lnconc(nil, v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    stack[-7] = v228;
    v228 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v228;
    goto v236;

v236:
    v228 = stack[-10];
    v228 = ncons(v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    stack[-1] = v228;
    goto v69;

v69:
    v228 = stack[-1];
    if (v228 == nil) goto v41;
    v231 = stack[-8];
    v230 = stack[-1];
    v229 = stack[-5];
    v228 = stack[-4];
    fn = elt(env, 16); /* rl_smupdknowl */
    v228 = (*qfnn(fn))(qenv(fn), 4, v231, v230, v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    stack[-5] = v228;
    v229 = stack[-5];
    v228 = elt(env, 4); /* false */
    if (!(v229 == v228)) goto v237;
    v228 = stack[-3];
    stack[-9] = v228;
    v228 = qvalue(elt(env, 1)); /* nil */
    stack[-7] = v228;
    goto v237;

v237:
    v228 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = v228;
    goto v41;

v176:
    stack[0] = v230;
    v228 = stack[-3];
    fn = elt(env, 17); /* cl_flip */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    if (equal(stack[0], v228)) goto v69;
    v229 = stack[-10];
    v228 = stack[-2];
    v228 = cons(v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    stack[-2] = v228;
    goto v69;

v39:
    v228 = stack[-10];
    v228 = qcdr(v228);
    stack[0] = v228;
    goto v21;

v21:
    v228 = stack[0];
    if (v228 == nil) goto v20;
    v228 = stack[0];
    v228 = qcar(v228);
    fn = elt(env, 18); /* cl_atfp */
    v228 = (*qfn1(fn))(qenv(fn), v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    if (v228 == nil) goto v20;
    v228 = stack[0];
    v229 = qcar(v228);
    v228 = stack[-1];
    v228 = cons(v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    stack[-1] = v228;
    v228 = stack[0];
    v228 = qcdr(v228);
    stack[0] = v228;
    goto v21;

v20:
    v228 = qvalue(elt(env, 2)); /* !*rlsiidem */
    if (v228 == nil) goto v168;
    v228 = stack[-1];
    if (v228 == nil) goto v168;
    v228 = stack[-2];
    v229 = Lnreverse(nil, v228);
    env = stack[-11];
    v228 = stack[-7];
    v228 = Lnconc(nil, v229, v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    stack[-7] = v228;
    v228 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v228;
    goto v168;

v168:
    v228 = stack[0];
    v228 = Lreverse(nil, v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    v228 = Lnconc(nil, stack[-2], v228);
    nil = C_nil;
    if (exception_pending()) goto v235;
    env = stack[-11];
    stack[-2] = v228;
    goto v69;

v101:
    v228 = stack[-3];
    stack[-9] = v228;
    v228 = qvalue(elt(env, 1)); /* nil */
    stack[-7] = v228;
    goto v69;

v51:
    v228 = stack[-10];
    goto v67;

v234:
    v229 = stack[-9];
    v228 = stack[-3];
    if (v229 == v228) goto v238;
    v233 = stack[-8];
    v232 = stack[-2];
    v231 = stack[-6];
    v230 = stack[-5];
    v229 = stack[-4];
    v228 = stack[-3];
    {
        popv(12);
        fn = elt(env, 19); /* cl_smsimpl!-junct2 */
        return (*qfnn(fn))(qenv(fn), 6, v233, v232, v231, v230, v229, v228);
    }

v238:
    v228 = stack[-3];
    popv(12);
    return ncons(v228);
/* error exit handlers */
v235:
    popv(12);
    return nil;
}



/* Code for mo!=modiv1 */

static Lisp_Object CC_moMmodiv1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v24;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=modiv1");
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

v19:
    v56 = stack[-1];
    if (v56 == nil) goto v40;
    v56 = stack[0];
    if (v56 == nil) goto v60;
    v56 = stack[-1];
    v24 = qcar(v56);
    v56 = stack[0];
    v56 = qcar(v56);
    v56 = (Lisp_Object)lesseq2(v24, v56);
    nil = C_nil;
    if (exception_pending()) goto v119;
    v56 = v56 ? lisp_true : nil;
    env = stack[-2];
    if (v56 == nil) goto v114;
    v56 = stack[-1];
    v56 = qcdr(v56);
    stack[-1] = v56;
    v56 = stack[0];
    v56 = qcdr(v56);
    stack[0] = v56;
    goto v19;

v114:
    v56 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v56); }

v60:
    v56 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v56); }

v40:
    v56 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v56); }
/* error exit handlers */
v119:
    popv(3);
    return nil;
}



/* Code for cnml */

static Lisp_Object MS_CDECL CC_cnml(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v83, v246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cnml");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cnml");
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
    v246 = qvalue(elt(env, 2)); /* atts */
    v83 = elt(env, 3); /* (t y p e) */
    fn = elt(env, 12); /* search_att */
    v83 = (*qfn2(fn))(qenv(fn), v246, v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    stack[-2] = v83;
    fn = elt(env, 13); /* lex */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v83 = qvalue(elt(env, 4)); /* char */
    stack[-1] = v83;
    fn = elt(env, 13); /* lex */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v246 = stack[-2];
    v83 = elt(env, 5); /* (c o n s t a n t) */
    if (!(equal(v246, v83))) goto v4;
    v83 = stack[-1];
    v83 = Lcompress(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v246 = Lintern(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v83 = qvalue(elt(env, 6)); /* rdci!* */
    v83 = Lassoc(nil, v246, v83);
    stack[0] = v83;
    if (v83 == nil) goto v4;
    v83 = stack[0];
    v83 = qcdr(v83);
    fn = elt(env, 14); /* first */
    stack[-1] = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v83 = stack[0];
    v83 = qcdr(v83);
    fn = elt(env, 15); /* rest */
    v83 = (*qfn1(fn))(qenv(fn), v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    {
        Lisp_Object v248 = stack[-1];
        popv(4);
        fn = elt(env, 16); /* apply */
        return (*qfn2(fn))(qenv(fn), v248, v83);
    }

v4:
    v83 = stack[-1];
    v83 = Lcompress(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    if (!(symbolp(v83))) goto v50;
    v83 = stack[-1];
    v246 = Lcompress(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v83 = (Lisp_Object)257; /* 16 */
    fn = elt(env, 17); /* errorml */
    v83 = (*qfn2(fn))(qenv(fn), v246, v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    goto v50;

v50:
    v83 = stack[-2];
    if (v83 == nil) goto v38;
    v246 = stack[-2];
    v83 = elt(env, 7); /* ((r e a l) (i n t e g e r)) */
    v83 = Lmember(nil, v246, v83);
    if (v83 == nil) goto v122;
    v83 = stack[-1];
        popv(4);
        return Lcompress(nil, v83);

v122:
    v246 = stack[-2];
    v83 = elt(env, 8); /* ((r a t i o n a l) (c o m p l e x !- c a r t e s i a n) (c o m p l e x !- p o l a r)) 
*/
    v83 = Lmember(nil, v246, v83);
    if (v83 == nil) goto v132;
    fn = elt(env, 18); /* seprd */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    stack[0] = v83;
    v246 = stack[-2];
    v83 = elt(env, 9); /* (r a t i o n a l) */
    if (equal(v246, v83)) goto v126;
    v246 = stack[-2];
    v83 = elt(env, 10); /* (c o m p l e x !- c a r t e s i a n) */
    if (equal(v246, v83)) goto v91;
    v246 = stack[-2];
    v83 = elt(env, 11); /* (c o m p l e x !- p o l a r) */
    if (!(equal(v246, v83))) goto v132;
    v83 = stack[-1];
    v246 = Lcompress(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v83 = stack[0];
    fn = elt(env, 19); /* po2ca */
    v83 = (*qfn2(fn))(qenv(fn), v246, v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    stack[0] = v83;
    fn = elt(env, 13); /* lex */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v83 = stack[0];
    v246 = qcar(v83);
    v83 = stack[0];
    v83 = qcdr(v83);
    v83 = qcar(v83);
    {
        popv(4);
        fn = elt(env, 20); /* comp2 */
        return (*qfn2(fn))(qenv(fn), v246, v83);
    }

v132:
    v83 = nil;
    { popv(4); return onevalue(v83); }

v91:
    fn = elt(env, 13); /* lex */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v83 = stack[-1];
    v246 = Lcompress(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v83 = stack[0];
    {
        popv(4);
        fn = elt(env, 20); /* comp2 */
        return (*qfn2(fn))(qenv(fn), v246, v83);
    }

v126:
    fn = elt(env, 13); /* lex */
    v83 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v83 = stack[-1];
    v246 = Lcompress(nil, v83);
    nil = C_nil;
    if (exception_pending()) goto v247;
    env = stack[-3];
    v83 = stack[0];
    {
        popv(4);
        fn = elt(env, 21); /* alg_quotient */
        return (*qfn2(fn))(qenv(fn), v246, v83);
    }

v38:
    v83 = stack[-1];
        popv(4);
        return Lcompress(nil, v83);
/* error exit handlers */
v247:
    popv(4);
    return nil;
}



/* Code for ps!:find!-order */

static Lisp_Object CC_psTfindKorder(Lisp_Object env,
                         Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v122, v94, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:find-order");
#endif
    if (stack >= stacklimit)
    {
        push(v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v122 = v1;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* ps */
    qvalue(elt(env, 1)) = nil; /* ps */
    qvalue(elt(env, 1)) = v122; /* ps */
    v122 = qvalue(elt(env, 1)); /* ps */
    if (v122 == nil) goto v75;
    v122 = qvalue(elt(env, 1)); /* ps */
    if (symbolp(v122)) goto v43;
    v122 = qvalue(elt(env, 1)); /* ps */
    v95 = v122;
    v122 = v95;
    v122 = (is_number(v122) ? lisp_true : nil);
    if (!(v122 == nil)) goto v5;
    v122 = v95;
    v122 = Lconsp(nil, v122);
    env = stack[-1];
    if (v122 == nil) goto v46;
    v122 = v95;
    v94 = qcar(v122);
    v122 = elt(env, 3); /* !:ps!: */
    if (v94 == v122) goto v44;
    v122 = v95;
    v94 = qcar(v122);
    v122 = elt(env, 4); /* dname */
    v122 = get(v94, v122);
    env = stack[-1];
    goto v5;

v5:
    if (v122 == nil) goto v31;
    v122 = (Lisp_Object)1; /* 0 */
    goto v19;

v19:
    qvalue(elt(env, 1)) = stack[0]; /* ps */
    { popv(2); return onevalue(v122); }

v31:
    v94 = qvalue(elt(env, 1)); /* ps */
    v122 = elt(env, 3); /* !:ps!: */
    if (!consp(v94)) goto v249;
    v94 = qcar(v94);
    if (!(v94 == v122)) goto v249;
    v122 = qvalue(elt(env, 1)); /* ps */
    v122 = qcdr(v122);
    if (symbolp(v122)) goto v117;
    v122 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 7); /* ps!:expression */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    if (!consp(v122)) goto v38;
    v122 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 8); /* ps!:find!-order1 */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    goto v19;

v38:
    v122 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 9); /* ps!:order */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    goto v19;

v117:
    v122 = qvalue(elt(env, 1)); /* ps */
    fn = elt(env, 10); /* ps!:unknown!-order */
    v122 = (*qfn1(fn))(qenv(fn), v122);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    goto v19;

v249:
    v95 = elt(env, 5); /* tps */
    v94 = (Lisp_Object)337; /* 21 */
    v122 = elt(env, 6); /* "Unexpected form in ps!:find!-order" */
    fn = elt(env, 11); /* rerror */
    v122 = (*qfnn(fn))(qenv(fn), 3, v95, v94, v122);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-1];
    goto v19;

v44:
    v122 = qvalue(elt(env, 2)); /* nil */
    goto v5;

v46:
    v122 = qvalue(elt(env, 2)); /* nil */
    goto v5;

v43:
    v122 = qvalue(elt(env, 1)); /* ps */
    goto v19;

v75:
    v122 = (Lisp_Object)1; /* 0 */
    goto v19;
/* error exit handlers */
v12:
    env = stack[-1];
    qvalue(elt(env, 1)) = stack[0]; /* ps */
    popv(2);
    return nil;
}



/* Code for ldf!-deg */

static Lisp_Object CC_ldfKdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-deg");
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
    v29 = v0;
/* end of prologue */
    stack[-4] = v29;
    v29 = stack[-4];
    if (v29 == nil) goto v43;
    v29 = stack[-4];
    v29 = qcar(v29);
    v30 = qcdr(v29);
    v29 = stack[-3];
    fn = elt(env, 2); /* degreef */
    v29 = (*qfn2(fn))(qenv(fn), v30, v29);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-5];
    v29 = ncons(v29);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-5];
    stack[-1] = v29;
    stack[-2] = v29;
    goto v75;

v75:
    v29 = stack[-4];
    v29 = qcdr(v29);
    stack[-4] = v29;
    v29 = stack[-4];
    if (v29 == nil) goto v45;
    stack[0] = stack[-1];
    v29 = stack[-4];
    v29 = qcar(v29);
    v30 = qcdr(v29);
    v29 = stack[-3];
    fn = elt(env, 2); /* degreef */
    v29 = (*qfn2(fn))(qenv(fn), v30, v29);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-5];
    v29 = ncons(v29);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-5];
    v29 = Lrplacd(nil, stack[0], v29);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-5];
    v29 = stack[-1];
    v29 = qcdr(v29);
    stack[-1] = v29;
    goto v75;

v45:
    v29 = stack[-2];
    goto v40;

v40:
    {
        popv(6);
        fn = elt(env, 3); /* maxl */
        return (*qfn1(fn))(qenv(fn), v29);
    }

v43:
    v29 = qvalue(elt(env, 1)); /* nil */
    goto v40;
/* error exit handlers */
v39:
    popv(6);
    return nil;
}



/* Code for simpwedge */

static Lisp_Object CC_simpwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpwedge");
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
    v19 = v0;
/* end of prologue */
    fn = elt(env, 1); /* partitwedge */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*pf2sq */
        return (*qfn1(fn))(qenv(fn), v19);
    }
/* error exit handlers */
v58:
    popv(1);
    return nil;
}



/* Code for mk!-contract!-coeff */

static Lisp_Object CC_mkKcontractKcoeff(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-contract-coeff");
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
    v30 = stack[0];
    v30 = qcar(v30);
    v26 = qcar(v30);
    v30 = (Lisp_Object)1; /* 0 */
    if (v26 == v30) goto v10;
    v30 = stack[0];
    v30 = qcar(v30);
    v30 = qcar(v30);
    stack[-3] = v30;
    v30 = stack[0];
    v30 = qcdr(v30);
    v30 = qcar(v30);
    v30 = Llength(nil, v30);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v26 = v30;
    v30 = stack[0];
    v30 = qcar(v30);
    v30 = qcdr(v30);
    stack[-2] = qcar(v30);
    stack[-1] = qvalue(elt(env, 1)); /* ndim!* */
    stack[0] = v26;
    v30 = stack[-3];
    v30 = plus2(v26, v30);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    fn = elt(env, 2); /* mk!-numr */
    v30 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    v30 = cons(stack[-2], v30);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-4];
    {
        popv(5);
        fn = elt(env, 3); /* constimes */
        return (*qfn1(fn))(qenv(fn), v30);
    }

v10:
    v30 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v30); }
/* error exit handlers */
v39:
    popv(5);
    return nil;
}



/* Code for fs!:zerop!: */

static Lisp_Object CC_fsTzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v101, v120;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:zerop:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v120 = v0;
/* end of prologue */
    v69 = v120;
    v69 = (v69 == nil ? lisp_true : nil);
    if (!(v69 == nil)) return onevalue(v69);
    v69 = v120;
    if (is_number(v69)) goto v70;
    v69 = v120;
    v69 = qcdr(v69);
    v69 = (v69 == nil ? lisp_true : nil);
    goto v75;

v75:
    if (!(v69 == nil)) return onevalue(v69);
    v69 = v120;
    v101 = qcdr(v69);
    v69 = (Lisp_Object)49; /* 3 */
    v69 = *(Lisp_Object *)((char *)v101 + (CELL-TAG_VECTOR) + ((int32_t)v69/(16/CELL)));
    if (v69 == nil) goto v52;
    v69 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v69);

v52:
    v69 = v120;
    v101 = qcdr(v69);
    v69 = (Lisp_Object)1; /* 0 */
    v69 = *(Lisp_Object *)((char *)v101 + (CELL-TAG_VECTOR) + ((int32_t)v69/(16/CELL)));
    v101 = v69;
    v69 = v101;
    if (is_number(v69)) goto v25;
    v69 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v69);

v25:
    v69 = v101;
        return Lzerop(nil, v69);

v70:
    v69 = qvalue(elt(env, 1)); /* nil */
    goto v75;
}



/* Code for monic */

static Lisp_Object CC_monic(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for monic");
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
    stack[-4] = nil;
    v124 = stack[-3];
    v124 = Lreverse(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    stack[-3] = v124;
    v124 = qvalue(elt(env, 1)); /* varlist */
    v124 = Llength(nil, v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    stack[-1] = v124;
    v124 = (Lisp_Object)17; /* 1 */
    stack[0] = v124;
    goto v5;

v5:
    v125 = stack[-1];
    v124 = stack[0];
    v124 = difference2(v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v124 = Lminusp(nil, v124);
    env = stack[-5];
    if (v124 == nil) goto v45;
    v124 = qvalue(elt(env, 1)); /* varlist */
    v124 = qcdr(v124);
    stack[-3] = v124;
    v124 = stack[-3];
    if (v124 == nil) goto v38;
    v124 = (Lisp_Object)1; /* 0 */
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    stack[-1] = v124;
    stack[-2] = v124;
    goto v157;

v157:
    v124 = stack[-3];
    v124 = qcdr(v124);
    stack[-3] = v124;
    v124 = stack[-3];
    if (v124 == nil) goto v249;
    stack[0] = stack[-1];
    v124 = (Lisp_Object)1; /* 0 */
    v124 = ncons(v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v124 = Lrplacd(nil, stack[0], v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v124 = stack[-1];
    v124 = qcdr(v124);
    stack[-1] = v124;
    goto v157;

v249:
    v124 = stack[-2];
    goto v30;

v30:
    v124 = (equal(stack[-4], v124) ? lisp_true : nil);
    { popv(6); return onevalue(v124); }

v38:
    v124 = qvalue(elt(env, 2)); /* nil */
    goto v30;

v45:
    v125 = stack[0];
    v124 = stack[-2];
    if (equal(v125, v124)) goto v123;
    v125 = stack[-3];
    v124 = stack[0];
    fn = elt(env, 3); /* nth */
    v125 = (*qfn2(fn))(qenv(fn), v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    v124 = stack[-4];
    v124 = cons(v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    stack[-4] = v124;
    goto v123;

v123:
    v124 = stack[0];
    v124 = add1(v124);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[-5];
    stack[0] = v124;
    goto v5;
/* error exit handlers */
v127:
    popv(6);
    return nil;
}



/* Code for !*n2a */

static Lisp_Object CC_Hn2a(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v62;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *n2a");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v62 = v0;
/* end of prologue */
    v43 = v62;
    v43 = integerp(v43);
    if (!(v43 == nil)) return onevalue(v62);
    v43 = v62;
    {
        fn = elt(env, 1); /* !*q2a */
        return (*qfn1(fn))(qenv(fn), v43);
    }
}



/* Code for cl_atml1 */

static Lisp_Object CC_cl_atml1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_atml1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v70 = v0;
/* end of prologue */
    v61 = v70;
    v70 = elt(env, 1); /* cl_atmlc */
    {
        fn = elt(env, 2); /* cl_f2ml */
        return (*qfn2(fn))(qenv(fn), v61, v70);
    }
}



/* Code for delet */

static Lisp_Object CC_delet(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v39, v117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for delet");
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
    v117 = nil;
    goto v58;

v58:
    v116 = stack[-1];
    if (v116 == nil) goto v43;
    v116 = stack[0];
    if (v116 == nil) goto v3;
    v39 = stack[-1];
    v116 = stack[0];
    if (equal(v39, v116)) goto v3;
    v39 = stack[-1];
    v116 = stack[0];
    v116 = qcar(v116);
    if (equal(v39, v116)) goto v67;
    v116 = stack[0];
    v116 = qcar(v116);
    v39 = v117;
    v116 = cons(v116, v39);
    nil = C_nil;
    if (exception_pending()) goto v118;
    env = stack[-2];
    v117 = v116;
    v116 = stack[0];
    v116 = qcdr(v116);
    stack[0] = v116;
    goto v58;

v67:
    v39 = v117;
    v116 = stack[0];
    v116 = qcdr(v116);
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v39, v116);
    }

v3:
    v116 = v117;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v116);
    }

v43:
    v39 = v117;
    v116 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v39, v116);
    }
/* error exit handlers */
v118:
    popv(3);
    return nil;
}



/* Code for !*multsq */

static Lisp_Object CC_Hmultsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v255;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *multsq");
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
    v133 = stack[-3];
    v133 = qcar(v133);
    if (v133 == nil) goto v62;
    v133 = stack[-2];
    v133 = qcar(v133);
    if (v133 == nil) goto v62;
    v133 = stack[-3];
    v255 = qcdr(v133);
    v133 = (Lisp_Object)17; /* 1 */
    if (!(v255 == v133)) goto v116;
    v133 = stack[-2];
    v255 = qcdr(v133);
    v133 = (Lisp_Object)17; /* 1 */
    if (!(v255 == v133)) goto v116;
    v133 = stack[-3];
    v255 = qcar(v133);
    v133 = stack[-2];
    v133 = qcar(v133);
    fn = elt(env, 2); /* !*multf */
    v255 = (*qfn2(fn))(qenv(fn), v255, v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v133 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v255, v133);

v116:
    v133 = stack[-3];
    v255 = qcar(v133);
    v133 = stack[-2];
    v133 = qcdr(v133);
    fn = elt(env, 3); /* gcdf */
    v133 = (*qfn2(fn))(qenv(fn), v255, v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    stack[-4] = v133;
    v133 = stack[-2];
    v255 = qcar(v133);
    v133 = stack[-3];
    v133 = qcdr(v133);
    fn = elt(env, 3); /* gcdf */
    v133 = (*qfn2(fn))(qenv(fn), v255, v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    stack[-1] = v133;
    v133 = stack[-3];
    v255 = qcar(v133);
    v133 = stack[-4];
    fn = elt(env, 4); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v255, v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    v133 = stack[-2];
    v255 = qcar(v133);
    v133 = stack[-1];
    fn = elt(env, 4); /* quotf */
    v133 = (*qfn2(fn))(qenv(fn), v255, v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    fn = elt(env, 2); /* !*multf */
    v133 = (*qfn2(fn))(qenv(fn), stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    stack[0] = v133;
    v133 = stack[-3];
    v255 = qcdr(v133);
    v133 = stack[-1];
    fn = elt(env, 4); /* quotf */
    stack[-1] = (*qfn2(fn))(qenv(fn), v255, v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    v133 = stack[-2];
    v255 = qcdr(v133);
    v133 = stack[-4];
    fn = elt(env, 4); /* quotf */
    v133 = (*qfn2(fn))(qenv(fn), v255, v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    fn = elt(env, 2); /* !*multf */
    v133 = (*qfn2(fn))(qenv(fn), stack[-1], v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    stack[-4] = v133;
    v133 = stack[-4];
    fn = elt(env, 5); /* minusf */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    if (v133 == nil) goto v162;
    v133 = stack[0];
    fn = elt(env, 6); /* negf */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    stack[0] = v133;
    v133 = stack[-4];
    fn = elt(env, 6); /* negf */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    stack[-4] = v133;
    goto v162;

v162:
    v255 = stack[0];
    v133 = stack[-4];
    fn = elt(env, 3); /* gcdf */
    v133 = (*qfn2(fn))(qenv(fn), v255, v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    stack[-1] = v133;
    v255 = stack[-1];
    v133 = (Lisp_Object)17; /* 1 */
    if (v255 == v133) goto v239;
    v255 = stack[0];
    v133 = stack[-1];
    fn = elt(env, 4); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v255, v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-5];
    v255 = stack[-4];
    v133 = stack[-1];
    fn = elt(env, 4); /* quotf */
    v133 = (*qfn2(fn))(qenv(fn), v255, v133);
    nil = C_nil;
    if (exception_pending()) goto v256;
    {
        Lisp_Object v257 = stack[0];
        popv(6);
        return cons(v257, v133);
    }

v239:
    v255 = stack[0];
    v133 = stack[-4];
    popv(6);
    return cons(v255, v133);

v62:
    v255 = qvalue(elt(env, 1)); /* nil */
    v133 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v255, v133);
/* error exit handlers */
v256:
    popv(6);
    return nil;
}



/* Code for sum_prodir */

static Lisp_Object MS_CDECL CC_sum_prodir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249, v245, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "sum_prodir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sum_prodir");
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
    v245 = qvalue(elt(env, 1)); /* atts */
    v249 = elt(env, 2); /* name */
    fn = elt(env, 5); /* find */
    v249 = (*qfn2(fn))(qenv(fn), v245, v249);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    v249 = Lintern(nil, v249);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    stack[-2] = v249;
    fn = elt(env, 6); /* lex */
    v249 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    fn = elt(env, 7); /* omobj */
    v249 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    stack[0] = v249;
    v245 = elt(env, 3); /* lowupperlimit */
    v249 = stack[0];
    v249 = qcdr(v249);
    v249 = cons(v245, v249);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    stack[0] = v249;
    fn = elt(env, 6); /* lex */
    v249 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    fn = elt(env, 7); /* omobj */
    v249 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    stack[-4] = v249;
    v249 = stack[-4];
    fn = elt(env, 8); /* lambdavar */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    stack[-1] = v249;
    v249 = stack[-4];
    fn = elt(env, 9); /* lambdafun */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    stack[-4] = v249;
    v245 = stack[-2];
    v249 = qvalue(elt(env, 4)); /* nil */
    stack[-2] = list2(v245, v249);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    v98 = stack[0];
    v245 = stack[-4];
    v249 = qvalue(elt(env, 4)); /* nil */
    v249 = list2star(v98, v245, v249);
    nil = C_nil;
    if (exception_pending()) goto v165;
    env = stack[-5];
    v249 = Lappend(nil, stack[-1], v249);
    nil = C_nil;
    if (exception_pending()) goto v165;
    {
        Lisp_Object v121 = stack[-2];
        popv(6);
        return Lappend(nil, v121, v249);
    }
/* error exit handlers */
v165:
    popv(6);
    return nil;
}



/* Code for ldf!-spf!-var */

static Lisp_Object CC_ldfKspfKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v12, v244;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-spf-var");
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
    v12 = v0;
/* end of prologue */
    v244 = nil;
    stack[-3] = nil;
    stack[-1] = v12;
    goto v75;

v75:
    v12 = stack[-1];
    if (v12 == nil) goto v40;
    v12 = stack[-1];
    v12 = qcar(v12);
    stack[0] = v244;
    v12 = qcdr(v12);
    fn = elt(env, 4); /* kernels */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v12 = Lappend(nil, stack[0], v12);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v244 = v12;
    v12 = stack[-1];
    v12 = qcdr(v12);
    stack[-1] = v12;
    goto v75;

v40:
    v12 = v244;
    fn = elt(env, 5); /* makeset */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    fn = elt(env, 6); /* prlist */
    v12 = (*qfn1(fn))(qenv(fn), v12);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[-2] = v12;
    goto v52;

v52:
    v12 = stack[-2];
    if (v12 == nil) goto v45;
    v12 = stack[-2];
    v12 = qcar(v12);
    stack[-1] = v12;
    v244 = stack[-1];
    v12 = elt(env, 2); /* x */
    if (!consp(v244)) goto v47;
    v244 = qcar(v244);
    if (!(v244 == v12)) goto v47;

v57:
    v12 = stack[-2];
    v12 = qcdr(v12);
    stack[-2] = v12;
    goto v52;

v47:
    v244 = stack[-1];
    v12 = elt(env, 3); /* u */
    if (!consp(v244)) goto v20;
    v244 = qcar(v244);
    if (v244 == v12) goto v57;
    else goto v20;

v20:
    v244 = elt(env, 2); /* x */
    v12 = stack[-1];
    v12 = qcdr(v12);
    fn = elt(env, 7); /* sacar */
    stack[0] = (*qfn2(fn))(qenv(fn), v244, v12);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v244 = elt(env, 3); /* u */
    v12 = stack[-1];
    v12 = qcdr(v12);
    fn = elt(env, 7); /* sacar */
    v244 = (*qfn2(fn))(qenv(fn), v244, v12);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v12 = stack[-3];
    fn = elt(env, 8); /* appends */
    v12 = (*qfnn(fn))(qenv(fn), 3, stack[0], v244, v12);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[-3] = v12;
    goto v57;

v45:
    v12 = stack[-3];
    {
        popv(5);
        fn = elt(env, 5); /* makeset */
        return (*qfn1(fn))(qenv(fn), v12);
    }
/* error exit handlers */
v125:
    popv(5);
    return nil;
}



/* Code for subs2pf */

static Lisp_Object CC_subs2pf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v56, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2pf");
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

v260:
    v55 = stack[0];
    if (v55 == nil) goto v19;
    v55 = stack[0];
    v55 = qcar(v55);
    v55 = qcdr(v55);
    fn = elt(env, 1); /* resimp */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    fn = elt(env, 2); /* subs2 */
    v55 = (*qfn1(fn))(qenv(fn), v55);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    v56 = v55;
    v56 = qcar(v56);
    if (v56 == nil) goto v44;
    v56 = stack[0];
    v56 = qcar(v56);
    v24 = qcar(v56);
    v56 = v55;
    v55 = stack[0];
    v55 = qcdr(v55);
    popv(2);
    return acons(v24, v56, v55);

v44:
    v55 = stack[0];
    v55 = qcdr(v55);
    stack[0] = v55;
    goto v260;

v19:
    v55 = nil;
    { popv(2); return onevalue(v55); }
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for decimal2internal */

static Lisp_Object CC_decimal2internal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v26, v47;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for decimal2internal");
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
    v26 = stack[0];
    v30 = (Lisp_Object)1; /* 0 */
    v30 = (Lisp_Object)geq2(v26, v30);
    nil = C_nil;
    if (exception_pending()) goto v39;
    v30 = v30 ? lisp_true : nil;
    env = stack[-3];
    if (v30 == nil) goto v57;
    stack[-2] = elt(env, 1); /* !:rd!: */
    v26 = (Lisp_Object)161; /* 10 */
    v30 = stack[0];
    v30 = Lexpt(nil, v26, v30);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    v26 = times2(stack[-1], v30);
    nil = C_nil;
    if (exception_pending()) goto v39;
    v30 = (Lisp_Object)1; /* 0 */
    {
        Lisp_Object v117 = stack[-2];
        popv(4);
        return list2star(v117, v26, v30);
    }

v57:
    v47 = elt(env, 1); /* !:rd!: */
    v26 = stack[-1];
    v30 = (Lisp_Object)1; /* 0 */
    stack[-1] = list2star(v47, v26, v30);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    v30 = stack[0];
    v30 = negate(v30);
    nil = C_nil;
    if (exception_pending()) goto v39;
    env = stack[-3];
    {
        Lisp_Object v157 = stack[-1];
        popv(4);
        fn = elt(env, 2); /* divide!-by!-power!-of!-ten */
        return (*qfn2(fn))(qenv(fn), v157, v30);
    }
/* error exit handlers */
v39:
    popv(4);
    return nil;
}



/* Code for sfchk */

static Lisp_Object CC_sfchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfchk");
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
    v43 = stack[0];
    fn = elt(env, 1); /* sfp */
    v43 = (*qfn1(fn))(qenv(fn), v43);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-1];
    if (v43 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v43 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* prepf */
        return (*qfn1(fn))(qenv(fn), v43);
    }
/* error exit handlers */
v63:
    popv(2);
    return nil;
}



/* Code for dp!=comp */

static Lisp_Object CC_dpMcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=comp");
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
    goto v58;

v58:
    v22 = stack[0];
    if (v22 == nil) goto v75;
    v22 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v22 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    fn = elt(env, 2); /* mo_comp */
    v23 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v22 = stack[-1];
    v22 = Leqn(nil, v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    if (v22 == nil) goto v113;
    v22 = stack[0];
    v23 = qcar(v22);
    v22 = stack[-2];
    v22 = cons(v23, v22);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-2] = v22;
    v22 = stack[0];
    v22 = qcdr(v22);
    stack[0] = v22;
    goto v58;

v113:
    v22 = stack[0];
    v22 = qcdr(v22);
    stack[0] = v22;
    goto v58;

v75:
    v22 = stack[-2];
    {
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v22);
    }
/* error exit handlers */
v51:
    popv(4);
    return nil;
}



/* Code for sub01 */

static Lisp_Object CC_sub01(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v23, v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sub01");
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
    v119 = nil;
    goto v58;

v58:
    v22 = stack[0];
    if (v22 == nil) goto v113;
    v22 = stack[0];
    v23 = qcar(v22);
    v22 = stack[-1];
    if (equal(v23, v22)) goto v3;
    v22 = (Lisp_Object)1; /* 0 */
    goto v63;

v63:
    v23 = v119;
    v22 = cons(v22, v23);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-2];
    v119 = v22;
    v22 = stack[0];
    v22 = qcdr(v22);
    stack[0] = v22;
    goto v58;

v3:
    v22 = (Lisp_Object)17; /* 1 */
    goto v63;

v113:
    v22 = v119;
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v22);
    }
/* error exit handlers */
v51:
    popv(3);
    return nil;
}



/* Code for pa_part2list */

static Lisp_Object CC_pa_part2list(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pa_part2list");
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
    v241 = stack[-6];
    v241 = qcdr(v241);
    fn = elt(env, 2); /* upbve */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    stack[0] = v241;
    v241 = stack[0];
    v241 = sub1(v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    v241 = Lmkvect(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    stack[-7] = v241;
    v241 = stack[0];
    stack[-4] = v241;
    goto v41;

v41:
    v241 = stack[-4];
    v241 = sub1(v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    v241 = Lminusp(nil, v241);
    env = stack[-8];
    if (v241 == nil) goto v46;
    v241 = stack[-6];
    v241 = qcar(v241);
    stack[-4] = v241;
    goto v99;

v99:
    v241 = stack[-4];
    if (v241 == nil) goto v258;
    v241 = stack[-4];
    v241 = qcar(v241);
    stack[0] = stack[-7];
    v241 = sub1(v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    v241 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v241/(16/CELL)));
    fn = elt(env, 3); /* copy */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    stack[-3] = v241;
    v241 = stack[-3];
    fn = elt(env, 4); /* lastpair */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    stack[-2] = v241;
    v241 = stack[-4];
    v241 = qcdr(v241);
    stack[-4] = v241;
    v241 = stack[-2];
    if (!consp(v241)) goto v99;
    else goto v100;

v100:
    v241 = stack[-4];
    if (v241 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v241 = stack[-4];
    v241 = qcar(v241);
    stack[0] = stack[-7];
    v241 = sub1(v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    v241 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v241/(16/CELL)));
    fn = elt(env, 3); /* copy */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    v241 = Lrplacd(nil, stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    v241 = stack[-2];
    fn = elt(env, 4); /* lastpair */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    stack[-2] = v241;
    v241 = stack[-4];
    v241 = qcdr(v241);
    stack[-4] = v241;
    goto v100;

v258:
    v241 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v241); }

v46:
    v241 = stack[-6];
    stack[0] = qcdr(v241);
    v241 = stack[-4];
    v241 = sub1(v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    v241 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v241/(16/CELL)));
    stack[-5] = v241;
    stack[-3] = stack[-7];
    v241 = stack[-5];
    stack[-2] = sub1(v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-7];
    v241 = stack[-5];
    v241 = sub1(v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    v241 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v241/(16/CELL)));
    v241 = cons(stack[-1], v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v241;
    v241 = stack[-4];
    v241 = sub1(v241);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-8];
    stack[-4] = v241;
    goto v41;
/* error exit handlers */
v146:
    popv(9);
    return nil;
}



setup_type const u34_setup[] =
{
    {"vdp_setsugar",            too_few_2,      CC_vdp_setsugar,wrong_no_2},
    {"diff2",                   CC_diff2,       too_many_1,    wrong_no_1},
    {"resetparser",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_resetparser},
    {"lengthn",                 CC_lengthn,     too_many_1,    wrong_no_1},
    {"dipcontenti",             CC_dipcontenti, too_many_1,    wrong_no_1},
    {"exptbf",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_exptbf},
    {"mkassign",                too_few_2,      CC_mkassign,   wrong_no_2},
    {"listminimize",            too_few_2,      CC_listminimize,wrong_no_2},
    {"addnew",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_addnew},
    {"lesspcar",                too_few_2,      CC_lesspcar,   wrong_no_2},
    {"coeffs-to-form1",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_coeffsKtoKform1},
    {"vdelete",                 too_few_2,      CC_vdelete,    wrong_no_2},
    {"rule*",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_ruleH},
    {"quotf*",                  too_few_2,      CC_quotfH,     wrong_no_2},
    {"operator_fn",             CC_operator_fn, too_many_1,    wrong_no_1},
    {"newsym1",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_newsym1},
    {"*kp2q",                   too_few_2,      CC_Hkp2q,      wrong_no_2},
    {"mk_binding",              too_few_2,      CC_mk_binding, wrong_no_2},
    {"gcdld",                   too_few_2,      CC_gcdld,      wrong_no_2},
    {"mo_zero?",                CC_mo_zeroW,    too_many_1,    wrong_no_1},
    {"prim-part",               CC_primKpart,   too_many_1,    wrong_no_1},
    {"*q2f",                    CC_Hq2f,        too_many_1,    wrong_no_1},
    {"rl_smrmknowl",            too_few_2,      CC_rl_smrmknowl,wrong_no_2},
    {"ofsf_facequal",           CC_ofsf_facequal,too_many_1,   wrong_no_1},
    {"xadd*",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_xaddH},
    {"csymbolrd",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_csymbolrd},
    {"den",                     CC_den,         too_many_1,    wrong_no_1},
    {"newvar",                  CC_newvar,      too_many_1,    wrong_no_1},
    {"gbftimes",                too_few_2,      CC_gbftimes,   wrong_no_2},
    {"delete_edge",             too_few_2,      CC_delete_edge,wrong_no_2},
    {"mo_from_ei",              CC_mo_from_ei,  too_many_1,    wrong_no_1},
    {"flattens1",               CC_flattens1,   too_many_1,    wrong_no_1},
    {"pst_d1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_pst_d1},
    {"gcd-in-vector",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_gcdKinKvector},
    {"cl_smsimpl-junct1",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_smsimplKjunct1},
    {"mo=modiv1",               too_few_2,      CC_moMmodiv1,  wrong_no_2},
    {"cnml",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cnml},
    {"ps:find-order",           CC_psTfindKorder,too_many_1,   wrong_no_1},
    {"ldf-deg",                 too_few_2,      CC_ldfKdeg,    wrong_no_2},
    {"simpwedge",               CC_simpwedge,   too_many_1,    wrong_no_1},
    {"mk-contract-coeff",       CC_mkKcontractKcoeff,too_many_1,wrong_no_1},
    {"fs:zerop:",               CC_fsTzeropT,   too_many_1,    wrong_no_1},
    {"monic",                   too_few_2,      CC_monic,      wrong_no_2},
    {"*n2a",                    CC_Hn2a,        too_many_1,    wrong_no_1},
    {"cl_atml1",                CC_cl_atml1,    too_many_1,    wrong_no_1},
    {"delet",                   too_few_2,      CC_delet,      wrong_no_2},
    {"*multsq",                 too_few_2,      CC_Hmultsq,    wrong_no_2},
    {"sum_prodir",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_sum_prodir},
    {"ldf-spf-var",             CC_ldfKspfKvar, too_many_1,    wrong_no_1},
    {"subs2pf",                 CC_subs2pf,     too_many_1,    wrong_no_1},
    {"decimal2internal",        too_few_2,      CC_decimal2internal,wrong_no_2},
    {"sfchk",                   CC_sfchk,       too_many_1,    wrong_no_1},
    {"dp=comp",                 too_few_2,      CC_dpMcomp,    wrong_no_2},
    {"sub01",                   too_few_2,      CC_sub01,      wrong_no_2},
    {"pa_part2list",            CC_pa_part2list,too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u34", (two_args *)"14928 9220760 1720555", 0}
};

/* end of generated code */
