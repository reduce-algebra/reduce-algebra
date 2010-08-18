
/* $destdir/generated-c\u35.c Machine generated C code */

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


/* Code for cl_apply2ats1 */

static Lisp_Object MS_CDECL CC_cl_apply2ats1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_apply2ats1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_apply2ats1");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v2;
    stack[-5] = v1;
    stack[-1] = v0;
/* end of prologue */
    v64 = stack[-1];
    if (!consp(v64)) goto v67;
    v64 = stack[-1];
    v64 = qcar(v64);
    goto v68;

v68:
    v66 = v64;
    v65 = v66;
    v64 = elt(env, 1); /* true */
    if (v65 == v64) { Lisp_Object res = stack[-1]; popv(8); return onevalue(res); }
    v65 = v66;
    v64 = elt(env, 2); /* false */
    if (v65 == v64) { Lisp_Object res = stack[-1]; popv(8); return onevalue(res); }
    v65 = v66;
    v64 = elt(env, 3); /* ex */
    if (v65 == v64) goto v69;
    v65 = v66;
    v64 = elt(env, 4); /* all */
    if (v65 == v64) goto v69;
    v65 = v66;
    v64 = elt(env, 5); /* bex */
    if (v65 == v64) goto v70;
    v65 = v66;
    v64 = elt(env, 6); /* ball */
    if (v65 == v64) goto v70;
    v65 = v66;
    v64 = elt(env, 7); /* or */
    if (v65 == v64) goto v71;
    v65 = v66;
    v64 = elt(env, 8); /* and */
    if (v65 == v64) goto v71;
    v65 = v66;
    v64 = elt(env, 9); /* not */
    if (v65 == v64) goto v71;
    v65 = v66;
    v64 = elt(env, 10); /* impl */
    if (v65 == v64) goto v71;
    v65 = v66;
    v64 = elt(env, 11); /* repl */
    if (v65 == v64) goto v71;
    v65 = v66;
    v64 = elt(env, 12); /* equiv */
    if (v65 == v64) goto v71;
    stack[0] = stack[-5];
    v65 = stack[-1];
    v64 = stack[-4];
    v64 = cons(v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    {
        Lisp_Object v73 = stack[0];
        popv(8);
        fn = elt(env, 14); /* apply */
        return (*qfn2(fn))(qenv(fn), v73, v64);
    }

v71:
    stack[-6] = v66;
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[-3] = v64;
    v64 = stack[-3];
    if (v64 == nil) goto v74;
    v64 = stack[-3];
    v64 = qcar(v64);
    v66 = v64;
    v65 = stack[-5];
    v64 = stack[-4];
    v64 = CC_cl_apply2ats1(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    v64 = ncons(v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    stack[-1] = v64;
    stack[-2] = v64;
    goto v75;

v75:
    v64 = stack[-3];
    v64 = qcdr(v64);
    stack[-3] = v64;
    v64 = stack[-3];
    if (v64 == nil) goto v76;
    stack[0] = stack[-1];
    v64 = stack[-3];
    v64 = qcar(v64);
    v66 = v64;
    v65 = stack[-5];
    v64 = stack[-4];
    v64 = CC_cl_apply2ats1(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    v64 = ncons(v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    v64 = Lrplacd(nil, stack[0], v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[-1] = v64;
    goto v75;

v76:
    v64 = stack[-2];
    goto v77;

v77:
    {
        Lisp_Object v78 = stack[-6];
        popv(8);
        return cons(v78, v64);
    }

v74:
    v64 = qvalue(elt(env, 13)); /* nil */
    goto v77;

v70:
    stack[-3] = v66;
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[-2] = qcar(v64);
    v64 = stack[-1];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v66 = qcar(v64);
    v65 = stack[-5];
    v64 = stack[-4];
    stack[0] = CC_cl_apply2ats1(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-7];
    v64 = stack[-1];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v66 = qcar(v64);
    v65 = stack[-5];
    v64 = stack[-4];
    v64 = CC_cl_apply2ats1(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    {
        Lisp_Object v79 = stack[-3];
        Lisp_Object v80 = stack[-2];
        Lisp_Object v81 = stack[0];
        popv(8);
        return list4(v79, v80, v81, v64);
    }

v69:
    stack[-2] = v66;
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[0] = qcar(v64);
    v64 = stack[-1];
    v64 = qcdr(v64);
    v64 = qcdr(v64);
    v66 = qcar(v64);
    v65 = stack[-5];
    v64 = stack[-4];
    v64 = CC_cl_apply2ats1(env, 3, v66, v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v72;
    {
        Lisp_Object v82 = stack[-2];
        Lisp_Object v83 = stack[0];
        popv(8);
        return list3(v82, v83, v64);
    }

v67:
    v64 = stack[-1];
    goto v68;
/* error exit handlers */
v72:
    popv(8);
    return nil;
}



/* Code for depend!-p */

static Lisp_Object CC_dependKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v94, v95, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for depend-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v95 = v1;
    v96 = v0;
/* end of prologue */
    v94 = v96;
    v93 = v95;
    if (v94 == v93) goto v97;
    v93 = v96;
    if (!consp(v93)) goto v98;
    v93 = v96;
    v93 = qcar(v93);
    if (!consp(v93)) goto v99;
    v93 = v96;
    v94 = v95;
    {
        fn = elt(env, 4); /* depend!-f */
        return (*qfn2(fn))(qenv(fn), v93, v94);
    }

v99:
    v93 = v96;
    v94 = qcar(v93);
    v93 = elt(env, 3); /* !*sq */
    if (v94 == v93) goto v100;
    v93 = v96;
    v93 = qcdr(v93);
    v94 = v95;
    {
        fn = elt(env, 5); /* depend!-l */
        return (*qfn2(fn))(qenv(fn), v93, v94);
    }

v100:
    v93 = v96;
    v93 = qcdr(v93);
    v93 = qcar(v93);
    v94 = v95;
    {
        fn = elt(env, 6); /* depend!-sq */
        return (*qfn2(fn))(qenv(fn), v93, v94);
    }

v98:
    v93 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v93);

v97:
    v93 = qvalue(elt(env, 1)); /* t */
    return onevalue(v93);
}



/* Code for gb_buch!-ev_divides!? */

static Lisp_Object CC_gb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gb_buch-ev_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v91 = v1;
    v102 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v91, v102);
    }
}



/* Code for copy_vect */

static Lisp_Object CC_copy_vect(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v86, v108, v109;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copy_vect");
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
    v57 = stack[-1];
    v57 = Lupbv(nil, v57);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    stack[-3] = v57;
    v57 = (Lisp_Object)1; /* 0 */
    stack[0] = v57;
    goto v110;

v110:
    v86 = stack[-3];
    v57 = stack[0];
    v57 = difference2(v86, v57);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    v57 = Lminusp(nil, v57);
    env = stack[-4];
    if (v57 == nil) goto v90;
    v57 = nil;
    { popv(5); return onevalue(v57); }

v90:
    v109 = stack[-2];
    v108 = stack[0];
    v86 = stack[-1];
    v57 = stack[0];
    v57 = *(Lisp_Object *)((char *)v86 + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL)));
    *(Lisp_Object *)((char *)v109 + (CELL-TAG_VECTOR) + ((int32_t)v108/(16/CELL))) = v57;
    v57 = stack[0];
    v57 = add1(v57);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-4];
    stack[0] = v57;
    goto v110;
/* error exit handlers */
v55:
    popv(5);
    return nil;
}



/* Code for nestzerop!: */

static Lisp_Object CC_nestzeropT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nestzerop:");
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
    v112 = v0;
/* end of prologue */
    v111 = v112;
    v111 = integerp(v111);
    if (v111 == nil) goto v101;
    v111 = v112;
    fn = elt(env, 1); /* simp */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    errexit();
    goto v113;

v113:
    v111 = qcar(v111);
    v111 = (v111 == nil ? lisp_true : nil);
    return onevalue(v111);

v101:
    v111 = v112;
    v111 = qcdr(v111);
    v111 = qcdr(v111);
    v111 = qcdr(v111);
    goto v113;
}



/* Code for fortassign */

static Lisp_Object CC_fortassign(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v115;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortassign");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v98 = v0;
/* end of prologue */
    v115 = v98;
    v115 = qcdr(v115);
    v115 = qcar(v115);
    v98 = qcdr(v98);
    v98 = qcdr(v98);
    v98 = qcar(v98);
    {
        fn = elt(env, 1); /* mkffortassign */
        return (*qfn2(fn))(qenv(fn), v115, v98);
    }
}



/* Code for mk_names_map_2 */

static Lisp_Object CC_mk_names_map_2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v117, v118;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_names_map_2");
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
    v117 = v0;
/* end of prologue */
    v118 = v117;
    v118 = qcar(v118);
    v117 = qcdr(v117);
    v117 = Lappend(nil, v118, v117);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-3] = v117;
    v117 = stack[-3];
    if (v117 == nil) goto v119;
    v117 = stack[-3];
    v117 = qcar(v117);
    v117 = qcar(v117);
    v117 = ncons(v117);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    stack[-1] = v117;
    stack[-2] = v117;
    goto v63;

v63:
    v117 = stack[-3];
    v117 = qcdr(v117);
    stack[-3] = v117;
    v117 = stack[-3];
    if (v117 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v117 = stack[-3];
    v117 = qcar(v117);
    v117 = qcar(v117);
    v117 = ncons(v117);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v117 = Lrplacd(nil, stack[0], v117);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-4];
    v117 = stack[-1];
    v117 = qcdr(v117);
    stack[-1] = v117;
    goto v63;

v119:
    v117 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v117); }
/* error exit handlers */
v69:
    popv(5);
    return nil;
}



/* Code for fs!:prin!: */

static Lisp_Object CC_fsTprinT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prin:");
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
    v67 = elt(env, 1); /* "[" */
    fn = elt(env, 3); /* prin2!* */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v67 = stack[0];
    v67 = qcdr(v67);
    fn = elt(env, 4); /* fs!:prin */
    v67 = (*qfn1(fn))(qenv(fn), v67);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[-1];
    v67 = elt(env, 2); /* "]" */
    {
        popv(2);
        fn = elt(env, 3); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v67);
    }
/* error exit handlers */
v102:
    popv(2);
    return nil;
}



/* Code for lf!=zero */

static Lisp_Object CC_lfMzero(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lf=zero");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v97 = v0;
/* end of prologue */
    v97 = qcdr(v97);
    v97 = (v97 == nil ? lisp_true : nil);
    return onevalue(v97);
}



/* Code for make!-x!-to!-p */

static Lisp_Object MS_CDECL CC_makeKxKtoKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v151, v21, v152, v153, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-x-to-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-x-to-p");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v21 = stack[-2];
    v151 = qvalue(elt(env, 1)); /* dpoly */
    if (((int32_t)(v21)) < ((int32_t)(v151))) goto v101;
    v21 = stack[-2];
    v151 = (Lisp_Object)33; /* 2 */
    v152 = quot2(v21, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v21 = stack[-1];
    v151 = stack[0];
    v151 = CC_makeKxKtoKp(env, 3, v152, v21, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v154 = stack[0];
    v153 = v151;
    v152 = stack[0];
    v21 = v151;
    v151 = stack[-1];
    fn = elt(env, 4); /* times!-in!-vector */
    v151 = (*qfnn(fn))(qenv(fn), 5, v154, v153, v152, v21, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[-3] = v151;
    v153 = stack[-1];
    v152 = stack[-3];
    v21 = qvalue(elt(env, 3)); /* poly!-vector */
    v151 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v151 = (*qfnn(fn))(qenv(fn), 4, v153, v152, v21, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[-3] = v151;
    v21 = stack[-2];
    v151 = (Lisp_Object)33; /* 2 */
    v21 = Liremainder(nil, v21, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v151 = (Lisp_Object)1; /* 0 */
    if (v21 == v151) goto v156;
    v151 = stack[-3];
    v154 = v151;
    goto v37;

v37:
    v151 = v154;
    v151 = ((intptr_t)(v151) < 0 ? lisp_true : nil);
    if (v151 == nil) goto v157;
    v152 = stack[-1];
    v21 = (Lisp_Object)1; /* 0 */
    v151 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v152 + (CELL-TAG_VECTOR) + ((int32_t)v21/(16/CELL))) = v151;
    v153 = stack[-1];
    v151 = stack[-3];
    v152 = (Lisp_Object)((int32_t)(v151) + 0x10);
    v21 = qvalue(elt(env, 3)); /* poly!-vector */
    v151 = qvalue(elt(env, 1)); /* dpoly */
    fn = elt(env, 5); /* remainder!-in!-vector */
    v151 = (*qfnn(fn))(qenv(fn), 4, v153, v152, v21, v151);
    nil = C_nil;
    if (exception_pending()) goto v155;
    stack[-3] = v151;
    goto v156;

v156:
    v151 = (Lisp_Object)1; /* 0 */
    v154 = v151;
    goto v158;

v158:
    v21 = stack[-3];
    v151 = v154;
    v151 = (Lisp_Object)(int32_t)((int32_t)v21 - (int32_t)v151 + TAG_FIXNUM);
    v151 = ((intptr_t)(v151) < 0 ? lisp_true : nil);
    if (!(v151 == nil)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v153 = stack[0];
    v152 = v154;
    v21 = stack[-1];
    v151 = v154;
    v151 = *(Lisp_Object *)((char *)v21 + (CELL-TAG_VECTOR) + ((int32_t)v151/(16/CELL)));
    *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v152/(16/CELL))) = v151;
    v151 = v154;
    v151 = (Lisp_Object)((int32_t)(v151) + 0x10);
    v154 = v151;
    goto v158;

v157:
    v153 = stack[-1];
    v151 = v154;
    v152 = (Lisp_Object)((int32_t)(v151) + 0x10);
    v21 = stack[-1];
    v151 = v154;
    v151 = *(Lisp_Object *)((char *)v21 + (CELL-TAG_VECTOR) + ((int32_t)v151/(16/CELL)));
    *(Lisp_Object *)((char *)v153 + (CELL-TAG_VECTOR) + ((int32_t)v152/(16/CELL))) = v151;
    v151 = v154;
    v151 = (Lisp_Object)((int32_t)(v151) - 0x10);
    v154 = v151;
    goto v37;

v101:
    v151 = (Lisp_Object)1; /* 0 */
    v153 = v151;
    goto v61;

v61:
    v151 = stack[-2];
    v21 = (Lisp_Object)((int32_t)(v151) - 0x10);
    v151 = v153;
    v151 = (Lisp_Object)(int32_t)((int32_t)v21 - (int32_t)v151 + TAG_FIXNUM);
    v151 = ((intptr_t)(v151) < 0 ? lisp_true : nil);
    if (v151 == nil) goto v87;
    v152 = stack[0];
    v21 = stack[-2];
    v151 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v152 + (CELL-TAG_VECTOR) + ((int32_t)v21/(16/CELL))) = v151;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

v87:
    v152 = stack[0];
    v21 = v153;
    v151 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v152 + (CELL-TAG_VECTOR) + ((int32_t)v21/(16/CELL))) = v151;
    v151 = v153;
    v151 = (Lisp_Object)((int32_t)(v151) + 0x10);
    v153 = v151;
    goto v61;
/* error exit handlers */
v155:
    popv(5);
    return nil;
}



/* Code for mktag */

static Lisp_Object MS_CDECL CC_mktag(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v166, v167;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktag");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktag");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v1;
    v165 = v0;
/* end of prologue */
    v166 = v165;
    if (v166 == nil) goto v168;
    v166 = v165;
    if (!consp(v166)) goto v101;
    v166 = v165;
    v167 = qcar(v166);
    v166 = elt(env, 2); /* texprec */
    v166 = get(v167, v166);
    env = stack[-4];
    if (!(v166 == nil)) goto v110;
    v166 = (Lisp_Object)15985; /* 999 */
    goto v110;

v110:
    stack[-3] = v166;
    v166 = v165;
    v167 = qcar(v166);
    v166 = qcdr(v165);
    v165 = stack[-3];
    fn = elt(env, 5); /* makefunc */
    v165 = (*qfnn(fn))(qenv(fn), 3, v167, v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    stack[0] = v165;
    v165 = stack[-1];
    if (v165 == nil) goto v95;
    v166 = stack[-2];
    v165 = stack[-3];
    if (!(equal(v166, v165))) goto v95;

v144:
    v166 = elt(env, 3); /* !\!( */
    v165 = stack[0];
    stack[0] = cons(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v165 = elt(env, 4); /* !\!) */
    v165 = ncons(v165);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[-4];
    v165 = Lnconc(nil, stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v47;
    stack[0] = v165;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v95:
    v166 = stack[-3];
    v165 = stack[-2];
    v165 = (Lisp_Object)lessp2(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v47;
    v165 = v165 ? lisp_true : nil;
    env = stack[-4];
    if (v165 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    else goto v144;

v101:
    {
        popv(5);
        fn = elt(env, 6); /* texexplode */
        return (*qfn1(fn))(qenv(fn), v165);
    }

v168:
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v165); }
/* error exit handlers */
v47:
    popv(5);
    return nil;
}



/* Code for get_dimension_in */

static Lisp_Object CC_get_dimension_in(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v114, v98;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_dimension_in");
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
    v114 = v0;
/* end of prologue */
    v98 = elt(env, 1); /* id */
    fn = elt(env, 2); /* get_rep_matrix_in */
    v114 = (*qfn2(fn))(qenv(fn), v98, v114);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[0];
    fn = elt(env, 3); /* mk!+trace */
    v114 = (*qfn1(fn))(qenv(fn), v114);
    nil = C_nil;
    if (exception_pending()) goto v115;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* change!+sq!+to!+int */
        return (*qfn1(fn))(qenv(fn), v114);
    }
/* error exit handlers */
v115:
    popv(1);
    return nil;
}



/* Code for rl_surep */

static Lisp_Object CC_rl_surep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_surep");
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
    v111 = v1;
    v112 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_surep!* */
    v111 = list2(v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v162;
    env = stack[-1];
    {
        Lisp_Object v110 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v110, v111);
    }
/* error exit handlers */
v162:
    popv(2);
    return nil;
}



/* Code for vdpcleanup */

static Lisp_Object MS_CDECL CC_vdpcleanup(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vdpcleanup");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpcleanup");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v113 = qvalue(elt(env, 1)); /* nil */
    v113 = ncons(v113);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[0];
    qvalue(elt(env, 2)) = v113; /* dipevlist!* */
    { popv(1); return onevalue(v113); }
/* error exit handlers */
v22:
    popv(1);
    return nil;
}



/* Code for gfquotient */

static Lisp_Object CC_gfquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v61, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfquotient");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v61 = v1;
    v89 = v0;
/* end of prologue */
    v62 = v89;
    v62 = qcar(v62);
    if (!consp(v62)) goto v101;
    v62 = v89;
    {
        fn = elt(env, 1); /* gbfquot */
        return (*qfn2(fn))(qenv(fn), v62, v61);
    }

v101:
    v62 = v89;
    {
        fn = elt(env, 2); /* gffquot */
        return (*qfn2(fn))(qenv(fn), v62, v61);
    }
}



/* Code for symmetrize!-inds */

static Lisp_Object CC_symmetrizeKinds(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v187;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symmetrize-inds");
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
    v186 = (Lisp_Object)1; /* 0 */
    stack[-10] = v186;
    v186 = stack[-9];
    stack[-7] = v186;
    v186 = stack[-7];
    if (v186 == nil) goto v112;
    v186 = stack[-7];
    v186 = qcar(v186);
    v187 = v186;
    if (!consp(v187)) goto v99;
    stack[-3] = v186;
    v186 = stack[-3];
    if (v186 == nil) goto v108;
    v186 = stack[-3];
    v186 = qcar(v186);
    v187 = stack[-8];
    fn = elt(env, 2); /* nth */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    stack[-1] = v186;
    stack[-2] = v186;
    goto v149;

v149:
    v186 = stack[-3];
    v186 = qcdr(v186);
    stack[-3] = v186;
    v186 = stack[-3];
    if (v186 == nil) goto v189;
    stack[0] = stack[-1];
    v186 = stack[-3];
    v186 = qcar(v186);
    v187 = stack[-8];
    fn = elt(env, 2); /* nth */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = Lrplacd(nil, stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = stack[-1];
    v186 = qcdr(v186);
    stack[-1] = v186;
    goto v149;

v189:
    v186 = stack[-2];
    goto v61;

v61:
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    stack[-5] = v186;
    stack[-6] = v186;
    goto v98;

v98:
    v186 = stack[-7];
    v186 = qcdr(v186);
    stack[-7] = v186;
    v186 = stack[-7];
    if (v186 == nil) goto v190;
    stack[-4] = stack[-5];
    v186 = stack[-7];
    v186 = qcar(v186);
    v187 = v186;
    if (!consp(v187)) goto v191;
    stack[-3] = v186;
    v186 = stack[-3];
    if (v186 == nil) goto v192;
    v186 = stack[-3];
    v186 = qcar(v186);
    v187 = stack[-8];
    fn = elt(env, 2); /* nth */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    stack[-1] = v186;
    stack[-2] = v186;
    goto v193;

v193:
    v186 = stack[-3];
    v186 = qcdr(v186);
    stack[-3] = v186;
    v186 = stack[-3];
    if (v186 == nil) goto v34;
    stack[0] = stack[-1];
    v186 = stack[-3];
    v186 = qcar(v186);
    v187 = stack[-8];
    fn = elt(env, 2); /* nth */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = Lrplacd(nil, stack[0], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = stack[-1];
    v186 = qcdr(v186);
    stack[-1] = v186;
    goto v193;

v34:
    v186 = stack[-2];
    goto v194;

v194:
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = Lrplacd(nil, stack[-4], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = stack[-5];
    v186 = qcdr(v186);
    stack[-5] = v186;
    goto v98;

v192:
    v186 = qvalue(elt(env, 1)); /* nil */
    goto v194;

v191:
    v187 = stack[-8];
    fn = elt(env, 2); /* nth */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    goto v194;

v190:
    v186 = stack[-6];
    goto v114;

v114:
    stack[-5] = v186;
    v186 = stack[-5];
    v186 = qcar(v186);
    if (!consp(v186)) goto v195;
    v186 = stack[-5];
    fn = elt(env, 3); /* indordln */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    fn = elt(env, 4); /* flatindl */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    goto v196;

v196:
    stack[0] = v186;
    v186 = stack[-9];
    v186 = qcar(v186);
    if (!consp(v186)) goto v8;
    v186 = stack[-9];
    fn = elt(env, 4); /* flatindl */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    stack[-9] = v186;
    goto v8;

v8:
    v187 = stack[-9];
    v186 = stack[0];
    fn = elt(env, 5); /* pair */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    stack[-5] = v186;
    stack[-6] = (Lisp_Object)17; /* 1 */
    v186 = stack[-8];
    stack[-7] = v186;
    v186 = stack[-7];
    if (v186 == nil) goto v197;
    v186 = stack[-7];
    v186 = qcar(v186);
    stack[-1] = v186;
    v186 = stack[-5];
    if (v186 == nil) goto v198;
    v186 = stack[-5];
    v186 = qcar(v186);
    stack[0] = qcar(v186);
    v186 = stack[-10];
    v186 = add1(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    stack[-10] = v186;
    if (!(equal(stack[0], v186))) goto v198;
    v186 = stack[-5];
    v186 = qcar(v186);
    v186 = qcdr(v186);
    v187 = v186;
    v186 = stack[-5];
    v186 = qcdr(v186);
    stack[-5] = v186;
    v186 = v187;
    goto v199;

v199:
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    stack[-3] = v186;
    stack[-4] = v186;
    goto v152;

v152:
    v186 = stack[-7];
    v186 = qcdr(v186);
    stack[-7] = v186;
    v186 = stack[-7];
    if (v186 == nil) goto v200;
    stack[-2] = stack[-3];
    v186 = stack[-7];
    v186 = qcar(v186);
    stack[-1] = v186;
    v186 = stack[-5];
    if (v186 == nil) goto v201;
    v186 = stack[-5];
    v186 = qcar(v186);
    stack[0] = qcar(v186);
    v186 = stack[-10];
    v186 = add1(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    stack[-10] = v186;
    if (!(equal(stack[0], v186))) goto v201;
    v186 = stack[-5];
    v186 = qcar(v186);
    v186 = qcdr(v186);
    v187 = v186;
    v186 = stack[-5];
    v186 = qcdr(v186);
    stack[-5] = v186;
    v186 = v187;
    goto v64;

v64:
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = Lrplacd(nil, stack[-2], v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    v186 = stack[-3];
    v186 = qcdr(v186);
    stack[-3] = v186;
    goto v152;

v201:
    v186 = stack[-1];
    goto v64;

v200:
    v186 = stack[-4];
    goto v74;

v74:
    {
        Lisp_Object v202 = stack[-6];
        popv(12);
        return cons(v202, v186);
    }

v198:
    v186 = stack[-1];
    goto v199;

v197:
    v186 = qvalue(elt(env, 1)); /* nil */
    goto v74;

v195:
    v186 = stack[-5];
    fn = elt(env, 6); /* indordn */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    goto v196;

v108:
    v186 = qvalue(elt(env, 1)); /* nil */
    goto v61;

v99:
    v187 = stack[-8];
    fn = elt(env, 2); /* nth */
    v186 = (*qfn2(fn))(qenv(fn), v187, v186);
    nil = C_nil;
    if (exception_pending()) goto v188;
    env = stack[-11];
    goto v61;

v112:
    v186 = qvalue(elt(env, 1)); /* nil */
    goto v114;
/* error exit handlers */
v188:
    popv(12);
    return nil;
}



/* Code for dv_skelsplit */

static Lisp_Object CC_dv_skelsplit(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v229, v230, v231;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_skelsplit");
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
    stack[-9] = v0;
/* end of prologue */
    v229 = (Lisp_Object)1; /* 0 */
    stack[-5] = v229;
    v229 = stack[-9];
    fn = elt(env, 10); /* listp */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    if (v229 == nil) goto v111;
    v229 = stack[-9];
    v230 = qcar(v229);
    v229 = elt(env, 3); /* symtree */
    v229 = get(v230, v229);
    env = stack[-11];
    stack[-10] = v229;
    v229 = stack[-10];
    if (!(v229 == nil)) goto v233;
    v229 = (Lisp_Object)17; /* 1 */
    stack[-3] = v229;
    v229 = stack[-9];
    v229 = qcdr(v229);
    v230 = Llength(nil, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = stack[-3];
    v229 = difference2(v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = Lminusp(nil, v229);
    env = stack[-11];
    if (v229 == nil) goto v234;
    v229 = qvalue(elt(env, 4)); /* nil */
    goto v52;

v52:
    stack[-10] = v229;
    v229 = stack[-9];
    v230 = qcar(v229);
    v229 = elt(env, 5); /* symmetric */
    v229 = Lflagp(nil, v230, v229);
    env = stack[-11];
    if (v229 == nil) goto v131;
    v230 = elt(env, 6); /* !+ */
    v229 = stack[-10];
    v229 = cons(v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-10] = v229;
    goto v233;

v233:
    v229 = stack[-9];
    v229 = qcdr(v229);
    v229 = Llength(nil, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = sub1(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = Lmkvect(nil, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-8] = v229;
    v229 = (Lisp_Object)1; /* 0 */
    stack[-7] = v229;
    v229 = stack[-9];
    v229 = qcdr(v229);
    stack[-4] = v229;
    goto v235;

v235:
    v229 = stack[-4];
    if (v229 == nil) goto v236;
    v229 = stack[-4];
    v229 = qcar(v229);
    stack[-1] = v229;
    v229 = stack[-7];
    v229 = add1(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-7] = v229;
    v229 = stack[-1];
    fn = elt(env, 10); /* listp */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    if (v229 == nil) goto v8;
    stack[-2] = stack[-8];
    v229 = stack[-7];
    stack[0] = sub1(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = stack[-1];
    v229 = ncons(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v229;
    goto v77;

v77:
    v229 = stack[-4];
    v229 = qcdr(v229);
    stack[-4] = v229;
    goto v235;

v8:
    v229 = stack[-1];
    fn = elt(env, 11); /* dummyp */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-6] = v229;
    if (v229 == nil) goto v237;
    v230 = stack[-5];
    v229 = stack[-6];
    fn = elt(env, 12); /* max */
    v229 = (*qfn2(fn))(qenv(fn), v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-5] = v229;
    stack[-3] = stack[-8];
    v229 = stack[-7];
    stack[-2] = sub1(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-1] = elt(env, 1); /* !~dv */
    stack[0] = elt(env, 2); /* !* */
    v229 = stack[-6];
    v229 = ncons(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = list2star(stack[-1], stack[0], v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v229;
    goto v77;

v237:
    stack[-2] = stack[-8];
    v229 = stack[-7];
    stack[0] = sub1(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = stack[-1];
    v229 = ncons(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v229;
    goto v77;

v236:
    v231 = stack[-10];
    v230 = stack[-8];
    v229 = elt(env, 9); /* skp_ordp */
    fn = elt(env, 13); /* st_sorttree */
    v229 = (*qfnn(fn))(qenv(fn), 3, v231, v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-10] = v229;
    v229 = stack[-10];
    if (v229 == nil) goto v65;
    v229 = stack[-10];
    v230 = qcar(v229);
    v229 = (Lisp_Object)1; /* 0 */
    if (!(v230 == v229)) goto v65;
    v229 = qvalue(elt(env, 4)); /* nil */
    { popv(12); return onevalue(v229); }

v65:
    v229 = stack[-10];
    v229 = qcar(v229);
    stack[0] = v229;
    v229 = stack[-10];
    v230 = qcdr(v229);
    v229 = stack[-8];
    fn = elt(env, 14); /* dv_skelsplit1 */
    v229 = (*qfn2(fn))(qenv(fn), v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-1] = v229;
    v229 = stack[-1];
    v229 = qcdr(v229);
    fn = elt(env, 15); /* st_consolidate */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-10] = v229;
    v229 = stack[-9];
    v230 = qcar(v229);
    v229 = stack[-1];
    v229 = qcar(v229);
    v229 = cons(v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-1] = v229;
    stack[-2] = stack[-5];
    v230 = stack[-1];
    v229 = stack[-10];
    v229 = cons(v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    {
        Lisp_Object v238 = stack[0];
        Lisp_Object v239 = stack[-2];
        popv(12);
        return list3(v238, v239, v229);
    }

v131:
    v229 = stack[-9];
    v230 = qcar(v229);
    v229 = elt(env, 7); /* antisymmetric */
    v229 = Lflagp(nil, v230, v229);
    env = stack[-11];
    if (v229 == nil) goto v30;
    v230 = elt(env, 8); /* !- */
    v229 = stack[-10];
    v229 = cons(v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-10] = v229;
    goto v233;

v30:
    v230 = elt(env, 2); /* !* */
    v229 = stack[-10];
    v229 = cons(v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-10] = v229;
    goto v233;

v234:
    v229 = stack[-3];
    v229 = ncons(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-1] = v229;
    stack[-2] = v229;
    goto v53;

v53:
    v229 = stack[-3];
    v229 = add1(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-3] = v229;
    v229 = stack[-9];
    v229 = qcdr(v229);
    v230 = Llength(nil, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = stack[-3];
    v229 = difference2(v230, v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = Lminusp(nil, v229);
    env = stack[-11];
    if (v229 == nil) goto v240;
    v229 = stack[-2];
    goto v52;

v240:
    stack[0] = stack[-1];
    v229 = stack[-3];
    v229 = ncons(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = Lrplacd(nil, stack[0], v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = stack[-1];
    v229 = qcdr(v229);
    stack[-1] = v229;
    goto v53;

v111:
    v229 = stack[-9];
    fn = elt(env, 11); /* dummyp */
    v229 = (*qfn1(fn))(qenv(fn), v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    stack[-6] = v229;
    if (v229 == nil) goto v117;
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[-6];
    stack[-1] = elt(env, 1); /* !~dv */
    stack[0] = elt(env, 2); /* !* */
    v229 = stack[-6];
    v229 = ncons(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-11];
    v229 = list2star(stack[-1], stack[0], v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    {
        Lisp_Object v241 = stack[-3];
        Lisp_Object v242 = stack[-2];
        popv(12);
        return list3(v241, v242, v229);
    }

v117:
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = (Lisp_Object)1; /* 0 */
    v229 = stack[-9];
    v229 = ncons(v229);
    nil = C_nil;
    if (exception_pending()) goto v232;
    {
        Lisp_Object v243 = stack[-1];
        Lisp_Object v244 = stack[0];
        popv(12);
        return list3(v243, v244, v229);
    }
/* error exit handlers */
v232:
    popv(12);
    return nil;
}



/* Code for repartf */

static Lisp_Object CC_repartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v240, v251;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repartf");
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
    v251 = elt(env, 1); /* i */
    v240 = qvalue(elt(env, 2)); /* kord!* */
    v240 = cons(v251, v240);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-4];
    stack[-3] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v240; /* kord!* */
    v240 = stack[0];
    fn = elt(env, 5); /* reorder */
    v240 = (*qfn1(fn))(qenv(fn), v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    stack[-2] = v240;
    v240 = stack[-2];
    if (!consp(v240)) goto v115;
    v240 = stack[-2];
    v240 = qcar(v240);
    if (!consp(v240)) goto v115;
    v240 = stack[-2];
    v240 = qcar(v240);
    v240 = qcar(v240);
    v251 = qcar(v240);
    v240 = elt(env, 1); /* i */
    if (v251 == v240) goto v252;
    v240 = stack[-2];
    v240 = qcar(v240);
    v251 = qcar(v240);
    v240 = (Lisp_Object)17; /* 1 */
    v240 = cons(v251, v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    stack[0] = ncons(v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v240 = stack[-2];
    v240 = qcar(v240);
    v240 = qcdr(v240);
    v240 = CC_repartf(env, v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    fn = elt(env, 6); /* multf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v240 = stack[-2];
    v240 = qcdr(v240);
    v240 = CC_repartf(env, v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    fn = elt(env, 7); /* addf */
    v240 = (*qfn2(fn))(qenv(fn), stack[0], v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v98;

v98:
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    { popv(5); return onevalue(v240); }

v252:
    v240 = stack[-2];
    v240 = qcdr(v240);
    v240 = CC_repartf(env, v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v98;

v115:
    v240 = stack[-2];
    if (!consp(v240)) goto v169;
    v240 = stack[-2];
    v251 = qcar(v240);
    v240 = elt(env, 3); /* cmpxfn */
    v240 = get(v251, v240);
    env = stack[-4];
    if (v240 == nil) goto v228;
    v240 = stack[-2];
    stack[-1] = qcar(v240);
    v240 = stack[-2];
    v240 = qcdr(v240);
    stack[0] = qcar(v240);
    v240 = stack[-2];
    v251 = qcar(v240);
    v240 = elt(env, 4); /* i2d */
    v251 = get(v251, v240);
    env = stack[-4];
    v240 = (Lisp_Object)1; /* 0 */
    v240 = Lapply1(nil, v251, v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v240 = qcdr(v240);
    v240 = qcar(v240);
    v240 = list2star(stack[-1], stack[0], v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    fn = elt(env, 8); /* int!-equiv!-chk */
    v240 = (*qfn1(fn))(qenv(fn), v240);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    goto v98;

v228:
    v240 = stack[-2];
    goto v98;

v169:
    v240 = stack[-2];
    goto v98;
/* error exit handlers */
v44:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* kord!* */
    popv(5);
    return nil;
v134:
    popv(5);
    return nil;
}



/* Code for ieval */

static Lisp_Object CC_ieval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ieval");
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
    v97 = v0;
/* end of prologue */
    fn = elt(env, 1); /* reval */
    v97 = (*qfn1(fn))(qenv(fn), v97);
    nil = C_nil;
    if (exception_pending()) goto v168;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*s2i */
        return (*qfn1(fn))(qenv(fn), v97);
    }
/* error exit handlers */
v168:
    popv(1);
    return nil;
}



/* Code for diford */

static Lisp_Object CC_diford(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diford");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v168 = v0;
/* end of prologue */
    v168 = qcdr(v168);
    v168 = qcdr(v168);
    {
        fn = elt(env, 1); /* lengthn */
        return (*qfn1(fn))(qenv(fn), v168);
    }
}



/* Code for solvealgtrig01 */

static Lisp_Object CC_solvealgtrig01(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v85;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for solvealgtrig01");
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

v168:
    v84 = stack[-1];
    if (!consp(v84)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v84 = stack[-1];
    v85 = qcar(v84);
    v84 = elt(env, 1); /* (sin cos tan cot sinh cosh tanh coth) */
    v84 = Lmemq(nil, v85, v84);
    if (v84 == nil) goto v104;
    v84 = stack[-1];
    v84 = qcdr(v84);
    v84 = qcar(v84);
    fn = elt(env, 2); /* constant_exprp */
    v84 = (*qfn1(fn))(qenv(fn), v84);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    if (!(v84 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v84 = stack[-1];
    v84 = qcdr(v84);
    v84 = qcar(v84);
    v85 = ncons(v84);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    v84 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* union */
        return (*qfn2(fn))(qenv(fn), v85, v84);
    }

v104:
    v84 = stack[-1];
    v84 = qcdr(v84);
    stack[-2] = v84;
    v84 = stack[-1];
    v85 = qcar(v84);
    v84 = stack[0];
    v84 = CC_solvealgtrig01(env, v85, v84);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-3];
    stack[0] = v84;
    v84 = stack[-2];
    stack[-1] = v84;
    goto v168;
/* error exit handlers */
v96:
    popv(4);
    return nil;
}



/* Code for groebmakepair */

static Lisp_Object CC_groebmakepair(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v245, v227;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebmakepair");
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
    v255 = stack[-3];
    v255 = qcdr(v255);
    v245 = qcar(v255);
    v255 = stack[-2];
    v255 = qcdr(v255);
    v255 = qcar(v255);
    fn = elt(env, 2); /* vevlcm */
    v255 = (*qfn2(fn))(qenv(fn), v245, v255);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    stack[-4] = v255;
    v255 = qvalue(elt(env, 1)); /* !*gsugar */
    if (v255 == nil) goto v256;
    v255 = stack[-3];
    fn = elt(env, 3); /* gsugar */
    stack[0] = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v245 = stack[-4];
    v255 = stack[-3];
    v255 = qcdr(v255);
    v255 = qcar(v255);
    fn = elt(env, 4); /* vevdif */
    v255 = (*qfn2(fn))(qenv(fn), v245, v255);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    fn = elt(env, 5); /* vevtdeg */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v255 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v255 - TAG_FIXNUM);
    stack[-1] = v255;
    v255 = stack[-2];
    fn = elt(env, 3); /* gsugar */
    stack[0] = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v245 = stack[-4];
    v255 = stack[-2];
    v255 = qcdr(v255);
    v255 = qcar(v255);
    fn = elt(env, 4); /* vevdif */
    v255 = (*qfn2(fn))(qenv(fn), v245, v255);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    fn = elt(env, 5); /* vevtdeg */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-5];
    v255 = (Lisp_Object)(int32_t)((int32_t)stack[0] + (int32_t)v255 - TAG_FIXNUM);
    stack[0] = stack[-4];
    v245 = stack[-1];
    fn = elt(env, 6); /* max */
    v255 = (*qfn2(fn))(qenv(fn), v245, v255);
    nil = C_nil;
    if (exception_pending()) goto v70;
    {
        Lisp_Object v257 = stack[0];
        Lisp_Object v139 = stack[-3];
        Lisp_Object v140 = stack[-2];
        popv(6);
        return list4(v257, v139, v140, v255);
    }

v256:
    v227 = stack[-4];
    v245 = stack[-3];
    v255 = stack[-2];
    popv(6);
    return list3(v227, v245, v255);
/* error exit handlers */
v70:
    popv(6);
    return nil;
}



/* Code for !:log2 */

static Lisp_Object CC_Tlog2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :log2");
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
    v161 = elt(env, 0); /* !:log2 */
    v100 = stack[0];
    fn = elt(env, 3); /* get!:const */
    v100 = (*qfn2(fn))(qenv(fn), v161, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    stack[-1] = v100;
    v161 = stack[-1];
    v100 = elt(env, 1); /* not_found */
    if (!(v161 == v100)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v161 = qvalue(elt(env, 2)); /* bftwo!* */
    v100 = stack[0];
    fn = elt(env, 4); /* log!: */
    v100 = (*qfn2(fn))(qenv(fn), v161, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    stack[-1] = v100;
    v161 = elt(env, 0); /* !:log2 */
    v100 = stack[-1];
    fn = elt(env, 5); /* save!:const */
    v100 = (*qfn2(fn))(qenv(fn), v161, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v104:
    popv(3);
    return nil;
}



/* Code for ev!-poles */

static Lisp_Object CC_evKpoles(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v59, v103, v105;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ev-poles");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v105 = v1;
    v103 = v0;
/* end of prologue */

v97:
    v60 = v103;
    if (v60 == nil) goto v68;
    v60 = v103;
    v59 = qcar(v60);
    v60 = v105;
    v60 = Lassoc(nil, v59, v60);
    v59 = qcdr(v60);
    v60 = (Lisp_Object)1; /* 0 */
    if (!(v59 == v60)) return onevalue(v103);
    v60 = v103;
    v60 = qcdr(v60);
    v103 = v60;
    goto v97;

v68:
    v60 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v60);
}



/* Code for precision1 */

static Lisp_Object CC_precision1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v261, v130;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for precision1");
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
    v130 = v1;
    stack[0] = v0;
/* end of prologue */
    v261 = stack[0];
    v129 = (Lisp_Object)1; /* 0 */
    if (v261 == v129) goto v68;
    v129 = v130;
    if (v129 == nil) goto v112;
    fn = elt(env, 14); /* rmsubs */
    v129 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    goto v112;

v112:
    v129 = qvalue(elt(env, 1)); /* !!rdprec */
    stack[-3] = v129;
    v129 = qvalue(elt(env, 2)); /* !*roundbf */
    if (v129 == nil) goto v88;
    v129 = stack[0];
    v261 = v129;
    goto v164;

v164:
    qvalue(elt(env, 1)) = v261; /* !!rdprec */
    v129 = (Lisp_Object)33; /* 2 */
    v129 = plus2(v261, v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    qvalue(elt(env, 4)) = v129; /* !:prec!: */
    v129 = qvalue(elt(env, 5)); /* !:print!-prec!: */
    if (v129 == nil) goto v57;
    v261 = qvalue(elt(env, 5)); /* !:print!-prec!: */
    v129 = (Lisp_Object)33; /* 2 */
    v129 = plus2(v261, v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    v129 = (Lisp_Object)lessp2(stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    v129 = v129 ? lisp_true : nil;
    env = stack[-4];
    if (v129 == nil) goto v57;
    v129 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 5)) = v129; /* !:print!-prec!: */
    goto v57;

v57:
    v129 = qvalue(elt(env, 4)); /* !:prec!: */
    fn = elt(env, 15); /* decprec2internal */
    v129 = (*qfn1(fn))(qenv(fn), v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    qvalue(elt(env, 7)) = v129; /* !:bprec!: */
    stack[-1] = elt(env, 8); /* !:rd!: */
    stack[0] = (Lisp_Object)17; /* 1 */
    v261 = qvalue(elt(env, 7)); /* !:bprec!: */
    v129 = (Lisp_Object)33; /* 2 */
    v129 = quot2(v261, v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    v129 = negate(v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    v129 = list2star(stack[-1], stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    qvalue(elt(env, 9)) = v129; /* epsqrt!* */
    stack[-1] = elt(env, 8); /* !:rd!: */
    stack[0] = (Lisp_Object)17; /* 1 */
    v261 = (Lisp_Object)97; /* 6 */
    v129 = qvalue(elt(env, 7)); /* !:bprec!: */
    v129 = difference2(v261, v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    v129 = list2star(stack[-1], stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    qvalue(elt(env, 10)) = v129; /* rd!-tolerance!* */
    stack[-2] = elt(env, 8); /* !:rd!: */
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = (Lisp_Object)33; /* 2 */
    v261 = (Lisp_Object)97; /* 6 */
    v129 = qvalue(elt(env, 7)); /* !:bprec!: */
    v129 = difference2(v261, v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    v129 = times2(stack[0], v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    v129 = list2star(stack[-2], stack[-1], v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    qvalue(elt(env, 11)) = v129; /* cr!-tolerance!* */
    v261 = qvalue(elt(env, 1)); /* !!rdprec */
    v129 = qvalue(elt(env, 12)); /* !!flprec */
    v129 = (Lisp_Object)greaterp2(v261, v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    v129 = v129 ? lisp_true : nil;
    env = stack[-4];
    if (!(v129 == nil)) goto v263;
    v129 = qvalue(elt(env, 2)); /* !*roundbf */
    goto v263;

v263:
    qvalue(elt(env, 13)) = v129; /* !*!*roundbf */
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v88:
    v261 = stack[0];
    v129 = qvalue(elt(env, 3)); /* minprec!# */
    fn = elt(env, 16); /* max */
    v129 = (*qfn2(fn))(qenv(fn), v261, v129);
    nil = C_nil;
    if (exception_pending()) goto v262;
    env = stack[-4];
    v261 = v129;
    goto v164;

v68:
    v129 = qvalue(elt(env, 1)); /* !!rdprec */
    { popv(5); return onevalue(v129); }
/* error exit handlers */
v262:
    popv(5);
    return nil;
}



/* Code for max!-degree */

static Lisp_Object CC_maxKdegree(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v84, v85, v93, v94;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for max-degree");
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
    v85 = v1;
    v93 = v0;
/* end of prologue */

v168:
    v84 = v93;
    if (!consp(v84)) { popv(2); return onevalue(v85); }
    v84 = v93;
    v84 = qcar(v84);
    if (!consp(v84)) { popv(2); return onevalue(v85); }
    v94 = v85;
    v84 = v93;
    v84 = qcar(v84);
    v84 = qcar(v84);
    v84 = qcdr(v84);
    if (((int32_t)(v94)) > ((int32_t)(v84))) goto v116;
    v84 = v93;
    v84 = qcdr(v84);
    stack[0] = v84;
    v84 = v93;
    v84 = qcar(v84);
    v84 = qcdr(v84);
    v85 = v93;
    v85 = qcar(v85);
    v85 = qcar(v85);
    v85 = qcdr(v85);
    v84 = CC_maxKdegree(env, v84, v85);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v85 = v84;
    v84 = stack[0];
    v93 = v84;
    goto v168;

v116:
    v84 = v93;
    v84 = qcdr(v84);
    stack[0] = v84;
    v84 = v93;
    v84 = qcar(v84);
    v84 = qcdr(v84);
    v84 = CC_maxKdegree(env, v84, v85);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v85 = v84;
    v84 = stack[0];
    v93 = v84;
    goto v168;
/* error exit handlers */
v96:
    popv(2);
    return nil;
}



/* Code for fctrf1 */

static Lisp_Object CC_fctrf1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v153, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fctrf1");
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
    stack[-1] = nil;
    v153 = stack[-3];
    if (!consp(v153)) goto v67;
    v153 = stack[-3];
    v153 = qcar(v153);
    if (!consp(v153)) goto v67;
    v154 = qvalue(elt(env, 1)); /* dmode!* */
    v153 = elt(env, 2); /* field */
    v153 = Lflagp(nil, v154, v153);
    env = stack[-5];
    if (v153 == nil) goto v162;
    v153 = stack[-3];
    fn = elt(env, 4); /* lnc */
    v154 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-1] = v154;
    v153 = (Lisp_Object)17; /* 1 */
    if (v154 == v153) goto v162;
    v153 = stack[-1];
    fn = elt(env, 5); /* !:recip */
    v154 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v153 = stack[-3];
    fn = elt(env, 6); /* multd */
    v153 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-3] = v153;
    goto v112;

v112:
    v153 = stack[-3];
    fn = elt(env, 7); /* comfac */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-4] = v153;
    stack[0] = stack[-3];
    v153 = stack[-4];
    fn = elt(env, 8); /* comfac!-to!-poly */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    fn = elt(env, 9); /* quotf */
    v153 = (*qfn2(fn))(qenv(fn), stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-3] = v153;
    v153 = stack[-4];
    v153 = qcdr(v153);
    v153 = CC_fctrf1(env, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-2] = v153;
    v153 = stack[-4];
    v153 = qcar(v153);
    if (v153 == nil) goto v259;
    v153 = stack[-2];
    stack[0] = qcar(v153);
    v153 = stack[-4];
    v153 = qcar(v153);
    v154 = qcar(v153);
    v153 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 10); /* to */
    v154 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v153 = (Lisp_Object)17; /* 1 */
    v153 = cons(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v154 = ncons(v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v153 = stack[-4];
    v153 = qcar(v153);
    v153 = qcdr(v153);
    v154 = cons(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v153 = stack[-2];
    v153 = qcdr(v153);
    v153 = list2star(stack[0], v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-2] = v153;
    goto v259;

v259:
    v153 = stack[-1];
    if (v153 == nil) goto v40;
    v154 = stack[-1];
    v153 = (Lisp_Object)17; /* 1 */
    if (v154 == v153) goto v40;
    v154 = stack[-1];
    v153 = stack[-2];
    v153 = qcar(v153);
    fn = elt(env, 6); /* multd */
    v154 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v153 = stack[-2];
    v153 = qcdr(v153);
    v153 = cons(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-2] = v153;
    goto v40;

v40:
    v153 = stack[-3];
    if (!consp(v153)) goto v26;
    v153 = stack[-3];
    v153 = qcar(v153);
    if (!consp(v153)) goto v26;
    v153 = stack[-3];
    fn = elt(env, 11); /* minusf */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    if (v153 == nil) goto v122;
    v153 = stack[-3];
    fn = elt(env, 12); /* negf */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-3] = v153;
    v153 = stack[-2];
    v153 = qcar(v153);
    fn = elt(env, 12); /* negf */
    v154 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v153 = stack[-2];
    v153 = qcdr(v153);
    v153 = cons(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-2] = v153;
    goto v122;

v122:
    v153 = stack[-3];
    fn = elt(env, 13); /* factor!-prim!-f */
    v154 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v153 = stack[-2];
    {
        popv(6);
        fn = elt(env, 14); /* fac!-merge */
        return (*qfn2(fn))(qenv(fn), v154, v153);
    }

v26:
    v154 = stack[-3];
    v153 = stack[-2];
    v153 = qcar(v153);
    fn = elt(env, 15); /* multf */
    v154 = (*qfn2(fn))(qenv(fn), v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    v153 = stack[-2];
    v153 = qcdr(v153);
    popv(6);
    return cons(v154, v153);

v162:
    v153 = qvalue(elt(env, 1)); /* dmode!* */
    if (v153 == nil) goto v112;
    v154 = qvalue(elt(env, 1)); /* dmode!* */
    v153 = elt(env, 3); /* unitsfn */
    v153 = get(v154, v153);
    env = stack[-5];
    stack[-2] = v153;
    if (v153 == nil) goto v112;
    stack[-1] = stack[-2];
    v154 = (Lisp_Object)17; /* 1 */
    v153 = stack[-3];
    stack[0] = cons(v154, v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v153 = stack[-3];
    fn = elt(env, 4); /* lnc */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    v153 = Lapply2(nil, 3, stack[-1], stack[0], v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-4] = v153;
    v153 = stack[-4];
    v153 = qcdr(v153);
    stack[-3] = v153;
    v153 = stack[-4];
    v153 = qcar(v153);
    fn = elt(env, 5); /* !:recip */
    v153 = (*qfn1(fn))(qenv(fn), v153);
    nil = C_nil;
    if (exception_pending()) goto v20;
    env = stack[-5];
    stack[-1] = v153;
    goto v112;

v67:
    v153 = stack[-3];
    popv(6);
    return ncons(v153);
/* error exit handlers */
v20:
    popv(6);
    return nil;
}



/* Code for change!+sq!+to!+int */

static Lisp_Object CC_changeLsqLtoLint(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v170, v62, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for change+sq+to+int");
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
    v170 = v0;
/* end of prologue */
    fn = elt(env, 2); /* prepsq */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[0];
    fn = elt(env, 3); /* simp!* */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[0];
    v61 = v170;
    v170 = v61;
    v62 = qcdr(v170);
    v170 = (Lisp_Object)17; /* 1 */
    if (v62 == v170) goto v101;
    v170 = elt(env, 1); /* "no integer in change!+sq!+to!+int" */
    fn = elt(env, 4); /* rederr */
    v170 = (*qfn1(fn))(qenv(fn), v170);
    nil = C_nil;
    if (exception_pending()) goto v89;
    v170 = nil;
    { popv(1); return onevalue(v170); }

v101:
    v170 = v61;
    v170 = qcar(v170);
    { popv(1); return onevalue(v170); }
/* error exit handlers */
v89:
    popv(1);
    return nil;
}



/* Code for ofsf_optfindeqsol */

static Lisp_Object CC_ofsf_optfindeqsol(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v166;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_optfindeqsol");
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

v272:
    v165 = stack[-2];
    v165 = qcar(v165);
    stack[-3] = v165;
    v165 = stack[-3];
    v166 = qcar(v165);
    v165 = elt(env, 1); /* equal */
    if (!(v166 == v165)) goto v101;
    stack[0] = stack[-1];
    v165 = stack[-3];
    fn = elt(env, 2); /* ofsf_varlat */
    v165 = (*qfn1(fn))(qenv(fn), v165);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    v165 = Lmemq(nil, stack[0], v165);
    if (v165 == nil) goto v101;
    v165 = stack[-3];
    v165 = qcdr(v165);
    v166 = qcar(v165);
    v165 = stack[-1];
    fn = elt(env, 3); /* ofsf_optmksol */
    v165 = (*qfn2(fn))(qenv(fn), v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    stack[-1] = v165;
    stack[-2] = stack[-3];
    v165 = stack[-1];
    v166 = qcar(v165);
    v165 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    v165 = stack[-1];
    v166 = qcdr(v165);
    v165 = (Lisp_Object)17; /* 1 */
    v165 = cons(v166, v165);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-4];
    fn = elt(env, 4); /* quotsq */
    v165 = (*qfn2(fn))(qenv(fn), stack[0], v165);
    nil = C_nil;
    if (exception_pending()) goto v48;
    {
        Lisp_Object v47 = stack[-2];
        popv(5);
        return cons(v47, v165);
    }

v101:
    v165 = stack[-2];
    v165 = qcdr(v165);
    if (v165 == nil) goto v233;
    v165 = stack[-2];
    v166 = qcdr(v165);
    v165 = stack[-1];
    stack[-2] = v166;
    stack[-1] = v165;
    goto v272;

v233:
    v165 = nil;
    { popv(5); return onevalue(v165); }
/* error exit handlers */
v48:
    popv(5);
    return nil;
}



/* Code for ldf!-sep!-var */

static Lisp_Object CC_ldfKsepKvar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v119;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldf-sep-var");
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
    v119 = stack[0];
    fn = elt(env, 1); /* ldf!-pow!-var */
    stack[-1] = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    v119 = stack[0];
    fn = elt(env, 2); /* ldf!-dep!-var */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    fn = elt(env, 3); /* compl */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v119);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    v119 = stack[0];
    fn = elt(env, 4); /* ldf!-spf!-var */
    v119 = (*qfn1(fn))(qenv(fn), v119);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-2];
    {
        Lisp_Object v264 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* compl */
        return (*qfn2(fn))(qenv(fn), v264, v119);
    }
/* error exit handlers */
v248:
    popv(3);
    return nil;
}



/* Code for setprev */

static Lisp_Object CC_setprev(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v140, v137;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for setprev");
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

v98:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v137 = qvalue(elt(env, 2)); /* maxvar */
    v140 = stack[-3];
    v140 = plus2(v137, v140);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v137 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v140/(16/CELL)));
    v140 = (Lisp_Object)49; /* 3 */
    v140 = *(Lisp_Object *)((char *)v137 + (CELL-TAG_VECTOR) + ((int32_t)v140/(16/CELL)));
    if (is_number(v140)) goto v103;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v137 = qvalue(elt(env, 2)); /* maxvar */
    v140 = stack[-3];
    v140 = plus2(v137, v140);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    stack[-4] = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v140/(16/CELL)));
    stack[-2] = (Lisp_Object)129; /* 8 */
    stack[-1] = stack[0];
    stack[0] = qvalue(elt(env, 1)); /* codmat */
    v137 = qvalue(elt(env, 2)); /* maxvar */
    v140 = stack[-3];
    v140 = plus2(v137, v140);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v137 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v140/(16/CELL)));
    v140 = (Lisp_Object)129; /* 8 */
    v140 = *(Lisp_Object *)((char *)v137 + (CELL-TAG_VECTOR) + ((int32_t)v140/(16/CELL)));
    v140 = cons(stack[-1], v140);
    nil = C_nil;
    if (exception_pending()) goto v180;
    *(Lisp_Object *)((char *)stack[-4] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v140;
    { popv(6); return onevalue(v140); }

v103:
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v137 = qvalue(elt(env, 2)); /* maxvar */
    v140 = stack[-3];
    v140 = plus2(v137, v140);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v137 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v140/(16/CELL)));
    v140 = (Lisp_Object)49; /* 3 */
    v140 = *(Lisp_Object *)((char *)v137 + (CELL-TAG_VECTOR) + ((int32_t)v140/(16/CELL)));
    stack[-3] = v140;
    goto v98;
/* error exit handlers */
v180:
    popv(6);
    return nil;
}



/* Code for dipretimes */

static Lisp_Object CC_dipretimes(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v107, v104;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipretimes");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v107 = v0;
/* end of prologue */

v67:
    v106 = v107;
    v104 = qcar(v106);
    v106 = (Lisp_Object)17; /* 1 */
    if (v104 == v106) goto v63;
    v106 = v107;
    v106 = qcdr(v106);
    if (v106 == nil) goto v61;
    v106 = elt(env, 1); /* times */
    return cons(v106, v107);

v61:
    v106 = v107;
    v106 = qcar(v106);
    return onevalue(v106);

v63:
    v106 = v107;
    v106 = qcdr(v106);
    if (v106 == nil) goto v169;
    v106 = v107;
    v106 = qcdr(v106);
    v107 = v106;
    goto v67;

v169:
    v106 = (Lisp_Object)17; /* 1 */
    return onevalue(v106);
}



/* Code for xpartitsq */

static Lisp_Object CC_xpartitsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v29, v277;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xpartitsq");
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
    v277 = v0;
/* end of prologue */
    v30 = v277;
    v29 = qcar(v30);
    v30 = v277;
    v30 = qcdr(v30);
    stack[-2] = v29;
    stack[-1] = v30;
    v30 = stack[-2];
    if (v30 == nil) goto v101;
    v30 = stack[-2];
    if (!consp(v30)) goto v248;
    v30 = stack[-2];
    v30 = qcar(v30);
    if (!consp(v30)) goto v248;
    v30 = stack[-2];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    fn = elt(env, 2); /* sfp */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    if (v30 == nil) goto v253;
    v30 = stack[-2];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v29 = qcar(v30);
    v30 = (Lisp_Object)17; /* 1 */
    v30 = cons(v29, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v29 = CC_xpartitsq(env, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v30 = stack[-2];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcdr(v30);
    fn = elt(env, 3); /* xexptpf */
    stack[0] = (*qfn2(fn))(qenv(fn), v29, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v30 = stack[-2];
    v30 = qcar(v30);
    v29 = qcdr(v30);
    v30 = stack[-1];
    v30 = cons(v29, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    fn = elt(env, 4); /* cancel */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v30 = CC_xpartitsq(env, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    fn = elt(env, 5); /* wedgepf */
    v30 = (*qfn2(fn))(qenv(fn), stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    stack[0] = v30;
    goto v32;

v32:
    v30 = stack[-2];
    v29 = qcdr(v30);
    v30 = stack[-1];
    v30 = cons(v29, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v30 = CC_xpartitsq(env, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    {
        Lisp_Object v278 = stack[0];
        popv(4);
        fn = elt(env, 6); /* addpf */
        return (*qfn2(fn))(qenv(fn), v278, v30);
    }

v253:
    v30 = stack[-2];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    fn = elt(env, 7); /* xvarp */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    if (v30 == nil) goto v270;
    v30 = stack[-2];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcar(v30);
    fn = elt(env, 8); /* xpartitk */
    v29 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v30 = stack[-2];
    v30 = qcar(v30);
    v30 = qcar(v30);
    v30 = qcdr(v30);
    fn = elt(env, 3); /* xexptpf */
    stack[0] = (*qfn2(fn))(qenv(fn), v29, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v30 = stack[-2];
    v30 = qcar(v30);
    v29 = qcdr(v30);
    v30 = stack[-1];
    v30 = cons(v29, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    fn = elt(env, 4); /* cancel */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v30 = CC_xpartitsq(env, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    fn = elt(env, 5); /* wedgepf */
    v30 = (*qfn2(fn))(qenv(fn), stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    stack[0] = v30;
    goto v32;

v270:
    v30 = stack[-2];
    v30 = qcar(v30);
    v29 = qcdr(v30);
    v30 = stack[-1];
    v30 = cons(v29, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    fn = elt(env, 4); /* cancel */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    stack[0] = CC_xpartitsq(env, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v30 = stack[-2];
    v30 = qcar(v30);
    v29 = qcar(v30);
    v30 = (Lisp_Object)17; /* 1 */
    v30 = cons(v29, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v29 = ncons(v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    v30 = (Lisp_Object)17; /* 1 */
    v30 = cons(v29, v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    fn = elt(env, 9); /* multpfsq */
    v30 = (*qfn2(fn))(qenv(fn), stack[0], v30);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-3];
    stack[0] = v30;
    goto v32;

v248:
    v30 = (Lisp_Object)17; /* 1 */
    v29 = v277;
    v30 = cons(v30, v29);
    nil = C_nil;
    if (exception_pending()) goto v125;
    popv(4);
    return ncons(v30);

v101:
    v30 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v30); }
/* error exit handlers */
v125:
    popv(4);
    return nil;
}



/* Code for !:log10 */

static Lisp_Object CC_Tlog10(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v161;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :log10");
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
    v161 = elt(env, 0); /* !:log10 */
    v100 = stack[0];
    fn = elt(env, 3); /* get!:const */
    v100 = (*qfn2(fn))(qenv(fn), v161, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    stack[-1] = v100;
    v161 = stack[-1];
    v100 = elt(env, 1); /* not_found */
    if (!(v161 == v100)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v161 = qvalue(elt(env, 2)); /* bften!* */
    v100 = stack[0];
    fn = elt(env, 4); /* log!: */
    v100 = (*qfn2(fn))(qenv(fn), v161, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    stack[-1] = v100;
    v161 = elt(env, 0); /* !:log10 */
    v100 = stack[-1];
    fn = elt(env, 5); /* save!:const */
    v100 = (*qfn2(fn))(qenv(fn), v161, v100);
    nil = C_nil;
    if (exception_pending()) goto v104;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v104:
    popv(3);
    return nil;
}



/* Code for markedvarp */

static Lisp_Object CC_markedvarp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v101, v102;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for markedvarp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v101 = v0;
/* end of prologue */
    v102 = elt(env, 1); /* !*marked!* */
        return Lflagp(nil, v101, v102);
}



/* Code for indordlp */

static Lisp_Object CC_indordlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v252, v146, v147, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for indordlp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v146 = v1;
    v147 = v0;
/* end of prologue */

v97:
    v252 = v147;
    if (v252 == nil) goto v68;
    v252 = v146;
    if (v252 == nil) goto v91;
    v252 = v147;
    v144 = qcar(v252);
    v252 = v146;
    v252 = qcar(v252);
    if (equal(v144, v252)) goto v115;
    v252 = v147;
    v252 = qcar(v252);
    if (!consp(v252)) goto v163;
    v252 = v146;
    v252 = qcar(v252);
    if (!consp(v252)) goto v118;
    v252 = v147;
    v252 = qcar(v252);
    v252 = qcdr(v252);
    v252 = qcar(v252);
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = qcar(v146);
    {
        fn = elt(env, 3); /* indordp */
        return (*qfn2(fn))(qenv(fn), v252, v146);
    }

v118:
    v252 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v252);

v163:
    v252 = v146;
    v252 = qcar(v252);
    if (!consp(v252)) goto v100;
    v252 = qvalue(elt(env, 2)); /* t */
    return onevalue(v252);

v100:
    v252 = v147;
    v252 = qcar(v252);
    v146 = qcar(v146);
    {
        fn = elt(env, 3); /* indordp */
        return (*qfn2(fn))(qenv(fn), v252, v146);
    }

v115:
    v252 = v147;
    v252 = qcdr(v252);
    v147 = v252;
    v252 = v146;
    v252 = qcdr(v252);
    v146 = v252;
    goto v97;

v91:
    v252 = qvalue(elt(env, 2)); /* t */
    return onevalue(v252);

v68:
    v252 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v252);
}



/* Code for new_prove */

static Lisp_Object CC_new_prove(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for new_prove");
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

v272:
    v87 = stack[0];
    if (v87 == nil) goto v97;
    v88 = stack[-1];
    v87 = stack[0];
    v87 = qcar(v87);
    fn = elt(env, 2); /* new_provev */
    v87 = (*qfn2(fn))(qenv(fn), v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-2];
    v88 = v87;
    v87 = v88;
    if (v87 == nil) goto v163;
    v87 = v88;
    popv(3);
    return ncons(v87);

v163:
    v88 = stack[-1];
    v87 = stack[0];
    v87 = qcdr(v87);
    stack[-1] = v88;
    stack[0] = v87;
    goto v272;

v97:
    v87 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v87); }
/* error exit handlers */
v161:
    popv(3);
    return nil;
}



/* Code for red_redpol */

static Lisp_Object CC_red_redpol(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v164, v99;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red_redpol");
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
    v164 = v1;
    stack[0] = v0;
/* end of prologue */
    fn = elt(env, 2); /* red_prepare */
    v164 = (*qfn1(fn))(qenv(fn), v164);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    v99 = qvalue(elt(env, 1)); /* !*red_total */
    if (v99 == nil) goto v169;
    v99 = stack[0];
    fn = elt(env, 3); /* red_totalred */
    v164 = (*qfn2(fn))(qenv(fn), v99, v164);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    goto v101;

v101:
    {
        popv(2);
        fn = elt(env, 4); /* red_extract */
        return (*qfn1(fn))(qenv(fn), v164);
    }

v169:
    v99 = stack[0];
    fn = elt(env, 5); /* red_topred */
    v164 = (*qfn2(fn))(qenv(fn), v99, v164);
    nil = C_nil;
    if (exception_pending()) goto v60;
    env = stack[-1];
    goto v101;
/* error exit handlers */
v60:
    popv(2);
    return nil;
}



/* Code for st_extract_symcells1 */

static Lisp_Object MS_CDECL CC_st_extract_symcells1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v127, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "st_extract_symcells1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for st_extract_symcells1");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v2;
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */
    v126 = stack[0];
    v126 = qcdr(v126);
    v126 = qcar(v126);
    fn = elt(env, 3); /* listp */
    v126 = (*qfn1(fn))(qenv(fn), v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-7];
    if (v126 == nil) goto v116;
    v126 = stack[0];
    stack[-6] = qcar(v126);
    v126 = stack[0];
    v126 = qcdr(v126);
    stack[-3] = v126;
    v126 = stack[-3];
    if (v126 == nil) goto v271;
    v126 = stack[-3];
    v126 = qcar(v126);
    v219 = v126;
    v127 = stack[-5];
    v126 = stack[-4];
    v126 = CC_st_extract_symcells1(env, 3, v219, v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-7];
    v127 = v126;
    v127 = qcdr(v127);
    v127 = qcar(v127);
    stack[-5] = v127;
    v127 = v126;
    v127 = qcdr(v127);
    v127 = qcdr(v127);
    v127 = qcar(v127);
    stack[-4] = v127;
    v127 = v126;
    v127 = qcar(v127);
    if (is_number(v127)) goto v165;
    v126 = qcar(v126);
    goto v52;

v52:
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-7];
    stack[-1] = v126;
    stack[-2] = v126;
    goto v86;

v86:
    v126 = stack[-3];
    v126 = qcdr(v126);
    stack[-3] = v126;
    v126 = stack[-3];
    if (v126 == nil) goto v246;
    stack[0] = stack[-1];
    v126 = stack[-3];
    v126 = qcar(v126);
    v219 = v126;
    v127 = stack[-5];
    v126 = stack[-4];
    v126 = CC_st_extract_symcells1(env, 3, v219, v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-7];
    v127 = v126;
    v127 = qcdr(v127);
    v127 = qcar(v127);
    stack[-5] = v127;
    v127 = v126;
    v127 = qcdr(v127);
    v127 = qcdr(v127);
    v127 = qcar(v127);
    stack[-4] = v127;
    v127 = v126;
    v127 = qcar(v127);
    if (is_number(v127)) goto v41;
    v126 = qcar(v126);
    goto v270;

v270:
    v126 = ncons(v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-7];
    v126 = Lrplacd(nil, stack[0], v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-7];
    v126 = stack[-1];
    v126 = qcdr(v126);
    stack[-1] = v126;
    goto v86;

v41:
    v127 = elt(env, 2); /* !* */
    v126 = qcar(v126);
    v126 = list2(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-7];
    goto v270;

v246:
    v126 = stack[-2];
    goto v253;

v253:
    v126 = cons(stack[-6], v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    v219 = v126;
    v127 = stack[-5];
    v126 = stack[-4];
    popv(8);
    return list3(v219, v127, v126);

v165:
    v127 = elt(env, 2); /* !* */
    v126 = qcar(v126);
    v126 = list2(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-7];
    goto v52;

v271:
    v126 = qvalue(elt(env, 1)); /* nil */
    goto v253;

v116:
    stack[-1] = stack[-4];
    v127 = stack[0];
    v126 = stack[-5];
    stack[0] = cons(v127, v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    env = stack[-7];
    v126 = stack[-4];
    v126 = add1(v126);
    nil = C_nil;
    if (exception_pending()) goto v280;
    {
        Lisp_Object v182 = stack[-1];
        Lisp_Object v125 = stack[0];
        popv(8);
        return list3(v182, v125, v126);
    }
/* error exit handlers */
v280:
    popv(8);
    return nil;
}



/* Code for evalleq */

static Lisp_Object CC_evalleq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalleq");
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
    v91 = v1;
    v92 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evalgreaterp */
    v91 = (*qfn2(fn))(qenv(fn), v92, v91);
    errexit();
    v91 = (v91 == nil ? lisp_true : nil);
    return onevalue(v91);
}



/* Code for simpx1 */

static Lisp_Object MS_CDECL CC_simpx1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v376, v377, v378;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "simpx1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpx1");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v2;
    stack[-1] = v1;
    stack[-4] = v0;
/* end of prologue */
    stack[-6] = nil;
    v377 = stack[-4];
    v376 = elt(env, 1); /* !*minus!* */
    if (!consp(v377)) goto v91;
    v377 = qcar(v377);
    if (!(v377 == v376)) goto v91;
    v377 = stack[-1];
    v376 = (Lisp_Object)17; /* 1 */
    if (!(v377 == v376)) goto v56;
    v376 = stack[-3];
    v376 = integerp(v376);
    if (v376 == nil) goto v56;
    v377 = stack[-3];
    v376 = (Lisp_Object)33; /* 2 */
    v377 = Cremainder(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = (Lisp_Object)1; /* 0 */
    if (!(v377 == v376)) goto v56;

v36:
    stack[-6] = elt(env, 3); /* expt */
    stack[-5] = elt(env, 4); /* i */
    stack[-2] = elt(env, 2); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v377 = stack[-3];
    v376 = (Lisp_Object)33; /* 2 */
    v376 = quot2(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = list3(stack[-2], stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = list3(stack[-6], stack[-5], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    fn = elt(env, 20); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = stack[-4];
    v376 = qcdr(v376);
    stack[-2] = qcar(v376);
    v378 = elt(env, 2); /* quotient */
    v377 = stack[-1];
    v376 = stack[-3];
    v376 = list3(v378, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = list2(stack[-2], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    {
        Lisp_Object v380 = stack[0];
        popv(8);
        fn = elt(env, 22); /* multsq */
        return (*qfn2(fn))(qenv(fn), v380, v376);
    }

v56:
    v377 = stack[-3];
    v376 = (Lisp_Object)17; /* 1 */
    if (!(v377 == v376)) goto v267;
    v377 = stack[-1];
    v376 = elt(env, 2); /* quotient */
    if (!consp(v377)) goto v267;
    v377 = qcar(v377);
    if (!(v377 == v376)) goto v267;
    v376 = stack[-1];
    v376 = qcdr(v376);
    v377 = qcar(v376);
    v376 = (Lisp_Object)17; /* 1 */
    if (!(v377 == v376)) goto v267;
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    v376 = qcar(v376);
    v376 = integerp(v376);
    if (v376 == nil) goto v267;
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    v377 = qcar(v376);
    v376 = (Lisp_Object)33; /* 2 */
    v377 = Cremainder(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = (Lisp_Object)1; /* 0 */
    if (v377 == v376) goto v36;
    else goto v267;

v267:
    v377 = stack[-1];
    v376 = (Lisp_Object)17; /* 1 */
    if (!(v377 == v376)) goto v91;
    v376 = stack[-3];
    v376 = integerp(v376);
    if (v376 == nil) goto v91;
    v376 = stack[-4];
    v376 = qcdr(v376);
    stack[0] = qcar(v376);
    v378 = elt(env, 2); /* quotient */
    v377 = stack[-1];
    v376 = stack[-3];
    v376 = list3(v378, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = list2(stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 23); /* negsq */
        return (*qfn1(fn))(qenv(fn), v376);
    }

v91:
    v376 = stack[-1];
    if (!(is_number(v376))) goto v15;
    v376 = stack[-3];
    if (!(is_number(v376))) goto v15;

v67:
    v376 = stack[-1];
    if (is_number(v376)) goto v200;
    v376 = stack[-1];
    if (!consp(v376)) goto v381;
    v376 = stack[-1];
    v377 = qcar(v376);
    v376 = elt(env, 11); /* minus */
    if (v377 == v376) goto v382;
    v376 = stack[-1];
    v377 = qcar(v376);
    v376 = elt(env, 12); /* plus */
    if (!(v377 == v376)) goto v383;
    v376 = qvalue(elt(env, 13)); /* !*expandexpt */
    if (v376 == nil) goto v383;
    v377 = (Lisp_Object)17; /* 1 */
    v376 = (Lisp_Object)17; /* 1 */
    v376 = cons(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-5] = v376;
    v376 = stack[-1];
    v376 = qcdr(v376);
    stack[-2] = v376;
    goto v384;

v384:
    v376 = stack[-2];
    if (v376 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    v376 = stack[-2];
    v376 = qcar(v376);
    stack[-1] = stack[-4];
    stack[0] = elt(env, 2); /* quotient */
    v377 = stack[-6];
    if (v377 == nil) goto v385;
    v377 = elt(env, 11); /* minus */
    v376 = list2(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v377 = v376;
    goto v386;

v386:
    v376 = stack[-3];
    v376 = list3(stack[0], v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = list2(stack[-1], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v377 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = stack[-5];
    fn = elt(env, 22); /* multsq */
    v376 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-5] = v376;
    v376 = stack[-2];
    v376 = qcdr(v376);
    stack[-2] = v376;
    goto v384;

v385:
    v377 = v376;
    goto v386;

v383:
    v376 = stack[-1];
    v377 = qcar(v376);
    v376 = elt(env, 15); /* times */
    if (!(v377 == v376)) goto v387;
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcar(v376);
    v376 = integerp(v376);
    if (v376 == nil) goto v387;
    v376 = stack[-3];
    if (is_number(v376)) goto v388;
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcar(v376);
    stack[-5] = v376;
    goto v389;

v389:
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    if (v376 == nil) goto v390;
    v377 = elt(env, 15); /* times */
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    v376 = cons(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    goto v391;

v391:
    stack[-1] = v376;
    goto v392;

v392:
    v376 = stack[-4];
    if (!(symbolp(v376))) goto v393;
    v377 = stack[-4];
    v376 = elt(env, 16); /* used!* */
    v376 = Lflagp(nil, v377, v376);
    env = stack[-7];
    if (!(v376 == nil)) goto v393;
    v376 = stack[-4];
    v377 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = elt(env, 16); /* used!* */
    v376 = Lflag(nil, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    goto v393;

v393:
    v377 = stack[-4];
    v376 = elt(env, 17); /* (minus 1) */
    if (!(equal(v377, v376))) goto v394;
    v377 = stack[-3];
    v376 = (Lisp_Object)17; /* 1 */
    if (!(v377 == v376)) goto v394;
    v378 = elt(env, 18); /* difference */
    v377 = stack[-1];
    v376 = elt(env, 19); /* (quotient 1 2) */
    v376 = list3(v378, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    fn = elt(env, 20); /* simp */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = qcar(v376);
    if (!(v376 == nil)) goto v394;
    v376 = elt(env, 4); /* i */
    fn = elt(env, 20); /* simp */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-4] = v376;
    v376 = stack[-6];
    if (v376 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v376 = stack[-4];
    {
        popv(8);
        fn = elt(env, 23); /* negsq */
        return (*qfn1(fn))(qenv(fn), v376);
    }

v394:
    stack[0] = elt(env, 3); /* expt */
    stack[-2] = stack[-4];
    v377 = stack[-3];
    v376 = (Lisp_Object)17; /* 1 */
    if (v377 == v376) goto v395;
    v378 = elt(env, 2); /* quotient */
    v377 = stack[-1];
    v376 = stack[-3];
    v376 = list3(v378, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    goto v396;

v396:
    v376 = list3(stack[0], stack[-2], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-4] = v376;
    stack[0] = stack[-4];
    v376 = stack[-6];
    if (v376 == nil) goto v397;
    v376 = stack[-5];
    v376 = negate(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    goto v398;

v398:
    {
        Lisp_Object v399 = stack[0];
        popv(8);
        fn = elt(env, 24); /* mksq */
        return (*qfn2(fn))(qenv(fn), v399, v376);
    }

v397:
    v376 = stack[-5];
    goto v398;

v395:
    v376 = stack[-1];
    goto v396;

v390:
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    v376 = qcar(v376);
    goto v391;

v388:
    v377 = stack[-3];
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcar(v376);
    v376 = Lgcd(nil, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-5] = v376;
    v377 = stack[-3];
    v376 = stack[-5];
    v376 = quot2(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-3] = v376;
    v376 = stack[-1];
    v376 = qcdr(v376);
    v377 = qcar(v376);
    v376 = stack[-5];
    v376 = quot2(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-5] = v376;
    goto v389;

v387:
    v376 = stack[-1];
    v377 = qcar(v376);
    v376 = elt(env, 2); /* quotient */
    if (!(v377 == v376)) goto v400;
    v377 = stack[-3];
    v376 = (Lisp_Object)17; /* 1 */
    if (!(v377 == v376)) goto v400;
    v376 = qvalue(elt(env, 13)); /* !*expandexpt */
    if (v376 == nil) goto v400;
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcdr(v376);
    v376 = qcar(v376);
    stack[-3] = v376;
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcar(v376);
    stack[-1] = v376;
    goto v67;

v400:
    v376 = (Lisp_Object)17; /* 1 */
    stack[-5] = v376;
    goto v392;

v382:
    v376 = stack[-1];
    v376 = qcdr(v376);
    v376 = qcar(v376);
    stack[-1] = v376;
    goto v101;

v101:
    v376 = qvalue(elt(env, 6)); /* !*mcd */
    if (v376 == nil) goto v401;
    v378 = stack[-4];
    v377 = stack[-1];
    v376 = stack[-3];
    v376 = CC_simpx1(env, 3, v378, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    {
        popv(8);
        fn = elt(env, 25); /* invsq */
        return (*qfn1(fn))(qenv(fn), v376);
    }

v401:
    v376 = stack[-6];
    v376 = (v376 == nil ? lisp_true : nil);
    stack[-6] = v376;
    goto v67;

v381:
    v376 = (Lisp_Object)17; /* 1 */
    stack[-5] = v376;
    goto v392;

v200:
    v376 = stack[-1];
    v376 = Lminusp(nil, v376);
    env = stack[-7];
    if (v376 == nil) goto v236;
    v376 = stack[-1];
    v376 = negate(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-1] = v376;
    goto v101;

v236:
    v376 = stack[-1];
    v376 = integerp(v376);
    if (v376 == nil) goto v402;
    v376 = stack[-3];
    v376 = integerp(v376);
    if (v376 == nil) goto v403;
    v376 = stack[-6];
    if (v376 == nil) goto v404;
    v376 = stack[-1];
    v376 = negate(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-1] = v376;
    goto v404;

v404:
    v376 = stack[-1];
    stack[-5] = v376;
    v376 = qvalue(elt(env, 6)); /* !*mcd */
    if (v376 == nil) goto v405;
    v376 = stack[-4];
    v376 = integerp(v376);
    if (!(v376 == nil)) goto v211;
    v376 = qvalue(elt(env, 7)); /* !*notseparate */
    if (!(v376 == nil)) goto v405;

v211:
    stack[-2] = stack[-5];
    stack[0] = stack[-3];
    v377 = stack[-1];
    v376 = stack[-3];
    v376 = quot2(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-1] = v376;
    v376 = times2(stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = difference2(stack[-2], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-5] = v376;
    v377 = stack[-5];
    v376 = (Lisp_Object)1; /* 0 */
    v376 = (Lisp_Object)lessp2(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    v376 = v376 ? lisp_true : nil;
    env = stack[-7];
    if (v376 == nil) goto v239;
    v376 = stack[-1];
    v376 = sub1(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-1] = v376;
    v377 = stack[-5];
    v376 = stack[-3];
    v376 = plus2(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-5] = v376;
    goto v239;

v239:
    v377 = stack[-4];
    v376 = stack[-1];
    v376 = list2(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    fn = elt(env, 21); /* simpexpt */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[0] = v376;
    v377 = stack[-5];
    v376 = (Lisp_Object)1; /* 0 */
    if (v377 == v376) { Lisp_Object res = stack[0]; popv(8); return onevalue(res); }
    v377 = stack[-3];
    v376 = (Lisp_Object)33; /* 2 */
    if (!(v377 == v376)) goto v406;
    v376 = qvalue(elt(env, 8)); /* !*keepsqrts */
    if (v376 == nil) goto v406;
    stack[-1] = stack[0];
    v377 = elt(env, 9); /* sqrt */
    v376 = elt(env, 10); /* simpfn */
    stack[0] = get(v377, v376);
    env = stack[-7];
    v376 = stack[-4];
    v376 = ncons(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = Lapply1(nil, stack[0], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    fn = elt(env, 22); /* multsq */
    v376 = (*qfn2(fn))(qenv(fn), stack[-1], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[0] = v376;
    v377 = stack[-5];
    v376 = (Lisp_Object)1; /* 0 */
    v376 = (Lisp_Object)lessp2(v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    v376 = v376 ? lisp_true : nil;
    env = stack[-7];
    if (v376 == nil) goto v407;
    v376 = stack[0];
    fn = elt(env, 25); /* invsq */
    v376 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[0] = v376;
    v376 = stack[-5];
    v376 = negate(v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    stack[-5] = v376;
    goto v407;

v407:
    v377 = stack[0];
    v376 = stack[-5];
    {
        popv(8);
        fn = elt(env, 26); /* exptsq */
        return (*qfn2(fn))(qenv(fn), v377, v376);
    }

v406:
    v376 = stack[-4];
    fn = elt(env, 27); /* simp!* */
    v377 = (*qfn1(fn))(qenv(fn), v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = stack[-3];
    fn = elt(env, 28); /* simprad */
    v377 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = stack[-5];
    fn = elt(env, 26); /* exptsq */
    v376 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    {
        Lisp_Object v408 = stack[0];
        popv(8);
        fn = elt(env, 22); /* multsq */
        return (*qfn2(fn))(qenv(fn), v408, v376);
    }

v405:
    v376 = (Lisp_Object)1; /* 0 */
    stack[-1] = v376;
    goto v239;

v403:
    v376 = stack[-1];
    stack[-5] = v376;
    v376 = (Lisp_Object)17; /* 1 */
    stack[-1] = v376;
    goto v392;

v402:
    v376 = (Lisp_Object)17; /* 1 */
    stack[-5] = v376;
    goto v392;

v15:
    v377 = qvalue(elt(env, 5)); /* frlis!* */
    v376 = stack[-1];
    fn = elt(env, 29); /* smemqlp */
    v376 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    if (!(v376 == nil)) goto v409;
    v377 = qvalue(elt(env, 5)); /* frlis!* */
    v376 = stack[-3];
    fn = elt(env, 29); /* smemqlp */
    v376 = (*qfn2(fn))(qenv(fn), v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    if (v376 == nil) goto v67;
    else goto v409;

v409:
    stack[0] = elt(env, 3); /* expt */
    stack[-2] = stack[-4];
    v377 = stack[-3];
    v376 = (Lisp_Object)17; /* 1 */
    if (v377 == v376) goto v215;
    v378 = elt(env, 2); /* quotient */
    v377 = stack[-1];
    v376 = stack[-3];
    v376 = list3(v378, v377, v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    goto v19;

v19:
    v377 = list3(stack[0], stack[-2], v376);
    nil = C_nil;
    if (exception_pending()) goto v379;
    env = stack[-7];
    v376 = (Lisp_Object)17; /* 1 */
    {
        popv(8);
        fn = elt(env, 24); /* mksq */
        return (*qfn2(fn))(qenv(fn), v377, v376);
    }

v215:
    v376 = stack[-1];
    goto v19;
/* error exit handlers */
v379:
    popv(8);
    return nil;
}



setup_type const u35_setup[] =
{
    {"cl_apply2ats1",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_apply2ats1},
    {"depend-p",                too_few_2,      CC_dependKp,   wrong_no_2},
    {"gb_buch-ev_divides?",     too_few_2,      CC_gb_buchKev_dividesW,wrong_no_2},
    {"copy_vect",               too_few_2,      CC_copy_vect,  wrong_no_2},
    {"nestzerop:",              CC_nestzeropT,  too_many_1,    wrong_no_1},
    {"fortassign",              CC_fortassign,  too_many_1,    wrong_no_1},
    {"mk_names_map_2",          CC_mk_names_map_2,too_many_1,  wrong_no_1},
    {"fs:prin:",                CC_fsTprinT,    too_many_1,    wrong_no_1},
    {"lf=zero",                 CC_lfMzero,     too_many_1,    wrong_no_1},
    {"make-x-to-p",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKxKtoKp},
    {"mktag",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktag},
    {"get_dimension_in",        CC_get_dimension_in,too_many_1,wrong_no_1},
    {"rl_surep",                too_few_2,      CC_rl_surep,   wrong_no_2},
    {"vdpcleanup",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpcleanup},
    {"gfquotient",              too_few_2,      CC_gfquotient, wrong_no_2},
    {"symmetrize-inds",         too_few_2,      CC_symmetrizeKinds,wrong_no_2},
    {"dv_skelsplit",            CC_dv_skelsplit,too_many_1,    wrong_no_1},
    {"repartf",                 CC_repartf,     too_many_1,    wrong_no_1},
    {"ieval",                   CC_ieval,       too_many_1,    wrong_no_1},
    {"diford",                  CC_diford,      too_many_1,    wrong_no_1},
    {"solvealgtrig01",          too_few_2,      CC_solvealgtrig01,wrong_no_2},
    {"groebmakepair",           too_few_2,      CC_groebmakepair,wrong_no_2},
    {":log2",                   CC_Tlog2,       too_many_1,    wrong_no_1},
    {"ev-poles",                too_few_2,      CC_evKpoles,   wrong_no_2},
    {"precision1",              too_few_2,      CC_precision1, wrong_no_2},
    {"max-degree",              too_few_2,      CC_maxKdegree, wrong_no_2},
    {"fctrf1",                  CC_fctrf1,      too_many_1,    wrong_no_1},
    {"change+sq+to+int",        CC_changeLsqLtoLint,too_many_1,wrong_no_1},
    {"ofsf_optfindeqsol",       too_few_2,      CC_ofsf_optfindeqsol,wrong_no_2},
    {"ldf-sep-var",             CC_ldfKsepKvar, too_many_1,    wrong_no_1},
    {"setprev",                 too_few_2,      CC_setprev,    wrong_no_2},
    {"dipretimes",              CC_dipretimes,  too_many_1,    wrong_no_1},
    {"xpartitsq",               CC_xpartitsq,   too_many_1,    wrong_no_1},
    {":log10",                  CC_Tlog10,      too_many_1,    wrong_no_1},
    {"markedvarp",              CC_markedvarp,  too_many_1,    wrong_no_1},
    {"indordlp",                too_few_2,      CC_indordlp,   wrong_no_2},
    {"new_prove",               too_few_2,      CC_new_prove,  wrong_no_2},
    {"red_redpol",              too_few_2,      CC_red_redpol, wrong_no_2},
    {"st_extract_symcells1",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_st_extract_symcells1},
    {"evalleq",                 too_few_2,      CC_evalleq,    wrong_no_2},
    {"simpx1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_simpx1},
    {NULL, (one_args *)"u35", (two_args *)"12259 1408392 9102295", 0}
};

/* end of generated code */
