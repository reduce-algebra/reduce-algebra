
/* $destdir/generated-c\u40.c Machine generated C code */

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


/* Code for simprad */

static Lisp_Object CC_simprad(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v53, v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simprad");
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
    stack[-3] = v1;
    stack[0] = v0;
/* end of prologue */
    v53 = qvalue(elt(env, 1)); /* !*reduced */
    if (v53 == nil) goto v55;
    v53 = stack[0];
    v54 = qcar(v53);
    v53 = stack[-3];
    fn = elt(env, 7); /* radfa */
    stack[-1] = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v53 = stack[0];
    v54 = qcdr(v53);
    v53 = stack[-3];
    fn = elt(env, 7); /* radfa */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    fn = elt(env, 8); /* invsq */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    {
        Lisp_Object v57 = stack[-1];
        popv(7);
        fn = elt(env, 9); /* multsq */
        return (*qfn2(fn))(qenv(fn), v57, v53);
    }

v55:
    stack[-4] = nil;
    v53 = qvalue(elt(env, 2)); /* !*rationalize */
    if (v53 == nil) goto v58;
    v53 = stack[0];
    v54 = qcdr(v53);
    v53 = (Lisp_Object)17; /* 1 */
    v53 = list2(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-1] = v53;
    v53 = stack[0];
    stack[-2] = qcar(v53);
    v53 = stack[0];
    stack[0] = qcdr(v53);
    v53 = stack[-3];
    v53 = sub1(v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    fn = elt(env, 10); /* exptf */
    v53 = (*qfn2(fn))(qenv(fn), stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    fn = elt(env, 11); /* multf */
    v54 = (*qfn2(fn))(qenv(fn), stack[-2], v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v53 = (Lisp_Object)17; /* 1 */
    v53 = cons(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[0] = v53;
    goto v59;

v59:
    v54 = stack[-3];
    v53 = (Lisp_Object)33; /* 2 */
    if (!(v54 == v53)) goto v60;
    v53 = stack[0];
    v53 = qcar(v53);
    fn = elt(env, 12); /* minusf */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    if (v53 == nil) goto v60;
    v53 = qvalue(elt(env, 3)); /* t */
    stack[-4] = v53;
    v53 = stack[0];
    v53 = qcar(v53);
    fn = elt(env, 13); /* negf */
    v54 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v53 = stack[-3];
    fn = elt(env, 14); /* radf */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-2] = v53;
    goto v61;

v61:
    stack[-5] = elt(env, 4); /* quotient */
    v53 = stack[-2];
    v53 = qcdr(v53);
    fn = elt(env, 15); /* retimes */
    stack[0] = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v53 = stack[-1];
    v53 = qcdr(v53);
    fn = elt(env, 15); /* retimes */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v53 = list3(stack[-5], stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    fn = elt(env, 16); /* simp */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-5] = v53;
    v53 = stack[-5];
    v53 = qcar(v53);
    if (!consp(v53)) goto v62;
    v53 = stack[-5];
    v53 = qcar(v53);
    v53 = qcar(v53);
    if (!(!consp(v53))) goto v63;

v62:
    v53 = stack[-5];
    v53 = qcdr(v53);
    if (!consp(v53)) goto v64;
    v53 = stack[-5];
    v53 = qcdr(v53);
    v53 = qcar(v53);
    if (!(!consp(v53))) goto v63;

v64:
    v53 = stack[-5];
    v53 = qcar(v53);
    fn = elt(env, 17); /* prepf */
    v54 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v53 = stack[-3];
    fn = elt(env, 18); /* mkrootsq */
    stack[0] = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v53 = stack[-5];
    v53 = qcdr(v53);
    fn = elt(env, 17); /* prepf */
    v54 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v53 = stack[-3];
    fn = elt(env, 18); /* mkrootsq */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    fn = elt(env, 8); /* invsq */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    fn = elt(env, 9); /* multsq */
    v53 = (*qfn2(fn))(qenv(fn), stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-5] = v53;
    goto v65;

v65:
    v53 = qvalue(elt(env, 6)); /* !*precise */
    if (v53 == nil) goto v66;
    v53 = stack[-3];
    v53 = Levenp(nil, v53);
    env = stack[-6];
    if (v53 == nil) goto v66;
    v53 = stack[-2];
    v54 = qcar(v53);
    v53 = (Lisp_Object)17; /* 1 */
    v53 = cons(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[0] = v53;
    goto v67;

v67:
    v54 = (Lisp_Object)17; /* 1 */
    v53 = stack[-1];
    v53 = qcar(v53);
    v53 = cons(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    fn = elt(env, 9); /* multsq */
    v54 = (*qfn2(fn))(qenv(fn), stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v53 = stack[-5];
    fn = elt(env, 9); /* multsq */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-5] = v53;
    v53 = stack[-4];
    if (v53 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[0] = stack[-5];
    v54 = (Lisp_Object)-15; /* -1 */
    v53 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 18); /* mkrootsq */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    fn = elt(env, 9); /* multsq */
    v53 = (*qfn2(fn))(qenv(fn), stack[0], v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    stack[-5] = v53;
    { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }

v66:
    v53 = stack[-2];
    v54 = qcar(v53);
    v53 = (Lisp_Object)17; /* 1 */
    v53 = cons(v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[0] = v53;
    goto v67;

v63:
    v53 = stack[-4];
    if (v53 == nil) goto v68;
    v53 = qvalue(elt(env, 5)); /* nil */
    stack[-4] = v53;
    v53 = stack[-5];
    fn = elt(env, 19); /* negsq */
    v53 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-5] = v53;
    goto v68;

v68:
    v53 = stack[-5];
    fn = elt(env, 20); /* prepsq */
    v54 = (*qfn1(fn))(qenv(fn), v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v53 = stack[-3];
    fn = elt(env, 18); /* mkrootsq */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-5] = v53;
    goto v65;

v60:
    v53 = stack[0];
    v54 = qcar(v53);
    v53 = stack[-3];
    fn = elt(env, 14); /* radf */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-2] = v53;
    goto v61;

v58:
    v53 = stack[0];
    v54 = qcdr(v53);
    v53 = stack[-3];
    fn = elt(env, 14); /* radf */
    v53 = (*qfn2(fn))(qenv(fn), v54, v53);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-1] = v53;
    goto v59;
/* error exit handlers */
v56:
    popv(7);
    return nil;
}



/* Code for get!-new!-prime */

static Lisp_Object CC_getKnewKprime(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-new-prime");
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
    v79 = qvalue(elt(env, 1)); /* !*force!-prime */
    if (v79 == nil) goto v80;
    v79 = qvalue(elt(env, 1)); /* !*force!-prime */
    { popv(5); return onevalue(v79); }

v80:
    stack[-3] = nil;
    v79 = stack[-2];
    stack[-1] = v79;
    goto v81;

v81:
    v79 = stack[-1];
    if (v79 == nil) goto v47;
    v79 = stack[-1];
    v79 = qcar(v79);
    stack[0] = v79;
    v58 = stack[0];
    v79 = (Lisp_Object)513; /* 32 */
    v79 = (Lisp_Object)lessp2(v58, v79);
    nil = C_nil;
    if (exception_pending()) goto v82;
    v79 = v79 ? lisp_true : nil;
    env = stack[-4];
    if (v79 == nil) goto v83;
    v58 = stack[0];
    v79 = stack[-3];
    v79 = cons(v58, v79);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-4];
    stack[-3] = v79;
    goto v83;

v83:
    v79 = stack[-1];
    v79 = qcdr(v79);
    stack[-1] = v79;
    goto v81;

v47:
    v79 = stack[-3];
    fn = elt(env, 4); /* random!-teeny!-prime */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-4];
    stack[0] = v79;
    if (v79 == nil) goto v45;
    v58 = stack[0];
    v79 = stack[-3];
    v79 = cons(v58, v79);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-4];
    stack[-3] = v79;
    goto v84;

v84:
    v58 = stack[0];
    v79 = stack[-2];
    v79 = Lmember(nil, v58, v79);
    if (v79 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    else goto v47;

v45:
    fn = elt(env, 5); /* random!-small!-prime */
    v79 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v82;
    env = stack[-4];
    stack[0] = v79;
    v79 = elt(env, 3); /* all */
    stack[-3] = v79;
    goto v84;
/* error exit handlers */
v82:
    popv(5);
    return nil;
}



/* Code for bfprin0x */

static Lisp_Object CC_bfprin0x(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v14, v6;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfprin0x");
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
    v14 = v1;
    v17 = v0;
/* end of prologue */
    fn = elt(env, 1); /* bfexplode0x */
    v17 = (*qfn2(fn))(qenv(fn), v17, v14);
    nil = C_nil;
    if (exception_pending()) goto v76;
    env = stack[0];
    v14 = v17;
    v14 = qcdr(v14);
    v14 = qcar(v14);
    v6 = v17;
    v6 = qcdr(v6);
    v6 = qcdr(v6);
    v6 = qcar(v6);
    v17 = qcar(v17);
    {
        popv(1);
        fn = elt(env, 2); /* bfprin!:lst */
        return (*qfnn(fn))(qenv(fn), 3, v17, v14, v6);
    }
/* error exit handlers */
v76:
    popv(1);
    return nil;
}



/* Code for lto_insert */

static Lisp_Object CC_lto_insert(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93, v75, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lto_insert");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v93 = v1;
    v75 = v0;
/* end of prologue */
    v94 = v75;
    v92 = v93;
    v92 = Lmember(nil, v94, v92);
    if (!(v92 == nil)) return onevalue(v93);
    v92 = v75;
    return cons(v92, v93);
}



/* Code for let3 */

static Lisp_Object MS_CDECL CC_let3(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v95, Lisp_Object v87,
                         Lisp_Object v86, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v127, v128, v129, v130, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "let3");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for let3");
#endif
    if (stack >= stacklimit)
    {
        push5(v86,v87,v95,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v95,v87,v86);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v86;
    stack[-2] = v87;
    stack[-3] = v95;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v126 = stack[-5];
    stack[-6] = v126;
    v126 = stack[-6];
    if (v126 == nil) goto v78;
    v126 = stack[-6];
    if (is_number(v126)) goto v51;
    v126 = stack[-4];
    fn = elt(env, 6); /* getrtype */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-7];
    stack[0] = v126;
    v126 = stack[-2];
    if (v126 == nil) goto v94;
    v126 = stack[-6];
    if (!(symbolp(v126))) goto v94;
    v127 = stack[-6];
    v126 = elt(env, 1); /* rtype */
    v126 = Lremprop(nil, v127, v126);
    env = stack[-7];
    v127 = stack[-6];
    v126 = elt(env, 2); /* avalue */
    v126 = Lremprop(nil, v127, v126);
    env = stack[-7];
    goto v94;

v94:
    v126 = stack[-6];
    fn = elt(env, 6); /* getrtype */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-7];
    v128 = v126;
    if (v126 == nil) goto v132;
    v127 = v128;
    v126 = elt(env, 3); /* typeletfn */
    v126 = get(v127, v126);
    env = stack[-7];
    v127 = v126;
    if (v126 == nil) goto v35;
    stack[-3] = v127;
    stack[-5] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v128;
    v126 = stack[-4];
    fn = elt(env, 6); /* getrtype */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-7];
    v126 = list2(stack[-2], v126);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-7];
    v126 = list3star(stack[-5], stack[-1], stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-7];
    {
        Lisp_Object v133 = stack[-3];
        popv(8);
        fn = elt(env, 7); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v133, v126);
    }

v35:
    stack[-3] = stack[-6];
    stack[-1] = stack[-4];
    stack[0] = v128;
    v126 = stack[-4];
    fn = elt(env, 6); /* getrtype */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-7];
    {
        Lisp_Object v134 = stack[-3];
        Lisp_Object v135 = stack[-1];
        Lisp_Object v136 = stack[0];
        Lisp_Object v137 = stack[-2];
        popv(8);
        fn = elt(env, 8); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v134, v135, v136, v137, v126);
    }

v132:
    v126 = stack[0];
    if (v126 == nil) goto v138;
    v127 = stack[0];
    v126 = elt(env, 4); /* yetunknowntype */
    if (v127 == v126) goto v138;
    v127 = stack[0];
    v126 = elt(env, 3); /* typeletfn */
    v126 = get(v127, v126);
    env = stack[-7];
    v127 = v126;
    if (v126 == nil) goto v139;
    stack[-3] = v127;
    stack[-5] = stack[-6];
    stack[-1] = qvalue(elt(env, 5)); /* nil */
    v127 = stack[-2];
    v126 = stack[0];
    v126 = list2(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-7];
    v126 = list3star(stack[-5], stack[-4], stack[-1], v126);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-7];
    {
        Lisp_Object v140 = stack[-3];
        popv(8);
        fn = elt(env, 7); /* lispapply */
        return (*qfn2(fn))(qenv(fn), v140, v126);
    }

v139:
    v130 = stack[-6];
    v129 = stack[-4];
    v128 = qvalue(elt(env, 5)); /* nil */
    v127 = stack[-2];
    v126 = stack[0];
    {
        popv(8);
        fn = elt(env, 8); /* typelet */
        return (*qfnn(fn))(qenv(fn), 5, v130, v129, v128, v127, v126);
    }

v138:
    v7 = stack[-5];
    v130 = stack[-4];
    v129 = stack[-3];
    v128 = stack[-6];
    v127 = stack[-2];
    v126 = stack[-1];
    fn = elt(env, 9); /* letscalar */
    v126 = (*qfnn(fn))(qenv(fn), 6, v7, v130, v129, v128, v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v131;
    v126 = nil;
    { popv(8); return onevalue(v126); }

v51:
    v126 = stack[-5];
    {
        popv(8);
        fn = elt(env, 10); /* errpri1 */
        return (*qfn1(fn))(qenv(fn), v126);
    }

v78:
    v126 = (Lisp_Object)1; /* 0 */
    stack[-5] = v126;
    v126 = stack[-5];
    {
        popv(8);
        fn = elt(env, 10); /* errpri1 */
        return (*qfn1(fn))(qenv(fn), v126);
    }
/* error exit handlers */
v131:
    popv(8);
    return nil;
}



/* Code for !*invsq */

static Lisp_Object CC_Hinvsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v78;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *invsq");
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
    v78 = v0;
/* end of prologue */
    v47 = qvalue(elt(env, 1)); /* sqrtflag */
    if (v47 == nil) goto v69;
    v47 = v78;
    fn = elt(env, 2); /* invsq */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* sqrt2top */
        return (*qfn1(fn))(qenv(fn), v47);
    }

v69:
    v47 = v78;
    {
        popv(1);
        fn = elt(env, 2); /* invsq */
        return (*qfn1(fn))(qenv(fn), v47);
    }
/* error exit handlers */
v141:
    popv(1);
    return nil;
}



/* Code for dipcontenti1 */

static Lisp_Object MS_CDECL CC_dipcontenti1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v95, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v84, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dipcontenti1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipcontenti1");
#endif
    if (stack >= stacklimit)
    {
        push3(v95,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v95;
    stack[-1] = v1;
    v84 = v0;
/* end of prologue */

v148:
    v146 = stack[0];
    if (v146 == nil) goto v90;
    v146 = stack[0];
    v146 = qcdr(v146);
    v146 = qcar(v146);
    fn = elt(env, 1); /* vbcgcd */
    v146 = (*qfn2(fn))(qenv(fn), v84, v146);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-3];
    stack[-2] = v146;
    v146 = stack[-1];
    if (v146 == nil) goto v55;
    v146 = stack[0];
    v84 = qcar(v146);
    v146 = stack[-1];
    fn = elt(env, 2); /* dipcontevmin */
    v146 = (*qfn2(fn))(qenv(fn), v84, v146);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-3];
    stack[-1] = v146;
    goto v55;

v55:
    v146 = stack[-2];
    fn = elt(env, 3); /* bcone!? */
    v146 = (*qfn1(fn))(qenv(fn), v146);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-3];
    if (v146 == nil) goto v149;
    v146 = stack[-1];
    if (!(v146 == nil)) goto v149;
    v146 = stack[-2];
    popv(4);
    return ncons(v146);

v149:
    v84 = stack[-2];
    v147 = stack[-1];
    v146 = stack[0];
    v146 = qcdr(v146);
    v146 = qcdr(v146);
    stack[-1] = v147;
    stack[0] = v146;
    goto v148;

v90:
    v146 = stack[-1];
    popv(4);
    return cons(v84, v146);
/* error exit handlers */
v70:
    popv(4);
    return nil;
}



/* Code for vevzero!?1 */

static Lisp_Object CC_vevzeroW1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v151, v122;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevzero?1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v151 = v0;
/* end of prologue */

v148:
    v74 = v151;
    v74 = (v74 == nil ? lisp_true : nil);
    if (!(v74 == nil)) return onevalue(v74);
    v74 = v151;
    v122 = qcar(v74);
    v74 = (Lisp_Object)1; /* 0 */
    if (v122 == v74) goto v152;
    v74 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v74);

v152:
    v74 = v151;
    v74 = qcdr(v74);
    v74 = (v74 == nil ? lisp_true : nil);
    if (!(v74 == nil)) return onevalue(v74);
    v74 = v151;
    v74 = qcdr(v74);
    v122 = qcar(v74);
    v74 = (Lisp_Object)1; /* 0 */
    if (v122 == v74) goto v124;
    v74 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v74);

v124:
    v74 = v151;
    v74 = qcdr(v74);
    v74 = qcdr(v74);
    v151 = v74;
    goto v148;
}



/* Code for xregister_wedge_pair */

static Lisp_Object MS_CDECL CC_xregister_wedge_pair(Lisp_Object env, int nargs, ...)
{
    Lisp_Object v95;
    argcheck(nargs, 0, "xregister_wedge_pair");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xregister_wedge_pair");
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v95 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v95);
}



/* Code for rand!-mons!-dense */

static Lisp_Object MS_CDECL CC_randKmonsKdense(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v95, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v210, v211;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rand-mons-dense");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rand-mons-dense");
#endif
    if (stack >= stacklimit)
    {
        push3(v95,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = v95;
    stack[-11] = v1;
    stack[-12] = v0;
/* end of prologue */
    v209 = stack[-12];
    v209 = qcar(v209);
    stack[-13] = v209;
    v209 = stack[-12];
    v209 = qcdr(v209);
    stack[-12] = v209;
    v209 = stack[-12];
    if (v209 == nil) goto v93;
    v211 = stack[-12];
    v210 = stack[-11];
    v209 = stack[-10];
    stack[-9] = CC_randKmonsKdense(env, 3, v211, v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = (Lisp_Object)17; /* 1 */
    stack[-8] = v209;
    goto v213;

v213:
    v210 = stack[-11];
    v209 = stack[-8];
    v209 = difference2(v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = Lminusp(nil, v209);
    env = stack[-14];
    if (v209 == nil) goto v214;
    v209 = qvalue(elt(env, 1)); /* nil */
    goto v215;

v215:
    {
        Lisp_Object v216 = stack[-9];
        popv(15);
        return Lappend(nil, v216, v209);
    }

v214:
    v210 = stack[-13];
    v209 = stack[-8];
    fn = elt(env, 2); /* mksq */
    v209 = (*qfn2(fn))(qenv(fn), v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = qcar(v209);
    stack[-4] = v209;
    stack[-2] = stack[-12];
    v210 = stack[-11];
    v209 = stack[-8];
    stack[-1] = difference2(v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[0] = (Lisp_Object)1; /* 0 */
    v210 = stack[-10];
    v209 = stack[-8];
    v209 = difference2(v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    fn = elt(env, 3); /* max */
    v209 = (*qfn2(fn))(qenv(fn), stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = CC_randKmonsKdense(env, 3, stack[-2], stack[-1], v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-3] = v209;
    v209 = stack[-3];
    if (v209 == nil) goto v217;
    v209 = stack[-3];
    v209 = qcar(v209);
    v210 = stack[-4];
    fn = elt(env, 4); /* multf */
    v209 = (*qfn2(fn))(qenv(fn), v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = ncons(v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-1] = v209;
    stack[-2] = v209;
    goto v110;

v110:
    v209 = stack[-3];
    v209 = qcdr(v209);
    stack[-3] = v209;
    v209 = stack[-3];
    if (v209 == nil) goto v218;
    stack[0] = stack[-1];
    v209 = stack[-3];
    v209 = qcar(v209);
    v210 = stack[-4];
    fn = elt(env, 4); /* multf */
    v209 = (*qfn2(fn))(qenv(fn), v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = ncons(v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = Lrplacd(nil, stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = stack[-1];
    v209 = qcdr(v209);
    stack[-1] = v209;
    goto v110;

v218:
    v209 = stack[-2];
    goto v219;

v219:
    stack[-7] = v209;
    v209 = stack[-7];
    fn = elt(env, 5); /* lastpair */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-6] = v209;
    v209 = stack[-8];
    v209 = add1(v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-8] = v209;
    v209 = stack[-6];
    if (!consp(v209)) goto v213;
    else goto v220;

v220:
    v210 = stack[-11];
    v209 = stack[-8];
    v209 = difference2(v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = Lminusp(nil, v209);
    env = stack[-14];
    if (v209 == nil) goto v2;
    v209 = stack[-7];
    goto v215;

v2:
    stack[-5] = stack[-6];
    v210 = stack[-13];
    v209 = stack[-8];
    fn = elt(env, 2); /* mksq */
    v209 = (*qfn2(fn))(qenv(fn), v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = qcar(v209);
    stack[-4] = v209;
    stack[-2] = stack[-12];
    v210 = stack[-11];
    v209 = stack[-8];
    stack[-1] = difference2(v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[0] = (Lisp_Object)1; /* 0 */
    v210 = stack[-10];
    v209 = stack[-8];
    v209 = difference2(v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    fn = elt(env, 3); /* max */
    v209 = (*qfn2(fn))(qenv(fn), stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = CC_randKmonsKdense(env, 3, stack[-2], stack[-1], v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-3] = v209;
    v209 = stack[-3];
    if (v209 == nil) goto v221;
    v209 = stack[-3];
    v209 = qcar(v209);
    v210 = stack[-4];
    fn = elt(env, 4); /* multf */
    v209 = (*qfn2(fn))(qenv(fn), v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = ncons(v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-1] = v209;
    stack[-2] = v209;
    goto v222;

v222:
    v209 = stack[-3];
    v209 = qcdr(v209);
    stack[-3] = v209;
    v209 = stack[-3];
    if (v209 == nil) goto v223;
    stack[0] = stack[-1];
    v209 = stack[-3];
    v209 = qcar(v209);
    v210 = stack[-4];
    fn = elt(env, 4); /* multf */
    v209 = (*qfn2(fn))(qenv(fn), v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = ncons(v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = Lrplacd(nil, stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = stack[-1];
    v209 = qcdr(v209);
    stack[-1] = v209;
    goto v222;

v223:
    v209 = stack[-2];
    goto v224;

v224:
    v209 = Lrplacd(nil, stack[-5], v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = stack[-6];
    fn = elt(env, 5); /* lastpair */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-6] = v209;
    v209 = stack[-8];
    v209 = add1(v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-8] = v209;
    goto v220;

v221:
    v209 = qvalue(elt(env, 1)); /* nil */
    goto v224;

v217:
    v209 = qvalue(elt(env, 1)); /* nil */
    goto v219;

v93:
    v210 = stack[-10];
    v209 = (Lisp_Object)1; /* 0 */
    v209 = (Lisp_Object)greaterp2(v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    v209 = v209 ? lisp_true : nil;
    env = stack[-14];
    if (v209 == nil) goto v125;
    v210 = stack[-13];
    v209 = stack[-10];
    fn = elt(env, 2); /* mksq */
    v209 = (*qfn2(fn))(qenv(fn), v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = qcar(v209);
    stack[-3] = v209;
    goto v142;

v142:
    v209 = stack[-10];
    v209 = add1(v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-4] = v209;
    v210 = stack[-11];
    v209 = stack[-4];
    v209 = difference2(v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = Lminusp(nil, v209);
    env = stack[-14];
    if (v209 == nil) goto v225;
    v209 = qvalue(elt(env, 1)); /* nil */
    goto v152;

v152:
    {
        Lisp_Object v226 = stack[-3];
        popv(15);
        return cons(v226, v209);
    }

v225:
    v210 = stack[-13];
    v209 = stack[-4];
    fn = elt(env, 2); /* mksq */
    v209 = (*qfn2(fn))(qenv(fn), v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = qcar(v209);
    v209 = ncons(v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-1] = v209;
    stack[-2] = v209;
    goto v123;

v123:
    v209 = stack[-4];
    v209 = add1(v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    stack[-4] = v209;
    v210 = stack[-11];
    v209 = stack[-4];
    v209 = difference2(v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = Lminusp(nil, v209);
    env = stack[-14];
    if (v209 == nil) goto v227;
    v209 = stack[-2];
    goto v152;

v227:
    stack[0] = stack[-1];
    v210 = stack[-13];
    v209 = stack[-4];
    fn = elt(env, 2); /* mksq */
    v209 = (*qfn2(fn))(qenv(fn), v210, v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = qcar(v209);
    v209 = ncons(v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = Lrplacd(nil, stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-14];
    v209 = stack[-1];
    v209 = qcdr(v209);
    stack[-1] = v209;
    goto v123;

v125:
    v209 = (Lisp_Object)17; /* 1 */
    stack[-3] = v209;
    goto v142;
/* error exit handlers */
v212:
    popv(15);
    return nil;
}



/* Code for exp!: */

static Lisp_Object CC_expT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v249, v170, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exp:");
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
    stack[-10] = v1;
    stack[-11] = v0;
/* end of prologue */
    v249 = stack[-10];
    v249 = integerp(v249);
    if (v249 == nil) goto v250;
    v170 = stack[-10];
    v249 = (Lisp_Object)1; /* 0 */
    v249 = (Lisp_Object)lesseq2(v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    v249 = v249 ? lisp_true : nil;
    env = stack[-13];
    if (!(v249 == nil)) goto v250;
    v249 = stack[-11];
    fn = elt(env, 5); /* bfzerop!: */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    if (v249 == nil) goto v77;
    v249 = qvalue(elt(env, 1)); /* bfone!* */
    { popv(14); return onevalue(v249); }

v77:
    stack[0] = elt(env, 2); /* !:rd!: */
    v249 = stack[-11];
    fn = elt(env, 6); /* abs!: */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-1] = v249;
    fn = elt(env, 7); /* conv!:bf2i */
    v170 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-9] = v170;
    v249 = (Lisp_Object)1; /* 0 */
    v249 = list2star(stack[0], v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[0] = v249;
    v170 = stack[-1];
    v249 = stack[0];
    fn = elt(env, 8); /* difference!: */
    v249 = (*qfn2(fn))(qenv(fn), v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-2] = stack[-10];
    v249 = stack[-9];
    fn = elt(env, 9); /* msd */
    v170 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    v249 = (Lisp_Object)113; /* 7 */
    v249 = plus2(v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    v249 = plus2(stack[-2], v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-12] = v249;
    v170 = stack[-1];
    v249 = stack[0];
    fn = elt(env, 8); /* difference!: */
    v249 = (*qfn2(fn))(qenv(fn), v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-8] = v249;
    v249 = stack[0];
    fn = elt(env, 5); /* bfzerop!: */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    if (v249 == nil) goto v203;
    v249 = qvalue(elt(env, 1)); /* bfone!* */
    stack[-7] = v249;
    goto v251;

v251:
    v249 = stack[-8];
    fn = elt(env, 5); /* bfzerop!: */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    if (v249 == nil) goto v252;
    v249 = qvalue(elt(env, 1)); /* bfone!* */
    stack[-6] = v249;
    goto v253;

v253:
    v170 = stack[-7];
    v249 = stack[-6];
    fn = elt(env, 10); /* times!: */
    stack[0] = (*qfn2(fn))(qenv(fn), v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    v249 = stack[-10];
    v249 = add1(v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    fn = elt(env, 11); /* cut!:mt */
    v249 = (*qfn2(fn))(qenv(fn), stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-1] = v249;
    v249 = stack[-11];
    fn = elt(env, 12); /* minusp!: */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    if (v249 == nil) goto v254;
    v168 = qvalue(elt(env, 1)); /* bfone!* */
    v170 = stack[-1];
    v249 = stack[-10];
    {
        popv(14);
        fn = elt(env, 13); /* divide!: */
        return (*qfnn(fn))(qenv(fn), 3, v168, v170, v249);
    }

v254:
    v170 = stack[-1];
    v249 = stack[-10];
    {
        popv(14);
        fn = elt(env, 14); /* round!:mt */
        return (*qfn2(fn))(qenv(fn), v170, v249);
    }

v252:
    stack[-1] = elt(env, 2); /* !:rd!: */
    stack[0] = (Lisp_Object)33; /* 2 */
    v249 = stack[-12];
    v249 = negate(v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    v249 = list2star(stack[-1], stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-4] = v249;
    v249 = qvalue(elt(env, 1)); /* bfone!* */
    stack[0] = v249;
    stack[-2] = v249;
    stack[-6] = v249;
    v249 = (Lisp_Object)17; /* 1 */
    stack[-9] = v249;
    v249 = (Lisp_Object)1; /* 0 */
    stack[-5] = v249;
    goto v213;

v213:
    v170 = stack[0];
    v249 = stack[-4];
    fn = elt(env, 15); /* greaterp!: */
    v249 = (*qfn2(fn))(qenv(fn), v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    if (v249 == nil) goto v253;
    stack[0] = elt(env, 2); /* !:rd!: */
    stack[-1] = stack[-9];
    v249 = stack[-5];
    v249 = add1(v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-5] = v249;
    v170 = times2(stack[-1], v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-9] = v170;
    v249 = (Lisp_Object)1; /* 0 */
    v249 = list2star(stack[0], v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-3] = v249;
    v170 = stack[-2];
    v249 = stack[-8];
    fn = elt(env, 10); /* times!: */
    stack[0] = (*qfn2(fn))(qenv(fn), v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    v249 = stack[-12];
    v249 = negate(v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    fn = elt(env, 16); /* cut!:ep */
    v249 = (*qfn2(fn))(qenv(fn), stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-2] = v249;
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = stack[-12];
    v249 = stack[-3];
    fn = elt(env, 17); /* order!: */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[0] = difference2(stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    v249 = stack[-2];
    fn = elt(env, 17); /* order!: */
    v249 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    v249 = plus2(stack[0], v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    fn = elt(env, 18); /* max */
    v249 = (*qfn2(fn))(qenv(fn), stack[-1], v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    v168 = stack[-2];
    v170 = stack[-3];
    fn = elt(env, 13); /* divide!: */
    v249 = (*qfnn(fn))(qenv(fn), 3, v168, v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[0] = v249;
    v170 = stack[-6];
    v249 = stack[0];
    fn = elt(env, 19); /* plus!: */
    v249 = (*qfn2(fn))(qenv(fn), v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-6] = v249;
    v170 = stack[-5];
    v249 = (Lisp_Object)161; /* 10 */
    v170 = Cremainder(v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    v249 = (Lisp_Object)1; /* 0 */
    if (!(v170 == v249)) goto v213;
    stack[-1] = stack[-6];
    v249 = stack[-12];
    v249 = negate(v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    fn = elt(env, 16); /* cut!:ep */
    v249 = (*qfn2(fn))(qenv(fn), stack[-1], v249);
    nil = C_nil;
    if (exception_pending()) goto v171;
    env = stack[-13];
    stack[-6] = v249;
    goto v213;

v203:
    v249 = stack[-12];
    stack[0] = qvalue(elt(env, 3)); /* !:bprec!: */
    qvalue(elt(env, 3)) = v249; /* !:bprec!: */
    v249 = stack[-12];
    fn = elt(env, 20); /* !:e */
    v170 = (*qfn1(fn))(qenv(fn), v249);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-13];
    v249 = stack[-9];
    fn = elt(env, 21); /* texpt!: */
    v249 = (*qfn2(fn))(qenv(fn), v170, v249);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-13];
    stack[-7] = v249;
    qvalue(elt(env, 3)) = stack[0]; /* !:bprec!: */
    goto v251;

v250:
    v249 = elt(env, 0); /* exp!: */
    {
        popv(14);
        fn = elt(env, 22); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v249);
    }
/* error exit handlers */
v172:
    env = stack[-13];
    qvalue(elt(env, 3)) = stack[0]; /* !:bprec!: */
    popv(14);
    return nil;
v171:
    popv(14);
    return nil;
}



/* Code for atlas_edges */

static Lisp_Object CC_atlas_edges(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for atlas_edges");
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
    v92 = stack[0];
    v92 = qcar(v92);
    fn = elt(env, 1); /* map__edges */
    stack[-1] = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v92 = stack[0];
    v92 = qcdr(v92);
    v92 = qcdr(v92);
    v92 = qcar(v92);
    fn = elt(env, 2); /* den__edges */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    fn = elt(env, 3); /* union_edges */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v92);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    v92 = stack[0];
    v92 = qcdr(v92);
    v92 = qcar(v92);
    fn = elt(env, 4); /* coeff_edges */
    v92 = (*qfn1(fn))(qenv(fn), v92);
    nil = C_nil;
    if (exception_pending()) goto v94;
    env = stack[-2];
    {
        Lisp_Object v83 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* union_edges */
        return (*qfn2(fn))(qenv(fn), v83, v92);
    }
/* error exit handlers */
v94:
    popv(3);
    return nil;
}



/* Code for rlval */

static Lisp_Object CC_rlval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v65, v191;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rlval");
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
    v65 = v0;
/* end of prologue */
    v7 = v65;
    if (!consp(v7)) { popv(6); return onevalue(v65); }
    v7 = v65;
    v7 = qcar(v7);
    if (!consp(v7)) { popv(6); return onevalue(v65); }
    v7 = stack[-3];
    if (!consp(v7)) goto v150;
    v7 = stack[-3];
    v7 = qcdr(v7);
    v191 = qcar(v7);
    v7 = (Lisp_Object)1; /* 0 */
    v7 = (v191 == v7 ? lisp_true : nil);
    goto v141;

v141:
    if (v7 == nil) goto v206;
    v7 = v65;
    v7 = qcar(v7);
    v191 = qcar(v7);
    v7 = (Lisp_Object)1; /* 0 */
    if (v191 == v7) goto v17;
    v7 = (Lisp_Object)1; /* 0 */
    {
        popv(6);
        fn = elt(env, 4); /* r2flbf */
        return (*qfn1(fn))(qenv(fn), v7);
    }

v17:
    v7 = v65;
    v7 = qcar(v7);
    v7 = qcdr(v7);
    { popv(6); return onevalue(v7); }

v206:
    v191 = stack[-3];
    v7 = elt(env, 1); /* !:rd!: */
    if (!consp(v191)) goto v268;
    v191 = qcar(v191);
    if (!(v191 == v7)) goto v268;
    v7 = stack[-3];
    v7 = qcdr(v7);
    v7 = (consp(v7) ? nil : lisp_true);
    v7 = (v7 == nil ? lisp_true : nil);
    goto v39;

v39:
    stack[-2] = v7;
    v7 = v65;
    fn = elt(env, 5); /* ncoeffs */
    v7 = (*qfn1(fn))(qenv(fn), v7);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    v7 = qcdr(v7);
    v65 = v7;
    v7 = qcar(v7);
    stack[-4] = v7;
    v7 = v65;
    v7 = qcdr(v7);
    stack[-1] = v7;
    goto v269;

v269:
    v7 = stack[-1];
    if (v7 == nil) goto v251;
    v7 = stack[-1];
    v7 = qcar(v7);
    stack[0] = v7;
    v7 = stack[-2];
    if (v7 == nil) goto v33;
    v65 = stack[-3];
    v7 = stack[-4];
    fn = elt(env, 6); /* times!: */
    v7 = (*qfn2(fn))(qenv(fn), v65, v7);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    goto v270;

v270:
    stack[-4] = v7;
    v7 = stack[0];
    if (v7 == nil) goto v271;
    v7 = stack[-2];
    if (v7 == nil) goto v29;
    v65 = stack[0];
    v7 = stack[-4];
    fn = elt(env, 7); /* plus!: */
    v7 = (*qfn2(fn))(qenv(fn), v65, v7);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    goto v31;

v31:
    stack[-4] = v7;
    goto v271;

v271:
    v7 = stack[-1];
    v7 = qcdr(v7);
    stack[-1] = v7;
    goto v269;

v29:
    v65 = stack[-4];
    v7 = stack[0];
    v7 = plus2(v65, v7);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    goto v31;

v33:
    v65 = stack[-3];
    v7 = stack[-4];
    v7 = times2(v65, v7);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    goto v270;

v251:
    v7 = stack[-2];
    if (v7 == nil) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    v7 = stack[-4];
    v7 = qcdr(v7);
    v7 = qcar(v7);
    v191 = v7;
    v65 = v191;
    v7 = (Lisp_Object)1; /* 0 */
    if (v65 == v7) goto v139;
    v65 = v191;
    v7 = qvalue(elt(env, 3)); /* !:bprec!: */
    fn = elt(env, 8); /* inorm */
    v7 = (*qfn2(fn))(qenv(fn), v65, v7);
    nil = C_nil;
    if (exception_pending()) goto v131;
    env = stack[-5];
    v191 = v7;
    stack[-1] = elt(env, 1); /* !:rd!: */
    v7 = v191;
    stack[0] = qcar(v7);
    v7 = v191;
    v65 = qcdr(v7);
    v7 = stack[-4];
    v7 = qcdr(v7);
    v7 = qcdr(v7);
    v7 = plus2(v65, v7);
    nil = C_nil;
    if (exception_pending()) goto v131;
    {
        Lisp_Object v133 = stack[-1];
        Lisp_Object v134 = stack[0];
        popv(6);
        return list2star(v133, v134, v7);
    }

v139:
    v191 = elt(env, 1); /* !:rd!: */
    v65 = (Lisp_Object)1; /* 0 */
    v7 = (Lisp_Object)1; /* 0 */
    popv(6);
    return list2star(v191, v65, v7);

v268:
    v7 = qvalue(elt(env, 2)); /* nil */
    goto v39;

v150:
    v7 = stack[-3];
    v7 = (Lisp_Object)zerop(v7);
    v7 = v7 ? lisp_true : nil;
    env = stack[-5];
    goto v141;
/* error exit handlers */
v131:
    popv(6);
    return nil;
}



/* Code for mkcrn */

static Lisp_Object CC_mkcrn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v78, v141;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkcrn");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v47 = v1;
    v78 = v0;
/* end of prologue */
    v141 = elt(env, 1); /* !:crn!: */
    return list2star(v141, v78, v47);
}



/* Code for remove_root_item */

static Lisp_Object CC_remove_root_item(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v145, v146;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for remove_root_item");
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
    v145 = stack[-1];
    v145 = qcdr(v145);
    v145 = qcar(v145);
    stack[-2] = v145;
    v145 = stack[-1];
    v145 = qcar(v145);
    stack[0] = v145;
    v146 = stack[-1];
    v145 = stack[-1];
    v145 = qcdr(v145);
    v145 = qcdr(v145);
    v145 = qcar(v145);
    fn = elt(env, 2); /* setcar */
    v145 = (*qfn2(fn))(qenv(fn), v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    v146 = stack[-1];
    v145 = stack[-1];
    v145 = qcdr(v145);
    v145 = qcdr(v145);
    v145 = qcdr(v145);
    fn = elt(env, 3); /* setcdr */
    v145 = (*qfn2(fn))(qenv(fn), v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    v145 = stack[-2];
    v145 = qcdr(v145);
    if (v145 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    else goto v208;

v208:
    v145 = stack[-1];
    v145 = qcdr(v145);
    if (v145 == nil) goto v45;
    v145 = stack[-1];
    v145 = qcdr(v145);
    v145 = qcar(v145);
    stack[-1] = v145;
    goto v208;

v45:
    v146 = stack[-1];
    v145 = stack[-2];
    v145 = qcar(v145);
    fn = elt(env, 2); /* setcar */
    v145 = (*qfn2(fn))(qenv(fn), v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v43;
    env = stack[-3];
    v146 = stack[-1];
    v145 = stack[-2];
    v145 = qcdr(v145);
    fn = elt(env, 3); /* setcdr */
    v145 = (*qfn2(fn))(qenv(fn), v146, v145);
    nil = C_nil;
    if (exception_pending()) goto v43;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v43:
    popv(4);
    return nil;
}



/* Code for latexprint */

static Lisp_Object CC_latexprint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for latexprint");
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
    fn = elt(env, 1); /* prinlabegin */
    v100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-1];
    v100 = stack[0];
    fn = elt(env, 2); /* latexprin */
    v100 = (*qfn1(fn))(qenv(fn), v100);
    nil = C_nil;
    if (exception_pending()) goto v80;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 3); /* prinlaend */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v80:
    popv(2);
    return nil;
}



/* Code for rtrnda */

static Lisp_Object CC_rtrnda(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v260, v247;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rtrnda");
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
    v260 = v1;
    stack[0] = v0;
/* end of prologue */
    v255 = stack[0];
    if (!consp(v255)) goto v112;
    v255 = stack[0];
    v255 = qcdr(v255);
    v247 = qcar(v255);
    v255 = (Lisp_Object)1; /* 0 */
    v255 = (v247 == v255 ? lisp_true : nil);
    goto v80;

v80:
    if (v255 == nil) goto v6;
    v260 = (Lisp_Object)1; /* 0 */
    v255 = (Lisp_Object)1; /* 0 */
    v255 = cons(v260, v255);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    qvalue(elt(env, 1)) = v255; /* rlval!# */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v6:
    v255 = stack[0];
    fn = elt(env, 2); /* round!:dec1 */
    v255 = (*qfn2(fn))(qenv(fn), v255, v260);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-1];
    v260 = v255;
    qvalue(elt(env, 1)) = v260; /* rlval!# */
    v260 = qcar(v260);
    v255 = qcdr(v255);
    {
        popv(2);
        fn = elt(env, 3); /* decimal2internal */
        return (*qfn2(fn))(qenv(fn), v260, v255);
    }

v112:
    v255 = stack[0];
    v255 = (Lisp_Object)zerop(v255);
    v255 = v255 ? lisp_true : nil;
    env = stack[-1];
    goto v80;
/* error exit handlers */
v149:
    popv(2);
    return nil;
}



/* Code for forttab */

static Lisp_Object CC_forttab(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for forttab");
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
    v73 = qvalue(elt(env, 1)); /* fortlinelen!* */
    v202 = qvalue(elt(env, 2)); /* minfortlinelen!* */
    v202 = difference2(v73, v202);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-1];
    fn = elt(env, 5); /* min0 */
    v73 = (*qfn2(fn))(qenv(fn), stack[0], v202);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-1];
    v202 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 6); /* max */
    v202 = (*qfn2(fn))(qenv(fn), v73, v202);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-1];
    qvalue(elt(env, 3)) = v202; /* !*fortcurrind!* */
    v73 = qvalue(elt(env, 3)); /* !*fortcurrind!* */
    v202 = qvalue(elt(env, 4)); /* !*posn!* */
    v73 = difference2(v73, v202);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-1];
    stack[0] = v73;
    v202 = (Lisp_Object)1; /* 0 */
    v202 = (Lisp_Object)greaterp2(v73, v202);
    nil = C_nil;
    if (exception_pending()) goto v151;
    v202 = v202 ? lisp_true : nil;
    env = stack[-1];
    if (v202 == nil) goto v93;
    v202 = stack[0];
    fn = elt(env, 7); /* nspaces */
    v202 = (*qfn1(fn))(qenv(fn), v202);
    nil = C_nil;
    if (exception_pending()) goto v151;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 8); /* pprin2 */
        return (*qfn1(fn))(qenv(fn), v202);
    }

v93:
    v202 = nil;
    { popv(2); return onevalue(v202); }
/* error exit handlers */
v151:
    popv(2);
    return nil;
}



/* Code for tot!-asym!-indp */

static Lisp_Object CC_totKasymKindp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v205;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tot-asym-indp");
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

v148:
    v147 = stack[0];
    v147 = (v147 == nil ? lisp_true : nil);
    if (!(v147 == nil)) { popv(2); return onevalue(v147); }
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = (v147 == nil ? lisp_true : nil);
    if (!(v147 == nil)) { popv(2); return onevalue(v147); }
    v147 = stack[0];
    v205 = qcar(v147);
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = qcar(v147);
    if (equal(v205, v147)) goto v91;
    v147 = stack[0];
    v147 = qcar(v147);
    if (!consp(v147)) goto v85;
    v147 = stack[0];
    v147 = qcar(v147);
    fn = elt(env, 2); /* indxchk */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    if (!(v147 == nil)) goto v75;
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = qcar(v147);
    fn = elt(env, 2); /* indxchk */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    if (!(v147 == nil)) goto v75;
    v147 = stack[0];
    v205 = qcar(v147);
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = qcar(v147);
    fn = elt(env, 3); /* indordlp */
    v147 = (*qfn2(fn))(qenv(fn), v205, v147);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    goto v75;

v75:
    if (v147 == nil) goto v91;
    v147 = stack[0];
    v147 = qcdr(v147);
    stack[0] = v147;
    goto v148;

v91:
    v147 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v147); }

v85:
    v147 = stack[0];
    v205 = qcar(v147);
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = qcar(v147);
    fn = elt(env, 4); /* indordp */
    v147 = (*qfn2(fn))(qenv(fn), v205, v147);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-1];
    goto v75;
/* error exit handlers */
v44:
    popv(2);
    return nil;
}



/* Code for mk!-strand!-vertex */

static Lisp_Object CC_mkKstrandKvertex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v207, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-strand-vertex");
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
    v206 = v1;
    stack[-2] = v0;
/* end of prologue */
    v71 = stack[-2];
    v207 = v206;
    v206 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 1); /* incident */
    v206 = (*qfnn(fn))(qenv(fn), 3, v71, v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-4];
    v207 = v206;
    v206 = v207;
    v206 = qcar(v206);
    stack[-3] = v206;
    stack[-1] = stack[-2];
    v206 = v207;
    stack[0] = qcdr(v206);
    v206 = stack[-3];
    v206 = qcar(v206);
    v206 = qcdr(v206);
    v206 = add1(v206);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-4];
    fn = elt(env, 1); /* incident */
    v206 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], v206);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-4];
    v207 = v206;
    v206 = v207;
    if (v206 == nil) goto v125;
    v206 = v207;
    v206 = qcar(v206);
    goto v132;

v132:
    v71 = stack[-2];
    v207 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* mk!-strand!-vertex2 */
        return (*qfnn(fn))(qenv(fn), 3, v71, v207, v206);
    }

v125:
    v207 = stack[-2];
    v206 = (Lisp_Object)1; /* 0 */
    v206 = cons(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-4];
    v206 = ncons(v206);
    nil = C_nil;
    if (exception_pending()) goto v146;
    env = stack[-4];
    goto v132;
/* error exit handlers */
v146:
    popv(5);
    return nil;
}



/* Code for cdr_signsort */

static Lisp_Object CC_cdr_signsort(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v194, v242;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cdr_signsort");
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
    v194 = v0;
/* end of prologue */
    fn = elt(env, 3); /* copy */
    v194 = (*qfn1(fn))(qenv(fn), v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    stack[-6] = v194;
    v194 = (Lisp_Object)17; /* 1 */
    stack[-1] = v194;
    v194 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v194;
    goto v150;

v150:
    v194 = stack[-6];
    if (v194 == nil) goto v102;
    v194 = stack[-4];
    if (v194 == nil) goto v83;
    v194 = stack[-6];
    v194 = qcar(v194);
    v242 = qcdr(v194);
    v194 = stack[-4];
    v194 = qcar(v194);
    v194 = qcdr(v194);
    if (equal(v242, v194)) goto v208;
    stack[0] = stack[-5];
    v194 = stack[-4];
    v194 = qcar(v194);
    v242 = qcdr(v194);
    v194 = stack[-6];
    v194 = qcar(v194);
    v194 = qcdr(v194);
    v194 = list2(v242, v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    fn = elt(env, 4); /* apply */
    v194 = (*qfn2(fn))(qenv(fn), stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    if (v194 == nil) goto v38;
    v194 = stack[-6];
    v242 = qcar(v194);
    v194 = stack[-4];
    v194 = cons(v242, v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    stack[-4] = v194;
    v194 = stack[-6];
    v194 = qcdr(v194);
    stack[-6] = v194;
    goto v150;

v38:
    v194 = stack[-1];
    v194 = negate(v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    stack[-1] = v194;
    v194 = stack[-4];
    stack[-3] = v194;
    v194 = qvalue(elt(env, 2)); /* t */
    stack[-2] = v194;
    goto v264;

v264:
    v194 = stack[-2];
    if (v194 == nil) goto v121;
    v194 = stack[-3];
    v194 = qcdr(v194);
    if (v194 == nil) goto v275;
    v194 = stack[-3];
    v194 = qcdr(v194);
    v194 = qcar(v194);
    v242 = qcdr(v194);
    v194 = stack[-6];
    v194 = qcar(v194);
    v194 = qcdr(v194);
    if (equal(v242, v194)) goto v276;
    stack[0] = stack[-5];
    v194 = stack[-3];
    v194 = qcdr(v194);
    v194 = qcar(v194);
    v242 = qcdr(v194);
    v194 = stack[-6];
    v194 = qcar(v194);
    v194 = qcdr(v194);
    v194 = list2(v242, v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    fn = elt(env, 4); /* apply */
    v194 = (*qfn2(fn))(qenv(fn), stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    if (v194 == nil) goto v115;
    v194 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v194;
    goto v264;

v115:
    v194 = stack[-3];
    v194 = qcdr(v194);
    stack[-3] = v194;
    v194 = stack[-1];
    v194 = negate(v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    stack[-1] = v194;
    goto v264;

v276:
    v194 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v194;
    v194 = (Lisp_Object)1; /* 0 */
    stack[-1] = v194;
    v194 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v194;
    stack[-4] = v194;
    goto v264;

v275:
    v194 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v194;
    goto v264;

v121:
    v194 = stack[-6];
    if (v194 == nil) goto v150;
    stack[0] = stack[-3];
    v194 = stack[-6];
    v242 = qcar(v194);
    v194 = stack[-3];
    v194 = qcdr(v194);
    v194 = cons(v242, v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    v194 = Lrplacd(nil, stack[0], v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    v194 = stack[-6];
    v194 = qcdr(v194);
    stack[-6] = v194;
    goto v150;

v208:
    v194 = (Lisp_Object)1; /* 0 */
    stack[-1] = v194;
    v194 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v194;
    stack[-4] = v194;
    goto v150;

v83:
    v194 = stack[-6];
    v242 = qcar(v194);
    v194 = stack[-4];
    v194 = cons(v242, v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-7];
    stack[-4] = v194;
    v194 = stack[-6];
    v194 = qcdr(v194);
    stack[-6] = v194;
    goto v150;

v102:
    stack[0] = stack[-1];
    v194 = stack[-4];
    v194 = Lreverse(nil, v194);
    nil = C_nil;
    if (exception_pending()) goto v68;
    {
        Lisp_Object v217 = stack[0];
        popv(8);
        return cons(v217, v194);
    }
/* error exit handlers */
v68:
    popv(8);
    return nil;
}



/* Code for makeupsf */

static Lisp_Object MS_CDECL CC_makeupsf(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v95, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v283, v284, v26, v193;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "makeupsf");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeupsf");
#endif
    if (stack >= stacklimit)
    {
        push3(v95,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v95);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v95;
    stack[-1] = v1;
    v193 = v0;
/* end of prologue */
    v283 = v193;
    v283 = qcar(v283);
    if (!consp(v283)) goto v85;
    v283 = v193;
    v284 = qcdr(v283);
    v283 = (Lisp_Object)17; /* 1 */
    if (v284 == v283) goto v85;
    v283 = v193;
    v283 = qcar(v283);
    v284 = qcar(v283);
    v283 = elt(env, 1); /* sqrt */
    if (v284 == v283) goto v39;
    v283 = v193;
    v283 = qcar(v283);
    v26 = v283;
    v283 = v26;
    v284 = qcar(v283);
    v283 = elt(env, 2); /* expt */
    if (v284 == v283) goto v79;
    v283 = qvalue(elt(env, 3)); /* nil */
    goto v70;

v70:
    if (v283 == nil) goto v189;
    v283 = v193;
    v284 = qcar(v283);
    v283 = stack[-1];
    v26 = v193;
    v26 = qcdr(v26);
    fn = elt(env, 5); /* !*multfexpt */
    v284 = (*qfnn(fn))(qenv(fn), 3, v284, v283, v26);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v283 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v284, v283);
    }

v189:
    v284 = v193;
    v283 = (Lisp_Object)17; /* 1 */
    v283 = cons(v284, v283);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v284 = ncons(v283);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v283 = stack[-1];
    fn = elt(env, 7); /* multf */
    v284 = (*qfn2(fn))(qenv(fn), v284, v283);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v283 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v284, v283);
    }

v79:
    v283 = v26;
    v283 = qcdr(v283);
    v283 = qcdr(v283);
    v283 = qcar(v283);
    v26 = v283;
    v283 = v26;
    if (!consp(v283)) goto v199;
    v283 = v26;
    v284 = qcar(v283);
    v283 = elt(env, 4); /* quotient */
    if (v284 == v283) goto v275;
    v283 = qvalue(elt(env, 3)); /* nil */
    goto v70;

v275:
    v283 = v26;
    v283 = qcdr(v283);
    v283 = qcar(v283);
    if (is_number(v283)) goto v285;
    v283 = qvalue(elt(env, 3)); /* nil */
    goto v70;

v285:
    v283 = v26;
    v283 = qcdr(v283);
    v283 = qcdr(v283);
    v283 = qcar(v283);
    v283 = (is_number(v283) ? lisp_true : nil);
    goto v70;

v199:
    v283 = qvalue(elt(env, 3)); /* nil */
    goto v70;

v39:
    v283 = v193;
    v284 = qcar(v283);
    v283 = stack[-1];
    v26 = v193;
    v26 = qcdr(v26);
    fn = elt(env, 8); /* !*multfsqrt */
    v284 = (*qfnn(fn))(qenv(fn), 3, v284, v283, v26);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v283 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v284, v283);
    }

v85:
    v284 = v193;
    v283 = (Lisp_Object)17; /* 1 */
    v283 = cons(v284, v283);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v284 = ncons(v283);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v283 = stack[-1];
    fn = elt(env, 7); /* multf */
    v284 = (*qfn2(fn))(qenv(fn), v284, v283);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v283 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v284, v283);
    }
/* error exit handlers */
v23:
    popv(3);
    return nil;
}



/* Code for cgp_greenp */

static Lisp_Object CC_cgp_greenp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgp_greenp");
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
    v250 = v0;
/* end of prologue */
    fn = elt(env, 1); /* cgp_rp */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    errexit();
    v250 = (v250 == nil ? lisp_true : nil);
    return onevalue(v250);
}



/* Code for getvariables */

static Lisp_Object CC_getvariables(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getvariables");
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
    v152 = v0;
/* end of prologue */
    v142 = v152;
    stack[0] = qcar(v142);
    v142 = v152;
    v152 = qcdr(v142);
    v142 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* varsinsf */
    v142 = (*qfn2(fn))(qenv(fn), v152, v142);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    {
        Lisp_Object v48 = stack[0];
        popv(2);
        fn = elt(env, 2); /* varsinsf */
        return (*qfn2(fn))(qenv(fn), v48, v142);
    }
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for codfac */

static Lisp_Object MS_CDECL CC_codfac(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v261, v262;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "codfac");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for codfac");
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
    v261 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v261;
    goto v141;

v141:
    v262 = (Lisp_Object)-15; /* -1 */
    v261 = stack[-1];
    v261 = difference2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    v261 = Lminusp(nil, v261);
    env = stack[-3];
    if (!(v261 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v262 = qvalue(elt(env, 4)); /* maxvar */
    v261 = stack[-1];
    v261 = plus2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    v262 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v261/(16/CELL)));
    v261 = (Lisp_Object)49; /* 3 */
    v262 = *(Lisp_Object *)((char *)v262 + (CELL-TAG_VECTOR) + ((int32_t)v261/(16/CELL)));
    v261 = (Lisp_Object)-15; /* -1 */
    if (v262 == v261) goto v88;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v262 = qvalue(elt(env, 4)); /* maxvar */
    v261 = stack[-1];
    v261 = plus2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    v262 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v261/(16/CELL)));
    v261 = (Lisp_Object)49; /* 3 */
    v262 = *(Lisp_Object *)((char *)v262 + (CELL-TAG_VECTOR) + ((int32_t)v261/(16/CELL)));
    v261 = (Lisp_Object)-31; /* -2 */
    if (v262 == v261) goto v88;
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v262 = qvalue(elt(env, 4)); /* maxvar */
    v261 = stack[-1];
    v261 = plus2(v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    v262 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v261/(16/CELL)));
    v261 = (Lisp_Object)33; /* 2 */
    v262 = *(Lisp_Object *)((char *)v262 + (CELL-TAG_VECTOR) + ((int32_t)v261/(16/CELL)));
    v261 = elt(env, 5); /* times */
    if (!(v262 == v261)) goto v88;
    v261 = stack[-1];
    fn = elt(env, 7); /* samefar */
    v261 = (*qfn1(fn))(qenv(fn), v261);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    v262 = v261;
    if (v261 == nil) goto v88;
    v261 = qvalue(elt(env, 6)); /* t */
    stack[-2] = v261;
    v261 = v262;
    stack[0] = v261;
    goto v285;

v285:
    v261 = stack[0];
    if (v261 == nil) goto v88;
    v261 = stack[0];
    v261 = qcar(v261);
    v262 = stack[-1];
    fn = elt(env, 8); /* commonfac */
    v261 = (*qfn2(fn))(qenv(fn), v262, v261);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    v261 = stack[0];
    v261 = qcdr(v261);
    stack[0] = v261;
    goto v285;

v88:
    v261 = stack[-1];
    v261 = add1(v261);
    nil = C_nil;
    if (exception_pending()) goto v198;
    env = stack[-3];
    stack[-1] = v261;
    goto v141;
/* error exit handlers */
v198:
    popv(4);
    return nil;
}



/* Code for copyd */

static Lisp_Object CC_copyd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v121, v264;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copyd");
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
    v59 = stack[-1];
    fn = elt(env, 5); /* getd */
    v59 = (*qfn1(fn))(qenv(fn), v59);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    v121 = v59;
    if (v121 == nil) goto v150;
    v264 = stack[-2];
    v121 = v59;
    v121 = qcar(v121);
    v59 = qcdr(v59);
    fn = elt(env, 6); /* putd */
    v59 = (*qfnn(fn))(qenv(fn), 3, v264, v121, v59);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    v59 = stack[-1];
    if (!symbolp(v59)) v59 = nil;
    else { v59 = qfastgets(v59);
           if (v59 != nil) { v59 = elt(v59, 1); /* lose */
#ifdef RECORD_GET
             if (v59 == SPID_NOPROP)
                record_get(elt(fastget_names, 1), 0),
                v59 = nil;
             else record_get(elt(fastget_names, 1), 1),
                v59 = lisp_true; }
           else record_get(elt(fastget_names, 1), 0); }
#else
             if (v59 == SPID_NOPROP) v59 = nil; else v59 = lisp_true; }}
#endif
    if (v59 == nil) goto v44;
    v59 = stack[-2];
    v121 = ncons(v59);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    v59 = elt(env, 4); /* lose */
    v59 = Lflag(nil, v121, v59);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    goto v44;

v44:
    v121 = stack[-1];
    v59 = elt(env, 1); /* !*savedef */
    v121 = get(v121, v59);
    env = stack[-4];
    v59 = v121;
    if (v121 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v264 = stack[-2];
    v121 = elt(env, 1); /* !*savedef */
    v59 = Lputprop(nil, 3, v264, v121, v59);
    nil = C_nil;
    if (exception_pending()) goto v245;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v150:
    v121 = qvalue(elt(env, 1)); /* !*savedef */
    v59 = elt(env, 1); /* !*savedef */
    if (v121 == v59) goto v44;
    stack[-3] = elt(env, 2); /* rlisp */
    stack[0] = (Lisp_Object)17; /* 1 */
    v121 = stack[-1];
    v59 = elt(env, 3); /* "has no definition in copyd" */
    v59 = list2(v121, v59);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    fn = elt(env, 7); /* rerror */
    v59 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[0], v59);
    nil = C_nil;
    if (exception_pending()) goto v245;
    env = stack[-4];
    goto v44;
/* error exit handlers */
v245:
    popv(5);
    return nil;
}



/* Code for column_dim */

static Lisp_Object CC_column_dim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for column_dim");
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
    v81 = qvalue(elt(env, 1)); /* !*fast_la */
    if (!(v81 == nil)) goto v250;
    v81 = stack[0];
    fn = elt(env, 3); /* matrixp */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-1];
    if (!(v81 == nil)) goto v250;
    v81 = elt(env, 2); /* "Error in column_dim: input should be a matrix." 
*/
    fn = elt(env, 4); /* rederr */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-1];
    goto v250;

v250:
    v81 = stack[0];
    fn = elt(env, 5); /* size_of_matrix */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v152;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 6); /* second */
        return (*qfn1(fn))(qenv(fn), v81);
    }
/* error exit handlers */
v152:
    popv(2);
    return nil;
}



/* Code for groebsaveltermbc */

static Lisp_Object CC_groebsaveltermbc(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v260, v247, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsaveltermbc");
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
    v260 = stack[0];
    fn = elt(env, 3); /* vbc2a */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-2];
    stack[0] = v260;
    v260 = stack[0];
    if (is_number(v260)) goto v119;
    v260 = stack[0];
    fn = elt(env, 4); /* constant_exprp */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-2];
    if (!(v260 == nil)) goto v119;
    v260 = stack[0];
    fn = elt(env, 5); /* simp */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-2];
    v260 = qcar(v260);
    fn = elt(env, 6); /* fctrf */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-2];
    v260 = qcdr(v260);
    stack[-1] = v260;
    goto v141;

v141:
    v260 = stack[-1];
    if (v260 == nil) goto v89;
    v260 = stack[-1];
    v260 = qcar(v260);
    v248 = v260;
    v260 = v248;
    v260 = qcar(v260);
    fn = elt(env, 7); /* prepf */
    v260 = (*qfn1(fn))(qenv(fn), v260);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-2];
    v248 = v260;
    v247 = v248;
    v260 = qvalue(elt(env, 2)); /* glterms */
    v260 = Lmember(nil, v247, v260);
    if (!(v260 == nil)) goto v9;
    stack[0] = qvalue(elt(env, 2)); /* glterms */
    v260 = v248;
    v260 = ncons(v260);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-2];
    v260 = Lnconc(nil, stack[0], v260);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-2];
    goto v9;

v9:
    v260 = stack[-1];
    v260 = qcdr(v260);
    stack[-1] = v260;
    goto v141;

v89:
    v260 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v260); }

v119:
    v260 = nil;
    { popv(3); return onevalue(v260); }
/* error exit handlers */
v268:
    popv(3);
    return nil;
}



/* Code for weak_xreduce */

static Lisp_Object CC_weak_xreduce(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v41, v42;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for weak_xreduce");
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
    v71 = qvalue(elt(env, 1)); /* nil */
    v71 = ncons(v71);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    stack[-2] = v71;
    v71 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v71 == nil) goto v55;
    v71 = stack[-1];
    fn = elt(env, 7); /* preppf */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    v41 = Lmkquote(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    v71 = nil;
    fn = elt(env, 8); /* writepri */
    v71 = (*qfn2(fn))(qenv(fn), v41, v71);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    v41 = elt(env, 3); /* " =" */
    v71 = elt(env, 4); /* last */
    fn = elt(env, 8); /* writepri */
    v71 = (*qfn2(fn))(qenv(fn), v41, v71);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    goto v55;

v55:
    v42 = stack[-1];
    v41 = stack[0];
    v71 = stack[-2];
    fn = elt(env, 9); /* weak_xreduce1 */
    v71 = (*qfnn(fn))(qenv(fn), 3, v42, v41, v71);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    stack[0] = v71;
    v71 = qvalue(elt(env, 2)); /* !*trxmod */
    if (v71 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v41 = elt(env, 5); /* "   " */
    v71 = elt(env, 6); /* first */
    fn = elt(env, 8); /* writepri */
    v71 = (*qfn2(fn))(qenv(fn), v41, v71);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    v71 = stack[0];
    fn = elt(env, 7); /* preppf */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    v41 = Lmkquote(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    v71 = elt(env, 4); /* last */
    fn = elt(env, 8); /* writepri */
    v71 = (*qfn2(fn))(qenv(fn), v41, v71);
    nil = C_nil;
    if (exception_pending()) goto v84;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
/* error exit handlers */
v84:
    popv(4);
    return nil;
}



/* Code for bfsqrt */

static Lisp_Object CC_bfsqrt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v304, v305, v306;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfsqrt");
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
    stack[-3] = v0;
/* end of prologue */
    v304 = stack[-3];
    fn = elt(env, 5); /* minusp!: */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    if (v304 == nil) goto v141;
    v305 = stack[-3];
    v304 = elt(env, 0); /* bfsqrt */
    {
        popv(7);
        fn = elt(env, 6); /* terrlst */
        return (*qfn2(fn))(qenv(fn), v305, v304);
    }

v141:
    v304 = stack[-3];
    fn = elt(env, 7); /* bfzerop!: */
    v304 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    if (v304 == nil) goto v85;
    v304 = qvalue(elt(env, 1)); /* bfz!* */
    { popv(7); return onevalue(v304); }

v85:
    v305 = qvalue(elt(env, 2)); /* !:bprec!: */
    v304 = (Lisp_Object)113; /* 7 */
    v304 = plus2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-1] = v304;
    stack[-4] = elt(env, 3); /* !:rd!: */
    stack[-2] = (Lisp_Object)17; /* 1 */
    v304 = stack[-1];
    stack[0] = negate(v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = stack[-3];
    fn = elt(env, 8); /* order!: */
    v305 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = (Lisp_Object)161; /* 10 */
    v305 = plus2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = (Lisp_Object)33; /* 2 */
    v304 = quot2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = plus2(stack[0], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = list2star(stack[-4], stack[-2], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-2] = v304;
    v305 = stack[-3];
    v304 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 9); /* conv!:mt */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-4] = v304;
    v304 = qcdr(v304);
    v304 = qcdr(v304);
    v304 = Levenp(nil, v304);
    env = stack[-6];
    if (v304 == nil) goto v279;
    stack[-5] = elt(env, 3); /* !:rd!: */
    stack[0] = (Lisp_Object)33; /* 2 */
    v305 = (Lisp_Object)49; /* 3 */
    v304 = stack[-4];
    v304 = qcdr(v304);
    v304 = qcar(v304);
    v304 = times2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v305 = plus2(stack[0], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = (Lisp_Object)81; /* 5 */
    stack[0] = quot2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = stack[-4];
    v304 = qcdr(v304);
    v305 = qcdr(v304);
    v304 = (Lisp_Object)33; /* 2 */
    v304 = quot2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = list2star(stack[-5], stack[0], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    goto v43;

v43:
    stack[-4] = v304;
    v304 = (Lisp_Object)17; /* 1 */
    stack[-5] = v304;
    goto v25;

v25:
    v305 = (Lisp_Object)33; /* 2 */
    v304 = stack[-5];
    v305 = times2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[-5] = v305;
    v304 = stack[-1];
    v304 = (Lisp_Object)greaterp2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    v304 = v304 ? lisp_true : nil;
    env = stack[-6];
    if (v304 == nil) goto v196;
    v304 = stack[-1];
    stack[-5] = v304;
    goto v196;

v196:
    stack[0] = qvalue(elt(env, 4)); /* bfhalf!* */
    v306 = stack[-3];
    v305 = stack[-4];
    v304 = stack[-5];
    fn = elt(env, 10); /* divide!: */
    v305 = (*qfnn(fn))(qenv(fn), 3, v306, v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = stack[-4];
    fn = elt(env, 11); /* plus!: */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    fn = elt(env, 12); /* times!: */
    v304 = (*qfn2(fn))(qenv(fn), stack[0], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    stack[0] = v304;
    v305 = stack[-5];
    v304 = stack[-1];
    v304 = (Lisp_Object)geq2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    v304 = v304 ? lisp_true : nil;
    env = stack[-6];
    if (v304 == nil) goto v133;
    v305 = stack[0];
    v304 = stack[-4];
    fn = elt(env, 13); /* difference!: */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    fn = elt(env, 14); /* abs!: */
    v305 = (*qfn1(fn))(qenv(fn), v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = stack[-2];
    fn = elt(env, 15); /* greaterp!: */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    if (!(v304 == nil)) goto v133;
    v304 = stack[-4];
    v304 = qcdr(v304);
    v304 = qcar(v304);
    v306 = v304;
    v305 = v306;
    v304 = (Lisp_Object)1; /* 0 */
    if (v305 == v304) goto v2;
    v305 = v306;
    v304 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 16); /* inorm */
    v304 = (*qfn2(fn))(qenv(fn), v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v306 = v304;
    stack[-1] = elt(env, 3); /* !:rd!: */
    v304 = v306;
    stack[0] = qcar(v304);
    v304 = v306;
    v305 = qcdr(v304);
    v304 = stack[-4];
    v304 = qcdr(v304);
    v304 = qcdr(v304);
    v304 = plus2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    {
        Lisp_Object v308 = stack[-1];
        Lisp_Object v173 = stack[0];
        popv(7);
        return list2star(v308, v173, v304);
    }

v2:
    v306 = elt(env, 3); /* !:rd!: */
    v305 = (Lisp_Object)1; /* 0 */
    v304 = (Lisp_Object)1; /* 0 */
    popv(7);
    return list2star(v306, v305, v304);

v133:
    v304 = stack[0];
    stack[-4] = v304;
    goto v25;

v279:
    stack[-5] = elt(env, 3); /* !:rd!: */
    stack[0] = (Lisp_Object)145; /* 9 */
    v305 = (Lisp_Object)81; /* 5 */
    v304 = stack[-4];
    v304 = qcdr(v304);
    v304 = qcar(v304);
    v304 = times2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v305 = plus2(stack[0], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = (Lisp_Object)161; /* 10 */
    stack[0] = quot2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = stack[-4];
    v304 = qcdr(v304);
    v304 = qcdr(v304);
    v305 = sub1(v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = (Lisp_Object)33; /* 2 */
    v304 = quot2(v305, v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    v304 = list2star(stack[-5], stack[0], v304);
    nil = C_nil;
    if (exception_pending()) goto v307;
    env = stack[-6];
    goto v43;
/* error exit handlers */
v307:
    popv(7);
    return nil;
}



/* Code for physop!*sq */

static Lisp_Object CC_physopHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v81;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physop*sq");
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
    v81 = qcar(v81);
    fn = elt(env, 3); /* !*q2a */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[0];
    fn = elt(env, 4); /* !*collectphysops */
    v81 = (*qfn1(fn))(qenv(fn), v81);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[0];
    if (v81 == nil) goto v72;
    v81 = elt(env, 2); /* physop */
    { popv(1); return onevalue(v81); }

v72:
    v81 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v81); }
/* error exit handlers */
v142:
    popv(1);
    return nil;
}



/* Code for mk!-coeff1 */

static Lisp_Object CC_mkKcoeff1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v44, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk-coeff1");
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
    v70 = v0;
/* end of prologue */
    v44 = v70;
    if (v44 == nil) goto v250;
    stack[-5] = elt(env, 1); /* times */
    v44 = v70;
    stack[-3] = v44;
    v44 = stack[-3];
    if (v44 == nil) goto v75;
    v44 = stack[-3];
    v44 = qcar(v44);
    v70 = qcar(v44);
    v44 = stack[-4];
    fn = elt(env, 3); /* getroad */
    v44 = (*qfn2(fn))(qenv(fn), v70, v44);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    fn = elt(env, 4); /* factorial */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v44 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    stack[-1] = v44;
    stack[-2] = v44;
    goto v89;

v89:
    v44 = stack[-3];
    v44 = qcdr(v44);
    stack[-3] = v44;
    v44 = stack[-3];
    if (v44 == nil) goto v122;
    stack[0] = stack[-1];
    v44 = stack[-3];
    v44 = qcar(v44);
    v70 = qcar(v44);
    v44 = stack[-4];
    fn = elt(env, 3); /* getroad */
    v44 = (*qfn2(fn))(qenv(fn), v70, v44);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    fn = elt(env, 4); /* factorial */
    v44 = (*qfn1(fn))(qenv(fn), v44);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v44 = ncons(v44);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v44 = Lrplacd(nil, stack[0], v44);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    v44 = stack[-1];
    v44 = qcdr(v44);
    stack[-1] = v44;
    goto v89;

v122:
    v44 = stack[-2];
    goto v141;

v141:
    v44 = cons(stack[-5], v44);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 5); /* eval */
        return (*qfn1(fn))(qenv(fn), v44);
    }

v75:
    v44 = qvalue(elt(env, 2)); /* nil */
    goto v141;

v250:
    v44 = (Lisp_Object)17; /* 1 */
    { popv(7); return onevalue(v44); }
/* error exit handlers */
v251:
    popv(7);
    return nil;
}



/* Code for chrstrem */

static Lisp_Object CC_chrstrem(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v311, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chrstrem");
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
    v311 = qvalue(elt(env, 1)); /* !*trwu */
    if (!(v311 == nil)) goto v69;
    v311 = qvalue(elt(env, 2)); /* !*trchrstrem */
    if (!(v311 == nil)) goto v69;

v48:
    v311 = stack[-3];
    fn = elt(env, 15); /* wusort */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[-3] = v311;
    v311 = qvalue(elt(env, 1)); /* !*trwu */
    if (!(v311 == nil)) goto v75;
    v311 = qvalue(elt(env, 2)); /* !*trchrstrem */
    if (!(v311 == nil)) goto v75;

v93:
    v311 = stack[-3];
    v311 = qcar(v311);
    fn = elt(env, 16); /* wuconstantp */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    if (v311 == nil) goto v205;
    v311 = qvalue(elt(env, 1)); /* !*trwu */
    if (v311 == nil) goto v206;
    v311 = elt(env, 7); /* "which is trivially trivial" */
    fn = elt(env, 17); /* prin2t!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    goto v206;

v206:
    v311 = elt(env, 8); /* inconsistent */
    stack[-2] = v311;
    v311 = (Lisp_Object)17; /* 1 */
    v311 = ncons(v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[-4] = v311;
    goto v247;

v247:
    v311 = qvalue(elt(env, 1)); /* !*trwu */
    if (v311 == nil) goto v117;
    v311 = stack[-2];
    if (!(v311 == nil)) goto v117;
    v311 = elt(env, 9); /* "A basic set is" */
    fn = elt(env, 17); /* prin2t!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = stack[-4];
    v311 = Lreverse(nil, v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[0] = v311;
    goto v227;

v227:
    v311 = stack[0];
    if (v311 == nil) goto v246;
    v311 = stack[0];
    v311 = qcar(v311);
    fn = elt(env, 18); /* printsf */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = stack[0];
    v311 = qcdr(v311);
    stack[0] = v311;
    goto v227;

v246:
    v311 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    goto v117;

v117:
    v167 = stack[-3];
    v311 = stack[-4];
    fn = elt(env, 20); /* setdiff */
    v311 = (*qfn2(fn))(qenv(fn), v167, v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[-1] = v311;
    goto v274;

v274:
    v311 = stack[-1];
    if (v311 == nil) goto v252;
    v311 = stack[-1];
    v311 = qcar(v311);
    stack[0] = v311;
    v167 = stack[-2];
    v311 = elt(env, 8); /* inconsistent */
    if (v167 == v311) goto v263;
    v311 = qvalue(elt(env, 1)); /* !*trwu */
    if (v311 == nil) goto v313;
    v311 = elt(env, 10); /* "The remainder of " */
    fn = elt(env, 21); /* prin2!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = stack[0];
    fn = elt(env, 18); /* printsf */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = elt(env, 11); /* "wrt the basic set is " */
    fn = elt(env, 21); /* prin2!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    goto v313;

v313:
    v167 = stack[0];
    v311 = stack[-4];
    fn = elt(env, 22); /* findremainder */
    v311 = (*qfn2(fn))(qenv(fn), v167, v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[0] = v311;
    v311 = qvalue(elt(env, 1)); /* !*trwu */
    if (v311 == nil) goto v182;
    v311 = stack[0];
    fn = elt(env, 18); /* printsf */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    goto v182;

v182:
    v311 = stack[0];
    if (v311 == nil) goto v263;
    v311 = stack[0];
    fn = elt(env, 16); /* wuconstantp */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    if (v311 == nil) goto v298;
    v311 = elt(env, 8); /* inconsistent */
    stack[-2] = v311;
    v311 = qvalue(elt(env, 1)); /* !*trwu */
    if (v311 == nil) goto v263;
    v311 = elt(env, 12); /* "which is a non-zero constant, and so" */
    fn = elt(env, 23); /* prin2t */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = elt(env, 13); /* "the equations are inconsistent." */
    fn = elt(env, 23); /* prin2t */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    goto v263;

v263:
    v311 = stack[-1];
    v311 = qcdr(v311);
    stack[-1] = v311;
    goto v274;

v298:
    v311 = stack[0];
    fn = elt(env, 24); /* absf */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v167 = ncons(v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = stack[-2];
    fn = elt(env, 25); /* union */
    v311 = (*qfn2(fn))(qenv(fn), v167, v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[-2] = v311;
    goto v263;

v252:
    v311 = stack[-2];
    if (v311 == nil) goto v96;
    v167 = stack[-2];
    v311 = elt(env, 8); /* inconsistent */
    if (v167 == v311) goto v96;
    v167 = stack[-3];
    v311 = stack[-2];
    v311 = Lappend(nil, v167, v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[-3] = v311;
    goto v96;

v96:
    v311 = stack[-2];
    if (v311 == nil) goto v15;
    v167 = stack[-2];
    v311 = elt(env, 8); /* inconsistent */
    if (!(v167 == v311)) goto v48;

v15:
    v167 = stack[-2];
    v311 = elt(env, 8); /* inconsistent */
    if (!(v167 == v311)) goto v237;
    v311 = (Lisp_Object)17; /* 1 */
    v311 = ncons(v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[-4] = v311;
    goto v237;

v237:
    v311 = qvalue(elt(env, 1)); /* !*trwu */
    if (!(v311 == nil)) goto v8;
    v311 = qvalue(elt(env, 2)); /* !*trchrstrem */
    if (!(v311 == nil)) goto v8;

v13:
    v311 = stack[-4];
    stack[-3] = v311;
    v311 = stack[-3];
    if (v311 == nil) goto v249;
    v311 = stack[-3];
    v311 = qcar(v311);
    fn = elt(env, 24); /* absf */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = ncons(v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[-1] = v311;
    stack[-2] = v311;
    goto v314;

v314:
    v311 = stack[-3];
    v311 = qcdr(v311);
    stack[-3] = v311;
    v311 = stack[-3];
    if (v311 == nil) goto v306;
    stack[0] = stack[-1];
    v311 = stack[-3];
    v311 = qcar(v311);
    fn = elt(env, 24); /* absf */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = ncons(v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = Lrplacd(nil, stack[0], v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = stack[-1];
    v311 = qcdr(v311);
    stack[-1] = v311;
    goto v314;

v306:
    v311 = stack[-2];
    goto v315;

v315:
        popv(6);
        return Lnreverse(nil, v311);

v249:
    v311 = qvalue(elt(env, 5)); /* nil */
    goto v315;

v8:
    v311 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = elt(env, 14); /* "The final characteristic set is:" */
    fn = elt(env, 17); /* prin2t!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = stack[-4];
    v311 = Lreverse(nil, v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    stack[0] = v311;
    goto v224;

v224:
    v311 = stack[0];
    if (v311 == nil) goto v13;
    v311 = stack[0];
    v311 = qcar(v311);
    fn = elt(env, 18); /* printsf */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = stack[0];
    v311 = qcdr(v311);
    stack[0] = v311;
    goto v224;

v205:
    v311 = qvalue(elt(env, 5)); /* nil */
    stack[-2] = v311;
    v311 = stack[-3];
    fn = elt(env, 26); /* pickbasicset */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = Lnreverse(nil, v311);
    env = stack[-5];
    stack[-4] = v311;
    goto v247;

v75:
    v311 = elt(env, 6); /* "The new pol-set in ascending order is" */
    fn = elt(env, 17); /* prin2t!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = stack[-3];
    stack[0] = v311;
    goto v76;

v76:
    v311 = stack[0];
    if (v311 == nil) goto v6;
    v311 = stack[0];
    v311 = qcar(v311);
    fn = elt(env, 18); /* printsf */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = stack[0];
    v311 = qcdr(v311);
    stack[0] = v311;
    goto v76;

v6:
    v311 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    goto v93;

v69:
    v311 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 19); /* terpri!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    v311 = elt(env, 4); /* "--------------------------------------------------------" 
*/
    fn = elt(env, 17); /* prin2t!* */
    v311 = (*qfn1(fn))(qenv(fn), v311);
    nil = C_nil;
    if (exception_pending()) goto v312;
    env = stack[-5];
    goto v48;
/* error exit handlers */
v312:
    popv(6);
    return nil;
}



/* Code for interglue */

static Lisp_Object MS_CDECL CC_interglue(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v95, Lisp_Object v87, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v166, v326;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "interglue");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for interglue");
#endif
    if (stack >= stacklimit)
    {
        push4(v87,v95,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v95,v87);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v87;
    stack[-2] = v95;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v166 = stack[-4];
    if (v166 == nil) goto v119;
    v166 = stack[-3];
    if (v166 == nil) goto v119;
    v166 = stack[-4];
    if (!(!consp(v166))) goto v119;
    v166 = stack[-3];
    if (!(!consp(v166))) goto v119;
    v326 = stack[-4];
    v166 = elt(env, 2); /* class */
    v166 = get(v326, v166);
    env = stack[-6];
    stack[0] = v166;
    v326 = stack[-3];
    v166 = elt(env, 2); /* class */
    v166 = get(v326, v166);
    env = stack[-6];
    v326 = stack[0];
    v166 = get(v326, v166);
    env = stack[-6];
    stack[-5] = v166;
    v166 = stack[-5];
    if (v166 == nil) goto v123;
    v326 = stack[-4];
    v166 = elt(env, 3); /* !\co!  */
    if (v326 == v166) goto v71;
    v326 = stack[-5];
    v166 = (Lisp_Object)1; /* 0 */
    v166 = (Lisp_Object)lessp2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    v166 = v166 ? lisp_true : nil;
    env = stack[-6];
    if (v166 == nil) goto v275;
    v326 = stack[-2];
    v166 = (Lisp_Object)1; /* 0 */
    v166 = (Lisp_Object)greaterp2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    v166 = v166 ? lisp_true : nil;
    env = stack[-6];
    if (v166 == nil) goto v270;
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v166); }

v270:
    v166 = stack[-5];
    v166 = negate(v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-6];
    stack[-5] = v166;
    goto v275;

v275:
    v326 = stack[-5];
    v166 = (Lisp_Object)17; /* 1 */
    if (v326 == v166) goto v117;
    v326 = stack[-5];
    v166 = (Lisp_Object)33; /* 2 */
    if (v326 == v166) goto v105;
    v326 = stack[-5];
    v166 = (Lisp_Object)49; /* 3 */
    if (v326 == v166) goto v328;
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v166); }

v328:
    stack[0] = (Lisp_Object)10485761; /* 655360 */
    v326 = stack[-1];
    v166 = (Lisp_Object)161; /* 10 */
    v326 = times2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-6];
    v166 = (Lisp_Object)801; /* 50 */
    v166 = difference2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    {
        Lisp_Object v329 = stack[0];
        popv(7);
        return list2(v329, v166);
    }

v105:
    v326 = stack[-4];
    v166 = elt(env, 4); /* !+ */
    if (v326 == v166) goto v261;
    v326 = stack[-4];
    v166 = elt(env, 5); /* !- */
    if (v326 == v166) goto v261;
    v326 = stack[-3];
    v166 = elt(env, 4); /* !+ */
    if (v326 == v166) goto v193;
    v326 = stack[-3];
    v166 = elt(env, 5); /* !- */
    if (!(v326 == v166)) goto v295;
    v326 = stack[0];
    v166 = elt(env, 6); /* ord */
    if (v326 == v166) goto v136;
    v326 = stack[0];
    v166 = elt(env, 7); /* clo */
    if (!(v326 == v166)) goto v295;

v136:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v326 = stack[-1];
    v166 = (Lisp_Object)481; /* 30 */
    v326 = times2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-6];
    v166 = (Lisp_Object)3361; /* 210 */
    v166 = difference2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    {
        Lisp_Object v330 = stack[0];
        popv(7);
        return list2(v330, v166);
    }

v295:
    v326 = stack[-4];
    v166 = elt(env, 8); /* !\cdot!  */
    if (v326 == v166) goto v331;
    v326 = stack[-3];
    v166 = elt(env, 8); /* !\cdot!  */
    if (v326 == v166) goto v177;
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v326 = stack[-1];
    v166 = (Lisp_Object)161; /* 10 */
    v166 = times2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    {
        Lisp_Object v332 = stack[0];
        popv(7);
        return list2(v332, v166);
    }

v177:
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v166); }

v331:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v326 = stack[-1];
    v166 = (Lisp_Object)161; /* 10 */
    v326 = times2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-6];
    v166 = (Lisp_Object)801; /* 50 */
    v166 = plus2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    {
        Lisp_Object v333 = stack[0];
        popv(7);
        return list2(v333, v166);
    }

v193:
    stack[0] = (Lisp_Object)2621441; /* 163840 */
    v326 = stack[-1];
    v166 = (Lisp_Object)481; /* 30 */
    v326 = times2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-6];
    v166 = (Lisp_Object)6241; /* 390 */
    v166 = difference2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    {
        Lisp_Object v334 = stack[0];
        popv(7);
        return list2(v334, v166);
    }

v261:
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v166); }

v117:
    stack[0] = (Lisp_Object)1295361; /* 80960 */
    v326 = stack[-1];
    v166 = (Lisp_Object)161; /* 10 */
    v326 = times2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    env = stack[-6];
    v166 = (Lisp_Object)321; /* 20 */
    v166 = plus2(v326, v166);
    nil = C_nil;
    if (exception_pending()) goto v327;
    {
        Lisp_Object v335 = stack[0];
        popv(7);
        return list2(v335, v166);
    }

v71:
    v326 = (Lisp_Object)1; /* 0 */
    v166 = (Lisp_Object)-159999; /* -10000 */
    popv(7);
    return list2(v326, v166);

v123:
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v166); }

v119:
    v166 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v166); }
/* error exit handlers */
v327:
    popv(7);
    return nil;
}



/* Code for xpdiff */

static Lisp_Object CC_xpdiff(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v336, v289;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpdiff");
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
    v336 = stack[-1];
    if (v336 == nil) goto v250;
    v336 = stack[0];
    if (v336 == nil) goto v81;
    v336 = stack[0];
    v289 = qcar(v336);
    v336 = stack[-1];
    v336 = qcar(v336);
    v336 = (Lisp_Object)greaterp2(v289, v336);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v336 = v336 ? lisp_true : nil;
    env = stack[-3];
    if (v336 == nil) goto v76;
    v336 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v336); }

v76:
    v336 = stack[-1];
    v289 = qcdr(v336);
    v336 = stack[0];
    v336 = qcdr(v336);
    v336 = CC_xpdiff(env, v289, v336);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-3];
    stack[-2] = v336;
    v289 = stack[-2];
    v336 = elt(env, 4); /* failed */
    if (v289 == v336) goto v123;
    v336 = stack[-1];
    v289 = qcar(v336);
    v336 = stack[0];
    v336 = qcar(v336);
    v289 = difference2(v289, v336);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v336 = stack[-2];
    popv(4);
    return cons(v289, v336);

v123:
    v336 = elt(env, 4); /* failed */
    { popv(4); return onevalue(v336); }

v81:
    v336 = elt(env, 3); /* "A too long in xpdiff" */
    {
        popv(4);
        fn = elt(env, 5); /* interr */
        return (*qfn1(fn))(qenv(fn), v336);
    }

v250:
    v336 = stack[0];
    if (v336 == nil) goto v69;
    v336 = elt(env, 2); /* "B too long in xpdiff" */
    {
        popv(4);
        fn = elt(env, 5); /* interr */
        return (*qfn1(fn))(qenv(fn), v336);
    }

v69:
    v336 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v336); }
/* error exit handlers */
v251:
    popv(4);
    return nil;
}



setup_type const u40_setup[] =
{
    {"simprad",                 too_few_2,      CC_simprad,    wrong_no_2},
    {"get-new-prime",           CC_getKnewKprime,too_many_1,   wrong_no_1},
    {"bfprin0x",                too_few_2,      CC_bfprin0x,   wrong_no_2},
    {"lto_insert",              too_few_2,      CC_lto_insert, wrong_no_2},
    {"let3",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_let3},
    {"*invsq",                  CC_Hinvsq,      too_many_1,    wrong_no_1},
    {"dipcontenti1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_dipcontenti1},
    {"vevzero?1",               CC_vevzeroW1,   too_many_1,    wrong_no_1},
    {"xregister_wedge_pair",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_xregister_wedge_pair},
    {"rand-mons-dense",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_randKmonsKdense},
    {"exp:",                    too_few_2,      CC_expT,       wrong_no_2},
    {"atlas_edges",             CC_atlas_edges, too_many_1,    wrong_no_1},
    {"rlval",                   too_few_2,      CC_rlval,      wrong_no_2},
    {"mkcrn",                   too_few_2,      CC_mkcrn,      wrong_no_2},
    {"remove_root_item",        CC_remove_root_item,too_many_1,wrong_no_1},
    {"latexprint",              CC_latexprint,  too_many_1,    wrong_no_1},
    {"rtrnda",                  too_few_2,      CC_rtrnda,     wrong_no_2},
    {"forttab",                 CC_forttab,     too_many_1,    wrong_no_1},
    {"tot-asym-indp",           CC_totKasymKindp,too_many_1,   wrong_no_1},
    {"mk-strand-vertex",        too_few_2,      CC_mkKstrandKvertex,wrong_no_2},
    {"cdr_signsort",            too_few_2,      CC_cdr_signsort,wrong_no_2},
    {"makeupsf",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeupsf},
    {"cgp_greenp",              CC_cgp_greenp,  too_many_1,    wrong_no_1},
    {"getvariables",            CC_getvariables,too_many_1,    wrong_no_1},
    {"codfac",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_codfac},
    {"copyd",                   too_few_2,      CC_copyd,      wrong_no_2},
    {"column_dim",              CC_column_dim,  too_many_1,    wrong_no_1},
    {"groebsaveltermbc",        CC_groebsaveltermbc,too_many_1,wrong_no_1},
    {"weak_xreduce",            too_few_2,      CC_weak_xreduce,wrong_no_2},
    {"bfsqrt",                  CC_bfsqrt,      too_many_1,    wrong_no_1},
    {"physop*sq",               CC_physopHsq,   too_many_1,    wrong_no_1},
    {"mk-coeff1",               too_few_2,      CC_mkKcoeff1,  wrong_no_2},
    {"chrstrem",                CC_chrstrem,    too_many_1,    wrong_no_1},
    {"interglue",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_interglue},
    {"xpdiff",                  too_few_2,      CC_xpdiff,     wrong_no_2},
    {NULL, (one_args *)"u40", (two_args *)"7158 1711855 8465897", 0}
};

/* end of generated code */
