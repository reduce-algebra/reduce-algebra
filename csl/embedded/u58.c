
/* $destdir/generated-c\u58.c Machine generated C code */

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


/* Code for dv_fill_comp_info */

static Lisp_Object MS_CDECL CC_dv_fill_comp_info(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v4, Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v57, v58, v59;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 6, "dv_fill_comp_info");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dv_fill_comp_info");
#endif
    if (stack >= stacklimit)
    {
        push6(v5,v4,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v0,v1,v2,v3,v4,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v5;
    stack[-2] = v4;
    stack[-3] = v3;
    stack[0] = v2;
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v58 = stack[0];
    v57 = (Lisp_Object)17; /* 1 */
    if (v58 == v57) goto v60;
    v57 = stack[-1];
    if (!(v57 == nil)) goto v61;
    v57 = stack[-4];
    fn = elt(env, 3); /* last_part_kern */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-1] = v57;
    stack[-2] = stack[-1];
    stack[-1] = stack[-5];
    v57 = stack[0];
    v57 = sub1(v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL)));
    fn = elt(env, 4); /* sc_kern */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    fn = elt(env, 5); /* pa_coinc_split */
    v57 = (*qfn2(fn))(qenv(fn), stack[-2], v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-1] = v57;
    stack[-2] = stack[-5];
    v57 = stack[0];
    v57 = sub1(v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL)));
    fn = elt(env, 6); /* sc_rep */
    v58 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = stack[-1];
    v57 = qcar(v57);
    v57 = cons(v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-2] = v57;
    v57 = stack[-1];
    v57 = qcdr(v57);
    stack[-1] = v57;
    goto v61;

v61:
    v57 = stack[-4];
    v57 = qcdr(v57);
    v58 = qcar(v57);
    v57 = (Lisp_Object)17; /* 1 */
    stack[-6] = *(Lisp_Object *)((char *)v58 + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL)));
    v57 = stack[0];
    v58 = sub1(v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = stack[-2];
    *(Lisp_Object *)((char *)stack[-6] + (CELL-TAG_VECTOR) + ((int32_t)v58/(16/CELL))) = v57;
    v57 = stack[0];
    v57 = add1(v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-6] = v57;
    goto v63;

v63:
    stack[0] = stack[-6];
    v57 = stack[-5];
    fn = elt(env, 7); /* upbve */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = (Lisp_Object)lesseq2(stack[0], v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    v57 = v57 ? lisp_true : nil;
    env = stack[-7];
    if (v57 == nil) goto v64;
    stack[0] = stack[-5];
    v57 = stack[-6];
    v57 = sub1(v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL)));
    fn = elt(env, 4); /* sc_kern */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    fn = elt(env, 5); /* pa_coinc_split */
    v57 = (*qfn2(fn))(qenv(fn), stack[-1], v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-1] = v57;
    stack[0] = stack[-5];
    v57 = stack[-6];
    v57 = sub1(v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL)));
    fn = elt(env, 6); /* sc_rep */
    v58 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = stack[-1];
    v57 = qcar(v57);
    v57 = cons(v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-2] = v57;
    v57 = stack[-1];
    v57 = qcdr(v57);
    stack[-1] = v57;
    v57 = stack[-4];
    v57 = qcdr(v57);
    v58 = qcar(v57);
    v57 = (Lisp_Object)17; /* 1 */
    stack[0] = *(Lisp_Object *)((char *)v58 + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL)));
    v57 = stack[-6];
    v58 = sub1(v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = stack[-2];
    *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v58/(16/CELL))) = v57;
    v57 = stack[-6];
    v57 = add1(v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-6] = v57;
    goto v63;

v64:
    v57 = stack[-4];
    stack[0] = qcdr(v57);
    v58 = stack[-1];
    v57 = stack[-4];
    v57 = qcdr(v57);
    v57 = qcdr(v57);
    v57 = cons(v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = Lrplacd(nil, stack[0], v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[0] = stack[-6];
    v57 = stack[-3];
    v57 = add1(v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    if (!(equal(stack[0], v57))) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    v57 = stack[-4];
    v57 = qcdr(v57);
    v58 = qcar(v57);
    v57 = (Lisp_Object)1; /* 0 */
    v57 = *(Lisp_Object *)((char *)v58 + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL)));
    if (!(v57 == nil)) goto v65;
    v57 = stack[-1];
    fn = elt(env, 8); /* dv_null_first_kern */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    if (v57 == nil) goto v65;
    v57 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = v57; /* g_skip_to_level */
    v58 = stack[-4];
    v57 = (Lisp_Object)33; /* 2 */
    v57 = Lrplaca(nil, v58, v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v65:
    v57 = stack[-4];
    v57 = qcdr(v57);
    stack[-2] = qcar(v57);
    stack[0] = (Lisp_Object)1; /* 0 */
    v57 = stack[-5];
    fn = elt(env, 9); /* fullcopy */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v57;
    v57 = stack[-4];
    v57 = qcdr(v57);
    v59 = qcar(v57);
    v58 = (Lisp_Object)33; /* 2 */
    v57 = stack[-1];
    *(Lisp_Object *)((char *)v59 + (CELL-TAG_VECTOR) + ((int32_t)v58/(16/CELL))) = v57;
    { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }

v60:
    v58 = stack[-5];
    v57 = (Lisp_Object)1; /* 0 */
    v57 = *(Lisp_Object *)((char *)v58 + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL)));
    fn = elt(env, 4); /* sc_kern */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-1] = v57;
    v58 = stack[-5];
    v57 = (Lisp_Object)1; /* 0 */
    v57 = *(Lisp_Object *)((char *)v58 + (CELL-TAG_VECTOR) + ((int32_t)v57/(16/CELL)));
    fn = elt(env, 6); /* sc_rep */
    v57 = (*qfn1(fn))(qenv(fn), v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    v57 = ncons(v57);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-7];
    stack[-2] = v57;
    goto v61;
/* error exit handlers */
v62:
    popv(8);
    return nil;
}



/* Code for modroots4 */

static Lisp_Object MS_CDECL CC_modroots4(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v68, v69, v70, v71;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "modroots4");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modroots4");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v71 = v2;
    v69 = v1;
    v70 = v0;
/* end of prologue */

v72:
    v68 = v70;
    if (!consp(v68)) goto v73;
    v68 = v70;
    v68 = qcar(v68);
    if (!consp(v68)) goto v73;
    v68 = v70;
    v68 = qcdr(v68);
    v70 = v68;
    v68 = v69;
    v68 = (v68 == nil ? lisp_true : nil);
    v69 = v68;
    goto v72;

v73:
    v68 = v70;
    if (v68 == nil) goto v74;
    v68 = v69;
    v68 = (v68 == nil ? lisp_true : nil);
    v69 = v68;
    goto v74;

v74:
    v68 = v70;
    if (v68 == nil) goto v75;
    v68 = nil;
    goto v76;

v76:
    if (v69 == nil) goto v51;
    v69 = v71;
    if (v69 == nil) goto v77;
    v69 = elt(env, 2); /* (-1 1) */
    goto v78;

v78:
        return Lappend(nil, v68, v69);

v77:
    v69 = elt(env, 3); /* (1) */
    goto v78;

v51:
    v69 = nil;
    goto v78;

v75:
    v68 = elt(env, 1); /* (0) */
    goto v76;
}



/* Code for make!-univariate!-mod!-p */

static Lisp_Object MS_CDECL CC_makeKunivariateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v87, v88;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "make-univariate-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-univariate-mod-p");
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
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    v86 = stack[-3];
    if (!consp(v86)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v86 = stack[-3];
    v86 = qcar(v86);
    if (!consp(v86)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v86 = stack[-3];
    v86 = qcar(v86);
    v86 = qcar(v86);
    v87 = qcar(v86);
    v86 = stack[-1];
    if (equal(v87, v86)) goto v78;
    v87 = stack[-3];
    v86 = stack[-2];
    fn = elt(env, 1); /* evaluate!-in!-order!-mod!-p */
    v86 = (*qfn2(fn))(qenv(fn), v87, v86);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 2); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v86);
    }

v78:
    v86 = stack[-3];
    v86 = qcar(v86);
    stack[-4] = qcar(v86);
    v86 = stack[-3];
    v86 = qcar(v86);
    v87 = qcdr(v86);
    v86 = stack[-2];
    fn = elt(env, 1); /* evaluate!-in!-order!-mod!-p */
    v86 = (*qfn2(fn))(qenv(fn), v87, v86);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    fn = elt(env, 2); /* !*n2f */
    stack[0] = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    v86 = stack[-3];
    v88 = qcdr(v86);
    v87 = stack[-2];
    v86 = stack[-1];
    v86 = CC_makeKunivariateKmodKp(env, 3, v88, v87, v86);
    nil = C_nil;
    if (exception_pending()) goto v89;
    env = stack[-5];
    {
        Lisp_Object v90 = stack[-4];
        Lisp_Object v44 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v90, v44, v86);
    }
/* error exit handlers */
v89:
    popv(6);
    return nil;
}



/* Code for taylor!-add!-to!-cache */

static Lisp_Object MS_CDECL CC_taylorKaddKtoKcache(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "taylor-add-to-cache");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taylor-add-to-cache");
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
    v97 = v0;
/* end of prologue */
    v96 = qvalue(elt(env, 1)); /* !*taylornocache */
    if (v96 == nil) goto v98;
    v96 = nil;
    { popv(5); return onevalue(v96); }

v98:
    stack[-3] = qvalue(elt(env, 2)); /* !*taylor!-assoc!-list!* */
    stack[0] = v97;
    v96 = qvalue(elt(env, 3)); /* nil */
    v96 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    v97 = ncons(v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    v96 = stack[-2];
    v96 = Lsubla(nil, v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    v77 = list2(stack[0], v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    v97 = stack[-1];
    v96 = qvalue(elt(env, 2)); /* !*taylor!-assoc!-list!* */
    v96 = qcar(v96);
    v96 = acons(v77, v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-4];
    {
        Lisp_Object v100 = stack[-3];
        popv(5);
        fn = elt(env, 4); /* setcar */
        return (*qfn2(fn))(qenv(fn), v100, v96);
    }
/* error exit handlers */
v99:
    popv(5);
    return nil;
}



/* Code for ctx_union */

static Lisp_Object CC_ctx_union(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v105;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ctx_union");
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
    v104 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 3); /* setkorder */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[0] = v104;
    v104 = stack[0];
    fn = elt(env, 3); /* setkorder */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    v104 = stack[-3];
    fn = elt(env, 4); /* ctx_ial */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-3] = v104;
    v104 = stack[-2];
    fn = elt(env, 4); /* ctx_ial */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-2] = v104;
    v104 = stack[0];
    stack[-1] = v104;
    goto v107;

v107:
    v104 = stack[-1];
    if (v104 == nil) goto v108;
    v104 = stack[-1];
    v104 = qcar(v104);
    stack[0] = v104;
    v104 = stack[-3];
    if (v104 == nil) goto v109;
    v104 = stack[-3];
    v104 = qcar(v104);
    v105 = qcar(v104);
    v104 = stack[0];
    if (!(v105 == v104)) goto v109;
    v104 = stack[-3];
    v105 = qcar(v104);
    v104 = stack[-4];
    v104 = cons(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-4] = v104;
    v104 = stack[-3];
    v104 = qcdr(v104);
    stack[-3] = v104;
    v104 = stack[-2];
    if (v104 == nil) goto v95;
    v104 = stack[-2];
    v104 = qcar(v104);
    v105 = qcar(v104);
    v104 = stack[0];
    if (!(v105 == v104)) goto v95;
    v104 = stack[-2];
    v104 = qcdr(v104);
    stack[-2] = v104;
    goto v95;

v95:
    v104 = stack[-1];
    v104 = qcdr(v104);
    stack[-1] = v104;
    goto v107;

v109:
    v104 = stack[-2];
    if (v104 == nil) goto v95;
    v104 = stack[-2];
    v104 = qcar(v104);
    v105 = qcar(v104);
    v104 = stack[0];
    if (!(v105 == v104)) goto v95;
    v104 = stack[-2];
    v105 = qcar(v104);
    v104 = stack[-4];
    v104 = cons(v105, v104);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-4] = v104;
    v104 = stack[-2];
    v104 = qcdr(v104);
    stack[-2] = v104;
    goto v95;

v108:
    v104 = stack[-3];
    if (!(v104 == nil)) goto v110;
    v104 = stack[-2];
    if (!(v104 == nil)) goto v110;

v111:
    v104 = stack[-4];
    v104 = Lnreverse(nil, v104);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 5); /* ctx_fromial */
        return (*qfn1(fn))(qenv(fn), v104);
    }

v110:
    v104 = elt(env, 2); /* "***** ctx_union: idorder not complete" */
    fn = elt(env, 6); /* prin2t */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    goto v111;
/* error exit handlers */
v106:
    popv(6);
    return nil;
}



/* Code for cd_surep */

static Lisp_Object CC_cd_surep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v113, v55, v56;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cd_surep");
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
    v55 = v1;
    v56 = v0;
/* end of prologue */
    stack[-2] = qvalue(elt(env, 1)); /* !*rlgsvb */
    qvalue(elt(env, 1)) = nil; /* !*rlgsvb */
    v113 = qvalue(elt(env, 2)); /* !*cgbgs */
    v107 = qvalue(elt(env, 3)); /* t */
    stack[-1] = qvalue(elt(env, 4)); /* !*rlspgs */
    qvalue(elt(env, 4)) = v113; /* !*rlspgs */
    stack[0] = qvalue(elt(env, 5)); /* !*rlsithok */
    qvalue(elt(env, 5)) = v107; /* !*rlsithok */
    v107 = v56;
    v113 = v55;
    fn = elt(env, 6); /* rl_surep */
    v107 = (*qfn2(fn))(qenv(fn), v107, v113);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; /* !*rlsithok */
    qvalue(elt(env, 4)) = stack[-1]; /* !*rlspgs */
    qvalue(elt(env, 1)) = stack[-2]; /* !*rlgsvb */
    { popv(4); return onevalue(v107); }
/* error exit handlers */
v85:
    env = stack[-3];
    qvalue(elt(env, 5)) = stack[0]; /* !*rlsithok */
    qvalue(elt(env, 4)) = stack[-1]; /* !*rlspgs */
    qvalue(elt(env, 1)) = stack[-2]; /* !*rlgsvb */
    popv(4);
    return nil;
}



/* Code for numlistp */

static Lisp_Object CC_numlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113, v55;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numlistp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v113 = v0;
/* end of prologue */

v114:
    v55 = v113;
    v55 = (v55 == nil ? lisp_true : nil);
    if (!(v55 == nil)) return onevalue(v55);
    v55 = v113;
    v55 = qcar(v55);
    if (is_number(v55)) goto v115;
    v113 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v113);

v115:
    v113 = qcdr(v113);
    goto v114;
}



/* Code for groeblistadd */

static Lisp_Object CC_groeblistadd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v118, v119, v66;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeblistadd");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v119 = v1;
    v66 = v0;
/* end of prologue */
    v118 = qvalue(elt(env, 1)); /* hcount!* */
    v109 = (Lisp_Object)80001; /* 5000 */
    if (((int32_t)(v118)) < ((int32_t)(v109))) goto v91;
    v109 = v66;
    v118 = v119;
    {
        fn = elt(env, 2); /* vdplsortinreplacing */
        return (*qfn2(fn))(qenv(fn), v109, v118);
    }

v91:
    v109 = v66;
    v118 = v119;
    {
        fn = elt(env, 3); /* vdplsortin */
        return (*qfn2(fn))(qenv(fn), v109, v118);
    }
}



/* Code for rd!:quotient */

static Lisp_Object CC_rdTquotient(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v143, v144;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rd:quotient");
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
    v142 = stack[-1];
    fn = elt(env, 9); /* !:zerop */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    if (v142 == nil) goto v55;
    v144 = elt(env, 1); /* arith */
    v143 = (Lisp_Object)113; /* 7 */
    v142 = elt(env, 2); /* "division by zero" */
    {
        popv(5);
        fn = elt(env, 10); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v144, v143, v142);
    }

v55:
    v142 = qvalue(elt(env, 4)); /* !*!*roundbf */
    if (!(v142 == nil)) goto v146;
    v142 = stack[-2];
    v142 = qcdr(v142);
    if (!(!consp(v142))) goto v146;
    v142 = stack[-1];
    v142 = qcdr(v142);
    if (!(!consp(v142))) goto v146;
    v142 = stack[-2];
    v143 = qcdr(v142);
    v142 = stack[-1];
    v142 = qcdr(v142);
    fn = elt(env, 11); /* safe!-fp!-quot */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[0] = v142;
    if (v142 == nil) goto v146;
    v143 = elt(env, 5); /* !:rd!: */
    v142 = stack[0];
    popv(5);
    return cons(v143, v142);

v146:
    v143 = stack[-2];
    v142 = stack[-1];
    fn = elt(env, 12); /* convprc2 */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[-3] = v142;
    v142 = qvalue(elt(env, 6)); /* yy!! */
    stack[-2] = v142;
    v142 = stack[-3];
    if (!(!consp(v142))) goto v86;
    v142 = stack[-2];
    v142 = (Lisp_Object)zerop(v142);
    v142 = v142 ? lisp_true : nil;
    env = stack[-4];
    if (v142 == nil) goto v86;
    fn = elt(env, 13); /* rdqoterr */
    v142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    goto v86;

v86:
    v142 = stack[-3];
    if (!consp(v142)) goto v147;
    v142 = stack[-2];
    v142 = qcdr(v142);
    v143 = qcar(v142);
    v142 = (Lisp_Object)1; /* 0 */
    if (v143 == v142) goto v148;
    v144 = stack[-3];
    v143 = stack[-2];
    v142 = qvalue(elt(env, 7)); /* !:bprec!: */
    fn = elt(env, 14); /* divide!: */
    v142 = (*qfnn(fn))(qenv(fn), 3, v144, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    fn = elt(env, 15); /* csl_normbf */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    goto v149;

v149:
    {
        popv(5);
        fn = elt(env, 16); /* mkround */
        return (*qfn1(fn))(qenv(fn), v142);
    }

v148:
    fn = elt(env, 13); /* rdqoterr */
    v142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    goto v149;

v147:
    stack[-1] = elt(env, 8); /* quotient */
    v142 = stack[-3];
    stack[0] = Lmkquote(nil, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v142 = stack[-2];
    v142 = Lmkquote(nil, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v143 = list3(stack[-1], stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v142 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 17); /* errorset!* */
    v142 = (*qfn2(fn))(qenv(fn), v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[0] = v142;
    v142 = stack[0];
    fn = elt(env, 18); /* errorp */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    if (v142 == nil) goto v14;
    fn = elt(env, 19); /* rndbfon */
    v142 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v142 = stack[-3];
    v142 = Lfloatp(nil, v142);
    env = stack[-4];
    if (v142 == nil) goto v150;
    v142 = stack[-3];
    fn = elt(env, 20); /* fl2bf */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[0] = v142;
    goto v28;

v28:
    v142 = stack[-2];
    v142 = Lfloatp(nil, v142);
    env = stack[-4];
    if (v142 == nil) goto v151;
    v142 = stack[-2];
    fn = elt(env, 20); /* fl2bf */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v143 = v142;
    goto v152;

v152:
    v142 = qvalue(elt(env, 7)); /* !:bprec!: */
    fn = elt(env, 14); /* divide!: */
    v142 = (*qfnn(fn))(qenv(fn), 3, stack[0], v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    fn = elt(env, 15); /* csl_normbf */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    goto v149;

v151:
    v142 = stack[-2];
    if (!consp(v142)) goto v153;
    v142 = stack[-2];
    goto v22;

v22:
    fn = elt(env, 15); /* csl_normbf */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    v143 = v142;
    goto v152;

v153:
    v142 = stack[-2];
    v142 = integerp(v142);
    if (v142 == nil) goto v154;
    v144 = elt(env, 5); /* !:rd!: */
    v143 = stack[-2];
    v142 = (Lisp_Object)1; /* 0 */
    v142 = list2star(v144, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    goto v22;

v154:
    v142 = stack[-2];
    fn = elt(env, 21); /* read!:num */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    goto v22;

v150:
    v142 = stack[-3];
    if (!consp(v142)) goto v155;
    v142 = stack[-3];
    goto v156;

v156:
    fn = elt(env, 15); /* csl_normbf */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    stack[0] = v142;
    goto v28;

v155:
    v142 = stack[-3];
    v142 = integerp(v142);
    if (v142 == nil) goto v64;
    v144 = elt(env, 5); /* !:rd!: */
    v143 = stack[-3];
    v142 = (Lisp_Object)1; /* 0 */
    v142 = list2star(v144, v143, v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    goto v156;

v64:
    v142 = stack[-3];
    fn = elt(env, 21); /* read!:num */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v145;
    env = stack[-4];
    goto v156;

v14:
    v142 = stack[0];
    v142 = qcar(v142);
    goto v149;
/* error exit handlers */
v145:
    popv(5);
    return nil;
}



/* Code for lispcondp */

static Lisp_Object CC_lispcondp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v157;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispcondp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v98 = v0;
/* end of prologue */
    v157 = elt(env, 1); /* cond */
        return Leqcar(nil, v98, v157);
}



/* Code for physopapply */

static Lisp_Object CC_physopapply(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v219, v220;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for physopapply");
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
    stack[-2] = v0;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    v218 = stack[-2];
    v218 = qcar(v218);
    fn = elt(env, 14); /* statep!* */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-5] = v218;
    v218 = stack[-2];
    v218 = qcdr(v218);
    v218 = qcar(v218);
    fn = elt(env, 14); /* statep!* */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v219 = v218;
    v218 = v219;
    if (v218 == nil) goto v60;
    v218 = stack[-5];
    if (v218 == nil) goto v60;
    v218 = stack[-2];
    v219 = qcar(v218);
    v218 = stack[-2];
    v218 = qcdr(v218);
    v218 = qcar(v218);
    {
        popv(7);
        fn = elt(env, 15); /* statemult */
        return (*qfn2(fn))(qenv(fn), v219, v218);
    }

v60:
    v218 = v219;
    if (v218 == nil) goto v67;
    v218 = stack[-2];
    v218 = qcdr(v218);
    v218 = qcar(v218);
    fn = elt(env, 16); /* physopsim!* */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 17); /* physopaeval */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-4] = v218;
    v218 = stack[-2];
    v218 = qcar(v218);
    fn = elt(env, 16); /* physopsim!* */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 17); /* physopaeval */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-3] = v218;
    goto v56;

v56:
    v218 = stack[-3];
    fn = elt(env, 18); /* getphystype */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    if (v218 == nil) goto v38;
    v218 = stack[-3];
    fn = elt(env, 19); /* physopp */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    if (v218 == nil) goto v104;
    v219 = stack[-3];
    v218 = elt(env, 12); /* unit */
    if (v219 == v218) goto v222;
    v218 = stack[-4];
    fn = elt(env, 19); /* physopp */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    if (!(v218 == nil)) goto v223;
    v218 = stack[-4];
    v219 = qcar(v218);
    v218 = elt(env, 13); /* physopmapping */
    v218 = Lflagp(nil, v219, v218);
    env = stack[-6];
    if (v218 == nil) goto v224;
    v218 = stack[-4];
    v218 = qcdr(v218);
    fn = elt(env, 14); /* statep!* */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    if (!(v218 == nil)) goto v223;

v224:
    v218 = stack[-4];
    stack[-2] = v218;
    v218 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = v218;
    goto v225;

v225:
    v218 = stack[-2];
    if (v218 == nil) goto v226;
    v218 = stack[-2];
    v218 = qcar(v218);
    stack[-1] = v218;
    v218 = stack[-2];
    v218 = qcdr(v218);
    stack[-2] = v218;
    v218 = stack[-1];
    fn = elt(env, 14); /* statep!* */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    if (v218 == nil) goto v227;
    v219 = stack[-3];
    v218 = stack[-1];
    v218 = list2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = CC_physopapply(env, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 17); /* physopaeval */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = ncons(v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = Lnconc(nil, stack[-4], v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-4] = v218;
    goto v228;

v228:
    v218 = qvalue(elt(env, 6)); /* !*hardstop */
    if (v218 == nil) goto v229;
    v218 = qvalue(elt(env, 7)); /* t */
    stack[0] = v218;
    goto v229;

v229:
    v218 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 6)) = v218; /* !*hardstop */
    goto v225;

v227:
    v218 = stack[-1];
    v218 = ncons(v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = Lnconc(nil, stack[-4], v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-4] = v218;
    goto v228;

v226:
    v218 = stack[0];
    if (v218 == nil) goto v230;
    v218 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 6)) = v218; /* !*hardstop */
    goto v230;

v230:
    v218 = stack[-4];
    fn = elt(env, 20); /* physop2sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 21); /* mk!*sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v223:
    v220 = elt(env, 2); /* opapply */
    v219 = stack[-3];
    v218 = stack[-4];
    v218 = list3(v220, v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 22); /* opmtch!* */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-2] = v218;
    v218 = stack[-2];
    if (!(v218 == nil)) goto v231;
    stack[-1] = elt(env, 2); /* opapply */
    v218 = stack[-4];
    fn = elt(env, 23); /* adjp */
    stack[0] = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = stack[-3];
    fn = elt(env, 23); /* adjp */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = list3(stack[-1], stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 22); /* opmtch!* */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = ncons(v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 24); /* physopadj */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-2] = v218;
    goto v231;

v231:
    v218 = stack[-2];
    if (v218 == nil) goto v232;
    v218 = stack[-2];
    fn = elt(env, 20); /* physop2sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 21); /* mk!*sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v232:
    v218 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 6)) = v218; /* !*hardstop */
    v220 = elt(env, 2); /* opapply */
    v219 = stack[-3];
    v218 = stack[-4];
    v219 = list3(v220, v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 25); /* to */
    v219 = (*qfn2(fn))(qenv(fn), v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = (Lisp_Object)17; /* 1 */
    v218 = cons(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v219 = ncons(v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = (Lisp_Object)17; /* 1 */
    v218 = cons(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 21); /* mk!*sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v222:
    v218 = stack[-4];
    fn = elt(env, 20); /* physop2sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 21); /* mk!*sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v104:
    v218 = stack[-3];
    v219 = qcar(v218);
    v218 = elt(env, 4); /* minus */
    if (v219 == v218) goto v33;
    v218 = stack[-3];
    v219 = qcar(v218);
    v218 = elt(env, 5); /* (plus difference) */
    v218 = Lmemq(nil, v219, v218);
    if (v218 == nil) goto v17;
    v218 = stack[-3];
    v218 = qcdr(v218);
    stack[-2] = v218;
    goto v31;

v31:
    v218 = stack[-2];
    if (v218 == nil) goto v30;
    v218 = stack[-2];
    v218 = qcar(v218);
    v219 = v218;
    v218 = stack[-4];
    v218 = list2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = CC_physopapply(env, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = ncons(v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = Lnconc(nil, stack[-1], v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-1] = v218;
    v218 = qvalue(elt(env, 6)); /* !*hardstop */
    if (v218 == nil) goto v64;
    v218 = qvalue(elt(env, 7)); /* t */
    stack[0] = v218;
    goto v64;

v64:
    v218 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 6)) = v218; /* !*hardstop */
    v218 = stack[-2];
    v218 = qcdr(v218);
    stack[-2] = v218;
    goto v31;

v30:
    v218 = stack[0];
    if (v218 == nil) goto v233;
    v218 = qvalue(elt(env, 7)); /* t */
    qvalue(elt(env, 6)) = v218; /* !*hardstop */
    goto v233;

v233:
    v218 = stack[-3];
    v219 = qcar(v218);
    v218 = stack[-1];
    v218 = cons(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 26); /* reval3 */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v17:
    v218 = stack[-3];
    v219 = qcar(v218);
    v218 = elt(env, 8); /* (dot commute anticommute expt) */
    v218 = Lmemq(nil, v219, v218);
    if (v218 == nil) goto v234;
    v218 = stack[-3];
    fn = elt(env, 16); /* physopsim!* */
    v219 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = stack[-4];
    v218 = list2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = CC_physopapply(env, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v234:
    v218 = stack[-3];
    v219 = qcar(v218);
    v218 = elt(env, 9); /* quotient */
    if (v219 == v218) goto v143;
    v218 = stack[-3];
    v219 = qcar(v218);
    v218 = elt(env, 10); /* times */
    if (v219 == v218) goto v235;
    v219 = elt(env, 2); /* opapply */
    v218 = elt(env, 11); /* "invalid operator to opapply" */
    fn = elt(env, 27); /* rederr2 */
    v218 = (*qfn2(fn))(qenv(fn), v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v235:
    v218 = stack[-3];
    v218 = qcdr(v218);
    v218 = Lreverse(nil, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-3] = v218;
    goto v236;

v236:
    v218 = stack[-3];
    if (v218 == nil) goto v237;
    v218 = qvalue(elt(env, 6)); /* !*hardstop */
    if (!(v218 == nil)) goto v237;
    v218 = stack[-3];
    v218 = qcar(v218);
    stack[-2] = v218;
    v218 = stack[-3];
    v218 = qcdr(v218);
    stack[-3] = v218;
    v219 = stack[-2];
    v218 = stack[-4];
    v218 = list2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = CC_physopapply(env, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-4] = v218;
    goto v236;

v237:
    v218 = qvalue(elt(env, 6)); /* !*hardstop */
    if (v218 == nil) goto v238;
    v218 = stack[-3];
    if (v218 == nil) goto v239;
    v218 = stack[-4];
    fn = elt(env, 17); /* physopaeval */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-2] = v218;
    stack[0] = elt(env, 10); /* times */
    v218 = stack[-3];
    v218 = Lreverse(nil, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = cons(stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-3] = v218;
    goto v240;

v240:
    v218 = stack[-2];
    if (v218 == nil) goto v241;
    v218 = stack[-2];
    v218 = qcar(v218);
    stack[-5] = v218;
    v218 = stack[-2];
    v218 = qcdr(v218);
    stack[-2] = v218;
    v218 = stack[-5];
    fn = elt(env, 28); /* listp */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    if (v218 == nil) goto v240;
    v219 = elt(env, 2); /* opapply */
    v218 = stack[-5];
    v218 = Lassoc(nil, v219, v218);
    stack[-5] = v218;
    if (v218 == nil) goto v240;
    stack[-1] = elt(env, 2); /* opapply */
    stack[0] = stack[-3];
    v218 = stack[-5];
    v218 = qcdr(v218);
    v218 = qcar(v218);
    v218 = ncons(v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v219 = Lnconc(nil, stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = stack[-5];
    v218 = qcdr(v218);
    v218 = qcdr(v218);
    v218 = qcar(v218);
    v218 = list3(stack[-1], v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-1] = v218;
    v220 = stack[-1];
    v219 = stack[-5];
    v218 = stack[-4];
    v218 = Lsubst(nil, 3, v220, v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-4] = v218;
    goto v240;

v241:
    v218 = stack[-4];
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v239:
    v218 = stack[-4];
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v238:
    v218 = stack[-4];
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v143:
    v218 = stack[-3];
    v218 = qcdr(v218);
    v218 = qcdr(v218);
    v218 = qcar(v218);
    fn = elt(env, 19); /* physopp */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    if (v218 == nil) goto v58;
    v218 = stack[-3];
    fn = elt(env, 16); /* physopsim!* */
    v219 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = stack[-4];
    v218 = list2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = CC_physopapply(env, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v58:
    v218 = stack[-3];
    v218 = qcdr(v218);
    v219 = qcar(v218);
    v218 = stack[-4];
    v218 = list2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = CC_physopapply(env, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 20); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = stack[-3];
    v218 = qcdr(v218);
    v218 = qcdr(v218);
    v218 = qcar(v218);
    fn = elt(env, 20); /* physop2sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 29); /* quotsq */
    v218 = (*qfn2(fn))(qenv(fn), stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 21); /* mk!*sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v33:
    v218 = stack[-3];
    v218 = qcdr(v218);
    v219 = qcar(v218);
    v218 = stack[-4];
    v218 = list2(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = CC_physopapply(env, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 20); /* physop2sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 30); /* negsq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 21); /* mk!*sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v38:
    v218 = stack[-3];
    fn = elt(env, 20); /* physop2sq */
    stack[0] = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    v218 = stack[-4];
    fn = elt(env, 20); /* physop2sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 31); /* multsq */
    v218 = (*qfn2(fn))(qenv(fn), stack[0], v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 21); /* mk!*sq */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    stack[-1] = v218;
    { Lisp_Object res = stack[-1]; popv(7); return onevalue(res); }

v67:
    v218 = stack[-5];
    if (v218 == nil) goto v100;
    v218 = stack[-2];
    v218 = qcar(v218);
    v218 = ncons(v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 24); /* physopadj */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 17); /* physopaeval */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-4] = v218;
    v218 = stack[-2];
    v218 = qcdr(v218);
    fn = elt(env, 24); /* physopadj */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    fn = elt(env, 17); /* physopaeval */
    v218 = (*qfn1(fn))(qenv(fn), v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    stack[-3] = v218;
    goto v56;

v100:
    v218 = stack[-2];
    v218 = qcar(v218);
    v218 = (Lisp_Object)zerop(v218);
    v218 = v218 ? lisp_true : nil;
    env = stack[-6];
    if (!(v218 == nil)) goto v45;
    v218 = stack[-2];
    v218 = qcdr(v218);
    v218 = qcar(v218);
    v218 = (Lisp_Object)zerop(v218);
    v218 = v218 ? lisp_true : nil;
    env = stack[-6];
    if (!(v218 == nil)) goto v45;
    v219 = elt(env, 2); /* opapply */
    v218 = elt(env, 3); /* "invalid arguments to opapply" */
    fn = elt(env, 27); /* rederr2 */
    v218 = (*qfn2(fn))(qenv(fn), v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    goto v56;

v45:
    v219 = qvalue(elt(env, 1)); /* nil */
    v218 = (Lisp_Object)17; /* 1 */
    v218 = cons(v219, v218);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 21); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v218);
    }
/* error exit handlers */
v221:
    popv(7);
    return nil;
}



/* Code for rep_edge_prop_ */

static Lisp_Object CC_rep_edge_prop_(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v76;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rep_edge_prop_");
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

v5:
    v85 = stack[-1];
    if (v85 == nil) goto v112;
    v85 = stack[-1];
    v76 = qcar(v85);
    v85 = stack[0];
    v85 = Lrplacd(nil, v76, v85);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    v85 = stack[-1];
    v85 = qcdr(v85);
    stack[-1] = v85;
    goto v5;

v112:
    v85 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v85); }
/* error exit handlers */
v54:
    popv(3);
    return nil;
}



/* Code for taylorevaluate */

static Lisp_Object CC_taylorevaluate(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v89, v90;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taylorevaluate");
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
    v90 = stack[0];
    v89 = stack[-1];
    v89 = qcdr(v89);
    v89 = qcar(v89);
    v89 = qcar(v89);
    v89 = (Lisp_Object)lessp2(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v244;
    v89 = v89 ? lisp_true : nil;
    env = stack[-2];
    if (v89 == nil) goto v54;
    v90 = qvalue(elt(env, 1)); /* nil */
    v89 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v90, v89);

v54:
    v90 = stack[0];
    v89 = stack[-1];
    v89 = qcdr(v89);
    v89 = qcar(v89);
    v89 = qcdr(v89);
    v89 = (Lisp_Object)greaterp2(v90, v89);
    nil = C_nil;
    if (exception_pending()) goto v244;
    v89 = v89 ? lisp_true : nil;
    env = stack[-2];
    if (v89 == nil) goto v100;
    v90 = stack[-1];
    v89 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* tayloreval2 */
        return (*qfn2(fn))(qenv(fn), v90, v89);
    }

v100:
    v90 = stack[0];
    v89 = stack[-1];
    v89 = qcdr(v89);
    v89 = qcdr(v89);
    v89 = Lassoc(nil, v90, v89);
    v90 = v89;
    v89 = v90;
    if (v89 == nil) goto v87;
    v89 = v90;
    v89 = qcdr(v89);
    { popv(3); return onevalue(v89); }

v87:
    v90 = stack[-1];
    v89 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* tayloreval2 */
        return (*qfn2(fn))(qenv(fn), v90, v89);
    }
/* error exit handlers */
v244:
    popv(3);
    return nil;
}



/* Code for general!-gcd!-mod!-p */

static Lisp_Object CC_generalKgcdKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v248, v249, v140, v141;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-gcd-mod-p");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v140 = v1;
    v141 = v0;
/* end of prologue */
    v248 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 1)) = v248; /* reduction!-count */
    v248 = v141;
    if (v248 == nil) goto v72;
    v248 = v140;
    if (v248 == nil) goto v157;
    v248 = v141;
    if (!consp(v248)) goto v92;
    v248 = v141;
    v248 = qcar(v248);
    if (!consp(v248)) goto v92;
    v248 = v140;
    if (!consp(v248)) goto v74;
    v248 = v140;
    v248 = qcar(v248);
    if (!consp(v248)) goto v74;
    v248 = v141;
    v248 = qcar(v248);
    v248 = qcar(v248);
    v249 = qcdr(v248);
    v248 = v140;
    v248 = qcar(v248);
    v248 = qcar(v248);
    v248 = qcdr(v248);
    if (((int32_t)(v249)) > ((int32_t)(v248))) goto v82;
    v248 = v140;
    v249 = v141;
    {
        fn = elt(env, 2); /* general!-ordered!-gcd!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v248, v249);
    }

v82:
    v248 = v141;
    v249 = v140;
    {
        fn = elt(env, 2); /* general!-ordered!-gcd!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v248, v249);
    }

v74:
    v248 = (Lisp_Object)17; /* 1 */
    return onevalue(v248);

v92:
    v248 = (Lisp_Object)17; /* 1 */
    return onevalue(v248);

v157:
    v248 = v141;
    {
        fn = elt(env, 3); /* monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v248);
    }

v72:
    v248 = v140;
    {
        fn = elt(env, 3); /* monic!-mod!-p */
        return (*qfn1(fn))(qenv(fn), v248);
    }
}



/* Code for numrdeg */

static Lisp_Object CC_numrdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v246;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numrdeg");
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
    v245 = stack[0];
    fn = elt(env, 1); /* !*a2k */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[0] = v245;
    v245 = stack[-1];
    if (!consp(v245)) goto v98;
    v245 = stack[-1];
    v245 = qcar(v245);
    if (!consp(v245)) goto v98;
    v245 = stack[-1];
    v245 = qcar(v245);
    v245 = qcar(v245);
    v246 = qcar(v245);
    v245 = stack[0];
    if (v246 == v245) goto v107;
    v245 = stack[0];
    fn = elt(env, 2); /* updkorder */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[-2] = v245;
    v245 = stack[-1];
    fn = elt(env, 3); /* reorder */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-3];
    stack[-1] = v245;
    v245 = stack[-1];
    v245 = qcar(v245);
    v245 = qcar(v245);
    v246 = qcar(v245);
    v245 = stack[0];
    if (v246 == v245) goto v48;
    v245 = (Lisp_Object)1; /* 0 */
    stack[-1] = v245;
    goto v67;

v67:
    v245 = stack[-2];
    fn = elt(env, 4); /* setkorder */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v141;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v48:
    v245 = stack[-1];
    v245 = qcar(v245);
    v245 = qcar(v245);
    v245 = qcdr(v245);
    stack[-1] = v245;
    goto v67;

v107:
    v245 = stack[-1];
    v245 = qcar(v245);
    v245 = qcar(v245);
    v245 = qcdr(v245);
    {
        popv(4);
        fn = elt(env, 5); /* prepf */
        return (*qfn1(fn))(qenv(fn), v245);
    }

v98:
    v245 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v245); }
/* error exit handlers */
v141:
    popv(4);
    return nil;
}



/* Code for ofsf_qesubiord */

static Lisp_Object MS_CDECL CC_ofsf_qesubiord(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v78, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_qesubiord");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_qesubiord");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v3;
    stack[-1] = v2;
    v76 = v1;
    v78 = v0;
/* end of prologue */
    stack[-2] = v78;
    v78 = v76;
    v76 = stack[-1];
    fn = elt(env, 1); /* sfto_reorder */
    v53 = (*qfn2(fn))(qenv(fn), v78, v76);
    nil = C_nil;
    if (exception_pending()) goto v109;
    env = stack[-3];
    v78 = stack[-1];
    v76 = stack[0];
    {
        Lisp_Object v118 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* ofsf_qesubiord1 */
        return (*qfnn(fn))(qenv(fn), 4, v118, v53, v78, v76);
    }
/* error exit handlers */
v109:
    popv(4);
    return nil;
}



/* Code for cl_gaussand */

static Lisp_Object MS_CDECL CC_cl_gaussand(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v88, v250, v251, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "cl_gaussand");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_gaussand");
#endif
    if (stack >= stacklimit)
    {
        push5(v4,v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v1,v2,v3,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v3;
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v87 = stack[-4];
    v45 = qcar(v87);
    v251 = stack[-3];
    v250 = stack[-2];
    v88 = stack[-1];
    v87 = stack[0];
    fn = elt(env, 2); /* cl_trygaussvar */
    v87 = (*qfnn(fn))(qenv(fn), 5, v45, v251, v250, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[-5] = v87;
    v87 = stack[-4];
    v87 = qcdr(v87);
    stack[-4] = v87;
    goto v109;

v109:
    v87 = stack[-4];
    if (v87 == nil) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v87 = stack[-5];
    fn = elt(env, 3); /* rl_bestgaussp */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    if (!(v87 == nil)) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    v87 = stack[-4];
    v45 = qcar(v87);
    v251 = stack[-3];
    v250 = stack[-2];
    v88 = stack[-1];
    v87 = stack[0];
    fn = elt(env, 2); /* cl_trygaussvar */
    v87 = (*qfnn(fn))(qenv(fn), 5, v45, v251, v250, v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    v88 = v87;
    v87 = stack[-5];
    fn = elt(env, 4); /* cl_gaussintersection */
    v87 = (*qfn2(fn))(qenv(fn), v88, v87);
    nil = C_nil;
    if (exception_pending()) goto v244;
    env = stack[-6];
    stack[-5] = v87;
    v87 = stack[-4];
    v87 = qcdr(v87);
    stack[-4] = v87;
    goto v109;
/* error exit handlers */
v244:
    popv(7);
    return nil;
}



/* Code for get!*generators */

static Lisp_Object CC_getHgenerators(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v117;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get*generators");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v116 = v0;
/* end of prologue */
    v117 = elt(env, 1); /* generators */
    return get(v116, v117);
}



/* Code for factor!-prim!-f */

static Lisp_Object CC_factorKprimKf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v262, v263;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for factor-prim-f");
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
    v17 = qvalue(elt(env, 1)); /* ncmp!* */
    if (v17 == nil) goto v73;
    stack[0] = (Lisp_Object)17; /* 1 */
    v262 = stack[-2];
    v17 = (Lisp_Object)17; /* 1 */
    v17 = cons(v262, v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    {
        Lisp_Object v126 = stack[0];
        popv(5);
        return list2(v126, v17);
    }

v73:
    v17 = qvalue(elt(env, 2)); /* dmode!* */
    if (v17 == nil) goto v46;
    v262 = qvalue(elt(env, 2)); /* dmode!* */
    v17 = elt(env, 3); /* sqfrfactorfn */
    v17 = get(v262, v17);
    env = stack[-4];
    stack[-1] = v17;
    if (v17 == nil) goto v46;
    v17 = qvalue(elt(env, 4)); /* !*factor */
    if (v17 == nil) goto v83;
    v262 = stack[-1];
    v17 = stack[-2];
    v17 = Lapply1(nil, v262, v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[0] = v17;
    goto v54;

v54:
    v17 = stack[-1];
    if (v17 == nil) goto v150;
    v263 = stack[-1];
    v262 = qvalue(elt(env, 2)); /* dmode!* */
    v17 = elt(env, 7); /* factorfn */
    v17 = get(v262, v17);
    env = stack[-4];
    if (v263 == v17) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    else goto v150;

v150:
    v17 = stack[0];
    v17 = qcar(v17);
    v17 = ncons(v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[-3] = v17;
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[0] = v17;
    goto v264;

v264:
    v17 = stack[0];
    if (v17 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v17 = stack[0];
    v17 = qcar(v17);
    fn = elt(env, 9); /* factor!-prim!-sqfree!-f */
    v262 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v17 = stack[-3];
    fn = elt(env, 10); /* fac!-merge */
    v17 = (*qfn2(fn))(qenv(fn), v262, v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[-3] = v17;
    v17 = stack[0];
    v17 = qcdr(v17);
    stack[0] = v17;
    goto v264;

v83:
    stack[0] = (Lisp_Object)17; /* 1 */
    v262 = stack[-2];
    v17 = (Lisp_Object)17; /* 1 */
    v17 = cons(v262, v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v17 = list2(stack[0], v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[0] = v17;
    goto v54;

v46:
    v262 = qvalue(elt(env, 2)); /* dmode!* */
    v17 = elt(env, 5); /* field */
    v17 = Lflagp(nil, v262, v17);
    env = stack[-4];
    if (v17 == nil) goto v265;
    v17 = stack[-2];
    fn = elt(env, 11); /* lnc */
    v262 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[-3] = v262;
    v17 = (Lisp_Object)17; /* 1 */
    if (v262 == v17) goto v265;
    stack[0] = stack[-3];
    v17 = stack[-3];
    fn = elt(env, 12); /* !:recip */
    v262 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v17 = stack[-2];
    fn = elt(env, 13); /* multd */
    v17 = (*qfn2(fn))(qenv(fn), v262, v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    fn = elt(env, 14); /* sqfrf */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v17 = cons(stack[0], v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[0] = v17;
    goto v54;

v265:
    v262 = qvalue(elt(env, 2)); /* dmode!* */
    v17 = elt(env, 6); /* units */
    v17 = get(v262, v17);
    env = stack[-4];
    stack[-3] = v17;
    if (v17 == nil) goto v212;
    v17 = stack[-2];
    fn = elt(env, 11); /* lnc */
    v262 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v263 = v262;
    v17 = stack[-3];
    v17 = Lassoc(nil, v262, v17);
    stack[-3] = v17;
    if (v17 == nil) goto v212;
    stack[0] = v263;
    v17 = stack[-3];
    v262 = qcdr(v17);
    v17 = stack[-2];
    fn = elt(env, 13); /* multd */
    v17 = (*qfn2(fn))(qenv(fn), v262, v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    fn = elt(env, 14); /* sqfrf */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v17 = cons(stack[0], v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[0] = v17;
    goto v54;

v212:
    stack[0] = (Lisp_Object)17; /* 1 */
    v17 = stack[-2];
    fn = elt(env, 14); /* sqfrf */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    v17 = cons(stack[0], v17);
    nil = C_nil;
    if (exception_pending()) goto v125;
    env = stack[-4];
    stack[0] = v17;
    goto v54;
/* error exit handlers */
v125:
    popv(5);
    return nil;
}



/* Code for sfto_dprpartf */

static Lisp_Object CC_sfto_dprpartf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v157;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_dprpartf");
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
    v157 = v0;
/* end of prologue */
    stack[0] = v157;
    fn = elt(env, 1); /* sfto_dcontentf */
    v157 = (*qfn1(fn))(qenv(fn), v157);
    nil = C_nil;
    if (exception_pending()) goto v117;
    env = stack[-1];
    {
        Lisp_Object v115 = stack[0];
        popv(2);
        fn = elt(env, 2); /* sfto_dprpartf1 */
        return (*qfn2(fn))(qenv(fn), v115, v157);
    }
/* error exit handlers */
v117:
    popv(2);
    return nil;
}



/* Code for load_package */

static Lisp_Object CC_load_package(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for load_package");
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
    v107 = v0;
/* end of prologue */
    stack[0] = v107;
    goto v5;

v5:
    v107 = stack[0];
    if (v107 == nil) goto v73;
    v107 = stack[0];
    v107 = qcar(v107);
    fn = elt(env, 2); /* load!-package */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v55;
    env = stack[-1];
    v107 = stack[0];
    v107 = qcdr(v107);
    stack[0] = v107;
    goto v5;

v73:
    v107 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v107); }
/* error exit handlers */
v55:
    popv(2);
    return nil;
}



/* Code for codgcd */

static Lisp_Object MS_CDECL CC_codgcd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v244, v267;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "codgcd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for codgcd");
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
    v244 = qvalue(elt(env, 1)); /* rowmax */
    stack[-2] = v244;
    v244 = (Lisp_Object)1; /* 0 */
    stack[-1] = v244;
    goto v92;

v92:
    v267 = stack[-2];
    v244 = stack[-1];
    v244 = difference2(v267, v244);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    v244 = Lminusp(nil, v244);
    env = stack[-3];
    if (v244 == nil) goto v51;
    v244 = nil;
    { popv(4); return onevalue(v244); }

v51:
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v267 = qvalue(elt(env, 4)); /* maxvar */
    v244 = stack[-1];
    v244 = plus2(v267, v244);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    v267 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v244/(16/CELL)));
    v244 = (Lisp_Object)49; /* 3 */
    v267 = *(Lisp_Object *)((char *)v267 + (CELL-TAG_VECTOR) + ((int32_t)v244/(16/CELL)));
    v244 = (Lisp_Object)-15; /* -1 */
    if (v267 == v244) goto v85;
    v244 = stack[-1];
    fn = elt(env, 5); /* mkgclst */
    v244 = (*qfn1(fn))(qenv(fn), v244);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    stack[0] = v244;
    goto v83;

v83:
    v244 = stack[0];
    if (v244 == nil) goto v85;
    v244 = stack[0];
    v244 = qcar(v244);
    v267 = v244;
    v244 = stack[-1];
    fn = elt(env, 6); /* remgc */
    v244 = (*qfn2(fn))(qenv(fn), v267, v244);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    v244 = stack[0];
    v244 = qcdr(v244);
    stack[0] = v244;
    goto v83;

v85:
    v244 = stack[-1];
    v244 = add1(v244);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-3];
    stack[-1] = v244;
    goto v92;
/* error exit handlers */
v148:
    popv(4);
    return nil;
}



/* Code for clear1 */

static Lisp_Object CC_clear1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v278, v16, v17, v262;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for clear1");
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

v112:
    v278 = stack[-1];
    if (v278 == nil) goto v18;
    v278 = stack[-1];
    v16 = qcar(v278);
    stack[-2] = v16;
    v278 = elt(env, 2); /* share */
    v278 = Lflagp(nil, v16, v278);
    env = stack[-3];
    if (v278 == nil) goto v68;
    v16 = stack[-2];
    v278 = elt(env, 3); /* reserved */
    v278 = Lflagp(nil, v16, v278);
    env = stack[-3];
    if (v278 == nil) goto v93;
    v278 = stack[-2];
    fn = elt(env, 10); /* rsverr */
    v278 = (*qfn1(fn))(qenv(fn), v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    goto v92;

v92:
    v278 = stack[-1];
    v278 = qcdr(v278);
    stack[-1] = v278;
    goto v112;

v93:
    v16 = stack[-2];
    v278 = stack[-2];
    v278 = Lset(nil, v16, v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    goto v92;

v68:
    v16 = stack[-2];
    v278 = elt(env, 4); /* list */
    if (!consp(v16)) goto v149;
    v16 = qcar(v16);
    if (!(v16 == v278)) goto v149;
    stack[0] = qvalue(elt(env, 1)); /* nil */
    v278 = stack[-2];
    v16 = qcdr(v278);
    v278 = stack[-1];
    v278 = qcdr(v278);
    v278 = Lappend(nil, v16, v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v278 = cons(stack[0], v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    stack[-1] = v278;
    goto v92;

v149:
    v16 = stack[-2];
    v278 = elt(env, 5); /* replaceby */
    if (!consp(v16)) goto v38;
    v16 = qcar(v16);
    if (!(v16 == v278)) goto v38;
    v278 = stack[-2];
    v16 = ncons(v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v278 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 11); /* rule!-list */
    v278 = (*qfn2(fn))(qenv(fn), v16, v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    goto v92;

v38:
    v16 = elt(env, 6); /* !~ */
    v278 = stack[-2];
    v278 = Lsmemq(nil, v16, v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    if (v278 == nil) goto v30;
    v16 = stack[-2];
    v278 = elt(env, 7); /* equal */
    if (!consp(v16)) goto v214;
    v16 = qcar(v16);
    if (!(v16 == v278)) goto v214;
    v278 = stack[-2];
    v16 = ncons(v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v278 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 11); /* rule!-list */
    v278 = (*qfn2(fn))(qenv(fn), v16, v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    goto v92;

v214:
    v17 = elt(env, 5); /* replaceby */
    v16 = stack[-2];
    v278 = qvalue(elt(env, 1)); /* nil */
    v278 = list3(v17, v16, v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v16 = ncons(v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v278 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 11); /* rule!-list */
    v278 = (*qfn2(fn))(qenv(fn), v16, v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    goto v92;

v30:
    v278 = stack[-2];
    if (!consp(v278)) goto v150;
    v278 = stack[-2];
    v278 = qcar(v278);
    v16 = v278;
    goto v280;

v280:
    v278 = elt(env, 8); /* clearfn */
    v278 = get(v16, v278);
    env = stack[-3];
    v16 = v278;
    if (v278 == nil) goto v24;
    v278 = stack[-2];
    v278 = Lapply1(nil, v16, v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    goto v92;

v24:
    v262 = stack[-2];
    v17 = qvalue(elt(env, 1)); /* nil */
    v16 = qvalue(elt(env, 1)); /* nil */
    v278 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 12); /* let2 */
    v278 = (*qfnn(fn))(qenv(fn), 4, v262, v17, v16, v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    v262 = stack[-2];
    v17 = qvalue(elt(env, 1)); /* nil */
    v16 = qvalue(elt(env, 9)); /* t */
    v278 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 12); /* let2 */
    v278 = (*qfnn(fn))(qenv(fn), 4, v262, v17, v16, v278);
    nil = C_nil;
    if (exception_pending()) goto v279;
    env = stack[-3];
    goto v92;

v150:
    v278 = stack[-2];
    v16 = v278;
    goto v280;

v18:
    v278 = nil;
    { popv(4); return onevalue(v278); }
/* error exit handlers */
v279:
    popv(4);
    return nil;
}



/* Code for gbfmult */

static Lisp_Object CC_gbfmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v245, v246, v248;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gbfmult");
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
    v245 = stack[-1];
    v245 = Lfloatp(nil, v245);
    env = stack[-3];
    if (v245 == nil) goto v157;
    v245 = stack[-1];
    fn = elt(env, 2); /* fl2bf */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    goto v4;

v4:
    stack[-1] = v245;
    v246 = stack[-1];
    v245 = stack[0];
    v245 = qcar(v245);
    fn = elt(env, 3); /* csl_timbf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    v246 = stack[-1];
    v245 = stack[0];
    v245 = qcdr(v245);
    fn = elt(env, 3); /* csl_timbf */
    v245 = (*qfn2(fn))(qenv(fn), v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v79;
    {
        Lisp_Object v43 = stack[-2];
        popv(4);
        return cons(v43, v245);
    }

v157:
    v245 = stack[-1];
    if (!consp(v245)) goto v108;
    v245 = stack[-1];
    goto v91;

v91:
    fn = elt(env, 4); /* csl_normbf */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    goto v4;

v108:
    v245 = stack[-1];
    v245 = integerp(v245);
    if (v245 == nil) goto v66;
    v248 = elt(env, 1); /* !:rd!: */
    v246 = stack[-1];
    v245 = (Lisp_Object)1; /* 0 */
    v245 = list2star(v248, v246, v245);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    goto v91;

v66:
    v245 = stack[-1];
    fn = elt(env, 5); /* read!:num */
    v245 = (*qfn1(fn))(qenv(fn), v245);
    nil = C_nil;
    if (exception_pending()) goto v79;
    env = stack[-3];
    goto v91;
/* error exit handlers */
v79:
    popv(4);
    return nil;
}



/* Code for !:pi */

static Lisp_Object CC_Tpi(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v294, v204;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :pi");
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
    v294 = stack[-6];
    v294 = integerp(v294);
    if (v294 == nil) goto v4;
    v204 = stack[-6];
    v294 = (Lisp_Object)1; /* 0 */
    v294 = (Lisp_Object)lesseq2(v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    v294 = v294 ? lisp_true : nil;
    env = stack[-8];
    if (!(v294 == nil)) goto v4;
    v204 = elt(env, 0); /* !:pi */
    v294 = stack[-6];
    fn = elt(env, 4); /* get!:const */
    v294 = (*qfn2(fn))(qenv(fn), v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[0] = v294;
    v204 = stack[0];
    v294 = elt(env, 1); /* not_found */
    if (!(v204 == v294)) { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }
    stack[0] = (Lisp_Object)33; /* 2 */
    v204 = stack[-6];
    v294 = (Lisp_Object)49; /* 3 */
    v294 = plus2(v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[-7] = v294;
    v204 = Lexpt(nil, stack[0], v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    v294 = (Lisp_Object)81; /* 5 */
    v294 = quot2(v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[-3] = v294;
    stack[-5] = v294;
    v204 = (Lisp_Object)81; /* 5 */
    v294 = (Lisp_Object)33; /* 2 */
    v294 = Lexpt(nil, v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    v294 = negate(v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[-2] = v294;
    v294 = (Lisp_Object)17; /* 1 */
    stack[-4] = v294;
    goto v101;

v101:
    v204 = stack[-3];
    v294 = (Lisp_Object)1; /* 0 */
    if (v204 == v294) goto v295;
    v204 = stack[-3];
    v294 = stack[-2];
    v294 = quot2(v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[-3] = v294;
    stack[-1] = stack[-5];
    stack[0] = stack[-3];
    v204 = stack[-4];
    v294 = (Lisp_Object)33; /* 2 */
    v294 = plus2(v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[-4] = v294;
    v294 = quot2(stack[0], v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    v294 = plus2(stack[-1], v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[-5] = v294;
    goto v101;

v295:
    v204 = (Lisp_Object)33; /* 2 */
    v294 = stack[-7];
    v204 = Lexpt(nil, v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    v294 = (Lisp_Object)3825; /* 239 */
    v294 = quot2(v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[-3] = v294;
    stack[0] = v294;
    v204 = (Lisp_Object)3825; /* 239 */
    v294 = (Lisp_Object)33; /* 2 */
    v294 = Lexpt(nil, v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    v294 = negate(v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[-2] = v294;
    v294 = (Lisp_Object)17; /* 1 */
    stack[-4] = v294;
    goto v273;

v273:
    v204 = stack[-3];
    v294 = (Lisp_Object)1; /* 0 */
    if (v204 == v294) goto v263;
    v204 = stack[-3];
    v294 = stack[-2];
    v294 = quot2(v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[-3] = v294;
    stack[-1] = stack[0];
    stack[0] = stack[-3];
    v204 = stack[-4];
    v294 = (Lisp_Object)33; /* 2 */
    v294 = plus2(v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[-4] = v294;
    v294 = quot2(stack[0], v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    v294 = plus2(stack[-1], v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[0] = v294;
    goto v273;

v263:
    stack[-1] = elt(env, 3); /* !:rd!: */
    v204 = (Lisp_Object)257; /* 16 */
    v294 = stack[-5];
    stack[-2] = times2(v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    v204 = (Lisp_Object)65; /* 4 */
    v294 = stack[0];
    v294 = times2(v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[0] = difference2(stack[-2], v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    v294 = stack[-7];
    v294 = negate(v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    v204 = list2star(stack[-1], stack[0], v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    v294 = stack[-6];
    fn = elt(env, 5); /* round!:mt */
    v294 = (*qfn2(fn))(qenv(fn), v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-8];
    stack[0] = v294;
    v204 = elt(env, 0); /* !:pi */
    v294 = stack[0];
    fn = elt(env, 6); /* save!:const */
    v294 = (*qfn2(fn))(qenv(fn), v204, v294);
    nil = C_nil;
    if (exception_pending()) goto v6;
    { Lisp_Object res = stack[0]; popv(9); return onevalue(res); }

v4:
    v294 = elt(env, 0); /* !:pi */
    {
        popv(9);
        fn = elt(env, 7); /* bflerrmsg */
        return (*qfn1(fn))(qenv(fn), v294);
    }
/* error exit handlers */
v6:
    popv(9);
    return nil;
}



/* Code for let0 */

static Lisp_Object CC_let0(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for let0");
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
    v18 = v0;
/* end of prologue */
    v72 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* frasc!* */
    qvalue(elt(env, 2)) = v72; /* frasc!* */
    v72 = v18;
    fn = elt(env, 3); /* let00 */
    v72 = (*qfn1(fn))(qenv(fn), v72);
    nil = C_nil;
    if (exception_pending()) goto v73;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* frasc!* */
    { popv(2); return onevalue(v72); }
/* error exit handlers */
v73:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* frasc!* */
    popv(2);
    return nil;
}



/* Code for getphystypestate */

static Lisp_Object CC_getphystypestate(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystypestate");
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
    v113 = stack[0];
    v113 = qcar(v113);
    fn = elt(env, 3); /* statep!* */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-1];
    if (v113 == nil) goto v92;
    v113 = stack[0];
    v113 = qcdr(v113);
    v113 = qcar(v113);
    fn = elt(env, 3); /* statep!* */
    v113 = (*qfn1(fn))(qenv(fn), v113);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-1];
    if (v113 == nil) goto v92;
    v113 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v113); }

v92:
    v113 = elt(env, 2); /* state */
    { popv(2); return onevalue(v113); }
/* error exit handlers */
v56:
    popv(2);
    return nil;
}



/* Code for actual_edges_world */

static Lisp_Object CC_actual_edges_world(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v76;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for actual_edges_world");
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
    v85 = stack[0];
    fn = elt(env, 2); /* s_actual_world1 */
    stack[-1] = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    v85 = stack[0];
    v85 = qcdr(v85);
    v85 = qcar(v85);
    fn = elt(env, 3); /* s_actual_coeff */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    fn = elt(env, 4); /* actual_world */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v85);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    v85 = qvalue(elt(env, 1)); /* nil */
    v76 = ncons(v85);
    nil = C_nil;
    if (exception_pending()) goto v54;
    v85 = stack[0];
    {
        Lisp_Object v95 = stack[-1];
        popv(3);
        return list3(v95, v76, v85);
    }
/* error exit handlers */
v54:
    popv(3);
    return nil;
}



/* Code for coeffeval */

static Lisp_Object CC_coeffeval(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v43, v86, v87;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coeffeval");
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
    v43 = stack[0];
    v43 = Llength(nil, v43);
    nil = C_nil;
    if (exception_pending()) goto v251;
    env = stack[-2];
    stack[-1] = v43;
    v86 = stack[-1];
    v43 = (Lisp_Object)33; /* 2 */
    v43 = (Lisp_Object)lessp2(v86, v43);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v43 = v43 ? lisp_true : nil;
    env = stack[-2];
    if (!(v43 == nil)) goto v75;
    v86 = stack[-1];
    v43 = (Lisp_Object)49; /* 3 */
    v43 = (Lisp_Object)greaterp2(v86, v43);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v43 = v43 ? lisp_true : nil;
    env = stack[-2];
    if (!(v43 == nil)) goto v75;
    v43 = stack[0];
    v87 = qcar(v43);
    v43 = stack[0];
    v43 = qcdr(v43);
    v86 = qcar(v43);
    v43 = stack[0];
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    if (v43 == nil) goto v71;
    v43 = stack[0];
    v43 = qcdr(v43);
    v43 = qcdr(v43);
    v43 = qcar(v43);
    goto v296;

v296:
    {
        popv(3);
        fn = elt(env, 4); /* coeff1 */
        return (*qfnn(fn))(qenv(fn), 3, v87, v86, v43);
    }

v71:
    v43 = qvalue(elt(env, 3)); /* nil */
    goto v296;

v75:
    v87 = elt(env, 1); /* alg */
    v86 = (Lisp_Object)449; /* 28 */
    v43 = elt(env, 2); /* "COEFF called with wrong number of arguments" 
*/
    fn = elt(env, 5); /* rerror */
    v43 = (*qfnn(fn))(qenv(fn), 3, v87, v86, v43);
    nil = C_nil;
    if (exception_pending()) goto v251;
    v43 = nil;
    { popv(3); return onevalue(v43); }
/* error exit handlers */
v251:
    popv(3);
    return nil;
}



/* Code for merge_list1 */

static Lisp_Object MS_CDECL CC_merge_list1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v43, v86;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "merge_list1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for merge_list1");
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
    v79 = stack[-2];
    if (v79 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v79 = stack[-1];
    if (v79 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v86 = stack[0];
    v79 = stack[-2];
    v43 = qcar(v79);
    v79 = stack[-1];
    v79 = qcar(v79);
    v79 = Lapply2(nil, 3, v86, v43, v79);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-4];
    if (v79 == nil) goto v99;
    stack[-3] = stack[-2];
    v79 = stack[-2];
    v86 = qcdr(v79);
    v43 = stack[-1];
    v79 = stack[0];
    v79 = CC_merge_list1(env, 3, v86, v43, v79);
    nil = C_nil;
    if (exception_pending()) goto v45;
    {
        Lisp_Object v46 = stack[-3];
        popv(5);
        return Lrplacd(nil, v46, v79);
    }

v99:
    stack[-3] = stack[-1];
    v86 = stack[-2];
    v79 = stack[-1];
    v43 = qcdr(v79);
    v79 = stack[0];
    v79 = CC_merge_list1(env, 3, v86, v43, v79);
    nil = C_nil;
    if (exception_pending()) goto v45;
    {
        Lisp_Object v243 = stack[-3];
        popv(5);
        return Lrplacd(nil, v243, v79);
    }
/* error exit handlers */
v45:
    popv(5);
    return nil;
}



/* Code for make!-image!-lc!-list */

static Lisp_Object CC_makeKimageKlcKlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-image-lc-list");
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
    v69 = v1;
    v70 = v0;
/* end of prologue */
    stack[-5] = v70;
    stack[-4] = v69;
    stack[-3] = v69;
    v69 = stack[-3];
    if (v69 == nil) goto v60;
    v69 = stack[-3];
    v69 = qcar(v69);
    v69 = qcar(v69);
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    stack[-1] = v69;
    stack[-2] = v69;
    goto v113;

v113:
    v69 = stack[-3];
    v69 = qcdr(v69);
    stack[-3] = v69;
    v69 = stack[-3];
    if (v69 == nil) goto v81;
    stack[0] = stack[-1];
    v69 = stack[-3];
    v69 = qcar(v69);
    v69 = qcar(v69);
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    v69 = Lrplacd(nil, stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-6];
    v69 = stack[-1];
    v69 = qcdr(v69);
    stack[-1] = v69;
    goto v113;

v81:
    v69 = stack[-2];
    goto v98;

v98:
    fn = elt(env, 2); /* make!-image!-lc!-list1 */
    v69 = (*qfnn(fn))(qenv(fn), 3, stack[-5], stack[-4], v69);
    nil = C_nil;
    if (exception_pending()) goto v246;
        popv(7);
        return Lnreverse(nil, v69);

v60:
    v69 = qvalue(elt(env, 1)); /* nil */
    goto v98;
/* error exit handlers */
v246:
    popv(7);
    return nil;
}



/* Code for multm */

static Lisp_Object CC_multm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v256, v257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multm");
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
/* copy arguments values to proper place */
    v256 = v1;
    stack[0] = v0;
/* end of prologue */
    fn = elt(env, 2); /* tp1 */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    stack[-9] = v256;
    v256 = stack[0];
    stack[-8] = v256;
    v256 = stack[-8];
    if (v256 == nil) goto v91;
    v256 = stack[-8];
    v256 = qcar(v256);
    stack[-4] = v256;
    v256 = stack[-9];
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v109;
    v256 = stack[-3];
    v256 = qcar(v256);
    v257 = stack[-4];
    fn = elt(env, 3); /* scalprod */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    fn = elt(env, 4); /* subs2 */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    stack[-1] = v256;
    stack[-2] = v256;
    goto v53;

v53:
    v256 = stack[-3];
    v256 = qcdr(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v47;
    stack[0] = stack[-1];
    v256 = stack[-3];
    v256 = qcar(v256);
    v257 = stack[-4];
    fn = elt(env, 3); /* scalprod */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    fn = elt(env, 4); /* subs2 */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    v256 = Lrplacd(nil, stack[0], v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-1] = v256;
    goto v53;

v47:
    v256 = stack[-2];
    goto v78;

v78:
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    stack[-6] = v256;
    stack[-7] = v256;
    goto v157;

v157:
    v256 = stack[-8];
    v256 = qcdr(v256);
    stack[-8] = v256;
    v256 = stack[-8];
    if (v256 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v256 = stack[-8];
    v256 = qcar(v256);
    stack[-4] = v256;
    v256 = stack[-9];
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v110;
    v256 = stack[-3];
    v256 = qcar(v256);
    v257 = stack[-4];
    fn = elt(env, 3); /* scalprod */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    fn = elt(env, 4); /* subs2 */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    stack[-1] = v256;
    stack[-2] = v256;
    goto v293;

v293:
    v256 = stack[-3];
    v256 = qcdr(v256);
    stack[-3] = v256;
    v256 = stack[-3];
    if (v256 == nil) goto v275;
    stack[0] = stack[-1];
    v256 = stack[-3];
    v256 = qcar(v256);
    v257 = stack[-4];
    fn = elt(env, 3); /* scalprod */
    v256 = (*qfn2(fn))(qenv(fn), v257, v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    fn = elt(env, 4); /* subs2 */
    v256 = (*qfn1(fn))(qenv(fn), v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    v256 = Lrplacd(nil, stack[0], v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    v256 = stack[-1];
    v256 = qcdr(v256);
    stack[-1] = v256;
    goto v293;

v275:
    v256 = stack[-2];
    goto v40;

v40:
    v256 = ncons(v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    v256 = Lrplacd(nil, stack[-5], v256);
    nil = C_nil;
    if (exception_pending()) goto v273;
    env = stack[-10];
    v256 = stack[-6];
    v256 = qcdr(v256);
    stack[-6] = v256;
    goto v157;

v110:
    v256 = qvalue(elt(env, 1)); /* nil */
    goto v40;

v109:
    v256 = qvalue(elt(env, 1)); /* nil */
    goto v78;

v91:
    v256 = qvalue(elt(env, 1)); /* nil */
    { popv(11); return onevalue(v256); }
/* error exit handlers */
v273:
    popv(11);
    return nil;
}



/* Code for mkexpvec */

static Lisp_Object CC_mkexpvec(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v61, v297;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkexpvec");
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
    v297 = stack[-3];
    v61 = qvalue(elt(env, 1)); /* dipvars!* */
    v61 = Lmember(nil, v297, v61);
    if (v61 == nil) goto v91;
    v61 = qvalue(elt(env, 1)); /* dipvars!* */
    stack[-4] = v61;
    v61 = stack[-4];
    if (v61 == nil) goto v118;
    v61 = stack[-4];
    v61 = qcar(v61);
    v297 = v61;
    v61 = stack[-3];
    if (v297 == v61) goto v94;
    v61 = (Lisp_Object)1; /* 0 */
    goto v247;

v247:
    v61 = ncons(v61);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    stack[-1] = v61;
    stack[-2] = v61;
    goto v54;

v54:
    v61 = stack[-4];
    v61 = qcdr(v61);
    stack[-4] = v61;
    v61 = stack[-4];
    if (v61 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v61 = stack[-4];
    v61 = qcar(v61);
    v297 = v61;
    v61 = stack[-3];
    if (v297 == v61) goto v46;
    v61 = (Lisp_Object)1; /* 0 */
    goto v45;

v45:
    v61 = ncons(v61);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    v61 = Lrplacd(nil, stack[0], v61);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-5];
    v61 = stack[-1];
    v61 = qcdr(v61);
    stack[-1] = v61;
    goto v54;

v46:
    v61 = (Lisp_Object)17; /* 1 */
    goto v45;

v94:
    v61 = (Lisp_Object)17; /* 1 */
    goto v247;

v118:
    v61 = qvalue(elt(env, 3)); /* nil */
    { popv(6); return onevalue(v61); }

v91:
    v297 = stack[-3];
    v61 = elt(env, 2); /* "dipoly variable" */
    {
        popv(6);
        fn = elt(env, 4); /* typerr */
        return (*qfn2(fn))(qenv(fn), v297, v61);
    }
/* error exit handlers */
v41:
    popv(6);
    return nil;
}



/* Code for deflate1c */

static Lisp_Object CC_deflate1c(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v147, v215;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deflate1c");
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
    v132 = v0;
/* end of prologue */
    stack[-5] = nil;
    fn = elt(env, 3); /* ncoeffs */
    v147 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-6];
    v132 = v147;
    v147 = qcar(v147);
    stack[-3] = v147;
    v132 = qcdr(v132);
    v147 = v132;
    v147 = qcar(v147);
    stack[-2] = v147;
    v132 = qcdr(v132);
    stack[-1] = v132;
    goto v107;

v107:
    v132 = stack[-1];
    if (v132 == nil) goto v63;
    v132 = stack[-1];
    v132 = qcar(v132);
    stack[0] = v132;
    v132 = stack[-3];
    v132 = sub1(v132);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-6];
    stack[-3] = v132;
    v132 = stack[-2];
    v132 = qcar(v132);
    if (!consp(v132)) goto v87;
    v132 = stack[-2];
    v132 = qcar(v132);
    v132 = qcdr(v132);
    v147 = qcar(v132);
    v132 = (Lisp_Object)1; /* 0 */
    if (v147 == v132) goto v83;
    v132 = qvalue(elt(env, 1)); /* nil */
    goto v81;

v81:
    if (!(v132 == nil)) goto v61;
    v215 = stack[-3];
    v147 = stack[-2];
    v132 = stack[-5];
    v132 = acons(v215, v147, v132);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-6];
    stack[-5] = v132;
    goto v61;

v61:
    v147 = stack[-4];
    v132 = stack[-2];
    fn = elt(env, 4); /* gftimesn */
    v132 = (*qfn2(fn))(qenv(fn), v147, v132);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-6];
    stack[-2] = v132;
    v132 = stack[0];
    if (v132 == nil) goto v42;
    v147 = stack[-2];
    v132 = stack[0];
    fn = elt(env, 5); /* gfplusn */
    v132 = (*qfn2(fn))(qenv(fn), v147, v132);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-6];
    stack[-2] = v132;
    goto v42;

v42:
    v132 = stack[-1];
    v132 = qcdr(v132);
    stack[-1] = v132;
    goto v107;

v83:
    v132 = stack[-2];
    v132 = qcdr(v132);
    v132 = qcdr(v132);
    v147 = qcar(v132);
    v132 = (Lisp_Object)1; /* 0 */
    v132 = (v147 == v132 ? lisp_true : nil);
    goto v81;

v87:
    v147 = stack[-2];
    v132 = elt(env, 2); /* (0.0 . 0.0) */
    v132 = (equal(v147, v132) ? lisp_true : nil);
    goto v81;

v63:
    v147 = stack[-2];
    v132 = stack[-5];
    popv(7);
    return cons(v147, v132);
/* error exit handlers */
v33:
    popv(7);
    return nil;
}



/* Code for mkffortassign */

static Lisp_Object CC_mkffortassign(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkffortassign");
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
    stack[-1] = v1;
    stack[0] = v0;
/* end of prologue */
    fn = elt(env, 3); /* mkforttab */
    stack[-2] = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-3];
    v49 = stack[0];
    if (!consp(v49)) goto v74;
    v50 = elt(env, 1); /* dummyarraytoken */
    v49 = stack[0];
    v49 = qcdr(v49);
    v49 = cons(v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-3];
    fn = elt(env, 4); /* fortexp */
    v50 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-3];
    v49 = stack[0];
    v49 = qcar(v49);
    v49 = Lrplaca(nil, v50, v49);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-3];
    goto v113;

v113:
    stack[-2] = cons(stack[-2], v49);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-3];
    stack[0] = elt(env, 2); /* != */
    v49 = stack[-1];
    fn = elt(env, 4); /* fortexp */
    v49 = (*qfn1(fn))(qenv(fn), v49);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-3];
    v49 = cons(stack[0], v49);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-3];
    stack[0] = Lappend(nil, stack[-2], v49);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-3];
    fn = elt(env, 5); /* mkfortterpri */
    v49 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-3];
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v248;
    {
        Lisp_Object v249 = stack[0];
        popv(4);
        return Lappend(nil, v249, v49);
    }

v74:
    v49 = stack[0];
    v49 = ncons(v49);
    nil = C_nil;
    if (exception_pending()) goto v248;
    env = stack[-3];
    goto v113;
/* error exit handlers */
v248:
    popv(4);
    return nil;
}



/* Code for all_deriv_search */

static Lisp_Object CC_all_deriv_search(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v306, v307;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for all_deriv_search");
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
    stack[0] = v1;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    v306 = stack[-2];
    v306 = Lconsp(nil, v306);
    env = stack[-4];
    if (v306 == nil) goto v92;
    v306 = stack[-2];
    v307 = qcar(v306);
    v306 = elt(env, 1); /* (plus quotient equal) */
    v306 = Lmember(nil, v307, v306);
    if (v306 == nil) goto v244;
    v306 = stack[-2];
    v306 = qcdr(v306);
    stack[-1] = v306;
    goto v100;

v100:
    v306 = stack[-1];
    if (v306 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v306 = stack[-1];
    v306 = qcar(v306);
    v307 = v306;
    v306 = stack[0];
    v307 = CC_all_deriv_search(env, v307, v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    v306 = stack[-3];
    fn = elt(env, 7); /* union */
    v306 = (*qfn2(fn))(qenv(fn), v307, v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    stack[-3] = v306;
    v306 = stack[-1];
    v306 = qcdr(v306);
    stack[-1] = v306;
    goto v100;

v244:
    v306 = stack[-2];
    v307 = qcar(v306);
    v306 = elt(env, 3); /* minus */
    if (v307 == v306) goto v61;
    v306 = stack[-2];
    v307 = qcar(v306);
    v306 = elt(env, 4); /* times */
    if (v307 == v306) goto v38;
    v306 = stack[-2];
    v307 = qcar(v306);
    v306 = elt(env, 5); /* expt */
    if (!(v307 == v306)) goto v279;
    v306 = stack[-2];
    v306 = qcdr(v306);
    v306 = qcdr(v306);
    v306 = qcar(v306);
    if (!(is_number(v306))) goto v279;
    v306 = stack[-2];
    v306 = qcdr(v306);
    v307 = qcar(v306);
    v306 = stack[0];
    v306 = CC_all_deriv_search(env, v307, v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    stack[-1] = v306;
    goto v308;

v308:
    v306 = stack[-1];
    if (v306 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v306 = stack[-1];
    v306 = qcar(v306);
    v307 = v306;
    v307 = qcdr(v307);
    if (!(is_number(v307))) goto v130;
    v307 = v306;
    stack[0] = qcar(v307);
    v307 = stack[-2];
    v307 = qcdr(v307);
    v307 = qcdr(v307);
    v307 = qcar(v307);
    v306 = qcdr(v306);
    v307 = times2(v307, v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    v306 = stack[-3];
    v306 = acons(stack[0], v307, v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    stack[-3] = v306;
    goto v130;

v130:
    v306 = stack[-1];
    v306 = qcdr(v306);
    stack[-1] = v306;
    goto v308;

v279:
    v306 = stack[-2];
    v307 = qcar(v306);
    v306 = elt(env, 6); /* df */
    if (!(v307 == v306)) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v306 = stack[-2];
    v306 = qcdr(v306);
    v307 = qcar(v306);
    v306 = stack[0];
    v306 = Lmember(nil, v307, v306);
    if (v306 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v306 = stack[-2];
    v307 = qcdr(v306);
    v306 = (Lisp_Object)17; /* 1 */
    v306 = cons(v307, v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    v306 = ncons(v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    stack[-3] = v306;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v38:
    v306 = stack[-2];
    v306 = qcdr(v306);
    stack[-1] = v306;
    goto v265;

v265:
    v306 = stack[-1];
    if (v306 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v306 = stack[-1];
    v306 = qcar(v306);
    v307 = v306;
    v306 = stack[0];
    v307 = CC_all_deriv_search(env, v307, v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    v306 = stack[-3];
    fn = elt(env, 8); /* mult_derivs */
    v306 = (*qfn2(fn))(qenv(fn), v307, v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    stack[-3] = v306;
    v306 = stack[-1];
    v306 = qcdr(v306);
    stack[-1] = v306;
    goto v265;

v61:
    v306 = stack[-2];
    v306 = qcdr(v306);
    v307 = qcar(v306);
    v306 = stack[0];
    v306 = CC_all_deriv_search(env, v307, v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    stack[-3] = v306;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v92:
    v307 = stack[-2];
    v306 = stack[0];
    v306 = Lmember(nil, v307, v306);
    if (v306 == nil) { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
    v306 = stack[-2];
    v307 = ncons(v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    v306 = (Lisp_Object)17; /* 1 */
    v306 = cons(v307, v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-4];
    v306 = ncons(v306);
    nil = C_nil;
    if (exception_pending()) goto v9;
    stack[-3] = v306;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v9:
    popv(5);
    return nil;
}



/* Code for zerleg */

static Lisp_Object CC_zerleg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for zerleg");
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
    v32 = stack[-4];
    if (v32 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    v32 = stack[-4];
    fn = elt(env, 2); /* domain!*p */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    if (v32 == nil) goto v117;
    v32 = stack[-4];
    popv(7);
    return ncons(v32);

v117:
    v32 = stack[-4];
    v32 = qcar(v32);
    stack[-5] = v32;
    v32 = stack[-4];
    v32 = qcdr(v32);
    stack[-4] = v32;
    v32 = stack[-4];
    if (v32 == nil) goto v76;
    v32 = stack[-4];
    fn = elt(env, 2); /* domain!*p */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    if (v32 == nil) goto v118;
    v33 = stack[-5];
    v32 = stack[-4];
    v32 = list2(v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    popv(7);
    return ncons(v32);

v118:
    v32 = stack[-4];
    v32 = qcar(v32);
    v32 = CC_zerleg(env, v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v33 = v32;
    v32 = v33;
    stack[-3] = v32;
    v32 = stack[-3];
    if (v32 == nil) goto v83;
    v32 = stack[-3];
    v32 = qcar(v32);
    v33 = stack[-5];
    v32 = cons(v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v32 = ncons(v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    stack[-1] = v32;
    stack[-2] = v32;
    goto v68;

v68:
    v32 = stack[-3];
    v32 = qcdr(v32);
    stack[-3] = v32;
    v32 = stack[-3];
    if (v32 == nil) goto v89;
    stack[0] = stack[-1];
    v32 = stack[-3];
    v32 = qcar(v32);
    v33 = stack[-5];
    v32 = cons(v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v32 = ncons(v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v32 = Lrplacd(nil, stack[0], v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v32 = stack[-1];
    v32 = qcdr(v32);
    stack[-1] = v32;
    goto v68;

v89:
    v32 = stack[-2];
    goto v48;

v48:
    v33 = v32;
    v32 = stack[-4];
    v32 = qcdr(v32);
    if (v32 == nil) { popv(7); return onevalue(v33); }
    stack[0] = v33;
    v33 = stack[-5];
    v32 = stack[-4];
    v32 = qcdr(v32);
    v32 = cons(v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    env = stack[-6];
    v32 = CC_zerleg(env, v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    {
        Lisp_Object v214 = stack[0];
        popv(7);
        return Lappend(nil, v214, v32);
    }

v83:
    v32 = qvalue(elt(env, 1)); /* nil */
    goto v48;

v76:
    v32 = stack[-5];
    v32 = ncons(v32);
    nil = C_nil;
    if (exception_pending()) goto v35;
    popv(7);
    return ncons(v32);
/* error exit handlers */
v35:
    popv(7);
    return nil;
}



setup_type const u58_setup[] =
{
    {"dv_fill_comp_info",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_dv_fill_comp_info},
    {"modroots4",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_modroots4},
    {"make-univariate-mod-p",   wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKunivariateKmodKp},
    {"taylor-add-to-cache",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_taylorKaddKtoKcache},
    {"ctx_union",               too_few_2,      CC_ctx_union,  wrong_no_2},
    {"cd_surep",                too_few_2,      CC_cd_surep,   wrong_no_2},
    {"numlistp",                CC_numlistp,    too_many_1,    wrong_no_1},
    {"groeblistadd",            too_few_2,      CC_groeblistadd,wrong_no_2},
    {"rd:quotient",             too_few_2,      CC_rdTquotient,wrong_no_2},
    {"lispcondp",               CC_lispcondp,   too_many_1,    wrong_no_1},
    {"physopapply",             CC_physopapply, too_many_1,    wrong_no_1},
    {"rep_edge_prop_",          too_few_2,      CC_rep_edge_prop_,wrong_no_2},
    {"taylorevaluate",          too_few_2,      CC_taylorevaluate,wrong_no_2},
    {"general-gcd-mod-p",       too_few_2,      CC_generalKgcdKmodKp,wrong_no_2},
    {"numrdeg",                 too_few_2,      CC_numrdeg,    wrong_no_2},
    {"ofsf_qesubiord",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_qesubiord},
    {"cl_gaussand",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_gaussand},
    {"get*generators",          CC_getHgenerators,too_many_1,  wrong_no_1},
    {"factor-prim-f",           CC_factorKprimKf,too_many_1,   wrong_no_1},
    {"sfto_dprpartf",           CC_sfto_dprpartf,too_many_1,   wrong_no_1},
    {"load_package",            CC_load_package,too_many_1,    wrong_no_1},
    {"codgcd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_codgcd},
    {"clear1",                  CC_clear1,      too_many_1,    wrong_no_1},
    {"gbfmult",                 too_few_2,      CC_gbfmult,    wrong_no_2},
    {":pi",                     CC_Tpi,         too_many_1,    wrong_no_1},
    {"let0",                    CC_let0,        too_many_1,    wrong_no_1},
    {"getphystypestate",        CC_getphystypestate,too_many_1,wrong_no_1},
    {"actual_edges_world",      CC_actual_edges_world,too_many_1,wrong_no_1},
    {"coeffeval",               CC_coeffeval,   too_many_1,    wrong_no_1},
    {"merge_list1",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_merge_list1},
    {"make-image-lc-list",      too_few_2,      CC_makeKimageKlcKlist,wrong_no_2},
    {"multm",                   too_few_2,      CC_multm,      wrong_no_2},
    {"mkexpvec",                CC_mkexpvec,    too_many_1,    wrong_no_1},
    {"deflate1c",               too_few_2,      CC_deflate1c,  wrong_no_2},
    {"mkffortassign",           too_few_2,      CC_mkffortassign,wrong_no_2},
    {"all_deriv_search",        too_few_2,      CC_all_deriv_search,wrong_no_2},
    {"zerleg",                  CC_zerleg,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u58", (two_args *)"16794 9625745 5857938", 0}
};

/* end of generated code */
